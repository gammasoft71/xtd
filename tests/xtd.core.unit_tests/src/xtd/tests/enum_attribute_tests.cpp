#include <xtd/enum_attribute>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(enum_attribute_tests) {
    void test_method_(standard) {
      assert::are_equal(0, enum_object<>::to_int32(enum_attribute::standard), csf_);
      assert::are_equal("standard", enum_object<>::to_string(enum_attribute::standard), csf_);
      assert::are_equal(enum_attribute::standard, enum_object<>::parse<enum_attribute>("standard"), csf_);
    }
    
    void test_method_(flags) {
      assert::are_equal(1, enum_object<>::to_int32(enum_attribute::flags), csf_);
      assert::are_equal("flags", enum_object<>::to_string(enum_attribute::flags), csf_);
      assert::are_equal(enum_attribute::flags, enum_object<>::parse<enum_attribute>("flags"), csf_);
    }
  };
}
