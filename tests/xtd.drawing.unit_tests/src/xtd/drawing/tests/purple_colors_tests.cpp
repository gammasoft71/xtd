#include <xtd/drawing/purple_colors>
#include <xtd/argument_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(purple_colors_tests) {
    auto test_method_(indigo) {
      auto c = purple_colors::indigo();
      
      assert::are_equal(purple_colors::indigo(), c);
      assert::are_equal(color::from_known_color(known_color::indigo), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x4B, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x82, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("indigo", c.name());
      
      assert::are_equal("color [indigo]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF4B0082, c.to_argb());
      assert::are_equal(known_color::indigo, c.to_known_color());
    }
    
    auto test_method_(rebecca_purple) {
      auto c = purple_colors::rebecca_purple();
      
      assert::are_equal(purple_colors::rebecca_purple(), c);
      assert::are_equal(color::from_known_color(known_color::rebecca_purple), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x66, c.r());
      assert::are_equal(0x33, c.g());
      assert::are_equal(0x99, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("rebecca_purple", c.name());
      
      assert::are_equal("color [rebecca_purple]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF663399, c.to_argb());
      assert::are_equal(known_color::rebecca_purple, c.to_known_color());
    }
    
    auto test_method_(purple) {
      auto c = purple_colors::purple();
      
      assert::are_equal(purple_colors::purple(), c);
      assert::are_equal(color::from_known_color(known_color::purple), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x80, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x80, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("purple", c.name());
      
      assert::are_equal("color [purple]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF800080, c.to_argb());
      assert::are_equal(known_color::purple, c.to_known_color());
    }
    
    auto test_method_(dark_magenta) {
      auto c = purple_colors::dark_magenta();
      
      assert::are_equal(purple_colors::dark_magenta(), c);
      assert::are_equal(color::from_known_color(known_color::dark_magenta), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x8B, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x8B, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_magenta", c.name());
      
      assert::are_equal("color [dark_magenta]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF8B008B, c.to_argb());
      assert::are_equal(known_color::dark_magenta, c.to_known_color());
    }
    
    auto test_method_(dark_violet) {
      auto c = purple_colors::dark_violet();
      
      assert::are_equal(purple_colors::dark_violet(), c);
      assert::are_equal(color::from_known_color(known_color::dark_violet), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x94, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0xD3, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_violet", c.name());
      
      assert::are_equal("color [dark_violet]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF9400D3, c.to_argb());
      assert::are_equal(known_color::dark_violet, c.to_known_color());
    }
    
    auto test_method_(dark_slate_blue) {
      auto c = purple_colors::dark_slate_blue();
      
      assert::are_equal(purple_colors::dark_slate_blue(), c);
      assert::are_equal(color::from_known_color(known_color::dark_slate_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x48, c.r());
      assert::are_equal(0x3D, c.g());
      assert::are_equal(0x8B, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_slate_blue", c.name());
      
      assert::are_equal("color [dark_slate_blue]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF483D8B, c.to_argb());
      assert::are_equal(known_color::dark_slate_blue, c.to_known_color());
    }
    
    auto test_method_(blue_violet) {
      auto c = purple_colors::blue_violet();
      
      assert::are_equal(purple_colors::blue_violet(), c);
      assert::are_equal(color::from_known_color(known_color::blue_violet), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x8A, c.r());
      assert::are_equal(0x2B, c.g());
      assert::are_equal(0xE2, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("blue_violet", c.name());
      
      assert::are_equal("color [blue_violet]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF8A2BE2, c.to_argb());
      assert::are_equal(known_color::blue_violet, c.to_known_color());
    }
    
    auto test_method_(dark_orchid) {
      auto c = purple_colors::dark_orchid();
      
      assert::are_equal(purple_colors::dark_orchid(), c);
      assert::are_equal(color::from_known_color(known_color::dark_orchid), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x99, c.r());
      assert::are_equal(0x32, c.g());
      assert::are_equal(0xCC, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_orchid", c.name());
      
      assert::are_equal("color [dark_orchid]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF9932CC, c.to_argb());
      assert::are_equal(known_color::dark_orchid, c.to_known_color());
    }
    
    auto test_method_(fuchsia) {
      auto c = purple_colors::fuchsia();
      
      assert::are_equal(purple_colors::fuchsia(), c);
      assert::are_equal(color::from_known_color(known_color::fuchsia), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("fuchsia", c.name());
      
      assert::are_equal("color [fuchsia]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF00FF, c.to_argb());
      assert::are_equal(known_color::fuchsia, c.to_known_color());
    }
    
    auto test_method_(magenta) {
      auto c = purple_colors::magenta();
      
      assert::are_equal(purple_colors::magenta(), c);
      assert::are_equal(color::from_known_color(known_color::magenta), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("magenta", c.name());
      
      assert::are_equal("color [magenta]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF00FF, c.to_argb());
      assert::are_equal(known_color::magenta, c.to_known_color());
    }
    
    auto test_method_(slate_blue) {
      auto c = purple_colors::slate_blue();
      
      assert::are_equal(purple_colors::slate_blue(), c);
      assert::are_equal(color::from_known_color(known_color::slate_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x6A, c.r());
      assert::are_equal(0x5A, c.g());
      assert::are_equal(0xCD, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("slate_blue", c.name());
      
      assert::are_equal("color [slate_blue]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF6A5ACD, c.to_argb());
      assert::are_equal(known_color::slate_blue, c.to_known_color());
    }
    
    auto test_method_(medium_slate_blue) {
      auto c = purple_colors::medium_slate_blue();
      
      assert::are_equal(purple_colors::medium_slate_blue(), c);
      assert::are_equal(color::from_known_color(known_color::medium_slate_blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x7B, c.r());
      assert::are_equal(0x68, c.g());
      assert::are_equal(0xEE, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("medium_slate_blue", c.name());
      
      assert::are_equal("color [medium_slate_blue]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF7B68EE, c.to_argb());
      assert::are_equal(known_color::medium_slate_blue, c.to_known_color());
    }
    
    auto test_method_(medium_orchid) {
      auto c = purple_colors::medium_orchid();
      
      assert::are_equal(purple_colors::medium_orchid(), c);
      assert::are_equal(color::from_known_color(known_color::medium_orchid), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xBA, c.r());
      assert::are_equal(0x55, c.g());
      assert::are_equal(0xD3, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("medium_orchid", c.name());
      
      assert::are_equal("color [medium_orchid]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFBA55D3, c.to_argb());
      assert::are_equal(known_color::medium_orchid, c.to_known_color());
    }
    
    auto test_method_(medium_purple) {
      auto c = purple_colors::medium_purple();
      
      assert::are_equal(purple_colors::medium_purple(), c);
      assert::are_equal(color::from_known_color(known_color::medium_purple), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x93, c.r());
      assert::are_equal(0x70, c.g());
      assert::are_equal(0xDB, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("medium_purple", c.name());
      
      assert::are_equal("color [medium_purple]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF9370DB, c.to_argb());
      assert::are_equal(known_color::medium_purple, c.to_known_color());
    }
    
    auto test_method_(orchid) {
      auto c = purple_colors::orchid();
      
      assert::are_equal(purple_colors::orchid(), c);
      assert::are_equal(color::from_known_color(known_color::orchid), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xDA, c.r());
      assert::are_equal(0x70, c.g());
      assert::are_equal(0xD6, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("orchid", c.name());
      
      assert::are_equal("color [orchid]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFDA70D6, c.to_argb());
      assert::are_equal(known_color::orchid, c.to_known_color());
    }
    
    auto test_method_(violet) {
      auto c = purple_colors::violet();
      
      assert::are_equal(purple_colors::violet(), c);
      assert::are_equal(color::from_known_color(known_color::violet), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xEE, c.r());
      assert::are_equal(0x82, c.g());
      assert::are_equal(0xEE, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("violet", c.name());
      
      assert::are_equal("color [violet]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFEE82EE, c.to_argb());
      assert::are_equal(known_color::violet, c.to_known_color());
    }
    
    auto test_method_(plum) {
      auto c = purple_colors::plum();
      
      assert::are_equal(purple_colors::plum(), c);
      assert::are_equal(color::from_known_color(known_color::plum), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xDD, c.r());
      assert::are_equal(0xA0, c.g());
      assert::are_equal(0xDD, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("plum", c.name());
      
      assert::are_equal("color [plum]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFDDA0DD, c.to_argb());
      assert::are_equal(known_color::plum, c.to_known_color());
    }
    
    auto test_method_(thistle) {
      auto c = purple_colors::thistle();
      
      assert::are_equal(purple_colors::thistle(), c);
      assert::are_equal(color::from_known_color(known_color::thistle), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xD8, c.r());
      assert::are_equal(0xBF, c.g());
      assert::are_equal(0xD8, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("thistle", c.name());
      
      assert::are_equal("color [thistle]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFD8BFD8, c.to_argb());
      assert::are_equal(known_color::thistle, c.to_known_color());
    }
    
    auto test_method_(lavender) {
      auto c = purple_colors::lavender();
      
      assert::are_equal(purple_colors::lavender(), c);
      assert::are_equal(color::from_known_color(known_color::lavender), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xE6, c.r());
      assert::are_equal(0xE6, c.g());
      assert::are_equal(0xFA, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("lavender", c.name());
      
      assert::are_equal("color [lavender]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFE6E6FA, c.to_argb());
      assert::are_equal(known_color::lavender, c.to_known_color());
    }
  };
}
