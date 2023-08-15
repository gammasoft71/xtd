#include <xtd/threading/thread.h>
#include <xtd/threading/interlocked.h>
#include <xtd/xtd.tunit>
#include <thread>

using namespace xtd::threading;
using namespace xtd::tunit;

// Used by xtd::tests::thread_tests unit tests.
struct __xtd_threads__ {
  static void reset_threads() {
    xtd::threading::thread::reset_threads();
  }
};

namespace xtd::tests {
  class test_class_(thread_tests) {
  public:
    void test_method_(constructor_empty) {
      thread t;
      assert::are_equal(thread::invalid_handle, t.handle(), csf_);
      assert::is_false(t.is_alive(), csf_);
      assert::is_false(t.is_background(), csf_);
      assert::is_false(t.is_thread_pool_thread(), csf_);
      assert::is_false(t.joinable(), csf_);
      assert::is_zero(t.managed_thread_id(), csf_);
      assert::is_empty(t.name(), csf_);
      assert::are_equal(thread::invalid_thread_id, t.thread_id(), csf_);
      assert::are_equal(thread_priority::normal, t.priority(), csf_);
      assert::are_equal(thread_state::unstarted, t.thread_state(), csf_);
    }
    
    void test_method_(constructor_with_empty_thread_start) {
      assert::throws<argument_exception>([]{thread t {thread_start {}};}, csf_);
    }
    
    void test_method_(constructor_with_thread_start_and_negative_max_stack_size) {
      assert::throws<argument_exception>([]{thread t {thread_start {[] {}}, -1};}, csf_);
    }
    
    void test_method_(constructor_with_thread_start) {
      thread t {thread_start {[] {}}};
      assert::are_equal(thread::invalid_handle, t.handle(), csf_);
      assert::is_false(t.is_alive(), csf_);
      assert::is_false(t.is_background(), csf_);
      assert::is_false(t.is_thread_pool_thread(), csf_);
      assert::is_false(t.joinable(), csf_);
      assert::is_not_zero(t.managed_thread_id(), csf_);
      assert::is_empty(t.name(), csf_);
      assert::are_equal(thread::invalid_thread_id, t.thread_id(), csf_);
      assert::are_equal(thread_priority::normal, t.priority(), csf_);
      assert::are_equal(thread_state::unstarted, t.thread_state(), csf_);
    }
    
    void test_method_(constructor_with_empty_parameterized_thread_start) {
      assert::throws<argument_exception>([]{thread t {parameterized_thread_start {}};}, csf_);
    }
    
    void test_method_(constructor_with_parameterized_thread_start_and_negative_max_stack_size) {
      assert::throws<argument_exception>([]{thread t {parameterized_thread_start {[](std::any) {}}, -1};}, csf_);
    }
    
    void test_method_(constructor_with_parameterized_thread_start) {
      thread t {parameterized_thread_start {[](std::any) {}}};
      assert::are_equal(thread::invalid_handle, t.handle(), csf_);
      assert::is_false(t.is_alive(), csf_);
      assert::is_false(t.is_background(), csf_);
      assert::is_false(t.is_thread_pool_thread(), csf_);
      assert::is_false(t.joinable(), csf_);
      assert::is_not_zero(t.managed_thread_id(), csf_);
      assert::is_empty(t.name(), csf_);
      assert::are_equal(thread::invalid_thread_id, t.thread_id(), csf_);
      assert::are_equal(thread_priority::normal, t.priority(), csf_);
      assert::are_equal(thread_state::unstarted, t.thread_state(), csf_);
    }
    
    void test_method_(main_as_current_thread) {
      thread t = thread::current_thread();
      assert::are_not_equal(thread::invalid_handle, t.handle(), csf_);
      assert::is_true(t.is_alive(), csf_);
      assert::is_false(t.is_background(), csf_);
      assert::is_false(t.is_thread_pool_thread(), csf_);
      assert::is_true(t.joinable(), csf_);
      assert::are_equal(1, t.managed_thread_id(), csf_);
      assert::is_empty(t.name(), csf_);
      assert::are_not_equal(thread::invalid_thread_id, t.thread_id(), csf_);
      assert::are_equal(thread_priority::normal, t.priority(), csf_);
      assert::are_equal(thread_state::running, t.thread_state(), csf_);
    }
    
    void test_method_(std_thread_as_current_thread) {
      bool thread_ran = false;
      std::thread t {[&] {
        thread_ran = true;
        thread t = thread::current_thread();
        assert::are_not_equal(thread::invalid_handle, t.handle(), csf_);
        assert::is_true(t.is_alive(), csf_);
        assert::is_true(t.is_background(), csf_);
        assert::is_false(t.is_thread_pool_thread(), csf_);
        assert::is_false(t.joinable(), csf_);
        assert::are_equal(0, t.managed_thread_id(), csf_);
        assert::is_empty(t.name(), csf_);
        assert::are_not_equal(thread::invalid_thread_id, t.thread_id(), csf_);
        assert::are_equal(thread_priority::normal, t.priority(), csf_);
        assert::are_equal(thread_state::running | thread_state::background, t.thread_state(), csf_);
      }};
      if (t.joinable()) t.join();
      assert::is_true(thread_ran, csf_);
    }
    
    void test_method_(xtd_threading_as_current_thread) {
      bool thread_ran = false;
      thread t {thread_start {[&] {
        thread_ran = true;
        thread t = thread::current_thread();
        assert::are_not_equal(thread::invalid_handle, t.handle(), csf_);
        assert::is_true(t.is_alive(), csf_);
        assert::is_false(t.is_background(), csf_);
        assert::is_false(t.is_thread_pool_thread(), csf_);
        assert::is_true(t.joinable(), csf_);
        assert::are_not_equal(0, t.managed_thread_id(), csf_);
        assert::are_not_equal(1, t.managed_thread_id(), csf_);
        assert::is_empty(t.name(), csf_);
        assert::are_not_equal(thread::invalid_thread_id, t.thread_id(), csf_);
        assert::are_equal(thread_priority::normal, t.priority(), csf_);
        assert::are_equal(thread_state::running, t.thread_state(), csf_);
      }}};
      t.start();
      if (t.joinable()) t.join();
      assert::is_true(thread_ran, csf_);
    }
    
    /*
    void test_method_(create_many_threads) {
      auto counter = 0;
      auto thread_proc = thread_start {[&] {
        thread::sleep(1);
        interlocked::increment(counter);
      }};
      
      constexpr auto max_count_thread = 10ul;
      auto threads = std::vector<thread> {};
      
      for (auto index = 0ul; index < max_count_thread; ++index)
        threads.emplace_back(thread_proc);
      
      for (auto& thread : threads)
        thread.start();
      for (auto& thread : threads)
        thread.join();
      
      assert::are_equal(max_count_thread, as<size_t>(counter), csf_);
    }
    
    void test_method_(create_many_threads_without_join) {
      auto counter = 0;
      auto thread_proc = thread_start {[&] {
        thread::sleep(1);
        interlocked::increment(counter);
      }};
      
      constexpr auto max_count_thread = 10ul;
      using_(auto threads = std::vector<thread> {}) {
        for (auto index = 0ul; index < max_count_thread; ++index)
          threads.emplace_back(thread_proc);
        
        for (auto& thread : threads)
          thread.start();
      }
      
      assert::are_not_equal(max_count_thread, as<size_t>(counter), csf_);
      
      // simulate end of main method
      __xtd_threads__::reset_threads();
    }
     */
  };
}
