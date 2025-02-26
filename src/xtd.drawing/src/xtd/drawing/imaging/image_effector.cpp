#include "../../../../include/xtd/drawing/imaging/image_effector.hpp"
#include <xtd/as>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;
using namespace xtd::helpers;

image image_effector::set_effect(const image& image, const effect& effect) {
  return set_effect(image, {0, 0, image.width(), image.height()}, effect);
}

image image_effector::set_effect(const image& image, const rectangle& rectangle, const effect& effect) {
  auto result = image.clone();
  set_effect(result, rectangle, effect);
  return result;
}

void image_effector::set_effect(image& image, const effects::effect& effect) {
  set_effect(image, {0, 0, image.width(), image.height()}, effect);
}

void image_effector::set_effect(image& image, const rectangle& rectangle, const effect& effect) {
  auto graphic = image.create_graphics();
  set_effect(graphic, rectangle, effect);
}

void image_effector::set_effect(graphics& graphics, const effect& effect) {
  set_effect(graphics, rectangle::round(graphics.clip_bounds()), effect);
}

void image_effector::set_effect(graphics& graphics, const rectangle& rectangle, const effect& effect) {
  if (!graphics.clip_bounds().contains(rectangle)) throw_helper::throws(xtd::helpers::exception_case::argument);
  effect.apply(graphics, rectangle);
}
