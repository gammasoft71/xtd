#include "../../../../include/xtd/forms/style_sheets/border_data.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

border_data::border_data(const color_data& color, border_style style, int32_t width, int32_t radius) : color_(color), style_(style), width_(width), radius_(radius) {
}

const color_data& border_data::color() const noexcept {
  return color_;
}

border_style border_data::style() const noexcept {
  return style_;
}

int32_t border_data::radius() const noexcept {
  return radius_;
}

int32_t border_data::width() const noexcept {
  return width_;
}
