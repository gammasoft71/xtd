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
    
    void test_method_(try_parse_with_hash_and_no_hex) {
      color_data c;
      assert::is_false(color_data::try_parse("#", c), csf_);
    }
    
    void test_method_(try_parse_with_hash_and_one_hex) {
      color_data c;
      assert::is_false(color_data::try_parse("#1", c), csf_);
    }

    void test_method_(try_parse_with_hash_and_two_hex) {
      color_data c;
      assert::is_false(color_data::try_parse("#12", c), csf_);
    }

    void test_method_(try_parse_with_hash_and_three_hex) {
      color_data c;
      assert::is_true(color_data::try_parse("#123", c), csf_);
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::from_argb(0xFF112233)}, c.colors(), csf_);
      assert::are_equal(90, c.angle(), csf_);
    }
    
    void test_method_(try_parse_with_hash_and_four_hex) {
      color_data c;
      assert::is_true(color_data::try_parse("#1234", c), csf_);
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::from_argb(0x11223344)}, c.colors(), csf_);
      assert::are_equal(90, c.angle(), csf_);
    }
    
    void test_method_(try_parse_with_hash_and_five_hex) {
      color_data c;
      assert::is_false(color_data::try_parse("#12345", c), csf_);
    }

    void test_method_(try_parse_with_hash_and_six_hex) {
      color_data c;
      assert::is_true(color_data::try_parse("#123456", c), csf_);
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::from_argb(0xFF123456)}, c.colors(), csf_);
      assert::are_equal(90, c.angle(), csf_);
    }
    
    void test_method_(try_parse_with_hash_and_seven_hex) {
      color_data c;
      assert::is_false(color_data::try_parse("#1234567", c), csf_);
    }

    void test_method_(try_parse_with_hash_and_eight_hex) {
      color_data c;
      assert::is_true(color_data::try_parse("#12345678", c), csf_);
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::from_argb(0x12345678)}, c.colors(), csf_);
      assert::are_equal(90, c.angle(), csf_);
    }
    
    void test_method_(try_parse_with_hash_and_nine_and_more_hex) {
      color_data c;
      assert::is_false(color_data::try_parse("#123456789", c), csf_);
      assert::is_false(color_data::try_parse("#1234567890", c), csf_);
      assert::is_false(color_data::try_parse("#12345678901", c), csf_);
      assert::is_false(color_data::try_parse("#1234567890123456", c), csf_);
    }
    
    void test_method_(try_parse_with_color_name_lightgreen) {
      color_data c;
      assert::is_true(color_data::try_parse("lightgreen", c), csf_);
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::light_green}, c.colors(), csf_);
      assert::are_equal(90, c.angle(), csf_);
    }
    
    void test_method_(try_parse_with_color_name_light_green) {
      color_data c;
      assert::is_true(color_data::try_parse("light green", c), csf_);
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::light_green}, c.colors(), csf_);
      assert::are_equal(90, c.angle(), csf_);
    }
    
    void test_method_(try_parse_with_unknown_color_name) {
      color_data c;
      assert::is_false(color_data::try_parse("graan", c), csf_);
    }
    
    void test_method_(try_parse_with_rgb_color) {
      color_data c;
      assert::is_true(color_data::try_parse("rgb(42, 84, 24)", c), csf_);
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::from_argb(42, 84, 24)}, c.colors(), csf_);
      assert::are_equal(90, c.angle(), csf_);
    }
    
    void test_method_(try_parse_with_bad_rgb_color) {
      color_data c;
      assert::is_false(color_data::try_parse("rgb(42, 84, 24", c), csf_);
      assert::is_false(color_data::try_parse("rgb(42, 84)", c), csf_);
      assert::is_false(color_data::try_parse("rgb(42, 84, 24, 12)", c), csf_);
    }
    
    void test_method_(try_parse_with_rgba_color) {
      color_data c;
      assert::is_true(color_data::try_parse("rgba(42, 84, 24, 128)", c), csf_);
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::from_argb(128, 42, 84, 24)}, c.colors(), csf_);
      assert::are_equal(90, c.angle(), csf_);
    }
    
    void test_method_(try_parse_with_bad_rgba_color) {
      color_data c;
      assert::is_false(color_data::try_parse("rgba(42, 84, 24, 128", c), csf_);
      assert::is_false(color_data::try_parse("rgba(42, 84, 128)", c), csf_);
      assert::is_false(color_data::try_parse("rgba(42, 84, 24, 12, 128)", c), csf_);
    }
    
    void test_method_(try_parse_with_argb_color) {
      color_data c;
      assert::is_true(color_data::try_parse("argb(128, 42, 84, 24)", c), csf_);
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::from_argb(128, 42, 84, 24)}, c.colors(), csf_);
      assert::are_equal(90, c.angle(), csf_);
    }
    
    void test_method_(try_parse_with_bad_argb_color) {
      color_data c;
      assert::is_false(color_data::try_parse("argb(128, 42, 84, 24", c), csf_);
      assert::is_false(color_data::try_parse("argb(128, 42, 84)", c), csf_);
      assert::is_false(color_data::try_parse("argb(128, 42, 84, 24, 12)", c), csf_);
    }
    
    void test_method_(try_parse_with_hsv_color) {
      color_data c;
      assert::is_true(color_data::try_parse("hsv(204, 62, 67)", c), csf_);
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::from_hsb(204, 62, 67)}, c.colors(), csf_);
      assert::are_equal(90, c.angle(), csf_);
    }
    
    void test_method_(try_parse_with_bad_hsv_color) {
      color_data c;
      assert::is_false(color_data::try_parse("hsv(204, 62, 67", c), csf_);
      assert::is_false(color_data::try_parse("hsv(204, 62)", c), csf_);
      assert::is_false(color_data::try_parse("hsv(204, 62, 67, 12)", c), csf_);
    }
    
    void test_method_(try_parse_with_hsva_color) {
      color_data c;
      assert::is_true(color_data::try_parse("hsva(204, 62, 67, 128)", c), csf_);
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::from_argb(128, color::from_hsb(204, 62, 67))}, c.colors(), csf_);
      assert::are_equal(90, c.angle(), csf_);
    }
    
    void test_method_(try_parse_with_bad_hsva_color) {
      color_data c;
      assert::is_false(color_data::try_parse("hsva(204, 62, 67, 128", c), csf_);
      assert::is_false(color_data::try_parse("hsva(204, 62, 128)", c), csf_);
      assert::is_false(color_data::try_parse("hsva(204, 62, 67, 12, 128)", c), csf_);
    }
    
    void test_method_(try_parse_with_ahsv_color) {
      color_data c;
      assert::is_true(color_data::try_parse("ahsv(128, 204, 62, 67)", c), csf_);
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::from_argb(128, color::from_hsb(204, 62, 67))}, c.colors(), csf_);
      assert::are_equal(90, c.angle(), csf_);
    }
    
    void test_method_(try_parse_with_bad_ahsv_color) {
      color_data c;
      assert::is_false(color_data::try_parse("ahsv(204, 62, 67", c), csf_);
      assert::is_false(color_data::try_parse("ahsv(204, 62, 67)", c), csf_);
      assert::is_false(color_data::try_parse("ahsv(128, 204, 62, 67, 12)", c), csf_);
    }
    
    void test_method_(try_parse_with_hsl_color) {
      color_data c;
      assert::is_true(color_data::try_parse("hsl(204, 62, 67)", c), csf_);
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::from_hsl(204, 62, 67)}, c.colors(), csf_);
      assert::are_equal(90, c.angle(), csf_);
    }
    
    void test_method_(try_parse_with_bad_hsl_color) {
      color_data c;
      assert::is_false(color_data::try_parse("hsl(204, 62, 67", c), csf_);
      assert::is_false(color_data::try_parse("hsl(204, 62)", c), csf_);
      assert::is_false(color_data::try_parse("hsl(204, 62, 67, 12)", c), csf_);
    }
    
    void test_method_(try_parse_with_hsla_color) {
      color_data c;
      assert::is_true(color_data::try_parse("hsla(204, 62, 67, 128)", c), csf_);
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::from_argb(128, color::from_hsl(204, 62, 67))}, c.colors(), csf_);
      assert::are_equal(90, c.angle(), csf_);
    }
    
    void test_method_(try_parse_with_bad_hsla_color) {
      color_data c;
      assert::is_false(color_data::try_parse("hsla(204, 62, 67, 128", c), csf_);
      assert::is_false(color_data::try_parse("hsla(204, 62, 128)", c), csf_);
      assert::is_false(color_data::try_parse("hsla(204, 62, 67, 12, 128)", c), csf_);
    }
    
    void test_method_(try_parse_with_ahsl_color) {
      color_data c;
      assert::is_true(color_data::try_parse("ahsl(128, 204, 62, 67)", c), csf_);
      assert::are_equal(color_style::solid, c.style(), csf_);
      assert::are_equal(1U, c.colors().size(), csf_);
      collection_assert::are_equal({color::from_argb(128, color::from_hsl(204, 62, 67))}, c.colors(), csf_);
      assert::are_equal(90, c.angle(), csf_);
    }
    
    void test_method_(try_parse_with_bad_ahsl_color) {
      color_data c;
      assert::is_false(color_data::try_parse("ahsl(204, 62, 67", c), csf_);
      assert::is_false(color_data::try_parse("ahsl(204, 62, 67)", c), csf_);
      assert::is_false(color_data::try_parse("ahsl(128, 204, 62, 67, 12)", c), csf_);
    }
  };
}
