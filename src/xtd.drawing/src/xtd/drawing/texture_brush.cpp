#include "../../../include/xtd/drawing/texture_brush.h"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/brush.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;

texture_brush::texture_brush() {
}

texture_brush& texture_brush::operator =(const texture_brush& value) {
  brush::operator =(value);
  data_ = value.data_;
  return *this;
}

bool texture_brush::operator ==(const texture_brush& value) const noexcept {
  return data_->image_ == value.data_->image_;
}

bool texture_brush::operator !=(const texture_brush& value) const noexcept {
  return !operator ==(value);
}

const drawing::image& texture_brush::image() const noexcept {
  return data_->image_;
}

texture_brush& texture_brush::image(const drawing::image& image) {
  if (data_->image_ != image) {
    data_->image_ = image;
    native::brush::texture(handle(), data_->image_.handle());
  }
  return *this;
}

texture_brush::texture_brush(const texture_brush& value) : brush(value), data_(value.data_) {
}
