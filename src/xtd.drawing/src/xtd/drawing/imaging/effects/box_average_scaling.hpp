#pragma once
#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"

namespace {
  struct box_precalculate {
    xtd::int32 box_start;
    xtd::int32 box_end;
  };
  
  inline void resample_box_precalculates(std::vector<box_precalculate>& precalculates, xtd::int32 old_size) {
    const auto new_size = static_cast<xtd::int32>(precalculates.size());
    if (old_size <= 0 || new_size == 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
    
    auto value = 0;
    for (auto distance = 0; distance < new_size; ++distance) {
      auto& precalculate = precalculates[distance];
      precalculate.box_start = value / new_size;
      value += old_size;
      precalculate.box_end = value % new_size != 0 ? value / new_size : (value / new_size) - 1;
    }
  }

  xtd::drawing::image box_average_scaling(const xtd::drawing::image& source_image, const xtd::drawing::size& size) {
    const auto source_width = source_image.width();
    const auto source_height = source_image.height();
    const auto source_alpha = reinterpret_cast<const xtd::drawing::helpers::alpha*>(source_image.alpha());
    const auto source_rgb = reinterpret_cast<const xtd::drawing::helpers::rgb*>(source_image.rgb());
    
    const auto result_width = size.width;
    const auto result_height = size.height;
    auto result_image = xtd::drawing::bitmap {result_width, result_height};
    auto result_alpha = reinterpret_cast<xtd::drawing::helpers::alpha*>(result_image.alpha());
    auto result_rgb = reinterpret_cast<xtd::drawing::helpers::rgb*>(result_image.rgb());
    
    auto vertical_precalculates = std::vector<box_precalculate>(result_height);
    auto horizontal_precalculates = std::vector<box_precalculate>(result_width);
    
    resample_box_precalculates(vertical_precalculates, source_height);
    resample_box_precalculates(horizontal_precalculates, source_width);

    for (auto y = 0; y < result_height; y++ ) {
      const auto& vertical_precalculate = vertical_precalculates[y];
      for (auto x = 0; x < result_width; ++x) {
        const auto& horizontal_precalculate = horizontal_precalculates[x];
        const auto averaged_pixels = (vertical_precalculate.box_end - vertical_precalculate.box_start + 1)  * (horizontal_precalculate.box_end - horizontal_precalculate.box_start + 1);
        const auto result_pixel = y * result_width + x;
        auto sum_a = 0.0, sum_r = 0.0, sum_g = 0.0, sum_b = 0.0;
        
        for (auto j = vertical_precalculate.box_start; j <= vertical_precalculate.box_end; ++j) {
          for (auto i = horizontal_precalculate.box_start; i <= horizontal_precalculate.box_end; ++i) {
            const auto source_pixel = j * source_width + i;
            sum_a += source_alpha[source_pixel].a;
            sum_r += source_rgb[source_pixel].r * source_alpha[source_pixel].a;
            sum_g += source_rgb[source_pixel].g * source_alpha[source_pixel].a;
            sum_b += source_rgb[source_pixel].b * source_alpha[source_pixel].a;
          }
        }
        
        if (sum_a == 0) continue;
        result_alpha[result_pixel].a = static_cast<xtd::byte>(sum_a / averaged_pixels);
        result_rgb[result_pixel].r = static_cast<xtd::byte>(sum_r / sum_a);
        result_rgb[result_pixel].g = static_cast<xtd::byte>(sum_g / sum_a);
        result_rgb[result_pixel].b = static_cast<xtd::byte>(sum_b / sum_a);
      }
    }
    
    return result_image;
  }
}
