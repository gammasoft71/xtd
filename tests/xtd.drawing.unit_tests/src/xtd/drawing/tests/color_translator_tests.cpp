#include <xtd/drawing/color_translator>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(color_translator_tests) {
    void test_method_(from_argb_to_hex) {
      assert::are_equal("#ff6347", color_translator::to_hex(color::from_argb(255, 255, 99, 71)), csf_);
      assert::are_equal("#ff6347", color_translator::to_hex(color::from_argb(128, 255, 99, 71)), csf_);
    }

    void test_method_(from_known_color_to_hex) {
      assert::are_equal("Red", color_translator::to_hex(color::from_known_color(xtd::drawing::known_color::red)), csf_);
      assert::are_equal("DodgerBlue", color_translator::to_hex(color::from_known_color(xtd::drawing::known_color::dodger_blue)), csf_);
      assert::are_equal("LightGray", color_translator::to_hex(color::from_known_color(xtd::drawing::known_color::light_gray)), csf_);
      assert::are_equal("ActiveText", color_translator::to_hex(color::from_known_color(xtd::drawing::known_color::active_text)), csf_);
      assert::are_equal("GradientInactiveCaption", color_translator::to_hex(color::from_known_color(xtd::drawing::known_color::gradient_inactive_caption)), csf_);
    }

    void test_method_(from_known_color_to_html) {
      assert::are_equal("Red", color_translator::to_html(color::from_known_color(xtd::drawing::known_color::red)), csf_);
      assert::are_equal("DodgerBlue", color_translator::to_html(color::from_known_color(xtd::drawing::known_color::dodger_blue)), csf_);
      assert::are_equal("LightGray", color_translator::to_html(color::from_known_color(xtd::drawing::known_color::light_gray)), csf_);
      assert::are_equal("ActiveText", color_translator::to_html(color::from_known_color(xtd::drawing::known_color::active_text)), csf_);
      assert::are_equal("GradientInactiveCaption", color_translator::to_html(color::from_known_color(xtd::drawing::known_color::gradient_inactive_caption)), csf_);
    }

    void test_method_(from_known_color_to_rgb) {
      assert::are_equal("Red", color_translator::to_rgb(color::from_known_color(xtd::drawing::known_color::red)), csf_);
      assert::are_equal("DodgerBlue", color_translator::to_rgb(color::from_known_color(xtd::drawing::known_color::dodger_blue)), csf_);
      assert::are_equal("LightGray", color_translator::to_rgb(color::from_known_color(xtd::drawing::known_color::light_gray)), csf_);
      assert::are_equal("ActiveText", color_translator::to_rgb(color::from_known_color(xtd::drawing::known_color::active_text)), csf_);
      assert::are_equal("GradientInactiveCaption", color_translator::to_rgb(color::from_known_color(xtd::drawing::known_color::gradient_inactive_caption)), csf_);
    }

    void test_method_(from_known_color_to_rgba) {
      assert::are_equal("Red", color_translator::to_rgba(color::from_known_color(xtd::drawing::known_color::red)), csf_);
      assert::are_equal("DodgerBlue", color_translator::to_rgba(color::from_known_color(xtd::drawing::known_color::dodger_blue)), csf_);
      assert::are_equal("LightGray", color_translator::to_rgba(color::from_known_color(xtd::drawing::known_color::light_gray)), csf_);
      assert::are_equal("ActiveText", color_translator::to_rgba(color::from_known_color(xtd::drawing::known_color::active_text)), csf_);
      assert::are_equal("GradientInactiveCaption", color_translator::to_rgba(color::from_known_color(xtd::drawing::known_color::gradient_inactive_caption)), csf_);
    }
  };
}
