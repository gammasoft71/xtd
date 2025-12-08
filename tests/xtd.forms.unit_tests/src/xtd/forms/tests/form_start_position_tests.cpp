#include <xtd/forms/form_start_position>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(form_start_position_tests) {
  public:
    auto test_method_(manual) {
      assert::are_equal(0, enum_object<>::to_int32(form_start_position::manual));
      assert::are_equal("manual", enum_object<>::to_string(form_start_position::manual));
      assert::are_equal(form_start_position::manual, enum_object<>::parse<form_start_position>("manual"));
    }
    
    auto test_method_(center_screen) {
      assert::are_equal(1, enum_object<>::to_int32(form_start_position::center_screen));
      assert::are_equal("center_screen", enum_object<>::to_string(form_start_position::center_screen));
      assert::are_equal(form_start_position::center_screen, enum_object<>::parse<form_start_position>("center_screen"));
    }
    
    auto test_method_(windows_default_location) {
      assert::are_equal(2, enum_object<>::to_int32(form_start_position::windows_default_location));
      assert::are_equal("windows_default_location", enum_object<>::to_string(form_start_position::windows_default_location));
      assert::are_equal(form_start_position::windows_default_location, enum_object<>::parse<form_start_position>("windows_default_location"));
    }
    
    auto test_method_(windows_default_bounds) {
      assert::are_equal(3, enum_object<>::to_int32(form_start_position::windows_default_bounds));
      assert::are_equal("windows_default_bounds", enum_object<>::to_string(form_start_position::windows_default_bounds));
      assert::are_equal(form_start_position::windows_default_bounds, enum_object<>::parse<form_start_position>("windows_default_bounds"));
    }
    
    auto test_method_(center_parent) {
      assert::are_equal(4, enum_object<>::to_int32(form_start_position::center_parent));
      assert::are_equal("center_parent", enum_object<>::to_string(form_start_position::center_parent));
      assert::are_equal(form_start_position::center_parent, enum_object<>::parse<form_start_position>("center_parent"));
    }
  };
}
