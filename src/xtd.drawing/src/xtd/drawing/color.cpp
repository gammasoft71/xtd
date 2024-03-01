#include "../../../include/xtd/drawing/color.h"
#include <xtd/argument_exception>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/system_colors>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/math>
#include <algorithm>
#include <map>
#include <sstream>

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
const color color::dark_olive_green = color::from_known_color(known_color::dark_olive_green);
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
const color color::rebecca_purple = color::from_known_color(known_color::rebecca_purple);
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

color::color(const color& color, const known_color& known_color) : argb_(color.argb_), empty_(false), handle_(color.handle_), known_color_(known_color) {
}

xtd::byte color::a() const noexcept {
  return static_cast<xtd::byte>((to_argb() & 0xFF000000) >> 24);
}

xtd::byte color::b() const noexcept {
  return static_cast<xtd::byte>(to_argb() & 0x000000FF);
}

xtd::byte color::g() const noexcept {
  return static_cast<xtd::byte>((to_argb() & 0x0000FF00) >> 8);
}

intptr color::handle() const noexcept {
  return handle_;
}

bool color::is_dark() const noexcept {
  return get_lightness() < lightness_threshold;
}

bool color::is_empty() const noexcept {
  return empty_;
}

bool color::is_known_color() const noexcept {
  return known_color_ != (xtd::drawing::known_color)0;
}

bool color::is_light() const noexcept {
  return get_lightness() >= lightness_threshold;
}

bool color::is_named_color() const noexcept {
  return name() != ustring::format("{:x8}", argb_) && name() != "0";
}

bool color::is_system_color() const noexcept {
  return known_color_ >= start_know_system_colors_range;
}

xtd::ustring color::name() const noexcept {
  if (name_ != ustring::empty_string) return name_;
  if (known_color_ != static_cast<xtd::drawing::known_color>(0)) return ustring::format("{}", known_color_);
  if (handle_ != 0) return ustring::format("{:x}h", handle_);
  if (argb_ != 0) return ustring::format("{:x8}", argb_);
  return "0";
}

xtd::byte color::r() const noexcept {
  return (xtd::byte)((to_argb() & 0x00FF0000) >> 16);
}

color color::alpha_blend(const color& fore_color, const color& back_color, double alpha) noexcept {;
  return average(fore_color, back_color, alpha);
}

color color::average(const color& color1, const color& color2, double weight) noexcept {
  return average(color1, color2, weight, false);
}

color color::average(const color& color1, const color& color2, double weight, bool average_alpha) noexcept {
  weight = std::clamp(weight, 0.0, 1.0);
  auto alpha_blend = [](xtd::byte fore_componant, xtd::byte back_componant, double percent) {return static_cast<xtd::byte>(fore_componant * (1 - percent) + back_componant * percent);};
  return from_argb(alpha_blend(color1.a(), color2.a(), average_alpha ? weight : 1.0), alpha_blend(color1.r(), color2.r(), weight), alpha_blend(color1.g(), color2.g(), weight), alpha_blend(color1.b(), color2.b(), weight));
}

color color::brightness(const color& color, double percent) noexcept {
  percent = std::clamp(percent, 0.0, 2.0);
  return percent < 1.0 ? alpha_blend(color, color::black, 1.0 - percent) : alpha_blend(color, color::white, percent - 1.0);
}

color color::contrast(const color& color, double percent) noexcept {
  // From https://efundies.com/adjust-the-contrast-of-an-image-in-c/
  if (percent < .0) percent = 0;
 
  auto r = std::clamp(((((color.r() / 255.0) - 0.5) * percent) + 0.5) * 255.0, .0, 255.0);
  auto g = std::clamp(((((color.g() / 255.0) - 0.5) * percent) + 0.5) * 255.0, .0, 255.0);
  auto b = std::clamp(((((color.b() / 255.0) - 0.5) * percent) + 0.5) * 255.0, .0, 255.0);
  
  return from_argb(color.a(), static_cast<xtd::byte>(r), static_cast<xtd::byte>(g), static_cast<xtd::byte>(b));
}

color color::dark(const color& color) noexcept {
  return color::dark(color, 1.0 / 3);
}

color color::dark(const color& color, double percent) noexcept {
  percent = std::clamp(percent, 0.0, 1.0);
  return alpha_blend(color, color::black, percent);
}

color color::disabled(const color& fore_color, const color& back_color) noexcept {
  return disabled(fore_color, back_color.get_brightness());
}

color color::disabled(const color& fore_color, float brightness) noexcept {
  brightness = std::clamp(brightness, .0f, 1.0f);
  return alpha_blend(fore_color, color::from_argb(0xFF000000 + (0xFFFFFF * brightness)), 0.4);
}

bool color::equals(const color& value) const noexcept {
  return argb_ == value.argb_ && handle_ == value.handle_ && name_ == value.name_ && empty_ == value.empty_;
}

color color::from_argb(uint32 argb) noexcept {
  return color(argb);
}

