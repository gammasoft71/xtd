#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/argb.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/blur_effect.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/resize_effect.hpp"
#include "../../../../../include/xtd/drawing/imaging/image_effector.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

namespace {
  image blur_horizontal(const image& source_image, int32 radius) {
    auto width = source_image.width();
    auto height = source_image.height();
    auto source_alpha = reinterpret_cast<const drawing::helpers::alpha*>(source_image.alpha());
    auto source_rgb = reinterpret_cast<const drawing::helpers::rgb*>(source_image.rgb());
    auto result_image = bitmap {width, height};
    auto result_alpha = reinterpret_cast<drawing::helpers::alpha*>(result_image.alpha());
    auto result_rgb = reinterpret_cast<drawing::helpers::rgb*>(result_image.rgb());
    const auto blur_area = radius * 2 + 1;
    
    for (auto y = 0; y < height; ++y) {
      auto sum_r = 0_s64, sum_g = 0_s64, sum_b = 0_s64, sum_a = 0_s64;
      
      for (auto kernel_x = -radius; kernel_x <= radius; ++kernel_x) {
        auto pixel_idx = kernel_x < 0 ? y * width : kernel_x + y * width;
        
        sum_r += source_rgb[pixel_idx].r;
        sum_g += source_rgb[pixel_idx].g;
        sum_b += source_rgb[pixel_idx].b;
        sum_a += source_alpha[pixel_idx].a;
      }
      
      result_rgb[y * width].r = static_cast<xtd::byte>(sum_r / blur_area);
      result_rgb[y * width].g = static_cast<xtd::byte>(sum_g / blur_area);
      result_rgb[y * width].b = static_cast<xtd::byte>(sum_b / blur_area);
      result_alpha[y * width].a = static_cast<xtd::byte>(sum_a / blur_area);
      
      for (auto x = 1; x < width; ++x) {
        auto pixel_idx = x - radius - 1 < 0 ? y * width : (x - radius - 1) + y * width;
        
        sum_r -= source_rgb[pixel_idx].r;
        sum_g -= source_rgb[pixel_idx].g;
        sum_b -= source_rgb[pixel_idx].b;
        sum_a -= source_alpha[pixel_idx].a;
        
        if (x + radius > width - 1) pixel_idx = width - 1 + y * width;
        else pixel_idx = x + radius + y * width;
        
        sum_r += source_rgb[pixel_idx].r;
        sum_g += source_rgb[pixel_idx].g;
        sum_b += source_rgb[pixel_idx].b;
        sum_a += source_alpha[pixel_idx].a;
        
        result_rgb[x + y * width].r = static_cast<xtd::byte>(sum_r / blur_area);
        result_rgb[x + y * width].g = static_cast<xtd::byte>(sum_g / blur_area);
        result_rgb[x + y * width].b = static_cast<xtd::byte>(sum_b / blur_area);
        result_alpha[x + y * width].a = static_cast<xtd::byte>(sum_a / blur_area);
      }
    }
    
    return result_image;
  }
}

image blur_vertical(const image& source_image, int32 radius) {
  auto width = source_image.width();
  auto height = source_image.height();
  auto source_alpha = reinterpret_cast<const drawing::helpers::alpha*>(source_image.alpha());
  auto source_rgb = reinterpret_cast<const drawing::helpers::rgb*>(source_image.rgb());
  auto result_image = bitmap {width, height};
  auto result_alpha = reinterpret_cast<drawing::helpers::alpha*>(result_image.alpha());
  auto result_rgb = reinterpret_cast<drawing::helpers::rgb*>(result_image.rgb());
  const auto blur_area = radius * 2 + 1;
  
  for (auto x = 0; x < width; ++x) {
    auto sum_r = 0_s64, sum_g = 0_s64, sum_b = 0_s64, sum_a = 0_s64;
    
    for (auto kernel_y = -radius; kernel_y <= radius; ++kernel_y) {
      auto pixel_idx = kernel_y < 0 ? x : x + kernel_y * width;
      
      sum_r += source_rgb[pixel_idx].r;
      sum_g += source_rgb[pixel_idx].g;
      sum_b += source_rgb[pixel_idx].b;
      sum_a += source_alpha[pixel_idx].a;
    }
    
    result_rgb[x].r = static_cast<xtd::byte>(sum_r / blur_area);
    result_rgb[x].g = static_cast<xtd::byte>(sum_g / blur_area);
    result_rgb[x].b = static_cast<xtd::byte>(sum_b / blur_area);
    result_alpha[x].a = static_cast<xtd::byte>(sum_a / blur_area);
    
    for (auto y = 1; y < height; ++y) {
      auto pixel_idx = y - radius - 1 < 0 ? x : x + (y - radius - 1) * width;
      
      sum_r -= source_rgb[pixel_idx].r;
      sum_g -= source_rgb[pixel_idx].g;
      sum_b -= source_rgb[pixel_idx].b;
      sum_a -= source_alpha[pixel_idx].a;
      
      pixel_idx = y + radius > height - 1 ? x + (height - 1) * width : x + (radius + y) * width;
      
      sum_r += source_rgb[pixel_idx].r;
      sum_g += source_rgb[pixel_idx].g;
      sum_b += source_rgb[pixel_idx].b;
      sum_a += source_alpha[pixel_idx].a;
      
      result_rgb[x + y * width].r = static_cast<xtd::byte>(sum_r / blur_area);
      result_rgb[x + y * width].g = static_cast<xtd::byte>(sum_g / blur_area);
      result_rgb[x + y * width].b = static_cast<xtd::byte>(sum_b / blur_area);
      result_alpha[x + y * width].a = static_cast<xtd::byte>(sum_a / blur_area);
    }
  }
  
  return result_image;
}

blur_effect::blur_effect(int32 radius) : blur_effect {radius, radius, false} {
}

blur_effect::blur_effect(int32 radius, bool expand_edge) : blur_effect {radius, radius, expand_edge} {
}

blur_effect::blur_effect(int32 horizontal_radius, int32 vertical_radius) : blur_effect {horizontal_radius, vertical_radius, false} {
}

blur_effect::blur_effect(int32 horizontal_radius, int32 vertical_radius, bool expand_edge) : expand_edge {expand_edge}, horizontal_radius {horizontal_radius}, vertical_radius {vertical_radius} {
}

void blur_effect::apply(xtd::drawing::image& image) const {
  auto horizontal_radius = this->horizontal_radius < 0 ? 0 : this->horizontal_radius;
  auto vertical_radius = this->vertical_radius < 0 ? 0 : this->vertical_radius;
  if (expand_edge) image_effector::set_effect(image, resize_effect {rectangle {horizontal_radius, vertical_radius, image.width() + horizontal_radius * 2, image.height() + vertical_radius * 2}});
  image = blur_vertical(blur_horizontal(image, horizontal_radius), vertical_radius);
}
