#include "../../../include/xtd/drawing/bitmap.h"
#include "../../../include/xtd/drawing/icon.h"
#include "../../../include/xtd/drawing/graphics.h"
#include "../../../include/xtd/drawing/solid_brush.h"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/graphics>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <xtd/as>
#include <xtd/int32_object>
#include <xtd/single_object>
#include <xtd/math>
#include <vector>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;

struct graphics::data {
  xtd::drawing::region clip;
  xtd::drawing::drawing_2d::compositing_mode compositing_mode = xtd::drawing::drawing_2d::compositing_mode::source_over;
  xtd::drawing::drawing_2d::compositing_quality compositing_quality = xtd::drawing::drawing_2d::compositing_quality::default_value;
  intptr handle = 0;
  xtd::drawing::drawing_2d::interpolation_mode interpolation_mode = xtd::drawing::drawing_2d::interpolation_mode::default_value;
  float page_scale = 1.0f;
  xtd::drawing::graphics_unit page_unit = xtd::drawing::graphics_unit::pixel;
  xtd::drawing::drawing_2d::pixel_offset_mode pixel_offset_mode = xtd::drawing::drawing_2d::pixel_offset_mode::default_value;
  xtd::drawing::drawing_2d::smoothing_mode smoothing_mode = xtd::drawing::drawing_2d::smoothing_mode::default_value;
  xtd::drawing::text::text_rendering_hint text_rendering_hint = xtd::drawing::text::text_rendering_hint::system_default;
  int32 text_contrast = 4;
};

graphics::graphics(intptr handle) : data_(std::make_shared<data>()) {
  data_->handle = handle;
}

graphics::graphics(intptr handle, const drawing::region& region) : data_(std::make_shared<data>()) {
  data_->handle = handle;
  if (!region.is_empty() && !region.is_infinite())
    clip(region);
}

graphics::graphics(const graphics& value) : data_(std::make_shared<data>()) {
  if (data_.use_count() == 1 && handle() != 0) native::graphics::destroy(handle());
  data_ = value.data_;
}

graphics& graphics::operator =(const graphics& value) {
  if (data_.use_count() == 1 && handle() != 0) native::graphics::destroy(handle());
  data_ = value.data_;
  return *this;
}

graphics::~graphics() {
  if (data_.use_count() == 1 && handle() != 0) native::graphics::destroy(handle());
}

region graphics::clip() const noexcept {
  return data_->clip;
}

graphics& graphics::clip(const xtd::drawing::region value) {
  if (data_->clip == value) return *this;
  data_->clip = value;
  native::graphics::clip(handle(), data_->clip.handle());
  return *this;
}

rectangle_f graphics::clip_bounds() const noexcept {
  auto rect_pixels = data_->clip.get_bounds(*this);
  return rectangle_f(to_page_unit(rect_pixels.x()), to_page_unit(rect_pixels.y()), to_page_unit(rect_pixels.width()), to_page_unit(rect_pixels.height()));
}

xtd::drawing::drawing_2d::compositing_mode graphics::compositing_mode() const noexcept {
  return data_->compositing_mode;
}

graphics& graphics::compositing_mode(xtd::drawing::drawing_2d::compositing_mode value) {
  if (data_->compositing_mode == value) return *this;
  data_->compositing_mode = value;
  if (data_->text_rendering_hint == xtd::drawing::text::text_rendering_hint::clear_type_grid_fit && data_->compositing_mode == xtd::drawing::drawing_2d::compositing_mode::source_copy) throw argument_exception {csf_};
  native::graphics::compositing_mode(handle(), static_cast<int32>(data_->compositing_mode));
  return *this;
}

xtd::drawing::drawing_2d::compositing_quality graphics::compositing_quality() const noexcept {
  return data_->compositing_quality;
}

graphics& graphics::compositing_quality(xtd::drawing::drawing_2d::compositing_quality value) {
  if (data_->compositing_quality == value) return *this;
  data_->compositing_quality = value;
  native::graphics::compositing_quality(handle(), static_cast<int32>(data_->compositing_quality));
  return *this;
}

float graphics::dpi_x() const noexcept {
  return native::graphics::get_dpi_x(handle());
}

float graphics::dpi_y() const noexcept {
  return native::graphics::get_dpi_y(handle());
}

intptr graphics::handle() const noexcept {
  return data_->handle;
}

xtd::drawing::drawing_2d::interpolation_mode graphics::interpolation_mode() const noexcept {
  return data_->interpolation_mode;
}

graphics& graphics::interpolation_mode(xtd::drawing::drawing_2d::interpolation_mode value) noexcept {
  if (data_->interpolation_mode == value) return *this;
  data_->interpolation_mode = value;
  native::graphics::interpolation_mode(handle(), static_cast<int32>(data_->interpolation_mode));
  return *this;
}

float graphics::page_scale() const noexcept {
  return data_->page_scale;
}

graphics& graphics::page_scale(float value) noexcept {
  data_->page_scale = value;
  return *this;
}

xtd::drawing::graphics_unit graphics::page_unit() const noexcept {
  return data_->page_unit;
}
graphics& graphics::page_unit(xtd::drawing::graphics_unit value) {
  if (value == graphics_unit::world) throw argument_exception {csf_};
  data_->page_unit = value;
  return *this;
}

xtd::drawing::drawing_2d::pixel_offset_mode graphics::pixel_offset_mode() const noexcept {
  return data_->pixel_offset_mode;
}

graphics& graphics::pixel_offset_mode(xtd::drawing::drawing_2d::pixel_offset_mode value) noexcept {
  if (data_->pixel_offset_mode == value)  return *this;
  data_->pixel_offset_mode = value;
  native::graphics::pixel_offset_mode(handle(), static_cast<int32>(data_->pixel_offset_mode));
  return *this;
}

