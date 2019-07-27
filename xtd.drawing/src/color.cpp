#include "../include/xtd/color.hpp"
#include <cmath>
#include <map>
#include <stdexcept>
#include <xtd/xtd.strings>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

const color color::empty = color();

const color color::transparent = color::from_known_color(known_color::transparent);

const color color::alice_blue = color::from_known_color(known_color::alice_blue);

const color color::antique_white = color::from_known_color(known_color::antique_white);

const color color::aqua = color::from_known_color(known_color::aqua);

const color color::aquamarine = color::from_known_color(known_color::aquamarine);

const color color::azure = color::from_known_color(known_color::azure);

const color color::beige = color::from_known_color(known_color::beige);

const color color::bisque = color::from_known_color(known_color::bisque);

const color color::black = color::from_known_color(known_color::black);

const color color::blanched_almond = color::from_known_color(known_color::blanched_almond);

const color color::blue = color::from_known_color(known_color::blue);

const color color::blue_violet = color::from_known_color(known_color::blue_violet);

const color color::brown = color::from_known_color(known_color::brown);

const color color::burly_wood = color::from_known_color(known_color::burly_wood);

const color color::cadet_blue = color::from_known_color(known_color::cadet_blue);

const color color::chartreuse = color::from_known_color(known_color::chartreuse);

const color color::chocolate = color::from_known_color(known_color::chocolate);

const color color::coral = color::from_known_color(known_color::coral);

const color color::cornflower_blue = color::from_known_color(known_color::cornflower_blue);

const color color::cornsilk = color::from_known_color(known_color::cornsilk);

const color color::crimson = color::from_known_color(known_color::crimson);

const color color::cyan = color::from_known_color(known_color::cyan);

const color color::dark_blue = color::from_known_color(known_color::dark_blue);

const color color::dark_cyan = color::from_known_color(known_color::dark_cyan);

const color color::dark_goldenrod = color::from_known_color(known_color::dark_goldenrod);

const color color::dark_gray = color::from_known_color(known_color::dark_gray);

const color color::dark_green = color::from_known_color(known_color::dark_green);

const color color::dark_khaki = color::from_known_color(known_color::dark_khaki);

const color color::dark_magenta = color::from_known_color(known_color::dark_magenta);

const color color::dark_oliveGreen = color::from_known_color(known_color::dark_oliveGreen);

const color color::dark_orange = color::from_known_color(known_color::dark_orange);

const color color::dark_orchid = color::from_known_color(known_color::dark_orchid);

const color color::dark_red = color::from_known_color(known_color::dark_red);

const color color::dark_salmon = color::from_known_color(known_color::dark_salmon);

const color color::dark_sea_green = color::from_known_color(known_color::dark_sea_green);

const color color::dark_slate_blue = color::from_known_color(known_color::dark_slate_blue);

const color color::dark_slate_gray = color::from_known_color(known_color::dark_slate_gray);

const color color::dark_turquoise = color::from_known_color(known_color::dark_turquoise);

const color color::dark_violet = color::from_known_color(known_color::dark_violet);

const color color::deep_pink = color::from_known_color(known_color::deep_pink);

const color color::deep_sky_blue = color::from_known_color(known_color::deep_sky_blue);

const color color::dim_gray = color::from_known_color(known_color::dim_gray);

const color color::dodger_blue = color::from_known_color(known_color::dodger_blue);

const color color::firebrick = color::from_known_color(known_color::firebrick);

const color color::floral_white = color::from_known_color(known_color::floral_white);

const color color::forest_green = color::from_known_color(known_color::forest_green);

const color color::fuchsia = color::from_known_color(known_color::fuchsia);

const color color::gainsboro = color::from_known_color(known_color::gainsboro);

const color color::ghost_white = color::from_known_color(known_color::ghost_white);

const color color::gold = color::from_known_color(known_color::gold);

const color color::goldenrod = color::from_known_color(known_color::goldenrod);

