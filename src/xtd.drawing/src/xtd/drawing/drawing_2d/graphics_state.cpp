#include "../../../../include/xtd/drawing/drawing_2d/graphics_state"

using namespace xtd::drawing::drawing_2d;

bool graphics_state::equals(const graphics_state& value) const noexcept {
  return handle_ == value.handle_;
}
