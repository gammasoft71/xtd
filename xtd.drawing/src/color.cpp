#include "../include/xtd/color.hpp"
#include <cmath>
#include <map>
#include <stdexcept>
#include <xtd/xtd.strings>

const xtd::drawing::color xtd::drawing::color::empty = xtd::drawing::color();

const xtd::drawing::color xtd::drawing::color::transparent = xtd::drawing::color::from_known_color(xtd::drawing::known_color::transparent);

const xtd::drawing::color xtd::drawing::color::alice_blue = xtd::drawing::color::from_known_color(xtd::drawing::known_color::alice_blue);

const xtd::drawing::color xtd::drawing::color::antique_white = xtd::drawing::color::from_known_color(xtd::drawing::known_color::antique_white);

const xtd::drawing::color xtd::drawing::color::aqua = xtd::drawing::color::from_known_color(xtd::drawing::known_color::aqua);

const xtd::drawing::color xtd::drawing::color::aquamarine = xtd::drawing::color::from_known_color(xtd::drawing::known_color::aquamarine);

const xtd::drawing::color xtd::drawing::color::azure = xtd::drawing::color::from_known_color(xtd::drawing::known_color::azure);

const xtd::drawing::color xtd::drawing::color::beige = xtd::drawing::color::from_known_color(xtd::drawing::known_color::beige);

const xtd::drawing::color xtd::drawing::color::bisque = xtd::drawing::color::from_known_color(xtd::drawing::known_color::bisque);

const xtd::drawing::color xtd::drawing::color::black = xtd::drawing::color::from_known_color(xtd::drawing::known_color::black);

const xtd::drawing::color xtd::drawing::color::blanched_almond = xtd::drawing::color::from_known_color(xtd::drawing::known_color::blanched_almond);

const xtd::drawing::color xtd::drawing::color::blue = xtd::drawing::color::from_known_color(xtd::drawing::known_color::blue);

const xtd::drawing::color xtd::drawing::color::blue_violet = xtd::drawing::color::from_known_color(xtd::drawing::known_color::blue_violet);

const xtd::drawing::color xtd::drawing::color::brown = xtd::drawing::color::from_known_color(xtd::drawing::known_color::brown);

const xtd::drawing::color xtd::drawing::color::burly_wood = xtd::drawing::color::from_known_color(xtd::drawing::known_color::burly_wood);

const xtd::drawing::color xtd::drawing::color::cadet_blue = xtd::drawing::color::from_known_color(xtd::drawing::known_color::cadet_blue);

const xtd::drawing::color xtd::drawing::color::chartreuse = xtd::drawing::color::from_known_color(xtd::drawing::known_color::chartreuse);

const xtd::drawing::color xtd::drawing::color::chocolate = xtd::drawing::color::from_known_color(xtd::drawing::known_color::chocolate);

const xtd::drawing::color xtd::drawing::color::coral = xtd::drawing::color::from_known_color(xtd::drawing::known_color::coral);

const xtd::drawing::color xtd::drawing::color::cornflower_blue = xtd::drawing::color::from_known_color(xtd::drawing::known_color::cornflower_blue);

const xtd::drawing::color xtd::drawing::color::cornsilk = xtd::drawing::color::from_known_color(xtd::drawing::known_color::cornsilk);

const xtd::drawing::color xtd::drawing::color::crimson = xtd::drawing::color::from_known_color(xtd::drawing::known_color::crimson);

const xtd::drawing::color xtd::drawing::color::cyan = xtd::drawing::color::from_known_color(xtd::drawing::known_color::cyan);

const xtd::drawing::color xtd::drawing::color::dark_blue = xtd::drawing::color::from_known_color(xtd::drawing::known_color::dark_blue);

const xtd::drawing::color xtd::drawing::color::dark_cyan = xtd::drawing::color::from_known_color(xtd::drawing::known_color::dark_cyan);

const xtd::drawing::color xtd::drawing::color::dark_goldenrod = xtd::drawing::color::from_known_color(xtd::drawing::known_color::dark_goldenrod);

const xtd::drawing::color xtd::drawing::color::dark_gray = xtd::drawing::color::from_known_color(xtd::drawing::known_color::dark_gray);

const xtd::drawing::color xtd::drawing::color::dark_green = xtd::drawing::color::from_known_color(xtd::drawing::known_color::dark_green);

const xtd::drawing::color xtd::drawing::color::dark_khaki = xtd::drawing::color::from_known_color(xtd::drawing::known_color::dark_khaki);

const xtd::drawing::color xtd::drawing::color::dark_magenta = xtd::drawing::color::from_known_color(xtd::drawing::known_color::dark_magenta);

const xtd::drawing::color xtd::drawing::color::dark_oliveGreen = xtd::drawing::color::from_known_color(xtd::drawing::known_color::dark_oliveGreen);

const xtd::drawing::color xtd::drawing::color::dark_orange = xtd::drawing::color::from_known_color(xtd::drawing::known_color::dark_orange);

const xtd::drawing::color xtd::drawing::color::dark_orchid = xtd::drawing::color::from_known_color(xtd::drawing::known_color::dark_orchid);

const xtd::drawing::color xtd::drawing::color::dark_red = xtd::drawing::color::from_known_color(xtd::drawing::known_color::dark_red);

const xtd::drawing::color xtd::drawing::color::dark_salmon = xtd::drawing::color::from_known_color(xtd::drawing::known_color::dark_salmon);

const xtd::drawing::color xtd::drawing::color::dark_seaGreen = xtd::drawing::color::from_known_color(xtd::drawing::known_color::dark_seaGreen);