const color color::gray = color::from_known_color(known_color::gray);

const color color::green = color::from_known_color(known_color::green);

const color color::green_yellow = color::from_known_color(known_color::green_yellow);

const color color::honeydew = color::from_known_color(known_color::honeydew);

const color color::hot_pink = color::from_known_color(known_color::hot_pink);

const color color::indian_red = color::from_known_color(known_color::indian_red);

const color color::indigo = color::from_known_color(known_color::indigo);

const color color::ivory = color::from_known_color(known_color::ivory);

const color color::khaki = color::from_known_color(known_color::khaki);

const color color::lavender = color::from_known_color(known_color::lavender);

const color color::lavender_blush = color::from_known_color(known_color::lavender_blush);

const color color::lawn_green = color::from_known_color(known_color::lawn_green);

const color color::lemon_chiffon = color::from_known_color(known_color::lemon_chiffon);

const color color::light_blue = color::from_known_color(known_color::light_blue);

const color color::light_coral = color::from_known_color(known_color::light_coral);

const color color::light_cyan = color::from_known_color(known_color::light_cyan);

const color color::light_goldenrod_yellow = color::from_known_color(known_color::light_goldenrod_yellow);

const color color::light_gray = color::from_known_color(known_color::light_gray);

const color color::light_green = color::from_known_color(known_color::light_green);

const color color::light_pink = color::from_known_color(known_color::light_pink);

const color color::light_salmon = color::from_known_color(known_color::light_salmon);

const color color::light_sea_green = color::from_known_color(known_color::light_sea_green);

const color color::light_sky_blue = color::from_known_color(known_color::light_sky_blue);

const color color::light_slate_gray = color::from_known_color(known_color::light_slate_gray);

const color color::light_steel_blue = color::from_known_color(known_color::light_steel_blue);

const color color::light_yellow = color::from_known_color(known_color::light_yellow);

const color color::lime = color::from_known_color(known_color::lime);

const color color::lime_green = color::from_known_color(known_color::lime_green);

const color color::linen = color::from_known_color(known_color::linen);

const color color::magenta = color::from_known_color(known_color::magenta);

const color color::maroon = color::from_known_color(known_color::maroon);

const color color::medium_aquamarine = color::from_known_color(known_color::medium_aquamarine);

const color color::medium_blue = color::from_known_color(known_color::medium_blue);

const color color::medium_orchid = color::from_known_color(known_color::medium_orchid);

const color color::medium_purple = color::from_known_color(known_color::medium_purple);

const color color::medium_sea_green = color::from_known_color(known_color::medium_sea_green);

const color color::medium_slate_blue = color::from_known_color(known_color::medium_slate_blue);

const color color::medium_spring_green = color::from_known_color(known_color::medium_spring_green);

const color color::medium_turquoise = color::from_known_color(known_color::medium_turquoise);

const color color::medium_violet_red = color::from_known_color(known_color::medium_violet_red);

const color color::midnight_blue = color::from_known_color(known_color::midnight_blue);

const color color::mint_cream = color::from_known_color(known_color::mint_cream);

const color color::misty_rose = color::from_known_color(known_color::misty_rose);

const color color::moccasin = color::from_known_color(known_color::moccasin);

const color color::navajo_white = color::from_known_color(known_color::navajo_white);

const color color::navy = color::from_known_color(known_color::navy);

const color color::old_lace = color::from_known_color(known_color::old_lace);

const color color::olive = color::from_known_color(known_color::olive);

const color color::olive_drab = color::from_known_color(known_color::olive_drab);

const color color::orange = color::from_known_color(known_color::orange);

const color color::orange_red = color::from_known_color(known_color::orange_red);

const color color::orchid = color::from_known_color(known_color::orchid);

const color color::pale_goldenrod = color::from_known_color(known_color::pale_goldenrod);

const color color::pale_green = color::from_known_color(known_color::pale_green);

