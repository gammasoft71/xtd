#include <xtd/forms/form_border_style>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(form_border_style_tests) {
  public:
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(form_border_style::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(form_border_style::none), csf_);
      assert::are_equal(form_border_style::none, enum_object<>::parse<form_border_style>("none"), csf_);
    }
    
    void test_method_(fixed_single) {
      assert::are_equal(1, enum_object<>::to_int32(form_border_style::fixed_single), csf_);
      assert::are_equal("fixed_single", enum_object<>::to_string(form_border_style::fixed_single), csf_);
      assert::are_equal(form_border_style::fixed_single, enum_object<>::parse<form_border_style>("fixed_single"), csf_);
    }
    
    void test_method_(fixed_3d) {
      assert::are_equal(2, enum_object<>::to_int32(form_border_style::fixed_3d), csf_);
      assert::are_equal("fixed_3d", enum_object<>::to_string(form_border_style::fixed_3d), csf_);
      assert::are_equal(form_border_style::fixed_3d, enum_object<>::parse<form_border_style>("fixed_3d"), csf_);
    }
    
    void test_method_(fixed_dialog) {
      assert::are_equal(3, enum_object<>::to_int32(form_border_style::fixed_dialog), csf_);
      assert::are_equal("fixed_dialog", enum_object<>::to_string(form_border_style::fixed_dialog), csf_);
      assert::are_equal(form_border_style::fixed_dialog, enum_object<>::parse<form_border_style>("fixed_dialog"), csf_);
    }
    
    void test_method_(sizable) {
      assert::are_equal(4, enum_object<>::to_int32(form_border_style::sizable), csf_);
      assert::are_equal("sizable", enum_object<>::to_string(form_border_style::sizable), csf_);
      assert::are_equal(form_border_style::sizable, enum_object<>::parse<form_border_style>("sizable"), csf_);
    }
    
    void test_method_(fixed_tool_window) {
      assert::are_equal(5, enum_object<>::to_int32(form_border_style::fixed_tool_window), csf_);
      assert::are_equal("fixed_tool_window", enum_object<>::to_string(form_border_style::fixed_tool_window), csf_);
      assert::are_equal(form_border_style::fixed_tool_window, enum_object<>::parse<form_border_style>("fixed_tool_window"), csf_);
    }
    
    void test_method_(sizable_tool_window) {
      assert::are_equal(6, enum_object<>::to_int32(form_border_style::sizable_tool_window), csf_);
      assert::are_equal("sizable_tool_window", enum_object<>::to_string(form_border_style::sizable_tool_window), csf_);
      assert::are_equal(form_border_style::sizable_tool_window, enum_object<>::parse<form_border_style>("sizable_tool_window"), csf_);
    }
  };
}