const xtd::drawing::color xtd::drawing::color::dark_slateBlue = xtd::drawing::color::from_known_color(xtd::drawing::known_color::dark_slateBlue);

const xtd::drawing::color xtd::drawing::color::dark_slateGray = xtd::drawing::color::from_known_color(xtd::drawing::known_color::dark_slateGray);

const xtd::drawing::color xtd::drawing::color::dark_turquoise = xtd::drawing::color::from_known_color(xtd::drawing::known_color::dark_turquoise);

const xtd::drawing::color xtd::drawing::color::dark_violet = xtd::drawing::color::from_known_color(xtd::drawing::known_color::dark_violet);

const xtd::drawing::color xtd::drawing::color::deep_pink = xtd::drawing::color::from_known_color(xtd::drawing::known_color::deep_pink);

const xtd::drawing::color xtd::drawing::color::deep_sky_blue = xtd::drawing::color::from_known_color(xtd::drawing::known_color::deep_sky_blue);

const xtd::drawing::color xtd::drawing::color::dim_gray = xtd::drawing::color::from_known_color(xtd::drawing::known_color::dim_gray);

const xtd::drawing::color xtd::drawing::color::dodger_blue = xtd::drawing::color::from_known_color(xtd::drawing::known_color::dodger_blue);

const xtd::drawing::color xtd::drawing::color::firebrick = xtd::drawing::color::from_known_color(xtd::drawing::known_color::firebrick);

const xtd::drawing::color xtd::drawing::color::floral_white = xtd::drawing::color::from_known_color(xtd::drawing::known_color::floral_white);

const xtd::drawing::color xtd::drawing::color::forest_green = xtd::drawing::color::from_known_color(xtd::drawing::known_color::forest_green);

const xtd::drawing::color xtd::drawing::color::fuchsia = xtd::drawing::color::from_known_color(xtd::drawing::known_color::fuchsia);

const xtd::drawing::color xtd::drawing::color::gainsboro = xtd::drawing::color::from_known_color(xtd::drawing::known_color::gainsboro);

const xtd::drawing::color xtd::drawing::color::ghost_white = xtd::drawing::color::from_known_color(xtd::drawing::known_color::ghost_white);

const xtd::drawing::color xtd::drawing::color::gold = xtd::drawing::color::from_known_color(xtd::drawing::known_color::gold);

const xtd::drawing::color xtd::drawing::color::goldenrod = xtd::drawing::color::from_known_color(xtd::drawing::known_color::goldenrod);

const xtd::drawing::color xtd::drawing::color::gray = xtd::drawing::color::from_known_color(xtd::drawing::known_color::gray);

const xtd::drawing::color xtd::drawing::color::green = xtd::drawing::color::from_known_color(xtd::drawing::known_color::green);

const xtd::drawing::color xtd::drawing::color::green_yellow = xtd::drawing::color::from_known_color(xtd::drawing::known_color::green_yellow);

const xtd::drawing::color xtd::drawing::color::honeydew = xtd::drawing::color::from_known_color(xtd::drawing::known_color::honeydew);

const xtd::drawing::color xtd::drawing::color::hot_pink = xtd::drawing::color::from_known_color(xtd::drawing::known_color::hot_pink);

const xtd::drawing::color xtd::drawing::color::indian_red = xtd::drawing::color::from_known_color(xtd::drawing::known_color::indian_red);

const xtd::drawing::color xtd::drawing::color::indigo = xtd::drawing::color::from_known_color(xtd::drawing::known_color::indigo);

const xtd::drawing::color xtd::drawing::color::ivory = xtd::drawing::color::from_known_color(xtd::drawing::known_color::ivory);

const xtd::drawing::color xtd::drawing::color::khaki = xtd::drawing::color::from_known_color(xtd::drawing::known_color::khaki);

const xtd::drawing::color xtd::drawing::color::lavender = xtd::drawing::color::from_known_color(xtd::drawing::known_color::lavender);

const xtd::drawing::color xtd::drawing::color::lavender_blush = xtd::drawing::color::from_known_color(xtd::drawing::known_color::lavender_blush);

const xtd::drawing::color xtd::drawing::color::lawn_green = xtd::drawing::color::from_known_color(xtd::drawing::known_color::lawn_green);

const xtd::drawing::color xtd::drawing::color::lemon_chiffon = xtd::drawing::color::from_known_color(xtd::drawing::known_color::lemon_chiffon);

const xtd::drawing::color xtd::drawing::color::light_blue = xtd::drawing::color::from_known_color(xtd::drawing::known_color::light_blue);

const xtd::drawing::color xtd::drawing::color::light_coral = xtd::drawing::color::from_known_color(xtd::drawing::known_color::light_coral);

const xtd::drawing::color xtd::drawing::color::light_cyan = xtd::drawing::color::from_known_color(xtd::drawing::known_color::light_cyan);

const xtd::drawing::color xtd::drawing::color::light_goldenrod_yellow = xtd::drawing::color::from_known_color(xtd::drawing::known_color::light_goldenrod_yellow);

const xtd::drawing::color xtd::drawing::color::light_gray = xtd::drawing::color::from_known_color(xtd::drawing::known_color::light_gray);

const xtd::drawing::color xtd::drawing::color::light_green = xtd::drawing::color::from_known_color(xtd::drawing::known_color::light_green);

const xtd::drawing::color xtd::drawing::color::light_pink = xtd::drawing::color::from_known_color(xtd::drawing::known_color::light_pink);

const xtd::drawing::color xtd::drawing::color::light_salmon = xtd::drawing::color::from_known_color(xtd::drawing::known_color::light_salmon);

