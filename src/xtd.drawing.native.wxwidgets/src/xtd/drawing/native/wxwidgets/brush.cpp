#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/brush.h>
#include <xtd/drawing/native/system_colors.h>
#include <xtd/drawing/native/toolkit.h>
#include "../../../../../include/xtd/drawing/native/wx_brush.h"
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <algorithm>
#include <wx/colour.h>

using namespace std;
using namespace xtd::drawing::native;

intptr_t brush::create() {
  toolkit::initialize(); // Must be first
  return reinterpret_cast<intptr_t>(new wx_brush());
}

void brush::solid(intptr_t brush, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  reinterpret_cast<wx_brush*>(brush)->create_solid_brush({r, g, b, a});
}

void brush::linear_gradient(intptr_t brush, int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint8_t a1, uint8_t r1, uint8_t g1, uint8_t b1, uint8_t a2, uint8_t r2, uint8_t g2, uint8_t b2, float angle) {
  if (angle <= 22) angle = 0;
  else if (angle <= 67) angle = 45;
  else if (angle <= 112) angle = 90;
  else if (angle <= 157) angle = 135;
  else if (angle <= 202) angle = 180;
  else if (angle <= 247) angle = 225;
  else if (angle <= 292) angle = 270;
  else if (angle <= 337) angle = 315;
  else if (angle <= 359) angle = 0;
  
  auto p1 = wxPoint(x1, y1);
  auto p2 = wxPoint(x2, y2);
  auto c1 = wxColour(r1, g1, b1, a1);
  auto c2 = wxColour(r2, g2, b2, a2);
  
  if (angle == 0 || angle == 180) p2.y = p1.y;
  if (angle == 90 || angle == 270) p2.x = p1.x;
  if (angle == 135 || angle == 315) swap(p1.x, p2.x);

  if (angle == 180 || angle == 225 || angle == 270 || angle == 315) swap(c1, c2);
  
  reinterpret_cast<wx_brush*>(brush)->create_linear_gradiant_brush(p1, p2, c1, c2);
}

void brush::texture(intptr_t brush, intptr_t texture) {
  reinterpret_cast<wx_brush*>(brush)->create_texture_brush(*reinterpret_cast<wxImage*>(texture));
}

void brush::destroy(intptr_t brush) {
  delete reinterpret_cast<wx_brush*>(brush);
}
