#include <xtd/forms/control>
#include <xtd/drawing/system_images>
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/diagnostics/debugger>
#include <xtd/invalid_operation_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/class_styles>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(control_tests) {
    class control_for_test : public control {
    public:
      control_for_test() = default;
      explicit control_for_test(const xtd::ustring& text) : control(text) {}
      control_for_test(const control& parent, const xtd::ustring& text) : control(parent, text) {}
      control_for_test(const xtd::ustring& text, int32 left, int32 top, int32 width, int32 height) : control(text, left, top, width, height) {}
      control_for_test(const control& parent, const xtd::ustring& text, int32 left, int32 top, int32 width, int32 height) : control(parent, text, left, top, width, height) {}
      
      using control::default_back_color;
      using control::default_cursor;
      using control::default_font;
      using control::default_fore_color;
      using control::default_size;
      
      using control::create_params;
      
      using control::create;
      static control_for_test create(const xtd::ustring& text, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {
        control_for_test item;
        item.text(text);
        if (location != drawing::point {-1, -1}) item.location(location);
        if (size != drawing::size {-1, -1}) item.size(size);
        item.name(name);
        return item;
      }
      static control_for_test create(const control& parent, const xtd::ustring& text, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string) {
        control_for_test item;
        item.parent(parent);
        item.text(text);
        if (location != drawing::point {-1, -1}) item.location(location);
        if (size != drawing::size {-1, -1}) item.size(size);
        item.name(name);
        return item;
      }
    };
    
    void test_method_(constructor) {
      control_for_test control;
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
      control_for_test control("Value");
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
      control_for_test control(form, "Value");
      assert::are_equal(1_sz, form.controls().size(), csf_);
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
      control_for_test control("Value", 10, 20, 100, 50);
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
      control_for_test control(form, "Value", 10, 20, 100, 50);
      assert::are_equal(1_sz, form.controls().size(), csf_);
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
      control_for_test control;
      
      forms::create_params cp = control.create_params();
      assert::is_empty(cp.caption(), csf_);
      assert::is_empty(cp.class_name(), csf_);
      assert::are_equal(CS_DBLCLKS, cp.class_style(), csf_);
      assert::is_zero(cp.ex_style(), csf_);
      assert::is_zero(cp.height(), csf_);
      assert::are_equal(drawing::point::empty, cp.location(), csf_);
      assert::is_zero(cp.param(), csf_);
      assert::is_zero(cp.parent(), csf_);
      assert::are_equal(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_VISIBLE | WS_TABSTOP, cp.style(), csf_);
      assert::are_equal(drawing::size::empty, cp.size(), csf_);
      assert::is_zero(cp.width(), csf_);
      assert::is_zero(cp.x(), csf_);
      assert::is_zero(cp.y(), csf_);
    }
    
    void test_method_(create_params_enabled_false) {
      control_for_test control;
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
      assert::are_equal(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_DISABLED | WS_VISIBLE | WS_TABSTOP, cp.style(), csf_);
      assert::are_equal(drawing::size::empty, cp.size(), csf_);
      assert::is_zero(cp.width(), csf_);
      assert::is_zero(cp.x(), csf_);
      assert::is_zero(cp.y(), csf_);
    }
    
    void test_method_(create_params_location) {
      control_for_test control;
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
      assert::are_equal(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_VISIBLE | WS_TABSTOP, cp.style(), csf_);
      assert::are_equal(drawing::size::empty, cp.size(), csf_);
      assert::is_zero(cp.width(), csf_);
      assert::are_equal(10, cp.x(), csf_);
      assert::are_equal(20, cp.y(), csf_);
    }
    
    void test_method_(create_params_parent) {
      forms::form form;
      control_for_test control;
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
      assert::are_equal(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_VISIBLE | WS_TABSTOP, cp.style(), csf_);
      assert::are_equal(drawing::size::empty, cp.size(), csf_);
      assert::is_zero(cp.width(), csf_);
      assert::is_zero(cp.x(), csf_);
      assert::is_zero(cp.y(), csf_);
    }
    
    void test_method_(create_params_size) {
      control_for_test control;
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
      assert::are_equal(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_VISIBLE | WS_TABSTOP, cp.style(), csf_);
      assert::are_equal(drawing::size(100, 50), cp.size(), csf_);
      assert::are_equal(100, cp.width(), csf_);
      assert::is_zero(cp.x(), csf_);
      assert::is_zero(cp.y(), csf_);
    }
    
    void test_method_(create_params_tab_stop_false) {
      control_for_test control;
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
      assert::are_equal(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_VISIBLE, cp.style(), csf_);
      assert::are_equal(drawing::size::empty, cp.size(), csf_);
      assert::is_zero(cp.width(), csf_);
      assert::is_zero(cp.x(), csf_);
      assert::is_zero(cp.y(), csf_);
    }
    
    void test_method_(create_params_text) {
      control_for_test control;
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
      assert::are_equal(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_VISIBLE | WS_TABSTOP, cp.style(), csf_);
      assert::are_equal(drawing::size::empty, cp.size(), csf_);
      assert::is_zero(cp.width(), csf_);
      assert::is_zero(cp.x(), csf_);
      assert::is_zero(cp.y(), csf_);
    }
    
    void test_method_(create_params_visible_false) {
      control_for_test control;
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
      assert::are_equal(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_TABSTOP, cp.style(), csf_);
      assert::are_equal(drawing::size::empty, cp.size(), csf_);
      assert::is_zero(cp.width(), csf_);
      assert::is_zero(cp.x(), csf_);
      assert::is_zero(cp.y(), csf_);
    }
    
    void test_method_(create_params_with_some_values) {
      forms::form form;
      control_for_test control;
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
      assert::are_equal(WS_CHILD | WS_CLIPSIBLINGS | WS_DISABLED | WS_CLIPCHILDREN, cp.style(), csf_);
      assert::are_equal(drawing::size(100, 50), cp.size(), csf_);
      assert::are_equal(100, cp.width(), csf_);
      assert::are_equal(10, cp.x(), csf_);
      assert::are_equal(20, cp.y(), csf_);
    }
    
    void test_method_(parent_with_controls_push_back) {
      forms::form form;
      control_for_test control;
      form.controls().push_back(control);
      assert::are_equal(1_sz, form.controls().size(), csf_);
      assert::are_equal(control, form.controls()[0].get(), csf_);
      assert::is_not_zero(control.handle(), csf_);
    }
    
    void test_method_(parent_with_control_set_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      assert::are_equal(1_sz, form.controls().size(), csf_);
      assert::are_equal(control, form.controls()[0].get(), csf_);
      assert::is_not_zero(control.handle(), csf_);
    }
    
    void test_method_(ambient_property_back_color) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      assert::are_equal(form.back_color(), control.back_color(), csf_);
    }
    
    void test_method_(ambient_property_cursor) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      assert::are_equal(form.cursor(), control.cursor(), csf_);
    }
    
    void test_method_(ambient_property_font) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      assert::are_equal(form.font(), control.font(), csf_);
    }
    
    void test_method_(ambient_property_fore_color) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      assert::are_equal(form.fore_color(), control.fore_color(), csf_);
    }
    
    void test_method_(ambient_property_change_parent_back_color) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      form.back_color(color::spring_green);
      assert::are_equal(color::spring_green, form.back_color(), csf_);
      assert::are_equal(form.back_color(), control.back_color(), csf_);
    }
    
    void test_method_(ambient_property_change_parent_cursor) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      form.cursor(cursors::cross());
      assert::are_equal(cursors::cross(), form.cursor(), csf_);
      assert::are_equal(form.cursor(), control.cursor(), csf_);
    }
    
    void test_method_(ambient_property_change_parent_font) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      form.font(system_fonts::tool_font());
      assert::are_equal(system_fonts::tool_font(), form.font(), csf_);
      assert::are_equal(form.font(), control.font(), csf_);
    }
    
    void test_method_(ambient_property_change_parent_fore_color) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      form.fore_color(color::spring_green);
      assert::are_equal(color::spring_green, form.fore_color(), csf_);
      assert::are_equal(form.fore_color(), control.fore_color(), csf_);
    }
    
    void test_method_(anchor_without_parent) {
      control_for_test control;
      control.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
      assert::are_equal(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom, control.anchor(), csf_);
    }
    
    void test_method_(anchor_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
      assert::are_equal(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom, control.anchor(), csf_);
    }
    
    void test_method_(auto_size_without_parent) {
      control_for_test control;
      control.auto_size(true);
      assert::is_true(control.auto_size(), csf_);
    }
    
    void test_method_(auto_size_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.auto_size(true);
      assert::is_true(control.auto_size(), csf_);
    }
    
    void test_method_(back_color_without_parent) {
      control_for_test control;
      control.back_color(color::blue);
      assert::are_equal(color::blue, control.back_color(), csf_);
    }
    
    void test_method_(back_color_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.back_color(color::blue);
      assert::are_equal(color::blue, control.back_color(), csf_);
    }
    
    void test_method_(back_color_nullptr__without_parent) {
      control_for_test control;
      control.back_color(color::blue);
      assert::are_equal(color::blue, control.back_color(), csf_);
      control.back_color(nullptr);
      assert::are_equal(control.default_back_color(), control.back_color(), csf_);
    }
    
    void test_method_(back_color_nullptr_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.back_color(color::blue);
      assert::are_equal(color::blue, control.back_color(), csf_);
      control.back_color(nullptr);
      assert::are_equal(control.default_back_color(), control.back_color(), csf_);
    }
    
    void test_method_(background_image_without_parent) {
      control_for_test control;
      image img = system_images::from_name("xtd");
      control.background_image(img);
      assert::are_equal(img, control.background_image(), csf_);
    }
    
    void test_method_(background_image_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      image img = system_images::from_name("xtd");
      control.background_image(img);
      assert::are_equal(img, control.background_image(), csf_);
    }
    
    void test_method_(background_image_layout_without_parent) {
      control_for_test control;
      control.background_image_layout(image_layout::zoom);
      assert::are_equal(image_layout::zoom, control.background_image_layout(), csf_);
    }
    
    void test_method_(background_image_layout_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.background_image_layout(image_layout::zoom);
      assert::are_equal(image_layout::zoom, control.background_image_layout(), csf_);
    }
    
    void test_method_(client_size_without_parent) {
      control_for_test control;
      control.client_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.client_size(), csf_);
      assert::are_equal(drawing::rectangle(0, 0, 100, 50), control.client_rectangle(), csf_);
      assert::are_equal(drawing::rectangle(0, 0, 100, 50), control.display_rectangle(), csf_);
    }
    
    void test_method_(client_size_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.client_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.client_size(), csf_);
      assert::are_equal(drawing::rectangle(0, 0, 100, 50), control.client_rectangle(), csf_);
      assert::are_equal(drawing::rectangle(0, 0, 100, 50), control.display_rectangle(), csf_);
    }
    
    void test_method_(context_menu_without_parent) {
      control_for_test control;
      menu_item context_menu_item1("Item1", [&] {});
      forms::context_menu context_menu1({context_menu_item1});
      control.context_menu(context_menu1);
      assert::are_same(context_menu1, control.context_menu().value().get(), csf_);
    }
    
    void test_method_(context_menu_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      menu_item context_menu_item1("Item1", [&] {});
      forms::context_menu context_menu1({context_menu_item1});
      control.context_menu(context_menu1);
      assert::are_same(context_menu1, control.context_menu().value().get(), csf_);
    }
    
    void test_method_(control_appearance_without_parent) {
      control_for_test control;
      control.control_appearance(forms::control_appearance::system);
      assert::are_equal(forms::control_appearance::system, control.control_appearance(), csf_);
    }
    
    void test_method_(control_appearance_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.control_appearance(forms::control_appearance::system);
      assert::are_equal(forms::control_appearance::system, control.control_appearance(), csf_);
    }
    
    void test_method_(controls_without_parent) {
      control_for_test control;
      control_for_test control1;
      control_for_test control2;
      control_for_test control3;
      control.controls().push_back(control1);
      control.controls().push_back(control2);
      control.controls().push_back(control3);
      assert::are_equal(3_sz, control.controls().size(), csf_);
      assert::are_same(control1, control.controls()[0].get(), csf_);
      assert::are_same(control2, control.controls()[1].get(), csf_);
      assert::are_same(control3, control.controls()[2].get(), csf_);
      assert::is_null(control1.parent(), csf_);
      assert::is_null(control2.parent(), csf_);
      assert::is_null(control3.parent(), csf_);
    }
    
    void test_method_(controls_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control_for_test control1;
      control_for_test control2;
      control_for_test control3;
      control.controls().push_back(control1);
      control.controls().push_back(control2);
      control.controls().push_back(control3);
      assert::are_equal(3_sz, control.controls().size(), csf_);
      assert::are_same(control1, control.controls()[0].get(), csf_);
      assert::are_same(control2, control.controls()[1].get(), csf_);
      assert::are_same(control3, control.controls()[2].get(), csf_);
      assert::are_same(control, control1.parent().value().get(), csf_);
      assert::are_same(control, control2.parent().value().get(), csf_);
      assert::are_same(control, control3.parent().value().get(), csf_);
    }
    
    void test_method_(cursor_without_parent) {
      control_for_test control;
      control.cursor(cursors::cross());
      assert::are_equal(cursors::cross(), control.cursor(), csf_);
    }
    
    void test_method_(cursor_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.cursor(cursors::cross());
      assert::are_equal(cursors::cross(), control.cursor(), csf_);
    }
    
    void test_method_(cursor_nullptr_without_parent) {
      control_for_test control;
      control.cursor(cursors::cross());
      assert::are_equal(cursors::cross(), control.cursor(), csf_);
      control.cursor(nullptr);
      assert::are_equal(control.default_cursor(), control.cursor(), csf_);
    }
    
    void test_method_(cursor_nullptr_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.cursor(cursors::cross());
      assert::are_equal(cursors::cross(), control.cursor(), csf_);
      control.cursor(nullptr);
      assert::are_equal(control.default_cursor(), control.cursor(), csf_);
    }
    
    void test_method_(dock_without_parent) {
      control_for_test control;
      control.dock(dock_style::fill);
      assert::are_equal(dock_style::fill, control.dock(), csf_);
    }
    
    void test_method_(dock_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.dock(dock_style::fill);
      assert::are_equal(dock_style::fill, control.dock(), csf_);
    }
    
    void test_method_(double_buffered_without_parent) {
      control_for_test control;
      control.double_buffered(true);
      assert::is_true(control.double_buffered(), csf_);
    }
    
    void test_method_(double_buffered_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.double_buffered(true);
      assert::is_true(control.double_buffered(), csf_);
    }
    
    void test_method_(enabled_without_parent) {
      control_for_test control;
      control.enabled(false);
      assert::is_false(control.double_buffered(), csf_);
    }
    
    void test_method_(enabled_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.enabled(false);
      assert::is_false(control.double_buffered(), csf_);
    }
    
    void test_method_(font_without_parent) {
      control_for_test control;
      control.font(system_fonts::tool_font());
      assert::are_equal(system_fonts::tool_font(), control.font(), csf_);
    }
    
    void test_method_(font_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.font(system_fonts::tool_font());
      assert::are_equal(system_fonts::tool_font(), control.font(), csf_);
    }
    
    void test_method_(font_nullptr_without_parent) {
      control_for_test control;
      control.font(system_fonts::tool_font());
      assert::are_equal(system_fonts::tool_font(), control.font(), csf_);
      control.font(nullptr);
      assert::are_equal(control.default_font(), control.font(), csf_);
    }
    
    void test_method_(font_nullptr_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.font(system_fonts::tool_font());
      assert::are_equal(system_fonts::tool_font(), control.font(), csf_);
      control.font(nullptr);
      assert::are_equal(control.default_font(), control.font(), csf_);
    }
    
    void test_method_(fore_color_without_parent) {
      control_for_test control;
      control.fore_color(color::spring_green);
      assert::are_equal(color::spring_green, control.fore_color(), csf_);
    }
    
    void test_method_(fore_color_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.fore_color(color::spring_green);
      assert::are_equal(color::spring_green, control.fore_color(), csf_);
    }
    
    void test_method_(fore_color_nullptr_without_parent) {
      control_for_test control;
      control.fore_color(color::blue);
      assert::are_equal(color::blue, control.fore_color(), csf_);
      control.fore_color(nullptr);
      assert::are_equal(control.default_fore_color(), control.fore_color(), csf_);
    }
    
    void test_method_(fore_color_nullptr_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.fore_color(color::blue);
      assert::are_equal(color::blue, control.fore_color(), csf_);
      control.fore_color(nullptr);
      assert::are_equal(control.default_fore_color(), control.fore_color(), csf_);
    }
    
    void test_method_(height_without_parent) {
      control_for_test control;
      control.height(50);
      assert::are_equal(50, control.height(), csf_);
      assert::are_equal(drawing::size(0, 50), control.size(), csf_);
    }
    
    void test_method_(height_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.height(50);
      assert::are_equal(50, control.height(), csf_);
      assert::are_equal(drawing::size(0, 50), control.size(), csf_);
    }
    
    void test_method_(left_without_parent) {
      control_for_test control;
      control.left(10);
      assert::are_equal(10, control.left(), csf_);
      assert::are_equal(drawing::point(10, 0), control.location(), csf_);
    }
    
    void test_method_(left_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.left(10);
      assert::are_equal(10, control.left(), csf_);
      assert::are_equal(drawing::point(10, 0), control.location(), csf_);
    }
    
    void test_method_(location_without_parent) {
      control_for_test control;
      control.location({10, 20});
      assert::are_equal(drawing::point(10, 20), control.location(), csf_);
      assert::are_equal(10, control.left(), csf_);
      assert::are_equal(20, control.top(), csf_);
    }
    
    void test_method_(location_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.location({10, 20});
      assert::are_equal(drawing::point(10, 20), control.location(), csf_);
      assert::are_equal(10, control.left(), csf_);
      assert::are_equal(20, control.top(), csf_);
    }
    
    void test_method_(margin_without_parent) {
      control_for_test control;
      control.margin(forms::padding(10));
      assert::are_equal(forms::padding(10), control.margin(), csf_);
    }
    
    void test_method_(margin_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.margin(forms::padding(10));
      assert::are_equal(forms::padding(10), control.margin(), csf_);
    }
    
    void test_method_(maximum_client_size_without_parent) {
      control_for_test control;
      control.client_size({300, 300});
      control.maximum_client_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.maximum_client_size(), csf_);
      assert::are_equal(drawing::size(100, 50), control.client_size(), csf_);
    }
    
    void test_method_(maximum_client_size_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.client_size({300, 300});
      control.maximum_client_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.maximum_client_size(), csf_);
      assert::are_equal(drawing::size(100, 50), control.client_size(), csf_);
    }
    
    void test_method_(maximum_size_without_parent) {
      control_for_test control;
      control.size({300, 300});
      control.maximum_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.maximum_size(), csf_);
      assert::are_equal(drawing::size(100, 50), control.size(), csf_);
    }
    
    void test_method_(maximum_size_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.size({300, 300});
      control.maximum_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.maximum_size(), csf_);
      assert::are_equal(drawing::size(100, 50), control.size(), csf_);
    }
    
    void test_method_(minimum_client_size_without_parent) {
      control_for_test control;
      control.minimum_client_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.minimum_client_size(), csf_);
      assert::are_equal(drawing::size(100, 50), control.client_size(), csf_);
    }
    
    void test_method_(minimum_client_size_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.minimum_client_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.minimum_client_size(), csf_);
      assert::are_equal(drawing::size(100, 50), control.client_size(), csf_);
    }
    
    void test_method_(minimum_size_without_parent) {
      control_for_test control;
      control.minimum_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.minimum_size(), csf_);
      assert::are_equal(drawing::size(100, 50), control.size(), csf_);
    }
    
    void test_method_(minimum_size_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.minimum_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.minimum_size(), csf_);
      assert::are_equal(drawing::size(100, 50), control.size(), csf_);
    }
    
    void test_method_(name_without_parent) {
      control_for_test control;
      control.name("Value");
      assert::are_equal("Value", control.name(), csf_);
    }
    
    void test_method_(name_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.name("Value");
      assert::are_equal("Value", control.name(), csf_);
    }
    
    void test_method_(padding_without_parent) {
      control_for_test control;
      control.padding(forms::padding(10));
      assert::are_equal(forms::padding(10), control.padding(), csf_);
    }
    
    void test_method_(padding_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.padding(forms::padding(10));
      assert::are_equal(forms::padding(10), control.padding(), csf_);
    }
    
    void test_method_(parent_without_parent) {
      control_for_test control;
      control_for_test control1;
      control_for_test control2;
      control_for_test control3;
      control1.parent(control);
      control2.parent(control);
      control3.parent(control);
      assert::are_equal(3_sz, control.controls().size(), csf_);
      assert::is_null(control1.parent(), csf_);
      assert::is_null(control2.parent(), csf_);
      assert::is_null(control3.parent(), csf_);
    }
    
    void test_method_(parent_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control_for_test control1;
      control_for_test control2;
      control_for_test control3;
      control1.parent(control);
      control2.parent(control);
      control3.parent(control);
      assert::are_equal(3_sz, control.controls().size(), csf_);
      assert::are_same(control, control1.parent().value().get(), csf_);
      assert::are_same(control, control2.parent().value().get(), csf_);
      assert::are_same(control, control3.parent().value().get(), csf_);
    }
    
    void test_method_(parent_nullptr) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control_for_test control1;
      control1.parent(control);
      assert::are_same(control, control1.parent().value().get(), csf_);
      control1.parent(nullptr);
      assert::is_null(control1.parent(), csf_);
    }
    
    void test_method_(parent_with_other_control) {
      forms::form form1;
      forms::form form2;
      control_for_test control;
      control.parent(form1);
      assert::are_equal(1_sz, form1.controls().size(), csf_);
      assert::are_equal(0_sz, form2.controls().size(), csf_);
      assert::are_same(form1, control.parent().value().get(), csf_);
      
      control.parent(form2);
      assert::are_equal(0_sz, form1.controls().size(), csf_);
      assert::are_equal(1_sz, form2.controls().size(), csf_);
      assert::are_same(form2, control.parent().value().get(), csf_);
    }
    
    void test_method_(region_without_parent) {
      control_for_test control;
      drawing::region region1;
      control.region(region1);
      assert::are_equal(region1, control.region(), csf_);
    }
    
    void test_method_(region_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      drawing::region region1;
      control.region(region1);
      assert::are_equal(region1, control.region(), csf_);
    }
    
    void test_method_(size_without_parent) {
      control_for_test control;
      control.size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.size(), csf_);
      assert::are_equal(100, control.width(), csf_);
      assert::are_equal(50, control.height(), csf_);
    }
    
    void test_method_(size_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.size(), csf_);
      assert::are_equal(100, control.width(), csf_);
      assert::are_equal(50, control.height(), csf_);
    }
    
    void test_method_(style_sheet_without_parent) {
      control_for_test control;
      style_sheets::style_sheet ss("control {"
        "  border-style: solid;"
        "  border-color: blue;"
        "}");
      control.style_sheet(ss);
      assert::are_equal(ss, control.style_sheet(), csf_);
    }
    
    void test_method_(style_sheet_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      style_sheets::style_sheet ss("control {"
        "  border-style: solid;"
        "  border-color: blue;"
        "}");
      control.style_sheet(ss);
      assert::are_equal(ss, control.style_sheet(), csf_);
    }
    
    void test_method_(tab_stop_without_parent) {
      control_for_test control;
      control.tab_stop(false);
      assert::is_false(control.tab_stop(), csf_);
    }
    
    void test_method_(tab_stop_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.tab_stop(false);
      assert::is_false(control.tab_stop(), csf_);
    }
    
    void test_method_(tag_without_parent) {
      control_for_test control;
      control.tag("my tag");
      assert::are_equal("my tag", as<ustring>(control.tag()), csf_);
    }
    
    void test_method_(tag_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.tag("my tag");
      assert::are_equal("my tag", as<ustring>(control.tag()), csf_);
    }
    
    void test_method_(text_without_parent) {
      control_for_test control;
      control.text("my text");
      assert::are_equal("my text", control.text(), csf_);
    }
    
    void test_method_(text_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.text("my text");
      assert::are_equal("my text", control.text(), csf_);
    }
    
    void test_method_(top_without_parent) {
      control_for_test control;
      control.top(20);
      assert::are_equal(20, control.top(), csf_);
      assert::are_equal(drawing::point(0, 20), control.location(), csf_);
    }
    
    void test_method_(top_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.top(20);
      assert::are_equal(20, control.top(), csf_);
      assert::are_equal(drawing::point(0, 20), control.location(), csf_);
    }
    
    void test_method_(visible_without_parent) {
      control_for_test control;
      control.visible(false);
      assert::is_false(control.visible(), csf_);
    }
    
    void test_method_(visible_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.visible(false);
      assert::is_false(control.visible(), csf_);
    }
    
    void test_method_(check_for_illegal_cross_thread_call) {
      auto previous_value = forms::control::check_for_illegal_cross_thread_calls();
      forms::control::check_for_illegal_cross_thread_calls(false);
      assert::is_false(forms::control::check_for_illegal_cross_thread_calls(), csf_);
      forms::control::check_for_illegal_cross_thread_calls(previous_value);
    }
    
    void test_method_(begin_invoke_without_parent) {
      bool invoked = false;
      control_for_test control;
      control.begin_invoke([&] {
        invoked = true;
      });
      assert::is_false(invoked, csf_);
    }
    
    void test_method_(begin_invoke_with_parent) {
      bool invoked = false;
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.begin_invoke([&] {
        invoked = true;
      });
      // The application's message loop must be running to execute begin_invoke: not testable in unit tests.
      assert::is_false(invoked, csf_);
    }
    
    void test_method_(bring_to_front_without_parent) {
      control_for_test control;
      control.bring_to_front();
      assert::is_false(control.focused(), csf_);
    }
    
    void test_method_(bring_to_front_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.bring_to_front();
      assert::is_true(control.focused(), csf_);
    }
    
    void test_method_(create_control_without_parent) {
      control_for_test control;
      assert::throws<argument_exception>([&] {control.create_control();}, csf_);
    }
    
    void test_method_(create_control_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      assert::are_equal(1_sz, form.controls().size(), csf_);
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
    
    void test_method_(create_control_on_control_already_created) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      assert::is_true(control.created(), csf_);
      assert::does_not_throw([&] {control.create_control();});
      assert::is_true(control.created(), csf_);
    }
    
    void test_method_(create_graphics_without_parent) {
      control_for_test control;
      assert::throws<invalid_operation_exception>([&] {control.create_graphics();}, csf_);
    }
    
    void test_method_(create_graphics_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      auto graphics = control.create_graphics();
      assert::is_not_zero(graphics.handle(), csf_);
    }
    
    void test_method_(destroy_control) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      assert::is_true(control.created(), csf_);
      control.destroy_control();
      assert::is_false(control.created(), csf_);
      assert::is_null(control.parent(), csf_);
    }
    
    void test_method_(focus_without_parent) {
      control_for_test control;
      assert::is_false(control.focus(), csf_);
      assert::is_false(control.focused(), csf_);
    }
    
    void test_method_(focus_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      assert::is_true(control.focus(), csf_);
      assert::is_true(control.focused(), csf_);
    }
    
    void test_method_(get_auto_size_mode) {
      control_for_test control;
      assert::are_equal(auto_size_mode::grow_and_shrink, control.get_auto_size_mode(), csf_);
    }
    
    void test_method_(get_child_index_without_parent) {
      control_for_test control;
      control_for_test control1;
      control_for_test control2;
      control_for_test control3;
      control_for_test control4;
      control.controls().push_back_range({control1, control2, control3});
      assert::are_equal(forms::control::control_collection::npos, control.get_child_index(control1.handle()), csf_);
      assert::are_equal(forms::control::control_collection::npos, control.get_child_index(control2.handle()), csf_);
      assert::are_equal(forms::control::control_collection::npos, control.get_child_index(control3.handle()), csf_);
      assert::are_equal(forms::control::control_collection::npos, control.get_child_index(control4.handle()), csf_);
    }
    
    void test_method_(get_child_index_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control_for_test control1;
      control_for_test control2;
      control_for_test control3;
      control_for_test control4;
      control.controls().push_back_range({control1, control2, control3});
      assert::are_equal(0_sz, control.get_child_index(control1.handle()), csf_);
      assert::are_equal(1_sz, control.get_child_index(control2.handle()), csf_);
      assert::are_equal(2_sz, control.get_child_index(control3.handle()), csf_);
      assert::are_equal(forms::control::control_collection::npos, control.get_child_index(control4.handle()), csf_);
    }
    
    void test_method_(hide_without_parent) {
      control_for_test control;
      control.hide();
      assert::is_false(control.visible(), csf_);
    }
    
    void test_method_(hide_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.hide();
      assert::is_false(control.visible(), csf_);
    }
    
    void test_method_(resume_layout_after_suspend_layout) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.suspend_layout();
      assert::does_not_throw([&] {control.resume_layout();}, csf_);
    }
    
    void test_method_(resume_layout_without_suspend_layout) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      assert::does_not_throw([&] {control.resume_layout();}, csf_);
    }
    
    void test_method_(show_without_parent) {
      control_for_test control;
      control.visible(false);
      control.show();
      assert::is_true(control.visible(), csf_);
    }
    
    void test_method_(show_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.visible(false);
      control.show();
      assert::is_true(control.visible(), csf_);
    }
    
    void test_method_(to_string) {
      control_for_test control;
      assert::are_equal("xtd::forms::tests::control_tests::control_for_test", control.to_string(), csf_);
    }
    
    void test_method_(to_string_with_name) {
      control_for_test control;
      control.name("my_name");
      assert::are_equal("xtd::forms::tests::control_tests::control_for_test, name: my_name", control.to_string(), csf_);
    }
    
    void test_method_(to_string_with_text) {
      control_for_test control;
      control.text("my_text");
      assert::are_equal("xtd::forms::tests::control_tests::control_for_test, text: my_text", control.to_string(), csf_);
    }
    
    void test_method_(create_with_default_arguments) {
      auto control = forms::control::create<control_for_test>();
      assert::is_null(control.parent(), csf_);
      assert::is_zero(control.handle(), csf_);
      assert::is_empty(control.text(), csf_);
      assert::are_equal(drawing::point(0, 0), control.location(), csf_);
      assert::are_equal(drawing::size(0, 0), control.size(), csf_);
      assert::is_empty(control.name(), csf_);
    }
    
    void test_method_(create_with_parent_default_arguments) {
      forms::form form;
      auto control = forms::control::create<control_for_test>(form);
      assert::are_same(form, control.parent().value().get(), csf_);
      assert::is_not_zero(control.handle(), csf_);
      assert::is_empty(control.text(), csf_);
      assert::are_equal(drawing::point(0, 0), control.location(), csf_);
      assert::are_equal(drawing::size(0, 0), control.size(), csf_);
      assert::is_empty(control.name(), csf_);
    }
    
    void test_method_(create_with_arguments) {
      auto control = forms::control::create<control_for_test>(drawing::point(10, 20), drawing::size(100, 50), "control_for_test1");
      assert::is_null(control.parent(), csf_);
      assert::is_zero(control.handle(), csf_);
      assert::is_empty(control.text(), csf_);
      assert::are_equal(drawing::point(10, 20), control.location(), csf_);
      assert::are_equal(drawing::size(100, 50), control.size(), csf_);
      assert::are_equal("control_for_test1", control.name(), csf_);
    }
    
    void test_method_(create_with_parent_and_arguments) {
      forms::form form;
      auto control = forms::control::create<control_for_test>(form, drawing::point(10, 20), drawing::size(100, 50), "control_for_test1");
      assert::are_same(form, control.parent().value().get(), csf_);
      assert::is_not_zero(control.handle(), csf_);
      assert::is_empty(control.text(), csf_);
      assert::are_equal(drawing::point(10, 20), control.location(), csf_);
      assert::are_equal(drawing::size(100, 50), control.size(), csf_);
      assert::are_equal("control_for_test1", control.name(), csf_);
    }
    
    void test_method_(create_with_text_and_default_arguments) {
      auto control = forms::control::create<control_for_test>("my_text");
      assert::is_null(control.parent(), csf_);
      assert::is_zero(control.handle(), csf_);
      assert::are_equal("my_text", control.text(), csf_);
      assert::are_equal(drawing::point(0, 0), control.location(), csf_);
      assert::are_equal(drawing::size(0, 0), control.size(), csf_);
      assert::is_empty(control.name(), csf_);
    }
    
    void test_method_(create_with_parent_text_and_default_arguments) {
      forms::form form;
      auto control = forms::control::create<control_for_test>(form, "my_text");
      assert::are_same(form, control.parent().value().get(), csf_);
      assert::is_not_zero(control.handle(), csf_);
      assert::are_equal("my_text", control.text(), csf_);
      assert::are_equal(drawing::point(0, 0), control.location(), csf_);
      assert::are_equal(drawing::size(0, 0), control.size(), csf_);
      assert::is_empty(control.name(), csf_);
    }
    
    void test_method_(create_with_text_and_arguments) {
      auto control = forms::control::create<control_for_test>("my_text", drawing::point(10, 20), drawing::size(100, 50), "control_for_test1");
      assert::is_null(control.parent(), csf_);
      assert::is_zero(control.handle(), csf_);
      assert::are_equal("my_text", control.text(), csf_);
      assert::are_equal(drawing::point(10, 20), control.location(), csf_);
      assert::are_equal(drawing::size(100, 50), control.size(), csf_);
      assert::are_equal("control_for_test1", control.name(), csf_);
    }
    
    void test_method_(create_with_parent_text_and_arguments) {
      forms::form form;
      auto control = forms::control::create<control_for_test>(form, "my_text", drawing::point(10, 20), drawing::size(100, 50), "control_for_test1");
      assert::are_same(form, control.parent().value().get(), csf_);
      assert::is_not_zero(control.handle(), csf_);
      assert::are_equal("my_text", control.text(), csf_);
      assert::are_equal(drawing::point(10, 20), control.location(), csf_);
      assert::are_equal(drawing::size(100, 50), control.size(), csf_);
      assert::are_equal("control_for_test1", control.name(), csf_);
    }
    
    void test_method_(from_child_handle) {
      forms::form form;
      control_for_test control1;
      control_for_test control2;
      control_for_test control3;
      control1.parent(form);
      control2.parent(control1);
      
      assert::is_null(forms::control::from_child_handle(form.handle()), csf_);
      assert::are_same(form, forms::control::from_child_handle(control1.handle()).value().get(), csf_);
      assert::are_same(control1, forms::control::from_child_handle(control2.handle()).value().get(), csf_);
      assert::is_null(forms::control::from_child_handle(control3.handle()), csf_);
      assert::is_null(forms::control::from_handle(1234), csf_);
    }
    
    void test_method_(from_handle) {
      forms::form form;
      control_for_test control1;
      control_for_test control2;
      control_for_test control3;
      control1.parent(form);
      control2.parent(control1);
      
      assert::are_same(form, forms::control::from_handle(form.handle()).value().get(), csf_);
      assert::are_same(control1, forms::control::from_handle(control1.handle()).value().get(), csf_);
      assert::are_same(control2, forms::control::from_handle(control2.handle()).value().get(), csf_);
      assert::is_null(forms::control::from_handle(control3.handle()), csf_);
      assert::is_null(forms::control::from_handle(1234), csf_);
    }
    
    void test_method_(control_insertion_operator) {
      forms::form form;
      control_for_test control1;
      control_for_test control2;
      
      form << control1;
      control1 << control2;
      
      assert::is_null(form.parent(), csf_);
      assert::are_same(form, control1.parent().value().get(), csf_);
      assert::are_same(control1, control2.parent().value().get(), csf_);
    }
    
    void test_method_(control_extraction_operator) {
      forms::form form;
      control_for_test control1;
      control_for_test control2;
      
      control1.parent(form);
      control2.parent(control1);
      
      assert::is_null(form.parent(), csf_);
      assert::are_same(form, control1.parent().value().get(), csf_);
      assert::are_same(control1, control2.parent().value().get(), csf_);
      
      control1 >> control2;
      form >> control1;
      
      assert::is_null(form.parent(), csf_);
      assert::is_null(control1.parent(), csf_);
      assert::is_null(control2.parent(), csf_);
    }
    
    void test_method_(auto_size_changed) {
      bool auto_size_changed_raised = false;
      control_for_test control;
      control.auto_size_changed += [&] {
        auto_size_changed_raised = true;
      };
      
      control.auto_size(false);
      assert::is_false(auto_size_changed_raised, csf_);
      control.auto_size(true);
      assert::is_true(auto_size_changed_raised, csf_);
    }
    
    void test_method_(back_color_changed) {
      bool back_color_changed_raised = false;
      control_for_test control;
      control.back_color_changed += [&] {
        back_color_changed_raised = true;
      };
      
      control.back_color(nullptr);
      assert::is_false(back_color_changed_raised, csf_);
      control.back_color(color::spring_green);
      assert::is_true(back_color_changed_raised, csf_);
    }
    
    void test_method_(background_image_changed) {
      bool background_image_changed_raised = false;
      control_for_test control;
      control.background_image_changed += [&] {
        background_image_changed_raised = true;
      };
      
      control.background_image(image::empty);
      assert::is_false(background_image_changed_raised, csf_);
      control.background_image(system_images::from_name("xtd"));
      assert::is_true(background_image_changed_raised, csf_);
    }
    
    void test_method_(background_image_layout_changed) {
      bool background_image_layout_changed_raised = false;
      control_for_test control;
      control.background_image_layout_changed += [&] {
        background_image_layout_changed_raised = true;
      };
      
      control.background_image_layout(image_layout::tile);
      assert::is_false(background_image_layout_changed_raised, csf_);
      control.background_image_layout(image_layout::zoom);
      assert::is_true(background_image_layout_changed_raised, csf_);
    }
    
    void test_method_(control_appearance_changed) {
      bool control_appearance_changed_raised = false;
      control_for_test control;
      control.control_appearance_changed += [&] {
        control_appearance_changed_raised = true;
      };
      
      control.control_appearance(forms::control_appearance::standard);
      assert::is_false(control_appearance_changed_raised, csf_);
      control.control_appearance(forms::control_appearance::system);
      assert::is_true(control_appearance_changed_raised, csf_);
    }
    
    void test_method_(client_size_changed) {
      bool client_size_changed_raised = false;
      control_for_test control;
      control.client_size_changed += [&] {
        client_size_changed_raised = true;
      };
      
      //control.client_size({0, 0}); // Do not activate this line because if client_size is not activated, it will be activated even for an identical value.
      assert::is_false(client_size_changed_raised, csf_);
      control.client_size({100, 50});
      assert::is_true(client_size_changed_raised, csf_);
    }
    
    void test_method_(control_added) {
      bool control_added_raised = false;
      control_for_test control;
      control.control_added += [&] {
        control_added_raised = true;
      };
      
      control_for_test child_control;
      assert::is_false(control_added_raised, csf_);
      control.controls().push_back(child_control);
      assert::is_true(control_added_raised, csf_);
    }
    
    void test_method_(control_removed) {
      bool control_removed_raised = false;
      control_for_test control;
      control.control_removed += [&] {
        control_removed_raised = true;
      };
      
      control_for_test child_control;
      control.controls().push_back(child_control);
      assert::is_false(control_removed_raised, csf_);
      control.controls().erase_at(0);
      assert::is_true(control_removed_raised, csf_);
    }
    
    void test_method_(cursor_changed) {
      bool cursor_changed_raised = false;
      control_for_test control;
      control.cursor_changed += [&] {
        cursor_changed_raised = true;
      };
      
      control.cursor(nullptr);
      assert::is_false(cursor_changed_raised, csf_);
      control.cursor(cursors::cross());
      assert::is_true(cursor_changed_raised, csf_);
    }
    
    void test_method_(dock_changed) {
      bool dock_changed_raised = false;
      control_for_test control;
      control.dock_changed += [&] {
        dock_changed_raised = true;
      };
      
      control.dock(dock_style::none);
      assert::is_false(dock_changed_raised, csf_);
      control.dock(dock_style::fill);
      assert::is_true(dock_changed_raised, csf_);
    }
    
    void test_method_(enabled_changed) {
      bool enabled_changed_raised = false;
      control_for_test control;
      control.enabled_changed += [&] {
        enabled_changed_raised = true;
      };
      
      control.enabled(true);
      assert::is_false(enabled_changed_raised, csf_);
      control.enabled(false);
      assert::is_true(enabled_changed_raised, csf_);
    }
    
    void test_method_(fore_color_changed) {
      bool fore_color_changed_raised = false;
      control_for_test control;
      control.fore_color_changed += [&] {
        fore_color_changed_raised = true;
      };
      
      control.fore_color(nullptr);
      assert::is_false(fore_color_changed_raised, csf_);
      control.fore_color(color::spring_green);
      assert::is_true(fore_color_changed_raised, csf_);
    }
    
    void test_method_(font_changed) {
      bool font_changed_raised = false;
      control_for_test control;
      control.font_changed += [&] {
        font_changed_raised = true;
      };
      
      control.font(nullptr);
      assert::is_false(font_changed_raised, csf_);
      control.font(system_fonts::tool_font());
      assert::is_true(font_changed_raised, csf_);
    }
    
    void test_method_(handle_created) {
      bool handle_created_raised = false;
      control_for_test control;
      control.handle_created += [&] {
        handle_created_raised = true;
      };
      
      forms::form form;
      assert::is_false(handle_created_raised, csf_);
      control.parent(form);
      assert::is_true(handle_created_raised, csf_);
    }
    
    void test_method_(handle_destroyed) {
      bool handle_destroyed_raised = false;
      control_for_test control;
      control.handle_destroyed += [&] {
        handle_destroyed_raised = true;
      };
      
      forms::form form;
      control.parent(form);
      assert::is_false(handle_destroyed_raised, csf_);
      control.parent(nullptr);
      assert::is_true(handle_destroyed_raised, csf_);
    }
    
    void test_method_(layout) {
      bool layout_raised = false;
      control_for_test control;
      control.layout += [&] {
        layout_raised = true;
      };
      
      forms::form form;
      control.parent(form);
      layout_raised = false;
      assert::is_false(layout_raised, csf_);
      control.perform_layout();
      assert::is_true(layout_raised, csf_);
      
      layout_raised = false;
      assert::is_false(layout_raised, csf_);
      control.resume_layout();
      assert::is_true(layout_raised, csf_);
    }
    
    void test_method_(location_changed) {
      bool location_changed_raised = false;
      control_for_test control;
      control.location_changed += [&] {
        location_changed_raised = true;
      };
      
      control.location({0, 0});
      assert::is_false(location_changed_raised, csf_);
      control.location({10, 20});
      assert::is_true(location_changed_raised, csf_);
    }
    
    void test_method_(parent_changed) {
      bool parent_changed_raised = false;
      control_for_test control;
      control.parent_changed += [&] {
        parent_changed_raised = true;
      };
      forms::form form;
      
      control.parent(nullptr);
      assert::is_false(parent_changed_raised, csf_);
      control.parent(form);
      assert::is_true(parent_changed_raised, csf_);
      control.parent(nullptr);
      assert::is_true(parent_changed_raised, csf_);
    }
    
    void test_method_(resize) {
      bool resize_raised = false;
      control_for_test control;
      control.resize += [&] {
        resize_raised = true;
      };
      
      control.size({0, 0});
      assert::is_false(resize_raised, csf_);
      control.size({100, 50});
      assert::is_true(resize_raised, csf_);
    }
    
    void test_method_(region_changed) {
      bool region_changed_raised = false;
      control_for_test control;
      control.region_changed += [&] {
        region_changed_raised = true;
      };
      
      control.region(control.region());
      assert::is_false(region_changed_raised, csf_);
      control.region(xtd::drawing::region());
      assert::is_true(region_changed_raised, csf_);
    }
    
    void test_method_(size_changed) {
      bool size_changed_raised = false;
      control_for_test control;
      control.size_changed += [&] {
        size_changed_raised = true;
      };
      
      control.size({0, 0});
      assert::is_false(size_changed_raised, csf_);
      control.size({100, 50});
      assert::is_true(size_changed_raised, csf_);
    }
    
    void test_method_(tab_stop_changed) {
      bool tab_stop_changed_raised = false;
      control_for_test control;
      control.tab_stop_changed += [&] {
        tab_stop_changed_raised = true;
      };
      
      control.tab_stop(true);
      assert::is_false(tab_stop_changed_raised, csf_);
      control.tab_stop(false);
      assert::is_true(tab_stop_changed_raised, csf_);
    }
    
    void test_method_(text_changed) {
      bool text_changed_raised = false;
      control_for_test control;
      control.text_changed += [&] {
        text_changed_raised = true;
      };
      
      control.text("");
      assert::is_false(text_changed_raised, csf_);
      control.text("Value");
      assert::is_true(text_changed_raised, csf_);
    }
    
    void test_method_(visible_changed) {
      bool visible_changed_raised = false;
      control_for_test control;
      control.visible_changed += [&] {
        visible_changed_raised = true;
      };
      
      control.visible(true);
      assert::is_false(visible_changed_raised, csf_);
      control.visible(false);
      assert::is_true(visible_changed_raised, csf_);
    }
    
    void test_method_(on_auto_size_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_auto_size_changed_raised = false;
        
      protected:
        void on_auto_size_changed(const event_args& e) override {
          control::on_auto_size_changed(e);
          on_auto_size_changed_raised = true;
        };
      };
      control_for_test control;
      
      control.auto_size(false);
      assert::is_false(control.on_auto_size_changed_raised, csf_);
      control.auto_size(true);
      assert::is_true(control.on_auto_size_changed_raised, csf_);
    }
    
    void test_method_(on_back_color_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_back_color_changed_raised = false;
        
      protected:
        void on_back_color_changed(const event_args& e) override {
          control::on_back_color_changed(e);
          on_back_color_changed_raised = true;
        };
      };
      control_for_test control;
      
      control.back_color(nullptr);
      assert::is_false(control.on_back_color_changed_raised, csf_);
      control.back_color(color::spring_green);
      assert::is_true(control.on_back_color_changed_raised, csf_);
    }
    
    void test_method_(on_background_image_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_background_image_changed_raised = false;
        
      protected:
        void on_background_image_changed(const event_args& e) override {
          control::on_background_image_changed(e);
          on_background_image_changed_raised = true;
        };
      };
      control_for_test control;
      
      control.background_image(image::empty);
      assert::is_false(control.on_background_image_changed_raised, csf_);
      control.background_image(system_images::from_name("xtd"));
      assert::is_true(control.on_background_image_changed_raised, csf_);
    }
    
    void test_method_(on_background_image_layout_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_background_image_layout_changed_raised = false;
        
      protected:
        void on_background_image_layout_changed(const event_args& e) override {
          control::on_background_image_layout_changed(e);
          on_background_image_layout_changed_raised = true;
        };
      };
      control_for_test control;
      
      control.background_image_layout(image_layout::tile);
      assert::is_false(control.on_background_image_layout_changed_raised, csf_);
      control.background_image_layout(image_layout::zoom);
      assert::is_true(control.on_background_image_layout_changed_raised, csf_);
    }
    
    void test_method_(on_control_appearance_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_control_appearance_changed_raised = false;
        
      protected:
        void on_control_appearance_changed(const event_args& e) override {
          control::on_control_appearance_changed(e);
          on_control_appearance_changed_raised = true;
        };
      };
      control_for_test control;
      
      control.control_appearance(forms::control_appearance::standard);
      assert::is_false(control.on_control_appearance_changed_raised, csf_);
      control.control_appearance(forms::control_appearance::system);
      assert::is_true(control.on_control_appearance_changed_raised, csf_);
    }
    
    void test_method_(on_client_size_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_client_size_changed_raised = false;
        
      protected:
        void on_client_size_changed(const event_args& e) override {
          control::on_client_size_changed(e);
          on_client_size_changed_raised = true;
        };
      };
      control_for_test control;
      
      //control.client_size({0, 0}); // Do not activate this line because if client_size is not activated, it will be activated even for an identical value.
      assert::is_false(control.on_client_size_changed_raised, csf_);
      control.client_size({100, 50});
      assert::is_true(control.on_client_size_changed_raised, csf_);
    }
    
    void test_method_(on_control_added) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_control_added_raised = false;
        
      protected:
        void on_control_added(const control_event_args& e) override {
          control::on_control_added(e);
          on_control_added_raised = true;
        };
      };
      control_for_test control;
      
      control_for_test child_control;
      assert::is_false(control.on_control_added_raised, csf_);
      control.controls().push_back(child_control);
      assert::is_true(control.on_control_added_raised, csf_);
    }
    
    void test_method_(on_control_removed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_control_removed_raised = false;
        
      protected:
        void on_control_removed(const control_event_args& e) override {
          control::on_control_removed(e);
          on_control_removed_raised = true;
        };
      };
      control_for_test control;
      
      control_for_test child_control;
      control.controls().push_back(child_control);
      assert::is_false(control.on_control_removed_raised, csf_);
      control.controls().erase_at(0);
      assert::is_true(control.on_control_removed_raised, csf_);
    }
    
    void test_method_(on_create_control) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_create_control_raised = false;
        
      protected:
        void on_create_control() override {
          control::on_create_control();
          on_create_control_raised = true;
        };
      };
      control_for_test control;
      
      forms::form form;
      control.parent(nullptr);
      assert::is_false(control.on_create_control_raised, csf_);
      control.parent(form);
      assert::is_true(control.on_create_control_raised, csf_);
    }
    
    void test_method_(on_cursor_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_cursor_changed_raised = false;
        
      protected:
        void on_cursor_changed(const event_args& e) override {
          control::on_cursor_changed(e);
          on_cursor_changed_raised = true;
        };
      };
      control_for_test control;
      
      control.cursor(nullptr);
      assert::is_false(control.on_cursor_changed_raised, csf_);
      control.cursor(cursors::cross());
      assert::is_true(control.on_cursor_changed_raised, csf_);
    }
    
    void test_method_(on_dock_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_dock_changed_raised = false;
        
      protected:
        void on_dock_changed(const event_args& e) override {
          control::on_dock_changed(e);
          on_dock_changed_raised = true;
        };
      };
      control_for_test control;
      
      control.dock(dock_style::none);
      assert::is_false(control.on_dock_changed_raised, csf_);
      control.dock(dock_style::fill);
      assert::is_true(control.on_dock_changed_raised, csf_);
    }
    
    void test_method_(on_enabled_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_enabled_changed_raised = false;
        
      protected:
        void on_enabled_changed(const event_args& e) override {
          control::on_enabled_changed(e);
          on_enabled_changed_raised = true;
        };
      };
      control_for_test control;
      
      control.enabled(true);
      assert::is_false(control.on_enabled_changed_raised, csf_);
      control.enabled(false);
      assert::is_true(control.on_enabled_changed_raised, csf_);
    }
    
    void test_method_(on_fore_color_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_fore_color_changed_raised = false;
        
      protected:
        void on_fore_color_changed(const event_args& e) override {
          control::on_fore_color_changed(e);
          on_fore_color_changed_raised = true;
        };
      };
      control_for_test control;
      
      control.fore_color(nullptr);
      assert::is_false(control.on_fore_color_changed_raised, csf_);
      control.fore_color(color::spring_green);
      assert::is_true(control.on_fore_color_changed_raised, csf_);
    }
    
    void test_method_(on_font_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_font_changed_raised = false;
        
      protected:
        void on_font_changed(const event_args& e) override {
          control::on_font_changed(e);
          on_font_changed_raised = true;
        };
      };
      control_for_test control;
      
      control.font(nullptr);
      assert::is_false(control.on_font_changed_raised, csf_);
      control.font(system_fonts::tool_font());
      assert::is_true(control.on_font_changed_raised, csf_);
    }
    
    void test_method_(on_handle_created) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_handle_created_raised = false;
        
      protected:
        void on_handle_created(const event_args& e) override {
          control::on_handle_created(e);
          on_handle_created_raised = true;
        };
      };
      control_for_test control;
      
      forms::form form;
      assert::is_false(control.on_handle_created_raised, csf_);
      control.parent(form);
      assert::is_true(control.on_handle_created_raised, csf_);
    }
    
    void test_method_(on_handle_destroyed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_handle_destroyed_raised = false;
        
      protected:
        void on_handle_destroyed(const event_args& e) override {
          control::on_handle_destroyed(e);
          on_handle_destroyed_raised = true;
        };
      };
      control_for_test control;
      
      forms::form form;
      control.parent(form);
      assert::is_false(control.on_handle_destroyed_raised, csf_);
      control.parent(nullptr);
      assert::is_true(control.on_handle_destroyed_raised, csf_);
    }
    
    void test_method_(on_layout) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_layout_raised = false;
        
      protected:
        void on_layout(const event_args& e) override {
          control::on_layout(e);
          on_layout_raised = true;
        };
      };
      control_for_test control;
      
      forms::form form;
      control.parent(form);
      control.on_layout_raised = false;
      assert::is_false(control.on_layout_raised, csf_);
      control.perform_layout();
      assert::is_true(control.on_layout_raised, csf_);
      
      control.on_layout_raised = false;
      assert::is_false(control.on_layout_raised, csf_);
      control.resume_layout();
      assert::is_true(control.on_layout_raised, csf_);
    }
    
    void test_method_(on_location_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_location_changed_raised = false;
        
      protected:
        void on_location_changed(const event_args& e) override {
          control::on_location_changed(e);
          on_location_changed_raised = true;
        };
      };
      control_for_test control;
      
      control.location({0, 0});
      assert::is_false(control.on_location_changed_raised, csf_);
      control.location({10, 20});
      assert::is_true(control.on_location_changed_raised, csf_);
    }
    
    void test_method_(on_parent_back_color_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_parent_back_color_changed_raised = false;
        
      protected:
        void on_parent_back_color_changed(const event_args& e) override {
          control::on_parent_back_color_changed(e);
          on_parent_back_color_changed_raised = true;
        };
      };
      control_for_test control;
      forms::form form;
      control.parent(form);
      
      form.back_color(nullptr);
      assert::is_false(control.on_parent_back_color_changed_raised, csf_);
      form.back_color(color::spring_green);
      assert::is_true(control.on_parent_back_color_changed_raised, csf_);
    }
    
    void test_method_(on_parent_cursor_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_parent_cursor_changed_raised = false;
        
      protected:
        void on_parent_cursor_changed(const event_args& e) override {
          control::on_parent_cursor_changed(e);
          on_parent_cursor_changed_raised = true;
        };
      };
      control_for_test control;
      forms::form form;
      control.parent(form);
      
      form.cursor(nullptr);
      assert::is_false(control.on_parent_cursor_changed_raised, csf_);
      form.cursor(cursors::cross());
      assert::is_true(control.on_parent_cursor_changed_raised, csf_);
    }
    
    void test_method_(on_parent_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_parent_changed_raised = false;
        
      protected:
        void on_parent_changed(const event_args& e) override {
          control::on_parent_changed(e);
          on_parent_changed_raised = true;
        };
      };
      control_for_test control;
      forms::form form;
      
      control.parent(nullptr);
      assert::is_false(control.on_parent_changed_raised, csf_);
      control.parent(form);
      assert::is_true(control.on_parent_changed_raised, csf_);
      control.parent(nullptr);
      assert::is_true(control.on_parent_changed_raised, csf_);
    }
    
    void test_method_(on_parent_enabled_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_parent_enabled_changed_raised = false;
        
      protected:
        void on_parent_enabled_changed(const event_args& e) override {
          control::on_parent_enabled_changed(e);
          on_parent_enabled_changed_raised = true;
        };
      };
      control_for_test control;
      forms::form form;
      control.parent(form);
      
      form.enabled(true);
      assert::is_false(control.on_parent_enabled_changed_raised, csf_);
      form.enabled(false);
      assert::is_true(control.on_parent_enabled_changed_raised, csf_);
    }
    
    void test_method_(on_parent_fore_color_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_parent_fore_color_changed_raised = false;
        
      protected:
        void on_parent_fore_color_changed(const event_args& e) override {
          control::on_parent_fore_color_changed(e);
          on_parent_fore_color_changed_raised = true;
        };
      };
      control_for_test control;
      forms::form form;
      control.parent(form);
      
      form.fore_color(nullptr);
      assert::is_false(control.on_parent_fore_color_changed_raised, csf_);
      form.fore_color(color::spring_green);
      assert::is_true(control.on_parent_fore_color_changed_raised, csf_);
    }
    
    void test_method_(on_parent_font_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_parent_font_changed_raised = false;
        
      protected:
        void on_parent_font_changed(const event_args& e) override {
          control::on_parent_font_changed(e);
          on_parent_font_changed_raised = true;
        };
      };
      control_for_test control;
      forms::form form;
      control.parent(form);
      
      form.font(nullptr);
      assert::is_false(control.on_parent_font_changed_raised, csf_);
      form.font({form.font(), 32});
      assert::is_true(control.on_parent_font_changed_raised, csf_);
    }
    
    void test_method_(on_resize) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_resize_raised = false;
        
      protected:
        void on_resize(const event_args& e) override {
          control::on_resize(e);
          on_resize_raised = true;
        };
      };
      control_for_test control;
      
      control.size({0, 0});
      assert::is_false(control.on_resize_raised, csf_);
      control.size({100, 50});
      assert::is_true(control.on_resize_raised, csf_);
    }
    
    void test_method_(on_region_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_region_changed_raised = false;
        
      protected:
        void on_region_changed(const event_args& e) override {
          control::on_region_changed(e);
          on_region_changed_raised = true;
        };
      };
      control_for_test control;
      
      control.region(control.region());
      assert::is_false(control.on_region_changed_raised, csf_);
      control.region(xtd::drawing::region());
      assert::is_true(control.on_region_changed_raised, csf_);
    }
    
    void test_method_(on_size_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_size_changed_raised = false;
        
      protected:
        void on_size_changed(const event_args& e) override {
          control::on_size_changed(e);
          on_size_changed_raised = true;
        };
      };
      control_for_test control;
      
      control.size({0, 0});
      assert::is_false(control.on_size_changed_raised, csf_);
      control.size({100, 50});
      assert::is_true(control.on_size_changed_raised, csf_);
    }
    
    void test_method_(on_tab_stop_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_tab_stop_changed_raised = false;
        
      protected:
        void on_tab_stop_changed(const event_args& e) override {
          control::on_tab_stop_changed(e);
          on_tab_stop_changed_raised = true;
        };
      };
      control_for_test control;
      
      control.tab_stop(true);
      assert::is_false(control.on_tab_stop_changed_raised, csf_);
      control.tab_stop(false);
      assert::is_true(control.on_tab_stop_changed_raised, csf_);
    }
    
    void test_method_(on_text_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_text_changed_raised = false;
        
      protected:
        void on_text_changed(const event_args& e) override {
          control::on_text_changed(e);
          on_text_changed_raised = true;
        };
      };
      control_for_test control;
      
      control.text("");
      assert::is_false(control.on_text_changed_raised, csf_);
      control.text("Value");
      assert::is_true(control.on_text_changed_raised, csf_);
    }
    
    void test_method_(on_visible_changed) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_visible_changed_raised = false;
        
      protected:
        void on_visible_changed(const event_args& e) override {
          control::on_visible_changed(e);
          on_visible_changed_raised = true;
        };
      };
      control_for_test control;
      
      control.visible(true);
      assert::is_false(control.on_visible_changed_raised, csf_);
      control.visible(false);
      assert::is_true(control.on_visible_changed_raised, csf_);
    }
    
    void test_method_(recreate_handle) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        using control::recreate_handle;
      };
      forms::form form;
      control_for_test control;
      control.parent(form);
      
      auto initial_handle = control.handle();
      control.recreate_handle();
      assert::are_not_equal(initial_handle, control.handle(), csf_);
    }
  };
}
