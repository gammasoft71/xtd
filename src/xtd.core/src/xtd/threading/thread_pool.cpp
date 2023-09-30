#include "../../../include/xtd/threading/manual_reset_event.h"
#include "../../../include/xtd/threading/thread_pool.h"
#include "../../../include/xtd/as.h"
#include "../../../include/xtd/environment.h"
#include "../../../include/xtd/lock.h"
#include <mutex>

using namespace xtd;
using namespace xtd::threading;

size_t thread_pool::max_threads_ = 800;
size_t thread_pool::max_asynchronous_io_threads_ = 800;
size_t thread_pool::min_threads_ = environment::processor_count();
size_t thread_pool::min_asynchronous_io_threads_ = environment::processor_count();

struct thread_pool::static_data {
  threading::semaphore asynchronous_io_semaphore = threading::semaphore(0, as<int32>(thread_pool::max_asynchronous_io_threads_));
  asynchronous_io_thread_vector asynchronous_io_threads;
  manual_reset_event close_asynchronous_io_threads_manual_reset_event {false};
  manual_reset_event close_threads_manual_reset_event {false};
  threading::semaphore semaphore = threading::semaphore(0, as<int32>(thread_pool::max_threads_));
  thread_vector threads;
  thread_pool_item_collection thread_pool_items;
  object thread_pool_items_sync_root;
  thread_pool_asynchronous_io_item_collection thread_pool_asynchronous_io_items;
  object thread_pool_asynchronous_io_items_sync_root;
};

void thread_pool::close() {
  join_all();
}

void thread_pool::get_available_threads(size_t& worker_threads, size_t& completion_port_threads) {
  worker_threads = max_threads_ - get_static_data().thread_pool_items.size();
  completion_port_threads = max_asynchronous_io_threads_ - get_static_data().thread_pool_asynchronous_io_items.size();
}

void thread_pool::get_max_threads(size_t& worker_threads, size_t& completion_port_threads) {
  worker_threads = max_threads_;
  completion_port_threads = max_asynchronous_io_threads_;
}

void thread_pool::get_min_threads(size_t& worker_threads, size_t& completion_port_threads) {
  worker_threads = min_threads_;
  completion_port_threads = min_asynchronous_io_threads_;
}

void thread_pool::join_all() {
  join_all(timeout::infinite);
}

bool thread_pool::join_all(int32 milliseconds_timeout) {
  auto result = join_all_threads(milliseconds_timeout);
  if (result) result = join_all_asynchronous_io_threads(milliseconds_timeout);
  return result;
}

bool thread_pool::join_all(const time_span& timeout) {
  return join_all(as<int32>(timeout.total_milliseconds()));
}

bool thread_pool::queue_user_work_item(const wait_callback& callback) {
  return queue_user_work_item(callback, std::any {});
}

bool thread_pool::queue_user_work_item(const wait_callback& callback, std::any state) {
  lock_(get_static_data().thread_pool_items_sync_root) {
    if (get_static_data().threads.size() == 0) initialize_min_threads();
    if (get_static_data().thread_pool_items.size() == max_threads_) return false;
    if (get_static_data().thread_pool_items.size() + 1 > get_static_data().threads.size()) create_thread();
    get_static_data().thread_pool_items.emplace(get_static_data().thread_pool_items.begin(), callback, state);
  }
  get_static_data().semaphore.release();
  return true;
}

registered_wait_handle thread_pool::register_wait_for_single_object(wait_handle& waitObject, const wait_or_timer_callback& callBack, std::any state, int32 milliseconds_timeout_interval, bool execute_only_once) {
  auto result = registered_wait_handle {};
  lock_(get_static_data().thread_pool_asynchronous_io_items_sync_root) {
    if (get_static_data().asynchronous_io_threads.size() == 0) initialize_min_asynchronous_io_threads();
    if (get_static_data().thread_pool_asynchronous_io_items.size() == max_asynchronous_io_threads_) return result;
    if (get_static_data().thread_pool_items.size() + 1 > get_static_data().threads.size()) create_thread();
    get_static_data().thread_pool_asynchronous_io_items.emplace(get_static_data().thread_pool_asynchronous_io_items.begin(), callBack, state, waitObject, milliseconds_timeout_interval, execute_only_once);
    result.item_ = reinterpret_cast<intptr>(&get_static_data().thread_pool_asynchronous_io_items.back());
  }
  get_static_data().asynchronous_io_semaphore.release();
  return result;
}

registered_wait_handle thread_pool::register_wait_for_single_object(wait_handle& waitObject, const wait_or_timer_callback& callBack, std::any state, int64 milliseconds_timeout_interval, bool execute_only_once)  {
  return register_wait_for_single_object(waitObject, callBack, state, as<int32>(milliseconds_timeout_interval), execute_only_once);
}

registered_wait_handle thread_pool::register_wait_for_single_object(wait_handle& waitObject, const wait_or_timer_callback& callBack, std::any state, const time_span& timeout, bool execute_only_once) {
  return register_wait_for_single_object(waitObject, callBack, state, timeout.total_milliseconds_duration().count(), execute_only_once);
}

registered_wait_handle thread_pool::register_wait_for_single_object(wait_handle& waitObject, const wait_or_timer_callback& callBack, std::any state, uint32 milliseconds_timeout_interval, bool execute_only_once) {
  return register_wait_for_single_object(waitObject, callBack, state, as<int32>(milliseconds_timeout_interval), execute_only_once);
}

