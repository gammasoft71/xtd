#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/blur_effect.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/resize_effect.hpp"
#include "../../../../../include/xtd/drawing/imaging/image_effector.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

blur_effect::blur_effect(int32 radius) : blur_effect {radius, false} {
}

blur_effect::blur_effect(int32 radius, bool expand_edge) : expand_edge {expand_edge}, radius {radius} {
}

void blur_effect::apply(xtd::drawing::image& image) const {
  if (expand_edge) image_effector::set_effect(image, resize_effect {rectangle {radius / 2, radius / 2, image.width() + radius, image.height() + radius}});
  image.blur(radius);
}
