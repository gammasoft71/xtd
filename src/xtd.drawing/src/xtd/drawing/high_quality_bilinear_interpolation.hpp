#pragma once
#include "bilinear_interpolation.hpp"
#include "shrink_interpolation.hpp"

namespace {
  xtd::drawing::image high_quality_bilinear_interpolation(const xtd::drawing::image& source_image, const xtd::drawing::size& size) {
    if (source_image == xtd::drawing::image::empty) return source_image;
    if (size.width == source_image.width() && size.height == source_image.height()) return source_image;
    if (size.width < 1 || size.height < 1) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
    
    if (source_image.width() % size.width == 0 && source_image.width() >= size.width && source_image.height() % size.height == 0 && source_image.height() >= size.height)
      return shrink_interpolation(source_image, size);

    return bilinear_interpolation(source_image, size);
  }
}