const xtd::drawing::color xtd::drawing::color::light_sea_green = xtd::drawing::color::from_known_color(xtd::drawing::known_color::light_sea_green);

const xtd::drawing::color xtd::drawing::color::light_sky_blue = xtd::drawing::color::from_known_color(xtd::drawing::known_color::light_sky_blue);

const xtd::drawing::color xtd::drawing::color::light_slate_gray = xtd::drawing::color::from_known_color(xtd::drawing::known_color::light_slate_gray);

const xtd::drawing::color xtd::drawing::color::light_steel_blue = xtd::drawing::color::from_known_color(xtd::drawing::known_color::light_steel_blue);

const xtd::drawing::color xtd::drawing::color::light_yellow = xtd::drawing::color::from_known_color(xtd::drawing::known_color::light_yellow);

const xtd::drawing::color xtd::drawing::color::lime = xtd::drawing::color::from_known_color(xtd::drawing::known_color::lime);

const xtd::drawing::color xtd::drawing::color::lime_green = xtd::drawing::color::from_known_color(xtd::drawing::known_color::lime_green);

const xtd::drawing::color xtd::drawing::color::linen = xtd::drawing::color::from_known_color(xtd::drawing::known_color::linen);

const xtd::drawing::color xtd::drawing::color::magenta = xtd::drawing::color::from_known_color(xtd::drawing::known_color::magenta);

const xtd::drawing::color xtd::drawing::color::maroon = xtd::drawing::color::from_known_color(xtd::drawing::known_color::maroon);

const xtd::drawing::color xtd::drawing::color::medium_aquamarine = xtd::drawing::color::from_known_color(xtd::drawing::known_color::medium_aquamarine);

const xtd::drawing::color xtd::drawing::color::medium_blue = xtd::drawing::color::from_known_color(xtd::drawing::known_color::medium_blue);

const xtd::drawing::color xtd::drawing::color::medium_orchid = xtd::drawing::color::from_known_color(xtd::drawing::known_color::medium_orchid);

const xtd::drawing::color xtd::drawing::color::medium_purple = xtd::drawing::color::from_known_color(xtd::drawing::known_color::medium_purple);

const xtd::drawing::color xtd::drawing::color::medium_sea_green = xtd::drawing::color::from_known_color(xtd::drawing::known_color::medium_sea_green);

const xtd::drawing::color xtd::drawing::color::medium_slate_blue = xtd::drawing::color::from_known_color(xtd::drawing::known_color::medium_slate_blue);

const xtd::drawing::color xtd::drawing::color::medium_spring_green = xtd::drawing::color::from_known_color(xtd::drawing::known_color::medium_spring_green);

const xtd::drawing::color xtd::drawing::color::medium_turquoise = xtd::drawing::color::from_known_color(xtd::drawing::known_color::medium_turquoise);

const xtd::drawing::color xtd::drawing::color::medium_violet_red = xtd::drawing::color::from_known_color(xtd::drawing::known_color::medium_violet_red);

const xtd::drawing::color xtd::drawing::color::midnight_blue = xtd::drawing::color::from_known_color(xtd::drawing::known_color::midnight_blue);

const xtd::drawing::color xtd::drawing::color::mint_cream = xtd::drawing::color::from_known_color(xtd::drawing::known_color::mint_cream);

const xtd::drawing::color xtd::drawing::color::misty_rose = xtd::drawing::color::from_known_color(xtd::drawing::known_color::misty_rose);

const xtd::drawing::color xtd::drawing::color::moccasin = xtd::drawing::color::from_known_color(xtd::drawing::known_color::moccasin);

const xtd::drawing::color xtd::drawing::color::navajo_white = xtd::drawing::color::from_known_color(xtd::drawing::known_color::navajo_white);

const xtd::drawing::color xtd::drawing::color::navy = xtd::drawing::color::from_known_color(xtd::drawing::known_color::navy);

const xtd::drawing::color xtd::drawing::color::old_lace = xtd::drawing::color::from_known_color(xtd::drawing::known_color::old_lace);

const xtd::drawing::color xtd::drawing::color::olive = xtd::drawing::color::from_known_color(xtd::drawing::known_color::olive);

const xtd::drawing::color xtd::drawing::color::olive_drab = xtd::drawing::color::from_known_color(xtd::drawing::known_color::OliveDrab);

const xtd::drawing::color xtd::drawing::color::orange = xtd::drawing::color::from_known_color(xtd::drawing::known_color::orange);

const xtd::drawing::color xtd::drawing::color::orange_red = xtd::drawing::color::from_known_color(xtd::drawing::known_color::orange_red);

const xtd::drawing::color xtd::drawing::color::orchid = xtd::drawing::color::from_known_color(xtd::drawing::known_color::orchid);

const xtd::drawing::color xtd::drawing::color::pale_goldenrod = xtd::drawing::color::from_known_color(xtd::drawing::known_color::pale_goldenrod);

const xtd::drawing::color xtd::drawing::color::pale_green = xtd::drawing::color::from_known_color(xtd::drawing::known_color::pale_green);

const xtd::drawing::color xtd::drawing::color::pale_turquoise = xtd::drawing::color::from_known_color(xtd::drawing::known_color::pale_turquoise);

const xtd::drawing::color xtd::drawing::color::pale_violet_red = xtd::drawing::color::from_known_color(xtd::drawing::known_color::pale_violet_red);

const xtd::drawing::color xtd::drawing::color::papaya_whip = xtd::drawing::color::from_known_color(xtd::drawing::known_color::papaya_whip);

