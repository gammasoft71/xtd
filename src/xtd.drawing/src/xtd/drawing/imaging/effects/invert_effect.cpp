#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/invert_effect.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

invert_effect::invert_effect(double percent) : percent {percent} {
}

// For more information about algorithm see https://www.programmingalgorithms.com/algorithm/invert
void invert_effect::apply(xtd::drawing::image& image) const {
  auto percent = math::clamp(this->percent, 0.0, 1.0);
  auto alpha = reinterpret_cast<helpers::alpha*>(image.alpha());
  auto rgb = reinterpret_cast<helpers::rgb*>(image.rgb());

  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      if (!alpha[pixel].a) continue;
      rgb[pixel].r = helpers::rgb::alpha_blend(rgb[pixel].r, 255 - rgb[pixel].r, percent);
      rgb[pixel].g = helpers::rgb::alpha_blend(rgb[pixel].g, 255 - rgb[pixel].g, percent);
      rgb[pixel].b = helpers::rgb::alpha_blend(rgb[pixel].b, 255 - rgb[pixel].b, percent);
    }
}
