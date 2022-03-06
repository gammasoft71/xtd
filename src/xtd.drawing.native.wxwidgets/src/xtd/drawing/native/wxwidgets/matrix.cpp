#include <map>
#include <vector>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/matrix.h>
#include <xtd/drawing/native/toolkit.h>
#include "../../../../../include/xtd/drawing/native/hdc_wrapper.h"
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <wx/graphics.h>
#include <xtd/as.h>

using namespace std;
using namespace xtd::drawing::native;

intptr_t matrix::create() {
  toolkit::initialize(); // Must be first
  wxMemoryDC mdc;
  wxGraphicsContext* mgc = wxGraphicsContext::Create(mdc);
  return reinterpret_cast<intptr_t>(new wxGraphicsMatrix(mgc->CreateMatrix()));
}

void matrix::destroy(intptr_t handle) {
  delete reinterpret_cast<wxGraphicsMatrix*>(handle);
}
