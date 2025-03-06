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
  auto levels = math::clamp(this->levels, 2, 256);
  auto alpha = reinterpret_cast<helpers::alpha*>(image.alpha());
  auto rgb = reinterpret_cast<helpers::rgb*>(image.rgb());
  auto step = 255.0f / (levels-1);
  
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      if (!alpha[pixel].a) continue;
      rgb[pixel].r = static_cast<byte>(std::round(rgb[pixel].r / step) * step);
      rgb[pixel].g = static_cast<byte>(std::round(rgb[pixel].g / step) * step);
      rgb[pixel].b = static_cast<byte>(std::round(rgb[pixel].b / step) * step);
    }
}
