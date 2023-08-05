#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/types.h>
#include <xtd/native/thread.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include "../../../include/xtd/threading/manual_reset_event.h"
#include "../../../include/xtd/threading/thread_abort_exception.h"
#include "../../../include/xtd/threading/thread_interrupted_exception.h"
#include "../../../include/xtd/threading/thread_state_exception.h"
#include "../../../include/xtd/threading/thread.h"
#include "../../../include/xtd/threading/timeout.h"
#include "../../../include/xtd/argument_exception.h"
#include "../../../include/xtd/int32_object.h"
#include "../../../include/xtd/invalid_operation_exception.h"
#include "../../../include/xtd/not_implemented_exception.h"
#include "../../../include/xtd/as.h"
#include <thread>

using namespace xtd;
using namespace xtd::threading;

namespace {
  static std::thread::id main_thread_id_ = std::this_thread::get_id();
  static std::recursive_mutex mutex_;
}

struct thread::data {
  bool critical_region {false};
  std::thread::id detached_thread_id;
  manual_reset_event end_thread_event {false};
  intptr handle {native::types::invalid_handle()};
  bool interrupted {false};
  bool is_thread_pool_thread {false};
  int32 managed_thread_id {unmanaged_thread_id};
  xtd::ustring name;
  xtd::threading::parameterized_thread_start parameterized_thread_start;
  xtd::threading::thread_priority priority {xtd::threading::thread_priority::normal};
  xtd::threading::thread_state state {xtd::threading::thread_state::unstarted};
  std::thread thread;
  xtd::threading::thread_start thread_start;
};

//thread::std::thread::id thread::main_thread_id_ = std::this_thread::get_id();
//std::recursive_mutex thread::mutex_ {};
thread::thread_collection thread::threads_ {thread {}, thread {}};

thread::thread() : data_(std::make_shared<data>()) {
}

thread::thread(xtd::threading::thread_start start) {
  
}

thread::thread(xtd::threading::thread_start start, int32 max_stack_size) {
  
}

thread::thread(xtd::threading::parameterized_thread_start start) {
  
}

thread::thread(xtd::threading::parameterized_thread_start start, int32 max_stack_size) {
  
}

thread& thread::current_thread() {
  std::lock_guard<std::recursive_mutex> lock(mutex_);
  std::thread::id id = std::this_thread::get_id();
  
  if (id == main_thread_id_) {
    if (threads_[0].data_->managed_thread_id != main_managed_thread_id) {
      threads_[0].data_->handle = get_current_thread_handle();
      threads_[0].data_->managed_thread_id = main_managed_thread_id;
      threads_[0].data_->state &= ~xtd::threading::thread_state::unstarted;
    }
    return threads_[0];
  }
  
  for (auto& item : threads_) {
    if (item.data_->thread.get_id() == id || item.data_->detached_thread_id == id)
      return item;
  }
  
  if ((threads_[1].data_->state & xtd::threading::thread_state::unstarted) == xtd::threading::thread_state::unstarted) {
    threads_[1].data_->handle = get_current_thread_handle();
    threads_[1].data_->state &= ~xtd::threading::thread_state::unstarted;
    threads_[1].data_->state |= xtd::threading::thread_state::background;
  }
  return threads_[1];
}

intptr thread::handle() const noexcept {
  return data_->handle;
}

int32 thread::managed_thread_id() const noexcept {
  return data_->managed_thread_id;
}

int32 thread::thread_id() const noexcept {
  return managed_thread_id();
}

xtd::threading::thread_state thread::thread_state() const noexcept {
  return data_->state;
}

void thread::interrupt() {
  if (data_->managed_thread_id == unmanaged_thread_id || data_->managed_thread_id == main_managed_thread_id)
    throw invalid_operation_exception(csf_);
  
  if (enum_object<xtd::threading::thread_state>(data_->state).has_flag(xtd::threading::thread_state::unstarted))
    throw thread_state_exception(csf_);
  
  if (enum_object<xtd::threading::thread_state>(data_->state).has_flag(xtd::threading::thread_state::wait_sleep_join) && cancel() == true) {
    data_->state &= ~xtd::threading::thread_state::wait_sleep_join;
    data_->interrupted = false;
    /// @todo When manual_reset_event is implemented add end_thread_event in data and uncomment folowing line
    //data_->end_thread_event.set();
    throw thread_interrupted_exception(csf_);
  }
  
  data_->interrupted = true;
}

void thread::sleep(int32 milliseconds_timeout) {
  sleep(std::chrono::milliseconds(milliseconds_timeout));
}

bool thread::yield() {
  std::this_thread::yield();
  return true;
}

bool thread::cancel() {
  // Double reinterpret_cast required to pass compilation with gcc.
  return native::thread::cancel(reinterpret_cast<intptr>(reinterpret_cast<intptr*>(data_->thread.native_handle())));
}

bool thread::do_wait(wait_handle& wait_handle, int32 milliseconds_timeout) {
  if (milliseconds_timeout < timeout::infinite) throw argument_exception(csf_);
  
  current_thread().data_->state |= xtd::threading::thread_state::wait_sleep_join;
  if (current_thread().data_->interrupted)
    current_thread().interrupt();
  try {
    auto result = wait_handle.wait(milliseconds_timeout);
    current_thread().data_->state &= ~xtd::threading::thread_state::wait_sleep_join;
    return result;
  } catch (...) {
    current_thread().data_->state &= ~xtd::threading::thread_state::wait_sleep_join;
    throw;
  }
}

int32 thread::generate_managed_thread_id() noexcept {
  static int32 managed_thread_id_counter = main_managed_thread_id;
  managed_thread_id_counter = managed_thread_id_counter == int32_object::max_value ? main_managed_thread_id + 1 : managed_thread_id_counter + 1;
  return managed_thread_id_counter;
}

intptr thread::get_current_thread_handle() {
  return native::thread::get_current_thread_handle();
}

void thread::nano_sleep(const std::chrono::nanoseconds& timeout) {
  auto nanoseconds_timeout = timeout.count();
  if (nanoseconds_timeout < timeout::infinite) throw argument_exception(csf_);
  
  if (current_thread().data_->interrupted) current_thread().interrupt();
  
  current_thread().data_->state |= xtd::threading::thread_state::wait_sleep_join;
  if (nanoseconds_timeout == timeout::infinite) while (true) std::this_thread::sleep_for(std::chrono::hours::max());
  else if (nanoseconds_timeout == 0) yield();
  else std::this_thread::sleep_for(timeout);
  current_thread().data_->state &= ~xtd::threading::thread_state::wait_sleep_join;
}
