#include <xtd/drawing/drawing_2d/line_join>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::drawing_2d;
using namespace xtd::tunit;

namespace xtd::drawing::drawing_2d::tests {
  class test_class_(line_join_tests) {
  public:
    void test_method_(miter) {
      assert::are_equal(0, enum_object<>::to_int32(line_join::miter), csf_);
      assert::are_equal("miter", enum_object<>::to_string(line_join::miter), csf_);
      assert::are_equal(line_join::miter, enum_object<>::parse<line_join>("miter"), csf_);
    }
    
    void test_method_(bevel) {
      assert::are_equal(1, enum_object<>::to_int32(line_join::bevel), csf_);
      assert::are_equal("bevel", enum_object<>::to_string(line_join::bevel), csf_);
      assert::are_equal(line_join::bevel, enum_object<>::parse<line_join>("bevel"), csf_);
    }
    
    void test_method_(round) {
      assert::are_equal(2, enum_object<>::to_int32(line_join::round), csf_);
      assert::are_equal("round", enum_object<>::to_string(line_join::round), csf_);
      assert::are_equal(line_join::round, enum_object<>::parse<line_join>("round"), csf_);
    }
    
    void test_method_(miter_clipped) {
      assert::are_equal(3, enum_object<>::to_int32(line_join::miter_clipped), csf_);
      assert::are_equal("miter_clipped", enum_object<>::to_string(line_join::miter_clipped), csf_);
      assert::are_equal(line_join::miter_clipped, enum_object<>::parse<line_join>("miter_clipped"), csf_);
    }
  };
}
