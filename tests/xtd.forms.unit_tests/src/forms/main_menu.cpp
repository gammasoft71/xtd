#include <xtd/xtd.forms>
#include <xtd/xtd.tunit>

using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_main_menu) {
  public:
    void test_method_(new_main_menu) {
      main_menu menu;
      assert::is_not_zero_(menu.handle());
      assert::is_zero_(menu.menu_items().size());
    }

    void test_method_(copy_main_menu) {
      main_menu menu1;
      main_menu menu2(menu1);
      assert::are_equal_(menu1.handle(), menu2.handle());
    }
  };
}
