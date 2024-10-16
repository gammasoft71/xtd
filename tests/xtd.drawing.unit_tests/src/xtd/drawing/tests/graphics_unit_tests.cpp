#include <xtd/drawing/graphics_unit>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(graphics_unit_tests) {
    void test_method_(world) {
      assert::are_equal(0, enum_object<>::to_int32(graphics_unit::world));
      assert::are_equal("world", enum_object<>::to_string(graphics_unit::world));
      assert::are_equal(graphics_unit::world, enum_object<>::parse<graphics_unit>("world"));
    }
    
    void test_method_(display) {
      assert::are_equal(1, enum_object<>::to_int32(graphics_unit::display));
      assert::are_equal("display", enum_object<>::to_string(graphics_unit::display));
      assert::are_equal(graphics_unit::display, enum_object<>::parse<graphics_unit>("display"));
    }
    
    void test_method_(pixel) {
      assert::are_equal(2, enum_object<>::to_int32(graphics_unit::pixel));
      assert::are_equal("pixel", enum_object<>::to_string(graphics_unit::pixel));
      assert::are_equal(graphics_unit::pixel, enum_object<>::parse<graphics_unit>("pixel"));
    }
    
    void test_method_(point) {
      assert::are_equal(3, enum_object<>::to_int32(graphics_unit::point));
      assert::are_equal("point", enum_object<>::to_string(graphics_unit::point));
      assert::are_equal(graphics_unit::point, enum_object<>::parse<graphics_unit>("point"));
    }
    
    void test_method_(inch) {
      assert::are_equal(4, enum_object<>::to_int32(graphics_unit::inch));
      assert::are_equal("inch", enum_object<>::to_string(graphics_unit::inch));
      assert::are_equal(graphics_unit::inch, enum_object<>::parse<graphics_unit>("inch"));
    }
    
    void test_method_(document) {
      assert::are_equal(5, enum_object<>::to_int32(graphics_unit::document));
      assert::are_equal("document", enum_object<>::to_string(graphics_unit::document));
      assert::are_equal(graphics_unit::document, enum_object<>::parse<graphics_unit>("document"));
    }
    
    void test_method_(millimeter) {
      assert::are_equal(6, enum_object<>::to_int32(graphics_unit::millimeter));
      assert::are_equal("millimeter", enum_object<>::to_string(graphics_unit::millimeter));
      assert::are_equal(graphics_unit::millimeter, enum_object<>::parse<graphics_unit>("millimeter"));
    }
  };
}
