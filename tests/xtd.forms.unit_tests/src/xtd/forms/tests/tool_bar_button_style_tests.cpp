#include <xtd/forms/tool_bar_button_style>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(tool_bar_button_style_tests) {
  public:
    void test_method_(push_button) {
      assert::are_equal(1, enum_object<>::to_int32(tool_bar_button_style::push_button), csf_);
      assert::are_equal("push_button", enum_object<>::to_string(tool_bar_button_style::push_button), csf_);
      assert::are_equal(tool_bar_button_style::push_button, enum_object<>::parse<tool_bar_button_style>("push_button"), csf_);
    }
    
    void test_method_(toggle_button) {
      assert::are_equal(2, enum_object<>::to_int32(tool_bar_button_style::toggle_button), csf_);
      assert::are_equal("toggle_button", enum_object<>::to_string(tool_bar_button_style::toggle_button), csf_);
      assert::are_equal(tool_bar_button_style::toggle_button, enum_object<>::parse<tool_bar_button_style>("toggle_button"), csf_);
    }
    
    void test_method_(separator) {
      assert::are_equal(3, enum_object<>::to_int32(tool_bar_button_style::separator), csf_);
      assert::are_equal("separator", enum_object<>::to_string(tool_bar_button_style::separator), csf_);
      assert::are_equal(tool_bar_button_style::separator, enum_object<>::parse<tool_bar_button_style>("separator"), csf_);
    }
    
    void test_method_(drop_down_button) {
      assert::are_equal(4, enum_object<>::to_int32(tool_bar_button_style::drop_down_button), csf_);
      assert::are_equal("drop_down_button", enum_object<>::to_string(tool_bar_button_style::drop_down_button), csf_);
      assert::are_equal(tool_bar_button_style::drop_down_button, enum_object<>::parse<tool_bar_button_style>("drop_down_button"), csf_);
    }
    
    void test_method_(stretchable_separator) {
      assert::are_equal(5, enum_object<>::to_int32(tool_bar_button_style::stretchable_separator), csf_);
      assert::are_equal("stretchable_separator", enum_object<>::to_string(tool_bar_button_style::stretchable_separator), csf_);
      assert::are_equal(tool_bar_button_style::stretchable_separator, enum_object<>::parse<tool_bar_button_style>("stretchable_separator"), csf_);
    }
    
    void test_method_(control) {
      assert::are_equal(6, enum_object<>::to_int32(tool_bar_button_style::control), csf_);
      assert::are_equal("control", enum_object<>::to_string(tool_bar_button_style::control), csf_);
      assert::are_equal(tool_bar_button_style::control, enum_object<>::parse<tool_bar_button_style>("control"), csf_);
    }
  };
}
