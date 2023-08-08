#include <xtd/threading/thread.h>
#include <xtd/xtd.tunit>

using namespace xtd::threading;
using namespace xtd::tunit;

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

    void test_method_(maint_thread_default_status) {
      thread t = thread::current_thread();
      assert::are_not_equal(thread::invalid_handle, t.handle(), csf_);
      assert::is_true(t.is_alive(), csf_);
      assert::is_false(t.is_background(), csf_);
      assert::is_false(t.is_thread_pool_thread(), csf_);
      assert::is_false(t.joinable(), csf_);
      assert::are_equal(1, t.managed_thread_id(), csf_);
      assert::is_empty(t.name(), csf_);
      assert::are_not_equal(thread::invalid_thread_id, t.thread_id(), csf_);
      assert::are_equal(thread_priority::normal, t.priority(), csf_);
      assert::are_equal(thread_state::running, t.thread_state(), csf_);
    }
    
    void test_method_(std_thread_created_default_status) {
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
    
    void test_method_(xtd_threading_thread_created_default_status) {
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

  };
}
