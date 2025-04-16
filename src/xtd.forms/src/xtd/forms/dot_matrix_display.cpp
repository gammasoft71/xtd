#include "../../../include/xtd/forms/dot_matrix_display.hpp"
#include <xtd/drawing/color_converter>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::helpers;

struct dot_matrix_display::data {
  drawing::size matrix_size = {7, 7};
  dots_collection dots = dots_collection(matrix_size.width, array<bool>(matrix_size.height, false));
  bool show_back_dot = true;
  std::optional<drawing::color> back_dot_color;
  double back_dot_opacity = 0.95;
  forms::dot_matrix_style dot_matrix_style = forms::dot_matrix_style::standard;
  std::optional<int32> thickness;
};

dot_matrix_display::dot_matrix_display() : data_(xtd::new_sptr<data>()) {
  auto_size(true);
  double_buffered(true);
}

drawing::color dot_matrix_display::back_dot_color() const noexcept {
  return data_->back_dot_color.value_or(fore_color());
}

dot_matrix_display& dot_matrix_display::back_dot_color(const drawing::color& value) {
  if (!data_->back_dot_color.has_value() || data_->back_dot_color.value() != value) {
    data_->back_dot_color = value;
    invalidate();
  }
  return *this;
}

double dot_matrix_display::back_dot_opacity() const noexcept {
  return data_->back_dot_opacity;
}

dot_matrix_display& dot_matrix_display::back_dot_opacity(double value) {
  if (value < 0.0 || value > 1.0) throw_helper::throws(exception_case::argument_out_of_range, "value must be between 0.0 and 1.0."_t);
  if (data_->back_dot_opacity == value) return *this;
  data_->back_dot_opacity = value;
  if (data_->back_dot_opacity < 0.0) data_->back_dot_opacity = 0.0;
  if (data_->back_dot_opacity > 1.0) data_->back_dot_opacity = 1.0;
  invalidate();
  return *this;
}

forms::dot_matrix_style dot_matrix_display::dot_matrix_style() const noexcept {
  return data_->dot_matrix_style;
}

dot_matrix_display& dot_matrix_display::dot_matrix_style(forms::dot_matrix_style value) {
  if (data_->dot_matrix_style == value) return *this;
  data_->dot_matrix_style = value;
  invalidate();
  return *this;
}

const dot_matrix_display::dots_collection& dot_matrix_display::dot_matrix_display::dots() const noexcept {
  return data_->dots;
}

dot_matrix_display& dot_matrix_display::dots(const dots_collection& dots) {
  if (data_->dots == dots) return *this;
  data_->dots = dots;
  data_->matrix_size = drawing::size(static_cast<int32>(data_->dots[0].size()), static_cast<int32>(data_->dots.size()));
  invalidate();
  return *this;
}

int32 dot_matrix_display::matrix_height() const noexcept {
  return data_->matrix_size.height;
}

dot_matrix_display& dot_matrix_display::matrix_height(int32 value) {
  matrix_size({data_->matrix_size.width, value});
  return *this;
}

int32 dot_matrix_display::matrix_width() const noexcept {
  return data_->matrix_size.width;
}

dot_matrix_display& dot_matrix_display::matrix_width(int32 value) {
  matrix_size({value, data_->matrix_size.height});
  return *this;
}

const drawing::size& dot_matrix_display::matrix_size() const noexcept {
  return data_->matrix_size;
}

dot_matrix_display& dot_matrix_display::matrix_size(const drawing::size& value) {
  if (data_->matrix_size == value) return *this;
  data_->matrix_size = value;
  data_->dots = dots_collection(data_->matrix_size.height, array<bool>(data_->matrix_size.width, false));
  invalidate();
  return *this;
}

bool dot_matrix_display::show_back_dot() const noexcept {
  return data_->show_back_dot;
}

dot_matrix_display& dot_matrix_display::show_back_dot(bool value) {
  if (data_->show_back_dot == value) return *this;
  data_->show_back_dot = value;
  invalidate();
  return *this;
}

int32 dot_matrix_display::thickness() const noexcept {
  return data_->thickness.value_or(size().height < (data_->matrix_size.height * 2) ? 1 : (size().height - data_->matrix_size.height) / data_->matrix_size.height);
}

