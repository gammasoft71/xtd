#include <xtd/forms/orientation.h>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(orientation_tests) {
  public:
    void test_method_(horizontal) {
      assert::are_equal(0, enum_object<>::to_int32(orientation::horizontal), csf_);
      assert::are_equal("horizontal", enum_object<>::to_string(orientation::horizontal), csf_);
      assert::are_equal(orientation::horizontal, enum_object<>::parse<orientation>("horizontal"), csf_);
    }
    
    void test_method_(vertical) {
      assert::are_equal(1, enum_object<>::to_int32(orientation::vertical), csf_);
      assert::are_equal("vertical", enum_object<>::to_string(orientation::vertical), csf_);
      assert::are_equal(orientation::vertical, enum_object<>::parse<orientation>("vertical"), csf_);
    }
  };
}

