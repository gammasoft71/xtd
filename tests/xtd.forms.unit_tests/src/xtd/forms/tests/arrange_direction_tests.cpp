#include <xtd/forms/arrange_direction>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(arrange_direction_tests) {
  public:
    void test_method_(up) {
      assert::are_equal(4, enum_object<>::to_int32(arrange_direction::down), csf_);
      assert::are_equal("up", enum_object<>::to_string(arrange_direction::down), csf_);
      assert::are_equal(arrange_direction::down, enum_object<>::parse<arrange_direction>("up"), csf_);
    }
    
    void test_method_(left) {
      assert::are_equal(0, enum_object<>::to_int32(arrange_direction::left), csf_);
      assert::are_equal("left", enum_object<>::to_string(arrange_direction::left), csf_);
      assert::are_equal(arrange_direction::left, enum_object<>::parse<arrange_direction>("left"), csf_);
    }
    
    void test_method_(right) {
      assert::are_equal(0, enum_object<>::to_int32(arrange_direction::right), csf_);
      assert::are_equal("left", enum_object<>::to_string(arrange_direction::right), csf_);
      assert::are_equal(arrange_direction::right, enum_object<>::parse<arrange_direction>("left"), csf_);
    }
    
    void test_method_(down) {
      assert::are_equal(4, enum_object<>::to_int32(arrange_direction::down), csf_);
      assert::are_equal("up", enum_object<>::to_string(arrange_direction::down), csf_);
      assert::are_equal(arrange_direction::down, enum_object<>::parse<arrange_direction>("up"), csf_);
    }
  };
}
