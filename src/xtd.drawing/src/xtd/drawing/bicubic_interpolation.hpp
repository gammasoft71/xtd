#pragma once
#include "../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/fixed_array>

namespace {
  inline constexpr double spline_cube(double value) {
    return value <= 0.0 ? 0.0 : value * value * value;
  }
  
  inline constexpr double spline_weight(double value) {
    return (spline_cube(value + 2) - 4 * spline_cube(value + 1) + 6 * spline_cube(value) - 4 * spline_cube(value - 1)) / 6;
  }

  struct bicubic_precalculate {
    xtd::fixed_array<double, 4> weight;
    xtd::fixed_array<xtd::int32, 4> offset;
  };
  
  inline void compute_bicubic_precalculate(bicubic_precalculate& precalculate, double source_pixel, xtd::int32 old_size) {
    const auto decimals = source_pixel - static_cast<xtd::int32>(source_pixel);
    for (auto k = -1; k <= 2; ++k) {
      precalculate.offset[k + 1] = source_pixel + k < 0.0 ? 0 : source_pixel + k >= old_size ? old_size - 1 : static_cast<xtd::int32>(source_pixel + k);
      precalculate.weight[k + 1] = spline_weight(k - decimals);
    }
  }

  inline void resample_bicubic_precalculates(std::vector<bicubic_precalculate>& precalculates, xtd::int32 old_size) {
    const auto new_size = static_cast<xtd::int32>(precalculates.size());
    if (old_size <= 0 || new_size == 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
    
    if (new_size > 1) {
      const auto scale_factor = static_cast<double>(old_size - 1) / (new_size - 1);
      for (auto distance = 0; distance < new_size; ++distance) {
        const auto source_pixel = static_cast<double>(distance) * scale_factor;
        compute_bicubic_precalculate(precalculates[distance], source_pixel, old_size);
      }
    } else {
      const auto source_pixel = static_cast<double>(old_size - 1) / 2.0;
      compute_bicubic_precalculate(precalculates[0], source_pixel, old_size);
    }
  }

  xtd::drawing::image bicubic_interpolation(const xtd::drawing::image& source_image, const xtd::drawing::size& size) {
    if (source_image == xtd::drawing::image::empty) return source_image;
    if (size.width == source_image.width() && size.height == source_image.height()) return source_image;
    if (size.width < 1 || size.height < 1) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
    
    const auto source_width = source_image.width();
    const auto source_height = source_image.height();
    const auto source_alpha = reinterpret_cast<const xtd::drawing::helpers::alpha*>(source_image.alpha());
    const auto source_rgb = reinterpret_cast<const xtd::drawing::helpers::rgb*>(source_image.rgb());

    const auto result_width = size.width;
    const auto result_height = size.height;
    auto result_image = xtd::drawing::bitmap {result_width, result_height};
    auto result_alpha = reinterpret_cast<xtd::drawing::helpers::alpha*>(result_image.alpha());
    auto result_rgb = reinterpret_cast<xtd::drawing::helpers::rgb*>(result_image.rgb());
    
    auto vertical_precalculates = std::vector<bicubic_precalculate>(result_height);
    auto horizontal_precalculates = std::vector<bicubic_precalculate>(result_width);
    
    resample_bicubic_precalculates(vertical_precalculates, source_height);
    resample_bicubic_precalculates(horizontal_precalculates, source_width);
    
    for (auto y = 0; y < result_height; ++y) {
      const auto& vertical_precalculate = vertical_precalculates[y];
      for (auto x = 0; x < result_width; ++x) {
        const auto& horizontal_precalculate = horizontal_precalculates[x];
        const auto result_pixel = y * result_width + x;
        auto sum_a = 0.0, sum_r = 0.0, sum_g = 0.0, sum_b = 0.0;
        
        for (auto k = -1; k <= 2; ++k) {
          const auto y_offset = vertical_precalculate.offset[k + 1];
          for (auto i = -1; i <= 2; ++i) {
            const auto x_offset = horizontal_precalculate.offset[i + 1];
            const auto source_pixel = y_offset * source_width + x_offset;
            const auto pixel_weight = vertical_precalculate.weight[k + 1] * horizontal_precalculate.weight[i + 1];
            const auto a = source_alpha[source_pixel].a;
            sum_a += a * pixel_weight;
            sum_r += source_rgb[source_pixel].r * pixel_weight * a;
            sum_g += source_rgb[source_pixel].g * pixel_weight * a;
            sum_b += source_rgb[source_pixel].b * pixel_weight * a;
          }
        }
        
        if (sum_a < xtd::double_object::epsilon) continue;
        result_alpha[result_pixel].a = static_cast<xtd::byte>(sum_a);
        result_rgb[result_pixel].r = static_cast<xtd::byte>(xtd::math::round(sum_r / sum_a));
        result_rgb[result_pixel].g = static_cast<xtd::byte>(xtd::math::round(sum_g / sum_a));
        result_rgb[result_pixel].b = static_cast<xtd::byte>(xtd::math::round(sum_b / sum_a));
      }
    }
    
    return result_image;
  }
}
