#include "../../../include/xtd/drawing/graphics.hpp"
#include <xtd/drawing/native/graphics.hpp>

using namespace xtd;
using namespace xtd::drawing;

graphics::~graphics() {
  if (this->hdc_ != 0) native::graphics::destroy(this->hdc_);
}

void graphics::clear(const color& color) {
  native::graphics::clear(this->hdc_, color.a(), color.r(), color.g(), color.b());
}
