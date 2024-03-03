#include "../../../include/xtd/drawing/color_converter.h"
#include "../../../include/xtd/drawing/image_converter.h"
#include <xtd/math>
#include <algorithm>
#include <tuple>

using namespace xtd::drawing;
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
  threshold = std::clamp(threshold, 0, 765);
  auto rgb = reinterpret_cast<rgb_ptr>(image.get_rgb());
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      auto lower = rgb[pixel].r + rgb[pixel].g + rgb[pixel].b <= threshold;
      rgb[pixel].r = lower ? lower_color.r() : upper_color.r();
      rgb[pixel].g = lower ? lower_color.g() : upper_color.g();
      rgb[pixel].b = lower ? lower_color.b() : upper_color.b();
    }
}

image image_converter::bitonal(const image& image, int32 threshold, const drawing::color& upper_color, const drawing::color& lower_color) {
  auto result = image;
  image_converter::bitonal(result, threshold, upper_color, lower_color);
  return result;
}

void image_converter::blur(image& image, int32 radius) {
  image.blur(radius);
}

image image_converter::blur(const image& image, int32 radius) {
  auto result = image;
  blur(result, radius);
  return result;
}

void image_converter::brightness(image& image, double percent) {
  percent = std::clamp(percent, 0.0, 2.0);
  auto rgb = reinterpret_cast<rgb_ptr>(image.get_rgb());
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      rgb[pixel].r = percent < 1.0 ? alpha_blend(rgb[pixel].r, 0, 1.0 - percent) : alpha_blend(rgb[pixel].r, 255, percent - 1.0);
      rgb[pixel].g = percent < 1.0 ? alpha_blend(rgb[pixel].g, 0, 1.0 - percent) : alpha_blend(rgb[pixel].g, 255, percent - 1.0);
      rgb[pixel].b = percent < 1.0 ? alpha_blend(rgb[pixel].b, 0, 1.0 - percent) : alpha_blend(rgb[pixel].b, 255, percent - 1.0);
    }
}

image image_converter::brightness(const image& image, double percent) {
  auto result = image;
  brightness(result, percent);
  return result;
}

void image_converter::color(xtd::drawing::image& image, const xtd::drawing::color& color, double percent) {
  percent = std::clamp(percent - 1.0, -1.0, 1.0);
  auto rgb = reinterpret_cast<rgb_ptr>(image.get_rgb());
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      auto r = std::clamp(static_cast<int32>(rgb[pixel].r) + color.r(), 0, 255);
      auto g = std::clamp(static_cast<int32>(rgb[pixel].g) + color.g(), 0, 255);
      auto b = std::clamp(static_cast<int32>(rgb[pixel].b) + color.b(), 0, 255);
      rgb[pixel].r = alpha_blend(rgb[pixel].r, static_cast<byte>(r), percent);
      rgb[pixel].g = alpha_blend(rgb[pixel].g, static_cast<byte>(g), percent);
      rgb[pixel].b = alpha_blend(rgb[pixel].b, static_cast<byte>(b), percent);
    }
}

xtd::drawing::image image_converter::color(const xtd::drawing::image& image, const xtd::drawing::color& color, double percent) {
  auto result = image;
  image_converter::color(result, color, percent);
  return result;
}

void image_converter::color_extraction(xtd::drawing::image& image, int32 threshold, const drawing::color& extraction_color, const xtd::drawing::color& other_pixels_color) noexcept {
  threshold = std::clamp(threshold, 0, 765);
  auto rgb = reinterpret_cast<rgb_ptr>(image.get_rgb());
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;

      int extraction_total_rgb = extraction_color.r() + extraction_color.g() + extraction_color.b();
      int total_rgb = rgb[pixel].r + rgb[pixel].g + rgb[pixel].b;
      if (math::abs(total_rgb - extraction_total_rgb) >= threshold) {
        rgb[pixel].r = other_pixels_color.r();
        rgb[pixel].g = other_pixels_color.g();
        rgb[pixel].b = other_pixels_color.b();
      }
    }
}

