#include <xtd/console_modifiers>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(console_modifiers_tests) {
  public:
    void test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(console_modifiers::none), csf_);
      assert::are_equal("none", enum_object<>::to_string(console_modifiers::none), csf_);
      assert::are_equal(console_modifiers::none, enum_object<>::parse<console_modifiers>("none"), csf_);
    }
    
    void test_method_(alt) {
      assert::are_equal(1, enum_object<>::to_int32(console_modifiers::alt), csf_);
      assert::are_equal("alt", enum_object<>::to_string(console_modifiers::alt), csf_);
      assert::are_equal(console_modifiers::alt, enum_object<>::parse<console_modifiers>("alt"), csf_);
    }
    
    void test_method_(shift) {
      assert::are_equal(2, enum_object<>::to_int32(console_modifiers::shift), csf_);
      assert::are_equal("shift", enum_object<>::to_string(console_modifiers::shift), csf_);
      assert::are_equal(console_modifiers::shift, enum_object<>::parse<console_modifiers>("shift"), csf_);
    }
    
    void test_method_(control) {
      assert::are_equal(4, enum_object<>::to_int32(console_modifiers::control), csf_);
      assert::are_equal("control", enum_object<>::to_string(console_modifiers::control), csf_);
      assert::are_equal(console_modifiers::control, enum_object<>::parse<console_modifiers>("control"), csf_);
    }
  };
}
