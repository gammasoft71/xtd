#include <xtd/argument_exception.h>
#include <xtd/drawing/solid_brush.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/drawing/drawing2d/linear_gradient_brush.h>
#include <xtd/not_supported_exception.h>
#include "../../../../include/xtd/forms/style_sheets/color_data.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

const color_data color_data::empty {true};

color_data::color_data(const color& color) : colors_({color}) {
}

color_data::color_data(color_style style, const vector<color>& colors) : style_(style), colors_(colors) {
  if (colors.empty()) throw argument_exception(csf_);
  if (style != color_style::solid && colors.size() < 2U) throw argument_exception(csf_);
  if (style != color_style::solid && style != color_style::linear_gradient) throw not_supported_exception(csf_);
}

color_data::color_data(color_style style, const vector<color>& colors, int32_t angle) : style_(style), colors_(colors), angle_((angle % 360) < 0 ? 360 + (angle % 360) : (angle % 360)) {
  if (colors.empty()) throw argument_exception(csf_);
  if (style != color_style::solid && colors.size() < 2U) throw argument_exception(csf_);
  if (style != color_style::solid && style != color_style::linear_gradient) throw not_supported_exception(csf_);
}

color_style color_data::style() const noexcept {
  return style_;
}

const std::vector<xtd::drawing::color>& color_data::colors() const noexcept {
  return colors_;
}

int32_t color_data::angle() const noexcept {
  return angle_;
}

bool color_data::from_css(const xtd::ustring& css_text, color_data& result) {
  return try_parse(css_text, result);
}

std::unique_ptr<xtd::drawing::brush> color_data::make_brush(const xtd::forms::style_sheets::color_data& color, const xtd::drawing::rectangle& rect) {
  if (color.style() == color_style::linear_gradient) {
    auto angle = color.angle() % 360;
    if (angle < 0) angle = 360 + angle;
    if (color.angle() <= 45) return make_unique<linear_gradient_brush>(rect, color.colors()[1], color.colors()[0], linear_gradient_mode::vertical);
    if (color.angle() <= 135) return make_unique<linear_gradient_brush>(rect, color.colors()[0], color.colors()[1], linear_gradient_mode::horizontal);
    if (color.angle() <= 225) return make_unique<linear_gradient_brush>(rect, color.colors()[0], color.colors()[1], linear_gradient_mode::vertical);
    if (color.angle() <= 315) return make_unique<linear_gradient_brush>(rect, color.colors()[1], color.colors()[0], linear_gradient_mode::horizontal);
    return make_unique<linear_gradient_brush>(rect, color.colors()[1], color.colors()[0], linear_gradient_mode::vertical);
  }
  return make_unique<solid_brush>(color.colors()[0]);
}

color_data color_data::parse(const xtd::ustring& text) {
  color_data result;
  if (!try_parse(text, result))
    throw argument_exception(csf_);
  return result;
}

xtd::ustring color_data::to_string() const noexcept {
  return ustring::format("[style={}, colors=[{}], width={}, angle={}]", style(), colors(), angle());
}

xtd::ustring color_data::to_css() const noexcept {
  if (style() == color_style::solid) return ustring::format("{}", color_to_string(colors()[0]));
  if (style() == color_style::linear_gradient) {
    ustring result = "linear-gradient(";
    if (angle() != 180) result += angle_to_string(angle());
    for (auto i = 0U; i < colors().size(); ++i)
      result += ustring::format("{}{}", i != 0 || angle() != 180 ? ", " : "", color_to_string(colors()[i]));
    return result + ")";
  }
  return "transparent";
}

