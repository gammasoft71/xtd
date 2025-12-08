#include <xtd/drawing/green_colors>
#include <xtd/argument_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(green_colors_tests) {
    auto test_method_(dark_green) {
      auto c = green_colors::dark_green();
      
      assert::are_equal(green_colors::dark_green(), c);
      assert::are_equal(color::from_known_color(known_color::dark_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x64, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_green", c.name());
      
      assert::are_equal("color [dark_green]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF006400, c.to_argb());
      assert::are_equal(known_color::dark_green, c.to_known_color());
    }
    
    auto test_method_(green) {
      auto c = green_colors::green();
      
      assert::are_equal(green_colors::green(), c);
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
    
    auto test_method_(dark_olive_green) {
      auto c = green_colors::dark_olive_green();
      
      assert::are_equal(green_colors::dark_olive_green(), c);
      assert::are_equal(color::from_known_color(known_color::dark_olive_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x55, c.r());
      assert::are_equal(0x6B, c.g());
      assert::are_equal(0x2F, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_olive_green", c.name());
      
      assert::are_equal("color [dark_olive_green]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF556B2F, c.to_argb());
      assert::are_equal(known_color::dark_olive_green, c.to_known_color());
    }
    
    auto test_method_(forest_green) {
      auto c = green_colors::forest_green();
      
      assert::are_equal(green_colors::forest_green(), c);
      assert::are_equal(color::from_known_color(known_color::forest_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x22, c.r());
      assert::are_equal(0x8B, c.g());
      assert::are_equal(0x22, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("forest_green", c.name());
      
      assert::are_equal("color [forest_green]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF228B22, c.to_argb());
      assert::are_equal(known_color::forest_green, c.to_known_color());
    }
    
    auto test_method_(sea_green) {
      auto c = green_colors::sea_green();
      
      assert::are_equal(green_colors::sea_green(), c);
      assert::are_equal(color::from_known_color(known_color::sea_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x2E, c.r());
      assert::are_equal(0x8B, c.g());
      assert::are_equal(0x57, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("sea_green", c.name());
      
      assert::are_equal("color [sea_green]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF2E8B57, c.to_argb());
      assert::are_equal(known_color::sea_green, c.to_known_color());
    }
    
    auto test_method_(olive) {
      auto c = green_colors::olive();
      
      assert::are_equal(green_colors::olive(), c);
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
    
    auto test_method_(olive_drab) {
      auto c = green_colors::olive_drab();
      
      assert::are_equal(green_colors::olive_drab(), c);
      assert::are_equal(color::from_known_color(known_color::olive_drab), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x6B, c.r());
      assert::are_equal(0x8E, c.g());
      assert::are_equal(0x23, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("olive_drab", c.name());
      
      assert::are_equal("color [olive_drab]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF6B8E23, c.to_argb());
      assert::are_equal(known_color::olive_drab, c.to_known_color());
    }
    
    auto test_method_(medium_sea_green) {
      auto c = green_colors::medium_sea_green();
      
      assert::are_equal(green_colors::medium_sea_green(), c);
      assert::are_equal(color::from_known_color(known_color::medium_sea_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x3C, c.r());
      assert::are_equal(0xB3, c.g());
      assert::are_equal(0x71, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("medium_sea_green", c.name());
      
      assert::are_equal("color [medium_sea_green]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF3CB371, c.to_argb());
      assert::are_equal(known_color::medium_sea_green, c.to_known_color());
    }
    
    auto test_method_(lime_green) {
      auto c = green_colors::lime_green();
      
      assert::are_equal(green_colors::lime_green(), c);
      assert::are_equal(color::from_known_color(known_color::lime_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x32, c.r());
      assert::are_equal(0xCD, c.g());
      assert::are_equal(0x32, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("lime_green", c.name());
      
      assert::are_equal("color [lime_green]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF32CD32, c.to_argb());
      assert::are_equal(known_color::lime_green, c.to_known_color());
    }
    
    auto test_method_(lime) {
      auto c = green_colors::lime();
      
      assert::are_equal(green_colors::lime(), c);
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
    
    auto test_method_(spring_green) {
      auto c = green_colors::spring_green();
      
      assert::are_equal(green_colors::spring_green(), c);
      assert::are_equal(color::from_known_color(known_color::spring_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0x7F, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("spring_green", c.name());
      
      assert::are_equal("color [spring_green]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF00FF7F, c.to_argb());
      assert::are_equal(known_color::spring_green, c.to_known_color());
    }
    
    auto test_method_(medium_spring_green) {
      auto c = green_colors::medium_spring_green();
      
      assert::are_equal(green_colors::medium_spring_green(), c);
      assert::are_equal(color::from_known_color(known_color::medium_spring_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0xFA, c.g());
      assert::are_equal(0x9A, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("medium_spring_green", c.name());
      
      assert::are_equal("color [medium_spring_green]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF00FA9A, c.to_argb());
      assert::are_equal(known_color::medium_spring_green, c.to_known_color());
    }
    
    auto test_method_(dark_sea_green) {
      auto c = green_colors::dark_sea_green();
      
      assert::are_equal(green_colors::dark_sea_green(), c);
      assert::are_equal(color::from_known_color(known_color::dark_sea_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x8F, c.r());
      assert::are_equal(0xBC, c.g());
      assert::are_equal(0x8B, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_sea_green", c.name());
      
      assert::are_equal("color [dark_sea_green]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF8FBC8B, c.to_argb());
      assert::are_equal(known_color::dark_sea_green, c.to_known_color());
    }
    
    auto test_method_(medium_aquamarine) {
      auto c = green_colors::medium_aquamarine();
      
      assert::are_equal(green_colors::medium_aquamarine(), c);
      assert::are_equal(color::from_known_color(known_color::medium_aquamarine), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x66, c.r());
      assert::are_equal(0xCD, c.g());
      assert::are_equal(0xAA, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("medium_aquamarine", c.name());
      
      assert::are_equal("color [medium_aquamarine]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF66CDAA, c.to_argb());
      assert::are_equal(known_color::medium_aquamarine, c.to_known_color());
    }
    
    auto test_method_(yellow_green) {
      auto c = green_colors::yellow_green();
      
      assert::are_equal(green_colors::yellow_green(), c);
      assert::are_equal(color::from_known_color(known_color::yellow_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x9A, c.r());
      assert::are_equal(0xCD, c.g());
      assert::are_equal(0x32, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("yellow_green", c.name());
      
      assert::are_equal("color [yellow_green]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF9ACD32, c.to_argb());
      assert::are_equal(known_color::yellow_green, c.to_known_color());
    }
    
    auto test_method_(lawn_green) {
      auto c = green_colors::lawn_green();
      
      assert::are_equal(green_colors::lawn_green(), c);
      assert::are_equal(color::from_known_color(known_color::lawn_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x7C, c.r());
      assert::are_equal(0xFC, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("lawn_green", c.name());
      
      assert::are_equal("color [lawn_green]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF7CFC00, c.to_argb());
      assert::are_equal(known_color::lawn_green, c.to_known_color());
    }
    
    auto test_method_(chartreuse) {
      auto c = green_colors::chartreuse();
      
      assert::are_equal(green_colors::chartreuse(), c);
      assert::are_equal(color::from_known_color(known_color::chartreuse), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x7F, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("chartreuse", c.name());
      
      assert::are_equal("color [chartreuse]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF7FFF00, c.to_argb());
      assert::are_equal(known_color::chartreuse, c.to_known_color());
    }
    
    auto test_method_(light_green) {
      auto c = green_colors::light_green();
      
      assert::are_equal(green_colors::light_green(), c);
      assert::are_equal(color::from_known_color(known_color::light_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x90, c.r());
      assert::are_equal(0xEE, c.g());
      assert::are_equal(0x90, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_green", c.name());
      
      assert::are_equal("color [light_green]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF90EE90, c.to_argb());
      assert::are_equal(known_color::light_green, c.to_known_color());
    }
    
    auto test_method_(green_yellow) {
      auto c = green_colors::green_yellow();
      
      assert::are_equal(green_colors::green_yellow(), c);
      assert::are_equal(color::from_known_color(known_color::green_yellow), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xAD, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0x2F, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("green_yellow", c.name());
      
      assert::are_equal("color [green_yellow]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFADFF2F, c.to_argb());
      assert::are_equal(known_color::green_yellow, c.to_known_color());
    }
    
    auto test_method_(pale_green) {
      auto c = green_colors::pale_green();
      
      assert::are_equal(green_colors::pale_green(), c);
      assert::are_equal(color::from_known_color(known_color::pale_green), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x98, c.r());
      assert::are_equal(0xFB, c.g());
      assert::are_equal(0x98, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("pale_green", c.name());
      
      assert::are_equal("color [pale_green]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF98FB98, c.to_argb());
      assert::are_equal(known_color::pale_green, c.to_known_color());
    }
  };
}