xtd::drawing::drawing_2d::smoothing_mode graphics::smoothing_mode() const noexcept {
  return data_->smoothing_mode;
}
graphics& graphics::smoothing_mode(xtd::drawing::drawing_2d::smoothing_mode value) noexcept {
  if (data_->smoothing_mode == value) return *this;
  data_->smoothing_mode = value;
  native::graphics::smoothing_mode(handle(), static_cast<int32>(data_->smoothing_mode));
  return *this;
}

int32 graphics::text_contrast() const noexcept {
  return data_->text_contrast;
}

graphics& graphics::text_contrast(int32 value) noexcept {
  if (data_->text_contrast == value) return *this;
  data_->text_contrast = value;
  native::graphics::text_contrast(handle(), data_->text_contrast);
  return *this;
}

xtd::drawing::text::text_rendering_hint graphics::text_rendering_hint() const noexcept {
  return data_->text_rendering_hint;
}

graphics& graphics::text_rendering_hint(xtd::drawing::text::text_rendering_hint value) {
  if (data_->text_rendering_hint == value) return *this;
  data_->text_rendering_hint = value;
  if (data_->text_rendering_hint == xtd::drawing::text::text_rendering_hint::clear_type_grid_fit && data_->compositing_mode == xtd::drawing::drawing_2d::compositing_mode::source_copy) throw argument_exception {csf_};
  native::graphics::text_rendering_hint(handle(), static_cast<int32>(data_->text_rendering_hint));
  return *this;
}

xtd::drawing::drawing_2d::matrix graphics::transform() const noexcept {
  return matrix(native::graphics::transform(handle()));
}

graphics& graphics::transform(const xtd::drawing::drawing_2d::matrix& value) noexcept {
  native::graphics::transform(handle(), value.handle());
  return *this;
}

rectangle_f graphics::visible_clip_bounds() const noexcept {
  auto x = 0.0f, y = 0.0f, width = 0.0f, height = 0.0f;
  native::graphics::visible_clip_bounds(handle(), x, y, width, height);
  return {to_page_unit(x), to_page_unit(y), to_page_unit(width), to_page_unit(height)};
}

void graphics::clear(const color& color) {
  native::graphics::clear(handle(), color.a(), color.r(), color.g(), color.b());
}

void graphics::copy_from_graphics(const graphics& source, const xtd::drawing::point& upper_left_source, const xtd::drawing::point& upper_left_destination, const xtd::drawing::size& block_region_size) {
  copy_from_graphics(source, upper_left_source.x(), upper_left_source.y(), upper_left_destination.x(), upper_left_destination.y(), block_region_size, xtd::drawing::copy_pixel_operation::source_copy);
}

void graphics::copy_from_graphics(const graphics& source, const xtd::drawing::point& upper_left_source, const xtd::drawing::point& upper_left_destination, const xtd::drawing::size& block_region_size, xtd::drawing::copy_pixel_operation copy_pixel_operation) {
  copy_from_graphics(source, upper_left_source.x(), upper_left_source.y(), upper_left_destination.x(), upper_left_destination.y(), block_region_size, copy_pixel_operation);
}

void graphics::copy_from_graphics(const graphics& source, int32 source_x, int32 source_y, int32 destination_x, int32 destination_y, const xtd::drawing::size& block_region_size) {
  copy_from_graphics(source, source_x, source_y, destination_x, destination_y, block_region_size, xtd::drawing::copy_pixel_operation::source_copy);
}

void graphics::copy_from_graphics(const graphics& source, int32 source_x, int32 source_y, int32 destination_x, int32 destination_y, const xtd::drawing::size& block_region_size, xtd::drawing::copy_pixel_operation copy_pixel_operation) {
  native::graphics::copy_from_graphics(handle(), source.handle(), to_pixels(source_x), to_pixels(source_y), to_pixels(destination_x), to_pixels(destination_y), to_pixels(block_region_size.width()), to_pixels(block_region_size.height()), static_cast<int32>(copy_pixel_operation));
}

void graphics::copy_from_screen(const xtd::drawing::point& upper_left_source, const xtd::drawing::point& upper_left_destination, const xtd::drawing::size& block_region_size) {
  copy_from_screen(upper_left_source.x(), upper_left_source.y(), upper_left_destination.x(), upper_left_destination.y(), block_region_size, xtd::drawing::copy_pixel_operation::source_copy);
}

void graphics::copy_from_screen(const xtd::drawing::point& upper_left_source, const xtd::drawing::point& upper_left_destination, const xtd::drawing::size& block_region_size, xtd::drawing::copy_pixel_operation copy_pixel_operation) {
  copy_from_screen(upper_left_source.x(), upper_left_source.y(), upper_left_destination.x(), upper_left_destination.y(), block_region_size, copy_pixel_operation);
}

void graphics::copy_from_screen(int32 source_x, int32 source_y, int32 destination_x, int32 destination_y, const xtd::drawing::size& block_region_size) {
  copy_from_screen(source_x, source_y, destination_x, destination_y, block_region_size, xtd::drawing::copy_pixel_operation::source_copy);
}

void graphics::copy_from_screen(int32 source_x, int32 source_y, int32 destination_x, int32 destination_y, const xtd::drawing::size& block_region_size, xtd::drawing::copy_pixel_operation copy_pixel_operation) {
  native::graphics::copy_from_screen(handle(), to_pixels(source_x), to_pixels(source_y), to_pixels(destination_x), to_pixels(destination_y), to_pixels(block_region_size.width()), to_pixels(block_region_size.height()), static_cast<int32>(copy_pixel_operation));
}

void graphics::draw_arc(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle) {
  draw_arc(pen, rectangle_f(rect), start_angle, sweep_angle);
}

void graphics::draw_arc(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle) {
  draw_arc(pen, rect.x(), rect.y(), rect.width(), rect.height(), start_angle, sweep_angle);
}

