#include "../../../../include/xtd/drawing/drawing_2d/graphics_path.h"
#include "../../../../include/xtd/drawing/graphics.h"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/graphics_path>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <xtd/as>
#include <xtd/is>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;

struct graphics_path::data {
  intptr handle = 0;
  xtd::drawing::drawing_2d::fill_mode fill_mode = xtd::drawing::drawing_2d::fill_mode::alternate;
};

graphics_path::graphics_path() : graphics_path(drawing_2d::fill_mode::alternate) {
}

graphics_path::graphics_path(drawing_2d::fill_mode mode) : data_(std::make_shared<data>()) {
  data_->fill_mode = mode;
  recreate_handle();
}

graphics_path::~graphics_path() {
  if (data_.use_count() == 1 && data_->handle != 0) {
    native::graphics_path::destroy(data_->handle);
    data_->handle = 0;
  }
}

intptr graphics_path::handle() const noexcept {
  return data_->handle;
}

xtd::drawing::drawing_2d::fill_mode graphics_path::fill_mode() const noexcept {
  return data_->fill_mode;
}

graphics_path& graphics_path::fill_mode(xtd::drawing::drawing_2d::fill_mode value) noexcept {
  data_->fill_mode = value;
  return *this;
}

void graphics_path::add_arc(const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle) {
  add_arc(rect.x(), rect.y(), rect.width(), rect.height(), start_angle, sweep_angle);
}

void graphics_path::add_arc(const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle) {
  add_arc(rect.x(), rect.y(), rect.width(), rect.height(), start_angle, sweep_angle);
}

void graphics_path::add_arc(int32 x, int32 y, int32 width, int32 height, float start_angle, float sweep_angle) {
  add_arc(as<float>(x), as<float>(y), as<float>(width), as<float>(height), start_angle, sweep_angle);
}

void graphics_path::add_arc(float x, float y, float width, float height, float start_angle, float sweep_angle) {
  native::graphics_path::add_arc(handle(), x, y, width, height, start_angle, sweep_angle);
}

void graphics_path::add_bezier(const xtd::drawing::point& pt1, const xtd::drawing::point& pt2, const xtd::drawing::point& pt3, const xtd::drawing::point& pt4) {
  add_bezier(pt1.x(), pt1.y(), pt2.x(), pt2.y(), pt3.x(), pt3.y(), pt4.x(), pt4.y());
}

void graphics_path::add_bezier(const xtd::drawing::point_f& pt1, const xtd::drawing::point_f& pt2, const xtd::drawing::point_f& pt3, const xtd::drawing::point_f& pt4) {
  add_bezier(pt1.x(), pt1.y(), pt2.x(), pt2.y(), pt3.x(), pt3.y(), pt4.x(), pt4.y());
}

void graphics_path::add_bezier(int32 x1, int32 y1, int32 x2, int32 y2, int32 x3, int32 y3, int32 x4, int32 y4) {
  add_bezier(as<float>(x1), as<float>(y1), as<float>(x2), as<float>(y2), as<float>(x3), as<float>(y3), as<float>(x4), as<float>(y4));
}

void graphics_path::add_bezier(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
  native::graphics_path::add_bezier(handle(), x1, y1, x2, y2, x3, y3, x4, y4);
}

void graphics_path::add_beziers(const std::vector<xtd::drawing::point>& points) {
  auto points_f = vector<point_f> {};
  for_each(points.begin(), points.end(), [&](auto point) {points_f.push_back(point_f(point));});
  add_beziers(points_f);
}

void graphics_path::add_beziers(const std::vector<xtd::drawing::point_f>& points) {
  auto pair_points = vector<pair<float, float>> {};
  for_each(points.begin(), points.end(), [&](auto point) {pair_points.emplace_back(point.x(), point.y());});
  native::graphics_path::add_beziers(handle(), pair_points);
}

void graphics_path::add_closed_curve(const std::vector<xtd::drawing::point>& points) {
  add_closed_curve(points, 0.0f);
}

void graphics_path::add_closed_curve(const std::vector<xtd::drawing::point_f>& points) {
  add_closed_curve(points, 0.0f);
}

void graphics_path::add_closed_curve(const std::vector<xtd::drawing::point>& points, float tension) {
  auto points_f = vector<point_f> {};
  for_each(points.begin(), points.end(), [&](auto point) {points_f.push_back(point_f(point));});
  add_closed_curve(points_f, tension);
}

void graphics_path::add_closed_curve(const std::vector<xtd::drawing::point_f>& points, float tension) {
  auto pair_points = vector<pair<float, float>> {};
  for_each(points.begin(), points.end(), [&](auto point) {pair_points.emplace_back(point.x(), point.y());});
  native::graphics_path::add_closed_curve(handle(), pair_points, tension);
}

void graphics_path::add_curve(const std::vector<xtd::drawing::point>& points) {
  add_curve(points, 0, points.size(), 0.5f);
}

