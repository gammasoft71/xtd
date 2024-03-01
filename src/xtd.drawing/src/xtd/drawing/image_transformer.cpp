#include "../../../include/xtd/drawing/image_transformer.h"

using namespace xtd::drawing;

void image_transformer::blur(image& image) {
  blur(image, 10);
}

image image_transformer::blur(const image& image) {
  return blur(image, 10);
}

void image_transformer::blur(image& image, int32 radius) {
  image.blur(radius);
}

image image_transformer::blur(const image& image, int32 radius) {
  auto result = image;
  blur(result, radius);
  return result;
}

void image_transformer::brightness(image& image, double percent) {
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x)
      image.set_pixel(x, y, color::brightness(image.get_pixel(x, y), percent));
}

image image_transformer::brightness(const image& image, double percent) {
  auto result = image;
  brightness(result, percent);
  return result;
}

void image_transformer::contrast(image& image, double percent) {
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x)
      image.set_pixel(x, y, color::contrast(image.get_pixel(x, y), percent));
}

image image_transformer::contrast(const image& image, double percent) {
  auto result = image;
  contrast(result, percent);
  return result;
}

void image_transformer::disabled(image& image, const color& back_color) {
  disabled(image, back_color.get_brightness());
}

image image_transformer::disabled(const image& image, const color& back_color) {
  return disabled(image, back_color.get_brightness());
}

void image_transformer::disabled(image& image, float brightness) {
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x)
      image.set_pixel(x, y, color::disabled(image.get_pixel(x, y), brightness));
}

image image_transformer::disabled(const image& image, float brightness) {
  auto result = image;
  disabled(result, brightness);
  return result;
}

void image_transformer::invert(image& image, double percent) {
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x)
      image.set_pixel(x, y, color::invert(image.get_pixel(x, y), percent));
}

image image_transformer::invert(const image& image, double percent) {
  auto result = image;
  invert(result, percent);
  return result;
}

void image_transformer::grayscale(image& image) {
  grayscale(image, 100);
}

image image_transformer::grayscale(const image& image) {
  return grayscale(image, 100);
}

void image_transformer::grayscale(image& image, double percent) {
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x)
      image.set_pixel(x, y, color::grayscale(image.get_pixel(x, y), percent));
}

image image_transformer::grayscale(const image& image, double percent) {
  auto result = image;
  grayscale(result, percent);
  return result;
}

void image_transformer::opacity(image& image, double percent) {
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x)
      image.set_pixel(x, y, color::from_argb(255 * percent, image.get_pixel(x, y)));
}

image image_transformer::opacity(const image& image, double percent) {
  auto result = image;
  opacity(result, percent);
  return result;
}

void image_transformer::rotate_flip(image& image, xtd::drawing::rotate_flip_type rotate_flip_type) {
  image.rotate_flip(rotate_flip_type);
}

image image_transformer::rotate_flip(const image& image, xtd::drawing::rotate_flip_type rotate_flip_type) {
  auto result = image;
  rotate_flip(result, rotate_flip_type);
  return result;
}

void image_transformer::saturate(image& image, double percent) {
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x)
      image.set_pixel(x, y, color::saturate(image.get_pixel(x, y), percent));
}

image image_transformer::saturate(const image& image, double percent) {
  auto result = image;
  saturate(result, percent);
  return result;
}

void image_transformer::sepia(image& image) {
  sepia(image, 100);
}

image image_transformer::sepia(const image& image) {
  return sepia(image, 100);
}

void image_transformer::sepia(image& image, double percent) {
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x)
      image.set_pixel(x, y, color::sepia(image.get_pixel(x, y), percent));
}

image image_transformer::sepia(const image& image, double percent) {
  auto result = image;
  sepia(result, percent);
  return result;
}
