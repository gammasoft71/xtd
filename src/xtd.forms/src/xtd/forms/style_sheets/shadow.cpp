#include "../../../../include/xtd/forms/style_sheets/shadow"
#include <xtd/as>
#include <xtd/is>

using namespace xtd;
using namespace xtd::forms::style_sheets;

shadow::shadow(const xtd::drawing::point& offset, int32 radius, const xtd::drawing::color& color) : color_(color), offset_(offset), radius_(radius) {
}

const xtd::drawing::color& shadow::color() const noexcept {
  return color_;
}

void shadow::color(const xtd::drawing::color& value) noexcept {
  color_ = value;
}

const xtd::drawing::point& shadow::offset() const noexcept {
  return offset_;
}

void shadow::offset(const xtd::drawing::point& value) noexcept {
  offset_ = value;
}

int32 shadow::radius() const noexcept {
  return radius_;
}

void shadow::radius(int32 value) noexcept {
  radius_ = value;
}

bool shadow::equals(const shadow& other) const noexcept {
  return color_ == other.color_ && offset_ == other.offset_ && radius_ == other.radius_;
}
