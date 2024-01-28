#include <xtd/forms/status_bar_panel_border_style>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(status_bar_panel_border_style_tests) {
  public:
    void test_method_(none) {
      assert::are_equal(1, enum_object<>::to_int32(status_bar_panel_border_style::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(status_bar_panel_border_style::none), csf_);
      assert::are_equal(status_bar_panel_border_style::none, enum_object<>::parse<status_bar_panel_border_style>("none"), csf_);
    }
    
    void test_method_(outset) {
      assert::are_equal(2, enum_object<>::to_int32(status_bar_panel_border_style::outset), csf_);
      assert::are_equal("outset", enum_object<>::to_string(status_bar_panel_border_style::outset), csf_);
      assert::are_equal(status_bar_panel_border_style::outset, enum_object<>::parse<status_bar_panel_border_style>("outset"), csf_);
    }
    
    void test_method_(inset) {
      assert::are_equal(3, enum_object<>::to_int32(status_bar_panel_border_style::inset), csf_);
      assert::are_equal("inset", enum_object<>::to_string(status_bar_panel_border_style::inset), csf_);
      assert::are_equal(status_bar_panel_border_style::inset, enum_object<>::parse<status_bar_panel_border_style>("inset"), csf_);
    }
    
    void test_method_(raised) {
      assert::are_equal(2, enum_object<>::to_int32(status_bar_panel_border_style::raised), csf_);
      assert::are_equal("outset", enum_object<>::to_string(status_bar_panel_border_style::raised), csf_);
      assert::are_equal(status_bar_panel_border_style::raised, enum_object<>::parse<status_bar_panel_border_style>("outset"), csf_);
    }
    
    void test_method_(sunken) {
      assert::are_equal(3, enum_object<>::to_int32(status_bar_panel_border_style::sunken), csf_);
      assert::are_equal("inset", enum_object<>::to_string(status_bar_panel_border_style::sunken), csf_);
      assert::are_equal(status_bar_panel_border_style::sunken, enum_object<>::parse<status_bar_panel_border_style>("inset"), csf_);
    }
  };
}
