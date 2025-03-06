#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/opacity_effect.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

opacity_effect::opacity_effect(double percent) : percent {percent} {
}

void opacity_effect::apply(xtd::drawing::image& image) const {
  auto percent = math::clamp(this->percent, 0.0, 1.0);
  auto alpha = reinterpret_cast<helpers::alpha*>(image.alpha());

  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      if (!alpha[pixel].a) continue;
      alpha[pixel].a = static_cast<xtd::byte>(255 * percent);
    }
}
