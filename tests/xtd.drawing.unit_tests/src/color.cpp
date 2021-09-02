#include <xtd/drawing/color.h>
#include <xtd/argument_exception.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_color) {
  public:
    void test_method_(create_empty_color) {
      color c;
      
      assert::are_equal(color(), c);
      assert::are_equal(color::empty, c);
      
      assert::are_equal(0, c.a());
      assert::are_equal(0, c.r());
      assert::are_equal(0, c.g());
      assert::are_equal(0, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("0", c.name());
      
      assert::are_equal("color [empty]", c.to_string());

      assert::is_true(c.is_empty());
      assert::is_false(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_false(c.is_named_color());

      assert::are_equal(0U, c.to_argb());
      assert::are_equal((known_color)0, c.to_known_color());
    }

    void test_method_(create_from_argb_0) {
      color c = color::from_argb(0);
      
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0, c.a());
      assert::are_equal(0, c.r());
      assert::are_equal(0, c.g());
      assert::are_equal(0, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("0", c.name());

      assert::are_equal("color [a=0, r=0, g=0, b=0]", c.to_string());

      assert::is_false(c.is_empty());
      assert::is_false(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_false(c.is_named_color());
      
      assert::are_equal(0U, c.to_argb());
      assert::are_equal((known_color)0, c.to_known_color());
    }

    void test_method_(create_from_argb_0x12_0x34_0x56_0x78) {
      color c = color::from_argb(0x12, 0x34, 0x56, 0x78);
      
      assert::are_equal(color::from_argb(0x12345678), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0x12, c.a());
      assert::are_equal(0x34, c.r());
      assert::are_equal(0x56, c.g());
      assert::are_equal(0x78, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("12345678", c.name());
      
      assert::are_equal("color [a=18, r=52, g=86, b=120]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_false(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_false(c.is_named_color());
      
      assert::are_equal(0x12345678U, c.to_argb());
      assert::are_equal((known_color)0, c.to_known_color());
    }

    void test_method_(create_from_argb_0x12_0x34_0x56) {
      color c = color::from_argb(0x12, 0x34, 0x56);
      
      assert::are_equal(color::from_argb(0xFF123456), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x12, c.r());
      assert::are_equal(0x34, c.g());
      assert::are_equal(0x56, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("FF123456", c.name());
      
      assert::are_equal("color [a=255, r=18, g=52, b=86]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_false(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_false(c.is_named_color());
      
      assert::are_equal(0xFF123456U, c.to_argb());
      assert::are_equal((known_color)0, c.to_known_color());
    }

    void test_method_(create_from_argb_0x20_color_blue) {
      color c = color::from_argb(0x20, color::blue);
      
      assert::are_equal(color::from_argb(0x20, color::blue), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0x20, c.a());
      assert::are_equal(0x0, c.r());
      assert::are_equal(0x0, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("200000FF", c.name());
      
      assert::are_equal("color [a=32, r=0, g=0, b=255]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_false(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_false(c.is_named_color());
      
      assert::are_equal(0x200000FFU, c.to_argb());
      assert::are_equal((known_color)0, c.to_known_color());
    }

    void test_method_(create_from_argb_0x12345678) {
      color c = color::from_argb(0x12345678);
      
      assert::are_equal(color::from_argb(0x12345678), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0x12, c.a());
      assert::are_equal(0x34, c.r());
      assert::are_equal(0x56, c.g());
      assert::are_equal(0x78, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("12345678", c.name());
      
      assert::are_equal("color [a=18, r=52, g=86, b=120]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_false(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_false(c.is_named_color());
      
      assert::are_equal(0x12345678U, c.to_argb());
      assert::are_equal((known_color)0, c.to_known_color());
    }
    
    void test_method_(create_from_hsb_240_1_1) {
      color c = color::from_hsb(240, 1.0f, 1.0f);

      assert::are_equal(color::from_hsb(240, 1.0f, 1.0f), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x00, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("FF0000FF", c.name());
      
      assert::are_equal(240, c.get_hue());
      assert::are_equal(1.0f, c.get_saturation());
      assert::are_equal(1.0f, c.get_brightness());

      assert::are_equal("color [a=255, r=0, g=0, b=255]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_false(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_false(c.is_named_color());
      
      assert::are_equal(0xFF0000FFU, c.to_argb());
      assert::are_equal((known_color)0, c.to_known_color());
    }
    
    void test_method_(create_from_hsl_138_050_076) {
      color c = color::from_hsl(138, 0.50f, 0.76f);
      
      assert::are_equal(color::from_hsl(138, 0.50f, 0.76f), c, csf_);
      assert::are_not_equal(color(), c, csf_);
      assert::are_not_equal(color::empty, c, csf_);
      
      assert::are_equal(0xFF, c.a(), csf_);
      assert::are_equal(0xA3, c.r(), csf_);
      assert::are_equal(0xE0, c.g(), csf_);
      assert::are_equal(0xB5, c.b(), csf_);
      assert::are_equal(0, c.handle(), csf_);
      assert::are_equal("FFA3E0B5", c.name(), csf_);
      
      assert::are_equal(138.0f, c.get_hue(), 0.5f, csf_);
      assert::are_equal(0.50f, c.get_saturation(), 0.005f, csf_);
      assert::are_equal(0.76f, c.get_lightness(), 0.005f, csf_);
      
      assert::are_equal("color [a=255, r=163, g=224, b=181]", c.to_string(), csf_);
      
      assert::is_false(c.is_empty(), csf_);
      assert::is_false(c.is_known_color(), csf_);
      assert::is_false(c.is_system_color(), csf_);
      assert::is_false(c.is_named_color(), csf_);
      
      assert::are_equal(0xFFA3E0B5, c.to_argb(), csf_);
      assert::are_equal((known_color)0, c.to_known_color(), csf_);
    }
    
    void test_method_(create_from_know_color_invalid) {
      assert::throws<argument_exception>([] {color::from_known_color((known_color)7654);});
    }

    void test_method_(create_from_know_color_transparent) {
      color c = color::from_known_color(known_color::transparent);
      
      assert::are_equal(color::from_known_color(known_color::transparent), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0x00, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("transparent", c.name());
      
      assert::are_equal("color [transparent]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0x00FFFFFFU, c.to_argb());
      assert::are_equal(known_color::transparent, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_alice_blue) {
      color c = color::from_known_color(known_color::alice_blue);
      
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
      
      assert::are_equal(0xFFF0F8FFU, c.to_argb());
      assert::are_equal(known_color::alice_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_antique_white) {
      color c = color::from_known_color(known_color::antique_white);
      
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
      
      assert::are_equal(0xFFFAEBD7U, c.to_argb());
      assert::are_equal(known_color::antique_white, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_aqua) {
      color c = color::from_known_color(known_color::aqua);
      
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
      
      assert::are_equal(0xFF00FFFFU, c.to_argb());
      assert::are_equal(known_color::aqua, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_aquamarine) {
      color c = color::from_known_color(known_color::aquamarine);
      
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
      
      assert::are_equal(0xFF7FFFD4U, c.to_argb());
      assert::are_equal(known_color::aquamarine, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_azure) {
      color c = color::from_known_color(known_color::azure);
      
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
      
      assert::are_equal(0xFFF0FFFFU, c.to_argb());
      assert::are_equal(known_color::azure, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_beige) {
      color c = color::from_known_color(known_color::beige);
      
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
      
      assert::are_equal(0xFFF5F5DCU, c.to_argb());
      assert::are_equal(known_color::beige, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_bisque) {
      color c = color::from_known_color(known_color::bisque);
      
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
      
      assert::are_equal(0xFFFFE4C4U, c.to_argb());
      assert::are_equal(known_color::bisque, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_black) {
      color c = color::from_known_color(known_color::black);
      
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
      
      assert::are_equal(0xFF000000U, c.to_argb());
      assert::are_equal(known_color::black, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_blanched_almond) {
      color c = color::from_known_color(known_color::blanched_almond);
      
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
      
      assert::are_equal(0xFFFFEBCDU, c.to_argb());
      assert::are_equal(known_color::blanched_almond, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_blue) {
      color c = color::from_known_color(known_color::blue);
      
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
      
      assert::are_equal(0xFF0000FFU, c.to_argb());
      assert::are_equal(known_color::blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_blue_violet) {
      color c = color::from_known_color(known_color::blue_violet);
      
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
      
      assert::are_equal(0xFF8A2BE2U, c.to_argb());
      assert::are_equal(known_color::blue_violet, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_brown) {
      color c = color::from_known_color(known_color::brown);
      
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
      
      assert::are_equal(0xFFA52A2AU, c.to_argb());
      assert::are_equal(known_color::brown, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_burly_wood) {
      color c = color::from_known_color(known_color::burly_wood);
      
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
      
      assert::are_equal(0xFFDEB887U, c.to_argb());
      assert::are_equal(known_color::burly_wood, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_cadet_blue) {
      color c = color::from_known_color(known_color::cadet_blue);
      
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
      
      assert::are_equal(0xFF5F9EA0U, c.to_argb());
      assert::are_equal(known_color::cadet_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_chartreuse) {
      color c = color::from_known_color(known_color::chartreuse);
      
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
      
      assert::are_equal(0xFF7FFF00U, c.to_argb());
      assert::are_equal(known_color::chartreuse, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_chocolate) {
      color c = color::from_known_color(known_color::chocolate);
      
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
      
      assert::are_equal(0xFFD2691EU, c.to_argb());
      assert::are_equal(known_color::chocolate, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_coral) {
      color c = color::from_known_color(known_color::coral);
      
      assert::are_equal(color::from_known_color(known_color::coral), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x7F, c.g());
      assert::are_equal(0x50, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("coral", c.name());
      
      assert::are_equal("color [coral]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF7F50U, c.to_argb());
      assert::are_equal(known_color::coral, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_cornflower_blue) {
      color c = color::from_known_color(known_color::cornflower_blue);
      
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
      
      assert::are_equal(0xFF6495EDU, c.to_argb());
      assert::are_equal(known_color::cornflower_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_cornsilk) {
      color c = color::from_known_color(known_color::cornsilk);
      
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
      
      assert::are_equal(0xFFFFF8DCU, c.to_argb());
      assert::are_equal(known_color::cornsilk, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_crimson) {
      color c = color::from_known_color(known_color::crimson);
      
      assert::are_equal(color::from_known_color(known_color::crimson), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xDC, c.r());
      assert::are_equal(0x14, c.g());
      assert::are_equal(0x3C, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crimson", c.name());
      
      assert::are_equal("color [crimson]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFDC143CU, c.to_argb());
      assert::are_equal(known_color::crimson, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_cyan) {
      color c = color::from_known_color(known_color::cyan);
      
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
      
      assert::are_equal(0xFF00FFFFU, c.to_argb());
      assert::are_equal(known_color::cyan, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_blue) {
      color c = color::from_known_color(known_color::dark_blue);
      
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
      
      assert::are_equal(0xFF00008BU, c.to_argb());
      assert::are_equal(known_color::dark_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_cyan) {
      color c = color::from_known_color(known_color::dark_cyan);
      
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
      
      assert::are_equal(0xFF008B8BU, c.to_argb());
      assert::are_equal(known_color::dark_cyan, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_goldenrod) {
      color c = color::from_known_color(known_color::dark_goldenrod);
      
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
      
      assert::are_equal(0xFFB8860BU, c.to_argb());
      assert::are_equal(known_color::dark_goldenrod, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_gray) {
      color c = color::from_known_color(known_color::dark_gray);
      
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
      
      assert::are_equal(0xFFA9A9A9U, c.to_argb());
      assert::are_equal(known_color::dark_gray, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_green) {
      color c = color::from_known_color(known_color::dark_green);
      
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
      
      assert::are_equal(0xFF006400U, c.to_argb());
      assert::are_equal(known_color::dark_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_khaki) {
      color c = color::from_known_color(known_color::dark_khaki);
      
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
      
      assert::are_equal(0xFFBDB76BU, c.to_argb());
      assert::are_equal(known_color::dark_khaki, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_magenta) {
      color c = color::from_known_color(known_color::dark_magenta);
      
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
      
      assert::are_equal(0xFF8B008BU, c.to_argb());
      assert::are_equal(known_color::dark_magenta, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_olive_green) {
      color c = color::from_known_color(known_color::dark_olive_green);
      
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
      
      assert::are_equal(0xFF556B2FU, c.to_argb());
      assert::are_equal(known_color::dark_olive_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_orange) {
      color c = color::from_known_color(known_color::dark_orange);
      
      assert::are_equal(color::from_known_color(known_color::dark_orange), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x8C, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_orange", c.name());
      
      assert::are_equal("color [dark_orange]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF8C00U, c.to_argb());
      assert::are_equal(known_color::dark_orange, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_orchid) {
      color c = color::from_known_color(known_color::dark_orchid);
      
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
      
      assert::are_equal(0xFF9932CCU, c.to_argb());
      assert::are_equal(known_color::dark_orchid, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_red) {
      color c = color::from_known_color(known_color::dark_red);
      
      assert::are_equal(color::from_known_color(known_color::dark_red), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x8B, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_red", c.name());
      
      assert::are_equal("color [dark_red]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF8B0000U, c.to_argb());
      assert::are_equal(known_color::dark_red, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_salmon) {
      color c = color::from_known_color(known_color::dark_salmon);
      
      assert::are_equal(color::from_known_color(known_color::dark_salmon), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xE9, c.r());
      assert::are_equal(0x96, c.g());
      assert::are_equal(0x7A, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_salmon", c.name());
      
      assert::are_equal("color [dark_salmon]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFE9967AU, c.to_argb());
      assert::are_equal(known_color::dark_salmon, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_sea_green) {
      color c = color::from_known_color(known_color::dark_sea_green);
      
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
      
      assert::are_equal(0xFF8FBC8BU, c.to_argb());
      assert::are_equal(known_color::dark_sea_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_slate_blue) {
      color c = color::from_known_color(known_color::dark_slate_blue);
      
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
      
      assert::are_equal(0xFF483D8BU, c.to_argb());
      assert::are_equal(known_color::dark_slate_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_slate_gray) {
      color c = color::from_known_color(known_color::dark_slate_gray);
      
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
      
      assert::are_equal(0xFF2F4F4FU, c.to_argb());
      assert::are_equal(known_color::dark_slate_gray, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_turquoise) {
      color c = color::from_known_color(known_color::dark_turquoise);
      
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
      
      assert::are_equal(0xFF00CED1U, c.to_argb());
      assert::are_equal(known_color::dark_turquoise, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dark_violet) {
      color c = color::from_known_color(known_color::dark_violet);
      
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
      
      assert::are_equal(0xFF9400D3U, c.to_argb());
      assert::are_equal(known_color::dark_violet, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_deep_pink) {
      color c = color::from_known_color(known_color::deep_pink);
      
      assert::are_equal(color::from_known_color(known_color::deep_pink), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x14, c.g());
      assert::are_equal(0x93, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("deep_pink", c.name());
      
      assert::are_equal("color [deep_pink]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF1493U, c.to_argb());
      assert::are_equal(known_color::deep_pink, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_deep_sky_blue) {
      color c = color::from_known_color(known_color::deep_sky_blue);
      
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
      
      assert::are_equal(0xFF00BFFFU, c.to_argb());
      assert::are_equal(known_color::deep_sky_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dim_gray) {
      color c = color::from_known_color(known_color::dim_gray);
      
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
      
      assert::are_equal(0xFF696969U, c.to_argb());
      assert::are_equal(known_color::dim_gray, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_dodger_blue) {
      color c = color::from_known_color(known_color::dodger_blue);
      
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
      
      assert::are_equal(0xFF1E90FFU, c.to_argb());
      assert::are_equal(known_color::dodger_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_firebrick) {
      color c = color::from_known_color(known_color::firebrick);
      
      assert::are_equal(color::from_known_color(known_color::firebrick), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xB2, c.r());
      assert::are_equal(0x22, c.g());
      assert::are_equal(0x22, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("firebrick", c.name());
      
      assert::are_equal("color [firebrick]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFB22222U, c.to_argb());
      assert::are_equal(known_color::firebrick, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_floral_white) {
      color c = color::from_known_color(known_color::floral_white);
      
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
      
      assert::are_equal(0xFFFFFAF0U, c.to_argb());
      assert::are_equal(known_color::floral_white, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_forest_green) {
      color c = color::from_known_color(known_color::forest_green);
      
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
      
      assert::are_equal(0xFF228B22U, c.to_argb());
      assert::are_equal(known_color::forest_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_fuchsia) {
      color c = color::from_known_color(known_color::fuchsia);
      
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
      
      assert::are_equal(0xFFFF00FFU, c.to_argb());
      assert::are_equal(known_color::fuchsia, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_gainsboro) {
      color c = color::from_known_color(known_color::gainsboro);
      
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
      
      assert::are_equal(0xFFDCDCDCU, c.to_argb());
      assert::are_equal(known_color::gainsboro, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_ghost_white) {
      color c = color::from_known_color(known_color::ghost_white);
      
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
      
      assert::are_equal(0xFFF8F8FFU, c.to_argb());
      assert::are_equal(known_color::ghost_white, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_gold) {
      color c = color::from_known_color(known_color::gold);
      
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
      
      assert::are_equal(0xFFFFD700U, c.to_argb());
      assert::are_equal(known_color::gold, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_goldenrod) {
      color c = color::from_known_color(known_color::goldenrod);
      
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
      
      assert::are_equal(0xFFDAA520U, c.to_argb());
      assert::are_equal(known_color::goldenrod, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_gray) {
      color c = color::from_known_color(known_color::gray);
      
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
      
      assert::are_equal(0xFF808080U, c.to_argb());
      assert::are_equal(known_color::gray, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_green) {
      color c = color::from_known_color(known_color::green);
      
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
      
      assert::are_equal(0xFF008000U, c.to_argb());
      assert::are_equal(known_color::green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_green_yellow) {
      color c = color::from_known_color(known_color::green_yellow);
      
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
      
      assert::are_equal(0xFFADFF2FU, c.to_argb());
      assert::are_equal(known_color::green_yellow, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_honeydew) {
      color c = color::from_known_color(known_color::honeydew);
      
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
      
      assert::are_equal(0xFFF0FFF0U, c.to_argb());
      assert::are_equal(known_color::honeydew, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_hot_pink) {
      color c = color::from_known_color(known_color::hot_pink);
      
      assert::are_equal(color::from_known_color(known_color::hot_pink), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x69, c.g());
      assert::are_equal(0xB4, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("hot_pink", c.name());
      
      assert::are_equal("color [hot_pink]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF69B4U, c.to_argb());
      assert::are_equal(known_color::hot_pink, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_indian_red) {
      color c = color::from_known_color(known_color::indian_red);
      
      assert::are_equal(color::from_known_color(known_color::indian_red), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xCD, c.r());
      assert::are_equal(0x5C, c.g());
      assert::are_equal(0x5C, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("indian_red", c.name());
      
      assert::are_equal("color [indian_red]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFCD5C5CU, c.to_argb());
      assert::are_equal(known_color::indian_red, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_indigo) {
      color c = color::from_known_color(known_color::indigo);
      
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
      
      assert::are_equal(0xFF4B0082U, c.to_argb());
      assert::are_equal(known_color::indigo, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_ivory) {
      color c = color::from_known_color(known_color::ivory);
      
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
      
      assert::are_equal(0xFFFFFFF0U, c.to_argb());
      assert::are_equal(known_color::ivory, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_khaki) {
      color c = color::from_known_color(known_color::khaki);
      
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
      
      assert::are_equal(0xFFF0E68CU, c.to_argb());
      assert::are_equal(known_color::khaki, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_lavender) {
      color c = color::from_known_color(known_color::lavender);
      
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
      
      assert::are_equal(0xFFE6E6FAU, c.to_argb());
      assert::are_equal(known_color::lavender, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_lavender_blush) {
      color c = color::from_known_color(known_color::lavender_blush);
      
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
      
      assert::are_equal(0xFFFFF0F5U, c.to_argb());
      assert::are_equal(known_color::lavender_blush, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_lawn_green) {
      color c = color::from_known_color(known_color::lawn_green);
      
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
      
      assert::are_equal(0xFF7CFC00U, c.to_argb());
      assert::are_equal(known_color::lawn_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_lemon_chiffon) {
      color c = color::from_known_color(known_color::lemon_chiffon);
      
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
      
      assert::are_equal(0xFFFFFACDU, c.to_argb());
      assert::are_equal(known_color::lemon_chiffon, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_blue) {
      color c = color::from_known_color(known_color::light_blue);
      
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
      
      assert::are_equal(0xFFADD8E6U, c.to_argb());
      assert::are_equal(known_color::light_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_coral) {
      color c = color::from_known_color(known_color::light_coral);
      
      assert::are_equal(color::from_known_color(known_color::light_coral), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF0, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x80, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_coral", c.name());
      
      assert::are_equal("color [light_coral]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF08080U, c.to_argb());
      assert::are_equal(known_color::light_coral, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_cyan) {
      color c = color::from_known_color(known_color::light_cyan);
      
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
      
      assert::are_equal(0xFFE0FFFFU, c.to_argb());
      assert::are_equal(known_color::light_cyan, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_goldenrod_yellow) {
      color c = color::from_known_color(known_color::light_goldenrod_yellow);
      
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
      
      assert::are_equal(0xFFFAFAD2U, c.to_argb());
      assert::are_equal(known_color::light_goldenrod_yellow, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_gray) {
      color c = color::from_known_color(known_color::light_gray);
      
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
      
      assert::are_equal(0xFFD3D3D3U, c.to_argb());
      assert::are_equal(known_color::light_gray, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_green) {
      color c = color::from_known_color(known_color::light_green);
      
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
      
      assert::are_equal(0xFF90EE90U, c.to_argb());
      assert::are_equal(known_color::light_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_pink) {
      color c = color::from_known_color(known_color::light_pink);
      
      assert::are_equal(color::from_known_color(known_color::light_pink), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xB6, c.g());
      assert::are_equal(0xC1, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_pink", c.name());
      
      assert::are_equal("color [light_pink]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFB6C1U, c.to_argb());
      assert::are_equal(known_color::light_pink, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_salmon) {
      color c = color::from_known_color(known_color::light_salmon);
      
      assert::are_equal(color::from_known_color(known_color::light_salmon), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xA0, c.g());
      assert::are_equal(0x7A, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_salmon", c.name());
      
      assert::are_equal("color [light_salmon]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFA07AU, c.to_argb());
      assert::are_equal(known_color::light_salmon, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_sea_green) {
      color c = color::from_known_color(known_color::light_sea_green);
      
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
      
      assert::are_equal(0xFF20B2AAU, c.to_argb());
      assert::are_equal(known_color::light_sea_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_sky_blue) {
      color c = color::from_known_color(known_color::light_sky_blue);
      
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
      
      assert::are_equal(0xFF87CEFAU, c.to_argb());
      assert::are_equal(known_color::light_sky_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_slate_gray) {
      color c = color::from_known_color(known_color::light_slate_gray);
      
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
      
      assert::are_equal(0xFF778899U, c.to_argb());
      assert::are_equal(known_color::light_slate_gray, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_steel_blue) {
      color c = color::from_known_color(known_color::light_steel_blue);
      
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
      
      assert::are_equal(0xFFB0C4DEU, c.to_argb());
      assert::are_equal(known_color::light_steel_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_light_yellow) {
      color c = color::from_known_color(known_color::light_yellow);
      
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
      
      assert::are_equal(0xFFFFFFE0U, c.to_argb());
      assert::are_equal(known_color::light_yellow, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_lime) {
      color c = color::from_known_color(known_color::lime);
      
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
      
      assert::are_equal(0xFF00FF00U, c.to_argb());
      assert::are_equal(known_color::lime, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_lime_green) {
      color c = color::from_known_color(known_color::lime_green);
      
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
      
      assert::are_equal(0xFF32CD32U, c.to_argb());
      assert::are_equal(known_color::lime_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_linen) {
      color c = color::from_known_color(known_color::linen);
      
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
      
      assert::are_equal(0xFFFAF0E6U, c.to_argb());
      assert::are_equal(known_color::linen, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_magenta) {
      color c = color::from_known_color(known_color::magenta);
      
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
      
      assert::are_equal(0xFFFF00FFU, c.to_argb());
      assert::are_equal(known_color::magenta, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_maroon) {
      color c = color::from_known_color(known_color::maroon);
      
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
      
      assert::are_equal(0xFF800000U, c.to_argb());
      assert::are_equal(known_color::maroon, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_medium_aquamarine) {
      color c = color::from_known_color(known_color::medium_aquamarine);
      
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
      
      assert::are_equal(0xFF66CDAAU, c.to_argb());
      assert::are_equal(known_color::medium_aquamarine, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_medium_blue) {
      color c = color::from_known_color(known_color::medium_blue);
      
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
      
      assert::are_equal(0xFF0000CDU, c.to_argb());
      assert::are_equal(known_color::medium_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_medium_orchid) {
      color c = color::from_known_color(known_color::medium_orchid);
      
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
      
      assert::are_equal(0xFFBA55D3U, c.to_argb());
      assert::are_equal(known_color::medium_orchid, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_medium_purple) {
      color c = color::from_known_color(known_color::medium_purple);
      
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
      
      assert::are_equal(0xFF9370DBU, c.to_argb());
      assert::are_equal(known_color::medium_purple, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_medium_sea_green) {
      color c = color::from_known_color(known_color::medium_sea_green);
      
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
      
      assert::are_equal(0xFF3CB371U, c.to_argb());
      assert::are_equal(known_color::medium_sea_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_medium_slate_blue) {
      color c = color::from_known_color(known_color::medium_slate_blue);
      
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
      
      assert::are_equal(0xFF7B68EEU, c.to_argb());
      assert::are_equal(known_color::medium_slate_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_medium_spring_green) {
      color c = color::from_known_color(known_color::medium_spring_green);
      
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
      
      assert::are_equal(0xFF00FA9AU, c.to_argb());
      assert::are_equal(known_color::medium_spring_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_medium_turquoise) {
      color c = color::from_known_color(known_color::medium_turquoise);
      
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
      
      assert::are_equal(0xFF48D1CCU, c.to_argb());
      assert::are_equal(known_color::medium_turquoise, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_medium_violet_red) {
      color c = color::from_known_color(known_color::medium_violet_red);
      
      assert::are_equal(color::from_known_color(known_color::medium_violet_red), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xC7, c.r());
      assert::are_equal(0x15, c.g());
      assert::are_equal(0x85, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("medium_violet_red", c.name());
      
      assert::are_equal("color [medium_violet_red]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFC71585U, c.to_argb());
      assert::are_equal(known_color::medium_violet_red, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_midnight_blue) {
      color c = color::from_known_color(known_color::midnight_blue);
      
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
      
      assert::are_equal(0xFF191970U, c.to_argb());
      assert::are_equal(known_color::midnight_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_mint_cream) {
      color c = color::from_known_color(known_color::mint_cream);
      
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
      
      assert::are_equal(0xFFF5FFFAU, c.to_argb());
      assert::are_equal(known_color::mint_cream, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_misty_rose) {
      color c = color::from_known_color(known_color::misty_rose);
      
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
      
      assert::are_equal(0xFFFFE4E1U, c.to_argb());
      assert::are_equal(known_color::misty_rose, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_moccasin) {
      color c = color::from_known_color(known_color::moccasin);
      
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
      
      assert::are_equal(0xFFFFE4B5U, c.to_argb());
      assert::are_equal(known_color::moccasin, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_navajo_white) {
      color c = color::from_known_color(known_color::navajo_white);
      
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
      
      assert::are_equal(0xFFFFDEADU, c.to_argb());
      assert::are_equal(known_color::navajo_white, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_navy) {
      color c = color::from_known_color(known_color::navy);
      
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
      
      assert::are_equal(0xFF000080U, c.to_argb());
      assert::are_equal(known_color::navy, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_old_lace) {
      color c = color::from_known_color(known_color::old_lace);
      
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
      
      assert::are_equal(0xFFFDF5E6U, c.to_argb());
      assert::are_equal(known_color::old_lace, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_olive) {
      color c = color::from_known_color(known_color::olive);
      
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
      
      assert::are_equal(0xFF808000U, c.to_argb());
      assert::are_equal(known_color::olive, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_olive_drab) {
      color c = color::from_known_color(known_color::olive_drab);
      
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
      
      assert::are_equal(0xFF6B8E23U, c.to_argb());
      assert::are_equal(known_color::olive_drab, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_orange) {
      color c = color::from_known_color(known_color::orange);
      
      assert::are_equal(color::from_known_color(known_color::orange), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xA5, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("orange", c.name());
      
      assert::are_equal("color [orange]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFA500U, c.to_argb());
      assert::are_equal(known_color::orange, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_orange_red) {
      color c = color::from_known_color(known_color::orange_red);
      
      assert::are_equal(color::from_known_color(known_color::orange_red), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x45, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("orange_red", c.name());
      
      assert::are_equal("color [orange_red]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF4500U, c.to_argb());
      assert::are_equal(known_color::orange_red, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_orchid) {
      color c = color::from_known_color(known_color::orchid);
      
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
      
      assert::are_equal(0xFFDA70D6U, c.to_argb());
      assert::are_equal(known_color::orchid, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_pale_goldenrod) {
      color c = color::from_known_color(known_color::pale_goldenrod);
      
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
      
      assert::are_equal(0xFFEEE8AAU, c.to_argb());
      assert::are_equal(known_color::pale_goldenrod, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_pale_green) {
      color c = color::from_known_color(known_color::pale_green);
      
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
      
      assert::are_equal(0xFF98FB98U, c.to_argb());
      assert::are_equal(known_color::pale_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_pale_turquoise) {
      color c = color::from_known_color(known_color::pale_turquoise);
      
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
      
      assert::are_equal(0xFFAFEEEEU, c.to_argb());
      assert::are_equal(known_color::pale_turquoise, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_pale_violet_red) {
      color c = color::from_known_color(known_color::pale_violet_red);
      
      assert::are_equal(color::from_known_color(known_color::pale_violet_red), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xDB, c.r());
      assert::are_equal(0x70, c.g());
      assert::are_equal(0x93, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("pale_violet_red", c.name());
      
      assert::are_equal("color [pale_violet_red]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFDB7093U, c.to_argb());
      assert::are_equal(known_color::pale_violet_red, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_papaya_whip) {
      color c = color::from_known_color(known_color::papaya_whip);
      
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
      
      assert::are_equal(0xFFFFEFD5U, c.to_argb());
      assert::are_equal(known_color::papaya_whip, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_peach_puff) {
      color c = color::from_known_color(known_color::peach_puff);
      
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
      
      assert::are_equal(0xFFFFDAB9U, c.to_argb());
      assert::are_equal(known_color::peach_puff, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_peru) {
      color c = color::from_known_color(known_color::peru);
      
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
      
      assert::are_equal(0xFFCD853FU, c.to_argb());
      assert::are_equal(known_color::peru, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_pink) {
      color c = color::from_known_color(known_color::pink);
      
      assert::are_equal(color::from_known_color(known_color::pink), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xC0, c.g());
      assert::are_equal(0xCB, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("pink", c.name());
      
      assert::are_equal("color [pink]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFC0CBU, c.to_argb());
      assert::are_equal(known_color::pink, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_plum) {
      color c = color::from_known_color(known_color::plum);
      
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
      
      assert::are_equal(0xFFDDA0DDU, c.to_argb());
      assert::are_equal(known_color::plum, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_powder_blue) {
      color c = color::from_known_color(known_color::powder_blue);
      
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
      
      assert::are_equal(0xFFB0E0E6U, c.to_argb());
      assert::are_equal(known_color::powder_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_purple) {
      color c = color::from_known_color(known_color::purple);
      
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
      
      assert::are_equal(0xFF800080U, c.to_argb());
      assert::are_equal(known_color::purple, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_rebecca_purple) {
      color c = color::from_known_color(known_color::rebecca_purple);
      
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
      
      assert::are_equal(0xFF663399U, c.to_argb());
      assert::are_equal(known_color::rebecca_purple, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_red) {
      color c = color::from_known_color(known_color::red);
      
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
      
      assert::are_equal(0xFFFF0000U, c.to_argb());
      assert::are_equal(known_color::red, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_rosy_brown) {
      color c = color::from_known_color(known_color::rosy_brown);
      
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
      
      assert::are_equal(0xFFBC8F8FU, c.to_argb());
      assert::are_equal(known_color::rosy_brown, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_royal_blue) {
      color c = color::from_known_color(known_color::royal_blue);
      
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
      
      assert::are_equal(0xFF4169E1U, c.to_argb());
      assert::are_equal(known_color::royal_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_saddle_brown) {
      color c = color::from_known_color(known_color::saddle_brown);
      
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
      
      assert::are_equal(0xFF8B4513U, c.to_argb());
      assert::are_equal(known_color::saddle_brown, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_salmon) {
      color c = color::from_known_color(known_color::salmon);
      
      assert::are_equal(color::from_known_color(known_color::salmon), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFA, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x72, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("salmon", c.name());
      
      assert::are_equal("color [salmon]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFA8072U, c.to_argb());
      assert::are_equal(known_color::salmon, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_sandy_brown) {
      color c = color::from_known_color(known_color::sandy_brown);
      
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
      
      assert::are_equal(0xFFF4A460U, c.to_argb());
      assert::are_equal(known_color::sandy_brown, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_sea_green) {
      color c = color::from_known_color(known_color::sea_green);
      
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
      
      assert::are_equal(0xFF2E8B57U, c.to_argb());
      assert::are_equal(known_color::sea_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_sea_shell) {
      color c = color::from_known_color(known_color::sea_shell);
      
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
      
      assert::are_equal(0xFFFFF5EEU, c.to_argb());
      assert::are_equal(known_color::sea_shell, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_sienna) {
      color c = color::from_known_color(known_color::sienna);
      
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
      
      assert::are_equal(0xFFA0522DU, c.to_argb());
      assert::are_equal(known_color::sienna, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_silver) {
      color c = color::from_known_color(known_color::silver);
      
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
      
      assert::are_equal(0xFFC0C0C0U, c.to_argb());
      assert::are_equal(known_color::silver, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_sky_blue) {
      color c = color::from_known_color(known_color::sky_blue);
      
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
      
      assert::are_equal(0xFF87CEEBU, c.to_argb());
      assert::are_equal(known_color::sky_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_slate_blue) {
      color c = color::from_known_color(known_color::slate_blue);
      
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
      
      assert::are_equal(0xFF6A5ACDU, c.to_argb());
      assert::are_equal(known_color::slate_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_slate_gray) {
      color c = color::from_known_color(known_color::slate_gray);
      
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
      
      assert::are_equal(0xFF708090U, c.to_argb());
      assert::are_equal(known_color::slate_gray, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_snow) {
      color c = color::from_known_color(known_color::snow);
      
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
      
      assert::are_equal(0xFFFFFAFAU, c.to_argb());
      assert::are_equal(known_color::snow, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_spring_green) {
      color c = color::from_known_color(known_color::spring_green);
      
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
      
      assert::are_equal(0xFF00FF7FU, c.to_argb());
      assert::are_equal(known_color::spring_green, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_steel_blue) {
      color c = color::from_known_color(known_color::steel_blue);
      
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
      
      assert::are_equal(0xFF4682B4U, c.to_argb());
      assert::are_equal(known_color::steel_blue, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_tan) {
      color c = color::from_known_color(known_color::tan);
      
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
      
      assert::are_equal(0xFFD2B48CU, c.to_argb());
      assert::are_equal(known_color::tan, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_teal) {
      color c = color::from_known_color(known_color::teal);
      
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
      
      assert::are_equal(0xFF008080U, c.to_argb());
      assert::are_equal(known_color::teal, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_thistle) {
      color c = color::from_known_color(known_color::thistle);
      
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
      
      assert::are_equal(0xFFD8BFD8U, c.to_argb());
      assert::are_equal(known_color::thistle, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_tomato) {
      color c = color::from_known_color(known_color::tomato);
      
      assert::are_equal(color::from_known_color(known_color::tomato), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x63, c.g());
      assert::are_equal(0x47, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("tomato", c.name());
      
      assert::are_equal("color [tomato]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF6347U, c.to_argb());
      assert::are_equal(known_color::tomato, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_turquoise) {
      color c = color::from_known_color(known_color::turquoise);
      
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
      
      assert::are_equal(0xFF40E0D0U, c.to_argb());
      assert::are_equal(known_color::turquoise, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_violet) {
      color c = color::from_known_color(known_color::violet);
      
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
      
      assert::are_equal(0xFFEE82EEU, c.to_argb());
      assert::are_equal(known_color::violet, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_wheat) {
      color c = color::from_known_color(known_color::wheat);
      
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
      
      assert::are_equal(0xFFF5DEB3U, c.to_argb());
      assert::are_equal(known_color::wheat, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_white) {
      color c = color::from_known_color(known_color::white);
      
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
      
      assert::are_equal(0xFFFFFFFFU, c.to_argb());
      assert::are_equal(known_color::white, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_white_smoke) {
      color c = color::from_known_color(known_color::white_smoke);
      
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
      
      assert::are_equal(0xFFF5F5F5U, c.to_argb());
      assert::are_equal(known_color::white_smoke, c.to_known_color());
    }
    
    void test_method_(create_from_know_color_yellow) {
      color c = color::from_known_color(known_color::yellow);
      
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
      
      assert::are_equal(0xFFFFFF00U, c.to_argb());
      assert::are_equal(known_color::yellow, c.to_known_color());
    }

    void test_method_(create_from_name_transparent) {
      color c = color::from_name("transparent");
      
      assert::are_equal(color::from_name("transparent"), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0x00, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xFF, c.g());
      assert::are_equal(0xFF, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("transparent", c.name());
      
      assert::are_equal("color [transparent]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0x00FFFFFFU, c.to_argb());
      assert::are_equal(known_color::transparent, c.to_known_color());
    }
    
    void test_method_(create_from_name_alice_blue) {
      color c = color::from_name("alice_blue");
      
      assert::are_equal(color::from_name("alice_blue"), c);
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
      
      assert::are_equal(0xFFF0F8FFU, c.to_argb());
      assert::are_equal(known_color::alice_blue, c.to_known_color());
    }
    
    void test_method_(create_from_name_antique_white) {
      color c = color::from_name("antique_white");
      
      assert::are_equal(color::from_name("antique_white"), c);
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
      
      assert::are_equal(0xFFFAEBD7U, c.to_argb());
      assert::are_equal(known_color::antique_white, c.to_known_color());
    }
    
    void test_method_(create_from_name_aqua) {
      color c = color::from_name("aqua");
      
      assert::are_equal(color::from_name("aqua"), c);
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
      
      assert::are_equal(0xFF00FFFFU, c.to_argb());
      assert::are_equal(known_color::aqua, c.to_known_color());
    }
    
    void test_method_(create_from_name_aquamarine) {
      color c = color::from_name("aquamarine");
      
      assert::are_equal(color::from_name("aquamarine"), c);
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
      
      assert::are_equal(0xFF7FFFD4U, c.to_argb());
      assert::are_equal(known_color::aquamarine, c.to_known_color());
    }
    
    void test_method_(create_from_name_azure) {
      color c = color::from_name("azure");
      
      assert::are_equal(color::from_name("azure"), c);
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
      
      assert::are_equal(0xFFF0FFFFU, c.to_argb());
      assert::are_equal(known_color::azure, c.to_known_color());
    }
    
    void test_method_(create_from_name_beige) {
      color c = color::from_name("beige");
      
      assert::are_equal(color::from_name("beige"), c);
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
      
      assert::are_equal(0xFFF5F5DCU, c.to_argb());
      assert::are_equal(known_color::beige, c.to_known_color());
    }
    
    void test_method_(create_from_name_bisque) {
      color c = color::from_name("bisque");
      
      assert::are_equal(color::from_name("bisque"), c);
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
      
      assert::are_equal(0xFFFFE4C4U, c.to_argb());
      assert::are_equal(known_color::bisque, c.to_known_color());
    }
    
    void test_method_(create_from_name_black) {
      color c = color::from_name("black");
      
      assert::are_equal(color::from_name("black"), c);
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
      
      assert::are_equal(0xFF000000U, c.to_argb());
      assert::are_equal(known_color::black, c.to_known_color());
    }
    
    void test_method_(create_from_name_blanched_almond) {
      color c = color::from_name("blanched_almond");
      
      assert::are_equal(color::from_name("blanched_almond"), c);
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
      
      assert::are_equal(0xFFFFEBCDU, c.to_argb());
      assert::are_equal(known_color::blanched_almond, c.to_known_color());
    }
    
    void test_method_(create_from_name_blue) {
      color c = color::from_name("blue");
      
      assert::are_equal(color::from_name("blue"), c);
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
      
      assert::are_equal(0xFF0000FFU, c.to_argb());
      assert::are_equal(known_color::blue, c.to_known_color());
    }
    
    void test_method_(create_from_name_blue_violet) {
      color c = color::from_name("blue_violet");
      
      assert::are_equal(color::from_name("blue_violet"), c);
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
      
      assert::are_equal(0xFF8A2BE2U, c.to_argb());
      assert::are_equal(known_color::blue_violet, c.to_known_color());
    }
    
    void test_method_(create_from_name_brown) {
      color c = color::from_name("brown");
      
      assert::are_equal(color::from_name("brown"), c);
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
      
      assert::are_equal(0xFFA52A2AU, c.to_argb());
      assert::are_equal(known_color::brown, c.to_known_color());
    }
    
    void test_method_(create_from_name_burly_wood) {
      color c = color::from_name("burly_wood");
      
      assert::are_equal(color::from_name("burly_wood"), c);
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
      
      assert::are_equal(0xFFDEB887U, c.to_argb());
      assert::are_equal(known_color::burly_wood, c.to_known_color());
    }
    
    void test_method_(create_from_name_cadet_blue) {
      color c = color::from_name("cadet_blue");
      
      assert::are_equal(color::from_name("cadet_blue"), c);
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
      
      assert::are_equal(0xFF5F9EA0U, c.to_argb());
      assert::are_equal(known_color::cadet_blue, c.to_known_color());
    }
    
    void test_method_(create_from_name_chartreuse) {
      color c = color::from_name("chartreuse");
      
      assert::are_equal(color::from_name("chartreuse"), c);
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
      
      assert::are_equal(0xFF7FFF00U, c.to_argb());
      assert::are_equal(known_color::chartreuse, c.to_known_color());
    }
    
    void test_method_(create_from_name_chocolate) {
      color c = color::from_name("chocolate");
      
      assert::are_equal(color::from_name("chocolate"), c);
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
      
      assert::are_equal(0xFFD2691EU, c.to_argb());
      assert::are_equal(known_color::chocolate, c.to_known_color());
    }
    
    void test_method_(create_from_name_coral) {
      color c = color::from_name("coral");
      
      assert::are_equal(color::from_name("coral"), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x7F, c.g());
      assert::are_equal(0x50, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("coral", c.name());
      
      assert::are_equal("color [coral]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF7F50U, c.to_argb());
      assert::are_equal(known_color::coral, c.to_known_color());
    }
    
    void test_method_(create_from_name_cornflower_blue) {
      color c = color::from_name("cornflower_blue");
      
      assert::are_equal(color::from_name("cornflower_blue"), c);
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
      
      assert::are_equal(0xFF6495EDU, c.to_argb());
      assert::are_equal(known_color::cornflower_blue, c.to_known_color());
    }
    
    void test_method_(create_from_name_cornsilk) {
      color c = color::from_name("cornsilk");
      
      assert::are_equal(color::from_name("cornsilk"), c);
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
      
      assert::are_equal(0xFFFFF8DCU, c.to_argb());
      assert::are_equal(known_color::cornsilk, c.to_known_color());
    }
    
    void test_method_(create_from_name_crimson) {
      color c = color::from_name("crimson");
      
      assert::are_equal(color::from_name("crimson"), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xDC, c.r());
      assert::are_equal(0x14, c.g());
      assert::are_equal(0x3C, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("crimson", c.name());
      
      assert::are_equal("color [crimson]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFDC143CU, c.to_argb());
      assert::are_equal(known_color::crimson, c.to_known_color());
    }
    
    void test_method_(create_from_name_cyan) {
      color c = color::from_name("cyan");
      
      assert::are_equal(color::from_name("cyan"), c);
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
      
      assert::are_equal(0xFF00FFFFU, c.to_argb());
      assert::are_equal(known_color::cyan, c.to_known_color());
    }
    
    void test_method_(create_from_name_dark_blue) {
      color c = color::from_name("dark_blue");
      
      assert::are_equal(color::from_name("dark_blue"), c);
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
      
      assert::are_equal(0xFF00008BU, c.to_argb());
      assert::are_equal(known_color::dark_blue, c.to_known_color());
    }
    
    void test_method_(create_from_name_dark_cyan) {
      color c = color::from_name("dark_cyan");
      
      assert::are_equal(color::from_name("dark_cyan"), c);
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
      
      assert::are_equal(0xFF008B8BU, c.to_argb());
      assert::are_equal(known_color::dark_cyan, c.to_known_color());
    }
    
    void test_method_(create_from_name_dark_goldenrod) {
      color c = color::from_name("dark_goldenrod");
      
      assert::are_equal(color::from_name("dark_goldenrod"), c);
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
      
      assert::are_equal(0xFFB8860BU, c.to_argb());
      assert::are_equal(known_color::dark_goldenrod, c.to_known_color());
    }
    
    void test_method_(create_from_name_dark_gray) {
      color c = color::from_name("dark_gray");
      
      assert::are_equal(color::from_name("dark_gray"), c);
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
      
      assert::are_equal(0xFFA9A9A9U, c.to_argb());
      assert::are_equal(known_color::dark_gray, c.to_known_color());
    }
    
    void test_method_(create_from_name_dark_green) {
      color c = color::from_name("dark_green");
      
      assert::are_equal(color::from_name("dark_green"), c);
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
      
      assert::are_equal(0xFF006400U, c.to_argb());
      assert::are_equal(known_color::dark_green, c.to_known_color());
    }
    
    void test_method_(create_from_name_dark_khaki) {
      color c = color::from_name("dark_khaki");
      
      assert::are_equal(color::from_name("dark_khaki"), c);
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
      
      assert::are_equal(0xFFBDB76BU, c.to_argb());
      assert::are_equal(known_color::dark_khaki, c.to_known_color());
    }
    
    void test_method_(create_from_name_dark_magenta) {
      color c = color::from_name("dark_magenta");
      
      assert::are_equal(color::from_name("dark_magenta"), c);
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
      
      assert::are_equal(0xFF8B008BU, c.to_argb());
      assert::are_equal(known_color::dark_magenta, c.to_known_color());
    }
    
    void test_method_(create_from_name_dark_olive_green) {
      color c = color::from_name("dark_olive_green");
      
      assert::are_equal(color::from_name("dark_olive_green"), c);
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
      
      assert::are_equal(0xFF556B2FU, c.to_argb());
      assert::are_equal(known_color::dark_olive_green, c.to_known_color());
    }
    
    void test_method_(create_from_name_dark_orange) {
      color c = color::from_name("dark_orange");
      
      assert::are_equal(color::from_name("dark_orange"), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x8C, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_orange", c.name());
      
      assert::are_equal("color [dark_orange]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF8C00U, c.to_argb());
      assert::are_equal(known_color::dark_orange, c.to_known_color());
    }
    
    void test_method_(create_from_name_dark_orchid) {
      color c = color::from_name("dark_orchid");
      
      assert::are_equal(color::from_name("dark_orchid"), c);
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
      
      assert::are_equal(0xFF9932CCU, c.to_argb());
      assert::are_equal(known_color::dark_orchid, c.to_known_color());
    }
    
    void test_method_(create_from_name_dark_red) {
      color c = color::from_name("dark_red");
      
      assert::are_equal(color::from_name("dark_red"), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0x8B, c.r());
      assert::are_equal(0x00, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_red", c.name());
      
      assert::are_equal("color [dark_red]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFF8B0000U, c.to_argb());
      assert::are_equal(known_color::dark_red, c.to_known_color());
    }
    
    void test_method_(create_from_name_dark_salmon) {
      color c = color::from_name("dark_salmon");
      
      assert::are_equal(color::from_name("dark_salmon"), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xE9, c.r());
      assert::are_equal(0x96, c.g());
      assert::are_equal(0x7A, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("dark_salmon", c.name());
      
      assert::are_equal("color [dark_salmon]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFE9967AU, c.to_argb());
      assert::are_equal(known_color::dark_salmon, c.to_known_color());
    }
    
    void test_method_(create_from_name_dark_sea_green) {
      color c = color::from_name("dark_sea_green");
      
      assert::are_equal(color::from_name("dark_sea_green"), c);
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
      
      assert::are_equal(0xFF8FBC8BU, c.to_argb());
      assert::are_equal(known_color::dark_sea_green, c.to_known_color());
    }
    
    void test_method_(create_from_name_dark_slate_blue) {
      color c = color::from_name("dark_slate_blue");
      
      assert::are_equal(color::from_name("dark_slate_blue"), c);
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
      
      assert::are_equal(0xFF483D8BU, c.to_argb());
      assert::are_equal(known_color::dark_slate_blue, c.to_known_color());
    }
    
    void test_method_(create_from_name_dark_slate_gray) {
      color c = color::from_name("dark_slate_gray");
      
      assert::are_equal(color::from_name("dark_slate_gray"), c);
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
      
      assert::are_equal(0xFF2F4F4FU, c.to_argb());
      assert::are_equal(known_color::dark_slate_gray, c.to_known_color());
    }
    
    void test_method_(create_from_name_dark_turquoise) {
      color c = color::from_name("dark_turquoise");
      
      assert::are_equal(color::from_name("dark_turquoise"), c);
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
      
      assert::are_equal(0xFF00CED1U, c.to_argb());
      assert::are_equal(known_color::dark_turquoise, c.to_known_color());
    }
    
    void test_method_(create_from_name_dark_violet) {
      color c = color::from_name("dark_violet");
      
      assert::are_equal(color::from_name("dark_violet"), c);
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
      
      assert::are_equal(0xFF9400D3U, c.to_argb());
      assert::are_equal(known_color::dark_violet, c.to_known_color());
    }
    
    void test_method_(create_from_name_deep_pink) {
      color c = color::from_name("deep_pink");
      
      assert::are_equal(color::from_name("deep_pink"), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x14, c.g());
      assert::are_equal(0x93, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("deep_pink", c.name());
      
      assert::are_equal("color [deep_pink]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF1493U, c.to_argb());
      assert::are_equal(known_color::deep_pink, c.to_known_color());
    }
    
    void test_method_(create_from_name_deep_sky_blue) {
      color c = color::from_name("deep_sky_blue");
      
      assert::are_equal(color::from_name("deep_sky_blue"), c);
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
      
      assert::are_equal(0xFF00BFFFU, c.to_argb());
      assert::are_equal(known_color::deep_sky_blue, c.to_known_color());
    }
    
    void test_method_(create_from_name_dim_gray) {
      color c = color::from_name("dim_gray");
      
      assert::are_equal(color::from_name("dim_gray"), c);
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
      
      assert::are_equal(0xFF696969U, c.to_argb());
      assert::are_equal(known_color::dim_gray, c.to_known_color());
    }
    
    void test_method_(create_from_name_dodger_blue) {
      color c = color::from_name("dodger_blue");
      
      assert::are_equal(color::from_name("dodger_blue"), c);
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
      
      assert::are_equal(0xFF1E90FFU, c.to_argb());
      assert::are_equal(known_color::dodger_blue, c.to_known_color());
    }
    
    void test_method_(create_from_name_firebrick) {
      color c = color::from_name("firebrick");
      
      assert::are_equal(color::from_name("firebrick"), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xB2, c.r());
      assert::are_equal(0x22, c.g());
      assert::are_equal(0x22, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("firebrick", c.name());
      
      assert::are_equal("color [firebrick]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFB22222U, c.to_argb());
      assert::are_equal(known_color::firebrick, c.to_known_color());
    }
    
    void test_method_(create_from_name_floral_white) {
      color c = color::from_name("floral_white");
      
      assert::are_equal(color::from_name("floral_white"), c);
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
      
      assert::are_equal(0xFFFFFAF0U, c.to_argb());
      assert::are_equal(known_color::floral_white, c.to_known_color());
    }
    
    void test_method_(create_from_name_forest_green) {
      color c = color::from_name("forest_green");
      
      assert::are_equal(color::from_name("forest_green"), c);
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
      
      assert::are_equal(0xFF228B22U, c.to_argb());
      assert::are_equal(known_color::forest_green, c.to_known_color());
    }
    
    void test_method_(create_from_name_fuchsia) {
      color c = color::from_name("fuchsia");
      
      assert::are_equal(color::from_name("fuchsia"), c);
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
      
      assert::are_equal(0xFFFF00FFU, c.to_argb());
      assert::are_equal(known_color::fuchsia, c.to_known_color());
    }
    
    void test_method_(create_from_name_gainsboro) {
      color c = color::from_name("gainsboro");
      
      assert::are_equal(color::from_name("gainsboro"), c);
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
      
      assert::are_equal(0xFFDCDCDCU, c.to_argb());
      assert::are_equal(known_color::gainsboro, c.to_known_color());
    }
    
    void test_method_(create_from_name_ghost_white) {
      color c = color::from_name("ghost_white");
      
      assert::are_equal(color::from_name("ghost_white"), c);
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
      
      assert::are_equal(0xFFF8F8FFU, c.to_argb());
      assert::are_equal(known_color::ghost_white, c.to_known_color());
    }
    
    void test_method_(create_from_name_gold) {
      color c = color::from_name("gold");
      
      assert::are_equal(color::from_name("gold"), c);
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
      
      assert::are_equal(0xFFFFD700U, c.to_argb());
      assert::are_equal(known_color::gold, c.to_known_color());
    }
    
    void test_method_(create_from_name_goldenrod) {
      color c = color::from_name("goldenrod");
      
      assert::are_equal(color::from_name("goldenrod"), c);
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
      
      assert::are_equal(0xFFDAA520U, c.to_argb());
      assert::are_equal(known_color::goldenrod, c.to_known_color());
    }
    
    void test_method_(create_from_name_gray) {
      color c = color::from_name("gray");
      
      assert::are_equal(color::from_name("gray"), c);
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
      
      assert::are_equal(0xFF808080U, c.to_argb());
      assert::are_equal(known_color::gray, c.to_known_color());
    }
    
    void test_method_(create_from_name_green) {
      color c = color::from_name("green");
      
      assert::are_equal(color::from_name("green"), c);
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
      
      assert::are_equal(0xFF008000U, c.to_argb());
      assert::are_equal(known_color::green, c.to_known_color());
    }
    
    void test_method_(create_from_name_green_yellow) {
      color c = color::from_name("green_yellow");
      
      assert::are_equal(color::from_name("green_yellow"), c);
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
      
      assert::are_equal(0xFFADFF2FU, c.to_argb());
      assert::are_equal(known_color::green_yellow, c.to_known_color());
    }
    
    void test_method_(create_from_name_honeydew) {
      color c = color::from_name("honeydew");
      
      assert::are_equal(color::from_name("honeydew"), c);
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
      
      assert::are_equal(0xFFF0FFF0U, c.to_argb());
      assert::are_equal(known_color::honeydew, c.to_known_color());
    }
    
    void test_method_(create_from_name_hot_pink) {
      color c = color::from_name("hot_pink");
      
      assert::are_equal(color::from_name("hot_pink"), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x69, c.g());
      assert::are_equal(0xB4, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("hot_pink", c.name());
      
      assert::are_equal("color [hot_pink]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF69B4U, c.to_argb());
      assert::are_equal(known_color::hot_pink, c.to_known_color());
    }
    
    void test_method_(create_from_name_indian_red) {
      color c = color::from_name("indian_red");
      
      assert::are_equal(color::from_name("indian_red"), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xCD, c.r());
      assert::are_equal(0x5C, c.g());
      assert::are_equal(0x5C, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("indian_red", c.name());
      
      assert::are_equal("color [indian_red]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFCD5C5CU, c.to_argb());
      assert::are_equal(known_color::indian_red, c.to_known_color());
    }
    
    void test_method_(create_from_name_indigo) {
      color c = color::from_name("indigo");
      
      assert::are_equal(color::from_name("indigo"), c);
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
      
      assert::are_equal(0xFF4B0082U, c.to_argb());
      assert::are_equal(known_color::indigo, c.to_known_color());
    }
    
    void test_method_(create_from_name_ivory) {
      color c = color::from_name("ivory");
      
      assert::are_equal(color::from_name("ivory"), c);
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
      
      assert::are_equal(0xFFFFFFF0U, c.to_argb());
      assert::are_equal(known_color::ivory, c.to_known_color());
    }
    
    void test_method_(create_from_name_khaki) {
      color c = color::from_name("khaki");
      
      assert::are_equal(color::from_name("khaki"), c);
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
      
      assert::are_equal(0xFFF0E68CU, c.to_argb());
      assert::are_equal(known_color::khaki, c.to_known_color());
    }
    
    void test_method_(create_from_name_lavender) {
      color c = color::from_name("lavender");
      
      assert::are_equal(color::from_name("lavender"), c);
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
      
      assert::are_equal(0xFFE6E6FAU, c.to_argb());
      assert::are_equal(known_color::lavender, c.to_known_color());
    }
    
    void test_method_(create_from_name_lavender_blush) {
      color c = color::from_name("lavender_blush");
      
      assert::are_equal(color::from_name("lavender_blush"), c);
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
      
      assert::are_equal(0xFFFFF0F5U, c.to_argb());
      assert::are_equal(known_color::lavender_blush, c.to_known_color());
    }
    
    void test_method_(create_from_name_lawn_green) {
      color c = color::from_name("lawn_green");
      
      assert::are_equal(color::from_name("lawn_green"), c);
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
      
      assert::are_equal(0xFF7CFC00U, c.to_argb());
      assert::are_equal(known_color::lawn_green, c.to_known_color());
    }
    
    void test_method_(create_from_name_lemon_chiffon) {
      color c = color::from_name("lemon_chiffon");
      
      assert::are_equal(color::from_name("lemon_chiffon"), c);
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
      
      assert::are_equal(0xFFFFFACDU, c.to_argb());
      assert::are_equal(known_color::lemon_chiffon, c.to_known_color());
    }
    
    void test_method_(create_from_name_light_blue) {
      color c = color::from_name("light_blue");
      
      assert::are_equal(color::from_name("light_blue"), c);
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
      
      assert::are_equal(0xFFADD8E6U, c.to_argb());
      assert::are_equal(known_color::light_blue, c.to_known_color());
    }
    
    void test_method_(create_from_name_light_coral) {
      color c = color::from_name("light_coral");
      
      assert::are_equal(color::from_name("light_coral"), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xF0, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x80, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_coral", c.name());
      
      assert::are_equal("color [light_coral]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFF08080U, c.to_argb());
      assert::are_equal(known_color::light_coral, c.to_known_color());
    }
    
    void test_method_(create_from_name_light_cyan) {
      color c = color::from_name("light_cyan");
      
      assert::are_equal(color::from_name("light_cyan"), c);
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
      
      assert::are_equal(0xFFE0FFFFU, c.to_argb());
      assert::are_equal(known_color::light_cyan, c.to_known_color());
    }
    
    void test_method_(create_from_name_light_goldenrod_yellow) {
      color c = color::from_name("light_goldenrod_yellow");
      
      assert::are_equal(color::from_name("light_goldenrod_yellow"), c);
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
      
      assert::are_equal(0xFFFAFAD2U, c.to_argb());
      assert::are_equal(known_color::light_goldenrod_yellow, c.to_known_color());
    }
    
    void test_method_(create_from_name_light_gray) {
      color c = color::from_name("light_gray");
      
      assert::are_equal(color::from_name("light_gray"), c);
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
      
      assert::are_equal(0xFFD3D3D3U, c.to_argb());
      assert::are_equal(known_color::light_gray, c.to_known_color());
    }
    
    void test_method_(create_from_name_light_green) {
      color c = color::from_name("light_green");
      
      assert::are_equal(color::from_name("light_green"), c);
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
      
      assert::are_equal(0xFF90EE90U, c.to_argb());
      assert::are_equal(known_color::light_green, c.to_known_color());
    }
    
    void test_method_(create_from_name_light_pink) {
      color c = color::from_name("light_pink");
      
      assert::are_equal(color::from_name("light_pink"), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xB6, c.g());
      assert::are_equal(0xC1, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_pink", c.name());
      
      assert::are_equal("color [light_pink]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFB6C1U, c.to_argb());
      assert::are_equal(known_color::light_pink, c.to_known_color());
    }
    
    void test_method_(create_from_name_light_salmon) {
      color c = color::from_name("light_salmon");
      
      assert::are_equal(color::from_name("light_salmon"), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xA0, c.g());
      assert::are_equal(0x7A, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("light_salmon", c.name());
      
      assert::are_equal("color [light_salmon]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFA07AU, c.to_argb());
      assert::are_equal(known_color::light_salmon, c.to_known_color());
    }
    
    void test_method_(create_from_name_light_sea_green) {
      color c = color::from_name("light_sea_green");
      
      assert::are_equal(color::from_name("light_sea_green"), c);
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
      
      assert::are_equal(0xFF20B2AAU, c.to_argb());
      assert::are_equal(known_color::light_sea_green, c.to_known_color());
    }
    
    void test_method_(create_from_name_light_sky_blue) {
      color c = color::from_name("light_sky_blue");
      
      assert::are_equal(color::from_name("light_sky_blue"), c);
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
      
      assert::are_equal(0xFF87CEFAU, c.to_argb());
      assert::are_equal(known_color::light_sky_blue, c.to_known_color());
    }
    
    void test_method_(create_from_name_light_slate_gray) {
      color c = color::from_name("light_slate_gray");
      
      assert::are_equal(color::from_name("light_slate_gray"), c);
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
      
      assert::are_equal(0xFF778899U, c.to_argb());
      assert::are_equal(known_color::light_slate_gray, c.to_known_color());
    }
    
    void test_method_(create_from_name_light_steel_blue) {
      color c = color::from_name("light_steel_blue");
      
      assert::are_equal(color::from_name("light_steel_blue"), c);
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
      
      assert::are_equal(0xFFB0C4DEU, c.to_argb());
      assert::are_equal(known_color::light_steel_blue, c.to_known_color());
    }
    
    void test_method_(create_from_name_light_yellow) {
      color c = color::from_name("light_yellow");
      
      assert::are_equal(color::from_name("light_yellow"), c);
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
      
      assert::are_equal(0xFFFFFFE0U, c.to_argb());
      assert::are_equal(known_color::light_yellow, c.to_known_color());
    }
    
    void test_method_(create_from_name_lime) {
      color c = color::from_name("lime");
      
      assert::are_equal(color::from_name("lime"), c);
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
      
      assert::are_equal(0xFF00FF00U, c.to_argb());
      assert::are_equal(known_color::lime, c.to_known_color());
    }
    
    void test_method_(create_from_name_lime_green) {
      color c = color::from_name("lime_green");
      
      assert::are_equal(color::from_name("lime_green"), c);
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
      
      assert::are_equal(0xFF32CD32U, c.to_argb());
      assert::are_equal(known_color::lime_green, c.to_known_color());
    }
    
    void test_method_(create_from_name_linen) {
      color c = color::from_name("linen");
      
      assert::are_equal(color::from_name("linen"), c);
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
      
      assert::are_equal(0xFFFAF0E6U, c.to_argb());
      assert::are_equal(known_color::linen, c.to_known_color());
    }
    
    void test_method_(create_from_name_magenta) {
      color c = color::from_name("magenta");
      
      assert::are_equal(color::from_name("magenta"), c);
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
      
      assert::are_equal(0xFFFF00FFU, c.to_argb());
      assert::are_equal(known_color::magenta, c.to_known_color());
    }
    
    void test_method_(create_from_name_maroon) {
      color c = color::from_name("maroon");
      
      assert::are_equal(color::from_name("maroon"), c);
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
      
      assert::are_equal(0xFF800000U, c.to_argb());
      assert::are_equal(known_color::maroon, c.to_known_color());
    }
    
    void test_method_(create_from_name_medium_aquamarine) {
      color c = color::from_name("medium_aquamarine");
      
      assert::are_equal(color::from_name("medium_aquamarine"), c);
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
      
      assert::are_equal(0xFF66CDAAU, c.to_argb());
      assert::are_equal(known_color::medium_aquamarine, c.to_known_color());
    }
    
    void test_method_(create_from_name_medium_blue) {
      color c = color::from_name("medium_blue");
      
      assert::are_equal(color::from_name("medium_blue"), c);
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
      
      assert::are_equal(0xFF0000CDU, c.to_argb());
      assert::are_equal(known_color::medium_blue, c.to_known_color());
    }
    
    void test_method_(create_from_name_medium_orchid) {
      color c = color::from_name("medium_orchid");
      
      assert::are_equal(color::from_name("medium_orchid"), c);
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
      
      assert::are_equal(0xFFBA55D3U, c.to_argb());
      assert::are_equal(known_color::medium_orchid, c.to_known_color());
    }
    
    void test_method_(create_from_name_medium_purple) {
      color c = color::from_name("medium_purple");
      
      assert::are_equal(color::from_name("medium_purple"), c);
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
      
      assert::are_equal(0xFF9370DBU, c.to_argb());
      assert::are_equal(known_color::medium_purple, c.to_known_color());
    }
    
    void test_method_(create_from_name_medium_sea_green) {
      color c = color::from_name("medium_sea_green");
      
      assert::are_equal(color::from_name("medium_sea_green"), c);
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
      
      assert::are_equal(0xFF3CB371U, c.to_argb());
      assert::are_equal(known_color::medium_sea_green, c.to_known_color());
    }
    
    void test_method_(create_from_name_medium_slate_blue) {
      color c = color::from_name("medium_slate_blue");
      
      assert::are_equal(color::from_name("medium_slate_blue"), c);
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
      
      assert::are_equal(0xFF7B68EEU, c.to_argb());
      assert::are_equal(known_color::medium_slate_blue, c.to_known_color());
    }
    
    void test_method_(create_from_name_medium_spring_green) {
      color c = color::from_name("medium_spring_green");
      
      assert::are_equal(color::from_name("medium_spring_green"), c);
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
      
      assert::are_equal(0xFF00FA9AU, c.to_argb());
      assert::are_equal(known_color::medium_spring_green, c.to_known_color());
    }
    
    void test_method_(create_from_name_medium_turquoise) {
      color c = color::from_name("medium_turquoise");
      
      assert::are_equal(color::from_name("medium_turquoise"), c);
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
      
      assert::are_equal(0xFF48D1CCU, c.to_argb());
      assert::are_equal(known_color::medium_turquoise, c.to_known_color());
    }
    
    void test_method_(create_from_name_medium_violet_red) {
      color c = color::from_name("medium_violet_red");
      
      assert::are_equal(color::from_name("medium_violet_red"), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xC7, c.r());
      assert::are_equal(0x15, c.g());
      assert::are_equal(0x85, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("medium_violet_red", c.name());
      
      assert::are_equal("color [medium_violet_red]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFC71585U, c.to_argb());
      assert::are_equal(known_color::medium_violet_red, c.to_known_color());
    }
    
    void test_method_(create_from_name_midnight_blue) {
      color c = color::from_name("midnight_blue");
      
      assert::are_equal(color::from_name("midnight_blue"), c);
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
      
      assert::are_equal(0xFF191970U, c.to_argb());
      assert::are_equal(known_color::midnight_blue, c.to_known_color());
    }
    
    void test_method_(create_from_name_mint_cream) {
      color c = color::from_name("mint_cream");
      
      assert::are_equal(color::from_name("mint_cream"), c);
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
      
      assert::are_equal(0xFFF5FFFAU, c.to_argb());
      assert::are_equal(known_color::mint_cream, c.to_known_color());
    }
    
    void test_method_(create_from_name_misty_rose) {
      color c = color::from_name("misty_rose");
      
      assert::are_equal(color::from_name("misty_rose"), c);
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
      
      assert::are_equal(0xFFFFE4E1U, c.to_argb());
      assert::are_equal(known_color::misty_rose, c.to_known_color());
    }
    
    void test_method_(create_from_name_moccasin) {
      color c = color::from_name("moccasin");
      
      assert::are_equal(color::from_name("moccasin"), c);
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
      
      assert::are_equal(0xFFFFE4B5U, c.to_argb());
      assert::are_equal(known_color::moccasin, c.to_known_color());
    }
    
    void test_method_(create_from_name_navajo_white) {
      color c = color::from_name("navajo_white");
      
      assert::are_equal(color::from_name("navajo_white"), c);
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
      
      assert::are_equal(0xFFFFDEADU, c.to_argb());
      assert::are_equal(known_color::navajo_white, c.to_known_color());
    }
    
    void test_method_(create_from_name_navy) {
      color c = color::from_name("navy");
      
      assert::are_equal(color::from_name("navy"), c);
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
      
      assert::are_equal(0xFF000080U, c.to_argb());
      assert::are_equal(known_color::navy, c.to_known_color());
    }
    
    void test_method_(create_from_name_old_lace) {
      color c = color::from_name("old_lace");
      
      assert::are_equal(color::from_name("old_lace"), c);
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
      
      assert::are_equal(0xFFFDF5E6U, c.to_argb());
      assert::are_equal(known_color::old_lace, c.to_known_color());
    }
    
    void test_method_(create_from_name_olive) {
      color c = color::from_name("olive");
      
      assert::are_equal(color::from_name("olive"), c);
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
      
      assert::are_equal(0xFF808000U, c.to_argb());
      assert::are_equal(known_color::olive, c.to_known_color());
    }
    
    void test_method_(create_from_name_olive_drab) {
      color c = color::from_name("olive_drab");
      
      assert::are_equal(color::from_name("olive_drab"), c);
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
      
      assert::are_equal(0xFF6B8E23U, c.to_argb());
      assert::are_equal(known_color::olive_drab, c.to_known_color());
    }
    
    void test_method_(create_from_name_orange) {
      color c = color::from_name("orange");
      
      assert::are_equal(color::from_name("orange"), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xA5, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("orange", c.name());
      
      assert::are_equal("color [orange]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFA500U, c.to_argb());
      assert::are_equal(known_color::orange, c.to_known_color());
    }
    
    void test_method_(create_from_name_orange_red) {
      color c = color::from_name("orange_red");
      
      assert::are_equal(color::from_name("orange_red"), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x45, c.g());
      assert::are_equal(0x00, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("orange_red", c.name());
      
      assert::are_equal("color [orange_red]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF4500U, c.to_argb());
      assert::are_equal(known_color::orange_red, c.to_known_color());
    }
    
    void test_method_(create_from_name_orchid) {
      color c = color::from_name("orchid");
      
      assert::are_equal(color::from_name("orchid"), c);
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
      
      assert::are_equal(0xFFDA70D6U, c.to_argb());
      assert::are_equal(known_color::orchid, c.to_known_color());
    }
    
    void test_method_(create_from_name_pale_goldenrod) {
      color c = color::from_name("pale_goldenrod");
      
      assert::are_equal(color::from_name("pale_goldenrod"), c);
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
      
      assert::are_equal(0xFFEEE8AAU, c.to_argb());
      assert::are_equal(known_color::pale_goldenrod, c.to_known_color());
    }
    
    void test_method_(create_from_name_pale_green) {
      color c = color::from_name("pale_green");
      
      assert::are_equal(color::from_name("pale_green"), c);
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
      
      assert::are_equal(0xFF98FB98U, c.to_argb());
      assert::are_equal(known_color::pale_green, c.to_known_color());
    }
    
    void test_method_(create_from_name_pale_turquoise) {
      color c = color::from_name("pale_turquoise");
      
      assert::are_equal(color::from_name("pale_turquoise"), c);
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
      
      assert::are_equal(0xFFAFEEEEU, c.to_argb());
      assert::are_equal(known_color::pale_turquoise, c.to_known_color());
    }
    
    void test_method_(create_from_name_pale_violet_red) {
      color c = color::from_name("pale_violet_red");
      
      assert::are_equal(color::from_name("pale_violet_red"), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xDB, c.r());
      assert::are_equal(0x70, c.g());
      assert::are_equal(0x93, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("pale_violet_red", c.name());
      
      assert::are_equal("color [pale_violet_red]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFDB7093U, c.to_argb());
      assert::are_equal(known_color::pale_violet_red, c.to_known_color());
    }
    
    void test_method_(create_from_name_papaya_whip) {
      color c = color::from_name("papaya_whip");
      
      assert::are_equal(color::from_name("papaya_whip"), c);
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
      
      assert::are_equal(0xFFFFEFD5U, c.to_argb());
      assert::are_equal(known_color::papaya_whip, c.to_known_color());
    }
    
    void test_method_(create_from_name_peach_puff) {
      color c = color::from_name("peach_puff");
      
      assert::are_equal(color::from_name("peach_puff"), c);
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
      
      assert::are_equal(0xFFFFDAB9U, c.to_argb());
      assert::are_equal(known_color::peach_puff, c.to_known_color());
    }
    
    void test_method_(create_from_name_peru) {
      color c = color::from_name("peru");
      
      assert::are_equal(color::from_name("peru"), c);
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
      
      assert::are_equal(0xFFCD853FU, c.to_argb());
      assert::are_equal(known_color::peru, c.to_known_color());
    }
    
    void test_method_(create_from_name_pink) {
      color c = color::from_name("pink");
      
      assert::are_equal(color::from_name("pink"), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0xC0, c.g());
      assert::are_equal(0xCB, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("pink", c.name());
      
      assert::are_equal("color [pink]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFFC0CBU, c.to_argb());
      assert::are_equal(known_color::pink, c.to_known_color());
    }
    
    void test_method_(create_from_name_plum) {
      color c = color::from_name("plum");
      
      assert::are_equal(color::from_name("plum"), c);
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
      
      assert::are_equal(0xFFDDA0DDU, c.to_argb());
      assert::are_equal(known_color::plum, c.to_known_color());
    }
    
    void test_method_(create_from_name_powder_blue) {
      color c = color::from_name("powder_blue");
      
      assert::are_equal(color::from_name("powder_blue"), c);
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
      
      assert::are_equal(0xFFB0E0E6U, c.to_argb());
      assert::are_equal(known_color::powder_blue, c.to_known_color());
    }
    
    void test_method_(create_from_name_purple) {
      color c = color::from_name("purple");
      
      assert::are_equal(color::from_name("purple"), c);
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
      
      assert::are_equal(0xFF800080U, c.to_argb());
      assert::are_equal(known_color::purple, c.to_known_color());
    }
    
    void test_method_(create_from_name_rebecca_purple) {
      color c = color::from_name("rebecca_purple");
      
      assert::are_equal(color::from_name("rebecca_purple"), c);
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
      
      assert::are_equal(0xFF663399U, c.to_argb());
      assert::are_equal(known_color::rebecca_purple, c.to_known_color());
    }
    
    void test_method_(create_from_name_red) {
      color c = color::from_name("red");
      
      assert::are_equal(color::from_name("red"), c);
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
      
      assert::are_equal(0xFFFF0000U, c.to_argb());
      assert::are_equal(known_color::red, c.to_known_color());
    }
    
    void test_method_(create_from_name_rosy_brown) {
      color c = color::from_name("rosy_brown");
      
      assert::are_equal(color::from_name("rosy_brown"), c);
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
      
      assert::are_equal(0xFFBC8F8FU, c.to_argb());
      assert::are_equal(known_color::rosy_brown, c.to_known_color());
    }
    
    void test_method_(create_from_name_royal_blue) {
      color c = color::from_name("royal_blue");
      
      assert::are_equal(color::from_name("royal_blue"), c);
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
      
      assert::are_equal(0xFF4169E1U, c.to_argb());
      assert::are_equal(known_color::royal_blue, c.to_known_color());
    }
    
    void test_method_(create_from_name_saddle_brown) {
      color c = color::from_name("saddle_brown");
      
      assert::are_equal(color::from_name("saddle_brown"), c);
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
      
      assert::are_equal(0xFF8B4513U, c.to_argb());
      assert::are_equal(known_color::saddle_brown, c.to_known_color());
    }
    
    void test_method_(create_from_name_salmon) {
      color c = color::from_name("salmon");
      
      assert::are_equal(color::from_name("salmon"), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFA, c.r());
      assert::are_equal(0x80, c.g());
      assert::are_equal(0x72, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("salmon", c.name());
      
      assert::are_equal("color [salmon]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFA8072U, c.to_argb());
      assert::are_equal(known_color::salmon, c.to_known_color());
    }
    
    void test_method_(create_from_name_sandy_brown) {
      color c = color::from_name("sandy_brown");
      
      assert::are_equal(color::from_name("sandy_brown"), c);
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
      
      assert::are_equal(0xFFF4A460U, c.to_argb());
      assert::are_equal(known_color::sandy_brown, c.to_known_color());
    }
    
    void test_method_(create_from_name_sea_green) {
      color c = color::from_name("sea_green");
      
      assert::are_equal(color::from_name("sea_green"), c);
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
      
      assert::are_equal(0xFF2E8B57U, c.to_argb());
      assert::are_equal(known_color::sea_green, c.to_known_color());
    }
    
    void test_method_(create_from_name_sea_shell) {
      color c = color::from_name("sea_shell");
      
      assert::are_equal(color::from_name("sea_shell"), c);
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
      
      assert::are_equal(0xFFFFF5EEU, c.to_argb());
      assert::are_equal(known_color::sea_shell, c.to_known_color());
    }
    
    void test_method_(create_from_name_sienna) {
      color c = color::from_name("sienna");
      
      assert::are_equal(color::from_name("sienna"), c);
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
      
      assert::are_equal(0xFFA0522DU, c.to_argb());
      assert::are_equal(known_color::sienna, c.to_known_color());
    }
    
    void test_method_(create_from_name_silver) {
      color c = color::from_name("silver");
      
      assert::are_equal(color::from_name("silver"), c);
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
      
      assert::are_equal(0xFFC0C0C0U, c.to_argb());
      assert::are_equal(known_color::silver, c.to_known_color());
    }
    
    void test_method_(create_from_name_sky_blue) {
      color c = color::from_name("sky_blue");
      
      assert::are_equal(color::from_name("sky_blue"), c);
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
      
      assert::are_equal(0xFF87CEEBU, c.to_argb());
      assert::are_equal(known_color::sky_blue, c.to_known_color());
    }
    
    void test_method_(create_from_name_slate_blue) {
      color c = color::from_name("slate_blue");
      
      assert::are_equal(color::from_name("slate_blue"), c);
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
      
      assert::are_equal(0xFF6A5ACDU, c.to_argb());
      assert::are_equal(known_color::slate_blue, c.to_known_color());
    }
    
    void test_method_(create_from_name_slate_gray) {
      color c = color::from_name("slate_gray");
      
      assert::are_equal(color::from_name("slate_gray"), c);
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
      
      assert::are_equal(0xFF708090U, c.to_argb());
      assert::are_equal(known_color::slate_gray, c.to_known_color());
    }
    
    void test_method_(create_from_name_snow) {
      color c = color::from_name("snow");
      
      assert::are_equal(color::from_name("snow"), c);
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
      
      assert::are_equal(0xFFFFFAFAU, c.to_argb());
      assert::are_equal(known_color::snow, c.to_known_color());
    }
    
    void test_method_(create_from_name_spring_green) {
      color c = color::from_name("spring_green");
      
      assert::are_equal(color::from_name("spring_green"), c);
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
      
      assert::are_equal(0xFF00FF7FU, c.to_argb());
      assert::are_equal(known_color::spring_green, c.to_known_color());
    }
    
    void test_method_(create_from_name_steel_blue) {
      color c = color::from_name("steel_blue");
      
      assert::are_equal(color::from_name("steel_blue"), c);
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
      
      assert::are_equal(0xFF4682B4U, c.to_argb());
      assert::are_equal(known_color::steel_blue, c.to_known_color());
    }
    
    void test_method_(create_from_name_tan) {
      color c = color::from_name("tan");
      
      assert::are_equal(color::from_name("tan"), c);
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
      
      assert::are_equal(0xFFD2B48CU, c.to_argb());
      assert::are_equal(known_color::tan, c.to_known_color());
    }
    
    void test_method_(create_from_name_teal) {
      color c = color::from_name("teal");
      
      assert::are_equal(color::from_name("teal"), c);
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
      
      assert::are_equal(0xFF008080U, c.to_argb());
      assert::are_equal(known_color::teal, c.to_known_color());
    }
    
    void test_method_(create_from_name_thistle) {
      color c = color::from_name("thistle");
      
      assert::are_equal(color::from_name("thistle"), c);
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
      
      assert::are_equal(0xFFD8BFD8U, c.to_argb());
      assert::are_equal(known_color::thistle, c.to_known_color());
    }
    
    void test_method_(create_from_name_tomato) {
      color c = color::from_name("tomato");
      
      assert::are_equal(color::from_name("tomato"), c);
      assert::are_not_equal(color(), c);
      assert::are_not_equal(color::empty, c);
      
      assert::are_equal(0xFF, c.a());
      assert::are_equal(0xFF, c.r());
      assert::are_equal(0x63, c.g());
      assert::are_equal(0x47, c.b());
      assert::are_equal(0, c.handle());
      assert::are_equal("tomato", c.name());
      
      assert::are_equal("color [tomato]", c.to_string());
      
      assert::is_false(c.is_empty());
      assert::is_true(c.is_known_color());
      assert::is_false(c.is_system_color());
      assert::is_true(c.is_named_color());
      
      assert::are_equal(0xFFFF6347U, c.to_argb());
      assert::are_equal(known_color::tomato, c.to_known_color());
    }
    
    void test_method_(create_from_name_turquoise) {
      color c = color::from_name("turquoise");
      
      assert::are_equal(color::from_name("turquoise"), c);
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
      
      assert::are_equal(0xFF40E0D0U, c.to_argb());
      assert::are_equal(known_color::turquoise, c.to_known_color());
    }
    
    void test_method_(create_from_name_violet) {
      color c = color::from_name("violet");
      
      assert::are_equal(color::from_name("violet"), c);
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
      
      assert::are_equal(0xFFEE82EEU, c.to_argb());
      assert::are_equal(known_color::violet, c.to_known_color());
    }
    
    void test_method_(create_from_name_wheat) {
      color c = color::from_name("wheat");
      
      assert::are_equal(color::from_name("wheat"), c);
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
      
      assert::are_equal(0xFFF5DEB3U, c.to_argb());
      assert::are_equal(known_color::wheat, c.to_known_color());
    }
    
    void test_method_(create_from_name_white) {
      color c = color::from_name("white");
      
      assert::are_equal(color::from_name("white"), c);
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
      
      assert::are_equal(0xFFFFFFFFU, c.to_argb());
      assert::are_equal(known_color::white, c.to_known_color());
    }
    
    void test_method_(create_from_name_white_smoke) {
      color c = color::from_name("white_smoke");
      
      assert::are_equal(color::from_name("white_smoke"), c);
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
      
      assert::are_equal(0xFFF5F5F5U, c.to_argb());
      assert::are_equal(known_color::white_smoke, c.to_known_color());
    }
    
    void test_method_(create_from_name_yellow) {
      color c = color::from_name("yellow");
      
      assert::are_equal(color::from_name("yellow"), c);
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
      
      assert::are_equal(0xFFFFFF00U, c.to_argb());
      assert::are_equal(known_color::yellow, c.to_known_color());
    }
  };
}
