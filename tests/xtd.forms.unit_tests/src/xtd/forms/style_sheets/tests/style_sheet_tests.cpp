#include <xtd/forms/style_sheets/style_sheet>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

class __test_style_sheet__ static_ {
public:
  static border_color border_color_from_css(style_sheets::style_sheet& style_sheet, const xtd::ustring& css_text, const border_color& result) noexcept {
    return style_sheet.border_color_from_css(css_text, result);
  }
  static style_sheets::border_style border_style_from_css(style_sheets::style_sheet& style_sheet, const ustring& css_text, const style_sheets::border_style& default_value) noexcept {
    return style_sheet.border_style_from_css(css_text, default_value);
  }
  static xtd::drawing::color color_from_css(style_sheets::style_sheet& style_sheet, const xtd::ustring& css_text, const xtd::drawing::color& default_value) noexcept {
    return style_sheet.color_from_css(css_text, default_value);
  }
  static background_image background_image_from_css(style_sheets::style_sheet& style_sheet, const xtd::ustring& css_text, const background_image& default_value) noexcept {
    return style_sheet.background_image_from_css(css_text, default_value);
  }
  static length length_from_css(style_sheets::style_sheet& style_sheet, const xtd::ustring& css_text, const length& default_value) noexcept {
    return style_sheet.length_from_css(css_text, default_value);
  }
  static xtd::ustring string_from_css(style_sheets::style_sheet& style_sheet, const xtd::ustring& css_text, const xtd::ustring& default_value) noexcept {
    return style_sheet.string_from_css(css_text, default_value);
  }
  static xtd::uri uri_from_css(style_sheets::style_sheet& style_sheet, const xtd::ustring& css_text, const xtd::uri& default_value) noexcept {
    return style_sheet.uri_from_css(css_text, default_value);
  }
};

namespace xtd::forms::style_sheets::tests {
  class test_class_(style_sheet_tests) {
    void test_method_(style_sheets) {
      auto styles = style_sheet::style_sheets();
      assert::are_not_equal(styles.end(), styles.find("GNOME (dark)"), csf_);
      assert::are_not_equal(styles.end(), styles.find("GNOME (light)"), csf_);
      assert::are_not_equal(styles.end(), styles.find("KDE (dark)"), csf_);
      assert::are_not_equal(styles.end(), styles.find("KDE (light)"), csf_);
      assert::are_not_equal(styles.end(), styles.find("macOS (light)"), csf_);
      assert::are_not_equal(styles.end(), styles.find("macOS (dark)"), csf_);
      assert::are_not_equal(styles.end(), styles.find("Symbolic (light)"), csf_);
      assert::are_not_equal(styles.end(), styles.find("Symbolic (dark)"), csf_);
    }
    
