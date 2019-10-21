#include <cmath>
#include <xtd/drawing/native/graphics.hpp>
#include "../../../../../include/xtd/drawing/native/fl_brush.hpp"
#include "../../../../../include/xtd/drawing/native/fl_dc.hpp"
#include "../../../../../include/xtd/drawing/native/fl_font.hpp"
#include "../../../../../include/xtd/drawing/native/fl_pen.hpp"

using namespace xtd::drawing::native;

void graphics::clear(intptr_t hdc, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (hdc == 0) return;
  reinterpret_cast<fl_dc*>(hdc)->clear(fl_rgb_color(r, g, b));
}

void graphics::draw_arc(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->draw_arc(reinterpret_cast<fl_pen*>(pen)->color(), reinterpret_cast<fl_pen*>(pen)->width(), reinterpret_cast<fl_pen*>(pen)->style(), x, y, width, height, start_angle, sweep_angle);
}

void graphics::draw_bezier(intptr_t hdc, intptr_t pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x3, int32_t y3, int32_t x4, int32_t y4) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->draw_bezier(reinterpret_cast<fl_pen*>(pen)->color(), reinterpret_cast<fl_pen*>(pen)->width(), reinterpret_cast<fl_pen*>(pen)->style(), x1, y1, x2, y2, x3, y3, x4, y4);
}

void graphics::draw_ellipse(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->draw_ellipse(reinterpret_cast<fl_pen*>(pen)->color(), reinterpret_cast<fl_pen*>(pen)->width(), reinterpret_cast<fl_pen*>(pen)->style(), x, y, width, height);
}

void graphics::destroy(intptr_t hdc) {
  if (!hdc) return;
  fl_dc* fldc = reinterpret_cast<fl_dc*>(hdc);
  delete fldc;
}

void graphics::draw_line(intptr_t hdc, intptr_t pen, int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->draw_line(reinterpret_cast<fl_pen*>(pen)->color(), reinterpret_cast<fl_pen*>(pen)->width(), reinterpret_cast<fl_pen*>(pen)->style(), x1, y1, x2, y2);
}

void graphics::draw_rectangle(intptr_t hdc, intptr_t pen, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->draw_rectangle(reinterpret_cast<fl_pen*>(pen)->color(), reinterpret_cast<fl_pen*>(pen)->width(), reinterpret_cast<fl_pen*>(pen)->style(), x, y, width, height);
}

void graphics::draw_string(intptr_t hdc, const std::string& text, intptr_t font, int32_t x, int32_t y, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->draw_string(text, x, y, reinterpret_cast<class fl_font*>(font)->font(), reinterpret_cast<class fl_font*>(font)->size(), fl_rgb_color(r, g, b));
}

void graphics::draw_string(intptr_t hdc, const std::string& text, intptr_t font, int32_t x, int32_t y, int32_t w, int32_t h, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->draw_string(text, x, y, w, h, reinterpret_cast<class fl_font*>(font)->font(), reinterpret_cast<class fl_font*>(font)->size(), fl_rgb_color(r, g, b));
}

void graphics::fill_ellipse(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->fill_ellipse(reinterpret_cast<fl_brush*>(brush)->color(), x, y, width, height);
}

void graphics::fill_pie(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height, int32_t start_angle, int32_t sweep_angle) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->fill_pie(reinterpret_cast<fl_brush*>(brush)->color(), x, y, width, height, start_angle, sweep_angle);
}

void graphics::fill_rectangle(intptr_t hdc, intptr_t brush, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->fill_rectangle(reinterpret_cast<fl_brush*>(brush)->color(), x, y, width, height);
}

void graphics::measure_string(intptr_t hdc, const std::string &text, intptr_t font, int32_t &width, int32_t &height) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->measure_string(text, reinterpret_cast<class fl_font*>(font)->font(), reinterpret_cast<class fl_font*>(font)->size(), width, height);
}
