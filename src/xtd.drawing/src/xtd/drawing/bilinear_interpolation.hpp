#pragma once
#include "../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../include/xtd/drawing/bitmap.hpp"

namespace {
  struct bilinear_precalculate {
    xtd::int32 offset1;
    xtd::int32 offset2;
    double decimals;
    double decimals1;
  };
  
  inline void compute_bilinear_precalculate(bilinear_precalculate& precalculate, double source_pixel, xtd::int32 source_pixel_maximum) {
    xtd::int32 source_pixel1 = static_cast<xtd::int32>(source_pixel);
    xtd::int32 source_pixel2 = source_pixel1 == source_pixel_maximum ? source_pixel1 : source_pixel1 + 1;
    
    precalculate.decimals = source_pixel - static_cast<xtd::int32>(source_pixel);
    precalculate.decimals1 = 1.0 - precalculate.decimals;
    precalculate.offset1 = source_pixel1 < 0.0 ? 0 : source_pixel1 > source_pixel_maximum ? source_pixel_maximum : static_cast<xtd::int32>(source_pixel1);
    precalculate.offset2 = source_pixel2 < 0.0 ? 0 : source_pixel2 > source_pixel_maximum ? source_pixel_maximum : static_cast<xtd::int32>(source_pixel2);
  }
  
  void resample_bilinear_precalculates(std::vector<bilinear_precalculate>& precalculates, xtd::int32 old_size) {
    const auto new_size = static_cast<xtd::int32>(precalculates.size());
    if (old_size <= 0 || new_size == 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
    const auto source_pixel_maximum = old_size - 1;
    if (new_size > 1) {
      const auto scale_factor = static_cast<double>(old_size - 1) / (new_size - 1);
      for (auto distance = 0; distance < new_size; ++distance) {
        auto source_pixel = static_cast<double>(distance) * scale_factor;
        compute_bilinear_precalculate(precalculates[distance], source_pixel, source_pixel_maximum);
      }
    } else {
      double source_pixel = (double)source_pixel_maximum / 2.0;
      compute_bilinear_precalculate(precalculates[0], source_pixel, source_pixel_maximum);
    }
  }

  xtd::drawing::image bilinear_interpolation(const xtd::drawing::image& source_image, const xtd::drawing::size& size) {
    const auto source_width = source_image.width();
    const auto source_height = source_image.height();
    const auto source_alpha = reinterpret_cast<const xtd::drawing::helpers::alpha*>(source_image.alpha());
    const auto source_rgb = reinterpret_cast<const xtd::drawing::helpers::rgb*>(source_image.rgb());
    
    const auto result_width = size.width;
    const auto result_height = size.height;
    auto result_image = xtd::drawing::bitmap {result_width, result_height};
    auto result_alpha = reinterpret_cast<xtd::drawing::helpers::alpha*>(result_image.alpha());
    auto result_rgb = reinterpret_cast<xtd::drawing::helpers::rgb*>(result_image.rgb());
    
    auto vertical_precalculates = std::vector<bilinear_precalculate>(result_height);
    auto horizontal_precalculates = std::vector<bilinear_precalculate>(result_width);

    resample_bilinear_precalculates(vertical_precalculates, source_height);
    resample_bilinear_precalculates(horizontal_precalculates, source_width);
    
    for (auto y = 0; y < result_height; ++y) {
      const auto& vertical_precalculate = vertical_precalculates[y];
      const auto y_offset1 = vertical_precalculate.offset1;
      const auto y_offset2 = vertical_precalculate.offset2;
      const auto dy = vertical_precalculate.decimals;
      const auto dy1 = vertical_precalculate.decimals1;
      
      for (auto x = 0; x < result_width; ++x) {
        const auto result_pixel = y * result_width + x;
        const auto& horizontal_precalculate = horizontal_precalculates[x];
        
        const auto x_offset1 = horizontal_precalculate.offset1;
        const auto x_offset2 = horizontal_precalculate.offset2;
        const auto dx = horizontal_precalculate.decimals;
        const auto dx1 = horizontal_precalculate.decimals1;
        
        const auto source_pixel_00 = y_offset1 * source_width + x_offset1;
        const auto source_pixel_01 = y_offset1 * source_width + x_offset2;
        const auto source_pixel_10 = y_offset2 * source_width + x_offset1;
        const auto source_pixel_11 = y_offset2 * source_width + x_offset2;
        
        const auto a1 = source_alpha[source_pixel_00].a * dx1 + source_alpha[source_pixel_01].a * dx;
        const auto r1 = source_rgb[source_pixel_00].r * dx1 + source_rgb[source_pixel_01].r * dx;
        const auto g1 = source_rgb[source_pixel_00].g * dx1 + source_rgb[source_pixel_01].g * dx;
        const auto b1 = source_rgb[source_pixel_00].b * dx1 + source_rgb[source_pixel_01].b * dx;
        
        const auto a2 = source_alpha[source_pixel_10].a * dx1 + source_alpha[source_pixel_11].a * dx;
        const auto r2 = source_rgb[source_pixel_10].r * dx1 + source_rgb[source_pixel_11].r * dx;
        const auto g2 = source_rgb[source_pixel_10].g * dx1 + source_rgb[source_pixel_11].g * dx;
        const auto b2 = source_rgb[source_pixel_10].b * dx1 + source_rgb[source_pixel_11].b * dx;
        
        result_alpha[result_pixel].a = static_cast<xtd::byte>(a1 * dy1 + a2 * dy + 0.5);
        result_rgb[result_pixel].r = static_cast<xtd::byte>(r1 * dy1 + r2 * dy + 0.5);
        result_rgb[result_pixel].g = static_cast<xtd::byte>(g1 * dy1 + g2 * dy + 0.5);
        result_rgb[result_pixel].b = static_cast<xtd::byte>(b1 * dy1 + b2 * dy + 0.5);
      }
    }

    return result_image;
  }
}
