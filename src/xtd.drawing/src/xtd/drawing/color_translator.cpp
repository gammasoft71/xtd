#include "../../../include/xtd/drawing/color_translator.hpp"
#include <xtd/as>
#include <xtd/format_exception>
#include <map>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::helpers;

color color_translator::from_hex(const string& text) {
  auto result = color::empty;
  if (string::is_empty(text)) return result;
  if (try_parse_hex_color(text, result) == false) throw_helper::throws(exception_case::format);
  return result;
}

color color_translator::from_hsl(const string& text) {
  auto result = color::empty;
  if (string::is_empty(text)) return result;
  if (try_parse_hsl_color(text, result) == false) throw_helper::throws(exception_case::format);
  return result;
}

color color_translator::from_hsla(const string& text) {
  auto result = color::empty;
  if (string::is_empty(text)) return result;
  if (try_parse_hsla_color(text, result) == false) throw_helper::throws(exception_case::format);
  return result;
}

color color_translator::from_hsv(const string& text) {
  auto result = color::empty;
  if (string::is_empty(text)) return result;
  if (try_parse_hsv_color(text, result) == false) throw_helper::throws(exception_case::format);
  return result;
}

color color_translator::from_hsva(const string& text) {
  auto result = color::empty;
  if (string::is_empty(text)) return result;
  if (try_parse_hsva_color(text, result) == false) throw_helper::throws(exception_case::format);
  return result;
}

color color_translator::from_html(const string& text) {
  auto result = color::empty;
  if (string::is_empty(text)) return result;
  if (try_parse_html_color(text, result) == false) throw_helper::throws(exception_case::format);
  return result;
}

color color_translator::from_rgb(const string& text) {
  auto result = color::empty;
  if (string::is_empty(text)) return result;
  if (try_parse_rgb_color(text, result) == false) throw_helper::throws(exception_case::format);
  return result;
}

color color_translator::from_rgba(const string& text) {
  auto result = color::empty;
  if (string::is_empty(text)) return result;
  if (try_parse_rgba_color(text, result) == false) throw_helper::throws(exception_case::format);
  return result;
}

color color_translator::from_win32(int32 value) {
  return color::from_argb(as<byte>((value >> win32_red_shift) & 0xFF), as<byte>((value >> win32_green_shift) & 0xFF), as<byte>((value >> win32_blue_shift) & 0xFF));
}

string color_translator::to_hex(const color& value) noexcept {
  return to_hex(value, false);
}

string color_translator::to_hex(const color& value, bool auto_alpha) noexcept {
  if (auto_alpha && value.a() < 255) return string::format("#{:x2}{:x2}{:x2}{:x2}", value.r(), value.g(), value.b(), value.a());
  return string::format("#{:x2}{:x2}{:x2}", value.r(), value.g(), value.b());
}

string color_translator::to_hsl(const color& value) noexcept {
  return to_hsl(value, false);
}

string color_translator::to_hsl(const color& value, bool auto_hsla) noexcept {
  if (auto_hsla && value.a() < 255) return to_hsla(value);
  return string::format("hsl({}, {}%, {}%)", as<int32>(value.get_hue()), as<int32>(value.get_saturation() * 100), as<int32>(value.get_lightness() * 100));
}

string color_translator::to_hsla(const color& value) noexcept {
  return string::format("hsla({}, {}%, {}%, {:G3})", as<int32>(value.get_hue()), as<int32>(value.get_saturation() * 100), as<int32>(value.get_lightness() * 100), value.a() / 255.0);
}

string color_translator::to_hsv(const color& value) noexcept {
  return to_hsv(value, false);
}

string color_translator::to_hsv(const color& value, bool auto_hsva) noexcept {
  if (auto_hsva && value.a() < 255) return to_hsva(value);
  return string::format("hsv({}, {}%, {}%)", as<int32>(value.get_hue()), as<int32>(value.get_saturation() * 100), as<int32>(value.get_brightness() * 100));
}

string color_translator::to_hsva(const color& value) noexcept {
  return string::format("hsva({}, {}%, {}%, {:G3})", as<int32>(value.get_hue()), as<int32>(value.get_saturation() * 100), as<int32>(value.get_brightness() * 100), value.a() / 255.0);
}

string color_translator::to_html(const color& value) noexcept {
  return value.is_named_color() ? from_name(value) : (value.a() != 255 ? to_rgba(value) : to_hex(value));
}

string color_translator::to_rgb(const color& value) noexcept {
  return to_rgb(value, false);
}

string color_translator::to_rgb(const color& value, bool auto_rgba) noexcept {
  if (auto_rgba && value.a() < 255) return to_rgba(value);
  return string::format("rgb({}, {}, {})", value.r(), value.g(), value.b());
}

string color_translator::to_rgba(const color& value) noexcept {
  return string::format("rgba({}, {}, {}, {:G3})", value.r(), value.g(), value.b(), value.a() / 255.0);
}

