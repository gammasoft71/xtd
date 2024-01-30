#include <xtd/forms/appearance>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(appearance_tests) {
  public:
    void test_method_(normal) {
      assert::are_equal(0, enum_object<>::to_int32(appearance::normal), csf_);
      assert::are_equal("normal", enum_object<>::to_string(appearance::normal), csf_);
      assert::are_equal(appearance::normal, enum_object<>::parse<appearance>("normal"), csf_);
    }
    
    void test_method_(button) {
      assert::are_equal(1, enum_object<>::to_int32(appearance::button), csf_);
      assert::are_equal("button", enum_object<>::to_string(appearance::button), csf_);
      assert::are_equal(appearance::button, enum_object<>::parse<appearance>("button"), csf_);
    }
    
    void test_method_(switch_button) {
      assert::are_equal(2, enum_object<>::to_int32(appearance::switch_button), csf_);
      assert::are_equal("switch_button", enum_object<>::to_string(appearance::switch_button), csf_);
      assert::are_equal(appearance::switch_button, enum_object<>::parse<appearance>("switch_button"), csf_);
    }
  };
}
