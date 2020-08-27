#include "../../../include/xtd/drawing/color.h"
#include <xtd/drawing/native/system_colors.h>
#include <cmath>
#include <map>
#include <stdexcept>
#include <sstream>
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
const color color::dark_oliveGreen = color::from_known_color(known_color::dark_olive_green);
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

color::color(const color& color, const known_color& known_color) : argb_(color.argb_), handle_(color.handle_), known_color_(known_color), name_(strings::format("{}", known_color)), empty_(false) {
}

bool color::is_system_color() const {
  return this->known_color_ != (known_color)0 && (this->known_color_ <= known_color::window_text || this->known_color_ >= drawing::known_color::button_face);
}

color color::from_argb(uint32_t argb) {
  return color(argb);
}

color color::from_argb(uint8_t alpha, const color& baseColor) {
  return color((alpha << 24) + ((baseColor.handle_ ? native::system_colors::to_argb(baseColor.handle_) : baseColor.argb_) & 0x00FFFFFF));
}

color color::from_argb(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue) {
  return color(((uint32_t)alpha << 24) + ((uint32_t)red << 16) + ((uint32_t)green << 8) + blue);
}

color color::from_argb(uint8_t red, uint8_t green, uint8_t blue) {
  return from_argb(0xFF, red, green, blue);
}

color color::from_handle(intptr_t handle) {
  return color(handle);
}

color color::from_hsb(float hue, float saturation, float brightness) {
  // algorithm version (see https://www.programmingalgorithms.com/algorithm/hsv-to-rgb)
  if (saturation == 0) return color::from_argb(255, static_cast<uint8_t>(brightness * 255.0f), static_cast<uint8_t>(brightness * 255.0f), static_cast<uint8_t>(brightness * 255.0f));
  
  hue = hue >= 360 ? 0 : hue / 60;
  
  float f = hue - trunc(hue);
  float p = brightness * (1.0f - saturation);
  float q = brightness * (1.0f - (saturation * f));
  float t = brightness * (1.0f - (saturation * (1.0f - f)));
  
  switch (static_cast<int>(trunc(hue))) {
    case 0: return color::from_argb(255, static_cast<uint8_t>(brightness * 255.0f), static_cast<uint8_t>(t * 255.0f), static_cast<uint8_t>(p * 255.0f));
    case 1: return color::from_argb(255, static_cast<uint8_t>(q * 255.0f), static_cast<uint8_t>(brightness * 255.0f), static_cast<uint8_t>(p * 255.0f));
    case 2: return color::from_argb(255, static_cast<uint8_t>(p * 255.0f),  static_cast<uint8_t>(brightness * 255.0f), static_cast<uint8_t>(t * 255.0f));
    case 3: return color::from_argb(255, static_cast<uint8_t>(p * 255.0f), static_cast<uint8_t>(q * 255.0f), static_cast<uint8_t>(brightness * 255.0f));
    case 4: return color::from_argb(255, static_cast<uint8_t>(t * 255.0f), static_cast<uint8_t>(p * 255.0f), static_cast<uint8_t>(brightness * 255.0f));
    default: return color::from_argb(255, static_cast<uint8_t>(brightness * 255.0f), static_cast<uint8_t>(p * 255.0f), static_cast<uint8_t>(q * 255.0f));
  }
}