const xtd::drawing::color xtd::drawing::color::peach_puff = xtd::drawing::color::from_known_color(xtd::drawing::known_color::peach_puff);

const xtd::drawing::color xtd::drawing::color::peru = xtd::drawing::color::from_known_color(xtd::drawing::known_color::peru);

const xtd::drawing::color xtd::drawing::color::pink = xtd::drawing::color::from_known_color(xtd::drawing::known_color::pink);

const xtd::drawing::color xtd::drawing::color::plum = xtd::drawing::color::from_known_color(xtd::drawing::known_color::plum);

const xtd::drawing::color xtd::drawing::color::powder_blue = xtd::drawing::color::from_known_color(xtd::drawing::known_color::powder_blue);

const xtd::drawing::color xtd::drawing::color::purple = xtd::drawing::color::from_known_color(xtd::drawing::known_color::purple);

const xtd::drawing::color xtd::drawing::color::red = xtd::drawing::color::from_known_color(xtd::drawing::known_color::red);

const xtd::drawing::color xtd::drawing::color::rosy_brown = xtd::drawing::color::from_known_color(xtd::drawing::known_color::rosy_brown);

const xtd::drawing::color xtd::drawing::color::royal_blue = xtd::drawing::color::from_known_color(xtd::drawing::known_color::royal_blue);

const xtd::drawing::color xtd::drawing::color::saddle_brown = xtd::drawing::color::from_known_color(xtd::drawing::known_color::saddle_brown);

const xtd::drawing::color xtd::drawing::color::salmon = xtd::drawing::color::from_known_color(xtd::drawing::known_color::salmon);

const xtd::drawing::color xtd::drawing::color::sandy_brown = xtd::drawing::color::from_known_color(xtd::drawing::known_color::sandy_brown);

const xtd::drawing::color xtd::drawing::color::sea_green = xtd::drawing::color::from_known_color(xtd::drawing::known_color::sea_green);

const xtd::drawing::color xtd::drawing::color::sea_shell = xtd::drawing::color::from_known_color(xtd::drawing::known_color::sea_shell);

const xtd::drawing::color xtd::drawing::color::sienna = xtd::drawing::color::from_known_color(xtd::drawing::known_color::sienna);

const xtd::drawing::color xtd::drawing::color::silver = xtd::drawing::color::from_known_color(xtd::drawing::known_color::silver);

const xtd::drawing::color xtd::drawing::color::sky_blue = xtd::drawing::color::from_known_color(xtd::drawing::known_color::sky_blue);

const xtd::drawing::color xtd::drawing::color::slate_blue = xtd::drawing::color::from_known_color(xtd::drawing::known_color::slate_blue);

const xtd::drawing::color xtd::drawing::color::slate_gray = xtd::drawing::color::from_known_color(xtd::drawing::known_color::slate_gray);

const xtd::drawing::color xtd::drawing::color::snow = xtd::drawing::color::from_known_color(xtd::drawing::known_color::snow);

const xtd::drawing::color xtd::drawing::color::spring_green = xtd::drawing::color::from_known_color(xtd::drawing::known_color::spring_green);

const xtd::drawing::color xtd::drawing::color::steel_blue = xtd::drawing::color::from_known_color(xtd::drawing::known_color::steel_blue);

const xtd::drawing::color xtd::drawing::color::tan = xtd::drawing::color::from_known_color(xtd::drawing::known_color::tan);

const xtd::drawing::color xtd::drawing::color::teal = xtd::drawing::color::from_known_color(xtd::drawing::known_color::teal);

const xtd::drawing::color xtd::drawing::color::thistle = xtd::drawing::color::from_known_color(xtd::drawing::known_color::thistle);

const xtd::drawing::color xtd::drawing::color::tomato = xtd::drawing::color::from_known_color(xtd::drawing::known_color::tomato);

const xtd::drawing::color xtd::drawing::color::turquoise = xtd::drawing::color::from_known_color(xtd::drawing::known_color::turquoise);

const xtd::drawing::color xtd::drawing::color::violet = xtd::drawing::color::from_known_color(xtd::drawing::known_color::violet);

const xtd::drawing::color xtd::drawing::color::wheat = xtd::drawing::color::from_known_color(xtd::drawing::known_color::wheat);

const xtd::drawing::color xtd::drawing::color::white = xtd::drawing::color::from_known_color(xtd::drawing::known_color::white);

const xtd::drawing::color xtd::drawing::color::white_smoke = xtd::drawing::color::from_known_color(xtd::drawing::known_color::white_smoke);

const xtd::drawing::color xtd::drawing::color::yellow = xtd::drawing::color::from_known_color(xtd::drawing::known_color::yellow);

const xtd::drawing::color xtd::drawing::color::yellow_green = xtd::drawing::color::from_known_color(xtd::drawing::known_color::yellow_green);

xtd::drawing::color::color(int argb) : argb(argb) {
}

xtd::drawing::color::color(int argb, const xtd::drawing::known_color& color) : argb(argb), known_color(color) {
}

xtd::drawing::color::color(const xtd::drawing::color& color) : argb(color.argb), known_color(color.known_color) {
}

bool xtd::drawing::color::is_system_color() const {
  return this->known_color != (xtd::drawing::known_color)0 && (this->known_color <= xtd::drawing::known_color::window_text || this->known_color >= xtd::drawing::known_color::button_face);
}

std::string xtd::drawing::color::name() const {
  if (this->known_color == (xtd::drawing::known_color)0 && this->argb == 0)
    return "0";

  /*
  if (this->knownColor != (xtd::drawing::known_color)0 || this->argb == 0)
    return Enum<>::GetName<xtd::drawing::known_color>(this->knownColor);
   */
  
  return xtd::strings::format("{0:X8}", this->argb);
}

