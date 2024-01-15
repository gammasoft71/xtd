#include <xtd/drawing/drawing_2d/line_cap>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::drawing_2d;
using namespace xtd::tunit;

namespace xtd::drawing::drawing_2d::tests {
  class test_class_(line_cap_tests) {
    void test_method_(flat) {
      assert::are_equal(0, enum_object<>::to_int32(line_cap::flat), csf_);
      assert::are_equal("flat", enum_object<>::to_string(line_cap::flat), csf_);
      assert::are_equal(line_cap::flat, enum_object<>::parse<line_cap>("flat"), csf_);
    }
    
    void test_method_(square) {
      assert::are_equal(1, enum_object<>::to_int32(line_cap::square), csf_);
      assert::are_equal("square", enum_object<>::to_string(line_cap::square), csf_);
      assert::are_equal(line_cap::square, enum_object<>::parse<line_cap>("square"), csf_);
    }
    
    void test_method_(round) {
      assert::are_equal(2, enum_object<>::to_int32(line_cap::round), csf_);
      assert::are_equal("round", enum_object<>::to_string(line_cap::round), csf_);
      assert::are_equal(line_cap::round, enum_object<>::parse<line_cap>("round"), csf_);
    }
  };
}
