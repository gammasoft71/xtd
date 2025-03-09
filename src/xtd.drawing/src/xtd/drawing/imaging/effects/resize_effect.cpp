#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/resize_effect.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/collections/generic/list>
#include <xtd/helpers/throw_helper>
#include <xtd/math>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;
using namespace xtd::helpers;

namespace {
  /*
  // Helper function to calculate average color of a given set of pixels
  color calculate_average_color(const list<color>& colors) {
    if (colors.empty()) return color::transparent;
    
    auto r = 0_u32, g = 0_u32, b = 0_u32;
    for (const auto& c : colors) {
      r += c.r();
      g += c.g();
      b += c.b();
    }
    auto count = colors.count();
    return color::from_argb(255, r / count, g / count, b / count);
  }

  // Function to get images pixels
  list<color> get_image_colors(const image& image) {
    auto bitmap = drawing::bitmap {image};
    auto colors = list<color> {};
    for (auto x = 0; x < bitmap.width(); ++x) {
      colors.add(bitmap.get_pixel(x, 0)); // Top border
      colors.add(bitmap.get_pixel(x, image.height() - 1)); // Bottom border
    }
    for (int y = 0; y < bitmap.height(); ++y) {
      colors.add(bitmap.get_pixel(0, y)); // Left border
      colors.add(bitmap.get_pixel(image.width() - 1, y)); // Right border
    }
    return colors;
  }
  
  // Function to enhance the color (increase saturation & adjust brightness)
  color enhance_color(const color& c) {
    int r = c.r(), g = c.g(), b = c.b();
    auto max_value = std::max({r, g, b});
    auto min_value = std::min({r, g, b});
    auto delta = max_value - min_value;
    
    // Increase saturation
    if (delta > 0) {
      r = std::min(255, r + delta / 2);
      g = std::min(255, g + delta / 2);
      b = std::min(255, b + delta / 2);
    }
    
    // Adjust brightness if needed
    auto brightness = (r + g + b) / 3;
    if (brightness < 100) {
      r = std::min(255, r + 30);
      g = std::min(255, g + 30);
      b = std::min(255, b + 30);
    }
    
    return color::from_argb(255, r, g, b);
  }
  
  // Determine the best fill color
  color determine_fill_color(const image& image) {
    auto border_colors = get_image_colors(image);
    auto avg_color = calculate_average_color(border_colors);
    return enhance_color(avg_color);
  }
  */

  // Determine the best fill color
  color determine_fill_color(const image& image) {
    if (image == drawing::image::empty) return color::transparent;
    
    int total_r = 0, total_g = 0, total_b = 0, total_a = 0;
    int count = 0;
    
    auto bitmap = drawing::bitmap {image};
    auto width = bitmap.width();
    auto height = bitmap.height();
    
    for (int x = 0; x < width; ++x) {
      auto top_pixel = bitmap.get_pixel(x, 0);
      auto bottom_pixel = bitmap.get_pixel(x, height - 1);
      total_r += top_pixel.r() + bottom_pixel.r();
      total_g += top_pixel.g() + bottom_pixel.g();
      total_b += top_pixel.b() + bottom_pixel.b();
      total_a += top_pixel.a() + bottom_pixel.a();
      count += 2;
    }
    
    for (int y = 0; y < height; ++y) {
      auto left_pixel = bitmap.get_pixel(0, y);
      auto right_pixel = bitmap.get_pixel(width - 1, y);
      total_r += left_pixel.r() + right_pixel.r();
      total_g += left_pixel.g() + right_pixel.g();
      total_b += left_pixel.b() + right_pixel.b();
      total_a += left_pixel.a() + right_pixel.a();
      count += 2;
    }
    
    return color::from_argb(total_a / count, total_r / count, total_g / count, total_b / count);
  }
}

resize_effect::resize_effect(const xtd::drawing::rectangle& rectangle) : rectangle {rectangle} {
}

resize_effect::resize_effect(const xtd::drawing::rectangle& rectangle, bool auto_determine_fill_color) : auto_determine_fill_color {auto_determine_fill_color}, rectangle {rectangle} {
}

