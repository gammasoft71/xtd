#include <xtd/forms/toggle_button>
#include <xtd/forms/form>
#include <xtd/diagnostics/debugger>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(toggle_button_tests) {
    class toggle_button_for_test : public toggle_button {
    public:
      toggle_button_for_test() = default;
      
      using toggle_button::default_back_color;
      using toggle_button::default_cursor;
      using toggle_button::default_font;
      using toggle_button::default_fore_color;
      using toggle_button::default_size;
    };
    
    auto test_method_(constructor) {
      toggle_button_for_test toggle_button;
      assert::are_equal(anchor_styles::left | anchor_styles::top, toggle_button.anchor());
      assert::are_equal(drawing::point::empty, toggle_button.auto_scroll_point());
      assert::is_false(toggle_button.auto_size());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), toggle_button.back_color());
      assert::are_equal(drawing::image::empty, toggle_button.background_image());
      assert::are_equal(image_layout::tile, toggle_button.background_image_layout());
      assert::are_equal(toggle_button.default_size().height, toggle_button.bottom());
      assert::are_equal(drawing::rectangle({0, 0}, toggle_button.default_size()), toggle_button.bounds());
      assert::is_false(toggle_button.can_focus());
      assert::is_true(toggle_button.can_raise_events());
      assert::is_true(toggle_button.can_select());
      assert::are_equal(drawing::rectangle({0, 0}, toggle_button.default_size()), toggle_button.client_rectangle());
      assert::are_equal(toggle_button.default_size(), toggle_button.client_size());
      assert::are_equal("Gammasoft", toggle_button.company_name());
      assert::is_null(toggle_button.context_menu());
      assert::are_equal(forms::control_appearance::standard, toggle_button.control_appearance());
      assert::is_empty(toggle_button.controls());
      assert::is_false(toggle_button.created());
      assert::are_equal(forms::cursors::default_cursor(), toggle_button.cursor());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), toggle_button.default_back_color());
      assert::are_equal(forms::cursors::default_cursor(), toggle_button.default_cursor());
      assert::are_equal(drawing::system_fonts::default_font(), toggle_button.default_font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), toggle_button.default_fore_color());
      assert::are_equal(toggle_button.default_size(), toggle_button.default_size());
      assert::are_equal(drawing::rectangle({0, 0}, toggle_button.default_size()), toggle_button.display_rectangle());
      assert::are_equal(forms::dock_style::none, toggle_button.dock());
      assert::is_false(toggle_button.double_buffered());
      assert::is_true(toggle_button.enabled());
      assert::is_false(toggle_button.focused());
      assert::are_equal(drawing::system_fonts::default_font(), toggle_button.font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), toggle_button.fore_color());
      assert::is_zero(toggle_button.handle());
      assert::are_equal(toggle_button.default_size().height, toggle_button.height());
      assert::is_false(toggle_button.invoke_required());
      assert::is_false(toggle_button.is_handle_created());
      assert::is_zero(toggle_button.left());
      assert::are_equal(drawing::point::empty, toggle_button.location());
      assert::are_equal(forms::padding(3), toggle_button.margin());
      assert::are_equal(drawing::size::empty, toggle_button.maximum_client_size());
      assert::are_equal(drawing::size::empty, toggle_button.maximum_size());
      assert::are_equal(drawing::size::empty, toggle_button.minimum_client_size());
      assert::are_equal(drawing::size::empty, toggle_button.minimum_size());
      assert::is_zero(toggle_button.native_handle());
      assert::is_empty(toggle_button.name());
      assert::are_equal(forms::padding(0), toggle_button.padding());
      assert::is_null(toggle_button.parent());
      assert::are_equal("xtd", toggle_button.product_name());
      assert::is_not_zero(toggle_button.region().handle());
      assert::are_equal(toggle_button.default_size().width, toggle_button.right());
      assert::are_equal(toggle_button.default_size(), toggle_button.size());
      assert::is_empty(toggle_button.style_sheet().theme().name());
      assert::is_true(toggle_button.tab_stop());
      assert::is_false(toggle_button.tag().has_value());
      assert::is_empty(toggle_button.text());
      assert::is_zero(toggle_button.toolkit_handle());
      assert::is_zero(toggle_button.top());
      assert::is_null(toggle_button.top_level_control());
      assert::is_true(toggle_button.visible());
      assert::are_equal(toggle_button.default_size().width, toggle_button.width());
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls());
      assert::are_equal(keys::none, forms::control::modifier_keys());
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons());
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position());
      
      assert::is_false(toggle_button.auto_ellipsis());
      assert::are_equal(flat_button_appearance(), toggle_button.flat_appearance());
      assert::are_equal(flat_style::standard, toggle_button.flat_style());
      assert::are_equal(image::empty, toggle_button.image());
      assert::are_equal(content_alignment::middle_center, toggle_button.image_align());
      assert::are_equal(-1, toggle_button.image_index());
      assert::are_equal(image_list::empty, toggle_button.image_list());
      assert::are_equal(content_alignment::middle_center, toggle_button.text_align());
    }
  };
}
