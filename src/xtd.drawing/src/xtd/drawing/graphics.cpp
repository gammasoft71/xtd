#include <vector>
#include "../../../include/xtd/drawing/bitmap.h"
#include "../../../include/xtd/drawing/icon.h"
#include "../../../include/xtd/drawing/graphics.h"
#include "../../../include/xtd/drawing/solid_brush.h"
#include <xtd/argument_exception.h>
#include <xtd/as.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/graphics.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

namespace {
  ustring get_hotkey_prefix_locations(const ustring& str, std::vector<size_t>& locations) {
    size_t offset = 0;
    for (auto index = 0U; index < str.size(); index++) {
      if (str[index] == '&' && str[index + 1] != '&')
        locations.push_back(index + offset);
      else if (str[index] == '&' && str[index + 1] == '&') {
        offset -= 2;
        ++index;
      }
    }
    auto new_str = str.replace("&&", "&");
    for (auto index = 0U; index < locations.size(); ++index)
      new_str = new_str.remove(locations[index], 1);
    return new_str;
  }
}

graphics::graphics(const graphics& value) {
  if (data_.use_count() == 1 && handle() != 0) native::graphics::destroy(handle());
  data_ = value.data_;
}

graphics& graphics::operator=(const graphics& value) {
  if (data_.use_count() == 1 && handle() != 0) native::graphics::destroy(handle());
  data_ = value.data_;
  return *this;
}

graphics::~graphics() {
  if (data_.use_count() == 1 && handle() != 0) native::graphics::destroy(handle());
}

region graphics::clip() const {
  return data_->clip;
}

graphics& graphics::clip(const xtd::drawing::region value) {
  if (data_->clip != value) {
    data_->clip = value;
    native::graphics::clip(handle(), data_->clip.handle());
  }
  return *this;
}

rectangle_f graphics::clip_bounds() const {
  auto rect_pixels = data_->clip.get_bounds(*this);
  return rectangle_f(to_page_unit(rect_pixels.x()), to_page_unit(rect_pixels.y()), to_page_unit(rect_pixels.width()), to_page_unit(rect_pixels.height()));
}

xtd::drawing::drawing2d::compositing_mode graphics::compositing_mode() const {
  return data_->compositing_mode;
}

graphics& graphics::compositing_mode(xtd::drawing::drawing2d::compositing_mode value) {
  if (data_->compositing_mode != value) {
    data_->compositing_mode = value;
    if (data_->text_rendering_hint == xtd::drawing::text::text_rendering_hint::clear_type_grid_fit && data_->compositing_mode == xtd::drawing::drawing2d::compositing_mode::source_copy) throw argument_exception(csf_);
    native::graphics::compositing_mode(handle(), static_cast<int32_t>(data_->compositing_mode));
  }
  return *this;
}

xtd::drawing::drawing2d::compositing_quality graphics::compositing_quality() const {
  return data_->compositing_quality;
}

graphics& graphics::compositing_quality(xtd::drawing::drawing2d::compositing_quality value) {
  if (data_->compositing_quality != value) {
    data_->compositing_quality = value;
    native::graphics::compositing_quality(handle(), static_cast<int32_t>(data_->compositing_quality));
  }
  return *this;
}

float graphics::dpi_x() const {
  return native::graphics::get_dpi_x(handle());
}

float graphics::dpi_y() const {
  return native::graphics::get_dpi_y(handle());
}

intptr_t graphics::handle() const {
  return data_->handle;
}

xtd::drawing::drawing2d::interpolation_mode graphics::interpolation_mode() const {
  return data_->interpolation_mode;
}

graphics& graphics::interpolation_mode(xtd::drawing::drawing2d::interpolation_mode value) {
  if (data_->interpolation_mode != value) {
    data_->interpolation_mode = value;
    native::graphics::interpolation_mode(handle(), static_cast<int32_t>(data_->interpolation_mode));
  }
  return *this;
}

float graphics::page_scale() const {
  return data_->page_scale;
}

graphics& graphics::page_scale(float value) {
  data_->page_scale = value;
  return *this;
}

xtd::drawing::graphics_unit graphics::page_unit() const {
  return data_->page_unit;
}
graphics& graphics::page_unit(xtd::drawing::graphics_unit value) {
  if (value == graphics_unit::world) throw argument_exception(csf_);
  data_->page_unit = value;
  return *this;
}

xtd::drawing::drawing2d::pixel_offset_mode graphics::pixel_offset_mode() const {
  return data_->pixel_offset_mode;
}

graphics& graphics::pixel_offset_mode(xtd::drawing::drawing2d::pixel_offset_mode value) {
  if (data_->pixel_offset_mode != value) {
    data_->pixel_offset_mode = value;
    native::graphics::pixel_offset_mode(handle(), static_cast<int32_t>(data_->pixel_offset_mode));
  }
  return *this;
}