void graphics_path::add_curve(const std::vector<xtd::drawing::point_f>& points) {
  add_curve(points, 0, points.size(), 0.5f);
}

void graphics_path::add_curve(const std::vector<xtd::drawing::point>& points, float tension) {
  add_curve(points, 0, points.size(), tension);
}

void graphics_path::add_curve(const std::vector<xtd::drawing::point_f>& points, float tension) {
  add_curve(points, 0, points.size(), tension);
}

void graphics_path::add_curve(const std::vector<xtd::drawing::point>& points, size_t offset, size_t number_of_segments, float tension) {
  auto points_f = vector<point_f> {};
  for_each(points.begin(), points.end(), [&](auto point) {points_f.push_back(point_f(point));});
  add_curve(points_f, offset, number_of_segments, tension);
}

void graphics_path::add_curve(const std::vector<xtd::drawing::point_f>& points, size_t offset, size_t number_of_segments, float tension) {
  auto pair_points = vector<pair<float, float>> {};
  for_each(points.begin(), points.end(), [&](auto point) {pair_points.emplace_back(point.x(), point.y());});
  native::graphics_path::add_curve(handle(), pair_points, offset, number_of_segments, tension);
}

void graphics_path::add_ellipse(const xtd::drawing::rectangle& rect) {
  add_ellipse(rectangle_f(rect));
}

