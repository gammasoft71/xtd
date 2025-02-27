#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/solarize_effect.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

solarize_effect::solarize_effect(int32 threshold) : threshold {threshold} {
}

void solarize_effect::apply(xtd::drawing::image& image) const {
  auto threshold = math::clamp(this->threshold, 0, 255);
  auto alpha = reinterpret_cast<helpers::alpha*>(image.alpha());
  auto rgb = reinterpret_cast<helpers::rgb*>(image.rgb());
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      if (!alpha[pixel].a) continue;
      if (rgb[pixel].r > threshold) rgb[pixel].r = 255 - rgb[pixel].r;
      if (rgb[pixel].g > threshold) rgb[pixel].g = 255 - rgb[pixel].g;
      if (rgb[pixel].b > threshold) rgb[pixel].b = 255 - rgb[pixel].b;
    }
}
