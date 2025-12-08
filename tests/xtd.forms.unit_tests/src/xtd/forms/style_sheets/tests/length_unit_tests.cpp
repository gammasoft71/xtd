#include <xtd/forms/style_sheets/length_unit>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

namespace xtd::forms::style_sheets::tests {
  class test_class_(length_unit_tests) {
  public:
    auto test_method_(centimeters) {
      assert::are_equal(0, enum_object<>::to_int32(length_unit::centimeters));
      assert::are_equal("centimeters", enum_object<>::to_string(length_unit::centimeters));
      assert::are_equal(length_unit::centimeters, enum_object<>::parse<length_unit>("centimeters"));
    }
    
    auto test_method_(millimeters) {
      assert::are_equal(1, enum_object<>::to_int32(length_unit::millimeters));
      assert::are_equal("millimeters", enum_object<>::to_string(length_unit::millimeters));
      assert::are_equal(length_unit::millimeters, enum_object<>::parse<length_unit>("millimeters"));
    }
    
    auto test_method_(inches) {
      assert::are_equal(2, enum_object<>::to_int32(length_unit::inches));
      assert::are_equal("inches", enum_object<>::to_string(length_unit::inches));
      assert::are_equal(length_unit::inches, enum_object<>::parse<length_unit>("inches"));
    }
    
    auto test_method_(pixels) {
      assert::are_equal(3, enum_object<>::to_int32(length_unit::pixels));
      assert::are_equal("pixels", enum_object<>::to_string(length_unit::pixels));
      assert::are_equal(length_unit::pixels, enum_object<>::parse<length_unit>("pixels"));
    }
    
    auto test_method_(points) {
      assert::are_equal(4, enum_object<>::to_int32(length_unit::points));
      assert::are_equal("points", enum_object<>::to_string(length_unit::points));
      assert::are_equal(length_unit::points, enum_object<>::parse<length_unit>("points"));
    }
    
    auto test_method_(picas) {
      assert::are_equal(5, enum_object<>::to_int32(length_unit::picas));
      assert::are_equal("picas", enum_object<>::to_string(length_unit::picas));
      assert::are_equal(length_unit::picas, enum_object<>::parse<length_unit>("picas"));
    }
    
    auto test_method_(element) {
      assert::are_equal(6, enum_object<>::to_int32(length_unit::element));
      assert::are_equal("element", enum_object<>::to_string(length_unit::element));
      assert::are_equal(length_unit::element, enum_object<>::parse<length_unit>("element"));
    }
    
    auto test_method_(element_x_height) {
      assert::are_equal(7, enum_object<>::to_int32(length_unit::element_x_height));
      assert::are_equal("element_x_height", enum_object<>::to_string(length_unit::element_x_height));
      assert::are_equal(length_unit::element_x_height, enum_object<>::parse<length_unit>("element_x_height"));
    }
    
    auto test_method_(chase) {
      assert::are_equal(8, enum_object<>::to_int32(length_unit::chase));
      assert::are_equal("chase", enum_object<>::to_string(length_unit::chase));
      assert::are_equal(length_unit::chase, enum_object<>::parse<length_unit>("chase"));
    }
    
    auto test_method_(root_element) {
      assert::are_equal(9, enum_object<>::to_int32(length_unit::root_element));
      assert::are_equal("root_element", enum_object<>::to_string(length_unit::root_element));
      assert::are_equal(length_unit::root_element, enum_object<>::parse<length_unit>("root_element"));
    }
    
    auto test_method_(viewport_width) {
      assert::are_equal(10, enum_object<>::to_int32(length_unit::viewport_width));
      assert::are_equal("viewport_width", enum_object<>::to_string(length_unit::viewport_width));
      assert::are_equal(length_unit::viewport_width, enum_object<>::parse<length_unit>("viewport_width"));
    }
    
    auto test_method_(viewport_height) {
      assert::are_equal(11, enum_object<>::to_int32(length_unit::viewport_height));
      assert::are_equal("viewport_height", enum_object<>::to_string(length_unit::viewport_height));
      assert::are_equal(length_unit::viewport_height, enum_object<>::parse<length_unit>("viewport_height"));
    }
    
    auto test_method_(viewport_min) {
      assert::are_equal(12, enum_object<>::to_int32(length_unit::viewport_min));
      assert::are_equal("viewport_min", enum_object<>::to_string(length_unit::viewport_min));
      assert::are_equal(length_unit::viewport_min, enum_object<>::parse<length_unit>("viewport_min"));
    }
    
    auto test_method_(viewport_max) {
      assert::are_equal(13, enum_object<>::to_int32(length_unit::viewport_max));
      assert::are_equal("viewport_max", enum_object<>::to_string(length_unit::viewport_max));
      assert::are_equal(length_unit::viewport_max, enum_object<>::parse<length_unit>("viewport_max"));
    }
    
    auto test_method_(percent) {
      assert::are_equal(14, enum_object<>::to_int32(length_unit::percent));
      assert::are_equal("percent", enum_object<>::to_string(length_unit::percent));
      assert::are_equal(length_unit::percent, enum_object<>::parse<length_unit>("percent"));
    }
  };
}
