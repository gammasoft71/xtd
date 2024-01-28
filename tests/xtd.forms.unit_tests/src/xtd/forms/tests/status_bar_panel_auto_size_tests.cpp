#include <xtd/forms/status_bar_panel_auto_size>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(status_bar_panel_auto_size_tests) {
  public:
    void test_method_(none) {
      assert::are_equal(1, enum_object<>::to_int32(status_bar_panel_auto_size::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(status_bar_panel_auto_size::none), csf_);
      assert::are_equal(status_bar_panel_auto_size::none, enum_object<>::parse<status_bar_panel_auto_size>("none"), csf_);
    }
    
    void test_method_(spring) {
      assert::are_equal(2, enum_object<>::to_int32(status_bar_panel_auto_size::spring), csf_);
      assert::are_equal("spring", enum_object<>::to_string(status_bar_panel_auto_size::spring), csf_);
      assert::are_equal(status_bar_panel_auto_size::spring, enum_object<>::parse<status_bar_panel_auto_size>("spring"), csf_);
    }
    
    void test_method_(contents) {
      assert::are_equal(3, enum_object<>::to_int32(status_bar_panel_auto_size::contents), csf_);
      assert::are_equal("contents", enum_object<>::to_string(status_bar_panel_auto_size::contents), csf_);
      assert::are_equal(status_bar_panel_auto_size::contents, enum_object<>::parse<status_bar_panel_auto_size>("contents"), csf_);
    }
  };
}