bool thread_pool::set_max_threads(size_t worker_threads, size_t completion_port_threads) {
  if (worker_threads < environment::processor_count() || completion_port_threads < environment::processor_count())
    return false;
  
  max_threads_ = worker_threads;
  max_asynchronous_io_threads_ = completion_port_threads;
  
  get_static_data().semaphore = semaphore(as<int32>(get_static_data().thread_pool_items.size()), as<int32>(max_threads_));
  get_static_data().asynchronous_io_semaphore = semaphore(as<int32>(get_static_data().thread_pool_asynchronous_io_items.size()), as<int32>(max_asynchronous_io_threads_));
  
  return true;
}

bool thread_pool::set_min_threads(size_t worker_threads, size_t completion_port_threads) {
  if (worker_threads >= max_threads_ || completion_port_threads >= max_asynchronous_io_threads_)
    return false;
  
  min_threads_ = worker_threads;
  min_asynchronous_io_threads_ = completion_port_threads;
  
  if (get_static_data().threads.size() != 0) initialize_min_threads();
  if (get_static_data().asynchronous_io_threads.size() != 0) initialize_min_asynchronous_io_threads();
  
  return true;
}

void thread_pool::asynchronous_io_run() {
  while (true) {
    if (wait_handle::wait_any(get_static_data().close_asynchronous_io_threads_manual_reset_event, get_static_data().asynchronous_io_semaphore) == 0) break;
    thread_pool_asynchronous_io_item item;
    lock_(get_static_data().thread_pool_asynchronous_io_items_sync_root) {
      item = get_static_data().thread_pool_asynchronous_io_items.back();
      get_static_data().thread_pool_asynchronous_io_items.pop_back();
    }
    
    do {
      auto wait_result = wait_handle::wait_any({&get_static_data().close_asynchronous_io_threads_manual_reset_event, item.wait_object}, item.milliseconds_timeout_interval);
      if (wait_result == 0) break;
      auto timeout = wait_result == wait_handle::wait_timeout;
      if (!item.unregistered) item.callback(item.state, timeout);
    } while (!item.execute_only_once && !item.unregistered);
  }
}

void thread_pool::create_thread() {
  get_static_data().threads.emplace_back(&thread_pool::run);
  get_static_data().threads.back().name("Thread Pool");
  get_static_data().threads.back().is_background(true);
  get_static_data().threads.back().is_thread_pool_thread(true);
  get_static_data().threads.back().start();
}

void thread_pool::create_asynchronous_io_thread() {
  get_static_data().asynchronous_io_threads.emplace_back(&thread_pool::asynchronous_io_run);
  get_static_data().asynchronous_io_threads.back().name("Thread Pool");
  get_static_data().asynchronous_io_threads.back().is_background(true);
  get_static_data().asynchronous_io_threads.back().is_thread_pool_thread(true);
  get_static_data().asynchronous_io_threads.back().start();
}

thread_pool::static_data& thread_pool::get_static_data() {
  static auto data = static_data {};
  return data;
}

void thread_pool::initialize_min_threads() {
  join_all_threads(timeout::infinite);
  get_static_data().threads.clear();
  for (auto index = 0_sz; index < min_threads_; ++index)
    create_thread();
}

void thread_pool::initialize_min_asynchronous_io_threads() {
  join_all_asynchronous_io_threads(timeout::infinite);
  get_static_data().asynchronous_io_threads.clear();
  for (auto index = 0_sz; index < min_asynchronous_io_threads_; ++index)
    create_asynchronous_io_thread();
}

bool thread_pool::join_all_threads(int32 milliseconds_timeout) {
  if (!get_static_data().threads.size()) return true;
  
  for (auto& thread : get_static_data().threads) {
    thread.is_background(false);
    thread.is_thread_pool_thread(false);
  }
  
  get_static_data().close_threads_manual_reset_event.set();
  auto result = thread::join_all(get_static_data().threads, milliseconds_timeout);
  get_static_data().threads.clear();
  get_static_data().close_threads_manual_reset_event.reset();
  return result;
}

bool thread_pool::join_all_asynchronous_io_threads(int32 milliseconds_timeout) {
  if (!get_static_data().asynchronous_io_threads.size()) return true;
  
  for (auto& thread : get_static_data().asynchronous_io_threads) {
    thread.is_background(false);
    thread.is_thread_pool_thread(false);
  }
  
  get_static_data().close_asynchronous_io_threads_manual_reset_event.set();
  auto result = thread::join_all(get_static_data().asynchronous_io_threads, milliseconds_timeout);
  get_static_data().asynchronous_io_threads.clear();
  get_static_data().close_asynchronous_io_threads_manual_reset_event.reset();
  return result;
}

void thread_pool::run() {
  while (true) {
    if (wait_handle::wait_any(get_static_data().close_threads_manual_reset_event, get_static_data().semaphore) == 0) break;
    auto item = thread_pool_item {};
    lock_(get_static_data().thread_pool_items_sync_root) {
      item = get_static_data().thread_pool_items.back();
      get_static_data().thread_pool_items.pop_back();
    }
    item.callback(item.state);
  }
}
