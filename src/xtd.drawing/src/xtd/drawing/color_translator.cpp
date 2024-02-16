#include "../../../include/xtd/drawing/color_translator.h"
#include <xtd/as>

using namespace xtd;
using namespace xtd::drawing;

namespace {
  const int32 win32_red_shift = 0;
  const int32 win32_green_shift = 8;
  const int32 win32_blue_shift = 16;
  
  ustring from_name(const color& value) {
    return value.name().replace("_", " ").to_title_case().replace(" ", "");
  }
}

ustring color_translator::to_hex(const color& value) noexcept {
  return value.is_named_color() ? from_name(value) : ustring::format("#{:x2}{:x2}{:x2}", value.r(), value.g(), value.b());
}

ustring color_translator::to_hsl(const color& value) noexcept {
  return ustring::format("hsl({}, {}%, {}%)", as<int32>(value.get_hue()), as<int32>(value.get_saturation() * 100), as<int32>(value.get_lightness() * 100));
}

ustring color_translator::to_hsla(const color& value) noexcept {
  return ustring::format("hsl({}, {}%, {}%, {:G3})", as<int32>(value.get_hue()), as<int32>(value.get_saturation() * 100), as<int32>(value.get_lightness() * 100), value.a() / 255.0);
}

ustring color_translator::to_html(const color& value) noexcept {
  return value.a() != 255 ? to_rgba(value) : to_hex(value);
}

ustring color_translator::to_rgb(const color& value) noexcept {
  return value.is_named_color() ? from_name(value) : ustring::format("rgb({}, {}, {})", value.r(), value.g(), value.b());
}

ustring color_translator::to_rgba(const color& value) noexcept {
  return value.is_named_color() ? from_name(value) : ustring::format("rgba({}, {}, {}, {:G3})", value.r(), value.g(), value.b(), value.a() / 255.0);
}

int32 color_translator::to_win32(const xtd::drawing::color& value) noexcept {
  return (value.r() << win32_red_shift) + (value.g() << win32_green_shift) + (value.b() << win32_blue_shift);
}
