#include "../../../../../include/xtd/drawing/imaging/effects/scale_effect.hpp"
#include "../../../../../include/xtd/drawing/image.hpp"

using namespace xtd::drawing::imaging::effects;

scale_effect::scale_effect(const xtd::drawing::size& size) : size {size} {
}

scale_effect::scale_effect(const xtd::drawing::size& size, xtd::drawing::drawing_2d::interpolation_mode interpolation_mode) : size {size}, interpolation_mode {interpolation_mode} {
}

void scale_effect::apply(image& image) const {
  auto size = this->size;
  if (size.width < 1) size.width = 1;
  if (size.height < 1) size.height = 1;
  image.scale(size, interpolation_mode);
}