color color::from_hsl(float hue, float saturation, float lightness) {
  // algorithm version (see https://www.programmingalgorithms.com/algorithm/hsl-to-rgb)
  if (saturation == 0) return color::from_argb(255, static_cast<uint8_t>(lightness * 255.0f), static_cast<uint8_t>(lightness * 255.0f), static_cast<uint8_t>(lightness * 255.0f));

  auto hue_to_rgb = [](float v1, float v2, float vh)->float {
    if (vh < 0) vh += 1;
    if (vh > 1) vh -= 1;
    if ((6 * vh) < 1) return (v1 + (v2 - v1) * 6 * vh);
    if ((2 * vh) < 1) return v2;
    if ((3 * vh) < 2) return (v1 + (v2 - v1) * ((2.0f / 3) - vh) * 6);
    return v1;
  };
  
  if (saturation == 0) return color::from_argb(255, static_cast<uint8_t>(lightness * 255.0f), static_cast<uint8_t>(lightness * 255.0f), static_cast<uint8_t>(lightness * 255.0f));

  hue = hue / 360.0f;
  float v2 = (lightness < 0.5f) ? (lightness * (1 + saturation)) : ((lightness + saturation) - (lightness * saturation));
  float v1 = 2 * lightness - v2;
  
  return color::from_argb(255, static_cast<uint8_t>(hue_to_rgb(v1, v2, hue + (1.0f / 3)) * 255.0f), static_cast<uint8_t>(hue_to_rgb(v1, v2, hue) * 255.0f), static_cast<uint8_t>(hue_to_rgb(v1, v2, hue - (1.0f / 3)) * 255.0f));
}

