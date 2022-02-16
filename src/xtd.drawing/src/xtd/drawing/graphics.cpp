#include <vector>
#include "../../../include/xtd/drawing/bitmap.h"
#include "../../../include/xtd/drawing/icon.h"
#include "../../../include/xtd/drawing/graphics.h"
#include "../../../include/xtd/drawing/solid_brush.h"
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
  auto rect_pixels = data_->clip.get_bounds();
  return rectangle_f(to_page_unit(rect_pixels.x()), to_page_unit(rect_pixels.y()), to_page_unit(rect_pixels.width()), to_page_unit(rect_pixels.height()));
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

xtd::drawing::graphics_unit graphics::page_unit() const {
  return data_->page_unit;
}
graphics& graphics::page_unit(xtd::drawing::graphics_unit value) {
  data_->page_unit = value;
  return *this;
}


void graphics::clear(const color& color) {
  native::graphics::clear(handle(), color.a(), color.r(), color.g(), color.b());
}

void graphics::draw_arc(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle) {
  draw_arc(pen, rectangle_f(rect), start_angle, sweep_angle);
}

void graphics::draw_arc(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle) {
  draw_arc(pen, rect.x(), rect.y(), rect.width(), rect.height(), start_angle, sweep_angle);
}

void graphics::draw_arc(const pen& pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  draw_arc(pen, static_cast<float>(x), static_cast<float>(y), static_cast<float>(width), static_cast<float>(height), static_cast<float>(start_angle), static_cast<float>(sweep_angle));
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
  draw_bezier(pen, static_cast<float>(x1), static_cast<float>(y1), static_cast<float>(x2), static_cast<float>(y2), static_cast<float>(x3), static_cast<float>(y3), static_cast<float>(x4), static_cast<float>(y4));
}

void graphics::draw_bezier(const pen& pen, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
  native::graphics::draw_bezier(handle(), pen.handle(), to_pixels(x1), to_pixels(y1), to_pixels(x2), to_pixels(y2), to_pixels(x3), to_pixels(y3), to_pixels(x4), to_pixels(y4));
}