bool color_data::try_parse(const xtd::ustring& text, color_data& result) {
  auto value = remove_key(text);
  if (text.starts_with("#")) return try_parse_hash_color(value, result);
  if (text.starts_with("rgb(") && text.ends_with(")")) return try_parse_rgb_color(value, result);
  if (text.starts_with("rgba(") && text.ends_with(")")) return try_parse_rgba_color(value, result);
  if (text.starts_with("argb(") && text.ends_with(")")) return try_parse_argb_color(value, result);
  if (text.starts_with("hsv(") && text.ends_with(")")) return try_parse_hsv_color(value, result);
  if (text.starts_with("hsva(") && text.ends_with(")")) return try_parse_hsva_color(value, result);
  if (text.starts_with("ahsv(") && text.ends_with(")")) return try_parse_ahsv_color(value, result);
  if (text.starts_with("hsl(") && text.ends_with(")")) return try_parse_hsl_color(value, result);
  if (text.starts_with("hsla(") && text.ends_with(")")) return try_parse_hsla_color(value, result);
  if (text.starts_with("ahsl(") && text.ends_with(")")) return try_parse_ahsl_color(value, result);
  if (text.starts_with("system-color(") && text.ends_with(")")) return try_parse_system_color(value, result);
  if (text.starts_with("linear-gradient(") && text.ends_with(")")) return try_parse_linear_gradient_color(value, result);
  return try_parse_named_color(value, result);
}

xtd::ustring color_data::angle_to_string(int32_t angle) {
  if (angle == 0) return "to top";
  if (angle == 45) return "to top right";
  if (angle == 90) return "to right";
  if (angle == 135) return "to bottom right";
  if (angle == 180) return "to botom";
  if (angle == 225) return "to bottom left";
  if (angle == 270) return "to left";
  if (angle == 315) return "to top left";
  return ustring::format("{}deg", angle);
}
xtd::ustring color_data::color_to_string(const drawing::color& color) {
  static map<ustring, drawing::color> colors {{"accent", system_colors::accent()}, {"accent_text", system_colors::accent_text()}, {"active_border", system_colors::active_border()}, {"active_caption", system_colors::active_caption()}, {"active_caption_text", system_colors::active_caption_text()}, {"app_workspace", system_colors::app_workspace()}, {"button_face", system_colors::button_face()}, {"button_highlight", system_colors::button_highlight()}, {"button_shadow", system_colors::button_shadow()}, {"control", system_colors::control()}, {"control_dark", system_colors::control_dark()}, {"control_dark_dark", system_colors::control_dark_dark()}, {"control_light", system_colors::control_light()}, {"control_light_light", system_colors::control_light_light()}, {"control_text", system_colors::control_text()}, {"desktop", system_colors::desktop()}, {"gradient_active_caption", system_colors::gradient_active_caption()}, {"gradient_inactive_caption", system_colors::gradient_inactive_caption()}, {"gray_text", system_colors::gray_text()}, {"highlight", system_colors::highlight()}, {"highlight_text", system_colors::highlight_text()}, {"hot_track", system_colors::hot_track()}, {"inactive_border", system_colors::inactive_border()}, {"inactive_caption", system_colors::inactive_caption()}, {"inactive_caption_text", system_colors::inactive_caption_text()}, {"info", system_colors::info()}, {"info_text", system_colors::info_text()}, {"menu", system_colors::menu()}, {"menu_bar", system_colors::menu_bar()}, {"menu_highlight", system_colors::menu_highlight()}, {"menu_text", system_colors::menu_text()}, {"scroll_bar", system_colors::scroll_bar()}, {"text_box", system_colors::text_box()}, {"text_box_text", system_colors::text_box_text()}, {"window", system_colors::window()}, {"window_frame", system_colors::window_frame()}, {"window_text", system_colors::window_text()}};
  auto it = colors.find(color.name());
  if (it != colors.end()) return ustring::format("system-color({})", color.name().replace("_", "-"));
  if (color.name() != ustring::format("{:X8}", color.to_argb())) return color.name().replace("_", "");
  if (color.a() == 255) return ustring::format("#{:X2}{:X2}{:X2}", color.r(), color.g(), color.b());
  return ustring::format("rgba({}, {}, {}, {})", color.r(), color.g(), color.b(), color.a());
}

ustring color_data::remove_key(const xtd::ustring& text) {
  auto result = text.trim();
  if (result.starts_with("color:")) result = result.replace("color:", "");
  if (result.starts_with("border-color:")) result = result.replace("border-color:", "");
  if (result.starts_with("background-color:")) result = result.replace("background-color:", "");
  result = result.trim_end(';');
  return result.trim();
}

