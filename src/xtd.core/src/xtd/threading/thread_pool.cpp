#include "../../../include/xtd/threading/manual_reset_event.hpp"
#include "../../../include/xtd/threading/thread_pool.hpp"
#include "../../../include/xtd/as.hpp"
#include "../../../include/xtd/environment.hpp"
#include "../../../include/xtd/lock.hpp"
#include <mutex>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::threading;

using asynchronous_io_thread_list = list<thread>;
using thread_list = list<thread>;

size_t thread_pool::max_threads_ = 800;
size_t thread_pool::max_asynchronous_io_threads_ = 800;
size_t thread_pool::min_threads_ = environment::processor_count();
size_t thread_pool::min_asynchronous_io_threads_ = environment::processor_count();

struct thread_pool::static_data {
  threading::semaphore asynchronous_io_semaphore = threading::semaphore(0, as<int32>(thread_pool::max_asynchronous_io_threads_));
  asynchronous_io_thread_list asynchronous_io_threads;
  manual_reset_event close_asynchronous_io_threads_manual_reset_event {false};
  manual_reset_event close_threads_manual_reset_event {false};
  threading::semaphore semaphore = threading::semaphore(0, as<int32>(thread_pool::max_threads_));
  thread_list threads;
  thread_pool_item_collection thread_pool_items;
  object thread_pool_items_sync_root;
  thread_pool_asynchronous_io_item_collection thread_pool_asynchronous_io_items;
  object thread_pool_asynchronous_io_items_sync_root;
  
  ~static_data() {
    close_asynchronous_io_threads_manual_reset_event.set();
    close_threads_manual_reset_event.set();
    for (auto& thread : threads)
      thread.close();
    for (auto& asynchronous_io_thread : asynchronous_io_threads)
      asynchronous_io_thread.close();
  }
};

thread_pool::static_data thread_pool::static_data_ {};

void thread_pool::close() {
  join_all();
}

void thread_pool::get_available_threads(size_t& worker_threads, size_t& completion_port_threads) {
  worker_threads = max_threads_ - static_data_.thread_pool_items.count();
  completion_port_threads = max_asynchronous_io_threads_ - static_data_.thread_pool_asynchronous_io_items.count();
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
  return queue_user_work_item(callback, any_object {});
}

bool thread_pool::queue_user_work_item(const wait_callback& callback, const any_object& state) {
  lock_(static_data_.thread_pool_items_sync_root) {
    if (static_data_.threads.count() == 0) initialize_min_threads();
    if (static_data_.thread_pool_items.count() == max_threads_) return false;
    if (static_data_.thread_pool_items.count() + 1 > static_data_.threads.count()) create_thread();
    static_data_.thread_pool_items.emplace(static_data_.thread_pool_items.begin(), callback, state);
  }
  static_data_.semaphore.release();
  return true;
}

registered_wait_handle thread_pool::register_wait_for_single_object(wait_handle& wait_object, const wait_or_timer_callback& callback, const any_object& state, int32 milliseconds_timeout_interval, bool execute_only_once) {
  auto result = registered_wait_handle {};
  lock_(static_data_.thread_pool_asynchronous_io_items_sync_root) {
    if (static_data_.asynchronous_io_threads.count() == 0) initialize_min_asynchronous_io_threads();
    if (static_data_.thread_pool_asynchronous_io_items.count() == max_asynchronous_io_threads_) return result;
    if (static_data_.thread_pool_items.count() + 1 > static_data_.threads.count()) create_thread();
    static_data_.thread_pool_asynchronous_io_items.emplace(static_data_.thread_pool_asynchronous_io_items.begin(), callback, state, wait_object, milliseconds_timeout_interval, execute_only_once);
    result.item_ = reinterpret_cast<intptr>(&static_data_.thread_pool_asynchronous_io_items[static_data_.thread_pool_asynchronous_io_items.count() - 1]);
  }
  static_data_.asynchronous_io_semaphore.release();
  return result;
}

registered_wait_handle thread_pool::register_wait_for_single_object(wait_handle& wait_object, const wait_or_timer_callback& callback, const any_object& state, int64 milliseconds_timeout_interval, bool execute_only_once)  {
  return register_wait_for_single_object(wait_object, callback, state, as<int32>(milliseconds_timeout_interval), execute_only_once);
}

registered_wait_handle thread_pool::register_wait_for_single_object(wait_handle& wait_object, const wait_or_timer_callback& callback, const any_object& state, const time_span& timeout, bool execute_only_once) {
  return register_wait_for_single_object(wait_object, callback, state, as<int32>(timeout.total_milliseconds_duration().count()), execute_only_once);
}

registered_wait_handle thread_pool::register_wait_for_single_object(wait_handle& wait_object, const wait_or_timer_callback& callback, const any_object& state, uint32 milliseconds_timeout_interval, bool execute_only_once) {
  return register_wait_for_single_object(wait_object, callback, state, as<int32>(milliseconds_timeout_interval), execute_only_once);
}