color color::from_argb(xtd::byte alpha, const color& baseColor) noexcept {
  return color((alpha << 24) + ((baseColor.handle_ ? native::system_colors::to_argb(baseColor.handle_) : baseColor.argb_) & 0x00FFFFFF));
}

color color::from_argb(xtd::byte alpha, xtd::byte red, xtd::byte green, xtd::byte blue) noexcept {
  return color(((uint32)alpha << 24) + ((uint32)red << 16) + ((uint32)green << 8) + blue);
}

color color::from_argb(xtd::byte red, xtd::byte green, xtd::byte blue) noexcept {
  return from_argb(0xFF, red, green, blue);
}

color color::from_handle(intptr handle) noexcept {
  return color(handle);
}

color color::from_hsb(float hue, float saturation, float brightness) noexcept {
  // algorithm version (see https://www.programmingalgorithms.com/algorithm/hsv-to-rgb)
  if (saturation == 0) return color::from_argb(255, static_cast<xtd::byte>(brightness * 255.0f), static_cast<xtd::byte>(brightness * 255.0f), static_cast<xtd::byte>(brightness * 255.0f));
  
  hue = hue >= 360 ? 0 : hue / 60;
  
  auto f = hue - trunc(hue);
  auto p = brightness * (1.0f - saturation);
  auto q = brightness * (1.0f - (saturation * f));
  auto t = brightness * (1.0f - (saturation * (1.0f - f)));
  
  switch (static_cast<int32>(trunc(hue))) {
    case 0: return color::from_argb(255, static_cast<xtd::byte>(brightness * 255.0f), static_cast<xtd::byte>(t * 255.0f), static_cast<xtd::byte>(p * 255.0f));
    case 1: return color::from_argb(255, static_cast<xtd::byte>(q * 255.0f), static_cast<xtd::byte>(brightness * 255.0f), static_cast<xtd::byte>(p * 255.0f));
    case 2: return color::from_argb(255, static_cast<xtd::byte>(p * 255.0f),  static_cast<xtd::byte>(brightness * 255.0f), static_cast<xtd::byte>(t * 255.0f));
    case 3: return color::from_argb(255, static_cast<xtd::byte>(p * 255.0f), static_cast<xtd::byte>(q * 255.0f), static_cast<xtd::byte>(brightness * 255.0f));
    case 4: return color::from_argb(255, static_cast<xtd::byte>(t * 255.0f), static_cast<xtd::byte>(p * 255.0f), static_cast<xtd::byte>(brightness * 255.0f));
    default: return color::from_argb(255, static_cast<xtd::byte>(brightness * 255.0f), static_cast<xtd::byte>(p * 255.0f), static_cast<xtd::byte>(q * 255.0f));
  }
}

color color::from_hsl(float hue, float saturation, float lightness) noexcept {
  // algorithm version (see https://www.programmingalgorithms.com/algorithm/hsl-to-rgb)
  if (saturation == 0) return color::from_argb(255, static_cast<xtd::byte>(lightness * 255.0f), static_cast<xtd::byte>(lightness * 255.0f), static_cast<xtd::byte>(lightness * 255.0f));
  
  auto hue_to_rgb = [](float v1, float v2, float vh)->float {
    if (vh < 0) vh += 1;
    if (vh > 1) vh -= 1;
    if ((6 * vh) < 1) return (v1 + (v2 - v1) * 6 * vh);
    if ((2 * vh) < 1) return v2;
    if ((3 * vh) < 2) return (v1 + (v2 - v1) * ((2.0f / 3) - vh) * 6);
    return v1;
  };
  
  hue = hue / 360.0f;
  auto v2 = (lightness < 0.5f) ? (lightness * (1 + saturation)) : ((lightness + saturation) - (lightness * saturation));
  auto v1 = 2 * lightness - v2;
  
  return color::from_argb(255, static_cast<xtd::byte>(hue_to_rgb(v1, v2, hue + (1.0f / 3)) * 255.0f), static_cast<xtd::byte>(hue_to_rgb(v1, v2, hue) * 255.0f), static_cast<xtd::byte>(hue_to_rgb(v1, v2, hue - (1.0f / 3)) * 255.0f));
}

