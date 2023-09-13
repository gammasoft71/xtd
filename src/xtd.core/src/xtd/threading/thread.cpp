#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/types.h>
#include <xtd/native/thread.h>
#include <xtd/native/types.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include "../../../include/xtd/threading/manual_reset_event.h"
#include "../../../include/xtd/threading/mutex.h"
#include "../../../include/xtd/threading/thread_abort_exception.h"
#include "../../../include/xtd/threading/thread_interrupted_exception.h"
#include "../../../include/xtd/threading/thread_state_exception.h"
#include "../../../include/xtd/threading/thread.h"
#include "../../../include/xtd/threading/thread_pool.h"
#include "../../../include/xtd/threading/timeout.h"
#include "../../../include/xtd/io/io_exception.h"
#include "../../../include/xtd/diagnostics/stopwatch.h"
#include "../../../include/xtd/argument_exception.h"
#include "../../../include/xtd/environment.h"
#include "../../../include/xtd/int32_object.h"
#include "../../../include/xtd/invalid_operation_exception.h"
#include "../../../include/xtd/not_implemented_exception.h"
#include "../../../include/xtd/as.h"
#include "../../../include/xtd/using.h"
#include <mutex>
#include <thread>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::threading;

namespace {
}

struct thread::data {
  manual_reset_event end_thread_event;
  intptr handle {invalid_handle};
  thread* safe_thread = nullptr;
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

struct thread::static_data {
  std::recursive_mutex threads_mutex;
  thread::thread_collection threads;
};

const intptr thread::invalid_handle = native::types::invalid_handle();

const intptr thread::invalid_thread_id = native::types::invalid_handle();

intptr thread::main_thread_id_ = thread::get_current_thread_id();

thread& thread::current_thread() {
  return get_thread(get_current_thread_id());
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
  std::lock_guard<std::recursive_mutex> lock {get_static_data().threads_mutex};
  auto safe_thread = std::make_shared<thread>(*this);
  data_->safe_thread = safe_thread.get();
  get_static_data().threads.push_back(safe_thread);
}

thread::thread(const xtd::threading::parameterized_thread_start& start) : thread(start, 0) {
}

thread::thread(const xtd::threading::parameterized_thread_start& start, int32 max_stack_size) : data_(std::make_shared<data>()) {
  if (start.is_empty() || max_stack_size < 0) throw argument_exception {csf_};
  data_->managed_thread_id = generate_managed_thread_id();
  data_->parameterized_thread_start = start;
  data_->max_stack_size = max_stack_size;
  std::lock_guard<std::recursive_mutex> lock {get_static_data().threads_mutex};
  auto safe_thread = std::make_shared<thread>(*this);
  data_->safe_thread = safe_thread.get();
  get_static_data().threads.push_back(safe_thread);
}

thread& thread::operator=(const thread& value) {
  if (data_.use_count() == 1) close();
  data_ = value.data_;
  return *this;
}

thread::~thread() {
  //if (data_.use_count() == 1) close();
}

intptr thread::handle() const noexcept {
  return data_->handle;
}

bool thread::is_alive() const noexcept {
  return !is_unstarted() && !is_stopped() && !is_aborted();
}

bool thread::is_background() const noexcept {
  return enum_object<xtd::threading::thread_state>(data_->state).has_flag(xtd::threading::thread_state::background);
}

thread& thread::is_background(bool value) {
  if (value) data_->state |= xtd::threading::thread_state::background;
  else data_->state &= ~xtd::threading::thread_state::background;

  return *this;
}

bool thread::is_main_thread() const noexcept {
  return data_->managed_thread_id == main_managed_thread_id;
}

bool thread::is_thread_pool_thread() const noexcept {
  return data_->is_thread_pool_thread;
}

bool thread::joinable() const noexcept {
  return data_ ? data_->joinable && !is_background() : false;
}

thread& thread::main_thread() {
  static thread main_thread;
  std::lock_guard<std::recursive_mutex> lock {get_static_data().threads_mutex};
  if (main_thread.data_->managed_thread_id != main_managed_thread_id) {
    main_thread.data_->end_thread_event.set();
    main_thread.data_->handle = get_current_thread_handle();
    main_thread.data_->joinable = true;
    main_thread.data_->managed_thread_id = main_managed_thread_id;
    main_thread.data_->state &= ~xtd::threading::thread_state::unstarted;
    main_thread.data_->thread_id = get_current_thread_id();
  }
  return main_thread;
}

int32 thread::managed_thread_id() const noexcept {
  return data_->managed_thread_id;
}

ustring thread::name() const noexcept {
  return data_->name;
}

thread& thread::name(const ustring& value) {
  if (value == data_->name) return *this;
  data_->name = value;
  if (get_current_thread_id() == data_->thread_id) native::thread::set_current_thread_name(value);
  return *this;
}

xtd::threading::thread_priority thread::priority() const noexcept {
  return data_->priority;
}

thread& thread::priority(xtd::threading::thread_priority value) {
  if (!enum_object<>::is_defined(value)) throw argument_exception {csf_};
  if (is_aborted() || is_stopped()) throw thread_state_exception {csf_};
  
  if (data_->priority == value) return *this;
  data_->priority = value;
  if (data_->handle != native::types::invalid_handle()) native::thread::set_priority(data_->handle, as<int32>(value));
  return *this;
}

intptr thread::thread_id() const noexcept {
  return data_->thread_id;
}

xtd::threading::thread_state thread::thread_state() const noexcept {
  return data_->state;
}

void thread::abort() {
  if (is_unstarted() || is_suspended()) throw thread_state_exception {csf_};
  
  data_->state |= xtd::threading::thread_state::abort_requested;
  
  if (is_main_thread()) {
    data_->state &= ~xtd::threading::thread_state::abort_requested;
    environment::abort();
    return;
  }
  
  if (!native::thread::cancel(data_->handle)) data_->state &= ~xtd::threading::thread_state::abort_requested;
  else {
    data_->state |= xtd::threading::thread_state::aborted;
    data_->state &= ~xtd::threading::thread_state::abort_requested;
    data_->end_thread_event.set();
  }
}

void thread::detach() {
  is_background(true);
}

void thread::interrupt() {
  data_->interrupted = true;
}

void thread::join() {
  join(timeout::infinite);
}

bool thread::join(int32 milliseconds_timeout) {
  if (is_unstarted()) throw thread_state_exception {csf_};
  if (milliseconds_timeout < timeout::infinite) throw argument_exception {csf_};
  
  if (data_->interrupted == true) interrupt_internal();
  if (!joinable()) return false;
  
  bool result = data_->end_thread_event.wait_one(milliseconds_timeout);
  if (result == true) {
    auto current_thread = thread::current_thread();
    try {
      current_thread.data_->state |= xtd::threading::thread_state::wait_sleep_join;
      native::thread::join(data_->handle);
      current_thread.data_->state &= ~xtd::threading::thread_state::wait_sleep_join;
    } catch (...) {
      current_thread.data_->state &= ~xtd::threading::thread_state::wait_sleep_join;
    }
    data_->joinable = false;
    std::lock_guard<std::recursive_mutex> lock {get_static_data().threads_mutex};
    thread_collection::iterator iterator = std::find_if(get_static_data().threads.begin(), get_static_data().threads.end(), [&](const auto& value) {return value->data_ ? value->data_->managed_thread_id == data_->managed_thread_id : false;});
    if (iterator == get_static_data().threads.end()) return result;
    (*iterator)->data_.reset();
    get_static_data().threads.erase(iterator);
  }
  return result;
}

bool thread::join(const time_span& timeout) {
  return join(as<int32>(timeout.total_milliseconds()));
}

void thread::join_all() {
  join_all(timeout::infinite);
}

bool thread::join_all(int32 milliseconds_timeout) {
  auto sw = stopwatch::start_new();
  if (!thread_pool::join_all(milliseconds_timeout)) return false;

  std::vector<thread*> thread_pointers;
  for (auto& thread : get_static_data().threads)
    thread_pointers.push_back(thread.get());

  if (sw.elapsed_milliseconds() > milliseconds_timeout || join_all_ptr(thread_pointers, milliseconds_timeout - as<int32>(sw.elapsed_milliseconds())) == false) return false;
  get_static_data().threads.clear();
  return true;
}

bool thread::join_all(const time_span& timeout) {
  return join_all(as<int32>(timeout.total_milliseconds()));
}

void thread::resume() {
  if (is_unstarted() || !is_suspended()) throw thread_state_exception {csf_};
  
  native::thread::resume(data_->handle);
  data_->state &= ~xtd::threading::thread_state::suspended;
}

void thread::sleep(const time_span& timeout) {
  sleep(as<int32>(timeout.total_milliseconds_duration().count()));
}

void thread::sleep(int32 milliseconds_timeout) {
  if (milliseconds_timeout < timeout::infinite) throw argument_exception {csf_};
  
  auto current_thread = thread::current_thread();
  
  if (current_thread.data_) current_thread.data_->state |= xtd::threading::thread_state::wait_sleep_join;
  if (current_thread.data_ && current_thread.data_->interrupted) current_thread.interrupt_internal();
  native::thread::sleep(milliseconds_timeout);
  if (current_thread.data_ && current_thread.data_->interrupted) current_thread.interrupt_internal();
  if (current_thread.data_) current_thread.data_->state &= ~xtd::threading::thread_state::wait_sleep_join;
}

void thread::spin_wait(int32 iterations) {
  for (auto count = 0; count < iterations; ++count) {
    if (count < iterations - 1) yield();
    else std::this_thread::sleep_for(std::chrono::microseconds(1));
  }
}

void thread::start() {
  if (!is_unstarted()) throw thread_state_exception {csf_};
  if (data_->thread_start.is_empty() && data_->parameterized_thread_start.is_empty()) throw invalid_operation_exception {csf_};
  data_->state &= ~xtd::threading::thread_state::unstarted;
  data_->joinable = true;
  data_->parameter = nullptr;
  data_->handle = native::thread::create([&](intptr arg) {
    reinterpret_cast<threading::thread*>(arg)->thread_proc();
  }, reinterpret_cast<intptr>(data_->safe_thread), data_->max_stack_size, is_suspended(), data_->thread_id);
  if (data_->handle == invalid_handle) throw io::io_exception {csf_};
}

void thread::start(std::any param) {
  if (!is_unstarted()) throw thread_state_exception {csf_};
  if (data_->parameterized_thread_start.is_empty()) throw invalid_operation_exception {csf_};
  data_->state &= ~xtd::threading::thread_state::unstarted;
  data_->joinable = true;
  data_->parameter = param;
  data_->handle = native::thread::create([](intptr arg) {
    reinterpret_cast<thread*>(arg)->thread_proc();
  }, reinterpret_cast<intptr>(data_->safe_thread), data_->max_stack_size, is_suspended(), data_->thread_id);
  if (data_->handle == invalid_handle) throw io::io_exception {csf_};
}

thread thread::start_new(const xtd::threading::thread_start& start) {
  auto thread = threading::thread {start};
  thread.start();
  return thread;
}

thread thread::start_new(const xtd::threading::parameterized_thread_start& start, std::any obj) {
  auto thread = threading::thread {start};
  thread.start(obj);
  return thread;
}

void thread::suspend() {
  if (!is_alive()) throw thread_state_exception {csf_};
  
  data_->state |= xtd::threading::thread_state::suspend_requested;
  native::thread::suspend(data_->handle);
  data_->state |= xtd::threading::thread_state::suspended;
  data_->state &= ~xtd::threading::thread_state::suspend_requested;
}

bool thread::yield() {
  return native::thread::yield();
}

bool thread::join_all(const std::initializer_list<std::shared_ptr<thread>>& threads){
  return join_all(threads, timeout::infinite);
}

bool thread::join_all(const std::initializer_list<std::shared_ptr<thread>>& threads, int32 milliseconds_timeout) {
  std::vector<thread*> threads_pointers;
  for (auto& thread : threads)
    threads_pointers.push_back(thread.get());
  return join_all_ptr(threads_pointers, milliseconds_timeout);
}

bool thread::join_all(const std::initializer_list<std::shared_ptr<thread>>& threads, const time_span& timeout) {
  return join_all(threads, as<int32>(timeout.total_milliseconds_duration().count()));
}

bool thread::join_all(const std::initializer_list<std::unique_ptr<thread>>& threads){
  return join_all(threads, timeout::infinite);
}

bool thread::join_all(const std::initializer_list<std::unique_ptr<thread>>& threads, int32 milliseconds_timeout) {
  std::vector<thread*> threads_pointers;
  for (auto& thread : threads)
    threads_pointers.push_back(thread.get());
  return join_all_ptr(threads_pointers, milliseconds_timeout);
}

bool thread::join_all(const std::initializer_list<std::unique_ptr<thread>>& threads, const time_span& timeout) {
  return join_all(threads, as<int32>(timeout.total_milliseconds_duration().count()));
}

bool thread::join_all(const std::vector<std::shared_ptr<thread>>& threads) {
  return join_all(threads, timeout::infinite);
}

bool thread::join_all(const std::vector<std::shared_ptr<thread>>& threads, int32 milliseconds_timeout) {
  std::vector<thread*> threads_pointers;
  for (auto& thread : threads)
    threads_pointers.push_back(thread.get());
  return join_all_ptr(threads_pointers, milliseconds_timeout);
}

bool thread::join_all(const std::vector<std::shared_ptr<thread>>& threads, const time_span& timeout) {
  return join_all(threads, as<int32>(timeout.total_milliseconds_duration().count()));
}

bool thread::join_all(const std::vector<std::unique_ptr<thread>>& threads) {
  return join_all(threads, timeout::infinite);
}

bool thread::join_all(const std::vector<std::unique_ptr<thread>>& threads, int32 milliseconds_timeout) {
  std::vector<thread*> threads_pointers;
  for (auto& thread : threads)
    threads_pointers.push_back(thread.get());
  return join_all_ptr(threads_pointers, milliseconds_timeout);
}

bool thread::join_all(const std::vector<std::unique_ptr<thread>>& threads, const time_span& timeout) {
  return join_all(threads, as<int32>(timeout.total_milliseconds_duration().count()));
}

void thread::close() {
  if (is_main_thread() || is_unmanaged_thread()) return;
  
  if (data_->joinable) join();
}

bool thread::do_wait(wait_handle& wait_handle, int32 milliseconds_timeout) {
  if (milliseconds_timeout < timeout::infinite) throw argument_exception {csf_};
  
  auto current_thread = thread::current_thread();
  current_thread.data_->state |= xtd::threading::thread_state::wait_sleep_join;
  if (current_thread.data_->interrupted) current_thread.interrupt_internal();
  try {
    auto result = wait_handle.wait(milliseconds_timeout);
    current_thread.data_->state &= ~xtd::threading::thread_state::wait_sleep_join;
    return result;
  } catch (...) {
    current_thread.data_->state &= ~xtd::threading::thread_state::wait_sleep_join;
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

thread::static_data& thread::get_static_data() {
  static static_data data;
  return data;
}

thread& thread::get_thread(intptr thread_id) {
  std::lock_guard<std::recursive_mutex> lock {get_static_data().threads_mutex};
  if (thread_id == main_thread_id_) return main_thread();
  
  for (auto& thread : get_static_data().threads)
    if (thread->data_ && thread->data_->thread_id == thread_id)
      return *thread;
  
  return unmanaged_thread();
}

void thread::interrupt_internal() {
  struct cancel_thread {
    ~cancel_thread() {
      if (data_->managed_thread_id != 1) native::thread::cancel(data_->handle);}
    thread::data* data_ = nullptr;
  } cancel_thread {data_.get()};
  data_->interrupted = false;
  data_->state &= ~xtd::threading::thread_state::wait_sleep_join;
  if (data_->managed_thread_id == 1) environment::raise(signal::interrupt);
  else throw thread_interrupted_exception {csf_};
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

void thread::is_thread_pool_thread(bool value) noexcept {
  data_->is_thread_pool_thread = value;
}

bool thread::is_unmanaged_thread() const noexcept {
  return data_->managed_thread_id == unmanaged_thread_id;
}

bool thread::is_unstarted() const noexcept {
  return enum_object<xtd::threading::thread_state>(data_->state).has_flag(xtd::threading::thread_state::unstarted);
}

bool thread::is_wait_sleep_join() const noexcept {
  return enum_object<xtd::threading::thread_state>(data_->state).has_flag(xtd::threading::thread_state::wait_sleep_join);
}

bool thread::join_all_ptr(const std::vector<thread*>& threads, int32 milliseconds_timeout) {
  if (milliseconds_timeout < timeout::infinite) throw argument_exception {csf_};
  
  thread::yield();
  if (milliseconds_timeout == timeout::infinite) {
    for (auto thread : threads) {
      if (thread->joinable()) thread->join();
      thread::yield();
    }
    return true;
  }
  
  auto sw = stopwatch::start_new();
  for (auto thread : threads) {
    if (sw.elapsed_milliseconds() > milliseconds_timeout || (thread->joinable() && thread->join(milliseconds_timeout - as<int32>(sw.elapsed_milliseconds())) == false)) return false;
  }
  return true;
}

void thread::thread_proc() {
  if (data_->thread_id == invalid_thread_id) data_->thread_id = get_current_thread_id();
  if (!data_->name.empty()) native::thread::set_current_thread_name(data_->name);
  if (data_->priority != xtd::threading::thread_priority::normal) native::thread::set_priority(data_->handle, as<int32>(data_->priority));

  if (!data_->thread_start.is_empty()) data_->thread_start();
  else if (!data_->parameterized_thread_start.is_empty()) data_->parameterized_thread_start(data_->parameter);
  else throw invalid_operation_exception {csf_};
  
  if (is_aborted()) throw thread_abort_exception {csf_};
  if (is_aborted()) throw thread_interrupted_exception {csf_};
  
  data_->state |= xtd::threading::thread_state::stopped;
  data_->end_thread_event.set();
  
  if (!is_background()) return;
  std::lock_guard<std::recursive_mutex> lock {get_static_data().threads_mutex};
  thread_collection::iterator iterator = std::find_if(get_static_data().threads.begin(), get_static_data().threads.end(), [&](const auto& value) {return value->data_ ? value->data_->managed_thread_id == data_->managed_thread_id : false;});
  if (iterator == get_static_data().threads.end()) return;
  (*iterator)->data_.reset();
  get_static_data().threads.erase(iterator);
}

thread& thread::unmanaged_thread() {
  static thread unmanaged_thread;
  if (unmanaged_thread.is_unstarted()) {
    unmanaged_thread.data_->state &= ~xtd::threading::thread_state::unstarted;
    unmanaged_thread.data_->state |= xtd::threading::thread_state::background;
  }
  unmanaged_thread.data_->handle = get_current_thread_handle();
  unmanaged_thread.data_->thread_id = get_current_thread_id();
  return unmanaged_thread;
}
