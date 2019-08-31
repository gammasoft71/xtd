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
    void test_method_(new_control_back_color) {
      control control;
      //assert::are_equal_(system_colors::control(), control.back_color());
    }
    
    void test_method_(new_control_client_size) {
      control control;
      assert::are_equal_(drawing::size(-1, -1), control.client_size());
    }
    
    void test_method_(new_control_default_back_color) {
      control control;
      //assert::are_equal_(system_colors::control(), control.default_back_color());
    }
    
    void test_method_(new_control_default_fore_color) {
      control control;
      //assert::are_equal_(system_colors::control_text(), control.default_fore_color());
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
      //assert::are_equal_(system_colors::control_text(), control.fore_color());
    }
    
    void test_method_(new_control_handle) {
      control control;
      assert::are_equal_(0, control.native_handle());
    }
    
    void test_method_(new_control_location) {
      control control;
      assert::are_equal_(point(-1, -1), control.location());
    }
    
    void test_method_(new_control_parent) {
      control control;
      assert::are_same_(control::null, control.parent());
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
      //assert::throws_(std::invalid_argument, [&] {control.create_control();});
    }
    
    void test_method_(create_control_with_parent) {
      /*
      form form;
      form.name("form");
      control control;
      control.name("control");
      control.parent(form);
      form.show();
      assert::are_equal_(drawing::size(0, 0), control.client_size());
      assert::are_not_equal_(0, control.native_handle());
      assert::are_equal_(xtd::drawing::point(-1, -1), control.location());
      assert::are_equal_(xtd::drawing::size(0, 0), control.size());
       */
    }
  };
}
