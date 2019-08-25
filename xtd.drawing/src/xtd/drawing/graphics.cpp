#include "../../../include/xtd/drawing/graphics.hpp"
#include <xtd/drawing/native/graphics.hpp>

using namespace xtd;
using namespace xtd::drawing;

graphics::~graphics() {
  if (this->hdc_ != 0) native::graphics::destroy(this->hdc_);
}

void graphics::clear(const color& color) {
  native::graphics::clear(this->hdc_, color.a(), color.r(), color.g(), color.b());
}

void graphics::draw_arc(const pen& pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  native::graphics::draw_arc(this->hdc_, pen.handle_, x, y, width, height, start_angle, sweep_angle);
}

void graphics::draw_line(const pen& pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
  native::graphics::draw_line(this->hdc_, pen.handle_, x1, y1, x2, y2);
}

void graphics::draw_rectangle(const pen& pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  native::graphics::draw_rectangle(this->hdc_, pen.handle_, x, y, width, height);
}

void graphics::fill_rectangle(const brush& brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  native::graphics::fill_rectangle(this->hdc_, brush.handle_, x, y, width, height);
}
