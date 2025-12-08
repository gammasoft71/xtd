#include <xtd/drawing/gray_colors>
#include <xtd/argument_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(gray_colors_tests) {
    auto test_method_(black) {
      auto c = gray_colors::black();
      
      assert::are_equal(gray_colors::black(), c);
      assert::are_equal(color::from_known_color(known_color::black), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("black", c.name());
      
      assert::are_equal("color [black]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF000000, c.to_argb());
      assert::are_equal(known_color::black, c.to_known_color());
    }
    
    auto test_method_(dark_slate_gray) {
      auto c = gray_colors::dark_slate_gray();
      
      assert::are_equal(gray_colors::dark_slate_gray(), c);
      assert::are_equal(color::from_known_color(known_color::dark_slate_gray), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x2F, c.r());
      assert::are_equal(0x4F, c.g());
      assert::are_equal(0x4F, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_slate_gray", c.name());
      
      assert::are_equal("color [dark_slate_gray]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF2F4F4F, c.to_argb());
      assert::are_equal(known_color::dark_slate_gray, c.to_known_color());
    }
    
    auto test_method_(dim_gray) {
      auto c = gray_colors::dim_gray();
      
      assert::are_equal(gray_colors::dim_gray(), c);
      assert::are_equal(color::from_known_color(known_color::dim_gray), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x69, c.r());
      assert::are_equal(0x69, c.g());
      assert::are_equal(0x69, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dim_gray", c.name());
      
      assert::are_equal("color [dim_gray]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF696969, c.to_argb());
      assert::are_equal(known_color::dim_gray, c.to_known_color());
    }
    
    auto test_method_(slate_gray) {
      auto c = gray_colors::slate_gray();
      
      assert::are_equal(gray_colors::slate_gray(), c);
      assert::are_equal(color::from_known_color(known_color::slate_gray), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x70, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x90, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("slate_gray", c.name());
      
      assert::are_equal("color [slate_gray]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF708090, c.to_argb());
      assert::are_equal(known_color::slate_gray, c.to_known_color());
    }
    
    auto test_method_(gray) {
      auto c = gray_colors::gray();
      
      assert::are_equal(gray_colors::gray(), c);
      assert::are_equal(color::from_known_color(known_color::gray), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x80, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x80, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("gray", c.name());
      
      assert::are_equal("color [gray]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF808080, c.to_argb());
      assert::are_equal(known_color::gray, c.to_known_color());
    }
    
    auto test_method_(light_slate_gray) {
      auto c = gray_colors::light_slate_gray();
      
      assert::are_equal(gray_colors::light_slate_gray(), c);
      assert::are_equal(color::from_known_color(known_color::light_slate_gray), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x77, c.r());
      assert::are_equal(0x88, c.g());
      assert::are_equal(0x99, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_slate_gray", c.name());
      
      assert::are_equal("color [light_slate_gray]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF778899, c.to_argb());
      assert::are_equal(known_color::light_slate_gray, c.to_known_color());
    }
    
    auto test_method_(dark_gray) {
      auto c = gray_colors::dark_gray();
      
      assert::are_equal(gray_colors::dark_gray(), c);
      assert::are_equal(color::from_known_color(known_color::dark_gray), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xA9, c.r());
      assert::are_equal(0xA9, c.g());
      assert::are_equal(0xA9, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_gray", c.name());
      
      assert::are_equal("color [dark_gray]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFA9A9A9, c.to_argb());
      assert::are_equal(known_color::dark_gray, c.to_known_color());
    }
    
    auto test_method_(silver) {
      auto c = gray_colors::silver();
      
      assert::are_equal(gray_colors::silver(), c);
      assert::are_equal(color::from_known_color(known_color::silver), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xC0, c.r());
      assert::are_equal(0xC0, c.g());
      assert::are_equal(0xC0, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("silver", c.name());
      
      assert::are_equal("color [silver]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFC0C0C0, c.to_argb());
      assert::are_equal(known_color::silver, c.to_known_color());
    }
    
    auto test_method_(light_gray) {
      auto c = gray_colors::light_gray();
      
      assert::are_equal(gray_colors::light_gray(), c);
      assert::are_equal(color::from_known_color(known_color::light_gray), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xD3, c.r());
      assert::are_equal(0xD3, c.g());
      assert::are_equal(0xD3, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_gray", c.name());
      
      assert::are_equal("color [light_gray]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFD3D3D3, c.to_argb());
      assert::are_equal(known_color::light_gray, c.to_known_color());
    }
    
    auto test_method_(gainsboro) {
      auto c = gray_colors::gainsboro();
      
      assert::are_equal(gray_colors::gainsboro(), c);
      assert::are_equal(color::from_known_color(known_color::gainsboro), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xDC, c.r());
      assert::are_equal(0xDC, c.g());
      assert::are_equal(0xDC, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("gainsboro", c.name());
      
      assert::are_equal("color [gainsboro]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFDCDCDC, c.to_argb());
      assert::are_equal(known_color::gainsboro, c.to_known_color());
    }
  };
}
