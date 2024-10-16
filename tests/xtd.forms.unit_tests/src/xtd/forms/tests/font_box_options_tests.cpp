#include <xtd/forms/font_box_options>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(font_box_options_tests) {
  public:
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(font_box_options::none));
      assert::are_equal("none", enum_object<>::to_string(font_box_options::none));
      assert::are_equal(font_box_options::none, enum_object<>::parse<font_box_options>("none"));
    }
    
    void test_method_(allow_simulations) {
      assert::are_equal(1, enum_object<>::to_int32(font_box_options::allow_simulations));
      assert::are_equal("allow_simulations", enum_object<>::to_string(font_box_options::allow_simulations));
      assert::are_equal(font_box_options::allow_simulations, enum_object<>::parse<font_box_options>("allow_simulations"));
    }
    
    void test_method_(allow_vector_fonts) {
      assert::are_equal(2, enum_object<>::to_int32(font_box_options::allow_vector_fonts));
      assert::are_equal("allow_vector_fonts", enum_object<>::to_string(font_box_options::allow_vector_fonts));
      assert::are_equal(font_box_options::allow_vector_fonts, enum_object<>::parse<font_box_options>("allow_vector_fonts"));
    }
    
    void test_method_(allow_vertical_fonts) {
      assert::are_equal(4, enum_object<>::to_int32(font_box_options::allow_vertical_fonts));
      assert::are_equal("allow_vertical_fonts", enum_object<>::to_string(font_box_options::allow_vertical_fonts));
      assert::are_equal(font_box_options::allow_vertical_fonts, enum_object<>::parse<font_box_options>("allow_vertical_fonts"));
    }
    
    void test_method_(allow_script_change) {
      assert::are_equal(8, enum_object<>::to_int32(font_box_options::allow_script_change));
      assert::are_equal("allow_script_change", enum_object<>::to_string(font_box_options::allow_script_change));
      assert::are_equal(font_box_options::allow_script_change, enum_object<>::parse<font_box_options>("allow_script_change"));
    }
    
    void test_method_(fixed_pitch_only) {
      assert::are_equal(16, enum_object<>::to_int32(font_box_options::fixed_pitch_only));
      assert::are_equal("fixed_pitch_only", enum_object<>::to_string(font_box_options::fixed_pitch_only));
      assert::are_equal(font_box_options::fixed_pitch_only, enum_object<>::parse<font_box_options>("fixed_pitch_only"));
    }
    
    void test_method_(scripts_only) {
      assert::are_equal(32, enum_object<>::to_int32(font_box_options::scripts_only));
      assert::are_equal("scripts_only", enum_object<>::to_string(font_box_options::scripts_only));
      assert::are_equal(font_box_options::scripts_only, enum_object<>::parse<font_box_options>("scripts_only"));
    }
    
    void test_method_(show_apply) {
      assert::are_equal(64, enum_object<>::to_int32(font_box_options::show_apply));
      assert::are_equal("show_apply", enum_object<>::to_string(font_box_options::show_apply));
      assert::are_equal(font_box_options::show_apply, enum_object<>::parse<font_box_options>("show_apply"));
    }
    
    void test_method_(show_color) {
      assert::are_equal(128, enum_object<>::to_int32(font_box_options::show_color));
      assert::are_equal("show_color", enum_object<>::to_string(font_box_options::show_color));
      assert::are_equal(font_box_options::show_color, enum_object<>::parse<font_box_options>("show_color"));
    }
    
    void test_method_(show_effects) {
      assert::are_equal(256, enum_object<>::to_int32(font_box_options::show_effects));
      assert::are_equal("show_effects", enum_object<>::to_string(font_box_options::show_effects));
      assert::are_equal(font_box_options::show_effects, enum_object<>::parse<font_box_options>("show_effects"));
    }
    
    void test_method_(show_help) {
      assert::are_equal(512, enum_object<>::to_int32(font_box_options::show_help));
      assert::are_equal("show_help", enum_object<>::to_string(font_box_options::show_help));
      assert::are_equal(font_box_options::show_help, enum_object<>::parse<font_box_options>("show_help"));
    }
    
    void test_method_(all) {
      assert::are_equal(1023, enum_object<>::to_int32(font_box_options::all));
      assert::are_equal("all", enum_object<>::to_string(font_box_options::all));
      assert::are_equal(font_box_options::all, enum_object<>::parse<font_box_options>("all"));
    }
  };
}
