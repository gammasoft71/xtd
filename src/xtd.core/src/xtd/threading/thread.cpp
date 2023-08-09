#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/types.h>
#include <xtd/native/thread.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include "../../../include/xtd/threading/event_wait_handle.h"
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

#include "../../../include/xtd/diagnostics/debug.h"

using namespace xtd;
using namespace xtd::threading;

struct __current_thread_id__ {
  intptr operator()() {
    return xtd::threading::thread::get_current_thread_id();
  }
};

struct __threads__ {
  thread::thread_collection operator()(bool write_debug = false) {
    if (write_debug) xtd::threading::thread::debug_write_threads("threads");
    return xtd::threading::thread::threads();
  }
};

namespace {
  static intptr main_thread_id = __current_thread_id__ {}();
  
  static std::recursive_mutex& mutex_for_threads_access() {
    static std::recursive_mutex mutex;
    return mutex;
  }
}

const intptr thread::invalid_handle = native::types::invalid_handle();

const intptr thread::invalid_thread_id = native::types::invalid_handle();

struct thread::data {
  bool critical_region {false};
  event_wait_handle end_thread_event {false, event_reset_mode::manual_reset};
  intptr handle {invalid_handle};
  size_t index = static_cast<size_t>(-1);
  bool interrupted {false};
  bool is_thread_pool_thread {false};
  bool joinable {false};
  int32 managed_thread_id {unmanaged_thread_id};
  int32 max_stack_size {0};
  xtd::ustring name;
  std::any parameter;
  xtd::threading::parameterized_thread_start parameterized_thread_start;
  xtd::threading::thread_priority priority {xtd::threading::thread_priority::normal};
  xtd::threading::thread_state state {xtd::threading::thread_state::unstarted};
  intptr thread_id {invalid_thread_id};
  xtd::threading::thread_start thread_start;
};

thread& thread::current_thread() {
  std::lock_guard<std::recursive_mutex> lock {mutex_for_threads_access()};
  intptr id = get_current_thread_id();
  
  if (id == main_thread_id) {
    if (threads().at(0)->data_->managed_thread_id != main_managed_thread_id) {
      threads().at(0)->data_->handle = get_current_thread_handle();
      threads().at(0)->data_->managed_thread_id = main_managed_thread_id;
      threads().at(0)->data_->state &= ~xtd::threading::thread_state::unstarted;
      threads().at(0)->data_->thread_id = get_current_thread_id();
    }
    return *threads().at(0);
  }
  
  for (auto index = 2ul; index < threads().size(); ++index) {
    if (threads()[index]->data_->thread_id == id)
      return *threads().at(index);
  }
  
  if ((threads().at(1)->data_->state & xtd::threading::thread_state::unstarted) == xtd::threading::thread_state::unstarted) {
    threads().at(1)->data_->handle = get_current_thread_handle();
    threads().at(1)->data_->state &= ~xtd::threading::thread_state::unstarted;
    threads().at(1)->data_->state |= xtd::threading::thread_state::background;
    threads().at(1)->data_->thread_id = get_current_thread_id();
  }
  return *threads().at(1);
}

thread::thread() : data_(std::make_shared<data>()) {
  std::lock_guard<std::recursive_mutex> lock {mutex_for_threads_access()};
  data_->index = threads().size();
  threads().push_back(std::make_shared<thread>(*this));
}

thread::thread(const xtd::threading::thread_start& start) : thread::thread(start, 0) {
}

thread::thread(const xtd::threading::thread_start& start, int32 max_stack_size) : data_(std::make_shared<data>()) {
  if (start.is_empty() || max_stack_size < 0) throw argument_exception {csf_};
  data_->managed_thread_id = generate_managed_thread_id();
  data_->thread_start = start;
  data_->max_stack_size = max_stack_size;
  std::lock_guard<std::recursive_mutex> lock {mutex_for_threads_access()};
  data_->index = threads().size();
  threads().push_back(std::make_shared<thread>(*this));
}

thread::thread(const xtd::threading::parameterized_thread_start& start) : thread(start, 0) {
}

thread::thread(const xtd::threading::parameterized_thread_start& start, int32 max_stack_size) : data_(std::make_shared<data>()) {
  if (start.is_empty() || max_stack_size < 0) throw argument_exception {csf_};
  data_->managed_thread_id = generate_managed_thread_id();
  data_->parameterized_thread_start = start;
  data_->max_stack_size = max_stack_size;
  std::lock_guard<std::recursive_mutex> lock {mutex_for_threads_access()};
  data_->index = threads().size();
  threads().push_back(std::make_shared<thread>(*this));
}

thread::thread(bool special_thread) : data_(std::make_shared<data>()) {
}

thread& thread::operator=(const thread& value) {
  close();
  data_ = value.data_;
  return *this;
}

