#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/gamma_correction_effect.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

gamma_correction_effect::gamma_correction_effect(double r, double g, double b) : r {r}, g {g}, b {b} {
}

// For more information about algorithm see https://www.programmingalgorithms.com/algorithm/gamma
void gamma_correction_effect::apply(xtd::drawing::image& image) const {
  auto r = math::clamp(this->r, .1, 5.0);
  auto g = math::clamp(this->g, .1, 5.0);
  auto b = math::clamp(this->b, .1, 5.0);
  auto alpha = reinterpret_cast<helpers::alpha*>(image.alpha());
  auto rgb = reinterpret_cast<helpers::rgb*>(image.rgb());

  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      if (!alpha[pixel].a) continue;
      rgb[pixel].r = static_cast<xtd::byte>(math::min(255, static_cast<int32>((255.0 * math::pow(rgb[pixel].r / 255.0, 1.0 / r)) + 0.5)));
      rgb[pixel].g = static_cast<xtd::byte>(math::min(255, static_cast<int32>((255.0 * math::pow(rgb[pixel].g / 255.0, 1.0 / g)) + 0.5)));
      rgb[pixel].b = static_cast<xtd::byte>(math::min(255, static_cast<int32>((255.0 * math::pow(rgb[pixel].b / 255.0, 1.0 / b)) + 0.5)));
    }
}