xtd::drawing::drawing2d::smoothing_mode graphics::smoothing_mode() const {
  return data_->smoothing_mode;
}
graphics& graphics::smoothing_mode(xtd::drawing::drawing2d::smoothing_mode value) {
  if (data_->smoothing_mode != value) {
    data_->smoothing_mode = value;
    native::graphics::smoothing_mode(handle(), static_cast<int32_t>(data_->smoothing_mode));
  }
  return *this;
}

int graphics::text_contrast() const {
  return data_->text_contrast;
}

graphics& graphics::text_contrast(int value) {
  if (data_->text_contrast != value) {
    data_->text_contrast = value;
    native::graphics::text_contrast(handle(), data_->text_contrast);
  }
  return *this;
}

xtd::drawing::text::text_rendering_hint graphics::text_rendering_hint() const {
  return data_->text_rendering_hint;
}

graphics& graphics::text_rendering_hint(xtd::drawing::text::text_rendering_hint value) {
  if (data_->text_rendering_hint != value) {
    data_->text_rendering_hint = value;
    if (data_->text_rendering_hint == xtd::drawing::text::text_rendering_hint::clear_type_grid_fit && data_->compositing_mode == xtd::drawing::drawing2d::compositing_mode::source_copy) throw argument_exception(csf_);
    native::graphics::text_rendering_hint(handle(), static_cast<int32_t>(data_->text_rendering_hint));
  }
  return *this;
}

rectangle_f graphics::visible_clip_bounds() const noexcept {
  float x = 0.0f, y = 0.0f, width = 0.0f, height = 0.0f;
  native::graphics::visible_clip_bounds(handle(), x, y, width, height);
  return {x, y, width, height};
}

void graphics::clear(const color& color) {
  native::graphics::clear(handle(), color.a(), color.r(), color.g(), color.b());
}

void graphics::copy_from_screen(const xtd::drawing::point& upper_left_source, const xtd::drawing::point& upper_left_destination, const xtd::drawing::size& block_region_size) {
  copy_from_screen(upper_left_source.x(), upper_left_source.y(), upper_left_destination.x(), upper_left_destination.y(), block_region_size, xtd::drawing::copy_pixel_operation::source_copy);
}

void graphics::copy_from_screen(const xtd::drawing::point& upper_left_source, const xtd::drawing::point& upper_left_destination, const xtd::drawing::size& block_region_size, xtd::drawing::copy_pixel_operation copy_pixel_operation) {
  copy_from_screen(upper_left_source.x(), upper_left_source.y(), upper_left_destination.x(), upper_left_destination.y(), block_region_size, copy_pixel_operation);
}

void graphics::copy_from_screen(int32_t source_x, int32_t source_y, int32_t destination_x, int32_t destination_y, const xtd::drawing::size& block_region_size) {
  copy_from_screen(source_x, source_y, destination_x, destination_y, block_region_size, xtd::drawing::copy_pixel_operation::source_copy);
}

void graphics::copy_from_screen(int32_t source_x, int32_t source_y, int32_t destination_x, int32_t destination_y, const xtd::drawing::size& block_region_size, xtd::drawing::copy_pixel_operation copy_pixel_operation) {
  native::graphics::copy_from_screen(handle(), source_x, source_y, destination_x, destination_y, block_region_size.width(), block_region_size.height(), static_cast<int32_t>(copy_pixel_operation));
}

void graphics::draw_arc(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle) {
  draw_arc(pen, rectangle_f(rect), start_angle, sweep_angle);
}

void graphics::draw_arc(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle) {
  draw_arc(pen, rect.x(), rect.y(), rect.width(), rect.height(), start_angle, sweep_angle);
}

void graphics::draw_arc(const pen& pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  draw_arc(pen, as<float>(x), as<float>(y), as<float>(width), as<float>(height), as<float>(start_angle), as<float>(sweep_angle));
}

void graphics::draw_arc(const xtd::drawing::pen& pen, float x, float y, float width, float height, float start_angle, float sweep_angle) {
  native::graphics::draw_arc(handle(), pen.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height), start_angle, sweep_angle);
}

void graphics::draw_bezier(const xtd::drawing::pen& pen, const xtd::drawing::point& pt1, const xtd::drawing::point& pt2, const xtd::drawing::point& pt3, const xtd::drawing::point& pt4) {
  draw_bezier(pen, pt1.x(), pt1.y(), pt2.x(), pt2.y(), pt3.x(), pt3.y(), pt4.x(), pt4.y());
}

void graphics::draw_bezier(const xtd::drawing::pen& pen, const xtd::drawing::point_f& pt1, const xtd::drawing::point_f& pt2, const xtd::drawing::point_f& pt3, const xtd::drawing::point_f& pt4) {
  draw_bezier(pen, pt1.x(), pt1.y(), pt2.x(), pt2.y(), pt3.x(), pt3.y(), pt4.x(), pt4.y());
}

