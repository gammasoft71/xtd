#include "../../../include/xtd/drawing/bitmap.h"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/image.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;

bitmap bitmap::empty;

drawing::color bitmap::get_pixel(int32_t x, int32_t y) const {
  native::argb color;
  native::image::get_pixel(handle(), x, y, color);
  return color::from_argb(color.a, color.r, color.g, color.b);
}

void bitmap::set_pixel(int32_t x, int32_t y, const drawing::color& color) {
  native::argb argb_color {color.a(), color.r(), color.g(), color.b()};
  native::image::set_pixel(handle(), x, y, argb_color);
}
