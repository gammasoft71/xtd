#include "../../../../include/xtd/forms/style_sheets/border_style"
#include <xtd/as>
#include <xtd/is>

using namespace xtd;
using namespace xtd::forms::style_sheets;

border_style::border_style(border_type all) : all_(true), left_(all), top_(all), right_(all), bottom_(all) {
}

border_style::border_style(border_type left, border_type top, border_type right, border_type bottom) : all_(left == top && left == right && left == bottom), left_(left), top_(top), right_(right), bottom_(bottom) {
}

border_type border_style::all() const noexcept {
  return all_ ? top_ : border_type();
}

void border_style::all(border_type all) noexcept {
  if (!all_ || left_ != all) {
    all_ = true;
    left_ = top_ = right_ = bottom_ = all;
  }
}

border_type border_style::bottom() const {
  return bottom_;
}

void border_style::bottom(border_type bottom) noexcept {
  if (all_ || bottom_ != bottom) {
    all_ = false;
    bottom_ = bottom;
  }
}

border_type border_style::left() const noexcept {
  return left_;
}

void border_style::left(border_type left) noexcept {
  if (all_ || left_ != left) {
    all_ = false;
    left_ = left;
  }
}

border_type border_style::right() const noexcept {
  return right_;
}

void border_style::right(border_type right) {
  if (all_ || right_ != right) {
    all_ = false;
    right_ = right;
  }
}

border_type border_style::top() const noexcept {
  return top_;
}

void border_style::top(border_type top) noexcept {
  if (all_ || top_ != top) {
    all_ = false;
    top_ = top;
  }
}

bool border_style::equals(const border_style& other) const noexcept {
  return all_ == other.all_ && left_ == other.left_ && top_ == other.top_ && right_ == other.right_ && bottom_ == other.bottom_;
}
