#include <xtd/forms/control.h>
#include <xtd/drawing/system_images.h>
#include <xtd/forms/form.h>
#include <xtd/xtd.tunit>

#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/class_styles.h>
#include <xtd/forms/native/window_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_control) {
  public:
    void test_method_(constructor) {
      forms::control control;
      assert::are_equal(anchor_styles::left | anchor_styles::top, control.anchor(), csf_);
      assert::are_equal(drawing::point::empty, control.auto_scroll_point(), csf_);
      assert::is_false(control.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.back_color(), csf_);
      assert::are_equal(drawing::image::empty, control.background_image(), csf_);
      assert::are_equal(image_layout::tile, control.background_image_layout(), csf_);
      assert::is_zero(control.bottom(), csf_);
      assert::are_equal(drawing::rectangle::empty, control.bounds(), csf_);
      assert::is_false(control.can_focus(), csf_);
      assert::is_true(control.can_raise_events(), csf_);
      assert::is_true(control.can_select(), csf_);
      assert::are_equal(drawing::rectangle::empty, control.client_rectangle(), csf_);
      assert::are_equal(drawing::size::empty, control.client_size(), csf_);
      assert::are_equal("Gammasoft", control.company_name(), csf_);
      assert::is_null(control.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, control.control_appearance(), csf_);
      assert::is_empty(control.controls(), csf_);
      assert::is_false(control.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), control.cursor(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.default_back_color(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), control.default_cursor(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), control.default_font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.default_fore_color(), csf_);
      assert::are_equal(drawing::size::empty, control.default_size(), csf_);
      assert::are_equal(drawing::rectangle::empty, control.display_rectangle(), csf_);
      assert::are_equal(forms::dock_style::none, control.dock(), csf_);
      assert::is_false(control.double_buffered(), csf_);
      assert::is_true(control.enabled(), csf_);
      assert::is_false(control.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), control.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.fore_color(), csf_);
      assert::is_zero(control.handle(), csf_);
      assert::is_zero(control.height(), csf_);
      assert::is_false(control.invoke_required(), csf_);
      assert::is_false(control.is_handle_created(), csf_);
      assert::is_zero(control.left(), csf_);
      assert::are_equal(drawing::point::empty, control.location(), csf_);
      assert::are_equal(forms::padding(3), control.margin(), csf_);
      assert::are_equal(drawing::size::empty, control.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, control.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, control.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, control.minimum_size(), csf_);
      assert::is_zero(control.native_handle(), csf_);
      assert::is_empty(control.name(), csf_);
      assert::are_equal(forms::padding(0), control.padding(), csf_);
      assert::is_null(control.parent(), csf_);
      assert::are_equal("xtd", control.product_name(), csf_);
      assert::is_not_zero(control.region().handle(), csf_);
      assert::is_zero(control.right(), csf_);
      assert::are_equal(drawing::size::empty, control.size(), csf_);
      assert::is_empty(control.style_sheet().theme().name(), csf_);
      assert::is_true(control.tab_stop(), csf_);
      assert::is_false(control.tag().has_value(), csf_);
      assert::is_empty(control.text(), csf_);
      assert::is_zero(control.toolkit_handle(), csf_);
      assert::is_zero(control.top(), csf_);
      assert::is_null(control.top_level_control(), csf_);
      assert::is_true(control.visible(), csf_);
      assert::is_zero(control.width(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
    }
    
    void test_method_(constructor_with_text) {
      control control("Value");
      assert::are_equal(anchor_styles::left | anchor_styles::top, control.anchor(), csf_);
      assert::are_equal(drawing::point::empty, control.auto_scroll_point(), csf_);
      assert::is_false(control.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.back_color(), csf_);
      assert::are_equal(drawing::image::empty, control.background_image(), csf_);
      assert::are_equal(image_layout::tile, control.background_image_layout(), csf_);
      assert::is_zero(control.bottom(), csf_);
      assert::are_equal(drawing::rectangle::empty, control.bounds(), csf_);
      assert::is_false(control.can_focus(), csf_);
      assert::is_true(control.can_raise_events(), csf_);
      assert::is_true(control.can_select(), csf_);
      assert::are_equal(drawing::rectangle::empty, control.client_rectangle(), csf_);
      assert::are_equal(drawing::size::empty, control.client_size(), csf_);
      assert::are_equal("Gammasoft", control.company_name(), csf_);
      assert::is_null(control.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, control.control_appearance(), csf_);
      assert::is_empty(control.controls(), csf_);
      assert::is_false(control.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), control.cursor(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.default_back_color(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), control.default_cursor(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), control.default_font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.default_fore_color(), csf_);
      assert::are_equal(drawing::size::empty, control.default_size(), csf_);
      assert::are_equal(drawing::rectangle::empty, control.display_rectangle(), csf_);
      assert::are_equal(forms::dock_style::none, control.dock(), csf_);
      assert::is_false(control.double_buffered(), csf_);
      assert::is_true(control.enabled(), csf_);
      assert::is_false(control.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), control.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.fore_color(), csf_);
      assert::is_zero(control.handle(), csf_);
      assert::is_zero(control.height(), csf_);
      assert::is_false(control.invoke_required(), csf_);
      assert::is_false(control.is_handle_created(), csf_);
      assert::is_zero(control.left(), csf_);
      assert::are_equal(drawing::point::empty, control.location(), csf_);
      assert::are_equal(forms::padding(3), control.margin(), csf_);
      assert::are_equal(drawing::size::empty, control.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, control.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, control.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, control.minimum_size(), csf_);
      assert::is_zero(control.native_handle(), csf_);
      assert::is_empty(control.name(), csf_);
      assert::are_equal(forms::padding(0), control.padding(), csf_);
      assert::is_null(control.parent(), csf_);
      assert::are_equal("xtd", control.product_name(), csf_);
      assert::is_not_zero(control.region().handle(), csf_);
      assert::is_zero(control.right(), csf_);
      assert::are_equal(drawing::size::empty, control.size(), csf_);
      assert::is_empty(control.style_sheet().theme().name(), csf_);
      assert::is_true(control.tab_stop(), csf_);
      assert::is_false(control.tag().has_value(), csf_);
      assert::are_equal("Value", control.text(), csf_);
      assert::is_zero(control.toolkit_handle(), csf_);
      assert::is_zero(control.top(), csf_);
      assert::is_null(control.top_level_control(), csf_);
      assert::is_true(control.visible(), csf_);
      assert::is_zero(control.width(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
    }
    
    void test_method_(constructor_with_parent_and_text) {
      forms::form form;
      control control(form, "Value");
      assert::are_equal(1U, form.controls().size(), csf_);
      assert::are_equal(control, form.controls()[0].get(), csf_);
      assert::are_equal(anchor_styles::left | anchor_styles::top, control.anchor(), csf_);
      assert::are_equal(drawing::point::empty, control.auto_scroll_point(), csf_);
      assert::is_false(control.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.back_color(), csf_);
      assert::are_equal(drawing::image::empty, control.background_image(), csf_);
      assert::are_equal(image_layout::tile, control.background_image_layout(), csf_);
      assert::is_zero(control.bottom(), csf_);
      assert::are_equal(drawing::rectangle::empty, control.bounds(), csf_);
      assert::is_false(control.can_focus(), csf_);
      assert::is_true(control.can_raise_events(), csf_);
      assert::is_true(control.can_select(), csf_);
      assert::are_equal(drawing::rectangle::empty, control.client_rectangle(), csf_);
      assert::are_equal(drawing::size::empty, control.client_size(), csf_);
      assert::are_equal("Gammasoft", control.company_name(), csf_);
      assert::is_null(control.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, control.control_appearance(), csf_);
      assert::is_empty(control.controls(), csf_);
      assert::is_true(control.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), control.cursor(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.default_back_color(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), control.default_cursor(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), control.default_font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.default_fore_color(), csf_);
      assert::are_equal(drawing::size::empty, control.default_size(), csf_);
      assert::are_equal(drawing::rectangle::empty, control.display_rectangle(), csf_);
      assert::are_equal(forms::dock_style::none, control.dock(), csf_);
      assert::is_false(control.double_buffered(), csf_);
      assert::is_true(control.enabled(), csf_);
      assert::is_false(control.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), control.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.fore_color(), csf_);
      assert::is_not_zero(control.handle(), csf_);
      assert::is_zero(control.height(), csf_);
      assert::is_false(control.invoke_required(), csf_);
      assert::is_true(control.is_handle_created(), csf_);
      assert::is_zero(control.left(), csf_);
      assert::are_equal(drawing::point::empty, control.location(), csf_);
      assert::are_equal(forms::padding(3), control.margin(), csf_);
      assert::are_equal(drawing::size::empty, control.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, control.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, control.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, control.minimum_size(), csf_);
      assert::is_not_zero(control.native_handle(), csf_);
      assert::is_empty(control.name(), csf_);
      assert::are_equal(forms::padding(0), control.padding(), csf_);
      assert::are_equal(form, control.parent().value().get(), csf_);
      assert::are_equal("xtd", control.product_name(), csf_);
      assert::is_not_zero(control.region().handle(), csf_);
      assert::is_zero(control.right(), csf_);
      assert::are_equal(drawing::size::empty, control.size(), csf_);
      assert::is_empty(control.style_sheet().theme().name(), csf_);
      assert::is_true(control.tab_stop(), csf_);
      assert::is_false(control.tag().has_value(), csf_);
      assert::are_equal("Value", control.text(), csf_);
      assert::is_not_zero(control.toolkit_handle(), csf_);
      assert::is_zero(control.top(), csf_);
      assert::are_equal(form, control.top_level_control().value().get(), csf_);
      assert::is_true(control.visible(), csf_);
      assert::is_zero(control.width(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
    }
    
    void test_method_(constructor_with_text_location_and_size) {
      control control("Value", 10, 20, 100, 50);
      assert::are_equal(anchor_styles::left | anchor_styles::top, control.anchor(), csf_);
      assert::are_equal(drawing::point::empty, control.auto_scroll_point(), csf_);
      assert::is_false(control.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.back_color(), csf_);
      assert::are_equal(drawing::image::empty, control.background_image(), csf_);
      assert::are_equal(image_layout::tile, control.background_image_layout(), csf_);
      assert::are_equal(70, control.bottom(), csf_);
      assert::are_equal(drawing::rectangle(10, 20, 100, 50), control.bounds(), csf_);
      assert::is_false(control.can_focus(), csf_);
      assert::is_true(control.can_raise_events(), csf_);
      assert::is_true(control.can_select(), csf_);
      assert::are_equal(drawing::rectangle(0, 0, 100, 50), control.client_rectangle(), csf_);
      assert::are_equal(drawing::size(100, 50), control.client_size(), csf_);
      assert::are_equal("Gammasoft", control.company_name(), csf_);
      assert::is_null(control.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, control.control_appearance(), csf_);
      assert::is_empty(control.controls(), csf_);
      assert::is_false(control.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), control.cursor(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.default_back_color(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), control.default_cursor(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), control.default_font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.default_fore_color(), csf_);
      assert::are_equal(drawing::size::empty, control.default_size(), csf_);
      assert::are_equal(drawing::rectangle(0, 0, 100, 50), control.display_rectangle(), csf_);
      assert::are_equal(forms::dock_style::none, control.dock(), csf_);
      assert::is_false(control.double_buffered(), csf_);
      assert::is_true(control.enabled(), csf_);
      assert::is_false(control.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), control.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.fore_color(), csf_);
      assert::is_zero(control.handle(), csf_);
      assert::are_equal(50, control.height(), csf_);
      assert::is_false(control.invoke_required(), csf_);
      assert::is_false(control.is_handle_created(), csf_);
      assert::are_equal(10, control.left(), csf_);
      assert::are_equal(drawing::point(10, 20), control.location(), csf_);
      assert::are_equal(forms::padding(3), control.margin(), csf_);
      assert::are_equal(drawing::size::empty, control.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, control.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, control.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, control.minimum_size(), csf_);
      assert::is_zero(control.native_handle(), csf_);
      assert::is_empty(control.name(), csf_);
      assert::are_equal(forms::padding(0), control.padding(), csf_);
      assert::is_null(control.parent(), csf_);
      assert::are_equal("xtd", control.product_name(), csf_);
      assert::is_not_zero(control.region().handle(), csf_);
      assert::are_equal(110, control.right(), csf_);
      assert::are_equal(drawing::size(100, 50), control.size(), csf_);
      assert::is_empty(control.style_sheet().theme().name(), csf_);
      assert::is_true(control.tab_stop(), csf_);
      assert::is_false(control.tag().has_value(), csf_);
      assert::are_equal("Value", control.text(), csf_);
      assert::is_zero(control.toolkit_handle(), csf_);
      assert::are_equal(20, control.top(), csf_);
      assert::is_null(control.top_level_control(), csf_);
      assert::is_true(control.visible(), csf_);
      assert::are_equal(100, control.width(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
    }
    
    void test_method_(constructor_with_parent_text_location_and_size) {
      forms::form form;
      control control(form, "Value", 10, 20, 100, 50);
      assert::are_equal(1U, form.controls().size(), csf_);
      assert::are_equal(control, form.controls()[0].get(), csf_);
      assert::are_equal(anchor_styles::left | anchor_styles::top, control.anchor(), csf_);
      assert::are_equal(drawing::point::empty, control.auto_scroll_point(), csf_);
      assert::is_false(control.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.back_color(), csf_);
      assert::are_equal(drawing::image::empty, control.background_image(), csf_);
      assert::are_equal(image_layout::tile, control.background_image_layout(), csf_);
      assert::are_equal(70, control.bottom(), csf_);
      assert::are_equal(drawing::rectangle(10, 20, 100, 50), control.bounds(), csf_);
      assert::is_false(control.can_focus(), csf_);
      assert::is_true(control.can_raise_events(), csf_);
      assert::is_true(control.can_select(), csf_);
      assert::are_equal(drawing::rectangle(0, 0, 100, 50), control.client_rectangle(), csf_);
      assert::are_equal(drawing::size(100, 50), control.client_size(), csf_);
      assert::are_equal("Gammasoft", control.company_name(), csf_);
      assert::is_null(control.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, control.control_appearance(), csf_);
      assert::is_empty(control.controls(), csf_);
      assert::is_true(control.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), control.cursor(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.default_back_color(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), control.default_cursor(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), control.default_font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.default_fore_color(), csf_);
      assert::are_equal(drawing::size::empty, control.default_size(), csf_);
      assert::are_equal(drawing::rectangle(0, 0, 100, 50), control.display_rectangle(), csf_);
      assert::are_equal(forms::dock_style::none, control.dock(), csf_);
      assert::is_false(control.double_buffered(), csf_);
      assert::is_true(control.enabled(), csf_);
      assert::is_false(control.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), control.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.fore_color(), csf_);
      assert::is_not_zero(control.handle(), csf_);
      assert::are_equal(50, control.height(), csf_);
      assert::is_false(control.invoke_required(), csf_);
      assert::is_true(control.is_handle_created(), csf_);
      assert::are_equal(10, control.left(), csf_);
      assert::are_equal(drawing::point(10, 20), control.location(), csf_);
      assert::are_equal(forms::padding(3), control.margin(), csf_);
      assert::are_equal(drawing::size::empty, control.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, control.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, control.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, control.minimum_size(), csf_);
      assert::is_not_zero(control.native_handle(), csf_);
      assert::is_empty(control.name(), csf_);
      assert::are_equal(forms::padding(0), control.padding(), csf_);
      assert::are_equal(form, control.parent().value().get(), csf_);
      assert::are_equal("xtd", control.product_name(), csf_);
      assert::is_not_zero(control.region().handle(), csf_);
      assert::are_equal(110, control.right(), csf_);
      assert::are_equal(drawing::size(100, 50), control.size(), csf_);
      assert::is_empty(control.style_sheet().theme().name(), csf_);
      assert::is_true(control.tab_stop(), csf_);
      assert::is_false(control.tag().has_value(), csf_);
      assert::are_equal("Value", control.text(), csf_);
      assert::is_not_zero(control.toolkit_handle(), csf_);
      assert::are_equal(20, control.top(), csf_);
      assert::are_equal(form, control.top_level_control().value().get(), csf_);
      assert::is_true(control.visible(), csf_);
      assert::are_equal(100, control.width(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
    }
 
    void test_method_(create_control_without_parent) {
      forms::control control;
      assert::throws<argument_exception>([&] {control.create_control();}, csf_);
    }
    
    void test_method_(create_control_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      assert::are_equal(1U, form.controls().size(), csf_);
      assert::are_equal(control, form.controls()[0].get(), csf_);
      assert::are_equal(anchor_styles::left | anchor_styles::top, control.anchor(), csf_);
      assert::are_equal(drawing::point::empty, control.auto_scroll_point(), csf_);
      assert::is_false(control.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.back_color(), csf_);
      assert::are_equal(drawing::image::empty, control.background_image(), csf_);
      assert::are_equal(image_layout::tile, control.background_image_layout(), csf_);
      assert::is_zero(control.bottom(), csf_);
      assert::are_equal(drawing::rectangle::empty, control.bounds(), csf_);
      assert::is_false(control.can_focus(), csf_);
      assert::is_true(control.can_raise_events(), csf_);
      assert::is_true(control.can_select(), csf_);
      assert::are_equal(drawing::rectangle::empty, control.client_rectangle(), csf_);
      assert::are_equal(drawing::size::empty, control.client_size(), csf_);
      assert::are_equal("Gammasoft", control.company_name(), csf_);
      assert::is_null(control.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, control.control_appearance(), csf_);
      assert::is_empty(control.controls(), csf_);
      assert::is_true(control.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), control.cursor(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.default_back_color(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), control.default_cursor(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), control.default_font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.default_fore_color(), csf_);
      assert::are_equal(drawing::size::empty, control.default_size(), csf_);
      assert::are_equal(drawing::rectangle::empty, control.display_rectangle(), csf_);
      assert::are_equal(forms::dock_style::none, control.dock(), csf_);
      assert::is_false(control.double_buffered(), csf_);
      assert::is_true(control.enabled(), csf_);
      assert::is_false(control.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), control.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.fore_color(), csf_);
      assert::is_not_zero(control.handle(), csf_);
      assert::is_zero(control.height(), csf_);
      assert::is_false(control.invoke_required(), csf_);
      assert::is_true(control.is_handle_created(), csf_);
      assert::is_zero(control.left(), csf_);
      assert::are_equal(drawing::point::empty, control.location(), csf_);
      assert::are_equal(forms::padding(3), control.margin(), csf_);
      assert::are_equal(drawing::size::empty, control.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, control.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, control.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, control.minimum_size(), csf_);
      assert::is_not_zero(control.native_handle(), csf_);
      assert::is_empty(control.name(), csf_);
      assert::are_equal(forms::padding(0), control.padding(), csf_);
      assert::are_equal(form, control.parent().value().get(), csf_);
      assert::are_equal("xtd", control.product_name(), csf_);
      assert::is_not_zero(control.region().handle(), csf_);
      assert::is_zero(control.right(), csf_);
      assert::are_equal(drawing::size::empty, control.size(), csf_);
      assert::is_empty(control.style_sheet().theme().name(), csf_);
      assert::is_true(control.tab_stop(), csf_);
      assert::is_false(control.tag().has_value(), csf_);
      assert::is_empty(control.text(), csf_);
      assert::is_not_zero(control.toolkit_handle(), csf_);
      assert::is_zero(control.top(), csf_);
      assert::are_equal(form, control.top_level_control().value().get(), csf_);
      assert::is_true(control.visible(), csf_);
      assert::is_zero(control.width(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
    }

    void test_method_(create_params_default_values) {
      class custom_control : public control {
      public:
        custom_control() = default;
        using control::create_params;
      };
      custom_control control;
      
      forms::create_params cp = control.create_params();
      assert::is_empty(cp.caption(), csf_);
      assert::is_empty(cp.class_name(), csf_);
      assert::are_equal(CS_DBLCLKS, cp.class_style(), csf_);
      assert::is_zero(cp.ex_style(), csf_);
      assert::is_zero(cp.height(), csf_);
      assert::are_equal(drawing::point::empty, cp.location(), csf_);
      assert::is_zero(cp.param(), csf_);
      assert::is_zero(cp.parent(), csf_);
      assert::are_equal(WS_VISIBLE|WS_CHILD|WS_TABSTOP, cp.style(), csf_);
      assert::are_equal(drawing::size::empty, cp.size(), csf_);
      assert::is_zero(cp.width(), csf_);
      assert::is_zero(cp.x(), csf_);
      assert::is_zero(cp.y(), csf_);
    }
    
    void test_method_(create_params_enabled_false) {
      class custom_control : public control {
      public:
        custom_control() = default;
        using control::create_params;
      };
      custom_control control;
      control.enabled(false);
      
      forms::create_params cp = control.create_params();
      assert::is_empty(cp.caption(), csf_);
      assert::is_empty(cp.class_name(), csf_);
      assert::are_equal(CS_DBLCLKS, cp.class_style(), csf_);
      assert::is_zero(cp.ex_style(), csf_);
      assert::is_zero(cp.height(), csf_);
      assert::are_equal(drawing::point::empty, cp.location(), csf_);
      assert::is_zero(cp.param(), csf_);
      assert::is_zero(cp.parent(), csf_);
      assert::are_equal(WS_VISIBLE|WS_DISABLED|WS_CHILD|WS_TABSTOP, cp.style(), csf_);
      assert::are_equal(drawing::size::empty, cp.size(), csf_);
      assert::is_zero(cp.width(), csf_);
      assert::is_zero(cp.x(), csf_);
      assert::is_zero(cp.y(), csf_);
    }
    
    void test_method_(create_params_location) {
      class custom_control : public control {
      public:
        custom_control() = default;
        using control::create_params;
      };
      custom_control control;
      control.location({10, 20});
      
      forms::create_params cp = control.create_params();
      assert::is_empty(cp.caption(), csf_);
      assert::is_empty(cp.class_name(), csf_);
      assert::are_equal(CS_DBLCLKS, cp.class_style(), csf_);
      assert::is_zero(cp.ex_style(), csf_);
      assert::is_zero(cp.height(), csf_);
      assert::are_equal(drawing::point(10, 20), cp.location(), csf_);
      assert::is_zero(cp.param(), csf_);
      assert::is_zero(cp.parent(), csf_);
      assert::are_equal(WS_VISIBLE|WS_CHILD|WS_TABSTOP, cp.style(), csf_);
      assert::are_equal(drawing::size::empty, cp.size(), csf_);
      assert::is_zero(cp.width(), csf_);
      assert::are_equal(10, cp.x(), csf_);
      assert::are_equal(20, cp.y(), csf_);
    }

    void test_method_(create_params_parent) {
      class custom_control : public control {
      public:
        custom_control() = default;
        using control::create_params;
      };
      forms::form form;
      custom_control control;
      control.parent(form);
      
      forms::create_params cp = control.create_params();
      assert::is_empty(cp.caption(), csf_);
      assert::is_empty(cp.class_name(), csf_);
      assert::are_equal(CS_DBLCLKS, cp.class_style(), csf_);
      assert::is_zero(cp.ex_style(), csf_);
      assert::is_zero(cp.height(), csf_);
      assert::are_equal(drawing::point::empty, cp.location(), csf_);
      assert::is_zero(cp.param(), csf_);
      assert::are_equal(form.handle(), cp.parent(), csf_);
      assert::are_equal(WS_VISIBLE|WS_CHILD|WS_TABSTOP, cp.style(), csf_);
      assert::are_equal(drawing::size::empty, cp.size(), csf_);
      assert::is_zero(cp.width(), csf_);
      assert::is_zero(cp.x(), csf_);
      assert::is_zero(cp.y(), csf_);
    }
    
    void test_method_(create_params_size) {
      class custom_control : public control {
      public:
        custom_control() = default;
        using control::create_params;
      };
      custom_control control;
      control.size({100, 50});
      
      forms::create_params cp = control.create_params();
      assert::is_empty(cp.caption(), csf_);
      assert::is_empty(cp.class_name(), csf_);
      assert::are_equal(CS_DBLCLKS, cp.class_style(), csf_);
      assert::is_zero(cp.ex_style(), csf_);
      assert::are_equal(50, cp.height(), csf_);
      assert::are_equal(drawing::point::empty, cp.location(), csf_);
      assert::is_zero(cp.param(), csf_);
      assert::is_zero(cp.parent(), csf_);
      assert::are_equal(WS_VISIBLE|WS_CHILD|WS_TABSTOP, cp.style(), csf_);
      assert::are_equal(drawing::size(100, 50), cp.size(), csf_);
      assert::are_equal(100, cp.width(), csf_);
      assert::is_zero(cp.x(), csf_);
      assert::is_zero(cp.y(), csf_);
    }
    
    void test_method_(create_params_tab_stop_false) {
      class custom_control : public control {
      public:
        custom_control() = default;
        using control::create_params;
      };
      custom_control control;
      control.tab_stop(false);
      
      forms::create_params cp = control.create_params();
      assert::is_empty(cp.caption(), csf_);
      assert::is_empty(cp.class_name(), csf_);
      assert::are_equal(CS_DBLCLKS, cp.class_style(), csf_);
      assert::is_zero(cp.ex_style(), csf_);
      assert::is_zero(cp.height(), csf_);
      assert::are_equal(drawing::point::empty, cp.location(), csf_);
      assert::is_zero(cp.param(), csf_);
      assert::is_zero(cp.parent(), csf_);
      assert::are_equal(WS_VISIBLE|WS_CHILD, cp.style(), csf_);
      assert::are_equal(drawing::size::empty, cp.size(), csf_);
      assert::is_zero(cp.width(), csf_);
      assert::is_zero(cp.x(), csf_);
      assert::is_zero(cp.y(), csf_);
    }

    void test_method_(create_params_text) {
      class custom_control : public control {
      public:
        custom_control() = default;
        using control::create_params;
      };
      custom_control control;
      control.text("Value");
      
      forms::create_params cp = control.create_params();
      assert::are_equal("Value", cp.caption(), csf_);
      assert::is_empty(cp.class_name(), csf_);
      assert::are_equal(CS_DBLCLKS, cp.class_style(), csf_);
      assert::is_zero(cp.ex_style(), csf_);
      assert::is_zero(cp.height(), csf_);
      assert::are_equal(drawing::point::empty, cp.location(), csf_);
      assert::is_zero(cp.param(), csf_);
      assert::is_zero(cp.parent(), csf_);
      assert::are_equal(WS_CHILD|WS_TABSTOP|WS_VISIBLE, cp.style(), csf_);
      assert::are_equal(drawing::size::empty, cp.size(), csf_);
      assert::is_zero(cp.width(), csf_);
      assert::is_zero(cp.x(), csf_);
      assert::is_zero(cp.y(), csf_);
    }

    void test_method_(create_params_visible_false) {
      class custom_control : public control {
      public:
        custom_control() = default;
        using control::create_params;
      };
      custom_control control;
      control.visible(false);
      
      forms::create_params cp = control.create_params();
      assert::is_empty(cp.caption(), csf_);
      assert::is_empty(cp.class_name(), csf_);
      assert::are_equal(CS_DBLCLKS, cp.class_style(), csf_);
      assert::is_zero(cp.ex_style(), csf_);
      assert::is_zero(cp.height(), csf_);
      assert::are_equal(drawing::point::empty, cp.location(), csf_);
      assert::is_zero(cp.param(), csf_);
      assert::is_zero(cp.parent(), csf_);
      assert::are_equal(WS_CHILD|WS_TABSTOP, cp.style(), csf_);
      assert::are_equal(drawing::size::empty, cp.size(), csf_);
      assert::is_zero(cp.width(), csf_);
      assert::is_zero(cp.x(), csf_);
      assert::is_zero(cp.y(), csf_);
    }

    void test_method_(create_params_with_some_values) {
      class custom_control : public control {
      public:
        custom_control() = default;
        using control::create_params;
      };
      forms::form form;
      custom_control control;
      control.enabled(false);
      control.location({10, 20});
      control.parent(form);
      control.size({100, 50});
      control.tab_stop(false);
      control.text("Value");
      control.visible(false);
      
      forms::create_params cp = control.create_params();
      assert::are_equal("Value", cp.caption(), csf_);
      assert::is_empty(cp.class_name(), csf_);
      assert::are_equal(CS_DBLCLKS, cp.class_style(), csf_);
      assert::is_zero(cp.ex_style(), csf_);
      assert::are_equal(50, cp.height(), csf_);
      assert::are_equal(drawing::point(10, 20), cp.location(), csf_);
      assert::is_zero(cp.param(), csf_);
      assert::are_equal(form.handle(), cp.parent(), csf_);
      assert::are_equal(WS_DISABLED|WS_CHILD, cp.style(), csf_);
      assert::are_equal(drawing::size(100, 50), cp.size(), csf_);
      assert::are_equal(100, cp.width(), csf_);
      assert::are_equal(10, cp.x(), csf_);
      assert::are_equal(20, cp.y(), csf_);
    }
    
    void test_method_(set_parent_with_controls_push_back) {
      forms::form form;
      forms::control control;
      form.controls().push_back(control);
      assert::are_equal(1U, form.controls().size(), csf_);
      assert::are_equal(control, form.controls()[0].get(), csf_);
      assert::is_not_zero(control.handle(), csf_);
    }
    
    void test_method_(set_parent_with_control_set_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      assert::are_equal(1U, form.controls().size(), csf_);
      assert::are_equal(control, form.controls()[0].get(), csf_);
      assert::is_not_zero(control.handle(), csf_);
    }

    void test_method_(ambient_property_back_color) {
      forms::form form;
      forms::control control;
      control.parent(form);
      assert::are_equal(form.back_color(), control.back_color(), csf_);
    }
    
    void test_method_(ambient_property_cursor) {
      forms::form form;
      forms::control control;
      control.parent(form);
      assert::are_equal(form.cursor(), control.cursor(), csf_);
    }
    
    void test_method_(ambient_property_font) {
      forms::form form;
      forms::control control;
      control.parent(form);
      assert::are_equal(form.font(), control.font(), csf_);
    }

    void test_method_(ambient_property_fore_color) {
      forms::form form;
      forms::control control;
      control.parent(form);
      assert::are_equal(form.fore_color(), control.fore_color(), csf_);
    }

    void test_method_(ambient_property_change_parent_back_color) {
      forms::form form;
      forms::control control;
      control.parent(form);
      form.back_color(color::spring_green);
      assert::are_equal(color::spring_green, form.back_color(), csf_);
      assert::are_equal(form.back_color(), control.back_color(), csf_);
    }

    void test_method_(ambient_property_change_parent_cursor) {
      forms::form form;
      forms::control control;
      control.parent(form);
      form.cursor(cursors::cross());
      assert::are_equal(cursors::cross(), form.cursor(), csf_);
      assert::are_equal(form.cursor(), control.cursor(), csf_);
    }
    
    void test_method_(ambient_property_change_parent_font) {
      forms::form form;
      forms::control control;
      control.parent(form);
      form.font(system_fonts::tool_font());
      assert::are_equal(system_fonts::tool_font(), form.font(), csf_);
      assert::are_equal(form.font(), control.font(), csf_);
    }
    
    void test_method_(ambient_property_change_parent_fore_color) {
      forms::form form;
      forms::control control;
      control.parent(form);
      form.fore_color(color::spring_green);
      assert::are_equal(color::spring_green, form.fore_color(), csf_);
      assert::are_equal(form.fore_color(), control.fore_color(), csf_);
    }

    void test_method_(set_anchor_without_parent) {
      forms::control control;
      control.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
      assert::are_equal(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom, control.anchor(), csf_);
    }
    
    void test_method_(set_anchor_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
      assert::are_equal(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom, control.anchor(), csf_);
    }
    
    void test_method_(set_auto_size_without_parent) {
      forms::control control;
      control.auto_size(true);
      assert::is_true(control.auto_size(), csf_);
    }
    
    void test_method_(set_auto_size_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.auto_size(true);
      assert::is_true(control.auto_size(), csf_);
    }
    
    void test_method_(set_back_color_without_parent) {
      forms::control control;
      control.back_color(color::blue);
      assert::are_equal(color::blue, control.back_color(), csf_);
    }
    
    void test_method_(set_back_color_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.back_color(color::blue);
      assert::are_equal(color::blue, control.back_color(), csf_);
    }
    
    void test_method_(reset_back_color_without_parent) {
      forms::control control;
      control.back_color(color::blue);
      assert::are_equal(color::blue, control.back_color(), csf_);
      control.back_color(nullptr);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.back_color(), csf_);
    }
    
    void test_method_(reset_back_color_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.back_color(color::blue);
      assert::are_equal(color::blue, control.back_color(), csf_);
      control.back_color(nullptr);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.back_color(), csf_);
    }
    
    void test_method_(set_background_image_without_parent) {
      forms::control control;
      image img = system_images::from_name("xtd");
      control.background_image(img);
      assert::are_equal(img, control.background_image(), csf_);
    }
    
    void test_method_(set_background_image_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      image img = system_images::from_name("xtd");
      control.background_image(img);
      assert::are_equal(img, control.background_image(), csf_);
    }
    
    void test_method_(set_background_image_layout_without_parent) {
      forms::control control;
      control.background_image_layout(image_layout::zoom);
      assert::are_equal(image_layout::zoom, control.background_image_layout(), csf_);
    }
    
    void test_method_(set_background_image_layout_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.background_image_layout(image_layout::zoom);
      assert::are_equal(image_layout::zoom, control.background_image_layout(), csf_);
    }
    
    void test_method_(set_client_size_without_parent) {
      forms::control control;
      control.client_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.client_size(), csf_);
      assert::are_equal(drawing::rectangle(0, 0, 100, 50), control.client_rectangle(), csf_);
      assert::are_equal(drawing::rectangle(0, 0, 100, 50), control.display_rectangle(), csf_);
    }
    
    void test_method_(set_client_size_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.client_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.client_size(), csf_);
      assert::are_equal(drawing::rectangle(0, 0, 100, 50), control.client_rectangle(), csf_);
      assert::are_equal(drawing::rectangle(0, 0, 100, 50), control.display_rectangle(), csf_);
    }
    
    void test_method_(set_context_menu_without_parent) {
      forms::control control;
      menu_item context_menu_item1("Item1", [&] {});
      forms::context_menu context_menu1({context_menu_item1});
      control.context_menu(context_menu1);
      assert::are_same(context_menu1, control.context_menu().value().get(), csf_);
    }
    
    void test_method_(set_context_menu_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      menu_item context_menu_item1("Item1", [&] {});
      forms::context_menu context_menu1({context_menu_item1});
      control.context_menu(context_menu1);
      assert::are_same(context_menu1, control.context_menu().value().get(), csf_);
    }
    
    void test_method_(set_control_appearance_without_parent) {
      forms::control control;
      control.control_appearance(forms::control_appearance::system);
      assert::are_equal(forms::control_appearance::system, control.control_appearance(), csf_);
    }
    
    void test_method_(set_control_appearance_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.control_appearance(forms::control_appearance::system);
      assert::are_equal(forms::control_appearance::system, control.control_appearance(), csf_);
    }
    
    void test_method_(set_controls_without_parent) {
      forms::control control;
      forms::control control1;
      forms::control control2;
      forms::control control3;
      control.controls().push_back(control1);
      control.controls().push_back(control2);
      control.controls().push_back(control3);
      assert::are_equal(3U, control.controls().size(), csf_);
      assert::are_same(control1, control.controls()[0].get(), csf_);
      assert::are_same(control2, control.controls()[1].get(), csf_);
      assert::are_same(control3, control.controls()[2].get(), csf_);
      assert::is_null(control1.parent(), csf_);
      assert::is_null(control2.parent(), csf_);
      assert::is_null(control3.parent(), csf_);
    }
    
    void test_method_(set_controls_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      forms::control control1;
      forms::control control2;
      forms::control control3;
      control.controls().push_back(control1);
      control.controls().push_back(control2);
      control.controls().push_back(control3);
      assert::are_equal(3U, control.controls().size(), csf_);
      assert::are_same(control1, control.controls()[0].get(), csf_);
      assert::are_same(control2, control.controls()[1].get(), csf_);
      assert::are_same(control3, control.controls()[2].get(), csf_);
      assert::are_same(control, control1.parent().value().get(), csf_);
      assert::are_same(control, control2.parent().value().get(), csf_);
      assert::are_same(control, control3.parent().value().get(), csf_);
    }
    
    void test_method_(set_cursor_without_parent) {
      forms::control control;
      control.cursor(cursors::cross());
      assert::are_equal(cursors::cross(), control.cursor(), csf_);
    }
    
    void test_method_(set_cursor_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.cursor(cursors::cross());
      assert::are_equal(cursors::cross(), control.cursor(), csf_);
    }
    
    void test_method_(set_dock_without_parent) {
      forms::control control;
      control.dock(dock_style::fill);
      assert::are_equal(dock_style::fill, control.dock(), csf_);
    }
    
    void test_method_(set_dock_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.dock(dock_style::fill);
      assert::are_equal(dock_style::fill, control.dock(), csf_);
    }
    
    void test_method_(set_double_buffered_without_parent) {
      forms::control control;
      control.double_buffered(true);
      assert::is_true(control.double_buffered(), csf_);
    }
    
    void test_method_(set_double_buffered_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.double_buffered(true);
      assert::is_true(control.double_buffered(), csf_);
    }
    
    void test_method_(set_enabled_without_parent) {
      forms::control control;
      control.enabled(false);
      assert::is_false(control.double_buffered(), csf_);
    }
    
    void test_method_(set_enabled_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.enabled(false);
      assert::is_false(control.double_buffered(), csf_);
    }
    
    void test_method_(set_font_without_parent) {
      forms::control control;
      control.font(system_fonts::tool_font());
      assert::are_equal(system_fonts::tool_font(), control.font(), csf_);
    }
    
    void test_method_(set_font_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.font(system_fonts::tool_font());
      assert::are_equal(system_fonts::tool_font(), control.font(), csf_);
    }
    
    void test_method_(set_fore_color_without_parent) {
      forms::control control;
      control.fore_color(color::spring_green);
      assert::are_equal(color::spring_green, control.fore_color(), csf_);
    }
    
    void test_method_(set_fore_color_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.fore_color(color::spring_green);
      assert::are_equal(color::spring_green, control.fore_color(), csf_);
    }
    
    void test_method_(set_height_without_parent) {
      forms::control control;
      control.height(50);
      assert::are_equal(50, control.height(), csf_);
      assert::are_equal(drawing::size(0, 50), control.size(), csf_);
    }
    
    void test_method_(set_height_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.height(50);
      assert::are_equal(50, control.height(), csf_);
      assert::are_equal(drawing::size(0, 50), control.size(), csf_);
    }
    
    void test_method_(set_left_without_parent) {
      forms::control control;
      control.left(10);
      assert::are_equal(10, control.left(), csf_);
      assert::are_equal(drawing::point(10, 0), control.location(), csf_);
    }
    
    void test_method_(set_left_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.left(10);
      assert::are_equal(10, control.left(), csf_);
      assert::are_equal(drawing::point(10, 0), control.location(), csf_);
    }
    
    void test_method_(set_location_without_parent) {
      forms::control control;
      control.location({10, 20});
      assert::are_equal(drawing::point(10, 20), control.location(), csf_);
      assert::are_equal(10, control.left(), csf_);
      assert::are_equal(20, control.top(), csf_);
    }

    void test_method_(set_location_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.location({10, 20});
      assert::are_equal(drawing::point(10, 20), control.location(), csf_);
      assert::are_equal(10, control.left(), csf_);
      assert::are_equal(20, control.top(), csf_);
    }

    void test_method_(set_margin_without_parent) {
      forms::control control;
      control.margin(forms::padding(10));
      assert::are_equal(forms::padding(10), control.margin(), csf_);
    }
    
    void test_method_(set_margin_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.margin(forms::padding(10));
      assert::are_equal(forms::padding(10), control.margin(), csf_);
    }
    
    void test_method_(set_maximum_client_size_without_parent) {
      forms::control control;
      control.client_size({300, 300});
      control.maximum_client_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.maximum_client_size(), csf_);
      assert::are_equal(drawing::size(100, 50), control.client_size(), csf_);
    }
    
    void test_method_(set_maximum_client_size_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.client_size({300, 300});
      control.maximum_client_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.maximum_client_size(), csf_);
      assert::are_equal(drawing::size(100, 50), control.client_size(), csf_);
    }
    
    void test_method_(set_maximum_size_without_parent) {
      forms::control control;
      control.size({300, 300});
      control.maximum_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.maximum_size(), csf_);
      assert::are_equal(drawing::size(100, 50), control.size(), csf_);
    }
    
    void test_method_(set_maximum_size_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.size({300, 300});
      control.maximum_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.maximum_size(), csf_);
      assert::are_equal(drawing::size(100, 50), control.size(), csf_);
    }
    
    void test_method_(set_minimum_client_size_without_parent) {
      forms::control control;
      control.minimum_client_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.minimum_client_size(), csf_);
      assert::are_equal(drawing::size(100, 50), control.client_size(), csf_);
    }
    
    void test_method_(set_minimum_client_size_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.minimum_client_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.minimum_client_size(), csf_);
      assert::are_equal(drawing::size(100, 50), control.client_size(), csf_);
    }
    
    void test_method_(set_minimum_size_without_parent) {
      forms::control control;
      control.minimum_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.minimum_size(), csf_);
      assert::are_equal(drawing::size(100, 50), control.size(), csf_);
    }
    
    void test_method_(set_minimum_size_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.minimum_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.minimum_size(), csf_);
      assert::are_equal(drawing::size(100, 50), control.size(), csf_);
    }
    
    void test_method_(set_name_without_parent) {
      forms::control control;
      control.name("Value");
      assert::are_equal("Value", control.name(), csf_);
    }
    
    void test_method_(set_name_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.name("Value");
      assert::are_equal("Value", control.name(), csf_);
    }

    void test_method_(set_padding_without_parent) {
      forms::control control;
      control.padding(forms::padding(10));
      assert::are_equal(forms::padding(10), control.padding(), csf_);
    }
    
    void test_method_(set_padding_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      control.padding(forms::padding(10));
      assert::are_equal(forms::padding(10), control.padding(), csf_);
    }
    
    void test_method_(set_parent_without_parent) {
      forms::control control;
      forms::control control1;
      forms::control control2;
      forms::control control3;
      control1.parent(control);
      control2.parent(control);
      control3.parent(control);
      assert::are_equal(3U, control.controls().size(), csf_);
      assert::is_null(control1.parent(), csf_);
      assert::is_null(control2.parent(), csf_);
      assert::is_null(control3.parent(), csf_);
    }
    
    void test_method_(set_parent_with_parent) {
      forms::form form;
      forms::control control;
      control.parent(form);
      forms::control control1;
      forms::control control2;
      forms::control control3;
      control1.parent(control);
      control2.parent(control);
      control3.parent(control);
      assert::are_equal(3U, control.controls().size(), csf_);
      assert::are_same(control, control1.parent().value().get(), csf_);
      assert::are_same(control, control2.parent().value().get(), csf_);
      assert::are_same(control, control3.parent().value().get(), csf_);
    }

    void test_method_(on_auto_size_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_auto_size_changed_raised = false;

      protected:
        void on_auto_size_changed(const event_args& e) override {
          control::on_auto_size_changed(e);
          on_auto_size_changed_raised = true;
        };
      };
      custom_control control;
      
      control.auto_size(false);
      assert::is_false(control.on_auto_size_changed_raised, csf_);
      control.auto_size(true);
      assert::is_true(control.on_auto_size_changed_raised, csf_);
    }

    void test_method_(on_back_color_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_back_color_changed_raised = false;
        
      protected:
        void on_back_color_changed(const event_args& e) override {
          control::on_back_color_changed(e);
          on_back_color_changed_raised = true;
        };
      };
      custom_control control;
      
      control.back_color(nullptr);
      assert::is_false(control.on_back_color_changed_raised, csf_);
      control.back_color(color::spring_green);
      assert::is_true(control.on_back_color_changed_raised, csf_);
    }

    void test_method_(on_background_image_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_background_image_changed_raised = false;
        
      protected:
        void on_background_image_changed(const event_args& e) override {
          control::on_background_image_changed(e);
          on_background_image_changed_raised = true;
        };
      };
      custom_control control;
      
      control.background_image(image::empty);
      assert::is_false(control.on_background_image_changed_raised, csf_);
      control.background_image(system_images::from_name("xtd"));
      assert::is_true(control.on_background_image_changed_raised, csf_);
    }

    void test_method_(on_background_image_layout_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_background_image_layout_changed_raised = false;
        
      protected:
        void on_background_image_layout_changed(const event_args& e) override {
          control::on_background_image_layout_changed(e);
          on_background_image_layout_changed_raised = true;
        };
      };
      custom_control control;
      
      control.background_image_layout(image_layout::tile);
      assert::is_false(control.on_background_image_layout_changed_raised, csf_);
      control.background_image_layout(image_layout::zoom);
      assert::is_true(control.on_background_image_layout_changed_raised, csf_);
    }

    void test_method_(on_control_appearance_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_control_appearance_changed_raised = false;
        
      protected:
        void on_control_appearance_changed(const event_args& e) override {
          control::on_control_appearance_changed(e);
          on_control_appearance_changed_raised = true;
        };
      };
      custom_control control;
      
      control.control_appearance(forms::control_appearance::standard);
      assert::is_false(control.on_control_appearance_changed_raised, csf_);
      control.control_appearance(forms::control_appearance::system);
      assert::is_true(control.on_control_appearance_changed_raised, csf_);
    }

    void test_method_(on_client_size_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_client_size_changed_raised = false;
        
      protected:
        void on_client_size_changed(const event_args& e) override {
          control::on_client_size_changed(e);
          on_client_size_changed_raised = true;
        };
      };
      custom_control control;
      
      //control.client_size({0, 0}); // Do not activate this line because if client_size is not activated, it will be activated even for an identical value.
      assert::is_false(control.on_client_size_changed_raised, csf_);
      control.client_size({100, 50});
      assert::is_true(control.on_client_size_changed_raised, csf_);
    }

    void test_method_(on_control_added) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_control_added_raised = false;
        
      protected:
        void on_control_added(const control_event_args& e) override {
          control::on_control_added(e);
          on_control_added_raised = true;
        };
      };
      custom_control control;
      
      forms::control child_control;
      assert::is_false(control.on_control_added_raised, csf_);
      control.controls().push_back(child_control);
      assert::is_true(control.on_control_added_raised, csf_);
    }

    void test_method_(on_control_removed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_control_removed_raised = false;
        
      protected:
        void on_control_removed(const control_event_args& e) override {
          control::on_control_removed(e);
          on_control_removed_raised = true;
        };
      };
      custom_control control;
      
      forms::control child_control;
      control.controls().push_back(child_control);
      assert::is_false(control.on_control_removed_raised, csf_);
      control.controls().erase_at(0);
      assert::is_true(control.on_control_removed_raised, csf_);
    }

    void test_method_(on_create_control) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_create_control_raised = false;
        
      protected:
        void on_create_control() override {
          control::on_create_control();
          on_create_control_raised = true;
        };
      };
      custom_control control;
      
      forms::form form;
      control.parent(nullptr);
      assert::is_false(control.on_create_control_raised, csf_);
      control.parent(form);
      assert::is_true(control.on_create_control_raised, csf_);
    }

    void test_method_(on_cursor_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_cursor_changed_raised = false;
        
      protected:
        void on_cursor_changed(const event_args& e) override {
          control::on_cursor_changed(e);
          on_cursor_changed_raised = true;
        };
      };
      custom_control control;
      
      control.cursor(nullptr);
      assert::is_false(control.on_cursor_changed_raised, csf_);
      control.cursor(cursors::cross());
      assert::is_true(control.on_cursor_changed_raised, csf_);
    }

    void test_method_(on_dock_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_dock_changed_raised = false;
        
      protected:
        void on_dock_changed(const event_args& e) override {
          control::on_dock_changed(e);
          on_dock_changed_raised = true;
        };
      };
      custom_control control;
      
      control.dock(dock_style::none);
      assert::is_false(control.on_dock_changed_raised, csf_);
      control.dock(dock_style::fill);
      assert::is_true(control.on_dock_changed_raised, csf_);
    }

    void test_method_(on_enabled_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_enabled_changed_raised = false;
        
      protected:
        void on_enabled_changed(const event_args& e) override {
          control::on_enabled_changed(e);
          on_enabled_changed_raised = true;
        };
      };
      custom_control control;
      
      control.enabled(true);
      assert::is_false(control.on_enabled_changed_raised, csf_);
      control.enabled(false);
      assert::is_true(control.on_enabled_changed_raised, csf_);
    }

    void test_method_(on_fore_color_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_fore_color_changed_raised = false;
        
      protected:
        void on_fore_color_changed(const event_args& e) override {
          control::on_fore_color_changed(e);
          on_fore_color_changed_raised = true;
        };
      };
      custom_control control;
      
      control.fore_color(nullptr);
      assert::is_false(control.on_fore_color_changed_raised, csf_);
      control.fore_color(color::spring_green);
      assert::is_true(control.on_fore_color_changed_raised, csf_);
    }

    void test_method_(on_font_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_font_changed_raised = false;
        
      protected:
        void on_font_changed(const event_args& e) override {
          control::on_font_changed(e);
          on_font_changed_raised = true;
        };
      };
      custom_control control;
      
      control.font(nullptr);
      assert::is_false(control.on_font_changed_raised, csf_);
      control.font(system_fonts::tool_font());
      assert::is_true(control.on_font_changed_raised, csf_);
    }

    void test_method_(on_handle_created) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_handle_created_raised = false;
        
      protected:
        void on_handle_created(const event_args& e) override {
          control::on_handle_created(e);
          on_handle_created_raised = true;
        };
      };
      custom_control control;
      
      forms::form form;
      assert::is_false(control.on_handle_created_raised, csf_);
      control.parent(form);
      assert::is_true(control.on_handle_created_raised, csf_);
    }

    void test_method_(on_handle_destroyed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_handle_destroyed_raised = false;
        
      protected:
        void on_handle_destroyed(const event_args& e) override {
          control::on_handle_destroyed(e);
          on_handle_destroyed_raised = true;
        };
      };
      custom_control control;
      
      forms::form form;
      control.parent(form);
      assert::is_false(control.on_handle_destroyed_raised, csf_);
      control.parent(nullptr);
      assert::is_true(control.on_handle_destroyed_raised, csf_);
    }

    void test_method_(on_layout) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_layout_raised = false;
        
      protected:
        void on_layout(const event_args& e) override {
          control::on_layout(e);
          on_layout_raised = true;
        };
      };
      custom_control control;
      
      forms::form form;
      control.parent(form);
      control.on_layout_raised = false;
      assert::is_false(control.on_layout_raised, csf_);
      control.perform_layout();
      assert::is_true(control.on_layout_raised, csf_);
    }

    void test_method_(on_location_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_location_changed_raised = false;
        
      protected:
        void on_location_changed(const event_args& e) override {
          control::on_location_changed(e);
          on_location_changed_raised = true;
        };
      };
      custom_control control;
      
      control.location({0, 0});
      assert::is_false(control.on_location_changed_raised, csf_);
      control.location({10, 20});
      assert::is_true(control.on_location_changed_raised, csf_);
    }

    void test_method_(on_parent_back_color_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_parent_back_color_changed_raised = false;
        
      protected:
        void on_parent_back_color_changed(const event_args& e) override {
          control::on_parent_back_color_changed(e);
          on_parent_back_color_changed_raised = true;
        };
      };
      custom_control control;
      forms::form form;
      control.parent(form);
      
      form.back_color(nullptr);
      assert::is_false(control.on_parent_back_color_changed_raised, csf_);
      form.back_color(color::spring_green);
      assert::is_true(control.on_parent_back_color_changed_raised, csf_);
    }

    void test_method_(on_parent_cursor_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_parent_cursor_changed_raised = false;
        
      protected:
        void on_parent_cursor_changed(const event_args& e) override {
          control::on_parent_cursor_changed(e);
          on_parent_cursor_changed_raised = true;
        };
      };
      custom_control control;
      forms::form form;
      control.parent(form);
      
      form.cursor(nullptr);
      assert::is_false(control.on_parent_cursor_changed_raised, csf_);
      form.cursor(cursors::cross());
      assert::is_true(control.on_parent_cursor_changed_raised, csf_);
    }

    void test_method_(on_parent_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_parent_changed_raised = false;
        
      protected:
        void on_parent_changed(const event_args& e) override {
          control::on_parent_changed(e);
          on_parent_changed_raised = true;
        };
      };
      custom_control control;
      forms::form form;
      
      control.parent(nullptr);
      assert::is_false(control.on_parent_changed_raised, csf_);
      control.parent(form);
      assert::is_true(control.on_parent_changed_raised, csf_);
    }

    void test_method_(on_parent_enabled_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_parent_enabled_changed_raised = false;
        
      protected:
        void on_parent_enabled_changed(const event_args& e) override {
          control::on_parent_enabled_changed(e);
          on_parent_enabled_changed_raised = true;
        };
      };
      custom_control control;
      forms::form form;
      control.parent(form);

      form.enabled(true);
      assert::is_false(control.on_parent_enabled_changed_raised, csf_);
      form.enabled(false);
      assert::is_true(control.on_parent_enabled_changed_raised, csf_);
    }
    
    void test_method_(on_parent_fore_color_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_parent_fore_color_changed_raised = false;
        
      protected:
        void on_parent_fore_color_changed(const event_args& e) override {
          control::on_parent_fore_color_changed(e);
          on_parent_fore_color_changed_raised = true;
        };
      };
      custom_control control;
      forms::form form;
      control.parent(form);

      form.fore_color(nullptr);
      assert::is_false(control.on_parent_fore_color_changed_raised, csf_);
      form.fore_color(color::spring_green);
      assert::is_true(control.on_parent_fore_color_changed_raised, csf_);
    }
    
    void test_method_(on_parent_font_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_parent_font_changed_raised = false;
        
      protected:
        void on_parent_font_changed(const event_args& e) override {
          control::on_parent_font_changed(e);
          on_parent_font_changed_raised = true;
        };
      };
      custom_control control;
      forms::form form;
      control.parent(form);

      form.font(nullptr);
      assert::is_false(control.on_parent_font_changed_raised, csf_);
      form.font(system_fonts::tool_font());
      assert::is_true(control.on_parent_font_changed_raised, csf_);
    }

    void test_method_(on_resize) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_resize_raised = false;
        
      protected:
        void on_resize(const event_args& e) override {
          control::on_resize(e);
          on_resize_raised = true;
        };
      };
      custom_control control;
      
      control.size({0, 0});
      assert::is_false(control.on_resize_raised, csf_);
      control.size({100, 50});
      assert::is_true(control.on_resize_raised, csf_);
    }

    void test_method_(on_region_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_region_changed_raised = false;
        
      protected:
        void on_region_changed(const event_args& e) override {
          control::on_region_changed(e);
          on_region_changed_raised = true;
        };
      };
      custom_control control;
      
      control.region(control.region());
      assert::is_false(control.on_region_changed_raised, csf_);
      control.region(xtd::drawing::region());
      assert::is_true(control.on_region_changed_raised, csf_);
    }

    void test_method_(on_size_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_size_changed_raised = false;
        
      protected:
        void on_size_changed(const event_args& e) override {
          control::on_size_changed(e);
          on_size_changed_raised = true;
        };
      };
      custom_control control;
      
      control.size({0, 0});
      assert::is_false(control.on_size_changed_raised, csf_);
      control.size({100, 50});
      assert::is_true(control.on_size_changed_raised, csf_);
    }

    void test_method_(on_tab_stop_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_tab_stop_changed_raised = false;
        
      protected:
        void on_tab_stop_changed(const event_args& e) override {
          control::on_tab_stop_changed(e);
          on_tab_stop_changed_raised = true;
        };
      };
      custom_control control;
      
      control.tab_stop(true);
      assert::is_false(control.on_tab_stop_changed_raised, csf_);
      control.tab_stop(false);
      assert::is_true(control.on_tab_stop_changed_raised, csf_);
    }

    void test_method_(on_text_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_text_changed_raised = false;
        
      protected:
        void on_text_changed(const event_args& e) override {
          control::on_text_changed(e);
          on_text_changed_raised = true;
        };
      };
      custom_control control;
      
      control.text("");
      assert::is_false(control.on_text_changed_raised, csf_);
      control.text("Value");
      assert::is_true(control.on_text_changed_raised, csf_);
    }

    void test_method_(on_visible_changed) {
      class custom_control : public control {
      public:
        custom_control() = default;
        bool on_visible_changed_raised = false;
        
      protected:
        void on_visible_changed(const event_args& e) override {
          control::on_visible_changed(e);
          on_visible_changed_raised = true;
        };
      };
      custom_control control;
      
      control.visible(true);
      assert::is_false(control.on_visible_changed_raised, csf_);
      control.visible(false);
      assert::is_true(control.on_visible_changed_raised, csf_);
    }
  };
}
