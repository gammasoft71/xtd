#include "../../../include/xtd/threading/spin_lock.h"
#include "../../../include/xtd/threading/lock_recursion_exception.h"
#include "../../../include/xtd/threading/synchronization_lock_exception.h"
#include "../../../include/xtd/threading/thread.h"
#include "../../../include/xtd/diagnostics/stopwatch.h"
#include "../../../include/xtd/as.h"
#include <atomic>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::threading;

struct spin_lock::data {
  bool enable_thread_owner_tracking = false;
  std::atomic_flag flag = ATOMIC_FLAG_INIT;
  intptr thread_id = thread::invalid_thread_id;
};

spin_lock::spin_lock() : spin_lock(false) {
}

spin_lock::spin_lock(bool enable_thread_owner_tracking) : data_(std::make_shared<data>()) {
  data_->enable_thread_owner_tracking = enable_thread_owner_tracking;
  data_->flag.clear();
}

bool spin_lock::is_held() const noexcept {
  return data_->flag.test();
}

bool spin_lock::is_held_by_current_thread() const noexcept {
  return data_->enable_thread_owner_tracking;
}

bool spin_lock::is_thread_owner_tracking_enabled() const noexcept {
  return data_->thread_id == thread::current_thread().thread_id();
}

void spin_lock::enter(bool& lock_taken) {
  try_enter(timeout::infinite, lock_taken);
}

void spin_lock::exit() {
  exit(true);
}

void spin_lock::exit(bool use_memory_barrier) {
  if (data_->enable_thread_owner_tracking && data_->thread_id != thread::current_thread().thread_id()) throw synchronization_lock_exception {csf_};
  if (use_memory_barrier) std::atomic_thread_fence(std::memory_order_acquire);
  if (data_->enable_thread_owner_tracking) data_->thread_id = thread::invalid_thread_id;
  data_->flag.clear(std::memory_order_release);
}

void spin_lock::try_enter(bool& lock_taken) {
  try_enter(0, lock_taken);
}

void spin_lock::try_enter(const time_span& timeout, bool& lock_taken) {
  try_enter(as<int32>(timeout.total_milliseconds()), lock_taken);
}

void spin_lock::try_enter(int32 milliseconds_timeout, bool& lock_taken) {
  if (data_->enable_thread_owner_tracking && data_->thread_id == thread::current_thread().thread_id()) throw lock_recursion_exception {csf_};
  lock_taken = false;
  auto sw = stopwatch::start_new();
  while (data_->flag.test_and_set(std::memory_order_acquire)) {
    if (milliseconds_timeout != timeout::infinite && sw.elapsed_milliseconds() > milliseconds_timeout) return;
    thread::yield();
  }
  if (data_->enable_thread_owner_tracking) data_->thread_id = thread::current_thread().thread_id();
  lock_taken = true;
}