color color::from_name(const string& name) {
  string key = strings::replace(strings::replace(strings::to_lower(name), " ", ""), "_", "");
  static map<string, known_color> names {{"activeborder", known_color::active_border}, {"activecaption", known_color::active_caption}, {"activecaptiontext", known_color::active_caption_text}, {"appworkspace", known_color::app_workspace}, {"control", known_color::control}, {"controldark", known_color::control_dark}, {"controldarkdark", known_color::control_dark_dark}, {"controllight", known_color::control_light}, {"controllightlight", known_color::control_light_light}, {"controltext", known_color::control_text}, {"desktop", known_color::desktop}, {"graytext", known_color::gray_text}, {"highlight", known_color::highlight}, {"highlighttext", known_color::highlight_text}, {"hottrack", known_color::hot_track}, {"inactiveborder", known_color::inactive_border}, {"inactivecaption", known_color::inactive_caption}, {"inactivecaptiontext", known_color::inactive_caption_text}, {"info", known_color::info}, {"infotext", known_color::info_text}, {"menu", known_color::menu}, {"menutext", known_color::menu_text}, {"scrollbar", known_color::scroll_bar}, {"window", known_color::window}, {"windowframe", known_color::window_frame}, {"windowtext", known_color::window_text}, {"transparent", known_color::transparent}, {"aliceblue", known_color::alice_blue}, {"antiquewhite", known_color::antique_white}, {"aqua", known_color::aqua}, {"aquamarine", known_color::aquamarine}, {"azure", known_color::azure}, {"beige", known_color::beige}, {"bisque", known_color::bisque}, {"black", known_color::black}, {"blanchedalmond", known_color::blanched_almond}, {"blue", known_color::blue}, {"blueviolet", known_color::blue_violet}, {"brown", known_color::brown}, {"burlywood", known_color::burly_wood}, {"cadetblue", known_color::cadet_blue}, {"chartreuse", known_color::chartreuse}, {"chocolate", known_color::chocolate}, {"coral", known_color::coral}, {"cornflowerblue", known_color::cornflower_blue}, {"cornsilk", known_color::cornsilk}, {"crimson", known_color::crimson}, {"cyan", known_color::cyan}, {"darkblue", known_color::dark_blue}, {"darkcyan", known_color::dark_cyan}, {"darkgoldenrod", known_color::dark_goldenrod}, {"darkgray", known_color::dark_gray}, {"darkgreen", known_color::dark_green}, {"darkkhaki", known_color::dark_khaki}, {"darkmagenta", known_color::dark_magenta}, {"darkolivegreen", known_color::dark_olive_green}, {"darkorange", known_color::dark_orange}, {"darkorchid", known_color::dark_orchid}, {"darkred", known_color::dark_red}, {"darksalmon", known_color::dark_salmon}, {"darkseagreen", known_color::dark_sea_green}, {"darkslateblue", known_color::dark_slate_blue}, {"darkslategray", known_color::dark_slate_gray}, {"darkturquoise", known_color::dark_turquoise}, {"darkviolet", known_color::dark_violet}, {"deeppink", known_color::deep_pink}, {"deepskyblue", known_color::deep_sky_blue}, {"dimgray", known_color::dim_gray}, {"dodgerblue", known_color::dodger_blue}, {"firebrick", known_color::firebrick}, {"floralwhite", known_color::floral_white}, {"forestgreen", known_color::forest_green}, {"fuchsia", known_color::fuchsia}, {"gainsboro", known_color::gainsboro}, {"ghostwhite", known_color::ghost_white}, {"gold", known_color::gold}, {"goldenrod", known_color::goldenrod}, {"gray", known_color::gray}, {"green", known_color::green}, {"greenyellow", known_color::green_yellow}, {"honeydew", known_color::honeydew}, {"hotpink", known_color::hot_pink}, {"indianred", known_color::indian_red}, {"indigo", known_color::indigo}, {"ivory", known_color::ivory}, {"khaki", known_color::khaki}, {"lavender", known_color::lavender}, {"lavenderblush", known_color::lavender_blush}, {"lawngreen", known_color::lawn_green}, {"lemonchiffon", known_color::lemon_chiffon}, {"lightblue", known_color::light_blue}, {"lightcoral", known_color::light_coral}, {"lightcyan", known_color::light_cyan}, {"lightgoldenrodyellow", known_color::light_goldenrod_yellow}, {"lightgray", known_color::light_gray}, {"lightgreen", known_color::light_green}, {"lightpink", known_color::light_pink}, {"lightsalmon", known_color::light_salmon}, {"lightseagreen", known_color::light_sea_green}, {"lightskyblue", known_color::light_sky_blue}, {"lightslategray", known_color::light_slate_gray}, {"lightsteelblue", known_color::light_steel_blue}, {"lightyellow", known_color::light_yellow}, {"lime", known_color::lime}, {"limegreen", known_color::lime_green}, {"linen", known_color::linen}, {"magenta", known_color::magenta}, {"maroon", known_color::maroon}, {"mediumaquamarine", known_color::medium_aquamarine}, {"mediumblue", known_color::medium_blue}, {"mediumorchid", known_color::medium_orchid}, {"mediumpurple", known_color::medium_purple}, {"mediumseagreen", known_color::medium_sea_green}, {"mediumslateblue", known_color::medium_slate_blue}, {"mediumspringgreen", known_color::medium_spring_green}, {"mediumturquoise", known_color::medium_turquoise}, {"mediumvioletred", known_color::medium_violet_red}, {"midnightblue", known_color::midnight_blue}, {"mintcream", known_color::mint_cream}, {"mistyrose", known_color::misty_rose}, {"moccasin", known_color::moccasin}, {"navajowhite", known_color::navajo_white}, {"navy", known_color::navy}, {"oldlace", known_color::old_lace}, {"olive", known_color::olive}, {"olivedrab", known_color::olive_drab}, {"orange", known_color::orange}, {"orangered", known_color::orange_red}, {"orchid", known_color::orchid}, {"palegoldenrod", known_color::pale_goldenrod}, {"palegreen", known_color::pale_green}, {"paleturquoise", known_color::pale_turquoise}, {"palevioletred", known_color::pale_violet_red}, {"papayawhip", known_color::papaya_whip}, {"peachpuff", known_color::peach_puff}, {"peru", known_color::peru}, {"pink", known_color::pink}, {"plum", known_color::plum}, {"powderblue", known_color::powder_blue}, {"purple", known_color::purple}, {"rebeccapurple", known_color::rebecca_purple}, {"red", known_color::red}, {"rosybrown", known_color::rosy_brown}, {"royalblue", known_color::royal_blue}, {"saddlebrown", known_color::saddle_brown}, {"salmon", known_color::salmon}, {"sandybrown", known_color::sandy_brown}, {"seagreen", known_color::sea_green}, {"seashell", known_color::sea_shell}, {"sienna", known_color::sienna}, {"silver", known_color::silver}, {"skyblue", known_color::sky_blue}, {"slateblue", known_color::slate_blue}, {"slategray", known_color::slate_gray}, {"snow", known_color::snow}, {"springgreen", known_color::spring_green}, {"steelblue", known_color::steel_blue}, {"tan", known_color::tan}, {"teal", known_color::teal}, {"thistle", known_color::thistle}, {"tomato", known_color::tomato}, {"turquoise", known_color::turquoise}, {"violet", known_color::violet}, {"wheat", known_color::wheat}, {"white", known_color::white}, {"whitesmoke", known_color::white_smoke}, {"yellow", known_color::yellow}, {"yellowgreen", known_color::yellow_green}, {"buttonface", known_color::button_face}, {"buttonhighlight", known_color::button_highlight}, {"buttonshadow", known_color::button_shadow}, {"gradientactivecaption", known_color::gradient_active_caption}, {"gradientinactivecaption", known_color::gradient_inactive_caption}, {"menubar", known_color::menu_bar}, {"menuhighlight", known_color::menu_highlight}};
  if (names.find(key) == names.end()) {
    color result;
    result.empty_ = false;
    result.name_ = name;
    return result;
  }
  return color::from_known_color(names[key]);
}

