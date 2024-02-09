#include <xtd/diagnostics/debugger>
#include <xtd/forms/properties/resources>
#include <xtd/forms/form>
#include <xtd/forms/tab_control>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(tab_control_tests) {
    class tab_control_for_test : public tab_control {
    public:
      tab_control_for_test() = default;
      
      using tab_control::default_back_color;
      using tab_control::default_cursor;
      using tab_control::default_font;
      using tab_control::default_fore_color;
      using tab_control::default_size;
    };
    
    void test_method_(constructor) {
      tab_control_for_test tab_control;
      assert::are_equal(anchor_styles::left | anchor_styles::top, tab_control.anchor(), csf_);
      assert::are_equal(drawing::point::empty, tab_control.auto_scroll_point(), csf_);
      assert::is_false(tab_control.auto_size(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), tab_control.back_color(), csf_);
      assert::are_equal(drawing::image::empty, tab_control.background_image(), csf_);
      assert::are_equal(image_layout::tile, tab_control.background_image_layout(), csf_);
      assert::are_equal(tab_control.default_size().height(), tab_control.bottom(), csf_);
      assert::are_equal(drawing::rectangle({0, 0}, tab_control.default_size()), tab_control.bounds(), csf_);
      assert::is_false(tab_control.can_focus(), csf_);
      assert::is_true(tab_control.can_raise_events(), csf_);
      assert::is_true(tab_control.can_select(), csf_);
      assert::are_equal(drawing::rectangle({0, 0}, tab_control.default_size()), tab_control.client_rectangle(), csf_);
      assert::are_equal(tab_control.default_size(), tab_control.client_size(), csf_);
      assert::are_equal("Gammasoft", tab_control.company_name(), csf_);
      assert::is_null(tab_control.context_menu(), csf_);
      assert::are_equal(forms::control_appearance::system, tab_control.control_appearance(), csf_);
      assert::is_false(tab_control.created(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), tab_control.cursor(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), tab_control.default_back_color(), csf_);
      assert::are_equal(forms::cursors::default_cursor(), tab_control.default_cursor(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), tab_control.default_font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), tab_control.default_fore_color(), csf_);
      assert::are_equal(tab_control.default_size(), tab_control.default_size(), csf_);
      assert::are_equal(drawing::rectangle({0, 0}, tab_control.default_size()), tab_control.display_rectangle(), csf_);
      assert::are_equal(forms::dock_style::none, tab_control.dock(), csf_);
      assert::is_false(tab_control.double_buffered(), csf_);
      assert::is_true(tab_control.enabled(), csf_);
      assert::is_false(tab_control.focused(), csf_);
      assert::are_equal(drawing::system_fonts::default_font(), tab_control.font(), csf_);
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), tab_control.fore_color(), csf_);
      assert::is_zero(tab_control.handle(), csf_);
      assert::are_equal(tab_control.default_size().height(), tab_control.height(), csf_);
      assert::is_false(tab_control.invoke_required(), csf_);
      assert::is_false(tab_control.is_handle_created(), csf_);
      assert::is_zero(tab_control.left(), csf_);
      assert::are_equal(drawing::point::empty, tab_control.location(), csf_);
      assert::are_equal(forms::padding(3), tab_control.margin(), csf_);
      assert::are_equal(drawing::size::empty, tab_control.maximum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, tab_control.maximum_size(), csf_);
      assert::are_equal(drawing::size::empty, tab_control.minimum_client_size(), csf_);
      assert::are_equal(drawing::size::empty, tab_control.minimum_size(), csf_);
      assert::is_zero(tab_control.native_handle(), csf_);
      assert::is_empty(tab_control.name(), csf_);
      assert::are_equal(forms::padding(0), tab_control.padding(), csf_);
      assert::is_null(tab_control.parent(), csf_);
      assert::are_equal("xtd", tab_control.product_name(), csf_);
      assert::is_not_zero(tab_control.region().handle(), csf_);
      assert::are_equal(tab_control.default_size().width(), tab_control.right(), csf_);
      assert::are_equal(tab_control.default_size(), tab_control.size(), csf_);
      assert::is_empty(tab_control.style_sheet().theme().name(), csf_);
      assert::is_true(tab_control.tab_stop(), csf_);
      assert::is_false(tab_control.tag().has_value(), csf_);
      assert::is_empty(tab_control.text(), csf_);
      assert::is_zero(tab_control.toolkit_handle(), csf_);
      assert::is_zero(tab_control.top(), csf_);
      assert::is_null(tab_control.top_level_control(), csf_);
      assert::is_true(tab_control.visible(), csf_);
      assert::are_equal(tab_control.default_size().width(), tab_control.width(), csf_);
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls(), csf_);
      assert::are_equal(keys::none, forms::control::modifier_keys(), csf_);
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons(), csf_);
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position(), csf_);
      
      assert::are_equal(tab_alignment::top, tab_control.alignment(), csf_);
      assert::are_equal(image_list::empty, tab_control.image_list(), csf_);
      assert::are_equal(tab_control::tab_page_collection::npos, tab_control.selected_index(), csf_);
      assert::is_zero(tab_control.tab_pages().size(), csf_);
    }
    
    void test_method_(alignment) {
      forms::form form;
      tab_control_for_test tab_control;
      tab_control.parent(form);
      tab_control.alignment(tab_alignment::left);
      assert::are_equal(tab_alignment::left, tab_control.alignment(), csf_);
      
      tab_control.alignment(tab_alignment::right);
      assert::are_equal(tab_alignment::right, tab_control.alignment(), csf_);
      
      tab_control.alignment(tab_alignment::bottom);
      assert::are_equal(tab_alignment::bottom, tab_control.alignment(), csf_);
      
      tab_control.alignment(tab_alignment::top);
      assert::are_equal(tab_alignment::top, tab_control.alignment(), csf_);
    }
    
    void test_method_(alignment_without_parent) {
      tab_control_for_test tab_control;
      tab_control.alignment(tab_alignment::left);
      assert::are_equal(tab_alignment::left, tab_control.alignment(), csf_);
      
      tab_control.alignment(tab_alignment::right);
      assert::are_equal(tab_alignment::right, tab_control.alignment(), csf_);
      
      tab_control.alignment(tab_alignment::bottom);
      assert::are_equal(tab_alignment::bottom, tab_control.alignment(), csf_);
      
      tab_control.alignment(tab_alignment::top);
      assert::are_equal(tab_alignment::top, tab_control.alignment(), csf_);
    }
    
    void test_method_(handle) {
      forms::form form;
      tab_control_for_test tab_control;
      tab_control.parent(form);
      assert::is_not_zero(tab_control.handle(), csf_);
    }
    
    void test_method_(image_list) {
      forms::form form;
      tab_control_for_test tab_control;
      tab_control.parent(form);
      
      forms::image_list image_list;
      image_list.images().push_back(forms::properties::resources::xtd());
      tab_control.image_list(image_list);
      assert::are_equal(image_list, tab_control.image_list(), csf_);
      assert::are_equal(1, tab_control.image_list().images().size(), csf_);
    }
    
    void test_method_(image_list_without_parent) {
      tab_control_for_test tab_control;
      
      forms::image_list image_list;
      image_list.images().push_back(forms::properties::resources::xtd());
      tab_control.image_list(image_list);
      assert::are_equal(image_list, tab_control.image_list(), csf_);
      assert::are_equal(1, tab_control.image_list().images().size(), csf_);
    }

    void test_method_(native_handle) {
      forms::form form;
      tab_control_for_test tab_control;
      tab_control.parent(form);
      assert::is_not_zero(tab_control.native_handle(), csf_);
    }
    
    void test_method_(parent) {
      forms::form form;
      tab_control_for_test tab_control;
      tab_control.parent(form);
      assert::is_not_null(tab_control.parent(), csf_);
      tab_control.parent(nullptr);
      assert::is_null(tab_control.parent(), csf_);
    }
    
    void test_method_(selected_index) {
      forms::form form;
      tab_control_for_test tab_control;
      tab_control.parent(form);
      
      assert::throws<argument_out_of_range_exception>([&]{tab_control.selected_index(0);}, csf_);
      //assert::are_equal(0, tab_control.selected_index(), csf_);
    }
  };
}
