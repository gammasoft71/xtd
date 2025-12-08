#include <xtd/drawing/blue_colors>
#include <xtd/argument_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(blue_colors_tests) {
    auto test_method_(midnight_blue) {
      auto c = blue_colors::midnight_blue();
      
      assert::are_equal(blue_colors::midnight_blue(), c);
      assert::are_equal(color::from_known_color(known_color::midnight_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x19, c.r());
      assert::are_equal(0x19, c.g());
      assert::are_equal(0x70, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("midnight_blue", c.name());
      
      assert::are_equal("color [midnight_blue]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF191970, c.to_argb());
      assert::are_equal(known_color::midnight_blue, c.to_known_color());
    }
    
    auto test_method_(navy) {
      auto c = blue_colors::navy();
      
      assert::are_equal(blue_colors::navy(), c);
      assert::are_equal(color::from_known_color(known_color::navy), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x80, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("navy", c.name());
      
      assert::are_equal("color [navy]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF000080, c.to_argb());
      assert::are_equal(known_color::navy, c.to_known_color());
    }
    
    auto test_method_(dark_blue) {
      auto c = blue_colors::dark_blue();
      
      assert::are_equal(blue_colors::dark_blue(), c);
      assert::are_equal(color::from_known_color(known_color::dark_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x8B, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_blue", c.name());
      
      assert::are_equal("color [dark_blue]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF00008B, c.to_argb());
      assert::are_equal(known_color::dark_blue, c.to_known_color());
    }
    
    auto test_method_(medium_blue) {
      auto c = blue_colors::medium_blue();
      
      assert::are_equal(blue_colors::medium_blue(), c);
      assert::are_equal(color::from_known_color(known_color::medium_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0xCD, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("medium_blue", c.name());
      
      assert::are_equal("color [medium_blue]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF0000CD, c.to_argb());
      assert::are_equal(known_color::medium_blue, c.to_known_color());
    }
    
    auto test_method_(blue) {
      auto c = blue_colors::blue();
      
      assert::are_equal(blue_colors::blue(), c);
      assert::are_equal(color::from_known_color(known_color::blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("blue", c.name());
      
      assert::are_equal("color [blue]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF0000FF, c.to_argb());
      assert::are_equal(known_color::blue, c.to_known_color());
    }
    
    auto test_method_(royal_blue) {
      auto c = blue_colors::royal_blue();
      
      assert::are_equal(blue_colors::royal_blue(), c);
      assert::are_equal(color::from_known_color(known_color::royal_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x41, c.r());
      assert::are_equal(0x69, c.g());
      assert::are_equal(0xE1, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("royal_blue", c.name());
      
      assert::are_equal("color [royal_blue]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF4169E1, c.to_argb());
      assert::are_equal(known_color::royal_blue, c.to_known_color());
    }
    
    auto test_method_(steel_blue) {
      auto c = blue_colors::steel_blue();
      
      assert::are_equal(blue_colors::steel_blue(), c);
      assert::are_equal(color::from_known_color(known_color::steel_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x46, c.r());
      assert::are_equal(0x82, c.g());
      assert::are_equal(0xB4, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("steel_blue", c.name());
      
      assert::are_equal("color [steel_blue]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF4682B4, c.to_argb());
      assert::are_equal(known_color::steel_blue, c.to_known_color());
    }
    
    auto test_method_(dodger_blue) {
      auto c = blue_colors::dodger_blue();
      
      assert::are_equal(blue_colors::dodger_blue(), c);
      assert::are_equal(color::from_known_color(known_color::dodger_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x1E, c.r());
      assert::are_equal(0x90, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dodger_blue", c.name());
      
      assert::are_equal("color [dodger_blue]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF1E90FF, c.to_argb());
      assert::are_equal(known_color::dodger_blue, c.to_known_color());
    }
    
    auto test_method_(deep_sky_blue) {
      auto c = blue_colors::deep_sky_blue();
      
      assert::are_equal(blue_colors::deep_sky_blue(), c);
      assert::are_equal(color::from_known_color(known_color::deep_sky_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0xBF, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("deep_sky_blue", c.name());
      
      assert::are_equal("color [deep_sky_blue]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF00BFFF, c.to_argb());
      assert::are_equal(known_color::deep_sky_blue, c.to_known_color());
    }
    
    auto test_method_(cornflower_blue) {
      auto c = blue_colors::cornflower_blue();
      
      assert::are_equal(blue_colors::cornflower_blue(), c);
      assert::are_equal(color::from_known_color(known_color::cornflower_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x64, c.r());
      assert::are_equal(0x95, c.g());
      assert::are_equal(0xED, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("cornflower_blue", c.name());
      
      assert::are_equal("color [cornflower_blue]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF6495ED, c.to_argb());
      assert::are_equal(known_color::cornflower_blue, c.to_known_color());
    }
    
    auto test_method_(sky_blue) {
      auto c = blue_colors::sky_blue();
      
      assert::are_equal(blue_colors::sky_blue(), c);
      assert::are_equal(color::from_known_color(known_color::sky_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x87, c.r());
      assert::are_equal(0xCE, c.g());
      assert::are_equal(0xEB, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("sky_blue", c.name());
      
      assert::are_equal("color [sky_blue]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF87CEEB, c.to_argb());
      assert::are_equal(known_color::sky_blue, c.to_known_color());
    }
    
    auto test_method_(light_sky_blue) {
      auto c = blue_colors::light_sky_blue();
      
      assert::are_equal(blue_colors::light_sky_blue(), c);
      assert::are_equal(color::from_known_color(known_color::light_sky_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x87, c.r());
      assert::are_equal(0xCE, c.g());
      assert::are_equal(0xFA, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_sky_blue", c.name());
      
      assert::are_equal("color [light_sky_blue]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF87CEFA, c.to_argb());
      assert::are_equal(known_color::light_sky_blue, c.to_known_color());
    }
    
    auto test_method_(light_steel_blue) {
      auto c = blue_colors::light_steel_blue();
      
      assert::are_equal(blue_colors::light_steel_blue(), c);
      assert::are_equal(color::from_known_color(known_color::light_steel_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xB0, c.r());
      assert::are_equal(0xC4, c.g());
      assert::are_equal(0xDE, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_steel_blue", c.name());
      
      assert::are_equal("color [light_steel_blue]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFB0C4DE, c.to_argb());
      assert::are_equal(known_color::light_steel_blue, c.to_known_color());
    }
    
    auto test_method_(light_blue) {
      auto c = blue_colors::light_blue();
      
      assert::are_equal(blue_colors::light_blue(), c);
      assert::are_equal(color::from_known_color(known_color::light_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xAD, c.r());
      assert::are_equal(0xD8, c.g());
      assert::are_equal(0xE6, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_blue", c.name());
      
      assert::are_equal("color [light_blue]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFADD8E6, c.to_argb());
      assert::are_equal(known_color::light_blue, c.to_known_color());
    }
    
    auto test_method_(powder_blue) {
      auto c = blue_colors::powder_blue();
      
      assert::are_equal(blue_colors::powder_blue(), c);
      assert::are_equal(color::from_known_color(known_color::powder_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xB0, c.r());
      assert::are_equal(0xE0, c.g());
      assert::are_equal(0xE6, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("powder_blue", c.name());
      
      assert::are_equal("color [powder_blue]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFB0E0E6, c.to_argb());
      assert::are_equal(known_color::powder_blue, c.to_known_color());
    }
  };
}
