#include <xtd/drawing/drawing_2d/dash_style>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::drawing_2d;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(dash_style_tests) {
    auto test_method_(solid) {
      assert::are_equal(0, enum_object<>::to_int32(dash_style::solid));
      assert::are_equal("solid", enum_object<>::to_string(dash_style::solid));
      assert::are_equal(dash_style::solid, enum_object<>::parse<dash_style>("solid"));
    }
    
    auto test_method_(dash) {
      assert::are_equal(1, enum_object<>::to_int32(dash_style::dash));
      assert::are_equal("dash", enum_object<>::to_string(dash_style::dash));
      assert::are_equal(dash_style::dash, enum_object<>::parse<dash_style>("dash"));
    }
    
    auto test_method_(dot) {
      assert::are_equal(2, enum_object<>::to_int32(dash_style::dot));
      assert::are_equal("dot", enum_object<>::to_string(dash_style::dot));
      assert::are_equal(dash_style::dot, enum_object<>::parse<dash_style>("dot"));
    }
    
    auto test_method_(dash_dot) {
      assert::are_equal(3, enum_object<>::to_int32(dash_style::dash_dot));
      assert::are_equal("dash_dot", enum_object<>::to_string(dash_style::dash_dot));
      assert::are_equal(dash_style::dash_dot, enum_object<>::parse<dash_style>("dash_dot"));
    }
    
    auto test_method_(dash_dot_dot) {
      assert::are_equal(4, enum_object<>::to_int32(dash_style::dash_dot_dot));
      assert::are_equal("dash_dot_dot", enum_object<>::to_string(dash_style::dash_dot_dot));
      assert::are_equal(dash_style::dash_dot_dot, enum_object<>::parse<dash_style>("dash_dot_dot"));
    }
  };
}
