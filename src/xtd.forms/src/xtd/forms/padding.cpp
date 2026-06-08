#include "../../../include/xtd/forms/padding.hpp"

using namespace xtd;
using namespace xtd::forms;

const padding padding::empty;

padding::padding(int32 all) : all_(true), left_(all), top_(all), right_(all), bottom_(all) {
}

padding::padding(int32 left, int32 top, int32 right, int32 bottom) : all_(left == top && left == right && left == bottom), left_(left), top_(top), right_(right), bottom_(bottom) {
}

auto padding::all() const noexcept -> int32 {
  return all_ ? top_ : -1;
}

auto padding::all(int32 all) -> padding& {
  if (all_ && left_ == all) return *this;
  all_ = true;
  left_ = top_ = right_ = bottom_ = all;
  return *this;
}

auto padding::bottom() const noexcept -> int32 {
  return bottom_;
}

auto padding::bottom(int32 bottom) -> padding& {
  if (!all_ && bottom_ == bottom) return *this;
  all_ = false;
  bottom_ = bottom;
  return *this;
}

auto padding::horizontal() const noexcept -> int32 {
  return left_ + right_;
}


auto padding::left() const noexcept -> int32 {
  return left_;
}

auto padding::left(int32 left) -> padding& {
  if (!all_ && left_ == left) return *this;
  all_ = false;
  left_ = left;
  return *this;
}

auto padding::right() const noexcept -> int32 {
  return right_;
}

auto padding::right(int32 right) -> padding& {
  if (!all_ && right_ == right) return *this;
  all_ = false;
  right_ = right;
  return *this;
}

auto padding::top() const noexcept -> int32 {
  return top_;
}

auto padding::top(int32 top) -> padding& {
  if (!all_ && top_ == top) return *this;
  all_ = false;
  top_ = top;
  return *this;
}

auto padding::vertical() const noexcept -> int32 {
  return top_ + bottom_;
}

auto padding::add(const padding& p1, const padding& p2) -> padding {
  if (p1.all_ && p2.all_) return {p1.left_ + p2.left_};
  return {p1.left_ + p2.left_, p1.top_ + p2.top_, p1.right_ + p2.right_, p1.bottom_ + p2.bottom_};
}

auto padding::equals(const object& obj) const noexcept -> bool {
  return is<padding>(obj) && equals(static_cast<const padding&>(obj));
}

auto padding::equals(const padding& other) const noexcept -> bool {
  return all_ == other.all_ && bottom_ == other.bottom_ && left_ == other.left_ && right_ == other.right_ && top_ == other.top_;
}

auto padding::get_hash_code() const noexcept -> usize {
  return hash_code::combine(all_, bottom_, left_, right_, top_);
}

auto padding::subtract(const padding& p1, const padding& p2) -> padding {
  if (p1.all_ && p2.all_) return {p1.left_ - p2.left_};
  return {p1.left_ - p2.left_, p1.top_ - p2.top_, p1.right_ - p2.right_, p1.bottom_ - p2.bottom_};
}

auto padding::to_string() const noexcept -> string {
  return string::format("padding [all={}, left={}, top={}, right={}, bottom={}]", all_, left_, top_, right_, bottom_);
}