xtd::drawing::image image_converter::color_extraction(const xtd::drawing::image& image, int32 threshold, const drawing::color& extraction_color, const xtd::drawing::color& other_pixels_color) noexcept {
  auto result = image;
  color_extraction(result, threshold, extraction_color, other_pixels_color);
  return result;
}

void image_converter::contrast(image& image, double percent) {
  if (percent < 0.0) percent = 0.0;
  auto rgb = reinterpret_cast<rgb_ptr>(image.get_rgb());
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      auto r = std::clamp(((((rgb[pixel].r / 255.0) - 0.5) * percent) + 0.5) * 255.0, .0, 255.0);
      auto g = std::clamp(((((rgb[pixel].g / 255.0) - 0.5) * percent) + 0.5) * 255.0, .0, 255.0);
      auto b = std::clamp(((((rgb[pixel].b / 255.0) - 0.5) * percent) + 0.5) * 255.0, .0, 255.0);
      rgb[pixel].r = static_cast<byte>(r);
      rgb[pixel].g = static_cast<byte>(g);
      rgb[pixel].b = static_cast<byte>(b);
    }
}

image image_converter::contrast(const image& image, double percent) {
  auto result = image;
  contrast(result, percent);
  return result;
}

void image_converter::disabled(image& image, const drawing::color& back_color) {
  disabled(image, back_color.get_brightness());
}

image image_converter::disabled(const image& image, const drawing::color& back_color) {
  return disabled(image, back_color.get_brightness());
}

void image_converter::disabled(image& image, float brightness) {
  auto rgb = reinterpret_cast<rgb_ptr>(image.get_rgb());
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      rgb[pixel].r = alpha_blend(rgb[pixel].r, 255 * brightness, 0.4);
      rgb[pixel].g = alpha_blend(rgb[pixel].g, 255 * brightness, 0.4);
      rgb[pixel].b = alpha_blend(rgb[pixel].b, 255 * brightness, 0.4);
    }
}

image image_converter::disabled(const image& image, float brightness) {
  auto result = image;
  disabled(result, brightness);
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
  auto rgb = reinterpret_cast<rgb_ptr>(image.get_rgb());
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      auto grayscale = static_cast<xtd::byte>((0.299 * rgb[pixel].r) + (0.587 * rgb[pixel].g) + (0.114 * rgb[pixel].b));
      rgb[pixel].r = alpha_blend(rgb[pixel].r, grayscale, percent);
      rgb[pixel].g = alpha_blend(rgb[pixel].g, grayscale, percent);
      rgb[pixel].b = alpha_blend(rgb[pixel].b, grayscale, percent);
    }
}

image image_converter::grayscale(const image& image, double percent) {
  auto result = image;
  grayscale(result, percent);
  return result;
}

void image_converter::hue_rotate(image& image, int angle) {
  angle = std::clamp(angle, 0, 360);
  auto rgb = reinterpret_cast<rgb_ptr>(image.get_rgb());
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      auto [h, s, l] = to_hsl(rgb[pixel].r, rgb[pixel].g, rgb[pixel].b);
      h = (static_cast<int>(h) + angle) % 360;
      if (h < 0) h += 360;
      auto [r, g, b] = from_hsl(h, s, l);
      rgb[pixel].r = r;
      rgb[pixel].g = g;
      rgb[pixel].b = b;
    }
}

image image_converter::hue_rotate(const image& image, int angle) {
  auto result = image;
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
  auto rgb = reinterpret_cast<rgb_ptr>(image.get_rgb());
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      rgb[pixel].r = alpha_blend(rgb[pixel].r, 255 - rgb[pixel].r, percent);
      rgb[pixel].g = alpha_blend(rgb[pixel].g, 255 - rgb[pixel].g, percent);
      rgb[pixel].b = alpha_blend(rgb[pixel].b, 255 - rgb[pixel].b, percent);
    }
}

