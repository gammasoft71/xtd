#include <xtd/drawing/crayon_colors>
#include <xtd/argument_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(crayon_colors_tests) {
    auto test_method_(licorice) {
      auto c = crayon_colors::licorice();
      
      assert::are_equal(crayon_colors::licorice(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_licorice), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_licorice", c.name());
      
      assert::are_equal("color [crayon_licorice]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF000000, c.to_argb());
      assert::are_equal(known_color::crayon_licorice, c.to_known_color());
    }
    
    auto test_method_(lead) {
      auto c = crayon_colors::lead();
      
      assert::are_equal(crayon_colors::lead(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_lead), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x19, c.r());
      assert::are_equal(0x19, c.g());
      assert::are_equal(0x19, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_lead", c.name());
      
      assert::are_equal("color [crayon_lead]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF191919, c.to_argb());
      assert::are_equal(known_color::crayon_lead, c.to_known_color());
    }
    
    auto test_method_(tungsten) {
      auto c = crayon_colors::tungsten();
      
      assert::are_equal(crayon_colors::tungsten(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_tungsten), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x33, c.r());
      assert::are_equal(0x33, c.g());
      assert::are_equal(0x33, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_tungsten", c.name());
      
      assert::are_equal("color [crayon_tungsten]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF333333, c.to_argb());
      assert::are_equal(known_color::crayon_tungsten, c.to_known_color());
    }
    
    auto test_method_(iron) {
      auto c = crayon_colors::iron();
      
      assert::are_equal(crayon_colors::iron(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_iron), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x4C, c.r());
      assert::are_equal(0x4C, c.g());
      assert::are_equal(0x4C, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_iron", c.name());
      
      assert::are_equal("color [crayon_iron]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF4C4C4C, c.to_argb());
      assert::are_equal(known_color::crayon_iron, c.to_known_color());
    }
    
    auto test_method_(steel) {
      auto c = crayon_colors::steel();
      
      assert::are_equal(crayon_colors::steel(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_steel), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x66, c.r());
      assert::are_equal(0x66, c.g());
      assert::are_equal(0x66, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_steel", c.name());
      
      assert::are_equal("color [crayon_steel]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF666666, c.to_argb());
      assert::are_equal(known_color::crayon_steel, c.to_known_color());
    }
    
    auto test_method_(tin) {
      auto c = crayon_colors::tin();
      
      assert::are_equal(crayon_colors::tin(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_tin), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x7F, c.r());
      assert::are_equal(0x7F, c.g());
      assert::are_equal(0x7F, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_tin", c.name());
      
      assert::are_equal("color [crayon_tin]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF7F7F7F, c.to_argb());
      assert::are_equal(known_color::crayon_tin, c.to_known_color());
    }
    
    auto test_method_(nickel) {
      auto c = crayon_colors::nickel();
      
      assert::are_equal(crayon_colors::nickel(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_nickel), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x80, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x80, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_nickel", c.name());
      
      assert::are_equal("color [crayon_nickel]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF808080, c.to_argb());
      assert::are_equal(known_color::crayon_nickel, c.to_known_color());
    }
    
    auto test_method_(aluminium) {
      auto c = crayon_colors::aluminium();
      
      assert::are_equal(crayon_colors::aluminium(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_aluminium), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x99, c.r());
      assert::are_equal(0x99, c.g());
      assert::are_equal(0x99, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_aluminium", c.name());
      
      assert::are_equal("color [crayon_aluminium]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF999999, c.to_argb());
      assert::are_equal(known_color::crayon_aluminium, c.to_known_color());
    }
    
    auto test_method_(magnesium) {
      auto c = crayon_colors::magnesium();
      
      assert::are_equal(crayon_colors::magnesium(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_magnesium), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xB3, c.r());
      assert::are_equal(0xB3, c.g());
      assert::are_equal(0xB3, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_magnesium", c.name());
      
      assert::are_equal("color [crayon_magnesium]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFB3B3B3, c.to_argb());
      assert::are_equal(known_color::crayon_magnesium, c.to_known_color());
    }
    
    auto test_method_(silver) {
      auto c = crayon_colors::silver();
      
      assert::are_equal(crayon_colors::silver(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_silver), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xCC, c.r());
      assert::are_equal(0xCC, c.g());
      assert::are_equal(0xCC, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_silver", c.name());
      
      assert::are_equal("color [crayon_silver]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFCCCCCC, c.to_argb());
      assert::are_equal(known_color::crayon_silver, c.to_known_color());
    }
    
    auto test_method_(mercury) {
      auto c = crayon_colors::mercury();
      
      assert::are_equal(crayon_colors::mercury(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_mercury), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xE6, c.r());
      assert::are_equal(0xE6, c.g());
      assert::are_equal(0xE6, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_mercury", c.name());
      
      assert::are_equal("color [crayon_mercury]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFE6E6E6, c.to_argb());
      assert::are_equal(known_color::crayon_mercury, c.to_known_color());
    }
    
    auto test_method_(snow) {
      auto c = crayon_colors::snow();
      
      assert::are_equal(crayon_colors::snow(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_snow), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_snow", c.name());
      
      assert::are_equal("color [crayon_snow]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFFFFF, c.to_argb());
      assert::are_equal(known_color::crayon_snow, c.to_known_color());
    }
    
    auto test_method_(cayenne) {
      auto c = crayon_colors::cayenne();
      
      assert::are_equal(crayon_colors::cayenne(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_cayenne), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x80, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x02, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_cayenne", c.name());
      
      assert::are_equal("color [crayon_cayenne]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF800002, c.to_argb());
      assert::are_equal(known_color::crayon_cayenne, c.to_known_color());
    }
    
    auto test_method_(mocha) {
      auto c = crayon_colors::mocha();
      
      assert::are_equal(crayon_colors::mocha(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_mocha), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x80, c.r());
      assert::are_equal(0x40, c.g());
      assert::are_equal(0x03, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_mocha", c.name());
      
      assert::are_equal("color [crayon_mocha]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF804003, c.to_argb());
      assert::are_equal(known_color::crayon_mocha, c.to_known_color());
    }
    
    auto test_method_(asparagus) {
      auto c = crayon_colors::asparagus();
      
      assert::are_equal(crayon_colors::asparagus(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_asparagus), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x80, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x04, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_asparagus", c.name());
      
      assert::are_equal("color [crayon_asparagus]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF808004, c.to_argb());
      assert::are_equal(known_color::crayon_asparagus, c.to_known_color());
    }
    
    auto test_method_(fern) {
      auto c = crayon_colors::fern();
      
      assert::are_equal(crayon_colors::fern(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_fern), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x40, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x02, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_fern", c.name());
      
      assert::are_equal("color [crayon_fern]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF408002, c.to_argb());
      assert::are_equal(known_color::crayon_fern, c.to_known_color());
    }
    
    auto test_method_(clover) {
      auto c = crayon_colors::clover();
      
      assert::are_equal(crayon_colors::clover(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_clover), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x11, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x02, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_clover", c.name());
      
      assert::are_equal("color [crayon_clover]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF118002, c.to_argb());
      assert::are_equal(known_color::crayon_clover, c.to_known_color());
    }
    
    auto test_method_(moss) {
      auto c = crayon_colors::moss();
      
      assert::are_equal(crayon_colors::moss(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_moss), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x11, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x40, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_moss", c.name());
      
      assert::are_equal("color [crayon_moss]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF118040, c.to_argb());
      assert::are_equal(known_color::crayon_moss, c.to_known_color());
    }
    
    auto test_method_(teal) {
      auto c = crayon_colors::teal();
      
      assert::are_equal(crayon_colors::teal(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_teal), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x10, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x80, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_teal", c.name());
      
      assert::are_equal("color [crayon_teal]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF108080, c.to_argb());
      assert::are_equal(known_color::crayon_teal, c.to_known_color());
    }
    
    auto test_method_(ocean) {
      auto c = crayon_colors::ocean();
      
      assert::are_equal(crayon_colors::ocean(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_ocean), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x07, c.r());
      assert::are_equal(0x40, c.g());
      assert::are_equal(0x80, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_ocean", c.name());
      
      assert::are_equal("color [crayon_ocean]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF074080, c.to_argb());
      assert::are_equal(known_color::crayon_ocean, c.to_known_color());
    }
    
    auto test_method_(midnight) {
      auto c = crayon_colors::midnight();
      
      assert::are_equal(crayon_colors::midnight(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_midnight), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x80, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_midnight", c.name());
      
      assert::are_equal("color [crayon_midnight]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF000080, c.to_argb());
      assert::are_equal(known_color::crayon_midnight, c.to_known_color());
    }
    
    auto test_method_(eggplant) {
      auto c = crayon_colors::eggplant();
      
      assert::are_equal(crayon_colors::eggplant(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_eggplant), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x40, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x80, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_eggplant", c.name());
      
      assert::are_equal("color [crayon_eggplant]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF400080, c.to_argb());
      assert::are_equal(known_color::crayon_eggplant, c.to_known_color());
    }
    
    auto test_method_(plum) {
      auto c = crayon_colors::plum();
      
      assert::are_equal(crayon_colors::plum(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_plum), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x80, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x80, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_plum", c.name());
      
      assert::are_equal("color [crayon_plum]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF800080, c.to_argb());
      assert::are_equal(known_color::crayon_plum, c.to_known_color());
    }
    
    auto test_method_(maroon) {
      auto c = crayon_colors::maroon();
      
      assert::are_equal(crayon_colors::maroon(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_maroon), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x80, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x40, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_maroon", c.name());
      
      assert::are_equal("color [crayon_maroon]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF800040, c.to_argb());
      assert::are_equal(known_color::crayon_maroon, c.to_known_color());
    }
    
    auto test_method_(maraschino) {
      auto c = crayon_colors::maraschino();
      
      assert::are_equal(crayon_colors::maraschino(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_maraschino), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFB, c.r());
      assert::are_equal(0x02, c.g());
      assert::are_equal(0x07, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_maraschino", c.name());
      
      assert::are_equal("color [crayon_maraschino]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFB0207, c.to_argb());
      assert::are_equal(known_color::crayon_maraschino, c.to_known_color());
    }
    
    auto test_method_(tangerine) {
      auto c = crayon_colors::tangerine();
      
      assert::are_equal(crayon_colors::tangerine(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_tangerine), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFD, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x08, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_tangerine", c.name());
      
      assert::are_equal("color [crayon_tangerine]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFD8008, c.to_argb());
      assert::are_equal(known_color::crayon_tangerine, c.to_known_color());
    }
    
    auto test_method_(lemon) {
      auto c = crayon_colors::lemon();
      
      assert::are_equal(crayon_colors::lemon(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_lemon), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0x0A, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_lemon", c.name());
      
      assert::are_equal("color [crayon_lemon]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFFF0A, c.to_argb());
      assert::are_equal(known_color::crayon_lemon, c.to_known_color());
    }
    
    auto test_method_(lime) {
      auto c = crayon_colors::lime();
      
      assert::are_equal(crayon_colors::lime(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_lime), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x80, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0x08, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_lime", c.name());
      
      assert::are_equal("color [crayon_lime]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF80FF08, c.to_argb());
      assert::are_equal(known_color::crayon_lime, c.to_known_color());
    }
    
    auto test_method_(spring) {
      auto c = crayon_colors::spring();
      
      assert::are_equal(crayon_colors::spring(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_spring), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x21, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0x06, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_spring", c.name());
      
      assert::are_equal("color [crayon_spring]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF21FF06, c.to_argb());
      assert::are_equal(known_color::crayon_spring, c.to_known_color());
    }
    
    auto test_method_(sea_foam) {
      auto c = crayon_colors::sea_foam();
      
      assert::are_equal(crayon_colors::sea_foam(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_sea_foam), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x21, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0x80, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_sea_foam", c.name());
      
      assert::are_equal("color [crayon_sea_foam]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF21FF80, c.to_argb());
      assert::are_equal(known_color::crayon_sea_foam, c.to_known_color());
    }
    
    auto test_method_(turquoise) {
      auto c = crayon_colors::turquoise();
      
      assert::are_equal(crayon_colors::turquoise(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_turquoise), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x21, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_turquoise", c.name());
      
      assert::are_equal("color [crayon_turquoise]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF21FFFF, c.to_argb());
      assert::are_equal(known_color::crayon_turquoise, c.to_known_color());
    }
    
    auto test_method_(aqua) {
      auto c = crayon_colors::aqua();
      
      assert::are_equal(crayon_colors::aqua(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_aqua), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x0F, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_aqua", c.name());
      
      assert::are_equal("color [crayon_aqua]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF0F80FF, c.to_argb());
      assert::are_equal(known_color::crayon_aqua, c.to_known_color());
    }
    
    auto test_method_(blueberry) {
      auto c = crayon_colors::blueberry();
      
      assert::are_equal(crayon_colors::blueberry(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_blueberry), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_blueberry", c.name());
      
      assert::are_equal("color [crayon_blueberry]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF0000FF, c.to_argb());
      assert::are_equal(known_color::crayon_blueberry, c.to_known_color());
    }
    
    auto test_method_(grape) {
      auto c = crayon_colors::grape();
      
      assert::are_equal(crayon_colors::grape(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_grape), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x80, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_grape", c.name());
      
      assert::are_equal("color [crayon_grape]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF8000FF, c.to_argb());
      assert::are_equal(known_color::crayon_grape, c.to_known_color());
    }
    
    auto test_method_(magenta) {
      auto c = crayon_colors::magenta();
      
      assert::are_equal(crayon_colors::magenta(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_magenta), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFB, c.r());
      assert::are_equal(0x02, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_magenta", c.name());
      
      assert::are_equal("color [crayon_magenta]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFB02FF, c.to_argb());
      assert::are_equal(known_color::crayon_magenta, c.to_known_color());
    }
    
    auto test_method_(strawberry) {
      auto c = crayon_colors::strawberry();
      
      assert::are_equal(crayon_colors::strawberry(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_strawberry), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFB, c.r());
      assert::are_equal(0x02, c.g());
      assert::are_equal(0x80, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_strawberry", c.name());
      
      assert::are_equal("color [crayon_strawberry]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFB0280, c.to_argb());
      assert::are_equal(known_color::crayon_strawberry, c.to_known_color());
    }
    
    auto test_method_(salmon) {
      auto c = crayon_colors::salmon();
      
      assert::are_equal(crayon_colors::salmon(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_salmon), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFC, c.r());
      assert::are_equal(0x66, c.g());
      assert::are_equal(0x66, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_salmon", c.name());
      
      assert::are_equal("color [crayon_salmon]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFC6666, c.to_argb());
      assert::are_equal(known_color::crayon_salmon, c.to_known_color());
    }
    
    auto test_method_(cantaloupe) {
      auto c = crayon_colors::cantaloupe();
      
      assert::are_equal(crayon_colors::cantaloupe(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_cantaloupe), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFE, c.r());
      assert::are_equal(0xCC, c.g());
      assert::are_equal(0x66, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_cantaloupe", c.name());
      
      assert::are_equal("color [crayon_cantaloupe]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFECC66, c.to_argb());
      assert::are_equal(known_color::crayon_cantaloupe, c.to_known_color());
    }
    
    auto test_method_(banana) {
      auto c = crayon_colors::banana();
      
      assert::are_equal(crayon_colors::banana(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_banana), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0x66, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_banana", c.name());
      
      assert::are_equal("color [crayon_banana]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFFF66, c.to_argb());
      assert::are_equal(known_color::crayon_banana, c.to_known_color());
    }
    
    auto test_method_(honeydew) {
      auto c = crayon_colors::honeydew();
      
      assert::are_equal(crayon_colors::honeydew(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_honeydew), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xCC, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0x66, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_honeydew", c.name());
      
      assert::are_equal("color [crayon_honeydew]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFCCFF66, c.to_argb());
      assert::are_equal(known_color::crayon_honeydew, c.to_known_color());
    }
    
    auto test_method_(flora) {
      auto c = crayon_colors::flora();
      
      assert::are_equal(crayon_colors::flora(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_flora), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x66, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0x66, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_flora", c.name());
      
      assert::are_equal("color [crayon_flora]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF66FF66, c.to_argb());
      assert::are_equal(known_color::crayon_flora, c.to_known_color());
    }
    
    auto test_method_(spindrift) {
      auto c = crayon_colors::spindrift();
      
      assert::are_equal(crayon_colors::spindrift(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_spindrift), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x66, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xCC, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_spindrift", c.name());
      
      assert::are_equal("color [crayon_spindrift]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF66FFCC, c.to_argb());
      assert::are_equal(known_color::crayon_spindrift, c.to_known_color());
    }
    
    auto test_method_(ice) {
      auto c = crayon_colors::ice();
      
      assert::are_equal(crayon_colors::ice(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_ice), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x66, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_ice", c.name());
      
      assert::are_equal("color [crayon_ice]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF66FFFF, c.to_argb());
      assert::are_equal(known_color::crayon_ice, c.to_known_color());
    }
    
    auto test_method_(sky) {
      auto c = crayon_colors::sky();
      
      assert::are_equal(crayon_colors::sky(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_sky), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x66, c.r());
      assert::are_equal(0xCC, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_sky", c.name());
      
      assert::are_equal("color [crayon_sky]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF66CCFF, c.to_argb());
      assert::are_equal(known_color::crayon_sky, c.to_known_color());
    }
    
    auto test_method_(orchid) {
      auto c = crayon_colors::orchid();
      
      assert::are_equal(crayon_colors::orchid(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_orchid), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x66, c.r());
      assert::are_equal(0x66, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_orchid", c.name());
      
      assert::are_equal("color [crayon_orchid]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF6666FF, c.to_argb());
      assert::are_equal(known_color::crayon_orchid, c.to_known_color());
    }
    
    auto test_method_(lavendar) {
      auto c = crayon_colors::lavendar();
      
      assert::are_equal(crayon_colors::lavendar(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_lavendar), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xCC, c.r());
      assert::are_equal(0x66, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_lavendar", c.name());
      
      assert::are_equal("color [crayon_lavendar]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFCC66FF, c.to_argb());
      assert::are_equal(known_color::crayon_lavendar, c.to_known_color());
    }
    
    auto test_method_(bubblegum) {
      auto c = crayon_colors::bubblegum();
      
      assert::are_equal(crayon_colors::bubblegum(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_bubblegum), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFC, c.r());
      assert::are_equal(0x66, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_bubblegum", c.name());
      
      assert::are_equal("color [crayon_bubblegum]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFC66FF, c.to_argb());
      assert::are_equal(known_color::crayon_bubblegum, c.to_known_color());
    }
    
    auto test_method_(carnation) {
      auto c = crayon_colors::carnation();
      
      assert::are_equal(crayon_colors::carnation(), c);
      assert::are_equal(color::from_known_color(known_color::crayon_carnation), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFC, c.r());
      assert::are_equal(0x6F, c.g());
      assert::are_equal(0xCF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crayon_carnation", c.name());
      
      assert::are_equal("color [crayon_carnation]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFC6FCF, c.to_argb());
      assert::are_equal(known_color::crayon_carnation, c.to_known_color());
    }
  };
}
