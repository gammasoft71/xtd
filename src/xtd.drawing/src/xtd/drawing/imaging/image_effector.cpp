#include "../../../../include/xtd/drawing/imaging/image_effector.hpp"
#include <xtd/as>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;
using namespace xtd::helpers;

image image_effector::set_effect(const image& image, const effect& effect) {
  return set_effect(image, rectangle {0, 0, image.width(), image.height()}, effect);
}

image image_effector::set_effect(const image& image, int32 x, int32 y, int32 width, int32 height, const effect& effect) {
  return set_effect(image, rectangle {x, y, width, height}, effect);
}

image image_effector::set_effect(const image& image, float x, float y, float width, float height, const effect& effect) {
  return set_effect(image, rectangle_f {x, y, width, height}, effect);
}

image image_effector::set_effect(const image& image, const rectangle& rectangle, const effect& effect) {
  auto result = image.clone();
  set_effect(result, rectangle, effect);
  return result;
}

image image_effector::set_effect(const image& image, const rectangle_f& rectangle, const effect& effect) {
  return set_effect(image, rectangle::round(rectangle), effect);
}

image image_effector::set_effect(const image& image, const region& region, const effect& effect) {
  auto result = image.clone();
  set_effect(result, region, effect);
  return result;
}

void image_effector::set_effect(image& image, const effects::effect& effect) {
  set_effect(image, rectangle {0, 0, image.width(), image.height()}, effect);
}

void image_effector::set_effect(image& image, int32 x, int32 y, int32 width, int32 height, const effect& effect) {
  set_effect(image, rectangle {x, y, width, height}, effect);
}

void image_effector::set_effect(image& image, float x, float y, float width, float height, const effect& effect) {
  set_effect(image, rectangle_f {x, y, width, height}, effect);
}

void image_effector::set_effect(image& image, const rectangle& rectangle, const effect& effect) {
  auto graphic = image.create_graphics();
  set_effect(graphic, rectangle, effect);
}

void image_effector::set_effect(image& image, const rectangle_f& rectangle, const effect& effect) {
  set_effect(image, rectangle::round(rectangle), effect);
}

void image_effector::set_effect(image& image, const region& region, const effect& effect) {
  auto graphic = image.create_graphics();
  set_effect(graphic, region, effect);
}

void image_effector::set_effect(graphics& graphics, const effect& effect) {
  set_effect(graphics, rectangle::round(graphics.clip_bounds()), effect);
}

void image_effector::set_effect(graphics& graphics, int32 x, int32 y, int32 width, int32 height, const effect& effect) {
  set_effect(graphics, rectangle {x, y, width, height}, effect);
}

void image_effector::set_effect(graphics& graphics, float x, float y, float width, float height, const effect& effect) {
  set_effect(graphics, rectangle_f {x, y, width, height}, effect);
}

void image_effector::set_effect(graphics& graphics, const rectangle& rectangle, const effect& effect) {
  if (!graphics.clip_bounds().contains(rectangle)) throw_helper::throws(xtd::helpers::exception_case::argument);
  effect.apply(graphics, rectangle);
}

void image_effector::set_effect(graphics& graphics, const rectangle_f& rectangle, const effect& effect) {
  set_effect(graphics, rectangle::round(rectangle), effect);
}

void image_effector::set_effect(xtd::drawing::graphics& graphics, const xtd::drawing::region& region, const xtd::drawing::imaging::effects::effect& effect) {
  auto old_clip = graphics.clip();
  graphics.clip(region);
  set_effect(graphics, region.get_bounds(), effect);
  graphics.clip(old_clip);
}
