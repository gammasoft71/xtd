#include <xtd/drawing/string_format_flags>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(string_format_flags_tests) {
    void test_method_(direction_right_to_left) {
      assert::are_equal(1, enum_object<>::to_int32(string_format_flags::direction_right_to_left), csf_);
      assert::are_equal("direction_right_to_left", enum_object<>::to_string(string_format_flags::direction_right_to_left), csf_);
      assert::are_equal(string_format_flags::direction_right_to_left, enum_object<>::parse<string_format_flags>("direction_right_to_left"), csf_);
    }
    
    void test_method_(direction_vertical) {
      assert::are_equal(2, enum_object<>::to_int32(string_format_flags::direction_vertical), csf_);
      assert::are_equal("direction_vertical", enum_object<>::to_string(string_format_flags::direction_vertical), csf_);
      assert::are_equal(string_format_flags::direction_vertical, enum_object<>::parse<string_format_flags>("direction_vertical"), csf_);
    }
    
    void test_method_(fit_black_box) {
      assert::are_equal(4, enum_object<>::to_int32(string_format_flags::fit_black_box), csf_);
      assert::are_equal("fit_black_box", enum_object<>::to_string(string_format_flags::fit_black_box), csf_);
      assert::are_equal(string_format_flags::fit_black_box, enum_object<>::parse<string_format_flags>("fit_black_box"), csf_);
    }
    
    void test_method_(display_format_control) {
      assert::are_equal(32, enum_object<>::to_int32(string_format_flags::display_format_control), csf_);
      assert::are_equal("display_format_control", enum_object<>::to_string(string_format_flags::display_format_control), csf_);
      assert::are_equal(string_format_flags::display_format_control, enum_object<>::parse<string_format_flags>("display_format_control"), csf_);
    }
    
    void test_method_(no_font_fallback) {
      assert::are_equal(1024, enum_object<>::to_int32(string_format_flags::no_font_fallback), csf_);
      assert::are_equal("no_font_fallback", enum_object<>::to_string(string_format_flags::no_font_fallback), csf_);
      assert::are_equal(string_format_flags::no_font_fallback, enum_object<>::parse<string_format_flags>("no_font_fallback"), csf_);
    }
    
    void test_method_(measure_trailing_spaces) {
      assert::are_equal(2048, enum_object<>::to_int32(string_format_flags::measure_trailing_spaces), csf_);
      assert::are_equal("measure_trailing_spaces", enum_object<>::to_string(string_format_flags::measure_trailing_spaces), csf_);
      assert::are_equal(string_format_flags::measure_trailing_spaces, enum_object<>::parse<string_format_flags>("measure_trailing_spaces"), csf_);
    }
    
    void test_method_(no_wrap) {
      assert::are_equal(4096, enum_object<>::to_int32(string_format_flags::no_wrap), csf_);
      assert::are_equal("no_wrap", enum_object<>::to_string(string_format_flags::no_wrap), csf_);
      assert::are_equal(string_format_flags::no_wrap, enum_object<>::parse<string_format_flags>("no_wrap"), csf_);
    }
    
    void test_method_(line_limit) {
      assert::are_equal(8192, enum_object<>::to_int32(string_format_flags::line_limit), csf_);
      assert::are_equal("line_limit", enum_object<>::to_string(string_format_flags::line_limit), csf_);
      assert::are_equal(string_format_flags::line_limit, enum_object<>::parse<string_format_flags>("line_limit"), csf_);
    }
    
    void test_method_(no_clip) {
      assert::are_equal(16384, enum_object<>::to_int32(string_format_flags::no_clip), csf_);
      assert::are_equal("no_clip", enum_object<>::to_string(string_format_flags::no_clip), csf_);
      assert::are_equal(string_format_flags::no_clip, enum_object<>::parse<string_format_flags>("no_clip"), csf_);
    }
  };
}
