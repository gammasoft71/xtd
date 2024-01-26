#include <xtd/forms/close_reason.h>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(close_reason_tests) {
  public:
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(close_reason::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(close_reason::none), csf_);
      assert::are_equal(close_reason::none, enum_object<>::parse<close_reason>("none"), csf_);
    }
    
    void test_method_(windows_shut_down) {
      assert::are_equal(1, enum_object<>::to_int32(close_reason::windows_shut_down), csf_);
      assert::are_equal("windows_shut_down", enum_object<>::to_string(close_reason::windows_shut_down), csf_);
      assert::are_equal(close_reason::windows_shut_down, enum_object<>::parse<close_reason>("windows_shut_down"), csf_);
    }
    
    void test_method_(mdi_form_closing) {
      assert::are_equal(2, enum_object<>::to_int32(close_reason::mdi_form_closing), csf_);
      assert::are_equal("mdi_form_closing", enum_object<>::to_string(close_reason::mdi_form_closing), csf_);
      assert::are_equal(close_reason::mdi_form_closing, enum_object<>::parse<close_reason>("mdi_form_closing"), csf_);
    }
    
    void test_method_(user_closing) {
      assert::are_equal(3, enum_object<>::to_int32(close_reason::user_closing), csf_);
      assert::are_equal("user_closing", enum_object<>::to_string(close_reason::user_closing), csf_);
      assert::are_equal(close_reason::user_closing, enum_object<>::parse<close_reason>("user_closing"), csf_);
    }
    
    void test_method_(task_manager_closing) {
      assert::are_equal(4, enum_object<>::to_int32(close_reason::task_manager_closing), csf_);
      assert::are_equal("task_manager_closing", enum_object<>::to_string(close_reason::task_manager_closing), csf_);
      assert::are_equal(close_reason::task_manager_closing, enum_object<>::parse<close_reason>("task_manager_closing"), csf_);
    }
    
    void test_method_(form_owner_closing) {
      assert::are_equal(5, enum_object<>::to_int32(close_reason::form_owner_closing), csf_);
      assert::are_equal("form_owner_closing", enum_object<>::to_string(close_reason::form_owner_closing), csf_);
      assert::are_equal(close_reason::form_owner_closing, enum_object<>::parse<close_reason>("form_owner_closing"), csf_);
    }
    
    void test_method_(application_exit_call) {
      assert::are_equal(6, enum_object<>::to_int32(close_reason::application_exit_call), csf_);
      assert::are_equal("application_exit_call", enum_object<>::to_string(close_reason::application_exit_call), csf_);
      assert::are_equal(close_reason::application_exit_call, enum_object<>::parse<close_reason>("application_exit_call"), csf_);
    }
  };
}

