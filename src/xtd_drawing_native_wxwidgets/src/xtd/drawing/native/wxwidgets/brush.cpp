#include <xtd/drawing/native/brush.h>
#include <xtd/drawing/native/system_colors.h>
#include <wx/brush.h>
#include <wx/colour.h>

using namespace xtd::drawing::native;

intptr_t brush::create() {
  return reinterpret_cast<intptr_t>(new wxBrush());
}

void brush::color(intptr_t brush, intptr_t handle, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
#if defined (__WXOSX__)
  if (handle && !drawing::native::system_colors::force_set_system_color())
    reinterpret_cast<wxBrush*>(brush)->SetColour(wxColour(reinterpret_cast<WX_NSColor>(handle)));
  else
    reinterpret_cast<wxBrush*>(brush)->SetColour(wxColour(r, g, b, a));
#else
  reinterpret_cast<wxBrush*>(brush)->SetColour(wxColour(r, g, b, a));
#endif
}

void brush::destroy(intptr_t brush) {
  delete reinterpret_cast<wxBrush*>(brush);
}