const color color::pale_turquoise = color::from_known_color(known_color::pale_turquoise);

const color color::pale_violet_red = color::from_known_color(known_color::pale_violet_red);

const color color::papaya_whip = color::from_known_color(known_color::papaya_whip);

const color color::peach_puff = color::from_known_color(known_color::peach_puff);

const color color::peru = color::from_known_color(known_color::peru);

const color color::pink = color::from_known_color(known_color::pink);

const color color::plum = color::from_known_color(known_color::plum);

const color color::powder_blue = color::from_known_color(known_color::powder_blue);

const color color::purple = color::from_known_color(known_color::purple);

const color color::red = color::from_known_color(known_color::red);

const color color::rosy_brown = color::from_known_color(known_color::rosy_brown);

const color color::royal_blue = color::from_known_color(known_color::royal_blue);

const color color::saddle_brown = color::from_known_color(known_color::saddle_brown);

const color color::salmon = color::from_known_color(known_color::salmon);

const color color::sandy_brown = color::from_known_color(known_color::sandy_brown);

const color color::sea_green = color::from_known_color(known_color::sea_green);

const color color::sea_shell = color::from_known_color(known_color::sea_shell);

const color color::sienna = color::from_known_color(known_color::sienna);

const color color::silver = color::from_known_color(known_color::silver);

const color color::sky_blue = color::from_known_color(known_color::sky_blue);

const color color::slate_blue = color::from_known_color(known_color::slate_blue);

const color color::slate_gray = color::from_known_color(known_color::slate_gray);

const color color::snow = color::from_known_color(known_color::snow);

const color color::spring_green = color::from_known_color(known_color::spring_green);

const color color::steel_blue = color::from_known_color(known_color::steel_blue);

const color color::tan = color::from_known_color(known_color::tan);

const color color::teal = color::from_known_color(known_color::teal);

const color color::thistle = color::from_known_color(known_color::thistle);

const color color::tomato = color::from_known_color(known_color::tomato);

const color color::turquoise = color::from_known_color(known_color::turquoise);

const color color::violet = color::from_known_color(known_color::violet);

const color color::wheat = color::from_known_color(known_color::wheat);

const color color::white = color::from_known_color(known_color::white);

const color color::white_smoke = color::from_known_color(known_color::white_smoke);

const color color::yellow = color::from_known_color(known_color::yellow);

const color color::yellow_green = color::from_known_color(known_color::yellow_green);

color::color(int argb) : argb(argb) {
}

color::color(int argb, const known_color& color) : argb(argb), known_color_(color) {
}

color::color(const color& color) : argb(color.argb), known_color_(color.known_color_) {
}

bool color::is_system_color() const {
  return this->known_color_ != (known_color)0 && (this->known_color_ <= known_color::window_text || this->known_color_ >= drawing::known_color::button_face);
}

string color::name() const {
  if (this->known_color_ == (known_color)0 && this->argb == 0)
    return "0";
  
  /*
   if (this->knownColor != (known_color)0 || this->argb == 0)
   return Enum<>::GetName<known_color>(this->knownColor);
   */
  
  return strings::format("{0:X8}", this->argb);
}

color color::from_argb(int argb) {
  return color(argb);
}

color color::from_argb(int alpha, const color& baseColor) {
  if (alpha < 0 || alpha > 255)
    throw invalid_argument("alpha value must be between 0 and 255");
  
  return color((alpha << 24) + (baseColor.argb & 0x00FFFFFF));
}

color color::from_argb(int alpha, int red, int green, int blue) {
  if (alpha < 0 || alpha > 255 || red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255)
    throw invalid_argument("alpha, red, green and blue values must be between 0 and 255");
  
  return color((alpha << 24) + (red << 16) + (green << 8) + blue);
}

