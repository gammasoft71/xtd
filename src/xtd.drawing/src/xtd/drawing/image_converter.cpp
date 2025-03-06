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
#include "../../../include/xtd/drawing/imaging/effects/posterize_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/resize_effect.hpp"
#include "../../../include/xtd/drawing/imaging/effects/solarize_effect.hpp"
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

namespace {
  struct rgb {
    xtd::byte r;
    xtd::byte g;
    xtd::byte b;
  };
  using rgb_ptr = rgb*;
  
  xtd::byte alpha_blend(xtd::byte fore_componant, xtd::byte back_componant, double percent) noexcept {
    return static_cast<xtd::byte>(fore_componant * (1 - percent) + back_componant * percent);
  }
  
  float get_hue(xtd::byte r, xtd::byte g, xtd::byte b) noexcept {
    if (r == g && g == b) return 0.0;
    
    auto rc = static_cast<float>(r) / 255.0f;
    auto gc = static_cast<float>(g) / 255.0f;
    auto bc = static_cast<float>(b) / 255.0f;
    
    auto max = static_cast<float>(xtd::math::max(xtd::math::max(rc, gc), bc));
    auto min = static_cast<float>(xtd::math::min(xtd::math::min(rc, gc), bc));
    
    auto delta = max - min;
    
    auto hue = 0.0f;
    if (rc == max) hue = (gc - bc) / delta;
    else if (gc == max) hue = 2 + (bc - rc) / delta;
    else if (bc == max) hue = 4 + (rc - gc) / delta;
    hue *= 60;
    
    if (hue < 0.0) hue += 360.0;
    return hue;
  }
  
  float get_saturation(xtd::byte r, xtd::byte g, xtd::byte b) noexcept {
    auto max = static_cast<float>(xtd::math::max(xtd::math::max(r, g), b)) / 255.0f;
    auto min = static_cast<float>(xtd::math::min(xtd::math::min(r, g), b)) / 255.0f;
    
    if (max == min) return 0.0f;
    
    return (max + min) <= 1.0f ? (max - min) / (max + min) : (max - min) / (2 - max - min);
  }
  
  float get_lightness(xtd::byte r, xtd::byte g, xtd::byte b) noexcept {
    return (static_cast<float>(xtd::math::max(xtd::math::max(r, g), b)) + static_cast<float>(xtd::math::min(xtd::math::min(r, g), b))) / 2.0f / 255.0f;
  }
  
  std::tuple<float, float, float> to_hsl(xtd::byte r, xtd::byte g, xtd::byte b) {
    return {get_hue(r, g, b), get_saturation(r, g, b), get_lightness(r, g, b)};
  }
  
  std::tuple<xtd::byte, xtd::byte, xtd::byte> from_hsl(float hue, float saturation, float lightness) noexcept {
    // algorithm version (see https://www.programmingalgorithms.com/algorithm/hsl-to-rgb)
    if (saturation == 0) return {static_cast<xtd::byte>(lightness * 255.0f), static_cast<xtd::byte>(lightness * 255.0f), static_cast<xtd::byte>(lightness * 255.0f)};
    
    auto hue_to_rgb = [](float v1, float v2, float vh)->float {
      if (vh < 0) vh += 1;
      if (vh > 1) vh -= 1;
      if ((6 * vh) < 1) return (v1 + (v2 - v1) * 6 * vh);
      if ((2 * vh) < 1) return v2;
      if ((3 * vh) < 2) return (v1 + (v2 - v1) * ((2.0f / 3) - vh) * 6);
      return v1;
    };
    
    hue = hue / 360.0f;
    auto v2 = (lightness < 0.5f) ? (lightness * (1 + saturation)) : ((lightness + saturation) - (lightness * saturation));
    auto v1 = 2 * lightness - v2;
    
    return {static_cast<xtd::byte>(hue_to_rgb(v1, v2, hue + (1.0f / 3)) * 255.0f), static_cast<xtd::byte>(hue_to_rgb(v1, v2, hue) * 255.0f), static_cast<xtd::byte>(hue_to_rgb(v1, v2, hue - (1.0f / 3)) * 255.0f)};
  }
}

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
  percent = std::clamp(percent, 0.0, 1.0);
  auto rgb = reinterpret_cast<rgb_ptr>(image.rgb());
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      auto grayscale = static_cast<xtd::byte>((0.299 * rgb[pixel].r) + (0.587 * rgb[pixel].g) + (0.114 * rgb[pixel].b));
      auto graysclae_r = alpha_blend(rgb[pixel].r, grayscale, percent);
      auto grayscale_g = alpha_blend(rgb[pixel].g, grayscale, percent);
      auto grayscale_b = alpha_blend(rgb[pixel].b, grayscale, percent);
      rgb[pixel] = {graysclae_r, grayscale_g, grayscale_b};
    }
}

