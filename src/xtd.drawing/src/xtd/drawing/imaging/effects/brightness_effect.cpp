#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/brightness_effect.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

brightness_effect::brightness_effect(double percent) : percent {percent} {
}

// For more information about algorithm see https://www.programmingalgorithms.com/algorithm/brightness
void brightness_effect::apply(xtd::drawing::image& image) const {
  auto percent = math::clamp(this->percent, 0.0, 2.0);
  auto alpha = reinterpret_cast<helpers::alpha*>(image.alpha());
  auto rgb = reinterpret_cast<helpers::rgb*>(image.rgb());
  auto blend_target = percent < 1.0 ? helpers::rgb {} : helpers::rgb {.r = 255, .g = 255, .b = 255};
  auto blend_factor = percent < 1.0 ? 1.0 - percent : percent - 1.0;

  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      if (!alpha[pixel].a) continue;
      rgb[pixel] = helpers::rgb::alpha_blend(rgb[pixel], blend_target, blend_factor);
    }
}
