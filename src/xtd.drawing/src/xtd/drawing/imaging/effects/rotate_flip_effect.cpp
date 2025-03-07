#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/rotate_flip_effect.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::helpers;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

namespace {
  image flip_x(const image& source_image) {
    auto width = source_image.width();
    auto height = source_image.height();
    auto source_alpha = reinterpret_cast<const alpha*>(source_image.alpha());
    auto source_rgb = reinterpret_cast<const rgb*>(source_image.rgb());
    auto result_image = bitmap {width, height};
    auto result_alpha = reinterpret_cast<alpha*>(result_image.alpha());
    auto result_rgb = reinterpret_cast<rgb*>(result_image.rgb());
    
    for (auto y = 0; y < height; ++y)
      for (auto x = 0; x < width; ++x) {
        auto source_pixel = y * width + x;
        auto result_pixel = y * width + width - x - 1;
        result_alpha[result_pixel] = source_alpha[source_pixel];
        result_rgb[result_pixel] = source_rgb[source_pixel];
      }
    return result_image;
  }
  
  image rotate_180(const image& source_image) {
    auto width = source_image.width();
    auto height = source_image.height();
    auto source_alpha = reinterpret_cast<const alpha*>(source_image.alpha());
    auto source_rgb = reinterpret_cast<const rgb*>(source_image.rgb());
    auto result_image = bitmap {width, height};
    auto result_alpha = reinterpret_cast<alpha*>(result_image.alpha());
    auto result_rgb = reinterpret_cast<rgb*>(result_image.rgb());
    
    for (auto y = 0; y < height; ++y)
      for (auto x = 0; x < width; ++x) {
        auto source_pixel = y * width + x;
        auto result_pixel = (height - y - 1) * width + width - x - 1;
        result_alpha[result_pixel] = source_alpha[source_pixel];
        result_rgb[result_pixel] = source_rgb[source_pixel];
      }
    return result_image;
  }

  image rotate_270(const image& source_image) {
    auto width = source_image.width();
    auto height = source_image.height();
    auto source_alpha = reinterpret_cast<const alpha*>(source_image.alpha());
    auto source_rgb = reinterpret_cast<const rgb*>(source_image.rgb());
    auto result_image = bitmap {height, width};
    auto result_alpha = reinterpret_cast<alpha*>(result_image.alpha());
    auto result_rgb = reinterpret_cast<rgb*>(result_image.rgb());
    
    for (auto y = 0; y < height; ++y)
      for (auto x = 0; x < width; ++x) {
        auto source_pixel = y * width + x;
        auto result_pixel = (width - x -1) * height + y;
        result_alpha[result_pixel] = source_alpha[source_pixel];
        result_rgb[result_pixel] = source_rgb[source_pixel];
      }
    return result_image;
  }
  
  image rotate_90(const image& source_image) {
    auto width = source_image.width();
    auto height = source_image.height();
    auto source_alpha = reinterpret_cast<const alpha*>(source_image.alpha());
    auto source_rgb = reinterpret_cast<const rgb*>(source_image.rgb());
    auto result_image = bitmap {height, width};
    auto result_alpha = reinterpret_cast<alpha*>(result_image.alpha());
    auto result_rgb = reinterpret_cast<rgb*>(result_image.rgb());
    
    for (auto y = 0; y < height; ++y)
      for (auto x = 0; x < width; ++x) {
        auto source_pixel = y * width + x;
        auto result_pixel = x * height + height - y - 1;
        result_alpha[result_pixel] = source_alpha[source_pixel];
        result_rgb[result_pixel] = source_rgb[source_pixel];
      }
    return result_image;
  }
}

rotate_flip_effect::rotate_flip_effect(xtd::drawing::rotate_flip_type rotate_flip_type) : rotate_flip_type {rotate_flip_type} {
}

void rotate_flip_effect::apply(xtd::drawing::image& image) const {
  switch (rotate_flip_type) {
    case rotate_flip_type::rotate_none_flip_none: break;
    case rotate_flip_type::rotate_90_flip_none: image = rotate_90(image); break;
    case rotate_flip_type::rotate_180_flip_none: image = rotate_180(image); break;
    case rotate_flip_type::rotate_270_flip_none: image = rotate_270(image); break;
    case rotate_flip_type::rotate_none_flip_x: image = flip_x(image); break;
    case rotate_flip_type::rotate_90_flip_x: image = flip_x(rotate_90(image)); break;
    case rotate_flip_type::rotate_180_flip_x: image = flip_x(rotate_180(image)); break;
    case rotate_flip_type::rotate_270_flip_x: image = flip_x(rotate_270(image)); break;
    default: break;
  }
}