void graphics::draw_bezier(const pen& pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, int32_t x4, int32_t y4) {
  draw_bezier(pen, as<float>(x1), as<float>(y1), as<float>(x2), as<float>(y2), as<float>(x3), as<float>(y3), as<float>(x4), as<float>(y4));
}

void graphics::draw_bezier(const pen& pen, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
  native::graphics::draw_bezier(handle(), pen.handle(), to_pixels(x1), to_pixels(y1), to_pixels(x2), to_pixels(y2), to_pixels(x3), to_pixels(y3), to_pixels(x4), to_pixels(y4));
}

void graphics::draw_beziers(const pen& pen, std::vector<xtd::drawing::point>& points) {
  if (points.size() < 4 || points.size() % 3 != 1) throw argument_exception(csf_);
  vector<point_f> beziers_points;
  for (auto pt : points)
    beziers_points.push_back(point_f(pt));
  draw_beziers(pen, beziers_points);
}

void graphics::draw_beziers(const pen& pen, std::vector<xtd::drawing::point_f>& points) {
  vector<pair<float, float>> beziers_points;
  for (auto pt: points)
    beziers_points.push_back(make_pair(pt.x(), pt.y()));
  native::graphics::draw_beziers(handle(), pen.handle(), beziers_points);
}

void graphics::draw_closed_curve(const pen& pen, std::vector<xtd::drawing::point>& points) {
  draw_closed_curve(pen, points, 0.0f);
}

void graphics::draw_closed_curve(const pen& pen, std::vector<xtd::drawing::point_f>& points) {
  draw_closed_curve(pen, points, 0.0f);
}

void graphics::draw_closed_curve(const pen& pen, std::vector<xtd::drawing::point>& points, float tension) {
  vector<point_f> close_curve_points;
  for (auto pt : points)
    close_curve_points.push_back(point_f(pt));
  draw_closed_curve(pen, close_curve_points, tension);
}

void graphics::draw_closed_curve(const pen& pen, std::vector<xtd::drawing::point_f>& points, float tension) {
  vector<pair<float, float>> closed_curve_points;
  for (auto pt : points)
    closed_curve_points.push_back(make_pair(to_pixels(pt.x()), to_pixels(pt.y())));
  native::graphics::draw_closed_curve(handle(), pen.handle(), closed_curve_points, tension);
}

void graphics::draw_curve(const pen& pen, std::vector<xtd::drawing::point>& points) {
  draw_curve(pen, points, 0, points.size(), 0.0f);
}

void graphics::draw_curve(const pen& pen, std::vector<xtd::drawing::point_f>& points) {
  draw_curve(pen, points, 0, points.size(), 0.0f);
}

void graphics::draw_curve(const pen& pen, std::vector<xtd::drawing::point>& points, float tension) {
  draw_curve(pen, points, 0, points.size(), tension);
}

void graphics::draw_curve(const pen& pen, std::vector<xtd::drawing::point_f>& points, float tension) {
  draw_curve(pen, points, 0, points.size(), tension);
}

void graphics::draw_curve(const pen& pen, std::vector<xtd::drawing::point>& points, size_t offset, size_t number_of_segments) {
  draw_curve(pen, points, offset, number_of_segments, 0.0f);
}

void graphics::draw_curve(const pen& pen, std::vector<xtd::drawing::point_f>& points, size_t offset, size_t number_of_segments) {
  draw_curve(pen, points, offset, number_of_segments, 0.0f);
}

void graphics::draw_curve(const pen& pen, std::vector<xtd::drawing::point>& points, size_t offset, size_t number_of_segments, float tension) {
  vector<point_f> curve_points;
  for (auto pt : points)
    curve_points.push_back(point_f(pt));
  draw_curve(pen, curve_points, offset, number_of_segments, tension);
}

void graphics::draw_curve(const pen& pen, std::vector<xtd::drawing::point_f>& points, size_t offset, size_t number_of_segments, float tension) {
  if (offset + number_of_segments > points.size() || number_of_segments == 0) throw argument_exception(csf_);
  vector<pair<float, float>> curve_points;
  for (auto index = 0U; index < number_of_segments; ++index)
    curve_points.push_back(make_pair(to_pixels(points[offset + index].x()), to_pixels(points[offset + index].y())));
  native::graphics::draw_curve(handle(), pen.handle(), curve_points, tension);
}