color color::from_known_color(known_color color) {
  switch (color) {
    case known_color::active_border: return drawing::color(color::from_handle(native::system_colors::active_border()), color);
    case known_color::active_caption: return drawing::color(color::from_handle(native::system_colors::active_caption()), color);
    case known_color::active_caption_text: return drawing::color(color::from_handle(native::system_colors::active_caption_text()), color);
    case known_color::app_workspace: return drawing::color(color::from_handle(native::system_colors::app_workspace()), color);
    case known_color::control: return drawing::color(color::from_handle(native::system_colors::control()), color);
    case known_color::control_dark: return drawing::color(color::from_handle(native::system_colors::control_dark()), color);
    case known_color::control_dark_dark: return drawing::color(color::from_handle(native::system_colors::control_dark_dark()), color);
    case known_color::control_light: return drawing::color(color::from_handle(native::system_colors::control_light()), color);
    case known_color::control_light_light: return drawing::color(color::from_handle(native::system_colors::control_light_light()), color);
    case known_color::control_text: return drawing::color(color::from_handle(native::system_colors::control_text()), color);
    case known_color::desktop: return drawing::color(color::from_handle(native::system_colors::desktop()), color);
    case known_color::gray_text: return drawing::color(color::from_handle(native::system_colors::gray_text()), color);
    case known_color::highlight: return drawing::color(color::from_handle(native::system_colors::highlight()), color);
    case known_color::highlight_text: return drawing::color(color::from_handle(native::system_colors::highlight_text()), color);
    case known_color::hot_track: return drawing::color(color::from_handle(native::system_colors::hot_track()), color);
    case known_color::inactive_border: return drawing::color(color::from_handle(native::system_colors::inactive_border()), color);
    case known_color::inactive_caption: return drawing::color(color::from_handle(native::system_colors::inactive_caption()), color);
    case known_color::inactive_caption_text: return drawing::color(color::from_handle(native::system_colors::inactive_caption_text()), color);
    case known_color::info: return drawing::color(color::from_handle(native::system_colors::info()), color);
    case known_color::info_text: return drawing::color(color::from_handle(native::system_colors::info_text()), color);
    case known_color::menu: return drawing::color(color::from_handle(native::system_colors::menu()), color);
    case known_color::menu_text: return drawing::color(color::from_handle(native::system_colors::menu_text()), color);
    case known_color::scroll_bar: return drawing::color(color::from_handle(native::system_colors::scroll_bar()), color);
    case known_color::window: return drawing::color(color::from_handle(native::system_colors::window()), color);
    case known_color::window_frame: return drawing::color(color::from_handle(native::system_colors::window_frame()), color);
    case known_color::window_text: return drawing::color(color::from_handle(native::system_colors::window_text()), color);
    case known_color::transparent: return drawing::color(color::from_argb(0x00FFFFFF), color);
    case known_color::alice_blue: return drawing::color(color::from_argb(0xFFF0F8FF), color);
    case known_color::antique_white: return drawing::color(color::from_argb(0xFFFAEBD7), color);
    case known_color::aqua: return drawing::color(color::from_argb(0xFF00FFFF), color);
    case known_color::aquamarine: return drawing::color(color::from_argb(0xFF7FFFD4), color);
    case known_color::azure: return drawing::color(color::from_argb(0xFFF0FFFF), color);
    case known_color::beige: return drawing::color(color::from_argb(0xFFF5F5DC), color);
    case known_color::bisque: return drawing::color(color::from_argb(0xFFFFE4C4), color);
    case known_color::black: return drawing::color(color::from_argb(0xFF000000), color);
    case known_color::blanched_almond: return drawing::color(color::from_argb(0xFFFFEBCD), color);
    case known_color::blue: return drawing::color(color::from_argb(0xFF0000FF), color);
    case known_color::blue_violet: return drawing::color(color::from_argb(0xFF8A2BE2), color);
    case known_color::brown: return drawing::color(color::from_argb(0xFFA52A2A), color);
    case known_color::burly_wood: return drawing::color(color::from_argb(0xFFDEB887), color);
    case known_color::cadet_blue: return drawing::color(color::from_argb(0xFF5F9EA0), color);
    case known_color::chartreuse: return drawing::color(color::from_argb(0xFF7FFF00), color);
    case known_color::chocolate: return drawing::color(color::from_argb(0xFFD2691E), color);
    case known_color::coral: return drawing::color(color::from_argb(0xFFFF7F50), color);
    case known_color::cornflower_blue: return drawing::color(color::from_argb(0xFF6495ED), color);
    case known_color::cornsilk: return drawing::color(color::from_argb(0xFFFFF8DC), color);
    case known_color::crimson: return drawing::color(color::from_argb(0xFFDC143C), color);
    case known_color::cyan: return drawing::color(color::from_argb(0xFF00FFFF), color);
    case known_color::dark_blue: return drawing::color(color::from_argb(0xFF00008B), color);
    case known_color::dark_cyan: return drawing::color(color::from_argb(0xFF008B8B), color);
    case known_color::dark_goldenrod: return drawing::color(color::from_argb(0xFFB8860B), color);
    case known_color::dark_gray: return drawing::color(color::from_argb(0xFFA9A9A9), color);
    case known_color::dark_green: return drawing::color(color::from_argb(0xFF006400), color);
    case known_color::dark_khaki: return drawing::color(color::from_argb(0xFFBDB76B), color);
    case known_color::dark_magenta: return drawing::color(color::from_argb(0xFF8B008B), color);
    case known_color::dark_olive_green: return drawing::color(color::from_argb(0xFF556B2F), color);
    case known_color::dark_orange: return drawing::color(color::from_argb(0xFFFF8C00), color);
    case known_color::dark_orchid: return drawing::color(color::from_argb(0xFF9932CC), color);
    case known_color::dark_red: return drawing::color(color::from_argb(0xFF8B0000), color);
    case known_color::dark_salmon: return drawing::color(color::from_argb(0xFFE9967A), color);
    case known_color::dark_sea_green: return drawing::color(color::from_argb(0xFF8FBC8B), color);
    case known_color::dark_slate_blue: return drawing::color(color::from_argb(0xFF483D8B), color);
    case known_color::dark_slate_gray: return drawing::color(color::from_argb(0xFF2F4F4F), color);
    case known_color::dark_turquoise: return drawing::color(color::from_argb(0xFF00CED1), color);
    case known_color::dark_violet: return drawing::color(color::from_argb(0xFF9400D3), color);
    case known_color::deep_pink: return drawing::color(color::from_argb(0xFFFF1493), color);
    case known_color::deep_sky_blue: return drawing::color(color::from_argb(0xFF00BFFF), color);
    case known_color::dim_gray: return drawing::color(color::from_argb(0xFF696969), color);
    case known_color::dodger_blue: return drawing::color(color::from_argb(0xFF1E90FF), color);
    case known_color::firebrick: return drawing::color(color::from_argb(0xFFB22222), color);
    case known_color::floral_white: return drawing::color(color::from_argb(0xFFFFFAF0), color);
    case known_color::forest_green: return drawing::color(color::from_argb(0xFF228B22), color);
    case known_color::fuchsia: return drawing::color(color::from_argb(0xFFFF00FF), color);
    case known_color::gainsboro: return drawing::color(color::from_argb(0xFFDCDCDC), color);
    case known_color::ghost_white: return drawing::color(color::from_argb(0xFFF8F8FF), color);
    case known_color::gold: return drawing::color(color::from_argb(0xFFFFD700), color);
    case known_color::goldenrod: return drawing::color(color::from_argb(0xFFDAA520), color);
    case known_color::gray: return drawing::color(color::from_argb(0xFF808080), color);
    case known_color::green: return drawing::color(color::from_argb(0xFF008000), color);
    case known_color::green_yellow: return drawing::color(color::from_argb(0xFFADFF2F), color);
    case known_color::honeydew: return drawing::color(color::from_argb(0xFFF0FFF0), color);
    case known_color::hot_pink: return drawing::color(color::from_argb(0xFFFF69B4), color);
    case known_color::indian_red: return drawing::color(color::from_argb(0xFFCD5C5C), color);
    case known_color::indigo: return drawing::color(color::from_argb(0xFF4B0082), color);
    case known_color::ivory: return drawing::color(color::from_argb(0xFFFFFFF0), color);
    case known_color::khaki: return drawing::color(color::from_argb(0xFFF0E68C), color);
    case known_color::lavender: return drawing::color(color::from_argb(0xFFE6E6FA), color);
    case known_color::lavender_blush: return drawing::color(color::from_argb(0xFFFFF0F5), color);
    case known_color::lawn_green: return drawing::color(color::from_argb(0xFF7CFC00), color);
    case known_color::lemon_chiffon: return drawing::color(color::from_argb(0xFFFFFACD), color);
    case known_color::light_blue: return drawing::color(color::from_argb(0xFFADD8E6), color);
    case known_color::light_coral: return drawing::color(color::from_argb(0xFFF08080), color);
    case known_color::light_cyan: return drawing::color(color::from_argb(0xFFE0FFFF), color);
    case known_color::light_goldenrod_yellow: return drawing::color(color::from_argb(0xFFFAFAD2), color);
    case known_color::light_gray: return drawing::color(color::from_argb(0xFFD3D3D3), color);
    case known_color::light_green: return drawing::color(color::from_argb(0xFF90EE90), color);
    case known_color::light_pink: return drawing::color(color::from_argb(0xFFFFB6C1), color);
    case known_color::light_salmon: return drawing::color(color::from_argb(0xFFFFA07A), color);
    case known_color::light_sea_green: return drawing::color(color::from_argb(0xFF20B2AA), color);
    case known_color::light_sky_blue: return drawing::color(color::from_argb(0xFF87CEFA), color);
    case known_color::light_slate_gray: return drawing::color(color::from_argb(0xFF778899), color);
    case known_color::light_steel_blue: return drawing::color(color::from_argb(0xFFB0C4DE), color);
    case known_color::light_yellow: return drawing::color(color::from_argb(0xFFFFFFE0), color);
    case known_color::lime: return drawing::color(color::from_argb(0xFF00FF00), color);
    case known_color::lime_green: return drawing::color(color::from_argb(0xFF32CD32), color);
    case known_color::linen: return drawing::color(color::from_argb(0xFFFAF0E6), color);
    case known_color::magenta: return drawing::color(color::from_argb(0xFFFF00FF), color);
    case known_color::maroon: return drawing::color(color::from_argb(0xFF800000), color);
    case known_color::medium_aquamarine: return drawing::color(color::from_argb(0xFF66CDAA), color);
    case known_color::medium_blue: return drawing::color(color::from_argb(0xFF0000CD), color);
    case known_color::medium_orchid: return drawing::color(color::from_argb(0xFFBA55D3), color);
    case known_color::medium_purple: return drawing::color(color::from_argb(0xFF9370DB), color);
    case known_color::medium_sea_green: return drawing::color(color::from_argb(0xFF3CB371), color);
    case known_color::medium_slate_blue: return drawing::color(color::from_argb(0xFF7B68EE), color);
    case known_color::medium_spring_green: return drawing::color(color::from_argb(0xFF00FA9A), color);
    case known_color::medium_turquoise: return drawing::color(color::from_argb(0xFF48D1CC), color);
    case known_color::medium_violet_red: return drawing::color(color::from_argb(0xFFC71585), color);
    case known_color::midnight_blue: return drawing::color(color::from_argb(0xFF191970), color);
    case known_color::mint_cream: return drawing::color(color::from_argb(0xFFF5FFFA), color);
    case known_color::misty_rose: return drawing::color(color::from_argb(0xFFFFE4E1), color);
    case known_color::moccasin: return drawing::color(color::from_argb(0xFFFFE4B5), color);
    case known_color::navajo_white: return drawing::color(color::from_argb(0xFFFFDEAD), color);
    case known_color::navy: return drawing::color(color::from_argb(0xFF000080), color);
    case known_color::old_lace: return drawing::color(color::from_argb(0xFFFDF5E6), color);
    case known_color::olive: return drawing::color(color::from_argb(0xFF808000), color);
    case known_color::olive_drab: return drawing::color(color::from_argb(0xFF6B8E23), color);
    case known_color::orange: return drawing::color(color::from_argb(0xFFFFA500), color);
    case known_color::orange_red: return drawing::color(color::from_argb(0xFFFF4500), color);
    case known_color::orchid: return drawing::color(color::from_argb(0xFFDA70D6), color);
    case known_color::pale_goldenrod: return drawing::color(color::from_argb(0xFFEEE8AA), color);
    case known_color::pale_green: return drawing::color(color::from_argb(0xFF98FB98), color);
    case known_color::pale_turquoise: return drawing::color(color::from_argb(0xFFAFEEEE), color);
    case known_color::pale_violet_red: return drawing::color(color::from_argb(0xFFDB7093), color);
    case known_color::papaya_whip: return drawing::color(color::from_argb(0xFFFFEFD5), color);
    case known_color::peach_puff: return drawing::color(color::from_argb(0xFFFFDAB9), color);
    case known_color::peru: return drawing::color(color::from_argb(0xFFCD853F), color);
    case known_color::pink: return drawing::color(color::from_argb(0xFFFFC0CB), color);
    case known_color::plum: return drawing::color(color::from_argb(0xFFDDA0DD), color);
    case known_color::powder_blue: return drawing::color(color::from_argb(0xFFB0E0E6), color);
    case known_color::purple: return drawing::color(color::from_argb(0xFF800080), color);
    case known_color::rebecca_purple: return drawing::color(color::from_argb(0xFF663399), color);
    case known_color::red: return drawing::color(color::from_argb(0xFFFF0000), color);
    case known_color::rosy_brown: return drawing::color(color::from_argb(0xFFBC8F8F), color);
    case known_color::royal_blue: return drawing::color(color::from_argb(0xFF4169E1), color);
    case known_color::saddle_brown: return drawing::color(color::from_argb(0xFF8B4513), color);
    case known_color::salmon: return drawing::color(color::from_argb(0xFFFA8072), color);
    case known_color::sandy_brown: return drawing::color(color::from_argb(0xFFF4A460), color);
    case known_color::sea_green: return drawing::color(color::from_argb(0xFF2E8B57), color);
    case known_color::sea_shell: return drawing::color(color::from_argb(0xFFFFF5EE), color);
    case known_color::sienna: return drawing::color(color::from_argb(0xFFA0522D), color);
    case known_color::silver: return drawing::color(color::from_argb(0xFFC0C0C0), color);
    case known_color::sky_blue: return drawing::color(color::from_argb(0xFF87CEEB), color);
    case known_color::slate_blue: return drawing::color(color::from_argb(0xFF6A5ACD), color);
    case known_color::slate_gray: return drawing::color(color::from_argb(0xFF708090), color);
    case known_color::snow: return drawing::color(color::from_argb(0xFFFFFAFA), color);
    case known_color::spring_green: return drawing::color(color::from_argb(0xFF00FF7F), color);
    case known_color::steel_blue: return drawing::color(color::from_argb(0xFF4682B4), color);
    case known_color::tan: return drawing::color(color::from_argb(0xFFD2B48C), color);
    case known_color::teal: return drawing::color(color::from_argb(0xFF008080), color);
    case known_color::thistle: return drawing::color(color::from_argb(0xFFD8BFD8), color);
    case known_color::tomato: return drawing::color(color::from_argb(0xFFFF6347), color);
    case known_color::turquoise: return drawing::color(color::from_argb(0xFF40E0D0), color);
    case known_color::violet: return drawing::color(color::from_argb(0xFFEE82EE), color);
    case known_color::wheat: return drawing::color(color::from_argb(0xFFF5DEB3), color);
    case known_color::white: return drawing::color(color::from_argb(0xFFFFFFFF), color);
    case known_color::white_smoke: return drawing::color(color::from_argb(0xFFF5F5F5), color);
    case known_color::yellow: return drawing::color(color::from_argb(0xFFFFFF00), color);
    case known_color::yellow_green: return drawing::color(color::from_argb(0xFF9ACD32), color);
    case known_color::button_face: return drawing::color(color::from_handle(native::system_colors::button_face()), color);
    case known_color::button_highlight: return drawing::color(color::from_handle(native::system_colors::button_highlight()), color);
    case known_color::button_shadow: return drawing::color(color::from_handle(native::system_colors::button_shadow()), color);
    case known_color::gradient_active_caption: return drawing::color(color::from_handle(native::system_colors::gradient_active_caption()), color);
    case known_color::gradient_inactive_caption: return drawing::color(color::from_handle(native::system_colors::gradient_inactive_caption()), color);
    case known_color::menu_bar: return drawing::color(color::from_handle(native::system_colors::menu_bar()), color);
    case known_color::menu_highlight: return drawing::color(color::from_handle(native::system_colors::menu_highlight()), color);
    case known_color::accent: return drawing::color(color::from_handle(native::system_colors::accent()), color);
    case known_color::accent_text: return drawing::color(color::from_handle(native::system_colors::accent_text()), color);
    default: throw std::invalid_argument("unknown know_color");
  }
}

