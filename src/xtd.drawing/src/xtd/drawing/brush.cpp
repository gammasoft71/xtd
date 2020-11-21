#include "../../../include/xtd/drawing/brush.h"
#include <xtd/drawing/native/brush.h>

using namespace xtd;
using namespace xtd::drawing;

brush::brush() {
  data_->handle_ = native::brush::create();
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
