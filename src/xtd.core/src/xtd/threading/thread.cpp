#include "../../../include/xtd/threading/thread_abort_exception.h"
#include "../../../include/xtd/threading/thread_interrupted_exception.h"
#include "../../../include/xtd/threading/thread_state_exception.h"
#include "../../../include/xtd/threading/thread.h"
#include "../../../include/xtd/threading/timeout.h"
#include "../../../include/xtd/argument_exception.h"
#include "../../../include/xtd/invalid_operation_exception.h"
#include "../../../include/xtd/not_implemented_exception.h"
#include "../../../include/xtd/as.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/thread.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::threading;

struct thread::data {
  thread_id detached_thread_id;
  bool interrupted {false};
  int32 managed_thread_id {unmanaged_thread_id};
  thread_priority priority {thread_priority::normal};
  thread_state state {thread_state::unstarted};
  std::thread thread;
  /// @todo When manual_reset_event is implemented uncomment folowing line
  /// manual_reset_event end_thread_event {false};
};

thread::thread_id thread::main_thread_id_ = std::this_thread::get_id();
std::recursive_mutex thread::mutex_ {};
thread::thread_collection thread::threads_ {thread {}, thread {}};

thread::thread() : data_(std::make_shared<data>()) {
}

thread& thread::current_thread() {
  std::lock_guard<std::recursive_mutex> lock(mutex_);
  thread_id id = std::this_thread::get_id();
  
  if (id == main_thread_id_) {
    if (threads_[0].data_->managed_thread_id != main_managed_thread_id) {
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
    threads_[1].data_->state &= ~xtd::threading::thread_state::unstarted;
    threads_[1].data_->state |= xtd::threading::thread_state::background;
  }
  return threads_[1];
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
  if (milliseconds_timeout < timeout::infinite)
    throw argument_exception(csf_);
  
  if (current_thread().data_->interrupted)
    current_thread().interrupt();
  
  current_thread().data_->state |= xtd::threading::thread_state::wait_sleep_join;
  if (milliseconds_timeout == timeout::infinite) while (true) std::this_thread::sleep_for(std::chrono::hours::max());
  else if (milliseconds_timeout == 0) yield();
  else std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds_timeout));
  current_thread().data_->state &= ~xtd::threading::thread_state::wait_sleep_join;
}

void thread::sleep(const time_span& timeout) {
  sleep(as<int32>(timeout.count()));
}

bool thread::yield() {
  std::this_thread::yield();
  return true;
}

bool thread::cancel() {
  // Double reinterpret_cast required to pass compilation with gcc.
  return native::thread::cancel(reinterpret_cast<intptr_t>(reinterpret_cast<intptr_t*>(data_->thread.native_handle())));
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