dot_matrix_display& dot_matrix_display::thickness(int32 value) {
  if (data_->thickness.has_value() && data_->thickness.value() == value) return *this;
  data_->thickness = value;
  invalidate();
  return *this;
}

dot_matrix_display dot_matrix_display::create() {
  return dot_matrix_display {};
}

dot_matrix_display dot_matrix_display::create(const drawing::point& location) {
  auto result = dot_matrix_display {};
  result.location(location);
  return result;
}

dot_matrix_display dot_matrix_display::create(const drawing::point& location, const drawing::size& size) {
  auto result = dot_matrix_display {};
  result.location(location);
  result.size(size);
  return result;
}

dot_matrix_display dot_matrix_display::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = dot_matrix_display {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

dot_matrix_display dot_matrix_display::create(const dots_collection& dots) {
  auto result = dot_matrix_display {};
  result.dots(dots);
  return result;
}

dot_matrix_display dot_matrix_display::create(const dots_collection& dots, const drawing::point& location) {
  auto result = dot_matrix_display {};
  result.dots(dots);
  result.location(location);
  return result;
}

dot_matrix_display dot_matrix_display::create(const dots_collection& dots, const drawing::point& location, const drawing::size& size) {
  auto result = dot_matrix_display {};
  result.dots(dots);
  result.location(location);
  result.size(size);
  return result;
}

dot_matrix_display dot_matrix_display::create(const dots_collection& dots, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = dot_matrix_display {};
  result.dots(dots);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

dot_matrix_display dot_matrix_display::create(const dots_collection& dots, bool show_back_dot) {
  auto result = dot_matrix_display {};
  result.dots(dots);
  result.show_back_dot(show_back_dot);
  return result;
}

dot_matrix_display dot_matrix_display::create(const dots_collection& dots, bool show_back_dot, const drawing::point& location) {
  auto result = dot_matrix_display {};
  result.dots(dots);
  result.show_back_dot(show_back_dot);
  result.location(location);
  return result;
}

dot_matrix_display dot_matrix_display::create(const dots_collection& dots, bool show_back_dot, const drawing::point& location, const drawing::size& size) {
  auto result = dot_matrix_display {};
  result.dots(dots);
  result.show_back_dot(show_back_dot);
  result.location(location);
  result.size(size);
  return result;
}

dot_matrix_display dot_matrix_display::create(const dots_collection& dots, bool show_back_dot, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = dot_matrix_display {};
  result.dots(dots);
  result.show_back_dot(show_back_dot);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

dot_matrix_display dot_matrix_display::create(const control& parent) {
  auto result = dot_matrix_display {};
  result.parent(parent);
  return result;
}

dot_matrix_display dot_matrix_display::create(const control& parent, const drawing::point& location) {
  auto result = dot_matrix_display {};
  result.parent(parent);
  result.location(location);
  return result;
}

dot_matrix_display dot_matrix_display::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = dot_matrix_display {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

dot_matrix_display dot_matrix_display::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = dot_matrix_display {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

dot_matrix_display dot_matrix_display::create(const control& parent, const dots_collection& dots) {
  auto result = dot_matrix_display {};
  result.parent(parent);
  result.dots(dots);
  return result;
}

dot_matrix_display dot_matrix_display::create(const control& parent, const dots_collection& dots, const drawing::point& location) {
  auto result = dot_matrix_display {};
  result.parent(parent);
  result.dots(dots);
  result.location(location);
  return result;
}

dot_matrix_display dot_matrix_display::create(const control& parent, const dots_collection& dots, const drawing::point& location, const drawing::size& size) {
  auto result = dot_matrix_display {};
  result.parent(parent);
  result.dots(dots);
  result.location(location);
  result.size(size);
  return result;
}

dot_matrix_display dot_matrix_display::create(const control& parent, const dots_collection& dots, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = dot_matrix_display {};
  result.parent(parent);
  result.dots(dots);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

dot_matrix_display dot_matrix_display::create(const control& parent, const dots_collection& dots, bool show_back_dot) {
  auto result = dot_matrix_display {};
  result.parent(parent);
  result.dots(dots);
  result.show_back_dot(show_back_dot);
  return result;
}

dot_matrix_display dot_matrix_display::create(const control& parent, const dots_collection& dots, bool show_back_dot, const drawing::point& location) {
  auto result = dot_matrix_display {};
  result.parent(parent);
  result.dots(dots);
  result.show_back_dot(show_back_dot);
  result.location(location);
  return result;
}

dot_matrix_display dot_matrix_display::create(const control& parent, const dots_collection& dots, bool show_back_dot, const drawing::point& location, const drawing::size& size) {
  auto result = dot_matrix_display {};
  result.parent(parent);
  result.dots(dots);
  result.show_back_dot(show_back_dot);
  result.location(location);
  result.size(size);
  return result;
}

dot_matrix_display dot_matrix_display::create(const control& parent, const dots_collection& dots, bool show_back_dot, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = dot_matrix_display {};
  result.parent(parent);
  result.dots(dots);
  result.show_back_dot(show_back_dot);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

bool dot_matrix_display::get_dot(const drawing::point& point) const noexcept {
  return data_->dots[point.y][point.x];
}

void dot_matrix_display::set_all_dots(bool on) {
  for (auto y = 0_z; y < data_->dots.size(); ++y)
    for (auto x = 0_z; x < data_->dots[y].size(); ++x)
      data_->dots[y][x] = on;
}

void dot_matrix_display::set_dot(const drawing::point& point, bool on) {
  if (data_->dots[point.y][point.x] != on) {
    data_->dots[point.y][point.x] = on;
    invalidate();
  }
}

void dot_matrix_display::set_dots(const points_collection& points) {
  set_all_dots(false);
  set_dots(points, true);
}

void dot_matrix_display::set_dots(const points_collection& points, bool on) {
  for (auto point : points)
    set_dot(point, on);
}

xtd::drawing::size dot_matrix_display::default_size() const noexcept {
  return {50, 50};
}

xtd::uptr<xtd::object> dot_matrix_display::clone() const {
  auto result = xtd::new_uptr<dot_matrix_display>(*this);
  if (typeof_(*result) != typeof_(*this)) throw_helper::throws(exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).c_str());
  return result;
}

void dot_matrix_display::on_back_color_changed(const event_args& e) {
  control::on_back_color_changed(e);
  invalidate();
}

void dot_matrix_display::on_fore_color_changed(const event_args& e) {
  control::on_fore_color_changed(e);
  invalidate();
}

void dot_matrix_display::on_paint(paint_event_args& e) {
  e.graphics().clear(back_color());
  for (auto y = 0_z; y < data_->dots.size(); ++y) {
    for (auto x = 0_z; x < data_->dots[y].size(); ++x) {
      if (data_->dots[y][x]) draw_dot(e.graphics(), fore_color(), {as<int32>(x), as<int32>(y)});
      else if (data_->show_back_dot) draw_dot(e.graphics(), drawing::color_converter::average(back_dot_color(), back_color(), data_->back_dot_opacity), {as<int32>(x), as<int32>(y)});
    }
  }
  control::on_paint(e);
}

drawing::size dot_matrix_display::measure_control() const noexcept {
  auto width = as<int32>(as<double>(height()) / matrix_height() * matrix_width());
  return drawing::size(width, height());
}

void dot_matrix_display::draw_dot(drawing::graphics& graphics, const drawing::color& color, const drawing::point& point) {
  auto y = (height() - as<int32>(data_->dots.size())) / static_cast<int32>(data_->dots.size());
  auto x = (width() - as<int32>(data_->dots[point.y].size())) / static_cast<int32>(data_->dots[point.y].size());
  if (data_->dot_matrix_style == dot_matrix_style::standard) graphics.fill_pie(drawing::solid_brush(color), (1 + x) * point.x, (1 + y) * point.y, thickness(), thickness(), 0, 360);
  else if (data_->dot_matrix_style == dot_matrix_style::square) graphics.fill_rectangle(drawing::solid_brush(color), (1 + x) * point.x, (1 + y) * point.y, thickness(), thickness());
}
