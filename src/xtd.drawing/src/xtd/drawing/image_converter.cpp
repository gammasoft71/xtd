#include "../../../include/xtd/drawing/imaging/effects/bitonal_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/blur_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/brightness_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/color_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/color_extraction_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/color_substitution_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/contrast_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/crop_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/disabled_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/drop_shadow_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/gamma_correction_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/grayscale_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/hue_rotate_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/invert_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/opacity_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/posterize_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/resize_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/saturate_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/sepia_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/solarize_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/threshold_effect.hpp"
#include "../../../include/xtd/drawing/imaging/image_effector.hpp"
#include "../../../include/xtd/drawing/color_converter.hpp"
#include "../../../include/xtd/drawing/image_converter.hpp"
#include <xtd/byte_object>
#include <xtd/math>
#include <algorithm>
#include <tuple>

// Most of the algorithms come from https://www.programmingalgorithms.com/category/image-processing/

using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

void image_converter::bitonal(image& image, int32 threshold, const drawing::color& upper_color, const drawing::color& lower_color) {
  image_effector::set_effect(image, bitonal_effect {threshold, upper_color, lower_color});
}

image image_converter::bitonal(const image& image, int32 threshold, const drawing::color& upper_color, const drawing::color& lower_color) {
  auto result = image.clone();
  image_converter::bitonal(result, threshold, upper_color, lower_color);
  return result;
}

void image_converter::blur(image& image, int32 radius) {
  image_effector::set_effect(image, blur_effect {radius});
}

image image_converter::blur(const image& image, int32 radius) {
  auto result = image.clone();
  blur(result, radius);
  return result;
}

void image_converter::brightness(image& image, double percent) {
  image_effector::set_effect(image, brightness_effect {percent});
}

image image_converter::brightness(const image& image, double percent) {
  auto result = image.clone();
  brightness(result, percent);
  return result;
}

void image_converter::color(xtd::drawing::image& image, const xtd::drawing::color& color, double percent) {
  image_effector::set_effect(image, color_effect {color, percent});
}

xtd::drawing::image image_converter::color(const xtd::drawing::image& image, const xtd::drawing::color& color, double percent) {
  auto result = image.clone();
  image_converter::color(result, color, percent);
  return result;
}

void image_converter::color_extraction(xtd::drawing::image& image, int32 threshold, const drawing::color& extraction_color, const xtd::drawing::color& other_pixels_color) noexcept {
  image_effector::set_effect(image, color_extraction_effect {threshold, extraction_color, other_pixels_color});
}

xtd::drawing::image image_converter::color_extraction(const xtd::drawing::image& image, int32 threshold, const drawing::color& extraction_color, const xtd::drawing::color& other_pixels_color) noexcept {
  auto result = image.clone();
  color_extraction(result, threshold, extraction_color, other_pixels_color);
  return result;
}

void image_converter::color_substitution(xtd::drawing::image& image, int32 threshold, const drawing::color& source_color, const xtd::drawing::color& new_color) noexcept {
  image_effector::set_effect(image, color_substitution_effect {threshold, source_color, new_color});
}

xtd::drawing::image image_converter::color_substitution(const xtd::drawing::image& image, int32 threshold, const drawing::color& source_color, const xtd::drawing::color& new_color) noexcept {
  auto result = image.clone();
  color_substitution(result, threshold, source_color, new_color);
  return result;
}

void image_converter::contrast(image& image, double percent) {
  image_effector::set_effect(image, contrast_effect {percent});
}

image image_converter::contrast(const image& image, double percent) {
  auto result = image.clone();
  contrast(result, percent);
  return result;
}

void image_converter::crop(xtd::drawing::image& image, const xtd::drawing::rectangle& rectangle) {
  image_effector::set_effect(image, crop_effect {rectangle});
}

xtd::drawing::image image_converter::crop(const xtd::drawing::image& image, const xtd::drawing::rectangle& rectangle) {
  auto result = image.clone();
  crop(result, rectangle);
  return result;
}

void image_converter::disabled(image& image, const drawing::color& back_color) {
  disabled(image, back_color.get_brightness());
}

image image_converter::disabled(const image& image, const drawing::color& back_color) {
  return disabled(image, back_color.get_brightness());
}

void image_converter::disabled(image& image, float brightness) {
  image_effector::set_effect(image, disabled_effect {brightness});
}

image image_converter::disabled(const image& image, float brightness) {
  auto result = image.clone();
  disabled(result, brightness);
  return result;
}

void image_converter::drop_shadow(xtd::drawing::image& image, int32 horizontal_shadow, int32 vertical_shadow, int32 blur, const xtd::drawing::color& color) {
  image_effector::set_effect(image, drop_shadow_effect {{horizontal_shadow, vertical_shadow}, blur, color});
}

