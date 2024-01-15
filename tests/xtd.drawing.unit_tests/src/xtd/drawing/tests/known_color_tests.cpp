#include <xtd/drawing/known_color>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(known_color_tests) {
    void test_method_(transparent) {
      assert::are_equal(1, enum_object<>::to_int32(known_color::transparent), csf_);
      assert::are_equal("transparent", enum_object<>::to_string(known_color::transparent), csf_);
      assert::are_equal(known_color::transparent, enum_object<>::parse<known_color>("transparent"), csf_);
    }
    
    void test_method_(alice_blue) {
      assert::are_equal(2, enum_object<>::to_int32(known_color::alice_blue), csf_);
      assert::are_equal("alice_blue", enum_object<>::to_string(known_color::alice_blue), csf_);
      assert::are_equal(known_color::alice_blue, enum_object<>::parse<known_color>("alice_blue"), csf_);
    }
    
    void test_method_(antique_white) {
      assert::are_equal(3, enum_object<>::to_int32(known_color::antique_white), csf_);
      assert::are_equal("antique_white", enum_object<>::to_string(known_color::antique_white), csf_);
      assert::are_equal(known_color::antique_white, enum_object<>::parse<known_color>("antique_white"), csf_);
    }
    
    void test_method_(aqua) {
      assert::are_equal(4, enum_object<>::to_int32(known_color::aqua), csf_);
      assert::are_equal("aqua", enum_object<>::to_string(known_color::aqua), csf_);
      assert::are_equal(known_color::aqua, enum_object<>::parse<known_color>("aqua"), csf_);
    }
    
    void test_method_(aquamarine) {
      assert::are_equal(5, enum_object<>::to_int32(known_color::aquamarine), csf_);
      assert::are_equal("aquamarine", enum_object<>::to_string(known_color::aquamarine), csf_);
      assert::are_equal(known_color::aquamarine, enum_object<>::parse<known_color>("aquamarine"), csf_);
    }
    
    void test_method_(azure) {
      assert::are_equal(6, enum_object<>::to_int32(known_color::azure), csf_);
      assert::are_equal("azure", enum_object<>::to_string(known_color::azure), csf_);
      assert::are_equal(known_color::azure, enum_object<>::parse<known_color>("azure"), csf_);
    }
    
    void test_method_(beige) {
      assert::are_equal(7, enum_object<>::to_int32(known_color::beige), csf_);
      assert::are_equal("beige", enum_object<>::to_string(known_color::beige), csf_);
      assert::are_equal(known_color::beige, enum_object<>::parse<known_color>("beige"), csf_);
    }
    
    void test_method_(bisque) {
      assert::are_equal(8, enum_object<>::to_int32(known_color::bisque), csf_);
      assert::are_equal("bisque", enum_object<>::to_string(known_color::bisque), csf_);
      assert::are_equal(known_color::bisque, enum_object<>::parse<known_color>("bisque"), csf_);
    }
    
    void test_method_(black) {
      assert::are_equal(9, enum_object<>::to_int32(known_color::black), csf_);
      assert::are_equal("black", enum_object<>::to_string(known_color::black), csf_);
      assert::are_equal(known_color::black, enum_object<>::parse<known_color>("black"), csf_);
    }
    
    void test_method_(blanched_almond) {
      assert::are_equal(10, enum_object<>::to_int32(known_color::blanched_almond), csf_);
      assert::are_equal("blanched_almond", enum_object<>::to_string(known_color::blanched_almond), csf_);
      assert::are_equal(known_color::blanched_almond, enum_object<>::parse<known_color>("blanched_almond"), csf_);
    }
    
    void test_method_(blue) {
      assert::are_equal(11, enum_object<>::to_int32(known_color::blue), csf_);
      assert::are_equal("blue", enum_object<>::to_string(known_color::blue), csf_);
      assert::are_equal(known_color::blue, enum_object<>::parse<known_color>("blue"), csf_);
    }
    
    void test_method_(blue_violet) {
      assert::are_equal(12, enum_object<>::to_int32(known_color::blue_violet), csf_);
      assert::are_equal("blue_violet", enum_object<>::to_string(known_color::blue_violet), csf_);
      assert::are_equal(known_color::blue_violet, enum_object<>::parse<known_color>("blue_violet"), csf_);
    }
    
    void test_method_(brown) {
      assert::are_equal(13, enum_object<>::to_int32(known_color::brown), csf_);
      assert::are_equal("brown", enum_object<>::to_string(known_color::brown), csf_);
      assert::are_equal(known_color::brown, enum_object<>::parse<known_color>("brown"), csf_);
    }
    
    void test_method_(burly_wood) {
      assert::are_equal(14, enum_object<>::to_int32(known_color::burly_wood), csf_);
      assert::are_equal("burly_wood", enum_object<>::to_string(known_color::burly_wood), csf_);
      assert::are_equal(known_color::burly_wood, enum_object<>::parse<known_color>("burly_wood"), csf_);
    }
    
    void test_method_(cadet_blue) {
      assert::are_equal(15, enum_object<>::to_int32(known_color::cadet_blue), csf_);
      assert::are_equal("cadet_blue", enum_object<>::to_string(known_color::cadet_blue), csf_);
      assert::are_equal(known_color::cadet_blue, enum_object<>::parse<known_color>("cadet_blue"), csf_);
    }
    
    void test_method_(chartreuse) {
      assert::are_equal(16, enum_object<>::to_int32(known_color::chartreuse), csf_);
      assert::are_equal("chartreuse", enum_object<>::to_string(known_color::chartreuse), csf_);
      assert::are_equal(known_color::chartreuse, enum_object<>::parse<known_color>("chartreuse"), csf_);
    }
    
    void test_method_(chocolate) {
      assert::are_equal(17, enum_object<>::to_int32(known_color::chocolate), csf_);
      assert::are_equal("chocolate", enum_object<>::to_string(known_color::chocolate), csf_);
      assert::are_equal(known_color::chocolate, enum_object<>::parse<known_color>("chocolate"), csf_);
    }
    
    void test_method_(coral) {
      assert::are_equal(18, enum_object<>::to_int32(known_color::coral), csf_);
      assert::are_equal("coral", enum_object<>::to_string(known_color::coral), csf_);
      assert::are_equal(known_color::coral, enum_object<>::parse<known_color>("coral"), csf_);
    }
    
    void test_method_(cornflower_blue) {
      assert::are_equal(19, enum_object<>::to_int32(known_color::cornflower_blue), csf_);
      assert::are_equal("cornflower_blue", enum_object<>::to_string(known_color::cornflower_blue), csf_);
      assert::are_equal(known_color::cornflower_blue, enum_object<>::parse<known_color>("cornflower_blue"), csf_);
    }
    
    void test_method_(cornsilk) {
      assert::are_equal(20, enum_object<>::to_int32(known_color::cornsilk), csf_);
      assert::are_equal("cornsilk", enum_object<>::to_string(known_color::cornsilk), csf_);
      assert::are_equal(known_color::cornsilk, enum_object<>::parse<known_color>("cornsilk"), csf_);
    }
    
    void test_method_(crimson) {
      assert::are_equal(21, enum_object<>::to_int32(known_color::crimson), csf_);
      assert::are_equal("crimson", enum_object<>::to_string(known_color::crimson), csf_);
      assert::are_equal(known_color::crimson, enum_object<>::parse<known_color>("crimson"), csf_);
    }
    
    void test_method_(cyan) {
      assert::are_equal(22, enum_object<>::to_int32(known_color::cyan), csf_);
      assert::are_equal("cyan", enum_object<>::to_string(known_color::cyan), csf_);
      assert::are_equal(known_color::cyan, enum_object<>::parse<known_color>("cyan"), csf_);
    }
    
    void test_method_(dark_blue) {
      assert::are_equal(23, enum_object<>::to_int32(known_color::dark_blue), csf_);
      assert::are_equal("dark_blue", enum_object<>::to_string(known_color::dark_blue), csf_);
      assert::are_equal(known_color::dark_blue, enum_object<>::parse<known_color>("dark_blue"), csf_);
    }
    
    void test_method_(dark_cyan) {
      assert::are_equal(24, enum_object<>::to_int32(known_color::dark_cyan), csf_);
      assert::are_equal("dark_cyan", enum_object<>::to_string(known_color::dark_cyan), csf_);
      assert::are_equal(known_color::dark_cyan, enum_object<>::parse<known_color>("dark_cyan"), csf_);
    }
    
    void test_method_(dark_goldenrod) {
      assert::are_equal(25, enum_object<>::to_int32(known_color::dark_goldenrod), csf_);
      assert::are_equal("dark_goldenrod", enum_object<>::to_string(known_color::dark_goldenrod), csf_);
      assert::are_equal(known_color::dark_goldenrod, enum_object<>::parse<known_color>("dark_goldenrod"), csf_);
    }
    
    void test_method_(dark_gray) {
      assert::are_equal(26, enum_object<>::to_int32(known_color::dark_gray), csf_);
      assert::are_equal("dark_gray", enum_object<>::to_string(known_color::dark_gray), csf_);
      assert::are_equal(known_color::dark_gray, enum_object<>::parse<known_color>("dark_gray"), csf_);
    }
    
    void test_method_(dark_green) {
      assert::are_equal(27, enum_object<>::to_int32(known_color::dark_green), csf_);
      assert::are_equal("dark_green", enum_object<>::to_string(known_color::dark_green), csf_);
      assert::are_equal(known_color::dark_green, enum_object<>::parse<known_color>("dark_green"), csf_);
    }
    
    void test_method_(dark_khaki) {
      assert::are_equal(28, enum_object<>::to_int32(known_color::dark_khaki), csf_);
      assert::are_equal("dark_khaki", enum_object<>::to_string(known_color::dark_khaki), csf_);
      assert::are_equal(known_color::dark_khaki, enum_object<>::parse<known_color>("dark_khaki"), csf_);
    }
    
    void test_method_(dark_magenta) {
      assert::are_equal(29, enum_object<>::to_int32(known_color::dark_magenta), csf_);
      assert::are_equal("dark_magenta", enum_object<>::to_string(known_color::dark_magenta), csf_);
      assert::are_equal(known_color::dark_magenta, enum_object<>::parse<known_color>("dark_magenta"), csf_);
    }
    
    void test_method_(dark_olive_green) {
      assert::are_equal(30, enum_object<>::to_int32(known_color::dark_olive_green), csf_);
      assert::are_equal("dark_olive_green", enum_object<>::to_string(known_color::dark_olive_green), csf_);
      assert::are_equal(known_color::dark_olive_green, enum_object<>::parse<known_color>("dark_olive_green"), csf_);
    }
    
    void test_method_(dark_orange) {
      assert::are_equal(31, enum_object<>::to_int32(known_color::dark_orange), csf_);
      assert::are_equal("dark_orange", enum_object<>::to_string(known_color::dark_orange), csf_);
      assert::are_equal(known_color::dark_orange, enum_object<>::parse<known_color>("dark_orange"), csf_);
    }
    
    void test_method_(dark_orchid) {
      assert::are_equal(32, enum_object<>::to_int32(known_color::dark_orchid), csf_);
      assert::are_equal("dark_orchid", enum_object<>::to_string(known_color::dark_orchid), csf_);
      assert::are_equal(known_color::dark_orchid, enum_object<>::parse<known_color>("dark_orchid"), csf_);
    }
    
    void test_method_(dark_red) {
      assert::are_equal(33, enum_object<>::to_int32(known_color::dark_red), csf_);
      assert::are_equal("dark_red", enum_object<>::to_string(known_color::dark_red), csf_);
      assert::are_equal(known_color::dark_red, enum_object<>::parse<known_color>("dark_red"), csf_);
    }
    
    void test_method_(dark_salmon) {
      assert::are_equal(34, enum_object<>::to_int32(known_color::dark_salmon), csf_);
      assert::are_equal("dark_salmon", enum_object<>::to_string(known_color::dark_salmon), csf_);
      assert::are_equal(known_color::dark_salmon, enum_object<>::parse<known_color>("dark_salmon"), csf_);
    }
    
    void test_method_(dark_sea_green) {
      assert::are_equal(35, enum_object<>::to_int32(known_color::dark_sea_green), csf_);
      assert::are_equal("dark_sea_green", enum_object<>::to_string(known_color::dark_sea_green), csf_);
      assert::are_equal(known_color::dark_sea_green, enum_object<>::parse<known_color>("dark_sea_green"), csf_);
    }
    
    void test_method_(dark_slate_blue) {
      assert::are_equal(36, enum_object<>::to_int32(known_color::dark_slate_blue), csf_);
      assert::are_equal("dark_slate_blue", enum_object<>::to_string(known_color::dark_slate_blue), csf_);
      assert::are_equal(known_color::dark_slate_blue, enum_object<>::parse<known_color>("dark_slate_blue"), csf_);
    }
    
    void test_method_(dark_slate_gray) {
      assert::are_equal(37, enum_object<>::to_int32(known_color::dark_slate_gray), csf_);
      assert::are_equal("dark_slate_gray", enum_object<>::to_string(known_color::dark_slate_gray), csf_);
      assert::are_equal(known_color::dark_slate_gray, enum_object<>::parse<known_color>("dark_slate_gray"), csf_);
    }
    
    void test_method_(dark_turquoise) {
      assert::are_equal(38, enum_object<>::to_int32(known_color::dark_turquoise), csf_);
      assert::are_equal("dark_turquoise", enum_object<>::to_string(known_color::dark_turquoise), csf_);
      assert::are_equal(known_color::dark_turquoise, enum_object<>::parse<known_color>("dark_turquoise"), csf_);
    }
    
    void test_method_(dark_violet) {
      assert::are_equal(39, enum_object<>::to_int32(known_color::dark_violet), csf_);
      assert::are_equal("dark_violet", enum_object<>::to_string(known_color::dark_violet), csf_);
      assert::are_equal(known_color::dark_violet, enum_object<>::parse<known_color>("dark_violet"), csf_);
    }
    
    void test_method_(deep_pink) {
      assert::are_equal(40, enum_object<>::to_int32(known_color::deep_pink), csf_);
      assert::are_equal("deep_pink", enum_object<>::to_string(known_color::deep_pink), csf_);
      assert::are_equal(known_color::deep_pink, enum_object<>::parse<known_color>("deep_pink"), csf_);
    }
    
    void test_method_(deep_sky_blue) {
      assert::are_equal(41, enum_object<>::to_int32(known_color::deep_sky_blue), csf_);
      assert::are_equal("deep_sky_blue", enum_object<>::to_string(known_color::deep_sky_blue), csf_);
      assert::are_equal(known_color::deep_sky_blue, enum_object<>::parse<known_color>("deep_sky_blue"), csf_);
    }
    
    void test_method_(dim_gray) {
      assert::are_equal(42, enum_object<>::to_int32(known_color::dim_gray), csf_);
      assert::are_equal("dim_gray", enum_object<>::to_string(known_color::dim_gray), csf_);
      assert::are_equal(known_color::dim_gray, enum_object<>::parse<known_color>("dim_gray"), csf_);
    }
    
    void test_method_(dodger_blue) {
      assert::are_equal(43, enum_object<>::to_int32(known_color::dodger_blue), csf_);
      assert::are_equal("dodger_blue", enum_object<>::to_string(known_color::dodger_blue), csf_);
      assert::are_equal(known_color::dodger_blue, enum_object<>::parse<known_color>("dodger_blue"), csf_);
    }
    
    void test_method_(firebrick) {
      assert::are_equal(44, enum_object<>::to_int32(known_color::firebrick), csf_);
      assert::are_equal("firebrick", enum_object<>::to_string(known_color::firebrick), csf_);
      assert::are_equal(known_color::firebrick, enum_object<>::parse<known_color>("firebrick"), csf_);
    }
    
    void test_method_(floral_white) {
      assert::are_equal(45, enum_object<>::to_int32(known_color::floral_white), csf_);
      assert::are_equal("floral_white", enum_object<>::to_string(known_color::floral_white), csf_);
      assert::are_equal(known_color::floral_white, enum_object<>::parse<known_color>("floral_white"), csf_);
    }
    
    void test_method_(forest_green) {
      assert::are_equal(46, enum_object<>::to_int32(known_color::forest_green), csf_);
      assert::are_equal("forest_green", enum_object<>::to_string(known_color::forest_green), csf_);
      assert::are_equal(known_color::forest_green, enum_object<>::parse<known_color>("forest_green"), csf_);
    }
    
    void test_method_(fuchsia) {
      assert::are_equal(47, enum_object<>::to_int32(known_color::fuchsia), csf_);
      assert::are_equal("fuchsia", enum_object<>::to_string(known_color::fuchsia), csf_);
      assert::are_equal(known_color::fuchsia, enum_object<>::parse<known_color>("fuchsia"), csf_);
    }
    
    void test_method_(gainsboro) {
      assert::are_equal(48, enum_object<>::to_int32(known_color::gainsboro), csf_);
      assert::are_equal("gainsboro", enum_object<>::to_string(known_color::gainsboro), csf_);
      assert::are_equal(known_color::gainsboro, enum_object<>::parse<known_color>("gainsboro"), csf_);
    }
    
    void test_method_(ghost_white) {
      assert::are_equal(49, enum_object<>::to_int32(known_color::ghost_white), csf_);
      assert::are_equal("ghost_white", enum_object<>::to_string(known_color::ghost_white), csf_);
      assert::are_equal(known_color::ghost_white, enum_object<>::parse<known_color>("ghost_white"), csf_);
    }
    
    void test_method_(gold) {
      assert::are_equal(50, enum_object<>::to_int32(known_color::gold), csf_);
      assert::are_equal("gold", enum_object<>::to_string(known_color::gold), csf_);
      assert::are_equal(known_color::gold, enum_object<>::parse<known_color>("gold"), csf_);
    }
    
    void test_method_(goldenrod) {
      assert::are_equal(51, enum_object<>::to_int32(known_color::goldenrod), csf_);
      assert::are_equal("goldenrod", enum_object<>::to_string(known_color::goldenrod), csf_);
      assert::are_equal(known_color::goldenrod, enum_object<>::parse<known_color>("goldenrod"), csf_);
    }
    
    void test_method_(gray) {
      assert::are_equal(52, enum_object<>::to_int32(known_color::gray), csf_);
      assert::are_equal("gray", enum_object<>::to_string(known_color::gray), csf_);
      assert::are_equal(known_color::gray, enum_object<>::parse<known_color>("gray"), csf_);
    }
    
    void test_method_(green) {
      assert::are_equal(53, enum_object<>::to_int32(known_color::green), csf_);
      assert::are_equal("green", enum_object<>::to_string(known_color::green), csf_);
      assert::are_equal(known_color::green, enum_object<>::parse<known_color>("green"), csf_);
    }
    
    void test_method_(green_yellow) {
      assert::are_equal(54, enum_object<>::to_int32(known_color::green_yellow), csf_);
      assert::are_equal("green_yellow", enum_object<>::to_string(known_color::green_yellow), csf_);
      assert::are_equal(known_color::green_yellow, enum_object<>::parse<known_color>("green_yellow"), csf_);
    }
    
    void test_method_(honeydew) {
      assert::are_equal(55, enum_object<>::to_int32(known_color::honeydew), csf_);
      assert::are_equal("honeydew", enum_object<>::to_string(known_color::honeydew), csf_);
      assert::are_equal(known_color::honeydew, enum_object<>::parse<known_color>("honeydew"), csf_);
    }
    
    void test_method_(hot_pink) {
      assert::are_equal(56, enum_object<>::to_int32(known_color::hot_pink), csf_);
      assert::are_equal("hot_pink", enum_object<>::to_string(known_color::hot_pink), csf_);
      assert::are_equal(known_color::hot_pink, enum_object<>::parse<known_color>("hot_pink"), csf_);
    }
    
    void test_method_(indian_red) {
      assert::are_equal(57, enum_object<>::to_int32(known_color::indian_red), csf_);
      assert::are_equal("indian_red", enum_object<>::to_string(known_color::indian_red), csf_);
      assert::are_equal(known_color::indian_red, enum_object<>::parse<known_color>("indian_red"), csf_);
    }
    
    void test_method_(indigo) {
      assert::are_equal(58, enum_object<>::to_int32(known_color::indigo), csf_);
      assert::are_equal("indigo", enum_object<>::to_string(known_color::indigo), csf_);
      assert::are_equal(known_color::indigo, enum_object<>::parse<known_color>("indigo"), csf_);
    }
    
    void test_method_(ivory) {
      assert::are_equal(59, enum_object<>::to_int32(known_color::ivory), csf_);
      assert::are_equal("ivory", enum_object<>::to_string(known_color::ivory), csf_);
      assert::are_equal(known_color::ivory, enum_object<>::parse<known_color>("ivory"), csf_);
    }
    
    void test_method_(khaki) {
      assert::are_equal(60, enum_object<>::to_int32(known_color::khaki), csf_);
      assert::are_equal("khaki", enum_object<>::to_string(known_color::khaki), csf_);
      assert::are_equal(known_color::khaki, enum_object<>::parse<known_color>("khaki"), csf_);
    }
    
    void test_method_(lavender) {
      assert::are_equal(61, enum_object<>::to_int32(known_color::lavender), csf_);
      assert::are_equal("lavender", enum_object<>::to_string(known_color::lavender), csf_);
      assert::are_equal(known_color::lavender, enum_object<>::parse<known_color>("lavender"), csf_);
    }
    
    void test_method_(lavender_blush) {
      assert::are_equal(62, enum_object<>::to_int32(known_color::lavender_blush), csf_);
      assert::are_equal("lavender_blush", enum_object<>::to_string(known_color::lavender_blush), csf_);
      assert::are_equal(known_color::lavender_blush, enum_object<>::parse<known_color>("lavender_blush"), csf_);
    }
    
    void test_method_(lawn_green) {
      assert::are_equal(63, enum_object<>::to_int32(known_color::lawn_green), csf_);
      assert::are_equal("lawn_green", enum_object<>::to_string(known_color::lawn_green), csf_);
      assert::are_equal(known_color::lawn_green, enum_object<>::parse<known_color>("lawn_green"), csf_);
    }
    
    void test_method_(lemon_chiffon) {
      assert::are_equal(64, enum_object<>::to_int32(known_color::lemon_chiffon), csf_);
      assert::are_equal("lemon_chiffon", enum_object<>::to_string(known_color::lemon_chiffon), csf_);
      assert::are_equal(known_color::lemon_chiffon, enum_object<>::parse<known_color>("lemon_chiffon"), csf_);
    }
    
    void test_method_(light_blue) {
      assert::are_equal(65, enum_object<>::to_int32(known_color::light_blue), csf_);
      assert::are_equal("light_blue", enum_object<>::to_string(known_color::light_blue), csf_);
      assert::are_equal(known_color::light_blue, enum_object<>::parse<known_color>("light_blue"), csf_);
    }
    
    void test_method_(light_coral) {
      assert::are_equal(66, enum_object<>::to_int32(known_color::light_coral), csf_);
      assert::are_equal("light_coral", enum_object<>::to_string(known_color::light_coral), csf_);
      assert::are_equal(known_color::light_coral, enum_object<>::parse<known_color>("light_coral"), csf_);
    }
    
    void test_method_(light_cyan) {
      assert::are_equal(67, enum_object<>::to_int32(known_color::light_cyan), csf_);
      assert::are_equal("light_cyan", enum_object<>::to_string(known_color::light_cyan), csf_);
      assert::are_equal(known_color::light_cyan, enum_object<>::parse<known_color>("light_cyan"), csf_);
    }
    
    void test_method_(light_goldenrod_yellow) {
      assert::are_equal(68, enum_object<>::to_int32(known_color::light_goldenrod_yellow), csf_);
      assert::are_equal("light_goldenrod_yellow", enum_object<>::to_string(known_color::light_goldenrod_yellow), csf_);
      assert::are_equal(known_color::light_goldenrod_yellow, enum_object<>::parse<known_color>("light_goldenrod_yellow"), csf_);
    }
    
    void test_method_(light_gray) {
      assert::are_equal(69, enum_object<>::to_int32(known_color::light_gray), csf_);
      assert::are_equal("light_gray", enum_object<>::to_string(known_color::light_gray), csf_);
      assert::are_equal(known_color::light_gray, enum_object<>::parse<known_color>("light_gray"), csf_);
    }
    
    void test_method_(light_green) {
      assert::are_equal(70, enum_object<>::to_int32(known_color::light_green), csf_);
      assert::are_equal("light_green", enum_object<>::to_string(known_color::light_green), csf_);
      assert::are_equal(known_color::light_green, enum_object<>::parse<known_color>("light_green"), csf_);
    }
    
    void test_method_(light_pink) {
      assert::are_equal(71, enum_object<>::to_int32(known_color::light_pink), csf_);
      assert::are_equal("light_pink", enum_object<>::to_string(known_color::light_pink), csf_);
      assert::are_equal(known_color::light_pink, enum_object<>::parse<known_color>("light_pink"), csf_);
    }
    
    void test_method_(light_salmon) {
      assert::are_equal(72, enum_object<>::to_int32(known_color::light_salmon), csf_);
      assert::are_equal("light_salmon", enum_object<>::to_string(known_color::light_salmon), csf_);
      assert::are_equal(known_color::light_salmon, enum_object<>::parse<known_color>("light_salmon"), csf_);
    }
    
    void test_method_(light_sea_green) {
      assert::are_equal(73, enum_object<>::to_int32(known_color::light_sea_green), csf_);
      assert::are_equal("light_sea_green", enum_object<>::to_string(known_color::light_sea_green), csf_);
      assert::are_equal(known_color::light_sea_green, enum_object<>::parse<known_color>("light_sea_green"), csf_);
    }
    
    void test_method_(light_sky_blue) {
      assert::are_equal(74, enum_object<>::to_int32(known_color::light_sky_blue), csf_);
      assert::are_equal("light_sky_blue", enum_object<>::to_string(known_color::light_sky_blue), csf_);
      assert::are_equal(known_color::light_sky_blue, enum_object<>::parse<known_color>("light_sky_blue"), csf_);
    }
    
    void test_method_(light_slate_gray) {
      assert::are_equal(75, enum_object<>::to_int32(known_color::light_slate_gray), csf_);
      assert::are_equal("light_slate_gray", enum_object<>::to_string(known_color::light_slate_gray), csf_);
      assert::are_equal(known_color::light_slate_gray, enum_object<>::parse<known_color>("light_slate_gray"), csf_);
    }
    
    void test_method_(light_steel_blue) {
      assert::are_equal(76, enum_object<>::to_int32(known_color::light_steel_blue), csf_);
      assert::are_equal("light_steel_blue", enum_object<>::to_string(known_color::light_steel_blue), csf_);
      assert::are_equal(known_color::light_steel_blue, enum_object<>::parse<known_color>("light_steel_blue"), csf_);
    }
    
    void test_method_(light_yellow) {
      assert::are_equal(77, enum_object<>::to_int32(known_color::light_yellow), csf_);
      assert::are_equal("light_yellow", enum_object<>::to_string(known_color::light_yellow), csf_);
      assert::are_equal(known_color::light_yellow, enum_object<>::parse<known_color>("light_yellow"), csf_);
    }
    
    void test_method_(lime) {
      assert::are_equal(78, enum_object<>::to_int32(known_color::lime), csf_);
      assert::are_equal("lime", enum_object<>::to_string(known_color::lime), csf_);
      assert::are_equal(known_color::lime, enum_object<>::parse<known_color>("lime"), csf_);
    }
    
    void test_method_(lime_green) {
      assert::are_equal(79, enum_object<>::to_int32(known_color::lime_green), csf_);
      assert::are_equal("lime_green", enum_object<>::to_string(known_color::lime_green), csf_);
      assert::are_equal(known_color::lime_green, enum_object<>::parse<known_color>("lime_green"), csf_);
    }
    
    void test_method_(linen) {
      assert::are_equal(80, enum_object<>::to_int32(known_color::linen), csf_);
      assert::are_equal("linen", enum_object<>::to_string(known_color::linen), csf_);
      assert::are_equal(known_color::linen, enum_object<>::parse<known_color>("linen"), csf_);
    }
    
    void test_method_(magenta) {
      assert::are_equal(81, enum_object<>::to_int32(known_color::magenta), csf_);
      assert::are_equal("magenta", enum_object<>::to_string(known_color::magenta), csf_);
      assert::are_equal(known_color::magenta, enum_object<>::parse<known_color>("magenta"), csf_);
    }
    
    void test_method_(maroon) {
      assert::are_equal(82, enum_object<>::to_int32(known_color::maroon), csf_);
      assert::are_equal("maroon", enum_object<>::to_string(known_color::maroon), csf_);
      assert::are_equal(known_color::maroon, enum_object<>::parse<known_color>("maroon"), csf_);
    }
    
    void test_method_(medium_aquamarine) {
      assert::are_equal(83, enum_object<>::to_int32(known_color::medium_aquamarine), csf_);
      assert::are_equal("medium_aquamarine", enum_object<>::to_string(known_color::medium_aquamarine), csf_);
      assert::are_equal(known_color::medium_aquamarine, enum_object<>::parse<known_color>("medium_aquamarine"), csf_);
    }
    
    void test_method_(medium_blue) {
      assert::are_equal(84, enum_object<>::to_int32(known_color::medium_blue), csf_);
      assert::are_equal("medium_blue", enum_object<>::to_string(known_color::medium_blue), csf_);
      assert::are_equal(known_color::medium_blue, enum_object<>::parse<known_color>("medium_blue"), csf_);
    }
    
    void test_method_(medium_orchid) {
      assert::are_equal(85, enum_object<>::to_int32(known_color::medium_orchid), csf_);
      assert::are_equal("medium_orchid", enum_object<>::to_string(known_color::medium_orchid), csf_);
      assert::are_equal(known_color::medium_orchid, enum_object<>::parse<known_color>("medium_orchid"), csf_);
    }
    
    void test_method_(medium_purple) {
      assert::are_equal(86, enum_object<>::to_int32(known_color::medium_purple), csf_);
      assert::are_equal("medium_purple", enum_object<>::to_string(known_color::medium_purple), csf_);
      assert::are_equal(known_color::medium_purple, enum_object<>::parse<known_color>("medium_purple"), csf_);
    }
    
    void test_method_(medium_sea_green) {
      assert::are_equal(87, enum_object<>::to_int32(known_color::medium_sea_green), csf_);
      assert::are_equal("medium_sea_green", enum_object<>::to_string(known_color::medium_sea_green), csf_);
      assert::are_equal(known_color::medium_sea_green, enum_object<>::parse<known_color>("medium_sea_green"), csf_);
    }
    
    void test_method_(medium_slate_blue) {
      assert::are_equal(88, enum_object<>::to_int32(known_color::medium_slate_blue), csf_);
      assert::are_equal("medium_slate_blue", enum_object<>::to_string(known_color::medium_slate_blue), csf_);
      assert::are_equal(known_color::medium_slate_blue, enum_object<>::parse<known_color>("medium_slate_blue"), csf_);
    }
    
    void test_method_(medium_spring_green) {
      assert::are_equal(89, enum_object<>::to_int32(known_color::medium_spring_green), csf_);
      assert::are_equal("medium_spring_green", enum_object<>::to_string(known_color::medium_spring_green), csf_);
      assert::are_equal(known_color::medium_spring_green, enum_object<>::parse<known_color>("medium_spring_green"), csf_);
    }
    
    void test_method_(medium_turquoise) {
      assert::are_equal(90, enum_object<>::to_int32(known_color::medium_turquoise), csf_);
      assert::are_equal("medium_turquoise", enum_object<>::to_string(known_color::medium_turquoise), csf_);
      assert::are_equal(known_color::medium_turquoise, enum_object<>::parse<known_color>("medium_turquoise"), csf_);
    }
    
    void test_method_(medium_violet_red) {
      assert::are_equal(91, enum_object<>::to_int32(known_color::medium_violet_red), csf_);
      assert::are_equal("medium_violet_red", enum_object<>::to_string(known_color::medium_violet_red), csf_);
      assert::are_equal(known_color::medium_violet_red, enum_object<>::parse<known_color>("medium_violet_red"), csf_);
    }
    
    void test_method_(midnight_blue) {
      assert::are_equal(92, enum_object<>::to_int32(known_color::midnight_blue), csf_);
      assert::are_equal("midnight_blue", enum_object<>::to_string(known_color::midnight_blue), csf_);
      assert::are_equal(known_color::midnight_blue, enum_object<>::parse<known_color>("midnight_blue"), csf_);
    }
    
    void test_method_(mint_cream) {
      assert::are_equal(93, enum_object<>::to_int32(known_color::mint_cream), csf_);
      assert::are_equal("mint_cream", enum_object<>::to_string(known_color::mint_cream), csf_);
      assert::are_equal(known_color::mint_cream, enum_object<>::parse<known_color>("mint_cream"), csf_);
    }
    
    void test_method_(misty_rose) {
      assert::are_equal(94, enum_object<>::to_int32(known_color::misty_rose), csf_);
      assert::are_equal("misty_rose", enum_object<>::to_string(known_color::misty_rose), csf_);
      assert::are_equal(known_color::misty_rose, enum_object<>::parse<known_color>("misty_rose"), csf_);
    }
    
    void test_method_(moccasin) {
      assert::are_equal(95, enum_object<>::to_int32(known_color::moccasin), csf_);
      assert::are_equal("moccasin", enum_object<>::to_string(known_color::moccasin), csf_);
      assert::are_equal(known_color::moccasin, enum_object<>::parse<known_color>("moccasin"), csf_);
    }
    
    void test_method_(navajo_white) {
      assert::are_equal(96, enum_object<>::to_int32(known_color::navajo_white), csf_);
      assert::are_equal("navajo_white", enum_object<>::to_string(known_color::navajo_white), csf_);
      assert::are_equal(known_color::navajo_white, enum_object<>::parse<known_color>("navajo_white"), csf_);
    }
    
    void test_method_(navy) {
      assert::are_equal(97, enum_object<>::to_int32(known_color::navy), csf_);
      assert::are_equal("navy", enum_object<>::to_string(known_color::navy), csf_);
      assert::are_equal(known_color::navy, enum_object<>::parse<known_color>("navy"), csf_);
    }
    
    void test_method_(old_lace) {
      assert::are_equal(98, enum_object<>::to_int32(known_color::old_lace), csf_);
      assert::are_equal("old_lace", enum_object<>::to_string(known_color::old_lace), csf_);
      assert::are_equal(known_color::old_lace, enum_object<>::parse<known_color>("old_lace"), csf_);
    }
    
    void test_method_(olive) {
      assert::are_equal(99, enum_object<>::to_int32(known_color::olive), csf_);
      assert::are_equal("olive", enum_object<>::to_string(known_color::olive), csf_);
      assert::are_equal(known_color::olive, enum_object<>::parse<known_color>("olive"), csf_);
    }
    
    void test_method_(olive_drab) {
      assert::are_equal(100, enum_object<>::to_int32(known_color::olive_drab), csf_);
      assert::are_equal("olive_drab", enum_object<>::to_string(known_color::olive_drab), csf_);
      assert::are_equal(known_color::olive_drab, enum_object<>::parse<known_color>("olive_drab"), csf_);
    }
    
    void test_method_(orange) {
      assert::are_equal(101, enum_object<>::to_int32(known_color::orange), csf_);
      assert::are_equal("orange", enum_object<>::to_string(known_color::orange), csf_);
      assert::are_equal(known_color::orange, enum_object<>::parse<known_color>("orange"), csf_);
    }
    
    void test_method_(orange_red) {
      assert::are_equal(102, enum_object<>::to_int32(known_color::orange_red), csf_);
      assert::are_equal("orange_red", enum_object<>::to_string(known_color::orange_red), csf_);
      assert::are_equal(known_color::orange_red, enum_object<>::parse<known_color>("orange_red"), csf_);
    }
    
    void test_method_(orchid) {
      assert::are_equal(103, enum_object<>::to_int32(known_color::orchid), csf_);
      assert::are_equal("orchid", enum_object<>::to_string(known_color::orchid), csf_);
      assert::are_equal(known_color::orchid, enum_object<>::parse<known_color>("orchid"), csf_);
    }
    
    void test_method_(pale_goldenrod) {
      assert::are_equal(104, enum_object<>::to_int32(known_color::pale_goldenrod), csf_);
      assert::are_equal("pale_goldenrod", enum_object<>::to_string(known_color::pale_goldenrod), csf_);
      assert::are_equal(known_color::pale_goldenrod, enum_object<>::parse<known_color>("pale_goldenrod"), csf_);
    }
    
    void test_method_(pale_green) {
      assert::are_equal(105, enum_object<>::to_int32(known_color::pale_green), csf_);
      assert::are_equal("pale_green", enum_object<>::to_string(known_color::pale_green), csf_);
      assert::are_equal(known_color::pale_green, enum_object<>::parse<known_color>("pale_green"), csf_);
    }
    
    void test_method_(pale_turquoise) {
      assert::are_equal(106, enum_object<>::to_int32(known_color::pale_turquoise), csf_);
      assert::are_equal("pale_turquoise", enum_object<>::to_string(known_color::pale_turquoise), csf_);
      assert::are_equal(known_color::pale_turquoise, enum_object<>::parse<known_color>("pale_turquoise"), csf_);
    }
    
    void test_method_(pale_violet_red) {
      assert::are_equal(107, enum_object<>::to_int32(known_color::pale_violet_red), csf_);
      assert::are_equal("pale_violet_red", enum_object<>::to_string(known_color::pale_violet_red), csf_);
      assert::are_equal(known_color::pale_violet_red, enum_object<>::parse<known_color>("pale_violet_red"), csf_);
    }
    
    void test_method_(papaya_whip) {
      assert::are_equal(108, enum_object<>::to_int32(known_color::papaya_whip), csf_);
      assert::are_equal("papaya_whip", enum_object<>::to_string(known_color::papaya_whip), csf_);
      assert::are_equal(known_color::papaya_whip, enum_object<>::parse<known_color>("papaya_whip"), csf_);
    }
    
    void test_method_(peach_puff) {
      assert::are_equal(109, enum_object<>::to_int32(known_color::peach_puff), csf_);
      assert::are_equal("peach_puff", enum_object<>::to_string(known_color::peach_puff), csf_);
      assert::are_equal(known_color::peach_puff, enum_object<>::parse<known_color>("peach_puff"), csf_);
    }
    
    void test_method_(peru) {
      assert::are_equal(110, enum_object<>::to_int32(known_color::peru), csf_);
      assert::are_equal("peru", enum_object<>::to_string(known_color::peru), csf_);
      assert::are_equal(known_color::peru, enum_object<>::parse<known_color>("peru"), csf_);
    }
    
    void test_method_(pink) {
      assert::are_equal(111, enum_object<>::to_int32(known_color::pink), csf_);
      assert::are_equal("pink", enum_object<>::to_string(known_color::pink), csf_);
      assert::are_equal(known_color::pink, enum_object<>::parse<known_color>("pink"), csf_);
    }
    
    void test_method_(plum) {
      assert::are_equal(112, enum_object<>::to_int32(known_color::plum), csf_);
      assert::are_equal("plum", enum_object<>::to_string(known_color::plum), csf_);
      assert::are_equal(known_color::plum, enum_object<>::parse<known_color>("plum"), csf_);
    }
    
    void test_method_(powder_blue) {
      assert::are_equal(113, enum_object<>::to_int32(known_color::powder_blue), csf_);
      assert::are_equal("powder_blue", enum_object<>::to_string(known_color::powder_blue), csf_);
      assert::are_equal(known_color::powder_blue, enum_object<>::parse<known_color>("powder_blue"), csf_);
    }
    
    void test_method_(purple) {
      assert::are_equal(114, enum_object<>::to_int32(known_color::purple), csf_);
      assert::are_equal("purple", enum_object<>::to_string(known_color::purple), csf_);
      assert::are_equal(known_color::purple, enum_object<>::parse<known_color>("purple"), csf_);
    }
    
    void test_method_(rebecca_purple) {
      assert::are_equal(115, enum_object<>::to_int32(known_color::rebecca_purple), csf_);
      assert::are_equal("rebecca_purple", enum_object<>::to_string(known_color::rebecca_purple), csf_);
      assert::are_equal(known_color::rebecca_purple, enum_object<>::parse<known_color>("rebecca_purple"), csf_);
    }
    
    void test_method_(red) {
      assert::are_equal(116, enum_object<>::to_int32(known_color::red), csf_);
      assert::are_equal("red", enum_object<>::to_string(known_color::red), csf_);
      assert::are_equal(known_color::red, enum_object<>::parse<known_color>("red"), csf_);
    }
    
    void test_method_(rosy_brown) {
      assert::are_equal(117, enum_object<>::to_int32(known_color::rosy_brown), csf_);
      assert::are_equal("rosy_brown", enum_object<>::to_string(known_color::rosy_brown), csf_);
      assert::are_equal(known_color::rosy_brown, enum_object<>::parse<known_color>("rosy_brown"), csf_);
    }
    
    void test_method_(royal_blue) {
      assert::are_equal(118, enum_object<>::to_int32(known_color::royal_blue), csf_);
      assert::are_equal("royal_blue", enum_object<>::to_string(known_color::royal_blue), csf_);
      assert::are_equal(known_color::royal_blue, enum_object<>::parse<known_color>("royal_blue"), csf_);
    }
    
    void test_method_(saddle_brown) {
      assert::are_equal(119, enum_object<>::to_int32(known_color::saddle_brown), csf_);
      assert::are_equal("saddle_brown", enum_object<>::to_string(known_color::saddle_brown), csf_);
      assert::are_equal(known_color::saddle_brown, enum_object<>::parse<known_color>("saddle_brown"), csf_);
    }
    
    void test_method_(salmon) {
      assert::are_equal(120, enum_object<>::to_int32(known_color::salmon), csf_);
      assert::are_equal("salmon", enum_object<>::to_string(known_color::salmon), csf_);
      assert::are_equal(known_color::salmon, enum_object<>::parse<known_color>("salmon"), csf_);
    }
    
    void test_method_(sandy_brown) {
      assert::are_equal(121, enum_object<>::to_int32(known_color::sandy_brown), csf_);
      assert::are_equal("sandy_brown", enum_object<>::to_string(known_color::sandy_brown), csf_);
      assert::are_equal(known_color::sandy_brown, enum_object<>::parse<known_color>("sandy_brown"), csf_);
    }
    
    void test_method_(sea_green) {
      assert::are_equal(122, enum_object<>::to_int32(known_color::sea_green), csf_);
      assert::are_equal("sea_green", enum_object<>::to_string(known_color::sea_green), csf_);
      assert::are_equal(known_color::sea_green, enum_object<>::parse<known_color>("sea_green"), csf_);
    }
    
    void test_method_(sea_shell) {
      assert::are_equal(123, enum_object<>::to_int32(known_color::sea_shell), csf_);
      assert::are_equal("sea_shell", enum_object<>::to_string(known_color::sea_shell), csf_);
      assert::are_equal(known_color::sea_shell, enum_object<>::parse<known_color>("sea_shell"), csf_);
    }
    
    void test_method_(sienna) {
      assert::are_equal(124, enum_object<>::to_int32(known_color::sienna), csf_);
      assert::are_equal("sienna", enum_object<>::to_string(known_color::sienna), csf_);
      assert::are_equal(known_color::sienna, enum_object<>::parse<known_color>("sienna"), csf_);
    }
    
    void test_method_(silver) {
      assert::are_equal(125, enum_object<>::to_int32(known_color::silver), csf_);
      assert::are_equal("silver", enum_object<>::to_string(known_color::silver), csf_);
      assert::are_equal(known_color::silver, enum_object<>::parse<known_color>("silver"), csf_);
    }
    
    void test_method_(sky_blue) {
      assert::are_equal(126, enum_object<>::to_int32(known_color::sky_blue), csf_);
      assert::are_equal("sky_blue", enum_object<>::to_string(known_color::sky_blue), csf_);
      assert::are_equal(known_color::sky_blue, enum_object<>::parse<known_color>("sky_blue"), csf_);
    }
    
    void test_method_(slate_blue) {
      assert::are_equal(127, enum_object<>::to_int32(known_color::slate_blue), csf_);
      assert::are_equal("slate_blue", enum_object<>::to_string(known_color::slate_blue), csf_);
      assert::are_equal(known_color::slate_blue, enum_object<>::parse<known_color>("slate_blue"), csf_);
    }
    
    void test_method_(slate_gray) {
      assert::are_equal(128, enum_object<>::to_int32(known_color::slate_gray), csf_);
      assert::are_equal("slate_gray", enum_object<>::to_string(known_color::slate_gray), csf_);
      assert::are_equal(known_color::slate_gray, enum_object<>::parse<known_color>("slate_gray"), csf_);
    }
    
    void test_method_(snow) {
      assert::are_equal(129, enum_object<>::to_int32(known_color::snow), csf_);
      assert::are_equal("snow", enum_object<>::to_string(known_color::snow), csf_);
      assert::are_equal(known_color::snow, enum_object<>::parse<known_color>("snow"), csf_);
    }
    
    void test_method_(spring_green) {
      assert::are_equal(130, enum_object<>::to_int32(known_color::spring_green), csf_);
      assert::are_equal("spring_green", enum_object<>::to_string(known_color::spring_green), csf_);
      assert::are_equal(known_color::spring_green, enum_object<>::parse<known_color>("spring_green"), csf_);
    }
    
    void test_method_(steel_blue) {
      assert::are_equal(131, enum_object<>::to_int32(known_color::steel_blue), csf_);
      assert::are_equal("steel_blue", enum_object<>::to_string(known_color::steel_blue), csf_);
      assert::are_equal(known_color::steel_blue, enum_object<>::parse<known_color>("steel_blue"), csf_);
    }
    
    void test_method_(tan) {
      assert::are_equal(132, enum_object<>::to_int32(known_color::tan), csf_);
      assert::are_equal("tan", enum_object<>::to_string(known_color::tan), csf_);
      assert::are_equal(known_color::tan, enum_object<>::parse<known_color>("tan"), csf_);
    }
    
    void test_method_(teal) {
      assert::are_equal(133, enum_object<>::to_int32(known_color::teal), csf_);
      assert::are_equal("teal", enum_object<>::to_string(known_color::teal), csf_);
      assert::are_equal(known_color::teal, enum_object<>::parse<known_color>("teal"), csf_);
    }
    
    void test_method_(thistle) {
      assert::are_equal(134, enum_object<>::to_int32(known_color::thistle), csf_);
      assert::are_equal("thistle", enum_object<>::to_string(known_color::thistle), csf_);
      assert::are_equal(known_color::thistle, enum_object<>::parse<known_color>("thistle"), csf_);
    }
    
    void test_method_(tomato) {
      assert::are_equal(135, enum_object<>::to_int32(known_color::tomato), csf_);
      assert::are_equal("tomato", enum_object<>::to_string(known_color::tomato), csf_);
      assert::are_equal(known_color::tomato, enum_object<>::parse<known_color>("tomato"), csf_);
    }
    
    void test_method_(turquoise) {
      assert::are_equal(136, enum_object<>::to_int32(known_color::turquoise), csf_);
      assert::are_equal("turquoise", enum_object<>::to_string(known_color::turquoise), csf_);
      assert::are_equal(known_color::turquoise, enum_object<>::parse<known_color>("turquoise"), csf_);
    }
    
    void test_method_(violet) {
      assert::are_equal(137, enum_object<>::to_int32(known_color::violet), csf_);
      assert::are_equal("violet", enum_object<>::to_string(known_color::violet), csf_);
      assert::are_equal(known_color::violet, enum_object<>::parse<known_color>("violet"), csf_);
    }
    
    void test_method_(wheat) {
      assert::are_equal(138, enum_object<>::to_int32(known_color::wheat), csf_);
      assert::are_equal("wheat", enum_object<>::to_string(known_color::wheat), csf_);
      assert::are_equal(known_color::wheat, enum_object<>::parse<known_color>("wheat"), csf_);
    }
    
    void test_method_(white) {
      assert::are_equal(139, enum_object<>::to_int32(known_color::white), csf_);
      assert::are_equal("white", enum_object<>::to_string(known_color::white), csf_);
      assert::are_equal(known_color::white, enum_object<>::parse<known_color>("white"), csf_);
    }
    
    void test_method_(white_smoke) {
      assert::are_equal(140, enum_object<>::to_int32(known_color::white_smoke), csf_);
      assert::are_equal("white_smoke", enum_object<>::to_string(known_color::white_smoke), csf_);
      assert::are_equal(known_color::white_smoke, enum_object<>::parse<known_color>("white_smoke"), csf_);
    }
    
    void test_method_(yellow) {
      assert::are_equal(141, enum_object<>::to_int32(known_color::yellow), csf_);
      assert::are_equal("yellow", enum_object<>::to_string(known_color::yellow), csf_);
      assert::are_equal(known_color::yellow, enum_object<>::parse<known_color>("yellow"), csf_);
    }
    
    void test_method_(yellow_green) {
      assert::are_equal(142, enum_object<>::to_int32(known_color::yellow_green), csf_);
      assert::are_equal("yellow_green", enum_object<>::to_string(known_color::yellow_green), csf_);
      assert::are_equal(known_color::yellow_green, enum_object<>::parse<known_color>("yellow_green"), csf_);
    }
    
    void test_method_(accent) {
      assert::are_equal(65281, enum_object<>::to_int32(known_color::accent), csf_);
      assert::are_equal("accent", enum_object<>::to_string(known_color::accent), csf_);
      assert::are_equal(known_color::accent, enum_object<>::parse<known_color>("accent"), csf_);
    }
    
    void test_method_(accent_text) {
      assert::are_equal(65282, enum_object<>::to_int32(known_color::accent_text), csf_);
      assert::are_equal("accent_text", enum_object<>::to_string(known_color::accent_text), csf_);
      assert::are_equal(known_color::accent_text, enum_object<>::parse<known_color>("accent_text"), csf_);
    }
    
    void test_method_(active_border) {
      assert::are_equal(65283, enum_object<>::to_int32(known_color::active_border), csf_);
      assert::are_equal("active_border", enum_object<>::to_string(known_color::active_border), csf_);
      assert::are_equal(known_color::active_border, enum_object<>::parse<known_color>("active_border"), csf_);
    }
    
    void test_method_(active_caption) {
      assert::are_equal(65284, enum_object<>::to_int32(known_color::active_caption), csf_);
      assert::are_equal("active_caption", enum_object<>::to_string(known_color::active_caption), csf_);
      assert::are_equal(known_color::active_caption, enum_object<>::parse<known_color>("active_caption"), csf_);
    }
    
    void test_method_(active_caption_text) {
      assert::are_equal(65285, enum_object<>::to_int32(known_color::active_caption_text), csf_);
      assert::are_equal("active_caption_text", enum_object<>::to_string(known_color::active_caption_text), csf_);
      assert::are_equal(known_color::active_caption_text, enum_object<>::parse<known_color>("active_caption_text"), csf_);
    }
    
    void test_method_(active_text) {
      assert::are_equal(65286, enum_object<>::to_int32(known_color::active_text), csf_);
      assert::are_equal("active_text", enum_object<>::to_string(known_color::active_text), csf_);
      assert::are_equal(known_color::active_text, enum_object<>::parse<known_color>("active_text"), csf_);
    }
    
    void test_method_(app_workspace) {
      assert::are_equal(65287, enum_object<>::to_int32(known_color::app_workspace), csf_);
      assert::are_equal("app_workspace", enum_object<>::to_string(known_color::app_workspace), csf_);
      assert::are_equal(known_color::app_workspace, enum_object<>::parse<known_color>("app_workspace"), csf_);
    }
    
    void test_method_(button_face) {
      assert::are_equal(65288, enum_object<>::to_int32(known_color::button_face), csf_);
      assert::are_equal("button_face", enum_object<>::to_string(known_color::button_face), csf_);
      assert::are_equal(known_color::button_face, enum_object<>::parse<known_color>("button_face"), csf_);
    }
    
    void test_method_(button_highlight) {
      assert::are_equal(65289, enum_object<>::to_int32(known_color::button_highlight), csf_);
      assert::are_equal("button_highlight", enum_object<>::to_string(known_color::button_highlight), csf_);
      assert::are_equal(known_color::button_highlight, enum_object<>::parse<known_color>("button_highlight"), csf_);
    }
    
    void test_method_(button_shadow) {
      assert::are_equal(65290, enum_object<>::to_int32(known_color::button_shadow), csf_);
      assert::are_equal("button_shadow", enum_object<>::to_string(known_color::button_shadow), csf_);
      assert::are_equal(known_color::button_shadow, enum_object<>::parse<known_color>("button_shadow"), csf_);
    }
    
    void test_method_(control) {
      assert::are_equal(65291, enum_object<>::to_int32(known_color::control), csf_);
      assert::are_equal("control", enum_object<>::to_string(known_color::control), csf_);
      assert::are_equal(known_color::control, enum_object<>::parse<known_color>("control"), csf_);
    }
    
    void test_method_(control_dark) {
      assert::are_equal(65292, enum_object<>::to_int32(known_color::control_dark), csf_);
      assert::are_equal("control_dark", enum_object<>::to_string(known_color::control_dark), csf_);
      assert::are_equal(known_color::control_dark, enum_object<>::parse<known_color>("control_dark"), csf_);
    }
    
    void test_method_(control_dark_dark) {
      assert::are_equal(65293, enum_object<>::to_int32(known_color::control_dark_dark), csf_);
      assert::are_equal("control_dark_dark", enum_object<>::to_string(known_color::control_dark_dark), csf_);
      assert::are_equal(known_color::control_dark_dark, enum_object<>::parse<known_color>("control_dark_dark"), csf_);
    }
    
    void test_method_(control_light) {
      assert::are_equal(65294, enum_object<>::to_int32(known_color::control_light), csf_);
      assert::are_equal("control_light", enum_object<>::to_string(known_color::control_light), csf_);
      assert::are_equal(known_color::control_light, enum_object<>::parse<known_color>("control_light"), csf_);
    }
    
    void test_method_(control_light_light) {
      assert::are_equal(65295, enum_object<>::to_int32(known_color::control_light_light), csf_);
      assert::are_equal("control_light_light", enum_object<>::to_string(known_color::control_light_light), csf_);
      assert::are_equal(known_color::control_light_light, enum_object<>::parse<known_color>("control_light_light"), csf_);
    }
    
    void test_method_(control_text) {
      assert::are_equal(65296, enum_object<>::to_int32(known_color::control_text), csf_);
      assert::are_equal("control_text", enum_object<>::to_string(known_color::control_text), csf_);
      assert::are_equal(known_color::control_text, enum_object<>::parse<known_color>("control_text"), csf_);
    }
    
    void test_method_(desktop) {
      assert::are_equal(65297, enum_object<>::to_int32(known_color::desktop), csf_);
      assert::are_equal("desktop", enum_object<>::to_string(known_color::desktop), csf_);
      assert::are_equal(known_color::desktop, enum_object<>::parse<known_color>("desktop"), csf_);
    }
    
    void test_method_(gradient_active_caption) {
      assert::are_equal(65298, enum_object<>::to_int32(known_color::gradient_active_caption), csf_);
      assert::are_equal("gradient_active_caption", enum_object<>::to_string(known_color::gradient_active_caption), csf_);
      assert::are_equal(known_color::gradient_active_caption, enum_object<>::parse<known_color>("gradient_active_caption"), csf_);
    }
    
    void test_method_(gradient_inactive_caption) {
      assert::are_equal(65299, enum_object<>::to_int32(known_color::gradient_inactive_caption), csf_);
      assert::are_equal("gradient_inactive_caption", enum_object<>::to_string(known_color::gradient_inactive_caption), csf_);
      assert::are_equal(known_color::gradient_inactive_caption, enum_object<>::parse<known_color>("gradient_inactive_caption"), csf_);
    }
    
    void test_method_(gray_text) {
      assert::are_equal(65300, enum_object<>::to_int32(known_color::gray_text), csf_);
      assert::are_equal("gray_text", enum_object<>::to_string(known_color::gray_text), csf_);
      assert::are_equal(known_color::gray_text, enum_object<>::parse<known_color>("gray_text"), csf_);
    }
    
    void test_method_(highlight) {
      assert::are_equal(65301, enum_object<>::to_int32(known_color::highlight), csf_);
      assert::are_equal("highlight", enum_object<>::to_string(known_color::highlight), csf_);
      assert::are_equal(known_color::highlight, enum_object<>::parse<known_color>("highlight"), csf_);
    }
    
    void test_method_(highlight_text) {
      assert::are_equal(65302, enum_object<>::to_int32(known_color::highlight_text), csf_);
      assert::are_equal("highlight_text", enum_object<>::to_string(known_color::highlight_text), csf_);
      assert::are_equal(known_color::highlight_text, enum_object<>::parse<known_color>("highlight_text"), csf_);
    }
    
    void test_method_(hot_track) {
      assert::are_equal(65303, enum_object<>::to_int32(known_color::hot_track), csf_);
      assert::are_equal("hot_track", enum_object<>::to_string(known_color::hot_track), csf_);
      assert::are_equal(known_color::hot_track, enum_object<>::parse<known_color>("hot_track"), csf_);
    }
    
    void test_method_(inactive_border) {
      assert::are_equal(65304, enum_object<>::to_int32(known_color::inactive_border), csf_);
      assert::are_equal("inactive_border", enum_object<>::to_string(known_color::inactive_border), csf_);
      assert::are_equal(known_color::inactive_border, enum_object<>::parse<known_color>("inactive_border"), csf_);
    }
    
    void test_method_(inactive_caption) {
      assert::are_equal(65305, enum_object<>::to_int32(known_color::inactive_caption), csf_);
      assert::are_equal("inactive_caption", enum_object<>::to_string(known_color::inactive_caption), csf_);
      assert::are_equal(known_color::inactive_caption, enum_object<>::parse<known_color>("inactive_caption"), csf_);
    }
    
    void test_method_(inactive_caption_text) {
      assert::are_equal(65306, enum_object<>::to_int32(known_color::inactive_caption_text), csf_);
      assert::are_equal("inactive_caption_text", enum_object<>::to_string(known_color::inactive_caption_text), csf_);
      assert::are_equal(known_color::inactive_caption_text, enum_object<>::parse<known_color>("inactive_caption_text"), csf_);
    }
    
    void test_method_(info) {
      assert::are_equal(65307, enum_object<>::to_int32(known_color::info), csf_);
      assert::are_equal("info", enum_object<>::to_string(known_color::info), csf_);
      assert::are_equal(known_color::info, enum_object<>::parse<known_color>("info"), csf_);
    }
    
    void test_method_(info_text) {
      assert::are_equal(65308, enum_object<>::to_int32(known_color::info_text), csf_);
      assert::are_equal("info_text", enum_object<>::to_string(known_color::info_text), csf_);
      assert::are_equal(known_color::info_text, enum_object<>::parse<known_color>("info_text"), csf_);
    }
    
    void test_method_(link_text) {
      assert::are_equal(65309, enum_object<>::to_int32(known_color::link_text), csf_);
      assert::are_equal("link_text", enum_object<>::to_string(known_color::link_text), csf_);
      assert::are_equal(known_color::link_text, enum_object<>::parse<known_color>("link_text"), csf_);
    }
    
    void test_method_(menu) {
      assert::are_equal(65310, enum_object<>::to_int32(known_color::menu), csf_);
      assert::are_equal("menu", enum_object<>::to_string(known_color::menu), csf_);
      assert::are_equal(known_color::menu, enum_object<>::parse<known_color>("menu"), csf_);
    }
    
    void test_method_(menu_bar) {
      assert::are_equal(65311, enum_object<>::to_int32(known_color::menu_bar), csf_);
      assert::are_equal("menu_bar", enum_object<>::to_string(known_color::menu_bar), csf_);
      assert::are_equal(known_color::menu_bar, enum_object<>::parse<known_color>("menu_bar"), csf_);
    }
    
    void test_method_(menu_highlight) {
      assert::are_equal(65312, enum_object<>::to_int32(known_color::menu_highlight), csf_);
      assert::are_equal("menu_highlight", enum_object<>::to_string(known_color::menu_highlight), csf_);
      assert::are_equal(known_color::menu_highlight, enum_object<>::parse<known_color>("menu_highlight"), csf_);
    }
    
    void test_method_(menu_text) {
      assert::are_equal(65313, enum_object<>::to_int32(known_color::menu_text), csf_);
      assert::are_equal("menu_text", enum_object<>::to_string(known_color::menu_text), csf_);
      assert::are_equal(known_color::menu_text, enum_object<>::parse<known_color>("menu_text"), csf_);
    }
    
    void test_method_(scroll_bar) {
      assert::are_equal(65314, enum_object<>::to_int32(known_color::scroll_bar), csf_);
      assert::are_equal("scroll_bar", enum_object<>::to_string(known_color::scroll_bar), csf_);
      assert::are_equal(known_color::scroll_bar, enum_object<>::parse<known_color>("scroll_bar"), csf_);
    }
    
    void test_method_(text_box) {
      assert::are_equal(65316, enum_object<>::to_int32(known_color::text_box), csf_);
      assert::are_equal("text_box", enum_object<>::to_string(known_color::text_box), csf_);
      assert::are_equal(known_color::text_box, enum_object<>::parse<known_color>("text_box"), csf_);
    }
    
    void test_method_(text_box_text) {
      assert::are_equal(65317, enum_object<>::to_int32(known_color::text_box_text), csf_);
      assert::are_equal("text_box_text", enum_object<>::to_string(known_color::text_box_text), csf_);
      assert::are_equal(known_color::text_box_text, enum_object<>::parse<known_color>("text_box_text"), csf_);
    }
    
    void test_method_(visited_text) {
      assert::are_equal(65318, enum_object<>::to_int32(known_color::visited_text), csf_);
      assert::are_equal("visited_text", enum_object<>::to_string(known_color::visited_text), csf_);
      assert::are_equal(known_color::visited_text, enum_object<>::parse<known_color>("visited_text"), csf_);
    }
    
    void test_method_(window) {
      assert::are_equal(65319, enum_object<>::to_int32(known_color::window), csf_);
      assert::are_equal("window", enum_object<>::to_string(known_color::window), csf_);
      assert::are_equal(known_color::window, enum_object<>::parse<known_color>("window"), csf_);
    }
    
    void test_method_(window_frame) {
      assert::are_equal(65320, enum_object<>::to_int32(known_color::window_frame), csf_);
      assert::are_equal("window_frame", enum_object<>::to_string(known_color::window_frame), csf_);
      assert::are_equal(known_color::window_frame, enum_object<>::parse<known_color>("window_frame"), csf_);
    }
    
    void test_method_(window_text) {
      assert::are_equal(65321, enum_object<>::to_int32(known_color::window_text), csf_);
      assert::are_equal("window_text", enum_object<>::to_string(known_color::window_text), csf_);
      assert::are_equal(known_color::window_text, enum_object<>::parse<known_color>("window_text"), csf_);
    }
  };
}
