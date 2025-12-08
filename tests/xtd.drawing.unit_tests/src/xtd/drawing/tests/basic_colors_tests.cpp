#include <xtd/drawing/basic_colors>
#include <xtd/argument_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(basic_colors_tests) {
    auto test_method_(white) {
      auto c = basic_colors::white();
      
      assert::are_equal(basic_colors::white(), c);
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
    
    auto test_method_(silver) {
      auto c = basic_colors::silver();
      
      assert::are_equal(basic_colors::silver(), c);
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
    
    auto test_method_(gray) {
      auto c = basic_colors::gray();
      
      assert::are_equal(basic_colors::gray(), c);
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
    
    auto test_method_(black) {
      auto c = basic_colors::black();
      
      assert::are_equal(basic_colors::black(), c);
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
    
    auto test_method_(red) {
      auto c = basic_colors::red();
      
      assert::are_equal(basic_colors::red(), c);
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
    
    auto test_method_(maroon) {
      auto c = basic_colors::maroon();
      
      assert::are_equal(basic_colors::maroon(), c);
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
    
    auto test_method_(yellow) {
      auto c = basic_colors::yellow();
      
      assert::are_equal(basic_colors::yellow(), c);
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
    
    auto test_method_(olive) {
      auto c = basic_colors::olive();
      
      assert::are_equal(basic_colors::olive(), c);
      assert::are_equal(color::from_known_color(known_color::olive), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x80, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("olive", c.name());
      
      assert::are_equal("color [olive]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF808000, c.to_argb());
      assert::are_equal(known_color::olive, c.to_known_color());
    }
    
    auto test_method_(lime) {
      auto c = basic_colors::lime();
      
      assert::are_equal(basic_colors::lime(), c);
      assert::are_equal(color::from_known_color(known_color::lime), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("lime", c.name());
      
      assert::are_equal("color [lime]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF00FF00, c.to_argb());
      assert::are_equal(known_color::lime, c.to_known_color());
    }
    
    auto test_method_(green) {
      auto c = basic_colors::green();
      
      assert::are_equal(basic_colors::green(), c);
      assert::are_equal(color::from_known_color(known_color::green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("green", c.name());
      
      assert::are_equal("color [green]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF008000, c.to_argb());
      assert::are_equal(known_color::green, c.to_known_color());
    }
    
    auto test_method_(aqua) {
      auto c = basic_colors::aqua();
      
      assert::are_equal(basic_colors::aqua(), c);
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
    
    auto test_method_(teal) {
      auto c = basic_colors::teal();
      
      assert::are_equal(basic_colors::teal(), c);
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
    
    auto test_method_(blue) {
      auto c = basic_colors::blue();
      
      assert::are_equal(basic_colors::blue(), c);
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
    
    auto test_method_(navy) {
      auto c = basic_colors::navy();
      
      assert::are_equal(basic_colors::navy(), c);
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
    
    auto test_method_(fuchsia) {
      auto c = basic_colors::fuchsia();
      
      assert::are_equal(basic_colors::fuchsia(), c);
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
    
    auto test_method_(purple) {
      auto c = basic_colors::purple();
      
      assert::are_equal(basic_colors::purple(), c);
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
  };
}