void graphics_path::add_ellipse(const xtd::drawing::rectangle_f& rect) {
  add_ellipse(rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics_path::add_ellipse(int32 x, int32 y, int32 width, int32 height) {
  add_ellipse(as<float>(x), as<float>(y), as<float>(width), as<float>(height));
}

void graphics_path::add_ellipse(float x, float y, float width, float height) {
  native::graphics_path::add_ellipse(handle(), x, y, width, height);
}

void graphics_path::add_line(const xtd::drawing::point& pt1, const xtd::drawing::point& pt2) {
  add_line(pt1.x(), pt1.y(), pt2.x(), pt2.y());
}

void graphics_path::add_line(const xtd::drawing::point_f& pt1, const xtd::drawing::point_f& pt2) {
  add_line(pt1.x(), pt1.y(), pt2.x(), pt2.y());
}

void graphics_path::add_line(int32 x1, int32 y1, int32 x2, int32 y2) {
  add_line(as<float>(x1), as<float>(y1), as<float>(x2), as<float>(y2));
}

void graphics_path::add_line(float x1, float y1, float x2, float y2) {
  native::graphics_path::add_line(handle(), x1, y1, x2, y2);
}

void graphics_path::add_lines(const std::vector<xtd::drawing::point>& points) {
  if (points.size() < 2) throw argument_exception {csf_};
  for (auto index = 0_z; index < points.size() - 1; ++index)
    add_line(points[index], points[index + 1]);
}

void graphics_path::add_lines(const std::vector<xtd::drawing::point_f>& points) {
  if (points.size() < 2) throw argument_exception {csf_};
  for (auto index = 0_z; index < points.size() - 1; ++index)
    add_line(points[index], points[index + 1]);
}

void graphics_path::add_path(const graphics_path& adding_path, bool connect) {
  native::graphics_path::add_path(handle(), adding_path.handle(), connect);
}

void graphics_path::add_pie(const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle) {
  add_pie(rect.x(), rect.y(), rect.width(), rect.height(), start_angle, sweep_angle);
}

void graphics_path::add_pie(const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle) {
  add_pie(rect.x(), rect.y(), rect.width(), rect.height(), start_angle, sweep_angle);
}

void graphics_path::add_pie(int32 x, int32 y, int32 width, int32 height, float start_angle, float sweep_angle) {
  add_pie(as<float>(x), as<float>(y), as<float>(width), as<float>(height), start_angle, sweep_angle);
}

void graphics_path::add_pie(float x, float y, float width, float height, float start_angle, float sweep_angle) {
  native::graphics_path::add_pie(handle(), x, y, width, height, start_angle, sweep_angle);
}

void graphics_path::add_polygon(const std::vector<xtd::drawing::point>& points) {
  if (points.size() < 2) throw argument_exception {csf_};
  for (auto index = 0_z; index < points.size() - 1; ++index)
    add_line(points[index], points[index + 1]);
  if (points[points.size() - 1] != points[0]) add_line(points[points.size() - 1], points[0]);
}

void graphics_path::add_polygon(const std::vector<xtd::drawing::point_f>& points) {
  if (points.size() < 2) throw argument_exception {csf_};
  for (auto index = 0_z; index < points.size() - 1; ++index)
    add_line(points[index], points[index + 1]);
  if (points[points.size() - 1] != points[0]) add_line(points[points.size() - 1], points[0]);
}

void graphics_path::add_rectangle(const rectangle& rect) {
  add_rectangle(rectangle_f(rect));
}
void graphics_path::add_rectangle(const rectangle_f& rect) {
  add_rectangle(rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics_path::add_rectangle(int32 x, int32 y, int32 width, int32 height) {
  add_rectangle(as<float>(x), as<float>(y), as<float>(width), as<float>(height));
}

void graphics_path::add_rectangle(float x, float y, float width, float height) {
  native::graphics_path::add_rectangle(handle(), x, y, width, height);
}

void graphics_path::add_rectangles(const std::vector<xtd::drawing::rectangle>& rects) {
  for (auto rect : rects)
    add_rectangle(rect);
}
void graphics_path::add_rectangles(const std::vector<xtd::drawing::rectangle_f>& rects) {
  for (auto rect : rects)
    add_rectangle(rect);
}

void graphics_path::add_rounded_rectangle(const rectangle& rect, float radius) {
  add_rounded_rectangle(rectangle_f(rect), radius);
}
void graphics_path::add_rounded_rectangle(const rectangle_f& rect, float radius) {
  add_rounded_rectangle(rect.x(), rect.y(), rect.width(), rect.height(), radius);
}

void graphics_path::add_rounded_rectangle(int32 x, int32 y, int32 width, int32 height, float radius) {
  add_rounded_rectangle(as<float>(x), as<float>(y), as<float>(width), as<float>(height), radius);
}

void graphics_path::add_rounded_rectangle(float x, float y, float width, float height, float radius) {
  native::graphics_path::add_rounded_rectangle(handle(), x, y, width, height, radius);
}

void graphics_path::add_string(const xtd::ustring& s, const xtd::drawing::font_family& family, xtd::drawing::font_style style, float em_size, const xtd::drawing::point& origin, const xtd::drawing::string_format& format) {
  add_string(s, family, style, em_size, point_f(origin), format);
}

void graphics_path::add_string(const xtd::ustring& s, const xtd::drawing::font_family& family, xtd::drawing::font_style style, float em_size, const xtd::drawing::point_f& origin, const xtd::drawing::string_format& format) {
  auto f = font {family, em_size, style};
  native::graphics_path::add_string(handle(), s, f.handle(), origin.x(), origin.y(), static_cast<int32>(format.alignment()), static_cast<int32>(format.line_alignment()), static_cast<int32>(format.hotkey_prefix()), static_cast<int32>(format.trimming()));
}

void graphics_path::add_string(const xtd::ustring& s, const xtd::drawing::font_family& family, xtd::drawing::font_style style, float em_size, const xtd::drawing::rectangle& layout_rect, const xtd::drawing::string_format& format) {
  add_string(s, family, style, em_size, rectangle_f(layout_rect), format);
}

void graphics_path::add_string(const xtd::ustring& s, const xtd::drawing::font_family& family, xtd::drawing::font_style style, float em_size, const xtd::drawing::rectangle_f& layout_rect, const xtd::drawing::string_format& format) {
  auto f = font {family, em_size, style};
  native::graphics_path::add_string(handle(), s, f.handle(), layout_rect.x(), layout_rect.y(), layout_rect.width(), layout_rect.height(), static_cast<int32>(format.alignment()), static_cast<int32>(format.line_alignment()), static_cast<int32>(format.hotkey_prefix()), static_cast<int32>(format.trimming()));
}

void graphics_path::close_all_figures() {
  native::graphics_path::close_all_figures(handle());
}

void graphics_path::close_figure() {
  native::graphics_path::close_figure(handle());
}

bool graphics_path::equals(const graphics_path& value) const noexcept {
  return data_ == value.data_;
}

void graphics_path::flatten() {
  native::graphics_path::flatten(handle());
}

xtd::drawing::rectangle_f graphics_path::get_bounds() const {
  auto x = .0f, y = .0f, width = .0f, height = .0f;
  native::graphics_path::get_bounds(handle(), x, y, width, height);
  return {x, y, width, height};
}

xtd::drawing::point_f graphics_path::get_lat_point() const {
  auto x = .0f, y = .0f;
  native::graphics_path::get_last_point(handle(), x, y);
  return point_f(x, y);
}

bool graphics_path::is_vsible(const xtd::drawing::point& point) const {
  return is_vsible(point.x(), point.y());
}

bool graphics_path::is_vsible(const xtd::drawing::point_f& point) const {
  return is_vsible(point.x(), point.y());
}

bool graphics_path::is_vsible(int32 x, int32 y) const {
  return is_vsible(as<float>(x), as<float>(y));
}

bool graphics_path::is_vsible(float x, float y) const {
  return native::graphics_path::is_vsible(handle(), x, y);
}

void graphics_path::reset() {
  data_->fill_mode = fill_mode::alternate;
  recreate_handle();
}

void graphics_path::reverse() {
  native::graphics_path::reverse(handle());
}

void graphics_path::start_figure() {
  native::graphics_path::start_figure(handle());
}

xtd::ustring graphics_path::to_string() const noexcept {
  return get_type().full_name();
}

void graphics_path::recreate_handle() {
  if (data_->handle != 0) native::graphics_path::destroy(data_->handle);
  data_->handle = native::graphics_path::create();
}
