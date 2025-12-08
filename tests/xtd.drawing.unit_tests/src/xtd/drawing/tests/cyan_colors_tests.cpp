#include <xtd/drawing/cyan_colors>
#include <xtd/argument_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(cyan_colors_tests) {
    auto test_method_(teal) {
      auto c = cyan_colors::teal();
      
      assert::are_equal(cyan_colors::teal(), c);
      assert::are_equal(color::from_known_color(known_color::teal), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x80, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("teal", c.name());
      
      assert::are_equal("color [teal]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF008080, c.to_argb());
      assert::are_equal(known_color::teal, c.to_known_color());
    }
    
    auto test_method_(dark_cyan) {
      auto c = cyan_colors::dark_cyan();
      
      assert::are_equal(cyan_colors::dark_cyan(), c);
      assert::are_equal(color::from_known_color(known_color::dark_cyan), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x8B, c.g());
      assert::are_equal(0x8B, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_cyan", c.name());
      
      assert::are_equal("color [dark_cyan]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF008B8B, c.to_argb());
      assert::are_equal(known_color::dark_cyan, c.to_known_color());
    }
    
    auto test_method_(light_sea_green) {
      auto c = cyan_colors::light_sea_green();
      
      assert::are_equal(cyan_colors::light_sea_green(), c);
      assert::are_equal(color::from_known_color(known_color::light_sea_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x20, c.r());
      assert::are_equal(0xB2, c.g());
      assert::are_equal(0xAA, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_sea_green", c.name());
      
      assert::are_equal("color [light_sea_green]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF20B2AA, c.to_argb());
      assert::are_equal(known_color::light_sea_green, c.to_known_color());
    }
    
    auto test_method_(cadet_blue) {
      auto c = cyan_colors::cadet_blue();
      
      assert::are_equal(cyan_colors::cadet_blue(), c);
      assert::are_equal(color::from_known_color(known_color::cadet_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x5F, c.r());
      assert::are_equal(0x9E, c.g());
      assert::are_equal(0xA0, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("cadet_blue", c.name());
      
      assert::are_equal("color [cadet_blue]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF5F9EA0, c.to_argb());
      assert::are_equal(known_color::cadet_blue, c.to_known_color());
    }
    
    auto test_method_(dark_turquoise) {
      auto c = cyan_colors::dark_turquoise();
      
      assert::are_equal(cyan_colors::dark_turquoise(), c);
      assert::are_equal(color::from_known_color(known_color::dark_turquoise), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0xCE, c.g());
      assert::are_equal(0xD1, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_turquoise", c.name());
      
      assert::are_equal("color [dark_turquoise]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF00CED1, c.to_argb());
      assert::are_equal(known_color::dark_turquoise, c.to_known_color());
    }
    
    auto test_method_(medium_turquoise) {
      auto c = cyan_colors::medium_turquoise();
      
      assert::are_equal(cyan_colors::medium_turquoise(), c);
      assert::are_equal(color::from_known_color(known_color::medium_turquoise), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x48, c.r());
      assert::are_equal(0xD1, c.g());
      assert::are_equal(0xCC, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("medium_turquoise", c.name());
      
      assert::are_equal("color [medium_turquoise]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF48D1CC, c.to_argb());
      assert::are_equal(known_color::medium_turquoise, c.to_known_color());
    }
    
    auto test_method_(turquoise) {
      auto c = cyan_colors::turquoise();
      
      assert::are_equal(cyan_colors::turquoise(), c);
      assert::are_equal(color::from_known_color(known_color::turquoise), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x40, c.r());
      assert::are_equal(0xE0, c.g());
      assert::are_equal(0xD0, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("turquoise", c.name());
      
      assert::are_equal("color [turquoise]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF40E0D0, c.to_argb());
      assert::are_equal(known_color::turquoise, c.to_known_color());
    }
    
    auto test_method_(aqua) {
      auto c = cyan_colors::aqua();
      
      assert::are_equal(cyan_colors::aqua(), c);
      assert::are_equal(color::from_known_color(known_color::aqua), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("aqua", c.name());
      
      assert::are_equal("color [aqua]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF00FFFF, c.to_argb());
      assert::are_equal(known_color::aqua, c.to_known_color());
    }
    
    auto test_method_(cyan) {
      auto c = cyan_colors::cyan();
      
      assert::are_equal(cyan_colors::cyan(), c);
      assert::are_equal(color::from_known_color(known_color::cyan), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("cyan", c.name());
      
      assert::are_equal("color [cyan]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF00FFFF, c.to_argb());
      assert::are_equal(known_color::cyan, c.to_known_color());
    }
    
    auto test_method_(aquamarine) {
      auto c = cyan_colors::aquamarine();
      
      assert::are_equal(cyan_colors::aquamarine(), c);
      assert::are_equal(color::from_known_color(known_color::aquamarine), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x7F, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xD4, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("aquamarine", c.name());
      
      assert::are_equal("color [aquamarine]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF7FFFD4, c.to_argb());
      assert::are_equal(known_color::aquamarine, c.to_known_color());
    }
    
    auto test_method_(pale_turquoise) {
      auto c = cyan_colors::pale_turquoise();
      
      assert::are_equal(cyan_colors::pale_turquoise(), c);
      assert::are_equal(color::from_known_color(known_color::pale_turquoise), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xAF, c.r());
      assert::are_equal(0xEE, c.g());
      assert::are_equal(0xEE, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("pale_turquoise", c.name());
      
      assert::are_equal("color [pale_turquoise]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFAFEEEE, c.to_argb());
      assert::are_equal(known_color::pale_turquoise, c.to_known_color());
    }
    
    auto test_method_(light_cyan) {
      auto c = cyan_colors::light_cyan();
      
      assert::are_equal(cyan_colors::light_cyan(), c);
      assert::are_equal(color::from_known_color(known_color::light_cyan), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xE0, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_cyan", c.name());
      
      assert::are_equal("color [light_cyan]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFE0FFFF, c.to_argb());
      assert::are_equal(known_color::light_cyan, c.to_known_color());
    }
  };
}