image image_converter::grayscale(const image& image, double percent) {
  auto result = image.clone();
  grayscale(result, percent);
  return result;
}

void image_converter::hue_rotate(image& image, int angle) {
  angle = std::clamp(angle, 0, 360);
  auto rgb = reinterpret_cast<rgb_ptr>(image.rgb());
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      auto [h, s, l] = to_hsl(rgb[pixel].r, rgb[pixel].g, rgb[pixel].b);
      h = static_cast<float>((static_cast<int>(h) + angle) % 360);
      if (h < 0) h += 360;
      auto [hue_rotate_r, hue_rotate_g, hue_rotate_b] = from_hsl(h, s, l);
      rgb[pixel] = {hue_rotate_r, hue_rotate_g, hue_rotate_b};
    }
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
  percent = std::clamp(percent, 0.0, 1.0);
  auto rgb = reinterpret_cast<rgb_ptr>(image.rgb());
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      auto invert_r = alpha_blend(rgb[pixel].r, 255 - rgb[pixel].r, percent);
      auto invert_g = alpha_blend(rgb[pixel].g, 255 - rgb[pixel].g, percent);
      auto invert_b = alpha_blend(rgb[pixel].b, 255 - rgb[pixel].b, percent);
      rgb[pixel] = {invert_r, invert_g, invert_b};
    }
}

image image_converter::invert(const image& image, double percent) {
  auto result = image.clone();
  invert(result, percent);
  return result;
}

void image_converter::opacity(image& image, double percent) {
  percent = std::clamp(percent, 0.0, 1.0);
  auto alpha = image.alpha();
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      if (!alpha[pixel]) continue;
      auto opacity_a = static_cast<xtd::byte>(255 * percent);
      alpha[pixel] = opacity_a;
    }
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
}

image image_converter::rotate_flip(const image& image, xtd::drawing::rotate_flip_type rotate_flip_type) {
  auto result = image.clone();
  rotate_flip(result, rotate_flip_type);
  return result;
}

void image_converter::saturate(image& image, double percent) {
  if (percent < .0) percent = 0;
  auto rgb = reinterpret_cast<rgb_ptr>(image.rgb());
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      auto r = rgb[pixel].r / 255.0;
      auto g = rgb[pixel].g / 255.0;
      auto b = rgb[pixel].b / 255.0;
      auto gray = 0.2989 * r + 0.5870 * g + 0.1140 * b;
      auto saturated_r = static_cast<xtd::byte>(std::clamp(gray + (r - gray) * percent, 0.0, 1.0) * 255);
      auto saturated_g = static_cast<xtd::byte>(std::clamp(gray + (g - gray) * percent, 0.0, 1.0) * 255);
      auto saturated_b = static_cast<xtd::byte>(std::clamp(gray + (b - gray) * percent, 0.0, 1.0) * 255);
      rgb[pixel] = {saturated_r, saturated_g, saturated_b};
    }
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
  percent = std::clamp(percent, 0.0, 1.0);
  auto rgb = reinterpret_cast<rgb_ptr>(image.rgb());
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      auto sepia_r = alpha_blend(rgb[pixel].r, static_cast<byte>(std::clamp(0.393 * rgb[pixel].r + 0.769 * rgb[pixel].g + 0.189 * rgb[pixel].b, .0, 255.0)), percent);
      auto sepia_g = alpha_blend(rgb[pixel].g, static_cast<byte>(std::clamp(0.349 * rgb[pixel].r + 0.686 * rgb[pixel].g + 0.168 * rgb[pixel].b, .0, 255.0)), percent);
      auto sepia_b = alpha_blend(rgb[pixel].b, static_cast<byte>(std::clamp(0.272 * rgb[pixel].r + 0.534 * rgb[pixel].g + 0.131 * rgb[pixel].b, .0, 255.0)), percent);
      rgb[pixel] = {sepia_r, sepia_g, sepia_b};
    }
}

image image_converter::sepia(const image& image, double percent) {
  auto result = image.clone();
  sepia(result, percent);
  return result;
}

void image_converter::threshold(image& image, int32 threshold) {
  bitonal(image, threshold, color::white, color::black);
}

image image_converter::threshold(const image& image, int32 threshold) {
  auto result = image.clone();
  image_converter::threshold(result, threshold);
  return result;
}