void graphics::draw_ellipse(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect) {
  draw_ellipse(pen, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::draw_ellipse(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect) {
  draw_ellipse(pen, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::draw_ellipse(const pen& pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  draw_ellipse(pen, as<float>(x), as<float>(y), as<float>(width), as<float>(height));
}

void graphics::draw_ellipse(const xtd::drawing::pen& pen, float x, float y, float width, float height) {
  native::graphics::draw_ellipse(handle(), pen.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height));
}

void graphics::draw_icon(const xtd::drawing::icon& icon, int32_t x, int32_t y) {
  draw_image(icon.to_bitmap(), x, y);
}

void graphics::draw_icon(const xtd::drawing::icon& icon, const xtd::drawing::rectangle& rect) {
  draw_image(icon.to_bitmap(), rect);
}

void graphics::draw_icon_unstretched(const xtd::drawing::icon& icon, const xtd::drawing::rectangle& rect) {
  draw_image_unscaled(icon.to_bitmap(), rect.x(), rect.y());
}

void graphics::draw_image(const xtd::drawing::image& image, const xtd::drawing::rectangle& rect) {
  draw_image(image, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::draw_image(const xtd::drawing::image& image, const xtd::drawing::rectangle_f& rect) {
  draw_image(image, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::draw_image(const xtd::drawing::image& image, const xtd::drawing::point& point) {
  draw_image(image, point.x(), point.y());
}

void graphics::draw_image(const xtd::drawing::image& image, const xtd::drawing::point_f& point) {
  draw_image(image, point.x(), point.y());
}

void graphics::draw_image(const xtd::drawing::image& image, int32_t x, int32_t y, int32_t width, int32_t height) {
  draw_image(image, as<float>(x), as<float>(y), as<float>(width), as<float>(height));
}

void graphics::draw_image(const xtd::drawing::image& image, float x, float y, float width, float height) {
  if (size_f(width, height) == size_f(image.size()))  native::graphics::draw_image(handle(), image.handle(), to_pixels(x), to_pixels(y));
  else native::graphics::draw_image(handle(), bitmap(image, size(as<int32_t>(to_pixels(width)), as<int32_t>(to_pixels(height)))).handle(), to_pixels(x), to_pixels(y));
}

void graphics::draw_image(const image& image, int32_t x, int32_t y) {
  draw_image(image, x, y, image.size().width(), image.size().height());
}

void graphics::draw_image(const xtd::drawing::image& image, float x, float y) {
  draw_image(image, as<int32_t>(x), as<int32_t>(y));
}

void graphics::draw_image_unscaled(const xtd::drawing::image& image, const xtd::drawing::point& point) {
  draw_image_unscaled(image, point.x(), point.y());
}

void graphics::draw_image_unscaled(const xtd::drawing::image& image, int32_t x, int32_t y) {
  draw_image(image, x, y);
}

void graphics::draw_image_unscaled(const xtd::drawing::image& image, const xtd::drawing::rectangle& rect) {
  draw_image_unscaled(image, rect.x(), rect.y());
}

void graphics::draw_image_unscaled(const xtd::drawing::image& image, int32_t x, int32_t y, int32_t width, int32_t height) {
  draw_image_unscaled(image, x, y);
}

void graphics::draw_image_unscaled_and_clipped(const xtd::drawing::image& image, const xtd::drawing::rectangle& rect) {
  auto backup_clip = clip();
  clip(region(rect));
  draw_image_unscaled(image, rect.x(), rect.y());
  clip(backup_clip);
}

void graphics::draw_image_disabled(const image& image, float x, float y, float brightness) {
  native::graphics::draw_image_disabled(handle(), image.handle(), to_pixels(x), to_pixels(y), brightness);
}

void graphics::draw_line(const xtd::drawing::pen& pen, const xtd::drawing::point& pt1, const point& pt2) {
  draw_line(pen, pt1.x(), pt1.y(), pt2.x(), pt2.y());
}

void graphics::draw_line(const xtd::drawing::pen& pen, const xtd::drawing::point_f& pt1, const point_f& pt2) {
  draw_line(pen, pt1.x(), pt1.y(), pt2.x(), pt2.y());
}

void graphics::draw_line(const pen& pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
  draw_line(pen, as<float>(x1), as<float>(y1), as<float>(x2), as<float>(y2));
}

void graphics::draw_line(const xtd::drawing::pen& pen, float x1, float y1, float x2, float y2) {
  native::graphics::draw_line(handle(), pen.handle(), to_pixels(x1), to_pixels(y1), to_pixels(x2), to_pixels(y2));
}

void graphics::draw_lines(const xtd::drawing::pen& pen, const std::vector<xtd::drawing::point>& points) {
  vector<point_f> lines_points;
  for (auto pt : points)
    lines_points.push_back(point_f(pt));
  draw_lines(pen, lines_points);
}

void graphics::draw_lines(const xtd::drawing::pen& pen, const std::vector<xtd::drawing::point_f>& points) {
  vector<pair<float, float>> line_points;
  for (auto pt: points)
    line_points.push_back(make_pair(to_pixels(pt.x()), to_pixels(pt.y())));
  native::graphics::draw_lines(handle(), pen.handle(), line_points);
}

void graphics::draw_path(const xtd::drawing::pen& pen, const xtd::drawing::drawing2d::graphics_path&path) {
  native::graphics::draw_path(handle(), pen.handle(), path.handle());
}

void graphics::draw_pie(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle) {
  draw_pie(pen, as<float>(rect.x()), as<float>(rect.y()), as<float>(rect.width()), as<float>(rect.height()), start_angle, sweep_angle);
}

void graphics::draw_pie(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle) {
  draw_pie(pen, rect.x(), rect.y(), rect.width(), rect.height(), start_angle, sweep_angle);
}

void graphics::draw_pie(const xtd::drawing::pen& pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  draw_pie(pen, as<float>(x), as<float>(y), as<float>(width), as<float>(height), as<float>(start_angle), as<float>(sweep_angle));
}

void graphics::draw_pie(const xtd::drawing::pen& pen, float x, float y, float width, float height, float start_angle, float sweep_angle) {
  native::graphics::draw_pie(handle(), pen.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height), start_angle, sweep_angle);
}

void graphics::draw_polygon(const xtd::drawing::pen& pen, const std::vector<xtd::drawing::point>& points) {
  vector<point_f> lines_points;
  for (auto pt : points)
    lines_points.push_back(point_f(pt));
  draw_polygon(pen, lines_points);
}

void graphics::draw_polygon(const xtd::drawing::pen& pen, const std::vector<xtd::drawing::point_f>& points) {
  vector<pair<float, float>> line_points;
  for (auto pt: points)
    line_points.push_back(make_pair(to_pixels(pt.x()), to_pixels(pt.y())));
  native::graphics::draw_polygon(handle(), pen.handle(), line_points);
}

void graphics::draw_point(const xtd::drawing::pen& pen, const xtd::drawing::point& point) {
  draw_point(pen, point.x(), point.y());
}

void graphics::draw_point(const xtd::drawing::pen& pen, const xtd::drawing::point_f& point) {
  draw_point(pen, point.x(), point.y());
}

void graphics::draw_point(const xtd::drawing::pen& pen, int32_t x, int32_t y) {
  draw_point(pen, as<float>(x), as<float>(y));
}

void graphics::draw_point(const xtd::drawing::pen& pen, float x, float y) {
  fill_ellipse(*pen.brush(), x, y, pen.width(), pen.width());
}

void graphics::draw_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect) {
  draw_rectangle(pen, rect.x(), rect.y(), rect.width(), rect.height());
}
void graphics::draw_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect) {
  draw_rectangle(pen, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::draw_rectangle(const pen& pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  draw_rectangle(pen, as<float>(x), as<float>(y), as<float>(width), as<float>(height));
}

void graphics::draw_rectangle(const xtd::drawing::pen& pen, float x, float y, float width, float height) {
  native::graphics::draw_rectangle(handle(), pen.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height));
}

void graphics::draw_rectangles(const xtd::drawing::pen& pen, const std::vector<xtd::drawing::rectangle>& rects) {
  vector<rectangle_f> rectangles;
  for (auto rect : rects)
    rectangles.push_back(rectangle_f(rect));
  draw_rectangles(pen, rectangles);
}

void graphics::draw_rectangles(const xtd::drawing::pen& pen, const std::vector<xtd::drawing::rectangle_f>& rects) {
  vector<tuple<float, float, float, float>> rectangles;
  for (auto rect: rects)
    rectangles.push_back(make_tuple(to_pixels(rect.x()), to_pixels(rect.y()), to_pixels(rect.width()), to_pixels(rect.height())));
  native::graphics::draw_rectangles(handle(), pen.handle(), rectangles);
}

void graphics::draw_rounded_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect, int32_t radius) {
  draw_rounded_rectangle(pen, rect.x(), rect.y(), rect.width(), rect.height(), radius);
}

void graphics::draw_rounded_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect, float radius) {
  draw_rounded_rectangle(pen, rect.x(), rect.y(), rect.width(), rect.height(), radius);
}

void graphics::draw_rounded_rectangle(const pen& pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t radius) {
  draw_rounded_rectangle(pen, as<float>(x), as<float>(y), as<float>(width), as<float>(height), as<float>(radius));
}

void graphics::draw_rounded_rectangle(const xtd::drawing::pen& pen, float x, float y, float width, float height, float radius) {
  native::graphics::draw_rounded_rectangle(handle(), pen.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height), to_pixels(radius));
}

void graphics::draw_string(const ustring& s, const font& font, const brush& brush, const rectangle_f& layout_rectangle, const string_format& format) {
  if (dynamic_cast<const solid_brush*>(&brush) != nullptr) {
    auto text_size = measure_string(s, font);
    auto y = layout_rectangle.y();
    auto height = layout_rectangle.height();
    
    if (format.line_alignment() == string_alignment::center) {
      y += (layout_rectangle.height() - text_size.height()) / 2;
      height -= (layout_rectangle.height() - text_size.height()) / 2;
    } else  if (format.line_alignment() == string_alignment::far) {
      y += (layout_rectangle.height() - text_size.height());
      height -= (layout_rectangle.height() - text_size.height());
    }
    
    auto lines = s.split({'\n'});
    for (auto line : lines) {
      if (line.empty()) line = " ";
      vector<size_t> hotkey_prefix_locations;
      string line_without_hotkey_prefix = get_hotkey_prefix_locations(line, hotkey_prefix_locations);
      auto drawable_line = format.hotkey_prefix() == hotkey_prefix::none ? line : line_without_hotkey_prefix;
      auto x = layout_rectangle.x();
      auto width = layout_rectangle.width();
      auto line_size = measure_string(drawable_line, font);
      if (format.alignment() == string_alignment::center) {
        x += (layout_rectangle.width() - line_size.width()) / 2;
        width -= (layout_rectangle.width() - line_size.width()) / 2;
      } else  if (format.alignment() == string_alignment::far) {
        x += (layout_rectangle.width() - line_size.width());
        width -= (layout_rectangle.width() - line_size.width());
      }
      
      if (format.hotkey_prefix() != hotkey_prefix::show) native::graphics::draw_string(handle(), drawable_line, font.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height), as<const solid_brush&>(brush).color().a(), as<const solid_brush&>(brush).color().r(), as<const solid_brush&>(brush).color().g(), as<const solid_brush&>(brush).color().b());
      else {
        /*
         for (auto index  = 0; index <hotkey_prefix_locations.size(); ++index) {
         g.draw_string(text_without_hotkey_prefix.substring(hotkey_prefix_locations[index], 1), xtd::drawing::font(font, font_style::underline), solid_brush(text_color), button_rect, to_string_format(flags));
         auto chunk_size = (index+1 < hotkey_prefix_locations.size() ? hotkey_prefix_locations[index+1] : text_without_hotkey_prefix.size()) - hotkey_prefix_locations[index] - 1;
         g.draw_string(text_without_hotkey_prefi.substring(hotkey_prefix_locations[index], chunk_size), font, solid_brush(text_color), button_rect, to_string_format(flags));
         }
         */
        native::graphics::draw_string(handle(), drawable_line, font.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height), as<const solid_brush&>(brush).color().a(), as<const solid_brush&>(brush).color().r(), as<const solid_brush&>(brush).color().g(), as<const solid_brush&>(brush).color().b());
      }
      
      y += line_size.height();
    }
  }
}

