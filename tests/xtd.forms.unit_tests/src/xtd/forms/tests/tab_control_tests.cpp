#include <xtd/diagnostics/debugger>
#include <xtd/forms/properties/resources>
#include <xtd/forms/form>
#include <xtd/forms/tab_control>
#include <xtd/forms/tab_page>
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
      assert::are_equal(anchor_styles::left | anchor_styles::top, tab_control.anchor());
      assert::are_equal(drawing::point::empty, tab_control.auto_scroll_point());
      assert::is_false(tab_control.auto_size());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), tab_control.back_color());
      assert::are_equal(drawing::image::empty, tab_control.background_image());
      assert::are_equal(image_layout::tile, tab_control.background_image_layout());
      assert::are_equal(tab_control.default_size().height, tab_control.bottom());
      assert::are_equal(drawing::rectangle({0, 0}, tab_control.default_size()), tab_control.bounds());
      assert::is_false(tab_control.can_focus());
      assert::is_true(tab_control.can_raise_events());
      assert::is_true(tab_control.can_select());
      assert::are_equal(drawing::rectangle({0, 0}, tab_control.default_size()), tab_control.client_rectangle());
      assert::are_equal(tab_control.default_size(), tab_control.client_size());
      assert::are_equal("Gammasoft", tab_control.company_name());
      assert::is_null(tab_control.context_menu());
      assert::are_equal(forms::control_appearance::system, tab_control.control_appearance());
      assert::is_false(tab_control.created());
      assert::are_equal(forms::cursors::default_cursor(), tab_control.cursor());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), tab_control.default_back_color());
      assert::are_equal(forms::cursors::default_cursor(), tab_control.default_cursor());
      assert::are_equal(drawing::system_fonts::default_font(), tab_control.default_font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), tab_control.default_fore_color());
      assert::are_equal(tab_control.default_size(), tab_control.default_size());
      assert::are_equal(drawing::rectangle({0, 0}, tab_control.default_size()), tab_control.display_rectangle());
      assert::are_equal(forms::dock_style::none, tab_control.dock());
      assert::is_false(tab_control.double_buffered());
      assert::is_true(tab_control.enabled());
      assert::is_false(tab_control.focused());
      assert::are_equal(drawing::system_fonts::default_font(), tab_control.font());
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), tab_control.fore_color());
      assert::is_zero(tab_control.handle());
      assert::are_equal(tab_control.default_size().height, tab_control.height());
      assert::is_false(tab_control.invoke_required());
      assert::is_false(tab_control.is_handle_created());
      assert::is_zero(tab_control.left());
      assert::are_equal(drawing::point::empty, tab_control.location());
      assert::are_equal(forms::padding(3), tab_control.margin());
      assert::are_equal(drawing::size::empty, tab_control.maximum_client_size());
      assert::are_equal(drawing::size::empty, tab_control.maximum_size());
      assert::are_equal(drawing::size::empty, tab_control.minimum_client_size());
      assert::are_equal(drawing::size::empty, tab_control.minimum_size());
      assert::is_zero(tab_control.native_handle());
      assert::is_empty(tab_control.name());
      assert::are_equal(forms::padding(0), tab_control.padding());
      assert::is_null(tab_control.parent());
      assert::are_equal("xtd", tab_control.product_name());
      assert::is_not_zero(tab_control.region().handle());
      assert::are_equal(tab_control.default_size().width, tab_control.right());
      assert::are_equal(tab_control.default_size(), tab_control.size());
      assert::is_empty(tab_control.style_sheet().theme().name());
      assert::is_true(tab_control.tab_stop());
      assert::is_false(tab_control.tag().has_value());
      assert::is_empty(tab_control.text());
      assert::is_zero(tab_control.toolkit_handle());
      assert::is_zero(tab_control.top());
      assert::is_null(tab_control.top_level_control());
      assert::is_true(tab_control.visible());
      assert::are_equal(tab_control.default_size().width, tab_control.width());
      assert::are_equal(diagnostics::debugger::is_attached(), forms::control::check_for_illegal_cross_thread_calls());
      assert::are_equal(keys::none, forms::control::modifier_keys());
      assert::are_equal(forms::mouse_buttons::none, forms::control::mouse_buttons());
      // The following test may fail: The user can place the mouse in the upper left position of the screen {0, 0}...
      // assert::are_not_equal(drawing::point::empty, forms::control::mouse_position());
      
      assert::are_equal(tab_alignment::top, tab_control.alignment());
      assert::are_equal(image_list::empty, tab_control.image_list());
      assert::are_equal(tab_control::tab_page_collection::npos, tab_control.selected_index());
      assert::is_zero(tab_control.tab_pages().size());
    }
    
    void test_method_(alignment) {
      forms::form form;
      tab_control_for_test tab_control;
      tab_control.parent(form);
      tab_control.alignment(tab_alignment::left);
      assert::are_equal(tab_alignment::left, tab_control.alignment());
      
      tab_control.alignment(tab_alignment::right);
      assert::are_equal(tab_alignment::right, tab_control.alignment());
      
      tab_control.alignment(tab_alignment::bottom);
      assert::are_equal(tab_alignment::bottom, tab_control.alignment());
      
      tab_control.alignment(tab_alignment::top);
      assert::are_equal(tab_alignment::top, tab_control.alignment());
    }
    
    void test_method_(alignment_without_form) {
      tab_control_for_test tab_control;
      tab_control.alignment(tab_alignment::left);
      assert::are_equal(tab_alignment::left, tab_control.alignment());
      
      tab_control.alignment(tab_alignment::right);
      assert::are_equal(tab_alignment::right, tab_control.alignment());
      
      tab_control.alignment(tab_alignment::bottom);
      assert::are_equal(tab_alignment::bottom, tab_control.alignment());
      
      tab_control.alignment(tab_alignment::top);
      assert::are_equal(tab_alignment::top, tab_control.alignment());
    }
    
    void test_method_(handle) {
      forms::form form;
      tab_control_for_test tab_control;
      tab_control.parent(form);
      assert::is_not_zero(tab_control.handle());
    }
    
    void test_method_(image_list) {
      forms::form form;
      tab_control_for_test tab_control;
      tab_control.parent(form);
      
      forms::image_list image_list;
      image_list.images().push_back(forms::properties::resources::xtd());
      tab_control.image_list(image_list);
      assert::are_equal(image_list, tab_control.image_list());
      assert::are_equal(1_z, tab_control.image_list().images().size());
    }
    
    void test_method_(image_list_without_form) {
      tab_control_for_test tab_control;
      
      forms::image_list image_list;
      image_list.images().push_back(forms::properties::resources::xtd());
      tab_control.image_list(image_list);
      assert::are_equal(image_list, tab_control.image_list());
      assert::are_equal(1_z, tab_control.image_list().images().size());
    }

    void test_method_(native_handle) {
      forms::form form;
      tab_control_for_test tab_control;
      tab_control.parent(form);
      assert::is_not_zero(tab_control.native_handle());
    }
    
    void test_method_(parent) {
      forms::form form;
      tab_control_for_test tab_control;
      tab_control.parent(form);
      assert::is_not_null(tab_control.parent());
      tab_control.parent(nullptr);
      assert::is_null(tab_control.parent());
    }
    
    void test_method_(selected_index) {
      forms::form form;
      tab_control_for_test tab_control;
      forms::tab_page tab_page1;
      tab_control.parent(form);
      
      assert::throws<argument_out_of_range_exception>([&]{tab_control.selected_index(0);});
      tab_control.tab_pages().push_back(tab_page1);
      tab_control.selected_index(0);
      assert::are_equal(0_z, tab_control.selected_index());
      assert::throws<argument_out_of_range_exception>([&]{tab_control.selected_index(1);});
    }
    
    void test_method_(selected_index_without_form) {
      tab_control_for_test tab_control;
      forms::tab_page tab_page1;
      
      assert::throws<argument_out_of_range_exception>([&]{tab_control.selected_index(0);});
      tab_control.tab_pages().push_back(tab_page1);
      tab_control.selected_index(0);
      assert::are_equal(0_z, tab_control.selected_index());
      assert::throws<argument_out_of_range_exception>([&]{tab_control.selected_index(1);});
    }
    
    void test_method_(tab_pages_add_pages_with_tab_pages_push_back) {
      forms::form form;
      tab_control_for_test tab_control;
      forms::tab_page tab_page1;
      forms::tab_page tab_page2;
      forms::tab_page tab_page3;
      tab_control.parent(form);
      
      tab_control.tab_pages().push_back_range({tab_page1, tab_page2, tab_page3});
      assert::are_equal(3_z, tab_control.tab_pages().size());
      assert::is_not_zero(tab_page1.handle());
      assert::is_not_zero(tab_page2.handle());
      assert::is_not_zero(tab_page3.handle());
      assert::are_equal(tab_control, tab_page1.parent());
      assert::are_equal(tab_control, tab_page2.parent());
      assert::are_equal(tab_control, tab_page3.parent());
      assert::are_equal(tab_page1, tab_control.tab_pages()[0].get());
      assert::are_equal(tab_page2, tab_control.tab_pages()[1].get());
      assert::are_equal(tab_page3, tab_control.tab_pages()[2].get());
    }
    
    void test_method_(tab_pages_add_pages_with_tab_pages_push_back_without_form) {
      tab_control_for_test tab_control;
      forms::tab_page tab_page1;
      forms::tab_page tab_page2;
      forms::tab_page tab_page3;
      
      tab_control.tab_pages().push_back_range({tab_page1, tab_page2, tab_page3});
      assert::are_equal(3_z, tab_control.tab_pages().size());
      assert::is_zero(tab_page1.handle());
      assert::is_zero(tab_page2.handle());
      assert::is_zero(tab_page3.handle());
      assert::is_null(tab_page1.parent());
      assert::is_null(tab_page2.parent());
      assert::is_null(tab_page3.parent());
      assert::are_equal(tab_page1, tab_control.tab_pages()[0].get());
      assert::are_equal(tab_page2, tab_control.tab_pages()[1].get());
      assert::are_equal(tab_page3, tab_control.tab_pages()[2].get());
    }

    void test_method_(tab_pages_add_pages_with_tab_page_parent) {
      forms::form form;
      tab_control_for_test tab_control;
      forms::tab_page tab_page1;
      forms::tab_page tab_page2;
      forms::tab_page tab_page3;
      tab_control.parent(form);
      
      tab_page1.parent(tab_control);
      tab_page2.parent(tab_control);
      tab_page3.parent(tab_control);
      assert::are_equal(3_z, tab_control.tab_pages().size());
      assert::is_not_zero(tab_page1.handle());
      assert::is_not_zero(tab_page2.handle());
      assert::is_not_zero(tab_page3.handle());
      assert::are_equal(tab_control, tab_page1.parent());
      assert::are_equal(tab_control, tab_page2.parent());
      assert::are_equal(tab_control, tab_page3.parent());
      assert::are_same(tab_page1, tab_control.tab_pages()[0].get());
      assert::are_same(tab_page2, tab_control.tab_pages()[1].get());
      assert::are_same(tab_page3, tab_control.tab_pages()[2].get());
    }

    void test_method_(tab_pages_remove_pages_with_tab_page_parent) {
      forms::form form;
      tab_control_for_test tab_control;
      forms::tab_page tab_page1;
      forms::tab_page tab_page2;
      forms::tab_page tab_page3;
      tab_control.parent(form);
      
      tab_control.tab_pages().push_back_range({tab_page1, tab_page2, tab_page3});
      tab_page2.parent(nullptr);
      assert::are_equal(2_z, tab_control.tab_pages().size());
      assert::are_same(tab_page1, tab_control.tab_pages()[0].get());
      assert::are_same(tab_page3, tab_control.tab_pages()[1].get());
      assert::is_null(tab_page2.parent());
    }

    void test_method_(tab_pages_remove_pages_with_tab_pages_eraqe_at) {
      forms::form form;
      tab_control_for_test tab_control;
      forms::tab_page tab_page1;
      forms::tab_page tab_page2;
      forms::tab_page tab_page3;
      tab_control.parent(form);
      
      tab_control.tab_pages().push_back_range({tab_page1, tab_page2, tab_page3});
      tab_control.tab_pages().erase_at(1);
      assert::are_equal(2_z, tab_control.tab_pages().size());
      assert::are_same(tab_page1, tab_control.tab_pages()[0].get());
      assert::are_same(tab_page3, tab_control.tab_pages()[1].get());
      assert::is_null(tab_page2.parent());
    }

    void test_method_(tab_pages_remove_pages_with_tab_pages_clear) {
      forms::form form;
      tab_control_for_test tab_control;
      forms::tab_page tab_page1;
      forms::tab_page tab_page2;
      forms::tab_page tab_page3;
      tab_control.parent(form);
      
      tab_control.tab_pages().push_back_range({tab_page1, tab_page2, tab_page3});
      tab_control.tab_pages().clear();
      assert::are_equal(0_z, tab_control.tab_pages().size());
      assert::is_null(tab_page1.parent());
      assert::is_null(tab_page2.parent());
      assert::is_null(tab_page3.parent());
    }
  };
}
