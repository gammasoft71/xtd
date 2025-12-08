#include <xtd/forms/border_sides>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(border_sides_tests) {
  public:
    auto test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(border_sides::none));
      assert::are_equal("none", enum_object<>::to_string(border_sides::none));
      assert::are_equal(border_sides::none, enum_object<>::parse<border_sides>("none"));
    }
    
    auto test_method_(top) {
      assert::are_equal(1, enum_object<>::to_int32(border_sides::top));
      assert::are_equal("top", enum_object<>::to_string(border_sides::top));
      assert::are_equal(border_sides::top, enum_object<>::parse<border_sides>("top"));
    }
    
    auto test_method_(bottom) {
      assert::are_equal(2, enum_object<>::to_int32(border_sides::bottom));
      assert::are_equal("bottom", enum_object<>::to_string(border_sides::bottom));
      assert::are_equal(border_sides::bottom, enum_object<>::parse<border_sides>("bottom"));
    }
    
    auto test_method_(left) {
      assert::are_equal(4, enum_object<>::to_int32(border_sides::left));
      assert::are_equal("left", enum_object<>::to_string(border_sides::left));
      assert::are_equal(border_sides::left, enum_object<>::parse<border_sides>("left"));
    }
    
    auto test_method_(right) {
      assert::are_equal(8, enum_object<>::to_int32(border_sides::right));
      assert::are_equal("right", enum_object<>::to_string(border_sides::right));
      assert::are_equal(border_sides::right, enum_object<>::parse<border_sides>("right"));
    }
  };
}