void graphics::draw_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& layout_rectangle) {
  draw_string(s, font, brush, layout_rectangle, string_format());
}

void graphics::draw_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::point_f& point, const string_format& format) {
  draw_string(s, font, brush, point.x(), point.y(), format);
}

void graphics::draw_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::point_f& point) {
  draw_string(s, font, brush, point.x(), point.y(), string_format());
}

void graphics::draw_string(const ustring& s, const font& font, const brush& brush, float x, float y, const string_format& format) {
  if (dynamic_cast<const solid_brush*>(&brush) != nullptr)
    native::graphics::draw_string(handle(), s, font.handle(), to_pixels(x), to_pixels(y), as<const solid_brush&>(brush).color().a(), as<const solid_brush&>(brush).color().r(), as<const solid_brush&>(brush).color().g(), as<const solid_brush&>(brush).color().b());
}

void graphics::draw_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, float x, float y) {
  draw_string(s, font, brush, x, y, string_format());
}

void graphics::exclude_clip(const xtd::drawing::region& region) {
  data_->clip.exclude(region);
  native::graphics::clip(handle(), data_->clip.handle());
}

void graphics::exclude_clip(const xtd::drawing::rectangle& rect) {
  exclude_clip(xtd::drawing::region(rect));
}

void graphics::exclude_clip(const xtd::drawing::rectangle_f& rect) {
  exclude_clip(xtd::drawing::region(rect));
}

