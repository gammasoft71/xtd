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
    
    void test_method_(is_alive) {
      auto thread = threading::thread {thread_start {[] {thread::sleep(2);}}};
      assert::is_false(thread.is_alive(), csf_);
      thread.start();
      assert::is_true(thread.is_alive());
      thread.join();
      assert::is_false(thread.is_alive(), csf_);
    }
    
    void test_method_(is_background) {
      auto thread = threading::thread {thread_start {[] {thread::sleep(2);}}};
      assert::is_false(thread.is_background(), csf_);
      thread.is_background(true);
      assert::is_true(thread.is_background(), csf_);
      thread.is_background(false);
      assert::is_false(thread.is_background(), csf_);
    }
    
    void test_method_(is_main_thread) {
      assert::is_true(threading::thread::current_thread().is_main_thread(), csf_);
      auto thread = threading::thread {thread_start {[] {thread::sleep(2);}}};
      thread.start();
      assert::is_false(thread.is_main_thread(), csf_);
    }
    
    void test_method_(is_thread_pool_thread) {
      assert::is_false(threading::thread::current_thread().is_thread_pool_thread(), csf_);
      auto thread = threading::thread {thread_start {[] {thread::sleep(2);}}};
      thread.start();
      assert::is_false(thread.is_thread_pool_thread(), csf_);
    }
    
    void test_method_(joinable) {
      auto thread = threading::thread {thread_start {[] {thread::sleep(2);}}};
      assert::is_false(thread.joinable(), csf_);
      thread.start();
      assert::is_true(thread.joinable(), csf_);
      thread.join();
      assert::is_false(thread.joinable(), csf_);
    }
    
    void test_method_(managed_thread_id) {
      assert::are_equal(1, threading::thread::current_thread().managed_thread_id(), csf_);
      auto thread = threading::thread {thread_start {[] {thread::sleep(2);}}};
      auto thread2 = threading::thread {thread_start {[] {thread::sleep(2);}}};
      assert::is_greater(thread.managed_thread_id(), 1, csf_);
      assert::are_equal(thread.managed_thread_id() + 1, thread2.managed_thread_id(), csf_);
    }
    
    void test_method_(name) {
      auto thread = threading::thread {thread_start {[] {
        threading::thread::current_thread().name("other");
        assert::are_equal("other", threading::thread::current_thread().name(), csf_);

      }}};
      assert::is_empty(thread.name(), csf_);
      thread.name("thread");
      assert::are_equal("thread", thread.name(), csf_);
      thread.start();
      thread.join();
      assert::are_equal("other", thread.name(), csf_);
    }
    
    void test_method_(priority) {
      auto thread = threading::thread {thread_start {[] {
        assert::are_equal(thread_priority::normal, threading::thread::current_thread().priority(), csf_);
        threading::thread::current_thread().priority(xtd::threading::thread_priority::lowest);
        assert::are_equal(thread_priority::lowest, threading::thread::current_thread().priority(), csf_);
        threading::thread::current_thread().priority(xtd::threading::thread_priority::below_normal);
        assert::are_equal(thread_priority::below_normal, threading::thread::current_thread().priority(), csf_);
        threading::thread::current_thread().priority(xtd::threading::thread_priority::above_normal);
        assert::are_equal(thread_priority::above_normal, threading::thread::current_thread().priority(), csf_);
        threading::thread::current_thread().priority(xtd::threading::thread_priority::highest);
        assert::are_equal(thread_priority::highest, threading::thread::current_thread().priority(), csf_);
        threading::thread::current_thread().priority(xtd::threading::thread_priority::normal);
        assert::are_equal(thread_priority::normal, threading::thread::current_thread().priority(), csf_);
        threading::thread::current_thread().priority(xtd::threading::thread_priority::above_normal);
      }}};
      assert::are_equal(thread_priority::normal, thread.priority(), csf_);
      thread.priority(xtd::threading::thread_priority::lowest);
      assert::are_equal(thread_priority::lowest, thread.priority(), csf_);
      thread.priority(xtd::threading::thread_priority::below_normal);
      assert::are_equal(thread_priority::below_normal, thread.priority(), csf_);
      thread.priority(xtd::threading::thread_priority::above_normal);
      assert::are_equal(thread_priority::above_normal, thread.priority(), csf_);
      thread.priority(xtd::threading::thread_priority::highest);
      assert::are_equal(thread_priority::highest, thread.priority(), csf_);
      thread.priority(xtd::threading::thread_priority::normal);
      assert::are_equal(thread_priority::normal, thread.priority(), csf_);
      thread.start();
      thread.join();
      assert::are_equal(thread_priority::above_normal, thread.priority(), csf_);
    }
    
    void test_method_(priority_argument_exception) {
      auto thread = threading::thread {thread_start {[] {}}};
      assert::throws<argument_exception>([&] {thread.priority(as<xtd::threading::thread_priority>(10));}, csf_);
    }
    
    void test_method_(priority_thread_state_exception) {
      auto thread = threading::thread {thread_start {[] {}}};
      thread.start();
      thread.join();
      assert::throws<thread_state_exception>([&] {thread.priority(xtd::threading::thread_priority::lowest);}, csf_);
    }

    void test_method_(create_many_threads) {
      auto counter = 0;
      auto thread_proc = thread_start {[&] {
        interlocked::increment(counter);
      }};
      
      constexpr auto max_count_thread = 1000ul;
      auto threads = std::vector<thread> {};
      
      for (auto index = 0ul; index < max_count_thread; ++index)
        threads.emplace_back(thread_proc);
      
      for (auto& thread : threads)
        thread.start();
      for (auto& thread : threads)
        thread.join();
      
      assert::are_equal(max_count_thread, as<size_t>(counter), csf_);
    }
    
    void test_method_(create_many_threads_with_join_all) {
      auto counter = 0;
      auto thread_proc = thread_start {[&] {
        interlocked::increment(counter);
      }};
      
      constexpr auto max_count_thread = 1000ul;
      auto threads = std::vector<thread> {};
      
      for (auto index = 0ul; index < max_count_thread; ++index)
        threads.push_back(thread::start_new(thread_proc));
      
      thread::join_all(threads);
      
      assert::are_equal(max_count_thread, as<size_t>(counter), csf_);
    }
    
    void test_method_(create_many_threads_with_join_all_global) {
      auto counter = 0;
      auto thread_proc = thread_start {[&] {
        interlocked::increment(counter);
      }};
      
      constexpr auto max_count_thread = 1000ul;
      for (auto index = 0ul; index < max_count_thread; ++index)
        thread::start_new(thread_proc);
      
      thread::join_all();
      
      assert::are_equal(max_count_thread, as<size_t>(counter), csf_);
    }
  };
}
