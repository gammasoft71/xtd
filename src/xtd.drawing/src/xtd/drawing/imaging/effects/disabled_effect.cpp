#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/disabled_effect.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

disabled_effect::disabled_effect(const xtd::drawing::color& back_color) : brightness {back_color.get_brightness()} {
}

disabled_effect::disabled_effect(float brightness) : brightness {brightness} {
}

void disabled_effect::back_color(const xtd::drawing::color& value) {
  brightness = value.get_brightness();
}

void disabled_effect::apply(xtd::drawing::image& image) const {
  auto brightness = math::clamp(this->brightness, 0.0f, 1.0f);
  auto alpha = reinterpret_cast<helpers::alpha*>(image.alpha());
  auto rgb = reinterpret_cast<helpers::rgb*>(image.rgb());

  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      if (!alpha[pixel].a) continue;
      rgb[pixel] = helpers::rgb {
        .r = helpers::rgb::alpha_blend(rgb[pixel].r, static_cast<xtd::byte>(255 * brightness), 0.4),
        .g = helpers::rgb::alpha_blend(rgb[pixel].g, static_cast<xtd::byte>(255 * brightness), 0.4),
        .b = helpers::rgb::alpha_blend(rgb[pixel].b, static_cast<xtd::byte>(255 * brightness), 0.4)
      };
    }
}
