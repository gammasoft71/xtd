#include <xtd/drawing/native/brush.h>
#include "../../../../../include/xtd/drawing/native/fl_brush.h"

using namespace xtd::drawing::native;

intmax_t brush::create() {
  return reinterpret_cast<intmax_t>(new fl_brush());
}

void brush::color(intmax_t brush, uint_least8_t a, uint_least8_t r, uint_least8_t g, uint_least8_t b) {
  reinterpret_cast<fl_brush*>(brush)->color(fl_rgb_color(r, g, b));
}

void brush::destroy(intmax_t brush) {
  delete reinterpret_cast<fl_brush*>(brush);
}
