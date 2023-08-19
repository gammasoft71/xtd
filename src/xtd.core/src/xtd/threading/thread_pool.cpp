#include "../../../include/xtd/threading/thread_pool.h"
#include "../../../include/xtd/lock.h"
#include "../../../include/xtd/as.h"
#include "../../../include/xtd/environment.h"

using namespace xtd;
using namespace xtd::threading;

thread_pool::asynchronous_io_thread_vector::asynchronous_io_thread_vector() {
}

thread_pool::asynchronous_io_thread_vector::asynchronous_io_thread_vector(size_t count) : std::vector<thread>(count) {
}

thread_pool::asynchronous_io_thread_vector::~asynchronous_io_thread_vector() {
  join_all_asynchronous_io_threads(timeout::infinite);
}

thread_pool::thread_vector::thread_vector() {
}

thread_pool::thread_vector::thread_vector(size_t count) : std::vector<thread>(count) {
}

thread_pool::thread_vector::~thread_vector() {
  join_all_threads(timeout::infinite);
}

size_t thread_pool::max_threads_ = 800;
size_t thread_pool::max_asynchronous_io_threads_ = 800;
size_t thread_pool::min_threads_ = environment::processor_count();
size_t thread_pool::min_asynchronous_io_threads_ = environment::processor_count();

semaphore thread_pool::asynchronous_io_semaphore_ = semaphore(0, as<int32>(thread_pool::max_asynchronous_io_threads_));
thread_pool::asynchronous_io_thread_vector thread_pool::asynchronous_io_threads_;
bool thread_pool::closed_ = false;
semaphore thread_pool::semaphore_ = semaphore(0, as<int32>(thread_pool::max_threads_));
thread_pool::thread_vector thread_pool::threads_;
thread_pool::thread_pool_item_collection thread_pool::thread_pool_items_;
object thread_pool::thread_pool_items_sync_root_;
thread_pool::thread_pool_asynchronous_io_item_collection thread_pool::thread_pool_asynchronous_io_items_;
object thread_pool::thread_pool_asynchronous_io_items_sync_root_;

void thread_pool::close() {
  join_all(timeout::infinite);
}

void thread_pool::get_available_threads(size_t& worker_threads, size_t& completion_port_threads) {
  worker_threads = max_threads_ - thread_pool_items_.size();
  completion_port_threads = max_asynchronous_io_threads_ - thread_pool_asynchronous_io_items_.size();
}

void thread_pool::get_max_threads(size_t& worker_threads, size_t& completion_port_threads) {
  worker_threads = max_threads_;
  completion_port_threads = max_asynchronous_io_threads_;
}

void thread_pool::get_min_threads(size_t& worker_threads, size_t& completion_port_threads) {
  worker_threads = min_threads_;
  completion_port_threads = min_asynchronous_io_threads_;
}

bool thread_pool::queue_user_work_item(const wait_callback& call_back) {
  return queue_user_work_item(call_back, std::any {});
}

bool thread_pool::queue_user_work_item(const wait_callback& call_back, std::any state) {
  if (threads_.size() == 0) initialize_min_threads();
  lock_(thread_pool_items_sync_root_) {
    if (thread_pool_items_.size() == max_threads_) return false;
    if (thread_pool_items_.size() + 1 > threads_.size()) create_thread();
    thread_pool_items_.emplace_back(call_back, state);
    semaphore_.release();
  }
  return true;
}

registered_wait_handle thread_pool::register_wait_for_single_object(wait_handle& waitObject, const wait_or_timer_callback& callBack, std::any state, int32 milliseconds_timeout_interval, bool execute_only_once) {
  if (asynchronous_io_threads_.size() == 0) initialize_min_asynchronous_io_threads();
  registered_wait_handle result;
  lock_(thread_pool_asynchronous_io_items_sync_root_) {
    if (thread_pool_asynchronous_io_items_.size() == max_asynchronous_io_threads_) return result;
    if (thread_pool_items_.size() + 1 > threads_.size()) create_thread();
    thread_pool_asynchronous_io_items_.emplace_back(callBack, state, waitObject, milliseconds_timeout_interval, execute_only_once);
    result.item_ = reinterpret_cast<intptr>(&thread_pool_asynchronous_io_items_.back());
    asynchronous_io_semaphore_.release();
  }
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
  
  lock_(thread_pool_items_sync_root_)
    semaphore_ = semaphore(as<int32>(thread_pool_items_.size()), as<int32>(max_threads_));
  lock_(thread_pool_asynchronous_io_items_sync_root_)
    asynchronous_io_semaphore_ = semaphore(as<int32>(thread_pool_asynchronous_io_items_.size()), as<int32>(max_asynchronous_io_threads_));
  
  return true;
}

