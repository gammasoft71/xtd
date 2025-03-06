#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/hue_rotate_effect.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

hue_rotate_effect::hue_rotate_effect(int32 angle) : angle {angle} {
}

void hue_rotate_effect::apply(xtd::drawing::image& image) const {
  auto angle = math::clamp(this->angle, 0, 360);
  auto alpha = reinterpret_cast<helpers::alpha*>(image.alpha());
  auto rgb = reinterpret_cast<helpers::rgb*>(image.rgb());

  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      if (!alpha[pixel].a) continue;
      auto [h, s, l] = rgb[pixel].to_hsl();
      h = static_cast<float>((static_cast<int>(h) + angle) % 360);
      if (h < 0) h += 360;
      rgb[pixel] = helpers::rgb::from_hsl(h, s, l);
    }
}
