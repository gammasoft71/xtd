#include <xtd/argument_exception.h>
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
  if (style != color_style::solid && style != color_style::linear_gradient) throw not_supported_exception(csf_);
}

color_data::color_data(color_style style, const vector<color>& colors, int32_t angle) : style_(style), colors_(colors), angle_(angle) {
  if (colors.empty()) throw argument_exception(csf_);
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
  if (color.style() == color_style::solid) return make_unique<solid_brush>(color.colors()[0]);
  if (color.style() == color_style::linear_gradient) {
    auto angle = color.angle() % 360;
    if (angle < 0) angle = 360 + angle;
    if (color.angle() <= 45) return make_unique<linear_gradient_brush>(rect, color.colors()[1], color.colors()[0], linear_gradient_mode::vertical);
    if (color.angle() <= 135) return make_unique<linear_gradient_brush>(rect, color.colors()[0], color.colors()[1], linear_gradient_mode::horizontal);
    if (color.angle() <= 225) return make_unique<linear_gradient_brush>(rect, color.colors()[0], color.colors()[1], linear_gradient_mode::vertical);
    if (color.angle() <= 315) return make_unique<linear_gradient_brush>(rect, color.colors()[1], color.colors()[0], linear_gradient_mode::horizontal);
    return make_unique<linear_gradient_brush>(rect, color.colors()[1], color.colors()[0], linear_gradient_mode::vertical);
  }
  throw argument_exception(csf_);
}
