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

intptr_t matrix::create(float m11, float m12, float m21, float m22, float dx, float dy) {
  toolkit::initialize(); // Must be first
  wxMemoryDC mdc;
  wxGraphicsContext* mgc = wxGraphicsContext::Create(mdc);
  return reinterpret_cast<intptr_t>(new wxGraphicsMatrix(mgc->CreateMatrix(m11, m12, m22, dx, dy)));
}

void matrix::destroy(intptr_t handle) {
  delete reinterpret_cast<wxGraphicsMatrix*>(handle);
}

std::vector<float> matrix::elenents(intptr_t handle) {
  double m11 = 1.0, m12 = 0.0, m21 = 0.0, m22 = 1.0, dx = 0.0, dy = 0.0;
  if (handle) reinterpret_cast<wxGraphicsMatrix*>(handle)->Get(&m11, &m12, &m21, &m22, &dx, &dy);
  return {as<float>(m11), as<float>(m12), as<float>(m21), as<float>(m22), as<float>(dx), as<float>(dy)};
}

bool is_identity(intptr_t handle) {
  if (!handle) return false;
  return reinterpret_cast<wxGraphicsMatrix*>(handle)->IsIdentity();
}

bool is_invertible(intptr_t handle) {
  if (!handle) return false;
  return true;
}