void graphics::fill_closed_curve(const xtd::drawing::brush& brush, std::vector<xtd::drawing::point>& points) {
  fill_closed_curve(brush, points, drawing2d::fill_mode::alternate, 0.0f);
}

void graphics::fill_closed_curve(const xtd::drawing::brush& brush, std::vector<xtd::drawing::point_f>& points) {
  fill_closed_curve(brush, points, drawing2d::fill_mode::alternate, 0.0f);
}

void graphics::fill_closed_curve(const xtd::drawing::brush& brush, std::vector<xtd::drawing::point>& points, xtd::drawing::drawing2d::fill_mode fill_mode) {
  fill_closed_curve(brush, points, fill_mode, 0.0f);
}

void graphics::fill_closed_curve(const xtd::drawing::brush& brush, std::vector<xtd::drawing::point_f>& points, xtd::drawing::drawing2d::fill_mode fill_mode) {
  fill_closed_curve(brush, points, fill_mode, 0.0f);
}

void graphics::fill_closed_curve(const xtd::drawing::brush& brush, std::vector<xtd::drawing::point>& points, xtd::drawing::drawing2d::fill_mode fill_mode, float tension) {
  vector<point_f> close_curve_points;
  for (auto pt : points)
    close_curve_points.push_back(point_f(pt));
  fill_closed_curve(brush, close_curve_points, fill_mode, tension);
}

