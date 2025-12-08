#include <xtd/drawing/white_colors>
#include <xtd/argument_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(white_colors_tests) {
    auto test_method_(misty_rose) {
      auto c = white_colors::misty_rose();
      
      assert::are_equal(white_colors::misty_rose(), c);
      assert::are_equal(color::from_known_color(known_color::misty_rose), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xE4, c.g());
      assert::are_equal(0xE1, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("misty_rose", c.name());
      
      assert::are_equal("color [misty_rose]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFE4E1, c.to_argb());
      assert::are_equal(known_color::misty_rose, c.to_known_color());
    }
    
    auto test_method_(antique_white) {
      auto c = white_colors::antique_white();
      
      assert::are_equal(white_colors::antique_white(), c);
      assert::are_equal(color::from_known_color(known_color::antique_white), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFA, c.r());
      assert::are_equal(0xEB, c.g());
      assert::are_equal(0xD7, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("antique_white", c.name());
      
      assert::are_equal("color [antique_white]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFAEBD7, c.to_argb());
      assert::are_equal(known_color::antique_white, c.to_known_color());
    }
    
    auto test_method_(linen) {
      auto c = white_colors::linen();
      
      assert::are_equal(white_colors::linen(), c);
      assert::are_equal(color::from_known_color(known_color::linen), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFA, c.r());
      assert::are_equal(0xF0, c.g());
      assert::are_equal(0xE6, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("linen", c.name());
      
      assert::are_equal("color [linen]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFAF0E6, c.to_argb());
      assert::are_equal(known_color::linen, c.to_known_color());
    }
    
    auto test_method_(beige) {
      auto c = white_colors::beige();
      
      assert::are_equal(white_colors::beige(), c);
      assert::are_equal(color::from_known_color(known_color::beige), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF5, c.r());
      assert::are_equal(0xF5, c.g());
      assert::are_equal(0xDC, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("beige", c.name());
      
      assert::are_equal("color [beige]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF5F5DC, c.to_argb());
      assert::are_equal(known_color::beige, c.to_known_color());
    }
    
    auto test_method_(white_smoke) {
      auto c = white_colors::white_smoke();
      
      assert::are_equal(white_colors::white_smoke(), c);
      assert::are_equal(color::from_known_color(known_color::white_smoke), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF5, c.r());
      assert::are_equal(0xF5, c.g());
      assert::are_equal(0xF5, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("white_smoke", c.name());
      
      assert::are_equal("color [white_smoke]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF5F5F5, c.to_argb());
      assert::are_equal(known_color::white_smoke, c.to_known_color());
    }
    
    auto test_method_(lavender_blush) {
      auto c = white_colors::lavender_blush();
      
      assert::are_equal(white_colors::lavender_blush(), c);
      assert::are_equal(color::from_known_color(known_color::lavender_blush), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xF0, c.g());
      assert::are_equal(0xF5, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("lavender_blush", c.name());
      
      assert::are_equal("color [lavender_blush]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFF0F5, c.to_argb());
      assert::are_equal(known_color::lavender_blush, c.to_known_color());
    }
    
    auto test_method_(old_lace) {
      auto c = white_colors::old_lace();
      
      assert::are_equal(white_colors::old_lace(), c);
      assert::are_equal(color::from_known_color(known_color::old_lace), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFD, c.r());
      assert::are_equal(0xF5, c.g());
      assert::are_equal(0xE6, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("old_lace", c.name());
      
      assert::are_equal("color [old_lace]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFDF5E6, c.to_argb());
      assert::are_equal(known_color::old_lace, c.to_known_color());
    }
    
    auto test_method_(alice_blue) {
      auto c = white_colors::alice_blue();
      
      assert::are_equal(white_colors::alice_blue(), c);
      assert::are_equal(color::from_known_color(known_color::alice_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF0, c.r());
      assert::are_equal(0xF8, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("alice_blue", c.name());
      
      assert::are_equal("color [alice_blue]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF0F8FF, c.to_argb());
      assert::are_equal(known_color::alice_blue, c.to_known_color());
    }
    
    auto test_method_(sea_shell) {
      auto c = white_colors::sea_shell();
      
      assert::are_equal(white_colors::sea_shell(), c);
      assert::are_equal(color::from_known_color(known_color::sea_shell), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xF5, c.g());
      assert::are_equal(0xEE, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("sea_shell", c.name());
      
      assert::are_equal("color [sea_shell]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFF5EE, c.to_argb());
      assert::are_equal(known_color::sea_shell, c.to_known_color());
    }
    
    auto test_method_(ghost_white) {
      auto c = white_colors::ghost_white();
      
      assert::are_equal(white_colors::ghost_white(), c);
      assert::are_equal(color::from_known_color(known_color::ghost_white), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF8, c.r());
      assert::are_equal(0xF8, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("ghost_white", c.name());
      
      assert::are_equal("color [ghost_white]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF8F8FF, c.to_argb());
      assert::are_equal(known_color::ghost_white, c.to_known_color());
    }
    
    auto test_method_(honeydew) {
      auto c = white_colors::honeydew();
      
      assert::are_equal(white_colors::honeydew(), c);
      assert::are_equal(color::from_known_color(known_color::honeydew), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF0, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xF0, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("honeydew", c.name());
      
      assert::are_equal("color [honeydew]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF0FFF0, c.to_argb());
      assert::are_equal(known_color::honeydew, c.to_known_color());
    }
    
    auto test_method_(floral_white) {
      auto c = white_colors::floral_white();
      
      assert::are_equal(white_colors::floral_white(), c);
      assert::are_equal(color::from_known_color(known_color::floral_white), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFA, c.g());
      assert::are_equal(0xF0, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("floral_white", c.name());
      
      assert::are_equal("color [floral_white]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFFAF0, c.to_argb());
      assert::are_equal(known_color::floral_white, c.to_known_color());
    }
    
    auto test_method_(azure) {
      auto c = white_colors::azure();
      
      assert::are_equal(white_colors::azure(), c);
      assert::are_equal(color::from_known_color(known_color::azure), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF0, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("azure", c.name());
      
      assert::are_equal("color [azure]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF0FFFF, c.to_argb());
      assert::are_equal(known_color::azure, c.to_known_color());
    }
    
    auto test_method_(mint_cream) {
      auto c = white_colors::mint_cream();
      
      assert::are_equal(white_colors::mint_cream(), c);
      assert::are_equal(color::from_known_color(known_color::mint_cream), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF5, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xFA, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("mint_cream", c.name());
      
      assert::are_equal("color [mint_cream]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF5FFFA, c.to_argb());
      assert::are_equal(known_color::mint_cream, c.to_known_color());
    }
    
    auto test_method_(snow) {
      auto c = white_colors::snow();
      
      assert::are_equal(white_colors::snow(), c);
      assert::are_equal(color::from_known_color(known_color::snow), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFA, c.g());
      assert::are_equal(0xFA, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("snow", c.name());
      
      assert::are_equal("color [snow]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFFAFA, c.to_argb());
      assert::are_equal(known_color::snow, c.to_known_color());
    }
    
    auto test_method_(ivory) {
      auto c = white_colors::ivory();
      
      assert::are_equal(white_colors::ivory(), c);
      assert::are_equal(color::from_known_color(known_color::ivory), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xF0, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("ivory", c.name());
      
      assert::are_equal("color [ivory]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFFFF0, c.to_argb());
      assert::are_equal(known_color::ivory, c.to_known_color());
    }
    
    auto test_method_(white) {
      auto c = white_colors::white();
      
      assert::are_equal(white_colors::white(), c);
      assert::are_equal(color::from_known_color(known_color::white), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("white", c.name());
      
      assert::are_equal("color [white]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFFFFF, c.to_argb());
      assert::are_equal(known_color::white, c.to_known_color());
    }
  };
}
