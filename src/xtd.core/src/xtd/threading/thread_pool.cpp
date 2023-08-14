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
  closed_ = true;
  
  for (auto& thread : *this)
    if (thread.thread_state() != thread_state::unstarted)
      asynchronous_io_semaphore_.release();
  
  for (auto& thread : *this)
    if (thread.thread_state() != thread_state::unstarted && (thread.thread_state() & thread_state::aborted) != thread_state::aborted)
      thread.join();
  
  closed_ = false;
}

thread_pool::thread_vector::thread_vector() {
}

thread_pool::thread_vector::thread_vector(size_t count) : std::vector<thread>(count) {
}

thread_pool::thread_vector::~thread_vector() {
  closed_ = true;
  
  for (auto& thread : *this)
    if (thread.thread_state() != thread_state::unstarted)
      semaphore_.release();
  
  for (auto& thread : *this)
    if (thread.thread_state() != thread_state::unstarted && (thread.thread_state() & thread_state::aborted) != thread_state::aborted)
      thread.join();
  closed_ = false;
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
  if (threads_.size() == 0)
    create_threads();
  lock_(thread_pool_items_sync_root_) {
    if (thread_pool_items_.size() == max_threads_) return false;
    thread_pool_items_.emplace_back(call_back);
    semaphore_.release();
  }
  return true;
}

bool thread_pool::queue_user_work_item(const wait_callback& call_back, std::any state) {
  if (threads_.size() == 0)
    create_threads();
  lock_(thread_pool_items_sync_root_) {
    if (thread_pool_items_.size() == max_threads_) return false;
    thread_pool_items_.emplace_back(call_back, state);
    semaphore_.release();
  }
  return true;
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
  
  if (threads_.size() != 0)
    create_threads();
  
  if (asynchronous_io_threads_.size() != 0)
    create_asynchronous_io_threads();
  
  return true;
}

void thread_pool::asynchronous_io_run() {
  while (!closed_) {
    asynchronous_io_semaphore_.wait_one();
    if (!closed_) {
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
}

void thread_pool::create_threads() {
  threads_ = thread_vector(min_threads_);
  for (size_t i = 0; i < min_threads_; ++i) {
    threads_[i] = thread {thread_start {&thread_pool::run}};
    threads_[i].name("Thread Pool");
    threads_[i].is_thread_pool_thread(true);
    threads_[i].is_background(true);
    threads_[i].start();
  }
}

void thread_pool::create_asynchronous_io_threads() {
  asynchronous_io_threads_ = asynchronous_io_thread_vector(min_asynchronous_io_threads_);
  for (size_t i = 0; i < min_asynchronous_io_threads_; ++i) {
    asynchronous_io_threads_[i] = thread {thread_start {&thread_pool::asynchronous_io_run}};
    asynchronous_io_threads_[i].name("Thread Pool");
    asynchronous_io_threads_[i].is_thread_pool_thread(true);
    asynchronous_io_threads_[i].is_background(true);
    asynchronous_io_threads_[i].start();
  }
}

void thread_pool::run() {
  while (!closed_) {
    semaphore_.wait_one();
    if (!closed_) {
      thread_pool_item item;
      lock_(thread_pool_items_sync_root_)
        item = thread_pool_items_[0];
      thread_pool_items_.erase(thread_pool_items_.begin());
      item.callback(item.state);
    }
  }
}