void graphics::fill_closed_curve(const xtd::drawing::brush& brush, std::vector<xtd::drawing::point_f>& points, xtd::drawing::drawing2d::fill_mode fill_mode, float tension) {
  vector<pair<float, float>> closed_curve_points;
  for (auto pt : points)
    closed_curve_points.push_back(make_pair(to_pixels(pt.x()), to_pixels(pt.y())));
  native::graphics::fill_closed_curve(handle(), brush.handle(), closed_curve_points, static_cast<int32_t>(fill_mode), tension);
}

void graphics::fill_ellipse(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect) {
  fill_ellipse(brush, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::fill_ellipse(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect) {
  fill_ellipse(brush, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::fill_ellipse(const brush& brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  fill_ellipse(brush, as<float>(x), as<float>(y), as<float>(width), as<float>(height));
}

void graphics::fill_ellipse(const xtd::drawing::brush& brush, float x, float y, float width, float height) {
  native::graphics::fill_ellipse(handle(), brush.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height));
}

void graphics::fill_path(const brush& brush, const drawing2d::graphics_path& path) {
  native::graphics::fill_path(handle(), brush.handle(), path.handle(), static_cast<int32_t>(path.fill_mode()));
}

void graphics::fill_pie(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle) {
  fill_pie(brush, as<float>(rect.x()), as<float>(rect.y()), as<float>(rect.width()), as<float>(rect.height()), start_angle, sweep_angle);
}

void graphics::fill_pie(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle) {
  fill_pie(brush, rect.x(), rect.y(), rect.width(), rect.height(), start_angle, sweep_angle);
}

void graphics::fill_pie(const brush& brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  fill_pie(brush, as<float>(x), as<float>(y), as<float>(width), as<float>(height), as<float>(start_angle), as<float>(sweep_angle));
}

void graphics::fill_pie(const xtd::drawing::brush& brush, float x, float y, float width, float height, float start_angle, float sweep_angle) {
  native::graphics::fill_pie(handle(), brush.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height), start_angle, sweep_angle);
}

void graphics::fill_polygon(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point>& points) {
  fill_polygon(brush, points, drawing2d::fill_mode::alternate);
}

void graphics::fill_polygon(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point_f>& points) {
  fill_polygon(brush, points, drawing2d::fill_mode::alternate);
}

void graphics::fill_polygon(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point>& points, xtd::drawing::drawing2d::fill_mode fill_mode) {
  vector<point_f> lines_points;
  for (auto pt : points)
    lines_points.push_back(point_f(pt));
  fill_polygon(brush, lines_points);
}

void graphics::fill_polygon(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point_f>& points, xtd::drawing::drawing2d::fill_mode fill_mode) {
  vector<pair<float, float>> line_points;
  for (auto pt: points)
    line_points.push_back(make_pair(to_pixels(pt.x()), to_pixels(pt.y())));
  native::graphics::fill_polygon(handle(), brush.handle(), line_points, static_cast<int32_t>(fill_mode));
}

void graphics::fill_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect) {
  fill_rectangle(brush, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::fill_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect) {
  fill_rectangle(brush, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::fill_rectangle(const brush& brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  fill_rectangle(brush, as<float>(x), as<float>(y), as<float>(width), as<float>(height));
}

void graphics::fill_rectangle(const xtd::drawing::brush& brush, float x, float y, float width, float height) {
  native::graphics::fill_rectangle(handle(), brush.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height));
}

void graphics::fill_rectangles(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::rectangle>& rects) {
  vector<rectangle_f> rectangles;
  for (auto rect : rects)
    rectangles.push_back(rectangle_f(rect));
  fill_rectangles(brush, rectangles);
}

void graphics::fill_rectangles(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::rectangle_f>& rects) {
  vector<tuple<float, float, float, float>> rectangles;
  for (auto rect: rects)
    rectangles.push_back(make_tuple(to_pixels(rect.x()), to_pixels(rect.y()), to_pixels(rect.width()), to_pixels(rect.height())));
  native::graphics::fill_rectangles(handle(), brush.handle(), rectangles);
}

void graphics::fill_region(const xtd::drawing::brush& brush, const xtd::drawing::region& region) {
  native::graphics::fill_region(handle(), brush.handle(), region.handle());
}

void graphics::fill_rounded_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect, int32_t radius) {
  fill_rounded_rectangle(brush, rect.x(), rect.y(), rect.width(), rect.height(), radius);
}

void graphics::fill_rounded_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect, float radius) {
  fill_rounded_rectangle(brush, rect.x(), rect.y(), rect.width(), rect.height(), radius);
}

void graphics::fill_rounded_rectangle(const brush& brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t radius) {
  fill_rounded_rectangle(brush, as<float>(x), as<float>(y), as<float>(width), as<float>(height), as<float>(radius));
}

void graphics::fill_rounded_rectangle(const xtd::drawing::brush& brush, float x, float y, float width, float height, float radius) {
  native::graphics::fill_rounded_rectangle(handle(), brush.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height), to_pixels(radius));
}

