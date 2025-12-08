#include <xtd/forms/radio_button>
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
  class test_class_(radio_button_tests) {
    class radio_button_for_test : public radio_button {
    public:
      radio_button_for_test() = default;
      
      using radio_button::default_back_color;
      using radio_button::default_cursor;
      using radio_button::default_font;
      using radio_button::default_fore_color;
      using radio_button::default_size;
    };
    
    auto test_method_(constructor) {
      radio_button_for_test radio_button;
      assert::are_equal(anchor_styles::left | anchor_styles::top, radio_button.anchor());
      assert::are_equal(drawing::point::empty, radio_button.auto_scroll_point());
      assert::is_false(radio_button.auto_size());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), radio_button.back_color());
      assert::are_equal(drawing::image::empty, radio_button.background_image());
      assert::are_equal(image_layout::tile, radio_button.background_image_layout());
      assert::are_equal(radio_button.default_size().height, radio_button.bottom());
      assert::are_equal(drawing::rectangle({0, 0}, radio_button.default_size()), radio_button.bounds());
      assert::is_false(radio_button.can_focus());
      assert::is_true(radio_button.can_raise_events());
      assert::is_true(radio_button.can_select());
      assert::are_equal(drawing::rectangle({0, 0}, radio_button.default_size()), radio_button.client_rectangle());
      assert::are_equal(radio_button.default_size(), radio_button.client_size());
      assert::are_equal("Gammasoft", radio_button.company_name());
      assert::is_null(radio_button.context_menu());
      assert::are_equal(forms::control_appearance::standard, radio_button.control_appearance());
      assert::is_empty(radio_button.controls());
      assert::is_false(radio_button.created());
      assert::are_equal(forms::cursors::default_cursor(), radio_button.cursor());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), radio_button.default_back_color());
      assert::are_equal(forms::cursors::default_cursor(), radio_button.default_cursor());
      assert::are_equal(drawing::system_fonts::default_font(), radio_button.default_font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), radio_button.default_fore_color());
      assert::are_equal(radio_button.default_size(), radio_button.default_size());
      assert::are_equal(drawing::rectangle({0, 0}, radio_button.default_size()), radio_button.display_rectangle());
      assert::are_equal(forms::dock_style::none, radio_button.dock());
      assert::is_false(radio_button.double_buffered());
      assert::is_true(radio_button.enabled());
      assert::is_false(radio_button.focused());
      assert::are_equal(drawing::system_fonts::default_font(), radio_button.font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), radio_button.fore_color());
      assert::is_zero(radio_button.handle());
      assert::are_equal(radio_button.default_size().height, radio_button.height());
      assert::is_false(radio_button.invoke_required());
      assert::is_false(radio_button.is_handle_created());
      assert::is_zero(radio_button.left());
      assert::are_equal(drawing::point::empty, radio_button.location());
      assert::are_equal(forms::padding(3), radio_button.margin());
      assert::are_equal(drawing::size::empty, radio_button.maximum_client_size());
      assert::are_equal(drawing::size::empty, radio_button.maximum_size());
      assert::are_equal(drawing::size::empty, radio_button.minimum_client_size());
      assert::are_equal(drawing::size::empty, radio_button.minimum_size());
      assert::is_zero(radio_button.native_handle());
      assert::is_empty(radio_button.name());
      assert::are_equal(forms::padding(0), radio_button.padding());
      assert::is_null(radio_button.parent());
      assert::are_equal("xtd", radio_button.product_name());
      assert::is_not_zero(radio_button.region().handle());
      assert::are_equal(radio_button.default_size().width, radio_button.right());
      assert::are_equal(radio_button.default_size(), radio_button.size());
      assert::is_empty(radio_button.style_sheet().theme().name());
      assert::is_true(radio_button.tab_stop());
      assert::is_false(radio_button.tag().has_value());
      assert::is_empty(radio_button.text());
      assert::is_zero(radio_button.toolkit_handle());
      assert::is_zero(radio_button.top());
      assert::is_null(radio_button.top_level_control());
      assert::is_true(radio_button.visible());
      assert::are_equal(radio_button.default_size().width, radio_button.width());
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls());
      assert::are_equal(keys::none, forms::control::modifier_keys());
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons());
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position());
      
      assert::is_false(radio_button.auto_ellipsis());
      assert::are_equal(flat_button_appearance(), radio_button.flat_appearance());
      assert::are_equal(flat_style::standard, radio_button.flat_style());
      assert::are_equal(image::empty, radio_button.image());
      assert::are_equal(content_alignment::middle_center, radio_button.image_align());
      assert::are_equal(-1, radio_button.image_index());
      assert::are_equal(image_list::empty, radio_button.image_list());
      assert::are_equal(content_alignment::middle_left, radio_button.text_align());
    }
  };
}
