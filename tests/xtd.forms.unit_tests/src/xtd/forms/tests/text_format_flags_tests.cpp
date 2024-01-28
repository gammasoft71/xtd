#include <xtd/forms/text_format_flags>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(text_format_flags_tests) {
  public:
    void test_method_(default_format) {
      assert::are_equal(0, enum_object<>::to_int32(text_format_flags::default_format), csf_);
      assert::are_equal("default_format", enum_object<>::to_string(text_format_flags::default_format), csf_);
      assert::are_equal(text_format_flags::default_format, enum_object<>::parse<text_format_flags>("default_format"), csf_);
    }
    
    void test_method_(glyph_overhang_padding) {
      assert::are_equal(0, enum_object<>::to_int32(text_format_flags::glyph_overhang_padding), csf_);
      assert::are_equal("default_format", enum_object<>::to_string(text_format_flags::glyph_overhang_padding), csf_);
      assert::are_equal(text_format_flags::glyph_overhang_padding, enum_object<>::parse<text_format_flags>("default_format"), csf_);
    }
    
    void test_method_(left) {
      assert::are_equal(0, enum_object<>::to_int32(text_format_flags::left), csf_);
      assert::are_equal("default_format", enum_object<>::to_string(text_format_flags::left), csf_);
      assert::are_equal(text_format_flags::left, enum_object<>::parse<text_format_flags>("default_format"), csf_);
    }
    
    void test_method_(top) {
      assert::are_equal(0, enum_object<>::to_int32(text_format_flags::top), csf_);
      assert::are_equal("default_format", enum_object<>::to_string(text_format_flags::top), csf_);
      assert::are_equal(text_format_flags::top, enum_object<>::parse<text_format_flags>("default_format"), csf_);
    }
    
    void test_method_(horizontal_center) {
      assert::are_equal(1, enum_object<>::to_int32(text_format_flags::horizontal_center), csf_);
      assert::are_equal("horizontal_center", enum_object<>::to_string(text_format_flags::horizontal_center), csf_);
      assert::are_equal(text_format_flags::horizontal_center, enum_object<>::parse<text_format_flags>("horizontal_center"), csf_);
    }
    
    void test_method_(right) {
      assert::are_equal(2, enum_object<>::to_int32(text_format_flags::right), csf_);
      assert::are_equal("right", enum_object<>::to_string(text_format_flags::right), csf_);
      assert::are_equal(text_format_flags::right, enum_object<>::parse<text_format_flags>("right"), csf_);
    }
    
    void test_method_(vertical_center) {
      assert::are_equal(4, enum_object<>::to_int32(text_format_flags::vertical_center), csf_);
      assert::are_equal("vertical_center", enum_object<>::to_string(text_format_flags::vertical_center), csf_);
      assert::are_equal(text_format_flags::vertical_center, enum_object<>::parse<text_format_flags>("vertical_center"), csf_);
    }
    
    void test_method_(bottom) {
      assert::are_equal(8, enum_object<>::to_int32(text_format_flags::bottom), csf_);
      assert::are_equal("bottom", enum_object<>::to_string(text_format_flags::bottom), csf_);
      assert::are_equal(text_format_flags::bottom, enum_object<>::parse<text_format_flags>("bottom"), csf_);
    }
    
    void test_method_(word_break) {
      assert::are_equal(16, enum_object<>::to_int32(text_format_flags::word_break), csf_);
      assert::are_equal("word_break", enum_object<>::to_string(text_format_flags::word_break), csf_);
      assert::are_equal(text_format_flags::word_break, enum_object<>::parse<text_format_flags>("word_break"), csf_);
    }
    
    void test_method_(single_line) {
      assert::are_equal(32, enum_object<>::to_int32(text_format_flags::single_line), csf_);
      assert::are_equal("single_line", enum_object<>::to_string(text_format_flags::single_line), csf_);
      assert::are_equal(text_format_flags::single_line, enum_object<>::parse<text_format_flags>("single_line"), csf_);
    }
    
    void test_method_(expand_tabs) {
      assert::are_equal(64, enum_object<>::to_int32(text_format_flags::expand_tabs), csf_);
      assert::are_equal("expand_tabs", enum_object<>::to_string(text_format_flags::expand_tabs), csf_);
      assert::are_equal(text_format_flags::expand_tabs, enum_object<>::parse<text_format_flags>("expand_tabs"), csf_);
    }
    
    void test_method_(no_clipping) {
      assert::are_equal(256, enum_object<>::to_int32(text_format_flags::no_clipping), csf_);
      assert::are_equal("no_clipping", enum_object<>::to_string(text_format_flags::no_clipping), csf_);
      assert::are_equal(text_format_flags::no_clipping, enum_object<>::parse<text_format_flags>("no_clipping"), csf_);
    }
    
    void test_method_(external_leading) {
      assert::are_equal(512, enum_object<>::to_int32(text_format_flags::external_leading), csf_);
      assert::are_equal("external_leading", enum_object<>::to_string(text_format_flags::external_leading), csf_);
      assert::are_equal(text_format_flags::external_leading, enum_object<>::parse<text_format_flags>("external_leading"), csf_);
    }
    
    void test_method_(no_prefix) {
      assert::are_equal(1024, enum_object<>::to_int32(text_format_flags::no_prefix), csf_);
      assert::are_equal("no_prefix", enum_object<>::to_string(text_format_flags::no_prefix), csf_);
      assert::are_equal(text_format_flags::no_prefix, enum_object<>::parse<text_format_flags>("no_prefix"), csf_);
    }
    
    void test_method_(internal) {
      assert::are_equal(4096, enum_object<>::to_int32(text_format_flags::internal), csf_);
      assert::are_equal("internal", enum_object<>::to_string(text_format_flags::internal), csf_);
      assert::are_equal(text_format_flags::internal, enum_object<>::parse<text_format_flags>("internal"), csf_);
    }
    
    void test_method_(text_box_control) {
      assert::are_equal(8192, enum_object<>::to_int32(text_format_flags::text_box_control), csf_);
      assert::are_equal("text_box_control", enum_object<>::to_string(text_format_flags::text_box_control), csf_);
      assert::are_equal(text_format_flags::text_box_control, enum_object<>::parse<text_format_flags>("text_box_control"), csf_);
    }
    
    void test_method_(path_ellipsis) {
      assert::are_equal(16384, enum_object<>::to_int32(text_format_flags::path_ellipsis), csf_);
      assert::are_equal("path_ellipsis", enum_object<>::to_string(text_format_flags::path_ellipsis), csf_);
      assert::are_equal(text_format_flags::path_ellipsis, enum_object<>::parse<text_format_flags>("path_ellipsis"), csf_);
    }
    
    void test_method_(end_ellipse) {
      assert::are_equal(32768, enum_object<>::to_int32(text_format_flags::end_ellipse), csf_);
      assert::are_equal("end_ellipse", enum_object<>::to_string(text_format_flags::end_ellipse), csf_);
      assert::are_equal(text_format_flags::end_ellipse, enum_object<>::parse<text_format_flags>("end_ellipse"), csf_);
    }
    
    void test_method_(modify_string) {
      assert::are_equal(65536, enum_object<>::to_int32(text_format_flags::modify_string), csf_);
      assert::are_equal("modify_string", enum_object<>::to_string(text_format_flags::modify_string), csf_);
      assert::are_equal(text_format_flags::modify_string, enum_object<>::parse<text_format_flags>("modify_string"), csf_);
    }
    
    void test_method_(right_to_left) {
      assert::are_equal(131072, enum_object<>::to_int32(text_format_flags::right_to_left), csf_);
      assert::are_equal("right_to_left", enum_object<>::to_string(text_format_flags::right_to_left), csf_);
      assert::are_equal(text_format_flags::right_to_left, enum_object<>::parse<text_format_flags>("right_to_left"), csf_);
    }
    
    void test_method_(word_ellipsis) {
      assert::are_equal(262144, enum_object<>::to_int32(text_format_flags::word_ellipsis), csf_);
      assert::are_equal("word_ellipsis", enum_object<>::to_string(text_format_flags::word_ellipsis), csf_);
      assert::are_equal(text_format_flags::word_ellipsis, enum_object<>::parse<text_format_flags>("word_ellipsis"), csf_);
    }
    
    void test_method_(no_full_width_characterB_break) {
      assert::are_equal(524288, enum_object<>::to_int32(text_format_flags::no_full_width_characterB_break), csf_);
      assert::are_equal("no_full_width_characterB_break", enum_object<>::to_string(text_format_flags::no_full_width_characterB_break), csf_);
      assert::are_equal(text_format_flags::no_full_width_characterB_break, enum_object<>::parse<text_format_flags>("no_full_width_characterB_break"), csf_);
    }
    
    void test_method_(hide_prefix) {
      assert::are_equal(1048576, enum_object<>::to_int32(text_format_flags::hide_prefix), csf_);
      assert::are_equal("hide_prefix", enum_object<>::to_string(text_format_flags::hide_prefix), csf_);
      assert::are_equal(text_format_flags::hide_prefix, enum_object<>::parse<text_format_flags>("hide_prefix"), csf_);
    }
    
    void test_method_(prefix_only) {
      assert::are_equal(2097152, enum_object<>::to_int32(text_format_flags::prefix_only), csf_);
      assert::are_equal("prefix_only", enum_object<>::to_string(text_format_flags::prefix_only), csf_);
      assert::are_equal(text_format_flags::prefix_only, enum_object<>::parse<text_format_flags>("prefix_only"), csf_);
    }
    
    void test_method_(preserve_graphics_clipping) {
      assert::are_equal(16777216, enum_object<>::to_int32(text_format_flags::preserve_graphics_clipping), csf_);
      assert::are_equal("preserve_graphics_clipping", enum_object<>::to_string(text_format_flags::preserve_graphics_clipping), csf_);
      assert::are_equal(text_format_flags::preserve_graphics_clipping, enum_object<>::parse<text_format_flags>("preserve_graphics_clipping"), csf_);
    }
    
    void test_method_(preserve_graphics_translate_transform) {
      assert::are_equal(33554432, enum_object<>::to_int32(text_format_flags::preserve_graphics_translate_transform), csf_);
      assert::are_equal("preserve_graphics_translate_transform", enum_object<>::to_string(text_format_flags::preserve_graphics_translate_transform), csf_);
      assert::are_equal(text_format_flags::preserve_graphics_translate_transform, enum_object<>::parse<text_format_flags>("preserve_graphics_translate_transform"), csf_);
    }
    
    void test_method_(no_padding) {
      assert::are_equal(268435456, enum_object<>::to_int32(text_format_flags::no_padding), csf_);
      assert::are_equal("no_padding", enum_object<>::to_string(text_format_flags::no_padding), csf_);
      assert::are_equal(text_format_flags::no_padding, enum_object<>::parse<text_format_flags>("no_padding"), csf_);
    }
    
    void test_method_(left_and_right_padding) {
      assert::are_equal(536870912, enum_object<>::to_int32(text_format_flags::left_and_right_padding), csf_);
      assert::are_equal("left_and_right_padding", enum_object<>::to_string(text_format_flags::left_and_right_padding), csf_);
      assert::are_equal(text_format_flags::left_and_right_padding, enum_object<>::parse<text_format_flags>("left_and_right_padding"), csf_);
    }
  };
}
