#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/posterize_effect.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

posterize_effect::posterize_effect(int32 levels) : levels {levels} {
}

void posterize_effect::apply(xtd::drawing::image& image) const {
  auto levels = math::clamp(this->levels, 1, 256);
  auto alpha = reinterpret_cast<helpers::alpha*>(image.alpha());
  auto rgb = reinterpret_cast<helpers::rgb*>(image.rgb());
  auto step = 256 / levels;
  
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      if (!alpha[pixel].a) continue;
      rgb[pixel].r = std::round(rgb[pixel].r / step) * step;
      rgb[pixel].g = std::round(rgb[pixel].g / step) * step;
      rgb[pixel].b = std::round(rgb[pixel].b / step) * step;
    }
}
