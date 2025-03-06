#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/saturate_effect.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

saturate_effect::saturate_effect(double percent) : percent {percent} {
}

void saturate_effect::apply(xtd::drawing::image& image) const {
  auto percent = this->percent < .0 ? 0 : this->percent;
  auto alpha = reinterpret_cast<helpers::alpha*>(image.alpha());
  auto rgb = reinterpret_cast<helpers::rgb*>(image.rgb());

  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      if (!alpha[pixel].a) continue;
      auto r = rgb[pixel].r / 255.0;
      auto g = rgb[pixel].g / 255.0;
      auto b = rgb[pixel].b / 255.0;
      auto gray = 0.2989 * r + 0.5870 * g + 0.1140 * b;
      rgb[pixel].r = static_cast<xtd::byte>(math::clamp(gray + (r - gray) * percent, 0.0, 1.0) * 255);
      rgb[pixel].g = static_cast<xtd::byte>(math::clamp(gray + (g - gray) * percent, 0.0, 1.0) * 255);
      rgb[pixel].b = static_cast<xtd::byte>(math::clamp(gray + (b - gray) * percent, 0.0, 1.0) * 255);
    }
}
