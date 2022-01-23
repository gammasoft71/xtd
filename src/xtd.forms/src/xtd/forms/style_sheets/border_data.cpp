#include "../../../../include/xtd/forms/style_sheets/border_data.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

border_data::border_data(const color_data& color, border_type style, int32_t width, int32_t radius) : color_(color), style_(style), width_(width), radius_(radius) {
}

const color_data& border_data::color() const noexcept {
  return color_;
}

void border_data::color(const color_data& value) noexcept {
  color_ = value;
}

border_type border_data::style() const noexcept {
  return style_;
}

void border_data::style(border_type value) noexcept {
  style_ = value;
}

int32_t border_data::radius() const noexcept {
  return radius_;
}

void border_data::radius(int32_t value) noexcept {
  radius_ = value;
}

int32_t border_data::width() const noexcept {
  return width_;
}

void border_data::width(int32_t value) noexcept {
  width_ = value;
}

xtd::ustring border_data::to_string() const noexcept {
  return ustring::format("[style={}, color={}, width={}, radius={}]", style(), color(), width(), radius());
}
