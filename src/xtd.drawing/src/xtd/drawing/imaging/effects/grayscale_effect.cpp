#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/grayscale_effect.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

grayscale_effect::grayscale_effect(double percent) : percent {percent} {
}

// For more information about algorithm see https://www.programmingalgorithms.com/algorithm/grayscale
void grayscale_effect::apply(xtd::drawing::image& image) const {
  auto percent = math::clamp(this->percent, 0.0, 1.0);
  auto alpha = reinterpret_cast<helpers::alpha*>(image.alpha());
  auto rgb = reinterpret_cast<helpers::rgb*>(image.rgb());

  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      if (!alpha[pixel].a) continue;
      auto grayscale = static_cast<xtd::byte>((0.299 * rgb[pixel].r) + (0.587 * rgb[pixel].g) + (0.114 * rgb[pixel].b));
      rgb[pixel].r = helpers::rgb::alpha_blend(rgb[pixel].r, grayscale, percent);
      rgb[pixel].g = helpers::rgb::alpha_blend(rgb[pixel].g, grayscale, percent);
      rgb[pixel].b = helpers::rgb::alpha_blend(rgb[pixel].b, grayscale, percent);
    }
}
