#include <xtd/drawing/pink_colors>
#include <xtd/argument_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(pink_colors_tests) {
    auto test_method_(medium_violet_red) {
      auto c = pink_colors::medium_violet_red();
      
      assert::are_equal(pink_colors::medium_violet_red(), c);
      assert::are_equal(color::from_known_color(known_color::medium_violet_red), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xC7, c.r());
      assert::are_equal(0x15, c.g());
      assert::are_equal(0x85, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("medium_violet_red", c.name());
      
      assert::are_equal("color [medium_violet_red]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFC71585, c.to_argb());
      assert::are_equal(known_color::medium_violet_red, c.to_known_color());
    }
    
    auto test_method_(deep_pink) {
      auto c = pink_colors::deep_pink();
      
      assert::are_equal(pink_colors::deep_pink(), c);
      assert::are_equal(color::from_known_color(known_color::deep_pink), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x14, c.g());
      assert::are_equal(0x93, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("deep_pink", c.name());
      
      assert::are_equal("color [deep_pink]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF1493, c.to_argb());
      assert::are_equal(known_color::deep_pink, c.to_known_color());
    }
    
    auto test_method_(pale_violet_red) {
      auto c = pink_colors::pale_violet_red();
      
      assert::are_equal(pink_colors::pale_violet_red(), c);
      assert::are_equal(color::from_known_color(known_color::pale_violet_red), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xDB, c.r());
      assert::are_equal(0x70, c.g());
      assert::are_equal(0x93, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("pale_violet_red", c.name());
      
      assert::are_equal("color [pale_violet_red]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFDB7093, c.to_argb());
      assert::are_equal(known_color::pale_violet_red, c.to_known_color());
    }
    
    auto test_method_(hot_pink) {
      auto c = pink_colors::hot_pink();
      
      assert::are_equal(pink_colors::hot_pink(), c);
      assert::are_equal(color::from_known_color(known_color::hot_pink), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x69, c.g());
      assert::are_equal(0xB4, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("hot_pink", c.name());
      
      assert::are_equal("color [hot_pink]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF69B4, c.to_argb());
      assert::are_equal(known_color::hot_pink, c.to_known_color());
    }
    
    auto test_method_(light_pink) {
      auto c = pink_colors::light_pink();
      
      assert::are_equal(pink_colors::light_pink(), c);
      assert::are_equal(color::from_known_color(known_color::light_pink), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xB6, c.g());
      assert::are_equal(0xC1, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_pink", c.name());
      
      assert::are_equal("color [light_pink]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFB6C1, c.to_argb());
      assert::are_equal(known_color::light_pink, c.to_known_color());
    }
    
    auto test_method_(pink) {
      auto c = pink_colors::pink();
      
      assert::are_equal(pink_colors::pink(), c);
      assert::are_equal(color::from_known_color(known_color::pink), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xC0, c.g());
      assert::are_equal(0xCB, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("pink", c.name());
      
      assert::are_equal("color [pink]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFC0CB, c.to_argb());
      assert::are_equal(known_color::pink, c.to_known_color());
    }
  };
}
