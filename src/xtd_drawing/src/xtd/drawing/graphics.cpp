#include "../../../include/xtd/drawing/graphics.h"
#include "../../../include/xtd/drawing/solid_brush.h"
#include <xtd/drawing/native/graphics.h>

using namespace xtd;
using namespace xtd::drawing;

graphics::graphics(const graphics& value) {
  if (this->data_.use_count() == 1 && this->data_->handle_ != 0) native::graphics::destroy(this->data_->handle_);
  this->data_ = value.data_;
}

graphics& graphics::operator=(const graphics& value) {
  if (this->data_.use_count() == 1 && this->data_->handle_ != 0) native::graphics::destroy(this->data_->handle_);
  this->data_ = value.data_;
  return *this;
}

graphics::~graphics() {
  if (this->data_.use_count() == 1 && this->data_->handle_ != 0) native::graphics::destroy(this->data_->handle_);
}

void graphics::clear(const color& color) {
  native::graphics::clear(this->data_->handle_, color.a(), color.r(), color.g(), color.b());
}

void graphics::draw_arc(const pen& pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  native::graphics::draw_arc(this->data_->handle_, pen.data_->handle_, x, y, width, height, start_angle, sweep_angle);
}

void graphics::draw_bezier(const pen& pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, int32_t x4, int32_t y4) {
  native::graphics::draw_bezier(this->data_->handle_, pen.data_->handle_, x1, y1, x2, y2, x3, y3, x4, y4);
}

void graphics::draw_ellipse(const pen& pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  native::graphics::draw_ellipse(this->data_->handle_, pen.data_->handle_, x, y, width, height);
}

void graphics::draw_image(const image& image, int32_t x, int32_t y) {
  native::graphics::draw_image(this->data_->handle_, image.handle(), x, y);
}

void graphics::draw_line(const pen& pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
  native::graphics::draw_line(this->data_->handle_, pen.data_->handle_, x1, y1, x2, y2);
}

void graphics::draw_rectangle(const pen& pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  native::graphics::draw_rectangle(this->data_->handle_, pen.data_->handle_, x, y, width, height);
}

void graphics::draw_string(const std::string& text, const font& font, const brush& brush, float x, float y, const string_format& format) {
  if (dynamic_cast<const solid_brush*>(&brush) != nullptr)
    native::graphics::draw_string(this->data_->handle_, text, font.data_->handle_, static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<const solid_brush&>(brush).color().a(), static_cast<const solid_brush&>(brush).color().r(), static_cast<const solid_brush&>(brush).color().g(), static_cast<const solid_brush&>(brush).color().b());
}

void graphics::draw_string(const std::string& text, const font& font, const brush& brush, const rectangle_f& layout_rectangle, const string_format& format) {
  if (dynamic_cast<const solid_brush*>(&brush) != nullptr) {
    auto text_size = measure_string(text, font);
    auto x = layout_rectangle.x();
    auto y = layout_rectangle.y();
    auto width = layout_rectangle.width();
    auto height = layout_rectangle.height();

    if (format.alignment() == string_alignment::center) {
      x += (layout_rectangle.width() - text_size.width()) / 2;
      width -= (layout_rectangle.width() - text_size.width()) / 2;
    } else  if (format.alignment() == string_alignment::far) {
      x += (layout_rectangle.width() - text_size.width());
      width -= (layout_rectangle.width() - text_size.width());
    }
    
    if (format.line_alignment() == string_alignment::center) {
      y += (layout_rectangle.height() - text_size.height()) / 2;
      height -= (layout_rectangle.height() - text_size.height()) / 2;
    } else  if (format.line_alignment() == string_alignment::far) {
      y += (layout_rectangle.height() - text_size.height());
      height -= (layout_rectangle.height() - text_size.height());
    }
    
    native::graphics::draw_string(this->data_->handle_, text, font.data_->handle_, static_cast<int32_t>(x), static_cast<int32_t>(y), static_cast<int32_t>(width), static_cast<int32_t>(height), static_cast<const solid_brush&>(brush).color().a(), static_cast<const solid_brush&>(brush).color().r(), static_cast<const solid_brush&>(brush).color().g(), static_cast<const solid_brush&>(brush).color().b());
  }
}

void graphics::fill_ellipse(const brush& brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  native::graphics::fill_ellipse(this->data_->handle_, brush.data_->handle_, x, y, width, height);
}

void graphics::fill_pie(const brush& brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  native::graphics::fill_pie(this->data_->handle_, brush.data_->handle_, x, y, width, height, start_angle, sweep_angle);
}

void graphics::fill_rectangle(const brush& brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  native::graphics::fill_rectangle(this->data_->handle_, brush.data_->handle_, x, y, width, height);
}

size_f graphics::measure_string(const std::string &text, const font &font) {
  int32_t width = 0;
  int32_t height = 0;
  native::graphics::measure_string(this->data_->handle_, text, font.handle(), width, height);
  return size_f(static_cast<float>(width), static_cast<float>(height));
}
