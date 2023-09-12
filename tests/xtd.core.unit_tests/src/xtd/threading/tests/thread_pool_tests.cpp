#include <xtd/threading/thread_pool>
#include <xtd/threading/interlocked>
#include <xtd/tunit/assert>
#include <xtd/tunit/string_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(thread_pool_tests) {
  public:
    void test_method_(get_max_threads) {
      size_t max_worker_threads = 0;
      size_t max_completion_port_threads = 0;
      thread_pool::get_max_threads(max_worker_threads, max_completion_port_threads);
      assert::are_equal(800ul, max_worker_threads, csf_);
      assert::are_equal(800ul, max_completion_port_threads, csf_);
    }
    
    void test_method_(get_min_threads) {
      size_t min_worker_threads = 0;
      size_t min_completion_port_threads = 0;
      thread_pool::get_min_threads(min_worker_threads, min_completion_port_threads);
      assert::are_equal(environment::processor_count(), min_worker_threads, csf_);
      assert::are_equal(environment::processor_count(), min_completion_port_threads, csf_);
    }
    
    void test_method_(queue_user_work_item_one) {
      auto count = 0;
      auto action = wait_callback {[&] {
        interlocked::increment(count);
      }};
      thread_pool::queue_user_work_item(action);
      thread::sleep(5);
      thread_pool::close();
      assert::are_equal(1, count, csf_);
    }
    
    void test_method_(queue_user_work_item_after_close) {
      auto count = 0;
      auto action = wait_callback {[&] {
        interlocked::increment(count);
      }};
      thread_pool::queue_user_work_item(action);
      thread::sleep(5);
      thread_pool::close();
      thread_pool::queue_user_work_item(action);
      thread::sleep(5);
      thread_pool::close();
      assert::are_equal(2, count, csf_);
    }

    void test_method_(queue_user_work_item_min_thread) {
      size_t min_worker_threads = 0;
      size_t min_completion_port_threads = 0;
      thread_pool::get_min_threads(min_worker_threads, min_completion_port_threads);
      auto count = 0;
      auto action = wait_callback {[&] {
        interlocked::increment(count);
      }};
      for (auto index = 0ul; index < min_worker_threads; ++index)
        thread_pool::queue_user_work_item(action);
      thread::sleep(5);
      thread_pool::close();
      assert::are_equal(min_worker_threads, as<size_t>(count), csf_);
    }
    
    void test_method_(queue_user_work_item_max_thread) {
      size_t max_worker_threads = 0;
      size_t max_completion_port_threads = 0;
      thread_pool::get_max_threads(max_worker_threads, max_completion_port_threads);
      auto count = 0;
      auto action = wait_callback {[&] {
        interlocked::increment(count);
      }};
      for (auto index = 0ul; index < max_worker_threads; ++index)
        thread_pool::queue_user_work_item(action);
      thread::sleep(5);
      thread_pool::close();
      assert::are_equal(max_worker_threads, count, csf_);
    }
  };
}
