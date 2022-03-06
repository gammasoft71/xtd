#include <stdexcept>
#include "../../../../include/xtd/drawing/drawing2d/matrix.h"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/matrix.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;

matrix::matrix() : matrix(1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f) {
}

matrix::matrix(float m11, float m12, float m21, float m22, float dx, float dy) {
  data_->handle = native::matrix::create(m11, m12, m21, m22, dx, dy);
}

matrix::~matrix() {
  if (data_.use_count() == 1 && data_->handle != 0) {
    native::matrix::destroy(data_->handle);
    data_->handle = 0;
  }
}

bool matrix::operator==(const matrix& value) const {
  return data_ == value.data_;
}

bool matrix::operator!=(const matrix& value) const {
  return !operator==(value);
}

std::vector<float> matrix::elements() const {
  return native::matrix::elenents(handle());
}

intptr_t matrix::handle() const noexcept {
  return data_->handle;
}

bool matrix::is_identity() const {
  return native::matrix::is_identity(handle());
}

bool matrix::is_invertible() const {
  return native::matrix::is_invertible(handle());
}

float matrix::offset_x() const {
  return elements()[4];
}

float matrix::offset_y() const {
  return elements()[5];
}

xtd::ustring matrix::to_string() const noexcept {
  return ustring::full_class_name(*this);
}