color color::from_known_color(known_color color) {
  switch (color) {
      // "Web" colors
    case known_color::transparent: return drawing::color {color::from_argb(0x00FFFFFF), color};
    case known_color::alice_blue: return drawing::color {color::from_argb(0xFFF0F8FF), color};
    case known_color::antique_white: return drawing::color {color::from_argb(0xFFFAEBD7), color};
    case known_color::aqua: return drawing::color {color::from_argb(0xFF00FFFF), color};
    case known_color::aquamarine: return drawing::color {color::from_argb(0xFF7FFFD4), color};
    case known_color::azure: return drawing::color {color::from_argb(0xFFF0FFFF), color};
    case known_color::beige: return drawing::color {color::from_argb(0xFFF5F5DC), color};
    case known_color::bisque: return drawing::color {color::from_argb(0xFFFFE4C4), color};
    case known_color::black: return drawing::color {color::from_argb(0xFF000000), color};
    case known_color::blanched_almond: return drawing::color {color::from_argb(0xFFFFEBCD), color};
    case known_color::blue: return drawing::color {color::from_argb(0xFF0000FF), color};
    case known_color::blue_violet: return drawing::color {color::from_argb(0xFF8A2BE2), color};
    case known_color::brown: return drawing::color {color::from_argb(0xFFA52A2A), color};
    case known_color::burly_wood: return drawing::color {color::from_argb(0xFFDEB887), color};
    case known_color::cadet_blue: return drawing::color {color::from_argb(0xFF5F9EA0), color};
    case known_color::chartreuse: return drawing::color {color::from_argb(0xFF7FFF00), color};
    case known_color::chocolate: return drawing::color {color::from_argb(0xFFD2691E), color};
    case known_color::coral: return drawing::color {color::from_argb(0xFFFF7F50), color};
    case known_color::cornflower_blue: return drawing::color {color::from_argb(0xFF6495ED), color};
    case known_color::cornsilk: return drawing::color {color::from_argb(0xFFFFF8DC), color};
    case known_color::crimson: return drawing::color {color::from_argb(0xFFDC143C), color};
    case known_color::cyan: return drawing::color {color::from_argb(0xFF00FFFF), color};
    case known_color::dark_blue: return drawing::color {color::from_argb(0xFF00008B), color};
    case known_color::dark_cyan: return drawing::color {color::from_argb(0xFF008B8B), color};
    case known_color::dark_goldenrod: return drawing::color {color::from_argb(0xFFB8860B), color};
    case known_color::dark_gray: return drawing::color {color::from_argb(0xFFA9A9A9), color};
    case known_color::dark_green: return drawing::color {color::from_argb(0xFF006400), color};
    case known_color::dark_khaki: return drawing::color {color::from_argb(0xFFBDB76B), color};
    case known_color::dark_magenta: return drawing::color {color::from_argb(0xFF8B008B), color};
    case known_color::dark_olive_green: return drawing::color {color::from_argb(0xFF556B2F), color};
    case known_color::dark_orange: return drawing::color {color::from_argb(0xFFFF8C00), color};
    case known_color::dark_orchid: return drawing::color {color::from_argb(0xFF9932CC), color};
    case known_color::dark_red: return drawing::color {color::from_argb(0xFF8B0000), color};
    case known_color::dark_salmon: return drawing::color {color::from_argb(0xFFE9967A), color};
    case known_color::dark_sea_green: return drawing::color {color::from_argb(0xFF8FBC8B), color};
    case known_color::dark_slate_blue: return drawing::color {color::from_argb(0xFF483D8B), color};
    case known_color::dark_slate_gray: return drawing::color {color::from_argb(0xFF2F4F4F), color};
    case known_color::dark_turquoise: return drawing::color {color::from_argb(0xFF00CED1), color};
    case known_color::dark_violet: return drawing::color {color::from_argb(0xFF9400D3), color};
    case known_color::deep_pink: return drawing::color {color::from_argb(0xFFFF1493), color};
    case known_color::deep_sky_blue: return drawing::color {color::from_argb(0xFF00BFFF), color};
    case known_color::dim_gray: return drawing::color {color::from_argb(0xFF696969), color};
    case known_color::dodger_blue: return drawing::color {color::from_argb(0xFF1E90FF), color};
    case known_color::firebrick: return drawing::color {color::from_argb(0xFFB22222), color};
    case known_color::floral_white: return drawing::color {color::from_argb(0xFFFFFAF0), color};
    case known_color::forest_green: return drawing::color {color::from_argb(0xFF228B22), color};
    case known_color::fuchsia: return drawing::color {color::from_argb(0xFFFF00FF), color};
    case known_color::gainsboro: return drawing::color {color::from_argb(0xFFDCDCDC), color};
    case known_color::ghost_white: return drawing::color {color::from_argb(0xFFF8F8FF), color};
    case known_color::gold: return drawing::color {color::from_argb(0xFFFFD700), color};
    case known_color::goldenrod: return drawing::color {color::from_argb(0xFFDAA520), color};
    case known_color::gray: return drawing::color {color::from_argb(0xFF808080), color};
    case known_color::green: return drawing::color {color::from_argb(0xFF008000), color};
    case known_color::green_yellow: return drawing::color {color::from_argb(0xFFADFF2F), color};
    case known_color::honeydew: return drawing::color {color::from_argb(0xFFF0FFF0), color};
    case known_color::hot_pink: return drawing::color {color::from_argb(0xFFFF69B4), color};
    case known_color::indian_red: return drawing::color {color::from_argb(0xFFCD5C5C), color};
    case known_color::indigo: return drawing::color {color::from_argb(0xFF4B0082), color};
    case known_color::ivory: return drawing::color {color::from_argb(0xFFFFFFF0), color};
    case known_color::khaki: return drawing::color {color::from_argb(0xFFF0E68C), color};
    case known_color::lavender: return drawing::color {color::from_argb(0xFFE6E6FA), color};
    case known_color::lavender_blush: return drawing::color {color::from_argb(0xFFFFF0F5), color};
    case known_color::lawn_green: return drawing::color {color::from_argb(0xFF7CFC00), color};
    case known_color::lemon_chiffon: return drawing::color {color::from_argb(0xFFFFFACD), color};
    case known_color::light_blue: return drawing::color {color::from_argb(0xFFADD8E6), color};
    case known_color::light_coral: return drawing::color {color::from_argb(0xFFF08080), color};
    case known_color::light_cyan: return drawing::color {color::from_argb(0xFFE0FFFF), color};
    case known_color::light_goldenrod_yellow: return drawing::color {color::from_argb(0xFFFAFAD2), color};
    case known_color::light_gray: return drawing::color {color::from_argb(0xFFD3D3D3), color};
    case known_color::light_green: return drawing::color {color::from_argb(0xFF90EE90), color};
    case known_color::light_pink: return drawing::color {color::from_argb(0xFFFFB6C1), color};
    case known_color::light_salmon: return drawing::color {color::from_argb(0xFFFFA07A), color};
    case known_color::light_sea_green: return drawing::color {color::from_argb(0xFF20B2AA), color};
    case known_color::light_sky_blue: return drawing::color {color::from_argb(0xFF87CEFA), color};
    case known_color::light_slate_gray: return drawing::color {color::from_argb(0xFF778899), color};
    case known_color::light_steel_blue: return drawing::color {color::from_argb(0xFFB0C4DE), color};
    case known_color::light_yellow: return drawing::color {color::from_argb(0xFFFFFFE0), color};
    case known_color::lime: return drawing::color {color::from_argb(0xFF00FF00), color};
    case known_color::lime_green: return drawing::color {color::from_argb(0xFF32CD32), color};
    case known_color::linen: return drawing::color {color::from_argb(0xFFFAF0E6), color};
    case known_color::magenta: return drawing::color {color::from_argb(0xFFFF00FF), color};
    case known_color::maroon: return drawing::color {color::from_argb(0xFF800000), color};
    case known_color::medium_aquamarine: return drawing::color {color::from_argb(0xFF66CDAA), color};
    case known_color::medium_blue: return drawing::color {color::from_argb(0xFF0000CD), color};
    case known_color::medium_orchid: return drawing::color {color::from_argb(0xFFBA55D3), color};
    case known_color::medium_purple: return drawing::color {color::from_argb(0xFF9370DB), color};
    case known_color::medium_sea_green: return drawing::color {color::from_argb(0xFF3CB371), color};
    case known_color::medium_slate_blue: return drawing::color {color::from_argb(0xFF7B68EE), color};
    case known_color::medium_spring_green: return drawing::color {color::from_argb(0xFF00FA9A), color};
    case known_color::medium_turquoise: return drawing::color {color::from_argb(0xFF48D1CC), color};
    case known_color::medium_violet_red: return drawing::color {color::from_argb(0xFFC71585), color};
    case known_color::midnight_blue: return drawing::color {color::from_argb(0xFF191970), color};
    case known_color::mint_cream: return drawing::color {color::from_argb(0xFFF5FFFA), color};
    case known_color::misty_rose: return drawing::color {color::from_argb(0xFFFFE4E1), color};
    case known_color::moccasin: return drawing::color {color::from_argb(0xFFFFE4B5), color};
    case known_color::navajo_white: return drawing::color {color::from_argb(0xFFFFDEAD), color};
    case known_color::navy: return drawing::color {color::from_argb(0xFF000080), color};
    case known_color::old_lace: return drawing::color {color::from_argb(0xFFFDF5E6), color};
    case known_color::olive: return drawing::color {color::from_argb(0xFF808000), color};
    case known_color::olive_drab: return drawing::color {color::from_argb(0xFF6B8E23), color};
    case known_color::orange: return drawing::color {color::from_argb(0xFFFFA500), color};
    case known_color::orange_red: return drawing::color {color::from_argb(0xFFFF4500), color};
    case known_color::orchid: return drawing::color {color::from_argb(0xFFDA70D6), color};
    case known_color::pale_goldenrod: return drawing::color {color::from_argb(0xFFEEE8AA), color};
    case known_color::pale_green: return drawing::color {color::from_argb(0xFF98FB98), color};
    case known_color::pale_turquoise: return drawing::color {color::from_argb(0xFFAFEEEE), color};
    case known_color::pale_violet_red: return drawing::color {color::from_argb(0xFFDB7093), color};
    case known_color::papaya_whip: return drawing::color {color::from_argb(0xFFFFEFD5), color};
    case known_color::peach_puff: return drawing::color {color::from_argb(0xFFFFDAB9), color};
    case known_color::peru: return drawing::color {color::from_argb(0xFFCD853F), color};
    case known_color::pink: return drawing::color {color::from_argb(0xFFFFC0CB), color};
    case known_color::plum: return drawing::color {color::from_argb(0xFFDDA0DD), color};
    case known_color::powder_blue: return drawing::color {color::from_argb(0xFFB0E0E6), color};
    case known_color::purple: return drawing::color {color::from_argb(0xFF800080), color};
    case known_color::rebecca_purple: return drawing::color {color::from_argb(0xFF663399), color};
    case known_color::red: return drawing::color {color::from_argb(0xFFFF0000), color};
    case known_color::rosy_brown: return drawing::color {color::from_argb(0xFFBC8F8F), color};
    case known_color::royal_blue: return drawing::color {color::from_argb(0xFF4169E1), color};
    case known_color::saddle_brown: return drawing::color {color::from_argb(0xFF8B4513), color};
    case known_color::salmon: return drawing::color {color::from_argb(0xFFFA8072), color};
    case known_color::sandy_brown: return drawing::color {color::from_argb(0xFFF4A460), color};
    case known_color::sea_green: return drawing::color {color::from_argb(0xFF2E8B57), color};
    case known_color::sea_shell: return drawing::color {color::from_argb(0xFFFFF5EE), color};
    case known_color::sienna: return drawing::color {color::from_argb(0xFFA0522D), color};
    case known_color::silver: return drawing::color {color::from_argb(0xFFC0C0C0), color};
    case known_color::sky_blue: return drawing::color {color::from_argb(0xFF87CEEB), color};
    case known_color::slate_blue: return drawing::color {color::from_argb(0xFF6A5ACD), color};
    case known_color::slate_gray: return drawing::color {color::from_argb(0xFF708090), color};
    case known_color::snow: return drawing::color {color::from_argb(0xFFFFFAFA), color};
    case known_color::spring_green: return drawing::color {color::from_argb(0xFF00FF7F), color};
    case known_color::steel_blue: return drawing::color {color::from_argb(0xFF4682B4), color};
    case known_color::tan: return drawing::color {color::from_argb(0xFFD2B48C), color};
    case known_color::teal: return drawing::color {color::from_argb(0xFF008080), color};
    case known_color::thistle: return drawing::color {color::from_argb(0xFFD8BFD8), color};
    case known_color::tomato: return drawing::color {color::from_argb(0xFFFF6347), color};
    case known_color::turquoise: return drawing::color {color::from_argb(0xFF40E0D0), color};
    case known_color::violet: return drawing::color {color::from_argb(0xFFEE82EE), color};
    case known_color::wheat: return drawing::color {color::from_argb(0xFFF5DEB3), color};
    case known_color::white: return drawing::color {color::from_argb(0xFFFFFFFF), color};
    case known_color::white_smoke: return drawing::color {color::from_argb(0xFFF5F5F5), color};
    case known_color::yellow: return drawing::color {color::from_argb(0xFFFFFF00), color};
    case known_color::yellow_green: return drawing::color {color::from_argb(0xFF9ACD32), color};

      // Apple colors
    case known_color::apple_black: return drawing::color {color::from_argb(0xFF000000), color};
    case known_color::apple_blue: return drawing::color {color::from_argb(0xFF0000FF), color};
    case known_color::apple_brown: return drawing::color {color::from_argb(0xFF996633), color};
    case known_color::apple_cyan: return drawing::color {color::from_argb(0xFF21FFFF), color};
    case known_color::apple_green: return drawing::color {color::from_argb(0xFF21FF06), color};
    case known_color::apple_magenta: return drawing::color {color::from_argb(0xFFFB02FF), color};
    case known_color::apple_orange: return drawing::color {color::from_argb(0xFFFD8008), color};
    case known_color::apple_purple: return drawing::color {color::from_argb(0xFF800080), color};
    case known_color::apple_red: return drawing::color {color::from_argb(0xFFFB0207), color};
    case known_color::apple_yellow: return drawing::color {color::from_argb(0xFFFFFF0A), color};
    case known_color::apple_white: return drawing::color {color::from_argb(0xFFFFFFFF), color};

      // Crayons colors
    case known_color::crayons_licorice: return drawing::color {color::from_argb(0xFF000000), color};
    case known_color::crayons_lead: return drawing::color {color::from_argb(0xFF191919), color};
    case known_color::crayons_tungsten: return drawing::color {color::from_argb(0xFF333333), color};
    case known_color::crayons_iron: return drawing::color {color::from_argb(0xFF4C4C4C), color};
    case known_color::crayons_steel: return drawing::color {color::from_argb(0xFF666666), color};
    case known_color::crayons_tin: return drawing::color {color::from_argb(0xFF7F7F7F), color};
    case known_color::crayons_nickel: return drawing::color {color::from_argb(0xFF808080), color};
    case known_color::crayons_aluminium: return drawing::color {color::from_argb(0xFF999999), color};
    case known_color::crayons_magnesium: return drawing::color {color::from_argb(0xFFB3B3B3), color};
    case known_color::crayons_silver: return drawing::color {color::from_argb(0xFFCCCCCC), color};
    case known_color::crayons_mercury: return drawing::color {color::from_argb(0xFFE6E6E6), color};
    case known_color::crayons_snow: return drawing::color {color::from_argb(0xFFFFFFFF), color};
    case known_color::crayons_cayenne: return drawing::color {color::from_argb(0xFF800002), color};
    case known_color::crayons_mocha: return drawing::color {color::from_argb(0xFF804003), color};
    case known_color::crayons_asparagus: return drawing::color {color::from_argb(0xFF808004), color};
    case known_color::crayons_fern: return drawing::color {color::from_argb(0xFF408002), color};
    case known_color::crayons_clover: return drawing::color {color::from_argb(0xFF118002), color};
    case known_color::crayons_moss: return drawing::color {color::from_argb(0xFF118040), color};
    case known_color::crayons_teal: return drawing::color {color::from_argb(0xFF108080), color};
    case known_color::crayons_ocean: return drawing::color {color::from_argb(0xFF074080), color};
    case known_color::crayons_midnight: return drawing::color {color::from_argb(0xFF000080), color};
    case known_color::crayons_eggplant: return drawing::color {color::from_argb(0xFF400080), color};
    case known_color::crayons_plum: return drawing::color {color::from_argb(0xFF800080), color};
    case known_color::crayons_maroon: return drawing::color {color::from_argb(0xFF800040), color};
    case known_color::crayons_maraschino: return drawing::color {color::from_argb(0xFFFB0207), color};
    case known_color::crayons_tangerine: return drawing::color {color::from_argb(0xFFFD8008), color};
    case known_color::crayons_lemon: return drawing::color {color::from_argb(0xFFFFFF0A), color};
    case known_color::crayons_lime: return drawing::color {color::from_argb(0xFF80FF08), color};
    case known_color::crayons_spring: return drawing::color {color::from_argb(0xFF21FF06), color};
    case known_color::crayons_sea_foam: return drawing::color {color::from_argb(0xFF21FF80), color};
    case known_color::crayons_turquoise: return drawing::color {color::from_argb(0xFF21FFFF), color};
    case known_color::crayons_aqua: return drawing::color {color::from_argb(0xFF0F80FF), color};
    case known_color::crayons_blueberry: return drawing::color {color::from_argb(0xFF0000FF), color};
    case known_color::crayons_grape: return drawing::color {color::from_argb(0xFF8000FF), color};
    case known_color::crayons_magenta: return drawing::color {color::from_argb(0xFFFB02FF), color};
    case known_color::crayons_strawberry: return drawing::color {color::from_argb(0xFFFB0280), color};
    case known_color::crayons_salmon: return drawing::color {color::from_argb(0xFFFC6666), color};
    case known_color::crayons_cantaloupe: return drawing::color {color::from_argb(0xFFFECC66), color};
    case known_color::crayons_banana: return drawing::color {color::from_argb(0xFFFFFF66), color};
    case known_color::crayons_honeydew: return drawing::color {color::from_argb(0xFFCCFF66), color};
    case known_color::crayons_flora: return drawing::color {color::from_argb(0xFF66FF66), color};
    case known_color::crayons_spindrift: return drawing::color {color::from_argb(0xFF66FFCC), color};
    case known_color::crayons_ice: return drawing::color {color::from_argb(0xFF66FFFF), color};
    case known_color::crayons_sky: return drawing::color {color::from_argb(0xFF66CCFF), color};
    case known_color::crayons_orchid: return drawing::color {color::from_argb(0xFF6666FF), color};
    case known_color::crayons_lavendar: return drawing::color {color::from_argb(0xFFCC66FF), color};
    case known_color::crayons_bubblegum: return drawing::color {color::from_argb(0xFFFC66FF), color};
    case known_color::crayons_carnation: return drawing::color {color::from_argb(0xFFFC6FCF), color};

      // "System" colors
    case known_color::accent: return drawing::color {color::from_handle(native::system_colors::accent()), color};
    case known_color::accent_text: return drawing::color {color::from_handle(native::system_colors::accent_text()), color};
    case known_color::active_border: return drawing::color {color::from_handle(native::system_colors::active_border()), color};
    case known_color::active_caption: return drawing::color {color::from_handle(native::system_colors::active_caption()), color};
    case known_color::active_caption_text: return drawing::color {color::from_handle(native::system_colors::active_caption_text()), color};
    case known_color::active_text: return drawing::color {color::from_handle(native::system_colors::active_text()), color};
    case known_color::app_workspace: return drawing::color {color::from_handle(native::system_colors::app_workspace()), color};
    case known_color::button_face: return drawing::color {color::from_handle(native::system_colors::button_face()), color};
    case known_color::button_highlight: return drawing::color {color::from_handle(native::system_colors::button_highlight()), color};
    case known_color::button_shadow: return drawing::color {color::from_handle(native::system_colors::button_shadow()), color};
    case known_color::control: return drawing::color {color::from_handle(native::system_colors::control()), color};
    case known_color::control_dark: return drawing::color {color::from_handle(native::system_colors::control_dark()), color};
    case known_color::control_dark_dark: return drawing::color {color::from_handle(native::system_colors::control_dark_dark()), color};
    case known_color::control_light: return drawing::color {color::from_handle(native::system_colors::control_light()), color};
    case known_color::control_light_light: return drawing::color {color::from_handle(native::system_colors::control_light_light()), color};
    case known_color::control_text: return drawing::color {color::from_handle(native::system_colors::control_text()), color};
    case known_color::desktop: return drawing::color {color::from_handle(native::system_colors::desktop()), color};
    case known_color::gradient_active_caption: return drawing::color {color::from_handle(native::system_colors::gradient_active_caption()), color};
    case known_color::gradient_inactive_caption: return drawing::color {color::from_handle(native::system_colors::gradient_inactive_caption()), color};
    case known_color::gray_text: return drawing::color {color::from_handle(native::system_colors::gray_text()), color};
    case known_color::highlight: return drawing::color {color::from_handle(native::system_colors::highlight()), color};
    case known_color::highlight_text: return drawing::color {color::from_handle(native::system_colors::highlight_text()), color};
    case known_color::hot_track: return drawing::color {color::from_handle(native::system_colors::hot_track()), color};
    case known_color::inactive_border: return drawing::color {color::from_handle(native::system_colors::inactive_border()), color};
    case known_color::inactive_caption: return drawing::color {color::from_handle(native::system_colors::inactive_caption()), color};
    case known_color::inactive_caption_text: return drawing::color {color::from_handle(native::system_colors::inactive_caption_text()), color};
    case known_color::info: return drawing::color {color::from_handle(native::system_colors::info()), color};
    case known_color::info_text: return drawing::color {color::from_handle(native::system_colors::info_text()), color};
    case known_color::link_text: return drawing::color {color::from_handle(native::system_colors::link_text()), color};
    case known_color::menu: return drawing::color {color::from_handle(native::system_colors::menu()), color};
    case known_color::menu_bar: return drawing::color {color::from_handle(native::system_colors::menu_bar()), color};
    case known_color::menu_highlight: return drawing::color {color::from_handle(native::system_colors::menu_highlight()), color};
    case known_color::menu_text: return drawing::color {color::from_handle(native::system_colors::menu_text()), color};
    case known_color::scroll_bar: return drawing::color {color::from_handle(native::system_colors::scroll_bar()), color};
    case known_color::shadow_text: return drawing::color {color::from_handle(native::system_colors::shadow_text()), color};
    case known_color::text_box: return drawing::color {color::from_handle(native::system_colors::text_box()), color};
    case known_color::text_box_text: return drawing::color {color::from_handle(native::system_colors::text_box_text()), color};
    case known_color::visited_text: return drawing::color {color::from_handle(native::system_colors::visited_text()), color};
    case known_color::window: return drawing::color {color::from_handle(native::system_colors::window()), color};
    case known_color::window_frame: return drawing::color {color::from_handle(native::system_colors::window_frame()), color};
    case known_color::window_text: return drawing::color {color::from_handle(native::system_colors::window_text()), color};

    default: throw xtd::argument_exception {"know_color invalid"_t, csf_};
  }
}

