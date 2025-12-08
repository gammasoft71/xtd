#include <xtd/drawing/imaging/encoder_parameter_value_type>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::imaging;
using namespace xtd::tunit;

namespace xtd::drawing::imaging::tests {
  class test_class_(encoder_parameter_value_type_tests) {
    auto test_method_(value_type_byte) {
      assert::are_equal(1, enum_object<>::to_int32(encoder_parameter_value_type::value_type_byte));
      assert::are_equal("value_type_byte", enum_object<>::to_string(encoder_parameter_value_type::value_type_byte));
      assert::are_equal(encoder_parameter_value_type::value_type_byte, enum_object<>::parse<encoder_parameter_value_type>("value_type_byte"));
    }
    
    auto test_method_(value_type_ascii) {
      assert::are_equal(2, enum_object<>::to_int32(encoder_parameter_value_type::value_type_ascii));
      assert::are_equal("value_type_ascii", enum_object<>::to_string(encoder_parameter_value_type::value_type_ascii));
      assert::are_equal(encoder_parameter_value_type::value_type_ascii, enum_object<>::parse<encoder_parameter_value_type>("value_type_ascii"));
    }
    
    auto test_method_(value_type_short) {
      assert::are_equal(3, enum_object<>::to_int32(encoder_parameter_value_type::value_type_short));
      assert::are_equal("value_type_short", enum_object<>::to_string(encoder_parameter_value_type::value_type_short));
      assert::are_equal(encoder_parameter_value_type::value_type_short, enum_object<>::parse<encoder_parameter_value_type>("value_type_short"));
    }
    
    auto test_method_(value_type_long) {
      assert::are_equal(4, enum_object<>::to_int32(encoder_parameter_value_type::value_type_long));
      assert::are_equal("value_type_long", enum_object<>::to_string(encoder_parameter_value_type::value_type_long));
      assert::are_equal(encoder_parameter_value_type::value_type_long, enum_object<>::parse<encoder_parameter_value_type>("value_type_long"));
    }
    
    auto test_method_(value_type_rational) {
      assert::are_equal(5, enum_object<>::to_int32(encoder_parameter_value_type::value_type_rational));
      assert::are_equal("value_type_rational", enum_object<>::to_string(encoder_parameter_value_type::value_type_rational));
      assert::are_equal(encoder_parameter_value_type::value_type_rational, enum_object<>::parse<encoder_parameter_value_type>("value_type_rational"));
    }
    
    auto test_method_(value_type_long_range) {
      assert::are_equal(6, enum_object<>::to_int32(encoder_parameter_value_type::value_type_long_range));
      assert::are_equal("value_type_long_range", enum_object<>::to_string(encoder_parameter_value_type::value_type_long_range));
      assert::are_equal(encoder_parameter_value_type::value_type_long_range, enum_object<>::parse<encoder_parameter_value_type>("value_type_long_range"));
    }
    
    auto test_method_(value_type_undefined) {
      assert::are_equal(7, enum_object<>::to_int32(encoder_parameter_value_type::value_type_undefined));
      assert::are_equal("value_type_undefined", enum_object<>::to_string(encoder_parameter_value_type::value_type_undefined));
      assert::are_equal(encoder_parameter_value_type::value_type_undefined, enum_object<>::parse<encoder_parameter_value_type>("value_type_undefined"));
    }
    
    auto test_method_(value_type_rational_range) {
      assert::are_equal(8, enum_object<>::to_int32(encoder_parameter_value_type::value_type_rational_range));
      assert::are_equal("value_type_rational_range", enum_object<>::to_string(encoder_parameter_value_type::value_type_rational_range));
      assert::are_equal(encoder_parameter_value_type::value_type_rational_range, enum_object<>::parse<encoder_parameter_value_type>("value_type_rational_range"));
    }
    
    auto test_method_(value_type_rational_pointer) {
      assert::are_equal(9, enum_object<>::to_int32(encoder_parameter_value_type::value_type_rational_pointer));
      assert::are_equal("value_type_rational_pointer", enum_object<>::to_string(encoder_parameter_value_type::value_type_rational_pointer));
      assert::are_equal(encoder_parameter_value_type::value_type_rational_pointer, enum_object<>::parse<encoder_parameter_value_type>("value_type_rational_pointer"));
    }
  };
}
