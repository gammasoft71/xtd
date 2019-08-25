#include "../../../include/xtd/drawing/solid_brush.hpp"
#include <xtd/drawing/native/brush.hpp>

using namespace xtd;
using namespace xtd::drawing;

solid_brush& solid_brush::color(const drawing::color& color) {
  if (this->color_ != color) {
    this->color_ = color;
    native::brush::color(this->handle_, color.a(), color.r(), color.g(), color.b());
  }
  return *this;
}

solid_brush::solid_brush(const solid_brush& solid_brush) {
  this->color(solid_brush.color());
  this->handle_ = native::brush::create();
}

solid_brush& solid_brush::operator=(const solid_brush& solid_brush) {
  this->color(solid_brush.color());
  return *this;
}