xtd::drawing::image image_converter::drop_shadow(const xtd::drawing::image& image, int32 horizontal_shadow, int32 vertical_shadow, int32 blur, const xtd::drawing::color& color) {
  auto result = image.clone();
  drop_shadow(result, horizontal_shadow, vertical_shadow, blur, color);
  return result;
}

void image_converter::gamma_correction(xtd::drawing::image &image, double r, double g, double b) {
  image_effector::set_effect(image, gamma_correction_effect {r, g, b});
}

image image_converter::gamma_correction(const image& image, double r, double g, double b) {
  auto result = image.clone();
  gamma_correction(result, r, g, b);
  return result;
}

void image_converter::grayscale(image& image) {
  grayscale(image, 100);
}

image image_converter::grayscale(const image& image) {
  return grayscale(image, 100);
}

void image_converter::grayscale(image& image, double percent) {
  image_effector::set_effect(image, grayscale_effect {percent});
}

image image_converter::grayscale(const image& image, double percent) {
  auto result = image.clone();
  grayscale(result, percent);
  return result;
}

void image_converter::hue_rotate(image& image, int angle) {
  image_effector::set_effect(image, hue_rotate_effect {angle});
}

image image_converter::hue_rotate(const image& image, int angle) {
  auto result = image.clone();
  hue_rotate(result, angle);
  return result;
}

void image_converter::invert(image& image) {
  invert(image, 1.0);
}

image image_converter::invert(const image& image) {
  return invert(image, 1.0);
}

void image_converter::invert(image& image, double percent) {
  image_effector::set_effect(image, invert_effect {percent});
}

image image_converter::invert(const image& image, double percent) {
  auto result = image.clone();
  invert(result, percent);
  return result;
}

void image_converter::opacity(image& image, double percent) {
  image_effector::set_effect(image, opacity_effect {percent});
}

image image_converter::opacity(const image& image, double percent) {
  auto result = image.clone();
  opacity(result, percent);
  return result;
}

void image_converter::rescale(xtd::drawing::image& image, const xtd::drawing::size& size) {
  image.rescale(size.width, size.height);
}

xtd::drawing::image image_converter::rescale(const xtd::drawing::image& image, const xtd::drawing::size& size) {
  auto result = image.clone();
  rescale(result, size);
  return result;
}

void image_converter::resize(xtd::drawing::image& image, const xtd::drawing::size& size) {
  image_effector::set_effect(image, resize_effect {size});
}

xtd::drawing::image image_converter::resize(const xtd::drawing::image& image, const xtd::drawing::size& size) {
  auto result = image.clone();
  resize(result, size);
  return result;
}

void image_converter::resize(xtd::drawing::image& image, const xtd::drawing::rectangle& rectangle) {
  image_effector::set_effect(image, resize_effect {rectangle});
}

xtd::drawing::image image_converter::resize(const xtd::drawing::image& image, const xtd::drawing::rectangle& rectangle) {
  auto result = image.clone();
  resize(result, rectangle);
  return result;
}

void image_converter::rotate_flip(image& image, xtd::drawing::rotate_flip_type rotate_flip_type) {
  image.rotate_flip(rotate_flip_type);
  if (image.width() != image.height() && (rotate_flip_type == xtd::drawing::rotate_flip_type::rotate_90_flip_none ||
      rotate_flip_type == xtd::drawing::rotate_flip_type::rotate_270_flip_none ||
      rotate_flip_type == xtd::drawing::rotate_flip_type::rotate_90_flip_x ||
      rotate_flip_type == xtd::drawing::rotate_flip_type::rotate_270_flip_x)) rescale(image, {image.height(), image.width()});
}

image image_converter::rotate_flip(const image& image, xtd::drawing::rotate_flip_type rotate_flip_type) {
  auto result = image.clone();
  rotate_flip(result, rotate_flip_type);
  return result;
}

void image_converter::saturate(image& image, double percent) {
  image_effector::set_effect(image, saturate_effect {percent});
}

image image_converter::saturate(const image& image, double percent) {
  auto result = image.clone();
  saturate(result, percent);
  return result;
}

void image_converter::sepia(image& image) {
  sepia(image, 100);
}

image image_converter::sepia(const image& image) {
  return sepia(image, 100);
}

void image_converter::sepia(image& image, double percent) {
  image_effector::set_effect(image, sepia_effect {percent});
}

image image_converter::sepia(const image& image, double percent) {
  auto result = image.clone();
  sepia(result, percent);
  return result;
}

void image_converter::threshold(image& image, int32 threshold) {
  image_effector::set_effect(image, threshold_effect {threshold});
}

image image_converter::threshold(const image& image, int32 threshold) {
  auto result = image.clone();
  image_converter::threshold(result, threshold);
  return result;
}
