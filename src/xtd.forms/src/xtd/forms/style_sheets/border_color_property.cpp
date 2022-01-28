#include <xtd/argument_exception.h>
#include <xtd/drawing/solid_brush.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/drawing/drawing2d/linear_gradient_brush.h>
#include <xtd/not_supported_exception.h>
#include "../../../../include/xtd/forms/style_sheets/border_color_property.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms::style_sheets;

const border_color_property border_color_property::empty {color_property()};

border_color_property::border_color_property(const color_property& all) : all_(true), left_(all), top_(all), right_(all), bottom_(all) {
}

border_color_property::border_color_property(const color_property& left, const color_property& top, const color_property& right, const color_property& bottom) : all_(left == top && left == right && left == bottom), left_(left), top_(top), right_(right), bottom_(bottom) {
}

const color_property& border_color_property::all() const noexcept {
  return all_ ? top_ : color_property::empty;
}

void border_color_property::all(const color_property& all) noexcept {
  if (!all_ || left_ != all) {
    all_ = true;
    left_ = top_ = right_ = bottom_ = all;
  }
}

const color_property& border_color_property::bottom() const noexcept {
  return bottom_;
}

void border_color_property::bottom(const color_property& bottom) noexcept {
  if (all_ || bottom_ != bottom) {
    all_ = false;
    bottom_ = bottom;
  }
}

const color_property& border_color_property::left() const noexcept {
  return left_;
}

void border_color_property::left(const color_property& left) noexcept {
  if (all_ || left_ != left) {
    all_ = false;
    left_ = left;
  }
}

const color_property& border_color_property::right() const noexcept {
  return right_;
}

void border_color_property::right(const color_property& right) noexcept {
  if (all_ || right_ != right) {
    all_ = false;
    right_ = right;
  }
}

const color_property& border_color_property::top() const noexcept {
  return top_;
}

void border_color_property::top(const color_property& top) noexcept {
  if (all_ || top_ != top) {
    all_ = false;
    top_ = top;
  }
}

bool border_color_property::equals(const object& other) const noexcept {
  return is<border_color_property>(other) ? equals(static_cast<const border_color_property&>(other)) : false;
}

bool border_color_property::equals(const border_color_property& other) const noexcept {
  return all_ == other.all_ && left_ == other.left_ && top_ == other.top_ && right_ == other.right_ && bottom_ == other.bottom_;;
}

bool border_color_property::from_css(const xtd::ustring& css_text, border_color_property& result) noexcept {
  vector<ustring> colors = split_colors(css_text.trim());
  if (colors.size() < 1 || colors.size() > 4) return false;
  color_property color;
  if (!color_property::from_css(colors[0], color)) return false;
  result.all(color);
  if (colors.size() >= 2) {
    if (!color_property::from_css(colors[1], color)) return false;
    result.right(color);
  }
  if (colors.size() >= 3) {
    if (!color_property::from_css(colors[2], color)) return false;
    result.bottom(color);
  }
  if (colors.size() == 4) {
    if (!color_property::from_css(colors[3], color)) return false;
    result.left(color);
  }
  return true;
}

border_color_property border_color_property::from_css(const xtd::ustring& css_text, const border_color_property& default_value) noexcept {
  border_color_property result;
  if (from_css(css_text, result)) return result;
  return default_value;
}

vector<ustring> border_color_property::split_colors(const ustring& text) {
  static vector<ustring> color_keywords = {"rgb(", "rgba(", "argb(", "hsl(", "hsla(", "ahsl(", "hsv(", "hsva(", "ahsv(", "system-color("};
  auto string_starts_with_any = [](const ustring& text, const vector<ustring>& values)->ustring {
    for (auto value : values)
      if (text.starts_with(value)) return value;
    return "";
  };
  vector<ustring> result;
  auto value = text.trim();
  while (!value.empty()) {
    auto color_keyword = string_starts_with_any(value, color_keywords);
    if (color_keyword != "") {
      result.push_back(value.substring(0, value.find(")") + 1).trim());
      value = value.remove(0, value.find(")") + 1).trim();
      if (value[0] == ',') value = value.remove(0, 1).trim();
    } else if (value.find(",") == ustring::npos) {
      result.push_back(value.trim());
      value = "";
    } else if (value.find(",") != ustring::npos) {
      result.push_back(value.substring(0, value.find(",")).trim());
      value = value.remove(0, value.find(",") + 1).trim();
    }
  }
  return result;
}
