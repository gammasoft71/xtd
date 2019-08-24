#include "../../../include/xtd/drawing/brush.hpp"
#include <xtd/drawing/native/brush.hpp>

using namespace xtd;
using namespace xtd::drawing;

brush::brush() {
  this->brush_ = native::brush::create();
}

brush::brush(const brush&) {
  this->brush_ = native::brush::create();
}

brush& brush::operator=(const brush&) {
  return *this;
}

brush::~brush() {
  native::brush::destroy(this->brush_);
}
