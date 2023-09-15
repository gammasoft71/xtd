#include "../../../include/xtd/threading/spin_lock.h"
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
  lock_taken = enter(timeout::infinite);
}

bool spin_lock::enter(const time_span& timeout) {
  return enter(as<int32>(timeout.total_milliseconds()));
}

bool spin_lock::enter(int32 milliseconds_timeout) {
  auto sw = stopwatch::start_new();
  while (data_->flag.test_and_set(std::memory_order_acquire)) {
    if (milliseconds_timeout != timeout::infinite && sw.elapsed_milliseconds() > milliseconds_timeout) return false;
    thread::yield();
  }
  if (data_->enable_thread_owner_tracking) data_->thread_id = thread::current_thread().thread_id();
  return true;
}

void spin_lock::exit() {
  exit(true);
}

void spin_lock::exit(bool memory_barrier) {
  if (memory_barrier) std::atomic_thread_fence(std::memory_order_acquire);
  if (data_->enable_thread_owner_tracking) data_->thread_id = thread::invalid_thread_id;
  data_->flag.clear(std::memory_order_release);
}