thread::~thread() {
  close();
}

intptr thread::handle() const noexcept {
  return data_ ? data_->handle : invalid_handle;
}

bool thread::is_alive() const noexcept {
  return data_ ? !is_unstarted() && !is_stopped() && !is_aborted() : false;
}

bool thread::is_background() const noexcept {
  return data_ ? enum_object<xtd::threading::thread_state>(data_->state).has_flag(xtd::threading::thread_state::background) : false;
}

thread& thread::is_background(bool value) {
  if (!data_) throw invalid_operation_exception {csf_};
  if (data_->managed_thread_id == unmanaged_thread_id || data_->managed_thread_id == main_managed_thread_id) throw invalid_operation_exception(csf_);
  
  if (value) data_->state |= xtd::threading::thread_state::background;
  else data_->state &= ~xtd::threading::thread_state::background;

  return *this;
}

bool thread::is_thread_pool_thread() const noexcept {
  return data_ ? data_->is_thread_pool_thread : false;
}

bool thread::joinable() const noexcept {
  return data_ ? data_->joinable && !is_background() : false;
}

int32 thread::managed_thread_id() const noexcept {
  return data_ ? data_->managed_thread_id : 0;
}

ustring thread::name() const noexcept {
  return data_ ? data_->name : "";
}

thread& thread::name(const ustring& value) {
  if (!data_) throw invalid_operation_exception {csf_};
  if (value == data_->name) return *this;
  data_->name = value;
  if (get_current_thread_id() == data_->thread_id) native::thread::set_current_thread_name(value);
  return *this;
}

xtd::threading::thread_priority thread::priority() const noexcept {
  return data_ ? data_->priority : xtd::threading::thread_priority::normal;
}

thread& thread::priority(xtd::threading::thread_priority value) {
  if (!data_) throw invalid_operation_exception {csf_};
  if (!enum_object<>::is_defined(value)) throw argument_exception {csf_};
  if (is_aborted() || is_stopped()) throw thread_state_exception(csf_);
  
  if (data_->priority == value) return *this;
  data_->priority = value;
  if (data_->handle != native::types::invalid_handle()) native::thread::set_priority(data_->handle, as<int32>(value));
  return *this;
}

intptr thread::thread_id() const noexcept {
  return data_ ? data_->thread_id : invalid_thread_id;
}

xtd::threading::thread_state thread::thread_state() const noexcept {
  return data_ ? data_->state : xtd::threading::thread_state::unstarted;
}

void thread::close() {
  if (data_ == nullptr || data_->managed_thread_id == main_managed_thread_id || data_->managed_thread_id == unmanaged_thread_id) return;

  if (data_.use_count() == 1 && data_->joinable) join();
}

void thread::interrupt() {
  if (data_->managed_thread_id == unmanaged_thread_id || data_->managed_thread_id == main_managed_thread_id) throw invalid_operation_exception(csf_);
  if (is_unstarted()) throw thread_state_exception(csf_);
  
  if (is_wait_sleep_join() && cancel() == true) {
    data_->state &= ~xtd::threading::thread_state::wait_sleep_join;
    data_->interrupted = false;
    data_->end_thread_event.set();
    throw thread_interrupted_exception(csf_);
  }
  
  data_->interrupted = true;
}

void thread::join() {
  join(timeout::infinite);
}

bool thread::join(int32 milliseconds_timeout) {
  if (data_->managed_thread_id == unmanaged_thread_id || data_->managed_thread_id == main_managed_thread_id) throw invalid_operation_exception {csf_};
  if (is_unstarted()) throw thread_state_exception {csf_};
  if (milliseconds_timeout < timeout::infinite) throw argument_exception(csf_);
  
  if (data_->interrupted == true) interrupt();
  if (!data_->joinable) return false;
  
  bool result = data_->end_thread_event.wait_one(milliseconds_timeout);
  if (result == true) {
    data_->joinable = false;
    try {
      current_thread().data_->state |= xtd::threading::thread_state::wait_sleep_join;
      native::thread::join(data_->handle);
      current_thread().data_->state &= ~xtd::threading::thread_state::wait_sleep_join;
    } catch (...) {
      current_thread().data_->state &= ~xtd::threading::thread_state::wait_sleep_join;
    }
  }
  return result;
}

void thread::sleep(int32 milliseconds_timeout) {
  if (milliseconds_timeout < timeout::infinite) throw argument_exception(csf_);
  
  if (current_thread().data_->interrupted) current_thread().interrupt();
  
  current_thread().data_->state |= xtd::threading::thread_state::wait_sleep_join;
  native::thread::sleep(milliseconds_timeout);
  current_thread().data_->state &= ~xtd::threading::thread_state::wait_sleep_join;
}

