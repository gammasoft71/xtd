#include <xtd/drawing/native/pen.h>
#include <wx/colour.h>
#include <wx/pen.h>

using namespace xtd::drawing::native;

intptr_t pen::create() {
  return reinterpret_cast<intptr_t>(new wxPen());
}

void pen::color(intptr_t pen, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  reinterpret_cast<wxPen*>(pen)->SetColour(wxColour(r, g, b, a));
}

void pen::width(intptr_t pen, float width) {
  reinterpret_cast<wxPen*>(pen)->SetWidth(static_cast<int>(width));
}

void pen::destroy(intptr_t pen) {
  delete reinterpret_cast<wxPen*>(pen);
}
