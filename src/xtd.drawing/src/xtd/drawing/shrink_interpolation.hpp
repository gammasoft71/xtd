#pragma once
#include "../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../include/xtd/drawing/bitmap.hpp"

namespace {
  xtd::drawing::image shrink_interpolation(const xtd::drawing::image& source_image, const xtd::drawing::size& size) {
    if (source_image == xtd::drawing::image::empty) return source_image;
    if (size.width == source_image.width() && size.height == source_image.height()) return source_image;
    if (size.width < 1 || size.height < 1) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
    if (source_image.width() % size.width != 0 || source_image.width() < size.width || source_image.height() % size.height != 0 || source_image.height() < size.height) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
    
    const auto source_height = source_image.height();
    const auto source_width = source_image.width();
    const auto source_alpha = reinterpret_cast<const xtd::drawing::helpers::alpha*>(source_image.alpha());
    const auto source_rgb = reinterpret_cast<const xtd::drawing::helpers::rgb*>(source_image.rgb());

    const auto result_width = size.width;
    const auto result_height = size.height;
    auto result_image = xtd::drawing::bitmap {result_width, result_height};
    auto result_alpha = reinterpret_cast<xtd::drawing::helpers::alpha*>(result_image.alpha());
    auto result_rgb = reinterpret_cast<xtd::drawing::helpers::rgb*>(result_image.rgb());
    
    const auto x_factor = source_width / result_width;
    const auto y_factor = source_height / result_height;
    
    if(x_factor == 1 && y_factor == 1) return source_image;
    if(x_factor <= 0 || y_factor <= 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);

    for (auto y = 0; y < result_height; ++y) {
      for (auto x = 0; x < result_width; ++x) {
        const auto result_pixel = y * result_width + x;
        auto counter = xtd::size {0}, sum_alpha = xtd::size {0}, sum_red = xtd::size {0}, sum_green = xtd::size {0}, sum_blue =xtd::size {0};

        for (auto y1 = 0 ; y1 < y_factor ; ++y1) {
          const auto y_offset = (y * y_factor + y1) * source_width;
          for (auto x1 = 0 ; x1 < x_factor ; ++x1) {
            const auto source_pixel = y_offset + x * x_factor + x1;
            sum_alpha += source_alpha[source_pixel].a;
            if (source_alpha[source_pixel].a == 0) continue;
            ++counter;
            sum_red += source_rgb[source_pixel].r;
            sum_green += source_rgb[source_pixel].g;
            sum_blue += source_rgb[source_pixel].b;
          }
        }
        result_alpha[result_pixel].a = counter == 0 ? 0 : static_cast<xtd::byte>(sum_alpha / counter);
        result_rgb[result_pixel].r = counter == 0 ? 0 : static_cast<xtd::byte>(sum_red / counter);
        result_rgb[result_pixel].g = counter == 0 ? 0 : static_cast<xtd::byte>(sum_green / counter);
        result_rgb[result_pixel].b = counter == 0 ? 0 : static_cast<xtd::byte>(sum_blue / counter);
      }
    }
    return result_image;
  }
}
