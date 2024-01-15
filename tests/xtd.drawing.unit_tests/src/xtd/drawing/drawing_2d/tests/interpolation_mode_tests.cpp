#include <xtd/drawing/drawing_2d/interpolation_mode>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::drawing_2d;
using namespace xtd::tunit;

namespace xtd::drawing::drawing_2d::tests {
  class test_class_(interpolation_mode_tests) {
    void test_method_(invalid) {
      assert::are_equal(-1, enum_object<>::to_int32(interpolation_mode::invalid), csf_);
      assert::are_equal("invalid", enum_object<>::to_string(interpolation_mode::invalid), csf_);
      assert::are_equal(interpolation_mode::invalid, enum_object<>::parse<interpolation_mode>("invalid"), csf_);
    }
    
    void test_method_(default_value) {
      assert::are_equal(0, enum_object<>::to_int32(interpolation_mode::default_value), csf_);
      assert::are_equal("default_value", enum_object<>::to_string(interpolation_mode::default_value), csf_);
      assert::are_equal(interpolation_mode::default_value, enum_object<>::parse<interpolation_mode>("default_value"), csf_);
    }
    
    void test_method_(low) {
      assert::are_equal(1, enum_object<>::to_int32(interpolation_mode::low), csf_);
      assert::are_equal("low", enum_object<>::to_string(interpolation_mode::low), csf_);
      assert::are_equal(interpolation_mode::low, enum_object<>::parse<interpolation_mode>("low"), csf_);
    }
    
    void test_method_(hight) {
      assert::are_equal(2, enum_object<>::to_int32(interpolation_mode::hight), csf_);
      assert::are_equal("hight", enum_object<>::to_string(interpolation_mode::hight), csf_);
      assert::are_equal(interpolation_mode::hight, enum_object<>::parse<interpolation_mode>("hight"), csf_);
    }
    
    void test_method_(bilinear) {
      assert::are_equal(3, enum_object<>::to_int32(interpolation_mode::bilinear), csf_);
      assert::are_equal("bilinear", enum_object<>::to_string(interpolation_mode::bilinear), csf_);
      assert::are_equal(interpolation_mode::bilinear, enum_object<>::parse<interpolation_mode>("bilinear"), csf_);
    }
    
    void test_method_(bicubic) {
      assert::are_equal(4, enum_object<>::to_int32(interpolation_mode::bicubic), csf_);
      assert::are_equal("bicubic", enum_object<>::to_string(interpolation_mode::bicubic), csf_);
      assert::are_equal(interpolation_mode::bicubic, enum_object<>::parse<interpolation_mode>("bicubic"), csf_);
    }
    
    void test_method_(nearest_neighbor) {
      assert::are_equal(5, enum_object<>::to_int32(interpolation_mode::nearest_neighbor), csf_);
      assert::are_equal("nearest_neighbor", enum_object<>::to_string(interpolation_mode::nearest_neighbor), csf_);
      assert::are_equal(interpolation_mode::nearest_neighbor, enum_object<>::parse<interpolation_mode>("nearest_neighbor"), csf_);
    }
    
    void test_method_(high_quality_bilinear) {
      assert::are_equal(6, enum_object<>::to_int32(interpolation_mode::high_quality_bilinear), csf_);
      assert::are_equal("high_quality_bilinear", enum_object<>::to_string(interpolation_mode::high_quality_bilinear), csf_);
      assert::are_equal(interpolation_mode::high_quality_bilinear, enum_object<>::parse<interpolation_mode>("high_quality_bilinear"), csf_);
    }
    
    void test_method_(high_quality_bicubic) {
      assert::are_equal(7, enum_object<>::to_int32(interpolation_mode::high_quality_bicubic), csf_);
      assert::are_equal("high_quality_bicubic", enum_object<>::to_string(interpolation_mode::high_quality_bicubic), csf_);
      assert::are_equal(interpolation_mode::high_quality_bicubic, enum_object<>::parse<interpolation_mode>("high_quality_bicubic"), csf_);
    }
  };
}
