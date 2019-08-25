#include "../../../include/xtd/drawing/graphics.hpp"
#include <xtd/drawing/native/graphics.hpp>

using namespace xtd;
using namespace xtd::drawing;

graphics::~graphics() {
  native::graphics::destroy(this->hdc_);
}
