#include <xtd/forms/loading_indicator_style>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(loading_indicator_style_tests) {
  public:
    auto test_method_(bar) {
      assert::are_equal(0, enum_object<>::to_int32(loading_indicator_style::bar));
      assert::are_equal("bar", enum_object<>::to_string(loading_indicator_style::bar));
      assert::are_equal(loading_indicator_style::bar, enum_object<>::parse<loading_indicator_style>("bar"));
    }
    
    auto test_method_(circle_bars) {
      assert::are_equal(1, enum_object<>::to_int32(loading_indicator_style::circle_bars));
      assert::are_equal("circle_bars", enum_object<>::to_string(loading_indicator_style::circle_bars));
      assert::are_equal(loading_indicator_style::circle_bars, enum_object<>::parse<loading_indicator_style>("circle_bars"));
    }
    
    auto test_method_(circle_blinks) {
      assert::are_equal(2, enum_object<>::to_int32(loading_indicator_style::circle_blinks));
      assert::are_equal("circle_blinks", enum_object<>::to_string(loading_indicator_style::circle_blinks));
      assert::are_equal(loading_indicator_style::circle_blinks, enum_object<>::parse<loading_indicator_style>("circle_blinks"));
    }
    
    auto test_method_(five_lines_center) {
      assert::are_equal(4, enum_object<>::to_int32(loading_indicator_style::five_lines_center));
      assert::are_equal("five_lines_center", enum_object<>::to_string(loading_indicator_style::five_lines_center));
      assert::are_equal(loading_indicator_style::five_lines_center, enum_object<>::parse<loading_indicator_style>("five_lines_center"));
    }
    
    auto test_method_(five_lines_chronological) {
      assert::are_equal(5, enum_object<>::to_int32(loading_indicator_style::five_lines_chronological));
      assert::are_equal("five_lines_chronological", enum_object<>::to_string(loading_indicator_style::five_lines_chronological));
      assert::are_equal(loading_indicator_style::five_lines_chronological, enum_object<>::parse<loading_indicator_style>("five_lines_chronological"));
    }
    
    auto test_method_(five_lines_pulse) {
      assert::are_equal(6, enum_object<>::to_int32(loading_indicator_style::five_lines_pulse));
      assert::are_equal("five_lines_pulse", enum_object<>::to_string(loading_indicator_style::five_lines_pulse));
      assert::are_equal(loading_indicator_style::five_lines_pulse, enum_object<>::parse<loading_indicator_style>("five_lines_pulse"));
    }
    
    auto test_method_(five_lines_wave) {
      assert::are_equal(7, enum_object<>::to_int32(loading_indicator_style::five_lines_wave));
      assert::are_equal("five_lines_wave", enum_object<>::to_string(loading_indicator_style::five_lines_wave));
      assert::are_equal(loading_indicator_style::five_lines_wave, enum_object<>::parse<loading_indicator_style>("five_lines_wave"));
    }
    
    auto test_method_(five_lines) {
      assert::are_equal(3, enum_object<>::to_int32(loading_indicator_style::five_lines));
      assert::are_equal("five_lines", enum_object<>::to_string(loading_indicator_style::five_lines));
      assert::are_equal(loading_indicator_style::five_lines, enum_object<>::parse<loading_indicator_style>("five_lines"));
    }
    
    auto test_method_(pulse) {
      assert::are_equal(8, enum_object<>::to_int32(loading_indicator_style::pulse));
      assert::are_equal("pulse", enum_object<>::to_string(loading_indicator_style::pulse));
      assert::are_equal(loading_indicator_style::pulse, enum_object<>::parse<loading_indicator_style>("pulse"));
    }
    
    auto test_method_(pulse_outline) {
      assert::are_equal(9, enum_object<>::to_int32(loading_indicator_style::pulse_outline));
      assert::are_equal("pulse_outline", enum_object<>::to_string(loading_indicator_style::pulse_outline));
      assert::are_equal(loading_indicator_style::pulse_outline, enum_object<>::parse<loading_indicator_style>("pulse_outline"));
    }
    
    auto test_method_(standard) {
      assert::are_equal(10, enum_object<>::to_int32(loading_indicator_style::standard));
      assert::are_equal("standard", enum_object<>::to_string(loading_indicator_style::standard));
      assert::are_equal(loading_indicator_style::standard, enum_object<>::parse<loading_indicator_style>("standard"));
    }
    
    auto test_method_(system) {
      assert::are_equal(11, enum_object<>::to_int32(loading_indicator_style::system));
      assert::are_equal("system", enum_object<>::to_string(loading_indicator_style::system));
      assert::are_equal(loading_indicator_style::system, enum_object<>::parse<loading_indicator_style>("system"));
    }
    
    auto test_method_(three_balls) {
      assert::are_equal(12, enum_object<>::to_int32(loading_indicator_style::three_balls));
      assert::are_equal("three_balls", enum_object<>::to_string(loading_indicator_style::three_balls));
      assert::are_equal(loading_indicator_style::three_balls, enum_object<>::parse<loading_indicator_style>("three_balls"));
    }
    
    auto test_method_(three_balls_bouncing) {
      assert::are_equal(13, enum_object<>::to_int32(loading_indicator_style::three_balls_bouncing));
      assert::are_equal("three_balls_bouncing", enum_object<>::to_string(loading_indicator_style::three_balls_bouncing));
      assert::are_equal(loading_indicator_style::three_balls_bouncing, enum_object<>::parse<loading_indicator_style>("three_balls_bouncing"));
    }
    
    auto test_method_(three_balls_rotation) {
      assert::are_equal(14, enum_object<>::to_int32(loading_indicator_style::three_balls_rotation));
      assert::are_equal("three_balls_rotation", enum_object<>::to_string(loading_indicator_style::three_balls_rotation));
      assert::are_equal(loading_indicator_style::three_balls_rotation, enum_object<>::parse<loading_indicator_style>("three_balls_rotation"));
    }
  };
}