bool color_data::try_parse_hash_color(const xtd::ustring& text, color_data& result) {
  if (text.starts_with("#") && text.size() == 4U) {
    byte_t r = 0;
    if (xtd::try_parse<byte_t>(text.substring(1, 1), r, number_styles::hex_number) == false) return false;
    r += r * 16;
    byte_t g = 0;
    if (xtd::try_parse<byte_t>(text.substring(2, 1), g, number_styles::hex_number) == false) return false;
    g += g * 16;
    byte_t b = 0;
    if (xtd::try_parse<byte_t>(text.substring(3, 1), b, number_styles::hex_number) == false) return false;
    b += b * 16;
    result = color_data(color::from_argb(r, g, b));
    return true;
  }
  if (text.starts_with("#") && text.size() == 5U) {
    byte_t a = 0;
    if (xtd::try_parse<byte_t>(text.substring(1, 1), a, number_styles::hex_number) == false) return false;
    a += a * 16;
    byte_t r = 0;
    if (xtd::try_parse<byte_t>(text.substring(2, 1), r, number_styles::hex_number) == false) return false;
    r += r * 16;
    byte_t g = 0;
    if (xtd::try_parse<byte_t>(text.substring(3, 1), g, number_styles::hex_number) == false) return false;
    g += g * 16;
    byte_t b = 0;
    if (xtd::try_parse<byte_t>(text.substring(4, 1), b, number_styles::hex_number) == false) return false;
    b += b * 16;
    result = color_data(color::from_argb(a, r, g, b));
    return true;
  }
  if (text.starts_with("#") &&text.size() == 7U) {
    int32_t rgb;
    if (xtd::try_parse<int>(text.substring(1), rgb, number_styles::hex_number) == false) return false;
    result = color_data(color::from_argb(rgb + 0xFF000000));
    return true;
  }
  if (text.starts_with("#") &&text.size() == 9U) {
    int32_t argb;
    if (xtd::try_parse<int>(text.substring(1), argb, number_styles::hex_number) == false) return false;
    result = color_data(color::from_argb(argb));
    return true;
  }
  return false;
}

bool color_data::try_parse_rgb_color(const xtd::ustring& text, color_data& result) {
  auto value = text.remove(text.size()-1).replace("rgb(", "");
  auto color_parts = value.split({','});
  if (color_parts.size() != 3) return false;
  byte_t r = 0;
  if (xtd::try_parse<byte_t>(color_parts[0], r) == false) return false;
  byte_t g = 0;
  if (xtd::try_parse<byte_t>(color_parts[1], g) == false) return false;
  byte_t b = 0;
  if (xtd::try_parse<byte_t>(color_parts[2], b) == false) return false;
  result = color_data(color::from_argb(r, g, b));
  return true;
}

bool color_data::try_parse_rgba_color(const xtd::ustring& text, color_data& result) {
  auto value = text.remove(text.size()-1).replace("rgba(", "");
  auto color_parts = value.split({','});
  if (color_parts.size() != 4) return false;
  byte_t r = 0;
  if (xtd::try_parse<byte_t>(color_parts[0], r) == false) return false;
  byte_t g = 0;
  if (xtd::try_parse<byte_t>(color_parts[1], g) == false) return false;
  byte_t b = 0;
  if (xtd::try_parse<byte_t>(color_parts[2], b) == false) return false;
  byte_t a = 0;
  if (xtd::try_parse<byte_t>(color_parts[3], a) == false) return false;
  result = color_data(color::from_argb(a, r, g, b));
  return true;
}

bool color_data::try_parse_argb_color(const xtd::ustring& text, color_data& result) {
  auto value = text.remove(text.size()-1).replace("argb(", "");
  auto color_parts = value.split({','});
  if (color_parts.size() != 4) return false;
  byte_t a = 0;
  if (xtd::try_parse<byte_t>(color_parts[0], a) == false) return false;
  byte_t r = 0;
  if (xtd::try_parse<byte_t>(color_parts[1], r) == false) return false;
  byte_t g = 0;
  if (xtd::try_parse<byte_t>(color_parts[2], g) == false) return false;
  byte_t b = 0;
  if (xtd::try_parse<byte_t>(color_parts[3], b) == false) return false;
  result = color_data(color::from_argb(a, r, g, b));
  return true;
}

