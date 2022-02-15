#include <stdexcept>
#include "../../../../include/xtd/drawing/drawing2d/graphics_path.h"
#include "../../../../include/xtd/drawing/graphics.h"
#include <xtd/argument_exception.h>
#include <xtd/as.h>
#include <xtd/is.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/graphics_path.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;

graphics_path::graphics_path() {
  data_->handle = native::graphics_path::create();
}

graphics_path::~graphics_path() {
  if (data_.use_count() == 1 && data_->handle != 0) native::graphics_path::destroy(data_->handle);
}

bool graphics_path::operator==(const graphics_path& value) const {
  return data_ == value.data_;
}

bool graphics_path::operator!=(const graphics_path& value) const {
  return !operator==(value);
}

intptr_t graphics_path::handle() const noexcept {
  return data_->handle;
}

void graphics_path::add_rectangle(const rectangle& rect) {
  add_rectangle(rectangle_f(rect));
}
void graphics_path::add_rectangle(const rectangle_f& rect) {
  native::graphics_path::add_rectangle(data_->handle, rect.x(), rect.y(), rect.width(), rect.height());
}

xtd::ustring graphics_path::to_string() const noexcept {
  return ustring::full_class_name(*this);
}