color color::from_name(const ustring& name) noexcept {
  static auto names = map<ustring, known_color> {};
  if (names.empty()) {
    for (auto entry : enum_object<>::get_entries<known_color>())
      names.insert({entry.second.replace("_", ""), entry.first});
  }
  
  auto key = name.to_lower().replace(" ", "").replace("_", "");
  auto it = names.find(key);
  if (it == names.end()) {
    auto result = color {};
    result.empty_ = name == "";
    result.name_ = name;
    return result;
  }
  
  try {
    return color::from_known_color(it->second);
  } catch (...) {
    return color::empty;
  }
}

float color::get_brightness() const noexcept {
  // .net version (see https://referencesource.microsoft.com/#System.Drawing/commonui/System/Drawing/color.cs,9103fd761ca562ae)
  //return ((float)max(max(r(), g()), b()) + (float)min(min(r(), g()), b())) / 255.0 / 2.0;
  // algorithm  version (see https://www.programmingalgorithms.com/algorithm/rgb-to-hsv)
  return static_cast<float>(math::max(math::max(r(), g()), b())) / 255.0f;
}

float color::get_hue() const noexcept {
  if (r() == g() && g() == b())
    return 0.0;
    
  auto rc = static_cast<float>(r()) / 255.0f;
  auto gc = static_cast<float>(g()) / 255.0f;
  auto bc = static_cast<float>(b()) / 255.0f;
  
  auto max = static_cast<float>(math::max(math::max(rc, gc), bc));
  auto min = static_cast<float>(math::min(math::min(rc, gc), bc));
  
  auto delta = max - min;
  
  auto hue = 0.0f;
  if (rc == max) hue = (gc - bc) / delta;
  else if (gc == max) hue = 2 + (bc - rc) / delta;
  else if (bc == max) hue = 4 + (rc - gc) / delta;
  hue *= 60;
  
  if (hue < 0.0) hue += 360.0;
  return hue;
}

