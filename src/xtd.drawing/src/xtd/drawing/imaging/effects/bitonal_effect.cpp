#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/bitonal_effect.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

bitonal_effect::bitonal_effect(int32 threshold, color upper_color, color lower_color) : threshold {threshold}, upper_color {upper_color}, lower_color {lower_color} {
}

// For more information about algorithm see https://www.programmingalgorithms.com/algorithm/bitonal
void bitonal_effect::apply(xtd::drawing::image& image) const {
  auto threshold = math::clamp(this->threshold, 0, 3 * byte_object::max_value);
  auto alpha = reinterpret_cast<helpers::alpha*>(image.alpha());
  auto rgb = reinterpret_cast<helpers::rgb*>(image.rgb());

  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      if (!alpha[pixel].a) continue;
      auto lower = rgb[pixel].r + rgb[pixel].g + rgb[pixel].b <= threshold;
      rgb[pixel] = lower ? helpers::rgb {lower_color.r(), lower_color.g(), lower_color.b()} : helpers::rgb {upper_color.r(), upper_color.g(), upper_color.b()};
    }
}
