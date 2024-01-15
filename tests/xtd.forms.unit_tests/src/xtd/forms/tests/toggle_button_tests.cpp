#include <xtd/forms/toggle_button>
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
  class test_class_(toggle_button_tests) {
    class toggle_button_for_test : public toggle_button {
    public:
      toggle_button_for_test() = default;
      
      using toggle_button::default_back_color;
      using toggle_button::default_cursor;
      using toggle_button::default_font;
      using toggle_button::default_fore_color;
      using toggle_button::default_size;
    };
    
    void test_method_(constructor) {
      toggle_button_for_test toggle_button;
      assert::are_equal(anchor_styles::left | anchor_styles::top, toggle_button.anchor(), csf_);
      assert::are_equal(drawing::point::empty, toggle_button.auto_scroll_point(), csf_);
      assert::is_false(toggle_button.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), toggle_button.back_color(), csf_);
      assert::are_equal(drawing::image::empty, toggle_button.background_image(), csf_);
      assert::are_equal(image_layout::tile, toggle_button.background_image_layout(), csf_);
      assert::are_equal(toggle_button.default_size().height(), toggle_button.bottom(), csf_);
      assert::are_equal(drawing::rectangle({0, 0}, toggle_button.default_size()), toggle_button.bounds(), csf_);
      assert::is_false(toggle_button.can_focus(), csf_);
      assert::is_true(toggle_button.can_raise_events(), csf_);
      assert::is_true(toggle_button.can_select(), csf_);
      assert::are_equal(drawing::rectangle({0, 0}, toggle_button.default_size()), toggle_button.client_rectangle(), csf_);
      assert::are_equal(toggle_button.default_size(), toggle_button.client_size(), csf_);
      assert::are_equal("Gammasoft", toggle_button.company_name(), csf_);
      assert::is_null(toggle_button.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, toggle_button.control_appearance(), csf_);
      assert::is_empty(toggle_button.controls(), csf_);
      assert::is_false(toggle_button.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), toggle_button.cursor(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), toggle_button.default_back_color(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), toggle_button.default_cursor(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), toggle_button.default_font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), toggle_button.default_fore_color(), csf_);
      assert::are_equal(toggle_button.default_size(), toggle_button.default_size(), csf_);
      assert::are_equal(drawing::rectangle({0, 0}, toggle_button.default_size()), toggle_button.display_rectangle(), csf_);
      assert::are_equal(forms::dock_style::none, toggle_button.dock(), csf_);
      assert::is_false(toggle_button.double_buffered(), csf_);
      assert::is_true(toggle_button.enabled(), csf_);
      assert::is_false(toggle_button.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), toggle_button.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), toggle_button.fore_color(), csf_);
      assert::is_zero(toggle_button.handle(), csf_);
      assert::are_equal(toggle_button.default_size().height(), toggle_button.height(), csf_);
      assert::is_false(toggle_button.invoke_required(), csf_);
      assert::is_false(toggle_button.is_handle_created(), csf_);
      assert::is_zero(toggle_button.left(), csf_);
      assert::are_equal(drawing::point::empty, toggle_button.location(), csf_);
      assert::are_equal(forms::padding(3), toggle_button.margin(), csf_);
      assert::are_equal(drawing::size::empty, toggle_button.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, toggle_button.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, toggle_button.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, toggle_button.minimum_size(), csf_);
      assert::is_zero(toggle_button.native_handle(), csf_);
      assert::is_empty(toggle_button.name(), csf_);
      assert::are_equal(forms::padding(0), toggle_button.padding(), csf_);
      assert::is_null(toggle_button.parent(), csf_);
      assert::are_equal("xtd", toggle_button.product_name(), csf_);
      assert::is_not_zero(toggle_button.region().handle(), csf_);
      assert::are_equal(toggle_button.default_size().width(), toggle_button.right(), csf_);
      assert::are_equal(toggle_button.default_size(), toggle_button.size(), csf_);
      assert::is_empty(toggle_button.style_sheet().theme().name(), csf_);
      assert::is_true(toggle_button.tab_stop(), csf_);
      assert::is_false(toggle_button.tag().has_value(), csf_);
      assert::is_empty(toggle_button.text(), csf_);
      assert::is_zero(toggle_button.toolkit_handle(), csf_);
      assert::is_zero(toggle_button.top(), csf_);
      assert::is_null(toggle_button.top_level_control(), csf_);
      assert::is_true(toggle_button.visible(), csf_);
      assert::are_equal(toggle_button.default_size().width(), toggle_button.width(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
      
      assert::is_false(toggle_button.auto_ellipsis(), csf_);
      assert::are_equal(flat_button_appearance(), toggle_button.flat_appearance(), csf_);
      assert::are_equal(flat_style::standard, toggle_button.flat_style(), csf_);
      assert::are_equal(image::empty, toggle_button.image(), csf_);
      assert::are_equal(content_alignment::middle_center, toggle_button.image_align(), csf_);
      assert::are_equal(-1, toggle_button.image_index(), csf_);
      assert::are_equal(image_list::empty, toggle_button.image_list(), csf_);
      assert::are_equal(content_alignment::middle_center, toggle_button.text_align(), csf_);
    }
  };
}