void graphics::draw_arc(const pen& pen, int32 x, int32 y, int32 width, int32 height, int32 start_angle, int32 sweep_angle) {
  if (width < 0 || height < 0) throw argument_exception {csf_};
  if (start_angle < 0 || start_angle > 360) throw argument_exception {csf_};
  if (sweep_angle < 0 || sweep_angle > 360) throw argument_exception {csf_};
  draw_arc(pen, as<float>(x), as<float>(y), as<float>(width), as<float>(height), as<float>(start_angle), as<float>(sweep_angle));
}

void graphics::draw_arc(const xtd::drawing::pen& pen, float x, float y, float width, float height, float start_angle, float sweep_angle) {
  if (width < 0 || height < 0) throw argument_exception {csf_};
  if (start_angle < 0 || start_angle > 360) throw argument_exception {csf_};
  if (sweep_angle < 0 || sweep_angle > 360) throw argument_exception {csf_};
  native::graphics::draw_arc(handle(), pen.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height), start_angle, sweep_angle);
}

void graphics::draw_bezier(const xtd::drawing::pen& pen, const xtd::drawing::point& pt1, const xtd::drawing::point& pt2, const xtd::drawing::point& pt3, const xtd::drawing::point& pt4) {
  draw_bezier(pen, pt1.x(), pt1.y(), pt2.x(), pt2.y(), pt3.x(), pt3.y(), pt4.x(), pt4.y());
}

void graphics::draw_bezier(const xtd::drawing::pen& pen, const xtd::drawing::point_f& pt1, const xtd::drawing::point_f& pt2, const xtd::drawing::point_f& pt3, const xtd::drawing::point_f& pt4) {
  draw_bezier(pen, pt1.x(), pt1.y(), pt2.x(), pt2.y(), pt3.x(), pt3.y(), pt4.x(), pt4.y());
}

void graphics::draw_bezier(const pen& pen, int32 x1, int32 y1, int32 x2, int32 y2, int32 x3, int32 y3, int32 x4, int32 y4) {
  draw_bezier(pen, as<float>(x1), as<float>(y1), as<float>(x2), as<float>(y2), as<float>(x3), as<float>(y3), as<float>(x4), as<float>(y4));
}

void graphics::draw_bezier(const pen& pen, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
  native::graphics::draw_bezier(handle(), pen.handle(), to_pixels(x1), to_pixels(y1), to_pixels(x2), to_pixels(y2), to_pixels(x3), to_pixels(y3), to_pixels(x4), to_pixels(y4));
}

void graphics::draw_beziers(const pen& pen, const std::vector<xtd::drawing::point>& points) {
  if (points.size() < 4 || points.size() % 3 != 1) throw argument_exception {csf_};
  auto beziers_points = vector<point_f> {};
  for_each(points.begin(), points.end(), [&](auto pt) {beziers_points.push_back(point_f(pt));});
  draw_beziers(pen, beziers_points);
}

void graphics::draw_beziers(const pen& pen, const std::vector<xtd::drawing::point_f>& points) {
  auto beziers_points = vector<pair<float, float>> {};
  for_each(points.begin(), points.end(), [&](auto pt) {beziers_points.emplace_back(to_pixels(pt.x()), to_pixels(pt.y()));});
  native::graphics::draw_beziers(handle(), pen.handle(), beziers_points);
}

void graphics::draw_closed_curve(const pen& pen, const std::vector<xtd::drawing::point>& points) {
  draw_closed_curve(pen, points, 0.0f);
}

void graphics::draw_closed_curve(const pen& pen, const std::vector<xtd::drawing::point_f>& points) {
  draw_closed_curve(pen, points, 0.0f);
}

void graphics::draw_closed_curve(const pen& pen, const std::vector<xtd::drawing::point>& points, float tension) {
  auto close_curve_points = vector<point_f> {};
  for_each(points.begin(), points.end(), [&](auto pt) {close_curve_points.push_back(point_f(pt));});
  draw_closed_curve(pen, close_curve_points, tension);
}

void graphics::draw_closed_curve(const pen& pen, const std::vector<xtd::drawing::point_f>& points, float tension) {
  auto closed_curve_points = vector<pair<float, float>> {};
  for_each(points.begin(), points.end(), [&](auto pt) {closed_curve_points.emplace_back(to_pixels(pt.x()), to_pixels(pt.y()));});
  native::graphics::draw_closed_curve(handle(), pen.handle(), closed_curve_points, tension);
}

void graphics::draw_curve(const pen& pen, const std::vector<xtd::drawing::point>& points) {
  draw_curve(pen, points, 0, points.size(), 0.0f);
}

void graphics::draw_curve(const pen& pen, const std::vector<xtd::drawing::point_f>& points) {
  draw_curve(pen, points, 0, points.size(), 0.0f);
}

void graphics::draw_curve(const pen& pen, const std::vector<xtd::drawing::point>& points, float tension) {
  draw_curve(pen, points, 0, points.size(), tension);
}

void graphics::draw_curve(const pen& pen, const std::vector<xtd::drawing::point_f>& points, float tension) {
  draw_curve(pen, points, 0, points.size(), tension);
}

void graphics::draw_curve(const pen& pen, const std::vector<xtd::drawing::point>& points, size_t offset, size_t number_of_segments) {
  draw_curve(pen, points, offset, number_of_segments, 0.0f);
}

void graphics::draw_curve(const pen& pen, const std::vector<xtd::drawing::point_f>& points, size_t offset, size_t number_of_segments) {
  draw_curve(pen, points, offset, number_of_segments, 0.0f);
}

void graphics::draw_curve(const pen& pen, const std::vector<xtd::drawing::point>& points, size_t offset, size_t number_of_segments, float tension) {
  auto curve_points = vector<point_f> {};
  for_each(points.begin(), points.end(), [&](auto pt) {curve_points.push_back(point_f(pt));});
  draw_curve(pen, curve_points, offset, number_of_segments, tension);
}

