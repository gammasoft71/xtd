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

blur_effect::blur_effect(int32 radius) : blur_effect {radius, radius, false} {
}

blur_effect::blur_effect(int32 radius, bool expand_edge) : blur_effect {radius, radius, expand_edge} {
}

blur_effect::blur_effect(int32 horizontal_radius, int32 vertical_radius) : blur_effect {horizontal_radius, vertical_radius, false} {
}

blur_effect::blur_effect(int32 horizontal_radius, int32 vertical_radius, bool expand_edge) : expand_edge {expand_edge}, horizontal_radius {horizontal_radius}, vertical_radius {vertical_radius} {
}

void blur_effect::apply(xtd::drawing::image& image) const {
  if (expand_edge) image_effector::set_effect(image, resize_effect {rectangle {horizontal_radius, vertical_radius, image.width() + horizontal_radius * 2, image.height() + vertical_radius * 2}});
  image.blur(horizontal_radius, vertical_radius);
}
