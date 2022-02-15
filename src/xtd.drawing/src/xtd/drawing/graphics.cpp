#include <vector>
#include "../../../include/xtd/drawing/bitmap.h"
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
  if (data_.use_count() == 1 && data_->handle_ != 0) native::graphics::destroy(data_->handle_);
  data_ = value.data_;
}

graphics& graphics::operator=(const graphics& value) {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::graphics::destroy(data_->handle_);
  data_ = value.data_;
  return *this;
}

graphics::~graphics() {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::graphics::destroy(data_->handle_);
}

void graphics::clear(const color& color) {
  native::graphics::clear(data_->handle_, color.a(), color.r(), color.g(), color.b());
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
  native::graphics::draw_arc(data_->handle_, pen.data_->handle_, x, y, width, height, start_angle, sweep_angle);
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
  native::graphics::draw_bezier(data_->handle_, pen.data_->handle_, x1, y1, x2, y2, x3, y3, x4, y4);
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
  native::graphics::draw_ellipse(data_->handle_, pen.data_->handle_, x, y, width, height);
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
  if (size_f(width, height) == size_f(image.size()))  native::graphics::draw_image(data_->handle_, image.handle(), x, y);
  else native::graphics::draw_image(data_->handle_, bitmap(image, size(width, height)).handle(), x, y);
}

void graphics::draw_image(const image& image, int32_t x, int32_t y) {
  draw_image(image, x, y, image.size().width(), image.size().height());
}

void graphics::draw_image(const xtd::drawing::image& image, float x, float y) {
  draw_image(image, static_cast<int32_t>(x), static_cast<int32_t>(y));
}

void graphics::draw_image_disabled(const image& image, float x, float y, float brightness) {
  native::graphics::draw_image_disabled(data_->handle_, image.handle(), x, y, brightness);
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
  native::graphics::draw_line(data_->handle_, pen.data_->handle_, x1, y1, x2, y2);
}

void graphics::draw_path(const xtd::drawing::pen& pen, const xtd::drawing::drawing2d::graphics_path& graphics_path) {
  native::graphics::draw_path(data_->handle_, pen.data_->handle_, graphics_path.handle());
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
  native::graphics::draw_rectangle(data_->handle_, pen.data_->handle_, x, y, width, height);
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
  native::graphics::draw_rounded_rectangle(data_->handle_, pen.data_->handle_, x, y, width, height, radius);
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
      
      if (format.hotkey_prefix() != hotkey_prefix::show) native::graphics::draw_string(data_->handle_, drawable_line, font.data_->handle_, static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<int32_t>(width), static_cast<int32_t>(height), static_cast<const solid_brush&>(brush).color().a(), static_cast<const solid_brush&>(brush).color().r(), static_cast<const solid_brush&>(brush).color().g(), static_cast<const solid_brush&>(brush).color().b());
      else {
        /*
         for (auto index  = 0; index <hotkey_prefix_locations.size(); ++index) {
         g.draw_string(text_without_hotkey_prefix.substring(hotkey_prefix_locations[index], 1), xtd::drawing::font(font, font_style::underline), solid_brush(text_color), button_rect, to_string_format(flags));
         auto chunk_size = (index+1 < hotkey_prefix_locations.size() ? hotkey_prefix_locations[index+1] : text_without_hotkey_prefix.size()) - hotkey_prefix_locations[index] - 1;
         g.draw_string(text_without_hotkey_prefi.substring(hotkey_prefix_locations[index], chunk_size), font, solid_brush(text_color), button_rect, to_string_format(flags));
         }
         */
        native::graphics::draw_string(data_->handle_, drawable_line, font.data_->handle_, x, y, width, height, static_cast<const solid_brush&>(brush).color().a(), static_cast<const solid_brush&>(brush).color().r(), static_cast<const solid_brush&>(brush).color().g(), static_cast<const solid_brush&>(brush).color().b());
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
    native::graphics::draw_string(data_->handle_, text, font.data_->handle_, x, y, static_cast<const solid_brush&>(brush).color().a(), static_cast<const solid_brush&>(brush).color().r(), static_cast<const solid_brush&>(brush).color().g(), static_cast<const solid_brush&>(brush).color().b());
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
  native::graphics::fill_ellipse(data_->handle_, brush.data_->handle_, x, y, width, height);
}

void graphics::fill_path(const brush& brush, const drawing2d::graphics_path& graphics_path) {
  native::graphics::fill_path(data_->handle_, brush.data_->handle_, graphics_path.handle());
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
  native::graphics::fill_pie(data_->handle_, brush.data_->handle_, x, y, width, height, start_angle, sweep_angle);
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
  native::graphics::fill_rectangle(data_->handle_, brush.data_->handle_, x, y, width, height);
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
  native::graphics::fill_rounded_rectangle(data_->handle_, brush.data_->handle_, x, y, width, height, radius);
}

graphics graphics::from_image(const image& image) {
  return graphics(native::graphics::from_image(image.handle()));
}

size_f graphics::measure_string(const ustring& text, const font& font) {
  float width = 0.0f;
  float height = 0.0f;
  native::graphics::measure_string(data_->handle_, text, font.handle(), width, height);
  return size_f(width, height);
}

void graphics::rotate_transform(float angle) {
  native::graphics::rotate_transform(data_->handle_, angle);
}

void graphics::translate_clip(int32_t dx, int32_t dy) {
  translate_clip(static_cast<float>(dx), static_cast<float>(dy));
}

void graphics::translate_clip(float dx, float dy) {
  native::graphics::translate_clip(data_->handle_, dx, dy);
}
