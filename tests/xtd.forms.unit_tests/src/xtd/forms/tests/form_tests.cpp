#include <xtd/forms/form>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(form_tests) {
    class form_for_test : public form {
    public:
      form_for_test() = default;
      
      using form::default_back_color;
      using form::default_cursor;
      using form::default_font;
      using form::default_fore_color;
      using form::default_size;
    };
    
    void test_method_(form_handle_destroyed) {
      auto on_handle_destroy_raised = false;
      auto on_handle_destroyed = [&] {
        on_handle_destroy_raised = true;
      };
      {
        form_for_test form;
        form.handle_destroyed += on_handle_destroyed;
      }
      assert::is_true(on_handle_destroy_raised);
    }
    
    void test_method_(new_form_back_color) {
      form_for_test form;
      assert::are_equal(form.default_back_color(), form.back_color());
    }
    
    void test_method_(new_form_client_size) {
      form_for_test form;
      assert::is_less_or_equal(form.client_size().height, form.size().height);
      assert::is_less_or_equal(form.client_size().width, form.size().width);
    }
    
    void test_method_(new_form_fore_color) {
      form_for_test form;
      assert::are_equal(form.default_fore_color(), form.fore_color());
    }
    
    void test_method_(new_form_default_back_color) {
      form_for_test form;
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control(), form.default_back_color());
    }
    
    void test_method_(new_form_default_fore_color) {
      form_for_test form;
      assert::are_equal(style_sheets::style_sheet::current_style_sheet().system_colors().control_text(), form.default_fore_color());
    }
    
    void test_method_(new_form_parent_default_size) {
      form_for_test form;
      assert::are_equal(xtd::drawing::size(300, 300), form.default_size());
    }
    
    void test_method_(new_form_handle) {
      form_for_test form;
      assert::is_not_zero(form.handle());
    }
    
    void test_method_(new_form_parent) {
      form_for_test form;
      assert::is_false(form.parent().has_value());
    }
    
    void test_method_(new_form_size) {
      form_for_test form;
      assert::are_equal(form.default_size(), form.size());
    }
  };
}