color color::from_hsb(float hue, float saturation, float brightness) {
  // algorithm version (see https://www.programmingalgorithms.com/algorithm/hsv-to-rgb)
  if (saturation == 0)
    return color::from_argb(255, (unsigned char)(brightness * 255.0f), (unsigned char)(brightness * 255.0f), (unsigned char)(brightness * 255.0f));
  
  hue = hue == 360 ? 0 : hue / 60;
  
  float f = hue - (float)trunc(hue);
  float p = brightness * (1.0f - saturation);
  float q = brightness * (1.0f - (saturation * f));
  float t = brightness * (1.0f - (saturation * (1.0f - f)));
  
  switch ((int)trunc(hue)) {
    case 0: return color::from_argb(255, (unsigned char)(brightness * 255.0f), (unsigned char)(t * 255.0f), (unsigned char)(p * 255.0f));
    case 1: return color::from_argb(255, (unsigned char)(q * 255.0f), (unsigned char)(brightness * 255.0f), (unsigned char)(p * 255.0f));
    case 2: return color::from_argb(255, (unsigned char)(p * 255.0f), (unsigned char)(brightness * 255.0f), (unsigned char)(t * 255.0f));
    case 3: return color::from_argb(255, (unsigned char)(p * 255.0f), (unsigned char)(q * 255.0f), (unsigned char)(brightness * 255.0f));
    case 4: return color::from_argb(255, (unsigned char)(t * 255.0f), (unsigned char)(p * 255.0f), (unsigned char)(brightness * 255.0f));
    default: return color::from_argb(255, (unsigned char)(brightness * 255.0f), (unsigned char)(p * 255.0f), (unsigned char)(q * 255.0f));
  }
}

color color::from_name(const string& name) {
  //return color::from_known_color((known_color)Enum<>::Parse<known_color>(name));
  return color::empty;
}

