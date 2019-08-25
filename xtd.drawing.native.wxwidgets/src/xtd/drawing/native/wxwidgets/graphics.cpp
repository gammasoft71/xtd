#include <xtd/drawing/native/graphics.hpp>
#include <wx/dc.h>
#include <wx/dcgraph.h>

using namespace xtd::drawing::native;

intptr_t graphics::create_graphics() {
  return reinterpret_cast<intptr_t>(new wxGCDC());
}

void graphics::destroy(intptr_t hdc) {
  delete reinterpret_cast<wxDC*>(hdc);
}