void graphics::draw_curve(const pen& pen, const std::vector<xtd::drawing::point_f>& points, size_t offset, size_t number_of_segments, float tension) {
  if (offset + number_of_segments > points.size() || number_of_segments == 0) throw argument_exception {csf_};
  auto curve_points = vector<pair<float, float>> {};
  for (auto index = 0_sz; index < number_of_segments; ++index)
    curve_points.emplace_back(to_pixels(points[offset + index].x()), to_pixels(points[offset + index].y()));
  native::graphics::draw_curve(handle(), pen.handle(), curve_points, tension);
}

void graphics::draw_ellipse(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect) {
  draw_ellipse(pen, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::draw_ellipse(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect) {
  draw_ellipse(pen, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::draw_ellipse(const pen& pen, int32 x, int32 y, int32 width, int32 height) {
  draw_ellipse(pen, as<float>(x), as<float>(y), as<float>(width), as<float>(height));
}

void graphics::draw_ellipse(const xtd::drawing::pen& pen, float x, float y, float width, float height) {
  if (width < 0 || height < 0) throw argument_exception {csf_};
  native::graphics::draw_ellipse(handle(), pen.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height));
}

void graphics::draw_icon(const xtd::drawing::icon& icon, int32 x, int32 y) {
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

void graphics::draw_image(const xtd::drawing::image& image, int32 x, int32 y, int32 width, int32 height) {
  draw_image(image, as<float>(x), as<float>(y), as<float>(width), as<float>(height));
}

void graphics::draw_image(const xtd::drawing::image& image, float x, float y, float width, float height) {
  if (width < 0 || height < 0) throw argument_exception {csf_};
  native::graphics::draw_image(handle(), image.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height));
}

void graphics::draw_image(const image& image, int32 x, int32 y) {
  draw_image(image, x, y, image.size().width(), image.size().height());
}

void graphics::draw_image(const xtd::drawing::image& image, float x, float y) {
  draw_image(image, as<int32>(x), as<int32>(y));
}

void graphics::draw_image(const xtd::drawing::image& image, const xtd::drawing::rectangle& dest_rect, const xtd::drawing::rectangle& src_rect) {
  draw_image(image, dest_rect, src_rect.x(), src_rect.y(), src_rect.width(), src_rect.height());
}

void graphics::draw_image(const xtd::drawing::image& image, const xtd::drawing::rectangle_f& dest_rect, const xtd::drawing::rectangle_f& src_rect) {
  draw_image(image, dest_rect, src_rect.x(), src_rect.y(), src_rect.width(), src_rect.height());
}

void graphics::draw_image(const xtd::drawing::image& image, const xtd::drawing::point& dest_point, const xtd::drawing::rectangle& src_rect) {
  draw_image(image, dest_point, src_rect.x(), src_rect.y(), src_rect.width(), src_rect.height());
}

void graphics::draw_image(const xtd::drawing::image& image, const xtd::drawing::point_f& dest_point, const xtd::drawing::rectangle_f& src_rect) {
  draw_image(image, dest_point, src_rect.x(), src_rect.y(), src_rect.width(), src_rect.height());
}

void graphics::draw_image(const xtd::drawing::image& image, const xtd::drawing::rectangle& dest_rect, int32 src_x, int32 src_y, int32 src_width, int32 src_height) {
  draw_image(image, rectangle_f {static_cast<float>(dest_rect.x()), static_cast<float>(dest_rect.y()), static_cast<float>(dest_rect.width()), static_cast<float>(dest_rect.height())}, static_cast<float>(src_x), static_cast<float>(src_y), static_cast<float>(src_width), static_cast<float>(src_height));
}

void graphics::draw_image(const xtd::drawing::image& image, const xtd::drawing::rectangle_f& dest_rect, float src_x, float src_y, float src_width, float src_height) {
  if (dest_rect.width() <= 0 || dest_rect.height() <= 0) throw argument_exception {csf_};
  if (src_width < 0 || src_height < 0) throw argument_exception {csf_};
  native::graphics::draw_image(handle(), image.handle(), dest_rect.x(), dest_rect.y(), dest_rect.width(), dest_rect.height(), src_x, src_y, src_width, src_height);
}

void graphics::draw_image(const xtd::drawing::image& image, const xtd::drawing::point& dest_point, int32 src_x, int32 src_y, int32 src_width, int32 src_height) {
  draw_image(image, rectangle_f {static_cast<float>(dest_point.x()), static_cast<float>(dest_point.y()), static_cast<float>(image.width()), static_cast<float>(image.height())}, static_cast<float>(src_x), static_cast<float>(src_y), static_cast<float>(src_width), static_cast<float>(src_height));
}

void graphics::draw_image(const xtd::drawing::image& image, const xtd::drawing::point_f& dest_point, float src_x, float src_y, float src_width, float src_height) {
  draw_image(image, rectangle_f {dest_point.x(), dest_point.y(), static_cast<float>(image.width()), static_cast<float>(image.height())}, src_x, src_y, src_width, src_height);
}

void graphics::draw_image_unscaled(const xtd::drawing::image& image, const xtd::drawing::point& point) {
  draw_image_unscaled(image, point.x(), point.y());
}

void graphics::draw_image_unscaled(const xtd::drawing::image& image, int32 x, int32 y) {
  draw_image(image, x, y);
}

void graphics::draw_image_unscaled(const xtd::drawing::image& image, const xtd::drawing::rectangle& rect) {
  draw_image_unscaled(image, rect.x(), rect.y());
}

void graphics::draw_image_unscaled(const xtd::drawing::image& image, int32 x, int32 y, int32 width, int32 height) {
  draw_image_unscaled(image, x, y);
}

void graphics::draw_image_unscaled_and_clipped(const xtd::drawing::image& image, const xtd::drawing::rectangle& rect) {
  auto backup_clip = clip();
  clip(region(rect));
  draw_image_unscaled(image, rect.x(), rect.y());
  clip(backup_clip);
}

void graphics::draw_image_disabled(const image& image, float x, float y, float width, float height, float brightness) {
  if (width < 0 || height < 0) throw argument_exception {csf_};
  native::graphics::draw_image_disabled(handle(), image.handle(), to_pixels(x), to_pixels(y), width, height, brightness);
}

void graphics::draw_line(const xtd::drawing::pen& pen, const xtd::drawing::point& pt1, const point& pt2) {
  draw_line(pen, pt1.x(), pt1.y(), pt2.x(), pt2.y());
}

void graphics::draw_line(const xtd::drawing::pen& pen, const xtd::drawing::point_f& pt1, const point_f& pt2) {
  draw_line(pen, pt1.x(), pt1.y(), pt2.x(), pt2.y());
}

void graphics::draw_line(const pen& pen, int32 x1, int32 y1, int32 x2, int32 y2) {
  draw_line(pen, as<float>(x1), as<float>(y1), as<float>(x2), as<float>(y2));
}

void graphics::draw_line(const xtd::drawing::pen& pen, float x1, float y1, float x2, float y2) {
  native::graphics::draw_line(handle(), pen.handle(), to_pixels(x1), to_pixels(y1), to_pixels(x2), to_pixels(y2));
}

void graphics::draw_lines(const xtd::drawing::pen& pen, const std::vector<xtd::drawing::point>& points) {
  auto lines_points = vector<point_f> {};
  for_each(points.begin(), points.end(), [&](auto pt) {lines_points.push_back(point_f(pt));});
  draw_lines(pen, lines_points);
}

void graphics::draw_lines(const xtd::drawing::pen& pen, const std::vector<xtd::drawing::point_f>& points) {
  auto line_points = vector<pair<float, float>> {};
  for_each(points.begin(), points.end(), [&](auto pt) {line_points.emplace_back(to_pixels(pt.x()), to_pixels(pt.y()));});
  native::graphics::draw_lines(handle(), pen.handle(), line_points);
}

void graphics::draw_path(const xtd::drawing::pen& pen, const xtd::drawing::drawing_2d::graphics_path& path) {
  native::graphics::draw_path(handle(), pen.handle(), path.handle());
}

void graphics::draw_pie(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle) {
  draw_pie(pen, as<float>(rect.x()), as<float>(rect.y()), as<float>(rect.width()), as<float>(rect.height()), start_angle, sweep_angle);
}

void graphics::draw_pie(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle) {
  draw_pie(pen, rect.x(), rect.y(), rect.width(), rect.height(), start_angle, sweep_angle);
}

void graphics::draw_pie(const xtd::drawing::pen& pen, int32 x, int32 y, int32 width, int32 height, int32 start_angle, int32 sweep_angle) {
  draw_pie(pen, as<float>(x), as<float>(y), as<float>(width), as<float>(height), as<float>(start_angle), as<float>(sweep_angle));
}

void graphics::draw_pie(const xtd::drawing::pen& pen, float x, float y, float width, float height, float start_angle, float sweep_angle) {
  if (width < 0 || height < 0) throw argument_exception {csf_};
  if (start_angle < 0 || start_angle > 360) throw argument_exception {csf_};
  if (sweep_angle < 0 || sweep_angle > 360) throw argument_exception {csf_};
  native::graphics::draw_pie(handle(), pen.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height), start_angle, sweep_angle);
}

void graphics::draw_polygon(const xtd::drawing::pen& pen, const std::vector<xtd::drawing::point>& points) {
  auto lines_points = vector<point_f> {};
  for_each(points.begin(), points.end(), [&](auto pt) {lines_points.push_back(point_f(pt));});
  draw_polygon(pen, lines_points);
}

void graphics::draw_polygon(const xtd::drawing::pen& pen, const std::vector<xtd::drawing::point_f>& points) {
  auto line_points = vector<pair<float, float>> {};
  for_each(points.begin(), points.end(), [&](auto pt) {line_points.emplace_back(to_pixels(pt.x()), to_pixels(pt.y()));});
  native::graphics::draw_polygon(handle(), pen.handle(), line_points);
}

void graphics::draw_point(const xtd::drawing::pen& pen, const xtd::drawing::point& point) {
  draw_point(pen, point.x(), point.y());
}

void graphics::draw_point(const xtd::drawing::pen& pen, const xtd::drawing::point_f& point) {
  draw_point(pen, point.x(), point.y());
}

void graphics::draw_point(const xtd::drawing::pen& pen, int32 x, int32 y) {
  draw_point(pen, as<float>(x), as<float>(y));
}

void graphics::draw_point(const xtd::drawing::pen& pen, float x, float y) {
  if (pen.width() <= 2.0f) fill_rectangle(*pen.brush(), x + as<float>(math::floor(pen.width() / 2.0f)), y + as<float>(math::floor(pen.width() / 2.0f)), pen.width(), pen.width());
  else fill_ellipse(*pen.brush(), x + as<float>(math::floor(pen.width() / 2.0f)), y + as<float>(math::floor(pen.width() / 2.0f)), pen.width(), pen.width());
}

void graphics::draw_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect) {
  draw_rectangle(pen, rect.x(), rect.y(), rect.width(), rect.height());
}
void graphics::draw_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect) {
  draw_rectangle(pen, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::draw_rectangle(const pen& pen, int32 x, int32 y, int32 width, int32 height) {
  draw_rectangle(pen, as<float>(x), as<float>(y), as<float>(width), as<float>(height));
}

void graphics::draw_rectangle(const xtd::drawing::pen& pen, float x, float y, float width, float height) {
  if (width < 0 || height < 0) throw argument_exception {csf_};
  native::graphics::draw_rectangle(handle(), pen.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height));
}

void graphics::draw_rectangles(const xtd::drawing::pen& pen, const std::vector<xtd::drawing::rectangle>& rects) {
  auto rectangles = vector<rectangle_f> {};
  for_each(rects.begin(), rects.end(), [&](auto rect) {rectangles.push_back(rectangle_f(rect));});
  draw_rectangles(pen, rectangles);
}

void graphics::draw_rectangles(const xtd::drawing::pen& pen, const std::vector<xtd::drawing::rectangle_f>& rects) {
  auto rectangles = vector<tuple<float, float, float, float>> {};
  for_each(rects.begin(), rects.end(), [&](auto rect) {rectangles.emplace_back(to_pixels(rect.x()), to_pixels(rect.y()), to_pixels(rect.width()), to_pixels(rect.height()));});
  native::graphics::draw_rectangles(handle(), pen.handle(), rectangles);
}

void graphics::draw_rotated_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::point_f& point, float angle) {
  draw_rotated_string(s, font, brush, point.x(), point.y(), angle);
}

