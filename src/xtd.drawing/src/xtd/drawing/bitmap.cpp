#include "../../../include/xtd/drawing/bitmap"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/image>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/argument_exception>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;

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

bitmap::bitmap(int32 width, int32 height, const graphics& g) : xtd::drawing::image(width, height, g.dpi_x(), g.dpi_y()) {
}

bitmap::bitmap(int32 width, int32 height, xtd::drawing::imaging::pixel_format format) : xtd::drawing::image(width, height, format) {
}

bitmap::bitmap(int32 width, int32 height, int32 stride, xtd::drawing::imaging::pixel_format format, intptr scan0) : xtd::drawing::image(width, height, stride, format, scan0) {
}

bitmap::bitmap(const xtd::drawing::size& size) : xtd::drawing::image(size.width(), size.height()) {
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
  auto a = 0_u8, r = 0_u8, g = 0_u8, b = 0_u8;
  native::image::get_pixel(handle(), x, y, a, r, g, b);
  return color::from_argb(a, r, g, b);
}

bitmap_data bitmap::lock_bits(const rectangle& rect, xtd::drawing::imaging::image_lock_mode flags, xtd::drawing::imaging::pixel_format format) {
  return lock_bits(rect, flags, format, bitmap_data {});
}

bitmap_data bitmap::lock_bits(const rectangle& rect, xtd::drawing::imaging::image_lock_mode flags, xtd::drawing::imaging::pixel_format format, const bitmap_data& data) {
  if (format == xtd::drawing::imaging::pixel_format::indexed || format == xtd::drawing::imaging::pixel_format::gdi) throw argument_exception {csf_};
  auto image_data_height = data.height();
  auto image_data_pixel_format = static_cast<int32>(data.pixel_format());
  auto image_data_reserved = data.reserved();
  auto image_data_scan0 = data.scan0();
  auto image_data_stride = data.stride();
  auto image_data_width = data.width();
  native::image::lock_bits(handle(), rect.left(), rect.top(), rect.width(), rect.height(), static_cast<int32>(flags), static_cast<int32>(format), image_data_height, image_data_pixel_format, image_data_reserved, image_data_scan0, image_data_stride, image_data_width);
  return bitmap_data().height(image_data_height).pixel_format(static_cast<xtd::drawing::imaging::pixel_format>(image_data_pixel_format)).reserved(image_data_reserved).scan0(image_data_scan0).stride(image_data_stride).width(image_data_width);
}

void bitmap::make_transparent() {
  for (auto y = 0; y < height(); ++y)
    for (auto x = 0; x < image::width(); ++x)
      if (get_pixel(x, y).a() < 255) return;
  make_transparent(color::light_gray);
}

void bitmap::make_transparent(const color& transparent_color) {
  set_pixel_format(imaging::pixel_format::format_32bpp_argb);
  native::image::make_transparent(handle(), transparent_color.a(), transparent_color.r(), transparent_color.g(), transparent_color.b());
}

void bitmap::set_pixel(int32 x, int32 y, const drawing::color& color) {
  native::image::set_pixel(handle(), x, y, color.a(), color.r(), color.g(), color.b());
}

void bitmap::set_resolution(int32 x_dpi, int32 y_dpi) {
  native::image::set_resolution(handle(), x_dpi, y_dpi);
}

void bitmap::unlock_bits(const bitmap_data& data) {
  auto image_data_height = data.height();
  auto image_data_pixel_format = static_cast<int32>(data.pixel_format());
  auto image_data_reserved = data.reserved();
  auto image_data_scan0 = data.scan0();
  auto image_data_stride = data.stride();
  auto image_data_width = data.width();
  native::image::unlock_bits(handle(), image_data_height, image_data_pixel_format, image_data_reserved, image_data_scan0, image_data_stride, image_data_width);
}
