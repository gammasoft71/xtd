#include <xtd/forms/menu_item_kind.h>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(menu_item_kind_tests) {
  public:
    void test_method_(normal) {
      assert::are_equal(0, enum_object<>::to_int32(menu_item_kind::normal), csf_);
      assert::are_equal("normal", enum_object<>::to_string(menu_item_kind::normal), csf_);
      assert::are_equal(menu_item_kind::normal, enum_object<>::parse<menu_item_kind>("normal"), csf_);
    }
    
    void test_method_(check) {
      assert::are_equal(1, enum_object<>::to_int32(menu_item_kind::check), csf_);
      assert::are_equal("check", enum_object<>::to_string(menu_item_kind::check), csf_);
      assert::are_equal(menu_item_kind::check, enum_object<>::parse<menu_item_kind>("check"), csf_);
    }
    
    void test_method_(radio) {
      assert::are_equal(2, enum_object<>::to_int32(menu_item_kind::radio), csf_);
      assert::are_equal("radio", enum_object<>::to_string(menu_item_kind::radio), csf_);
      assert::are_equal(menu_item_kind::radio, enum_object<>::parse<menu_item_kind>("radio"), csf_);
    }
    
    void test_method_(drop_down) {
      assert::are_equal(3, enum_object<>::to_int32(menu_item_kind::drop_down), csf_);
      assert::are_equal("drop_down", enum_object<>::to_string(menu_item_kind::drop_down), csf_);
      assert::are_equal(menu_item_kind::drop_down, enum_object<>::parse<menu_item_kind>("drop_down"), csf_);
    }
    
    void test_method_(separator) {
      assert::are_equal(4, enum_object<>::to_int32(menu_item_kind::separator), csf_);
      assert::are_equal("separator", enum_object<>::to_string(menu_item_kind::separator), csf_);
      assert::are_equal(menu_item_kind::separator, enum_object<>::parse<menu_item_kind>("separator"), csf_);
    }
  };
}

