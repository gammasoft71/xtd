#include <xtd/drawing/yellow_colors>
#include <xtd/argument_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(yellow_colors_tests) {
    auto test_method_(dark_khaki) {
      auto c = yellow_colors::dark_khaki();
      
      assert::are_equal(yellow_colors::dark_khaki(), c);
      assert::are_equal(color::from_known_color(known_color::dark_khaki), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xBD, c.r());
      assert::are_equal(0xB7, c.g());
      assert::are_equal(0x6B, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_khaki", c.name());
      
      assert::are_equal("color [dark_khaki]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFBDB76B, c.to_argb());
      assert::are_equal(known_color::dark_khaki, c.to_known_color());
    }
    
    auto test_method_(gold) {
      auto c = yellow_colors::gold();
      
      assert::are_equal(yellow_colors::gold(), c);
      assert::are_equal(color::from_known_color(known_color::gold), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xD7, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("gold", c.name());
      
      assert::are_equal("color [gold]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFD700, c.to_argb());
      assert::are_equal(known_color::gold, c.to_known_color());
    }
    
    auto test_method_(khaki) {
      auto c = yellow_colors::khaki();
      
      assert::are_equal(yellow_colors::khaki(), c);
      assert::are_equal(color::from_known_color(known_color::khaki), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF0, c.r());
      assert::are_equal(0xE6, c.g());
      assert::are_equal(0x8C, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("khaki", c.name());
      
      assert::are_equal("color [khaki]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF0E68C, c.to_argb());
      assert::are_equal(known_color::khaki, c.to_known_color());
    }
    
    auto test_method_(peach_puff) {
      auto c = yellow_colors::peach_puff();
      
      assert::are_equal(yellow_colors::peach_puff(), c);
      assert::are_equal(color::from_known_color(known_color::peach_puff), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xDA, c.g());
      assert::are_equal(0xB9, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("peach_puff", c.name());
      
      assert::are_equal("color [peach_puff]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFDAB9, c.to_argb());
      assert::are_equal(known_color::peach_puff, c.to_known_color());
    }
    
    auto test_method_(yellow) {
      auto c = yellow_colors::yellow();
      
      assert::are_equal(yellow_colors::yellow(), c);
      assert::are_equal(color::from_known_color(known_color::yellow), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("yellow", c.name());
      
      assert::are_equal("color [yellow]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFFF00, c.to_argb());
      assert::are_equal(known_color::yellow, c.to_known_color());
    }
    
    auto test_method_(pale_goldenrod) {
      auto c = yellow_colors::pale_goldenrod();
      
      assert::are_equal(yellow_colors::pale_goldenrod(), c);
      assert::are_equal(color::from_known_color(known_color::pale_goldenrod), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xEE, c.r());
      assert::are_equal(0xE8, c.g());
      assert::are_equal(0xAA, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("pale_goldenrod", c.name());
      
      assert::are_equal("color [pale_goldenrod]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFEEE8AA, c.to_argb());
      assert::are_equal(known_color::pale_goldenrod, c.to_known_color());
    }
    
    auto test_method_(moccasin) {
      auto c = yellow_colors::moccasin();
      
      assert::are_equal(yellow_colors::moccasin(), c);
      assert::are_equal(color::from_known_color(known_color::moccasin), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xE4, c.g());
      assert::are_equal(0xB5, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("moccasin", c.name());
      
      assert::are_equal("color [moccasin]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFE4B5, c.to_argb());
      assert::are_equal(known_color::moccasin, c.to_known_color());
    }
    
    auto test_method_(papaya_whip) {
      auto c = yellow_colors::papaya_whip();
      
      assert::are_equal(yellow_colors::papaya_whip(), c);
      assert::are_equal(color::from_known_color(known_color::papaya_whip), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xEF, c.g());
      assert::are_equal(0xD5, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("papaya_whip", c.name());
      
      assert::are_equal("color [papaya_whip]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFEFD5, c.to_argb());
      assert::are_equal(known_color::papaya_whip, c.to_known_color());
    }
    
    auto test_method_(light_goldenrod_yellow) {
      auto c = yellow_colors::light_goldenrod_yellow();
      
      assert::are_equal(yellow_colors::light_goldenrod_yellow(), c);
      assert::are_equal(color::from_known_color(known_color::light_goldenrod_yellow), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFA, c.r());
      assert::are_equal(0xFA, c.g());
      assert::are_equal(0xD2, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_goldenrod_yellow", c.name());
      
      assert::are_equal("color [light_goldenrod_yellow]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFAFAD2, c.to_argb());
      assert::are_equal(known_color::light_goldenrod_yellow, c.to_known_color());
    }
    
    auto test_method_(lemon_chiffon) {
      auto c = yellow_colors::lemon_chiffon();
      
      assert::are_equal(yellow_colors::lemon_chiffon(), c);
      assert::are_equal(color::from_known_color(known_color::lemon_chiffon), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFA, c.g());
      assert::are_equal(0xCD, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("lemon_chiffon", c.name());
      
      assert::are_equal("color [lemon_chiffon]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFFACD, c.to_argb());
      assert::are_equal(known_color::lemon_chiffon, c.to_known_color());
    }
    
    auto test_method_(light_yellow) {
      auto c = yellow_colors::light_yellow();
      
      assert::are_equal(yellow_colors::light_yellow(), c);
      assert::are_equal(color::from_known_color(known_color::light_yellow), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xE0, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_yellow", c.name());
      
      assert::are_equal("color [light_yellow]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFFFE0, c.to_argb());
      assert::are_equal(known_color::light_yellow, c.to_known_color());
    }
  };
}
