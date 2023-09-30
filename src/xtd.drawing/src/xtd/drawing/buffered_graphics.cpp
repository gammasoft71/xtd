#include "../../../include/xtd/drawing/buffered_graphics.h"
#include <xtd/argument_exception>

using namespace xtd;
using namespace xtd::drawing;

const graphics& buffered_graphics::graphics() const noexcept {
  return buffered_graphics_surface_;
}

graphics& buffered_graphics::graphics() noexcept  {
  return buffered_graphics_surface_;
}

void buffered_graphics::render() {
  auto target_graphics = target_graphics_.value_or(xtd::drawing::graphics::from_hdc(target_dc_));
  render(target_graphics);
}

void buffered_graphics::render(xtd::drawing::graphics& target) {
  target.copy_from_graphics(buffered_graphics_surface_, target_location_, {0, 0}, virtual_size_);
}

void buffered_graphics::render(intptr target_dc) {
  auto target_graphics = xtd::drawing::graphics::from_hdc(target_dc);
  render(target_graphics);
}

buffered_graphics::buffered_graphics(const xtd::drawing::graphics& buffered_graphics_surface, std::optional<xtd::drawing::graphics> target_graphics, intptr target_dc, const xtd::drawing::point& target_location, xtd::drawing::size virtual_size) : buffered_graphics_surface_(buffered_graphics_surface), target_dc_(target_dc), target_graphics_(target_graphics), target_location_(target_location), virtual_size_(virtual_size) {
  if (!target_graphics.has_value() && !target_dc) throw argument_exception {csf_};
}
