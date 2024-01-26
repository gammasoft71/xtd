#include <xtd/forms/form_window_state.h>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(form_window_state_tests) {
  public:
    void test_method_(normal) {
      assert::are_equal(0, enum_object<>::to_int32(form_window_state::normal), csf_);
      assert::are_equal("normal", enum_object<>::to_string(form_window_state::normal), csf_);
      assert::are_equal(form_window_state::normal, enum_object<>::parse<form_window_state>("normal"), csf_);
    }
    
    void test_method_(minimized) {
      assert::are_equal(1, enum_object<>::to_int32(form_window_state::minimized), csf_);
      assert::are_equal("minimized", enum_object<>::to_string(form_window_state::minimized), csf_);
      assert::are_equal(form_window_state::minimized, enum_object<>::parse<form_window_state>("minimized"), csf_);
    }
    
    void test_method_(maximized) {
      assert::are_equal(2, enum_object<>::to_int32(form_window_state::maximized), csf_);
      assert::are_equal("maximized", enum_object<>::to_string(form_window_state::maximized), csf_);
      assert::are_equal(form_window_state::maximized, enum_object<>::parse<form_window_state>("maximized"), csf_);
    }
    
    void test_method_(full_screen) {
      assert::are_equal(3, enum_object<>::to_int32(form_window_state::full_screen), csf_);
      assert::are_equal("full_screen", enum_object<>::to_string(form_window_state::full_screen), csf_);
      assert::are_equal(form_window_state::full_screen, enum_object<>::parse<form_window_state>("full_screen"), csf_);
    }
  };
}

