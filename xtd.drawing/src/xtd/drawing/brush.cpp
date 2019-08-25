#include "../../../include/xtd/drawing/brush.hpp"
#include <xtd/drawing/native/brush.hpp>

using namespace xtd;
using namespace xtd::drawing;

brush::brush() {
  this->handle_ = native::brush::create();
}

brush::brush(const brush&) {
  this->handle_ = native::brush::create();
}

brush& brush::operator=(const brush&) {
  return *this;
}

brush::~brush() {
  native::brush::destroy(this->handle_);
}
