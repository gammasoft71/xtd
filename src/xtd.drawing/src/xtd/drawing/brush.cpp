#include "../../../include/xtd/drawing/brush"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/brush>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;

struct brush::data {
  intptr handle_ = 0;
};

brush::brush() : data_(std::make_shared<data>()) {
  set_native_brush(native::brush::create());
}

brush::brush(const brush& value) : data_(std::make_shared<data>()) {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::brush::destroy(data_->handle_);
  data_ = value.data_;
}

brush& brush::operator =(const brush& value) {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::brush::destroy(data_->handle_);
  data_ = value.data_;
  return *this;
}

brush::~brush() {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::brush::destroy(data_->handle_);
}

intptr brush::handle() const noexcept {
  return data_->handle_;
}

bool brush::equals(const brush& value) const noexcept {
  return data_->handle_ == value.data_->handle_;
}

xtd::ustring brush::to_string() const noexcept {
  return get_type().full_name();
}

void brush::set_native_brush(intptr brush) {
  data_->handle_ = brush;
}
