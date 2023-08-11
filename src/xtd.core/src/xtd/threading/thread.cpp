#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/types.h>
#include <xtd/native/thread.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include "../../../include/xtd/threading/manual_reset_event.h"
#include "../../../include/xtd/threading/mutex.h"
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

using namespace xtd;
using namespace xtd::threading;

namespace {
  class lock_guard_threads {
  public:
    lock_guard_threads() {lock_.wait_one();}
    ~lock_guard_threads() {lock_.release_mutex();}
    
    static xtd::threading::mutex& lock() {return lock_;}
    
  private:
    inline static xtd::threading::mutex lock_;
  };
}

struct thread::data {
  bool critical_region {false};
  manual_reset_event end_thread_event;
  intptr handle {invalid_handle};
  size_t index = std::numeric_limits<size_t>::max();
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

class thread::thread_collection : public std::vector<std::shared_ptr<thread>> {
public:
  thread_collection() = default;
  thread_collection(std::initializer_list<std::shared_ptr<thread>> init) : std::vector<std::shared_ptr<thread>>(init) {    
  }
  
  ~thread_collection() {
    for (auto& item : *this)
      if (item && item->data_ && !item->is_main_thread() && !item->is_unmanaged_thread()) while (item->is_wait_sleep_join()) native::thread::sleep(10);
  }
};

const intptr thread::invalid_handle = native::types::invalid_handle();

const intptr thread::invalid_thread_id = native::types::invalid_handle();

intptr thread::main_thread_id_ = thread::get_current_thread_id();

thread::thread_collection thread::threads_ {std::make_shared<thread>(), std::make_shared<thread>()};

thread& thread::current_thread() {
  lock_guard_threads lock;
  intptr id = get_current_thread_id();
  
  if (id == main_thread_id_) return main_thread();
  
  for (auto index = 2ul; index < threads_.size(); ++index) {
    if (threads_[index]->data_ && threads_[index]->data_->thread_id == id)
      return *threads_.at(index);
  }
  
  if (threads_.at(1)->is_unstarted()) {
    threads_.at(1)->data_->handle = get_current_thread_handle();
    threads_.at(1)->data_->state &= ~xtd::threading::thread_state::unstarted;
    threads_.at(1)->data_->state |= xtd::threading::thread_state::background;
    threads_.at(1)->data_->thread_id = get_current_thread_id();
  }
  return *threads_.at(1);
}

thread& thread::main_thread() {
  lock_guard_threads lock;
  if (threads_.at(0)->data_->managed_thread_id != main_managed_thread_id) {
    threads_.at(0)->data_->end_thread_event.set();
    threads_.at(0)->data_->handle = get_current_thread_handle();
    threads_.at(0)->data_->joinable = true;
    threads_.at(0)->data_->managed_thread_id = main_managed_thread_id;
    threads_.at(0)->data_->state &= ~xtd::threading::thread_state::unstarted;
    threads_.at(0)->data_->thread_id = get_current_thread_id();
  }
  return *threads_.at(0);
}

thread::thread() : data_(std::make_shared<data>()) {
}

thread::thread(const xtd::threading::thread_start& start) : thread::thread(start, 0) {
}

thread::thread(const xtd::threading::thread_start& start, int32 max_stack_size) : data_(std::make_shared<data>()) {
  if (start.is_empty() || max_stack_size < 0) throw argument_exception {csf_};
  data_->managed_thread_id = generate_managed_thread_id();
  data_->thread_start = start;
  data_->max_stack_size = max_stack_size;
  lock_guard_threads lock;
  data_->index = threads_.size();
  threads_.push_back(std::make_shared<thread>(*this));
}

thread::thread(const xtd::threading::parameterized_thread_start& start) : thread(start, 0) {
}

thread::thread(const xtd::threading::parameterized_thread_start& start, int32 max_stack_size) : data_(std::make_shared<data>()) {
  if (start.is_empty() || max_stack_size < 0) throw argument_exception {csf_};
  data_->managed_thread_id = generate_managed_thread_id();
  data_->parameterized_thread_start = start;
  data_->max_stack_size = max_stack_size;
  lock_guard_threads lock;
  data_->index = threads_.size();
  threads_.push_back(std::make_shared<thread>(*this));
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
  if (is_unmanaged_thread()) throw thread_state_exception(csf_);
  
  if (value) data_->state |= xtd::threading::thread_state::background;
  else data_->state &= ~xtd::threading::thread_state::background;

  return *this;
}

bool thread::is_main_thread() const noexcept {
  return data_ ? data_->managed_thread_id == main_managed_thread_id : false;
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
  if (data_ == nullptr || is_main_thread() || is_unmanaged_thread()) return;

  if (data_.use_count() == 1 && data_->joinable) join();
}

void thread::detach() {
  is_background(true);
}

void thread::interrupt() {
  if (!data_) throw invalid_operation_exception {csf_};
  if (is_unmanaged_thread() || is_main_thread()) throw invalid_operation_exception(csf_);
  if (is_unstarted()) throw thread_state_exception(csf_);
  
  if (is_wait_sleep_join() && cancel()) {
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
  if (is_unmanaged_thread()) throw invalid_operation_exception {csf_};
  if (is_unstarted()) throw thread_state_exception {csf_};
  if (milliseconds_timeout < timeout::infinite) throw argument_exception(csf_);
  
  if (data_ && data_->interrupted == true) interrupt();
  if (!data_ || !joinable()) return false;
  
  bool result = data_->end_thread_event.wait_one(milliseconds_timeout);
  if (result == true) {
    try {
      if (!is_main_thread()) current_thread().data_->state |= xtd::threading::thread_state::wait_sleep_join;
      native::thread::join(data_->handle);
      if (!is_main_thread()) current_thread().data_->state &= ~xtd::threading::thread_state::wait_sleep_join;
    } catch (...) {
      if (!is_main_thread()) current_thread().data_->state &= ~xtd::threading::thread_state::wait_sleep_join;
    }
    data_->joinable = false;
  }
  return result;
}

void thread::sleep(int32 milliseconds_timeout) {
  if (milliseconds_timeout < timeout::infinite) throw argument_exception(csf_);
  
  if (current_thread().data_ && current_thread().data_->interrupted) current_thread().interrupt();
  
  if (current_thread().data_) current_thread().data_->state |= xtd::threading::thread_state::wait_sleep_join;
  native::thread::sleep(milliseconds_timeout);
  if (current_thread().data_) current_thread().data_->state &= ~xtd::threading::thread_state::wait_sleep_join;
}

void thread::start() {
  if (!data_) throw invalid_operation_exception {csf_};
  if (!is_unstarted()) throw thread_state_exception {csf_};
  if (!data_->parameter.has_value() && data_->thread_start.is_empty()) throw invalid_operation_exception {csf_};
  data_->state &= ~xtd::threading::thread_state::unstarted;
  data_->joinable = true;
  data_->parameter = nullptr;
  data_->handle = native::thread::create([&](intptr arg) {
    reinterpret_cast<threading::thread*>(arg)->thread_proc();
  }, reinterpret_cast<intptr>(threads_.at(data_->index).get()), data_->max_stack_size, is_suspended(), data_->thread_id);
}

void thread::start(std::any param) {
  if (!data_) throw invalid_operation_exception {csf_};
  if (!is_unstarted()) throw thread_state_exception {csf_};
  if (data_->parameter.has_value() && data_->parameterized_thread_start.is_empty()) throw invalid_operation_exception {csf_};
  data_->state &= ~xtd::threading::thread_state::unstarted;
  data_->joinable = true;
  data_->parameter = param;
  data_->handle = native::thread::create([](intptr arg) {
    reinterpret_cast<thread*>(arg)->thread_proc();
  }, reinterpret_cast<intptr>(threads_.at(data_->index).get()), data_->max_stack_size, is_suspended(), data_->thread_id);
}

thread thread::start_new(const xtd::threading::thread_start& start) {
  auto thread = threading::thread {start};
  thread.start();
  return thread;
}

thread thread::start_new(const xtd::threading::parameterized_thread_start& start) {
  auto thread = threading::thread {start};
  thread.start();
  return thread;
}

bool thread::yield() {
  return native::thread::yield();
}

bool thread::cancel() {
  return data_ ? native::thread::cancel(data_->handle) : false;
}

bool thread::do_wait(wait_handle& wait_handle, int32 milliseconds_timeout) {
  if (milliseconds_timeout < timeout::infinite) throw argument_exception(csf_);
  
  // Don't use default way, otherwise you'll get reentrant calls up to a stack overflow in the do_wait method.
  if (wait_handle.handle() == lock_guard_threads::lock().handle()) return lock_guard_threads::lock().wait(milliseconds_timeout);
  
  if (current_thread().data_) current_thread().data_->state |= xtd::threading::thread_state::wait_sleep_join;
  if (current_thread().data_ && current_thread().data_->interrupted) current_thread().interrupt();
  try {
    auto result = wait_handle.wait(milliseconds_timeout);
    if (current_thread().data_) current_thread().data_->state &= ~xtd::threading::thread_state::wait_sleep_join;
    return result;
  } catch (...) {
    if (current_thread().data_) current_thread().data_->state &= ~xtd::threading::thread_state::wait_sleep_join;
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

void thread::reset_threads() {
  if (threads_.size() > 2) {
    for (auto& item : threads_)
      if (item && item->data_ && !item->is_main_thread() && !item->is_unmanaged_thread()) while (item->is_wait_sleep_join()) native::thread::sleep(10);
    threads_.erase(threads_.begin() + 2, threads_.end());
  }
}

bool thread::is_aborted() const noexcept {
  return data_ ? enum_object<xtd::threading::thread_state>(data_->state).has_flag(xtd::threading::thread_state::aborted) : false;
}

bool thread::is_stopped() const noexcept {
  return data_ ? enum_object<xtd::threading::thread_state>(data_->state).has_flag(xtd::threading::thread_state::stopped) : false;
}

bool thread::is_suspended() const noexcept {
  return data_ ? enum_object<xtd::threading::thread_state>(data_->state).has_flag(xtd::threading::thread_state::suspended) : false;
}

bool thread::is_unmanaged_thread() const noexcept {
  return data_ ? data_->managed_thread_id == unmanaged_thread_id : false;
}

bool thread::is_unstarted() const noexcept {
  return data_ ? enum_object<xtd::threading::thread_state>(data_->state).has_flag(xtd::threading::thread_state::unstarted) : true;
}

bool thread::is_wait_sleep_join() const noexcept {
  return data_ ? enum_object<xtd::threading::thread_state>(data_->state).has_flag(xtd::threading::thread_state::wait_sleep_join) : false;
}

void thread::thread_proc() {
  if (!data_) throw invalid_operation_exception {csf_};
  
  if (!data_->name.empty()) native::thread::set_current_thread_name(data_->name);
  if (data_->priority != xtd::threading::thread_priority::normal) native::thread::set_priority(data_->handle, as<int32>(data_->priority));

  if (!data_->thread_start.is_empty()) data_->thread_start();
  else if (!data_->parameterized_thread_start.is_empty()) data_->parameterized_thread_start(data_->parameter);
  else throw invalid_operation_exception {csf_};
  
  data_->state |= xtd::threading::thread_state::stopped;
  data_->end_thread_event.set();
  
  lock_guard_threads lock;
  thread_collection::iterator iterator = std::find_if(threads_.begin(), threads_.end(), [&](const auto& value) {return value->data_ ? value->data_->managed_thread_id == data_->managed_thread_id : false;});
  if (iterator != threads_.end()) {
    (*iterator)->data_.reset();
    threads_.erase(iterator);
  }
}
