#include <xtd/forms/dock_style>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(dock_style_tests) {
  public:
    auto test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(dock_style::none));
      assert::are_equal("none", enum_object<>::to_string(dock_style::none));
      assert::are_equal(dock_style::none, enum_object<>::parse<dock_style>("none"));
    }
    
    auto test_method_(top) {
      assert::are_equal(1, enum_object<>::to_int32(dock_style::top));
      assert::are_equal("top", enum_object<>::to_string(dock_style::top));
      assert::are_equal(dock_style::top, enum_object<>::parse<dock_style>("top"));
    }
    
    auto test_method_(bottom) {
      assert::are_equal(2, enum_object<>::to_int32(dock_style::bottom));
      assert::are_equal("bottom", enum_object<>::to_string(dock_style::bottom));
      assert::are_equal(dock_style::bottom, enum_object<>::parse<dock_style>("bottom"));
    }
    
    auto test_method_(left) {
      assert::are_equal(3, enum_object<>::to_int32(dock_style::left));
      assert::are_equal("left", enum_object<>::to_string(dock_style::left));
      assert::are_equal(dock_style::left, enum_object<>::parse<dock_style>("left"));
    }
    
    auto test_method_(right) {
      assert::are_equal(4, enum_object<>::to_int32(dock_style::right));
      assert::are_equal("right", enum_object<>::to_string(dock_style::right));
      assert::are_equal(dock_style::right, enum_object<>::parse<dock_style>("right"));
    }
    
    auto test_method_(fill) {
      assert::are_equal(5, enum_object<>::to_int32(dock_style::fill));
      assert::are_equal("fill", enum_object<>::to_string(dock_style::fill));
      assert::are_equal(dock_style::fill, enum_object<>::parse<dock_style>("fill"));
    }
  };
}