void graphics::draw_ellipse(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect) {
  draw_ellipse(pen, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::draw_ellipse(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect) {
  draw_ellipse(pen, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::draw_ellipse(const pen& pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  draw_ellipse(pen, static_cast<float>(x), static_cast<float>(y), static_cast<float>(width), static_cast<float>(height));
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
  draw_icon(icon, rect.x(), rect.y());
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
  draw_image(image, static_cast<float>(x), static_cast<float>(y), static_cast<float>(width), static_cast<float>(height));
}

void graphics::draw_image(const xtd::drawing::image& image, float x, float y, float width, float height) {
  if (size_f(width, height) == size_f(image.size()))  native::graphics::draw_image(handle(), image.handle(), to_pixels(x), to_pixels(y));
  else native::graphics::draw_image(handle(), bitmap(image, size(static_cast<int32_t>(to_pixels(width)), static_cast<int32_t>(to_pixels(height)))).handle(), to_pixels(x), to_pixels(y));
}

void graphics::draw_image(const image& image, int32_t x, int32_t y) {
  draw_image(image, x, y, image.size().width(), image.size().height());
}

void graphics::draw_image(const xtd::drawing::image& image, float x, float y) {
  draw_image(image, static_cast<int32_t>(x), static_cast<int32_t>(y));
}

void graphics::draw_image_disabled(const image& image, float x, float y, float brightness) {
  native::graphics::draw_image_disabled(handle(), image.handle(), to_pixels(x), to_pixels(y), brightness);
}

void graphics::draw_line(const xtd::drawing::pen& pen, const xtd::drawing::point& p1, const point& p2) {
  draw_line(pen, p1.x(), p1.y(), p2.x(), p2.y());
}

void graphics::draw_line(const xtd::drawing::pen& pen, const xtd::drawing::point_f& p1, const point_f& p2) {
  draw_line(pen, p1.x(), p1.y(), p2.x(), p2.y());
}

void graphics::draw_line(const pen& pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
  draw_line(pen, static_cast<float>(x1), static_cast<float>(y1), static_cast<float>(x2), static_cast<float>(y2));
}

void graphics::draw_line(const xtd::drawing::pen& pen, float x1, float y1, float x2, float y2) {
  native::graphics::draw_line(handle(), pen.handle(), to_pixels(x1), to_pixels(y1), to_pixels(x2), to_pixels(y2));
}

void graphics::draw_path(const xtd::drawing::pen& pen, const xtd::drawing::drawing2d::graphics_path& graphics_path) {
  native::graphics::draw_path(handle(), pen.handle(), graphics_path.handle());
}

void graphics::draw_point(const xtd::drawing::pen& pen, const xtd::drawing::point& p) {
  draw_point(pen, p.x(), p.y());
}

void graphics::draw_point(const xtd::drawing::pen& pen, const xtd::drawing::point_f& p) {
  draw_point(pen, p.x(), p.y());
}

void graphics::draw_point(const xtd::drawing::pen& pen, int32_t x, int32_t y) {
  draw_point(pen, static_cast<float>(x), static_cast<float>(y));
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
  draw_rectangle(pen, static_cast<float>(x), static_cast<float>(y), static_cast<float>(width), static_cast<float>(height));
}

void graphics::draw_rectangle(const xtd::drawing::pen& pen, float x, float y, float width, float height) {
  native::graphics::draw_rectangle(handle(), pen.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height));
}

void graphics::draw_rounded_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle& rect, int32_t radius) {
  draw_rounded_rectangle(pen, rect.x(), rect.y(), rect.width(), rect.height(), radius);
}

void graphics::draw_rounded_rectangle(const xtd::drawing::pen& pen, const xtd::drawing::rectangle_f& rect, float radius) {
  draw_rounded_rectangle(pen, rect.x(), rect.y(), rect.width(), rect.height(), radius);
}

void graphics::draw_rounded_rectangle(const pen& pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t radius) {
  draw_rounded_rectangle(pen, static_cast<float>(x), static_cast<float>(y), static_cast<float>(width), static_cast<float>(height), static_cast<float>(radius));
}

void graphics::draw_rounded_rectangle(const xtd::drawing::pen& pen, float x, float y, float width, float height, float radius) {
  native::graphics::draw_rounded_rectangle(handle(), pen.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height), to_pixels(radius));
}

void graphics::draw_string(const ustring& text, const font& font, const brush& brush, const rectangle_f& layout_rectangle, const string_format& format) {
  if (dynamic_cast<const solid_brush*>(&brush) != nullptr) {
    auto text_size = measure_string(text, font);
    auto y = layout_rectangle.y();
    auto height = layout_rectangle.height();
    
    if (format.line_alignment() == string_alignment::center) {
      y += (layout_rectangle.height() - text_size.height()) / 2;
      height -= (layout_rectangle.height() - text_size.height()) / 2;
    } else  if (format.line_alignment() == string_alignment::far) {
      y += (layout_rectangle.height() - text_size.height());
      height -= (layout_rectangle.height() - text_size.height());
    }
    
    auto lines = text.split({'\n'});
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
      
      if (format.hotkey_prefix() != hotkey_prefix::show) native::graphics::draw_string(handle(), drawable_line, font.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height), static_cast<const solid_brush&>(brush).color().a(), static_cast<const solid_brush&>(brush).color().r(), static_cast<const solid_brush&>(brush).color().g(), static_cast<const solid_brush&>(brush).color().b());
      else {
        /*
         for (auto index  = 0; index <hotkey_prefix_locations.size(); ++index) {
         g.draw_string(text_without_hotkey_prefix.substring(hotkey_prefix_locations[index], 1), xtd::drawing::font(font, font_style::underline), solid_brush(text_color), button_rect, to_string_format(flags));
         auto chunk_size = (index+1 < hotkey_prefix_locations.size() ? hotkey_prefix_locations[index+1] : text_without_hotkey_prefix.size()) - hotkey_prefix_locations[index] - 1;
         g.draw_string(text_without_hotkey_prefi.substring(hotkey_prefix_locations[index], chunk_size), font, solid_brush(text_color), button_rect, to_string_format(flags));
         }
         */
        native::graphics::draw_string(handle(), drawable_line, font.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height), static_cast<const solid_brush&>(brush).color().a(), static_cast<const solid_brush&>(brush).color().r(), static_cast<const solid_brush&>(brush).color().g(), static_cast<const solid_brush&>(brush).color().b());
      }
      
      y += line_size.height();
    }
  }
}

void graphics::draw_string(const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& layout_rectangle) {
  draw_string(text, font, brush, layout_rectangle, string_format());
}

void graphics::draw_string(const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::point_f& point, const string_format& format) {
  draw_string(text, font, brush, point.x(), point.y(), format);
}

void graphics::draw_string(const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::brush& brush, const xtd::drawing::point_f& point) {
  draw_string(text, font, brush, point.x(), point.y(), string_format());
}

