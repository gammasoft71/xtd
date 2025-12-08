#include <xtd/drawing/known_color>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(known_color_tests) {
    auto test_method_(transparent) {
      assert::are_equal(1, enum_object<>::to_int32(known_color::transparent));
      assert::are_equal("transparent", enum_object<>::to_string(known_color::transparent));
      assert::are_equal(known_color::transparent, enum_object<>::parse<known_color>("transparent"));
    }
    
    auto test_method_(alice_blue) {
      assert::are_equal(2, enum_object<>::to_int32(known_color::alice_blue));
      assert::are_equal("alice_blue", enum_object<>::to_string(known_color::alice_blue));
      assert::are_equal(known_color::alice_blue, enum_object<>::parse<known_color>("alice_blue"));
    }
    
    auto test_method_(antique_white) {
      assert::are_equal(3, enum_object<>::to_int32(known_color::antique_white));
      assert::are_equal("antique_white", enum_object<>::to_string(known_color::antique_white));
      assert::are_equal(known_color::antique_white, enum_object<>::parse<known_color>("antique_white"));
    }
    
    auto test_method_(aqua) {
      assert::are_equal(4, enum_object<>::to_int32(known_color::aqua));
      assert::are_equal("aqua", enum_object<>::to_string(known_color::aqua));
      assert::are_equal(known_color::aqua, enum_object<>::parse<known_color>("aqua"));
    }
    
    auto test_method_(aquamarine) {
      assert::are_equal(5, enum_object<>::to_int32(known_color::aquamarine));
      assert::are_equal("aquamarine", enum_object<>::to_string(known_color::aquamarine));
      assert::are_equal(known_color::aquamarine, enum_object<>::parse<known_color>("aquamarine"));
    }
    
    auto test_method_(azure) {
      assert::are_equal(6, enum_object<>::to_int32(known_color::azure));
      assert::are_equal("azure", enum_object<>::to_string(known_color::azure));
      assert::are_equal(known_color::azure, enum_object<>::parse<known_color>("azure"));
    }
    
    auto test_method_(beige) {
      assert::are_equal(7, enum_object<>::to_int32(known_color::beige));
      assert::are_equal("beige", enum_object<>::to_string(known_color::beige));
      assert::are_equal(known_color::beige, enum_object<>::parse<known_color>("beige"));
    }
    
    auto test_method_(bisque) {
      assert::are_equal(8, enum_object<>::to_int32(known_color::bisque));
      assert::are_equal("bisque", enum_object<>::to_string(known_color::bisque));
      assert::are_equal(known_color::bisque, enum_object<>::parse<known_color>("bisque"));
    }
    
    auto test_method_(black) {
      assert::are_equal(9, enum_object<>::to_int32(known_color::black));
      assert::are_equal("black", enum_object<>::to_string(known_color::black));
      assert::are_equal(known_color::black, enum_object<>::parse<known_color>("black"));
    }
    
    auto test_method_(blanched_almond) {
      assert::are_equal(10, enum_object<>::to_int32(known_color::blanched_almond));
      assert::are_equal("blanched_almond", enum_object<>::to_string(known_color::blanched_almond));
      assert::are_equal(known_color::blanched_almond, enum_object<>::parse<known_color>("blanched_almond"));
    }
    
    auto test_method_(blue) {
      assert::are_equal(11, enum_object<>::to_int32(known_color::blue));
      assert::are_equal("blue", enum_object<>::to_string(known_color::blue));
      assert::are_equal(known_color::blue, enum_object<>::parse<known_color>("blue"));
    }
    
    auto test_method_(blue_violet) {
      assert::are_equal(12, enum_object<>::to_int32(known_color::blue_violet));
      assert::are_equal("blue_violet", enum_object<>::to_string(known_color::blue_violet));
      assert::are_equal(known_color::blue_violet, enum_object<>::parse<known_color>("blue_violet"));
    }
    
    auto test_method_(brown) {
      assert::are_equal(13, enum_object<>::to_int32(known_color::brown));
      assert::are_equal("brown", enum_object<>::to_string(known_color::brown));
      assert::are_equal(known_color::brown, enum_object<>::parse<known_color>("brown"));
    }
    
    auto test_method_(burly_wood) {
      assert::are_equal(14, enum_object<>::to_int32(known_color::burly_wood));
      assert::are_equal("burly_wood", enum_object<>::to_string(known_color::burly_wood));
      assert::are_equal(known_color::burly_wood, enum_object<>::parse<known_color>("burly_wood"));
    }
    
    auto test_method_(cadet_blue) {
      assert::are_equal(15, enum_object<>::to_int32(known_color::cadet_blue));
      assert::are_equal("cadet_blue", enum_object<>::to_string(known_color::cadet_blue));
      assert::are_equal(known_color::cadet_blue, enum_object<>::parse<known_color>("cadet_blue"));
    }
    
    auto test_method_(chartreuse) {
      assert::are_equal(16, enum_object<>::to_int32(known_color::chartreuse));
      assert::are_equal("chartreuse", enum_object<>::to_string(known_color::chartreuse));
      assert::are_equal(known_color::chartreuse, enum_object<>::parse<known_color>("chartreuse"));
    }
    
    auto test_method_(chocolate) {
      assert::are_equal(17, enum_object<>::to_int32(known_color::chocolate));
      assert::are_equal("chocolate", enum_object<>::to_string(known_color::chocolate));
      assert::are_equal(known_color::chocolate, enum_object<>::parse<known_color>("chocolate"));
    }
    
    auto test_method_(coral) {
      assert::are_equal(18, enum_object<>::to_int32(known_color::coral));
      assert::are_equal("coral", enum_object<>::to_string(known_color::coral));
      assert::are_equal(known_color::coral, enum_object<>::parse<known_color>("coral"));
    }
    
    auto test_method_(cornflower_blue) {
      assert::are_equal(19, enum_object<>::to_int32(known_color::cornflower_blue));
      assert::are_equal("cornflower_blue", enum_object<>::to_string(known_color::cornflower_blue));
      assert::are_equal(known_color::cornflower_blue, enum_object<>::parse<known_color>("cornflower_blue"));
    }
    
    auto test_method_(cornsilk) {
      assert::are_equal(20, enum_object<>::to_int32(known_color::cornsilk));
      assert::are_equal("cornsilk", enum_object<>::to_string(known_color::cornsilk));
      assert::are_equal(known_color::cornsilk, enum_object<>::parse<known_color>("cornsilk"));
    }
    
    auto test_method_(crimson) {
      assert::are_equal(21, enum_object<>::to_int32(known_color::crimson));
      assert::are_equal("crimson", enum_object<>::to_string(known_color::crimson));
      assert::are_equal(known_color::crimson, enum_object<>::parse<known_color>("crimson"));
    }
    
    auto test_method_(cyan) {
      assert::are_equal(22, enum_object<>::to_int32(known_color::cyan));
      assert::are_equal("cyan", enum_object<>::to_string(known_color::cyan));
      assert::are_equal(known_color::cyan, enum_object<>::parse<known_color>("cyan"));
    }
    
    auto test_method_(dark_blue) {
      assert::are_equal(23, enum_object<>::to_int32(known_color::dark_blue));
      assert::are_equal("dark_blue", enum_object<>::to_string(known_color::dark_blue));
      assert::are_equal(known_color::dark_blue, enum_object<>::parse<known_color>("dark_blue"));
    }
    
    auto test_method_(dark_cyan) {
      assert::are_equal(24, enum_object<>::to_int32(known_color::dark_cyan));
      assert::are_equal("dark_cyan", enum_object<>::to_string(known_color::dark_cyan));
      assert::are_equal(known_color::dark_cyan, enum_object<>::parse<known_color>("dark_cyan"));
    }
    
    auto test_method_(dark_goldenrod) {
      assert::are_equal(25, enum_object<>::to_int32(known_color::dark_goldenrod));
      assert::are_equal("dark_goldenrod", enum_object<>::to_string(known_color::dark_goldenrod));
      assert::are_equal(known_color::dark_goldenrod, enum_object<>::parse<known_color>("dark_goldenrod"));
    }
    
    auto test_method_(dark_gray) {
      assert::are_equal(26, enum_object<>::to_int32(known_color::dark_gray));
      assert::are_equal("dark_gray", enum_object<>::to_string(known_color::dark_gray));
      assert::are_equal(known_color::dark_gray, enum_object<>::parse<known_color>("dark_gray"));
    }
    
    auto test_method_(dark_green) {
      assert::are_equal(27, enum_object<>::to_int32(known_color::dark_green));
      assert::are_equal("dark_green", enum_object<>::to_string(known_color::dark_green));
      assert::are_equal(known_color::dark_green, enum_object<>::parse<known_color>("dark_green"));
    }
    
    auto test_method_(dark_khaki) {
      assert::are_equal(28, enum_object<>::to_int32(known_color::dark_khaki));
      assert::are_equal("dark_khaki", enum_object<>::to_string(known_color::dark_khaki));
      assert::are_equal(known_color::dark_khaki, enum_object<>::parse<known_color>("dark_khaki"));
    }
    
    auto test_method_(dark_magenta) {
      assert::are_equal(29, enum_object<>::to_int32(known_color::dark_magenta));
      assert::are_equal("dark_magenta", enum_object<>::to_string(known_color::dark_magenta));
      assert::are_equal(known_color::dark_magenta, enum_object<>::parse<known_color>("dark_magenta"));
    }
    
    auto test_method_(dark_olive_green) {
      assert::are_equal(30, enum_object<>::to_int32(known_color::dark_olive_green));
      assert::are_equal("dark_olive_green", enum_object<>::to_string(known_color::dark_olive_green));
      assert::are_equal(known_color::dark_olive_green, enum_object<>::parse<known_color>("dark_olive_green"));
    }
    
    auto test_method_(dark_orange) {
      assert::are_equal(31, enum_object<>::to_int32(known_color::dark_orange));
      assert::are_equal("dark_orange", enum_object<>::to_string(known_color::dark_orange));
      assert::are_equal(known_color::dark_orange, enum_object<>::parse<known_color>("dark_orange"));
    }
    
    auto test_method_(dark_orchid) {
      assert::are_equal(32, enum_object<>::to_int32(known_color::dark_orchid));
      assert::are_equal("dark_orchid", enum_object<>::to_string(known_color::dark_orchid));
      assert::are_equal(known_color::dark_orchid, enum_object<>::parse<known_color>("dark_orchid"));
    }
    
    auto test_method_(dark_red) {
      assert::are_equal(33, enum_object<>::to_int32(known_color::dark_red));
      assert::are_equal("dark_red", enum_object<>::to_string(known_color::dark_red));
      assert::are_equal(known_color::dark_red, enum_object<>::parse<known_color>("dark_red"));
    }
    
    auto test_method_(dark_salmon) {
      assert::are_equal(34, enum_object<>::to_int32(known_color::dark_salmon));
      assert::are_equal("dark_salmon", enum_object<>::to_string(known_color::dark_salmon));
      assert::are_equal(known_color::dark_salmon, enum_object<>::parse<known_color>("dark_salmon"));
    }
    
    auto test_method_(dark_sea_green) {
      assert::are_equal(35, enum_object<>::to_int32(known_color::dark_sea_green));
      assert::are_equal("dark_sea_green", enum_object<>::to_string(known_color::dark_sea_green));
      assert::are_equal(known_color::dark_sea_green, enum_object<>::parse<known_color>("dark_sea_green"));
    }
    
    auto test_method_(dark_slate_blue) {
      assert::are_equal(36, enum_object<>::to_int32(known_color::dark_slate_blue));
      assert::are_equal("dark_slate_blue", enum_object<>::to_string(known_color::dark_slate_blue));
      assert::are_equal(known_color::dark_slate_blue, enum_object<>::parse<known_color>("dark_slate_blue"));
    }
    
    auto test_method_(dark_slate_gray) {
      assert::are_equal(37, enum_object<>::to_int32(known_color::dark_slate_gray));
      assert::are_equal("dark_slate_gray", enum_object<>::to_string(known_color::dark_slate_gray));
      assert::are_equal(known_color::dark_slate_gray, enum_object<>::parse<known_color>("dark_slate_gray"));
    }
    
    auto test_method_(dark_turquoise) {
      assert::are_equal(38, enum_object<>::to_int32(known_color::dark_turquoise));
      assert::are_equal("dark_turquoise", enum_object<>::to_string(known_color::dark_turquoise));
      assert::are_equal(known_color::dark_turquoise, enum_object<>::parse<known_color>("dark_turquoise"));
    }
    
    auto test_method_(dark_violet) {
      assert::are_equal(39, enum_object<>::to_int32(known_color::dark_violet));
      assert::are_equal("dark_violet", enum_object<>::to_string(known_color::dark_violet));
      assert::are_equal(known_color::dark_violet, enum_object<>::parse<known_color>("dark_violet"));
    }
    
    auto test_method_(deep_pink) {
      assert::are_equal(40, enum_object<>::to_int32(known_color::deep_pink));
      assert::are_equal("deep_pink", enum_object<>::to_string(known_color::deep_pink));
      assert::are_equal(known_color::deep_pink, enum_object<>::parse<known_color>("deep_pink"));
    }
    
    auto test_method_(deep_sky_blue) {
      assert::are_equal(41, enum_object<>::to_int32(known_color::deep_sky_blue));
      assert::are_equal("deep_sky_blue", enum_object<>::to_string(known_color::deep_sky_blue));
      assert::are_equal(known_color::deep_sky_blue, enum_object<>::parse<known_color>("deep_sky_blue"));
    }
    
    auto test_method_(dim_gray) {
      assert::are_equal(42, enum_object<>::to_int32(known_color::dim_gray));
      assert::are_equal("dim_gray", enum_object<>::to_string(known_color::dim_gray));
      assert::are_equal(known_color::dim_gray, enum_object<>::parse<known_color>("dim_gray"));
    }
    
    auto test_method_(dodger_blue) {
      assert::are_equal(43, enum_object<>::to_int32(known_color::dodger_blue));
      assert::are_equal("dodger_blue", enum_object<>::to_string(known_color::dodger_blue));
      assert::are_equal(known_color::dodger_blue, enum_object<>::parse<known_color>("dodger_blue"));
    }
    
    auto test_method_(firebrick) {
      assert::are_equal(44, enum_object<>::to_int32(known_color::firebrick));
      assert::are_equal("firebrick", enum_object<>::to_string(known_color::firebrick));
      assert::are_equal(known_color::firebrick, enum_object<>::parse<known_color>("firebrick"));
    }
    
    auto test_method_(floral_white) {
      assert::are_equal(45, enum_object<>::to_int32(known_color::floral_white));
      assert::are_equal("floral_white", enum_object<>::to_string(known_color::floral_white));
      assert::are_equal(known_color::floral_white, enum_object<>::parse<known_color>("floral_white"));
    }
    
    auto test_method_(forest_green) {
      assert::are_equal(46, enum_object<>::to_int32(known_color::forest_green));
      assert::are_equal("forest_green", enum_object<>::to_string(known_color::forest_green));
      assert::are_equal(known_color::forest_green, enum_object<>::parse<known_color>("forest_green"));
    }
    
    auto test_method_(fuchsia) {
      assert::are_equal(47, enum_object<>::to_int32(known_color::fuchsia));
      assert::are_equal("fuchsia", enum_object<>::to_string(known_color::fuchsia));
      assert::are_equal(known_color::fuchsia, enum_object<>::parse<known_color>("fuchsia"));
    }
    
    auto test_method_(gainsboro) {
      assert::are_equal(48, enum_object<>::to_int32(known_color::gainsboro));
      assert::are_equal("gainsboro", enum_object<>::to_string(known_color::gainsboro));
      assert::are_equal(known_color::gainsboro, enum_object<>::parse<known_color>("gainsboro"));
    }
    
    auto test_method_(ghost_white) {
      assert::are_equal(49, enum_object<>::to_int32(known_color::ghost_white));
      assert::are_equal("ghost_white", enum_object<>::to_string(known_color::ghost_white));
      assert::are_equal(known_color::ghost_white, enum_object<>::parse<known_color>("ghost_white"));
    }
    
    auto test_method_(gold) {
      assert::are_equal(50, enum_object<>::to_int32(known_color::gold));
      assert::are_equal("gold", enum_object<>::to_string(known_color::gold));
      assert::are_equal(known_color::gold, enum_object<>::parse<known_color>("gold"));
    }
    
    auto test_method_(goldenrod) {
      assert::are_equal(51, enum_object<>::to_int32(known_color::goldenrod));
      assert::are_equal("goldenrod", enum_object<>::to_string(known_color::goldenrod));
      assert::are_equal(known_color::goldenrod, enum_object<>::parse<known_color>("goldenrod"));
    }
    
    auto test_method_(gray) {
      assert::are_equal(52, enum_object<>::to_int32(known_color::gray));
      assert::are_equal("gray", enum_object<>::to_string(known_color::gray));
      assert::are_equal(known_color::gray, enum_object<>::parse<known_color>("gray"));
    }
    
    auto test_method_(green) {
      assert::are_equal(53, enum_object<>::to_int32(known_color::green));
      assert::are_equal("green", enum_object<>::to_string(known_color::green));
      assert::are_equal(known_color::green, enum_object<>::parse<known_color>("green"));
    }
    
    auto test_method_(green_yellow) {
      assert::are_equal(54, enum_object<>::to_int32(known_color::green_yellow));
      assert::are_equal("green_yellow", enum_object<>::to_string(known_color::green_yellow));
      assert::are_equal(known_color::green_yellow, enum_object<>::parse<known_color>("green_yellow"));
    }
    
    auto test_method_(honeydew) {
      assert::are_equal(55, enum_object<>::to_int32(known_color::honeydew));
      assert::are_equal("honeydew", enum_object<>::to_string(known_color::honeydew));
      assert::are_equal(known_color::honeydew, enum_object<>::parse<known_color>("honeydew"));
    }
    
    auto test_method_(hot_pink) {
      assert::are_equal(56, enum_object<>::to_int32(known_color::hot_pink));
      assert::are_equal("hot_pink", enum_object<>::to_string(known_color::hot_pink));
      assert::are_equal(known_color::hot_pink, enum_object<>::parse<known_color>("hot_pink"));
    }
    
    auto test_method_(indian_red) {
      assert::are_equal(57, enum_object<>::to_int32(known_color::indian_red));
      assert::are_equal("indian_red", enum_object<>::to_string(known_color::indian_red));
      assert::are_equal(known_color::indian_red, enum_object<>::parse<known_color>("indian_red"));
    }
    
    auto test_method_(indigo) {
      assert::are_equal(58, enum_object<>::to_int32(known_color::indigo));
      assert::are_equal("indigo", enum_object<>::to_string(known_color::indigo));
      assert::are_equal(known_color::indigo, enum_object<>::parse<known_color>("indigo"));
    }
    
    auto test_method_(ivory) {
      assert::are_equal(59, enum_object<>::to_int32(known_color::ivory));
      assert::are_equal("ivory", enum_object<>::to_string(known_color::ivory));
      assert::are_equal(known_color::ivory, enum_object<>::parse<known_color>("ivory"));
    }
    
    auto test_method_(khaki) {
      assert::are_equal(60, enum_object<>::to_int32(known_color::khaki));
      assert::are_equal("khaki", enum_object<>::to_string(known_color::khaki));
      assert::are_equal(known_color::khaki, enum_object<>::parse<known_color>("khaki"));
    }
    
    auto test_method_(lavender) {
      assert::are_equal(61, enum_object<>::to_int32(known_color::lavender));
      assert::are_equal("lavender", enum_object<>::to_string(known_color::lavender));
      assert::are_equal(known_color::lavender, enum_object<>::parse<known_color>("lavender"));
    }
    
    auto test_method_(lavender_blush) {
      assert::are_equal(62, enum_object<>::to_int32(known_color::lavender_blush));
      assert::are_equal("lavender_blush", enum_object<>::to_string(known_color::lavender_blush));
      assert::are_equal(known_color::lavender_blush, enum_object<>::parse<known_color>("lavender_blush"));
    }
    
    auto test_method_(lawn_green) {
      assert::are_equal(63, enum_object<>::to_int32(known_color::lawn_green));
      assert::are_equal("lawn_green", enum_object<>::to_string(known_color::lawn_green));
      assert::are_equal(known_color::lawn_green, enum_object<>::parse<known_color>("lawn_green"));
    }
    
    auto test_method_(lemon_chiffon) {
      assert::are_equal(64, enum_object<>::to_int32(known_color::lemon_chiffon));
      assert::are_equal("lemon_chiffon", enum_object<>::to_string(known_color::lemon_chiffon));
      assert::are_equal(known_color::lemon_chiffon, enum_object<>::parse<known_color>("lemon_chiffon"));
    }
    
    auto test_method_(light_blue) {
      assert::are_equal(65, enum_object<>::to_int32(known_color::light_blue));
      assert::are_equal("light_blue", enum_object<>::to_string(known_color::light_blue));
      assert::are_equal(known_color::light_blue, enum_object<>::parse<known_color>("light_blue"));
    }
    
    auto test_method_(light_coral) {
      assert::are_equal(66, enum_object<>::to_int32(known_color::light_coral));
      assert::are_equal("light_coral", enum_object<>::to_string(known_color::light_coral));
      assert::are_equal(known_color::light_coral, enum_object<>::parse<known_color>("light_coral"));
    }
    
    auto test_method_(light_cyan) {
      assert::are_equal(67, enum_object<>::to_int32(known_color::light_cyan));
      assert::are_equal("light_cyan", enum_object<>::to_string(known_color::light_cyan));
      assert::are_equal(known_color::light_cyan, enum_object<>::parse<known_color>("light_cyan"));
    }
    
    auto test_method_(light_goldenrod_yellow) {
      assert::are_equal(68, enum_object<>::to_int32(known_color::light_goldenrod_yellow));
      assert::are_equal("light_goldenrod_yellow", enum_object<>::to_string(known_color::light_goldenrod_yellow));
      assert::are_equal(known_color::light_goldenrod_yellow, enum_object<>::parse<known_color>("light_goldenrod_yellow"));
    }
    
    auto test_method_(light_gray) {
      assert::are_equal(69, enum_object<>::to_int32(known_color::light_gray));
      assert::are_equal("light_gray", enum_object<>::to_string(known_color::light_gray));
      assert::are_equal(known_color::light_gray, enum_object<>::parse<known_color>("light_gray"));
    }
    
    auto test_method_(light_green) {
      assert::are_equal(70, enum_object<>::to_int32(known_color::light_green));
      assert::are_equal("light_green", enum_object<>::to_string(known_color::light_green));
      assert::are_equal(known_color::light_green, enum_object<>::parse<known_color>("light_green"));
    }
    
    auto test_method_(light_pink) {
      assert::are_equal(71, enum_object<>::to_int32(known_color::light_pink));
      assert::are_equal("light_pink", enum_object<>::to_string(known_color::light_pink));
      assert::are_equal(known_color::light_pink, enum_object<>::parse<known_color>("light_pink"));
    }
    
    auto test_method_(light_salmon) {
      assert::are_equal(72, enum_object<>::to_int32(known_color::light_salmon));
      assert::are_equal("light_salmon", enum_object<>::to_string(known_color::light_salmon));
      assert::are_equal(known_color::light_salmon, enum_object<>::parse<known_color>("light_salmon"));
    }
    
    auto test_method_(light_sea_green) {
      assert::are_equal(73, enum_object<>::to_int32(known_color::light_sea_green));
      assert::are_equal("light_sea_green", enum_object<>::to_string(known_color::light_sea_green));
      assert::are_equal(known_color::light_sea_green, enum_object<>::parse<known_color>("light_sea_green"));
    }
    
    auto test_method_(light_sky_blue) {
      assert::are_equal(74, enum_object<>::to_int32(known_color::light_sky_blue));
      assert::are_equal("light_sky_blue", enum_object<>::to_string(known_color::light_sky_blue));
      assert::are_equal(known_color::light_sky_blue, enum_object<>::parse<known_color>("light_sky_blue"));
    }
    
    auto test_method_(light_slate_gray) {
      assert::are_equal(75, enum_object<>::to_int32(known_color::light_slate_gray));
      assert::are_equal("light_slate_gray", enum_object<>::to_string(known_color::light_slate_gray));
      assert::are_equal(known_color::light_slate_gray, enum_object<>::parse<known_color>("light_slate_gray"));
    }
    
    auto test_method_(light_steel_blue) {
      assert::are_equal(76, enum_object<>::to_int32(known_color::light_steel_blue));
      assert::are_equal("light_steel_blue", enum_object<>::to_string(known_color::light_steel_blue));
      assert::are_equal(known_color::light_steel_blue, enum_object<>::parse<known_color>("light_steel_blue"));
    }
    
    auto test_method_(light_yellow) {
      assert::are_equal(77, enum_object<>::to_int32(known_color::light_yellow));
      assert::are_equal("light_yellow", enum_object<>::to_string(known_color::light_yellow));
      assert::are_equal(known_color::light_yellow, enum_object<>::parse<known_color>("light_yellow"));
    }
    
    auto test_method_(lime) {
      assert::are_equal(78, enum_object<>::to_int32(known_color::lime));
      assert::are_equal("lime", enum_object<>::to_string(known_color::lime));
      assert::are_equal(known_color::lime, enum_object<>::parse<known_color>("lime"));
    }
    
    auto test_method_(lime_green) {
      assert::are_equal(79, enum_object<>::to_int32(known_color::lime_green));
      assert::are_equal("lime_green", enum_object<>::to_string(known_color::lime_green));
      assert::are_equal(known_color::lime_green, enum_object<>::parse<known_color>("lime_green"));
    }
    
    auto test_method_(linen) {
      assert::are_equal(80, enum_object<>::to_int32(known_color::linen));
      assert::are_equal("linen", enum_object<>::to_string(known_color::linen));
      assert::are_equal(known_color::linen, enum_object<>::parse<known_color>("linen"));
    }
    
    auto test_method_(magenta) {
      assert::are_equal(81, enum_object<>::to_int32(known_color::magenta));
      assert::are_equal("magenta", enum_object<>::to_string(known_color::magenta));
      assert::are_equal(known_color::magenta, enum_object<>::parse<known_color>("magenta"));
    }
    
    auto test_method_(maroon) {
      assert::are_equal(82, enum_object<>::to_int32(known_color::maroon));
      assert::are_equal("maroon", enum_object<>::to_string(known_color::maroon));
      assert::are_equal(known_color::maroon, enum_object<>::parse<known_color>("maroon"));
    }
    
    auto test_method_(medium_aquamarine) {
      assert::are_equal(83, enum_object<>::to_int32(known_color::medium_aquamarine));
      assert::are_equal("medium_aquamarine", enum_object<>::to_string(known_color::medium_aquamarine));
      assert::are_equal(known_color::medium_aquamarine, enum_object<>::parse<known_color>("medium_aquamarine"));
    }
    
    auto test_method_(medium_blue) {
      assert::are_equal(84, enum_object<>::to_int32(known_color::medium_blue));
      assert::are_equal("medium_blue", enum_object<>::to_string(known_color::medium_blue));
      assert::are_equal(known_color::medium_blue, enum_object<>::parse<known_color>("medium_blue"));
    }
    
    auto test_method_(medium_orchid) {
      assert::are_equal(85, enum_object<>::to_int32(known_color::medium_orchid));
      assert::are_equal("medium_orchid", enum_object<>::to_string(known_color::medium_orchid));
      assert::are_equal(known_color::medium_orchid, enum_object<>::parse<known_color>("medium_orchid"));
    }
    
    auto test_method_(medium_purple) {
      assert::are_equal(86, enum_object<>::to_int32(known_color::medium_purple));
      assert::are_equal("medium_purple", enum_object<>::to_string(known_color::medium_purple));
      assert::are_equal(known_color::medium_purple, enum_object<>::parse<known_color>("medium_purple"));
    }
    
    auto test_method_(medium_sea_green) {
      assert::are_equal(87, enum_object<>::to_int32(known_color::medium_sea_green));
      assert::are_equal("medium_sea_green", enum_object<>::to_string(known_color::medium_sea_green));
      assert::are_equal(known_color::medium_sea_green, enum_object<>::parse<known_color>("medium_sea_green"));
    }
    
    auto test_method_(medium_slate_blue) {
      assert::are_equal(88, enum_object<>::to_int32(known_color::medium_slate_blue));
      assert::are_equal("medium_slate_blue", enum_object<>::to_string(known_color::medium_slate_blue));
      assert::are_equal(known_color::medium_slate_blue, enum_object<>::parse<known_color>("medium_slate_blue"));
    }
    
    auto test_method_(medium_spring_green) {
      assert::are_equal(89, enum_object<>::to_int32(known_color::medium_spring_green));
      assert::are_equal("medium_spring_green", enum_object<>::to_string(known_color::medium_spring_green));
      assert::are_equal(known_color::medium_spring_green, enum_object<>::parse<known_color>("medium_spring_green"));
    }
    
    auto test_method_(medium_turquoise) {
      assert::are_equal(90, enum_object<>::to_int32(known_color::medium_turquoise));
      assert::are_equal("medium_turquoise", enum_object<>::to_string(known_color::medium_turquoise));
      assert::are_equal(known_color::medium_turquoise, enum_object<>::parse<known_color>("medium_turquoise"));
    }
    
    auto test_method_(medium_violet_red) {
      assert::are_equal(91, enum_object<>::to_int32(known_color::medium_violet_red));
      assert::are_equal("medium_violet_red", enum_object<>::to_string(known_color::medium_violet_red));
      assert::are_equal(known_color::medium_violet_red, enum_object<>::parse<known_color>("medium_violet_red"));
    }
    
    auto test_method_(midnight_blue) {
      assert::are_equal(92, enum_object<>::to_int32(known_color::midnight_blue));
      assert::are_equal("midnight_blue", enum_object<>::to_string(known_color::midnight_blue));
      assert::are_equal(known_color::midnight_blue, enum_object<>::parse<known_color>("midnight_blue"));
    }
    
    auto test_method_(mint_cream) {
      assert::are_equal(93, enum_object<>::to_int32(known_color::mint_cream));
      assert::are_equal("mint_cream", enum_object<>::to_string(known_color::mint_cream));
      assert::are_equal(known_color::mint_cream, enum_object<>::parse<known_color>("mint_cream"));
    }
    
    auto test_method_(misty_rose) {
      assert::are_equal(94, enum_object<>::to_int32(known_color::misty_rose));
      assert::are_equal("misty_rose", enum_object<>::to_string(known_color::misty_rose));
      assert::are_equal(known_color::misty_rose, enum_object<>::parse<known_color>("misty_rose"));
    }
    
    auto test_method_(moccasin) {
      assert::are_equal(95, enum_object<>::to_int32(known_color::moccasin));
      assert::are_equal("moccasin", enum_object<>::to_string(known_color::moccasin));
      assert::are_equal(known_color::moccasin, enum_object<>::parse<known_color>("moccasin"));
    }
    
    auto test_method_(navajo_white) {
      assert::are_equal(96, enum_object<>::to_int32(known_color::navajo_white));
      assert::are_equal("navajo_white", enum_object<>::to_string(known_color::navajo_white));
      assert::are_equal(known_color::navajo_white, enum_object<>::parse<known_color>("navajo_white"));
    }
    
    auto test_method_(navy) {
      assert::are_equal(97, enum_object<>::to_int32(known_color::navy));
      assert::are_equal("navy", enum_object<>::to_string(known_color::navy));
      assert::are_equal(known_color::navy, enum_object<>::parse<known_color>("navy"));
    }
    
    auto test_method_(old_lace) {
      assert::are_equal(98, enum_object<>::to_int32(known_color::old_lace));
      assert::are_equal("old_lace", enum_object<>::to_string(known_color::old_lace));
      assert::are_equal(known_color::old_lace, enum_object<>::parse<known_color>("old_lace"));
    }
    
    auto test_method_(olive) {
      assert::are_equal(99, enum_object<>::to_int32(known_color::olive));
      assert::are_equal("olive", enum_object<>::to_string(known_color::olive));
      assert::are_equal(known_color::olive, enum_object<>::parse<known_color>("olive"));
    }
    
    auto test_method_(olive_drab) {
      assert::are_equal(100, enum_object<>::to_int32(known_color::olive_drab));
      assert::are_equal("olive_drab", enum_object<>::to_string(known_color::olive_drab));
      assert::are_equal(known_color::olive_drab, enum_object<>::parse<known_color>("olive_drab"));
    }
    
    auto test_method_(orange) {
      assert::are_equal(101, enum_object<>::to_int32(known_color::orange));
      assert::are_equal("orange", enum_object<>::to_string(known_color::orange));
      assert::are_equal(known_color::orange, enum_object<>::parse<known_color>("orange"));
    }
    
    auto test_method_(orange_red) {
      assert::are_equal(102, enum_object<>::to_int32(known_color::orange_red));
      assert::are_equal("orange_red", enum_object<>::to_string(known_color::orange_red));
      assert::are_equal(known_color::orange_red, enum_object<>::parse<known_color>("orange_red"));
    }
    
    auto test_method_(orchid) {
      assert::are_equal(103, enum_object<>::to_int32(known_color::orchid));
      assert::are_equal("orchid", enum_object<>::to_string(known_color::orchid));
      assert::are_equal(known_color::orchid, enum_object<>::parse<known_color>("orchid"));
    }
    
    auto test_method_(pale_goldenrod) {
      assert::are_equal(104, enum_object<>::to_int32(known_color::pale_goldenrod));
      assert::are_equal("pale_goldenrod", enum_object<>::to_string(known_color::pale_goldenrod));
      assert::are_equal(known_color::pale_goldenrod, enum_object<>::parse<known_color>("pale_goldenrod"));
    }
    
    auto test_method_(pale_green) {
      assert::are_equal(105, enum_object<>::to_int32(known_color::pale_green));
      assert::are_equal("pale_green", enum_object<>::to_string(known_color::pale_green));
      assert::are_equal(known_color::pale_green, enum_object<>::parse<known_color>("pale_green"));
    }
    
    auto test_method_(pale_turquoise) {
      assert::are_equal(106, enum_object<>::to_int32(known_color::pale_turquoise));
      assert::are_equal("pale_turquoise", enum_object<>::to_string(known_color::pale_turquoise));
      assert::are_equal(known_color::pale_turquoise, enum_object<>::parse<known_color>("pale_turquoise"));
    }
    
    auto test_method_(pale_violet_red) {
      assert::are_equal(107, enum_object<>::to_int32(known_color::pale_violet_red));
      assert::are_equal("pale_violet_red", enum_object<>::to_string(known_color::pale_violet_red));
      assert::are_equal(known_color::pale_violet_red, enum_object<>::parse<known_color>("pale_violet_red"));
    }
    
    auto test_method_(papaya_whip) {
      assert::are_equal(108, enum_object<>::to_int32(known_color::papaya_whip));
      assert::are_equal("papaya_whip", enum_object<>::to_string(known_color::papaya_whip));
      assert::are_equal(known_color::papaya_whip, enum_object<>::parse<known_color>("papaya_whip"));
    }
    
    auto test_method_(peach_puff) {
      assert::are_equal(109, enum_object<>::to_int32(known_color::peach_puff));
      assert::are_equal("peach_puff", enum_object<>::to_string(known_color::peach_puff));
      assert::are_equal(known_color::peach_puff, enum_object<>::parse<known_color>("peach_puff"));
    }
    
    auto test_method_(peru) {
      assert::are_equal(110, enum_object<>::to_int32(known_color::peru));
      assert::are_equal("peru", enum_object<>::to_string(known_color::peru));
      assert::are_equal(known_color::peru, enum_object<>::parse<known_color>("peru"));
    }
    
    auto test_method_(pink) {
      assert::are_equal(111, enum_object<>::to_int32(known_color::pink));
      assert::are_equal("pink", enum_object<>::to_string(known_color::pink));
      assert::are_equal(known_color::pink, enum_object<>::parse<known_color>("pink"));
    }
    
    auto test_method_(plum) {
      assert::are_equal(112, enum_object<>::to_int32(known_color::plum));
      assert::are_equal("plum", enum_object<>::to_string(known_color::plum));
      assert::are_equal(known_color::plum, enum_object<>::parse<known_color>("plum"));
    }
    
    auto test_method_(powder_blue) {
      assert::are_equal(113, enum_object<>::to_int32(known_color::powder_blue));
      assert::are_equal("powder_blue", enum_object<>::to_string(known_color::powder_blue));
      assert::are_equal(known_color::powder_blue, enum_object<>::parse<known_color>("powder_blue"));
    }
    
    auto test_method_(purple) {
      assert::are_equal(114, enum_object<>::to_int32(known_color::purple));
      assert::are_equal("purple", enum_object<>::to_string(known_color::purple));
      assert::are_equal(known_color::purple, enum_object<>::parse<known_color>("purple"));
    }
    
    auto test_method_(rebecca_purple) {
      assert::are_equal(115, enum_object<>::to_int32(known_color::rebecca_purple));
      assert::are_equal("rebecca_purple", enum_object<>::to_string(known_color::rebecca_purple));
      assert::are_equal(known_color::rebecca_purple, enum_object<>::parse<known_color>("rebecca_purple"));
    }
    
    auto test_method_(red) {
      assert::are_equal(116, enum_object<>::to_int32(known_color::red));
      assert::are_equal("red", enum_object<>::to_string(known_color::red));
      assert::are_equal(known_color::red, enum_object<>::parse<known_color>("red"));
    }
    
    auto test_method_(rosy_brown) {
      assert::are_equal(117, enum_object<>::to_int32(known_color::rosy_brown));
      assert::are_equal("rosy_brown", enum_object<>::to_string(known_color::rosy_brown));
      assert::are_equal(known_color::rosy_brown, enum_object<>::parse<known_color>("rosy_brown"));
    }
    
    auto test_method_(royal_blue) {
      assert::are_equal(118, enum_object<>::to_int32(known_color::royal_blue));
      assert::are_equal("royal_blue", enum_object<>::to_string(known_color::royal_blue));
      assert::are_equal(known_color::royal_blue, enum_object<>::parse<known_color>("royal_blue"));
    }
    
    auto test_method_(saddle_brown) {
      assert::are_equal(119, enum_object<>::to_int32(known_color::saddle_brown));
      assert::are_equal("saddle_brown", enum_object<>::to_string(known_color::saddle_brown));
      assert::are_equal(known_color::saddle_brown, enum_object<>::parse<known_color>("saddle_brown"));
    }
    
    auto test_method_(salmon) {
      assert::are_equal(120, enum_object<>::to_int32(known_color::salmon));
      assert::are_equal("salmon", enum_object<>::to_string(known_color::salmon));
      assert::are_equal(known_color::salmon, enum_object<>::parse<known_color>("salmon"));
    }
    
    auto test_method_(sandy_brown) {
      assert::are_equal(121, enum_object<>::to_int32(known_color::sandy_brown));
      assert::are_equal("sandy_brown", enum_object<>::to_string(known_color::sandy_brown));
      assert::are_equal(known_color::sandy_brown, enum_object<>::parse<known_color>("sandy_brown"));
    }
    
    auto test_method_(sea_green) {
      assert::are_equal(122, enum_object<>::to_int32(known_color::sea_green));
      assert::are_equal("sea_green", enum_object<>::to_string(known_color::sea_green));
      assert::are_equal(known_color::sea_green, enum_object<>::parse<known_color>("sea_green"));
    }
    
    auto test_method_(sea_shell) {
      assert::are_equal(123, enum_object<>::to_int32(known_color::sea_shell));
      assert::are_equal("sea_shell", enum_object<>::to_string(known_color::sea_shell));
      assert::are_equal(known_color::sea_shell, enum_object<>::parse<known_color>("sea_shell"));
    }
    
    auto test_method_(sienna) {
      assert::are_equal(124, enum_object<>::to_int32(known_color::sienna));
      assert::are_equal("sienna", enum_object<>::to_string(known_color::sienna));
      assert::are_equal(known_color::sienna, enum_object<>::parse<known_color>("sienna"));
    }
    
    auto test_method_(silver) {
      assert::are_equal(125, enum_object<>::to_int32(known_color::silver));
      assert::are_equal("silver", enum_object<>::to_string(known_color::silver));
      assert::are_equal(known_color::silver, enum_object<>::parse<known_color>("silver"));
    }
    
    auto test_method_(sky_blue) {
      assert::are_equal(126, enum_object<>::to_int32(known_color::sky_blue));
      assert::are_equal("sky_blue", enum_object<>::to_string(known_color::sky_blue));
      assert::are_equal(known_color::sky_blue, enum_object<>::parse<known_color>("sky_blue"));
    }
    
    auto test_method_(slate_blue) {
      assert::are_equal(127, enum_object<>::to_int32(known_color::slate_blue));
      assert::are_equal("slate_blue", enum_object<>::to_string(known_color::slate_blue));
      assert::are_equal(known_color::slate_blue, enum_object<>::parse<known_color>("slate_blue"));
    }
    
    auto test_method_(slate_gray) {
      assert::are_equal(128, enum_object<>::to_int32(known_color::slate_gray));
      assert::are_equal("slate_gray", enum_object<>::to_string(known_color::slate_gray));
      assert::are_equal(known_color::slate_gray, enum_object<>::parse<known_color>("slate_gray"));
    }
    
    auto test_method_(snow) {
      assert::are_equal(129, enum_object<>::to_int32(known_color::snow));
      assert::are_equal("snow", enum_object<>::to_string(known_color::snow));
      assert::are_equal(known_color::snow, enum_object<>::parse<known_color>("snow"));
    }
    
    auto test_method_(spring_green) {
      assert::are_equal(130, enum_object<>::to_int32(known_color::spring_green));
      assert::are_equal("spring_green", enum_object<>::to_string(known_color::spring_green));
      assert::are_equal(known_color::spring_green, enum_object<>::parse<known_color>("spring_green"));
    }
    
    auto test_method_(steel_blue) {
      assert::are_equal(131, enum_object<>::to_int32(known_color::steel_blue));
      assert::are_equal("steel_blue", enum_object<>::to_string(known_color::steel_blue));
      assert::are_equal(known_color::steel_blue, enum_object<>::parse<known_color>("steel_blue"));
    }
    
    auto test_method_(tan) {
      assert::are_equal(132, enum_object<>::to_int32(known_color::tan));
      assert::are_equal("tan", enum_object<>::to_string(known_color::tan));
      assert::are_equal(known_color::tan, enum_object<>::parse<known_color>("tan"));
    }
    
    auto test_method_(teal) {
      assert::are_equal(133, enum_object<>::to_int32(known_color::teal));
      assert::are_equal("teal", enum_object<>::to_string(known_color::teal));
      assert::are_equal(known_color::teal, enum_object<>::parse<known_color>("teal"));
    }
    
    auto test_method_(thistle) {
      assert::are_equal(134, enum_object<>::to_int32(known_color::thistle));
      assert::are_equal("thistle", enum_object<>::to_string(known_color::thistle));
      assert::are_equal(known_color::thistle, enum_object<>::parse<known_color>("thistle"));
    }
    
    auto test_method_(tomato) {
      assert::are_equal(135, enum_object<>::to_int32(known_color::tomato));
      assert::are_equal("tomato", enum_object<>::to_string(known_color::tomato));
      assert::are_equal(known_color::tomato, enum_object<>::parse<known_color>("tomato"));
    }
    
    auto test_method_(turquoise) {
      assert::are_equal(136, enum_object<>::to_int32(known_color::turquoise));
      assert::are_equal("turquoise", enum_object<>::to_string(known_color::turquoise));
      assert::are_equal(known_color::turquoise, enum_object<>::parse<known_color>("turquoise"));
    }
    
    auto test_method_(violet) {
      assert::are_equal(137, enum_object<>::to_int32(known_color::violet));
      assert::are_equal("violet", enum_object<>::to_string(known_color::violet));
      assert::are_equal(known_color::violet, enum_object<>::parse<known_color>("violet"));
    }
    
    auto test_method_(wheat) {
      assert::are_equal(138, enum_object<>::to_int32(known_color::wheat));
      assert::are_equal("wheat", enum_object<>::to_string(known_color::wheat));
      assert::are_equal(known_color::wheat, enum_object<>::parse<known_color>("wheat"));
    }
    
    auto test_method_(white) {
      assert::are_equal(139, enum_object<>::to_int32(known_color::white));
      assert::are_equal("white", enum_object<>::to_string(known_color::white));
      assert::are_equal(known_color::white, enum_object<>::parse<known_color>("white"));
    }
    
    auto test_method_(white_smoke) {
      assert::are_equal(140, enum_object<>::to_int32(known_color::white_smoke));
      assert::are_equal("white_smoke", enum_object<>::to_string(known_color::white_smoke));
      assert::are_equal(known_color::white_smoke, enum_object<>::parse<known_color>("white_smoke"));
    }
    
    auto test_method_(yellow) {
      assert::are_equal(141, enum_object<>::to_int32(known_color::yellow));
      assert::are_equal("yellow", enum_object<>::to_string(known_color::yellow));
      assert::are_equal(known_color::yellow, enum_object<>::parse<known_color>("yellow"));
    }
    
    auto test_method_(yellow_green) {
      assert::are_equal(142, enum_object<>::to_int32(known_color::yellow_green));
      assert::are_equal("yellow_green", enum_object<>::to_string(known_color::yellow_green));
      assert::are_equal(known_color::yellow_green, enum_object<>::parse<known_color>("yellow_green"));
    }
    
    auto test_method_(apple_black) {
      assert::are_equal(143, enum_object<>::to_int32(known_color::apple_black));
      assert::are_equal("apple_black", enum_object<>::to_string(known_color::apple_black));
      assert::are_equal(known_color::apple_black, enum_object<>::parse<known_color>("apple_black"));
    }
    
    auto test_method_(apple_blue) {
      assert::are_equal(144, enum_object<>::to_int32(known_color::apple_blue));
      assert::are_equal("apple_blue", enum_object<>::to_string(known_color::apple_blue));
      assert::are_equal(known_color::apple_blue, enum_object<>::parse<known_color>("apple_blue"));
    }
    
    auto test_method_(apple_brown) {
      assert::are_equal(145, enum_object<>::to_int32(known_color::apple_brown));
      assert::are_equal("apple_brown", enum_object<>::to_string(known_color::apple_brown));
      assert::are_equal(known_color::apple_brown, enum_object<>::parse<known_color>("apple_brown"));
    }
    
    auto test_method_(apple_cyan) {
      assert::are_equal(146, enum_object<>::to_int32(known_color::apple_cyan));
      assert::are_equal("apple_cyan", enum_object<>::to_string(known_color::apple_cyan));
      assert::are_equal(known_color::apple_cyan, enum_object<>::parse<known_color>("apple_cyan"));
    }
    
    auto test_method_(apple_green) {
      assert::are_equal(147, enum_object<>::to_int32(known_color::apple_green));
      assert::are_equal("apple_green", enum_object<>::to_string(known_color::apple_green));
      assert::are_equal(known_color::apple_green, enum_object<>::parse<known_color>("apple_green"));
    }
    
    auto test_method_(apple_magenta) {
      assert::are_equal(148, enum_object<>::to_int32(known_color::apple_magenta));
      assert::are_equal("apple_magenta", enum_object<>::to_string(known_color::apple_magenta));
      assert::are_equal(known_color::apple_magenta, enum_object<>::parse<known_color>("apple_magenta"));
    }
    
    auto test_method_(apple_orange) {
      assert::are_equal(149, enum_object<>::to_int32(known_color::apple_orange));
      assert::are_equal("apple_orange", enum_object<>::to_string(known_color::apple_orange));
      assert::are_equal(known_color::apple_orange, enum_object<>::parse<known_color>("apple_orange"));
    }
    
    auto test_method_(apple_purple) {
      assert::are_equal(150, enum_object<>::to_int32(known_color::apple_purple));
      assert::are_equal("apple_purple", enum_object<>::to_string(known_color::apple_purple));
      assert::are_equal(known_color::apple_purple, enum_object<>::parse<known_color>("apple_purple"));
    }
    
    auto test_method_(apple_red) {
      assert::are_equal(151, enum_object<>::to_int32(known_color::apple_red));
      assert::are_equal("apple_red", enum_object<>::to_string(known_color::apple_red));
      assert::are_equal(known_color::apple_red, enum_object<>::parse<known_color>("apple_red"));
    }
    
    auto test_method_(apple_yellow) {
      assert::are_equal(152, enum_object<>::to_int32(known_color::apple_yellow));
      assert::are_equal("apple_yellow", enum_object<>::to_string(known_color::apple_yellow));
      assert::are_equal(known_color::apple_yellow, enum_object<>::parse<known_color>("apple_yellow"));
    }
    
    auto test_method_(apple_white) {
      assert::are_equal(153, enum_object<>::to_int32(known_color::apple_white));
      assert::are_equal("apple_white", enum_object<>::to_string(known_color::apple_white));
      assert::are_equal(known_color::apple_white, enum_object<>::parse<known_color>("apple_white"));
    }
    
    auto test_method_(crayon_licorice) {
      assert::are_equal(154, enum_object<>::to_int32(known_color::crayon_licorice));
      assert::are_equal("crayon_licorice", enum_object<>::to_string(known_color::crayon_licorice));
      assert::are_equal(known_color::crayon_licorice, enum_object<>::parse<known_color>("crayon_licorice"));
    }
    
    auto test_method_(crayon_lead) {
      assert::are_equal(155, enum_object<>::to_int32(known_color::crayon_lead));
      assert::are_equal("crayon_lead", enum_object<>::to_string(known_color::crayon_lead));
      assert::are_equal(known_color::crayon_lead, enum_object<>::parse<known_color>("crayon_lead"));
    }
    
    auto test_method_(crayon_tungsten) {
      assert::are_equal(156, enum_object<>::to_int32(known_color::crayon_tungsten));
      assert::are_equal("crayon_tungsten", enum_object<>::to_string(known_color::crayon_tungsten));
      assert::are_equal(known_color::crayon_tungsten, enum_object<>::parse<known_color>("crayon_tungsten"));
    }
    
    auto test_method_(crayon_iron) {
      assert::are_equal(157, enum_object<>::to_int32(known_color::crayon_iron));
      assert::are_equal("crayon_iron", enum_object<>::to_string(known_color::crayon_iron));
      assert::are_equal(known_color::crayon_iron, enum_object<>::parse<known_color>("crayon_iron"));
    }
    
    auto test_method_(crayon_steel) {
      assert::are_equal(158, enum_object<>::to_int32(known_color::crayon_steel));
      assert::are_equal("crayon_steel", enum_object<>::to_string(known_color::crayon_steel));
      assert::are_equal(known_color::crayon_steel, enum_object<>::parse<known_color>("crayon_steel"));
    }
    
    auto test_method_(crayon_tin) {
      assert::are_equal(159, enum_object<>::to_int32(known_color::crayon_tin));
      assert::are_equal("crayon_tin", enum_object<>::to_string(known_color::crayon_tin));
      assert::are_equal(known_color::crayon_tin, enum_object<>::parse<known_color>("crayon_tin"));
    }
    
    auto test_method_(crayon_nickel) {
      assert::are_equal(160, enum_object<>::to_int32(known_color::crayon_nickel));
      assert::are_equal("crayon_nickel", enum_object<>::to_string(known_color::crayon_nickel));
      assert::are_equal(known_color::crayon_nickel, enum_object<>::parse<known_color>("crayon_nickel"));
    }
    
    auto test_method_(crayon_aluminium) {
      assert::are_equal(161, enum_object<>::to_int32(known_color::crayon_aluminium));
      assert::are_equal("crayon_aluminium", enum_object<>::to_string(known_color::crayon_aluminium));
      assert::are_equal(known_color::crayon_aluminium, enum_object<>::parse<known_color>("crayon_aluminium"));
    }
    
    auto test_method_(crayon_magnesium) {
      assert::are_equal(162, enum_object<>::to_int32(known_color::crayon_magnesium));
      assert::are_equal("crayon_magnesium", enum_object<>::to_string(known_color::crayon_magnesium));
      assert::are_equal(known_color::crayon_magnesium, enum_object<>::parse<known_color>("crayon_magnesium"));
    }
    
    auto test_method_(crayon_silver) {
      assert::are_equal(163, enum_object<>::to_int32(known_color::crayon_silver));
      assert::are_equal("crayon_silver", enum_object<>::to_string(known_color::crayon_silver));
      assert::are_equal(known_color::crayon_silver, enum_object<>::parse<known_color>("crayon_silver"));
    }
    
    auto test_method_(crayon_mercury) {
      assert::are_equal(164, enum_object<>::to_int32(known_color::crayon_mercury));
      assert::are_equal("crayon_mercury", enum_object<>::to_string(known_color::crayon_mercury));
      assert::are_equal(known_color::crayon_mercury, enum_object<>::parse<known_color>("crayon_mercury"));
    }
    
    auto test_method_(crayon_snow) {
      assert::are_equal(165, enum_object<>::to_int32(known_color::crayon_snow));
      assert::are_equal("crayon_snow", enum_object<>::to_string(known_color::crayon_snow));
      assert::are_equal(known_color::crayon_snow, enum_object<>::parse<known_color>("crayon_snow"));
    }
    
    auto test_method_(crayon_cayenne) {
      assert::are_equal(166, enum_object<>::to_int32(known_color::crayon_cayenne));
      assert::are_equal("crayon_cayenne", enum_object<>::to_string(known_color::crayon_cayenne));
      assert::are_equal(known_color::crayon_cayenne, enum_object<>::parse<known_color>("crayon_cayenne"));
    }
    
    auto test_method_(crayon_mocha) {
      assert::are_equal(167, enum_object<>::to_int32(known_color::crayon_mocha));
      assert::are_equal("crayon_mocha", enum_object<>::to_string(known_color::crayon_mocha));
      assert::are_equal(known_color::crayon_mocha, enum_object<>::parse<known_color>("crayon_mocha"));
    }
    
    auto test_method_(crayon_asparagus) {
      assert::are_equal(168, enum_object<>::to_int32(known_color::crayon_asparagus));
      assert::are_equal("crayon_asparagus", enum_object<>::to_string(known_color::crayon_asparagus));
      assert::are_equal(known_color::crayon_asparagus, enum_object<>::parse<known_color>("crayon_asparagus"));
    }
    
    auto test_method_(crayon_fern) {
      assert::are_equal(169, enum_object<>::to_int32(known_color::crayon_fern));
      assert::are_equal("crayon_fern", enum_object<>::to_string(known_color::crayon_fern));
      assert::are_equal(known_color::crayon_fern, enum_object<>::parse<known_color>("crayon_fern"));
    }
    
    auto test_method_(crayon_clover) {
      assert::are_equal(170, enum_object<>::to_int32(known_color::crayon_clover));
      assert::are_equal("crayon_clover", enum_object<>::to_string(known_color::crayon_clover));
      assert::are_equal(known_color::crayon_clover, enum_object<>::parse<known_color>("crayon_clover"));
    }
    
    auto test_method_(crayon_moss) {
      assert::are_equal(171, enum_object<>::to_int32(known_color::crayon_moss));
      assert::are_equal("crayon_moss", enum_object<>::to_string(known_color::crayon_moss));
      assert::are_equal(known_color::crayon_moss, enum_object<>::parse<known_color>("crayon_moss"));
    }
    
    auto test_method_(crayon_teal) {
      assert::are_equal(172, enum_object<>::to_int32(known_color::crayon_teal));
      assert::are_equal("crayon_teal", enum_object<>::to_string(known_color::crayon_teal));
      assert::are_equal(known_color::crayon_teal, enum_object<>::parse<known_color>("crayon_teal"));
    }
    
    auto test_method_(crayon_ocean) {
      assert::are_equal(173, enum_object<>::to_int32(known_color::crayon_ocean));
      assert::are_equal("crayon_ocean", enum_object<>::to_string(known_color::crayon_ocean));
      assert::are_equal(known_color::crayon_ocean, enum_object<>::parse<known_color>("crayon_ocean"));
    }
    
    auto test_method_(crayon_midnight) {
      assert::are_equal(174, enum_object<>::to_int32(known_color::crayon_midnight));
      assert::are_equal("crayon_midnight", enum_object<>::to_string(known_color::crayon_midnight));
      assert::are_equal(known_color::crayon_midnight, enum_object<>::parse<known_color>("crayon_midnight"));
    }
    
    auto test_method_(crayon_eggplant) {
      assert::are_equal(175, enum_object<>::to_int32(known_color::crayon_eggplant));
      assert::are_equal("crayon_eggplant", enum_object<>::to_string(known_color::crayon_eggplant));
      assert::are_equal(known_color::crayon_eggplant, enum_object<>::parse<known_color>("crayon_eggplant"));
    }
    
    auto test_method_(crayon_plum) {
      assert::are_equal(176, enum_object<>::to_int32(known_color::crayon_plum));
      assert::are_equal("crayon_plum", enum_object<>::to_string(known_color::crayon_plum));
      assert::are_equal(known_color::crayon_plum, enum_object<>::parse<known_color>("crayon_plum"));
    }
    
    auto test_method_(crayon_maroon) {
      assert::are_equal(177, enum_object<>::to_int32(known_color::crayon_maroon));
      assert::are_equal("crayon_maroon", enum_object<>::to_string(known_color::crayon_maroon));
      assert::are_equal(known_color::crayon_maroon, enum_object<>::parse<known_color>("crayon_maroon"));
    }
    
    auto test_method_(crayon_tangerine) {
      assert::are_equal(179, enum_object<>::to_int32(known_color::crayon_tangerine));
      assert::are_equal("crayon_tangerine", enum_object<>::to_string(known_color::crayon_tangerine));
      assert::are_equal(known_color::crayon_tangerine, enum_object<>::parse<known_color>("crayon_tangerine"));
    }
    
    auto test_method_(crayon_lemon) {
      assert::are_equal(180, enum_object<>::to_int32(known_color::crayon_lemon));
      assert::are_equal("crayon_lemon", enum_object<>::to_string(known_color::crayon_lemon));
      assert::are_equal(known_color::crayon_lemon, enum_object<>::parse<known_color>("crayon_lemon"));
    }
    
    auto test_method_(crayon_lime) {
      assert::are_equal(181, enum_object<>::to_int32(known_color::crayon_lime));
      assert::are_equal("crayon_lime", enum_object<>::to_string(known_color::crayon_lime));
      assert::are_equal(known_color::crayon_lime, enum_object<>::parse<known_color>("crayon_lime"));
    }
    
    auto test_method_(crayon_spring) {
      assert::are_equal(182, enum_object<>::to_int32(known_color::crayon_spring));
      assert::are_equal("crayon_spring", enum_object<>::to_string(known_color::crayon_spring));
      assert::are_equal(known_color::crayon_spring, enum_object<>::parse<known_color>("crayon_spring"));
    }
    
    auto test_method_(crayon_sea_foam) {
      assert::are_equal(183, enum_object<>::to_int32(known_color::crayon_sea_foam));
      assert::are_equal("crayon_sea_foam", enum_object<>::to_string(known_color::crayon_sea_foam));
      assert::are_equal(known_color::crayon_sea_foam, enum_object<>::parse<known_color>("crayon_sea_foam"));
    }
    
    auto test_method_(crayon_turquoise) {
      assert::are_equal(184, enum_object<>::to_int32(known_color::crayon_turquoise));
      assert::are_equal("crayon_turquoise", enum_object<>::to_string(known_color::crayon_turquoise));
      assert::are_equal(known_color::crayon_turquoise, enum_object<>::parse<known_color>("crayon_turquoise"));
    }
    
    auto test_method_(crayon_aqua) {
      assert::are_equal(185, enum_object<>::to_int32(known_color::crayon_aqua));
      assert::are_equal("crayon_aqua", enum_object<>::to_string(known_color::crayon_aqua));
      assert::are_equal(known_color::crayon_aqua, enum_object<>::parse<known_color>("crayon_aqua"));
    }
    
    auto test_method_(crayon_blueberry) {
      assert::are_equal(186, enum_object<>::to_int32(known_color::crayon_blueberry));
      assert::are_equal("crayon_blueberry", enum_object<>::to_string(known_color::crayon_blueberry));
      assert::are_equal(known_color::crayon_blueberry, enum_object<>::parse<known_color>("crayon_blueberry"));
    }
    
    auto test_method_(crayon_grape) {
      assert::are_equal(187, enum_object<>::to_int32(known_color::crayon_grape));
      assert::are_equal("crayon_grape", enum_object<>::to_string(known_color::crayon_grape));
      assert::are_equal(known_color::crayon_grape, enum_object<>::parse<known_color>("crayon_grape"));
    }
    
    auto test_method_(crayon_magenta) {
      assert::are_equal(188, enum_object<>::to_int32(known_color::crayon_magenta));
      assert::are_equal("crayon_magenta", enum_object<>::to_string(known_color::crayon_magenta));
      assert::are_equal(known_color::crayon_magenta, enum_object<>::parse<known_color>("crayon_magenta"));
    }
    
    auto test_method_(crayon_strawberry) {
      assert::are_equal(189, enum_object<>::to_int32(known_color::crayon_strawberry));
      assert::are_equal("crayon_strawberry", enum_object<>::to_string(known_color::crayon_strawberry));
      assert::are_equal(known_color::crayon_strawberry, enum_object<>::parse<known_color>("crayon_strawberry"));
    }
    
    auto test_method_(crayon_salmon) {
      assert::are_equal(190, enum_object<>::to_int32(known_color::crayon_salmon));
      assert::are_equal("crayon_salmon", enum_object<>::to_string(known_color::crayon_salmon));
      assert::are_equal(known_color::crayon_salmon, enum_object<>::parse<known_color>("crayon_salmon"));
    }
    
    auto test_method_(crayon_cantaloupe) {
      assert::are_equal(191, enum_object<>::to_int32(known_color::crayon_cantaloupe));
      assert::are_equal("crayon_cantaloupe", enum_object<>::to_string(known_color::crayon_cantaloupe));
      assert::are_equal(known_color::crayon_cantaloupe, enum_object<>::parse<known_color>("crayon_cantaloupe"));
    }
    
    auto test_method_(crayon_banana) {
      assert::are_equal(192, enum_object<>::to_int32(known_color::crayon_banana));
      assert::are_equal("crayon_banana", enum_object<>::to_string(known_color::crayon_banana));
      assert::are_equal(known_color::crayon_banana, enum_object<>::parse<known_color>("crayon_banana"));
    }
    
    auto test_method_(crayon_honeydew) {
      assert::are_equal(193, enum_object<>::to_int32(known_color::crayon_honeydew));
      assert::are_equal("crayon_honeydew", enum_object<>::to_string(known_color::crayon_honeydew));
      assert::are_equal(known_color::crayon_honeydew, enum_object<>::parse<known_color>("crayon_honeydew"));
    }
    
    auto test_method_(crayon_flora) {
      assert::are_equal(194, enum_object<>::to_int32(known_color::crayon_flora));
      assert::are_equal("crayon_flora", enum_object<>::to_string(known_color::crayon_flora));
      assert::are_equal(known_color::crayon_flora, enum_object<>::parse<known_color>("crayon_flora"));
    }
    
    auto test_method_(crayon_spindrift) {
      assert::are_equal(195, enum_object<>::to_int32(known_color::crayon_spindrift));
      assert::are_equal("crayon_spindrift", enum_object<>::to_string(known_color::crayon_spindrift));
      assert::are_equal(known_color::crayon_spindrift, enum_object<>::parse<known_color>("crayon_spindrift"));
    }
    
    auto test_method_(crayon_ice) {
      assert::are_equal(196, enum_object<>::to_int32(known_color::crayon_ice));
      assert::are_equal("crayon_ice", enum_object<>::to_string(known_color::crayon_ice));
      assert::are_equal(known_color::crayon_ice, enum_object<>::parse<known_color>("crayon_ice"));
    }
    
    auto test_method_(crayon_sky) {
      assert::are_equal(197, enum_object<>::to_int32(known_color::crayon_sky));
      assert::are_equal("crayon_sky", enum_object<>::to_string(known_color::crayon_sky));
      assert::are_equal(known_color::crayon_sky, enum_object<>::parse<known_color>("crayon_sky"));
    }
    
    auto test_method_(crayon_orchid) {
      assert::are_equal(198, enum_object<>::to_int32(known_color::crayon_orchid));
      assert::are_equal("crayon_orchid", enum_object<>::to_string(known_color::crayon_orchid));
      assert::are_equal(known_color::crayon_orchid, enum_object<>::parse<known_color>("crayon_orchid"));
    }
    
    auto test_method_(crayon_lavendar) {
      assert::are_equal(199, enum_object<>::to_int32(known_color::crayon_lavendar));
      assert::are_equal("crayon_lavendar", enum_object<>::to_string(known_color::crayon_lavendar));
      assert::are_equal(known_color::crayon_lavendar, enum_object<>::parse<known_color>("crayon_lavendar"));
    }
    
    auto test_method_(crayon_bubblegum) {
      assert::are_equal(200, enum_object<>::to_int32(known_color::crayon_bubblegum));
      assert::are_equal("crayon_bubblegum", enum_object<>::to_string(known_color::crayon_bubblegum));
      assert::are_equal(known_color::crayon_bubblegum, enum_object<>::parse<known_color>("crayon_bubblegum"));
    }
    
    auto test_method_(crayon_carnation) {
      assert::are_equal(201, enum_object<>::to_int32(known_color::crayon_carnation));
      assert::are_equal("crayon_carnation", enum_object<>::to_string(known_color::crayon_carnation));
      assert::are_equal(known_color::crayon_carnation, enum_object<>::parse<known_color>("crayon_carnation"));
    }
    
    auto test_method_(accent) {
      assert::are_equal(65281, enum_object<>::to_int32(known_color::accent));
      assert::are_equal("accent", enum_object<>::to_string(known_color::accent));
      assert::are_equal(known_color::accent, enum_object<>::parse<known_color>("accent"));
    }
    
    auto test_method_(accent_text) {
      assert::are_equal(65282, enum_object<>::to_int32(known_color::accent_text));
      assert::are_equal("accent_text", enum_object<>::to_string(known_color::accent_text));
      assert::are_equal(known_color::accent_text, enum_object<>::parse<known_color>("accent_text"));
    }
    
    auto test_method_(active_border) {
      assert::are_equal(65283, enum_object<>::to_int32(known_color::active_border));
      assert::are_equal("active_border", enum_object<>::to_string(known_color::active_border));
      assert::are_equal(known_color::active_border, enum_object<>::parse<known_color>("active_border"));
    }
    
    auto test_method_(active_caption) {
      assert::are_equal(65284, enum_object<>::to_int32(known_color::active_caption));
      assert::are_equal("active_caption", enum_object<>::to_string(known_color::active_caption));
      assert::are_equal(known_color::active_caption, enum_object<>::parse<known_color>("active_caption"));
    }
    
    auto test_method_(active_caption_text) {
      assert::are_equal(65285, enum_object<>::to_int32(known_color::active_caption_text));
      assert::are_equal("active_caption_text", enum_object<>::to_string(known_color::active_caption_text));
      assert::are_equal(known_color::active_caption_text, enum_object<>::parse<known_color>("active_caption_text"));
    }
    
    auto test_method_(active_text) {
      assert::are_equal(65286, enum_object<>::to_int32(known_color::active_text));
      assert::are_equal("active_text", enum_object<>::to_string(known_color::active_text));
      assert::are_equal(known_color::active_text, enum_object<>::parse<known_color>("active_text"));
    }
    
    auto test_method_(app_workspace) {
      assert::are_equal(65287, enum_object<>::to_int32(known_color::app_workspace));
      assert::are_equal("app_workspace", enum_object<>::to_string(known_color::app_workspace));
      assert::are_equal(known_color::app_workspace, enum_object<>::parse<known_color>("app_workspace"));
    }
    
    auto test_method_(button_face) {
      assert::are_equal(65288, enum_object<>::to_int32(known_color::button_face));
      assert::are_equal("button_face", enum_object<>::to_string(known_color::button_face));
      assert::are_equal(known_color::button_face, enum_object<>::parse<known_color>("button_face"));
    }
    
    auto test_method_(button_highlight) {
      assert::are_equal(65289, enum_object<>::to_int32(known_color::button_highlight));
      assert::are_equal("button_highlight", enum_object<>::to_string(known_color::button_highlight));
      assert::are_equal(known_color::button_highlight, enum_object<>::parse<known_color>("button_highlight"));
    }
    
    auto test_method_(button_shadow) {
      assert::are_equal(65290, enum_object<>::to_int32(known_color::button_shadow));
      assert::are_equal("button_shadow", enum_object<>::to_string(known_color::button_shadow));
      assert::are_equal(known_color::button_shadow, enum_object<>::parse<known_color>("button_shadow"));
    }
    
    auto test_method_(control) {
      assert::are_equal(65291, enum_object<>::to_int32(known_color::control));
      assert::are_equal("control", enum_object<>::to_string(known_color::control));
      assert::are_equal(known_color::control, enum_object<>::parse<known_color>("control"));
    }
    
    auto test_method_(control_dark) {
      assert::are_equal(65292, enum_object<>::to_int32(known_color::control_dark));
      assert::are_equal("control_dark", enum_object<>::to_string(known_color::control_dark));
      assert::are_equal(known_color::control_dark, enum_object<>::parse<known_color>("control_dark"));
    }
    
    auto test_method_(control_dark_dark) {
      assert::are_equal(65293, enum_object<>::to_int32(known_color::control_dark_dark));
      assert::are_equal("control_dark_dark", enum_object<>::to_string(known_color::control_dark_dark));
      assert::are_equal(known_color::control_dark_dark, enum_object<>::parse<known_color>("control_dark_dark"));
    }
    
    auto test_method_(control_light) {
      assert::are_equal(65294, enum_object<>::to_int32(known_color::control_light));
      assert::are_equal("control_light", enum_object<>::to_string(known_color::control_light));
      assert::are_equal(known_color::control_light, enum_object<>::parse<known_color>("control_light"));
    }
    
    auto test_method_(control_light_light) {
      assert::are_equal(65295, enum_object<>::to_int32(known_color::control_light_light));
      assert::are_equal("control_light_light", enum_object<>::to_string(known_color::control_light_light));
      assert::are_equal(known_color::control_light_light, enum_object<>::parse<known_color>("control_light_light"));
    }
    
    auto test_method_(control_text) {
      assert::are_equal(65296, enum_object<>::to_int32(known_color::control_text));
      assert::are_equal("control_text", enum_object<>::to_string(known_color::control_text));
      assert::are_equal(known_color::control_text, enum_object<>::parse<known_color>("control_text"));
    }
    
    auto test_method_(desktop) {
      assert::are_equal(65297, enum_object<>::to_int32(known_color::desktop));
      assert::are_equal("desktop", enum_object<>::to_string(known_color::desktop));
      assert::are_equal(known_color::desktop, enum_object<>::parse<known_color>("desktop"));
    }
    
    auto test_method_(gradient_active_caption) {
      assert::are_equal(65298, enum_object<>::to_int32(known_color::gradient_active_caption));
      assert::are_equal("gradient_active_caption", enum_object<>::to_string(known_color::gradient_active_caption));
      assert::are_equal(known_color::gradient_active_caption, enum_object<>::parse<known_color>("gradient_active_caption"));
    }
    
    auto test_method_(gradient_inactive_caption) {
      assert::are_equal(65299, enum_object<>::to_int32(known_color::gradient_inactive_caption));
      assert::are_equal("gradient_inactive_caption", enum_object<>::to_string(known_color::gradient_inactive_caption));
      assert::are_equal(known_color::gradient_inactive_caption, enum_object<>::parse<known_color>("gradient_inactive_caption"));
    }
    
    auto test_method_(gray_text) {
      assert::are_equal(65300, enum_object<>::to_int32(known_color::gray_text));
      assert::are_equal("gray_text", enum_object<>::to_string(known_color::gray_text));
      assert::are_equal(known_color::gray_text, enum_object<>::parse<known_color>("gray_text"));
    }
    
    auto test_method_(highlight) {
      assert::are_equal(65301, enum_object<>::to_int32(known_color::highlight));
      assert::are_equal("highlight", enum_object<>::to_string(known_color::highlight));
      assert::are_equal(known_color::highlight, enum_object<>::parse<known_color>("highlight"));
    }
    
    auto test_method_(highlight_text) {
      assert::are_equal(65302, enum_object<>::to_int32(known_color::highlight_text));
      assert::are_equal("highlight_text", enum_object<>::to_string(known_color::highlight_text));
      assert::are_equal(known_color::highlight_text, enum_object<>::parse<known_color>("highlight_text"));
    }
    
    auto test_method_(hot_track) {
      assert::are_equal(65303, enum_object<>::to_int32(known_color::hot_track));
      assert::are_equal("hot_track", enum_object<>::to_string(known_color::hot_track));
      assert::are_equal(known_color::hot_track, enum_object<>::parse<known_color>("hot_track"));
    }
    
    auto test_method_(inactive_border) {
      assert::are_equal(65304, enum_object<>::to_int32(known_color::inactive_border));
      assert::are_equal("inactive_border", enum_object<>::to_string(known_color::inactive_border));
      assert::are_equal(known_color::inactive_border, enum_object<>::parse<known_color>("inactive_border"));
    }
    
    auto test_method_(inactive_caption) {
      assert::are_equal(65305, enum_object<>::to_int32(known_color::inactive_caption));
      assert::are_equal("inactive_caption", enum_object<>::to_string(known_color::inactive_caption));
      assert::are_equal(known_color::inactive_caption, enum_object<>::parse<known_color>("inactive_caption"));
    }
    
    auto test_method_(inactive_caption_text) {
      assert::are_equal(65306, enum_object<>::to_int32(known_color::inactive_caption_text));
      assert::are_equal("inactive_caption_text", enum_object<>::to_string(known_color::inactive_caption_text));
      assert::are_equal(known_color::inactive_caption_text, enum_object<>::parse<known_color>("inactive_caption_text"));
    }
    
    auto test_method_(info) {
      assert::are_equal(65307, enum_object<>::to_int32(known_color::info));
      assert::are_equal("info", enum_object<>::to_string(known_color::info));
      assert::are_equal(known_color::info, enum_object<>::parse<known_color>("info"));
    }
    
    auto test_method_(info_text) {
      assert::are_equal(65308, enum_object<>::to_int32(known_color::info_text));
      assert::are_equal("info_text", enum_object<>::to_string(known_color::info_text));
      assert::are_equal(known_color::info_text, enum_object<>::parse<known_color>("info_text"));
    }
    
    auto test_method_(link_text) {
      assert::are_equal(65309, enum_object<>::to_int32(known_color::link_text));
      assert::are_equal("link_text", enum_object<>::to_string(known_color::link_text));
      assert::are_equal(known_color::link_text, enum_object<>::parse<known_color>("link_text"));
    }
    
    auto test_method_(menu) {
      assert::are_equal(65310, enum_object<>::to_int32(known_color::menu));
      assert::are_equal("menu", enum_object<>::to_string(known_color::menu));
      assert::are_equal(known_color::menu, enum_object<>::parse<known_color>("menu"));
    }
    
    auto test_method_(menu_bar) {
      assert::are_equal(65311, enum_object<>::to_int32(known_color::menu_bar));
      assert::are_equal("menu_bar", enum_object<>::to_string(known_color::menu_bar));
      assert::are_equal(known_color::menu_bar, enum_object<>::parse<known_color>("menu_bar"));
    }
    
    auto test_method_(menu_highlight) {
      assert::are_equal(65312, enum_object<>::to_int32(known_color::menu_highlight));
      assert::are_equal("menu_highlight", enum_object<>::to_string(known_color::menu_highlight));
      assert::are_equal(known_color::menu_highlight, enum_object<>::parse<known_color>("menu_highlight"));
    }
    
    auto test_method_(menu_text) {
      assert::are_equal(65313, enum_object<>::to_int32(known_color::menu_text));
      assert::are_equal("menu_text", enum_object<>::to_string(known_color::menu_text));
      assert::are_equal(known_color::menu_text, enum_object<>::parse<known_color>("menu_text"));
    }
    
    auto test_method_(scroll_bar) {
      assert::are_equal(65314, enum_object<>::to_int32(known_color::scroll_bar));
      assert::are_equal("scroll_bar", enum_object<>::to_string(known_color::scroll_bar));
      assert::are_equal(known_color::scroll_bar, enum_object<>::parse<known_color>("scroll_bar"));
    }
    
    auto test_method_(text_box) {
      assert::are_equal(65316, enum_object<>::to_int32(known_color::text_box));
      assert::are_equal("text_box", enum_object<>::to_string(known_color::text_box));
      assert::are_equal(known_color::text_box, enum_object<>::parse<known_color>("text_box"));
    }
    
    auto test_method_(text_box_text) {
      assert::are_equal(65317, enum_object<>::to_int32(known_color::text_box_text));
      assert::are_equal("text_box_text", enum_object<>::to_string(known_color::text_box_text));
      assert::are_equal(known_color::text_box_text, enum_object<>::parse<known_color>("text_box_text"));
    }
    
    auto test_method_(visited_text) {
      assert::are_equal(65318, enum_object<>::to_int32(known_color::visited_text));
      assert::are_equal("visited_text", enum_object<>::to_string(known_color::visited_text));
      assert::are_equal(known_color::visited_text, enum_object<>::parse<known_color>("visited_text"));
    }
    
    auto test_method_(window) {
      assert::are_equal(65319, enum_object<>::to_int32(known_color::window));
      assert::are_equal("window", enum_object<>::to_string(known_color::window));
      assert::are_equal(known_color::window, enum_object<>::parse<known_color>("window"));
    }
    
    auto test_method_(window_frame) {
      assert::are_equal(65320, enum_object<>::to_int32(known_color::window_frame));
      assert::are_equal("window_frame", enum_object<>::to_string(known_color::window_frame));
      assert::are_equal(known_color::window_frame, enum_object<>::parse<known_color>("window_frame"));
    }
    
    auto test_method_(window_text) {
      assert::are_equal(65321, enum_object<>::to_int32(known_color::window_text));
      assert::are_equal("window_text", enum_object<>::to_string(known_color::window_text));
      assert::are_equal(known_color::window_text, enum_object<>::parse<known_color>("window_text"));
    }
  };
}
