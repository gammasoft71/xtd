#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/sepia_effect.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

sepia_effect::sepia_effect(double percent) : percent {percent} {
}

// For more information about algorithm see https://www.programmingalgorithms.com/algorithm/sepia
void sepia_effect::apply(xtd::drawing::image& image) const {
  auto percent = math::clamp(this->percent, 0.0, 1.0);
  auto alpha = reinterpret_cast<helpers::alpha*>(image.alpha());
  auto rgb = reinterpret_cast<helpers::rgb*>(image.rgb());

  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      if (!alpha[pixel].a) continue;
      auto value = rgb[pixel];
      rgb[pixel].r = helpers::rgb::alpha_blend(rgb[pixel].r, static_cast<byte>(math::clamp(0.393 * value.r + 0.769 * value.g + 0.189 * value.b, .0, 255.0)), percent);
      rgb[pixel].g = helpers::rgb::alpha_blend(value.g, static_cast<byte>(math::clamp(0.349 * value.r + 0.686 * value.g + 0.168 * value.b, .0, 255.0)), percent);
      rgb[pixel].b = helpers::rgb::alpha_blend(value.b, static_cast<byte>(math::clamp(0.272 * value.r + 0.534 * value.g + 0.131 * value.b, .0, 255.0)), percent);
    }
}