    void test_method_(color_from_css_with_hash_and_no_hex) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "#", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hash_and_one_hex) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "#1", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hash_and_two_hex) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "#12", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hash_and_three_hex) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_argb(0xFF112233), __test_style_sheet__::color_from_css(style, "#123", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hash_and_four_hex) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_argb(0x11223344), __test_style_sheet__::color_from_css(style, "#1234", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hash_and_five_hex) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "#12345", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hash_and_six_hex) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_argb(0xFF123456), __test_style_sheet__::color_from_css(style, "#123456", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hash_and_seven_hex) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "#1234567", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hash_and_eight_hex) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_argb(0x12345678), __test_style_sheet__::color_from_css(style, "#12345678", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hash_and_nine_and_more_hex) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "#123456789", color::empty), csf_);
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "#1234567890", color::empty), csf_);
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "#12345678901", color::empty), csf_);
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "#1234567890123456", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_color_name_lightgreen) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::light_green, __test_style_sheet__::color_from_css(style, "lightgreen", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_color_name_light_green) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "light green", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_unknown_color_name) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "graan", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_rgb_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_argb(42, 84, 24), __test_style_sheet__::color_from_css(style, "rgb(42, 84, 24)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_bad_rgb_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "rgb(42, 84, 24", color::empty), csf_);
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "rgb(42, 84)", color::empty), csf_);
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "rgb(42, 84, 24, 12)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_rgba_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_argb(128, 42, 84, 24), __test_style_sheet__::color_from_css(style, "rgba(42, 84, 24, 0.5)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_bad_rgba_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "rgba(42, 84, 24, 0.5", color::empty), csf_);
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "rgba(42, 84, 0.5)", color::empty), csf_);
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "rgba(42, 84, 24, 12, 0.5)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hsv_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_hsb(204, 62, 67), __test_style_sheet__::color_from_css(style, "hsv(204, 62, 67)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_bad_hsv_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "hsv(204, 62, 67", color::empty), csf_);
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "hsv(204, 62)", color::empty), csf_);
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "hsv(204, 62, 67, 12)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hsva_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_argb(128, color::from_hsb(204, 62, 67)), __test_style_sheet__::color_from_css(style, "hsva(204, 62, 67, 0.5)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_bad_hsva_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "hsva(204, 62, 67, 0.5", color::empty), csf_);
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "hsva(204, 62, 0.5)", color::empty), csf_);
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "hsva(204, 62, 67, 12, 0.5)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hsl_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_hsl(204, 62, 67), __test_style_sheet__::color_from_css(style, "hsl(204, 62, 67)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_bad_hsl_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "hsl(204, 62, 67", color::empty), csf_);
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "hsl(204, 62)", color::empty), csf_);
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "hsl(204, 62, 67, 12)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hsla_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_argb(128, color::from_hsl(204, 62, 67)), __test_style_sheet__::color_from_css(style, "hsla(204, 62, 67, 0.5)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_bad_hsla_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "hsla(204, 62, 67, 0.5", color::empty), csf_);
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "hsla(204, 62, 0.5)", color::empty), csf_);
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "hsla(204, 62, 67, 12, 0.5)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_system_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(style.system_colors().control_text(), __test_style_sheet__::color_from_css(style, "system-color(control-text)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_bad_system_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "system-color(control-text", color::empty), csf_);
      assert::are_equal(color::empty, __test_style_sheet__::color_from_css(style, "system-color(checkbox)", color::empty), csf_);
    }
    
    void test_method_(string_from_css) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal("String text.", __test_style_sheet__::string_from_css(style, "\"String text.\"", "Default"), csf_);
    }
    
    void test_method_(string_from_css_with_bad_format) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal("Default", __test_style_sheet__::string_from_css(style, "String text.", "Default"), csf_);
    }
    
    void test_method_(uri_from_css) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal("https://gammasoft71.github.io/xtd", __test_style_sheet__::uri_from_css(style, "url(https://gammasoft71.github.io/xtd)", uri("https://gammasoft71.wixsite.com/gammasoft")).to_string(), csf_);
    }
    
    void test_method_(uri_from_css_with_bad_format) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal("https://gammasoft71.wixsite.com/gammasoft", __test_style_sheet__::string_from_css(style, "https://gammasoft71.github.io/xtd", "https://gammasoft71.wixsite.com/gammasoft"), csf_);
    }
    
    void test_method_(linear_gradient_from_css_with_named_colors) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(background_image(image_type::linear_gradient, {color::blue, color::white}, 180), __test_style_sheet__::background_image_from_css(style, "linear-gradient(blue, white)", background_image::empty), csf_);
    }
    
    void test_method_(linear_gradient_from_css_with_to_top_and_named_colors) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(background_image(image_type::linear_gradient, {color::blue, color::white}, 0), __test_style_sheet__::background_image_from_css(style, "linear-gradient(to top, blue, white)", background_image::empty), csf_);
    }
    
    void test_method_(linear_gradient_from_css_with_to_top_right_and_named_colors) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(background_image(image_type::linear_gradient, {color::blue, color::white}, 45), __test_style_sheet__::background_image_from_css(style, "linear-gradient(to top right, blue, white)", background_image::empty), csf_);
    }
    
    void test_method_(linear_gradient_from_css_with_to_right_and_named_colors) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(background_image(image_type::linear_gradient, {color::blue, color::white}, 90), __test_style_sheet__::background_image_from_css(style, "linear-gradient(to right, blue, white)", background_image::empty), csf_);
    }
    
    void test_method_(linear_gradient_from_css_with_to_bottom_right_and_named_colors) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(background_image(image_type::linear_gradient, {color::blue, color::white}, 135), __test_style_sheet__::background_image_from_css(style, "linear-gradient(to bottom right, blue, white)", background_image::empty), csf_);
    }
    
    void test_method_(linear_gradient_from_css_with_to_bottom_and_named_colors) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(background_image(image_type::linear_gradient, {color::blue, color::white}, 180), __test_style_sheet__::background_image_from_css(style, "linear-gradient(to bottom, blue, white)", background_image::empty), csf_);
    }
    
    void test_method_(linear_gradient_from_css_with_to_bottom_left_and_named_colors) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(background_image(image_type::linear_gradient, {color::blue, color::white}, 225), __test_style_sheet__::background_image_from_css(style, "linear-gradient(to bottom left, blue, white)", background_image::empty), csf_);
    }
    
    void test_method_(linear_gradient_from_css_with_to_left_and_named_colors) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(background_image(image_type::linear_gradient, {color::blue, color::white}, 270), __test_style_sheet__::background_image_from_css(style, "linear-gradient(to left, blue, white)", background_image::empty), csf_);
    }
    
    void test_method_(linear_gradient_from_css_with_to_top_left_and_named_colors) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(background_image(image_type::linear_gradient, {color::blue, color::white}, 315), __test_style_sheet__::background_image_from_css(style, "linear-gradient(to top left, blue, white)", background_image::empty), csf_);
    }
    
    void test_method_(linear_gradient_from_css_with_angle_and_named_colors) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(background_image(image_type::linear_gradient, {color::blue, color::white}, 126), __test_style_sheet__::background_image_from_css(style, "linear-gradient(126deg, blue, white)", background_image::empty), csf_);
    }
    
    void test_method_(linear_gradient_from_css_with_rgb_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(background_image(image_type::linear_gradient, {color::from_argb(42, 24, 12), color::from_argb(84, 128, 16)}, 180), __test_style_sheet__::background_image_from_css(style, "linear-gradient(rgb(42, 24, 12), rgb(84, 128, 16))", background_image::empty), csf_);
    }
    
    void test_method_(linear_gradient_from_css_with_angle_rgb_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(background_image(image_type::linear_gradient, {color::from_argb(42, 24, 12), color::from_argb(84, 128, 16)}, 24), __test_style_sheet__::background_image_from_css(style, "linear-gradient(24deg, rgb(42, 24, 12), rgb(84, 128, 16))", background_image::empty), csf_);
    }
    
    void test_method_(linear_gradient_from_css_with_to_left_rgb_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(background_image(image_type::linear_gradient, {color::from_argb(42, 24, 12), color::from_argb(84, 128, 16)}, 270), __test_style_sheet__::background_image_from_css(style, "linear-gradient(to left, rgb(42, 24, 12), rgb(84, 128, 16))", background_image::empty), csf_);
    }
    
    void test_method_(rect_test) {
      auto bounds = drawing::rectangle(100, 200, 300, 400);
      style_sheets::control ctrl;
      ctrl.margin({length(1), length(2), length(3), length(4)});
      ctrl.border_width({length(5), length(6), length(7), length(8)});
      ctrl.border_style(border_style(border_type::solid));
      ctrl.padding({length(9), length(10), length(11), length(12)});
      assert::are_equal(drawing::rectangle(101, 202, 296, 394), ctrl.get_border_rectangle(bounds));
      assert::are_equal(drawing::rectangle(106, 208, 284, 380), ctrl.get_fill_rectangle(bounds));
      assert::are_equal(drawing::rectangle(115, 218, 264, 358), ctrl.get_content_rectangle(bounds));
    }
  };
}
