#include <xtd/drawing/red_colors>
#include <xtd/argument_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(red_colors_tests) {
    auto test_method_(dark_red) {
      auto c = red_colors::dark_red();
      
      assert::are_equal(red_colors::dark_red(), c);
      assert::are_equal(color::from_known_color(known_color::dark_red), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x8B, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_red", c.name());
      
      assert::are_equal("color [dark_red]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF8B0000, c.to_argb());
      assert::are_equal(known_color::dark_red, c.to_known_color());
    }
    
    auto test_method_(red) {
      auto c = red_colors::red();
      
      assert::are_equal(red_colors::red(), c);
      assert::are_equal(color::from_known_color(known_color::red), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("red", c.name());
      
      assert::are_equal("color [red]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF0000, c.to_argb());
      assert::are_equal(known_color::red, c.to_known_color());
    }
    
    auto test_method_(firebrick) {
      auto c = red_colors::firebrick();
      
      assert::are_equal(red_colors::firebrick(), c);
      assert::are_equal(color::from_known_color(known_color::firebrick), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xB2, c.r());
      assert::are_equal(0x22, c.g());
      assert::are_equal(0x22, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("firebrick", c.name());
      
      assert::are_equal("color [firebrick]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFB22222, c.to_argb());
      assert::are_equal(known_color::firebrick, c.to_known_color());
    }
    
    auto test_method_(crimson) {
      auto c = red_colors::crimson();
      
      assert::are_equal(red_colors::crimson(), c);
      assert::are_equal(color::from_known_color(known_color::crimson), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xDC, c.r());
      assert::are_equal(0x14, c.g());
      assert::are_equal(0x3C, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crimson", c.name());
      
      assert::are_equal("color [crimson]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFDC143C, c.to_argb());
      assert::are_equal(known_color::crimson, c.to_known_color());
    }
    
    auto test_method_(indian_red) {
      auto c = red_colors::indian_red();
      
      assert::are_equal(red_colors::indian_red(), c);
      assert::are_equal(color::from_known_color(known_color::indian_red), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xCD, c.r());
      assert::are_equal(0x5C, c.g());
      assert::are_equal(0x5C, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("indian_red", c.name());
      
      assert::are_equal("color [indian_red]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFCD5C5C, c.to_argb());
      assert::are_equal(known_color::indian_red, c.to_known_color());
    }
    
    auto test_method_(light_coral) {
      auto c = red_colors::light_coral();
      
      assert::are_equal(red_colors::light_coral(), c);
      assert::are_equal(color::from_known_color(known_color::light_coral), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF0, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x80, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_coral", c.name());
      
      assert::are_equal("color [light_coral]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF08080, c.to_argb());
      assert::are_equal(known_color::light_coral, c.to_known_color());
    }
    
    auto test_method_(salmon) {
      auto c = red_colors::salmon();
      
      assert::are_equal(red_colors::salmon(), c);
      assert::are_equal(color::from_known_color(known_color::salmon), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFA, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x72, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("salmon", c.name());
      
      assert::are_equal("color [salmon]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFA8072, c.to_argb());
      assert::are_equal(known_color::salmon, c.to_known_color());
    }
    
    auto test_method_(dark_salmon) {
      auto c = red_colors::dark_salmon();
      
      assert::are_equal(red_colors::dark_salmon(), c);
      assert::are_equal(color::from_known_color(known_color::dark_salmon), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xE9, c.r());
      assert::are_equal(0x96, c.g());
      assert::are_equal(0x7A, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_salmon", c.name());
      
      assert::are_equal("color [dark_salmon]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFE9967A, c.to_argb());
      assert::are_equal(known_color::dark_salmon, c.to_known_color());
    }
    
    auto test_method_(light_salmon) {
      auto c = red_colors::light_salmon();
      
      assert::are_equal(red_colors::light_salmon(), c);
      assert::are_equal(color::from_known_color(known_color::light_salmon), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xA0, c.g());
      assert::are_equal(0x7A, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_salmon", c.name());
      
      assert::are_equal("color [light_salmon]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFA07A, c.to_argb());
      assert::are_equal(known_color::light_salmon, c.to_known_color());
    }
  };
}
