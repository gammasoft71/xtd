#include <xtd/forms>
#include <xtd/tunit>

using namespace std;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_control) {
  public:
    void test_method_(create_control) {
      control control;
      assert::are_equal(0, control.handle());
      assert::are_same(control::null, control.parent());
      assert::is_empty(control.text());
    }
  };
}
