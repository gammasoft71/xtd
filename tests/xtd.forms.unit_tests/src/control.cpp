#include <xtd/xtd.forms>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_control) {
  public:
    void test_method_(create_control) {
      control control;
      assert::are_equal(0, control.handle());
      assert::are_equal(xtd::drawing::point(0, 0), control.location());
      assert::are_same(control::null, control.parent());
      assert::are_equal(xtd::drawing::size(0, 0), control.size());
      assert::is_empty(control.text());
      assert::is_true(control.visible());
    }
  };
}
