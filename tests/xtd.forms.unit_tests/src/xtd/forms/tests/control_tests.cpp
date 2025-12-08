#include <xtd/forms/control>
#include <xtd/drawing/system_images>
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/window_messages>
#include <xtd/diagnostics/debugger>
#include <xtd/invalid_operation_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/class_styles>
#include <xtd/forms/native/window_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(control_tests) {
    class control_for_test : public control {
    public:
      control_for_test() = default;
      explicit control_for_test(const xtd::string& text) : control(text) {}
      control_for_test(const control& parent, const xtd::string& text) : control(parent, text) {}
      control_for_test(const xtd::string& text, int32 left, int32 top, int32 width, int32 height) : control(text, left, top, width, height) {}
      control_for_test(const control& parent, const xtd::string& text, int32 left, int32 top, int32 width, int32 height) : control(parent, text, left, top, width, height) {}
      
      using control::default_back_color;
      using control::default_cursor;
      using control::default_font;
      using control::default_fore_color;
      using control::default_size;
      
      using control::create_params;
      
      using control::create;
    };
    
    auto test_method_(constructor) {
      control_for_test control;
      assert::are_equal(anchor_styles::left | anchor_styles::top, control.anchor());
      assert::are_equal(drawing::point::empty, control.auto_scroll_point());
      assert::is_false(control.auto_size());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.back_color());
      assert::are_equal(drawing::image::empty, control.background_image());
      assert::are_equal(image_layout::tile, control.background_image_layout());
      assert::is_zero(control.bottom());
      assert::are_equal(drawing::rectangle::empty, control.bounds());
      assert::is_false(control.can_focus());
      assert::is_true(control.can_raise_events());
      assert::is_true(control.can_select());
      assert::are_equal(drawing::rectangle::empty, control.client_rectangle());
      assert::are_equal(drawing::size::empty, control.client_size());
      assert::are_equal("Gammasoft", control.company_name());
      assert::is_null(control.context_menu());
      assert::are_equal(forms::control_appearance::standard, control.control_appearance());
      assert::is_empty(control.controls());
      assert::is_false(control.created());
      assert::are_equal(forms::cursors::default_cursor(), control.cursor());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.default_back_color());
      assert::are_equal(forms::cursors::default_cursor(), control.default_cursor());
      assert::are_equal(drawing::system_fonts::default_font(), control.default_font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.default_fore_color());
      assert::are_equal(drawing::size::empty, control.default_size());
      assert::are_equal(drawing::rectangle::empty, control.display_rectangle());
      assert::are_equal(forms::dock_style::none, control.dock());
      assert::is_false(control.double_buffered());
      assert::is_true(control.enabled());
      assert::is_false(control.focused());
      assert::are_equal(drawing::system_fonts::default_font(), control.font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.fore_color());
      assert::is_zero(control.handle());
      assert::is_zero(control.height());
      assert::is_false(control.invoke_required());
      assert::is_false(control.is_handle_created());
      assert::is_zero(control.left());
      assert::are_equal(drawing::point::empty, control.location());
      assert::are_equal(forms::padding(3), control.margin());
      assert::are_equal(drawing::size::empty, control.maximum_client_size());
      assert::are_equal(drawing::size::empty, control.maximum_size());
      assert::are_equal(drawing::size::empty, control.minimum_client_size());
      assert::are_equal(drawing::size::empty, control.minimum_size());
      assert::is_zero(control.native_handle());
      assert::is_empty(control.name());
      assert::are_equal(forms::padding(0), control.padding());
      assert::is_null(control.parent());
      assert::are_equal("xtd", control.product_name());
      assert::is_not_zero(control.region().handle());
      assert::is_zero(control.right());
      assert::are_equal(drawing::size::empty, control.size());
      assert::is_empty(control.style_sheet().theme().name());
      assert::is_true(control.tab_stop());
      assert::is_false(control.tag().has_value());
      assert::is_empty(control.text());
      assert::is_zero(control.toolkit_handle());
      assert::is_zero(control.top());
      assert::is_null(control.top_level_control());
      assert::is_true(control.visible());
      assert::is_zero(control.width());
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls());
      assert::are_equal(keys::none, forms::control::modifier_keys());
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons());
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position());
    }
    
    auto test_method_(constructor_with_text) {
      control_for_test control("Value");
      assert::are_equal(anchor_styles::left | anchor_styles::top, control.anchor());
      assert::are_equal(drawing::point::empty, control.auto_scroll_point());
      assert::is_false(control.auto_size());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.back_color());
      assert::are_equal(drawing::image::empty, control.background_image());
      assert::are_equal(image_layout::tile, control.background_image_layout());
      assert::is_zero(control.bottom());
      assert::are_equal(drawing::rectangle::empty, control.bounds());
      assert::is_false(control.can_focus());
      assert::is_true(control.can_raise_events());
      assert::is_true(control.can_select());
      assert::are_equal(drawing::rectangle::empty, control.client_rectangle());
      assert::are_equal(drawing::size::empty, control.client_size());
      assert::are_equal("Gammasoft", control.company_name());
      assert::is_null(control.context_menu());
      assert::are_equal(forms::control_appearance::standard, control.control_appearance());
      assert::is_empty(control.controls());
      assert::is_false(control.created());
      assert::are_equal(forms::cursors::default_cursor(), control.cursor());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.default_back_color());
      assert::are_equal(forms::cursors::default_cursor(), control.default_cursor());
      assert::are_equal(drawing::system_fonts::default_font(), control.default_font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.default_fore_color());
      assert::are_equal(drawing::size::empty, control.default_size());
      assert::are_equal(drawing::rectangle::empty, control.display_rectangle());
      assert::are_equal(forms::dock_style::none, control.dock());
      assert::is_false(control.double_buffered());
      assert::is_true(control.enabled());
      assert::is_false(control.focused());
      assert::are_equal(drawing::system_fonts::default_font(), control.font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.fore_color());
      assert::is_zero(control.handle());
      assert::is_zero(control.height());
      assert::is_false(control.invoke_required());
      assert::is_false(control.is_handle_created());
      assert::is_zero(control.left());
      assert::are_equal(drawing::point::empty, control.location());
      assert::are_equal(forms::padding(3), control.margin());
      assert::are_equal(drawing::size::empty, control.maximum_client_size());
      assert::are_equal(drawing::size::empty, control.maximum_size());
      assert::are_equal(drawing::size::empty, control.minimum_client_size());
      assert::are_equal(drawing::size::empty, control.minimum_size());
      assert::is_zero(control.native_handle());
      assert::is_empty(control.name());
      assert::are_equal(forms::padding(0), control.padding());
      assert::is_null(control.parent());
      assert::are_equal("xtd", control.product_name());
      assert::is_not_zero(control.region().handle());
      assert::is_zero(control.right());
      assert::are_equal(drawing::size::empty, control.size());
      assert::is_empty(control.style_sheet().theme().name());
      assert::is_true(control.tab_stop());
      assert::is_false(control.tag().has_value());
      assert::are_equal("Value", control.text());
      assert::is_zero(control.toolkit_handle());
      assert::is_zero(control.top());
      assert::is_null(control.top_level_control());
      assert::is_true(control.visible());
      assert::is_zero(control.width());
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls());
      assert::are_equal(keys::none, forms::control::modifier_keys());
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons());
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position());
    }
    
    auto test_method_(constructor_with_parent_and_text) {
      forms::form form;
      control_for_test control(form, "Value");
      assert::are_equal(1_z, form.controls().count());
      assert::are_equal(control, form.controls()[0].get());
      assert::are_equal(anchor_styles::left | anchor_styles::top, control.anchor());
      assert::are_equal(drawing::point::empty, control.auto_scroll_point());
      assert::is_false(control.auto_size());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.back_color());
      assert::are_equal(drawing::image::empty, control.background_image());
      assert::are_equal(image_layout::tile, control.background_image_layout());
      assert::is_zero(control.bottom());
      assert::are_equal(drawing::rectangle::empty, control.bounds());
      assert::is_false(control.can_focus());
      assert::is_true(control.can_raise_events());
      assert::is_true(control.can_select());
      assert::are_equal(drawing::rectangle::empty, control.client_rectangle());
      assert::are_equal(drawing::size::empty, control.client_size());
      assert::are_equal("Gammasoft", control.company_name());
      assert::is_null(control.context_menu());
      assert::are_equal(forms::control_appearance::standard, control.control_appearance());
      assert::is_empty(control.controls());
      assert::is_true(control.created());
      assert::are_equal(forms::cursors::default_cursor(), control.cursor());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.default_back_color());
      assert::are_equal(forms::cursors::default_cursor(), control.default_cursor());
      assert::are_equal(drawing::system_fonts::default_font(), control.default_font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.default_fore_color());
      assert::are_equal(drawing::size::empty, control.default_size());
      assert::are_equal(drawing::rectangle::empty, control.display_rectangle());
      assert::are_equal(forms::dock_style::none, control.dock());
      assert::is_false(control.double_buffered());
      assert::is_true(control.enabled());
      assert::is_false(control.focused());
      assert::are_equal(drawing::system_fonts::default_font(), control.font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.fore_color());
      assert::is_not_zero(control.handle());
      assert::is_zero(control.height());
      assert::is_false(control.invoke_required());
      assert::is_true(control.is_handle_created());
      assert::is_zero(control.left());
      assert::are_equal(drawing::point::empty, control.location());
      assert::are_equal(forms::padding(3), control.margin());
      assert::are_equal(drawing::size::empty, control.maximum_client_size());
      assert::are_equal(drawing::size::empty, control.maximum_size());
      assert::are_equal(drawing::size::empty, control.minimum_client_size());
      assert::are_equal(drawing::size::empty, control.minimum_size());
      assert::is_not_zero(control.native_handle());
      assert::is_empty(control.name());
      assert::are_equal(forms::padding(0), control.padding());
      assert::are_equal(form, control.parent().value().get());
      assert::are_equal("xtd", control.product_name());
      assert::is_not_zero(control.region().handle());
      assert::is_zero(control.right());
      assert::are_equal(drawing::size::empty, control.size());
      assert::is_empty(control.style_sheet().theme().name());
      assert::is_true(control.tab_stop());
      assert::is_false(control.tag().has_value());
      assert::are_equal("Value", control.text());
      assert::is_not_zero(control.toolkit_handle());
      assert::is_zero(control.top());
      assert::are_equal(form, control.top_level_control().value().get());
      assert::is_true(control.visible());
      assert::is_zero(control.width());
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls());
      assert::are_equal(keys::none, forms::control::modifier_keys());
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons());
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position());
    }
    
    auto test_method_(constructor_with_text_location_and_size) {
      control_for_test control("Value", 10, 20, 100, 50);
      assert::are_equal(anchor_styles::left | anchor_styles::top, control.anchor());
      assert::are_equal(drawing::point::empty, control.auto_scroll_point());
      assert::is_false(control.auto_size());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.back_color());
      assert::are_equal(drawing::image::empty, control.background_image());
      assert::are_equal(image_layout::tile, control.background_image_layout());
      assert::are_equal(70, control.bottom());
      assert::are_equal(drawing::rectangle(10, 20, 100, 50), control.bounds());
      assert::is_false(control.can_focus());
      assert::is_true(control.can_raise_events());
      assert::is_true(control.can_select());
      assert::are_equal(drawing::rectangle(0, 0, 100, 50), control.client_rectangle());
      assert::are_equal(drawing::size(100, 50), control.client_size());
      assert::are_equal("Gammasoft", control.company_name());
      assert::is_null(control.context_menu());
      assert::are_equal(forms::control_appearance::standard, control.control_appearance());
      assert::is_empty(control.controls());
      assert::is_false(control.created());
      assert::are_equal(forms::cursors::default_cursor(), control.cursor());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.default_back_color());
      assert::are_equal(forms::cursors::default_cursor(), control.default_cursor());
      assert::are_equal(drawing::system_fonts::default_font(), control.default_font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.default_fore_color());
      assert::are_equal(drawing::size::empty, control.default_size());
      assert::are_equal(drawing::rectangle(0, 0, 100, 50), control.display_rectangle());
      assert::are_equal(forms::dock_style::none, control.dock());
      assert::is_false(control.double_buffered());
      assert::is_true(control.enabled());
      assert::is_false(control.focused());
      assert::are_equal(drawing::system_fonts::default_font(), control.font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.fore_color());
      assert::is_zero(control.handle());
      assert::are_equal(50, control.height());
      assert::is_false(control.invoke_required());
      assert::is_false(control.is_handle_created());
      assert::are_equal(10, control.left());
      assert::are_equal(drawing::point(10, 20), control.location());
      assert::are_equal(forms::padding(3), control.margin());
      assert::are_equal(drawing::size::empty, control.maximum_client_size());
      assert::are_equal(drawing::size::empty, control.maximum_size());
      assert::are_equal(drawing::size::empty, control.minimum_client_size());
      assert::are_equal(drawing::size::empty, control.minimum_size());
      assert::is_zero(control.native_handle());
      assert::is_empty(control.name());
      assert::are_equal(forms::padding(0), control.padding());
      assert::is_null(control.parent());
      assert::are_equal("xtd", control.product_name());
      assert::is_not_zero(control.region().handle());
      assert::are_equal(110, control.right());
      assert::are_equal(drawing::size(100, 50), control.size());
      assert::is_empty(control.style_sheet().theme().name());
      assert::is_true(control.tab_stop());
      assert::is_false(control.tag().has_value());
      assert::are_equal("Value", control.text());
      assert::is_zero(control.toolkit_handle());
      assert::are_equal(20, control.top());
      assert::is_null(control.top_level_control());
      assert::is_true(control.visible());
      assert::are_equal(100, control.width());
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls());
      assert::are_equal(keys::none, forms::control::modifier_keys());
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons());
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position());
    }
    
    auto test_method_(constructor_with_parent_text_location_and_size) {
      forms::form form;
      control_for_test control(form, "Value", 10, 20, 100, 50);
      assert::are_equal(1_z, form.controls().count());
      assert::are_equal(control, form.controls()[0].get());
      assert::are_equal(anchor_styles::left | anchor_styles::top, control.anchor());
      assert::are_equal(drawing::point::empty, control.auto_scroll_point());
      assert::is_false(control.auto_size());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.back_color());
      assert::are_equal(drawing::image::empty, control.background_image());
      assert::are_equal(image_layout::tile, control.background_image_layout());
      assert::are_equal(70, control.bottom());
      assert::are_equal(drawing::rectangle(10, 20, 100, 50), control.bounds());
      assert::is_false(control.can_focus());
      assert::is_true(control.can_raise_events());
      assert::is_true(control.can_select());
      assert::are_equal(drawing::rectangle(0, 0, 100, 50), control.client_rectangle());
      assert::are_equal(drawing::size(100, 50), control.client_size());
      assert::are_equal("Gammasoft", control.company_name());
      assert::is_null(control.context_menu());
      assert::are_equal(forms::control_appearance::standard, control.control_appearance());
      assert::is_empty(control.controls());
      assert::is_true(control.created());
      assert::are_equal(forms::cursors::default_cursor(), control.cursor());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.default_back_color());
      assert::are_equal(forms::cursors::default_cursor(), control.default_cursor());
      assert::are_equal(drawing::system_fonts::default_font(), control.default_font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.default_fore_color());
      assert::are_equal(drawing::size::empty, control.default_size());
      assert::are_equal(drawing::rectangle(0, 0, 100, 50), control.display_rectangle());
      assert::are_equal(forms::dock_style::none, control.dock());
      assert::is_false(control.double_buffered());
      assert::is_true(control.enabled());
      assert::is_false(control.focused());
      assert::are_equal(drawing::system_fonts::default_font(), control.font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.fore_color());
      assert::is_not_zero(control.handle());
      assert::are_equal(50, control.height());
      assert::is_false(control.invoke_required());
      assert::is_true(control.is_handle_created());
      assert::are_equal(10, control.left());
      assert::are_equal(drawing::point(10, 20), control.location());
      assert::are_equal(forms::padding(3), control.margin());
      assert::are_equal(drawing::size::empty, control.maximum_client_size());
      assert::are_equal(drawing::size::empty, control.maximum_size());
      assert::are_equal(drawing::size::empty, control.minimum_client_size());
      assert::are_equal(drawing::size::empty, control.minimum_size());
      assert::is_not_zero(control.native_handle());
      assert::is_empty(control.name());
      assert::are_equal(forms::padding(0), control.padding());
      assert::are_equal(form, control.parent().value().get());
      assert::are_equal("xtd", control.product_name());
      assert::is_not_zero(control.region().handle());
      assert::are_equal(110, control.right());
      assert::are_equal(drawing::size(100, 50), control.size());
      assert::is_empty(control.style_sheet().theme().name());
      assert::is_true(control.tab_stop());
      assert::is_false(control.tag().has_value());
      assert::are_equal("Value", control.text());
      assert::is_not_zero(control.toolkit_handle());
      assert::are_equal(20, control.top());
      assert::are_equal(form, control.top_level_control().value().get());
      assert::is_true(control.visible());
      assert::are_equal(100, control.width());
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls());
      assert::are_equal(keys::none, forms::control::modifier_keys());
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons());
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position());
    }
    
    auto test_method_(create_params_default_values) {
      control_for_test control;
      
      forms::create_params cp = control.create_params();
      assert::is_empty(cp.caption());
      assert::is_empty(cp.class_name());
      assert::are_equal(CS_DBLCLKS, cp.class_style());
      assert::is_zero(cp.ex_style());
      assert::is_zero(cp.height());
      assert::are_equal(drawing::point::empty, cp.location());
      assert::is_zero(cp.param());
      assert::is_zero(cp.parent());
      assert::are_equal(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_VISIBLE | WS_TABSTOP, cp.style());
      assert::are_equal(drawing::size::empty, cp.size());
      assert::is_zero(cp.width());
      assert::is_zero(cp.x());
      assert::is_zero(cp.y());
    }
    
    auto test_method_(create_params_enabled_false) {
      control_for_test control;
      control.enabled(false);
      
      forms::create_params cp = control.create_params();
      assert::is_empty(cp.caption());
      assert::is_empty(cp.class_name());
      assert::are_equal(CS_DBLCLKS, cp.class_style());
      assert::is_zero(cp.ex_style());
      assert::is_zero(cp.height());
      assert::are_equal(drawing::point::empty, cp.location());
      assert::is_zero(cp.param());
      assert::is_zero(cp.parent());
      assert::are_equal(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_DISABLED | WS_VISIBLE | WS_TABSTOP, cp.style());
      assert::are_equal(drawing::size::empty, cp.size());
      assert::is_zero(cp.width());
      assert::is_zero(cp.x());
      assert::is_zero(cp.y());
    }
    
    auto test_method_(create_params_location) {
      control_for_test control;
      control.location({10, 20});
      
      forms::create_params cp = control.create_params();
      assert::is_empty(cp.caption());
      assert::is_empty(cp.class_name());
      assert::are_equal(CS_DBLCLKS, cp.class_style());
      assert::is_zero(cp.ex_style());
      assert::is_zero(cp.height());
      assert::are_equal(drawing::point(10, 20), cp.location());
      assert::is_zero(cp.param());
      assert::is_zero(cp.parent());
      assert::are_equal(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_VISIBLE | WS_TABSTOP, cp.style());
      assert::are_equal(drawing::size::empty, cp.size());
      assert::is_zero(cp.width());
      assert::are_equal(10, cp.x());
      assert::are_equal(20, cp.y());
    }
    
    auto test_method_(create_params_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      
      forms::create_params cp = control.create_params();
      assert::is_empty(cp.caption());
      assert::is_empty(cp.class_name());
      assert::are_equal(CS_DBLCLKS, cp.class_style());
      assert::is_zero(cp.ex_style());
      assert::is_zero(cp.height());
      assert::are_equal(drawing::point::empty, cp.location());
      assert::is_zero(cp.param());
      assert::are_equal(form.handle(), cp.parent());
      assert::are_equal(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_VISIBLE | WS_TABSTOP, cp.style());
      assert::are_equal(drawing::size::empty, cp.size());
      assert::is_zero(cp.width());
      assert::is_zero(cp.x());
      assert::is_zero(cp.y());
    }
    
    auto test_method_(create_params_size) {
      control_for_test control;
      control.size({100, 50});
      
      forms::create_params cp = control.create_params();
      assert::is_empty(cp.caption());
      assert::is_empty(cp.class_name());
      assert::are_equal(CS_DBLCLKS, cp.class_style());
      assert::is_zero(cp.ex_style());
      assert::are_equal(50, cp.height());
      assert::are_equal(drawing::point::empty, cp.location());
      assert::is_zero(cp.param());
      assert::is_zero(cp.parent());
      assert::are_equal(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_VISIBLE | WS_TABSTOP, cp.style());
      assert::are_equal(drawing::size(100, 50), cp.size());
      assert::are_equal(100, cp.width());
      assert::is_zero(cp.x());
      assert::is_zero(cp.y());
    }
    
    auto test_method_(create_params_tab_stop_false) {
      control_for_test control;
      control.tab_stop(false);
      
      forms::create_params cp = control.create_params();
      assert::is_empty(cp.caption());
      assert::is_empty(cp.class_name());
      assert::are_equal(CS_DBLCLKS, cp.class_style());
      assert::is_zero(cp.ex_style());
      assert::is_zero(cp.height());
      assert::are_equal(drawing::point::empty, cp.location());
      assert::is_zero(cp.param());
      assert::is_zero(cp.parent());
      assert::are_equal(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_VISIBLE, cp.style());
      assert::are_equal(drawing::size::empty, cp.size());
      assert::is_zero(cp.width());
      assert::is_zero(cp.x());
      assert::is_zero(cp.y());
    }
    
    auto test_method_(create_params_text) {
      control_for_test control;
      control.text("Value");
      
      forms::create_params cp = control.create_params();
      assert::are_equal("Value", cp.caption());
      assert::is_empty(cp.class_name());
      assert::are_equal(CS_DBLCLKS, cp.class_style());
      assert::is_zero(cp.ex_style());
      assert::is_zero(cp.height());
      assert::are_equal(drawing::point::empty, cp.location());
      assert::is_zero(cp.param());
      assert::is_zero(cp.parent());
      assert::are_equal(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_VISIBLE | WS_TABSTOP, cp.style());
      assert::are_equal(drawing::size::empty, cp.size());
      assert::is_zero(cp.width());
      assert::is_zero(cp.x());
      assert::is_zero(cp.y());
    }
    
    auto test_method_(create_params_visible_false) {
      control_for_test control;
      control.visible(false);
      
      forms::create_params cp = control.create_params();
      assert::is_empty(cp.caption());
      assert::is_empty(cp.class_name());
      assert::are_equal(CS_DBLCLKS, cp.class_style());
      assert::is_zero(cp.ex_style());
      assert::is_zero(cp.height());
      assert::are_equal(drawing::point::empty, cp.location());
      assert::is_zero(cp.param());
      assert::is_zero(cp.parent());
      assert::are_equal(WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_TABSTOP, cp.style());
      assert::are_equal(drawing::size::empty, cp.size());
      assert::is_zero(cp.width());
      assert::is_zero(cp.x());
      assert::is_zero(cp.y());
    }
    
    auto test_method_(create_params_with_some_values) {
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
      assert::are_equal("Value", cp.caption());
      assert::is_empty(cp.class_name());
      assert::are_equal(CS_DBLCLKS, cp.class_style());
      assert::is_zero(cp.ex_style());
      assert::are_equal(50, cp.height());
      assert::are_equal(drawing::point(10, 20), cp.location());
      assert::is_zero(cp.param());
      assert::are_equal(form.handle(), cp.parent());
      assert::are_equal(WS_CHILD | WS_CLIPSIBLINGS | WS_DISABLED | WS_CLIPCHILDREN, cp.style());
      assert::are_equal(drawing::size(100, 50), cp.size());
      assert::are_equal(100, cp.width());
      assert::are_equal(10, cp.x());
      assert::are_equal(20, cp.y());
    }
    
    auto test_method_(parent_with_controls_add) {
      forms::form form;
      control_for_test control;
      form.controls().add(control);
      assert::are_equal(1_z, form.controls().count());
      assert::are_equal(control, form.controls()[0].get());
      assert::are_equal(form, control.parent());
      assert::is_not_zero(control.handle());
    }
    
    auto test_method_(parent_with_control_set_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      assert::are_equal(1_z, form.controls().count());
      assert::are_equal(control, form.controls()[0].get());
      assert::is_not_zero(control.handle());
    }
    
    auto test_method_(ambient_property_back_color) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      assert::are_equal(form.back_color(), control.back_color());
    }
    
    auto test_method_(ambient_property_cursor) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      assert::are_equal(form.cursor(), control.cursor());
    }
    
    auto test_method_(ambient_property_font) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      assert::are_equal(form.font(), control.font());
    }
    
    auto test_method_(ambient_property_fore_color) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      assert::are_equal(form.fore_color(), control.fore_color());
    }
    
    auto test_method_(ambient_property_change_parent_back_color) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      form.back_color(color::spring_green);
      assert::are_equal(color::spring_green, form.back_color());
      assert::are_equal(form.back_color(), control.back_color());
    }
    
    auto test_method_(ambient_property_change_parent_cursor) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      form.cursor(cursors::cross());
      assert::are_equal(cursors::cross(), form.cursor());
      assert::are_equal(form.cursor(), control.cursor());
    }
    
    auto test_method_(ambient_property_change_parent_font) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      form.font(system_fonts::tool_font());
      assert::are_equal(system_fonts::tool_font(), form.font());
      assert::are_equal(form.font(), control.font());
    }
    
    auto test_method_(ambient_property_change_parent_fore_color) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      form.fore_color(color::spring_green);
      assert::are_equal(color::spring_green, form.fore_color());
      assert::are_equal(form.fore_color(), control.fore_color());
    }
    
    auto test_method_(anchor_without_parent) {
      control_for_test control;
      control.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
      assert::are_equal(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom, control.anchor());
    }
    
    auto test_method_(anchor_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
      assert::are_equal(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom, control.anchor());
    }
    
    auto test_method_(auto_size_without_parent) {
      control_for_test control;
      control.auto_size(true);
      assert::is_true(control.auto_size());
    }
    
    auto test_method_(auto_size_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.auto_size(true);
      assert::is_true(control.auto_size());
    }
    
    auto test_method_(back_color_without_parent) {
      control_for_test control;
      control.back_color(color::blue);
      assert::are_equal(color::blue, control.back_color());
    }
    
    auto test_method_(back_color_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.back_color(color::blue);
      assert::are_equal(color::blue, control.back_color());
    }
    
    auto test_method_(back_color_nullptr__without_parent) {
      control_for_test control;
      control.back_color(color::blue);
      assert::are_equal(color::blue, control.back_color());
      control.back_color(nullptr);
      assert::are_equal(control.default_back_color(), control.back_color());
    }
    
    auto test_method_(back_color_nullptr_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.back_color(color::blue);
      assert::are_equal(color::blue, control.back_color());
      control.back_color(nullptr);
      assert::are_equal(control.default_back_color(), control.back_color());
    }
    
    auto test_method_(background_image_without_parent) {
      control_for_test control;
      image img = system_images::from_name("xtd");
      control.background_image(img);
      assert::are_equal(img, control.background_image());
    }
    
    auto test_method_(background_image_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      image img = system_images::from_name("xtd");
      control.background_image(img);
      assert::are_equal(img, control.background_image());
    }
    
    auto test_method_(background_image_layout_without_parent) {
      control_for_test control;
      control.background_image_layout(image_layout::zoom);
      assert::are_equal(image_layout::zoom, control.background_image_layout());
    }
    
    auto test_method_(background_image_layout_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.background_image_layout(image_layout::zoom);
      assert::are_equal(image_layout::zoom, control.background_image_layout());
    }
    
    auto test_method_(client_size_without_parent) {
      control_for_test control;
      control.client_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.client_size());
      assert::are_equal(drawing::rectangle(0, 0, 100, 50), control.client_rectangle());
      assert::are_equal(drawing::rectangle(0, 0, 100, 50), control.display_rectangle());
    }
    
    auto test_method_(client_size_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.client_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.client_size());
      assert::are_equal(drawing::rectangle(0, 0, 100, 50), control.client_rectangle());
      assert::are_equal(drawing::rectangle(0, 0, 100, 50), control.display_rectangle());
    }
    
    auto test_method_(context_menu_without_parent) {
      control_for_test control;
      menu_item context_menu_item1("Item1", [&] {});
      forms::context_menu context_menu1({context_menu_item1});
      control.context_menu(context_menu1);
      assert::are_same(context_menu1, control.context_menu().value().get());
    }
    
    auto test_method_(context_menu_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      menu_item context_menu_item1("Item1", [&] {});
      forms::context_menu context_menu1({context_menu_item1});
      control.context_menu(context_menu1);
      assert::are_same(context_menu1, control.context_menu().value().get());
    }
    
    auto test_method_(control_appearance_without_parent) {
      control_for_test control;
      control.control_appearance(forms::control_appearance::system);
      assert::are_equal(forms::control_appearance::system, control.control_appearance());
    }
    
    auto test_method_(control_appearance_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.control_appearance(forms::control_appearance::system);
      assert::are_equal(forms::control_appearance::system, control.control_appearance());
    }
    
    auto test_method_(controls_without_parent) {
      control_for_test control;
      control_for_test control1;
      control_for_test control2;
      control_for_test control3;
      control.controls().add(control1);
      control.controls().add(control2);
      control.controls().add(control3);
      assert::are_equal(3_z, control.controls().count());
      assert::are_same(control1, control.controls()[0].get());
      assert::are_same(control2, control.controls()[1].get());
      assert::are_same(control3, control.controls()[2].get());
      assert::is_null(control1.parent());
      assert::is_null(control2.parent());
      assert::is_null(control3.parent());
    }
    
    auto test_method_(controls_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control_for_test control1;
      control_for_test control2;
      control_for_test control3;
      control.controls().add(control1);
      control.controls().add(control2);
      control.controls().add(control3);
      assert::are_equal(3_z, control.controls().count());
      assert::are_same(control1, control.controls()[0].get());
      assert::are_same(control2, control.controls()[1].get());
      assert::are_same(control3, control.controls()[2].get());
      assert::are_same(control, control1.parent().value().get());
      assert::are_same(control, control2.parent().value().get());
      assert::are_same(control, control3.parent().value().get());
    }
    
    auto test_method_(cursor_without_parent) {
      control_for_test control;
      control.cursor(cursors::cross());
      assert::are_equal(cursors::cross(), control.cursor());
    }
    
    auto test_method_(cursor_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.cursor(cursors::cross());
      assert::are_equal(cursors::cross(), control.cursor());
    }
    
    auto test_method_(cursor_nullptr_without_parent) {
      control_for_test control;
      control.cursor(cursors::cross());
      assert::are_equal(cursors::cross(), control.cursor());
      control.cursor(nullptr);
      assert::are_equal(control.default_cursor(), control.cursor());
    }
    
    auto test_method_(cursor_nullptr_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.cursor(cursors::cross());
      assert::are_equal(cursors::cross(), control.cursor());
      control.cursor(nullptr);
      assert::are_equal(control.default_cursor(), control.cursor());
    }
    
    auto test_method_(dock_without_parent) {
      control_for_test control;
      control.dock(dock_style::fill);
      assert::are_equal(dock_style::fill, control.dock());
    }
    
    auto test_method_(dock_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.dock(dock_style::fill);
      assert::are_equal(dock_style::fill, control.dock());
    }
    
    auto test_method_(double_buffered_without_parent) {
      control_for_test control;
      control.double_buffered(true);
      assert::is_true(control.double_buffered());
    }
    
    auto test_method_(double_buffered_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.double_buffered(true);
      assert::is_true(control.double_buffered());
    }
    
    auto test_method_(enabled_without_parent) {
      control_for_test control;
      control.enabled(false);
      assert::is_false(control.double_buffered());
    }
    
    auto test_method_(enabled_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.enabled(false);
      assert::is_false(control.double_buffered());
    }
    
    auto test_method_(font_without_parent) {
      control_for_test control;
      control.font(system_fonts::tool_font());
      assert::are_equal(system_fonts::tool_font(), control.font());
    }
    
    auto test_method_(font_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.font(system_fonts::tool_font());
      assert::are_equal(system_fonts::tool_font(), control.font());
    }
    
    auto test_method_(font_nullptr_without_parent) {
      control_for_test control;
      control.font(system_fonts::tool_font());
      assert::are_equal(system_fonts::tool_font(), control.font());
      control.font(nullptr);
      assert::are_equal(control.default_font(), control.font());
    }
    
    auto test_method_(font_nullptr_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.font(system_fonts::tool_font());
      assert::are_equal(system_fonts::tool_font(), control.font());
      control.font(nullptr);
      assert::are_equal(control.default_font(), control.font());
    }
    
    auto test_method_(fore_color_without_parent) {
      control_for_test control;
      control.fore_color(color::spring_green);
      assert::are_equal(color::spring_green, control.fore_color());
    }
    
    auto test_method_(fore_color_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.fore_color(color::spring_green);
      assert::are_equal(color::spring_green, control.fore_color());
    }
    
    auto test_method_(fore_color_nullptr_without_parent) {
      control_for_test control;
      control.fore_color(color::blue);
      assert::are_equal(color::blue, control.fore_color());
      control.fore_color(nullptr);
      assert::are_equal(control.default_fore_color(), control.fore_color());
    }
    
    auto test_method_(fore_color_nullptr_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.fore_color(color::blue);
      assert::are_equal(color::blue, control.fore_color());
      control.fore_color(nullptr);
      assert::are_equal(control.default_fore_color(), control.fore_color());
    }
    
    auto test_method_(height_without_parent) {
      control_for_test control;
      control.height(50);
      assert::are_equal(50, control.height());
      assert::are_equal(drawing::size(0, 50), control.size());
    }
    
    auto test_method_(height_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.height(50);
      assert::are_equal(50, control.height());
      assert::are_equal(drawing::size(0, 50), control.size());
    }
    
    auto test_method_(left_without_parent) {
      control_for_test control;
      control.left(10);
      assert::are_equal(10, control.left());
      assert::are_equal(drawing::point(10, 0), control.location());
    }
    
    auto test_method_(left_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.left(10);
      assert::are_equal(10, control.left());
      assert::are_equal(drawing::point(10, 0), control.location());
    }
    
    auto test_method_(location_without_parent) {
      control_for_test control;
      control.location({10, 20});
      assert::are_equal(drawing::point(10, 20), control.location());
      assert::are_equal(10, control.left());
      assert::are_equal(20, control.top());
    }
    
    auto test_method_(location_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.location({10, 20});
      assert::are_equal(drawing::point(10, 20), control.location());
      assert::are_equal(10, control.left());
      assert::are_equal(20, control.top());
    }
    
    auto test_method_(margin_without_parent) {
      control_for_test control;
      control.margin(forms::padding(10));
      assert::are_equal(forms::padding(10), control.margin());
    }
    
    auto test_method_(margin_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.margin(forms::padding(10));
      assert::are_equal(forms::padding(10), control.margin());
    }
    
    auto test_method_(maximum_client_size_without_parent) {
      control_for_test control;
      control.client_size({300, 300});
      control.maximum_client_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.maximum_client_size());
      assert::are_equal(drawing::size(100, 50), control.client_size());
    }
    
    auto test_method_(maximum_client_size_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.client_size({300, 300});
      control.maximum_client_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.maximum_client_size());
      assert::are_equal(drawing::size(100, 50), control.client_size());
    }
    
    auto test_method_(maximum_size_without_parent) {
      control_for_test control;
      control.size({300, 300});
      control.maximum_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.maximum_size());
      assert::are_equal(drawing::size(100, 50), control.size());
    }
    
    auto test_method_(maximum_size_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.size({300, 300});
      control.maximum_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.maximum_size());
      assert::are_equal(drawing::size(100, 50), control.size());
    }
    
    auto test_method_(minimum_client_size_without_parent) {
      control_for_test control;
      control.minimum_client_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.minimum_client_size());
      assert::are_equal(drawing::size(100, 50), control.client_size());
    }
    
    auto test_method_(minimum_client_size_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.minimum_client_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.minimum_client_size());
      assert::are_equal(drawing::size(100, 50), control.client_size());
    }
    
    auto test_method_(minimum_size_without_parent) {
      control_for_test control;
      control.minimum_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.minimum_size());
      assert::are_equal(drawing::size(100, 50), control.size());
    }
    
    auto test_method_(minimum_size_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.minimum_size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.minimum_size());
      assert::are_equal(drawing::size(100, 50), control.size());
    }
    
    auto test_method_(name_without_parent) {
      control_for_test control;
      control.name("Value");
      assert::are_equal("Value", control.name());
    }
    
    auto test_method_(name_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.name("Value");
      assert::are_equal("Value", control.name());
    }
    
    auto test_method_(padding_without_parent) {
      control_for_test control;
      control.padding(forms::padding(10));
      assert::are_equal(forms::padding(10), control.padding());
    }
    
    auto test_method_(padding_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.padding(forms::padding(10));
      assert::are_equal(forms::padding(10), control.padding());
    }
    
    auto test_method_(parent_without_parent) {
      control_for_test control;
      control_for_test control1;
      control_for_test control2;
      control_for_test control3;
      control1.parent(control);
      control2.parent(control);
      control3.parent(control);
      assert::are_equal(3_z, control.controls().count());
      assert::is_null(control1.parent());
      assert::is_null(control2.parent());
      assert::is_null(control3.parent());
    }
    
    auto test_method_(parent_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control_for_test control1;
      control_for_test control2;
      control_for_test control3;
      control1.parent(control);
      control2.parent(control);
      control3.parent(control);
      assert::are_equal(3_z, control.controls().count());
      assert::are_same(control, control1.parent().value().get());
      assert::are_same(control, control2.parent().value().get());
      assert::are_same(control, control3.parent().value().get());
    }
    
    auto test_method_(parent_nullptr) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control_for_test control1;
      control1.parent(control);
      assert::are_same(control, control1.parent().value().get());
      control1.parent(nullptr);
      assert::is_null(control1.parent());
    }
    
    auto test_method_(parent_with_other_control) {
      forms::form form1;
      forms::form form2;
      control_for_test control;
      control.parent(form1);
      assert::are_equal(1_z, form1.controls().count());
      assert::are_equal(0_z, form2.controls().count());
      assert::are_same(form1, control.parent().value().get());
      
      control.parent(form2);
      assert::are_equal(0_z, form1.controls().count());
      assert::are_equal(1_z, form2.controls().count());
      assert::are_same(form2, control.parent().value().get());
    }
    
    auto test_method_(region_without_parent) {
      control_for_test control;
      drawing::region region1;
      control.region(region1);
      assert::are_equal(region1, control.region());
    }
    
    auto test_method_(region_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      drawing::region region1;
      control.region(region1);
      assert::are_equal(region1, control.region());
    }
    
    auto test_method_(size_without_parent) {
      control_for_test control;
      control.size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.size());
      assert::are_equal(100, control.width());
      assert::are_equal(50, control.height());
    }
    
    auto test_method_(size_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.size({100, 50});
      assert::are_equal(drawing::size(100, 50), control.size());
      assert::are_equal(100, control.width());
      assert::are_equal(50, control.height());
    }
    
    auto test_method_(style_sheet_without_parent) {
      control_for_test control;
      style_sheets::style_sheet ss("control {"
                                   "  border-style: solid;"
                                   "  border-color: blue;"
                                   "}");
      control.style_sheet(ss);
      assert::are_equal(ss, control.style_sheet());
    }
    
    auto test_method_(style_sheet_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      style_sheets::style_sheet ss("control {"
                                   "  border-style: solid;"
                                   "  border-color: blue;"
                                   "}");
      control.style_sheet(ss);
      assert::are_equal(ss, control.style_sheet());
    }
    
    auto test_method_(tab_stop_without_parent) {
      control_for_test control;
      control.tab_stop(false);
      assert::is_false(control.tab_stop());
    }
    
    auto test_method_(tab_stop_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.tab_stop(false);
      assert::is_false(control.tab_stop());
    }
    
    auto test_method_(tag_without_parent) {
      control_for_test control;
      control.tag("my tag");
      assert::are_equal("my tag", as<string>(control.tag()));
    }
    
    auto test_method_(tag_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.tag("my tag");
      assert::are_equal("my tag", as<string>(control.tag()));
    }
    
    auto test_method_(text_without_parent) {
      control_for_test control;
      control.text("my text");
      assert::are_equal("my text", control.text());
    }
    
    auto test_method_(text_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.text("my text");
      assert::are_equal("my text", control.text());
    }
    
    auto test_method_(top_without_parent) {
      control_for_test control;
      control.top(20);
      assert::are_equal(20, control.top());
      assert::are_equal(drawing::point(0, 20), control.location());
    }
    
    auto test_method_(top_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.top(20);
      assert::are_equal(20, control.top());
      assert::are_equal(drawing::point(0, 20), control.location());
    }
    
    auto test_method_(visible_without_parent) {
      control_for_test control;
      control.visible(false);
      assert::is_false(control.visible());
    }
    
    auto test_method_(visible_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.visible(false);
      assert::is_false(control.visible());
    }
    
    auto test_method_(check_for_illegal_cross_thread_call) {
      auto previous_value = forms::control::check_for_illegal_cross_thread_calls();
      forms::control::check_for_illegal_cross_thread_calls(false);
      assert::is_false(forms::control::check_for_illegal_cross_thread_calls());
      forms::control::check_for_illegal_cross_thread_calls(previous_value);
    }
    
    auto test_method_(begin_invoke_without_parent) {
      bool invoked = false;
      control_for_test control;
      control.begin_invoke([&] {
        invoked = true;
      });
      assert::is_false(invoked);
    }
    
    auto test_method_(begin_invoke_with_parent) {
      bool invoked = false;
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.begin_invoke([&] {
        invoked = true;
      });
      // The application's message loop must be running to execute begin_invoke: not testable in unit tests.
      assert::is_false(invoked);
    }
    
    auto test_method_(bring_to_front_without_parent) {
      control_for_test control;
      control.bring_to_front();
      assert::is_false(control.focused());
    }
    
    auto test_method_(bring_to_front_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.bring_to_front();
      assert::is_true(control.focused());
    }
    
    auto test_method_(create_control_without_parent) {
      control_for_test control;
      assert::throws<argument_exception>([&] {control.create_control();});
    }
    
    auto test_method_(create_control_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      assert::are_equal(1_z, form.controls().count());
      assert::are_equal(control, form.controls()[0].get());
      assert::are_equal(anchor_styles::left | anchor_styles::top, control.anchor());
      assert::are_equal(drawing::point::empty, control.auto_scroll_point());
      assert::is_false(control.auto_size());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.back_color());
      assert::are_equal(drawing::image::empty, control.background_image());
      assert::are_equal(image_layout::tile, control.background_image_layout());
      assert::is_zero(control.bottom());
      assert::are_equal(drawing::rectangle::empty, control.bounds());
      assert::is_false(control.can_focus());
      assert::is_true(control.can_raise_events());
      assert::is_true(control.can_select());
      assert::are_equal(drawing::rectangle::empty, control.client_rectangle());
      assert::are_equal(drawing::size::empty, control.client_size());
      assert::are_equal("Gammasoft", control.company_name());
      assert::is_null(control.context_menu());
      assert::are_equal(forms::control_appearance::standard, control.control_appearance());
      assert::is_empty(control.controls());
      assert::is_true(control.created());
      assert::are_equal(forms::cursors::default_cursor(), control.cursor());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), control.default_back_color());
      assert::are_equal(forms::cursors::default_cursor(), control.default_cursor());
      assert::are_equal(drawing::system_fonts::default_font(), control.default_font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.default_fore_color());
      assert::are_equal(drawing::size::empty, control.default_size());
      assert::are_equal(drawing::rectangle::empty, control.display_rectangle());
      assert::are_equal(forms::dock_style::none, control.dock());
      assert::is_false(control.double_buffered());
      assert::is_true(control.enabled());
      assert::is_false(control.focused());
      assert::are_equal(drawing::system_fonts::default_font(), control.font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), control.fore_color());
      assert::is_not_zero(control.handle());
      assert::is_zero(control.height());
      assert::is_false(control.invoke_required());
      assert::is_true(control.is_handle_created());
      assert::is_zero(control.left());
      assert::are_equal(drawing::point::empty, control.location());
      assert::are_equal(forms::padding(3), control.margin());
      assert::are_equal(drawing::size::empty, control.maximum_client_size());
      assert::are_equal(drawing::size::empty, control.maximum_size());
      assert::are_equal(drawing::size::empty, control.minimum_client_size());
      assert::are_equal(drawing::size::empty, control.minimum_size());
      assert::is_not_zero(control.native_handle());
      assert::is_empty(control.name());
      assert::are_equal(forms::padding(0), control.padding());
      assert::are_equal(form, control.parent().value().get());
      assert::are_equal("xtd", control.product_name());
      assert::is_not_zero(control.region().handle());
      assert::is_zero(control.right());
      assert::are_equal(drawing::size::empty, control.size());
      assert::is_empty(control.style_sheet().theme().name());
      assert::is_true(control.tab_stop());
      assert::is_false(control.tag().has_value());
      assert::is_empty(control.text());
      assert::is_not_zero(control.toolkit_handle());
      assert::is_zero(control.top());
      assert::are_equal(form, control.top_level_control().value().get());
      assert::is_true(control.visible());
      assert::is_zero(control.width());
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls());
      assert::are_equal(keys::none, forms::control::modifier_keys());
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons());
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position());
    }
    
    auto test_method_(create_control_on_control_already_created) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      assert::is_true(control.created());
      assert::does_not_throw([&] {control.create_control();});
      assert::is_true(control.created());
    }
    
    auto test_method_(create_graphics_without_parent) {
      control_for_test control;
      assert::throws<invalid_operation_exception>([&] {control.create_graphics();});
    }
    
    auto test_method_(create_graphics_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      auto graphics = control.create_graphics();
      assert::is_not_zero(graphics.handle());
    }
    
    auto test_method_(destroy_control) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      assert::is_true(control.created());
      control.destroy_control();
      assert::is_false(control.created());
      assert::is_null(control.parent());
    }
    
    auto test_method_(focus_without_parent) {
      control_for_test control;
      assert::is_false(control.focus());
      assert::is_false(control.focused());
    }
    
    auto test_method_(focus_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      assert::is_true(control.focus());
      assert::is_true(control.focused());
    }
    
    auto test_method_(get_auto_size_mode) {
      control_for_test control;
      assert::are_equal(auto_size_mode::grow_and_shrink, control.get_auto_size_mode());
    }
    
    auto test_method_(get_child_index_without_parent) {
      control_for_test control;
      control_for_test control1;
      control_for_test control2;
      control_for_test control3;
      control_for_test control4;
      control.controls().add_range({control1, control2, control3});
      assert::are_equal(forms::control::control_collection::npos, control.get_child_index(control1.handle()));
      assert::are_equal(forms::control::control_collection::npos, control.get_child_index(control2.handle()));
      assert::are_equal(forms::control::control_collection::npos, control.get_child_index(control3.handle()));
      assert::are_equal(forms::control::control_collection::npos, control.get_child_index(control4.handle()));
    }
    
    auto test_method_(get_child_index_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control_for_test control1;
      control_for_test control2;
      control_for_test control3;
      control_for_test control4;
      control.controls().add_range({control1, control2, control3});
      assert::are_equal(0_z, control.get_child_index(control1.handle()));
      assert::are_equal(1_z, control.get_child_index(control2.handle()));
      assert::are_equal(2_z, control.get_child_index(control3.handle()));
      assert::are_equal(forms::control::control_collection::npos, control.get_child_index(control4.handle()));
    }
    
    auto test_method_(hide_without_parent) {
      control_for_test control;
      control.hide();
      assert::is_false(control.visible());
    }
    
    auto test_method_(hide_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.hide();
      assert::is_false(control.visible());
    }
    
    auto test_method_(resume_layout_after_suspend_layout) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.suspend_layout();
      assert::does_not_throw([&] {control.resume_layout();});
    }
    
    auto test_method_(resume_layout_without_suspend_layout) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      assert::does_not_throw([&] {control.resume_layout();});
    }
    
    auto test_method_(show_without_parent) {
      control_for_test control;
      control.visible(false);
      control.show();
      assert::is_true(control.visible());
    }
    
    auto test_method_(show_with_parent) {
      forms::form form;
      control_for_test control;
      control.parent(form);
      control.visible(false);
      control.show();
      assert::is_true(control.visible());
    }
    
    auto test_method_(to_string) {
      control_for_test control;
      assert::are_equal("xtd::forms::tests::control_tests::control_for_test", control.to_string());
    }
    
    auto test_method_(to_string_with_name) {
      control_for_test control;
      control.name("my_name");
      assert::are_equal("xtd::forms::tests::control_tests::control_for_test, name: my_name", control.to_string());
    }
    
    auto test_method_(to_string_with_text) {
      control_for_test control;
      control.text("my_text");
      assert::are_equal("xtd::forms::tests::control_tests::control_for_test, text: my_text", control.to_string());
    }
    
    auto test_method_(create_with_default_arguments) {
      auto control = control_for_test {};
      assert::is_null(control.parent());
      assert::is_zero(control.handle());
      assert::is_empty(control.text());
      assert::are_equal(drawing::point(0, 0), control.location());
      assert::are_equal(drawing::size(0, 0), control.size());
      assert::is_empty(control.name());
    }
    
    auto test_method_(from_child_handle) {
      forms::form form;
      control_for_test control1;
      control_for_test control2;
      control_for_test control3;
      control1.parent(form);
      control2.parent(control1);
      
      assert::is_null(forms::control::from_child_handle(form.handle()));
      assert::are_same(form, forms::control::from_child_handle(control1.handle()).value().get());
      assert::are_same(control1, forms::control::from_child_handle(control2.handle()).value().get());
      assert::is_null(forms::control::from_child_handle(control3.handle()));
      assert::is_null(forms::control::from_handle(1234));
    }
    
    auto test_method_(from_handle) {
      forms::form form;
      control_for_test control1;
      control_for_test control2;
      control_for_test control3;
      control1.parent(form);
      control2.parent(control1);
      
      assert::are_same(form, forms::control::from_handle(form.handle()).value().get());
      assert::are_same(control1, forms::control::from_handle(control1.handle()).value().get());
      assert::are_same(control2, forms::control::from_handle(control2.handle()).value().get());
      assert::is_null(forms::control::from_handle(control3.handle()));
      assert::is_null(forms::control::from_handle(1234));
    }
    
    auto test_method_(control_insertion_operator) {
      forms::form form;
      control_for_test control1;
      control_for_test control2;
      
      form << control1;
      control1 << control2;
      
      assert::is_null(form.parent());
      assert::are_same(form, control1.parent().value().get());
      assert::are_same(control1, control2.parent().value().get());
    }
    
    auto test_method_(control_extraction_operator) {
      forms::form form;
      control_for_test control1;
      control_for_test control2;
      
      control1.parent(form);
      control2.parent(control1);
      
      assert::is_null(form.parent());
      assert::are_same(form, control1.parent().value().get());
      assert::are_same(control1, control2.parent().value().get());
      
      control1 >> control2;
      form >> control1;
      
      assert::is_null(form.parent());
      assert::is_null(control1.parent());
      assert::is_null(control2.parent());
    }
    
    auto test_method_(auto_size_changed) {
      bool auto_size_changed_raised = false;
      control_for_test control;
      control.auto_size_changed += [&] {
        auto_size_changed_raised = true;
      };
      
      control.auto_size(false);
      assert::is_false(auto_size_changed_raised);
      control.auto_size(true);
      assert::is_true(auto_size_changed_raised);
    }
    
    auto test_method_(back_color_changed) {
      bool back_color_changed_raised = false;
      control_for_test control;
      control.back_color_changed += [&] {
        back_color_changed_raised = true;
      };
      
      control.back_color(nullptr);
      assert::is_false(back_color_changed_raised);
      control.back_color(color::spring_green);
      assert::is_true(back_color_changed_raised);
    }
    
    auto test_method_(background_image_changed) {
      bool background_image_changed_raised = false;
      control_for_test control;
      control.background_image_changed += [&] {
        background_image_changed_raised = true;
      };
      
      control.background_image(image::empty);
      assert::is_false(background_image_changed_raised);
      control.background_image(system_images::from_name("xtd"));
      assert::is_true(background_image_changed_raised);
    }
    
    auto test_method_(background_image_layout_changed) {
      bool background_image_layout_changed_raised = false;
      control_for_test control;
      control.background_image_layout_changed += [&] {
        background_image_layout_changed_raised = true;
      };
      
      control.background_image_layout(image_layout::tile);
      assert::is_false(background_image_layout_changed_raised);
      control.background_image_layout(image_layout::zoom);
      assert::is_true(background_image_layout_changed_raised);
    }
    
    auto test_method_(control_appearance_changed) {
      bool control_appearance_changed_raised = false;
      control_for_test control;
      control.control_appearance_changed += [&] {
        control_appearance_changed_raised = true;
      };
      
      control.control_appearance(forms::control_appearance::standard);
      assert::is_false(control_appearance_changed_raised);
      control.control_appearance(forms::control_appearance::system);
      assert::is_true(control_appearance_changed_raised);
    }
    
    auto test_method_(client_size_changed) {
      bool client_size_changed_raised = false;
      control_for_test control;
      control.client_size_changed += [&] {
        client_size_changed_raised = true;
      };
      
      //control.client_size({0, 0}); // Do not activate this line because if client_size is not activated, it will be activated even for an identical value.
      assert::is_false(client_size_changed_raised);
      control.client_size({100, 50});
      assert::is_true(client_size_changed_raised);
    }
    
    auto test_method_(control_added) {
      bool control_added_raised = false;
      control_for_test control;
      control.control_added += [&] {
        control_added_raised = true;
      };
      
      control_for_test child_control;
      assert::is_false(control_added_raised);
      control.controls().add(child_control);
      assert::is_true(control_added_raised);
    }
    
    auto test_method_(control_removed) {
      bool control_removed_raised = false;
      control_for_test control;
      control.control_removed += [&] {
        control_removed_raised = true;
      };
      
      control_for_test child_control;
      control.controls().add(child_control);
      assert::is_false(control_removed_raised);
      control.controls().remove_at(0);
      assert::is_true(control_removed_raised);
    }
    
    auto test_method_(cursor_changed) {
      bool cursor_changed_raised = false;
      control_for_test control;
      control.cursor_changed += [&] {
        cursor_changed_raised = true;
      };
      
      control.cursor(nullptr);
      assert::is_false(cursor_changed_raised);
      control.cursor(cursors::cross());
      assert::is_true(cursor_changed_raised);
    }
    
    auto test_method_(dock_changed) {
      bool dock_changed_raised = false;
      control_for_test control;
      control.dock_changed += [&] {
        dock_changed_raised = true;
      };
      
      control.dock(dock_style::none);
      assert::is_false(dock_changed_raised);
      control.dock(dock_style::fill);
      assert::is_true(dock_changed_raised);
    }
    
    auto test_method_(enabled_changed) {
      bool enabled_changed_raised = false;
      control_for_test control;
      control.enabled_changed += [&] {
        enabled_changed_raised = true;
      };
      
      control.enabled(true);
      assert::is_false(enabled_changed_raised);
      control.enabled(false);
      assert::is_true(enabled_changed_raised);
    }
    
    auto test_method_(fore_color_changed) {
      bool fore_color_changed_raised = false;
      control_for_test control;
      control.fore_color_changed += [&] {
        fore_color_changed_raised = true;
      };
      
      control.fore_color(nullptr);
      assert::is_false(fore_color_changed_raised);
      control.fore_color(color::spring_green);
      assert::is_true(fore_color_changed_raised);
    }
    
    auto test_method_(font_changed) {
      bool font_changed_raised = false;
      control_for_test control;
      control.font_changed += [&] {
        font_changed_raised = true;
      };
      
      control.font(nullptr);
      assert::is_false(font_changed_raised);
      control.font(system_fonts::tool_font());
      assert::is_true(font_changed_raised);
    }
    
    auto test_method_(handle_created) {
      bool handle_created_raised = false;
      control_for_test control;
      control.handle_created += [&] {
        handle_created_raised = true;
      };
      
      forms::form form;
      assert::is_false(handle_created_raised);
      control.parent(form);
      assert::is_true(handle_created_raised);
    }
    
    auto test_method_(handle_destroyed) {
      bool handle_destroyed_raised = false;
      control_for_test control;
      control.handle_destroyed += [&] {
        handle_destroyed_raised = true;
      };
      
      forms::form form;
      control.parent(form);
      assert::is_false(handle_destroyed_raised);
      control.parent(nullptr);
      assert::is_true(handle_destroyed_raised);
    }
    
    auto test_method_(layout) {
      bool layout_raised = false;
      control_for_test control;
      control.layout += [&] {
        layout_raised = true;
      };
      
      forms::form form;
      control.parent(form);
      layout_raised = false;
      assert::is_false(layout_raised);
      control.perform_layout();
      assert::is_true(layout_raised);
      
      layout_raised = false;
      assert::is_false(layout_raised);
      control.resume_layout();
      assert::is_true(layout_raised);
    }
    
    auto test_method_(location_changed) {
      bool location_changed_raised = false;
      control_for_test control;
      control.location_changed += [&] {
        location_changed_raised = true;
      };
      
      control.location({0, 0});
      assert::is_false(location_changed_raised);
      control.location({10, 20});
      assert::is_true(location_changed_raised);
    }
    
    auto test_method_(parent_changed) {
      bool parent_changed_raised = false;
      control_for_test control;
      control.parent_changed += [&] {
        parent_changed_raised = true;
      };
      forms::form form;
      
      control.parent(nullptr);
      assert::is_false(parent_changed_raised);
      control.parent(form);
      assert::is_true(parent_changed_raised);
      control.parent(nullptr);
      assert::is_true(parent_changed_raised);
    }
    
    auto test_method_(resize) {
      bool resize_raised = false;
      control_for_test control;
      control.resize += [&] {
        resize_raised = true;
      };
      
      control.size({0, 0});
      assert::is_false(resize_raised);
      control.size({100, 50});
      assert::is_true(resize_raised);
    }
    
    auto test_method_(region_changed) {
      bool region_changed_raised = false;
      control_for_test control;
      control.region_changed += [&] {
        region_changed_raised = true;
      };
      
      control.region(control.region());
      assert::is_false(region_changed_raised);
      control.region(xtd::drawing::region());
      assert::is_true(region_changed_raised);
    }
    
    auto test_method_(size_changed) {
      bool size_changed_raised = false;
      control_for_test control;
      control.size_changed += [&] {
        size_changed_raised = true;
      };
      
      control.size({0, 0});
      assert::is_false(size_changed_raised);
      control.size({100, 50});
      assert::is_true(size_changed_raised);
    }
    
    auto test_method_(tab_stop_changed) {
      bool tab_stop_changed_raised = false;
      control_for_test control;
      control.tab_stop_changed += [&] {
        tab_stop_changed_raised = true;
      };
      
      control.tab_stop(true);
      assert::is_false(tab_stop_changed_raised);
      control.tab_stop(false);
      assert::is_true(tab_stop_changed_raised);
    }
    
    auto test_method_(text_changed) {
      bool text_changed_raised = false;
      control_for_test control;
      control.text_changed += [&] {
        text_changed_raised = true;
      };
      
      control.text("");
      assert::is_false(text_changed_raised);
      control.text("Value");
      assert::is_true(text_changed_raised);
    }
    
    auto test_method_(visible_changed) {
      bool visible_changed_raised = false;
      control_for_test control;
      control.visible_changed += [&] {
        visible_changed_raised = true;
      };
      
      control.visible(true);
      assert::is_false(visible_changed_raised);
      control.visible(false);
      assert::is_true(visible_changed_raised);
    }
    
    auto test_method_(on_auto_size_changed) {
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
      assert::is_false(control.on_auto_size_changed_raised);
      control.auto_size(true);
      assert::is_true(control.on_auto_size_changed_raised);
    }
    
    auto test_method_(on_back_color_changed) {
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
      assert::is_false(control.on_back_color_changed_raised);
      control.back_color(color::spring_green);
      assert::is_true(control.on_back_color_changed_raised);
    }
    
    auto test_method_(on_background_image_changed) {
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
      assert::is_false(control.on_background_image_changed_raised);
      control.background_image(system_images::from_name("xtd"));
      assert::is_true(control.on_background_image_changed_raised);
    }
    
    auto test_method_(on_background_image_layout_changed) {
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
      assert::is_false(control.on_background_image_layout_changed_raised);
      control.background_image_layout(image_layout::zoom);
      assert::is_true(control.on_background_image_layout_changed_raised);
    }
    
    auto test_method_(on_control_appearance_changed) {
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
      assert::is_false(control.on_control_appearance_changed_raised);
      control.control_appearance(forms::control_appearance::system);
      assert::is_true(control.on_control_appearance_changed_raised);
    }
    
    auto test_method_(on_client_size_changed) {
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
      assert::is_false(control.on_client_size_changed_raised);
      control.client_size({100, 50});
      assert::is_true(control.on_client_size_changed_raised);
    }
    
    auto test_method_(on_control_added) {
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
      assert::is_false(control.on_control_added_raised);
      control.controls().add(child_control);
      assert::is_true(control.on_control_added_raised);
    }
    
    auto test_method_(on_control_removed) {
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
      control.controls().add(child_control);
      assert::is_false(control.on_control_removed_raised);
      control.controls().remove_at(0);
      assert::is_true(control.on_control_removed_raised);
    }
    
    auto test_method_(on_create_control) {
      class control_for_test : public control {
      public:
        control_for_test() = default;
        bool on_create_control_raised = false;
        
        // trick for forcing post message to be sent...
        void do_events() {
          auto m = message::create(handle(), WM_NULL, 0, 0);
          wnd_proc(m);
        }
        
      protected:
        void on_create_control() override {
          control::on_create_control();
          on_create_control_raised = true;
        };
      };
      control_for_test control;
      
      forms::form form;
      control.parent(nullptr);
      assert::is_false(control.on_create_control_raised);
      control.parent(form);
      control.do_events();
      assert::is_true(control.on_create_control_raised);
    }
    
    auto test_method_(on_cursor_changed) {
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
      assert::is_false(control.on_cursor_changed_raised);
      control.cursor(cursors::cross());
      assert::is_true(control.on_cursor_changed_raised);
    }
    
    auto test_method_(on_dock_changed) {
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
      assert::is_false(control.on_dock_changed_raised);
      control.dock(dock_style::fill);
      assert::is_true(control.on_dock_changed_raised);
    }
    
    auto test_method_(on_enabled_changed) {
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
      assert::is_false(control.on_enabled_changed_raised);
      control.enabled(false);
      assert::is_true(control.on_enabled_changed_raised);
    }
    
    auto test_method_(on_fore_color_changed) {
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
      assert::is_false(control.on_fore_color_changed_raised);
      control.fore_color(color::spring_green);
      assert::is_true(control.on_fore_color_changed_raised);
    }
    
    auto test_method_(on_font_changed) {
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
      assert::is_false(control.on_font_changed_raised);
      control.font(system_fonts::tool_font());
      assert::is_true(control.on_font_changed_raised);
    }
    
    auto test_method_(on_handle_created) {
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
      assert::is_false(control.on_handle_created_raised);
      control.parent(form);
      assert::is_true(control.on_handle_created_raised);
    }
    
    auto test_method_(on_handle_destroyed) {
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
      assert::is_false(control.on_handle_destroyed_raised);
      control.parent(nullptr);
      assert::is_true(control.on_handle_destroyed_raised);
    }
    
    auto test_method_(on_layout) {
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
      assert::is_false(control.on_layout_raised);
      control.perform_layout();
      assert::is_true(control.on_layout_raised);
      
      control.on_layout_raised = false;
      assert::is_false(control.on_layout_raised);
      control.resume_layout();
      assert::is_true(control.on_layout_raised);
    }
    
    auto test_method_(on_location_changed) {
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
      assert::is_false(control.on_location_changed_raised);
      control.location({10, 20});
      assert::is_true(control.on_location_changed_raised);
    }
    
    auto test_method_(on_parent_back_color_changed) {
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
      assert::is_true(control.on_parent_back_color_changed_raised); // Form has back color...
      control.on_parent_back_color_changed_raised = false;
      form.back_color(color::spring_green);
      assert::is_true(control.on_parent_back_color_changed_raised);
    }
    
    auto test_method_(on_parent_cursor_changed) {
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
      assert::is_false(control.on_parent_cursor_changed_raised);
      form.cursor(cursors::cross());
      assert::is_true(control.on_parent_cursor_changed_raised);
    }
    
    auto test_method_(on_parent_changed) {
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
      assert::is_false(control.on_parent_changed_raised);
      control.parent(form);
      assert::is_true(control.on_parent_changed_raised);
      control.parent(nullptr);
      assert::is_true(control.on_parent_changed_raised);
    }
    
    auto test_method_(on_parent_enabled_changed) {
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
      assert::is_false(control.on_parent_enabled_changed_raised);
      form.enabled(false);
      assert::is_true(control.on_parent_enabled_changed_raised);
    }
    
    auto test_method_(on_parent_fore_color_changed) {
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
      assert::is_true(control.on_parent_fore_color_changed_raised); // Form has fore color...
      control.on_parent_fore_color_changed_raised = false;
      form.fore_color(color::spring_green);
      assert::is_true(control.on_parent_fore_color_changed_raised);
    }
    
    auto test_method_(on_parent_font_changed) {
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
      assert::is_false(control.on_parent_font_changed_raised);
      form.font({form.font(), 32});
      assert::is_true(control.on_parent_font_changed_raised);
    }
    
    auto test_method_(on_resize) {
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
      assert::is_false(control.on_resize_raised);
      control.size({100, 50});
      assert::is_true(control.on_resize_raised);
    }
    
    auto test_method_(on_region_changed) {
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
      assert::is_false(control.on_region_changed_raised);
      control.region(xtd::drawing::region());
      assert::is_true(control.on_region_changed_raised);
    }
    
    auto test_method_(on_size_changed) {
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
      assert::is_false(control.on_size_changed_raised);
      control.size({100, 50});
      assert::is_true(control.on_size_changed_raised);
    }
    
    auto test_method_(on_tab_stop_changed) {
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
      assert::is_false(control.on_tab_stop_changed_raised);
      control.tab_stop(false);
      assert::is_true(control.on_tab_stop_changed_raised);
    }
    
    auto test_method_(on_text_changed) {
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
      assert::is_false(control.on_text_changed_raised);
      control.text("Value");
      assert::is_true(control.on_text_changed_raised);
    }
    
    auto test_method_(on_visible_changed) {
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
      assert::is_false(control.on_visible_changed_raised);
      control.visible(false);
      assert::is_true(control.on_visible_changed_raised);
    }
    
    auto test_method_(recreate_handle) {
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
      assert::are_not_equal(initial_handle, control.handle());
    }
    
    auto test_method_(controls_add_controls_with_controls_add) {
      forms::form form;
      control_for_test control;
      control_for_test control1;
      control_for_test control2;
      control_for_test control3;
      
      control.parent(form);
      
      control.controls().add_range({control1, control2, control3});
      assert::are_equal(3u, control.controls().count());
      assert::is_not_zero(control1.handle());
      assert::is_not_zero(control2.handle());
      assert::is_not_zero(control3.handle());
      assert::are_equal(control, control1.parent());
      assert::are_equal(control, control2.parent());
      assert::are_equal(control, control3.parent());
      assert::are_equal(control1, control.controls()[0].get());
      assert::are_equal(control2, control.controls()[1].get());
      assert::are_equal(control3, control.controls()[2].get());
    }
    
    auto test_method_(controls_add_controls_with_control_parent_and_controls_add) {
      forms::form form;
      control_for_test control;
      control_for_test control1;
      control_for_test control2;
      control_for_test control3;
      
      control.parent(form);
      control1.parent(control);
      control.controls().add_range({control1, control2, control3});
      assert::are_equal(3u, control.controls().count());
      assert::is_not_zero(control1.handle());
      assert::is_not_zero(control2.handle());
      assert::is_not_zero(control3.handle());
      assert::are_equal(control, control1.parent());
      assert::are_equal(control, control2.parent());
      assert::are_equal(control, control3.parent());
      assert::are_equal(control1, control.controls()[0].get());
      assert::are_equal(control2, control.controls()[1].get());
      assert::are_equal(control3, control.controls()[2].get());
    }
    
    auto test_method_(controls_remove_controls) {
      forms::form form;
      control_for_test control;
      control_for_test control1;
      control_for_test control2;
      control_for_test control3;
      control.parent(form);
      
      control.controls().add_range({control1, control2, control3});
      control2.parent(nullptr);
      assert::are_equal(2u, control.controls().count());
      assert::are_same(control1, control.controls()[0].get());
      assert::are_same(control3, control.controls()[1].get());
    }
  };
}
