#include "../../../include/xtd/drawing/color.hpp"
#include <xtd/drawing/native/system_colors.hpp>
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

color::color(uint32_t argb) : argb_(argb) {
}

color::color(const color& color, const known_color& known_color) : argb_(color.argb_), handle_(color.handle_), known_color_(known_color) {
}

bool color::is_system_color() const {
  return this->known_color_ != (known_color)0 && (this->known_color_ <= known_color::window_text || this->known_color_ >= drawing::known_color::button_face);
}

string color::name() const {
  if (this->known_color_ == (known_color)0 && this->argb_ == 0 && this->handle_ == 0)
    return "0";
  
  if (this->known_color_ != (known_color)0 || this->argb_ == 0) {
    stringstream ss;
    ss << this->known_color_;
    return ss.str();
  }
  
  return strings::format("{0:X8}", this->argb_);
}

color color::from_argb(uint32_t argb) {
  return color(argb);
}

color color::from_argb(uint8_t alpha, const color& baseColor) {
  if (alpha < 0 || alpha > 255)
    throw invalid_argument("alpha value must be between 0 and 255");
  
  return color((alpha << 24) + (baseColor.argb_ & 0x00FFFFFF));
}

color color::from_argb(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue) {
  return color(((uint32_t)alpha << 24) + ((uint32_t)red << 16) + ((uint32_t)green << 8) + blue);
}

color color::from_handle(intptr_t handle) {
  color color;
  color.handle_ = handle;
  return color;
}

color color::from_hsb(float hue, float saturation, float brightness) {
  // algorithm version (see https://www.programmingalgorithms.com/algorithm/hsv-to-rgb)
  if (saturation == 0)
    return color::from_argb(255, (uint8_t)(brightness * 255.0f), (uint8_t)(brightness * 255.0f), (uint8_t)(brightness * 255.0f));
  
  hue = hue == 360 ? 0 : hue / 60;
  
  float f = hue - (float)trunc(hue);
  float p = brightness * (1.0f - saturation);
  float q = brightness * (1.0f - (saturation * f));
  float t = brightness * (1.0f - (saturation * (1.0f - f)));
  
  switch ((int)trunc(hue)) {
    case 0: return color::from_argb(255, (uint8_t)(brightness * 255.0f), (uint8_t)(t * 255.0f), (uint8_t)(p * 255.0f));
    case 1: return color::from_argb(255, (uint8_t)(q * 255.0f), (uint8_t)(brightness * 255.0f), (uint8_t)(p * 255.0f));
    case 2: return color::from_argb(255, (uint8_t)(p * 255.0f), (uint8_t)(brightness * 255.0f), (uint8_t)(t * 255.0f));
    case 3: return color::from_argb(255, (uint8_t)(p * 255.0f), (uint8_t)(q * 255.0f), (uint8_t)(brightness * 255.0f));
    case 4: return color::from_argb(255, (uint8_t)(t * 255.0f), (uint8_t)(p * 255.0f), (uint8_t)(brightness * 255.0f));
    default: return color::from_argb(255, (uint8_t)(brightness * 255.0f), (uint8_t)(p * 255.0f), (uint8_t)(q * 255.0f));
  }
}