xtd::drawing::color xtd::drawing::color::from_argb(int argb) {
  return xtd::drawing::color(argb);
}

xtd::drawing::color xtd::drawing::color::from_argb(int alpha, const xtd::drawing::color& baseColor) {
  if (alpha < 0 || alpha > 255)
    throw std::invalid_argument("alpha value must be between 0 and 255");
  
  return xtd::drawing::color((alpha << 24) + (baseColor.argb & 0x00FFFFFF));
}

xtd::drawing::color xtd::drawing::color::from_argb(int alpha, int red, int green, int blue) {
  if (alpha < 0 || alpha > 255 || red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255)
    throw std::invalid_argument("alpha, red, green and blue values must be between 0 and 255");
  
  return xtd::drawing::color((alpha << 24) + (red << 16) + (green << 8) + blue);
}

xtd::drawing::color xtd::drawing::color::from_hsb(float hue, float saturation, float brightness) {
  // algorithm version (see https://www.programmingalgorithms.com/algorithm/hsv-to-rgb)
  if (saturation == 0)
    return xtd::drawing::color::from_argb(255, (unsigned char)(brightness * 255.0f), (unsigned char)(brightness * 255.0f), (unsigned char)(brightness * 255.0f));
  
  hue = hue == 360 ? 0 : hue / 60;
  
  float f = hue - (float)std::trunc(hue);
  float p = brightness * (1.0f - saturation);
  float q = brightness * (1.0f - (saturation * f));
  float t = brightness * (1.0f - (saturation * (1.0f - f)));
  
  switch ((int)std::trunc(hue)) {
    case 0: return xtd::drawing::color::from_argb(255, (unsigned char)(brightness * 255.0f), (unsigned char)(t * 255.0f), (unsigned char)(p * 255.0f));
    case 1: return xtd::drawing::color::from_argb(255, (unsigned char)(q * 255.0f), (unsigned char)(brightness * 255.0f), (unsigned char)(p * 255.0f));
    case 2: return xtd::drawing::color::from_argb(255, (unsigned char)(p * 255.0f), (unsigned char)(brightness * 255.0f), (unsigned char)(t * 255.0f));
    case 3: return xtd::drawing::color::from_argb(255, (unsigned char)(p * 255.0f), (unsigned char)(q * 255.0f), (unsigned char)(brightness * 255.0f));
    case 4: return xtd::drawing::color::from_argb(255, (unsigned char)(t * 255.0f), (unsigned char)(p * 255.0f), (unsigned char)(brightness * 255.0f));
    default: return xtd::drawing::color::from_argb(255, (unsigned char)(brightness * 255.0f), (unsigned char)(p * 255.0f), (unsigned char)(q * 255.0f));
  }
}

xtd::drawing::color xtd::drawing::color::from_name(const std::string& name) {
  //return xtd::drawing::color::from_known_color((xtd::drawing::known_color)Enum<>::Parse<xtd::drawing::known_color>(name));
  return xtd::drawing::color::empty;
}

