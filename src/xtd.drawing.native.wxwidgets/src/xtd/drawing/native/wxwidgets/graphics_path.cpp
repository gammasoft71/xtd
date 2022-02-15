#include <map>
#include <vector>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/graphics_path.h>
#include <xtd/drawing/native/toolkit.h>
#include "../../../../../include/xtd/drawing/native/hdc_wrapper.h"
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <wx/colour.h>
#include <xtd/as.h>

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

void graphics_path::get_bounds(intptr_t handle, float& x, float& y, float& width, float& height) {
  double wx_x, wx_y, wx_width, wx_height;
  reinterpret_cast<wxGraphicsPath*>(handle)->GetBox(&wx_x, &wx_y, &wx_width, &wx_height);
  x = as<float>(wx_x);
  y = as<float>(wx_y);
  width = as<float>(wx_width);
  height = as<float>(wx_height);
}