color color::from_name(const string& name) {
  string key = strings::replace(strings::replace(strings::to_lower(name), " ", ""), "_", "");
  static map<string, known_color> names {{"activeborder", known_color::active_border}, {"activecaption", known_color::active_caption}, {"activecaptiontext", known_color::active_caption_text}, {"appworkspace", known_color::app_workspace}, {"control", known_color::control}, {"controldark", known_color::control_dark}, {"controldarkdark", known_color::control_dark_dark}, {"controllight", known_color::control_light}, {"controllightlight", known_color::control_light_light}, {"controltext", known_color::control_text}, {"desktop", known_color::desktop}, {"graytext", known_color::gray_text}, {"highlight", known_color::highlight}, {"highlighttext", known_color::highlight_text}, {"hottrack", known_color::hot_track}, {"inactiveborder", known_color::inactive_border}, {"inactivecaption", known_color::inactive_caption}, {"inactivecaptiontext", known_color::inactive_caption_text}, {"info", known_color::info}, {"infotext", known_color::info_text}, {"menu", known_color::menu}, {"menutext", known_color::menu_text}, {"scrollbar", known_color::scroll_bar}, {"window", known_color::window}, {"windowframe", known_color::window_frame}, {"windowtext", known_color::window_text}, {"transparent", known_color::transparent}, {"aliceblue", known_color::alice_blue}, {"antiquewhite", known_color::antique_white}, {"aqua", known_color::aqua}, {"aquamarine", known_color::aquamarine}, {"azure", known_color::azure}, {"beige", known_color::beige}, {"bisque", known_color::bisque}, {"black", known_color::black}, {"blanchedalmond", known_color::blanched_almond}, {"blue", known_color::blue}, {"blueviolet", known_color::blue_violet}, {"brown", known_color::brown}, {"burlywood", known_color::burly_wood}, {"cadetblue", known_color::cadet_blue}, {"chartreuse", known_color::chartreuse}, {"chocolate", known_color::chocolate}, {"coral", known_color::coral}, {"cornflowerblue", known_color::cornflower_blue}, {"cornsilk", known_color::cornsilk}, {"crimson", known_color::crimson}, {"cyan", known_color::cyan}, {"darkblue", known_color::dark_blue}, {"darkcyan", known_color::dark_cyan}, {"darkgoldenrod", known_color::dark_goldenrod}, {"darkgray", known_color::dark_gray}, {"darkgreen", known_color::dark_green}, {"darkkhaki", known_color::dark_khaki}, {"darkmagenta", known_color::dark_magenta}, {"darkolivereen", known_color::dark_olive_green}, {"darkorange", known_color::dark_orange}, {"darkorchid", known_color::dark_orchid}, {"darkred", known_color::dark_red}, {"darksalmon", known_color::dark_salmon}, {"darkseagreen", known_color::dark_sea_green}, {"darkslateblue", known_color::dark_slate_blue}, {"darkslategray", known_color::dark_slate_gray}, {"darkturquoise", known_color::dark_turquoise}, {"darkviolet", known_color::dark_violet}, {"deeppink", known_color::deep_pink}, {"deepskyblue", known_color::deep_sky_blue}, {"dimgray", known_color::dim_gray}, {"dodgerblue", known_color::dodger_blue}, {"firebrick", known_color::firebrick}, {"floralwhite", known_color::floral_white}, {"forestgreen", known_color::forest_green}, {"fuchsia", known_color::fuchsia}, {"gainsboro", known_color::gainsboro}, {"ghostwhite", known_color::ghost_white}, {"gold", known_color::gold}, {"goldenrod", known_color::goldenrod}, {"gray", known_color::gray}, {"green", known_color::green}, {"greenyellow", known_color::green_yellow}, {"honeydew", known_color::honeydew}, {"hot_pink", known_color::hot_pink}, {"indianred", known_color::indian_red}, {"indigo", known_color::indigo}, {"ivory", known_color::ivory}, {"khaki", known_color::khaki}, {"lavender", known_color::lavender}, {"lavenderblush", known_color::lavender_blush}, {"lawngreen", known_color::lawn_green}, {"lemonchiffon", known_color::lemon_chiffon}, {"lightblue", known_color::light_blue}, {"lightcoral", known_color::light_coral}, {"lightcyan", known_color::light_cyan}, {"lightgoldenrodyellow", known_color::light_goldenrod_yellow}, {"lightgray", known_color::light_gray}, {"lightgreen", known_color::light_green}, {"lightpink", known_color::light_pink}, {"lightsalmon", known_color::light_salmon}, {"lightseagreen", known_color::light_sea_green}, {"lightskyblue", known_color::light_sky_blue}, {"lightslategray", known_color::light_slate_gray}, {"lightsteelblue", known_color::light_steel_blue}, {"lightyellow", known_color::light_yellow}, {"lime", known_color::lime}, {"limegreen", known_color::lime_green}, {"linen", known_color::linen}, {"magenta", known_color::magenta}, {"maroon", known_color::maroon}, {"mediumaquamarine", known_color::medium_aquamarine}, {"mediumblue", known_color::medium_blue}, {"mediumorchid", known_color::medium_orchid}, {"mediumpurple", known_color::medium_purple}, {"mediumseagreen", known_color::medium_sea_green}, {"mediumslateblue", known_color::medium_slate_blue}, {"mediumspringgreen", known_color::medium_spring_green}, {"mediumturquoise", known_color::medium_turquoise}, {"mediumvioletred", known_color::medium_violet_red}, {"midnightblue", known_color::midnight_blue}, {"mintcream", known_color::mint_cream}, {"mistyrose", known_color::misty_rose}, {"moccasin", known_color::moccasin}, {"navajowhite", known_color::navajo_white}, {"navy", known_color::navy}, {"oldlace", known_color::old_lace}, {"olive", known_color::olive}, {"olivedrab", known_color::olive_drab}, {"orange", known_color::orange}, {"orangered", known_color::orange_red}, {"orchid", known_color::orchid}, {"palegoldenrod", known_color::pale_goldenrod}, {"palegreen", known_color::pale_green}, {"paleturquoise", known_color::pale_turquoise}, {"palevioletred", known_color::pale_violet_red}, {"papayawhip", known_color::papaya_whip}, {"peachpuff", known_color::peach_puff}, {"peru", known_color::peru}, {"pink", known_color::pink}, {"plum", known_color::plum}, {"powderblue", known_color::powder_blue}, {"purple", known_color::purple}, {"rebecca_purple", known_color::rebecca_purple}, {"red", known_color::red}, {"rosybrown", known_color::rosy_brown}, {"royalblue", known_color::royal_blue}, {"saddlebrown", known_color::saddle_brown}, {"salmon", known_color::salmon}, {"sandybrown", known_color::sandy_brown}, {"seagreen", known_color::sea_green}, {"seashell", known_color::sea_shell}, {"sienna", known_color::sienna}, {"silver", known_color::silver}, {"skyblue", known_color::sky_blue}, {"slateblue", known_color::slate_blue}, {"slategray", known_color::slate_gray}, {"snow", known_color::snow}, {"springgreen", known_color::spring_green}, {"steelblue", known_color::steel_blue}, {"tan", known_color::tan}, {"teal", known_color::teal}, {"thistle", known_color::thistle}, {"tomato", known_color::tomato}, {"turquoise", known_color::turquoise}, {"violet", known_color::violet}, {"wheat", known_color::wheat}, {"white", known_color::white}, {"whitesmoke", known_color::white_smoke}, {"yellow", known_color::yellow}, {"yellowgreen", known_color::yellow_green}, {"buttonface", known_color::button_face}, {"buttonhighlight", known_color::button_highlight}, {"buttonshadow", known_color::button_shadow}, {"gradientactivecaption", known_color::gradient_active_caption}, {"gradientinactivecaption", known_color::gradient_inactive_caption}, {"menubar", known_color::menu_bar}, {"menuhighlight", known_color::menu_highlight}};
  if (names.find(key) == names.end())
    return color::empty;
  return color::from_known_color(names[key]);
}