xtd::drawing::color xtd::drawing::color::from_known_color(xtd::drawing::known_color color) {
  /*
  static std::map<int, int> knownColors{ { (int)xtd::drawing::known_color::ActiveBorder, Native::SystemColorsApi::GetActiveBorder() }, { (int)xtd::drawing::known_color::ActiveCaption, Native::SystemColorsApi::GetActiveCaption() }, { (int)xtd::drawing::known_color::ActiveCaptionText, Native::SystemColorsApi::GetActiveCaptionText() }, { (int)xtd::drawing::known_color::AppWorkspace, Native::SystemColorsApi::GetAppWorkspace() }, { (int)xtd::drawing::known_color::Control, Native::SystemColorsApi::GetControl() }, { (int)xtd::drawing::known_color::ControlDark, Native::SystemColorsApi::GetControlDark() }, { (int)xtd::drawing::known_color::ControlDarkDark, Native::SystemColorsApi::GetControlDarkDark() }, { (int)xtd::drawing::known_color::ControlLight, Native::SystemColorsApi::GetControlLight() }, { (int)xtd::drawing::known_color::ControlLightLight, Native::SystemColorsApi::GetControlLightLight() }, { (int)xtd::drawing::known_color::ControlText, Native::SystemColorsApi::GetControlText() }, { (int)xtd::drawing::known_color::Desktop, Native::SystemColorsApi::GetDesktop() }, { (int)xtd::drawing::known_color::GrayText, Native::SystemColorsApi::GetGrayText() }, { (int)xtd::drawing::known_color::Highlight, Native::SystemColorsApi::GetHighlight() }, { (int)xtd::drawing::known_color::HighlightText, Native::SystemColorsApi::GetHighlightText() }, { (int)xtd::drawing::known_color::HotTrack, Native::SystemColorsApi::GetHotTrack() }, { (int)xtd::drawing::known_color::InactiveBorder, Native::SystemColorsApi::GetInactiveBorder() }, { (int)xtd::drawing::known_color::InactiveCaption, Native::SystemColorsApi::GetInactiveCaption() }, { (int)xtd::drawing::known_color::InactiveCaptionText, Native::SystemColorsApi::GetInactiveCaptionText() }, { (int)xtd::drawing::known_color::Info, Native::SystemColorsApi::GetInfo() }, { (int)xtd::drawing::known_color::InfoText, Native::SystemColorsApi::GetInfoText() }, { (int)xtd::drawing::known_color::Menu, Native::SystemColorsApi::GetMenu() }, { (int)xtd::drawing::known_color::MenuText, Native::SystemColorsApi::GetMenuText() }, { (int)xtd::drawing::known_color::ScrollBar, Native::SystemColorsApi::GetScrollBar() }, { (int)xtd::drawing::known_color::Window, Native::SystemColorsApi::GetWindow() }, { (int)xtd::drawing::known_color::WindowFrame, Native::SystemColorsApi::GetWindowFrame() }, { (int)xtd::drawing::known_color::WindowText, Native::SystemColorsApi::GetWindowText() }, { (int)xtd::drawing::known_color::transparent, (int)0x00FFFFFF }, { (int)xtd::drawing::known_color::alice_blue, (int)0xFFF0F8FF }, { (int)xtd::drawing::known_color::antique_white, (int)0xFFFAEBD7 }, { (int)xtd::drawing::known_color::aqua, (int)0xFF00FFFF }, { (int)xtd::drawing::known_color::aquamarine, (int)0xFF7FFFD4 }, { (int)xtd::drawing::known_color::azure, (int)0xFFF0FFFF }, { (int)xtd::drawing::known_color::beige, (int)0xFFF5F5DC }, { (int)xtd::drawing::known_color::bisque, (int)0xFFFFE4C4 }, { (int)xtd::drawing::known_color::black, (int)0xFF000000 }, { (int)xtd::drawing::known_color::blanched_almond, (int)0xFFFFEBCD }, { (int)xtd::drawing::known_color::blue, (int)0xFF0000FF }, { (int)xtd::drawing::known_color::blue_violet, (int)0xFF8A2BE2 }, { (int)xtd::drawing::known_color::brown, (int)0xFFA52A2A }, { (int)xtd::drawing::known_color::burly_wood, (int)0xFFDEB887 }, { (int)xtd::drawing::known_color::cadet_blue, (int)0xFF5F9EA0 }, { (int)xtd::drawing::known_color::chartreuse, (int)0xFF7FFF00 }, { (int)xtd::drawing::known_color::chocolate, (int)0xFFD2691E }, { (int)xtd::drawing::known_color::coral, (int)0xFFFF7F50 }, { (int)xtd::drawing::known_color::cornflower_blue, (int)0xFF6495ED }, { (int)xtd::drawing::known_color::cornsilk, (int)0xFFFFF8DC }, { (int)xtd::drawing::known_color::crimson, (int)0xFFDC143C }, { (int)xtd::drawing::known_color::cyan, (int)0xFF00FFFF }, { (int)xtd::drawing::known_color::dark_blue, (int)0xFF00008B }, { (int)xtd::drawing::known_color::dark_cyan, (int)0xFF008B8B }, { (int)xtd::drawing::known_color::dark_goldenrod, (int)0xFFB8860B }, { (int)xtd::drawing::known_color::dark_gray, (int)0xFFA9A9A9 }, { (int)xtd::drawing::known_color::dark_green, (int)0xFF006400 }, { (int)xtd::drawing::known_color::dark_khaki, (int)0xFFBDB76B }, { (int)xtd::drawing::known_color::dark_magenta, (int)0xFF8B008B }, { (int)xtd::drawing::known_color::dark_oliveGreen, (int)0xFF556B2F }, { (int)xtd::drawing::known_color::dark_orange, (int)0xFFFF8C00 }, { (int)xtd::drawing::known_color::dark_orchid, (int)0xFF9932CC }, { (int)xtd::drawing::known_color::dark_red, (int)0xFF8B0000 }, { (int)xtd::drawing::known_color::dark_salmon, (int)0xFFE9967A }, { (int)xtd::drawing::known_color::dark_seaGreen, (int)0xFF8FBC8B }, { (int)xtd::drawing::known_color::dark_slateBlue, (int)0xFF483D8B }, { (int)xtd::drawing::known_color::dark_slateGray, (int)0xFF2F4F4F }, { (int)xtd::drawing::known_color::dark_turquoise, (int)0xFF00CED1 }, { (int)xtd::drawing::known_color::dark_violet, (int)0xFF9400D3 }, { (int)xtd::drawing::known_color::deep_pink, (int)0xFFFF1493 }, { (int)xtd::drawing::known_color::DeepSkyBlue, (int)0xFF00BFFF }, { (int)xtd::drawing::known_color::DimGray, (int)0xFF696969 }, { (int)xtd::drawing::known_color::DodgerBlue, (int)0xFF1E90FF }, { (int)xtd::drawing::known_color::Firebrick, (int)0xFFB22222 }, { (int)xtd::drawing::known_color::FloralWhite, (int)0xFFFFFAF0 }, { (int)xtd::drawing::known_color::ForestGreen, (int)0xFF228B22 }, { (int)xtd::drawing::known_color::Fuchsia, (int)0xFFFF00FF }, { (int)xtd::drawing::known_color::Gainsboro, (int)0xFFDCDCDC }, { (int)xtd::drawing::known_color::GhostWhite, (int)0xFFF8F8FF }, { (int)xtd::drawing::known_color::Gold, (int)0xFFFFD700 }, { (int)xtd::drawing::known_color::Goldenrod, (int)0xFFDAA520 }, { (int)xtd::drawing::known_color::Gray, (int)0xFF808080 }, { (int)xtd::drawing::known_color::Green, (int)0xFF008000 }, { (int)xtd::drawing::known_color::GreenYellow, (int)0xFFADFF2F }, { (int)xtd::drawing::known_color::Honeydew, (int)0xFFF0FFF0 }, { (int)xtd::drawing::known_color::HotPink, (int)0xFFFF69B4 }, { (int)xtd::drawing::known_color::IndianRed, (int)0xFFCD5C5C }, { (int)xtd::drawing::known_color::Indigo, (int)0xFF4B0082 }, { (int)xtd::drawing::known_color::Ivory, (int)0xFFFFFFF0 }, { (int)xtd::drawing::known_color::Khaki, (int)0xFFF0E68C }, { (int)xtd::drawing::known_color::Lavender, (int)0xFFE6E6FA }, { (int)xtd::drawing::known_color::LavenderBlush, (int)0xFFFFF0F5 }, { (int)xtd::drawing::known_color::LawnGreen, (int)0xFF7CFC00 }, { (int)xtd::drawing::known_color::LemonChiffon, (int)0xFFFFFACD }, { (int)xtd::drawing::known_color::LightBlue, (int)0xFFADD8E6 }, { (int)xtd::drawing::known_color::LightCoral, (int)0xFFF08080 }, { (int)xtd::drawing::known_color::LightCyan, (int)0xFFE0FFFF }, { (int)xtd::drawing::known_color::LightGoldenrodYellow, (int)0xFFFAFAD2 }, { (int)xtd::drawing::known_color::LightGray, (int)0xFFD3D3D3 }, { (int)xtd::drawing::known_color::LightGreen, (int)0xFF90EE90 }, { (int)xtd::drawing::known_color::LightPink, (int)0xFFFFB6C1 }, { (int)xtd::drawing::known_color::LightSalmon, (int)0xFFFFA07A }, { (int)xtd::drawing::known_color::LightSeaGreen, (int)0xFF20B2AA }, { (int)xtd::drawing::known_color::LightSkyBlue, (int)0xFF87CEFA }, { (int)xtd::drawing::known_color::LightSlateGray, (int)0xFF778899 }, { (int)xtd::drawing::known_color::LightSteelBlue, (int)0xFFB0C4DE }, { (int)xtd::drawing::known_color::LightYellow, (int)0xFFFFFFE0 }, { (int)xtd::drawing::known_color::Lime, (int)0xFF00FF00 }, { (int)xtd::drawing::known_color::LimeGreen, (int)0xFF32CD32 }, { (int)xtd::drawing::known_color::Linen, (int)0xFFFAF0E6 }, { (int)xtd::drawing::known_color::Magenta, (int)0xFFFF00FF }, { (int)xtd::drawing::known_color::Maroon, (int)0xFF800000 }, { (int)xtd::drawing::known_color::MediumAquamarine, (int)0xFF66CDAA }, { (int)xtd::drawing::known_color::MediumBlue, (int)0xFF0000CD }, { (int)xtd::drawing::known_color::MediumOrchid, (int)0xFFBA55D3 }, { (int)xtd::drawing::known_color::MediumPurple, (int)0xFF9370DB }, { (int)xtd::drawing::known_color::MediumSeaGreen, (int)0xFF3CB371 }, { (int)xtd::drawing::known_color::MediumSlateBlue, (int)0xFF7B68EE }, { (int)xtd::drawing::known_color::MediumSpringGreen, (int)0xFF00FA9A }, { (int)xtd::drawing::known_color::MediumTurquoise, (int)0xFF48D1CC }, { (int)xtd::drawing::known_color::MediumVioletRed, (int)0xFFC71585 }, { (int)xtd::drawing::known_color::MidnightBlue, (int)0xFF191970 }, { (int)xtd::drawing::known_color::MintCream, (int)0xFFF5FFFA }, { (int)xtd::drawing::known_color::MistyRose, (int)0xFFFFE4E1 }, { (int)xtd::drawing::known_color::Moccasin, (int)0xFFFFE4B5 }, { (int)xtd::drawing::known_color::NavajoWhite, (int)0xFFFFDEAD }, { (int)xtd::drawing::known_color::Navy, (int)0xFF000080 }, { (int)xtd::drawing::known_color::OldLace, (int)0xFFFDF5E6 }, { (int)xtd::drawing::known_color::Olive, (int)0xFF808000 }, { (int)xtd::drawing::known_color::OliveDrab, (int)0xFF6B8E23 }, { (int)xtd::drawing::known_color::Orange, (int)0xFFFFA500 }, { (int)xtd::drawing::known_color::OrangeRed, (int)0xFFFF4500 }, { (int)xtd::drawing::known_color::Orchid, (int)0xFFDA70D6 }, { (int)xtd::drawing::known_color::PaleGoldenrod, (int)0xFFEEE8AA }, { (int)xtd::drawing::known_color::PaleGreen, (int)0xFF98FB98 }, { (int)xtd::drawing::known_color::PaleTurquoise, (int)0xFFAFEEEE }, { (int)xtd::drawing::known_color::PaleVioletRed, (int)0xFFDB7093 }, { (int)xtd::drawing::known_color::PapayaWhip, (int)0xFFFFEFD5 }, { (int)xtd::drawing::known_color::PeachPuff, (int)0xFFFFDAB9 }, { (int)xtd::drawing::known_color::Peru, (int)0xFFCD853F }, { (int)xtd::drawing::known_color::Pink, (int)0xFFFFC0CB }, { (int)xtd::drawing::known_color::Plum, (int)0xFFDDA0DD }, { (int)xtd::drawing::known_color::PowderBlue, (int)0xFFB0E0E6 }, { (int)xtd::drawing::known_color::Purple, (int)0xFF800080 }, { (int)xtd::drawing::known_color::Red, (int)0xFFFF0000 }, { (int)xtd::drawing::known_color::RosyBrown, (int)0xFFBC8F8F }, { (int)xtd::drawing::known_color::RoyalBlue, (int)0xFF4169E1 }, { (int)xtd::drawing::known_color::SaddleBrown, (int)0xFF8B4513 }, { (int)xtd::drawing::known_color::Salmon, (int)0xFFFA8072 }, { (int)xtd::drawing::known_color::SandyBrown, (int)0xFFF4A460 }, { (int)xtd::drawing::known_color::SeaGreen, (int)0xFF2E8B57 }, { (int)xtd::drawing::known_color::SeaShell, (int)0xFFFFF5EE }, { (int)xtd::drawing::known_color::Sienna, (int)0xFFA0522D }, { (int)xtd::drawing::known_color::Silver, (int)0xFFC0C0C0 }, { (int)xtd::drawing::known_color::SkyBlue, (int)0xFF87CEEB }, { (int)xtd::drawing::known_color::SlateBlue, (int)0xFF6A5ACD }, { (int)xtd::drawing::known_color::SlateGray, (int)0xFF708090 }, { (int)xtd::drawing::known_color::Snow, (int)0xFFFFFAFA }, { (int)xtd::drawing::known_color::SpringGreen, (int)0xFF00FF7F }, { (int)xtd::drawing::known_color::SteelBlue, (int)0xFF4682B4 }, { (int)xtd::drawing::known_color::Tan, (int)0xFFD2B48C }, { (int)xtd::drawing::known_color::Teal, (int)0xFF008080 }, { (int)xtd::drawing::known_color::Thistle, (int)0xFFD8BFD8 }, { (int)xtd::drawing::known_color::Tomato, (int)0xFFFF6347 }, { (int)xtd::drawing::known_color::Turquoise, (int)0xFF40E0D0 }, { (int)xtd::drawing::known_color::Violet, (int)0xFFEE82EE }, { (int)xtd::drawing::known_color::Wheat, (int)0xFFF5DEB3 }, { (int)xtd::drawing::known_color::White, (int)0xFFFFFFFF }, { (int)xtd::drawing::known_color::WhiteSmoke, (int)0xFFF5F5F5 }, { (int)xtd::drawing::known_color::Yellow, (int)0xFFFFFF00 }, { (int)xtd::drawing::known_color::YellowGreen, (int)0xFF9ACD32 }, { (int)xtd::drawing::known_color::ButtonFace, Native::SystemColorsApi::GetButtonFace() }, { (int)xtd::drawing::known_color::ButtonHighlight, Native::SystemColorsApi::GetButtonHighlight() }, { (int)xtd::drawing::known_color::ButtonShadow, Native::SystemColorsApi::GetButtonFace() }, { (int)xtd::drawing::known_color::GradientActiveCaption, Native::SystemColorsApi::GetGradientActiveCaption() }, { (int)xtd::drawing::known_color::GradientInactiveCaption, Native::SystemColorsApi::GetGradientInactiveCaption() }, { (int)xtd::drawing::known_color::MenuBar, Native::SystemColorsApi::GetMenuBar() }, { (int)xtd::drawing::known_color::MenuHighlight, Native::SystemColorsApi::GetMenuHighlight() } };
  
  if (!knownColors.ContainsKey((int)color))
    throw ArgumentException(caller_);
  
  return xtd::drawing::color(knownColors[(int)color], color);
   */
  return xtd::drawing::color::empty;
}

