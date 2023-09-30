#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/shadow.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

struct shadow::data {
  drawing::color color = application::style_sheet().system_colors().shadow_text();
  point offset = {2, 2};
  int32 radius = 0;
};

shadow::shadow() : data_(std::make_shared<data>()) {
}

shadow::shadow(int32 x, int32 y) : shadow(point {x, y}) {
}

shadow::shadow(int32 x, int32 y, int32 radius) : shadow(point {x, y}, radius) {
}

shadow::shadow(int32 x, int32 y, int32 radius, const drawing::color& color) : shadow(point {x, y}, radius, color) {
}

shadow::shadow(const point& offset) : shadow() {
  data_->offset = offset;
}

shadow::shadow(const point& offset, int32 radius) : shadow() {
  data_->offset = offset;
  data_->radius = radius;
}

shadow::shadow(const point& offset, int32 radius, const drawing::color& color) : shadow() {
  data_->color = color;
  data_->offset = offset;
  data_->radius = radius;
}

shadow::shadow(const shadow& other) {
  *data_ = *other.data_;
}

shadow& shadow::operator =(const shadow& other) {
  *data_ = *other.data_;
  return *this;
}

const xtd::drawing::color& shadow::color() const noexcept {
  return data_->color;
}

shadow& shadow::color(const xtd::drawing::color& value) noexcept {
  data_->color = value;
  return *this;
}

const xtd::drawing::point& shadow::offset() const noexcept {
  return data_->offset;
}

shadow& shadow::offset(const xtd::drawing::point& value) noexcept {
  data_->offset = value;
  return *this;
}

int32 shadow::radius() const noexcept {
  return data_->radius;
}

shadow& shadow::radius(int32 value) noexcept {
  data_->radius = value;
  return *this;
}

int32 shadow::x() const noexcept {
  return data_->offset.x();
}

shadow& shadow::x(int32 value) noexcept {
  data_->offset.x(value);
  return *this;
}

int32 shadow::y() const noexcept {
  return data_->offset.y();
}

shadow& shadow::y(int32 value) noexcept {
  data_->offset.y(value);
  return *this;
}

bool shadow::equals(const shadow& other) const noexcept {
  return data_->color == other.data_->color && data_->offset == other.data_->offset && data_->radius == other.data_->radius;
}
