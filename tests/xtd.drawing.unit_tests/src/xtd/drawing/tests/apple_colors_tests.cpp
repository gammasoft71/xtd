#include <xtd/drawing/apple_colors>
#include <xtd/argument_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(apple_colors_tests) {
    auto test_method_(black) {
      auto c = apple_colors::black();
      
      assert::are_equal(apple_colors::black(), c);
      assert::are_equal(color::from_known_color(known_color::apple_black), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("apple_black", c.name());
      
      assert::are_equal("color [apple_black]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF000000, c.to_argb());
      assert::are_equal(known_color::apple_black, c.to_known_color());
    }
    
    auto test_method_(blue) {
      auto c = apple_colors::blue();
      
      assert::are_equal(apple_colors::blue(), c);
      assert::are_equal(color::from_known_color(known_color::apple_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("apple_blue", c.name());
      
      assert::are_equal("color [apple_blue]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF0000FF, c.to_argb());
      assert::are_equal(known_color::apple_blue, c.to_known_color());
    }
    
    auto test_method_(brown) {
      auto c = apple_colors::brown();
      
      assert::are_equal(apple_colors::brown(), c);
      assert::are_equal(color::from_known_color(known_color::apple_brown), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x99, c.r());
      assert::are_equal(0x66, c.g());
      assert::are_equal(0x33, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("apple_brown", c.name());
      
      assert::are_equal("color [apple_brown]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF996633, c.to_argb());
      assert::are_equal(known_color::apple_brown, c.to_known_color());
    }
    
    auto test_method_(cyan) {
      auto c = apple_colors::cyan();
      
      assert::are_equal(apple_colors::cyan(), c);
      assert::are_equal(color::from_known_color(known_color::apple_cyan), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x21, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("apple_cyan", c.name());
      
      assert::are_equal("color [apple_cyan]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF21FFFF, c.to_argb());
      assert::are_equal(known_color::apple_cyan, c.to_known_color());
    }
    
    auto test_method_(green) {
      auto c = apple_colors::green();
      
      assert::are_equal(apple_colors::green(), c);
      assert::are_equal(color::from_known_color(known_color::apple_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x21, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0x06, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("apple_green", c.name());
      
      assert::are_equal("color [apple_green]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF21FF06, c.to_argb());
      assert::are_equal(known_color::apple_green, c.to_known_color());
    }
    
    auto test_method_(magenta) {
      auto c = apple_colors::magenta();
      
      assert::are_equal(apple_colors::magenta(), c);
      assert::are_equal(color::from_known_color(known_color::apple_magenta), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFB, c.r());
      assert::are_equal(0x02, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("apple_magenta", c.name());
      
      assert::are_equal("color [apple_magenta]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFB02FF, c.to_argb());
      assert::are_equal(known_color::apple_magenta, c.to_known_color());
    }
    
    auto test_method_(orange) {
      auto c = apple_colors::orange();
      
      assert::are_equal(apple_colors::orange(), c);
      assert::are_equal(color::from_known_color(known_color::apple_orange), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFD, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x08, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("apple_orange", c.name());
      
      assert::are_equal("color [apple_orange]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFD8008, c.to_argb());
      assert::are_equal(known_color::apple_orange, c.to_known_color());
    }
    
    auto test_method_(purple) {
      auto c = apple_colors::purple();
      
      assert::are_equal(apple_colors::purple(), c);
      assert::are_equal(color::from_known_color(known_color::apple_purple), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x80, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x80, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("apple_purple", c.name());
      
      assert::are_equal("color [apple_purple]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF800080, c.to_argb());
      assert::are_equal(known_color::apple_purple, c.to_known_color());
    }
    
    auto test_method_(red) {
      auto c = apple_colors::red();
      
      assert::are_equal(apple_colors::red(), c);
      assert::are_equal(color::from_known_color(known_color::apple_red), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFB, c.r());
      assert::are_equal(0x02, c.g());
      assert::are_equal(0x07, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("apple_red", c.name());
      
      assert::are_equal("color [apple_red]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFB0207, c.to_argb());
      assert::are_equal(known_color::apple_red, c.to_known_color());
    }
    
    auto test_method_(yellow) {
      auto c = apple_colors::yellow();
      
      assert::are_equal(apple_colors::yellow(), c);
      assert::are_equal(color::from_known_color(known_color::apple_yellow), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0x0A, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("apple_yellow", c.name());
      
      assert::are_equal("color [apple_yellow]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFFF0A, c.to_argb());
      assert::are_equal(known_color::apple_yellow, c.to_known_color());
    }
    
    auto test_method_(white) {
      auto c = apple_colors::white();
      
      assert::are_equal(apple_colors::white(), c);
      assert::are_equal(color::from_known_color(known_color::apple_white), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("apple_white", c.name());
      
      assert::are_equal("color [apple_white]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFFFFF, c.to_argb());
      assert::are_equal(known_color::apple_white, c.to_known_color());
    }
  };
}