color color::from_known_color(known_color color) {
  static map<known_color, unsigned int> known_colors {
    /*
    {known_color::active_border, Native::SystemColorsApi::GetActiveBorder()},
    {known_color::active_caption, Native::SystemColorsApi::GetActiveCaption()},
    {known_color::active_caption_text, Native::SystemColorsApi::GetActiveCaptionText()},
    {known_color::app_workspace, Native::SystemColorsApi::GetAppWorkspace()},
    {known_color::control, Native::SystemColorsApi::GetControl()},
    {known_color::control_dark, Native::SystemColorsApi::GetControlDark()},
    {known_color::control_dark_dark, Native::SystemColorsApi::GetControlDarkDark()},
    {known_color::control_light, Native::SystemColorsApi::GetControlLight()},
    {known_color::control_light_light, Native::SystemColorsApi::GetControlLightLight()},
    {known_color::control_text, Native::SystemColorsApi::GetControlText()},
    {known_color::Desktop, Native::SystemColorsApi::GetDesktop()},
    {known_color::gray_text, Native::SystemColorsApi::GetGrayText()},
    {known_color::highlight, Native::SystemColorsApi::GetHighlight()},
    {known_color::highlight_text, Native::SystemColorsApi::GetHighlightText()},
    {known_color::hot_track, Native::SystemColorsApi::GetHotTrack()},
    {known_color::inactive_border, Native::SystemColorsApi::GetInactiveBorder()},
    {known_color::inactive_caption, Native::SystemColorsApi::GetInactiveCaption()},
    {known_color::inactive_caption_text, Native::SystemColorsApi::GetInactiveCaptionText()},
    {known_color::info, Native::SystemColorsApi::GetInfo()},
    {known_color::info_text, Native::SystemColorsApi::GetInfoText()},
    {known_color::menu, Native::SystemColorsApi::GetMenu()},
    {known_color::menu_text, Native::SystemColorsApi::GetMenuText()},
    {known_color::scroll_bar, Native::SystemColorsApi::GetScrollBar()},
    {known_color::window, Native::SystemColorsApi::GetWindow()},
    {known_color::window_frame, Native::SystemColorsApi::GetWindowFrame()},
    {known_color::window_text, Native::SystemColorsApi::GetWindowText()},
     */
    {known_color::transparent, 0x00FFFFFF},
    {known_color::alice_blue, 0xFFF0F8FF},
    {known_color::antique_white, 0xFFFAEBD7},
    {known_color::aqua, 0xFF00FFFF},
    {known_color::aquamarine, 0xFF7FFFD4},
    {known_color::azure, 0xFFF0FFFF},
    {known_color::beige, 0xFFF5F5DC},
    {known_color::bisque, 0xFFFFE4C4},
    {known_color::black, 0xFF000000},
    {known_color::blanched_almond, 0xFFFFEBCD},
    {known_color::blue, 0xFF0000FF},
    {known_color::blue_violet, 0xFF8A2BE2},
    {known_color::brown, 0xFFA52A2A},
    {known_color::burly_wood, 0xFFDEB887},
    {known_color::cadet_blue, 0xFF5F9EA0},
    {known_color::chartreuse, 0xFF7FFF00},
    {known_color::chocolate, 0xFFD2691E},
    {known_color::coral, 0xFFFF7F50},
    {known_color::cornflower_blue, 0xFF6495ED},
    {known_color::cornsilk, 0xFFFFF8DC},
    {known_color::crimson, 0xFFDC143C},
    {known_color::cyan, 0xFF00FFFF},
    {known_color::dark_blue, 0xFF00008B},
    {known_color::dark_cyan, 0xFF008B8B},
    {known_color::dark_goldenrod, 0xFFB8860B},
    {known_color::dark_gray, 0xFFA9A9A9},
    {known_color::dark_green, 0xFF006400},
    {known_color::dark_khaki, 0xFFBDB76B},
    {known_color::dark_magenta, 0xFF8B008B},
    {known_color::dark_oliveGreen, 0xFF556B2F},
    {known_color::dark_orange, 0xFFFF8C00},
    {known_color::dark_orchid, 0xFF9932CC},
    {known_color::dark_red, 0xFF8B0000},
    {known_color::dark_salmon, 0xFFE9967A},
    {known_color::dark_sea_green, 0xFF8FBC8B},
    {known_color::dark_slate_blue, 0xFF483D8B},
    {known_color::dark_slate_gray, 0xFF2F4F4F},
    {known_color::dark_turquoise, 0xFF00CED1},
    {known_color::dark_violet, 0xFF9400D3},
    {known_color::deep_pink, 0xFFFF1493},
    {known_color::deep_sky_blue, 0xFF00BFFF},
    {known_color::dim_gray, 0xFF696969},
    {known_color::dodger_blue, 0xFF1E90FF},
    {known_color::firebrick, 0xFFB22222},
    {known_color::floral_white, 0xFFFFFAF0},
    {known_color::forest_green, 0xFF228B22},
    {known_color::fuchsia, 0xFFFF00FF},
    {known_color::gainsboro, 0xFFDCDCDC},
    {known_color::ghost_white, 0xFFF8F8FF},
    {known_color::gold, 0xFFFFD700},
    {known_color::goldenrod, 0xFFDAA520},
    {known_color::gray, 0xFF808080},
    {known_color::green, 0xFF008000},
    {known_color::green_yellow, 0xFFADFF2F},
    {known_color::honeydew, 0xFFF0FFF0},
    {known_color::hot_pink, 0xFFFF69B4},
    {known_color::indian_red, 0xFFCD5C5C},
    {known_color::indigo, 0xFF4B0082},
    {known_color::ivory, 0xFFFFFFF0},
    {known_color::khaki, 0xFFF0E68C},
    {known_color::lavender, 0xFFE6E6FA},
    {known_color::lavender_blush, 0xFFFFF0F5},
    {known_color::lawn_green, 0xFF7CFC00},
    {known_color::lemon_chiffon, 0xFFFFFACD},
    {known_color::light_blue, 0xFFADD8E6},
    {known_color::light_coral, 0xFFF08080},
    {known_color::light_cyan, 0xFFE0FFFF},
    {known_color::light_goldenrod_yellow, 0xFFFAFAD2},
    {known_color::light_gray, 0xFFD3D3D3},
    {known_color::light_green, 0xFF90EE90},
    {known_color::light_pink, 0xFFFFB6C1},
    {known_color::light_salmon, 0xFFFFA07A},
    {known_color::light_sea_green, 0xFF20B2AA},
    {known_color::light_sky_blue, 0xFF87CEFA},
    {known_color::light_slate_gray, 0xFF778899},
    {known_color::light_steel_blue, 0xFFB0C4DE},
    {known_color::light_yellow, 0xFFFFFFE0},
    {known_color::lime, 0xFF00FF00},
    {known_color::lime_green, 0xFF32CD32},
    {known_color::linen, 0xFFFAF0E6},
    {known_color::magenta, 0xFFFF00FF},
    {known_color::maroon, 0xFF800000},
    {known_color::medium_aquamarine, 0xFF66CDAA},
    {known_color::medium_blue, 0xFF0000CD},
    {known_color::medium_orchid, 0xFFBA55D3},
    {known_color::medium_purple, 0xFF9370DB},
    {known_color::medium_sea_green, 0xFF3CB371},
    {known_color::medium_slate_blue, 0xFF7B68EE},
    {known_color::medium_spring_green, 0xFF00FA9A},
    {known_color::medium_turquoise, 0xFF48D1CC},
    {known_color::medium_violet_red, 0xFFC71585},
    {known_color::midnight_blue, 0xFF191970},
    {known_color::mint_cream, 0xFFF5FFFA},
    {known_color::misty_rose, 0xFFFFE4E1},
    {known_color::moccasin, 0xFFFFE4B5},
    {known_color::navajo_white, 0xFFFFDEAD},
    {known_color::navy, 0xFF000080},
    {known_color::old_lace, 0xFFFDF5E6},
    {known_color::olive, 0xFF808000},
    {known_color::olive_drab, 0xFF6B8E23},
    {known_color::orange, 0xFFFFA500},
    {known_color::orange_red, 0xFFFF4500},
    {known_color::orchid, 0xFFDA70D6},
    {known_color::pale_goldenrod, 0xFFEEE8AA},
    {known_color::pale_green, 0xFF98FB98},
    {known_color::pale_turquoise, 0xFFAFEEEE},
    {known_color::pale_violet_red, 0xFFDB7093},
    {known_color::papaya_whip, 0xFFFFEFD5},
    {known_color::peach_puff, 0xFFFFDAB9},
    {known_color::peru, 0xFFCD853F},
    {known_color::pink, 0xFFFFC0CB},
    {known_color::plum, 0xFFDDA0DD},
    {known_color::powder_blue, 0xFFB0E0E6},
    {known_color::purple, 0xFF800080},
    {known_color::red, 0xFFFF0000},
    {known_color::rosy_brown, 0xFFBC8F8F},
    {known_color::royal_blue, 0xFF4169E1},
    {known_color::saddle_brown, 0xFF8B4513},
    {known_color::salmon, 0xFFFA8072},
    {known_color::sandy_brown, 0xFFF4A460},
    {known_color::sea_green, 0xFF2E8B57},
    {known_color::sea_shell, 0xFFFFF5EE},
    {known_color::sienna, 0xFFA0522D},
    {known_color::silver, 0xFFC0C0C0},
    {known_color::sky_blue, 0xFF87CEEB},
    {known_color::slate_blue, 0xFF6A5ACD},
    {known_color::slate_gray, 0xFF708090},
    {known_color::snow, 0xFFFFFAFA},
    {known_color::spring_green, 0xFF00FF7F},
    {known_color::steel_blue, 0xFF4682B4},
    {known_color::tan, 0xFFD2B48C},
    {known_color::teal, 0xFF008080},
    {known_color::thistle, 0xFFD8BFD8},
    {known_color::tomato, 0xFFFF6347},
    {known_color::turquoise, 0xFF40E0D0},
    {known_color::violet, 0xFFEE82EE},
    {known_color::wheat, 0xFFF5DEB3},
    {known_color::white, 0xFFFFFFFF},
    {known_color::white_smoke, 0xFFF5F5F5},
    {known_color::yellow, 0xFFFFFF00},
    {known_color::yellow_green, 0xFF9ACD32},
    /*
    {known_color::button_face, Native::SystemColorsApi::GetButtonFace()},
    {known_color::button_highlight, Native::SystemColorsApi::GetButtonHighlight()},
    {known_color::button_shadow, Native::SystemColorsApi::GetButtonFace()},
    {known_color::gradient_active_caption, Native::SystemColorsApi::GetGradientActiveCaption()},
    {known_color::gradient_inactive_caption, Native::SystemColorsApi::GetGradientInactiveCaption()},
    {known_color::menu_bar, Native::SystemColorsApi::GetMenuBar()},
    {known_color::menu_highlight, Native::SystemColorsApi::GetMenuHighlight()},
     */
     };
  
  if (known_colors.find(color) == known_colors.end())
    throw std::invalid_argument("unknown know_color");
  
  return drawing::color((int)known_colors[color], color);
}

