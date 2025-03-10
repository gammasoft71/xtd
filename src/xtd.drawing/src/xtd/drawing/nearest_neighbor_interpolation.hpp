#pragma once
#include "shrink_interpolation.hpp"
#include "../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../include/xtd/drawing/bitmap.hpp"

namespace {
  xtd::drawing::image nearest_neighbor_interpolation(const xtd::drawing::image& source_image, const xtd::drawing::size& size) {
    if (source_image == xtd::drawing::image::empty) return source_image;
    if (size.width == source_image.width() && size.height == source_image.height()) return source_image;
    if (size.width < 1 || size.height < 1) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);

    if (source_image.width() % size.width == 0 && source_image.width() >= size.width && source_image.height() % size.height == 0 && source_image.height() >= size.height)
      return shrink_interpolation(source_image, size);
    
    const auto source_width = source_image.width();
    const auto source_height = source_image.height();
    const auto source_alpha = reinterpret_cast<const xtd::drawing::helpers::alpha*>(source_image.alpha());
    const auto source_rgb = reinterpret_cast<const xtd::drawing::helpers::rgb*>(source_image.rgb());

    if (static_cast<xtd::size>(source_width) > xtd::size_object::max_value >> 16) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument, "The source image width is greather than 281474976710655 pixels");
    if (static_cast<xtd::size>(source_height) > xtd::size_object::max_value >> 16) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument, "The source image height is greather than 281474976710655 pixels");
    
    const auto result_width = size.width;
    const auto result_height = size.height;
    auto result_image = xtd::drawing::bitmap {result_width, result_height};
    auto result_alpha = reinterpret_cast<xtd::drawing::helpers::alpha*>(result_image.alpha());
    auto result_rgb = reinterpret_cast<xtd::drawing::helpers::rgb*>(result_image.rgb());

    const auto delta_x = (static_cast<xtd::size>(source_width) << 16) / result_width;
    const auto delta_y = (static_cast<xtd::size>(source_height) << 16) / result_height;
    
    auto source_y = xtd::size {0};
    for (auto y = 0; y < result_height; ++y) {
      auto source_x = xtd::size {0};
      for (auto x = 0; x < result_width; ++x) {
        const auto result_pixel = y * result_width + x;
        const auto source_pixel = static_cast<xtd::int32>((source_y >> 16) * source_width + (source_x >> 16));
        result_alpha[result_pixel].a = source_alpha[source_pixel].a;
        result_rgb[result_pixel].r = source_rgb[source_pixel].r;
        result_rgb[result_pixel].g = source_rgb[source_pixel].g;
        result_rgb[result_pixel].b = source_rgb[source_pixel].b;
        source_x += delta_x;
      }
      source_y += delta_y;
    }
        
    return result_image;
  }
}