float color::get_lightness() const noexcept {
  return (static_cast<float>(math::max(math::max(r(), g()), b())) + static_cast<float>(math::min(math::min(r(), g()), b()))) / 2.0f / 255.0f;
}

float color::get_saturation() const noexcept {
  auto max = static_cast<float>(math::max(math::max(r(), g()), b())) / 255.0f;
  auto min = static_cast<float>(math::min(math::min(r(), g()), b())) / 255.0f;
  
  if (max == min) return 0.0f;
  
  return (max + min) <= 1.0f ? (max - min) / (max + min) : (max - min) / (2 - max - min);
}

color color::grayscale(const color& color) noexcept {
  return grayscale(color, 1.0);
}

color color::grayscale(const color& color, double percent) noexcept {
  // From https://stackoverflow.com/questions/14330/rgb-to-monochrome-conversion
  percent = std::clamp(percent, 0.0, 1.0);
  auto grayscale = static_cast<xtd::byte>((0.299 * color.r()) + (0.587 * color.g()) + (0.114 * color.b()));
  return alpha_blend(color, color::from_argb(color.a(), grayscale, grayscale, grayscale), percent);
}

color color::hue_rotate(const color& color, int angle) noexcept {
  angle = std::clamp(angle, 0, 360);

  auto h = static_cast<int>(color.get_hue());
  h = (h + angle) % 360;
  if (h < 0) h += 360;

  return color::from_hsl(static_cast<float>(h), color.get_saturation(), color.get_lightness());
}

