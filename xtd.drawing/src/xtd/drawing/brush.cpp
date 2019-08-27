#include "../../../include/xtd/drawing/brush.hpp"
#include <xtd/drawing/native/brush.hpp>

using namespace xtd;
using namespace xtd::drawing;

brush::brush() {
  this->data_->handle_ = native::brush::create();
}

brush::~brush() {
  if (this->data_.use_count() == 1 && this->data_->handle_ != 0) native::brush::destroy(this->data_->handle_);
}
