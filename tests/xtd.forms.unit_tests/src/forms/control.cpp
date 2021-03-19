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
      assert::is_false_(control.auto_size());
      assert::are_equal_(system_colors::control(), control.back_color());
      assert::is_zero_(control.bottom());
      assert::are_equal_(drawing::rectangle(0, 0, 0, 0), control.bounds());
      assert::are_equal_(drawing::size(0, 0), control.client_size());
      assert::are_equal_(system_colors::control(), control.default_back_color());
      assert::are_equal_(system_colors::control_text(), control.default_fore_color());
      assert::are_equal_(drawing::size(0, 0), control.default_size());
      assert::is_true_(control.enabled());
      assert::are_equal_(system_colors::control_text(), control.fore_color());
      assert::is_zero_(control.handle());
      assert::are_equal_(point(0, 0), control.location());
      assert::is_false_(control.parent().has_value());
      assert::are_equal_(drawing::size(0, 0), control.size());
      assert::is_empty_(control.text());
      assert::is_true_(control.visible());
    }
    
    void test_method_(create_control_without_parent) {
      control control;
      assert::throws_(argument_exception, [&] {control.create_control();});
    }
    
    void test_method_(create_control_with_parent) {
      form form;
      control control;
      control.parent(form);
      assert::are_equal_(1U, form.controls().size());
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
