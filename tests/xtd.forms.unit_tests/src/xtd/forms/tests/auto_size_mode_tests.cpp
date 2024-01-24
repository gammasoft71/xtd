#include <xtd/forms/auto_size_mode.h>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(auto_size_mode_tests) {
  public:
    void test_method_(grow_and_shrink) {
      assert::are_equal(0, enum_object<>::to_int32(auto_size_mode::grow_and_shrink), csf_);
      assert::are_equal("grow_and_shrink", enum_object<>::to_string(auto_size_mode::grow_and_shrink), csf_);
      assert::are_equal(auto_size_mode::grow_and_shrink, enum_object<>::parse<auto_size_mode>("grow_and_shrink"), csf_);
    }
    
    void test_method_(grow_only) {
      assert::are_equal(1, enum_object<>::to_int32(auto_size_mode::grow_only), csf_);
      assert::are_equal("grow_only", enum_object<>::to_string(auto_size_mode::grow_only), csf_);
      assert::are_equal(auto_size_mode::grow_only, enum_object<>::parse<auto_size_mode>("grow_only"), csf_);
    }
  };
}

