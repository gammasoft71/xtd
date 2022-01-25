#include <xtd/forms/style_sheets/color_data.h>
#include <xtd/drawing/system_colors.h>
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
      assert::are_equal(color::transparent, c.color(), csf_);
    }

    void test_method_(create_with_specified_color) {
      color_data c(color::blue);
      assert::are_equal(color::blue, c.color(), csf_);
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
      assert::are_equal(color::from_argb(0xFF112233), c.color(), csf_);
    }
    
    void test_method_(try_parse_with_hash_and_four_hex) {
      color_data c;
      assert::is_true(color_data::try_parse("#1234", c), csf_);
      assert::are_equal(color::from_argb(0x11223344), c.color(), csf_);
    }
    
    void test_method_(try_parse_with_hash_and_five_hex) {
      color_data c;
      assert::is_false(color_data::try_parse("#12345", c), csf_);
    }

    void test_method_(try_parse_with_hash_and_six_hex) {
      color_data c;
      assert::is_true(color_data::try_parse("#123456", c), csf_);
      assert::are_equal(color::from_argb(0xFF123456), c.color(), csf_);
    }
    
    void test_method_(try_parse_with_hash_and_seven_hex) {
      color_data c;
      assert::is_false(color_data::try_parse("#1234567", c), csf_);
    }

    void test_method_(try_parse_with_hash_and_eight_hex) {
      color_data c;
      assert::is_true(color_data::try_parse("#12345678", c), csf_);
      assert::are_equal(color::from_argb(0x12345678), c.color(), csf_);
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
      assert::are_equal(color::light_green, c.color(), csf_);
    }
    
    void test_method_(try_parse_with_color_name_light_green) {
      color_data c;
      assert::is_false(color_data::try_parse("light green", c), csf_);
    }
    
    void test_method_(try_parse_with_unknown_color_name) {
      color_data c;
      assert::is_false(color_data::try_parse("graan", c), csf_);
    }
    
    void test_method_(try_parse_with_rgb_color) {
      color_data c;
      assert::is_true(color_data::try_parse("rgb(42, 84, 24)", c), csf_);
      assert::are_equal(color::from_argb(42, 84, 24), c.color(), csf_);
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
      assert::are_equal(color::from_argb(128, 42, 84, 24), c.color(), csf_);
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
      assert::are_equal(color::from_argb(128, 42, 84, 24), c.color(), csf_);
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
      assert::are_equal(color::from_hsb(204, 62, 67), c.color(), csf_);
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
      assert::are_equal(color::from_argb(128, color::from_hsb(204, 62, 67)), c.color(), csf_);
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
      assert::are_equal(color::from_argb(128, color::from_hsb(204, 62, 67)), c.color(), csf_);
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
      assert::are_equal(color::from_hsl(204, 62, 67), c.color(), csf_);
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
      assert::are_equal(color::from_argb(128, color::from_hsl(204, 62, 67)), c.color(), csf_);
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
      assert::are_equal(color::from_argb(128, color::from_hsl(204, 62, 67)), c.color(), csf_);
    }
    
    void test_method_(try_parse_with_bad_ahsl_color) {
      color_data c;
      assert::is_false(color_data::try_parse("ahsl(204, 62, 67", c), csf_);
      assert::is_false(color_data::try_parse("ahsl(204, 62, 67)", c), csf_);
      assert::is_false(color_data::try_parse("ahsl(128, 204, 62, 67, 12)", c), csf_);
    }
    
    void test_method_(try_parse_with_system_color) {
      color_data c;
      assert::is_true(color_data::try_parse("system-color(control-text)", c), csf_);
      /// @todo Replace drawing::system_colors by theme::system_colors
      assert::are_equal(system_colors::control_text(), c.color(), csf_);
    }
    
    void test_method_(try_parse_with_bad_system_color) {
      color_data c;
      assert::is_false(color_data::try_parse("system-color(control-text", c), csf_);
      assert::is_false(color_data::try_parse("system-color(checkbox)", c), csf_);
    }
    
    void test_method_(to_css_color_data_with_color_name_white) {
      assert::are_equal("white", color_data(color::white).to_css());
    }
    
    void test_method_(to_css_color_data_with_color_name_light_green) {
      assert::are_equal("lightgreen", color_data(color::light_green).to_css());
    }
    
    void test_method_(to_css_color_data_with_alpha_to_255) {
      assert::are_equal("#FF8040", color_data(color::from_argb(255, 128, 64)).to_css());
    }
    
    void test_method_(to_css_color_data_with_alpha_not_255) {
      assert::are_equal("rgba(255, 128, 64, 32)", color_data(color::from_argb(32, 255, 128, 64)).to_css());
    }
    
    void test_method_(to_css_color_data_with_system_color) {
      assert::are_equal("system-color(control-text)", color_data(system_colors::control_text()).to_css());
    }
  };
}
