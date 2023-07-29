#include <xtd/drawing/native/pen.hpp>
#include "../../../../../include/xtd/drawing/native/fl_pen.hpp"

using namespace xtd::drawing::native;

intmax_t pen::create() {
  return reinterpret_cast<intmax_t>(new fl_pen());
}

void pen::color(intmax_t pen, uint_least8_t a, uint_least8_t r, uint_least8_t g, uint_least8_t b) {
  reinterpret_cast<fl_pen*>(pen)->color(fl_rgb_color(r, g, b));
}

void pen::width(intmax_t pen, float width) {
  reinterpret_cast<fl_pen*>(pen)->width(static_cast<int>(width));
}

void pen::destroy(intmax_t pen) {
  delete reinterpret_cast<fl_pen*>(pen);
}
