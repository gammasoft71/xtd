#include "../../../include/xtd/drawing/color_converter.h"

using namespace xtd;
using namespace xtd::drawing;


color color_converter::alpha_blend(const color& fore_color, const color& back_color, double alpha) noexcept {;
  return average(fore_color, back_color, alpha);
}

color color_converter::average(const color& color1, const color& color2, double weight) noexcept {
  return average(color1, color2, weight, false);
}

color color_converter::average(const color& color1, const color& color2, double weight, bool average_alpha) noexcept {
  weight = std::clamp(weight, 0.0, 1.0);
  auto alpha_blend = [](xtd::byte fore_componant, xtd::byte back_componant, double percent) {return static_cast<xtd::byte>(fore_componant * (1 - percent) + back_componant * percent);};
  return color::from_argb(alpha_blend(color1.a(), color2.a(), average_alpha ? weight : 1.0), alpha_blend(color1.r(), color2.r(), weight), alpha_blend(color1.g(), color2.g(), weight), alpha_blend(color1.b(), color2.b(), weight));
}

color color_converter::bi_tonal(const drawing::color& color, int32 threshold, const drawing::color& upper_color, const drawing::color& lower_color) noexcept {
  threshold = std::clamp(threshold, 0, 765);
  if (color.r() + color.g() + color.b() <= threshold) return lower_color;
  return upper_color;
}

color color_converter::brightness(const color& color, double percent) noexcept {
  percent = std::clamp(percent, 0.0, 2.0);
  return percent < 1.0 ? alpha_blend(color, color::black, 1.0 - percent) : alpha_blend(color, color::white, percent - 1.0);
}

color color_converter::contrast(const color& color, double percent) noexcept {
  // From https://efundies.com/adjust-the-contrast-of-an-image-in-c/
  if (percent < .0) percent = 0;
  
  auto r = std::clamp(((((color.r() / 255.0) - 0.5) * percent) + 0.5) * 255.0, .0, 255.0);
  auto g = std::clamp(((((color.g() / 255.0) - 0.5) * percent) + 0.5) * 255.0, .0, 255.0);
  auto b = std::clamp(((((color.b() / 255.0) - 0.5) * percent) + 0.5) * 255.0, .0, 255.0);
  
  return color::from_argb(color.a(), static_cast<xtd::byte>(r), static_cast<xtd::byte>(g), static_cast<xtd::byte>(b));
}

color color_converter::dark(const color& color) noexcept {
  return color::dark(color, 1.0 / 3);
}

color color_converter::dark(const color& color, double percent) noexcept {
  percent = std::clamp(percent, 0.0, 1.0);
  return alpha_blend(color, color::black, percent);
}

color color_converter::disabled(const color& fore_color, const color& back_color) noexcept {
  return disabled(fore_color, back_color.get_brightness());
}

color color_converter::disabled(const color& fore_color, float brightness) noexcept {
  brightness = std::clamp(brightness, .0f, 1.0f);
  return alpha_blend(fore_color, color::from_argb(0xFF000000 + (0xFFFFFF * brightness)), 0.4);
}

color color_converter::grayscale(const color& color) noexcept {
  return grayscale(color, 1.0);
}

color color_converter::grayscale(const color& color, double percent) noexcept {
  // From https://stackoverflow.com/questions/14330/rgb-to-monochrome-conversion
  percent = std::clamp(percent, 0.0, 1.0);
  auto grayscale = static_cast<xtd::byte>((0.299 * color.r()) + (0.587 * color.g()) + (0.114 * color.b()));
  return alpha_blend(color, color::from_argb(color.a(), grayscale, grayscale, grayscale), percent);
}

color color_converter::hue_rotate(const color& color, int angle) noexcept {
  angle = std::clamp(angle, 0, 360);
  
  auto h = static_cast<int>(color.get_hue());
  h = (h + angle) % 360;
  if (h < 0) h += 360;
  
  return color::from_hsl(static_cast<float>(h), color.get_saturation(), color.get_lightness());
}

color color_converter::invert(const color& color) noexcept {
  return invert(color, 1.0);
}

color color_converter::invert(const color& color,  double percent) noexcept {
  percent = std::clamp(percent, 0.0, 1.0);
  return alpha_blend(color, color::from_argb(color.a(), 255 - color.r(), 255 - color.g(), 255 - color.b()), percent);
}

color color_converter::light(const color& color) noexcept {
  return light(color, 1.0 / 3);
}

color color_converter::light(const color& color, double percent) noexcept {
  percent = std::clamp(percent, 0.0, 1.0);
  return alpha_blend(color, color::white, percent);
}

color color_converter::saturate(const color& color, double percent) noexcept {
  if (percent < .0) percent = 0;
  
  auto r = color.r() / 255.0;
  auto g = color.g() / 255.0;
  auto b = color.b() / 255.0;
  
  auto gray = 0.2989 * r + 0.5870 * g + 0.1140 * b;
  auto saturated_r = gray + (r - gray) * percent;
  auto saturated_g = gray + (g - gray) * percent;
  auto saturated_b = gray + (b - gray) * percent;
  
  saturated_r = std::clamp(saturated_r, 0.0, 1.0);
  saturated_g = std::clamp(saturated_g, 0.0, 1.0);
  saturated_b = std::clamp(saturated_b, 0.0, 1.0);
  
  return color::from_argb(color.a(), static_cast<int>(saturated_r * 255), static_cast<int>(saturated_g * 255), static_cast<int>(saturated_b * 255));
}

color color_converter::sepia(const color& color) noexcept {
  return sepia(color, 1.0);
}

color color_converter::sepia(const color& color, double percent) noexcept {
  // From https://www.geeksforgeeks.org/image-processing-in-java-colored-image-to-sepia-image-conversion/
  percent = std::clamp(percent, 0.0, 1.0);
  auto r = std::clamp(0.393 * color.r() + 0.769 * color.g() + 0.189 * color.b(), .0, 255.0);
  auto g = std::clamp(0.349 * color.r() + 0.686 * color.g() + 0.168 * color.b(), .0, 255.0);
  auto b = std::clamp(0.272 * color.r() + 0.534 * color.g() + 0.131 * color.b(), .0, 255.0);
  return alpha_blend(color, color::from_argb(color.a(), static_cast<xtd::byte>(r), static_cast<xtd::byte>(g), static_cast<xtd::byte>(b)), percent);
}

color color_converter::threshold(const color& color, int32 threshold) noexcept {
  return bi_tonal(color, threshold, color::white, color::black);
}
