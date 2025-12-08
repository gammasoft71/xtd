#include <xtd/diagnostics/debugger>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(button_tests) {
    class button_for_test : public button {
    public:
      button_for_test() = default;
      
      using button::default_back_color;
      using button::default_cursor;
      using button::default_font;
      using button::default_fore_color;
      using button::default_size;
    };
    
    auto test_method_(constructor) {
      button_for_test button;
      assert::are_equal(anchor_styles::left | anchor_styles::top, button.anchor());
      assert::are_equal(drawing::point::empty, button.auto_scroll_point());
      assert::is_false(button.auto_size());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), button.back_color());
      assert::are_equal(drawing::image::empty, button.background_image());
      assert::are_equal(image_layout::tile, button.background_image_layout());
      assert::are_equal(button.default_size().height, button.bottom());
      assert::are_equal(drawing::rectangle({0, 0}, button.default_size()), button.bounds());
      assert::is_false(button.can_focus());
      assert::is_true(button.can_raise_events());
      assert::is_true(button.can_select());
      assert::are_equal(drawing::rectangle({0, 0}, button.default_size()), button.client_rectangle());
      assert::are_equal(button.default_size(), button.client_size());
      assert::are_equal("Gammasoft", button.company_name());
      assert::is_null(button.context_menu());
      assert::are_equal(forms::control_appearance::standard, button.control_appearance());
      assert::is_empty(button.controls());
      assert::is_false(button.created());
      assert::are_equal(forms::cursors::default_cursor(), button.cursor());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), button.default_back_color());
      assert::are_equal(forms::cursors::default_cursor(), button.default_cursor());
      assert::are_equal(drawing::system_fonts::default_font(), button.default_font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), button.default_fore_color());
      assert::are_equal(button.default_size(), button.default_size());
      assert::are_equal(drawing::rectangle({0, 0}, button.default_size()), button.display_rectangle());
      assert::are_equal(forms::dock_style::none, button.dock());
      assert::is_false(button.double_buffered());
      assert::is_true(button.enabled());
      assert::is_false(button.focused());
      assert::are_equal(drawing::system_fonts::default_font(), button.font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), button.fore_color());
      assert::is_zero(button.handle());
      assert::are_equal(button.default_size().height, button.height());
      assert::is_false(button.invoke_required());
      assert::is_false(button.is_handle_created());
      assert::is_zero(button.left());
      assert::are_equal(drawing::point::empty, button.location());
      assert::are_equal(forms::padding(3), button.margin());
      assert::are_equal(drawing::size::empty, button.maximum_client_size());
      assert::are_equal(drawing::size::empty, button.maximum_size());
      assert::are_equal(drawing::size::empty, button.minimum_client_size());
      assert::are_equal(drawing::size::empty, button.minimum_size());
      assert::is_zero(button.native_handle());
      assert::is_empty(button.name());
      assert::are_equal(forms::padding(0), button.padding());
      assert::is_null(button.parent());
      assert::are_equal("xtd", button.product_name());
      assert::is_not_zero(button.region().handle());
      assert::are_equal(button.default_size().width, button.right());
      assert::are_equal(button.default_size(), button.size());
      assert::is_empty(button.style_sheet().theme().name());
      assert::is_true(button.tab_stop());
      assert::is_false(button.tag().has_value());
      assert::is_empty(button.text());
      assert::is_zero(button.toolkit_handle());
      assert::is_zero(button.top());
      assert::is_null(button.top_level_control());
      assert::is_true(button.visible());
      assert::are_equal(button.default_size().width, button.width());
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls());
      assert::are_equal(keys::none, forms::control::modifier_keys());
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons());
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position());
      
      assert::is_false(button.auto_ellipsis());
      assert::are_equal(flat_button_appearance(), button.flat_appearance());
      assert::are_equal(flat_style::standard, button.flat_style());
      assert::are_equal(image::empty, button.image());
      assert::are_equal(content_alignment::middle_center, button.image_align());
      assert::are_equal(-1, button.image_index());
      assert::are_equal(image_list::empty, button.image_list());
      assert::are_equal(content_alignment::middle_center, button.text_align());
      
      assert::is_false(button.auto_repeat());
      assert::are_equal(300, button.auto_repeat_delay());
      assert::are_equal(100, button.auto_repeat_interval());
      assert::are_equal(dialog_result::none, button.dialog_result());
    }
    
    auto test_method_(create) {
      auto button = forms::button::create();
      assert::are_equal(anchor_styles::left | anchor_styles::top, button.anchor());
      assert::are_equal(drawing::point::empty, button.auto_scroll_point());
      assert::is_false(button.auto_size());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), button.back_color());
      assert::are_equal(drawing::image::empty, button.background_image());
      assert::are_equal(image_layout::tile, button.background_image_layout());
      assert::is_false(button.can_focus());
      assert::is_true(button.can_raise_events());
      assert::is_true(button.can_select());
      assert::are_equal("Gammasoft", button.company_name());
      assert::is_null(button.context_menu());
      assert::are_equal(forms::control_appearance::standard, button.control_appearance());
      assert::is_empty(button.controls());
      assert::is_false(button.created());
      assert::are_equal(forms::cursors::default_cursor(), button.cursor());
      assert::are_equal(forms::dock_style::none, button.dock());
      assert::is_false(button.double_buffered());
      assert::is_true(button.enabled());
      assert::is_false(button.focused());
      assert::are_equal(drawing::system_fonts::default_font(), button.font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), button.fore_color());
      assert::is_zero(button.handle());
      assert::is_false(button.invoke_required());
      assert::is_false(button.is_handle_created());
      assert::is_zero(button.left());
      assert::are_equal(drawing::point::empty, button.location());
      assert::are_equal(forms::padding(3), button.margin());
      assert::are_equal(drawing::size::empty, button.maximum_client_size());
      assert::are_equal(drawing::size::empty, button.maximum_size());
      assert::are_equal(drawing::size::empty, button.minimum_client_size());
      assert::are_equal(drawing::size::empty, button.minimum_size());
      assert::is_zero(button.native_handle());
      assert::is_empty(button.name());
      assert::are_equal(forms::padding(0), button.padding());
      assert::is_null(button.parent());
      assert::are_equal("xtd", button.product_name());
      assert::is_not_zero(button.region().handle());
      assert::is_empty(button.style_sheet().theme().name());
      assert::is_true(button.tab_stop());
      assert::is_false(button.tag().has_value());
      assert::is_empty(button.text());
      assert::is_zero(button.toolkit_handle());
      assert::is_zero(button.top());
      assert::is_null(button.top_level_control());
      assert::is_true(button.visible());
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls());
      assert::are_equal(keys::none, forms::control::modifier_keys());
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons());
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position());
      
      assert::is_false(button.auto_ellipsis());
      assert::are_equal(flat_button_appearance(), button.flat_appearance());
      assert::are_equal(flat_style::standard, button.flat_style());
      assert::are_equal(image::empty, button.image());
      assert::are_equal(content_alignment::middle_center, button.image_align());
      assert::are_equal(-1, button.image_index());
      assert::are_equal(image_list::empty, button.image_list());
      assert::are_equal(content_alignment::middle_center, button.text_align());
      
      assert::is_false(button.auto_repeat());
      assert::are_equal(300, button.auto_repeat_delay());
      assert::are_equal(100, button.auto_repeat_interval());
      assert::are_equal(dialog_result::none, button.dialog_result());
    }
    
    auto test_method_(create_with_text) {
      auto button = forms::button::create("new text");
      assert::are_equal(anchor_styles::left | anchor_styles::top, button.anchor());
      assert::are_equal(drawing::point::empty, button.auto_scroll_point());
      assert::is_false(button.auto_size());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), button.back_color());
      assert::are_equal(drawing::image::empty, button.background_image());
      assert::are_equal(image_layout::tile, button.background_image_layout());
      assert::is_false(button.can_focus());
      assert::is_true(button.can_raise_events());
      assert::is_true(button.can_select());
      assert::are_equal("Gammasoft", button.company_name());
      assert::is_null(button.context_menu());
      assert::are_equal(forms::control_appearance::standard, button.control_appearance());
      assert::is_empty(button.controls());
      assert::is_false(button.created());
      assert::are_equal(forms::cursors::default_cursor(), button.cursor());
      assert::are_equal(forms::dock_style::none, button.dock());
      assert::is_false(button.double_buffered());
      assert::is_true(button.enabled());
      assert::is_false(button.focused());
      assert::are_equal(drawing::system_fonts::default_font(), button.font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), button.fore_color());
      assert::is_zero(button.handle());
      assert::is_false(button.invoke_required());
      assert::is_false(button.is_handle_created());
      assert::is_zero(button.left());
      assert::are_equal(drawing::point::empty, button.location());
      assert::are_equal(forms::padding(3), button.margin());
      assert::are_equal(drawing::size::empty, button.maximum_client_size());
      assert::are_equal(drawing::size::empty, button.maximum_size());
      assert::are_equal(drawing::size::empty, button.minimum_client_size());
      assert::are_equal(drawing::size::empty, button.minimum_size());
      assert::is_zero(button.native_handle());
      assert::is_empty(button.name());
      assert::are_equal(forms::padding(0), button.padding());
      assert::is_null(button.parent());
      assert::are_equal("xtd", button.product_name());
      assert::is_not_zero(button.region().handle());
      assert::is_empty(button.style_sheet().theme().name());
      assert::is_true(button.tab_stop());
      assert::is_false(button.tag().has_value());
      assert::are_equal("new text", button.text());
      assert::is_zero(button.toolkit_handle());
      assert::is_zero(button.top());
      assert::is_null(button.top_level_control());
      assert::is_true(button.visible());
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls());
      assert::are_equal(keys::none, forms::control::modifier_keys());
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons());
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position());
      
      assert::is_false(button.auto_ellipsis());
      assert::are_equal(flat_button_appearance(), button.flat_appearance());
      assert::are_equal(flat_style::standard, button.flat_style());
      assert::are_equal(image::empty, button.image());
      assert::are_equal(content_alignment::middle_center, button.image_align());
      assert::are_equal(-1, button.image_index());
      assert::are_equal(image_list::empty, button.image_list());
      assert::are_equal(content_alignment::middle_center, button.text_align());
      
      assert::is_false(button.auto_repeat());
      assert::are_equal(300, button.auto_repeat_delay());
      assert::are_equal(100, button.auto_repeat_interval());
      assert::are_equal(dialog_result::none, button.dialog_result());
    }
    
    auto test_method_(create_with_text_and_location) {
      auto button = forms::button::create("new text", {10, 20});
      assert::are_equal(anchor_styles::left | anchor_styles::top, button.anchor());
      assert::are_equal(drawing::point::empty, button.auto_scroll_point());
      assert::is_false(button.auto_size());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), button.back_color());
      assert::are_equal(drawing::image::empty, button.background_image());
      assert::are_equal(image_layout::tile, button.background_image_layout());
      assert::is_false(button.can_focus());
      assert::is_true(button.can_raise_events());
      assert::is_true(button.can_select());
      assert::are_equal("Gammasoft", button.company_name());
      assert::is_null(button.context_menu());
      assert::are_equal(forms::control_appearance::standard, button.control_appearance());
      assert::is_empty(button.controls());
      assert::is_false(button.created());
      assert::are_equal(forms::cursors::default_cursor(), button.cursor());
      assert::are_equal(forms::dock_style::none, button.dock());
      assert::is_false(button.double_buffered());
      assert::is_true(button.enabled());
      assert::is_false(button.focused());
      assert::are_equal(drawing::system_fonts::default_font(), button.font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), button.fore_color());
      assert::is_zero(button.handle());
      assert::is_false(button.invoke_required());
      assert::is_false(button.is_handle_created());
      assert::are_equal(10, button.left());
      assert::are_equal(point {10, 20}, button.location());
      assert::are_equal(forms::padding(3), button.margin());
      assert::are_equal(drawing::size::empty, button.maximum_client_size());
      assert::are_equal(drawing::size::empty, button.maximum_size());
      assert::are_equal(drawing::size::empty, button.minimum_client_size());
      assert::are_equal(drawing::size::empty, button.minimum_size());
      assert::is_zero(button.native_handle());
      assert::is_empty(button.name());
      assert::are_equal(forms::padding(0), button.padding());
      assert::is_null(button.parent());
      assert::are_equal("xtd", button.product_name());
      assert::is_not_zero(button.region().handle());
      assert::is_empty(button.style_sheet().theme().name());
      assert::is_true(button.tab_stop());
      assert::is_false(button.tag().has_value());
      assert::are_equal("new text", button.text());
      assert::is_zero(button.toolkit_handle());
      assert::are_equal(20, button.top());
      assert::is_null(button.top_level_control());
      assert::is_true(button.visible());
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls());
      assert::are_equal(keys::none, forms::control::modifier_keys());
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons());
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position());
      
      assert::is_false(button.auto_ellipsis());
      assert::are_equal(flat_button_appearance(), button.flat_appearance());
      assert::are_equal(flat_style::standard, button.flat_style());
      assert::are_equal(image::empty, button.image());
      assert::are_equal(content_alignment::middle_center, button.image_align());
      assert::are_equal(-1, button.image_index());
      assert::are_equal(image_list::empty, button.image_list());
      assert::are_equal(content_alignment::middle_center, button.text_align());
      
      assert::is_false(button.auto_repeat());
      assert::are_equal(300, button.auto_repeat_delay());
      assert::are_equal(100, button.auto_repeat_interval());
      assert::are_equal(dialog_result::none, button.dialog_result());
    }
    
    auto test_method_(create_with_text_location_and_size) {
      auto button = forms::button::create("new text", {10, 20}, {30, 40});
      assert::are_equal(anchor_styles::left | anchor_styles::top, button.anchor());
      assert::are_equal(drawing::point::empty, button.auto_scroll_point());
      assert::is_false(button.auto_size());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), button.back_color());
      assert::are_equal(drawing::image::empty, button.background_image());
      assert::are_equal(image_layout::tile, button.background_image_layout());
      assert::is_false(button.can_focus());
      assert::is_true(button.can_raise_events());
      assert::is_true(button.can_select());
      assert::are_equal("Gammasoft", button.company_name());
      assert::is_null(button.context_menu());
      assert::are_equal(forms::control_appearance::standard, button.control_appearance());
      assert::is_empty(button.controls());
      assert::is_false(button.created());
      assert::are_equal(forms::cursors::default_cursor(), button.cursor());
      assert::are_equal(forms::dock_style::none, button.dock());
      assert::is_false(button.double_buffered());
      assert::is_true(button.enabled());
      assert::is_false(button.focused());
      assert::are_equal(drawing::system_fonts::default_font(), button.font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), button.fore_color());
      assert::is_zero(button.handle());
      assert::are_equal(40, button.height());
      assert::is_false(button.invoke_required());
      assert::is_false(button.is_handle_created());
      assert::are_equal(10, button.left());
      assert::are_equal(point {10, 20}, button.location());
      assert::are_equal(forms::padding(3), button.margin());
      assert::are_equal(drawing::size::empty, button.maximum_client_size());
      assert::are_equal(drawing::size::empty, button.maximum_size());
      assert::are_equal(drawing::size::empty, button.minimum_client_size());
      assert::are_equal(drawing::size::empty, button.minimum_size());
      assert::is_zero(button.native_handle());
      assert::is_empty(button.name());
      assert::are_equal(forms::padding(0), button.padding());
      assert::is_null(button.parent());
      assert::are_equal("xtd", button.product_name());
      assert::is_not_zero(button.region().handle());
      assert::are_equal(drawing::size {30, 40}, button.size());
      assert::is_empty(button.style_sheet().theme().name());
      assert::is_true(button.tab_stop());
      assert::is_false(button.tag().has_value());
      assert::are_equal("new text", button.text());
      assert::is_zero(button.toolkit_handle());
      assert::are_equal(20, button.top());
      assert::is_null(button.top_level_control());
      assert::is_true(button.visible());
      assert::are_equal(30, button.width());
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls());
      assert::are_equal(keys::none, forms::control::modifier_keys());
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons());
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position());
      
      assert::is_false(button.auto_ellipsis());
      assert::are_equal(flat_button_appearance(), button.flat_appearance());
      assert::are_equal(flat_style::standard, button.flat_style());
      assert::are_equal(image::empty, button.image());
      assert::are_equal(content_alignment::middle_center, button.image_align());
      assert::are_equal(-1, button.image_index());
      assert::are_equal(image_list::empty, button.image_list());
      assert::are_equal(content_alignment::middle_center, button.text_align());
      
      assert::is_false(button.auto_repeat());
      assert::are_equal(300, button.auto_repeat_delay());
      assert::are_equal(100, button.auto_repeat_interval());
      assert::are_equal(dialog_result::none, button.dialog_result());
    }
    
    auto test_method_(create_with_text_location_size_and_name) {
      auto button = forms::button::create("new text", {10, 20}, {30, 40}, "button");
      assert::are_equal(anchor_styles::left | anchor_styles::top, button.anchor());
      assert::are_equal(drawing::point::empty, button.auto_scroll_point());
      assert::is_false(button.auto_size());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), button.back_color());
      assert::are_equal(drawing::image::empty, button.background_image());
      assert::are_equal(image_layout::tile, button.background_image_layout());
      assert::is_false(button.can_focus());
      assert::is_true(button.can_raise_events());
      assert::is_true(button.can_select());
      assert::are_equal("Gammasoft", button.company_name());
      assert::is_null(button.context_menu());
      assert::are_equal(forms::control_appearance::standard, button.control_appearance());
      assert::is_empty(button.controls());
      assert::is_false(button.created());
      assert::are_equal(forms::cursors::default_cursor(), button.cursor());
      assert::are_equal(forms::dock_style::none, button.dock());
      assert::is_false(button.double_buffered());
      assert::is_true(button.enabled());
      assert::is_false(button.focused());
      assert::are_equal(drawing::system_fonts::default_font(), button.font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), button.fore_color());
      assert::is_zero(button.handle());
      assert::are_equal(40, button.height());
      assert::is_false(button.invoke_required());
      assert::is_false(button.is_handle_created());
      assert::are_equal(10, button.left());
      assert::are_equal(point {10, 20}, button.location());
      assert::are_equal(forms::padding(3), button.margin());
      assert::are_equal(drawing::size::empty, button.maximum_client_size());
      assert::are_equal(drawing::size::empty, button.maximum_size());
      assert::are_equal(drawing::size::empty, button.minimum_client_size());
      assert::are_equal(drawing::size::empty, button.minimum_size());
      assert::is_zero(button.native_handle());
      assert::are_equal("button", button.name());
      assert::are_equal(forms::padding(0), button.padding());
      assert::is_null(button.parent());
      assert::are_equal("xtd", button.product_name());
      assert::is_not_zero(button.region().handle());
      assert::are_equal(drawing::size {30, 40}, button.size());
      assert::is_empty(button.style_sheet().theme().name());
      assert::is_true(button.tab_stop());
      assert::is_false(button.tag().has_value());
      assert::are_equal("new text", button.text());
      assert::is_zero(button.toolkit_handle());
      assert::are_equal(20, button.top());
      assert::is_null(button.top_level_control());
      assert::is_true(button.visible());
      assert::are_equal(30, button.width());
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls());
      assert::are_equal(keys::none, forms::control::modifier_keys());
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons());
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position());
      
      assert::is_false(button.auto_ellipsis());
      assert::are_equal(flat_button_appearance(), button.flat_appearance());
      assert::are_equal(flat_style::standard, button.flat_style());
      assert::are_equal(image::empty, button.image());
      assert::are_equal(content_alignment::middle_center, button.image_align());
      assert::are_equal(-1, button.image_index());
      assert::are_equal(image_list::empty, button.image_list());
      assert::are_equal(content_alignment::middle_center, button.text_align());
      
      assert::is_false(button.auto_repeat());
      assert::are_equal(300, button.auto_repeat_delay());
      assert::are_equal(100, button.auto_repeat_interval());
      assert::are_equal(dialog_result::none, button.dialog_result());
    }
    
    auto test_method_(create_with_parent) {
      auto form = forms::form::create();
      auto button = forms::button::create(form);
      assert::are_equal(anchor_styles::left | anchor_styles::top, button.anchor());
      assert::are_equal(drawing::point::empty, button.auto_scroll_point());
      assert::is_false(button.auto_size());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), button.back_color());
      assert::are_equal(drawing::image::empty, button.background_image());
      assert::are_equal(image_layout::tile, button.background_image_layout());
      assert::is_false(button.can_focus());
      assert::is_true(button.can_raise_events());
      assert::is_true(button.can_select());
      assert::are_equal("Gammasoft", button.company_name());
      assert::is_null(button.context_menu());
      assert::are_equal(forms::control_appearance::standard, button.control_appearance());
      assert::is_empty(button.controls());
      assert::is_true(button.created());
      assert::are_equal(forms::cursors::default_cursor(), button.cursor());
      assert::are_equal(forms::dock_style::none, button.dock());
      assert::is_false(button.double_buffered());
      assert::is_true(button.enabled());
      assert::is_false(button.focused());
      assert::are_equal(drawing::system_fonts::default_font(), button.font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), button.fore_color());
      assert::is_not_zero(button.handle());
      assert::is_false(button.invoke_required());
      assert::is_true(button.is_handle_created());
      assert::is_zero(button.left());
      assert::are_equal(drawing::point::empty, button.location());
      assert::are_equal(forms::padding(3), button.margin());
      assert::are_equal(drawing::size::empty, button.maximum_client_size());
      assert::are_equal(drawing::size::empty, button.maximum_size());
      assert::are_equal(drawing::size::empty, button.minimum_client_size());
      assert::are_equal(drawing::size::empty, button.minimum_size());
      assert::is_not_zero(button.native_handle());
      assert::is_empty(button.name());
      assert::are_equal(forms::padding(0), button.padding());
      assert::are_same(form, button.parent().value().get());
      assert::are_equal("xtd", button.product_name());
      assert::is_not_zero(button.region().handle());
      assert::is_empty(button.style_sheet().theme().name());
      assert::is_true(button.tab_stop());
      assert::is_false(button.tag().has_value());
      assert::is_empty(button.text());
      assert::is_not_zero(button.toolkit_handle());
      assert::is_zero(button.top());
      assert::are_same(form, button.top_level_control().value().get());
      assert::is_true(button.visible());
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls());
      assert::are_equal(keys::none, forms::control::modifier_keys());
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons());
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position());
      
      assert::is_false(button.auto_ellipsis());
      assert::are_equal(flat_button_appearance(), button.flat_appearance());
      assert::are_equal(flat_style::standard, button.flat_style());
      assert::are_equal(image::empty, button.image());
      assert::are_equal(content_alignment::middle_center, button.image_align());
      assert::are_equal(-1, button.image_index());
      assert::are_equal(image_list::empty, button.image_list());
      assert::are_equal(content_alignment::middle_center, button.text_align());
      
      assert::is_false(button.auto_repeat());
      assert::are_equal(300, button.auto_repeat_delay());
      assert::are_equal(100, button.auto_repeat_interval());
      assert::are_equal(dialog_result::none, button.dialog_result());
    }
    
    auto test_method_(create_with_parent_and_text) {
      auto form = forms::form::create();
      auto button = forms::button::create(form, "new text");
      assert::are_equal(anchor_styles::left | anchor_styles::top, button.anchor());
      assert::are_equal(drawing::point::empty, button.auto_scroll_point());
      assert::is_false(button.auto_size());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), button.back_color());
      assert::are_equal(drawing::image::empty, button.background_image());
      assert::are_equal(image_layout::tile, button.background_image_layout());
      assert::is_false(button.can_focus());
      assert::is_true(button.can_raise_events());
      assert::is_true(button.can_select());
      assert::are_equal("Gammasoft", button.company_name());
      assert::is_null(button.context_menu());
      assert::are_equal(forms::control_appearance::standard, button.control_appearance());
      assert::is_empty(button.controls());
      assert::is_true(button.created());
      assert::are_equal(forms::cursors::default_cursor(), button.cursor());
      assert::are_equal(forms::dock_style::none, button.dock());
      assert::is_false(button.double_buffered());
      assert::is_true(button.enabled());
      assert::is_false(button.focused());
      assert::are_equal(drawing::system_fonts::default_font(), button.font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), button.fore_color());
      assert::is_not_zero(button.handle());
      assert::is_false(button.invoke_required());
      assert::is_true(button.is_handle_created());
      assert::is_zero(button.left());
      assert::are_equal(drawing::point::empty, button.location());
      assert::are_equal(forms::padding(3), button.margin());
      assert::are_equal(drawing::size::empty, button.maximum_client_size());
      assert::are_equal(drawing::size::empty, button.maximum_size());
      assert::are_equal(drawing::size::empty, button.minimum_client_size());
      assert::are_equal(drawing::size::empty, button.minimum_size());
      assert::is_not_zero(button.native_handle());
      assert::is_empty(button.name());
      assert::are_equal(forms::padding(0), button.padding());
      assert::are_same(form, button.parent().value().get());
      assert::are_equal("xtd", button.product_name());
      assert::is_not_zero(button.region().handle());
      assert::is_empty(button.style_sheet().theme().name());
      assert::is_true(button.tab_stop());
      assert::is_false(button.tag().has_value());
      assert::are_equal("new text", button.text());
      assert::is_not_zero(button.toolkit_handle());
      assert::is_zero(button.top());
      assert::are_same(form, button.top_level_control().value().get());
      assert::is_true(button.visible());
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls());
      assert::are_equal(keys::none, forms::control::modifier_keys());
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons());
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position());
      
      assert::is_false(button.auto_ellipsis());
      assert::are_equal(flat_button_appearance(), button.flat_appearance());
      assert::are_equal(flat_style::standard, button.flat_style());
      assert::are_equal(image::empty, button.image());
      assert::are_equal(content_alignment::middle_center, button.image_align());
      assert::are_equal(-1, button.image_index());
      assert::are_equal(image_list::empty, button.image_list());
      assert::are_equal(content_alignment::middle_center, button.text_align());
      
      assert::is_false(button.auto_repeat());
      assert::are_equal(300, button.auto_repeat_delay());
      assert::are_equal(100, button.auto_repeat_interval());
      assert::are_equal(dialog_result::none, button.dialog_result());
    }
    
    auto test_method_(create_with_parent_text_and_location) {
      auto form = forms::form::create();
      auto button = forms::button::create(form, "new text", {10, 20});
      assert::are_equal(anchor_styles::left | anchor_styles::top, button.anchor());
      assert::are_equal(drawing::point::empty, button.auto_scroll_point());
      assert::is_false(button.auto_size());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), button.back_color());
      assert::are_equal(drawing::image::empty, button.background_image());
      assert::are_equal(image_layout::tile, button.background_image_layout());
      assert::is_false(button.can_focus());
      assert::is_true(button.can_raise_events());
      assert::is_true(button.can_select());
      assert::are_equal("Gammasoft", button.company_name());
      assert::is_null(button.context_menu());
      assert::are_equal(forms::control_appearance::standard, button.control_appearance());
      assert::is_empty(button.controls());
      assert::is_true(button.created());
      assert::are_equal(forms::cursors::default_cursor(), button.cursor());
      assert::are_equal(forms::dock_style::none, button.dock());
      assert::is_false(button.double_buffered());
      assert::is_true(button.enabled());
      assert::is_false(button.focused());
      assert::are_equal(drawing::system_fonts::default_font(), button.font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), button.fore_color());
      assert::is_not_zero(button.handle());
      assert::is_false(button.invoke_required());
      assert::is_true(button.is_handle_created());
      assert::are_equal(10, button.left());
      assert::are_equal(point {10, 20}, button.location());
      assert::are_equal(forms::padding(3), button.margin());
      assert::are_equal(drawing::size::empty, button.maximum_client_size());
      assert::are_equal(drawing::size::empty, button.maximum_size());
      assert::are_equal(drawing::size::empty, button.minimum_client_size());
      assert::are_equal(drawing::size::empty, button.minimum_size());
      assert::is_not_zero(button.native_handle());
      assert::is_empty(button.name());
      assert::are_equal(forms::padding(0), button.padding());
      assert::are_same(form, button.parent().value().get());
      assert::are_equal("xtd", button.product_name());
      assert::is_not_zero(button.region().handle());
      assert::is_empty(button.style_sheet().theme().name());
      assert::is_true(button.tab_stop());
      assert::is_false(button.tag().has_value());
      assert::are_equal("new text", button.text());
      assert::is_not_zero(button.toolkit_handle());
      assert::are_equal(20, button.top());
      assert::are_same(form, button.top_level_control().value().get());
      assert::is_true(button.visible());
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls());
      assert::are_equal(keys::none, forms::control::modifier_keys());
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons());
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position());
      
      assert::is_false(button.auto_ellipsis());
      assert::are_equal(flat_button_appearance(), button.flat_appearance());
      assert::are_equal(flat_style::standard, button.flat_style());
      assert::are_equal(image::empty, button.image());
      assert::are_equal(content_alignment::middle_center, button.image_align());
      assert::are_equal(-1, button.image_index());
      assert::are_equal(image_list::empty, button.image_list());
      assert::are_equal(content_alignment::middle_center, button.text_align());
      
      assert::is_false(button.auto_repeat());
      assert::are_equal(300, button.auto_repeat_delay());
      assert::are_equal(100, button.auto_repeat_interval());
      assert::are_equal(dialog_result::none, button.dialog_result());
    }
    
    auto test_method_(create_with_parent_text_location_and_size) {
      auto form = forms::form::create();
      auto button = forms::button::create(form, "new text", {10, 20}, {30, 40});
      assert::are_equal(anchor_styles::left | anchor_styles::top, button.anchor());
      assert::are_equal(drawing::point::empty, button.auto_scroll_point());
      assert::is_false(button.auto_size());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), button.back_color());
      assert::are_equal(drawing::image::empty, button.background_image());
      assert::are_equal(image_layout::tile, button.background_image_layout());
      assert::is_false(button.can_focus());
      assert::is_true(button.can_raise_events());
      assert::is_true(button.can_select());
      assert::are_equal("Gammasoft", button.company_name());
      assert::is_null(button.context_menu());
      assert::are_equal(forms::control_appearance::standard, button.control_appearance());
      assert::is_empty(button.controls());
      assert::is_true(button.created());
      assert::are_equal(forms::cursors::default_cursor(), button.cursor());
      assert::are_equal(forms::dock_style::none, button.dock());
      assert::is_false(button.double_buffered());
      assert::is_true(button.enabled());
      assert::is_false(button.focused());
      assert::are_equal(drawing::system_fonts::default_font(), button.font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), button.fore_color());
      assert::is_not_zero(button.handle());
      assert::are_equal(40, button.height());
      assert::is_false(button.invoke_required());
      assert::is_true(button.is_handle_created());
      assert::are_equal(10, button.left());
      assert::are_equal(point {10, 20}, button.location());
      assert::are_equal(forms::padding(3), button.margin());
      assert::are_equal(drawing::size::empty, button.maximum_client_size());
      assert::are_equal(drawing::size::empty, button.maximum_size());
      assert::are_equal(drawing::size::empty, button.minimum_client_size());
      assert::are_equal(drawing::size::empty, button.minimum_size());
      assert::is_not_zero(button.native_handle());
      assert::is_empty(button.name());
      assert::are_equal(forms::padding(0), button.padding());
      assert::are_same(form, button.parent().value().get());
      assert::are_equal("xtd", button.product_name());
      assert::is_not_zero(button.region().handle());
      assert::are_equal(drawing::size {30, 40}, button.size());
      assert::is_empty(button.style_sheet().theme().name());
      assert::is_true(button.tab_stop());
      assert::is_false(button.tag().has_value());
      assert::are_equal("new text", button.text());
      assert::is_not_zero(button.toolkit_handle());
      assert::are_equal(20, button.top());
      assert::are_same(form, button.top_level_control().value().get());
      assert::is_true(button.visible());
      assert::are_equal(30, button.width());
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls());
      assert::are_equal(keys::none, forms::control::modifier_keys());
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons());
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position());
      
      assert::is_false(button.auto_ellipsis());
      assert::are_equal(flat_button_appearance(), button.flat_appearance());
      assert::are_equal(flat_style::standard, button.flat_style());
      assert::are_equal(image::empty, button.image());
      assert::are_equal(content_alignment::middle_center, button.image_align());
      assert::are_equal(-1, button.image_index());
      assert::are_equal(image_list::empty, button.image_list());
      assert::are_equal(content_alignment::middle_center, button.text_align());
      
      assert::is_false(button.auto_repeat());
      assert::are_equal(300, button.auto_repeat_delay());
      assert::are_equal(100, button.auto_repeat_interval());
      assert::are_equal(dialog_result::none, button.dialog_result());
    }
    
    auto test_method_(create_with_parent_text_location_size_and_name) {
      auto form = forms::form::create();
      auto button = forms::button::create(form, "new text", {10, 20}, {30, 40}, "button");
      assert::are_equal(anchor_styles::left | anchor_styles::top, button.anchor());
      assert::are_equal(drawing::point::empty, button.auto_scroll_point());
      assert::is_false(button.auto_size());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), button.back_color());
      assert::are_equal(drawing::image::empty, button.background_image());
      assert::are_equal(image_layout::tile, button.background_image_layout());
      assert::is_false(button.can_focus());
      assert::is_true(button.can_raise_events());
      assert::is_true(button.can_select());
      assert::are_equal("Gammasoft", button.company_name());
      assert::is_null(button.context_menu());
      assert::are_equal(forms::control_appearance::standard, button.control_appearance());
      assert::is_empty(button.controls());
      assert::is_true(button.created());
      assert::are_equal(forms::cursors::default_cursor(), button.cursor());
      assert::are_equal(forms::dock_style::none, button.dock());
      assert::is_false(button.double_buffered());
      assert::is_true(button.enabled());
      assert::is_false(button.focused());
      assert::are_equal(drawing::system_fonts::default_font(), button.font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), button.fore_color());
      assert::is_not_zero(button.handle());
      assert::are_equal(40, button.height());
      assert::is_false(button.invoke_required());
      assert::is_true(button.is_handle_created());
      assert::are_equal(10, button.left());
      assert::are_equal(point {10, 20}, button.location());
      assert::are_equal(forms::padding(3), button.margin());
      assert::are_equal(drawing::size::empty, button.maximum_client_size());
      assert::are_equal(drawing::size::empty, button.maximum_size());
      assert::are_equal(drawing::size::empty, button.minimum_client_size());
      assert::are_equal(drawing::size::empty, button.minimum_size());
      assert::is_not_zero(button.native_handle());
      assert::are_equal("button", button.name());
      assert::are_equal(forms::padding(0), button.padding());
      assert::are_same(form, button.parent().value().get());
      assert::are_equal("xtd", button.product_name());
      assert::is_not_zero(button.region().handle());
      assert::are_equal(drawing::size {30, 40}, button.size());
      assert::is_empty(button.style_sheet().theme().name());
      assert::is_true(button.tab_stop());
      assert::is_false(button.tag().has_value());
      assert::are_equal("new text", button.text());
      assert::is_not_zero(button.toolkit_handle());
      assert::are_equal(20, button.top());
      assert::are_same(form, button.top_level_control().value().get());
      assert::is_true(button.visible());
      assert::are_equal(30, button.width());
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls());
      assert::are_equal(keys::none, forms::control::modifier_keys());
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons());
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position());
      
      assert::is_false(button.auto_ellipsis());
      assert::are_equal(flat_button_appearance(), button.flat_appearance());
      assert::are_equal(flat_style::standard, button.flat_style());
      assert::are_equal(image::empty, button.image());
      assert::are_equal(content_alignment::middle_center, button.image_align());
      assert::are_equal(-1, button.image_index());
      assert::are_equal(image_list::empty, button.image_list());
      assert::are_equal(content_alignment::middle_center, button.text_align());
      
      assert::is_false(button.auto_repeat());
      assert::are_equal(300, button.auto_repeat_delay());
      assert::are_equal(100, button.auto_repeat_interval());
      assert::are_equal(dialog_result::none, button.dialog_result());
    }
    
    auto test_method_(perform_click_form_button) {
      form form;
      button_for_test button;
      button.parent(form);
      int click_control_check = 0;
      button.click += [&] {
        click_control_check += 1;
      };
      button.perform_click();
      assert::are_equal(1, click_control_check);
    }
    
    /*
    auto test_method_(send_message_button_click_form_panel_button) {
      form form;
      panel panel;
      panel.parent(form);
      forms::button button;
      button.parent(panel);
      int click_control_check = 0;
      button.click += [&] {
        click_control_check += 1;
      };
      send_message(button.handle(), WM_COMMAND, HIWORD(BN_CLICKED), button.handle());
      assert::are_equal(1, click_control_check);
    }*/
    
    auto test_method_(set_client_size) {
      form form;
      button_for_test button;
      button.parent(form);
      button.client_size({100, 50});
      assert::are_equal(drawing::size(100, 50), button.client_size());
    }
    
    auto test_method_(set_size) {
      form form;
      button_for_test button;
      button.parent(form);
      button.size({100, 50});
      assert::are_equal(drawing::size(100, 50), button.size());
    }
  };
}