float color::get_brightness() const {
  // .net version (see https://referencesource.microsoft.com/#System.Drawing/commonui/System/Drawing/color.cs,9103fd761ca562ae)
  //return ((float)Math::Max(Math::Max(this->R, this->G), this->B) + (float)Math::Min(Math::Min(this->R, this->G), this->B)) / 255.0 / 2.0;
  // algorithm  version (see https://www.programmingalgorithms.com/algorithm/rgb-to-hsv)
  return (float)max(max(this->r(), this->g()), this->b()) / 255.0f;
}

float color::get_hue() const {
  if (r() == g() && g() == b())
    return 0.0;
  
  float r = (float)this->r() / 255.0f;
  float g = (float)this->g() / 255.0f;
  float b = (float)this->b() / 255.0f;
  
  float max = (float)std::max(std::max(r, g), b);
  float min = (float)std::min(std::min(r, g), b);
  
  float delta = max - min;
  
  float hue = 0.0;
  if (r == max) hue = (g - b) / delta;
  else if (g == max) hue = 2 + (b - r) / delta;
  else if (b == max) hue = 4 + (r - g) / delta;
  hue *= 60;
  
  if (hue < 0.0) hue += 360.0;
  return hue;
}

float color::get_saturation() const {
  float max = (float)std::max(std::max(this->r(), this->g()), this->b()) / 255.0f;
  float min = (float)std::min(std::min(this->r(), this->g()), this->b()) / 255.0f;
  
  if (max == min) return 0.0f;
  
  return (max + min) <= 1.0f ? (max - min) / (max + min) : (max - min) / (2 - max - min);
}

color color::parse(const string& color) {
  /*
   try {
   Array<string> argb = color.Replace("color [A=", "").Replace(" R=", "").Replace(" G=", "").Replace(" B=", "").Replace("]", "").Split(',');
   return color::FromArgb(Int32::Parse(argb[0]), Int32::Parse(argb[1]), Int32::Parse(argb[2]), Int32::Parse(argb[3]));
   } catch(...) {
   return FromName(color.Replace("color [", "").Replace("]", ""));
   }
   */
  return color::empty;
}

int color::to_argb() const {
  return this->argb;
}

known_color color::to_known_color() const {
  return this->known_color_;
}

string color::to_string() const {
  if (this->known_color_ == (known_color)0 && this->argb == 0)
    return "color [empty]";
  
  if (this->known_color_ != (known_color)0 || this->argb == 0)
    return strings::format("color [{0}]", name());
  
  return strings::format("color [a={}, r={}, g={}, b={}]", a(), r(), g(), b());
}

