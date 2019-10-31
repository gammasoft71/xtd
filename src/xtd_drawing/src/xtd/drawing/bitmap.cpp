#include "../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/drawing/native/image.hpp>

using namespace xtd;
using namespace xtd::drawing;


drawing::color bitmap::get_pixel(int32_t x, int32_t y) const {
  native::argb color;
  native::image::get_pixel(this->handle(), x, y, color);
  return color::from_argb(color.a, color.r, color.g, color.b);
}
