#include <xtd/forms/progress_bar>
#include <xtd/forms/form>
#include <xtd/diagnostics/debugger>
#include <xtd/tunit/assert>
#include <xtd/tunit/valid>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(progress_bar_tests) {
    class progress_bar_for_test : public progress_bar {
    public:
      progress_bar_for_test() = default;
      
      using progress_bar::default_back_color;
      using progress_bar::default_cursor;
      using progress_bar::default_font;
      using progress_bar::default_fore_color;
      using progress_bar::default_size;
    };
    
    void test_method_(constructor) {
      progress_bar_for_test progress_bar;
      assert::are_equal(anchor_styles::left | anchor_styles::top, progress_bar.anchor(), csf_);
      assert::are_equal(drawing::point::empty, progress_bar.auto_scroll_point(), csf_);
      assert::is_false(progress_bar.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), progress_bar.back_color(), csf_);
      assert::are_equal(drawing::image::empty, progress_bar.background_image(), csf_);
      assert::are_equal(image_layout::tile, progress_bar.background_image_layout(), csf_);
      assert::are_equal(progress_bar.default_size().height(), progress_bar.bottom(), csf_);
      assert::are_equal(drawing::rectangle({0, 0}, progress_bar.default_size()), progress_bar.bounds(), csf_);
      assert::is_false(progress_bar.can_focus(), csf_);
      assert::is_true(progress_bar.can_raise_events(), csf_);
      assert::is_false(progress_bar.can_select(), csf_);
      assert::are_equal(drawing::rectangle({0, 0}, progress_bar.default_size()), progress_bar.client_rectangle(), csf_);
      assert::are_equal(progress_bar.default_size(), progress_bar.client_size(), csf_);
      assert::are_equal("Gammasoft", progress_bar.company_name(), csf_);
      assert::is_null(progress_bar.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::system, progress_bar.control_appearance(), csf_);
      assert::is_empty(progress_bar.controls(), csf_);
      assert::is_false(progress_bar.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), progress_bar.cursor(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), progress_bar.default_back_color(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), progress_bar.default_cursor(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), progress_bar.default_font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), progress_bar.default_fore_color(), csf_);
      assert::are_equal(progress_bar.default_size(), progress_bar.default_size(), csf_);
      assert::are_equal(drawing::rectangle({0, 0}, progress_bar.default_size()), progress_bar.display_rectangle(), csf_);
      assert::are_equal(forms::dock_style::none, progress_bar.dock(), csf_);
      assert::is_false(progress_bar.double_buffered(), csf_);
      assert::is_true(progress_bar.enabled(), csf_);
      assert::is_false(progress_bar.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), progress_bar.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), progress_bar.fore_color(), csf_);
      assert::is_zero(progress_bar.handle(), csf_);
      assert::are_equal(progress_bar.default_size().height(), progress_bar.height(), csf_);
      assert::is_false(progress_bar.invoke_required(), csf_);
      assert::is_false(progress_bar.is_handle_created(), csf_);
      assert::is_zero(progress_bar.left(), csf_);
      assert::are_equal(drawing::point::empty, progress_bar.location(), csf_);
      assert::are_equal(forms::padding(3), progress_bar.margin(), csf_);
      assert::are_equal(drawing::size::empty, progress_bar.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, progress_bar.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, progress_bar.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, progress_bar.minimum_size(), csf_);
      assert::is_zero(progress_bar.native_handle(), csf_);
      assert::is_empty(progress_bar.name(), csf_);
      assert::are_equal(forms::padding(0), progress_bar.padding(), csf_);
      assert::is_null(progress_bar.parent(), csf_);
      assert::are_equal("xtd", progress_bar.product_name(), csf_);
      assert::is_not_zero(progress_bar.region().handle(), csf_);
      assert::are_equal(progress_bar.default_size().width(), progress_bar.right(), csf_);
      assert::are_equal(progress_bar.default_size(), progress_bar.size(), csf_);
      assert::is_empty(progress_bar.style_sheet().theme().name(), csf_);
      assert::is_true(progress_bar.tab_stop(), csf_);
      assert::is_false(progress_bar.tag().has_value(), csf_);
      assert::is_empty(progress_bar.text(), csf_);
      assert::is_zero(progress_bar.toolkit_handle(), csf_);
      assert::is_zero(progress_bar.top(), csf_);
      assert::is_null(progress_bar.top_level_control(), csf_);
      assert::is_true(progress_bar.visible(), csf_);
      assert::are_equal(progress_bar.default_size().width(), progress_bar.width(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
      
      assert::are_equal(100u, progress_bar.marquee_animation_speed(), csf_);
      assert::are_equal(100, progress_bar.maximum(), csf_);
      assert::is_zero(progress_bar.minimum(), csf_);
      assert::are_equal(orientation::horizontal, progress_bar.orientation(), csf_);
      assert::are_equal(10, progress_bar.step(), csf_);
      assert::are_equal(progress_bar_style::blocks, progress_bar.style(), csf_);
      assert::is_zero(progress_bar.value(), csf_);
    }
    
    void test_method_(set_animation_speed) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100u, progress_bar.marquee_animation_speed(), csf_);
      
      progress_bar.marquee_animation_speed(50u);
      assert::are_equal(50u, progress_bar.marquee_animation_speed(), csf_);
    }
    
    void test_method_(set_maximum) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum(), csf_);
      valid::is_zero(progress_bar.minimum(), csf_);
      valid::is_zero(progress_bar.value(), csf_);
      
      progress_bar.maximum(10);
      assert::are_equal(10, progress_bar.maximum(), csf_);
      assert::is_zero(progress_bar.minimum(), csf_);
      assert::is_zero(progress_bar.value(), csf_);
    }
    
    void test_method_(set_maximum_less_than_minimum) {
      progress_bar_for_test progress_bar;
      progress_bar.maximum(200);
      progress_bar.minimum(100);
      valid::are_equal(200, progress_bar.maximum(), csf_);
      valid::are_equal(100, progress_bar.minimum(), csf_);
      valid::are_equal(100, progress_bar.value(), csf_);
      
      progress_bar.maximum(50);
      assert::are_equal(50, progress_bar.maximum(), csf_);
      assert::are_equal(50, progress_bar.minimum(), csf_);
      assert::are_equal(50, progress_bar.value(), csf_);
    }
    
    void test_method_(set_minimum) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum(), csf_);
      valid::is_zero(progress_bar.minimum(), csf_);
      valid::is_zero(progress_bar.value(), csf_);
      
      progress_bar.minimum(10);
      assert::are_equal(100, progress_bar.maximum(), csf_);
      assert::are_equal(10, progress_bar.minimum(), csf_);
      assert::are_equal(10, progress_bar.value(), csf_);
    }
    
    void test_method_(set_minimum_greather_than_maximum) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum(), csf_);
      valid::is_zero(progress_bar.minimum(), csf_);
      valid::is_zero(progress_bar.value(), csf_);
      
      progress_bar.minimum(200);
      assert::are_equal(200, progress_bar.maximum(), csf_);
      assert::are_equal(200, progress_bar.minimum(), csf_);
      assert::are_equal(200, progress_bar.value(), csf_);
    }
    
    void test_method_(set_orientation_vertical) {
      progress_bar_for_test progress_bar;
      valid::are_equal(orientation::horizontal, progress_bar.orientation(), csf_);
      
      progress_bar.orientation(forms::orientation::vertical);
      assert::are_equal(orientation::vertical, progress_bar.orientation(), csf_);
    }
    
    void test_method_(set_orientation_with_invalid_orientation) {
      progress_bar_for_test progress_bar;
      valid::are_equal(orientation::horizontal, progress_bar.orientation(), csf_);
      
      assert::throws<argument_out_of_range_exception>([&] {progress_bar.orientation(as<forms::orientation>(2));}, csf_);
    }
    
    void test_method_(set_step_1) {
      progress_bar_for_test progress_bar;
      valid::are_equal(10, progress_bar.step(), csf_);
      
      progress_bar.step(1);
      assert::are_equal(1, progress_bar.step(), csf_);
    }
    
    void test_method_(set_step_50) {
      progress_bar_for_test progress_bar;
      valid::are_equal(10, progress_bar.step(), csf_);
      
      progress_bar.step((50));
      assert::are_equal(50, progress_bar.step(), csf_);
    }
    
    void test_method_(set_style_continuous) {
      progress_bar_for_test progress_bar;
      valid::are_equal(progress_bar_style::blocks, progress_bar.style(), csf_);
      
      progress_bar.style(progress_bar_style::continuous);
      assert::are_equal(progress_bar_style::continuous, progress_bar.style(), csf_);
    }
    
    void test_method_(set_style_marquee) {
      progress_bar_for_test progress_bar;
      valid::are_equal(progress_bar_style::blocks, progress_bar.style(), csf_);
      
      progress_bar.style(progress_bar_style::marquee);
      assert::are_equal(progress_bar_style::marquee, progress_bar.style(), csf_);
    }
    
    void test_method_(set_style_with_invalid_style) {
      progress_bar_for_test progress_bar;
      valid::are_equal(progress_bar_style::blocks, progress_bar.style(), csf_);
      
      assert::throws<argument_out_of_range_exception>([&] {progress_bar.style(as<progress_bar_style>(3));}, csf_);
    }
    
    void test_method_(set_value_in_range) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum(), csf_);
      valid::is_zero(progress_bar.minimum(), csf_);
      valid::is_zero(progress_bar.value(), csf_);
      
      progress_bar.value(10);
      assert::are_equal(100, progress_bar.maximum(), csf_);
      assert::is_zero(progress_bar.minimum(), csf_);
      assert::are_equal(10, progress_bar.value(), csf_);
    }
    
    void test_method_(set_value_out_range) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum(), csf_);
      valid::is_zero(progress_bar.minimum(), csf_);
      valid::is_zero(progress_bar.value(), csf_);
      
      progress_bar.value(110);
      assert::are_equal(100, progress_bar.maximum(), csf_);
      assert::is_zero(progress_bar.minimum(), csf_);
      assert::are_equal(progress_bar.maximum(), progress_bar.value(), csf_);
      
      progress_bar.value(-10);
      assert::are_equal(100, progress_bar.maximum(), csf_);
      assert::is_zero(progress_bar.minimum(), csf_);
      assert::are_equal(progress_bar.minimum(), progress_bar.value(), csf_);
    }
    
    void test_method_(set_increment) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum(), csf_);
      valid::is_zero(progress_bar.minimum(), csf_);
      valid::is_zero(progress_bar.value(), csf_);
      
      progress_bar.increment(1);
      assert::are_equal(100, progress_bar.maximum(), csf_);
      assert::is_zero(progress_bar.minimum(), csf_);
      assert::are_equal(1, progress_bar.value(), csf_);
    }
    
    void test_method_(set_increments) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum(), csf_);
      valid::is_zero(progress_bar.minimum(), csf_);
      valid::is_zero(progress_bar.value(), csf_);
      
      progress_bar.increment(1);
      assert::are_equal(100, progress_bar.maximum(), csf_);
      assert::is_zero(progress_bar.minimum(), csf_);
      assert::are_equal(1, progress_bar.value(), csf_);
      
      progress_bar.increment(5);
      assert::are_equal(100, progress_bar.maximum(), csf_);
      assert::is_zero(progress_bar.minimum(), csf_);
      assert::are_equal(6, progress_bar.value(), csf_);
      
      progress_bar.increment(10);
      assert::are_equal(100, progress_bar.maximum(), csf_);
      assert::is_zero(progress_bar.minimum(), csf_);
      assert::are_equal(16, progress_bar.value(), csf_);
    }
    
    void test_method_(set_increment_out_of_range) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum(), csf_);
      valid::is_zero(progress_bar.minimum(), csf_);
      valid::is_zero(progress_bar.value(), csf_);
      
      progress_bar.increment(110);
      assert::are_equal(100, progress_bar.maximum(), csf_);
      assert::is_zero(progress_bar.minimum(), csf_);
      assert::are_equal(progress_bar.maximum(), progress_bar.value(), csf_);
    }
    
    void test_method_(set_perform_step) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum(), csf_);
      valid::is_zero(progress_bar.minimum(), csf_);
      valid::is_zero(progress_bar.value(), csf_);
      valid::are_equal(10, progress_bar.step(), csf_);
      
      progress_bar.perform_step();
      assert::are_equal(100, progress_bar.maximum(), csf_);
      assert::is_zero(progress_bar.minimum(), csf_);
      assert::are_equal(10, progress_bar.value(), csf_);
    }
    
    void test_method_(set_perform_steps) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum(), csf_);
      valid::is_zero(progress_bar.minimum(), csf_);
      valid::is_zero(progress_bar.value(), csf_);
      valid::are_equal(10, progress_bar.step(), csf_);
      
      progress_bar.perform_step();
      assert::are_equal(100, progress_bar.maximum(), csf_);
      assert::is_zero(progress_bar.minimum(), csf_);
      assert::are_equal(10, progress_bar.value(), csf_);
      
      progress_bar.perform_step();
      progress_bar.perform_step();
      assert::are_equal(100, progress_bar.maximum(), csf_);
      assert::is_zero(progress_bar.minimum(), csf_);
      assert::are_equal(30, progress_bar.value(), csf_);
      
      progress_bar.perform_step();
      progress_bar.perform_step();
      progress_bar.perform_step();
      progress_bar.perform_step();
      progress_bar.perform_step();
      progress_bar.perform_step();
      progress_bar.perform_step();
      progress_bar.perform_step();
      assert::are_equal(100, progress_bar.maximum(), csf_);
      assert::is_zero(progress_bar.minimum(), csf_);
      assert::are_equal(progress_bar.maximum(), progress_bar.value(), csf_);
    }
    
    void test_method_(set_perform_steps_with_step_20) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum(), csf_);
      valid::is_zero(progress_bar.minimum(), csf_);
      valid::is_zero(progress_bar.value(), csf_);
      valid::are_equal(10, progress_bar.step(), csf_);
      
      progress_bar.step(20);
      valid::are_equal(20, progress_bar.step(), csf_);
      
      progress_bar.perform_step();
      assert::are_equal(100, progress_bar.maximum(), csf_);
      assert::is_zero(progress_bar.minimum(), csf_);
      assert::are_equal(20, progress_bar.value(), csf_);
      
      progress_bar.perform_step();
      progress_bar.perform_step();
      assert::are_equal(100, progress_bar.maximum(), csf_);
      assert::is_zero(progress_bar.minimum(), csf_);
      assert::are_equal(60, progress_bar.value(), csf_);
      
      progress_bar.perform_step();
      progress_bar.perform_step();
      progress_bar.perform_step();
      assert::are_equal(100, progress_bar.maximum(), csf_);
      assert::is_zero(progress_bar.minimum(), csf_);
      assert::are_equal(progress_bar.maximum(), progress_bar.value(), csf_);
    }
    
    void test_method_(set_range) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum(), csf_);
      valid::is_zero(progress_bar.minimum(), csf_);
      valid::is_zero(progress_bar.value(), csf_);
      
      progress_bar.set_range(100, 200);
      assert::are_equal(200, progress_bar.maximum(), csf_);
      assert::are_equal(100, progress_bar.minimum(), csf_);
      assert::are_equal(100, progress_bar.value(), csf_);
    }
  };
}
