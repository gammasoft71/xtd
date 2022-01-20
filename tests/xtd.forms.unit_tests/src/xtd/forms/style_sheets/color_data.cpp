#include <xtd/forms/style_sheets/color_data.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_color_data) {
  public:
    void test_method_(create_with_default_constructor) {
      color_data c;
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::black}, c.colors(), csf_);
      assert::are_equal(90, c.angle(), csf_);
    }

    void test_method_(create_with_specified_color) {
      color_data c(color::blue);
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::blue}, c.colors(), csf_);
      assert::are_equal(90, c.angle(), csf_);
    }
    
    void test_method_(create_with_specified_style_solid_and_one_colors) {
      color_data c(color_style::solid, {color::blue});
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::blue}, c.colors(), csf_);
      assert::are_equal(90, c.angle(), csf_);
    }
    
    void test_method_(create_with_specified_style_linear_gradient_and_colors) {
      color_data c(color_style::linear_gradient, {color::blue, color::white});
      assert::are_equal(color_style::linear_gradient, c.style(), csf_);
      assert::are_equal(2U, c.colors().size(), csf_);
      collection_assert::are_equal({color::blue, color::white}, c.colors(), csf_);
      assert::are_equal(90, c.angle(), csf_);
    }
    
    void test_method_(create_with_specified_style_linear_gradient_and_one_color) {
      assert::throws<argument_exception>([]{color_data c(color_style::linear_gradient, {color::blue});}, csf_);
    }
    
    void test_method_(create_with_specified_style_radial_gradient_and_colors) {
      assert::throws<not_supported_exception>([]{color_data c(color_style::radial_gradient, {color::blue, color::white});}, csf_);
    }
    
    void test_method_(create_with_specified_style_conic_gradient_and_colors) {
      assert::throws<not_supported_exception>([]{color_data c(color_style::conic_gradient, {color::blue, color::white});}, csf_);
    }
    
    void test_method_(create_with_specified_style_solid_one_colors_and_angle) {
      color_data c(color_style::solid, {color::blue}, 180);
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::blue}, c.colors(), csf_);
      assert::are_equal(180, c.angle(), csf_);
    }
    
    void test_method_(create_with_specified_style_linear_gradient_colors_and_angle) {
      color_data c(color_style::linear_gradient, {color::blue, color::white}, 180);
      assert::are_equal(color_style::linear_gradient, c.style(), csf_);
      assert::are_equal(2U, c.colors().size(), csf_);
      collection_assert::are_equal({color::blue, color::white}, c.colors(), csf_);
      assert::are_equal(180, c.angle(), csf_);
    }
    
    void test_method_(create_with_specified_style_linear_gradient_one_color_and_angle) {
      assert::throws<argument_exception>([]{color_data c(color_style::linear_gradient, {color::blue}, 180);}, csf_);
    }
    
    void test_method_(create_with_specified_style_radial_gradient_colors_and_angle) {
      assert::throws<not_supported_exception>([]{color_data c(color_style::radial_gradient, {color::blue, color::white}, 180);}, csf_);
    }
    
    void test_method_(create_with_specified_style_conic_gradient_colors_and_angle) {
      assert::throws<not_supported_exception>([]{color_data c(color_style::conic_gradient, {color::blue, color::white}, 180);}, csf_);
    }
    
    void test_method_(create_with_specified_style_solid_one_colors_and_negative_angle) {
      color_data c(color_style::solid, {color::blue}, -90);
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::blue}, c.colors(), csf_);
      assert::are_equal(270, c.angle(), csf_);
    }
    
    void test_method_(create_with_specified_style_solid_one_colors_and_angle_grrather_than_360) {
      color_data c(color_style::solid, {color::blue}, 540);
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::blue}, c.colors(), csf_);
      assert::are_equal(180, c.angle(), csf_);
    }
    
    void test_method_(create_with_specified_style_solid_one_colors_and_angle_less_than_minus_360) {
      color_data c(color_style::solid, {color::blue}, -540);
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::blue}, c.colors(), csf_);
      assert::are_equal(180, c.angle(), csf_);
    }
  };
}
