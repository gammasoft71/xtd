#include <xtd/xtd.forms>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_control) {
  public:
    void test_method_(new_control_auto_size) {
      control control;
      assert::is_false_(control.auto_size());
    }

    void test_method_(new_control_back_color) {
      control control;
      assert::are_equal_(system_colors::control(), control.back_color());
    }
    
    void test_method_(new_control_bottom) {
      control control;
      assert::is_zero_(control.bottom());
    }

    void test_method_(new_control_client_bounds) {
      control control;
      assert::are_equal_(drawing::rectangle(0, 0, 0, 0), control.bounds());
    }

    void test_method_(new_control_client_size) {
      control control;
      assert::are_equal_(drawing::size(0, 0), control.client_size());
    }

    void test_method_(new_control_default_back_color) {
      control control;
      assert::are_equal_(system_colors::control(), control.default_back_color());
    }
    
    void test_method_(new_control_default_fore_color) {
      control control;
      assert::are_equal_(system_colors::control_text(), control.default_fore_color());
    }

    void test_method_(new_control_default_size) {
      control control;
      assert::are_equal_(drawing::size(0, 0), control.default_size());
    }
    
    void test_method_(new_control_enabled) {
      control control;
      assert::is_true_(control.enabled());
    }
    
    void test_method_(new_control_fore_color) {
      control control;
      assert::are_equal_(system_colors::control_text(), control.fore_color());
    }
    
    void test_method_(new_control_handle) {
      control control;
      assert::is_zero_(control.handle());
    }
    
    void test_method_(new_control_location) {
      control control;
      assert::are_equal_(point(0, 0), control.location());
    }
    
    void test_method_(new_control_parent) {
      control control;
      assert::is_false_(control.parent().has_value());
    }
    
    void test_method_(new_control_size) {
      control control;
      assert::are_equal_(drawing::size(0, 0), control.size());
    }
    
    void test_method_(new_control_text) {
      control control;
      assert::is_empty_(control.text());
    }
    
    void test_method_(new_control_visible) {
      control control;
      assert::is_true_(control.visible());
    }
    
    void test_method_(create_control_without_parent) {
      control control;
      assert::throws_(std::invalid_argument, [&] {control.create_control();});
    }
    
    void test_method_(create_control_with_parent) {
      form form;
      control control;
      control.parent(form);
      assert::are_equal_(1, form.controls().size());
      assert::are_equal_(control, form.controls()[0].get());
    }

    void test_method_(create_control_with_parent_back_color) {
      form form;
      control control;
      control.parent(form);
      assert::are_equal_(form.back_color(), control.back_color());
    }

    void test_method_(create_control_with_parent_fore_color) {
      form form;
      control control;
      control.parent(form);
      assert::are_equal_(form.fore_color(), control.fore_color());
    }

    void test_method_(create_control_with_parent_handle) {
      form form;
      control control;
      control.parent(form);
      assert::is_not_zero_(control.handle());
    }

    void test_method_(create_control_with_parent_parent) {
      form form;
      control control;
      control.parent(form);
      assert::is_true(control.parent().has_value());
      assert::are_equal_(form, control.parent().value().get());
    }
    
    void test_method_(change_parent_back_color) {
      form form;
      control control;
      control.parent(form);
      form.back_color(color::spring_green);
      assert::are_equal_(form.back_color(), control.back_color());
    }
  };
}
