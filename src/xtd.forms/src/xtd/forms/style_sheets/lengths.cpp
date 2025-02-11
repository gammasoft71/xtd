#include "../../../../include/xtd/forms/style_sheets/lengths.hpp"
#include <xtd/as>
#include <xtd/is>

using namespace xtd;
using namespace xtd::forms::style_sheets;

lengths::lengths(length all) : all_(true), left_(all), top_(all), right_(all), bottom_(all) {
}

lengths::lengths(length left, length top, length right, length bottom) : all_(left == top && left == right && left == bottom), left_(left), top_(top), right_(right), bottom_(bottom) {
}

length lengths::all() const noexcept {
  return all_ ? top_ : length::empty;
}

void lengths::all(length all) noexcept {
  if (!all_ || left_ != all) {
    all_ = true;
    left_ = top_ = right_ = bottom_ = all;
  }
}


length lengths::bottom() const noexcept {
  return bottom_;
}

void lengths::bottom(length bottom) noexcept {
  if (all_ || bottom_ != bottom) {
    all_ = false;
    bottom_ = bottom;
  }
}

length lengths::left() const noexcept {
  return left_;
}

void lengths::left(length left) noexcept {
  if (all_ || left_ != left) {
    all_ = false;
    left_ = left;
  }
}

length lengths::right() const noexcept {
  return right_;
}

void lengths::right(length right) noexcept {
  if (all_ || right_ != right) {
    all_ = false;
    right_ = right;
  }
}

length lengths::top() const noexcept {
  return top_;
}

void lengths::top(length top) noexcept {
  if (all_ || top_ != top) {
    all_ = false;
    top_ = top;
  }
}

bool lengths::equals(const object& obj) const noexcept {
  return is<lengths>(obj) && equals(static_cast<const lengths&>(obj));
}

bool lengths::equals(const lengths& other) const noexcept {
  return all_ == other.all_ && bottom_ == other.bottom_ && left_ == other.left_ && right_ == other.right_ && top_ == other.top_;
}

xtd::size lengths::get_hash_code() const noexcept {
  return hash_code::combine(all_, bottom_, left_, right_, top_);
}

xtd::string lengths::to_string() const noexcept {
  if (all_) return string::format("[all = {}]", top());
  return string::format("[top = {}, left = {}, bottom = {}, right = {}]", top(), left(), bottom(), right());
}
