#include <stdexcept>
#include "../../../../include/xtd/drawing/drawing2d/matrix.h"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/matrix.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;

matrix::matrix() {
  recreate_handle();
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

intptr_t matrix::handle() const noexcept {
  return data_->handle;
}

xtd::ustring matrix::to_string() const noexcept {
  return ustring::full_class_name(*this);
}

void matrix::recreate_handle() {
  if (data_->handle != 0) native::matrix::destroy(data_->handle);
  data_->handle = native::matrix::create();
}
