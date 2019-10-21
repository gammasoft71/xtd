#include <xtd/drawing/native/pen.hpp>
#include "../../../../../include/xtd/drawing/native/fl_pen.hpp"

using namespace xtd::drawing::native;

intptr_t pen::create() {
  return reinterpret_cast<intptr_t>(new fl_pen());
}

void pen::color(intptr_t pen, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  reinterpret_cast<fl_pen*>(pen)->color(fl_rgb_color(r, g, b));
}

void pen::width(intptr_t pen, float width) {
  reinterpret_cast<fl_pen*>(pen)->width(static_cast<int>(width));
}

void pen::destroy(intptr_t pen) {
  delete reinterpret_cast<fl_pen*>(pen);
}
