#include <xtd/forms/search_direction>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(search_direction_tests) {
  public:
    void test_method_(down) {
      assert::are_equal(0, enum_object<>::to_int32(search_direction::down), csf_);
      assert::are_equal("down", enum_object<>::to_string(search_direction::down), csf_);
      assert::are_equal(search_direction::down, enum_object<>::parse<search_direction>("down"), csf_);
    }
    
    void test_method_(up) {
      assert::are_equal(1, enum_object<>::to_int32(search_direction::up), csf_);
      assert::are_equal("up", enum_object<>::to_string(search_direction::up), csf_);
      assert::are_equal(search_direction::up, enum_object<>::parse<search_direction>("up"), csf_);
    }
  };
}
