#include <xtd/forms/color_box_styles>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(color_box_styles_tests) {
  public:
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(color_box_styles::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(color_box_styles::none), csf_);
      assert::are_equal(color_box_styles::none, enum_object<>::parse<color_box_styles>("none"), csf_);
    }
    
    void test_method_(alpha_color) {
      assert::are_equal(1, enum_object<>::to_int32(color_box_styles::alpha_color), csf_);
      assert::are_equal("alpha_color", enum_object<>::to_string(color_box_styles::alpha_color), csf_);
      assert::are_equal(color_box_styles::alpha_color, enum_object<>::parse<color_box_styles>("alpha_color"), csf_);
    }
    
    void test_method_(allow_full_open) {
      assert::are_equal(2, enum_object<>::to_int32(color_box_styles::allow_full_open), csf_);
      assert::are_equal("allow_full_open", enum_object<>::to_string(color_box_styles::allow_full_open), csf_);
      assert::are_equal(color_box_styles::allow_full_open, enum_object<>::parse<color_box_styles>("allow_full_open"), csf_);
    }
    
    void test_method_(any_color) {
      assert::are_equal(4, enum_object<>::to_int32(color_box_styles::any_color), csf_);
      assert::are_equal("any_color", enum_object<>::to_string(color_box_styles::any_color), csf_);
      assert::are_equal(color_box_styles::any_color, enum_object<>::parse<color_box_styles>("any_color"), csf_);
    }
    
    void test_method_(full_open) {
      assert::are_equal(8, enum_object<>::to_int32(color_box_styles::full_open), csf_);
      assert::are_equal("full_open", enum_object<>::to_string(color_box_styles::full_open), csf_);
      assert::are_equal(color_box_styles::full_open, enum_object<>::parse<color_box_styles>("full_open"), csf_);
    }
    
    void test_method_(show_help) {
      assert::are_equal(16, enum_object<>::to_int32(color_box_styles::show_help), csf_);
      assert::are_equal("show_help", enum_object<>::to_string(color_box_styles::show_help), csf_);
      assert::are_equal(color_box_styles::show_help, enum_object<>::parse<color_box_styles>("show_help"), csf_);
    }
    
    void test_method_(solid_color_only) {
      assert::are_equal(32, enum_object<>::to_int32(color_box_styles::solid_color_only), csf_);
      assert::are_equal("solid_color_only", enum_object<>::to_string(color_box_styles::solid_color_only), csf_);
      assert::are_equal(color_box_styles::solid_color_only, enum_object<>::parse<color_box_styles>("solid_color_only"), csf_);
    }
  };
}
