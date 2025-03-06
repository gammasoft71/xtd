#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/color_effect.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

color_effect::color_effect(const xtd::drawing::color& color, double percent) : color {color}, percent {percent} {
}

// For more information about algorithm see https://www.programmingalgorithms.com/algorithm/color
void color_effect::apply(xtd::drawing::image& image) const {
  auto percent = math::clamp(this->percent - 1.0, -1.0, 1.0);
  auto alpha = reinterpret_cast<helpers::alpha*>(image.alpha());
  auto rgb = reinterpret_cast<helpers::rgb*>(image.rgb());
  
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      if (!alpha[pixel].a) continue;
      rgb[pixel] = helpers::rgb {
        .r = helpers::rgb::alpha_blend(rgb[pixel].r, static_cast<byte>(math::clamp(static_cast<int32>(rgb[pixel].r) + color.r(), 0, 255)), percent),
        .g = helpers::rgb::alpha_blend(rgb[pixel].g, static_cast<byte>(math::clamp(static_cast<int32>(rgb[pixel].g) + color.g(), 0, 255)), percent),
        .b = helpers::rgb::alpha_blend(rgb[pixel].b, static_cast<byte>(math::clamp(static_cast<int32>(rgb[pixel].b) + color.b(), 0, 255)), percent)
      };
    }
}
