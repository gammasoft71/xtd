#include <xtd/drawing/drawing_2d/pixel_offset_mode>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::drawing_2d;
using namespace xtd::tunit;

namespace xtd::drawing::drawing_2d::tests {
  class test_class_(pixel_offset_mode_tests) {
    void test_method_(invalid) {
      assert::are_equal(-1, enum_object<>::to_int32(pixel_offset_mode::invalid), csf_);
      assert::are_equal("invalid", enum_object<>::to_string(pixel_offset_mode::invalid), csf_);
      assert::are_equal(pixel_offset_mode::invalid, enum_object<>::parse<pixel_offset_mode>("invalid"), csf_);
    }
    
    void test_method_(default_value) {
      assert::are_equal(0, enum_object<>::to_int32(pixel_offset_mode::default_value), csf_);
      assert::are_equal("default_value", enum_object<>::to_string(pixel_offset_mode::default_value), csf_);
      assert::are_equal(pixel_offset_mode::default_value, enum_object<>::parse<pixel_offset_mode>("default_value"), csf_);
    }
    
    void test_method_(high_speed) {
      assert::are_equal(1, enum_object<>::to_int32(pixel_offset_mode::high_speed), csf_);
      assert::are_equal("high_speed", enum_object<>::to_string(pixel_offset_mode::high_speed), csf_);
      assert::are_equal(pixel_offset_mode::high_speed, enum_object<>::parse<pixel_offset_mode>("high_speed"), csf_);
    }
    
    void test_method_(high_quality) {
      assert::are_equal(2, enum_object<>::to_int32(pixel_offset_mode::high_quality), csf_);
      assert::are_equal("high_quality", enum_object<>::to_string(pixel_offset_mode::high_quality), csf_);
      assert::are_equal(pixel_offset_mode::high_quality, enum_object<>::parse<pixel_offset_mode>("high_quality"), csf_);
    }
    
    void test_method_(none) {
      assert::are_equal(3, enum_object<>::to_int32(pixel_offset_mode::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(pixel_offset_mode::none), csf_);
      assert::are_equal(pixel_offset_mode::none, enum_object<>::parse<pixel_offset_mode>("none"), csf_);
    }
    
    void test_method_(half) {
      assert::are_equal(4, enum_object<>::to_int32(pixel_offset_mode::half), csf_);
      assert::are_equal("half", enum_object<>::to_string(pixel_offset_mode::half), csf_);
      assert::are_equal(pixel_offset_mode::half, enum_object<>::parse<pixel_offset_mode>("half"), csf_);
    }
  };
}
