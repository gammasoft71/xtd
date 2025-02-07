#include "../../../../include/xtd/drawing/drawing_2d/graphics_state.hpp"
#include <xtd/hash_code>
#include <xtd/is>

using namespace xtd;
using namespace xtd::drawing::drawing_2d;

bool graphics_state::equals(const object& obj) const noexcept {
  return is<graphics_state>(obj) && equals(static_cast<const graphics_state&>(obj));
}

bool graphics_state::equals(const graphics_state& other) const noexcept {
  return handle_ == other.handle_;
}

size graphics_state::get_hash_code() const noexcept {
  return hash_code::combine(handle_);
}
