#include "../../../include/xtd/drawing/graphics.hpp"
#include <xtd/drawing/native/graphics.hpp>

using namespace xtd;
using namespace xtd::drawing;

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

void graphics::draw_line(const pen& pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
  native::graphics::draw_line(this->data_->handle_, pen.data_->handle_, x1, y1, x2, y2);
}

void graphics::draw_rectangle(const pen& pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  native::graphics::draw_rectangle(this->data_->handle_, pen.data_->handle_, x, y, width, height);
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