color color::invert(const color& color) noexcept {
  return invert(color, 1.0);
}

color color::invert(const color& color,  double percent) noexcept {
  percent = std::clamp(percent, 0.0, 1.0);
  return alpha_blend(color, color::from_argb(color.a(), 255 - color.r(), 255 - color.g(), 255 - color.b()), percent);
}

color color::light(const color& color) noexcept {
  return color::light(color, 1.0 / 3);
}

color color::light(const color& color, double percent) noexcept {
  percent = std::clamp(percent, 0.0, 1.0);
  return alpha_blend(color, color::white, percent);
}

color color::parse(const ustring& color) noexcept {
  try {
    auto argb = color.replace("color [a=", "").replace(" r=", "").replace(" g=", "").replace("b=", "").replace("]", "").split({','});
    if (argb.size() == 1) return color::from_argb(xtd::parse<uint32>(argb.at(0), xtd::number_styles::hex_number));
    return color::from_argb(ustring::parse<xtd::byte>(argb.at(0)), ustring::parse<xtd::byte>(argb.at(1)), ustring::parse<xtd::byte>(argb.at(2)), ustring::parse<xtd::byte>(argb.at(3)));
  } catch (...) {
    return color::from_name(color.replace("]", "").replace("color [", ""));
  }
}

color color::saturate(const color& color, double percent) noexcept {
  if (percent < .0) percent = 0;

  auto r = color.r() / 255.0;
  auto g = color.g() / 255.0;
  auto b = color.b() / 255.0;
  
  auto gray = 0.2989 * r + 0.5870 * g + 0.1140 * b;
  auto saturated_r = gray + (r - gray) * percent;
  auto saturated_g = gray + (g - gray) * percent;
  auto saturated_b = gray + (b - gray) * percent;
  
  saturated_r = std::clamp(saturated_r, 0.0, 1.0);
  saturated_g = std::clamp(saturated_g, 0.0, 1.0);
  saturated_b = std::clamp(saturated_b, 0.0, 1.0);

  return from_argb(color.a(), static_cast<int>(saturated_r * 255), static_cast<int>(saturated_g * 255), static_cast<int>(saturated_b * 255));
}

