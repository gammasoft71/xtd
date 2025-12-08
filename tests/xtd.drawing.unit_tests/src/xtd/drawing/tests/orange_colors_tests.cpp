#include <xtd/drawing/orange_colors>
#include <xtd/argument_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(orange_colors_tests) {
    auto test_method_(orange_red) {
      auto c = orange_colors::orange_red();
      
      assert::are_equal(orange_colors::orange_red(), c);
      assert::are_equal(color::from_known_color(known_color::orange_red), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x45, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("orange_red", c.name());
      
      assert::are_equal("color [orange_red]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF4500, c.to_argb());
      assert::are_equal(known_color::orange_red, c.to_known_color());
    }
    
    auto test_method_(tomato) {
      auto c = orange_colors::tomato();
      
      assert::are_equal(orange_colors::tomato(), c);
      assert::are_equal(color::from_known_color(known_color::tomato), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x63, c.g());
      assert::are_equal(0x47, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("tomato", c.name());
      
      assert::are_equal("color [tomato]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF6347, c.to_argb());
      assert::are_equal(known_color::tomato, c.to_known_color());
    }
    
    auto test_method_(dark_orange) {
      auto c = orange_colors::dark_orange();
      
      assert::are_equal(orange_colors::dark_orange(), c);
      assert::are_equal(color::from_known_color(known_color::dark_orange), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x8C, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_orange", c.name());
      
      assert::are_equal("color [dark_orange]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF8C00, c.to_argb());
      assert::are_equal(known_color::dark_orange, c.to_known_color());
    }
    
    auto test_method_(coral) {
      auto c = orange_colors::coral();
      
      assert::are_equal(orange_colors::coral(), c);
      assert::are_equal(color::from_known_color(known_color::coral), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x7F, c.g());
      assert::are_equal(0x50, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("coral", c.name());
      
      assert::are_equal("color [coral]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF7F50, c.to_argb());
      assert::are_equal(known_color::coral, c.to_known_color());
    }
    
    auto test_method_(orange) {
      auto c = orange_colors::orange();
      
      assert::are_equal(orange_colors::orange(), c);
      assert::are_equal(color::from_known_color(known_color::orange), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xA5, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("orange", c.name());
      
      assert::are_equal("color [orange]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFA500, c.to_argb());
      assert::are_equal(known_color::orange, c.to_known_color());
    }
  };
}
