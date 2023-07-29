#include <cmath>
#include <xtd/drawing/native/graphics.hpp>
#include "../../../../../include/xtd/drawing/native/fl_brush.hpp"
#include "../../../../../include/xtd/drawing/native/fl_dc.hpp"
#include "../../../../../include/xtd/drawing/native/fl_font.hpp"
#include "../../../../../include/xtd/drawing/native/fl_pen.hpp"

using namespace xtd::drawing::native;

void graphics::clear(intmax_t hdc, uint_least8_t a, uint_least8_t r, uint_least8_t g, uint_least8_t b) {
  if (hdc == 0) return;
  reinterpret_cast<fl_dc*>(hdc)->clear(fl_rgb_color(r, g, b));
}

void graphics::draw_arc(intmax_t hdc, intmax_t pen, int_least32_t x, int_least32_t y, int_least32_t width, int_least32_t height, int_least32_t start_angle, int_least32_t sweep_angle) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->draw_arc(reinterpret_cast<fl_pen*>(pen)->color(), reinterpret_cast<fl_pen*>(pen)->width(), reinterpret_cast<fl_pen*>(pen)->style(), x, y, width, height, start_angle, sweep_angle);
}

void graphics::draw_bezier(intmax_t hdc, intmax_t pen, int_least32_t x1, int_least32_t y1, int_least32_t x2, int_least32_t y2, int_least32_t x3, int_least32_t y3, int_least32_t x4, int_least32_t y4) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->draw_bezier(reinterpret_cast<fl_pen*>(pen)->color(), reinterpret_cast<fl_pen*>(pen)->width(), reinterpret_cast<fl_pen*>(pen)->style(), x1, y1, x2, y2, x3, y3, x4, y4);
}

void graphics::draw_ellipse(intmax_t hdc, intmax_t pen, int_least32_t x, int_least32_t y, int_least32_t width, int_least32_t height) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->draw_ellipse(reinterpret_cast<fl_pen*>(pen)->color(), reinterpret_cast<fl_pen*>(pen)->width(), reinterpret_cast<fl_pen*>(pen)->style(), x, y, width, height);
}

void graphics::destroy(intmax_t hdc) {
  if (!hdc) return;
  fl_dc* fldc = reinterpret_cast<fl_dc*>(hdc);
  delete fldc;
}

void graphics::draw_line(intmax_t hdc, intmax_t pen, int_least32_t x1, int_least32_t y1, int_least32_t x2, int_least32_t y2) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->draw_line(reinterpret_cast<fl_pen*>(pen)->color(), reinterpret_cast<fl_pen*>(pen)->width(), reinterpret_cast<fl_pen*>(pen)->style(), x1, y1, x2, y2);
}

void graphics::draw_rectangle(intmax_t hdc, intmax_t pen, int_least32_t x, int_least32_t y, int_least32_t width, int_least32_t height) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->draw_rectangle(reinterpret_cast<fl_pen*>(pen)->color(), reinterpret_cast<fl_pen*>(pen)->width(), reinterpret_cast<fl_pen*>(pen)->style(), x, y, width, height);
}

void graphics::draw_string(intmax_t hdc, const std::string& text, intmax_t font, int_least32_t x, int_least32_t y, uint_least8_t a, uint_least8_t r, uint_least8_t g, uint_least8_t b) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->draw_string(text, x, y, reinterpret_cast<class fl_font*>(font)->font(), reinterpret_cast<class fl_font*>(font)->size(), fl_rgb_color(r, g, b));
}

void graphics::draw_string(intmax_t hdc, const std::string& text, intmax_t font, int_least32_t x, int_least32_t y, int_least32_t w, int_least32_t h, uint_least8_t a, uint_least8_t r, uint_least8_t g, uint_least8_t b) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->draw_string(text, x, y, w, h, reinterpret_cast<class fl_font*>(font)->font(), reinterpret_cast<class fl_font*>(font)->size(), fl_rgb_color(r, g, b));
}

void graphics::fill_ellipse(intmax_t hdc, intmax_t brush, int_least32_t x, int_least32_t y, int_least32_t width, int_least32_t height) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->fill_ellipse(reinterpret_cast<fl_brush*>(brush)->color(), x, y, width, height);
}

void graphics::fill_pie(intmax_t hdc, intmax_t brush, int_least32_t x, int_least32_t y, int_least32_t width, int_least32_t height, int_least32_t start_angle, int_least32_t sweep_angle) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->fill_pie(reinterpret_cast<fl_brush*>(brush)->color(), x, y, width, height, start_angle, sweep_angle);
}

void graphics::fill_rectangle(intmax_t hdc, intmax_t brush, int_least32_t x, int_least32_t y, int_least32_t width, int_least32_t height) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->fill_rectangle(reinterpret_cast<fl_brush*>(brush)->color(), x, y, width, height);
}

void graphics::measure_string(intmax_t hdc, const std::string& text, intmax_t font, int_least32_t& width, int_least32_t& height) {
  if (!hdc) return;
  reinterpret_cast<fl_dc*>(hdc)->measure_string(text, reinterpret_cast<class fl_font*>(font)->font(), reinterpret_cast<class fl_font*>(font)->size(), width, height);
}
