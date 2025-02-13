#include "../../../include/xtd/drawing/bitmap.hpp"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/image>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/argument_exception>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;

bitmap bitmap::empty;

bitmap::bitmap(const image& original) : image(original) {
}

bitmap::bitmap(const image& original, const xtd::drawing::size& new_size) : image(original, new_size.width, new_size.height) {
}

bitmap::bitmap(const image& original, int32 width, int32 height) : image(original, width, height) {
}

bitmap::bitmap(const image& original, const rectangle& new_rect) : image(original, new_rect) {
}

bitmap::bitmap(const string& filename) : image(filename) {
}

bitmap::bitmap(const string& filename, bool use_icm) : image(filename, use_icm) {
}

bitmap::bitmap(std::istream& stream) : image(stream) {
}

bitmap::bitmap(std::istream& stream, bool use_icm) : image(stream, use_icm) {
}

bitmap::bitmap(const char* const* bits) : image(bits) {
}

bitmap::bitmap(int32 width, int32 height) : image(width, height) {
}

bitmap::bitmap(int32 width, int32 height, const graphics& g) : image(width, height, g.dpi_x(), g.dpi_y()) {
}

bitmap::bitmap(int32 width, int32 height, enum pixel_format format) : image(width, height, format) {
}

bitmap::bitmap(int32 width, int32 height, int32 stride, enum pixel_format format, intptr scan0) : image(width, height, stride, format, scan0) {
}

bitmap::bitmap(const xtd::drawing::size& size) : image(size.width, size.height) {
}

bitmap bitmap::clone(const rectangle& rect) const {
  return bitmap(*this, rect);
}

bitmap bitmap::clone(const rectangle_f& rect) const {
  return bitmap(*this, xtd::drawing::rectangle::ceiling(rect));
}

bitmap bitmap::from_hicon(intptr hicon) {
  return bitmap(image::from_hicon(hicon));
}

intptr bitmap::get_hbitmap() const {
  return native::image::get_hbitmap(handle());
}

intptr bitmap::get_hbitmap(const color& background) const {
  return native::image::get_hbitmap(handle(), background.a(), background.r(), background.g(), background.b());
}

intptr bitmap::get_hicon() const {
  return native::image::get_hicon(handle());
}

drawing::color bitmap::get_pixel(int32 x, int32 y) const {
  return image::get_pixel(x, y);
}

bitmap_data bitmap::lock_bits(const rectangle& rect, image_lock_mode flags, enum pixel_format format) {
  return lock_bits(rect, flags, format, bitmap_data {});
}

bitmap_data bitmap::lock_bits(const rectangle& rect, image_lock_mode flags, enum pixel_format format, const bitmap_data& data) {
  if (format == pixel_format::indexed || format == pixel_format::gdi) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  auto image_data_height = data.height;
  auto image_data_pixel_format = static_cast<int32>(data.pixel_format);
  auto image_data_reserved = data.reserved;
  auto image_data_scan0 = data.scan0;
  auto image_data_stride = data.stride;
  auto image_data_width = data.width;
  native::image::lock_bits(handle(), rect.left(), rect.top(), rect.width, rect.height, static_cast<int32>(flags), static_cast<int32>(format), image_data_height, image_data_pixel_format, image_data_reserved, image_data_scan0, image_data_stride, image_data_width);
  auto result = bitmap_data {};
  result.height = image_data_height;
  result.pixel_format = static_cast<enum pixel_format>(image_data_pixel_format);
  result.reserved = image_data_reserved;
  result.scan0 = image_data_scan0;
  result.stride = image_data_stride;
  result.width = image_data_width;
  return result;
}

void bitmap::make_transparent() {
  for (auto y = 0; y < height(); ++y)
    for (auto x = 0; x < image::width(); ++x)
      if (get_pixel(x, y).a() < 255) return;
  make_transparent(color::light_gray);
}

void bitmap::make_transparent(const color& transparent_color) {
  set_pixel_format(pixel_format::format_32bpp_argb);
  native::image::make_transparent(handle(), transparent_color.a(), transparent_color.r(), transparent_color.g(), transparent_color.b());
}

void bitmap::set_pixel(int32 x, int32 y, const color& color) {
  image::set_pixel(x, y, color);
}

void bitmap::set_resolution(int32 x_dpi, int32 y_dpi) {
  native::image::set_resolution(handle(), x_dpi, y_dpi);
}

void bitmap::unlock_bits(const bitmap_data& data) {
  auto image_data_height = data.height;
  auto image_data_pixel_format = static_cast<int32>(data.pixel_format);
  auto image_data_reserved = data.reserved;
  auto image_data_scan0 = data.scan0;
  auto image_data_stride = data.stride;
  auto image_data_width = data.width;
  native::image::unlock_bits(handle(), image_data_height, image_data_pixel_format, image_data_reserved, image_data_scan0, image_data_stride, image_data_width);
}