void graphics::draw_rotated_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, float x, float y, float angle) {
  native::graphics::draw_rotated_string(handle(), s, font.handle(), brush.handle(), to_pixels(x), to_pixels(y), angle);
}

void graphics::draw_rounded_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect, int32 radius) {
  draw_rounded_rectangle(pen, rect.x(), rect.y(), rect.width(), rect.height(), radius);
}

void graphics::draw_rounded_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect, float radius) {
  draw_rounded_rectangle(pen, rect.x(), rect.y(), rect.width(), rect.height(), radius);
}

void graphics::draw_rounded_rectangle(const pen& pen, int32 x, int32 y, int32 width, int32 height, int32 radius) {
  draw_rounded_rectangle(pen, as<float>(x), as<float>(y), as<float>(width), as<float>(height), as<float>(radius));
}

void graphics::draw_rounded_rectangle(const xtd::drawing::pen& pen, float x, float y, float width, float height, float radius) {
  if (width < 0 || height < 0) throw argument_exception {csf_};
  native::graphics::draw_rounded_rectangle(handle(), pen.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height), to_pixels(radius));
}

void graphics::draw_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& layout_rectangle) {
  draw_string(s, font, brush, layout_rectangle, string_format());
}

void graphics::draw_string(const ustring& s, const font& font, const brush& brush, const rectangle_f& layout_rectangle, const string_format& format) {
  native::graphics::draw_string(handle(), s, font.handle(), brush.handle(), to_pixels(layout_rectangle.x()), to_pixels(layout_rectangle.y()), to_pixels(layout_rectangle.width()), to_pixels(layout_rectangle.height()), static_cast<int32>(format.alignment()), static_cast<int32>(format.line_alignment()), static_cast<int32>(format.hotkey_prefix()), static_cast<int32>(format.trimming()), static_cast<int32>(format.format_flags()));
}

