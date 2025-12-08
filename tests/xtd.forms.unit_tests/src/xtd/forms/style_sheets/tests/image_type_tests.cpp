#include <xtd/forms/style_sheets/image_type>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

namespace xtd::forms::style_sheets::tests {
  class test_class_(image_type_tests) {
  public:
    auto test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(image_type::none));
      assert::are_equal("none", enum_object<>::to_string(image_type::none));
      assert::are_equal(image_type::none, enum_object<>::parse<image_type>("none"));
    }
    
    auto test_method_(url) {
      assert::are_equal(1, enum_object<>::to_int32(image_type::url));
      assert::are_equal("url", enum_object<>::to_string(image_type::url));
      assert::are_equal(image_type::url, enum_object<>::parse<image_type>("url"));
    }
    
    auto test_method_(linear_gradient) {
      assert::are_equal(2, enum_object<>::to_int32(image_type::linear_gradient));
      assert::are_equal("linear_gradient", enum_object<>::to_string(image_type::linear_gradient));
      assert::are_equal(image_type::linear_gradient, enum_object<>::parse<image_type>("linear_gradient"));
    }
    
    auto test_method_(radial_gradient) {
      assert::are_equal(3, enum_object<>::to_int32(image_type::radial_gradient));
      assert::are_equal("radial_gradient", enum_object<>::to_string(image_type::radial_gradient));
      assert::are_equal(image_type::radial_gradient, enum_object<>::parse<image_type>("radial_gradient"));
    }
    
    auto test_method_(conic_gradient) {
      assert::are_equal(4, enum_object<>::to_int32(image_type::conic_gradient));
      assert::are_equal("conic_gradient", enum_object<>::to_string(image_type::conic_gradient));
      assert::are_equal(image_type::conic_gradient, enum_object<>::parse<image_type>("conic_gradient"));
    }
  };
}
