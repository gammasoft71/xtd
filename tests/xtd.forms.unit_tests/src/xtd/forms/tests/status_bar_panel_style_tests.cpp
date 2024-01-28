#include <xtd/forms/status_bar_panel_style>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(status_bar_panel_style_tests) {
  public:
    void test_method_(text) {
      assert::are_equal(1, enum_object<>::to_int32(status_bar_panel_style::text), csf_);
      assert::are_equal("text", enum_object<>::to_string(status_bar_panel_style::text), csf_);
      assert::are_equal(status_bar_panel_style::text, enum_object<>::parse<status_bar_panel_style>("text"), csf_);
    }
    
    void test_method_(owner_draw) {
      assert::are_equal(2, enum_object<>::to_int32(status_bar_panel_style::owner_draw), csf_);
      assert::are_equal("owner_draw", enum_object<>::to_string(status_bar_panel_style::owner_draw), csf_);
      assert::are_equal(status_bar_panel_style::owner_draw, enum_object<>::parse<status_bar_panel_style>("owner_draw"), csf_);
    }
    
    void test_method_(control) {
      assert::are_equal(3, enum_object<>::to_int32(status_bar_panel_style::control), csf_);
      assert::are_equal("control", enum_object<>::to_string(status_bar_panel_style::control), csf_);
      assert::are_equal(status_bar_panel_style::control, enum_object<>::parse<status_bar_panel_style>("control"), csf_);
    }
  };
}
