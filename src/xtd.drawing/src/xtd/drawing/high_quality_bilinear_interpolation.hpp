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
    
    const auto scale_x = static_cast<double>(source_image.width()) / size.width;
    const auto scale_y = static_cast<double>(source_image.height()) / size.height;
    const auto passes = static_cast<xtd::int32>(xtd::math::ceiling(xtd::math::max(xtd::math::log(scale_x, 2), xtd::math::log(scale_y, 2))));
    
    auto result_image = source_image;
    for (auto passe = 0; passe < passes; ++passe) {
      const auto intermediate_width = xtd::math::max(static_cast<double>(size.width), result_image.width() / 2.0);
      const auto intermediate_height = xtd::math::max(static_cast<double>(size.height), result_image.height() / 2.0);
      result_image = bilinear_interpolation(result_image, {static_cast<int>(intermediate_width), static_cast<int>(intermediate_height)});
    }
    
    return result_image;
  }
}
