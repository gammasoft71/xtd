#include <xtd/drawing/drawing_2d/compositing_quality>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::drawing_2d;
using namespace xtd::tunit;

namespace xtd::drawing::drawing_2d::tests {
  class test_class_(compositing_quality_tests) {
    void test_method_(invalid) {
      assert::are_equal(-1, enum_object<>::to_int32(compositing_quality::invalid), csf_);
      assert::are_equal("invalid", enum_object<>::to_string(compositing_quality::invalid), csf_);
      assert::are_equal(compositing_quality::invalid, enum_object<>::parse<compositing_quality>("invalid"), csf_);
    }
    
    void test_method_(default_value) {
      assert::are_equal(0, enum_object<>::to_int32(compositing_quality::default_value), csf_);
      assert::are_equal("default_value", enum_object<>::to_string(compositing_quality::default_value), csf_);
      assert::are_equal(compositing_quality::default_value, enum_object<>::parse<compositing_quality>("default_value"), csf_);
    }
    
    void test_method_(high_speed) {
      assert::are_equal(1, enum_object<>::to_int32(compositing_quality::high_speed), csf_);
      assert::are_equal("high_speed", enum_object<>::to_string(compositing_quality::high_speed), csf_);
      assert::are_equal(compositing_quality::high_speed, enum_object<>::parse<compositing_quality>("high_speed"), csf_);
    }
    
    void test_method_(high_quality) {
      assert::are_equal(2, enum_object<>::to_int32(compositing_quality::high_quality), csf_);
      assert::are_equal("high_quality", enum_object<>::to_string(compositing_quality::high_quality), csf_);
      assert::are_equal(compositing_quality::high_quality, enum_object<>::parse<compositing_quality>("high_quality"), csf_);
    }
    
    void test_method_(gamma_corrected) {
      assert::are_equal(3, enum_object<>::to_int32(compositing_quality::gamma_corrected), csf_);
      assert::are_equal("gamma_corrected", enum_object<>::to_string(compositing_quality::gamma_corrected), csf_);
      assert::are_equal(compositing_quality::gamma_corrected, enum_object<>::parse<compositing_quality>("gamma_corrected"), csf_);
    }
    
    void test_method_(assume_linear) {
      assert::are_equal(4, enum_object<>::to_int32(compositing_quality::assume_linear), csf_);
      assert::are_equal("assume_linear", enum_object<>::to_string(compositing_quality::assume_linear), csf_);
      assert::are_equal(compositing_quality::assume_linear, enum_object<>::parse<compositing_quality>("assume_linear"), csf_);
    }
  };
}