bool color_data::try_parse_hsv_color(const xtd::ustring& text, color_data& result) {
  auto value = text.remove(text.size()-1).replace("hsv(", "");
  auto color_parts = value.split({','});
  if (color_parts.size() != 3) return false;
  float h = 0;
  if (xtd::try_parse<float>(color_parts[0], h) == false) return false;
  float s = 0;
  if (xtd::try_parse<float>(color_parts[1], s) == false) return false;
  float v = 0;
  if (xtd::try_parse<float>(color_parts[2], v) == false) return false;
  result = color_data(color::from_hsb(h, s, v));
  return true;
}

bool color_data::try_parse_hsva_color(const xtd::ustring& text, color_data& result) {
  auto value = text.remove(text.size()-1).replace("hsva(", "");
  auto color_parts = value.split({','});
  if (color_parts.size() != 4) return false;
  float h = 0;
  if (xtd::try_parse<float>(color_parts[0], h) == false) return false;
  float s = 0;
  if (xtd::try_parse<float>(color_parts[1], s) == false) return false;
  float v = 0;
  if (xtd::try_parse<float>(color_parts[2], v) == false) return false;
  byte_t a = 0;
  if (xtd::try_parse<byte_t>(color_parts[3], a) == false) return false;
  result = color_data(color::from_argb(a, color::from_hsb(h, s, v)));
  return true;
}

bool color_data::try_parse_ahsv_color(const xtd::ustring& text, color_data& result) {
  auto value = text.remove(text.size()-1).replace("ahsv(", "");
  auto color_parts = value.split({','});
  if (color_parts.size() != 4) return false;
  byte_t a = 0;
  if (xtd::try_parse<byte_t>(color_parts[0], a) == false) return false;
  float h = 0;
  if (xtd::try_parse<float>(color_parts[1], h) == false) return false;
  float s = 0;
  if (xtd::try_parse<float>(color_parts[2], s) == false) return false;
  float v = 0;
  if (xtd::try_parse<float>(color_parts[3], v) == false) return false;
  result = color_data(color::from_argb(a, color::from_hsb(h, s, v)));
  return true;
}

bool color_data::try_parse_hsl_color(const xtd::ustring& text, color_data& result) {
  auto value = text.remove(text.size()-1).replace("hsl(", "");
  auto color_parts = value.split({','});
  if (color_parts.size() != 3) return false;
  float h = 0;
  if (xtd::try_parse<float>(color_parts[0], h) == false) return false;
  float s = 0;
  if (xtd::try_parse<float>(color_parts[1], s) == false) return false;
  float l = 0;
  if (xtd::try_parse<float>(color_parts[2], l) == false) return false;
  result = color_data(color::from_hsl(h, s, l));
  return true;
}

bool color_data::try_parse_hsla_color(const xtd::ustring& text, color_data& result) {
  auto value = text.remove(text.size()-1).replace("hsla(", "");
  auto color_parts = value.split({','});
  if (color_parts.size() != 4) return false;
  float h = 0;
  if (xtd::try_parse<float>(color_parts[0], h) == false) return false;
  float s = 0;
  if (xtd::try_parse<float>(color_parts[1], s) == false) return false;
  float l = 0;
  if (xtd::try_parse<float>(color_parts[2], l) == false) return false;
  byte_t a = 0;
  if (xtd::try_parse<byte_t>(color_parts[3], a) == false) return false;
  result = color_data(color::from_argb(a, color::from_hsl(h, s, l)));
  return true;
}

bool color_data::try_parse_ahsl_color(const xtd::ustring& text, color_data& result) {
  auto value = text.remove(text.size()-1).replace("ahsl(", "");
  auto color_parts = value.split({','});
  if (color_parts.size() != 4) return false;
  byte_t a = 0;
  if (xtd::try_parse<byte_t>(color_parts[0], a) == false) return false;
  float h = 0;
  if (xtd::try_parse<float>(color_parts[1], h) == false) return false;
  float s = 0;
  if (xtd::try_parse<float>(color_parts[2], s) == false) return false;
  float l = 0;
  if (xtd::try_parse<float>(color_parts[3], l) == false) return false;
  result = color_data(color::from_argb(a, color::from_hsl(h, s, l)));
  return true;
}

