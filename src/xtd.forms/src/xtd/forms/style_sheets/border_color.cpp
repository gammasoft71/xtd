#include "../../../../include/xtd/forms/style_sheets/border_color.h"
#include <xtd/drawing/solid_brush>
#include <xtd/drawing/system_colors>

using namespace std;
using namespace xtd;
using namespace xtd::forms::style_sheets;

const border_color border_color::empty {xtd::drawing::color()};

border_color::border_color(const xtd::drawing::color& all) : all_(true), left_(all), top_(all), right_(all), bottom_(all) {
}

border_color::border_color(const xtd::drawing::color& left, const xtd::drawing::color& top, const xtd::drawing::color& right, const xtd::drawing::color& bottom) : all_(left == top && left == right && left == bottom), left_(left), top_(top), right_(right), bottom_(bottom) {
}

const xtd::drawing::color& border_color::all() const noexcept {
  return all_ ? top_ : xtd::drawing::color::empty;
}

void border_color::all(const xtd::drawing::color& all) noexcept {
  if (!all_ || left_ != all) {
    all_ = true;
    left_ = top_ = right_ = bottom_ = all;
  }
}

const xtd::drawing::color& border_color::bottom() const noexcept {
  return bottom_;
}

void border_color::bottom(const xtd::drawing::color& bottom) noexcept {
  if (all_ || bottom_ != bottom) {
    all_ = false;
    bottom_ = bottom;
  }
}

const xtd::drawing::color& border_color::left() const noexcept {
  return left_;
}

void border_color::left(const xtd::drawing::color& left) noexcept {
  if (all_ || left_ != left) {
    all_ = false;
    left_ = left;
  }
}

const xtd::drawing::color& border_color::right() const noexcept {
  return right_;
}

void border_color::right(const xtd::drawing::color& right) noexcept {
  if (all_ || right_ != right) {
    all_ = false;
    right_ = right;
  }
}

const xtd::drawing::color& border_color::top() const noexcept {
  return top_;
}

void border_color::top(const xtd::drawing::color& top) noexcept {
  if (all_ || top_ != top) {
    all_ = false;
    top_ = top;
  }
}

bool border_color::equals(const border_color& other) const noexcept {
  return all_ == other.all_ && left_ == other.left_ && top_ == other.top_ && right_ == other.right_ && bottom_ == other.bottom_;
}
