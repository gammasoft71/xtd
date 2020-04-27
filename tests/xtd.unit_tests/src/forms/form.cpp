#include <xtd/xtd.forms>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_form) {
  public:
    void test_method_(new_form_back_color) {
      form form;
      assert::are_equal_(form.default_back_color(), form.back_color());
    }
    
    void test_method_(new_form_client_size) {
      form form;
      assert::is_less_or_equal_(form.client_size().height(), form.size().height());
      assert::is_less_or_equal_(form.client_size().width(), form.size().width());
    }

    void test_method_(new_form_fore_color) {
      form form;
      assert::are_equal_(form.default_fore_color(), form.fore_color());
    }
    
    void test_method_(new_form_default_back_color) {
      form form;
      assert::are_equal_(system_colors::control(), form.default_back_color());
    }
    
    void test_method_(new_form_default_fore_color) {
      form form;
      assert::are_equal_(system_colors::control_text(), form.default_fore_color());
    }

    void test_method_(new_form_parent_default_size) {
      form form;
      assert::are_equal_(xtd::drawing::size(300, 300), form.default_size());
    }

    void test_method_(new_form_handle) {
      form form;
      assert::is_not_zero_(form.handle());
    }
    
    void test_method_(new_form_parent) {
      form form;
      assert::is_false_(form.parent().has_value());
    }

    void test_method_(new_form_size) {
      form form;
      assert::are_equal_(form.default_size(), form.size());
    }
  };
}
