#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/color_substitution_effect.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

color_substitution_effect::color_substitution_effect(int32 threshold, color source_color, color new_color) : threshold {threshold}, source_color {source_color}, new_color {new_color} {
}

// For more information about algorithm see https://www.programmingalgorithms.com/algorithm/color-substitution
void color_substitution_effect::apply(xtd::drawing::image& image) const {
  auto threshold = math::clamp(this->threshold, 0, 3 * byte_object::max_value);
  auto alpha = reinterpret_cast<helpers::alpha*>(image.alpha());
  auto rgb = reinterpret_cast<helpers::rgb*>(image.rgb());

  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      if (!alpha[pixel].a) continue;
      int source_total_rgb = source_color.r() + source_color.g() + source_color.b();
      int total_rgb = rgb[pixel].r + rgb[pixel].g + rgb[pixel].b;
      if (math::abs(total_rgb - source_total_rgb) < threshold) rgb[pixel] = {new_color.r(), new_color.g(), new_color.b()};
    }
}