void graphics::flush() {
  flush(xtd::drawing::drawing2d::flush_intention::flush);
}

void graphics::flush(xtd::drawing::drawing2d::flush_intention intention) {
  native::graphics::flush(handle(), static_cast<int32_t>(intention));
}

graphics graphics::from_hdc(intptr_t hdc) {
  return graphics(native::graphics::from_hdc(hdc));
}

graphics graphics::from_hdc(intptr_t hdc, intptr_t hdevice) {
  return graphics(native::graphics::from_hdc(hdc, hdevice));
}

graphics graphics::from_hwnd(intptr_t hwnd) {
  return graphics(native::graphics::from_hwnd(hwnd));
}

graphics graphics::from_image(const image& image) {
  return graphics(native::graphics::from_image(image.handle()));
}

intptr_t graphics::get_hdc() const {
  return native::graphics::get_hdc(handle());
}

xtd::drawing::color graphics::get_nearest_color(const xtd::drawing::color& color) const {
  uint8_t a, r, g, b;
  native::graphics::get_nearest_color(handle(), color.a(), color.r(), color.g(), color.b(), a, r, g, b);
  return xtd::drawing::color::from_argb(a, r, g, b);
}

void graphics::intersect_clip(const xtd::drawing::region& region) {
  data_->clip.intersect(region);
  native::graphics::clip(handle(), data_->clip.handle());
}

void graphics::intersect_clip(const xtd::drawing::rectangle& rect) {
  intersect_clip(xtd::drawing::region(rect));
}

void graphics::intersect_clip(const xtd::drawing::rectangle_f& rect) {
  intersect_clip(xtd::drawing::region(rect));
}

size_f graphics::measure_string(const ustring& text, const font& font) {
  float width = 0.0f;
  float height = 0.0f;
  native::graphics::measure_string(handle(), text, font.handle(), width, height);
  return size_f(to_page_unit(width), to_page_unit(height));
}

void graphics::rotate_transform(float angle) {
  native::graphics::rotate_transform(handle(), angle);
}

void graphics::translate_clip(int32_t dx, int32_t dy) {
  translate_clip(as<float>(dx), as<float>(dy));
}

void graphics::translate_clip(float dx, float dy) {
  native::graphics::translate_clip(handle(), to_pixels(dx), to_pixels(dy));
}

float graphics::to_page_unit(float value) const {
  return to_page_unit(value, data_->page_unit, data_->page_scale, dpi_x());
}

float graphics::to_page_unit(float value, graphics_unit page_unit, float page_scale, float dpi) {
  switch (page_unit) {
    case graphics_unit::world:
    case graphics_unit::display:
    case graphics_unit::pixel: return value * page_scale;
    case graphics_unit::point: return value / 96.0f * dpi * page_scale;
    case graphics_unit::inch: return value / 96.0f * dpi * page_scale;
    case graphics_unit::document: return value / 96.0f * 300.0f * dpi * page_scale;
    case graphics_unit::millimeter: return value / 96.0f * 25.4f * dpi * page_scale;
    default: return value;
  }
}

float graphics::to_pixels(float value) const {
  return to_pixels(value, data_->page_unit, data_->page_scale, dpi_x());
}

float graphics::to_pixels(float value, graphics_unit page_unit, float page_scale, float dpi) {
  switch (page_unit) {
    case graphics_unit::world:
    case graphics_unit::display:
    case graphics_unit::pixel: return value / page_scale;
    case graphics_unit::point: return value * 96.0f / dpi / page_scale;
    case graphics_unit::inch: return value * 96.0f / dpi / page_scale;
    case graphics_unit::document: return value * 96.0f / 300.0f / dpi / page_scale;
    case graphics_unit::millimeter: return value * 96.0f / 25.4f / dpi / page_scale;
    default: return value;
  }
}
