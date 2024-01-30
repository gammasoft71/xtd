#include <xtd/forms/link_behavior>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(link_behavior_tests) {
  public:
    void test_method_(system_default) {
      assert::are_equal(0, enum_object<>::to_int32(link_behavior::system_default), csf_);
      assert::are_equal("system_default", enum_object<>::to_string(link_behavior::system_default), csf_);
      assert::are_equal(link_behavior::system_default, enum_object<>::parse<link_behavior>("system_default"), csf_);
    }
    
    void test_method_(always_underline) {
      assert::are_equal(1, enum_object<>::to_int32(link_behavior::always_underline), csf_);
      assert::are_equal("always_underline", enum_object<>::to_string(link_behavior::always_underline), csf_);
      assert::are_equal(link_behavior::always_underline, enum_object<>::parse<link_behavior>("always_underline"), csf_);
    }
    
    void test_method_(hover_underline) {
      assert::are_equal(2, enum_object<>::to_int32(link_behavior::hover_underline), csf_);
      assert::are_equal("hover_underline", enum_object<>::to_string(link_behavior::hover_underline), csf_);
      assert::are_equal(link_behavior::hover_underline, enum_object<>::parse<link_behavior>("hover_underline"), csf_);
    }
    
    void test_method_(never_underline) {
      assert::are_equal(3, enum_object<>::to_int32(link_behavior::never_underline), csf_);
      assert::are_equal("never_underline", enum_object<>::to_string(link_behavior::never_underline), csf_);
      assert::are_equal(link_behavior::never_underline, enum_object<>::parse<link_behavior>("never_underline"), csf_);
    }
  };
}
