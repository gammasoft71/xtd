#include "../../../include/xtd/drawing/texture_brush.hpp"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/brush>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;

struct texture_brush::data {
  drawing::image image_;
};

texture_brush::texture_brush(const drawing::image& image) : data_(xtd::new_sptr<data>()) {
  this->image(image);
}

texture_brush::texture_brush() : data_(xtd::new_sptr<data>()) {
}

texture_brush& texture_brush::operator =(const texture_brush& value) {
  brush::operator =(value);
  data_ = value.data_;
  return *this;
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
