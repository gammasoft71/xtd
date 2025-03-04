#include "../../../../../include/xtd/drawing/imaging/effects/crop_effect.hpp"
#include "../../../../../include/xtd/drawing/imaging/image_effector.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/resize_effect.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;
using namespace xtd::helpers;

crop_effect::crop_effect(const xtd::drawing::rectangle& rectangle) : rectangle {rectangle} {
}

crop_effect::crop_effect(const xtd::drawing::size& size) : crop_effect {drawing::rectangle {point {0, 0}, size}} {
}

void crop_effect::apply(xtd::drawing::image& image) const {
  if (image == drawing::image::empty) return;
  if (rectangle.x < 0 || rectangle.y < 0 || (rectangle.x + rectangle.width) > image.width() || (rectangle.y + rectangle.height) > image.height()) throw_helper::throws(exception_case::argument);
  image_effector::set_effect(image, resize_effect {rectangle});
}
