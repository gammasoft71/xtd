#include "../../../include/xtd/forms/padding"

using namespace xtd;
using namespace xtd::forms;

const padding padding::empty;

padding::padding(int32 all) : all_(true), left_(all), top_(all), right_(all), bottom_(all) {
}

padding::padding(int32 left, int32 top, int32 right, int32 bottom) : all_(left == top && left == right && left == bottom), left_(left), top_(top), right_(right), bottom_(bottom) {
}

int32 padding::all() const noexcept {
  return all_ ? top_ : -1;
}

void padding::all(int32 all) {
  if (!all_ || left_ != all) {
    all_ = true;
    left_ = top_ = right_ = bottom_ = all;
  }
}

int32 padding::bottom() const noexcept {
  return bottom_;
}

void padding::bottom(int32 bottom) {
  if (all_ || bottom_ != bottom) {
    all_ = false;
    bottom_ = bottom;
  }
}

int32 padding::horizontal() const noexcept {
  return left_ + right_;
}


int32 padding::left() const noexcept {
  return left_;
}

void padding::left(int32 left) {
  if (all_ || left_ != left) {
    all_ = false;
    left_ = left;
  }
}

int32 padding::right() const noexcept {
  return right_;
}

void padding::right(int32 right) {
  if (all_ || right_ != right) {
    all_ = false;
    right_ = right;
  }
}

int32 padding::top() const noexcept {
  return top_;
}

void padding::top(int32 top) {
  if (all_ || top_ != top) {
    all_ = false;
    top_ = top;
  }
}

int32 padding::vertical() const noexcept {
  return top_ + bottom_;
}

padding padding::add(const padding& p1, const padding& p2) {
  if (p1.all_ && p2.all_) return {p1.left_ + p2.left_};
  return {p1.left_ + p2.left_, p1.top_ + p2.top_, p1.right_ + p2.right_, p1.bottom_ + p2.bottom_};
}

bool padding::equals(const padding& value) const noexcept {
  return all_ == value.all_ && left_ == value.left_ && top_ == value.top_ && right_ == value.right_ && bottom_ == value.bottom_;
}

padding padding::subtract(const padding& p1, const padding& p2) {
  if (p1.all_ && p2.all_) return {p1.left_ - p2.left_};
  return {p1.left_ - p2.left_, p1.top_ - p2.top_, p1.right_ - p2.right_, p1.bottom_ - p2.bottom_};
}

xtd::ustring padding::to_string() const noexcept {
  return xtd::ustring::format("padding [all={}, left={}, top={}, right={}, bottom={}]", all_, left_, top_, right_, bottom_);
}
