#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/matrix>
#include <xtd/drawing/native/toolkit>
#include "../../../../../include/xtd/drawing/native/hdc_wrapper"
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/as>
#include <xtd/math>
#include <wx/graphics.h>
#include <map>
#include <vector>

using namespace std;
using namespace xtd;
using namespace xtd::drawing::native;

intptr matrix::create(float m11, float m12, float m21, float m22, float dx, float dy) {
  toolkit::initialize(); // Must be first
  wxMemoryDC mdc;
  wxGraphicsContext* mgc = wxGraphicsContext::Create(mdc);
  return reinterpret_cast<intptr>(new wxGraphicsMatrix(mgc->CreateMatrix(m11, m12, m22, dx, dy)));
}

void matrix::destroy(intptr handle) {
  delete reinterpret_cast<wxGraphicsMatrix*>(handle);
}

std::vector<float> matrix::elenents(intptr handle) {
  double m11 = 1.0, m12 = 0.0, m21 = 0.0, m22 = 1.0, dx = 0.0, dy = 0.0;
  if (handle) reinterpret_cast<wxGraphicsMatrix*>(handle)->Get(&m11, &m12, &m21, &m22, &dx, &dy);
  return {as<float>(m11), as<float>(m12), as<float>(m21), as<float>(m22), as<float>(dx), as<float>(dy)};
}

bool matrix::is_identity(intptr handle) {
  if (!handle) return false;
  return reinterpret_cast<wxGraphicsMatrix*>(handle)->IsIdentity();
}

bool matrix::is_invertible(intptr handle) {
  if (!handle) return false;
  return true;
}

void matrix::invert(intptr handle) {
  if (!handle) return;
  reinterpret_cast<wxGraphicsMatrix*>(handle)->Invert();
}

float matrix::offset_x(intptr handle) {
  double dx = 0.0, dy = 0.0;
  reinterpret_cast<wxGraphicsMatrix*>(handle)->TransformDistance(&dx, &dy);
  return as<float>(dx);
}

float matrix::offset_y(intptr handle) {
  double dx = 0.0, dy = 0.0;
  reinterpret_cast<wxGraphicsMatrix*>(handle)->TransformDistance(&dx, &dy);
  return as<float>(dy);
}

void matrix::multiply(intptr handle, intptr matrix, int32 order) {
  if (!handle) return;
  /// Does not exist on wxWidgets...
}

void matrix::reset(intptr handle) {
  if (!handle) return;
  reinterpret_cast<wxGraphicsMatrix*>(handle)->Set();
}

void matrix::rotate(intptr handle, float angle, int32 order) {
  if (!handle) return;
  reinterpret_cast<wxGraphicsMatrix*>(handle)->Rotate(math::degrees_to_radians(angle));
}

void matrix::rotate_at(intptr handle, float angle, float x, float y, int32 order) {
  if (!handle) return;
  reinterpret_cast<wxGraphicsMatrix*>(handle)->Translate(x, y);
  reinterpret_cast<wxGraphicsMatrix*>(handle)->Rotate(math::degrees_to_radians(angle));
}

void matrix::scale(intptr handle, float scale_x, float scale_y, int32 order) {
  if (!handle) return;
  reinterpret_cast<wxGraphicsMatrix*>(handle)->Scale(scale_x, scale_y);
}

void matrix::shear(intptr handle, float scale_x, float scale_y, int32 order) {
  if (!handle) return;
  /// Does not exist on wxWidgets...
}

void matrix::transform_point(intptr handle, int32& x, int32& y) {
  if (!handle) return;
  double dx = x, dy = y;
  reinterpret_cast<wxGraphicsMatrix*>(handle)->TransformPoint(&dx, &dy);
  x = as<int32>(dx);
  y = as<int32>(dy);
}

void matrix::transform_point(intptr handle, float& x, float& y) {
  if (!handle) return;
  double dx = x, dy = y;
  reinterpret_cast<wxGraphicsMatrix*>(handle)->TransformPoint(&dx, &dy);
  x = as<float>(dx);
  y = as<float>(dy);
}

void matrix::transform_vectors(intptr handle, std::vector<std::pair<int32, int32>>& points) {
  if (!handle) return;
}

void matrix::transform_vectors(intptr handle, std::vector<std::pair<float, float>>& points) {
  if (!handle) return;
}

void matrix::translate(intptr handle, float ofset_x, float offset_y, int32 order) {
  if (!handle) return;
  reinterpret_cast<wxGraphicsMatrix*>(handle)->Translate(offset_y, offset_y);
}

void matrix::vector_transform_points(intptr handle, std::vector<std::pair<int32, int32>>& points) {
  if (!handle) return;
}
