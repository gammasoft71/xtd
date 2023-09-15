#include <xtd/drawing/drawing_2d/smoothing_mode>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::drawing_2d;
using namespace xtd::tunit;

namespace xtd::drawing::drawing_2d::tests {
  class test_class_(smoothing_mode_tests) {
  public:
    void test_method_(invalid) {
      assert::are_equal(-1, enum_object<>::to_int32(smoothing_mode::invalid), csf_);
      assert::are_equal("invalid", enum_object<>::to_string(smoothing_mode::invalid), csf_);
      assert::are_equal(smoothing_mode::invalid, enum_object<>::parse<smoothing_mode>("invalid"), csf_);
    }
    
    void test_method_(default_value) {
      assert::are_equal(0, enum_object<>::to_int32(smoothing_mode::default_value), csf_);
      assert::are_equal("default_value", enum_object<>::to_string(smoothing_mode::default_value), csf_);
      assert::are_equal(smoothing_mode::default_value, enum_object<>::parse<smoothing_mode>("default_value"), csf_);
    }
    
    void test_method_(high_speed) {
      assert::are_equal(1, enum_object<>::to_int32(smoothing_mode::high_speed), csf_);
      assert::are_equal("high_speed", enum_object<>::to_string(smoothing_mode::high_speed), csf_);
      assert::are_equal(smoothing_mode::high_speed, enum_object<>::parse<smoothing_mode>("high_speed"), csf_);
    }
    
    void test_method_(high_quality) {
      assert::are_equal(2, enum_object<>::to_int32(smoothing_mode::high_quality), csf_);
      assert::are_equal("high_quality", enum_object<>::to_string(smoothing_mode::high_quality), csf_);
      assert::are_equal(smoothing_mode::high_quality, enum_object<>::parse<smoothing_mode>("high_quality"), csf_);
    }
    
    void test_method_(none) {
      assert::are_equal(3, enum_object<>::to_int32(smoothing_mode::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(smoothing_mode::none), csf_);
      assert::are_equal(smoothing_mode::none, enum_object<>::parse<smoothing_mode>("none"), csf_);
    }
    
    void test_method_(anti_alias) {
      assert::are_equal(4, enum_object<>::to_int32(smoothing_mode::anti_alias), csf_);
      assert::are_equal("anti_alias", enum_object<>::to_string(smoothing_mode::anti_alias), csf_);
      assert::are_equal(smoothing_mode::anti_alias, enum_object<>::parse<smoothing_mode>("anti_alias"), csf_);
    }
  };
}