float color::get_brightness() const {
  // .net version (see https://referencesource.microsoft.com/#System.Drawing/commonui/System/Drawing/color.cs,9103fd761ca562ae)
  //return ((float)max(max(this->r(), this->g()), this->b()) + (float)min(min(this->r(), this->g()), this->b())) / 255.0 / 2.0;
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

float color::get_lightness() const {
  return ((float)max(max(this->r(), this->g()), this->b()) + (float)min(min(this->r(), this->g()), this->b())) / 2.0f / 255.0f;
}

float color::get_saturation() const {
  float max = (float)std::max(std::max(this->r(), this->g()), this->b()) / 255.0f;
  float min = (float)std::min(std::min(this->r(), this->g()), this->b()) / 255.0f;
  
  if (max == min) return 0.0f;
  
  return (max + min) <= 1.0f ? (max - min) / (max + min) : (max - min) / (2 - max - min);
}

color color::parse(const string& color) {
   try {
     vector<string> argb = strings::split(strings::replace(strings::replace(strings::replace(strings::replace(strings::replace(color, "color [a=", ""), " r=", ""), " g=", ""), "b=", ""), "]", ""), {','});
     return color::from_argb(strings::parse<uint8_t>(argb.at(0)), strings::parse<uint8_t>(argb.at(1)), strings::parse<uint8_t>(argb.at(2)), strings::parse<uint8_t>(argb.at(3)));
   } catch(...) {
     return color::from_name(strings::replace(strings::replace(color, "]", ""), "color [", ""));
   }
  return color::empty;
}

uint32_t color::to_argb() const {
  if (this->handle_) return native::system_colors::to_argb(this->handle_);
  return this->argb_;
}

known_color color::to_known_color() const {
  return this->known_color_;
}

string color::to_string() const {
  if (this->empty_) return "color [empty]";
  if (this->name_ != strings::format("{:X8}", this->argb_) && this->name_ != "0") return strings::format("color [{0}]", name());
  return strings::format("color [a={}, r={}, g={}, b={}]", a(), r(), g(), b());
}

