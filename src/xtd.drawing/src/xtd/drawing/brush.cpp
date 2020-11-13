#include "../../../include/xtd/drawing/brush.h"
#include <xtd/drawing/native/brush.h>

using namespace xtd;
using namespace xtd::drawing;

brush::brush() {
  this->data_->handle_ = native::brush::create();
}

brush::brush(const brush& value) {
  if (this->data_.use_count() == 1 && this->data_->handle_ != 0) native::brush::destroy(this->data_->handle_);
  this->data_ = value.data_;
}

brush& brush::operator=(const brush& value) {
  if (this->data_.use_count() == 1 && this->data_->handle_ != 0) native::brush::destroy(this->data_->handle_);
  this->data_ = value.data_;
  return *this;
}

brush::~brush() {
  if (this->data_.use_count() == 1 && this->data_->handle_ != 0) native::brush::destroy(this->data_->handle_);
}