bool color_data::try_parse_named_color(const xtd::ustring& text, color_data& result) {
  result = color_data(color::from_name(text));
  return result.colors()[0].is_known_color();
}

bool color_data::try_parse_system_color(const xtd::ustring& text, color_data& result) {
  auto value = text.remove(text.size()-1).replace("system-color(", "");
  /// @todo Replace drawing::system_colors by theme::system_colors
  static map<ustring, color> colors {{"accent", system_colors::accent()}, {"accent-text", system_colors::accent_text()}, {"active-border", system_colors::active_border()}, {"active-caption", system_colors::active_caption()}, {"active-caption-text", system_colors::active_caption_text()}, {"app-workspace", system_colors::app_workspace()}, {"button-face", system_colors::button_face()}, {"button-highlight", system_colors::button_highlight()}, {"button-shadow", system_colors::button_shadow()}, {"control", system_colors::control()}, {"control-dark", system_colors::control_dark()}, {"control-dark-dark", system_colors::control_dark_dark()}, {"control-light", system_colors::control_light()}, {"control-light-light", system_colors::control_light_light()}, {"control-text", system_colors::control_text()}, {"desktop", system_colors::desktop()}, {"gradient-active-caption", system_colors::gradient_active_caption()}, {"gradient-inactive-caption", system_colors::gradient_inactive_caption()}, {"gray-text", system_colors::gray_text()}, {"highlight", system_colors::highlight()}, {"highlight-text", system_colors::highlight_text()}, {"hot-track", system_colors::hot_track()}, {"inactive-border", system_colors::inactive_border()}, {"inactive-caption", system_colors::inactive_caption()}, {"inactive-caption-text", system_colors::inactive_caption_text()}, {"info", system_colors::info()}, {"info-text", system_colors::info_text()}, {"menu", system_colors::menu()}, {"menu-bar", system_colors::menu_bar()}, {"menu-highlight", system_colors::menu_highlight()}, {"menu-text", system_colors::menu_text()}, {"scroll-bar", system_colors::scroll_bar()}, {"text-box", system_colors::text_box()}, {"text-box-text", system_colors::text_box_text()}, {"window", system_colors::window()}, {"window-frame", system_colors::window_frame()}, {"window-text", system_colors::window_text()}};
  auto it = colors.find(value);
  if (it == colors.end()) return false;
  result = color_data(it->second);
  return true;
}