resize_effect::resize_effect(const xtd::drawing::rectangle& rectangle, const xtd::drawing::color& fill_color) : fill_color {fill_color}, rectangle {rectangle} {
}

resize_effect::resize_effect(const xtd::drawing::size& size) : resize_effect {drawing::rectangle {point {0, 0}, size}} {
}

resize_effect::resize_effect(const xtd::drawing::size& size, bool auto_determine_fill_color) : resize_effect {drawing::rectangle {point {0, 0}, size}, auto_determine_fill_color} {
}

resize_effect::resize_effect(const xtd::drawing::size& size, const xtd::drawing::color& fill_color) : resize_effect {drawing::rectangle {point {0, 0}, size}, fill_color} {
}

void resize_effect::apply(xtd::drawing::image& image) const {
  if (rectangle.x == 0 && rectangle.y == 0 && rectangle.width == image.width() && rectangle.height == image.height()) return;
  if (rectangle.x < 0 || rectangle.y < 0 || rectangle.width < 1 || rectangle.height < 1) throw_helper::throws(xtd::helpers::exception_case::argument);
  if (rectangle.width < image.width() && (rectangle.x + rectangle.width) > image.width()) throw_helper::throws(exception_case::argument);
  if (rectangle.height < image.height() && (rectangle.y + rectangle.height) > image.height()) throw_helper::throws(exception_case::argument);
  if (rectangle.width >= image.width() && (rectangle.x + image.width()) > rectangle.width) throw_helper::throws(exception_case::argument);
  if (rectangle.height >= image.height() && (rectangle.y + image.height()) > rectangle.height) throw_helper::throws(exception_case::argument);
  
  auto resized_image = bitmap {rectangle.width, rectangle.height};
  auto resized_image_graphics = resized_image.create_graphics();
  
  auto offset_image_x = rectangle.width < image.width() ? rectangle.x : 0;
  auto offset_image_y = rectangle.height < image.height() ? rectangle.y : 0;
  auto offset_x = rectangle.width >= image.width() ? rectangle.x : 0;
  auto offset_y = rectangle.height >= image.height() ? rectangle.y : 0;
  resized_image_graphics.draw_image(image, drawing::rectangle {offset_x, offset_y, rectangle.width, rectangle.height}, drawing::rectangle {offset_image_x, offset_image_y, rectangle.width, rectangle.height});
  
  auto fill_color = auto_determine_fill_color ? determine_fill_color(image) : this->fill_color;
  if (fill_color != color::transparent) {
    auto alpha = reinterpret_cast<helpers::alpha*>(resized_image.alpha());
    auto rgb = reinterpret_cast<helpers::rgb*>(resized_image.rgb());
    
    for (auto x = 0; x < rectangle.width; ++x) {
      for (auto y = 0; y < offset_y; ++y) {
        auto pixel = y * rectangle.width + x;
        alpha[pixel].a = fill_color.a();
        rgb[pixel] = {fill_color.r(), fill_color.g(), fill_color.b()};
      }

      for (auto y = offset_y + image.height(); y < rectangle.height; ++y) {
        auto pixel = y * rectangle.width + x;
        alpha[pixel].a = fill_color.a();
        rgb[pixel] = {fill_color.r(), fill_color.g(), fill_color.b()};
      }
    }

    for (auto y = offset_y; y < offset_y + image.height(); ++y) {
      for (auto x = 0; x < offset_x; ++x) {
        auto pixel = y * rectangle.width + x;
        alpha[pixel].a = fill_color.a();
        rgb[pixel] = {fill_color.r(), fill_color.g(), fill_color.b()};
      }
      
      for (auto x = offset_x +image.width(); x < rectangle.width; ++x) {
        auto pixel = y * rectangle.width + x;
        alpha[pixel].a = fill_color.a();
        rgb[pixel] = {fill_color.r(), fill_color.g(), fill_color.b()};
      }
    }
  }
  
  image = resized_image;
}