int32 color_translator::to_win32(const xtd::drawing::color& value) noexcept {
  return (as<int32>(value.r()) << win32_red_shift) + (as<int32>(value.g()) << win32_green_shift) + (as<int32>(value.b()) << win32_blue_shift);
}

string color_translator::from_name(const color& value) {
  return value.name().replace("_", " ").to_title_case().replace(" ", string::empty_string);
}

bool color_translator::try_parse_hex_color(const string& text, color& result) noexcept {
  if (text.starts_with("#") && text.size() == 4_z) {
    auto r = xtd::byte {};
    if (xtd::try_parse<xtd::byte>(text.substring(1, 1).chars(), r, number_styles::hex_number) == false) return false;
    r += r * 16;
    auto g = xtd::byte {};
    if (xtd::try_parse<xtd::byte>(text.substring(2, 1).chars(), g, number_styles::hex_number) == false) return false;
    g += g * 16;
    auto b = xtd::byte {};
    if (xtd::try_parse<xtd::byte>(text.substring(3, 1).chars(), b, number_styles::hex_number) == false) return false;
    b += b * 16;
    result = color::from_argb(r, g, b);
    return true;
  }
  if (text.starts_with("#") && text.size() == 5_z) {
    auto a = xtd::byte {};
    if (xtd::try_parse<xtd::byte>(text.substring(1, 1).chars(), a, number_styles::hex_number) == false) return false;
    a += a * 16;
    auto r = xtd::byte {};
    if (xtd::try_parse<xtd::byte>(text.substring(2, 1).chars(), r, number_styles::hex_number) == false) return false;
    r += r * 16;
    auto g = xtd::byte {};
    if (xtd::try_parse<xtd::byte>(text.substring(3, 1).chars(), g, number_styles::hex_number) == false) return false;
    g += g * 16;
    auto b = xtd::byte {};
    if (xtd::try_parse<xtd::byte>(text.substring(4, 1).chars(), b, number_styles::hex_number) == false) return false;
    b += b * 16;
    result = color::from_argb(a, r, g, b);
    return true;
  }
  if (text.starts_with("#") && text.size() == 7_z) {
    auto rgb = 0u;
    if (xtd::try_parse<uint32>(text.substring(1).chars(), rgb, number_styles::hex_number) == false) return false;
    result = color::from_argb(0xFF000000u + rgb);
    return true;
  }
  if (text.starts_with("#") && text.size() == 9_z) {
    auto rgba = 0u;
    if (xtd::try_parse<uint32>(text.substring(1).chars(), rgba, number_styles::hex_number) == false) return false;
    result = color::from_argb(((rgba & 0xFFFFFF00u) >> 8) + ((rgba & 0x000000FFu) << 24));
    return true;
  }
  return false;
}

bool color_translator::try_parse_hsl_color(const string& text, color& result) noexcept {
  auto value = text.remove(text.size() - 1).replace("hsl(", string::empty_string);
  auto color_parts = value.split(',');
  if (color_parts.size() != 3) return false;
  if (!color_parts[1].ends_with("%")) return false;
  if (!color_parts[2].ends_with("%")) return false;
  color_parts[1] = color_parts[1].remove(color_parts[1].size() - 1);
  color_parts[2] = color_parts[2].remove(color_parts[2].size() - 1);
  auto h = .0f;
  if (string::try_parse<float>(color_parts[0], h) == false) return false;
  auto s = .0f;
  if (string::try_parse<float>(color_parts[1], s) == false) return false;
  auto l = .0f;
  if (string::try_parse<float>(color_parts[2], l) == false) return false;
  result = color::from_hsl(h, s / 100.0f, l / 100.0f);
  return true;
}

bool color_translator::try_parse_hsla_color(const string& text, color& result) noexcept {
  auto value = text.remove(text.size() - 1).replace("hsla(", string::empty_string);
  auto color_parts = value.split(',');
  if (color_parts.size() != 4) return false;
  if (!color_parts[1].ends_with("%")) return false;
  if (!color_parts[2].ends_with("%")) return false;
  color_parts[1] = color_parts[1].remove(color_parts[1].size() - 1);
  color_parts[2] = color_parts[2].remove(color_parts[2].size() - 1);
  auto h = .0f;
  if (string::try_parse<float>(color_parts[0], h) == false) return false;
  auto s = .0f;
  if (string::try_parse<float>(color_parts[1], s) == false) return false;
  auto l = .0f;
  if (string::try_parse<float>(color_parts[2], l) == false) return false;
  auto a = .0f;
  if (string::try_parse<float>(color_parts[3], a) == false) return false;
  result = color::from_argb(as<xtd::byte>(as<int32>(a * 255) % 256), color::from_hsl(h, s / 100.0f, l / 100.0f));
  return true;
}