bool color_data::try_parse_linear_gradient_color(const xtd::ustring& text, color_data& result) {
  auto value = text.remove(text.size()-1).replace("linear-gradient(", "");
  vector<color> colors;
  int32_t angle = -1;
  while (!value.empty()) {
    value = value.trim();
    color_data color;
    if (value.starts_with("rgb(") && value.find_first_of(")") != value.npos) {
      auto sub_value = value.find_first_of(",", value.find_first_of(")")) != value.npos ? value.substring(0, value.find_first_of(",", value.find_first_of(")"))) : value;
      if (try_parse_rgb_color(sub_value, color) == false) return false;
      value = value.remove(0, value.find_first_of(")"));
      colors.push_back(color.colors()[0]);
    } else if (value.starts_with("rgba(")) {
      auto sub_value = value.find_first_of(",", value.find_first_of(")")) != value.npos ? value.substring(0, value.find_first_of(",", value.find_first_of(")"))) : value;
      if (try_parse_rgba_color(sub_value, color) == false) return false;
      value = value.remove(0, value.find_first_of(")"));
      colors.push_back(color.colors()[0]);
    } else if (value.starts_with("argb(")) {
      auto sub_value = value.find_first_of(",", value.find_first_of(")")) != value.npos ? value.substring(0, value.find_first_of(",", value.find_first_of(")"))) : value;
      if (try_parse_argb_color(sub_value, color) == false) return false;
      value = value.remove(0, value.find_first_of(")"));
      colors.push_back(color.colors()[0]);
    } else if (value.starts_with("hsv(")) {
      auto sub_value = value.find_first_of(",", value.find_first_of(")")) != value.npos ? value.substring(0, value.find_first_of(",", value.find_first_of(")"))) : value;
      if (try_parse_hsv_color(sub_value, color) == false) return false;
      value = value.remove(0, value.find_first_of(")"));
      colors.push_back(color.colors()[0]);
    } else if (value.starts_with("hsva(")) {
      auto sub_value = value.find_first_of(",", value.find_first_of(")")) != value.npos ? value.substring(0, value.find_first_of(",", value.find_first_of(")"))) : value;
      if (try_parse_hsva_color(sub_value, color) == false) return false;
      value = value.remove(0, value.find_first_of(")"));
      colors.push_back(color.colors()[0]);
    } else if (value.starts_with("ahsv(")) {
      auto sub_value = value.find_first_of(",", value.find_first_of(")")) != value.npos ? value.substring(0, value.find_first_of(",", value.find_first_of(")"))) : value;
      if (try_parse_ahsv_color(sub_value, color) == false) return false;
      value = value.remove(0, value.find(")"));
      colors.push_back(color.colors()[0]);
    } else if (value.starts_with("hsl(")) {
      auto sub_value = value.find_first_of(",", value.find_first_of(")")) != value.npos ? value.substring(0, value.find_first_of(",", value.find_first_of(")"))) : value;
      if (try_parse_hsl_color(sub_value, color) == false) return false;
      value = value.remove(0, value.find_first_of(")"));
      colors.push_back(color.colors()[0]);
    } else if (value.starts_with("hsla(")) {
      auto sub_value = value.find_first_of(",", value.find_first_of(")")) != value.npos ? value.substring(0, value.find_first_of(",", value.find_first_of(")"))) : value;
      if (try_parse_hsla_color(sub_value, color) == false) return false;
      value = value.remove(0, value.find_first_of(")"));
      colors.push_back(color.colors()[0]);
    } else if (value.starts_with("ahsl(")) {
      auto sub_value = value.find_first_of(",", value.find_first_of(")")) != value.npos ? value.substring(0, value.find_first_of(",", value.find_first_of(")"))) : value;
      if (try_parse_ahsl_color(sub_value, color) == false) return false;
      value = value.remove(0, value.find_first_of(")"));
      colors.push_back(color.colors()[0]);
    } else if (value.starts_with("system-color(")) {
      auto sub_value = value.find_first_of(",", value.find_first_of(")")) != value.npos ? value.substring(0, value.find_first_of(",", value.find_first_of(")"))) : value;
      if (try_parse_system_color(sub_value, color) == false) return false;
      value = value.remove(0, value.find_first_of(")"));
      colors.push_back(color.colors()[0]);
    } else {
      auto sub_value = value.find(",") != value.npos ? value.substring(0, value.find(",")) : value;
      value = value.find(",") != value.npos ? value.remove(0, value.find(",") + 1) : "";
      sub_value.trim();
      if (sub_value.starts_with("#") && try_parse_hash_color(sub_value, color))
        colors.push_back(color.colors()[0]);
      else if (sub_value == "to top") {
        if (angle != -1) return false;
        angle = 0;
      } else if (sub_value == "to top right") {
        if (angle != -1) return false;
        angle = 45;
      } else if (sub_value == "to right") {
        if (angle != -1) return false;
        angle = 90;
      } else if (sub_value == "to bottom right") {
        if (angle != -1) return false;
        angle = 135;
      } else if (sub_value == "to bottom") {
        if (angle != -1) return false;
        angle = 180;
      } else if (sub_value == "to bottom left") {
        if (angle != -1) return false;
        angle = 225;
      } else if (sub_value == "to left") {
        if (angle != -1) return false;
        angle = 270;
      } else if (sub_value == "to top left") {
        if (angle != -1) return false;
        angle = 315;
      } else if (sub_value.ends_with("deg")) {
        sub_value = sub_value.replace("deg", "");
        if (angle != -1 || xtd::try_parse<int32_t>(sub_value, angle) == false) return false;
      } else if (try_parse_named_color(sub_value, color))
        colors.push_back(color.colors()[0]);
    }
  }
  if (colors.size() < 2) return false;
  result = color_data(color_style::linear_gradient, colors, angle == -1? 180 : angle);
  return true;
}