float xtd::drawing::color::get_brightness() const {
  // .net version (see https://referencesource.microsoft.com/#System.Drawing/commonui/System/Drawing/xtd::drawing::color.cs,9103fd761ca562ae)
  //return ((float)Math::Max(Math::Max(this->R, this->G), this->B) + (float)Math::Min(Math::Min(this->R, this->G), this->B)) / 255.0 / 2.0;
  // algorithm  version (see https://www.programmingalgorithms.com/algorithm/rgb-to-hsv)
  return (float)std::max(std::max(this->r(), this->g()), this->b()) / 255.0f;
}

float xtd::drawing::color::get_hue() const {
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

float xtd::drawing::color::get_saturation() const {
  float max = (float)std::max(std::max(this->r(), this->g()), this->b()) / 255.0f;
  float min = (float)std::min(std::min(this->r(), this->g()), this->b()) / 255.0f;
  
  if (max == min) return 0.0f;
  
  return (max + min) <= 1.0f ? (max - min) / (max + min) : (max - min) / (2 - max - min);
}

xtd::drawing::color xtd::drawing::color::parse(const std::string& color) {
  /*
  try {
    Array<string> argb = color.Replace("xtd::drawing::color [A=", "").Replace(" R=", "").Replace(" G=", "").Replace(" B=", "").Replace("]", "").Split(',');
    return xtd::drawing::color::FromArgb(Int32::Parse(argb[0]), Int32::Parse(argb[1]), Int32::Parse(argb[2]), Int32::Parse(argb[3]));
  } catch(...) {
    return FromName(color.Replace("xtd::drawing::color [", "").Replace("]", ""));
  }
   */
  return xtd::drawing::color::empty;
}

int xtd::drawing::color::to_argb() const {
  return this->argb;
}

xtd::drawing::known_color xtd::drawing::color::to_known_color() const {
  return this->known_color;
}

std::string xtd::drawing::color::to_string() const {
  if (this->known_color == (xtd::drawing::known_color)0 && this->argb == 0)
    return "xtd::drawing::color [empty]";
  
  if (this->known_color != (xtd::drawing::known_color)0 || this->argb == 0)
    return xtd::strings::format("xtd::drawing::color [{0}]", name());
  
  return xtd::strings::format("xtd::drawing::color [a={}, r={}, g={}, b={}]", a(), r(), g(), b());
}
