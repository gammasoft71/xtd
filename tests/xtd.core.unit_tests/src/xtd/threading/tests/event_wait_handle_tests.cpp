#include <xtd/threading/event_wait_handle.h>
#include <xtd/xtd.tunit>
#include <utility>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(event_wait_handle_tests) {
  public:
    static void class_initialize_(class_initialize) {
      auto e = event_wait_handle {"xtd_event_wait_handle_test"};
      auto e2 = event_wait_handle {"xtd_event_wait_handle_test_2"};
    }

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
  };
}
