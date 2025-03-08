#include "bicubic_scaling.hpp"
#include "box_average_scaling.hpp"

namespace {
  xtd::drawing::image default_scaling(const xtd::drawing::image& source_image, const xtd::drawing::size& size) {
    return size.width < source_image.width() && size.height < source_image.height() ? box_average_scaling(source_image, size) : bicubic_scaling(source_image, size);
  }
}
