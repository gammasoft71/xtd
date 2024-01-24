#include <xtd/forms/style_sheets/length_unit.h>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(length_unit_tests) {
  public:
    void test_method_(centimeters) {
      assert::are_equal(0, enum_object<>::to_int32(length_unit::centimeters), csf_);
      assert::are_equal("centimeters", enum_object<>::to_string(length_unit::centimeters), csf_);
      assert::are_equal(length_unit::centimeters, enum_object<>::parse<length_unit>("centimeters"), csf_);
    }
    
    void test_method_(millimeters) {
      assert::are_equal(1, enum_object<>::to_int32(length_unit::millimeters), csf_);
      assert::are_equal("millimeters", enum_object<>::to_string(length_unit::millimeters), csf_);
      assert::are_equal(length_unit::millimeters, enum_object<>::parse<length_unit>("millimeters"), csf_);
    }
    
    void test_method_(inches) {
      assert::are_equal(2, enum_object<>::to_int32(length_unit::inches), csf_);
      assert::are_equal("inches", enum_object<>::to_string(length_unit::inches), csf_);
      assert::are_equal(length_unit::inches, enum_object<>::parse<length_unit>("inches"), csf_);
    }
    
    void test_method_(pixels) {
      assert::are_equal(3, enum_object<>::to_int32(length_unit::pixels), csf_);
      assert::are_equal("pixels", enum_object<>::to_string(length_unit::pixels), csf_);
      assert::are_equal(length_unit::pixels, enum_object<>::parse<length_unit>("pixels"), csf_);
    }
    
    void test_method_(points) {
      assert::are_equal(4, enum_object<>::to_int32(length_unit::points), csf_);
      assert::are_equal("points", enum_object<>::to_string(length_unit::points), csf_);
      assert::are_equal(length_unit::points, enum_object<>::parse<length_unit>("points"), csf_);
    }
    
    void test_method_(picas) {
      assert::are_equal(5, enum_object<>::to_int32(length_unit::picas), csf_);
      assert::are_equal("picas", enum_object<>::to_string(length_unit::picas), csf_);
      assert::are_equal(length_unit::picas, enum_object<>::parse<length_unit>("picas"), csf_);
    }
    
    void test_method_(element) {
      assert::are_equal(6, enum_object<>::to_int32(length_unit::element), csf_);
      assert::are_equal("element", enum_object<>::to_string(length_unit::element), csf_);
      assert::are_equal(length_unit::element, enum_object<>::parse<length_unit>("element"), csf_);
    }
    
    void test_method_(element_x_height) {
      assert::are_equal(7, enum_object<>::to_int32(length_unit::element_x_height), csf_);
      assert::are_equal("element_x_height", enum_object<>::to_string(length_unit::element_x_height), csf_);
      assert::are_equal(length_unit::element_x_height, enum_object<>::parse<length_unit>("element_x_height"), csf_);
    }
    
    void test_method_(chase) {
      assert::are_equal(8, enum_object<>::to_int32(length_unit::chase), csf_);
      assert::are_equal("chase", enum_object<>::to_string(length_unit::chase), csf_);
      assert::are_equal(length_unit::chase, enum_object<>::parse<length_unit>("chase"), csf_);
    }
    
    void test_method_(root_element) {
      assert::are_equal(9, enum_object<>::to_int32(length_unit::root_element), csf_);
      assert::are_equal("root_element", enum_object<>::to_string(length_unit::root_element), csf_);
      assert::are_equal(length_unit::root_element, enum_object<>::parse<length_unit>("root_element"), csf_);
    }
    
    void test_method_(viewport_width) {
      assert::are_equal(10, enum_object<>::to_int32(length_unit::viewport_width), csf_);
      assert::are_equal("viewport_width", enum_object<>::to_string(length_unit::viewport_width), csf_);
      assert::are_equal(length_unit::viewport_width, enum_object<>::parse<length_unit>("viewport_width"), csf_);
    }
    
    void test_method_(viewport_height) {
      assert::are_equal(11, enum_object<>::to_int32(length_unit::viewport_height), csf_);
      assert::are_equal("viewport_height", enum_object<>::to_string(length_unit::viewport_height), csf_);
      assert::are_equal(length_unit::viewport_height, enum_object<>::parse<length_unit>("viewport_height"), csf_);
    }
    
    void test_method_(viewport_min) {
      assert::are_equal(12, enum_object<>::to_int32(length_unit::viewport_min), csf_);
      assert::are_equal("viewport_min", enum_object<>::to_string(length_unit::viewport_min), csf_);
      assert::are_equal(length_unit::viewport_min, enum_object<>::parse<length_unit>("viewport_min"), csf_);
    }
    
    void test_method_(viewport_max) {
      assert::are_equal(13, enum_object<>::to_int32(length_unit::viewport_max), csf_);
      assert::are_equal("viewport_max", enum_object<>::to_string(length_unit::viewport_max), csf_);
      assert::are_equal(length_unit::viewport_max, enum_object<>::parse<length_unit>("viewport_max"), csf_);
    }
    
    void test_method_(percent) {
      assert::are_equal(14, enum_object<>::to_int32(length_unit::percent), csf_);
      assert::are_equal("percent", enum_object<>::to_string(length_unit::percent), csf_);
      assert::are_equal(length_unit::percent, enum_object<>::parse<length_unit>("percent"), csf_);
    }
  };
}

