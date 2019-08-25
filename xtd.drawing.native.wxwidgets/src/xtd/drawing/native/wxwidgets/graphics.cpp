#include <xtd/drawing/native/graphics.hpp>
#include <wx/dc.h>
#include <wx/dcgraph.h>

using namespace xtd::drawing::native;

void graphics::clear(intptr_t hdc, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  reinterpret_cast<wxDC*>(hdc)->SetBackground(wxBrush(wxColour(r, g, b, a)));
  reinterpret_cast<wxDC*>(hdc)->Clear();
  
}

intptr_t graphics::create() {
  return reinterpret_cast<intptr_t>(new wxGCDC());
}

void graphics::destroy(intptr_t hdc) {
  delete reinterpret_cast<wxDC*>(hdc);
}
