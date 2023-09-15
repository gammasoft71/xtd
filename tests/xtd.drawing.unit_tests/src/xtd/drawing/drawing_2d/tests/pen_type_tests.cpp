#include <xtd/drawing/drawing_2d/pen_type>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::drawing_2d;
using namespace xtd::tunit;

namespace xtd::drawing::drawing_2d::tests {
  class test_class_(pen_type_tests) {
  public:
    void test_method_(solid_color) {
      assert::are_equal(0, enum_object<>::to_int32(pen_type::solid_color), csf_);
      assert::are_equal("solid_color", enum_object<>::to_string(pen_type::solid_color), csf_);
      assert::are_equal(pen_type::solid_color, enum_object<>::parse<pen_type>("solid_color"), csf_);
    }
    
    void test_method_(hatch_fill) {
      assert::are_equal(1, enum_object<>::to_int32(pen_type::hatch_fill), csf_);
      assert::are_equal("hatch_fill", enum_object<>::to_string(pen_type::hatch_fill), csf_);
      assert::are_equal(pen_type::hatch_fill, enum_object<>::parse<pen_type>("hatch_fill"), csf_);
    }
    
    void test_method_(texture_fill) {
      assert::are_equal(2, enum_object<>::to_int32(pen_type::texture_fill), csf_);
      assert::are_equal("texture_fill", enum_object<>::to_string(pen_type::texture_fill), csf_);
      assert::are_equal(pen_type::texture_fill, enum_object<>::parse<pen_type>("texture_fill"), csf_);
    }
    
    void test_method_(path_gradient) {
      assert::are_equal(3, enum_object<>::to_int32(pen_type::path_gradient), csf_);
      assert::are_equal("path_gradient", enum_object<>::to_string(pen_type::path_gradient), csf_);
      assert::are_equal(pen_type::path_gradient, enum_object<>::parse<pen_type>("path_gradient"), csf_);
    }
    
    void test_method_(linear_gradient) {
      assert::are_equal(4, enum_object<>::to_int32(pen_type::linear_gradient), csf_);
      assert::are_equal("linear_gradient", enum_object<>::to_string(pen_type::linear_gradient), csf_);
      assert::are_equal(pen_type::linear_gradient, enum_object<>::parse<pen_type>("linear_gradient"), csf_);
    }
    
    void test_method_(conical_gradient) {
      assert::are_equal(5, enum_object<>::to_int32(pen_type::conical_gradient), csf_);
      assert::are_equal("conical_gradient", enum_object<>::to_string(pen_type::conical_gradient), csf_);
      assert::are_equal(pen_type::conical_gradient, enum_object<>::parse<pen_type>("conical_gradient"), csf_);
    }
    
    void test_method_(radial_gradient) {
      assert::are_equal(6, enum_object<>::to_int32(pen_type::radial_gradient), csf_);
      assert::are_equal("radial_gradient", enum_object<>::to_string(pen_type::radial_gradient), csf_);
      assert::are_equal(pen_type::radial_gradient, enum_object<>::parse<pen_type>("radial_gradient"), csf_);
    }
  };
}
