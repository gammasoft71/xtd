#include "../../../../include/xtd/forms/style_sheets/border_width.h"
#include <xtd/as.h>
#include <xtd/is.h>

using namespace xtd;
using namespace xtd::forms::style_sheets;

border_width::border_width(length all) : all_(true), left_(all), top_(all), right_(all), bottom_(all) {
}

border_width::border_width(length left, length top, length right, length bottom) : all_(left == top && left == right && left == bottom), left_(left), top_(top), right_(right), bottom_(bottom) {
}

length border_width::all() const noexcept {
  return all_ ? top_ : length::empty;
}

void border_width::all(length all) noexcept {
  if (!all_ || left_ != all) {
    all_ = true;
    left_ = top_ = right_ = bottom_ = all;
  }
}


length border_width::bottom() const noexcept {
  return bottom_;
}

void border_width::bottom(length bottom) noexcept {
  if (all_ || bottom_ != bottom) {
    all_ = false;
    bottom_ = bottom;
  }
}

length border_width::left() const noexcept {
  return left_;
}

void border_width::left(length left) noexcept {
  if (all_ || left_ != left) {
    all_ = false;
    left_ = left;
  }
}

length border_width::right() const noexcept {
  return right_;
}

void border_width::right(length right) noexcept {
  if (all_ || right_ != right) {
    all_ = false;
    right_ = right;
  }
}

length border_width::top() const noexcept {
  return top_;
}

void border_width::top(length top) noexcept {
  if (all_ || top_ != top) {
    all_ = false;
    top_ = top;
  }
}

bool border_width::equals(const object& other) const noexcept {
  return is<border_width>(other) ? equals(static_cast<const border_width&>(other)) : false;
}

bool border_width::equals(const border_width& other) const noexcept {
  return all_ == other.all_ && left_ == other.left_ && top_ == other.top_ && right_ == other.right_ && bottom_ == other.bottom_;
}
