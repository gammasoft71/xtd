#pragma once
#include "high_quality_bicubic_interpolation.hpp"
#include "box_average_interpolation.hpp"

namespace {
  xtd::drawing::image default_interpolation(const xtd::drawing::image& source_image, const xtd::drawing::size& size) {
    if (source_image == xtd::drawing::image::empty) return source_image;
    if (size.width == source_image.width() && size.height == source_image.height()) return source_image;
    if (size.width < 1 || size.height < 1) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
    
    if (size.width < source_image.width() && size.height < source_image.height())
      return box_average_interpolation(source_image, size);
    
    return bicubic_interpolation(source_image, size);
  }
}