void graphics::draw_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::point_f& point) {
  draw_string(s, font, brush, point.x(), point.y(), string_format());
}

void graphics::draw_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::point_f& point, const string_format& format) {
  draw_string(s, font, brush, point.x(), point.y(), format);
}

void graphics::draw_string(const xtd::ustring& s, const xtd::drawing::font& font, const xtd::drawing::brush& brush, float x, float y) {
  draw_string(s, font, brush, x, y, string_format());
}

void graphics::draw_string(const ustring& s, const font& font, const brush& brush, float x, float y, const string_format& format) {
  native::graphics::draw_string(handle(), s, font.handle(), brush.handle(), to_pixels(x), to_pixels(y), static_cast<int32>(format.alignment()), static_cast<int32>(format.line_alignment()), static_cast<int32>(format.hotkey_prefix()), static_cast<int32>(format.trimming()));
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

void graphics::fill_closed_curve(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point>& points) {
  fill_closed_curve(brush, points, drawing_2d::fill_mode::alternate, 0.0f);
}

void graphics::fill_closed_curve(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point_f>& points) {
  fill_closed_curve(brush, points, drawing_2d::fill_mode::alternate, 0.0f);
}

void graphics::fill_closed_curve(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point>& points, xtd::drawing::drawing_2d::fill_mode fill_mode) {
  fill_closed_curve(brush, points, fill_mode, 0.0f);
}

void graphics::fill_closed_curve(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point_f>& points, xtd::drawing::drawing_2d::fill_mode fill_mode) {
  fill_closed_curve(brush, points, fill_mode, 0.0f);
}

void graphics::fill_closed_curve(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point>& points, xtd::drawing::drawing_2d::fill_mode fill_mode, float tension) {
  auto close_curve_points = vector<point_f> {};
  for_each(points.begin(), points.end(), [&](auto pt) {close_curve_points.push_back(point_f(pt));});
  fill_closed_curve(brush, close_curve_points, fill_mode, tension);
}

void graphics::fill_closed_curve(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point_f>& points, xtd::drawing::drawing_2d::fill_mode fill_mode, float tension) {
  auto closed_curve_points = vector<pair<float, float>> {};
  for_each(points.begin(), points.end(), [&](auto pt) {closed_curve_points.emplace_back(to_pixels(pt.x()), to_pixels(pt.y()));});
  native::graphics::fill_closed_curve(handle(), brush.handle(), closed_curve_points, static_cast<int32>(fill_mode), tension);
}

void graphics::fill_ellipse(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect) {
  fill_ellipse(brush, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::fill_ellipse(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect) {
  fill_ellipse(brush, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::fill_ellipse(const brush& brush, int32 x, int32 y, int32 width, int32 height) {
  fill_ellipse(brush, as<float>(x), as<float>(y), as<float>(width), as<float>(height));
}

void graphics::fill_ellipse(const xtd::drawing::brush& brush, float x, float y, float width, float height) {
  if (width < 0 || height < 0) throw argument_exception {csf_};
  native::graphics::fill_ellipse(handle(), brush.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height));
}

void graphics::fill_path(const brush& brush, const drawing_2d::graphics_path& path) {
  native::graphics::fill_path(handle(), brush.handle(), path.handle(), static_cast<int32>(path.fill_mode()));
}

void graphics::fill_pie(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle) {
  fill_pie(brush, as<float>(rect.x()), as<float>(rect.y()), as<float>(rect.width()), as<float>(rect.height()), start_angle, sweep_angle);
}

void graphics::fill_pie(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle) {
  fill_pie(brush, rect.x(), rect.y(), rect.width(), rect.height(), start_angle, sweep_angle);
}

void graphics::fill_pie(const brush& brush, int32 x, int32 y, int32 width, int32 height, int32 start_angle, int32 sweep_angle) {
  fill_pie(brush, as<float>(x), as<float>(y), as<float>(width), as<float>(height), as<float>(start_angle), as<float>(sweep_angle));
}

void graphics::fill_pie(const xtd::drawing::brush& brush, float x, float y, float width, float height, float start_angle, float sweep_angle) {
  if (width < 0 || height < 0) throw argument_exception {csf_};
  if (start_angle < 0 || start_angle > 360) throw argument_exception {csf_};
  if (sweep_angle < 0 || sweep_angle > 360) throw argument_exception {csf_};
  native::graphics::fill_pie(handle(), brush.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height), start_angle, sweep_angle);
}

void graphics::fill_polygon(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point>& points) {
  fill_polygon(brush, points, drawing_2d::fill_mode::alternate);
}

void graphics::fill_polygon(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point_f>& points) {
  fill_polygon(brush, points, drawing_2d::fill_mode::alternate);
}

void graphics::fill_polygon(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point>& points, xtd::drawing::drawing_2d::fill_mode fill_mode) {
  auto lines_points = vector<point_f> {};
  for_each(points.begin(), points.end(), [&](auto pt) {lines_points.push_back(point_f(pt));});
  fill_polygon(brush, lines_points);
}

void graphics::fill_polygon(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::point_f>& points, xtd::drawing::drawing_2d::fill_mode fill_mode) {
  auto line_points = vector<pair<float, float>> {};
  for_each(points.begin(), points.end(), [&](auto pt) {line_points.emplace_back(to_pixels(pt.x()), to_pixels(pt.y()));});
  native::graphics::fill_polygon(handle(), brush.handle(), line_points, static_cast<int32>(fill_mode));
}

void graphics::fill_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect) {
  fill_rectangle(brush, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::fill_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect) {
  fill_rectangle(brush, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::fill_rectangle(const brush& brush, int32 x, int32 y, int32 width, int32 height) {
  fill_rectangle(brush, as<float>(x), as<float>(y), as<float>(width), as<float>(height));
}

void graphics::fill_rectangle(const xtd::drawing::brush& brush, float x, float y, float width, float height) {
  if (width < 0 || height < 0) throw argument_exception {csf_};
  native::graphics::fill_rectangle(handle(), brush.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height));
}

void graphics::fill_rectangles(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::rectangle>& rects) {
  auto rectangles = vector<rectangle_f> {};
  for_each(rects.begin(), rects.end(), [&](auto rect) {rectangles.push_back(rectangle_f(rect));});
  fill_rectangles(brush, rectangles);
}

void graphics::fill_rectangles(const xtd::drawing::brush& brush, const std::vector<xtd::drawing::rectangle_f>& rects) {
  auto rectangles = vector<tuple<float, float, float, float>> {};
  for_each(rects.begin(), rects.end(), [&](auto rect) {rectangles.emplace_back(to_pixels(rect.x()), to_pixels(rect.y()), to_pixels(rect.width()), to_pixels(rect.height()));});
  native::graphics::fill_rectangles(handle(), brush.handle(), rectangles);
}

void graphics::fill_region(const xtd::drawing::brush& brush, const xtd::drawing::region& region) {
  native::graphics::fill_region(handle(), brush.handle(), region.handle());
}

void graphics::fill_rounded_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect, int32 radius) {
  fill_rounded_rectangle(brush, rect.x(), rect.y(), rect.width(), rect.height(), radius);
}

void graphics::fill_rounded_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect, float radius) {
  fill_rounded_rectangle(brush, rect.x(), rect.y(), rect.width(), rect.height(), radius);
}

void graphics::fill_rounded_rectangle(const brush& brush, int32 x, int32 y, int32 width, int32 height, int32 radius) {
  fill_rounded_rectangle(brush, as<float>(x), as<float>(y), as<float>(width), as<float>(height), as<float>(radius));
}

void graphics::fill_rounded_rectangle(const xtd::drawing::brush& brush, float x, float y, float width, float height, float radius) {
  if (width < 0 || height < 0) throw argument_exception {csf_};
  native::graphics::fill_rounded_rectangle(handle(), brush.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height), to_pixels(radius));
}

void graphics::flush() {
  flush(xtd::drawing::drawing_2d::flush_intention::flush);
}

void graphics::flush(xtd::drawing::drawing_2d::flush_intention intention) {
  native::graphics::flush(handle(), static_cast<int32>(intention));
}

graphics graphics::from_hdc(intptr hdc) {
  return graphics(native::graphics::from_hdc(hdc));
}

graphics graphics::from_hdc(intptr hdc, intptr hdevice) {
  return graphics(native::graphics::from_hdc(hdc, hdevice));
}

graphics graphics::from_hwnd(intptr hwnd) {
  return graphics(native::graphics::from_hwnd(hwnd));
}

graphics graphics::from_image(const image& image) {
  return graphics(native::graphics::from_image(image.handle()));
}

intptr graphics::get_hdc() const {
  return native::graphics::get_hdc(handle());
}

xtd::drawing::color graphics::get_nearest_color(const xtd::drawing::color& color) const {
  auto a = 0_b, r = 0_b, g = 0_b, b = 0_b;
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

bool graphics::is_visible(const xtd::drawing::rectangle& rect) {
  return clip().is_visible(rect, *this);
}

bool graphics::is_visible(const xtd::drawing::rectangle_f& rect) {
  return clip().is_visible(rect, *this);
}

bool graphics::is_visible(int32 x, int32 y, int32 width, int32 height) {
  return clip().is_visible(x, y, width, height, *this);
}

bool graphics::is_visible(float x, float y, float width, float height) {
  return clip().is_visible(x, y, width, height, *this);
}

bool graphics::is_visible(const xtd::drawing::point& point) {
  return clip().is_visible(point, *this);
}

bool graphics::is_visible(const xtd::drawing::point_f& point) {
  return clip().is_visible(point, *this);
}

bool graphics::is_visible(int32 x, int32 y) {
  return clip().is_visible(x, y, *this);
}

bool graphics::is_visible(float x, float y) {
  return clip().is_visible(x, y, *this);
}

size_f graphics::measure_string(const ustring& text, const font& font) {
  return measure_string(text, font, size_f(single_object::max_value, single_object::max_value), string_format());
}

size_f graphics::measure_string(const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::size_f& layout_area) {
  return measure_string(text, font, layout_area, string_format());
}

size_f graphics::measure_string(const xtd::ustring& text, const xtd::drawing::font& font, int32 width) {
  return measure_string(text, font, size_f(as<float>(width), single_object::max_value), string_format());
}

size_f graphics::measure_string(const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::point_f& origin, const xtd::drawing::string_format& format) {
  return measure_string(text, font, size_f(single_object::max_value, single_object::max_value), format);
}

size_f graphics::measure_string(const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::size_f& layout_area, const xtd::drawing::string_format& format) {
  return measure_string(text, font, layout_area, format, int32_object::max_value, int32_object::max_value);
}

size_f graphics::measure_string(const xtd::ustring& text, const xtd::drawing::font& font, int32 width, const xtd::drawing::string_format& format) {
  return measure_string(text, font, size_f(as<float>(width), single_object::max_value), format);
}

size_f graphics::measure_string(const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::size_f& layout_area, const xtd::drawing::string_format& format, size_t characters_fitted, size_t lines_filled) {
  auto string_width = 0.0f;
  auto string_height = 0.0f;
  native::graphics::measure_string(handle(), text, font.handle(), string_width, string_height, to_pixels(layout_area.width()), to_pixels(layout_area.height()), static_cast<int32>(format.alignment()), static_cast<int32>(format.line_alignment()), static_cast<int32>(format.hotkey_prefix()), static_cast<int32>(format.trimming()), characters_fitted, lines_filled, (format.format_flags() & string_format_flags::measure_trailing_spaces) == string_format_flags::measure_trailing_spaces);
  return size_f(to_page_unit(string_width), to_page_unit(string_height));
}

void graphics::multiply_transform(const xtd::drawing::drawing_2d::matrix& matrix) {
  auto new_matrix = transform();
  new_matrix.multiply(matrix);
  transform(new_matrix);
}

void graphics::multiply_transform(const xtd::drawing::drawing_2d::matrix& matrix, xtd::drawing::drawing_2d::matrix_order order) {
  auto new_matrix = transform();
  new_matrix.multiply(matrix, order);
  transform(new_matrix);
}

void graphics::release_hdc(intptr hdc) {
  native::graphics::release_hdc(handle(), hdc);
}

void graphics::reset_clip() {
  data_->clip.make_infinite();
  native::graphics::clip(handle(), data_->clip.handle());
}

void graphics::reset_transform() {
  native::graphics::reset_transform(handle());
}

void graphics::restore(const xtd::drawing::drawing_2d::graphics_state& gstate) {
  native::graphics::restore(handle(), gstate.handle_);
}

void graphics::rotate_transform(float angle) {
  rotate_transform(angle, matrix_order::prepend);
}

void graphics::rotate_transform(float angle, matrix_order order) {
  native::graphics::rotate_transform(handle(), angle, static_cast<int32>(order));
}

graphics_state graphics::save() {
  return graphics_state(native::graphics::save(handle()));
}

void graphics::scale_transform(float sx, float sy) {
  scale_transform(sx, sy, matrix_order::prepend);
}

void graphics::scale_transform(float sx, float sy, matrix_order order) {
  native::graphics::scale_transform(handle(), to_pixels(sx), to_pixels(sy), static_cast<int32>(order));
}

void graphics::translate_clip(int32 dx, int32 dy) {
  data_->clip.translate(to_pixels(dx), to_pixels(dy));
  native::graphics::clip(handle(), clip().handle());
}

void graphics::translate_clip(float dx, float dy) {
  data_->clip.translate(to_pixels(dx), to_pixels(dy));
  native::graphics::clip(handle(), clip().handle());
}

void graphics::translate_transform(float dx, float dy) {
  translate_transform(dx, dy, matrix_order::prepend);
}

void graphics::translate_transform(float dx, float dy, matrix_order order) {
  native::graphics::translate_transform(handle(), to_pixels(dx), to_pixels(dy), static_cast<int32>(order));
}

ustring graphics::trim_string(const ustring& text, const font& font, float width, string_trimming trimming) {
  auto result = text;
  return native::graphics::trim_string(handle(), text, font.handle(), width, static_cast<int32>(trimming));
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

int32 graphics::to_pixels(int32 value) const {
  return as<int32>(to_pixels(as<float>(value)));
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
