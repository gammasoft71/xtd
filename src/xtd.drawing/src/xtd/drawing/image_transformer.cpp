#include "../../../include/xtd/drawing/image_transformer.h"

using namespace xtd::drawing;

image image_transformer::blur(const image& image) {
  return blur(image, 10);
}

image image_transformer::blur(const image& image, int32 radius) {
  return drawing::image {xtd::drawing::image::blur(image, radius)};
}

image image_transformer::brightness(const image& image, double percent) {
  if (image == drawing::image::empty) return image;
  auto result = image;
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x)
      result.set_pixel(x, y, color::brightness(image.get_pixel(x, y), percent));
  return result;
}

image image_transformer::contrast(const image& image, double percent) {
  if (image == drawing::image::empty) return image;
  auto result = image;
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x)
      result.set_pixel(x, y, color::contrast(image.get_pixel(x, y), percent));
  return result;
}

image image_transformer::disabled(const image& image, const color& back_color) {
  return disabled(image, back_color.get_brightness());
}

image image_transformer::disabled(const image& image, float brightness) {
  if (image == drawing::image::empty) return image;
  auto result = image;
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x)
      result.set_pixel(x, y, color::disabled(image.get_pixel(x, y), brightness));
  return result;
}

image image_transformer::invert(const image& image, double percent) {
  if (image == drawing::image::empty) return image;
  auto result = image;
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x)
      result.set_pixel(x, y, color::invert(image.get_pixel(x, y), percent));
  return result;
}

image image_transformer::grayscale(const image& image) {
  return grayscale(image, 100);
}

image image_transformer::grayscale(const image& image, double percent) {
  if (image == drawing::image::empty) return image;
  auto result = image;
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x)
      result.set_pixel(x, y, color::grayscale(image.get_pixel(x, y), percent));
  return result;
}

image image_transformer::opacity(const image& image, double percent) {
  if (image == drawing::image::empty) return image;
  auto result = image;
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x)
      result.set_pixel(x, y, color::from_argb(255 * percent, image.get_pixel(x, y)));
  return result;
}

image image_transformer::rotate_flip(const image& image, xtd::drawing::rotate_flip_type rotate_flip_type) {
  auto result = drawing::image {image};
  result.rotate_flip(rotate_flip_type);
  return result;
}

image image_transformer::sepia(const image& image) {
  return sepia(image, 100);
}

image image_transformer::sepia(const image& image, double percent) {
  if (image == drawing::image::empty) return image;
  auto result = image;
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x)
      result.set_pixel(x, y, color::sepia(image.get_pixel(x, y), percent));
  return result;
}
