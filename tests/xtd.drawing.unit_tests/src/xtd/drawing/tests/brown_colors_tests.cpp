#include <xtd/drawing/brown_colors>
#include <xtd/argument_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(brown_colors_tests) {
    auto test_method_(maroon) {
      auto c = brown_colors::maroon();
      
      assert::are_equal(brown_colors::maroon(), c);
      assert::are_equal(color::from_known_color(known_color::maroon), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x80, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("maroon", c.name());
      
      assert::are_equal("color [maroon]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF800000, c.to_argb());
      assert::are_equal(known_color::maroon, c.to_known_color());
    }
    
    auto test_method_(brown) {
      auto c = brown_colors::brown();
      
      assert::are_equal(brown_colors::brown(), c);
      assert::are_equal(color::from_known_color(known_color::brown), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xA5, c.r());
      assert::are_equal(0x2A, c.g());
      assert::are_equal(0x2A, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("brown", c.name());
      
      assert::are_equal("color [brown]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFA52A2A, c.to_argb());
      assert::are_equal(known_color::brown, c.to_known_color());
    }
    
    auto test_method_(saddle_brown) {
      auto c = brown_colors::saddle_brown();
      
      assert::are_equal(brown_colors::saddle_brown(), c);
      assert::are_equal(color::from_known_color(known_color::saddle_brown), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x8B, c.r());
      assert::are_equal(0x45, c.g());
      assert::are_equal(0x13, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("saddle_brown", c.name());
      
      assert::are_equal("color [saddle_brown]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF8B4513, c.to_argb());
      assert::are_equal(known_color::saddle_brown, c.to_known_color());
    }
    
    auto test_method_(sienna) {
      auto c = brown_colors::sienna();
      
      assert::are_equal(brown_colors::sienna(), c);
      assert::are_equal(color::from_known_color(known_color::sienna), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xA0, c.r());
      assert::are_equal(0x52, c.g());
      assert::are_equal(0x2D, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("sienna", c.name());
      
      assert::are_equal("color [sienna]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFA0522D, c.to_argb());
      assert::are_equal(known_color::sienna, c.to_known_color());
    }
    
    auto test_method_(chocolate) {
      auto c = brown_colors::chocolate();
      
      assert::are_equal(brown_colors::chocolate(), c);
      assert::are_equal(color::from_known_color(known_color::chocolate), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xD2, c.r());
      assert::are_equal(0x69, c.g());
      assert::are_equal(0x1E, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("chocolate", c.name());
      
      assert::are_equal("color [chocolate]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFD2691E, c.to_argb());
      assert::are_equal(known_color::chocolate, c.to_known_color());
    }
    
    auto test_method_(dark_goldenrod) {
      auto c = brown_colors::dark_goldenrod();
      
      assert::are_equal(brown_colors::dark_goldenrod(), c);
      assert::are_equal(color::from_known_color(known_color::dark_goldenrod), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xB8, c.r());
      assert::are_equal(0x86, c.g());
      assert::are_equal(0x0B, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_goldenrod", c.name());
      
      assert::are_equal("color [dark_goldenrod]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFB8860B, c.to_argb());
      assert::are_equal(known_color::dark_goldenrod, c.to_known_color());
    }
    
    auto test_method_(peru) {
      auto c = brown_colors::peru();
      
      assert::are_equal(brown_colors::peru(), c);
      assert::are_equal(color::from_known_color(known_color::peru), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xCD, c.r());
      assert::are_equal(0x85, c.g());
      assert::are_equal(0x3F, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("peru", c.name());
      
      assert::are_equal("color [peru]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFCD853F, c.to_argb());
      assert::are_equal(known_color::peru, c.to_known_color());
    }
    
    auto test_method_(rosy_brown) {
      auto c = brown_colors::rosy_brown();
      
      assert::are_equal(brown_colors::rosy_brown(), c);
      assert::are_equal(color::from_known_color(known_color::rosy_brown), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xBC, c.r());
      assert::are_equal(0x8F, c.g());
      assert::are_equal(0x8F, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("rosy_brown", c.name());
      
      assert::are_equal("color [rosy_brown]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFBC8F8F, c.to_argb());
      assert::are_equal(known_color::rosy_brown, c.to_known_color());
    }
    
    auto test_method_(goldenrod) {
      auto c = brown_colors::goldenrod();
      
      assert::are_equal(brown_colors::goldenrod(), c);
      assert::are_equal(color::from_known_color(known_color::goldenrod), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xDA, c.r());
      assert::are_equal(0xA5, c.g());
      assert::are_equal(0x20, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("goldenrod", c.name());
      
      assert::are_equal("color [goldenrod]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFDAA520, c.to_argb());
      assert::are_equal(known_color::goldenrod, c.to_known_color());
    }
    
    auto test_method_(sandy_brown) {
      auto c = brown_colors::sandy_brown();
      
      assert::are_equal(brown_colors::sandy_brown(), c);
      assert::are_equal(color::from_known_color(known_color::sandy_brown), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF4, c.r());
      assert::are_equal(0xA4, c.g());
      assert::are_equal(0x60, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("sandy_brown", c.name());
      
      assert::are_equal("color [sandy_brown]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF4A460, c.to_argb());
      assert::are_equal(known_color::sandy_brown, c.to_known_color());
    }
    
    auto test_method_(tan) {
      auto c = brown_colors::tan();
      
      assert::are_equal(brown_colors::tan(), c);
      assert::are_equal(color::from_known_color(known_color::tan), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xD2, c.r());
      assert::are_equal(0xB4, c.g());
      assert::are_equal(0x8C, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("tan", c.name());
      
      assert::are_equal("color [tan]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFD2B48C, c.to_argb());
      assert::are_equal(known_color::tan, c.to_known_color());
    }
    
    auto test_method_(burly_wood) {
      auto c = brown_colors::burly_wood();
      
      assert::are_equal(brown_colors::burly_wood(), c);
      assert::are_equal(color::from_known_color(known_color::burly_wood), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xDE, c.r());
      assert::are_equal(0xB8, c.g());
      assert::are_equal(0x87, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("burly_wood", c.name());
      
      assert::are_equal("color [burly_wood]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFDEB887, c.to_argb());
      assert::are_equal(known_color::burly_wood, c.to_known_color());
    }
    
    auto test_method_(wheat) {
      auto c = brown_colors::wheat();
      
      assert::are_equal(brown_colors::wheat(), c);
      assert::are_equal(color::from_known_color(known_color::wheat), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF5, c.r());
      assert::are_equal(0xDE, c.g());
      assert::are_equal(0xB3, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("wheat", c.name());
      
      assert::are_equal("color [wheat]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF5DEB3, c.to_argb());
      assert::are_equal(known_color::wheat, c.to_known_color());
    }
    
    auto test_method_(navajo_white) {
      auto c = brown_colors::navajo_white();
      
      assert::are_equal(brown_colors::navajo_white(), c);
      assert::are_equal(color::from_known_color(known_color::navajo_white), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xDE, c.g());
      assert::are_equal(0xAD, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("navajo_white", c.name());
      
      assert::are_equal("color [navajo_white]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFDEAD, c.to_argb());
      assert::are_equal(known_color::navajo_white, c.to_known_color());
    }
    
    auto test_method_(bisque) {
      auto c = brown_colors::bisque();
      
      assert::are_equal(brown_colors::bisque(), c);
      assert::are_equal(color::from_known_color(known_color::bisque), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xE4, c.g());
      assert::are_equal(0xC4, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("bisque", c.name());
      
      assert::are_equal("color [bisque]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFE4C4, c.to_argb());
      assert::are_equal(known_color::bisque, c.to_known_color());
    }
    
    auto test_method_(blanched_almond) {
      auto c = brown_colors::blanched_almond();
      
      assert::are_equal(brown_colors::blanched_almond(), c);
      assert::are_equal(color::from_known_color(known_color::blanched_almond), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xEB, c.g());
      assert::are_equal(0xCD, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("blanched_almond", c.name());
      
      assert::are_equal("color [blanched_almond]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFEBCD, c.to_argb());
      assert::are_equal(known_color::blanched_almond, c.to_known_color());
    }
    
    auto test_method_(cornsilk) {
      auto c = brown_colors::cornsilk();
      
      assert::are_equal(brown_colors::cornsilk(), c);
      assert::are_equal(color::from_known_color(known_color::cornsilk), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xF8, c.g());
      assert::are_equal(0xDC, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("cornsilk", c.name());
      
      assert::are_equal("color [cornsilk]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFF8DC, c.to_argb());
      assert::are_equal(known_color::cornsilk, c.to_known_color());
    }
  };
}
