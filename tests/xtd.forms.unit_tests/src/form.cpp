#include <xtd/forms>
#include <xtd/tunit>

using namespace std;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_form) {
  public:
    void test_method_(create_form) {
      form form;
      assert::are_not_equal(0, form.handle());
      assert::are_same(control::null, form.parent());
      assert::is_empty(form.text());
    }
  };
}
