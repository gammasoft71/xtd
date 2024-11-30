#include <xtd/drawing/native/brush>
#include "../../../../../include/xtd/drawing/native/fl_brush.hpp"

using namespace xtd::drawing::native;

intmax_t brush::create() {
  return reinterpret_cast<intmax_t>(new fl_brush());
}

void brush::color(intmax_t brush, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  reinterpret_cast<fl_brush*>(brush)->color(fl_rgb_color(r, g, b));
}

void brush::destroy(intmax_t brush) {
  delete reinterpret_cast<fl_brush*>(brush);
}
