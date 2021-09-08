#include <xtd/forms/control.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/form.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_control) {
  public:
    void test_method_(new_control) {
      control control;
      assert::is_false(control.auto_size(), csf_);
      assert::are_equal(system_colors::control(), control.back_color(), csf_);
      assert::is_zero(control.bottom(), csf_);
      assert::are_equal(drawing::rectangle(0, 0, 0, 0), control.bounds(), csf_);
      assert::are_equal(drawing::size(0, 0), control.client_size(), csf_);
      assert::are_equal(system_colors::control(), control.default_back_color(), csf_);
      assert::are_equal(system_colors::control_text(), control.default_fore_color(), csf_);
      assert::are_equal(drawing::size(0, 0), control.default_size(), csf_);
      assert::is_true(control.enabled(), csf_);
      assert::are_equal(system_colors::control_text(), control.fore_color(), csf_);
      assert::is_zero(control.handle(), csf_);
      assert::are_equal(point(0, 0), control.location(), csf_);
      assert::is_false(control.parent().has_value(), csf_);
      assert::are_equal(drawing::size(0, 0), control.size(), csf_);
      assert::is_empty(control.text(), csf_);
      assert::is_true(control.visible(), csf_);
    }
    
    void test_method_(create_control_without_parent) {
      control control;
      assert::throws<argument_exception>([&] {control.create_control();}, csf_);
    }
    
    void test_method_(create_control_with_parent) {
      form form;
      control control;
      control.parent(form);
      assert::are_equal(1U, form.controls().size(), csf_);
      assert::are_equal(control, form.controls()[0].get(), csf_);
    }

    void test_method_(create_control_with_parent_back_color) {
      form form;
      control control;
      control.parent(form);
      assert::are_equal(form.back_color(), control.back_color(), csf_);
    }

    void test_method_(create_control_with_parent_fore_color) {
      form form;
      control control;
      control.parent(form);
      assert::are_equal(form.fore_color(), control.fore_color(), csf_);
    }

    void test_method_(create_control_with_parent_handle) {
      form form;
      control control;
      control.parent(form);
      assert::is_not_zero(control.handle(), csf_);
    }

    void test_method_(create_control_with_parent_parent) {
      form form;
      control control;
      control.parent(form);
      assert::is_true(control.parent().has_value(), csf_);
      assert::are_equal(form, control.parent().value().get(), csf_);
    }
    
    void test_method_(change_parent_back_color) {
      form form;
      control control;
      control.parent(form);
      form.back_color(color::spring_green);
      assert::are_equal(form.back_color(), control.back_color(), csf_);
    }
  };
}
