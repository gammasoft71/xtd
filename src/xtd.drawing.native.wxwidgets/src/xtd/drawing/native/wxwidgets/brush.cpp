#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/brush.h>
#include <xtd/drawing/native/system_colors.h>
#include <xtd/drawing/native/toolkit.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include "../../../../../include/xtd/drawing/native/wx_brush.h"
#include <wx/colour.h>

using namespace xtd::drawing::native;

intptr_t brush::create() {
  toolkit::initialize(); // Must be first
  return reinterpret_cast<intptr_t>(new wx_brush());
}

void brush::solid(intptr_t brush, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  reinterpret_cast<wx_brush*>(brush)->create_solid_brush({r, g, b, a});
}

void brush::linear_gradient(intptr_t brush, int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint8_t a1, uint8_t r1, uint8_t g1, uint8_t b1, uint8_t a2, uint8_t r2, uint8_t g2, uint8_t b2) {
  reinterpret_cast<wx_brush*>(brush)->create_linear_gradiant_brush({x1, y1}, {x2, y2}, {r1, g1, b1, a1}, {r2, g2, b2, a2});
}

void brush::texture(intptr_t brush, intptr_t texture) {
  reinterpret_cast<wx_brush*>(brush)->create_texture_brush(*reinterpret_cast<wxImage*>(texture));
}

void brush::destroy(intptr_t brush) {
  delete reinterpret_cast<wx_brush*>(brush);
}
