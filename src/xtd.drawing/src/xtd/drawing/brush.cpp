#include "../../../include/xtd/drawing/brush.h"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/brush.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;

brush::brush() {
  set_native_brush(native::brush::create());
}

brush::brush(const brush& value) {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::brush::destroy(data_->handle_);
  data_ = value.data_;
}

brush& brush::operator=(const brush& value) {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::brush::destroy(data_->handle_);
  data_ = value.data_;
  return *this;
}

brush::~brush() {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::brush::destroy(data_->handle_);
}

void brush::set_native_brush(intptr_t brush) {
  data_->handle_ = brush;
}
