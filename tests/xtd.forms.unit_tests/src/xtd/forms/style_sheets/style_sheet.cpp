#include <xtd/forms/style_sheets/style_sheet.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_style_sheet) {
  public:
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
      assert::are_equal(color::empty, style.color_from_css("#", color::empty), csf_);
    }

    void test_method_(color_from_css_with_hash_and_one_hex) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, style.color_from_css("#1", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hash_and_two_hex) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, style.color_from_css("#12", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hash_and_three_hex) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_argb(0xFF112233), style.color_from_css("#123", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hash_and_four_hex) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_argb(0x11223344), style.color_from_css("#1234", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hash_and_five_hex) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, style.color_from_css("#12345", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hash_and_six_hex) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_argb(0xFF123456), style.color_from_css("#123456", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hash_and_seven_hex) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, style.color_from_css("#1234567", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hash_and_eight_hex) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_argb(0x12345678), style.color_from_css("#12345678", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hash_and_nine_and_more_hex) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, style.color_from_css("#123456789", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("#1234567890", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("#12345678901", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("#1234567890123456", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_color_name_lightgreen) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::light_green, style.color_from_css("lightgreen", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_color_name_light_green) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, style.color_from_css("light green", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_unknown_color_name) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, style.color_from_css("graan", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_rgb_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_argb(42, 84, 24), style.color_from_css("rgb(42, 84, 24)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_bad_rgb_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, style.color_from_css("rgb(42, 84, 24", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("rgb(42, 84)", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("rgb(42, 84, 24, 12)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_rgba_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_argb(128, 42, 84, 24), style.color_from_css("rgba(42, 84, 24, 128)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_bad_rgba_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, style.color_from_css("rgba(42, 84, 24, 128", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("rgba(42, 84, 128)", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("rgba(42, 84, 24, 12, 128)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_argb_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_argb(128, 42, 84, 24), style.color_from_css("argb(128, 42, 84, 24)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_bad_argb_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, style.color_from_css("argb(128, 42, 84, 24", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("argb(128, 42, 84)", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("argb(128, 42, 84, 24, 12)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hsv_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_hsb(204, 62, 67), style.color_from_css("hsv(204, 62, 67)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_bad_hsv_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, style.color_from_css("hsv(204, 62, 67", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("hsv(204, 62)", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("hsv(204, 62, 67, 12)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hsva_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_argb(128, color::from_hsb(204, 62, 67)), style.color_from_css("hsva(204, 62, 67, 128)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_bad_hsva_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, style.color_from_css("hsva(204, 62, 67, 128", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("hsva(204, 62, 128)", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("hsva(204, 62, 67, 12, 128)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_ahsv_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_argb(128, color::from_hsb(204, 62, 67)), style.color_from_css("ahsv(128, 204, 62, 67)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_bad_ahsv_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, style.color_from_css("ahsv(204, 62, 67", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("ahsv(204, 62, 67)", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("ahsv(128, 204, 62, 67, 12)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hsl_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_hsl(204, 62, 67), style.color_from_css("hsl(204, 62, 67)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_bad_hsl_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, style.color_from_css("hsl(204, 62, 67", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("hsl(204, 62)", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("hsl(204, 62, 67, 12)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_hsla_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_argb(128, color::from_hsl(204, 62, 67)), style.color_from_css("hsla(204, 62, 67, 128)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_bad_hsla_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, style.color_from_css("hsla(204, 62, 67, 128", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("hsla(204, 62, 128)", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("hsla(204, 62, 67, 12, 128)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_ahsl_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::from_argb(128, color::from_hsl(204, 62, 67)), style.color_from_css("ahsl(128, 204, 62, 67)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_bad_ahsl_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, style.color_from_css("ahsl(204, 62, 67", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("ahsl(204, 62, 67)", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("ahsl(128, 204, 62, 67, 12)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_system_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(style.system_colors().control_text(), style.color_from_css("system-color(control-text)", color::empty), csf_);
    }
    
    void test_method_(color_from_css_with_bad_system_color) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal(color::empty, style.color_from_css("system-color(control-text", color::empty), csf_);
      assert::are_equal(color::empty, style.color_from_css("system-color(checkbox)", color::empty), csf_);
    }
    
    void test_method_(string_from_css) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal("String text.", style.string_from_css("\"String text.\"", "Default"), csf_);
    }
    
    void test_method_(string_from_css_with_bad_format) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal("Default", style.string_from_css("String text.", "Default"), csf_);
    }
    
    void test_method_(uri_from_css) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal("https://gammasoft71.wixsite.com/xtdpro", style.uri_from_css("url(https://gammasoft71.wixsite.com/xtdpro)", "https://gammasoft71.wixsite.com/gammasoft"), csf_);
    }
    
    void test_method_(uri_from_css_with_bad_format) {
      auto styles = style_sheet::style_sheets();
      auto style = styles.find("macOS (dark)")->second;
      assert::are_equal("https://gammasoft71.wixsite.com/gammasoft", style.string_from_css("https://gammasoft71.wixsite.com/xtdpro", "https://gammasoft71.wixsite.com/gammasoft"), csf_);
    }
  };
}