bool thread_pool::set_min_threads(size_t worker_threads, size_t completion_port_threads) {
  if (worker_threads < 0 || completion_port_threads < 0 || worker_threads >= max_threads_ || completion_port_threads >= max_asynchronous_io_threads_)
    return false;
  
  min_threads_ = worker_threads;
  min_asynchronous_io_threads_ = completion_port_threads;
  
  if (threads_.size() != 0) initialize_min_threads();
  if (asynchronous_io_threads_.size() != 0) initialize_min_asynchronous_io_threads();
  
  return true;
}

void thread_pool::asynchronous_io_run() {
  while (!closed_) {
    asynchronous_io_semaphore_.wait_one();
    if (closed_) break;
    thread_pool_asynchronous_io_item item;
    lock_(thread_pool_asynchronous_io_items_sync_root_)
      item = thread_pool_asynchronous_io_items_[0];
    thread_pool_asynchronous_io_items_.erase(thread_pool_asynchronous_io_items_.begin());
    
    do {
      bool timeout = !item.wait_object->wait_one(item.milliseconds_timeout_interval);
      if (!item.unregistered)
        item.callback(item.state, timeout);
    } while (!item.execute_only_once && !item.unregistered);
  }
}

void thread_pool::create_thread() {
  threads_.emplace_back(thread_start {&thread_pool::run});
  threads_.back().name("Thread Pool");
  threads_.back().is_background(true);
  threads_.back().is_thread_pool_thread(true);
  threads_.back().start();
}

void thread_pool::create_asynchronous_io_thread() {
  asynchronous_io_threads_.emplace_back(thread_start {&thread_pool::asynchronous_io_run});
  asynchronous_io_threads_.back().name("Thread Pool");
  asynchronous_io_threads_.back().is_background(true);
  asynchronous_io_threads_.back().is_thread_pool_thread(true);
  asynchronous_io_threads_.back().start();
}

void thread_pool::initialize_min_threads() {
  join_all_threads(timeout::infinite);
  threads_ = thread_vector {};
  for (size_t i = 0; i < min_threads_; ++i)
    create_thread();
}

void thread_pool::initialize_min_asynchronous_io_threads() {
  join_all_asynchronous_io_threads(timeout::infinite);
  asynchronous_io_threads_ = asynchronous_io_thread_vector();
  for (size_t i = 0; i < min_asynchronous_io_threads_; ++i)
    create_asynchronous_io_thread();
}

bool thread_pool::join_all(int32 milliseconds_timeout) {
  closed_ = true;
  auto result = join_all_threads(milliseconds_timeout);
  if (result) result = join_all_asynchronous_io_threads(milliseconds_timeout);
  closed_ = false;

  return result;
}

bool thread_pool::join_all_threads(int32 milliseconds_timeout) {
  if (!threads_.size()) return true;
  for (auto& thread : threads_) {
    thread.is_background(false);
    thread.is_thread_pool_thread(false);
  }
  
  semaphore_.release(as<int32>(threads_.size()));
  auto result = thread::join_all(threads_, milliseconds_timeout);
  threads_.clear();
  return result;
}

bool thread_pool::join_all_asynchronous_io_threads(int32 milliseconds_timeout) {
  if (!asynchronous_io_threads_.size()) return true;
  for (auto& thread : asynchronous_io_threads_) {
    thread.is_background(false);
    thread.is_thread_pool_thread(false);
  }
  
  asynchronous_io_semaphore_.release(as<int32>(asynchronous_io_threads_.size()));
  auto result = thread::join_all(asynchronous_io_threads_, milliseconds_timeout);
  asynchronous_io_threads_.clear();
  return result;
}

void thread_pool::run() {
  while (!closed_) {
    semaphore_.wait_one();
    if (closed_) break;
    thread_pool_item item;
    lock_(thread_pool_items_sync_root_) {
      item = thread_pool_items_[0];
      thread_pool_items_.erase(thread_pool_items_.begin());
    }
    item.callback(item.state);
  }
}
