#pragma once
#include "bicubic_interpolation.hpp"
#include "box_average_interpolation.hpp"

namespace {
  xtd::drawing::image default_interpolation(const xtd::drawing::image& source_image, const xtd::drawing::size& size) {
    return size.width < source_image.width() && size.height < source_image.height() ? box_average_interpolation(source_image, size) : bicubic_interpolation(source_image, size);
  }
}
