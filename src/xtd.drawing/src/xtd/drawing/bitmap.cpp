#include "../../../include/xtd/drawing/bitmap.h"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/image.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;

bitmap bitmap::empty;

bitmap::bitmap(const image& original) : xtd::drawing::image(original) {
}

bitmap::bitmap(const image& original, const xtd::drawing::size& new_size) : xtd::drawing::image(original, new_size.width(), new_size.height()) {
}

bitmap::bitmap(const image& original, int32 width, int32 height) : xtd::drawing::image(original, width, height) {
}

bitmap::bitmap(const image& original, const rectangle& new_rect) : xtd::drawing::image(original, new_rect) {
}

bitmap::bitmap(const xtd::ustring& filename) : xtd::drawing::image(filename) {
}

bitmap::bitmap(const xtd::ustring& filename, bool use_icm) : xtd::drawing::image(filename, use_icm) {
}

bitmap::bitmap(std::istream& stream) : xtd::drawing::image(stream) {
}

bitmap::bitmap(std::istream& stream, bool use_icm) : xtd::drawing::image(stream, use_icm) {
}

bitmap::bitmap(const char* const* bits) : xtd::drawing::image(bits) {
}

bitmap::bitmap(int32 width, int32 height) : xtd::drawing::image(width, height) {
}

bitmap::bitmap(const xtd::drawing::size& size) : xtd::drawing::image(size.width(), size.height()) {
}

bitmap bitmap::clone(const rectangle& rect) const {
  return bitmap(*this, rect);
}

bitmap bitmap::clone(const rectangle_f& rect) const {
  return bitmap(*this, xtd::drawing::rectangle::ceiling(rect));
}

drawing::color bitmap::get_pixel(int32 x, int32 y) const {
  xtd::byte a = 0, r = 0, g = 0, b = 0;
  native::image::get_pixel(handle(), x, y, a, r, g, b);
  return color::from_argb(a, r, g, b);
}

void bitmap::set_pixel(int32 x, int32 y, const drawing::color& color) {
  native::image::set_pixel(handle(), x, y, color.a(), color.r(), color.g(), color.b());
}
