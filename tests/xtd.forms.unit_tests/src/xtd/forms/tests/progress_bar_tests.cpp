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
    
    auto test_method_(constructor) {
      progress_bar_for_test progress_bar;
      assert::are_equal(anchor_styles::left | anchor_styles::top, progress_bar.anchor());
      assert::are_equal(drawing::point::empty, progress_bar.auto_scroll_point());
      assert::is_false(progress_bar.auto_size());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), progress_bar.back_color());
      assert::are_equal(drawing::image::empty, progress_bar.background_image());
      assert::are_equal(image_layout::tile, progress_bar.background_image_layout());
      assert::are_equal(progress_bar.default_size().height, progress_bar.bottom());
      assert::are_equal(drawing::rectangle({0, 0}, progress_bar.default_size()), progress_bar.bounds());
      assert::is_false(progress_bar.can_focus());
      assert::is_true(progress_bar.can_raise_events());
      assert::is_false(progress_bar.can_select());
      assert::are_equal(drawing::rectangle({0, 0}, progress_bar.default_size()), progress_bar.client_rectangle());
      assert::are_equal(progress_bar.default_size(), progress_bar.client_size());
      assert::are_equal("Gammasoft", progress_bar.company_name());
      assert::is_null(progress_bar.context_menu());
      assert::are_equal(forms::control_appearance::system, progress_bar.control_appearance());
      assert::is_empty(progress_bar.controls());
      assert::is_false(progress_bar.created());
      assert::are_equal(forms::cursors::default_cursor(), progress_bar.cursor());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), progress_bar.default_back_color());
      assert::are_equal(forms::cursors::default_cursor(), progress_bar.default_cursor());
      assert::are_equal(drawing::system_fonts::default_font(), progress_bar.default_font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), progress_bar.default_fore_color());
      assert::are_equal(progress_bar.default_size(), progress_bar.default_size());
      assert::are_equal(drawing::rectangle({0, 0}, progress_bar.default_size()), progress_bar.display_rectangle());
      assert::are_equal(forms::dock_style::none, progress_bar.dock());
      assert::is_false(progress_bar.double_buffered());
      assert::is_true(progress_bar.enabled());
      assert::is_false(progress_bar.focused());
      assert::are_equal(drawing::system_fonts::default_font(), progress_bar.font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), progress_bar.fore_color());
      assert::is_zero(progress_bar.handle());
      assert::are_equal(progress_bar.default_size().height, progress_bar.height());
      assert::is_false(progress_bar.invoke_required());
      assert::is_false(progress_bar.is_handle_created());
      assert::is_zero(progress_bar.left());
      assert::are_equal(drawing::point::empty, progress_bar.location());
      assert::are_equal(forms::padding(3), progress_bar.margin());
      assert::are_equal(drawing::size::empty, progress_bar.maximum_client_size());
      assert::are_equal(drawing::size::empty, progress_bar.maximum_size());
      assert::are_equal(drawing::size::empty, progress_bar.minimum_client_size());
      assert::are_equal(drawing::size::empty, progress_bar.minimum_size());
      assert::is_zero(progress_bar.native_handle());
      assert::is_empty(progress_bar.name());
      assert::are_equal(forms::padding(0), progress_bar.padding());
      assert::is_null(progress_bar.parent());
      assert::are_equal("xtd", progress_bar.product_name());
      assert::is_not_zero(progress_bar.region().handle());
      assert::are_equal(progress_bar.default_size().width, progress_bar.right());
      assert::are_equal(progress_bar.default_size(), progress_bar.size());
      assert::is_empty(progress_bar.style_sheet().theme().name());
      assert::is_true(progress_bar.tab_stop());
      assert::is_false(progress_bar.tag().has_value());
      assert::is_empty(progress_bar.text());
      assert::is_zero(progress_bar.toolkit_handle());
      assert::is_zero(progress_bar.top());
      assert::is_null(progress_bar.top_level_control());
      assert::is_true(progress_bar.visible());
      assert::are_equal(progress_bar.default_size().width, progress_bar.width());
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls());
      assert::are_equal(keys::none, forms::control::modifier_keys());
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons());
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position());
      
      assert::are_equal(100u, progress_bar.marquee_animation_speed());
      assert::are_equal(100, progress_bar.maximum());
      assert::is_zero(progress_bar.minimum());
      assert::are_equal(orientation::horizontal, progress_bar.orientation());
      assert::are_equal(10, progress_bar.step());
      assert::are_equal(progress_bar_style::blocks, progress_bar.style());
      assert::is_zero(progress_bar.value());
    }
    
    auto test_method_(set_animation_speed) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100u, progress_bar.marquee_animation_speed());
      
      progress_bar.marquee_animation_speed(50u);
      assert::are_equal(50u, progress_bar.marquee_animation_speed());
    }
    
    auto test_method_(set_maximum) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum());
      valid::is_zero(progress_bar.minimum());
      valid::is_zero(progress_bar.value());
      
      progress_bar.maximum(10);
      assert::are_equal(10, progress_bar.maximum());
      assert::is_zero(progress_bar.minimum());
      assert::is_zero(progress_bar.value());
    }
    
    auto test_method_(set_maximum_less_than_minimum) {
      progress_bar_for_test progress_bar;
      progress_bar.maximum(200);
      progress_bar.minimum(100);
      valid::are_equal(200, progress_bar.maximum());
      valid::are_equal(100, progress_bar.minimum());
      valid::are_equal(100, progress_bar.value());
      
      progress_bar.maximum(50);
      assert::are_equal(50, progress_bar.maximum());
      assert::are_equal(50, progress_bar.minimum());
      assert::are_equal(50, progress_bar.value());
    }
    
    auto test_method_(set_minimum) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum());
      valid::is_zero(progress_bar.minimum());
      valid::is_zero(progress_bar.value());
      
      progress_bar.minimum(10);
      assert::are_equal(100, progress_bar.maximum());
      assert::are_equal(10, progress_bar.minimum());
      assert::are_equal(10, progress_bar.value());
    }
    
    auto test_method_(set_minimum_greater_than_maximum) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum());
      valid::is_zero(progress_bar.minimum());
      valid::is_zero(progress_bar.value());
      
      progress_bar.minimum(200);
      assert::are_equal(200, progress_bar.maximum());
      assert::are_equal(200, progress_bar.minimum());
      assert::are_equal(200, progress_bar.value());
    }
    
    auto test_method_(set_orientation_vertical) {
      progress_bar_for_test progress_bar;
      valid::are_equal(orientation::horizontal, progress_bar.orientation());
      
      progress_bar.orientation(forms::orientation::vertical);
      assert::are_equal(orientation::vertical, progress_bar.orientation());
    }
    
    auto test_method_(set_orientation_with_invalid_orientation) {
      progress_bar_for_test progress_bar;
      valid::are_equal(orientation::horizontal, progress_bar.orientation());
      
      assert::throws<argument_out_of_range_exception>([&] {progress_bar.orientation(as<forms::orientation>(2));});
    }
    
    auto test_method_(set_step_1) {
      progress_bar_for_test progress_bar;
      valid::are_equal(10, progress_bar.step());
      
      progress_bar.step(1);
      assert::are_equal(1, progress_bar.step());
    }
    
    auto test_method_(set_step_50) {
      progress_bar_for_test progress_bar;
      valid::are_equal(10, progress_bar.step());
      
      progress_bar.step((50));
      assert::are_equal(50, progress_bar.step());
    }
    
    auto test_method_(set_style_continuous) {
      progress_bar_for_test progress_bar;
      valid::are_equal(progress_bar_style::blocks, progress_bar.style());
      
      progress_bar.style(progress_bar_style::continuous);
      assert::are_equal(progress_bar_style::continuous, progress_bar.style());
    }
    
    auto test_method_(set_style_marquee) {
      progress_bar_for_test progress_bar;
      valid::are_equal(progress_bar_style::blocks, progress_bar.style());
      
      progress_bar.style(progress_bar_style::marquee);
      assert::are_equal(progress_bar_style::marquee, progress_bar.style());
    }
    
    auto test_method_(set_style_with_invalid_style) {
      progress_bar_for_test progress_bar;
      valid::are_equal(progress_bar_style::blocks, progress_bar.style());
      
      assert::throws<argument_out_of_range_exception>([&] {progress_bar.style(as<progress_bar_style>(3));});
    }
    
    auto test_method_(set_value_in_range) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum());
      valid::is_zero(progress_bar.minimum());
      valid::is_zero(progress_bar.value());
      
      progress_bar.value(10);
      assert::are_equal(100, progress_bar.maximum());
      assert::is_zero(progress_bar.minimum());
      assert::are_equal(10, progress_bar.value());
    }
    
    auto test_method_(set_value_out_range) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum());
      valid::is_zero(progress_bar.minimum());
      valid::is_zero(progress_bar.value());
      
      progress_bar.value(110);
      assert::are_equal(100, progress_bar.maximum());
      assert::is_zero(progress_bar.minimum());
      assert::are_equal(progress_bar.maximum(), progress_bar.value());
      
      progress_bar.value(-10);
      assert::are_equal(100, progress_bar.maximum());
      assert::is_zero(progress_bar.minimum());
      assert::are_equal(progress_bar.minimum(), progress_bar.value());
    }
    
    auto test_method_(set_increment) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum());
      valid::is_zero(progress_bar.minimum());
      valid::is_zero(progress_bar.value());
      
      progress_bar.increment(1);
      assert::are_equal(100, progress_bar.maximum());
      assert::is_zero(progress_bar.minimum());
      assert::are_equal(1, progress_bar.value());
    }
    
    auto test_method_(set_increments) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum());
      valid::is_zero(progress_bar.minimum());
      valid::is_zero(progress_bar.value());
      
      progress_bar.increment(1);
      assert::are_equal(100, progress_bar.maximum());
      assert::is_zero(progress_bar.minimum());
      assert::are_equal(1, progress_bar.value());
      
      progress_bar.increment(5);
      assert::are_equal(100, progress_bar.maximum());
      assert::is_zero(progress_bar.minimum());
      assert::are_equal(6, progress_bar.value());
      
      progress_bar.increment(10);
      assert::are_equal(100, progress_bar.maximum());
      assert::is_zero(progress_bar.minimum());
      assert::are_equal(16, progress_bar.value());
    }
    
    auto test_method_(set_increment_out_of_range) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum());
      valid::is_zero(progress_bar.minimum());
      valid::is_zero(progress_bar.value());
      
      progress_bar.increment(110);
      assert::are_equal(100, progress_bar.maximum());
      assert::is_zero(progress_bar.minimum());
      assert::are_equal(progress_bar.maximum(), progress_bar.value());
    }
    
    auto test_method_(set_perform_step) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum());
      valid::is_zero(progress_bar.minimum());
      valid::is_zero(progress_bar.value());
      valid::are_equal(10, progress_bar.step());
      
      progress_bar.perform_step();
      assert::are_equal(100, progress_bar.maximum());
      assert::is_zero(progress_bar.minimum());
      assert::are_equal(10, progress_bar.value());
    }
    
    auto test_method_(set_perform_steps) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum());
      valid::is_zero(progress_bar.minimum());
      valid::is_zero(progress_bar.value());
      valid::are_equal(10, progress_bar.step());
      
      progress_bar.perform_step();
      assert::are_equal(100, progress_bar.maximum());
      assert::is_zero(progress_bar.minimum());
      assert::are_equal(10, progress_bar.value());
      
      progress_bar.perform_step();
      progress_bar.perform_step();
      assert::are_equal(100, progress_bar.maximum());
      assert::is_zero(progress_bar.minimum());
      assert::are_equal(30, progress_bar.value());
      
      progress_bar.perform_step();
      progress_bar.perform_step();
      progress_bar.perform_step();
      progress_bar.perform_step();
      progress_bar.perform_step();
      progress_bar.perform_step();
      progress_bar.perform_step();
      progress_bar.perform_step();
      assert::are_equal(100, progress_bar.maximum());
      assert::is_zero(progress_bar.minimum());
      assert::are_equal(progress_bar.maximum(), progress_bar.value());
    }
    
    auto test_method_(set_perform_steps_with_step_20) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum());
      valid::is_zero(progress_bar.minimum());
      valid::is_zero(progress_bar.value());
      valid::are_equal(10, progress_bar.step());
      
      progress_bar.step(20);
      valid::are_equal(20, progress_bar.step());
      
      progress_bar.perform_step();
      assert::are_equal(100, progress_bar.maximum());
      assert::is_zero(progress_bar.minimum());
      assert::are_equal(20, progress_bar.value());
      
      progress_bar.perform_step();
      progress_bar.perform_step();
      assert::are_equal(100, progress_bar.maximum());
      assert::is_zero(progress_bar.minimum());
      assert::are_equal(60, progress_bar.value());
      
      progress_bar.perform_step();
      progress_bar.perform_step();
      progress_bar.perform_step();
      assert::are_equal(100, progress_bar.maximum());
      assert::is_zero(progress_bar.minimum());
      assert::are_equal(progress_bar.maximum(), progress_bar.value());
    }
    
    auto test_method_(set_range) {
      progress_bar_for_test progress_bar;
      valid::are_equal(100, progress_bar.maximum());
      valid::is_zero(progress_bar.minimum());
      valid::is_zero(progress_bar.value());
      
      progress_bar.set_range(100, 200);
      assert::are_equal(200, progress_bar.maximum());
      assert::are_equal(100, progress_bar.minimum());
      assert::are_equal(100, progress_bar.value());
    }
  };
}
