#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/color_extraction_effect.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

color_extraction_effect::color_extraction_effect(int32 threshold, color extraction_color, color other_pixels_color) : threshold {threshold}, extraction_color {extraction_color}, other_pixels_color {other_pixels_color} {
}

// For more information about algorithm see https://www.programmingalgorithms.com/algorithm/color-extraction
void color_extraction_effect::apply(xtd::drawing::image& image) const {
  auto threshold = math::clamp(this->threshold, 0, 3 * byte_object::max_value);
  auto alpha = reinterpret_cast<helpers::alpha*>(image.alpha());
  auto rgb = reinterpret_cast<helpers::rgb*>(image.rgb());

  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      if (!alpha[pixel].a) continue;
      int extraction_total_rgb = extraction_color.r() + extraction_color.g() + extraction_color.b();
      int total_rgb = rgb[pixel].r + rgb[pixel].g + rgb[pixel].b;
      if (math::abs(total_rgb - extraction_total_rgb) >= threshold) rgb[pixel] = {other_pixels_color.r(), other_pixels_color.g(), other_pixels_color.b()};
    }
}