image image_converter::invert(const image& image, double percent) {
  auto result = image;
  invert(result, percent);
  return result;
}

void image_converter::opacity(image& image, double percent) {
  percent = std::clamp(percent, 0.0, 1.0);
  auto alpha = image.get_alpha();
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      alpha[pixel] = 255 * percent;
    }
}

image image_converter::opacity(const image& image, double percent) {
  auto result = image;
  opacity(result, percent);
  return result;
}

void image_converter::resize(xtd::drawing::image& image, const xtd::drawing::size& size) {
  image = xtd::drawing::image {image, size.width(), size.height()};
}

xtd::drawing::image image_converter::resize(const xtd::drawing::image& image, const xtd::drawing::size& size) {
  auto result = image;
  resize(result, size);
  return result;
}

void image_converter::rotate_flip(image& image, xtd::drawing::rotate_flip_type rotate_flip_type) {
  image.rotate_flip(rotate_flip_type);
}

image image_converter::rotate_flip(const image& image, xtd::drawing::rotate_flip_type rotate_flip_type) {
  auto result = image;
  rotate_flip(result, rotate_flip_type);
  return result;
}

void image_converter::saturate(image& image, double percent) {
  if (percent < .0) percent = 0;  
  auto rgb = reinterpret_cast<rgb_ptr>(image.get_rgb());
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      auto r = rgb[pixel].r / 255.0;
      auto g = rgb[pixel].g / 255.0;
      auto b = rgb[pixel].b / 255.0;
      
      auto gray = 0.2989 * r + 0.5870 * g + 0.1140 * b;
      auto saturated_r = gray + (r - gray) * percent;
      auto saturated_g = gray + (g - gray) * percent;
      auto saturated_b = gray + (b - gray) * percent;
      
      saturated_r = std::clamp(saturated_r, 0.0, 1.0);
      saturated_g = std::clamp(saturated_g, 0.0, 1.0);
      saturated_b = std::clamp(saturated_b, 0.0, 1.0);

      rgb[pixel].r = static_cast<int>(saturated_r * 255);
      rgb[pixel].g = static_cast<int>(saturated_g * 255);
      rgb[pixel].b = static_cast<int>(saturated_b * 255);
    }
}

image image_converter::saturate(const image& image, double percent) {
  auto result = image;
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
  auto rgb = reinterpret_cast<rgb_ptr>(image.get_rgb());
  for (auto y = 0; y < image.height(); ++y)
    for (auto x = 0; x < image.width(); ++x) {
      auto pixel = y * image.width() + x;
      auto r = std::clamp(0.393 * rgb[pixel].r + 0.769 * rgb[pixel].g + 0.189 * rgb[pixel].b, .0, 255.0);
      auto g = std::clamp(0.349 * rgb[pixel].r + 0.686 * rgb[pixel].g + 0.168 * rgb[pixel].b, .0, 255.0);
      auto b = std::clamp(0.272 * rgb[pixel].r + 0.534 * rgb[pixel].g + 0.131 * rgb[pixel].b, .0, 255.0);
      rgb[pixel].r = alpha_blend(rgb[pixel].r, static_cast<byte>(r), percent);
      rgb[pixel].g = alpha_blend(rgb[pixel].g, static_cast<byte>(g), percent);
      rgb[pixel].b = alpha_blend(rgb[pixel].b, static_cast<byte>(b), percent);
    }
}

image image_converter::sepia(const image& image, double percent) {
  auto result = image;
  sepia(result, percent);
  return result;
}

void image_converter::threshold(image& image, int32 threshold) {
  bitonal(image, threshold, color::white, color::black);
}

image image_converter::threshold(const image& image, int32 threshold) {
  auto result = image;
  image_converter::threshold(result, threshold);
  return result;
}
