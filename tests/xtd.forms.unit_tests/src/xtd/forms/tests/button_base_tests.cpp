#include <xtd/forms/button>
#include <xtd/drawing/system_images>
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
  class test_class_(button_base_tests) {
    class button_base_for_test : public button_base {
    public:
      button_base_for_test() = default;
      
      bool on_image_changed_raised = false;
      void on_image_changed(const xtd::event_args& e) override {
        button_base::on_image_changed(e);
        on_image_changed_raised = true;
      }
      
      using button_base::default_back_color;
      using button_base::default_cursor;
      using button_base::default_font;
      using button_base::default_fore_color;
      using button_base::default_size;
    };
    
    void test_method_(constructor) {
      button_base_for_test button;
      assert::are_equal(anchor_styles::left | anchor_styles::top, button.anchor(), csf_);
      assert::are_equal(drawing::point::empty, button.auto_scroll_point(), csf_);
      assert::is_false(button.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), button.back_color(), csf_);
      assert::are_equal(drawing::image::empty, button.background_image(), csf_);
      assert::are_equal(image_layout::tile, button.background_image_layout(), csf_);
      assert::is_zero(button.bottom(), csf_);
      assert::are_equal(drawing::rectangle::empty, button.bounds(), csf_);
      assert::is_false(button.can_focus(), csf_);
      assert::is_true(button.can_raise_events(), csf_);
      assert::is_true(button.can_select(), csf_);
      assert::are_equal(drawing::rectangle::empty, button.client_rectangle(), csf_);
      assert::are_equal(drawing::size::empty, button.client_size(), csf_);
      assert::are_equal("Gammasoft", button.company_name(), csf_);
      assert::is_null(button.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, button.control_appearance(), csf_);
      assert::is_empty(button.controls(), csf_);
      assert::is_false(button.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), button.cursor(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), button.default_back_color(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), button.default_cursor(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), button.default_font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), button.default_fore_color(), csf_);
      assert::are_equal(drawing::size::empty, button.default_size(), csf_);
      assert::are_equal(drawing::rectangle::empty, button.display_rectangle(), csf_);
      assert::are_equal(forms::dock_style::none, button.dock(), csf_);
      assert::is_false(button.double_buffered(), csf_);
      assert::is_true(button.enabled(), csf_);
      assert::is_false(button.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), button.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), button.fore_color(), csf_);
      assert::is_zero(button.handle(), csf_);
      assert::is_zero(button.height(), csf_);
      assert::is_false(button.invoke_required(), csf_);
      assert::is_false(button.is_handle_created(), csf_);
      assert::is_zero(button.left(), csf_);
      assert::are_equal(drawing::point::empty, button.location(), csf_);
      assert::are_equal(forms::padding(3), button.margin(), csf_);
      assert::are_equal(drawing::size::empty, button.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, button.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, button.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, button.minimum_size(), csf_);
      assert::is_zero(button.native_handle(), csf_);
      assert::is_empty(button.name(), csf_);
      assert::are_equal(forms::padding(0), button.padding(), csf_);
      assert::is_null(button.parent(), csf_);
      assert::are_equal("xtd", button.product_name(), csf_);
      assert::is_not_zero(button.region().handle(), csf_);
      assert::is_zero(button.right(), csf_);
      assert::are_equal(drawing::size::empty, button.size(), csf_);
      assert::is_empty(button.style_sheet().theme().name(), csf_);
      assert::is_true(button.tab_stop(), csf_);
      assert::is_false(button.tag().has_value(), csf_);
      assert::is_empty(button.text(), csf_);
      assert::is_zero(button.toolkit_handle(), csf_);
      assert::is_zero(button.top(), csf_);
      assert::is_null(button.top_level_control(), csf_);
      assert::is_true(button.visible(), csf_);
      assert::is_zero(button.width(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
      
      assert::is_false(button.auto_ellipsis(), csf_);
      assert::are_equal(flat_button_appearance(), button.flat_appearance(), csf_);
      assert::are_equal(flat_style::standard, button.flat_style(), csf_);
      assert::are_equal(image::empty, button.image(), csf_);
      assert::are_equal(content_alignment::middle_center, button.image_align(), csf_);
      assert::are_equal(-1, button.image_index(), csf_);
      assert::are_equal(image_list::empty, button.image_list(), csf_);
      assert::are_equal(content_alignment::middle_center, button.text_align(), csf_);
    }
    
    void test_method_(auto_elipsis_without_parent) {
      button_base_for_test button;
      button.auto_ellipsis(true);
      assert::is_true(button.auto_ellipsis(), csf_);
    }
    
    void test_method_(auto_elipsis_with_parent) {
      forms::form form;
      button_base_for_test button;
      button.parent(form);
      button.auto_ellipsis(true);
      assert::is_true(button.auto_ellipsis(), csf_);
    }
    
    void test_method_(auto_size_without_parent) {
      button_base_for_test button;
      button.auto_size(true);
      assert::is_true(button.auto_size(), csf_);
    }
    
    void test_method_(auto_size_with_parent) {
      forms::form form;
      button_base_for_test button;
      button.parent(form);
      button.auto_size(true);
      assert::is_true(button.auto_size(), csf_);
    }
    
    void test_method_(control_appearance_without_parent) {
      button_base_for_test button;
      button.control_appearance(xtd::forms::control_appearance::system);
      assert::are_equal(xtd::forms::control_appearance::system, button.control_appearance(), csf_);
      assert::are_equal(xtd::forms::flat_style::system, button.flat_style(), csf_);
      
      button.control_appearance(xtd::forms::control_appearance::standard);
      assert::are_equal(xtd::forms::control_appearance::standard, button.control_appearance(), csf_);
      assert::are_equal(xtd::forms::flat_style::standard, button.flat_style(), csf_);
    }
    
    void test_method_(control_appearance_with_parent) {
      forms::form form;
      button_base_for_test button;
      button.parent(form);
      button.control_appearance(xtd::forms::control_appearance::system);
      assert::are_equal(xtd::forms::control_appearance::system, button.control_appearance(), csf_);
      assert::are_equal(xtd::forms::flat_style::system, button.flat_style(), csf_);
      
      button.control_appearance(xtd::forms::control_appearance::standard);
      assert::are_equal(xtd::forms::control_appearance::standard, button.control_appearance(), csf_);
      assert::are_equal(xtd::forms::flat_style::standard, button.flat_style(), csf_);
    }
    
    void test_method_(flat_appearance_without_parent) {
      button_base_for_test button;
      auto appearance = flat_button_appearance().border_color(drawing::color::spring_green);
      button.flat_appearance(appearance);
      assert::are_equal(appearance, button.flat_appearance(), csf_);
      assert::are_equal(drawing::color::spring_green, button.flat_appearance().border_color(), csf_);
    }
    
    void test_method_(flat_appearance_with_parent) {
      forms::form form;
      button_base_for_test button;
      button.parent(form);
      auto appearance = flat_button_appearance().border_color(drawing::color::spring_green);
      button.flat_appearance(appearance);
      assert::are_equal(appearance, button.flat_appearance(), csf_);
      assert::are_equal(drawing::color::spring_green, button.flat_appearance().border_color(), csf_);
    }
    
    void test_method_(flat_style_without_parent) {
      button_base_for_test button;
      button.flat_style(xtd::forms::flat_style::flat);
      assert::are_equal(xtd::forms::flat_style::flat, button.flat_style(), csf_);
      assert::are_equal(xtd::forms::control_appearance::standard, button.control_appearance(), csf_);
      
      button.flat_style(xtd::forms::flat_style::system);
      assert::are_equal(xtd::forms::flat_style::system, button.flat_style(), csf_);
      assert::are_equal(xtd::forms::control_appearance::system, button.control_appearance(), csf_);
    }
    
    void test_method_(flat_style_with_parent) {
      forms::form form;
      button_base_for_test button;
      button.parent(form);
      button.flat_style(xtd::forms::flat_style::flat);
      assert::are_equal(xtd::forms::flat_style::flat, button.flat_style(), csf_);
      assert::are_equal(xtd::forms::control_appearance::standard, button.control_appearance(), csf_);
      
      button.flat_style(xtd::forms::flat_style::system);
      assert::are_equal(xtd::forms::flat_style::system, button.flat_style(), csf_);
      assert::are_equal(xtd::forms::control_appearance::system, button.control_appearance(), csf_);
    }
    
    void test_method_(image_changed) {
      bool image_changed_raised = false;
      button_base_for_test button;
      button.image_changed += [&]() {
        image_changed_raised = true;
      };
      
      button.image(image::empty);
      assert::is_false(image_changed_raised, csf_);
      button.image(system_images::from_name("xtd"));
      assert::is_true(image_changed_raised, csf_);
    }
    
    void test_method_(on_image_changed) {
      button_base_for_test button;
      
      button.image(image::empty);
      assert::is_false(button.on_image_changed_raised, csf_);
      button.image(system_images::from_name("xtd"));
      assert::is_true(button.on_image_changed_raised, csf_);
    }
  };
}
