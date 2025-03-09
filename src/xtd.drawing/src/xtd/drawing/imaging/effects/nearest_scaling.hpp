#pragma once
#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"

namespace {
  xtd::drawing::image shrink_image(const xtd::drawing::image& source_image, xtd::int32 x_factor , xtd::int32 y_factor ) {
    if(x_factor == 1 && y_factor == 1) return source_image;
    if(x_factor <= 0 || y_factor <= 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);

    const auto source_height = source_image.height();
    const auto source_width = source_image.width();
    const auto source_alpha = reinterpret_cast<const xtd::drawing::helpers::alpha*>(source_image.alpha());
    const auto source_rgb = reinterpret_cast<const xtd::drawing::helpers::rgb*>(source_image.rgb());

    const auto result_width = source_width / x_factor ;
    const auto result_height = source_height / y_factor ;
    auto result_image = xtd::drawing::bitmap {result_width, result_height};
    auto result_alpha = reinterpret_cast<xtd::drawing::helpers::alpha*>(result_image.alpha());
    auto result_rgb = reinterpret_cast<xtd::drawing::helpers::rgb*>(result_image.rgb());

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
  
  xtd::drawing::image nearest_scaling(const xtd::drawing::image& source_image, const xtd::drawing::size& size) {
    if (source_image.width() % size.width == 0 && source_image.width() >= size.width && source_image.height() % size.height == 0 && source_image.height() >= size.height)
      return shrink_image(source_image, source_image.width() / size.width, source_image.height() / size.height);
    
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
