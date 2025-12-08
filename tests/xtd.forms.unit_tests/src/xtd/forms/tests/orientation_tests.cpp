#include <xtd/forms/orientation>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(orientation_tests) {
  public:
    auto test_method_(horizontal) {
      assert::are_equal(0, enum_object<>::to_int32(orientation::horizontal));
      assert::are_equal("horizontal", enum_object<>::to_string(orientation::horizontal));
      assert::are_equal(orientation::horizontal, enum_object<>::parse<orientation>("horizontal"));
    }
    
    auto test_method_(vertical) {
      assert::are_equal(1, enum_object<>::to_int32(orientation::vertical));
      assert::are_equal("vertical", enum_object<>::to_string(orientation::vertical));
      assert::are_equal(orientation::vertical, enum_object<>::parse<orientation>("vertical"));
    }
  };
}
