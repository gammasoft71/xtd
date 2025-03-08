#pragma once
#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"

namespace {
  static inline double spline_cube(double value) {
    return value <= 0.0 ? 0.0 : value * value * value;
  }
  
  double spline_weight(double value) {
    return (spline_cube(value + 2) - 4 * spline_cube(value + 1) + 6 * spline_cube(value) - 4 * spline_cube(value - 1)) / 6;
  }

  struct bicubic_precalculate {
    double weight[4];
    xtd::int32 offset[4];
  };
  
  void compute_precalculate(bicubic_precalculate& precalculate, double source_pixel, xtd::int32 old_size) {
    const auto dd = source_pixel - static_cast<xtd::int32>(source_pixel);
    for (auto k = -1; k <= 2; ++k) {
      precalculate.offset[k + 1] = source_pixel + k < 0.0 ? 0 : source_pixel + k >= old_size ? old_size - 1 : static_cast<xtd::int32>(source_pixel + k);
      precalculate.weight[k + 1] = spline_weight(k - dd);
    }
  }

  void resample_bicubic_precalculate(std::vector<bicubic_precalculate>& weight, xtd::int32 old_size) {
    const auto new_size = weight.size();
    if (old_size < 0 || new_size < 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
    
    if (new_size > 1) {
      const auto scale_factor = static_cast<double>(old_size - 1) / (new_size - 1);
      for (auto distance_d = xtd::size {0}; distance_d < new_size; ++distance_d) {
        const auto source_pixel = static_cast<double>(distance_d) * scale_factor;
        compute_precalculate(weight[distance_d], source_pixel, old_size);
      }
    } else {
      const auto source_pixel = static_cast<double>(old_size - 1) / 2.0;
      compute_precalculate(weight[0], source_pixel, old_size);
    }
  }

  xtd::drawing::image bicubic_scaling(const xtd::drawing::image& source_image, const xtd::drawing::size& size) {
    auto source_width = source_image.width();
    auto source_height = source_image.height();
    auto source_alpha = reinterpret_cast<const xtd::drawing::helpers::alpha*>(source_image.alpha());
    auto source_rgb = reinterpret_cast<const xtd::drawing::helpers::rgb*>(source_image.rgb());

    auto result_width = size.width;
    auto result_height = size.height;
    auto result_image = xtd::drawing::bitmap {result_width, result_height};
    auto result_alpha = reinterpret_cast<xtd::drawing::helpers::alpha*>(result_image.alpha());
    auto result_rgb = reinterpret_cast<xtd::drawing::helpers::rgb*>(result_image.rgb());
    
    auto vertical_precalculates = std::vector<bicubic_precalculate>(result_height);
    auto horizontal_precalculates = std::vector<bicubic_precalculate>(result_width);
    
    resample_bicubic_precalculate(vertical_precalculates, source_height);
    resample_bicubic_precalculate(horizontal_precalculates, source_width);
    
    for (auto distance_y = 0; distance_y < result_height; ++distance_y) {
      const auto& vertical_precalculate = vertical_precalculates[distance_y];
      for (auto distance_x = 0; distance_x < result_width; ++distance_x) {
        const auto& horizontal_precalculate = horizontal_precalculates[distance_x];
        const auto result_pixel = distance_y * result_width + distance_x;
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
        
        result_rgb[result_pixel].r = sum_a == 0 ? 0 : static_cast<xtd::byte>(sum_r / sum_a + 0.5);
        result_rgb[result_pixel].g = sum_a == 0 ? 0 : static_cast<xtd::byte>(sum_g / sum_a + 0.5);
        result_rgb[result_pixel].b = sum_a == 0 ? 0 : static_cast<xtd::byte>(sum_b / sum_a + 0.5);
        result_alpha[result_pixel].a = static_cast<xtd::byte>(sum_a);
      }
    }
    
    return result_image;
  }
}