color color::sepia(const color& color) noexcept {
  return sepia(color, 1.0);
}

color color::sepia(const color& color, double percent) noexcept {
  // From https://www.geeksforgeeks.org/image-processing-in-java-colored-image-to-sepia-image-conversion/
  percent = std::clamp(percent, 0.0, 1.0);
  auto r = std::clamp(0.393 * color.r() + 0.769 * color.g() + 0.189 * color.b(), .0, 255.0);
  auto g = std::clamp(0.349 * color.r() + 0.686 * color.g() + 0.168 * color.b(), .0, 255.0);
  auto b = std::clamp(0.272 * color.r() + 0.534 * color.g() + 0.131 * color.b(), .0, 255.0);
  return alpha_blend(color, color::from_argb(color.a(), static_cast<xtd::byte>(r), static_cast<xtd::byte>(g), static_cast<xtd::byte>(b)), percent);
}

uint32 color::to_argb() const noexcept {
  if (handle_) return native::system_colors::to_argb(handle_);
  return argb_;
}

known_color color::to_known_color() const noexcept {
  return known_color_;
}

ustring color::to_string() const noexcept {
  if (empty_) return "color [empty]";
  if (name() != ustring::format("{:x8}", argb_) && name() != "0") return ustring::format("color [{0}]", name());
  return ustring::format("color [a={}, r={}, g={}, b={}]", a(), r(), g(), b());
}

color::color(uint32 argb) : argb_(argb), empty_(false) {
}

color::color(intptr handle) : empty_(false), handle_(handle) {
}
