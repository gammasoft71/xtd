#include <xtd/drawing/text/text_rendering_hint>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::text;
using namespace xtd::tunit;

namespace xtd::drawing::text::tests {
  class test_class_(text_rendering_hint_tests) {
  public:
    void test_method_(system_default) {
      assert::are_equal(0, enum_object<>::to_int32(text_rendering_hint::system_default), csf_);
      assert::are_equal("system_default", enum_object<>::to_string(text_rendering_hint::system_default), csf_);
      assert::are_equal(text_rendering_hint::system_default, enum_object<>::parse<text_rendering_hint>("system_default"), csf_);
    }
    
    void test_method_(single_bit_per_pixel_grid_fit) {
      assert::are_equal(1, enum_object<>::to_int32(text_rendering_hint::single_bit_per_pixel_grid_fit), csf_);
      assert::are_equal("single_bit_per_pixel_grid_fit", enum_object<>::to_string(text_rendering_hint::single_bit_per_pixel_grid_fit), csf_);
      assert::are_equal(text_rendering_hint::single_bit_per_pixel_grid_fit, enum_object<>::parse<text_rendering_hint>("single_bit_per_pixel_grid_fit"), csf_);
    }
    
    void test_method_(single_bit_per_pixel) {
      assert::are_equal(2, enum_object<>::to_int32(text_rendering_hint::single_bit_per_pixel), csf_);
      assert::are_equal("single_bit_per_pixel", enum_object<>::to_string(text_rendering_hint::single_bit_per_pixel), csf_);
      assert::are_equal(text_rendering_hint::single_bit_per_pixel, enum_object<>::parse<text_rendering_hint>("single_bit_per_pixel"), csf_);
    }
    
    void test_method_(anti_alias_grid_fit) {
      assert::are_equal(3, enum_object<>::to_int32(text_rendering_hint::anti_alias_grid_fit), csf_);
      assert::are_equal("anti_alias_grid_fit", enum_object<>::to_string(text_rendering_hint::anti_alias_grid_fit), csf_);
      assert::are_equal(text_rendering_hint::anti_alias_grid_fit, enum_object<>::parse<text_rendering_hint>("anti_alias_grid_fit"), csf_);
    }
    
    void test_method_(anti_alias) {
      assert::are_equal(4, enum_object<>::to_int32(text_rendering_hint::anti_alias), csf_);
      assert::are_equal("anti_alias", enum_object<>::to_string(text_rendering_hint::anti_alias), csf_);
      assert::are_equal(text_rendering_hint::anti_alias, enum_object<>::parse<text_rendering_hint>("anti_alias"), csf_);
    }
    
    void test_method_(clear_type_grid_fit) {
      assert::are_equal(5, enum_object<>::to_int32(text_rendering_hint::clear_type_grid_fit), csf_);
      assert::are_equal("clear_type_grid_fit", enum_object<>::to_string(text_rendering_hint::clear_type_grid_fit), csf_);
      assert::are_equal(text_rendering_hint::clear_type_grid_fit, enum_object<>::parse<text_rendering_hint>("clear_type_grid_fit"), csf_);
    }
  };
}
