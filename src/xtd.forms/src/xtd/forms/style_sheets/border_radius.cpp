#include "../../../../include/xtd/forms/style_sheets/border_radius"
#include <xtd/as>
#include <xtd/is>

using namespace xtd;
using namespace xtd::forms::style_sheets;

border_radius::border_radius(length all) : all_(true), top_left_(all), top_right_(all), bottom_left_(all), bottom_right_(all) {
}

border_radius::border_radius(length top_left, length top_right, length bottom_right, length bottom_left) : all_(top_left == top_right && top_left == bottom_left && top_left == bottom_right), top_left_(top_left), top_right_(top_right), bottom_left_(bottom_left), bottom_right_(bottom_right) {
}

length border_radius::all() const noexcept {
  return all_ ? top_right_ : length::empty;
}

void border_radius::all(length all) noexcept {
  if (!all_ || top_left_ != all) {
    all_ = true;
    top_left_ = top_right_ = bottom_left_ = bottom_right_ = all;
  }
}

length border_radius::bottom_right() const noexcept {
  return bottom_right_;
}

void border_radius::bottom_right(length bottom_right) noexcept {
  if (all_ || bottom_right_ != bottom_right) {
    all_ = false;
    bottom_right_ = bottom_right;
  }
}


length border_radius::top_left() const noexcept {
  return top_left_;
}

void border_radius::top_left(length top_left) noexcept {
  if (all_ || top_left_ != top_left) {
    all_ = false;
    top_left_ = top_left;
  }
}

length border_radius::bottom_left() const noexcept {
  return bottom_left_;
}

void border_radius::bottom_left(length bottom_left) noexcept {
  if (all_ || bottom_left_ != bottom_left) {
    all_ = false;
    bottom_left_ = bottom_left;
  }
}

length border_radius::top_right() const noexcept {
  return top_right_;
}

void border_radius::top_right(length top_right) noexcept {
  if (all_ || top_right_ != top_right) {
    all_ = false;
    top_right_ = top_right;
  }
}

bool border_radius::equals(const border_radius& other) const noexcept {
  return all_ == other.all_ && top_left_ == other.top_left_ && top_right_ == other.top_left_ && bottom_left_ == other.bottom_left_ && bottom_right_ == other.bottom_right_;
}
