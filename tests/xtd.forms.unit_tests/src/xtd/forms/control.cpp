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
      control control;
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

    void test_method_(set_anchor_without_parent) {
      control control;
      control.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
      assert::are_equal(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom, control.anchor(), csf_);
    }
    
    void test_method_(set_anchor_with_parent) {
      forms::form form;
      control control;
      control.parent(form);
      control.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
      assert::are_equal(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom, control.anchor(), csf_);
    }
    
    void test_method_(set_auto_size_without_parent) {
      control control;
      control.auto_size(true);
      assert::is_true(control.auto_size(), csf_);
    }
    
    void test_method_(set_auto_size_with_parent) {
      forms::form form;
      control control;
      control.parent(form);
      control.auto_size(true);
      assert::is_true(control.auto_size(), csf_);
    }
    
    void test_method_(set_back_color_without_parent) {
      control control;
      control.back_color(color::blue);
      assert::are_equal(color::blue, control.back_color(), csf_);
    }
    
    void test_method_(set_back_color_with_parent) {
      forms::form form;
      control control;
      control.parent(form);
      control.back_color(color::blue);
      assert::are_equal(color::blue, control.back_color(), csf_);
    }
    
    void test_method_(reset_back_color_without_parent) {
      control control;
      control.back_color(color::blue);
      assert::are_equal(color::blue, control.back_color(), csf_);
      control.back_color(nullptr);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.back_color(), csf_);
    }
    
    void test_method_(reset_back_color_with_parent) {
      forms::form form;
      control control;
      control.parent(form);
      control.back_color(color::blue);
      assert::are_equal(color::blue, control.back_color(), csf_);
      control.back_color(nullptr);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.back_color(), csf_);
    }
    
    void test_method_(set_background_image_without_parent) {
      control control;
      image img = system_images::from_name("xtd");
      control.background_image(img);
      assert::are_equal(img, control.background_image(), csf_);
    }
    
    void test_method_(set_background_image_with_parent) {
      forms::form form;
      control control;
      control.parent(form);
      image img = system_images::from_name("xtd");
      control.background_image(img);
      assert::are_equal(img, control.background_image(), csf_);
    }

    void test_method_(create_control_without_parent) {
      control control;
      assert::throws<argument_exception>([&] {control.create_control();}, csf_);
    }
    
    void test_method_(create_control_set_parent) {
      forms::form form;
      control control;
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
    
    void test_method_(create_control_and_parent_controls_push_back) {
      forms::form form;
      control control;
      form.controls().push_back(control);
      assert::are_equal(1U, form.controls().size(), csf_);
      assert::are_equal(control, form.controls()[0].get(), csf_);
   }
    
    void test_method_(create_control_with_parent_back_color) {
      forms::form form;
      control control;
      control.parent(form);
      assert::are_equal(form.back_color(), control.back_color(), csf_);
    }
    
    void test_method_(create_control_with_parent_fore_color) {
      forms::form form;
      control control;
      control.parent(form);
      assert::are_equal(form.fore_color(), control.fore_color(), csf_);
    }
    
    void test_method_(create_control_with_parent_handle) {
      forms::form form;
      control control;
      control.parent(form);
      assert::is_not_zero(control.handle(), csf_);
    }
    
    void test_method_(create_control_with_parent_parent) {
      forms::form form;
      control control;
      control.parent(form);
      assert::is_true(control.parent().has_value(), csf_);
      assert::are_equal(form, control.parent().value().get(), csf_);
    }
    
    void test_method_(change_parent_back_color) {
      forms::form form;
      control control;
      control.parent(form);
      form.back_color(color::spring_green);
      assert::are_equal(form.back_color(), control.back_color(), csf_);
    }
    
    void test_method_(change_parent_fore_color) {
      forms::form form;
      control control;
      control.parent(form);
      form.fore_color(color::spring_green);
      assert::are_equal(form.fore_color(), control.fore_color(), csf_);
    }
  };
}
