#include "../../../include/xtd/drawing/bitmap.h"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/image.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;

bitmap bitmap::empty;

drawing::color bitmap::get_pixel(int32_t x, int32_t y) const {
  uint8_t a = 0, r = 0, g = 0, b = 0;
  native::image::get_pixel(handle(), x, y, a, r, g, b);
  return color::from_argb(a, r, g, b);
}

void bitmap::set_pixel(int32_t x, int32_t y, const drawing::color& color) {
  native::image::set_pixel(handle(), x, y, color.a(), color.r(), color.g(), color.b());
}
