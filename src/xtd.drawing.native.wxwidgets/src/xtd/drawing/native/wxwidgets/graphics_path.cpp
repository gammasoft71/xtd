#include <map>
#include <vector>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/graphics_path.h>
#include <xtd/drawing/native/toolkit.h>
#include "../../../../../include/xtd/drawing/native/hdc_wrapper.h"
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <wx/colour.h>
#include <wx/graphics.h>

using namespace std;
using namespace xtd::drawing::native;

intptr_t graphics_path::create() {
  toolkit::initialize(); // Must be first
  wxMemoryDC mdc;
  wxGraphicsContext* mgc = wxGraphicsContext::Create(mdc);
  return reinterpret_cast<intptr_t>(new wxGraphicsPath(mgc->CreatePath()));
}

void graphics_path::destroy(intptr_t handle) {
  delete reinterpret_cast<wxGraphicsPath*>(handle);
}


void graphics_path::add_rectangle(intptr_t handle, float x, float y, float width, float height) {
  reinterpret_cast<wxGraphicsPath*>(handle)->AddRectangle(x, y, width, height);
}
