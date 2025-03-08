#include "bicubic_scaling.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/scale_effect.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::helpers;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;
using namespace xtd::helpers;

namespace {
  image nearest_scaling(const image& source_image, const xtd::drawing::size& size) {
    auto result_image = source_image.clone();

    return result_image;
  }
  
  image bilinear_scaling(const image& source_image, const xtd::drawing::size& size) {
    auto result_image = source_image.clone();

    return result_image;
  }
  
  image box_average_scaling(const image& source_image, const xtd::drawing::size& size) {
    auto result_image = source_image.clone();

    return result_image;
  }

  image default_scaling(const image& source_image, const xtd::drawing::size& size) {
    if (size.width < source_image.width() && size.height < source_image.height()) return box_average_scaling(source_image, size);
    return bicubic_scaling(source_image, size);
  }
}

scale_effect::scale_effect(const xtd::drawing::size& size) : size {size} {
}

scale_effect::scale_effect(const xtd::drawing::size& size, xtd::drawing::scale_type scale_type) : size {size}, scale_type {scale_type} {
}

void scale_effect::apply(xtd::drawing::image& image) const {
  auto size = this->size;
  if (size.width < 1) size.width = 1;
  if (size.height < 1) size.height = 1;
  
  if (image.size() == size) return;
  
  switch (scale_type) {
    case scale_type::default_scaling: image = default_scaling(image, size); break; // image.rescale(size.width, size.height); break; // image = default_scaling(image, size); break;
    case scale_type::nearest: image = nearest_scaling(image, size); break;
    case scale_type::bilinear: image = bilinear_scaling(image, size); break;
    case scale_type::bicubic: image = bicubic_scaling(image, size); break;
    case scale_type::box_average: image = box_average_scaling(image, size); break;
    default: image = default_scaling(image, size); break;
  }
}