void graphics::draw_string(const ustring& text, const font& font, const brush& brush, float x, float y, const string_format& format) {
  if (dynamic_cast<const solid_brush*>(&brush) != nullptr)
    native::graphics::draw_string(handle(), text, font.handle(), to_pixels(x), to_pixels(y), static_cast<const solid_brush&>(brush).color().a(), static_cast<const solid_brush&>(brush).color().r(), static_cast<const solid_brush&>(brush).color().g(), static_cast<const solid_brush&>(brush).color().b());
}

void graphics::draw_string(const xtd::ustring& text, const xtd::drawing::font& font, const xtd::drawing::brush& brush, float x, float y) {
  draw_string(text, font, brush, x, y, string_format());
}

void graphics::fill_ellipse(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect) {
  fill_ellipse(brush, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::fill_ellipse(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect) {
  fill_ellipse(brush, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::fill_ellipse(const brush& brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  fill_ellipse(brush, static_cast<float>(x), static_cast<float>(y), static_cast<float>(width), static_cast<float>(height));
}

void graphics::fill_ellipse(const xtd::drawing::brush& brush, float x, float y, float width, float height) {
  native::graphics::fill_ellipse(handle(), brush.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height));
}

void graphics::fill_path(const brush& brush, const drawing2d::graphics_path& path) {
  native::graphics::fill_path(handle(), brush.handle(), path.handle(), static_cast<int32_t>(path.fill_mode()));
}

void graphics::fill_pie(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle) {
  fill_pie(brush, rect.x(), rect.y(), rect.width(), rect.height(), static_cast<int32_t>(start_angle), static_cast<int32_t>(sweep_angle));
}

void graphics::fill_pie(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle) {
  fill_pie(brush, rect.x(), rect.y(), rect.width(), rect.height(), start_angle, sweep_angle);
}

void graphics::fill_pie(const brush& brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  fill_pie(brush, static_cast<float>(x), static_cast<float>(y), static_cast<float>(width), static_cast<float>(height), static_cast<float>(start_angle), static_cast<float>(sweep_angle));
}

void graphics::fill_pie(const xtd::drawing::brush& brush, float x, float y, float width, float height, float start_angle, float sweep_angle) {
  native::graphics::fill_pie(handle(), brush.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height), start_angle, sweep_angle);
}

void graphics::fill_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle& rect) {
  fill_rectangle(brush, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::fill_rectangle(const xtd::drawing::brush& brush, const xtd::drawing::rectangle_f& rect) {
  fill_rectangle(brush, rect.x(), rect.y(), rect.width(), rect.height());
}

void graphics::fill_rectangle(const brush& brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  fill_rectangle(brush, static_cast<float>(x), static_cast<float>(y), static_cast<float>(width), static_cast<float>(height));
}

void graphics::fill_rectangle(const xtd::drawing::brush& brush, float x, float y, float width, float height) {
  native::graphics::fill_rectangle(handle(), brush.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height));
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
  fill_rounded_rectangle(brush, static_cast<float>(x), static_cast<float>(y), static_cast<float>(width), static_cast<float>(height), static_cast<float>(radius));
}

void graphics::fill_rounded_rectangle(const xtd::drawing::brush& brush, float x, float y, float width, float height, float radius) {
  native::graphics::fill_rounded_rectangle(handle(), brush.handle(), to_pixels(x), to_pixels(y), to_pixels(width), to_pixels(height), to_pixels(radius));
}

graphics graphics::from_image(const image& image) {
  return graphics(native::graphics::from_image(image.handle()));
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
  translate_clip(static_cast<float>(dx), static_cast<float>(dy));
}

void graphics::translate_clip(float dx, float dy) {
  native::graphics::translate_clip(handle(), to_pixels(dx), to_pixels(dy));
}

float graphics::to_pixels(float value) const {
  switch (data_->page_unit) {
    case graphics_unit::world:
    case graphics_unit::display:
    case graphics_unit::pixel: return value;
    case graphics_unit::point: return value * 96.0f / dpi_x();
    case graphics_unit::inch: return value * 96.0f / dpi_x();
    case graphics_unit::document: return value * 96.0f / 300.0f / dpi_x();
    case graphics_unit::millimeter: return value * 96.0f / 25.4f / dpi_x();
    default: return value;
  }
}

float graphics::to_page_unit(float value) const {
  switch (data_->page_unit) {
    case graphics_unit::world:
    case graphics_unit::display:
    case graphics_unit::pixel: return value;
    case graphics_unit::point: return value / 96.0f * dpi_x();
    case graphics_unit::inch: return value / 96.0f * dpi_x();
    case graphics_unit::document: return value / 96.0f * 300.0f * dpi_x();
    case graphics_unit::millimeter: return value / 96.0f * 25.4f * dpi_x();
    default: return value;
  }
}
