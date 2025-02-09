#include "../../../include/xtd/drawing/brush.hpp"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/brush>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/type_object>

using namespace xtd;
using namespace xtd::drawing;

struct brush::data {
  intptr handle = 0;
};

brush::brush() : data_(xtd::new_sptr<data>()) {
  set_native_brush(native::brush::create());
}

brush::brush(const brush& value) : data_(xtd::new_sptr<data>()) {
  if (data_.use_count() == 1 && data_->handle != 0) native::brush::destroy(data_->handle);
  data_ = value.data_;
}

brush& brush::operator =(const brush& value) {
  if (data_.use_count() == 1 && data_->handle != 0) native::brush::destroy(data_->handle);
  data_ = value.data_;
  return *this;
}

brush::~brush() {
  if (data_.use_count() == 1 && data_->handle != 0) native::brush::destroy(data_->handle);
}

intptr brush::handle() const noexcept {
  return data_->handle;
}

bool brush::equals(const object& obj) const noexcept {
  return is<brush>(obj) && equals(static_cast<const brush&>(obj));
}

bool brush::equals(const brush& other) const noexcept {
  return data_->handle == other.data_->handle;
}

size brush::get_hash_code() const noexcept {
  return hash_code::combine(data_->handle);
}

string brush::to_string() const noexcept {
  return get_type().full_name();
}

void brush::set_native_brush(intptr brush) {
  data_->handle = brush;
}
