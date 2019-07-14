#include <xtd/xtd.forms>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_control) {
  public:
    void test_method_(new_control) {
      control control;
      assert::are_equal_(xtd::drawing::size(-1, -1), control.client_size());
      assert::are_equal_(xtd::drawing::size(0, 0), control.default_size());
      assert::is_true_(control.enabled());
      assert::are_equal_(0, control.handle());
      assert::are_equal_(xtd::drawing::point(-1, -1), control.location());
      assert::are_same_(control::null, control.parent());
      assert::are_equal_(xtd::drawing::size(-1, -1), control.size());
      assert::is_empty_(control.text());
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
      assert::are_equal_(control.default_size(), control.client_size());
      assert::are_not_equal_(0, control.handle());
      assert::are_equal_(xtd::drawing::point(0, 0), control.location());
      assert::are_equal_(xtd::drawing::size(0, 0), control.size());
    }
  };
}