bool color_translator::try_parse_hsv_color(const string& text, color& result) noexcept {
  auto value = text.remove(text.size() - 1).replace("hsv(", string::empty_string);
  auto color_parts = value.split(',');
  if (color_parts.size() != 3) return false;
  if (!color_parts[1].ends_with("%")) return false;
  if (!color_parts[2].ends_with("%")) return false;
  color_parts[1] = color_parts[1].remove(color_parts[1].size() - 1);
  color_parts[2] = color_parts[2].remove(color_parts[2].size() - 1);
  auto h = .0f;
  if (string::try_parse<float>(color_parts[0], h) == false) return false;
  auto s = .0f;
  if (string::try_parse<float>(color_parts[1], s) == false) return false;
  auto v = .0f;
  if (string::try_parse<float>(color_parts[2], v) == false) return false;
  result = color::from_hsb(h, s / 100.0f, v / 100.0f);
  return true;
}

bool color_translator::try_parse_hsva_color(const string& text, color& result) noexcept {
  auto value = text.remove(text.size() - 1).replace("hsva(", string::empty_string);
  auto color_parts = value.split(',');
  if (color_parts.size() != 4) return false;
  if (!color_parts[1].ends_with("%")) return false;
  if (!color_parts[2].ends_with("%")) return false;
  color_parts[1] = color_parts[1].remove(color_parts[1].size() - 1);
  color_parts[2] = color_parts[2].remove(color_parts[2].size() - 1);
  auto h = .0f;
  if (string::try_parse<float>(color_parts[0], h) == false) return false;
  auto s = .0f;
  if (string::try_parse<float>(color_parts[1], s) == false) return false;
  auto v = .0f;
  if (string::try_parse<float>(color_parts[2], v) == false) return false;
  auto a = .0f;
  if (string::try_parse<float>(color_parts[3], a) == false) return false;
  result = color::from_argb(as<xtd::byte>(as<int32>(a * 255) % 256), color::from_hsb(h, s / 100.0f, v / 100.0f));
  return true;
}

bool color_translator::try_parse_html_color(const string& text, color& result) noexcept {
  if (text.starts_with("#") && try_parse_hex_color(text, result)) return true;
  if (text.starts_with("rgb(") && text.ends_with(")") && try_parse_rgb_color(text, result)) return true;
  if (text.starts_with("rgba(") && text.ends_with(")") && try_parse_rgba_color(text, result)) return true;
  if (text.starts_with("hsv(") && text.ends_with(")") && try_parse_hsv_color(text, result)) return true;
  if (text.starts_with("hsva(") && text.ends_with(")") && try_parse_hsva_color(text, result)) return true;
  if (text.starts_with("hsl(") && text.ends_with(")") && try_parse_hsl_color(text, result)) return true;
  if (text.starts_with("hsla(") && text.ends_with(")") && try_parse_hsla_color(text, result)) return true;
  //if (text.starts_with("system-color(") && text.ends_with(")") && try_parse_system_color(text, result)) return true;
  if (try_parse_named_color(text, result)) return true;
  return false;
}

bool color_translator::try_parse_named_color(const string& text, color& result) noexcept {
  if (text.trim().find(' ') != string::npos) return false;
  auto named_color = color::from_name(text);
  if (!named_color.is_known_color()) return false;
  result = named_color;
  return true;
}

bool color_translator::try_parse_rgb_color(const string& text, color& result) noexcept {
  auto value = text.remove(text.size() - 1).replace("rgb(", string::empty_string);
  auto color_parts = value.split(',');
  if (color_parts.size() != 3) return false;
  auto r = xtd::byte {};
  if (string::try_parse<xtd::byte>(color_parts[0], r) == false) return false;
  auto g = xtd::byte {};
  if (string::try_parse<xtd::byte>(color_parts[1], g) == false) return false;
  auto b = xtd::byte {};
  if (string::try_parse<xtd::byte>(color_parts[2], b) == false) return false;
  result = color::from_argb(r, g, b);
  return true;
}

bool color_translator::try_parse_rgba_color(const string& text, color& result) noexcept {
  auto value = text.remove(text.size() - 1).replace("rgba(", string::empty_string);
  auto color_parts = value.split(',');
  if (color_parts.size() != 4) return false;
  auto r = xtd::byte {};
  if (string::try_parse<xtd::byte>(color_parts[0], r) == false) return false;
  auto g = xtd::byte {};
  if (string::try_parse<xtd::byte>(color_parts[1], g) == false) return false;
  auto b = xtd::byte {};
  if (string::try_parse<xtd::byte>(color_parts[2], b) == false) return false;
  auto a = .0f;
  if (string::try_parse<float>(color_parts[3], a) == false) return false;
  result = color::from_argb(as<xtd::byte>(as<int32>(a * 255) % 256), r, g, b);
  return true;
}
