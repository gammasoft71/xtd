#include <xtd/argument_exception.h>
#include <xtd/format_exception.h>
#include <xtd/drawing/solid_brush.h>
#include <xtd/drawing/drawing2d/linear_gradient_brush.h>
#include <xtd/not_supported_exception.h>
#include "../../../../include/xtd/forms/style_sheets/color_data.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

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
    throw format_exception(csf_);
  return result;
}

bool color_data::try_parse(const xtd::ustring& text, color_data& result) {
  auto value = text.trim();
  if (text.starts_with("#") && (value.size() == 4U || value.size() == 5U || value.size() == 7U || value.size() == 9U)) {
    color c;
    if (try_parse_solid_color(value, c) == false) return false;
    result = color_data(c);
    return true;
  }
  return false;
}

bool color_data::try_parse_solid_color(const xtd::ustring& text, color& result) {
  if (text.starts_with("#") && text.size() == 4U) {
    byte_t r;
    if (xtd::try_parse<byte_t>(text.substring(1, 1), r, number_styles::hex_number) == false) return false;
    r += r * 16;
    byte_t g;
    if (xtd::try_parse<byte_t>(text.substring(2, 1), g, number_styles::hex_number) == false) return false;
    g += g * 16;
    byte_t b;
    if (xtd::try_parse<byte_t>(text.substring(3, 1), b, number_styles::hex_number) == false) return false;
    b += b * 16;
    result = color::from_argb(r, g, b);
    return true;
  }
  if (text.starts_with("#") && text.size() == 5U) {
    byte_t a;
    if (xtd::try_parse<byte_t>(text.substring(1, 1), a, number_styles::hex_number) == false) return false;
    a += a * 16;
    byte_t r;
    if (xtd::try_parse<byte_t>(text.substring(2, 1), r, number_styles::hex_number) == false) return false;
    r += r * 16;
    byte_t g;
    if (xtd::try_parse<byte_t>(text.substring(3, 1), g, number_styles::hex_number) == false) return false;
    g += g * 16;
    byte_t b;
    if (xtd::try_parse<byte_t>(text.substring(4, 1), b, number_styles::hex_number) == false) return false;
    b += b * 16;
    result = color::from_argb(a, r, g, b);
    return true;
  }
  if (text.starts_with("#") &&text.size() == 7U) {
    int32_t rgb;
    if (xtd::try_parse<int>(text.substring(1), rgb, number_styles::hex_number) == false) return false;
    result = color::from_argb(rgb + 0xFF000000);
    return true;
  }
  if (text.starts_with("#") &&text.size() == 9U) {
    int32_t argb;
    if (xtd::try_parse<int>(text.substring(1), argb, number_styles::hex_number) == false) return false;
    result = color::from_argb(argb);
    return true;
  }
  return false;
}