bool thread_pool::set_max_threads(size_t worker_threads, size_t completion_port_threads) {
  if (worker_threads < environment::processor_count() || completion_port_threads < environment::processor_count())
    return false;
    
  max_threads_ = worker_threads;
  max_asynchronous_io_threads_ = completion_port_threads;
  
  static_data_.semaphore = semaphore(as<int32>(static_data_.thread_pool_items.count()), as<int32>(max_threads_));
  static_data_.asynchronous_io_semaphore = semaphore(as<int32>(static_data_.thread_pool_asynchronous_io_items.count()), as<int32>(max_asynchronous_io_threads_));
  
  return true;
}

bool thread_pool::set_min_threads(size_t worker_threads, size_t completion_port_threads) {
  if (worker_threads >= max_threads_ || completion_port_threads >= max_asynchronous_io_threads_)
    return false;
    
  min_threads_ = worker_threads;
  min_asynchronous_io_threads_ = completion_port_threads;
  
  if (static_data_.threads.count() != 0) initialize_min_threads();
  if (static_data_.asynchronous_io_threads.count() != 0) initialize_min_asynchronous_io_threads();
  
  return true;
}

void thread_pool::asynchronous_io_run() {
  while (true) {
    if (wait_handle::wait_any(static_data_.close_asynchronous_io_threads_manual_reset_event, static_data_.asynchronous_io_semaphore) == 0) break;
    thread_pool_asynchronous_io_item item;
    lock_(static_data_.thread_pool_asynchronous_io_items_sync_root) {
      item = static_data_.thread_pool_asynchronous_io_items[static_data_.thread_pool_asynchronous_io_items.count() - 1];
      static_data_.thread_pool_asynchronous_io_items.pop_back();
    }
    
    do {
      auto wait_result = wait_handle::wait_any({&static_data_.close_asynchronous_io_threads_manual_reset_event, item.wait_object()}, item.milliseconds_timeout_interval());
      if (wait_result == 0) break;
      auto timeout = wait_result == wait_handle::wait_timeout;
      if (!item.unregistered()) item.run(timeout);
    } while (!item.execute_only_once() && !item.unregistered());
  }
}

void thread_pool::create_thread() {
  static_data_.threads.emplace_back(&thread_pool::run);
  static_data_.threads[static_data_.threads.count() - 1].name("Thread Pool");
  static_data_.threads[static_data_.threads.count() - 1].is_background(true);
  static_data_.threads[static_data_.threads.count() - 1].is_thread_pool_thread(true);
  static_data_.threads[static_data_.threads.count() - 1].start();
}

void thread_pool::create_asynchronous_io_thread() {
  static_data_.asynchronous_io_threads.emplace_back(&thread_pool::asynchronous_io_run);
  static_data_.asynchronous_io_threads[static_data_.threads.count() - 1].name("Thread Pool");
  static_data_.asynchronous_io_threads[static_data_.threads.count() - 1].is_background(true);
  static_data_.asynchronous_io_threads[static_data_.threads.count() - 1].is_thread_pool_thread(true);
  static_data_.asynchronous_io_threads[static_data_.threads.count() - 1].start();
}

void thread_pool::initialize_min_threads() {
  join_all_threads(timeout::infinite);
  static_data_.threads.clear();
  for (auto index = 0_z; index < min_threads_; ++index)
    create_thread();
}

void thread_pool::initialize_min_asynchronous_io_threads() {
  join_all_asynchronous_io_threads(timeout::infinite);
  static_data_.asynchronous_io_threads.clear();
  for (auto index = 0_z; index < min_asynchronous_io_threads_; ++index)
    create_asynchronous_io_thread();
}

bool thread_pool::join_all_threads(int32 milliseconds_timeout) {
  if (!static_data_.threads.count()) return true;
  
  for (auto& thread : static_data_.threads) {
    thread.is_background(false);
    thread.is_thread_pool_thread(false);
  }
  
  static_data_.close_threads_manual_reset_event.set();
  auto result = thread::join_all(static_data_.threads, milliseconds_timeout);
  static_data_.threads.clear();
  static_data_.close_threads_manual_reset_event.reset();
  return result;
}

bool thread_pool::join_all_asynchronous_io_threads(int32 milliseconds_timeout) {
  if (!static_data_.asynchronous_io_threads.count()) return true;
  
  for (auto& thread : static_data_.asynchronous_io_threads) {
    thread.is_background(false);
    thread.is_thread_pool_thread(false);
  }
  
  static_data_.close_asynchronous_io_threads_manual_reset_event.set();
  auto result = thread::join_all(static_data_.asynchronous_io_threads, milliseconds_timeout);
  static_data_.asynchronous_io_threads.clear();
  static_data_.close_asynchronous_io_threads_manual_reset_event.reset();
  return result;
}

void thread_pool::run() {
  while (true) {
    if (wait_handle::wait_any(static_data_.close_threads_manual_reset_event, static_data_.semaphore) == 0) break;
    auto item = thread_pool_item {};
    lock_(static_data_.thread_pool_items_sync_root) {
      item = static_data_.thread_pool_items[static_data_.thread_pool_items.count() - 1];
      static_data_.thread_pool_items.pop_back();
    }
    item.run();
  }
}
