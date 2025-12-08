#include <xtd/architecture_id>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(architecture_id_tests) {
    auto test_method_(unknown) {
      assert::are_equal(-1, enum_object<>::to_int32(architecture_id::unknown));
      assert::are_equal("unknown", enum_object<>::to_string(architecture_id::unknown));
      assert::are_equal(architecture_id::unknown, enum_object<>::parse<architecture_id>("unknown"));
    }
    
    auto test_method_(x86) {
      assert::are_equal(0, enum_object<>::to_int32(architecture_id::x86));
      assert::are_equal("x86", enum_object<>::to_string(architecture_id::x86));
      assert::are_equal(architecture_id::x86, enum_object<>::parse<architecture_id>("x86"));
    }
    
    auto test_method_(arm) {
      assert::are_equal(1, enum_object<>::to_int32(architecture_id::arm));
      assert::are_equal("arm", enum_object<>::to_string(architecture_id::arm));
      assert::are_equal(architecture_id::arm, enum_object<>::parse<architecture_id>("arm"));
    }
  };
}
