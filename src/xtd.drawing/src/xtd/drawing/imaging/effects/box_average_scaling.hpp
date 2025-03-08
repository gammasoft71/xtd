#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"

namespace {
  xtd::drawing::image box_average_scaling(const xtd::drawing::image& source_image, const xtd::drawing::size& size) {
    return source_image.clone();
  }
}
