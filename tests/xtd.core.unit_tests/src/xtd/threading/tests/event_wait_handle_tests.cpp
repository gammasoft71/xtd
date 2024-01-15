#include <xtd/threading/event_wait_handle>
#include <xtd/threading/thread>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include <xtd/io/io_exception>
#include <utility>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(event_wait_handle_tests) {
    void test_method_(constructor) {
      auto e1 = event_wait_handle {};
      auto e2 = event_wait_handle {};
      assert::are_not_equal(event_wait_handle::invalid_handle, e1.handle(), csf_);
      assert::are_not_equal(event_wait_handle::invalid_handle, e2.handle(), csf_);
      assert::are_not_equal(e2, e1, csf_);
      assert::is_false(e1.wait_one(0), csf_);
      assert::is_false(e2.wait_one(0), csf_);
    }

    void test_method_(constructor_initial_state_to_false) {
      auto e = event_wait_handle {false};
      assert::is_false(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
    }

    void test_method_(constructor_initial_state_to_true) {
      auto e = event_wait_handle {true};
      assert::is_true(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
    }
    
    void test_method_(constructor_empty_name) {
      auto e1 = event_wait_handle {""};
      auto e2 = event_wait_handle {""};
      assert::are_not_equal(event_wait_handle::invalid_handle, e1.handle(), csf_);
      assert::are_not_equal(event_wait_handle::invalid_handle, e2.handle(), csf_);
      assert::are_not_equal(e2, e1, csf_);
      assert::is_false(e1.wait_one(0), csf_);
      assert::is_false(e2.wait_one(0), csf_);
    }
    
    void test_method_(constructor_same_name) {
      auto e1 = event_wait_handle {"xtd_event_wait_handle"};
      auto e2 = event_wait_handle {"xtd_event_wait_handle"};
      assert::are_not_equal(event_wait_handle::invalid_handle, e1.handle(), csf_);
      assert::are_not_equal(event_wait_handle::invalid_handle, e2.handle(), csf_);
      e1.set();
      assert::is_true(e2.wait_one(0), csf_);
    }
    
    void test_method_(constructor_different_name) {
      auto e1 = event_wait_handle {"xtd_event_wait_handle"};
      auto e2 = event_wait_handle {"xtd_event_wait_handle2"};
      assert::are_not_equal(event_wait_handle::invalid_handle, e1.handle(), csf_);
      assert::are_not_equal(event_wait_handle::invalid_handle, e2.handle(), csf_);
      assert::is_true(e1.set(), csf_);
      assert::is_false(e2.wait_one(0), csf_);
    }
    
    void test_method_(constructor_same_name_and_create_new) {
      auto created_new = false;
      auto e1 = event_wait_handle {"xtd_event_wait_handle", created_new};
      assert::is_true(created_new, csf_);
      auto e2 = event_wait_handle {"xtd_event_wait_handle", created_new};
      assert::is_false(created_new, csf_);
      assert::are_not_equal(event_wait_handle::invalid_handle, e1.handle(), csf_);
      assert::are_not_equal(event_wait_handle::invalid_handle, e2.handle(), csf_);
      assert::is_true(e1.set(), csf_);
      assert::is_true(e2.wait_one(0), csf_);
    }
    
    void test_method_(constructor_empty_name_and_create_new) {
      auto created_new = false;
      auto e1 = event_wait_handle {"", created_new};
      assert::is_true(created_new, csf_);
      auto e2 = event_wait_handle {"", created_new};
      assert::is_true(created_new, csf_);
      assert::are_not_equal(event_wait_handle::invalid_handle, e1.handle(), csf_);
      assert::are_not_equal(event_wait_handle::invalid_handle, e2.handle(), csf_);
      assert::is_true(e1.set(), csf_);
      assert::is_false(e2.wait_one(0), csf_);
    }

    void test_method_(constructor_initial_state_to_false_with_empty_name) {
      auto e = event_wait_handle {false, ""};
      assert::is_false(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
    }
    
    void test_method_(constructor_initial_state_to_true_with_empty_name) {
      auto e = event_wait_handle {true, ""};
      assert::is_true(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
    }

    void test_method_(constructor_initial_state_to_false_with_name) {
      auto e = event_wait_handle {false, "xtd_event_wait_handle"};
      assert::is_false(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
    }
    
    void test_method_(constructor_initial_state_to_true_with_name) {
      auto e = event_wait_handle {true, "xtd_event_wait_handle"};
      assert::is_true(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
    }

    void test_method_(constructor_initial_state_to_false_with_different_name) {
      auto e1 = event_wait_handle {false, "xtd_event_wait_handle"};
      auto e2 = event_wait_handle {"xtd_event_wait_handle2"};
      assert::is_false(e2.wait_one(0), csf_);
      assert::is_false(e1.wait_one(0), csf_);
    }

    void test_method_(constructor_initial_state_to_true_with_different_name) {
      auto e1 = event_wait_handle {true, "xtd_event_wait_handle"};
      auto e2 = event_wait_handle {"xtd_event_wait_handle2"};
      assert::is_false(e2.wait_one(0), csf_);
      assert::is_true(e1.wait_one(0), csf_);
    }

    void test_method_(constructor_initial_state_to_false_with_same_name) {
      auto e1 = event_wait_handle {true, "xtd_event_wait_handle"};
      auto e2 = event_wait_handle {"xtd_event_wait_handle"};
      assert::is_true(e2.wait_one(0), csf_);
      assert::is_false(e1.wait_one(0), csf_);
    }
    
    void test_method_(constructor_initial_state_to_true_with_same_name) {
      auto e1 = event_wait_handle {true, "xtd_event_wait_handle"};
      auto e2 = event_wait_handle {"xtd_event_wait_handle"};
      assert::is_true(e2.wait_one(0), csf_);
      assert::is_false(e1.wait_one(0), csf_);
    }
    
    void test_method_(constructor_initial_state_to_false_same_name_and_create_new) {
      auto created_new = false;
      auto e1 = event_wait_handle {false, "xtd_event_wait_handle", created_new};
      assert::is_true(created_new, csf_);
      auto e2 = event_wait_handle {"xtd_event_wait_handle", created_new};
      assert::is_false(created_new, csf_);
      assert::are_not_equal(event_wait_handle::invalid_handle, e1.handle(), csf_);
      assert::are_not_equal(event_wait_handle::invalid_handle, e2.handle(), csf_);
      assert::is_true(e1.set(), csf_);
      assert::is_true(e2.wait_one(0), csf_);
    }
    
    void test_method_(constructor_initial_state_to_false_empty_name_and_create_new) {
      auto created_new = false;
      auto e1 = event_wait_handle {false, "", created_new};
      assert::is_true(created_new, csf_);
      auto e2 = event_wait_handle {"", created_new};
      assert::is_true(created_new, csf_);
      assert::are_not_equal(event_wait_handle::invalid_handle, e1.handle(), csf_);
      assert::are_not_equal(event_wait_handle::invalid_handle, e2.handle(), csf_);
      assert::is_true(e1.set(), csf_);
      assert::is_false(e2.wait_one(0), csf_);
    }
    
    void test_method_(constructor_initial_state_to_true_same_name_and_create_new) {
      auto created_new = false;
      auto e1 = event_wait_handle {true, "xtd_event_wait_handle", created_new};
      assert::is_true(created_new, csf_);
      auto e2 = event_wait_handle {"xtd_event_wait_handle", created_new};
      assert::is_false(created_new, csf_);
      assert::are_not_equal(event_wait_handle::invalid_handle, e1.handle(), csf_);
      assert::are_not_equal(event_wait_handle::invalid_handle, e2.handle(), csf_);
      assert::is_true(e2.wait_one(0), csf_);
      assert::is_false(e1.wait_one(0), csf_);
    }
    
    void test_method_(constructor_initial_state_to_true_empty_name_and_create_new) {
      auto created_new = false;
      auto e1 = event_wait_handle {true, "", created_new};
      assert::is_true(created_new, csf_);
      auto e2 = event_wait_handle {"", created_new};
      assert::is_true(created_new, csf_);
      assert::are_not_equal(event_wait_handle::invalid_handle, e1.handle(), csf_);
      assert::are_not_equal(event_wait_handle::invalid_handle, e2.handle(), csf_);
      assert::is_false(e2.wait_one(0), csf_);
      assert::is_true(e1.wait_one(0), csf_);
    }

    void test_method_(constructor_initial_state_to_false_event_reset_mode_to_auto_reset) {
      auto e = event_wait_handle {false, event_reset_mode::auto_reset};
      assert::is_false(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
    }
    
    void test_method_(constructor_initial_state_to_true_event_reset_mode_to_auto_reset) {
      auto e = event_wait_handle {true, event_reset_mode::auto_reset};
      assert::is_true(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
    }

    void test_method_(constructor_initial_state_to_false_event_reset_mode_to_manual_reset) {
      auto e = event_wait_handle {false, event_reset_mode::manual_reset};
      assert::is_false(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
    }
    
    void test_method_(constructor_initial_state_to_true_event_reset_mode_to_manual_reset) {
      auto e = event_wait_handle {true, event_reset_mode::manual_reset};
      assert::is_true(e.wait_one(0), csf_);
      assert::is_true(e.wait_one(0), csf_);
    }

    void test_method_(constructor_initial_state_to_false_event_reset_mode_to_auto_reset_with_empty_name) {
      auto e = event_wait_handle {false, event_reset_mode::auto_reset, ""};
      assert::is_false(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
    }
    
    void test_method_(constructor_initial_state_to_true_event_reset_mode_to_auto_reset_with_empty_name) {
      auto e = event_wait_handle {true, event_reset_mode::auto_reset, ""};
      assert::is_true(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
    }
    
    void test_method_(constructor_initial_state_to_false_event_reset_mode_to_manual_reset_with_empty_name) {
      auto e = event_wait_handle {false, event_reset_mode::manual_reset, ""};
      assert::is_false(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
    }
    
    void test_method_(constructor_initial_state_to_true_event_reset_mode_to_manual_reset_with_empty_name) {
      auto e = event_wait_handle {true, event_reset_mode::manual_reset, ""};
      assert::is_true(e.wait_one(0), csf_);
      assert::is_true(e.wait_one(0), csf_);
    }

    void test_method_(constructor_initial_state_to_false_event_reset_mode_to_auto_reset_with_different_name) {
      auto e1 = event_wait_handle {false, event_reset_mode::auto_reset, "xtd_event_wait_handle"};
      auto e2 = event_wait_handle {false, event_reset_mode::auto_reset, "xtd_event_wait_handle2"};
      assert::is_false(e1.wait_one(0), csf_);
      assert::is_false(e2.wait_one(0), csf_);
    }
    
    void test_method_(constructor_initial_state_to_true_event_reset_mode_to_auto_reset_with_different_name) {
      auto e1 = event_wait_handle {true, event_reset_mode::auto_reset, "xtd_event_wait_handle"};
      auto e2 = event_wait_handle {true, event_reset_mode::auto_reset, "xtd_event_wait_handle2"};
      assert::is_true(e1.wait_one(0), csf_);
      assert::is_false(e1.wait_one(0), csf_);
      assert::is_true(e2.wait_one(0), csf_);
      assert::is_false(e2.wait_one(0), csf_);
    }
    
    void test_method_(constructor_initial_state_to_false_event_reset_mode_to_manual_reset_with_different_name) {
      auto e1 = event_wait_handle {false, event_reset_mode::manual_reset, "xtd_event_wait_handle"};
      auto e2 = event_wait_handle {false, event_reset_mode::manual_reset, "xtd_event_wait_handle2"};
      assert::is_false(e1.wait_one(0), csf_);
      assert::is_false(e2.wait_one(0), csf_);
    }
    
    void test_method_(constructor_initial_state_to_true_event_reset_mode_to_manual_reset_with_different_name) {
      auto e1 = event_wait_handle {true, event_reset_mode::manual_reset, "xtd_event_wait_handle"};
      auto e2 = event_wait_handle {true, event_reset_mode::manual_reset, "xtd_event_wait_handle2"};
      assert::is_true(e1.wait_one(0), csf_);
      assert::is_true(e1.wait_one(0), csf_);
      assert::is_true(e2.wait_one(0), csf_);
      assert::is_true(e2.wait_one(0), csf_);
    }

    void test_method_(constructor_initial_state_to_false_event_reset_mode_to_auto_reset_with_same_name) {
      auto e1 = event_wait_handle {false, event_reset_mode::auto_reset, "xtd_event_wait_handle"};
      auto e2 = event_wait_handle {false, event_reset_mode::auto_reset, "xtd_event_wait_handle"};
      assert::is_false(e1.wait_one(0), csf_);
      assert::is_false(e2.wait_one(0), csf_);
    }
    
    void test_method_(constructor_initial_state_to_true_event_reset_mode_to_auto_reset_with_same_name) {
      auto e1 = event_wait_handle {true, event_reset_mode::auto_reset, "xtd_event_wait_handle"};
      auto e2 = event_wait_handle {true, event_reset_mode::auto_reset, "xtd_event_wait_handle"};
      assert::is_true(e2.wait_one(0), csf_);
      assert::is_false(e2.wait_one(0), csf_);
      assert::is_false(e1.wait_one(0), csf_);
      assert::is_false(e1.wait_one(0), csf_);
    }
    
    void test_method_(constructor_initial_state_to_false_event_reset_mode_to_manual_reset_with_same_name) {
      auto e1 = event_wait_handle {false, event_reset_mode::manual_reset, "xtd_event_wait_handle"};
      auto e2 = event_wait_handle {false, event_reset_mode::manual_reset, "xtd_event_wait_handle"};
      assert::is_false(e1.wait_one(0), csf_);
      assert::is_false(e2.wait_one(0), csf_);
    }
    
    void test_method_(constructor_initial_state_to_true_event_reset_mode_to_manual_reset_with_same_name) {
      auto e1 = event_wait_handle {true, event_reset_mode::manual_reset, "xtd_event_wait_handle"};
      auto e2 = event_wait_handle {true, event_reset_mode::manual_reset, "xtd_event_wait_handle"};
      assert::is_true(e1.wait_one(0), csf_);
      assert::is_true(e1.wait_one(0), csf_);
      assert::is_true(e2.wait_one(0), csf_);
      assert::is_true(e2.wait_one(0), csf_);
    }
    
    void test_method_(open_existing_with_same_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto e = event_wait_handle {"xtd_event_wait_handle_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, e.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        auto e2 = event_wait_handle::open_existing("xtd_event_wait_handle_test");
        assert::are_not_equal(wait_handle::invalid_handle, e2.handle(), csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }
    
    void test_method_(open_existing_with_different_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto e = event_wait_handle {"xtd_event_wait_handle_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, e.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        assert::throws<io::io_exception>([] {auto e2 = event_wait_handle::open_existing("xtd_event_wait_handle_test_é");}, csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }
    
    void test_method_(open_existing_with_empty_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto e = event_wait_handle {"xtd_event_wait_handle_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, e.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        assert::throws<argument_exception>([] {auto m2 = event_wait_handle::open_existing("");}, csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }

    void test_method_(set_auto_reset_event_unnamed) {
      auto e = event_wait_handle {false, event_reset_mode::auto_reset};
      assert::is_false(e.wait_one(0), csf_);
      assert::is_true(e.set(), csf_);
      assert::is_true(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
      assert::is_true(e.set(), csf_);
      assert::is_true(e.set(), csf_);
      assert::is_true(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
    }
    
    void test_method_(set_manual_reset_event_unnamed) {
      auto e = event_wait_handle {false, event_reset_mode::manual_reset};
      assert::is_false(e.wait_one(0), csf_);
      assert::is_true(e.set(), csf_);
      assert::is_true(e.wait_one(0), csf_);
      assert::is_true(e.wait_one(0), csf_);
      assert::is_true(e.set(), csf_);
      assert::is_true(e.set(), csf_);
      assert::is_true(e.wait_one(0), csf_);
      assert::is_true(e.wait_one(0), csf_);
    }
    
    void test_method_(set_auto_reset_event_named) {
      auto e = event_wait_handle {false, event_reset_mode::auto_reset, "xtd_event_wait_handle"};
      assert::is_false(e.wait_one(0), csf_);
      assert::is_true(e.set(), csf_);
      assert::is_true(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
      assert::is_true(e.set(), csf_);
      assert::is_true(e.set(), csf_);
      assert::is_true(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
    }
    
    void test_method_(set_manual_reset_event_named) {
      auto e = event_wait_handle {false, event_reset_mode::manual_reset, "xtd_event_wait_handle"};
      assert::is_false(e.wait_one(0), csf_);
      assert::is_true(e.set(), csf_);
      assert::is_true(e.wait_one(0), csf_);
      assert::is_true(e.wait_one(0), csf_);
      assert::is_true(e.set(), csf_);
      assert::is_true(e.set(), csf_);
      assert::is_true(e.wait_one(0), csf_);
      assert::is_true(e.wait_one(0), csf_);
    }
    
    void test_method_(reset_auto_reset_event_unnamed) {
      auto e = event_wait_handle {true, event_reset_mode::auto_reset};
      assert::is_true(e.reset(), csf_);
      assert::is_false(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
      assert::is_true(e.set(), csf_);
      assert::is_true(e.reset(), csf_);
      assert::is_true(e.reset(), csf_);
      assert::is_false(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
    }
    
    void test_method_(reset_manual_reset_event_unnamed) {
      auto e = event_wait_handle {true, event_reset_mode::manual_reset};
      assert::is_true(e.reset(), csf_);
      assert::is_false(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
      assert::is_true(e.set(), csf_);
      assert::is_true(e.reset(), csf_);
      assert::is_true(e.reset(), csf_);
      assert::is_false(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
    }
    
    void test_method_(reset_auto_reset_event_named) {
      auto e = event_wait_handle {true, event_reset_mode::auto_reset, "xtd_event_wait_handle"};
      assert::is_true(e.reset(), csf_);
      assert::is_false(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
      assert::is_true(e.set(), csf_);
      assert::is_true(e.reset(), csf_);
      assert::is_true(e.reset(), csf_);
      assert::is_false(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
    }
    
    void test_method_(reset_manual_reset_event_named) {
      auto e = event_wait_handle {true, event_reset_mode::manual_reset, "xtd_event_wait_handle"};
      assert::is_true(e.reset(), csf_);
      assert::is_false(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
      assert::is_true(e.set(), csf_);
      assert::is_true(e.reset(), csf_);
      assert::is_true(e.reset(), csf_);
      assert::is_false(e.wait_one(0), csf_);
      assert::is_false(e.wait_one(0), csf_);
    }

    void test_method_(try_open_existing_with_same_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto e = event_wait_handle {"xtd_event_wait_handle_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, e.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        auto e2 = event_wait_handle {};
        auto result = event_wait_handle::try_open_existing("xtd_event_wait_handle_test", e2);
        assert::is_true(result, csf_);
        assert::are_not_equal(wait_handle::invalid_handle, e2.handle(), csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }
    
    void test_method_(try_open_existing_with_different_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto e = event_wait_handle {"xtd_event_wait_handle_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, e.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        auto e2 = event_wait_handle {};
        auto result = event_wait_handle::try_open_existing("xtd_event_wait_handle_test_é", e2);
        assert::is_false(result, csf_);
        assert::are_equal(wait_handle::invalid_handle, e2.handle(), csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }
    
    void test_method_(try_open_existing_with_empty_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto e = event_wait_handle {"xtd_event_wait_handle_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, e.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        auto e2 = event_wait_handle {};
        auto result = event_wait_handle::try_open_existing("", e2);
        assert::is_false(result, csf_);
        assert::are_equal(wait_handle::invalid_handle, e2.handle(), csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }
  };
}
