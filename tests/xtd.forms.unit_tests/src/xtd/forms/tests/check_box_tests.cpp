#include <xtd/forms/check_box>
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
  class test_class_(check_box_tests) {
    class check_box_for_test : public check_box {
    public:
      check_box_for_test() = default;
      
      using check_box::default_back_color;
      using check_box::default_cursor;
      using check_box::default_font;
      using check_box::default_fore_color;
      using check_box::default_size;
    };
    
    void test_method_(constructor) {
      check_box_for_test check_box;
      assert::are_equal(anchor_styles::left | anchor_styles::top, check_box.anchor(), csf_);
      assert::are_equal(drawing::point::empty, check_box.auto_scroll_point(), csf_);
      assert::is_false(check_box.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), check_box.back_color(), csf_);
      assert::are_equal(drawing::image::empty, check_box.background_image(), csf_);
      assert::are_equal(image_layout::tile, check_box.background_image_layout(), csf_);
      assert::are_equal(check_box.default_size().height(), check_box.bottom(), csf_);
      assert::are_equal(drawing::rectangle({0, 0}, check_box.default_size()), check_box.bounds(), csf_);
      assert::is_false(check_box.can_focus(), csf_);
      assert::is_true(check_box.can_raise_events(), csf_);
      assert::is_true(check_box.can_select(), csf_);
      assert::are_equal(drawing::rectangle({0, 0}, check_box.default_size()), check_box.client_rectangle(), csf_);
      assert::are_equal(check_box.default_size(), check_box.client_size(), csf_);
      assert::are_equal("Gammasoft", check_box.company_name(), csf_);
      assert::is_null(check_box.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, check_box.control_appearance(), csf_);
      assert::is_empty(check_box.controls(), csf_);
      assert::is_false(check_box.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), check_box.cursor(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), check_box.default_back_color(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), check_box.default_cursor(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), check_box.default_font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), check_box.default_fore_color(), csf_);
      assert::are_equal(check_box.default_size(), check_box.default_size(), csf_);
      assert::are_equal(drawing::rectangle({0, 0}, check_box.default_size()), check_box.display_rectangle(), csf_);
      assert::are_equal(forms::dock_style::none, check_box.dock(), csf_);
      assert::is_false(check_box.double_buffered(), csf_);
      assert::is_true(check_box.enabled(), csf_);
      assert::is_false(check_box.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), check_box.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), check_box.fore_color(), csf_);
      assert::is_zero(check_box.handle(), csf_);
      assert::are_equal(check_box.default_size().height(), check_box.height(), csf_);
      assert::is_false(check_box.invoke_required(), csf_);
      assert::is_false(check_box.is_handle_created(), csf_);
      assert::is_zero(check_box.left(), csf_);
      assert::are_equal(drawing::point::empty, check_box.location(), csf_);
      assert::are_equal(forms::padding(3), check_box.margin(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_size(), csf_);
      assert::is_zero(check_box.native_handle(), csf_);
      assert::is_empty(check_box.name(), csf_);
      assert::are_equal(forms::padding(0), check_box.padding(), csf_);
      assert::is_null(check_box.parent(), csf_);
      assert::are_equal("xtd", check_box.product_name(), csf_);
      assert::is_not_zero(check_box.region().handle(), csf_);
      assert::are_equal(check_box.default_size().width(), check_box.right(), csf_);
      assert::are_equal(check_box.default_size(), check_box.size(), csf_);
      assert::is_empty(check_box.style_sheet().theme().name(), csf_);
      assert::is_true(check_box.tab_stop(), csf_);
      assert::is_false(check_box.tag().has_value(), csf_);
      assert::is_empty(check_box.text(), csf_);
      assert::is_zero(check_box.toolkit_handle(), csf_);
      assert::is_zero(check_box.top(), csf_);
      assert::is_null(check_box.top_level_control(), csf_);
      assert::is_true(check_box.visible(), csf_);
      assert::are_equal(check_box.default_size().width(), check_box.width(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
      
      assert::is_false(check_box.auto_ellipsis(), csf_);
      assert::are_equal(flat_button_appearance(), check_box.flat_appearance(), csf_);
      assert::are_equal(flat_style::standard, check_box.flat_style(), csf_);
      assert::are_equal(image::empty, check_box.image(), csf_);
      assert::are_equal(content_alignment::middle_center, check_box.image_align(), csf_);
      assert::are_equal(-1, check_box.image_index(), csf_);
      assert::are_equal(image_list::empty, check_box.image_list(), csf_);
      assert::are_equal(content_alignment::middle_left, check_box.text_align(), csf_);

      assert::are_equal(check_state::unchecked, check_box.check_state(), csf_);
      assert::is_false(check_box.checked(), csf_);
      assert::is_false(check_box.three_state(), csf_);
    }
    
    void test_method_(create) {
      auto check_box = forms::check_box::create();
      assert::are_equal(anchor_styles::left | anchor_styles::top, check_box.anchor(), csf_);
      assert::are_equal(drawing::point::empty, check_box.auto_scroll_point(), csf_);
      assert::is_false(check_box.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), check_box.back_color(), csf_);
      assert::are_equal(drawing::image::empty, check_box.background_image(), csf_);
      assert::are_equal(image_layout::tile, check_box.background_image_layout(), csf_);
      assert::is_false(check_box.can_focus(), csf_);
      assert::is_true(check_box.can_raise_events(), csf_);
      assert::is_true(check_box.can_select(), csf_);
      assert::are_equal("Gammasoft", check_box.company_name(), csf_);
      assert::is_null(check_box.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, check_box.control_appearance(), csf_);
      assert::is_empty(check_box.controls(), csf_);
      assert::is_false(check_box.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), check_box.cursor(), csf_);
      assert::are_equal(forms::dock_style::none, check_box.dock(), csf_);
      assert::is_false(check_box.double_buffered(), csf_);
      assert::is_true(check_box.enabled(), csf_);
      assert::is_false(check_box.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), check_box.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), check_box.fore_color(), csf_);
      assert::is_zero(check_box.handle(), csf_);
      assert::is_false(check_box.invoke_required(), csf_);
      assert::is_false(check_box.is_handle_created(), csf_);
      assert::is_zero(check_box.left(), csf_);
      assert::are_equal(drawing::point::empty, check_box.location(), csf_);
      assert::are_equal(forms::padding(3), check_box.margin(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_size(), csf_);
      assert::is_zero(check_box.native_handle(), csf_);
      assert::is_empty(check_box.name(), csf_);
      assert::are_equal(forms::padding(0), check_box.padding(), csf_);
      assert::is_null(check_box.parent(), csf_);
      assert::are_equal("xtd", check_box.product_name(), csf_);
      assert::is_not_zero(check_box.region().handle(), csf_);
      assert::is_empty(check_box.style_sheet().theme().name(), csf_);
      assert::is_true(check_box.tab_stop(), csf_);
      assert::is_false(check_box.tag().has_value(), csf_);
      assert::is_empty(check_box.text(), csf_);
      assert::is_zero(check_box.toolkit_handle(), csf_);
      assert::is_zero(check_box.top(), csf_);
      assert::is_null(check_box.top_level_control(), csf_);
      assert::is_true(check_box.visible(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
      
      assert::is_false(check_box.auto_ellipsis(), csf_);
      assert::are_equal(flat_button_appearance(), check_box.flat_appearance(), csf_);
      assert::are_equal(flat_style::standard, check_box.flat_style(), csf_);
      assert::are_equal(image::empty, check_box.image(), csf_);
      assert::are_equal(content_alignment::middle_center, check_box.image_align(), csf_);
      assert::are_equal(-1, check_box.image_index(), csf_);
      assert::are_equal(image_list::empty, check_box.image_list(), csf_);
      assert::are_equal(content_alignment::middle_left, check_box.text_align(), csf_);

      assert::are_equal(check_state::unchecked, check_box.check_state(), csf_);
      assert::is_false(check_box.checked(), csf_);
      assert::is_false(check_box.three_state(), csf_);
    }
    
    void test_method_(create_with_text) {
      auto check_box = forms::check_box::create("new text");
      assert::are_equal(anchor_styles::left | anchor_styles::top, check_box.anchor(), csf_);
      assert::are_equal(drawing::point::empty, check_box.auto_scroll_point(), csf_);
      assert::is_false(check_box.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), check_box.back_color(), csf_);
      assert::are_equal(drawing::image::empty, check_box.background_image(), csf_);
      assert::are_equal(image_layout::tile, check_box.background_image_layout(), csf_);
      assert::is_false(check_box.can_focus(), csf_);
      assert::is_true(check_box.can_raise_events(), csf_);
      assert::is_true(check_box.can_select(), csf_);
      assert::are_equal("Gammasoft", check_box.company_name(), csf_);
      assert::is_null(check_box.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, check_box.control_appearance(), csf_);
      assert::is_empty(check_box.controls(), csf_);
      assert::is_false(check_box.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), check_box.cursor(), csf_);
      assert::are_equal(forms::dock_style::none, check_box.dock(), csf_);
      assert::is_false(check_box.double_buffered(), csf_);
      assert::is_true(check_box.enabled(), csf_);
      assert::is_false(check_box.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), check_box.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), check_box.fore_color(), csf_);
      assert::is_zero(check_box.handle(), csf_);
      assert::is_false(check_box.invoke_required(), csf_);
      assert::is_false(check_box.is_handle_created(), csf_);
      assert::is_zero(check_box.left(), csf_);
      assert::are_equal(drawing::point::empty, check_box.location(), csf_);
      assert::are_equal(forms::padding(3), check_box.margin(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_size(), csf_);
      assert::is_zero(check_box.native_handle(), csf_);
      assert::is_empty(check_box.name(), csf_);
      assert::are_equal(forms::padding(0), check_box.padding(), csf_);
      assert::is_null(check_box.parent(), csf_);
      assert::are_equal("xtd", check_box.product_name(), csf_);
      assert::is_not_zero(check_box.region().handle(), csf_);
      assert::is_empty(check_box.style_sheet().theme().name(), csf_);
      assert::is_true(check_box.tab_stop(), csf_);
      assert::is_false(check_box.tag().has_value(), csf_);
      assert::are_equal("new text", check_box.text(), csf_);
      assert::is_zero(check_box.toolkit_handle(), csf_);
      assert::is_zero(check_box.top(), csf_);
      assert::is_null(check_box.top_level_control(), csf_);
      assert::is_true(check_box.visible(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
      
      assert::is_false(check_box.auto_ellipsis(), csf_);
      assert::are_equal(flat_button_appearance(), check_box.flat_appearance(), csf_);
      assert::are_equal(flat_style::standard, check_box.flat_style(), csf_);
      assert::are_equal(image::empty, check_box.image(), csf_);
      assert::are_equal(content_alignment::middle_center, check_box.image_align(), csf_);
      assert::are_equal(-1, check_box.image_index(), csf_);
      assert::are_equal(image_list::empty, check_box.image_list(), csf_);
      assert::are_equal(content_alignment::middle_left, check_box.text_align(), csf_);

      assert::are_equal(check_state::unchecked, check_box.check_state(), csf_);
      assert::is_false(check_box.checked(), csf_);
      assert::is_false(check_box.three_state(), csf_);
    }
    
    void test_method_(create_with_text_and_three_state) {
      auto check_box = forms::check_box::create("new text", true);
      assert::are_equal(anchor_styles::left | anchor_styles::top, check_box.anchor(), csf_);
      assert::are_equal(drawing::point::empty, check_box.auto_scroll_point(), csf_);
      assert::is_false(check_box.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), check_box.back_color(), csf_);
      assert::are_equal(drawing::image::empty, check_box.background_image(), csf_);
      assert::are_equal(image_layout::tile, check_box.background_image_layout(), csf_);
      assert::is_false(check_box.can_focus(), csf_);
      assert::is_true(check_box.can_raise_events(), csf_);
      assert::is_true(check_box.can_select(), csf_);
      assert::are_equal("Gammasoft", check_box.company_name(), csf_);
      assert::is_null(check_box.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, check_box.control_appearance(), csf_);
      assert::is_empty(check_box.controls(), csf_);
      assert::is_false(check_box.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), check_box.cursor(), csf_);
      assert::are_equal(forms::dock_style::none, check_box.dock(), csf_);
      assert::is_false(check_box.double_buffered(), csf_);
      assert::is_true(check_box.enabled(), csf_);
      assert::is_false(check_box.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), check_box.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), check_box.fore_color(), csf_);
      assert::is_zero(check_box.handle(), csf_);
      assert::is_false(check_box.invoke_required(), csf_);
      assert::is_false(check_box.is_handle_created(), csf_);
      assert::is_zero(check_box.left(), csf_);
      assert::are_equal(drawing::point::empty, check_box.location(), csf_);
      assert::are_equal(forms::padding(3), check_box.margin(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_size(), csf_);
      assert::is_zero(check_box.native_handle(), csf_);
      assert::is_empty(check_box.name(), csf_);
      assert::are_equal(forms::padding(0), check_box.padding(), csf_);
      assert::is_null(check_box.parent(), csf_);
      assert::are_equal("xtd", check_box.product_name(), csf_);
      assert::is_not_zero(check_box.region().handle(), csf_);
      assert::is_empty(check_box.style_sheet().theme().name(), csf_);
      assert::is_true(check_box.tab_stop(), csf_);
      assert::is_false(check_box.tag().has_value(), csf_);
      assert::are_equal("new text", check_box.text(), csf_);
      assert::is_zero(check_box.toolkit_handle(), csf_);
      assert::is_zero(check_box.top(), csf_);
      assert::is_null(check_box.top_level_control(), csf_);
      assert::is_true(check_box.visible(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
      
      assert::is_false(check_box.auto_ellipsis(), csf_);
      assert::are_equal(flat_button_appearance(), check_box.flat_appearance(), csf_);
      assert::are_equal(flat_style::standard, check_box.flat_style(), csf_);
      assert::are_equal(image::empty, check_box.image(), csf_);
      assert::are_equal(content_alignment::middle_center, check_box.image_align(), csf_);
      assert::are_equal(-1, check_box.image_index(), csf_);
      assert::are_equal(image_list::empty, check_box.image_list(), csf_);
      assert::are_equal(content_alignment::middle_left, check_box.text_align(), csf_);
      
      assert::are_equal(check_state::unchecked, check_box.check_state(), csf_);
      assert::is_false(check_box.checked(), csf_);
      assert::is_true(check_box.three_state(), csf_);
    }
    
    void test_method_(create_with_text_three_state_and_check_state) {
      auto check_box = forms::check_box::create("new text", true, check_state::checked);
      assert::are_equal(anchor_styles::left | anchor_styles::top, check_box.anchor(), csf_);
      assert::are_equal(drawing::point::empty, check_box.auto_scroll_point(), csf_);
      assert::is_false(check_box.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), check_box.back_color(), csf_);
      assert::are_equal(drawing::image::empty, check_box.background_image(), csf_);
      assert::are_equal(image_layout::tile, check_box.background_image_layout(), csf_);
      assert::is_false(check_box.can_focus(), csf_);
      assert::is_true(check_box.can_raise_events(), csf_);
      assert::is_true(check_box.can_select(), csf_);
      assert::are_equal("Gammasoft", check_box.company_name(), csf_);
      assert::is_null(check_box.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, check_box.control_appearance(), csf_);
      assert::is_empty(check_box.controls(), csf_);
      assert::is_false(check_box.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), check_box.cursor(), csf_);
      assert::are_equal(forms::dock_style::none, check_box.dock(), csf_);
      assert::is_false(check_box.double_buffered(), csf_);
      assert::is_true(check_box.enabled(), csf_);
      assert::is_false(check_box.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), check_box.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), check_box.fore_color(), csf_);
      assert::is_zero(check_box.handle(), csf_);
      assert::is_false(check_box.invoke_required(), csf_);
      assert::is_false(check_box.is_handle_created(), csf_);
      assert::is_zero(check_box.left(), csf_);
      assert::are_equal(drawing::point::empty, check_box.location(), csf_);
      assert::are_equal(forms::padding(3), check_box.margin(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_size(), csf_);
      assert::is_zero(check_box.native_handle(), csf_);
      assert::is_empty(check_box.name(), csf_);
      assert::are_equal(forms::padding(0), check_box.padding(), csf_);
      assert::is_null(check_box.parent(), csf_);
      assert::are_equal("xtd", check_box.product_name(), csf_);
      assert::is_not_zero(check_box.region().handle(), csf_);
      assert::is_empty(check_box.style_sheet().theme().name(), csf_);
      assert::is_true(check_box.tab_stop(), csf_);
      assert::is_false(check_box.tag().has_value(), csf_);
      assert::are_equal("new text", check_box.text(), csf_);
      assert::is_zero(check_box.toolkit_handle(), csf_);
      assert::is_zero(check_box.top(), csf_);
      assert::is_null(check_box.top_level_control(), csf_);
      assert::is_true(check_box.visible(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
      
      assert::is_false(check_box.auto_ellipsis(), csf_);
      assert::are_equal(flat_button_appearance(), check_box.flat_appearance(), csf_);
      assert::are_equal(flat_style::standard, check_box.flat_style(), csf_);
      assert::are_equal(image::empty, check_box.image(), csf_);
      assert::are_equal(content_alignment::middle_center, check_box.image_align(), csf_);
      assert::are_equal(-1, check_box.image_index(), csf_);
      assert::are_equal(image_list::empty, check_box.image_list(), csf_);
      assert::are_equal(content_alignment::middle_left, check_box.text_align(), csf_);
      
      assert::are_equal(check_state::checked, check_box.check_state(), csf_);
      assert::is_true(check_box.checked(), csf_);
      assert::is_true(check_box.three_state(), csf_);
    }
    
    void test_method_(create_with_text_three_state_check_state_and_location) {
      auto check_box = forms::check_box::create("new text", true, check_state::checked, {10, 20});
      assert::are_equal(anchor_styles::left | anchor_styles::top, check_box.anchor(), csf_);
      assert::are_equal(drawing::point::empty, check_box.auto_scroll_point(), csf_);
      assert::is_false(check_box.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), check_box.back_color(), csf_);
      assert::are_equal(drawing::image::empty, check_box.background_image(), csf_);
      assert::are_equal(image_layout::tile, check_box.background_image_layout(), csf_);
      assert::is_false(check_box.can_focus(), csf_);
      assert::is_true(check_box.can_raise_events(), csf_);
      assert::is_true(check_box.can_select(), csf_);
      assert::are_equal("Gammasoft", check_box.company_name(), csf_);
      assert::is_null(check_box.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, check_box.control_appearance(), csf_);
      assert::is_empty(check_box.controls(), csf_);
      assert::is_false(check_box.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), check_box.cursor(), csf_);
      assert::are_equal(forms::dock_style::none, check_box.dock(), csf_);
      assert::is_false(check_box.double_buffered(), csf_);
      assert::is_true(check_box.enabled(), csf_);
      assert::is_false(check_box.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), check_box.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), check_box.fore_color(), csf_);
      assert::is_zero(check_box.handle(), csf_);
      assert::is_false(check_box.invoke_required(), csf_);
      assert::is_false(check_box.is_handle_created(), csf_);
      assert::are_equal(10, check_box.left(), csf_);
      assert::are_equal(drawing::point {10, 20}, check_box.location(), csf_);
      assert::are_equal(forms::padding(3), check_box.margin(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_size(), csf_);
      assert::is_zero(check_box.native_handle(), csf_);
      assert::is_empty(check_box.name(), csf_);
      assert::are_equal(forms::padding(0), check_box.padding(), csf_);
      assert::is_null(check_box.parent(), csf_);
      assert::are_equal("xtd", check_box.product_name(), csf_);
      assert::is_not_zero(check_box.region().handle(), csf_);
      assert::is_empty(check_box.style_sheet().theme().name(), csf_);
      assert::is_true(check_box.tab_stop(), csf_);
      assert::is_false(check_box.tag().has_value(), csf_);
      assert::are_equal("new text", check_box.text(), csf_);
      assert::is_zero(check_box.toolkit_handle(), csf_);
      assert::are_equal(20, check_box.top(), csf_);
      assert::is_null(check_box.top_level_control(), csf_);
      assert::is_true(check_box.visible(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
      
      assert::is_false(check_box.auto_ellipsis(), csf_);
      assert::are_equal(flat_button_appearance(), check_box.flat_appearance(), csf_);
      assert::are_equal(flat_style::standard, check_box.flat_style(), csf_);
      assert::are_equal(image::empty, check_box.image(), csf_);
      assert::are_equal(content_alignment::middle_center, check_box.image_align(), csf_);
      assert::are_equal(-1, check_box.image_index(), csf_);
      assert::are_equal(image_list::empty, check_box.image_list(), csf_);
      assert::are_equal(content_alignment::middle_left, check_box.text_align(), csf_);
      
      assert::are_equal(check_state::checked, check_box.check_state(), csf_);
      assert::is_true(check_box.checked(), csf_);
      assert::is_true(check_box.three_state(), csf_);
    }
    
    void test_method_(create_with_text_three_state_check_state_location_and_size) {
      auto check_box = forms::check_box::create("new text", true, check_state::checked, {10, 20}, {30, 40});
      assert::are_equal(anchor_styles::left | anchor_styles::top, check_box.anchor(), csf_);
      assert::are_equal(drawing::point::empty, check_box.auto_scroll_point(), csf_);
      assert::is_false(check_box.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), check_box.back_color(), csf_);
      assert::are_equal(drawing::image::empty, check_box.background_image(), csf_);
      assert::are_equal(image_layout::tile, check_box.background_image_layout(), csf_);
      assert::is_false(check_box.can_focus(), csf_);
      assert::is_true(check_box.can_raise_events(), csf_);
      assert::is_true(check_box.can_select(), csf_);
      assert::are_equal("Gammasoft", check_box.company_name(), csf_);
      assert::is_null(check_box.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, check_box.control_appearance(), csf_);
      assert::is_empty(check_box.controls(), csf_);
      assert::is_false(check_box.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), check_box.cursor(), csf_);
      assert::are_equal(forms::dock_style::none, check_box.dock(), csf_);
      assert::is_false(check_box.double_buffered(), csf_);
      assert::is_true(check_box.enabled(), csf_);
      assert::is_false(check_box.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), check_box.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), check_box.fore_color(), csf_);
      assert::is_zero(check_box.handle(), csf_);
      assert::are_equal(40, check_box.height(), csf_);
      assert::is_false(check_box.invoke_required(), csf_);
      assert::is_false(check_box.is_handle_created(), csf_);
      assert::are_equal(10, check_box.left(), csf_);
      assert::are_equal(drawing::point {10, 20}, check_box.location(), csf_);
      assert::are_equal(forms::padding(3), check_box.margin(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_size(), csf_);
      assert::is_zero(check_box.native_handle(), csf_);
      assert::is_empty(check_box.name(), csf_);
      assert::are_equal(forms::padding(0), check_box.padding(), csf_);
      assert::is_null(check_box.parent(), csf_);
      assert::are_equal("xtd", check_box.product_name(), csf_);
      assert::is_not_zero(check_box.region().handle(), csf_);
      assert::are_equal(drawing::size {30, 40}, check_box.size(), csf_);
      assert::is_empty(check_box.style_sheet().theme().name(), csf_);
      assert::is_true(check_box.tab_stop(), csf_);
      assert::is_false(check_box.tag().has_value(), csf_);
      assert::are_equal("new text", check_box.text(), csf_);
      assert::is_zero(check_box.toolkit_handle(), csf_);
      assert::are_equal(20, check_box.top(), csf_);
      assert::is_null(check_box.top_level_control(), csf_);
      assert::is_true(check_box.visible(), csf_);
      assert::are_equal(30, check_box.width(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
      
      assert::is_false(check_box.auto_ellipsis(), csf_);
      assert::are_equal(flat_button_appearance(), check_box.flat_appearance(), csf_);
      assert::are_equal(flat_style::standard, check_box.flat_style(), csf_);
      assert::are_equal(image::empty, check_box.image(), csf_);
      assert::are_equal(content_alignment::middle_center, check_box.image_align(), csf_);
      assert::are_equal(-1, check_box.image_index(), csf_);
      assert::are_equal(image_list::empty, check_box.image_list(), csf_);
      assert::are_equal(content_alignment::middle_left, check_box.text_align(), csf_);
      
      assert::are_equal(check_state::checked, check_box.check_state(), csf_);
      assert::is_true(check_box.checked(), csf_);
      assert::is_true(check_box.three_state(), csf_);
    }

    void test_method_(create_with_parent) {
      auto form = forms::form::create();
      auto check_box = forms::check_box::create(form);
      assert::are_equal(anchor_styles::left | anchor_styles::top, check_box.anchor(), csf_);
      assert::are_equal(drawing::point::empty, check_box.auto_scroll_point(), csf_);
      assert::is_false(check_box.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), check_box.back_color(), csf_);
      assert::are_equal(drawing::image::empty, check_box.background_image(), csf_);
      assert::are_equal(image_layout::tile, check_box.background_image_layout(), csf_);
      assert::is_false(check_box.can_focus(), csf_);
      assert::is_true(check_box.can_raise_events(), csf_);
      assert::is_true(check_box.can_select(), csf_);
      assert::are_equal("Gammasoft", check_box.company_name(), csf_);
      assert::is_null(check_box.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, check_box.control_appearance(), csf_);
      assert::is_empty(check_box.controls(), csf_);
      assert::is_true(check_box.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), check_box.cursor(), csf_);
      assert::are_equal(forms::dock_style::none, check_box.dock(), csf_);
      assert::is_false(check_box.double_buffered(), csf_);
      assert::is_true(check_box.enabled(), csf_);
      assert::is_false(check_box.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), check_box.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), check_box.fore_color(), csf_);
      assert::is_not_zero(check_box.handle(), csf_);
      assert::is_false(check_box.invoke_required(), csf_);
      assert::is_true(check_box.is_handle_created(), csf_);
      assert::is_zero(check_box.left(), csf_);
      assert::are_equal(drawing::point::empty, check_box.location(), csf_);
      assert::are_equal(forms::padding(3), check_box.margin(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_size(), csf_);
      assert::is_not_zero(check_box.native_handle(), csf_);
      assert::is_empty(check_box.name(), csf_);
      assert::are_equal(forms::padding(0), check_box.padding(), csf_);
      assert::are_same(form, check_box.parent().value().get(), csf_);
      assert::are_equal("xtd", check_box.product_name(), csf_);
      assert::is_not_zero(check_box.region().handle(), csf_);
      assert::is_empty(check_box.style_sheet().theme().name(), csf_);
      assert::is_true(check_box.tab_stop(), csf_);
      assert::is_false(check_box.tag().has_value(), csf_);
      assert::is_empty(check_box.text(), csf_);
      assert::is_not_zero(check_box.toolkit_handle(), csf_);
      assert::is_zero(check_box.top(), csf_);
      assert::are_same(form, check_box.top_level_control().value().get(), csf_);
      assert::is_true(check_box.visible(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
      
      assert::is_false(check_box.auto_ellipsis(), csf_);
      assert::are_equal(flat_button_appearance(), check_box.flat_appearance(), csf_);
      assert::are_equal(flat_style::standard, check_box.flat_style(), csf_);
      assert::are_equal(image::empty, check_box.image(), csf_);
      assert::are_equal(content_alignment::middle_center, check_box.image_align(), csf_);
      assert::are_equal(-1, check_box.image_index(), csf_);
      assert::are_equal(image_list::empty, check_box.image_list(), csf_);
      assert::are_equal(content_alignment::middle_left, check_box.text_align(), csf_);

      assert::are_equal(check_state::unchecked, check_box.check_state(), csf_);
      assert::is_false(check_box.checked(), csf_);
      assert::is_false(check_box.three_state(), csf_);
    }

    void test_method_(create_with_parent_and_text) {
      auto form = forms::form::create();
      auto check_box = forms::check_box::create(form, "new text");
      assert::are_equal(anchor_styles::left | anchor_styles::top, check_box.anchor(), csf_);
      assert::are_equal(drawing::point::empty, check_box.auto_scroll_point(), csf_);
      assert::is_false(check_box.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), check_box.back_color(), csf_);
      assert::are_equal(drawing::image::empty, check_box.background_image(), csf_);
      assert::are_equal(image_layout::tile, check_box.background_image_layout(), csf_);
      assert::is_false(check_box.can_focus(), csf_);
      assert::is_true(check_box.can_raise_events(), csf_);
      assert::is_true(check_box.can_select(), csf_);
      assert::are_equal("Gammasoft", check_box.company_name(), csf_);
      assert::is_null(check_box.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, check_box.control_appearance(), csf_);
      assert::is_empty(check_box.controls(), csf_);
      assert::is_true(check_box.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), check_box.cursor(), csf_);
      assert::are_equal(forms::dock_style::none, check_box.dock(), csf_);
      assert::is_false(check_box.double_buffered(), csf_);
      assert::is_true(check_box.enabled(), csf_);
      assert::is_false(check_box.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), check_box.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), check_box.fore_color(), csf_);
      assert::is_not_zero(check_box.handle(), csf_);
      assert::is_false(check_box.invoke_required(), csf_);
      assert::is_true(check_box.is_handle_created(), csf_);
      assert::is_zero(check_box.left(), csf_);
      assert::are_equal(drawing::point::empty, check_box.location(), csf_);
      assert::are_equal(forms::padding(3), check_box.margin(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_size(), csf_);
      assert::is_not_zero(check_box.native_handle(), csf_);
      assert::is_empty(check_box.name(), csf_);
      assert::are_equal(forms::padding(0), check_box.padding(), csf_);
      assert::are_same(form, check_box.parent().value().get(), csf_);
      assert::are_equal("xtd", check_box.product_name(), csf_);
      assert::is_not_zero(check_box.region().handle(), csf_);
      assert::is_empty(check_box.style_sheet().theme().name(), csf_);
      assert::is_true(check_box.tab_stop(), csf_);
      assert::is_false(check_box.tag().has_value(), csf_);
      assert::are_equal("new text", check_box.text(), csf_);
      assert::is_not_zero(check_box.toolkit_handle(), csf_);
      assert::is_zero(check_box.top(), csf_);
      assert::are_same(form, check_box.top_level_control().value().get(), csf_);
      assert::is_true(check_box.visible(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
      
      assert::is_false(check_box.auto_ellipsis(), csf_);
      assert::are_equal(flat_button_appearance(), check_box.flat_appearance(), csf_);
      assert::are_equal(flat_style::standard, check_box.flat_style(), csf_);
      assert::are_equal(image::empty, check_box.image(), csf_);
      assert::are_equal(content_alignment::middle_center, check_box.image_align(), csf_);
      assert::are_equal(-1, check_box.image_index(), csf_);
      assert::are_equal(image_list::empty, check_box.image_list(), csf_);
      assert::are_equal(content_alignment::middle_left, check_box.text_align(), csf_);

      assert::are_equal(check_state::unchecked, check_box.check_state(), csf_);
      assert::is_false(check_box.checked(), csf_);
      assert::is_false(check_box.three_state(), csf_);
    }

    void test_method_(create_with_parent_text_and_three_state) {
      auto form = forms::form::create();
      auto check_box = forms::check_box::create(form, "new text", true);
      assert::are_equal(anchor_styles::left | anchor_styles::top, check_box.anchor(), csf_);
      assert::are_equal(drawing::point::empty, check_box.auto_scroll_point(), csf_);
      assert::is_false(check_box.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), check_box.back_color(), csf_);
      assert::are_equal(drawing::image::empty, check_box.background_image(), csf_);
      assert::are_equal(image_layout::tile, check_box.background_image_layout(), csf_);
      assert::is_false(check_box.can_focus(), csf_);
      assert::is_true(check_box.can_raise_events(), csf_);
      assert::is_true(check_box.can_select(), csf_);
      assert::are_equal("Gammasoft", check_box.company_name(), csf_);
      assert::is_null(check_box.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, check_box.control_appearance(), csf_);
      assert::is_empty(check_box.controls(), csf_);
      assert::is_true(check_box.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), check_box.cursor(), csf_);
      assert::are_equal(forms::dock_style::none, check_box.dock(), csf_);
      assert::is_false(check_box.double_buffered(), csf_);
      assert::is_true(check_box.enabled(), csf_);
      assert::is_false(check_box.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), check_box.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), check_box.fore_color(), csf_);
      assert::is_not_zero(check_box.handle(), csf_);
      assert::is_false(check_box.invoke_required(), csf_);
      assert::is_true(check_box.is_handle_created(), csf_);
      assert::is_zero(check_box.left(), csf_);
      assert::are_equal(drawing::point::empty, check_box.location(), csf_);
      assert::are_equal(forms::padding(3), check_box.margin(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_size(), csf_);
      assert::is_not_zero(check_box.native_handle(), csf_);
      assert::is_empty(check_box.name(), csf_);
      assert::are_equal(forms::padding(0), check_box.padding(), csf_);
      assert::are_same(form, check_box.parent().value().get(), csf_);
      assert::are_equal("xtd", check_box.product_name(), csf_);
      assert::is_not_zero(check_box.region().handle(), csf_);
      assert::is_empty(check_box.style_sheet().theme().name(), csf_);
      assert::is_true(check_box.tab_stop(), csf_);
      assert::is_false(check_box.tag().has_value(), csf_);
      assert::are_equal("new text", check_box.text(), csf_);
      assert::is_not_zero(check_box.toolkit_handle(), csf_);
      assert::is_zero(check_box.top(), csf_);
      assert::are_same(form, check_box.top_level_control().value().get(), csf_);
      assert::is_true(check_box.visible(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
      
      assert::is_false(check_box.auto_ellipsis(), csf_);
      assert::are_equal(flat_button_appearance(), check_box.flat_appearance(), csf_);
      assert::are_equal(flat_style::standard, check_box.flat_style(), csf_);
      assert::are_equal(image::empty, check_box.image(), csf_);
      assert::are_equal(content_alignment::middle_center, check_box.image_align(), csf_);
      assert::are_equal(-1, check_box.image_index(), csf_);
      assert::are_equal(image_list::empty, check_box.image_list(), csf_);
      assert::are_equal(content_alignment::middle_left, check_box.text_align(), csf_);
      
      assert::are_equal(check_state::unchecked, check_box.check_state(), csf_);
      assert::is_false(check_box.checked(), csf_);
      assert::is_true(check_box.three_state(), csf_);
    }

    void test_method_(create_with_parent_text_three_state_and_check_state) {
      auto form = forms::form::create();
      auto check_box = forms::check_box::create(form, "new text", true, check_state::checked);
      assert::are_equal(anchor_styles::left | anchor_styles::top, check_box.anchor(), csf_);
      assert::are_equal(drawing::point::empty, check_box.auto_scroll_point(), csf_);
      assert::is_false(check_box.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), check_box.back_color(), csf_);
      assert::are_equal(drawing::image::empty, check_box.background_image(), csf_);
      assert::are_equal(image_layout::tile, check_box.background_image_layout(), csf_);
      assert::is_false(check_box.can_focus(), csf_);
      assert::is_true(check_box.can_raise_events(), csf_);
      assert::is_true(check_box.can_select(), csf_);
      assert::are_equal("Gammasoft", check_box.company_name(), csf_);
      assert::is_null(check_box.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, check_box.control_appearance(), csf_);
      assert::is_empty(check_box.controls(), csf_);
      assert::is_true(check_box.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), check_box.cursor(), csf_);
      assert::are_equal(forms::dock_style::none, check_box.dock(), csf_);
      assert::is_false(check_box.double_buffered(), csf_);
      assert::is_true(check_box.enabled(), csf_);
      assert::is_false(check_box.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), check_box.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), check_box.fore_color(), csf_);
      assert::is_not_zero(check_box.handle(), csf_);
      assert::is_false(check_box.invoke_required(), csf_);
      assert::is_true(check_box.is_handle_created(), csf_);
      assert::is_zero(check_box.left(), csf_);
      assert::are_equal(drawing::point::empty, check_box.location(), csf_);
      assert::are_equal(forms::padding(3), check_box.margin(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_size(), csf_);
      assert::is_not_zero(check_box.native_handle(), csf_);
      assert::is_empty(check_box.name(), csf_);
      assert::are_equal(forms::padding(0), check_box.padding(), csf_);
      assert::are_same(form, check_box.parent().value().get(), csf_);
      assert::are_equal("xtd", check_box.product_name(), csf_);
      assert::is_not_zero(check_box.region().handle(), csf_);
      assert::is_empty(check_box.style_sheet().theme().name(), csf_);
      assert::is_true(check_box.tab_stop(), csf_);
      assert::is_false(check_box.tag().has_value(), csf_);
      assert::are_equal("new text", check_box.text(), csf_);
      assert::is_not_zero(check_box.toolkit_handle(), csf_);
      assert::is_zero(check_box.top(), csf_);
      assert::are_same(form, check_box.top_level_control().value().get(), csf_);
      assert::is_true(check_box.visible(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
      
      assert::is_false(check_box.auto_ellipsis(), csf_);
      assert::are_equal(flat_button_appearance(), check_box.flat_appearance(), csf_);
      assert::are_equal(flat_style::standard, check_box.flat_style(), csf_);
      assert::are_equal(image::empty, check_box.image(), csf_);
      assert::are_equal(content_alignment::middle_center, check_box.image_align(), csf_);
      assert::are_equal(-1, check_box.image_index(), csf_);
      assert::are_equal(image_list::empty, check_box.image_list(), csf_);
      assert::are_equal(content_alignment::middle_left, check_box.text_align(), csf_);
      
      assert::are_equal(check_state::checked, check_box.check_state(), csf_);
      assert::is_true(check_box.checked(), csf_);
      assert::is_true(check_box.three_state(), csf_);
    }

    void test_method_(create_with_parent_text_three_state_check_state_and_location) {
      auto form = forms::form::create();
      auto check_box = forms::check_box::create(form, "new text", true, check_state::checked, {10, 20});
      assert::are_equal(anchor_styles::left | anchor_styles::top, check_box.anchor(), csf_);
      assert::are_equal(drawing::point::empty, check_box.auto_scroll_point(), csf_);
      assert::is_false(check_box.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), check_box.back_color(), csf_);
      assert::are_equal(drawing::image::empty, check_box.background_image(), csf_);
      assert::are_equal(image_layout::tile, check_box.background_image_layout(), csf_);
      assert::is_false(check_box.can_focus(), csf_);
      assert::is_true(check_box.can_raise_events(), csf_);
      assert::is_true(check_box.can_select(), csf_);
      assert::are_equal("Gammasoft", check_box.company_name(), csf_);
      assert::is_null(check_box.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, check_box.control_appearance(), csf_);
      assert::is_empty(check_box.controls(), csf_);
      assert::is_true(check_box.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), check_box.cursor(), csf_);
      assert::are_equal(forms::dock_style::none, check_box.dock(), csf_);
      assert::is_false(check_box.double_buffered(), csf_);
      assert::is_true(check_box.enabled(), csf_);
      assert::is_false(check_box.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), check_box.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), check_box.fore_color(), csf_);
      assert::is_not_zero(check_box.handle(), csf_);
      assert::is_false(check_box.invoke_required(), csf_);
      assert::is_true(check_box.is_handle_created(), csf_);
      assert::are_equal(10, check_box.left(), csf_);
      assert::are_equal(drawing::point {10, 20}, check_box.location(), csf_);
      assert::are_equal(forms::padding(3), check_box.margin(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_size(), csf_);
      assert::is_not_zero(check_box.native_handle(), csf_);
      assert::is_empty(check_box.name(), csf_);
      assert::are_equal(forms::padding(0), check_box.padding(), csf_);
      assert::are_same(form, check_box.parent().value().get(), csf_);
      assert::are_equal("xtd", check_box.product_name(), csf_);
      assert::is_not_zero(check_box.region().handle(), csf_);
      assert::is_empty(check_box.style_sheet().theme().name(), csf_);
      assert::is_true(check_box.tab_stop(), csf_);
      assert::is_false(check_box.tag().has_value(), csf_);
      assert::are_equal("new text", check_box.text(), csf_);
      assert::is_not_zero(check_box.toolkit_handle(), csf_);
      assert::are_equal(20, check_box.top(), csf_);
      assert::are_same(form, check_box.top_level_control().value().get(), csf_);
      assert::is_true(check_box.visible(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
      
      assert::is_false(check_box.auto_ellipsis(), csf_);
      assert::are_equal(flat_button_appearance(), check_box.flat_appearance(), csf_);
      assert::are_equal(flat_style::standard, check_box.flat_style(), csf_);
      assert::are_equal(image::empty, check_box.image(), csf_);
      assert::are_equal(content_alignment::middle_center, check_box.image_align(), csf_);
      assert::are_equal(-1, check_box.image_index(), csf_);
      assert::are_equal(image_list::empty, check_box.image_list(), csf_);
      assert::are_equal(content_alignment::middle_left, check_box.text_align(), csf_);
      
      assert::are_equal(check_state::checked, check_box.check_state(), csf_);
      assert::is_true(check_box.checked(), csf_);
      assert::is_true(check_box.three_state(), csf_);
    }

    void test_method_(create_with_parent_text_three_state_check_state_location_and_size) {
      auto form = forms::form::create();
      auto check_box = forms::check_box::create(form, "new text", true, check_state::checked, {10, 20}, {30, 40});
      assert::are_equal(anchor_styles::left | anchor_styles::top, check_box.anchor(), csf_);
      assert::are_equal(drawing::point::empty, check_box.auto_scroll_point(), csf_);
      assert::is_false(check_box.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), check_box.back_color(), csf_);
      assert::are_equal(drawing::image::empty, check_box.background_image(), csf_);
      assert::are_equal(image_layout::tile, check_box.background_image_layout(), csf_);
      assert::is_false(check_box.can_focus(), csf_);
      assert::is_true(check_box.can_raise_events(), csf_);
      assert::is_true(check_box.can_select(), csf_);
      assert::are_equal("Gammasoft", check_box.company_name(), csf_);
      assert::is_null(check_box.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, check_box.control_appearance(), csf_);
      assert::is_empty(check_box.controls(), csf_);
      assert::is_true(check_box.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), check_box.cursor(), csf_);
      assert::are_equal(forms::dock_style::none, check_box.dock(), csf_);
      assert::is_false(check_box.double_buffered(), csf_);
      assert::is_true(check_box.enabled(), csf_);
      assert::is_false(check_box.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), check_box.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), check_box.fore_color(), csf_);
      assert::is_not_zero(check_box.handle(), csf_);
      assert::are_equal(40, check_box.height(), csf_);
      assert::is_false(check_box.invoke_required(), csf_);
      assert::is_true(check_box.is_handle_created(), csf_);
      assert::are_equal(10, check_box.left(), csf_);
      assert::are_equal(drawing::point {10, 20}, check_box.location(), csf_);
      assert::are_equal(forms::padding(3), check_box.margin(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, check_box.minimum_size(), csf_);
      assert::is_not_zero(check_box.native_handle(), csf_);
      assert::is_empty(check_box.name(), csf_);
      assert::are_equal(forms::padding(0), check_box.padding(), csf_);
      assert::are_same(form, check_box.parent().value().get(), csf_);
      assert::are_equal("xtd", check_box.product_name(), csf_);
      assert::is_not_zero(check_box.region().handle(), csf_);
      assert::are_equal(drawing::size {30, 40}, check_box.size(), csf_);
      assert::is_empty(check_box.style_sheet().theme().name(), csf_);
      assert::is_true(check_box.tab_stop(), csf_);
      assert::is_false(check_box.tag().has_value(), csf_);
      assert::are_equal("new text", check_box.text(), csf_);
      assert::is_not_zero(check_box.toolkit_handle(), csf_);
      assert::are_equal(20, check_box.top(), csf_);
      assert::are_same(form, check_box.top_level_control().value().get(), csf_);
      assert::is_true(check_box.visible(), csf_);
      assert::are_equal(30, check_box.width(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
      
      assert::is_false(check_box.auto_ellipsis(), csf_);
      assert::are_equal(flat_button_appearance(), check_box.flat_appearance(), csf_);
      assert::are_equal(flat_style::standard, check_box.flat_style(), csf_);
      assert::are_equal(image::empty, check_box.image(), csf_);
      assert::are_equal(content_alignment::middle_center, check_box.image_align(), csf_);
      assert::are_equal(-1, check_box.image_index(), csf_);
      assert::are_equal(image_list::empty, check_box.image_list(), csf_);
      assert::are_equal(content_alignment::middle_left, check_box.text_align(), csf_);
      
      assert::are_equal(check_state::checked, check_box.check_state(), csf_);
      assert::is_true(check_box.checked(), csf_);
      assert::is_true(check_box.three_state(), csf_);
    }

    void test_method_(set_client_size) {
      form form;
      check_box_for_test check_box;
      check_box.parent(form);
      check_box.client_size({100, 50});
      assert::are_equal(drawing::size(100, 50), check_box.client_size(), csf_);
    }
    
    void test_method_(set_size) {
      form form;
      check_box_for_test check_box;
      check_box.parent(form);
      check_box.size({100, 50});
      assert::are_equal(drawing::size(100, 50), check_box.size(), csf_);
    }
  };
}
