#include <xtd/forms/radio_button>
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
  class test_class_(radio_button_tests) {
    class radio_button_for_test : public radio_button {
    public:
      radio_button_for_test() = default;
      
      using radio_button::default_back_color;
      using radio_button::default_cursor;
      using radio_button::default_font;
      using radio_button::default_fore_color;
      using radio_button::default_size;
    };
    
    void test_method_(constructor) {
      radio_button_for_test radio_button;
      assert::are_equal(anchor_styles::left | anchor_styles::top, radio_button.anchor(), csf_);
      assert::are_equal(drawing::point::empty, radio_button.auto_scroll_point(), csf_);
      assert::is_false(radio_button.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), radio_button.back_color(), csf_);
      assert::are_equal(drawing::image::empty, radio_button.background_image(), csf_);
      assert::are_equal(image_layout::tile, radio_button.background_image_layout(), csf_);
      assert::are_equal(radio_button.default_size().height(), radio_button.bottom(), csf_);
      assert::are_equal(drawing::rectangle({0, 0}, radio_button.default_size()), radio_button.bounds(), csf_);
      assert::is_false(radio_button.can_focus(), csf_);
      assert::is_true(radio_button.can_raise_events(), csf_);
      assert::is_true(radio_button.can_select(), csf_);
      assert::are_equal(drawing::rectangle({0, 0}, radio_button.default_size()), radio_button.client_rectangle(), csf_);
      assert::are_equal(radio_button.default_size(), radio_button.client_size(), csf_);
      assert::are_equal("Gammasoft", radio_button.company_name(), csf_);
      assert::is_null(radio_button.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::standard, radio_button.control_appearance(), csf_);
      assert::is_empty(radio_button.controls(), csf_);
      assert::is_false(radio_button.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), radio_button.cursor(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), radio_button.default_back_color(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), radio_button.default_cursor(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), radio_button.default_font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), radio_button.default_fore_color(), csf_);
      assert::are_equal(radio_button.default_size(), radio_button.default_size(), csf_);
      assert::are_equal(drawing::rectangle({0, 0}, radio_button.default_size()), radio_button.display_rectangle(), csf_);
      assert::are_equal(forms::dock_style::none, radio_button.dock(), csf_);
      assert::is_false(radio_button.double_buffered(), csf_);
      assert::is_true(radio_button.enabled(), csf_);
      assert::is_false(radio_button.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), radio_button.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), radio_button.fore_color(), csf_);
      assert::is_zero(radio_button.handle(), csf_);
      assert::are_equal(radio_button.default_size().height(), radio_button.height(), csf_);
      assert::is_false(radio_button.invoke_required(), csf_);
      assert::is_false(radio_button.is_handle_created(), csf_);
      assert::is_zero(radio_button.left(), csf_);
      assert::are_equal(drawing::point::empty, radio_button.location(), csf_);
      assert::are_equal(forms::padding(3), radio_button.margin(), csf_);
      assert::are_equal(drawing::size::empty, radio_button.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, radio_button.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, radio_button.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, radio_button.minimum_size(), csf_);
      assert::is_zero(radio_button.native_handle(), csf_);
      assert::is_empty(radio_button.name(), csf_);
      assert::are_equal(forms::padding(0), radio_button.padding(), csf_);
      assert::is_null(radio_button.parent(), csf_);
      assert::are_equal("xtd", radio_button.product_name(), csf_);
      assert::is_not_zero(radio_button.region().handle(), csf_);
      assert::are_equal(radio_button.default_size().width(), radio_button.right(), csf_);
      assert::are_equal(radio_button.default_size(), radio_button.size(), csf_);
      assert::is_empty(radio_button.style_sheet().theme().name(), csf_);
      assert::is_true(radio_button.tab_stop(), csf_);
      assert::is_false(radio_button.tag().has_value(), csf_);
      assert::is_empty(radio_button.text(), csf_);
      assert::is_zero(radio_button.toolkit_handle(), csf_);
      assert::is_zero(radio_button.top(), csf_);
      assert::is_null(radio_button.top_level_control(), csf_);
      assert::is_true(radio_button.visible(), csf_);
      assert::are_equal(radio_button.default_size().width(), radio_button.width(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
      
      assert::is_false(radio_button.auto_ellipsis(), csf_);
      assert::are_equal(flat_button_appearance(), radio_button.flat_appearance(), csf_);
      assert::are_equal(flat_style::standard, radio_button.flat_style(), csf_);
      assert::are_equal(image::empty, radio_button.image(), csf_);
      assert::are_equal(content_alignment::middle_center, radio_button.image_align(), csf_);
      assert::are_equal(-1, radio_button.image_index(), csf_);
      assert::are_equal(image_list::empty, radio_button.image_list(), csf_);
      assert::are_equal(content_alignment::middle_left, radio_button.text_align(), csf_);
    }
  };
}
