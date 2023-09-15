#include <xtd/console_special_key>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(console_special_key_tests) {
  public:
    void test_method_(control_break) {
      assert::are_equal(0, enum_object<>::to_int32(console_special_key::control_break), csf_);
      assert::are_equal("control_break", enum_object<>::to_string(console_special_key::control_break), csf_);
      assert::are_equal(console_special_key::control_break, enum_object<>::parse<console_special_key>("control_break"), csf_);
    }
    
    void test_method_(control_c) {
      assert::are_equal(1, enum_object<>::to_int32(console_special_key::control_c), csf_);
      assert::are_equal("control_c", enum_object<>::to_string(console_special_key::control_c), csf_);
      assert::are_equal(console_special_key::control_c, enum_object<>::parse<console_special_key>("control_c"), csf_);
    }
    
    void test_method_(control_backslash) {
      assert::are_equal(2, enum_object<>::to_int32(console_special_key::control_backslash), csf_);
      assert::are_equal("control_backslash", enum_object<>::to_string(console_special_key::control_backslash), csf_);
      assert::are_equal(console_special_key::control_backslash, enum_object<>::parse<console_special_key>("control_backslash"), csf_);
    }
    
    void test_method_(control_z) {
      assert::are_equal(3, enum_object<>::to_int32(console_special_key::control_z), csf_);
      assert::are_equal("control_z", enum_object<>::to_string(console_special_key::control_z), csf_);
      assert::are_equal(console_special_key::control_z, enum_object<>::parse<console_special_key>("control_z"), csf_);
    }
  };
}
