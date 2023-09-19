#include "../../../../include/xtd/drawing/drawing_2d/hatch_brush.h"
#include "../../../../include/xtd/drawing/bitmap.h"
#include <xtd/delegate.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/brush.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;

namespace {
  using point_collection = std::vector<xtd::drawing::point>;
  
  image create_empty_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    return bitmap;
  }
  
  image create_horizontal_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}, {7, 4}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_vertical_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {2, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_forward_diagonal_texture(const color& fore_color, const color& back_color) {
    static auto antialiasing_points = point_collection {{5, 0}, {7, 0}, {0, 1}, {6, 1}, {1, 2}, {7, 2}, {0, 3}, {2, 3}, {1, 4}, {3, 4}, {2, 5}, {4, 5}, {3, 6}, {5, 6}, {4, 7}, {6, 7}};
    static auto points = point_collection {{6, 0}, {7, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 6}, {5, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : antialiasing_points)
      graphics.draw_point(pen(color::from_argb(64, fore_color), 1), point);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_backward_diagonal_texture(const color& fore_color, const color& back_color) {
    static auto antialiasing_points = point_collection {{4, 0}, {6, 0}, {3, 1}, {5, 1}, {2, 2}, {4, 2}, {1, 3}, {3, 3}, {0, 4}, {2, 4}, {7, 5}, {1, 5}, {6, 6}, {0, 6}, {5, 7}, {7, 7}};
    static auto points = point_collection {{5, 0}, {4, 1}, {3, 2}, {2, 3}, {1, 4}, {0, 5}, {7, 6}, {6, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : antialiasing_points)
      graphics.draw_point(pen(color::from_argb(64, fore_color), 1), point);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_cross_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}, {7, 4}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 5}, {2, 6}, {2, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_diagonal_cross_texture(const color& fore_color, const color& back_color) {
    static auto antialiasing_points = point_collection {{5, 0}, {7, 0}, {0, 1}, {6, 1}, {1, 2}, {7, 2}, {0, 3}, {2, 3}, {1, 4}, {3, 4}, {2, 5}, {4, 5}, {3, 6}, {5, 6}, {4, 7}, {6, 7}, {4, 0}, {6, 0}, {3, 1}, {5, 1}, {2, 2}, {4, 2}, {1, 3}, {3, 3}, {0, 4}, {2, 4}, {7, 5}, {1, 5}, {6, 6}, {0, 6}, {5, 7}, {7, 7}};
    static auto points = point_collection {{6, 0}, {7, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 6}, {5, 7}, {5, 0}, {4, 1}, {3, 2}, {2, 3}, {1, 4}, {0, 5}, {7, 6}, {6, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : antialiasing_points)
      graphics.draw_point(pen(color::from_argb(64, fore_color), 1), point);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_percent_05_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{6, 0}, {2, 4}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_percent_10_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{2, 0}, {6, 2}, {2, 4}, {6, 6}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_percent_20_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{2, 0}, {6, 0}, {0, 2}, {4, 2}, {2, 4}, {6, 4}, {0, 6}, {4, 6}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_percent_25_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{2, 0}, {6, 0}, {0, 1}, {4, 1}, {2, 2}, {6, 2}, {0, 3}, {4, 3}, {2, 4}, {6, 4}, {0, 5}, {4, 5}, {2, 6}, {6, 6}, {0, 7}, {4, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_percent_30_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{0, 0}, {2, 0}, {4, 0}, {6, 0}, {3, 1}, {7, 1}, {0, 2}, {2, 2}, {4, 2}, {6, 2}, {1, 3}, {5, 3}, {0, 4}, {2, 4}, {4, 4}, {6, 4}, {3, 5}, {7, 5}, {0, 6}, {2, 6}, {4, 6}, {6, 6}, {1, 7}, {5, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_percent_40_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{0, 0}, {2, 0}, {4, 0}, {6, 0}, {1, 1}, {3, 1}, {5, 1}, {7, 1}, {0, 2}, {2, 2}, {4, 2}, {6, 2}, {1, 3}, {5, 3}, {7, 3}, {0, 4}, {2, 4}, {4, 4}, {6, 4}, {1, 5}, {3, 5}, {5, 5}, {7, 5}, {0, 6}, {2, 6}, {4, 6}, {6, 6}, {1, 7}, {3, 7}, {5, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_percent_50_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (int32 y = 0, index = 0; y < 8; y++, index++)
      for (int32 x = 0; x < 8; x++, index++)
        if (index % 2 == 0) graphics.draw_point(pen(fore_color, 1), x, y);
    return bitmap;
  }
  
  image create_percent_60_texture(const color& fore_color, const color& back_color) {
    return create_percent_40_texture(back_color, fore_color);
  }
  
  image create_percent_70_texture(const color& fore_color, const color& back_color) {
    return create_percent_30_texture(back_color, fore_color);
  }
  
  image create_percent_75_texture(const color& fore_color, const color& back_color) {
    return create_percent_25_texture(back_color, fore_color);
  }
  
  image create_percent_80_texture(const color& fore_color, const color& back_color) {
    return create_percent_20_texture(back_color, fore_color);
  }
  
  image create_percent_90_texture(const color& fore_color, const color& back_color) {
    return create_percent_10_texture(back_color, fore_color);
  }
  
  image create_light_downward_diagonal_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{2, 0}, {6, 0}, {3, 1}, {7, 1}, {0, 2}, {4, 2}, {1, 3}, {5, 3}, {2, 4}, {6, 4}, {3, 5}, {7, 5}, {0, 6}, {4, 6}, {1, 7}, {5, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_light_upward_diagonal_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{1, 0}, {5, 0}, {0, 1}, {4, 1}, {3, 2}, {7, 2}, {2, 3}, {6, 3}, {1, 4}, {5, 4}, {0, 5}, {4, 5}, {3, 6}, {7, 6}, {2, 7}, {6, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_dark_downward_diagonal_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{2, 0}, {3, 0}, {6, 0}, {7, 0}, {0, 1}, {3, 1}, {4, 1}, {7, 1}, {0, 2}, {1, 2}, {4, 2}, {5, 2}, {1, 3}, {2, 3}, {5, 3}, {6, 3}, {2, 4}, {3, 4}, {6, 4}, {7, 4}, {0, 5}, {3, 5}, {4, 5}, {7, 5}, {0, 6}, {1, 6}, {4, 6}, {5, 6}, {1, 7}, {2, 7}, {5, 7}, {6, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_dark_upward_diagonal_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{1, 0}, {2, 0}, {5, 0}, {6, 0}, {0, 1}, {1, 1}, {4, 1}, {5, 1}, {0, 2}, {3, 2}, {4, 2}, {7, 2}, {2, 3}, {3, 3}, {6, 3}, {7, 3}, {1, 4}, {2, 4}, {5, 4}, {6, 4}, {0, 5}, {1, 5}, {4, 5}, {5, 5}, {0, 6 }, {3, 6}, {4, 6}, {7, 6}, {2, 7}, {3, 7}, {6, 7}, {7, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_wide_downward_diagonal_texture(const color& fore_color, const color& back_color) {
    return create_light_downward_diagonal_texture(back_color, fore_color);
  }
  
  image create_wide_upward_diagonal_texture(const color& fore_color, const color& back_color) {
    return create_light_upward_diagonal_texture(back_color, fore_color);
  }
  
  image create_light_horizontal_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}, {7, 4}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_light_vertical_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{2, 0}, {6, 0}, {2, 1}, {6, 1}, {2, 2}, {6, 2}, {2, 3}, {6, 3}, {2, 4}, {6, 4}, {2, 5}, {6, 5}, {2, 6}, {6, 6}, {2, 7}, {6, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_narrow_horizontal_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}, {7, 2}, {0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}, {7, 4}, {0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {6, 6}, {7, 6}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_narrow_vertical_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{0, 0}, {2, 0}, {4, 0}, {6, 0}, {0, 1}, {2, 1}, {4, 1}, {6, 1}, {0, 2}, {2, 2}, {4, 2}, {6, 2}, {0, 3}, {2, 3}, {4, 3}, {6, 3}, {0, 4}, {2, 4}, {4, 4}, {6, 4}, {0, 5}, {2, 5}, {4, 5}, {6, 5}, {0, 6}, {2, 6}, {4, 6}, {6, 6}, {0, 7}, {2, 7}, {4, 7}, {6, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_dark_horizontal_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}, {7, 1}, {0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}, {7, 4}, {0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}, {6, 5}, {7, 5}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_dark_vertical_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{2, 0}, {3, 0}, {6, 0}, {7, 0}, {2, 1}, {3, 1}, {6, 1}, {7, 1}, {2, 2}, {3, 2}, {6, 2}, {7, 2}, {2, 3}, {3, 3}, {6, 3}, {7, 3}, {2, 4}, {3, 4}, {6, 4}, {7, 4}, {2, 5}, {3, 5}, {6, 5}, {7, 5}, {2, 6}, {3, 6}, {6, 6}, {7, 6}, {2, 7}, {3, 7}, {6, 7}, {7, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_dashed_downward_diagonal_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{0, 0}, {4, 0}, {1, 1}, {5, 1}, {2, 6}, {6, 6}, {3, 7}, {7, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_dashed_upward_diagonal_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{3, 0}, {7, 0}, {2, 1}, {6, 1}, {1, 6}, {5, 6}, {0, 7}, {4, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_dashed_horizontal_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{0, 0}, {1, 0}, {6, 0}, {7, 0}, {2, 4}, {3, 4}, {4, 4}, {5, 4}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_dashed_vertical_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{2, 0}, {2, 1}, {6, 2}, {6, 3}, {6, 4}, {6, 5}, {2, 6}, {2, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_small_confetti_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{5, 0}, {1, 1}, {4, 2}, {7, 3}, {2, 4}, {6, 5}, {3, 6}, {0, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_large_confetti_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{2, 0}, {3, 0}, {5, 0}, {6, 0}, {2, 1}, {3, 1}, {6, 2}, {7, 2}, {1, 3}, {2, 3}, {6, 3}, {7, 3}, {1, 4}, {2, 4}, {4, 4}, {5, 4}, {4, 5}, {5, 5}, {0, 6}, {1, 6}, {0, 7}, {1, 7}, {5, 7}, {6, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_zig_zag_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{1, 0}, {2, 0}, {0, 1}, {3, 1}, {4, 2}, {7, 2}, {5, 3}, {6, 3}, {1, 4}, {2, 4}, {0, 5}, {3, 5}, {4, 6}, {7, 6}, {5, 7}, {6, 7} };
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_wave_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{5, 1}, {6, 1}, {1, 2}, {4, 2}, {7, 2}, {2, 3}, {3, 3}, {5, 5}, {6, 5}, {1, 6}, {4, 6}, {7, 6}, {2, 7}, {3, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_diagonal_brick_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{5, 0}, {6, 0}, {4, 1}, {7, 1}, {0, 2}, {3, 2}, {1, 3}, {2, 3}, {1, 4}, {0, 5}, {7, 6}, {6, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_horizontal_brick_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {6, 1}, {6, 2}, {6, 3}, {0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}, {7, 4}, {2, 5}, {2, 6}, {2, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_weave_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{2, 0}, {6, 0}, {5, 1}, {7, 1}, {0, 2}, {4, 2}, {1, 3}, {3, 3}, {5, 3}, {2, 4}, {6, 4}, {3, 5}, {5, 5}, {7, 5}, {0, 6}, {4, 6}, {1, 7}, {3, 7}, {7, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_plaid_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{2, 0}, {3, 0}, {4, 0}, {5, 0}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {2, 3}, {3, 3}, {4, 3}, {5, 3}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    for (int32 y = 4, index = 0; y < 8; y++, index++)
      for (int32 x = 0; x < 8; x++, index++)
        if (index % 2 == 0) graphics.draw_point(pen(fore_color, 1), x, y);
    return bitmap;
  }
  
  image create_divot_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{2, 1}, {1, 2}, {2, 3}, {5, 5}, {6, 6}, {5, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_dotted_grid_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{2, 0}, {2, 2}, {0, 4}, {2, 4}, {4, 4}, {6, 4}, {2, 6}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_dotted_diamond_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{6, 0}, {0, 2}, {4, 2}, {2, 4}, {0, 6}, {4, 6}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_shingle_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{6, 0}, {7, 0}, {0, 1}, {1, 2}, {1, 3}, {0, 4}, {1, 4}, {2, 5}, {7, 5}, {3, 6}, {6, 6}, {4, 7}, {5, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_trellis_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {0, 1}, {3, 1}, {4, 1}, {7, 1}, {0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}, {7, 2}, {1, 3}, {2, 3}, {5, 3}, {6, 3}, {0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}, {7, 4}, {0, 5}, {3, 5}, {4, 5}, {7, 5}, {0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {6, 6}, {7, 6}, {1, 7}, {2, 7}, {5, 7}, {6, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_sphere_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{0, 0}, {1, 0}, {3, 0}, {4, 0}, {5, 0}, {7, 0}, {2, 1}, {5, 1}, {6, 1}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {6, 3}, {0, 4}, {1, 4}, {3, 4}, {4, 4}, {5, 4}, {7, 4}, {1, 5}, {2, 5}, {6, 5}, {0, 6}, {1, 6}, {2, 6}, {6, 6}, {7, 6}, {0, 7}, {1, 7}, {2, 7}, {6, 7}, {7, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_small_grid_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {2, 1}, {6, 1}, {2, 2}, {6, 2}, {2, 3}, {6, 3}, {0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}, {7, 4}, {2, 5}, {6, 5}, {2, 6}, {6, 6}, {2, 7}, {6, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_small_checker_board_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{1, 0}, {2, 0}, {5, 0}, {6, 0}, {0, 1}, {3, 1}, {4, 1}, {7, 1}, {0, 2}, {3, 2}, {4, 2}, {7, 2}, {1, 3}, {2, 3}, {5, 3}, {6, 3}, {1, 4}, {2, 4}, {5, 4}, {6, 4}, {0, 5}, {3, 5}, {4, 5}, {7, 5}, {0, 6}, {3, 6}, {4, 6}, {7, 6}, {1, 7}, {2, 7}, {5, 7}, {6, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_large_checker_board_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{0, 0}, {1, 0}, {6, 0}, {7, 0}, {0, 1}, {1, 1}, {6, 1}, {7, 1}, {0, 2}, {1, 2}, {6, 2}, {7, 2}, {0, 3}, {1, 3}, {6, 3}, {7, 3}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {2, 5}, {3, 5}, {4, 5}, {5, 5}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {2, 7}, {3, 7}, {4, 7}, {5, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_outlined_diamond_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{4, 0}, {6, 0}, {3, 1}, {7, 1}, {0, 2}, {2, 2}, {1, 3}, {0, 4}, {2, 4}, {3, 5}, {7, 5}, {4, 6}, {6, 6}, {5, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_solid_diamond_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {4, 1}, {5, 1}, {6, 1}, {5, 2}, {5, 4}, {4, 5}, {5, 5}, {6, 5}, {3, 6}, {4, 6}, {5, 6}, {6, 6}, {7, 6}, {0, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}, {6, 7}, {7, 7}};
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
  
  image create_wide_checker_board_texture(const color& fore_color, const color& back_color) {
    static auto points = point_collection {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {12, 0}, {13, 0}, {14, 0}, {15, 0}, {0, 1}, {1, 1}, {2, 1}, {3, 1}, {12, 1}, {13, 1}, {14, 1}, {15, 1}, {0, 2}, {1, 2}, {2, 2}, {3, 2}, {12, 2}, {13, 2}, {14, 2}, {15, 2}, {0, 3}, {1, 3}, {2, 3}, {3, 3}, {12, 3}, {13, 3}, {14, 3}, {15, 3}, {4, 4}, {5, 4}, {6, 4}, {7, 4}, {8, 4}, {9, 4}, {10, 4}, {11, 4}, {4, 5}, {5, 5}, {6, 5}, {7, 5}, {8, 5}, {9, 5}, {10, 5}, {11, 5}, {4, 6}, {5, 6}, {6, 6}, {7, 6}, {8, 6}, {9, 6}, {10, 6}, {11, 6}, {4, 7}, {5, 7}, {6, 7}, {7, 7}, {8, 7}, {9, 7}, {10, 7}, {11, 7}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {10, 8}, {11, 8}, {4, 9}, {5, 9}, {6, 9}, {7, 9}, {8, 9}, {9, 9}, {10, 9}, {11, 9}, {4, 10}, {5, 10}, {6, 10}, {7, 10}, {8, 10}, {9, 10}, {10, 10}, {11, 10}, {4, 11}, {5, 11}, {6, 11}, {7, 11}, {8, 11}, {9, 11}, {10, 11}, {11, 11}, {0, 12}, {1, 12}, {2, 12}, {3, 12}, {12, 12}, {13, 12}, {14, 12}, {15, 12}, {0, 13}, {1, 13}, {2, 13}, {3, 13}, {12, 13}, {13, 13}, {14, 13}, {15, 13}, {0, 14}, {1, 14}, {2, 14}, {3, 14}, {12, 14}, {13, 14}, {14, 14}, {15, 14}, {0, 15}, {1, 15}, {2, 15}, {3, 15}, {12, 15}, {13, 15}, {14, 15}, {15, 15}};
    auto bitmap = drawing::bitmap(16, 16);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    for (auto point : points)
      graphics.draw_point(pen(fore_color, 1), point);
    return bitmap;
  }
}

struct hatch_brush::data {
  xtd::drawing::drawing_2d::hatch_style hatch_style_ = xtd::drawing::drawing_2d::hatch_style::horizontal;
  xtd::drawing::color fore_color_;
  xtd::drawing::color back_color_;
};

hatch_brush::hatch_brush() : hatch_brush(xtd::drawing::drawing_2d::hatch_style::horizontal, xtd::drawing::color::black, xtd::drawing::color::black) {
}

hatch_brush::hatch_brush(xtd::drawing::drawing_2d::hatch_style hatch_style, const xtd::drawing::color& fore_color) : hatch_brush(hatch_style, fore_color, xtd::drawing::color::black) {
}

hatch_brush::hatch_brush(xtd::drawing::drawing_2d::hatch_style hatch_style, const xtd::drawing::color& fore_color, const xtd::drawing::color& back_color) : data_(std::make_shared<data>()) {
  data_->hatch_style_ = hatch_style;
  data_->fore_color_ = fore_color;
  data_->back_color_ = back_color;
  recreate_handle();
}

void hatch_brush::recreate_handle() {
  static auto textures = std::map<xtd::drawing::drawing_2d::hatch_style, delegate<image(const color&, const color&)>> {{hatch_style::horizontal, {create_horizontal_texture}}, {hatch_style::vertical, {create_vertical_texture}}, {hatch_style::forward_diagonal, {create_forward_diagonal_texture}}, {hatch_style::backward_diagonal, {create_backward_diagonal_texture}}, {hatch_style::cross, {create_cross_texture}}, {hatch_style::diagonal_cross, {create_diagonal_cross_texture}}, {hatch_style::percent_05, {create_percent_05_texture}}, {hatch_style::percent_10, {create_percent_10_texture}}, {hatch_style::percent_20, {create_percent_20_texture}}, {hatch_style::percent_25, {create_percent_25_texture}}, {hatch_style::percent_30, {create_percent_30_texture}}, {hatch_style::percent_40, {create_percent_40_texture}}, {hatch_style::percent_50, {create_percent_50_texture}}, {hatch_style::percent_60, {create_percent_60_texture}}, {hatch_style::percent_70, {create_percent_70_texture}}, {hatch_style::percent_75, {create_percent_75_texture}}, {hatch_style::percent_80, {create_percent_80_texture}}, {hatch_style::percent_90, {create_percent_90_texture}}, {hatch_style::light_downward_diagonal, {create_light_downward_diagonal_texture}}, {hatch_style::light_upward_diagonal, {create_light_upward_diagonal_texture}}, {hatch_style::dark_downward_diagonal, {create_dark_downward_diagonal_texture}}, {hatch_style::dark_upward_diagonal, {create_dark_upward_diagonal_texture}}, {hatch_style::wide_downward_diagonal, {create_wide_downward_diagonal_texture}}, {hatch_style::wide_upward_diagonal, {create_wide_upward_diagonal_texture}}, {hatch_style::light_horizontal, {create_light_horizontal_texture}}, {hatch_style::light_vertical, {create_light_vertical_texture}}, {hatch_style::narrow_horizontal, {create_narrow_horizontal_texture}}, {hatch_style::narrow_vertical, {create_narrow_vertical_texture}}, {hatch_style::dark_horizontal, {create_dark_horizontal_texture}}, {hatch_style::dark_vertical, {create_dark_vertical_texture}}, {hatch_style::dashed_downward_diagonal, {create_dashed_downward_diagonal_texture}}, {hatch_style::dashed_upward_diagonal, {create_dashed_upward_diagonal_texture}}, {hatch_style::dashed_horizontal, {create_dashed_horizontal_texture}}, {hatch_style::dashed_vertical, {create_dashed_vertical_texture}}, {hatch_style::small_confetti, {create_small_confetti_texture}}, {hatch_style::large_confetti, {create_large_confetti_texture}}, {hatch_style::zig_zag, {create_zig_zag_texture}}, {hatch_style::wave, {create_wave_texture}}, {hatch_style::diagonal_brick, {create_diagonal_brick_texture}}, {hatch_style::horizontal_brick, {create_horizontal_brick_texture}}, {hatch_style::weave, {create_weave_texture}}, {hatch_style::plaid, {create_plaid_texture}}, {hatch_style::divot, {create_divot_texture}}, {hatch_style::dotted_grid, {create_dotted_grid_texture}}, {hatch_style::dotted_diamond, {create_dotted_diamond_texture}}, {hatch_style::shingle, {create_shingle_texture}}, {hatch_style::trellis, {create_trellis_texture}}, {hatch_style::sphere, {create_sphere_texture}}, {hatch_style::small_grid, {create_small_grid_texture}}, {hatch_style::small_checker_board, {create_small_checker_board_texture}}, {hatch_style::large_checker_board, {create_large_checker_board_texture}}, {hatch_style::outlined_diamond, {create_outlined_diamond_texture}}, {hatch_style::solid_diamond, {create_solid_diamond_texture}}, {hatch_style::wide_checker_board, {create_wide_checker_board_texture}}};
  auto it = textures.find(data_->hatch_style_);
  native::brush::texture(handle(), (it != textures.end() ? it->second(data_->fore_color_, data_->back_color_) : create_empty_texture(data_->fore_color_, data_->back_color_)).handle());
}

hatch_brush::hatch_brush(const hatch_brush& value) : brush(value), data_(value.data_) {
}

hatch_brush& hatch_brush::operator =(const hatch_brush& value) {
  brush::operator =(value);
  data_ = value.data_;
  return *this;
}

xtd::drawing::color hatch_brush::background_color() const noexcept {return data_->back_color_;}

xtd::drawing::color hatch_brush::foreground_color() const noexcept {
  return data_->fore_color_;
}

xtd::drawing::drawing_2d::hatch_style hatch_brush::hatch_style() const noexcept {
  return data_->hatch_style_;
}

bool hatch_brush::equals(const hatch_brush& value) const noexcept {
  return data_->hatch_style_ == value.data_->hatch_style_ && data_->fore_color_ == value.data_->fore_color_ && data_->back_color_ == value.data_->back_color_;
}