color color::from_known_color(known_color color) {
  static map<known_color, drawing::color> known_colors {{known_color::active_border, color::from_handle(native::system_colors::active_border())}, {known_color::active_caption, color::from_handle(native::system_colors::active_caption())}, {known_color::active_caption_text, color::from_handle(native::system_colors::active_caption_text())}, {known_color::app_workspace, color::from_handle(native::system_colors::app_workspace())}, {known_color::control, color::from_handle(native::system_colors::control())}, {known_color::control_dark, color::from_handle(native::system_colors::control_dark())}, {known_color::control_dark_dark, color::from_handle(native::system_colors::control_dark_dark())}, {known_color::control_light, color::from_handle(native::system_colors::control_light())}, {known_color::control_light_light, color::from_handle(native::system_colors::control_light_light())}, {known_color::control_text, color::from_handle(native::system_colors::control_text())}, {known_color::desktop, color::from_handle(native::system_colors::desktop())}, {known_color::gray_text, color::from_handle(native::system_colors::gray_text())}, {known_color::highlight, color::from_handle(native::system_colors::highlight())}, {known_color::highlight_text, color::from_handle(native::system_colors::highlight_text())}, {known_color::hot_track, color::from_handle(native::system_colors::hot_track())}, {known_color::inactive_border, color::from_handle(native::system_colors::inactive_border())}, {known_color::inactive_caption, color::from_handle(native::system_colors::inactive_caption())}, {known_color::inactive_caption_text, color::from_handle(native::system_colors::inactive_caption_text())}, {known_color::info, color::from_handle(native::system_colors::info())}, {known_color::info_text, color::from_handle(native::system_colors::info_text())}, {known_color::menu, color::from_handle(native::system_colors::menu())}, {known_color::menu_text, color::from_handle(native::system_colors::menu_text())}, {known_color::scroll_bar, color::from_handle(native::system_colors::scroll_bar())}, {known_color::window, color::from_handle(native::system_colors::window())}, {known_color::window_frame, color::from_handle(native::system_colors::window_frame())}, {known_color::window_text, color::from_handle(native::system_colors::window_text())}, {known_color::transparent, color::from_argb(0x00FFFFFF)}, {known_color::alice_blue, color::from_argb(0xFFF0F8FF)}, {known_color::antique_white, color::from_argb(0xFFFAEBD7)}, {known_color::aqua, color::from_argb(0xFF00FFFF)}, {known_color::aquamarine, color::from_argb(0xFF7FFFD4)}, {known_color::azure, color::from_argb(0xFFF0FFFF)}, {known_color::beige, color::from_argb(0xFFF5F5DC)}, {known_color::bisque, color::from_argb(0xFFFFE4C4)}, {known_color::black, color::from_argb(0xFF000000)}, {known_color::blanched_almond, color::from_argb(0xFFFFEBCD)}, {known_color::blue, color::from_argb(0xFF0000FF)}, {known_color::blue_violet, color::from_argb(0xFF8A2BE2)}, {known_color::brown, color::from_argb(0xFFA52A2A)}, {known_color::burly_wood, color::from_argb(0xFFDEB887)}, {known_color::cadet_blue, color::from_argb(0xFF5F9EA0)}, {known_color::chartreuse, color::from_argb(0xFF7FFF00)}, {known_color::chocolate, color::from_argb(0xFFD2691E)}, {known_color::coral, color::from_argb(0xFFFF7F50)}, {known_color::cornflower_blue, color::from_argb(0xFF6495ED)}, {known_color::cornsilk, color::from_argb(0xFFFFF8DC)}, {known_color::crimson, color::from_argb(0xFFDC143C)}, {known_color::cyan, color::from_argb(0xFF00FFFF)}, {known_color::dark_blue, color::from_argb(0xFF00008B)}, {known_color::dark_cyan, color::from_argb(0xFF008B8B)}, {known_color::dark_goldenrod, color::from_argb(0xFFB8860B)}, {known_color::dark_gray, color::from_argb(0xFFA9A9A9)}, {known_color::dark_green, color::from_argb(0xFF006400)}, {known_color::dark_khaki, color::from_argb(0xFFBDB76B)}, {known_color::dark_magenta, color::from_argb(0xFF8B008B)}, {known_color::dark_olive_green, color::from_argb(0xFF556B2F)}, {known_color::dark_orange, color::from_argb(0xFFFF8C00)}, {known_color::dark_orchid, color::from_argb(0xFF9932CC)}, {known_color::dark_red, color::from_argb(0xFF8B0000)}, {known_color::dark_salmon, color::from_argb(0xFFE9967A)}, {known_color::dark_sea_green, color::from_argb(0xFF8FBC8B)}, {known_color::dark_slate_blue, color::from_argb(0xFF483D8B)}, {known_color::dark_slate_gray, color::from_argb(0xFF2F4F4F)}, {known_color::dark_turquoise, color::from_argb(0xFF00CED1)}, {known_color::dark_violet, color::from_argb(0xFF9400D3)}, {known_color::deep_pink, color::from_argb(0xFFFF1493)}, {known_color::deep_sky_blue, color::from_argb(0xFF00BFFF)}, {known_color::dim_gray, color::from_argb(0xFF696969)}, {known_color::dodger_blue, color::from_argb(0xFF1E90FF)}, {known_color::firebrick, color::from_argb(0xFFB22222)}, {known_color::floral_white, color::from_argb(0xFFFFFAF0)}, {known_color::forest_green, color::from_argb(0xFF228B22)}, {known_color::fuchsia, color::from_argb(0xFFFF00FF)}, {known_color::gainsboro, color::from_argb(0xFFDCDCDC)}, {known_color::ghost_white, color::from_argb(0xFFF8F8FF)}, {known_color::gold, color::from_argb(0xFFFFD700)}, {known_color::goldenrod, color::from_argb(0xFFDAA520)}, {known_color::gray, color::from_argb(0xFF808080)}, {known_color::green, color::from_argb(0xFF008000)}, {known_color::green_yellow, color::from_argb(0xFFADFF2F)}, {known_color::honeydew, color::from_argb(0xFFF0FFF0)}, {known_color::hot_pink, color::from_argb(0xFFFF69B4)}, {known_color::indian_red, color::from_argb(0xFFCD5C5C)}, {known_color::indigo, color::from_argb(0xFF4B0082)}, {known_color::ivory, color::from_argb(0xFFFFFFF0)}, {known_color::khaki, color::from_argb(0xFFF0E68C)}, {known_color::lavender, color::from_argb(0xFFE6E6FA)}, {known_color::lavender_blush, color::from_argb(0xFFFFF0F5)}, {known_color::lawn_green, color::from_argb(0xFF7CFC00)}, {known_color::lemon_chiffon, color::from_argb(0xFFFFFACD)}, {known_color::light_blue, color::from_argb(0xFFADD8E6)}, {known_color::light_coral, color::from_argb(0xFFF08080)}, {known_color::light_cyan, color::from_argb(0xFFE0FFFF)}, {known_color::light_goldenrod_yellow, color::from_argb(0xFFFAFAD2)}, {known_color::light_gray, color::from_argb(0xFFD3D3D3)}, {known_color::light_green, color::from_argb(0xFF90EE90)}, {known_color::light_pink, color::from_argb(0xFFFFB6C1)}, {known_color::light_salmon, color::from_argb(0xFFFFA07A)}, {known_color::light_sea_green, color::from_argb(0xFF20B2AA)}, {known_color::light_sky_blue, color::from_argb(0xFF87CEFA)}, {known_color::light_slate_gray, color::from_argb(0xFF778899)}, {known_color::light_steel_blue, color::from_argb(0xFFB0C4DE)}, {known_color::light_yellow, color::from_argb(0xFFFFFFE0)}, {known_color::lime, color::from_argb(0xFF00FF00)}, {known_color::lime_green, color::from_argb(0xFF32CD32)}, {known_color::linen, color::from_argb(0xFFFAF0E6)}, {known_color::magenta, color::from_argb(0xFFFF00FF)}, {known_color::maroon, color::from_argb(0xFF800000)}, {known_color::medium_aquamarine, color::from_argb(0xFF66CDAA)}, {known_color::medium_blue, color::from_argb(0xFF0000CD)}, {known_color::medium_orchid, color::from_argb(0xFFBA55D3)}, {known_color::medium_purple, color::from_argb(0xFF9370DB)}, {known_color::medium_sea_green, color::from_argb(0xFF3CB371)}, {known_color::medium_slate_blue, color::from_argb(0xFF7B68EE)}, {known_color::medium_spring_green, color::from_argb(0xFF00FA9A)}, {known_color::medium_turquoise, color::from_argb(0xFF48D1CC)}, {known_color::medium_violet_red, color::from_argb(0xFFC71585)}, {known_color::midnight_blue, color::from_argb(0xFF191970)}, {known_color::mint_cream, color::from_argb(0xFFF5FFFA)}, {known_color::misty_rose, color::from_argb(0xFFFFE4E1)}, {known_color::moccasin, color::from_argb(0xFFFFE4B5)}, {known_color::navajo_white, color::from_argb(0xFFFFDEAD)}, {known_color::navy, color::from_argb(0xFF000080)}, {known_color::old_lace, color::from_argb(0xFFFDF5E6)}, {known_color::olive, color::from_argb(0xFF808000)}, {known_color::olive_drab, color::from_argb(0xFF6B8E23)}, {known_color::orange, color::from_argb(0xFFFFA500)}, {known_color::orange_red, color::from_argb(0xFFFF4500)}, {known_color::orchid, color::from_argb(0xFFDA70D6)}, {known_color::pale_goldenrod, color::from_argb(0xFFEEE8AA)}, {known_color::pale_green, color::from_argb(0xFF98FB98)}, {known_color::pale_turquoise, color::from_argb(0xFFAFEEEE)}, {known_color::pale_violet_red, color::from_argb(0xFFDB7093)}, {known_color::papaya_whip, color::from_argb(0xFFFFEFD5)}, {known_color::peach_puff, color::from_argb(0xFFFFDAB9)}, {known_color::peru, color::from_argb(0xFFCD853F)}, {known_color::pink, color::from_argb(0xFFFFC0CB)}, {known_color::plum, color::from_argb(0xFFDDA0DD)}, {known_color::powder_blue, color::from_argb(0xFFB0E0E6)}, {known_color::purple, color::from_argb(0xFF800080)}, {known_color::rebecca_purple, color::from_argb(0xFF663399)}, {known_color::red, color::from_argb(0xFFFF0000)}, {known_color::rosy_brown, color::from_argb(0xFFBC8F8F)}, {known_color::royal_blue, color::from_argb(0xFF4169E1)}, {known_color::saddle_brown, color::from_argb(0xFF8B4513)}, {known_color::salmon, color::from_argb(0xFFFA8072)}, {known_color::sandy_brown, color::from_argb(0xFFF4A460)}, {known_color::sea_green, color::from_argb(0xFF2E8B57)}, {known_color::sea_shell, color::from_argb(0xFFFFF5EE)}, {known_color::sienna, color::from_argb(0xFFA0522D)}, {known_color::silver, color::from_argb(0xFFC0C0C0)}, {known_color::sky_blue, color::from_argb(0xFF87CEEB)}, {known_color::slate_blue, color::from_argb(0xFF6A5ACD)}, {known_color::slate_gray, color::from_argb(0xFF708090)}, {known_color::snow, color::from_argb(0xFFFFFAFA)}, {known_color::spring_green, color::from_argb(0xFF00FF7F)}, {known_color::steel_blue, color::from_argb(0xFF4682B4)}, {known_color::tan, color::from_argb(0xFFD2B48C)}, {known_color::teal, color::from_argb(0xFF008080)}, {known_color::thistle, color::from_argb(0xFFD8BFD8)}, {known_color::tomato, color::from_argb(0xFFFF6347)}, {known_color::turquoise, color::from_argb(0xFF40E0D0)}, {known_color::violet, color::from_argb(0xFFEE82EE)}, {known_color::wheat, color::from_argb(0xFFF5DEB3)}, {known_color::white, color::from_argb(0xFFFFFFFF)}, {known_color::white_smoke, color::from_argb(0xFFF5F5F5)}, {known_color::yellow, color::from_argb(0xFFFFFF00)}, {known_color::yellow_green, color::from_argb(0xFF9ACD32)}, {known_color::button_face, color::from_handle(native::system_colors::button_face())}, {known_color::button_highlight, color::from_handle(native::system_colors::button_highlight())}, {known_color::button_shadow, color::from_handle(native::system_colors::button_shadow())}, {known_color::gradient_active_caption, color::from_handle(native::system_colors::gradient_active_caption())}, {known_color::gradient_inactive_caption, color::from_handle(native::system_colors::gradient_inactive_caption())}, {known_color::menu_bar, color::from_handle(native::system_colors::menu_bar())}, {known_color::menu_highlight, color::from_handle(native::system_colors::menu_highlight())}};
  if (known_colors.find(color) == known_colors.end())
    throw std::invalid_argument("unknown know_color");
  return drawing::color(known_colors[color], color);
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
   try {
     vector<string> argb = strings::split(strings::replace(strings::replace(strings::replace(strings::replace(strings::replace(color, "color [a=", ""), " r=", ""), " g=", ""), "b=", ""), "]", ""), {','});
     return color::from_argb(strings::parse<uint8_t>(argb[0]), strings::parse<uint8_t>(argb[1]), strings::parse<uint8_t>(argb[2]), strings::parse<uint8_t>(argb[3]));
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
  if (this->known_color_ == (known_color)0 && this->argb_ == 0 && this->handle_ == 0)
    return "color [empty]";
  
  if (this->known_color_ != (known_color)0 || this->argb_ == 0)
    return strings::format("color [{0}]", name());
  
  return strings::format("color [a={}, r={}, g={}, b={}]", a(), r(), g(), b());
}

