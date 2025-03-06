#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/contrast_effect.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

contrast_effect::contrast_effect(double percent) : percent {percent} {
}

// For more information about algorithm see https://www.programmingalgorithms.com/algorithm/contrast
void contrast_effect::apply(xtd::drawing::image& image) const {
  auto percent = this->percent < 0.0 ? 0.0 : this->percent;
  auto alpha = reinterpret_cast<helpers::alpha*>(image.alpha());
  auto rgb = reinterpret_cast<helpers::rgb*>(image.rgb());

  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      if (!alpha[pixel].a) continue;
      rgb[pixel] = helpers::rgb {
        .r = static_cast<byte>(math::clamp(((((rgb[pixel].r / 255.0) - 0.5) * percent) + 0.5) * 255.0, .0, 255.0)),
        .g = static_cast<byte>(math::clamp(((((rgb[pixel].g / 255.0) - 0.5) * percent) + 0.5) * 255.0, .0, 255.0)),
        .b = static_cast<byte>(math::clamp(((((rgb[pixel].b / 255.0) - 0.5) * percent) + 0.5) * 255.0, .0, 255.0))
      };
    }
}
