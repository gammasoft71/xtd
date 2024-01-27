#include <xtd/forms/known_themed_color.h>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(known_themed_color_tests) {
  public:
    void test_method_(active_border) {
      assert::are_equal(3, enum_object<>::to_int32(known_themed_color::active_border), csf_);
      assert::are_equal("active_border", enum_object<>::to_string(known_themed_color::active_border), csf_);
      assert::are_equal(known_themed_color::active_border, enum_object<>::parse<known_themed_color>("active_border"), csf_);
    }
    
    void test_method_(active_caption) {
      assert::are_equal(4, enum_object<>::to_int32(known_themed_color::active_caption), csf_);
      assert::are_equal("active_caption", enum_object<>::to_string(known_themed_color::active_caption), csf_);
      assert::are_equal(known_themed_color::active_caption, enum_object<>::parse<known_themed_color>("active_caption"), csf_);
    }
    
    void test_method_(active_caption_text) {
      assert::are_equal(5, enum_object<>::to_int32(known_themed_color::active_caption_text), csf_);
      assert::are_equal("active_caption_text", enum_object<>::to_string(known_themed_color::active_caption_text), csf_);
      assert::are_equal(known_themed_color::active_caption_text, enum_object<>::parse<known_themed_color>("active_caption_text"), csf_);
    }
    
    void test_method_(app_workspace) {
      assert::are_equal(6, enum_object<>::to_int32(known_themed_color::app_workspace), csf_);
      assert::are_equal("app_workspace", enum_object<>::to_string(known_themed_color::app_workspace), csf_);
      assert::are_equal(known_themed_color::app_workspace, enum_object<>::parse<known_themed_color>("app_workspace"), csf_);
    }
    
    void test_method_(control) {
      assert::are_equal(10, enum_object<>::to_int32(known_themed_color::control), csf_);
      assert::are_equal("control", enum_object<>::to_string(known_themed_color::control), csf_);
      assert::are_equal(known_themed_color::control, enum_object<>::parse<known_themed_color>("control"), csf_);
    }
    
    void test_method_(control_dark) {
      assert::are_equal(11, enum_object<>::to_int32(known_themed_color::control_dark), csf_);
      assert::are_equal("control_dark", enum_object<>::to_string(known_themed_color::control_dark), csf_);
      assert::are_equal(known_themed_color::control_dark, enum_object<>::parse<known_themed_color>("control_dark"), csf_);
    }
    
    void test_method_(control_dark_dark) {
      assert::are_equal(12, enum_object<>::to_int32(known_themed_color::control_dark_dark), csf_);
      assert::are_equal("control_dark_dark", enum_object<>::to_string(known_themed_color::control_dark_dark), csf_);
      assert::are_equal(known_themed_color::control_dark_dark, enum_object<>::parse<known_themed_color>("control_dark_dark"), csf_);
    }
    
    void test_method_(control_light) {
      assert::are_equal(13, enum_object<>::to_int32(known_themed_color::control_light), csf_);
      assert::are_equal("control_light", enum_object<>::to_string(known_themed_color::control_light), csf_);
      assert::are_equal(known_themed_color::control_light, enum_object<>::parse<known_themed_color>("control_light"), csf_);
    }
    
    void test_method_(control_light_light) {
      assert::are_equal(14, enum_object<>::to_int32(known_themed_color::control_light_light), csf_);
      assert::are_equal("control_light_light", enum_object<>::to_string(known_themed_color::control_light_light), csf_);
      assert::are_equal(known_themed_color::control_light_light, enum_object<>::parse<known_themed_color>("control_light_light"), csf_);
    }
    
    void test_method_(control_text) {
      assert::are_equal(15, enum_object<>::to_int32(known_themed_color::control_text), csf_);
      assert::are_equal("control_text", enum_object<>::to_string(known_themed_color::control_text), csf_);
      assert::are_equal(known_themed_color::control_text, enum_object<>::parse<known_themed_color>("control_text"), csf_);
    }
    
    void test_method_(desktop) {
      assert::are_equal(16, enum_object<>::to_int32(known_themed_color::desktop), csf_);
      assert::are_equal("desktop", enum_object<>::to_string(known_themed_color::desktop), csf_);
      assert::are_equal(known_themed_color::desktop, enum_object<>::parse<known_themed_color>("desktop"), csf_);
    }
    
    void test_method_(gray_text) {
      assert::are_equal(19, enum_object<>::to_int32(known_themed_color::gray_text), csf_);
      assert::are_equal("gray_text", enum_object<>::to_string(known_themed_color::gray_text), csf_);
      assert::are_equal(known_themed_color::gray_text, enum_object<>::parse<known_themed_color>("gray_text"), csf_);
    }
    
    void test_method_(highlight) {
      assert::are_equal(20, enum_object<>::to_int32(known_themed_color::highlight), csf_);
      assert::are_equal("highlight", enum_object<>::to_string(known_themed_color::highlight), csf_);
      assert::are_equal(known_themed_color::highlight, enum_object<>::parse<known_themed_color>("highlight"), csf_);
    }
    
    void test_method_(highlight_text) {
      assert::are_equal(21, enum_object<>::to_int32(known_themed_color::highlight_text), csf_);
      assert::are_equal("highlight_text", enum_object<>::to_string(known_themed_color::highlight_text), csf_);
      assert::are_equal(known_themed_color::highlight_text, enum_object<>::parse<known_themed_color>("highlight_text"), csf_);
    }
    
    void test_method_(hot_track) {
      assert::are_equal(22, enum_object<>::to_int32(known_themed_color::hot_track), csf_);
      assert::are_equal("hot_track", enum_object<>::to_string(known_themed_color::hot_track), csf_);
      assert::are_equal(known_themed_color::hot_track, enum_object<>::parse<known_themed_color>("hot_track"), csf_);
    }
    
    void test_method_(inactive_border) {
      assert::are_equal(23, enum_object<>::to_int32(known_themed_color::inactive_border), csf_);
      assert::are_equal("inactive_border", enum_object<>::to_string(known_themed_color::inactive_border), csf_);
      assert::are_equal(known_themed_color::inactive_border, enum_object<>::parse<known_themed_color>("inactive_border"), csf_);
    }
    
    void test_method_(inactive_caption) {
      assert::are_equal(24, enum_object<>::to_int32(known_themed_color::inactive_caption), csf_);
      assert::are_equal("inactive_caption", enum_object<>::to_string(known_themed_color::inactive_caption), csf_);
      assert::are_equal(known_themed_color::inactive_caption, enum_object<>::parse<known_themed_color>("inactive_caption"), csf_);
    }
    
    void test_method_(inactive_caption_text) {
      assert::are_equal(25, enum_object<>::to_int32(known_themed_color::inactive_caption_text), csf_);
      assert::are_equal("inactive_caption_text", enum_object<>::to_string(known_themed_color::inactive_caption_text), csf_);
      assert::are_equal(known_themed_color::inactive_caption_text, enum_object<>::parse<known_themed_color>("inactive_caption_text"), csf_);
    }
    
    void test_method_(info) {
      assert::are_equal(26, enum_object<>::to_int32(known_themed_color::info), csf_);
      assert::are_equal("info", enum_object<>::to_string(known_themed_color::info), csf_);
      assert::are_equal(known_themed_color::info, enum_object<>::parse<known_themed_color>("info"), csf_);
    }
    
    void test_method_(info_text) {
      assert::are_equal(27, enum_object<>::to_int32(known_themed_color::info_text), csf_);
      assert::are_equal("info_text", enum_object<>::to_string(known_themed_color::info_text), csf_);
      assert::are_equal(known_themed_color::info_text, enum_object<>::parse<known_themed_color>("info_text"), csf_);
    }
    
    void test_method_(menu) {
      assert::are_equal(28, enum_object<>::to_int32(known_themed_color::menu), csf_);
      assert::are_equal("menu", enum_object<>::to_string(known_themed_color::menu), csf_);
      assert::are_equal(known_themed_color::menu, enum_object<>::parse<known_themed_color>("menu"), csf_);
    }
    
    void test_method_(menu_text) {
      assert::are_equal(31, enum_object<>::to_int32(known_themed_color::menu_text), csf_);
      assert::are_equal("menu_text", enum_object<>::to_string(known_themed_color::menu_text), csf_);
      assert::are_equal(known_themed_color::menu_text, enum_object<>::parse<known_themed_color>("menu_text"), csf_);
    }
    
    void test_method_(scroll_bar) {
      assert::are_equal(32, enum_object<>::to_int32(known_themed_color::scroll_bar), csf_);
      assert::are_equal("scroll_bar", enum_object<>::to_string(known_themed_color::scroll_bar), csf_);
      assert::are_equal(known_themed_color::scroll_bar, enum_object<>::parse<known_themed_color>("scroll_bar"), csf_);
    }
    
    void test_method_(window) {
      assert::are_equal(35, enum_object<>::to_int32(known_themed_color::window), csf_);
      assert::are_equal("window", enum_object<>::to_string(known_themed_color::window), csf_);
      assert::are_equal(known_themed_color::window, enum_object<>::parse<known_themed_color>("window"), csf_);
    }
    
    void test_method_(window_frame) {
      assert::are_equal(36, enum_object<>::to_int32(known_themed_color::window_frame), csf_);
      assert::are_equal("window_frame", enum_object<>::to_string(known_themed_color::window_frame), csf_);
      assert::are_equal(known_themed_color::window_frame, enum_object<>::parse<known_themed_color>("window_frame"), csf_);
    }
    
    void test_method_(window_text) {
      assert::are_equal(37, enum_object<>::to_int32(known_themed_color::window_text), csf_);
      assert::are_equal("window_text", enum_object<>::to_string(known_themed_color::window_text), csf_);
      assert::are_equal(known_themed_color::window_text, enum_object<>::parse<known_themed_color>("window_text"), csf_);
    }
    
    void test_method_(button_face) {
      assert::are_equal(7, enum_object<>::to_int32(known_themed_color::button_face), csf_);
      assert::are_equal("button_face", enum_object<>::to_string(known_themed_color::button_face), csf_);
      assert::are_equal(known_themed_color::button_face, enum_object<>::parse<known_themed_color>("button_face"), csf_);
    }
    
    void test_method_(button_highlight) {
      assert::are_equal(8, enum_object<>::to_int32(known_themed_color::button_highlight), csf_);
      assert::are_equal("button_highlight", enum_object<>::to_string(known_themed_color::button_highlight), csf_);
      assert::are_equal(known_themed_color::button_highlight, enum_object<>::parse<known_themed_color>("button_highlight"), csf_);
    }
    
    void test_method_(button_shadow) {
      assert::are_equal(9, enum_object<>::to_int32(known_themed_color::button_shadow), csf_);
      assert::are_equal("button_shadow", enum_object<>::to_string(known_themed_color::button_shadow), csf_);
      assert::are_equal(known_themed_color::button_shadow, enum_object<>::parse<known_themed_color>("button_shadow"), csf_);
    }
    
    void test_method_(gradient_active_caption) {
      assert::are_equal(17, enum_object<>::to_int32(known_themed_color::gradient_active_caption), csf_);
      assert::are_equal("gradient_active_caption", enum_object<>::to_string(known_themed_color::gradient_active_caption), csf_);
      assert::are_equal(known_themed_color::gradient_active_caption, enum_object<>::parse<known_themed_color>("gradient_active_caption"), csf_);
    }
    
    void test_method_(gradient_inactive_caption) {
      assert::are_equal(18, enum_object<>::to_int32(known_themed_color::gradient_inactive_caption), csf_);
      assert::are_equal("gradient_inactive_caption", enum_object<>::to_string(known_themed_color::gradient_inactive_caption), csf_);
      assert::are_equal(known_themed_color::gradient_inactive_caption, enum_object<>::parse<known_themed_color>("gradient_inactive_caption"), csf_);
    }
    
    void test_method_(menu_bar) {
      assert::are_equal(29, enum_object<>::to_int32(known_themed_color::menu_bar), csf_);
      assert::are_equal("menu_bar", enum_object<>::to_string(known_themed_color::menu_bar), csf_);
      assert::are_equal(known_themed_color::menu_bar, enum_object<>::parse<known_themed_color>("menu_bar"), csf_);
    }
    
    void test_method_(menu_highlight) {
      assert::are_equal(30, enum_object<>::to_int32(known_themed_color::menu_highlight), csf_);
      assert::are_equal("menu_highlight", enum_object<>::to_string(known_themed_color::menu_highlight), csf_);
      assert::are_equal(known_themed_color::menu_highlight, enum_object<>::parse<known_themed_color>("menu_highlight"), csf_);
    }
    
    void test_method_(accent) {
      assert::are_equal(1, enum_object<>::to_int32(known_themed_color::accent), csf_);
      assert::are_equal("accent", enum_object<>::to_string(known_themed_color::accent), csf_);
      assert::are_equal(known_themed_color::accent, enum_object<>::parse<known_themed_color>("accent"), csf_);
    }
    
    void test_method_(accent_text) {
      assert::are_equal(2, enum_object<>::to_int32(known_themed_color::accent_text), csf_);
      assert::are_equal("accent_text", enum_object<>::to_string(known_themed_color::accent_text), csf_);
      assert::are_equal(known_themed_color::accent_text, enum_object<>::parse<known_themed_color>("accent_text"), csf_);
    }
    
    void test_method_(text_box) {
      assert::are_equal(33, enum_object<>::to_int32(known_themed_color::text_box), csf_);
      assert::are_equal("text_box", enum_object<>::to_string(known_themed_color::text_box), csf_);
      assert::are_equal(known_themed_color::text_box, enum_object<>::parse<known_themed_color>("text_box"), csf_);
    }
    
    void test_method_(text_box_text) {
      assert::are_equal(34, enum_object<>::to_int32(known_themed_color::text_box_text), csf_);
      assert::are_equal("text_box_text", enum_object<>::to_string(known_themed_color::text_box_text), csf_);
      assert::are_equal(known_themed_color::text_box_text, enum_object<>::parse<known_themed_color>("text_box_text"), csf_);
    }
  };
}
