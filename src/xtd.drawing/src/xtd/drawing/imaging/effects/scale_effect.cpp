#include "bicubic_scaling.hpp"
#include "box_average_scaling.hpp"
#include "nearest_scaling.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/scale_effect.hpp"

namespace {
  xtd::drawing::image bilinear_scaling(const xtd::drawing::image& source_image, const xtd::drawing::size& size) {
    return source_image.clone();
  }
  
  xtd::drawing::image default_scaling(const xtd::drawing::image& source_image, const xtd::drawing::size& size) {
    return size.width < source_image.width() && size.height < source_image.height() ? box_average_scaling(source_image, size) : bicubic_scaling(source_image, size);
  }
}

using namespace xtd::drawing::imaging::effects;

scale_effect::scale_effect(const xtd::drawing::size& size) : size {size} {
}

scale_effect::scale_effect(const xtd::drawing::size& size, xtd::drawing::scale_type scale_type) : size {size}, scale_type {scale_type} {
}

void scale_effect::apply(image& image) const {
  auto size = this->size;
  if (size.width < 1) size.width = 1;
  if (size.height < 1) size.height = 1;
  
  if (image.size() == size) return;
  
  switch (scale_type) {
    case xtd::drawing::scale_type::default_scaling: image = default_scaling(image, size); break;
    case xtd::drawing::scale_type::nearest: image = nearest_scaling(image, size); break;
    case xtd::drawing::scale_type::bilinear: image = bilinear_scaling(image, size); break;
    case xtd::drawing::scale_type::bicubic: image = bicubic_scaling(image, size); break;
    case xtd::drawing::scale_type::box_average: image = box_average_scaling(image, size); break;
    default: image = default_scaling(image, size); break;
  }
}