void thread::start() {
  if (!is_unstarted()) throw thread_state_exception {csf_};
  if (!data_->parameter.has_value() && data_->thread_start.is_empty()) throw invalid_operation_exception {csf_};
  data_->state &= ~xtd::threading::thread_state::unstarted;
  data_->joinable = true;
  data_->parameter = nullptr;
  data_->handle = native::thread::create([&](intptr arg) {
    reinterpret_cast<threading::thread*>(arg)->thread_proc();
  }, reinterpret_cast<intptr>(threads().at(data_->index).get()), data_->max_stack_size, is_suspended(), data_->thread_id);
}

void thread::start(std::any param) {
  if (!is_unstarted()) throw thread_state_exception {csf_};
  if (data_->parameter.has_value() && data_->parameterized_thread_start.is_empty()) throw invalid_operation_exception {csf_};
  data_->state &= ~xtd::threading::thread_state::unstarted;
  data_->joinable = true;
  data_->parameter = param;
  data_->handle = native::thread::create([](intptr arg) {
    reinterpret_cast<thread*>(arg)->thread_proc();
  }, reinterpret_cast<intptr>(threads().at(data_->index).get()), data_->max_stack_size, is_suspended(), data_->thread_id);
}

bool thread::yield() {
  return native::thread::yield();
}

bool thread::cancel() {
  // Double reinterpret_cast required to pass compilation with gcc.
  return native::thread::cancel(reinterpret_cast<intptr>(reinterpret_cast<intptr*>(data_->handle)));
}

bool thread::do_wait(wait_handle& wait_handle, int32 milliseconds_timeout) {
  if (milliseconds_timeout < timeout::infinite) throw argument_exception(csf_);
  
  current_thread().data_->state |= xtd::threading::thread_state::wait_sleep_join;
  if (current_thread().data_->interrupted) current_thread().interrupt();
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

intptr thread::get_current_thread_id() {
  return native::thread::get_thread_id(get_current_thread_handle());
}

bool thread::is_aborted() const noexcept {
  return enum_object<xtd::threading::thread_state>(data_->state).has_flag(xtd::threading::thread_state::aborted);
}

bool thread::is_stopped() const noexcept {
  return enum_object<xtd::threading::thread_state>(data_->state).has_flag(xtd::threading::thread_state::stopped);
}

bool thread::is_suspended() const noexcept {
  return enum_object<xtd::threading::thread_state>(data_->state).has_flag(xtd::threading::thread_state::suspended);
}

bool thread::is_unstarted() const noexcept {
  return enum_object<xtd::threading::thread_state>(data_->state).has_flag(xtd::threading::thread_state::unstarted);
}

bool thread::is_wait_sleep_join() const noexcept {
  return enum_object<xtd::threading::thread_state>(data_->state).has_flag(xtd::threading::thread_state::wait_sleep_join);
}

thread::thread_collection& thread::threads() {
  static thread_collection threads {std::shared_ptr<thread> {new thread {true}}, std::shared_ptr<thread> {new thread {true}}};
  return threads;
}

void thread::thread_proc() {
  if (!data_) {
    debug_write_threads(csf_.get_method());
    throw invalid_operation_exception {csf_};
  }
  
  native::thread::set_current_thread_name(data_->name);
  data_->joinable = true;
  data_->thread_id = native::thread::get_thread_id(data_->handle);
  if (data_->priority != xtd::threading::thread_priority::normal) native::thread::set_priority(data_->handle, as<int32>(data_->priority));
  if (!data_->thread_start.is_empty()) data_->thread_start();
  else if (!data_->parameterized_thread_start.is_empty()) data_->parameterized_thread_start(data_->parameter);
  else throw invalid_operation_exception {csf_};
  
  data_->state |= xtd::threading::thread_state::stopped;
  data_->end_thread_event.set();
  
  std::lock_guard<std::recursive_mutex> lock {mutex_for_threads_access()};
  thread_collection::iterator iterator = std::find_if(threads().begin(), threads().end(), [&](const auto& value) {return value->data_->managed_thread_id == data_->managed_thread_id;});
  if (iterator != threads().end()) {
    (*iterator)->data_ = nullptr;
    threads().erase(iterator);
  }
}

void thread::debug_write_threads(const xtd::ustring& fct) {
  for (auto index = 0ul; index < threads().size(); ++index)
    diagnostics::debug::write_line("({}) [{}] {{handle=0x{:x}, data_=0x{:x}, managed_thread_id={}, thread_id=0x{:x}, name=\"{}\" }}", fct, index, reinterpret_cast<intptr>(threads().at(index).get()), reinterpret_cast<intptr>(threads().at(index)->data_.get()), threads().at(index)->managed_thread_id(), threads().at(index)->thread_id(), threads().at(index)->name());
}
