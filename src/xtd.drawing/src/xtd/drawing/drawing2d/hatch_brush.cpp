#include "../../../../include/xtd/drawing/drawing2d/hatch_brush.h"
#include "../../../../include/xtd/drawing/bitmap.h"
#include <xtd/delegate.h>
#include <xtd/drawing/native/brush.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;

namespace {
  image create_empty_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    return bitmap;
  }
  
  image create_horizontal_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 0, 4, 0, 4);
    graphics.draw_line(pen(fore_color, 1), 1, 4, 1, 4);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    graphics.draw_line(pen(fore_color, 1), 3, 4, 3, 4);
    graphics.draw_line(pen(fore_color, 1), 4, 4, 4, 4);
    graphics.draw_line(pen(fore_color, 1), 5, 4, 5, 4);
    graphics.draw_line(pen(fore_color, 1), 6, 4, 6, 4);
    graphics.draw_line(pen(fore_color, 1), 7, 4, 7, 4);
    return bitmap;
  }

  image create_vertical_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 2, 0, 2, 0);
    graphics.draw_line(pen(fore_color, 1), 2, 1, 2, 1);
    graphics.draw_line(pen(fore_color, 1), 2, 2, 2, 2);
    graphics.draw_line(pen(fore_color, 1), 2, 3, 2, 3);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    graphics.draw_line(pen(fore_color, 1), 2, 5, 2, 5);
    graphics.draw_line(pen(fore_color, 1), 2, 6, 2, 6);
    graphics.draw_line(pen(fore_color, 1), 2, 7, 2, 7);
    return bitmap;
  }

  image create_forward_diagonal_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);

    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 5, 0, 5, 0);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 7, 0, 7, 0);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 0, 1, 0, 1);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 6, 1, 6, 1);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 1, 2, 1, 2);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 7, 2, 7, 2);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 0, 3, 0, 3);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 2, 3, 2, 3);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 1, 4, 1, 4);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 3, 4, 3, 4);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 2, 5, 2, 5);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 4, 5, 4, 5);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 3, 6, 3, 6);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 5, 6, 5, 6);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 4, 7, 4, 7);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 6, 7, 6, 7);

    graphics.draw_line(pen(fore_color, 1), 6, 0, 6, 0);
    graphics.draw_line(pen(fore_color, 1), 7, 1, 7, 1);
    graphics.draw_line(pen(fore_color, 1), 0, 2, 0, 2);
    graphics.draw_line(pen(fore_color, 1), 1, 3, 1, 3);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    graphics.draw_line(pen(fore_color, 1), 3, 5, 3, 5);
    graphics.draw_line(pen(fore_color, 1), 4, 6, 4, 6);
    graphics.draw_line(pen(fore_color, 1), 5, 7, 5, 7);

    return bitmap;
  }

  image create_backward_diagonal_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);

    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 4, 0, 4, 0);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 6, 0, 6, 0);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 3, 1, 3, 1);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 5, 1, 5, 1);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 2, 2, 2, 2);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 4, 2, 4, 2);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 1, 3, 1, 3);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 3, 3, 3, 3);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 0, 4, 0, 4);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 2, 4, 2, 4);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 7, 5, 7, 5);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 1, 5, 1, 5);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 6, 6, 6, 6);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 0, 6, 0, 6);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 5, 7, 5, 7);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 7, 7, 7, 7);

    graphics.draw_line(pen(fore_color, 1), 5, 0, 5, 0);
    graphics.draw_line(pen(fore_color, 1), 4, 1, 4, 1);
    graphics.draw_line(pen(fore_color, 1), 3, 2, 3, 2);
    graphics.draw_line(pen(fore_color, 1), 2, 3, 2, 3);
    graphics.draw_line(pen(fore_color, 1), 1, 4, 1, 4);
    graphics.draw_line(pen(fore_color, 1), 0, 5, 0, 5);
    graphics.draw_line(pen(fore_color, 1), 7, 6, 7, 6);
    graphics.draw_line(pen(fore_color, 1), 6, 7, 6, 7);

    return bitmap;
  }

  image create_cross_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 0, 4, 0, 4);
    graphics.draw_line(pen(fore_color, 1), 1, 4, 1, 4);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    graphics.draw_line(pen(fore_color, 1), 3, 4, 3, 4);
    graphics.draw_line(pen(fore_color, 1), 4, 4, 4, 4);
    graphics.draw_line(pen(fore_color, 1), 5, 4, 5, 4);
    graphics.draw_line(pen(fore_color, 1), 6, 4, 6, 4);
    graphics.draw_line(pen(fore_color, 1), 7, 4, 7, 4);
    graphics.draw_line(pen(fore_color, 1), 2, 0, 2, 0);
    graphics.draw_line(pen(fore_color, 1), 2, 1, 2, 1);
    graphics.draw_line(pen(fore_color, 1), 2, 2, 2, 2);
    graphics.draw_line(pen(fore_color, 1), 2, 3, 2, 3);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    graphics.draw_line(pen(fore_color, 1), 2, 5, 2, 5);
    graphics.draw_line(pen(fore_color, 1), 2, 6, 2, 6);
    graphics.draw_line(pen(fore_color, 1), 2, 7, 2, 7);
    return bitmap;
  }

  image create_diagonal_cross_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);

    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 5, 0, 5, 0);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 7, 0, 7, 0);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 0, 1, 0, 1);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 6, 1, 6, 1);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 1, 2, 1, 2);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 7, 2, 7, 2);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 0, 3, 0, 3);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 2, 3, 2, 3);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 1, 4, 1, 4);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 3, 4, 3, 4);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 2, 5, 2, 5);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 4, 5, 4, 5);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 3, 6, 3, 6);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 5, 6, 5, 6);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 4, 7, 4, 7);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 6, 7, 6, 7);
    
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 4, 0, 4, 0);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 6, 0, 6, 0);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 3, 1, 3, 1);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 5, 1, 5, 1);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 2, 2, 2, 2);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 4, 2, 4, 2);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 1, 3, 1, 3);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 3, 3, 3, 3);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 0, 4, 0, 4);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 2, 4, 2, 4);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 7, 5, 7, 5);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 1, 5, 1, 5);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 6, 6, 6, 6);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 0, 6, 0, 6);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 5, 7, 5, 7);
    graphics.draw_line(pen(color::from_argb(64, fore_color), 1), 7, 7, 7, 7);

    graphics.draw_line(pen(fore_color, 1), 6, 0, 6, 0);
    graphics.draw_line(pen(fore_color, 1), 7, 1, 7, 1);
    graphics.draw_line(pen(fore_color, 1), 0, 2, 0, 2);
    graphics.draw_line(pen(fore_color, 1), 1, 3, 1, 3);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    graphics.draw_line(pen(fore_color, 1), 3, 5, 3, 5);
    graphics.draw_line(pen(fore_color, 1), 4, 6, 4, 6);
    graphics.draw_line(pen(fore_color, 1), 5, 7, 5, 7);
    
    graphics.draw_line(pen(fore_color, 1), 5, 0, 5, 0);
    graphics.draw_line(pen(fore_color, 1), 4, 1, 4, 1);
    graphics.draw_line(pen(fore_color, 1), 3, 2, 3, 2);
    graphics.draw_line(pen(fore_color, 1), 2, 3, 2, 3);
    graphics.draw_line(pen(fore_color, 1), 1, 4, 1, 4);
    graphics.draw_line(pen(fore_color, 1), 0, 5, 0, 5);
    graphics.draw_line(pen(fore_color, 1), 7, 6, 7, 6);
    graphics.draw_line(pen(fore_color, 1), 6, 7, 6, 7);

    return bitmap;
  }

  image create_percent_05_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 6, 0, 6, 0);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    return bitmap;
  }

  image create_percent_10_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 2, 0, 2, 0);
    graphics.draw_line(pen(fore_color, 1), 6, 2, 6, 2);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    graphics.draw_line(pen(fore_color, 1), 6, 6, 6, 6);
    return bitmap;
  }

  image create_percent_20_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 2, 0, 2, 0);
    graphics.draw_line(pen(fore_color, 1), 6, 0, 6, 0);
    graphics.draw_line(pen(fore_color, 1), 0, 2, 0, 2);
    graphics.draw_line(pen(fore_color, 1), 4, 2, 4, 2);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    graphics.draw_line(pen(fore_color, 1), 6, 4, 6, 4);
    graphics.draw_line(pen(fore_color, 1), 0, 6, 0, 6);
    graphics.draw_line(pen(fore_color, 1), 4, 6, 4, 6);
    return bitmap;
  }

  image create_percent_25_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 2, 0, 2, 0);
    graphics.draw_line(pen(fore_color, 1), 6, 0, 6, 0);
    graphics.draw_line(pen(fore_color, 1), 0, 1, 0, 1);
    graphics.draw_line(pen(fore_color, 1), 4, 1, 4, 1);
    graphics.draw_line(pen(fore_color, 1), 2, 2, 2, 2);
    graphics.draw_line(pen(fore_color, 1), 6, 2, 6, 2);
    graphics.draw_line(pen(fore_color, 1), 0, 3, 0, 3);
    graphics.draw_line(pen(fore_color, 1), 4, 3, 4, 3);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    graphics.draw_line(pen(fore_color, 1), 6, 4, 6, 4);
    graphics.draw_line(pen(fore_color, 1), 0, 5, 0, 5);
    graphics.draw_line(pen(fore_color, 1), 4, 5, 4, 5);
    graphics.draw_line(pen(fore_color, 1), 2, 6, 2, 6);
    graphics.draw_line(pen(fore_color, 1), 6, 6, 6, 6);
    graphics.draw_line(pen(fore_color, 1), 0, 7, 0, 7);
    graphics.draw_line(pen(fore_color, 1), 4, 7, 4, 7);
    return bitmap;
  }

  image create_percent_30_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 0, 0, 0, 0);
    graphics.draw_line(pen(fore_color, 1), 2, 0, 2, 0);
    graphics.draw_line(pen(fore_color, 1), 4, 0, 4, 0);
    graphics.draw_line(pen(fore_color, 1), 6, 0, 6, 0);
    graphics.draw_line(pen(fore_color, 1), 3, 1, 3, 1);
    graphics.draw_line(pen(fore_color, 1), 7, 1, 7, 1);
    graphics.draw_line(pen(fore_color, 1), 0, 2, 0, 2);
    graphics.draw_line(pen(fore_color, 1), 2, 2, 2, 2);
    graphics.draw_line(pen(fore_color, 1), 4, 2, 4, 2);
    graphics.draw_line(pen(fore_color, 1), 6, 2, 6, 2);
    graphics.draw_line(pen(fore_color, 1), 1, 3, 1, 3);
    graphics.draw_line(pen(fore_color, 1), 5, 3, 5, 3);
    graphics.draw_line(pen(fore_color, 1), 0, 4, 0, 4);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    graphics.draw_line(pen(fore_color, 1), 4, 4, 4, 4);
    graphics.draw_line(pen(fore_color, 1), 6, 4, 6, 4);
    graphics.draw_line(pen(fore_color, 1), 3, 5, 3, 5);
    graphics.draw_line(pen(fore_color, 1), 7, 5, 7, 5);
    graphics.draw_line(pen(fore_color, 1), 0, 6, 0, 6);
    graphics.draw_line(pen(fore_color, 1), 2, 6, 2, 6);
    graphics.draw_line(pen(fore_color, 1), 4, 6, 4, 6);
    graphics.draw_line(pen(fore_color, 1), 6, 6, 6, 6);
    graphics.draw_line(pen(fore_color, 1), 1, 7, 1, 7);
    graphics.draw_line(pen(fore_color, 1), 5, 7, 5, 7);
    return bitmap;
  }
  
  image create_percent_40_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 0, 0, 0, 0);
    graphics.draw_line(pen(fore_color, 1), 2, 0, 2, 0);
    graphics.draw_line(pen(fore_color, 1), 4, 0, 4, 0);
    graphics.draw_line(pen(fore_color, 1), 6, 0, 6, 0);
    graphics.draw_line(pen(fore_color, 1), 1, 1, 1, 1);
    graphics.draw_line(pen(fore_color, 1), 3, 1, 3, 1);
    graphics.draw_line(pen(fore_color, 1), 5, 1, 5, 1);
    graphics.draw_line(pen(fore_color, 1), 7, 1, 7, 1);
    graphics.draw_line(pen(fore_color, 1), 0, 2, 0, 2);
    graphics.draw_line(pen(fore_color, 1), 2, 2, 2, 2);
    graphics.draw_line(pen(fore_color, 1), 4, 2, 4, 2);
    graphics.draw_line(pen(fore_color, 1), 6, 2, 6, 2);
    graphics.draw_line(pen(fore_color, 1), 1, 3, 1, 3);
    graphics.draw_line(pen(fore_color, 1), 5, 3, 5, 3);
    graphics.draw_line(pen(fore_color, 1), 7, 3, 7, 3);
    graphics.draw_line(pen(fore_color, 1), 0, 4, 0, 4);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    graphics.draw_line(pen(fore_color, 1), 4, 4, 4, 4);
    graphics.draw_line(pen(fore_color, 1), 6, 4, 6, 4);
    graphics.draw_line(pen(fore_color, 1), 1, 5, 1, 5);
    graphics.draw_line(pen(fore_color, 1), 3, 5, 3, 5);
    graphics.draw_line(pen(fore_color, 1), 5, 5, 5, 5);
    graphics.draw_line(pen(fore_color, 1), 7, 5, 7, 5);
    graphics.draw_line(pen(fore_color, 1), 0, 6, 0, 6);
    graphics.draw_line(pen(fore_color, 1), 2, 6, 2, 6);
    graphics.draw_line(pen(fore_color, 1), 4, 6, 4, 6);
    graphics.draw_line(pen(fore_color, 1), 6, 6, 6, 6);
    graphics.draw_line(pen(fore_color, 1), 1, 7, 1, 7);
    graphics.draw_line(pen(fore_color, 1), 3, 7, 3, 7);
    graphics.draw_line(pen(fore_color, 1), 5, 7, 5, 7);
    return bitmap;
  }
  
  image create_percent_50_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 0, 0, 0, 0);
    graphics.draw_line(pen(fore_color, 1), 2, 0, 2, 0);
    graphics.draw_line(pen(fore_color, 1), 4, 0, 4, 0);
    graphics.draw_line(pen(fore_color, 1), 6, 0, 6, 0);
    graphics.draw_line(pen(fore_color, 1), 1, 1, 1, 1);
    graphics.draw_line(pen(fore_color, 1), 3, 1, 3, 1);
    graphics.draw_line(pen(fore_color, 1), 5, 1, 5, 1);
    graphics.draw_line(pen(fore_color, 1), 7, 1, 7, 1);
    graphics.draw_line(pen(fore_color, 1), 0, 2, 0, 2);
    graphics.draw_line(pen(fore_color, 1), 2, 2, 2, 2);
    graphics.draw_line(pen(fore_color, 1), 4, 2, 4, 2);
    graphics.draw_line(pen(fore_color, 1), 6, 2, 6, 2);
    graphics.draw_line(pen(fore_color, 1), 1, 3, 1, 3);
    graphics.draw_line(pen(fore_color, 1), 3, 3, 3, 3);
    graphics.draw_line(pen(fore_color, 1), 5, 3, 5, 3);
    graphics.draw_line(pen(fore_color, 1), 7, 3, 7, 3);
    graphics.draw_line(pen(fore_color, 1), 0, 4, 0, 4);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    graphics.draw_line(pen(fore_color, 1), 4, 4, 4, 4);
    graphics.draw_line(pen(fore_color, 1), 6, 4, 6, 4);
    graphics.draw_line(pen(fore_color, 1), 1, 5, 1, 5);
    graphics.draw_line(pen(fore_color, 1), 3, 5, 3, 5);
    graphics.draw_line(pen(fore_color, 1), 5, 5, 5, 5);
    graphics.draw_line(pen(fore_color, 1), 7, 5, 7, 5);
    graphics.draw_line(pen(fore_color, 1), 0, 6, 0, 6);
    graphics.draw_line(pen(fore_color, 1), 2, 6, 2, 6);
    graphics.draw_line(pen(fore_color, 1), 4, 6, 4, 6);
    graphics.draw_line(pen(fore_color, 1), 6, 6, 6, 6);
    graphics.draw_line(pen(fore_color, 1), 1, 7, 1, 7);
    graphics.draw_line(pen(fore_color, 1), 3, 7, 3, 7);
    graphics.draw_line(pen(fore_color, 1), 5, 7, 5, 7);
    graphics.draw_line(pen(fore_color, 1), 7, 7, 7, 7);
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
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 2, 0, 2, 0);
    graphics.draw_line(pen(fore_color, 1), 6, 0, 6, 0);
    graphics.draw_line(pen(fore_color, 1), 3, 1, 3, 1);
    graphics.draw_line(pen(fore_color, 1), 7, 1, 7, 1);
    graphics.draw_line(pen(fore_color, 1), 4, 2, 4, 2);
    graphics.draw_line(pen(fore_color, 1), 0, 2, 0, 2);
    graphics.draw_line(pen(fore_color, 1), 5, 3, 5, 3);
    graphics.draw_line(pen(fore_color, 1), 1, 3, 1, 3);
    graphics.draw_line(pen(fore_color, 1), 6, 4, 6, 4);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    graphics.draw_line(pen(fore_color, 1), 7, 5, 7, 5);
    graphics.draw_line(pen(fore_color, 1), 3, 5, 3, 5);
    graphics.draw_line(pen(fore_color, 1), 0, 6, 0, 6);
    graphics.draw_line(pen(fore_color, 1), 4, 6, 4, 6);
    graphics.draw_line(pen(fore_color, 1), 1, 7, 1, 7);
    graphics.draw_line(pen(fore_color, 1), 5, 7, 5, 7);
    return bitmap;
  }
  
  image create_light_upward_diagonal_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 1, 0, 1, 0);
    graphics.draw_line(pen(fore_color, 1), 5, 0, 5, 0);
    graphics.draw_line(pen(fore_color, 1), 0, 1, 0, 1);
    graphics.draw_line(pen(fore_color, 1), 4, 1, 4, 1);
    graphics.draw_line(pen(fore_color, 1), 7, 2, 7, 2);
    graphics.draw_line(pen(fore_color, 1), 3, 2, 3, 2);
    graphics.draw_line(pen(fore_color, 1), 6, 3, 6, 3);
    graphics.draw_line(pen(fore_color, 1), 2, 3, 2, 3);
    graphics.draw_line(pen(fore_color, 1), 5, 4, 5, 4);
    graphics.draw_line(pen(fore_color, 1), 1, 4, 1, 4);
    graphics.draw_line(pen(fore_color, 1), 4, 5, 4, 5);
    graphics.draw_line(pen(fore_color, 1), 0, 5, 0, 5);
    graphics.draw_line(pen(fore_color, 1), 3, 6, 3, 6);
    graphics.draw_line(pen(fore_color, 1), 7, 6, 7, 6);
    graphics.draw_line(pen(fore_color, 1), 2, 7, 2, 7);
    graphics.draw_line(pen(fore_color, 1), 6, 7, 6, 7);
    return bitmap;
  }
  
  image create_dark_downward_diagonal_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 2, 0, 2, 0);
    graphics.draw_line(pen(fore_color, 1), 3, 0, 3, 0);
    graphics.draw_line(pen(fore_color, 1), 6, 0, 6, 0);
    graphics.draw_line(pen(fore_color, 1), 7, 0, 7, 0);
    graphics.draw_line(pen(fore_color, 1), 3, 1, 3, 1);
    graphics.draw_line(pen(fore_color, 1), 4, 1, 4, 1);
    graphics.draw_line(pen(fore_color, 1), 7, 1, 7, 1);
    graphics.draw_line(pen(fore_color, 1), 0, 1, 0, 1);
    graphics.draw_line(pen(fore_color, 1), 4, 2, 4, 2);
    graphics.draw_line(pen(fore_color, 1), 5, 2, 5, 2);
    graphics.draw_line(pen(fore_color, 1), 0, 2, 0, 2);
    graphics.draw_line(pen(fore_color, 1), 1, 2, 1, 2);
    graphics.draw_line(pen(fore_color, 1), 5, 3, 5, 3);
    graphics.draw_line(pen(fore_color, 1), 6, 3, 6, 3);
    graphics.draw_line(pen(fore_color, 1), 1, 3, 1, 3);
    graphics.draw_line(pen(fore_color, 1), 2, 3, 2, 3);
    graphics.draw_line(pen(fore_color, 1), 6, 4, 6, 4);
    graphics.draw_line(pen(fore_color, 1), 7, 4, 6, 4);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    graphics.draw_line(pen(fore_color, 1), 3, 4, 3, 4);
    graphics.draw_line(pen(fore_color, 1), 7, 5, 7, 5);
    graphics.draw_line(pen(fore_color, 1), 0, 5, 0, 5);
    graphics.draw_line(pen(fore_color, 1), 3, 5, 3, 5);
    graphics.draw_line(pen(fore_color, 1), 4, 5, 4, 5);
    graphics.draw_line(pen(fore_color, 1), 0, 6, 0, 6);
    graphics.draw_line(pen(fore_color, 1), 1, 6, 1, 6);
    graphics.draw_line(pen(fore_color, 1), 4, 6, 4, 6);
    graphics.draw_line(pen(fore_color, 1), 5, 6, 5, 6);
    graphics.draw_line(pen(fore_color, 1), 1, 7, 1, 7);
    graphics.draw_line(pen(fore_color, 1), 2, 7, 2, 7);
    graphics.draw_line(pen(fore_color, 1), 5, 7, 5, 7);
    graphics.draw_line(pen(fore_color, 1), 6, 7, 6, 7);
    return bitmap;
  }
  
  image create_dark_upward_diagonal_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 1, 0, 1, 0);
    graphics.draw_line(pen(fore_color, 1), 2, 0, 2, 0);
    graphics.draw_line(pen(fore_color, 1), 5, 0, 5, 0);
    graphics.draw_line(pen(fore_color, 1), 6, 0, 6, 0);
    graphics.draw_line(pen(fore_color, 1), 0, 1, 0, 1);
    graphics.draw_line(pen(fore_color, 1), 1, 1, 1, 1);
    graphics.draw_line(pen(fore_color, 1), 4, 1, 4, 1);
    graphics.draw_line(pen(fore_color, 1), 5, 1, 5, 1);
    graphics.draw_line(pen(fore_color, 1), 7, 2, 7, 2);
    graphics.draw_line(pen(fore_color, 1), 0, 2, 0, 2);
    graphics.draw_line(pen(fore_color, 1), 3, 2, 3, 2);
    graphics.draw_line(pen(fore_color, 1), 4, 2, 4, 2);
    graphics.draw_line(pen(fore_color, 1), 6, 3, 6, 3);
    graphics.draw_line(pen(fore_color, 1), 7, 3, 7, 3);
    graphics.draw_line(pen(fore_color, 1), 2, 3, 2, 3);
    graphics.draw_line(pen(fore_color, 1), 3, 3, 3, 3);
    graphics.draw_line(pen(fore_color, 1), 5, 4, 5, 4);
    graphics.draw_line(pen(fore_color, 1), 6, 4, 6, 4);
    graphics.draw_line(pen(fore_color, 1), 1, 4, 1, 4);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    graphics.draw_line(pen(fore_color, 1), 4, 5, 4, 5);
    graphics.draw_line(pen(fore_color, 1), 5, 5, 5, 5);
    graphics.draw_line(pen(fore_color, 1), 0, 5, 0, 5);
    graphics.draw_line(pen(fore_color, 1), 1, 5, 1, 5);
    graphics.draw_line(pen(fore_color, 1), 3, 6, 3, 6);
    graphics.draw_line(pen(fore_color, 1), 4, 6, 4, 6);
    graphics.draw_line(pen(fore_color, 1), 7, 6, 7, 6);
    graphics.draw_line(pen(fore_color, 1), 0, 6, 0, 6);
    graphics.draw_line(pen(fore_color, 1), 2, 7, 2, 7);
    graphics.draw_line(pen(fore_color, 1), 3, 7, 3, 7);
    graphics.draw_line(pen(fore_color, 1), 6, 7, 6, 7);
    graphics.draw_line(pen(fore_color, 1), 7, 7, 7, 7);
    return bitmap;
  }

  image create_wide_downward_diagonal_texture(const color& fore_color, const color& back_color) {
    return create_light_downward_diagonal_texture(back_color, fore_color);
  }

  image create_wide_upward_diagonal_texture(const color& fore_color, const color& back_color) {
    return create_light_upward_diagonal_texture(back_color, fore_color);
  }
  
  image create_light_horizontal_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 0, 0, 0, 0);
    graphics.draw_line(pen(fore_color, 1), 1, 0, 1, 0);
    graphics.draw_line(pen(fore_color, 1), 2, 0, 2, 0);
    graphics.draw_line(pen(fore_color, 1), 3, 0, 3, 0);
    graphics.draw_line(pen(fore_color, 1), 4, 0, 4, 0);
    graphics.draw_line(pen(fore_color, 1), 5, 0, 5, 0);
    graphics.draw_line(pen(fore_color, 1), 6, 0, 6, 0);
    graphics.draw_line(pen(fore_color, 1), 7, 0, 7, 0);
    
    graphics.draw_line(pen(fore_color, 1), 0, 4, 0, 4);
    graphics.draw_line(pen(fore_color, 1), 1, 4, 1, 4);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    graphics.draw_line(pen(fore_color, 1), 3, 4, 3, 4);
    graphics.draw_line(pen(fore_color, 1), 4, 4, 4, 4);
    graphics.draw_line(pen(fore_color, 1), 5, 4, 5, 4);
    graphics.draw_line(pen(fore_color, 1), 6, 4, 6, 4);
    graphics.draw_line(pen(fore_color, 1), 7, 4, 7, 4);
    return bitmap;
  }
  
  image create_light_vertical_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 2, 0, 2, 0);
    graphics.draw_line(pen(fore_color, 1), 2, 1, 2, 1);
    graphics.draw_line(pen(fore_color, 1), 2, 2, 2, 2);
    graphics.draw_line(pen(fore_color, 1), 2, 3, 2, 3);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    graphics.draw_line(pen(fore_color, 1), 2, 5, 2, 5);
    graphics.draw_line(pen(fore_color, 1), 2, 6, 2, 6);
    graphics.draw_line(pen(fore_color, 1), 2, 7, 2, 7);
    
    graphics.draw_line(pen(fore_color, 1), 6, 0, 6, 0);
    graphics.draw_line(pen(fore_color, 1), 6, 1, 6, 1);
    graphics.draw_line(pen(fore_color, 1), 6, 2, 6, 2);
    graphics.draw_line(pen(fore_color, 1), 6, 3, 6, 3);
    graphics.draw_line(pen(fore_color, 1), 6, 4, 6, 4);
    graphics.draw_line(pen(fore_color, 1), 6, 5, 6, 5);
    graphics.draw_line(pen(fore_color, 1), 6, 6, 6, 6);
    graphics.draw_line(pen(fore_color, 1), 6, 7, 6, 7);
    return bitmap;
  }
  
  image create_narrow_horizontal_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 0, 0, 0, 0);
    graphics.draw_line(pen(fore_color, 1), 1, 0, 1, 0);
    graphics.draw_line(pen(fore_color, 1), 2, 0, 2, 0);
    graphics.draw_line(pen(fore_color, 1), 3, 0, 3, 0);
    graphics.draw_line(pen(fore_color, 1), 4, 0, 4, 0);
    graphics.draw_line(pen(fore_color, 1), 5, 0, 5, 0);
    graphics.draw_line(pen(fore_color, 1), 6, 0, 6, 0);
    graphics.draw_line(pen(fore_color, 1), 7, 0, 7, 0);
    
    graphics.draw_line(pen(fore_color, 1), 0, 2, 0, 2);
    graphics.draw_line(pen(fore_color, 1), 1, 2, 1, 2);
    graphics.draw_line(pen(fore_color, 1), 2, 2, 2, 2);
    graphics.draw_line(pen(fore_color, 1), 3, 2, 3, 2);
    graphics.draw_line(pen(fore_color, 1), 4, 2, 4, 2);
    graphics.draw_line(pen(fore_color, 1), 5, 2, 5, 2);
    graphics.draw_line(pen(fore_color, 1), 6, 2, 6, 2);
    graphics.draw_line(pen(fore_color, 1), 7, 2, 7, 2);
    
    graphics.draw_line(pen(fore_color, 1), 0, 4, 0, 4);
    graphics.draw_line(pen(fore_color, 1), 1, 4, 1, 4);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    graphics.draw_line(pen(fore_color, 1), 3, 4, 3, 4);
    graphics.draw_line(pen(fore_color, 1), 4, 4, 4, 4);
    graphics.draw_line(pen(fore_color, 1), 5, 4, 5, 4);
    graphics.draw_line(pen(fore_color, 1), 6, 4, 6, 4);
    graphics.draw_line(pen(fore_color, 1), 7, 4, 7, 4);
    
    graphics.draw_line(pen(fore_color, 1), 0, 6, 0, 6);
    graphics.draw_line(pen(fore_color, 1), 1, 6, 1, 6);
    graphics.draw_line(pen(fore_color, 1), 2, 6, 2, 6);
    graphics.draw_line(pen(fore_color, 1), 3, 6, 3, 6);
    graphics.draw_line(pen(fore_color, 1), 4, 6, 4, 6);
    graphics.draw_line(pen(fore_color, 1), 5, 6, 5, 6);
    graphics.draw_line(pen(fore_color, 1), 6, 6, 6, 6);
    graphics.draw_line(pen(fore_color, 1), 7, 6, 7, 6);
    return bitmap;
  }
  
  image create_narrow_vertical_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 0, 0, 0, 0);
    graphics.draw_line(pen(fore_color, 1), 0, 1, 0, 1);
    graphics.draw_line(pen(fore_color, 1), 0, 2, 0, 2);
    graphics.draw_line(pen(fore_color, 1), 0, 3, 0, 3);
    graphics.draw_line(pen(fore_color, 1), 0, 4, 0, 4);
    graphics.draw_line(pen(fore_color, 1), 0, 5, 0, 5);
    graphics.draw_line(pen(fore_color, 1), 0, 6, 0, 6);
    graphics.draw_line(pen(fore_color, 1), 0, 7, 0, 7);
    
    graphics.draw_line(pen(fore_color, 1), 2, 0, 2, 0);
    graphics.draw_line(pen(fore_color, 1), 2, 1, 2, 1);
    graphics.draw_line(pen(fore_color, 1), 2, 2, 2, 2);
    graphics.draw_line(pen(fore_color, 1), 2, 3, 2, 3);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    graphics.draw_line(pen(fore_color, 1), 2, 5, 2, 5);
    graphics.draw_line(pen(fore_color, 1), 2, 6, 2, 6);
    graphics.draw_line(pen(fore_color, 1), 2, 7, 2, 7);
    
    graphics.draw_line(pen(fore_color, 1), 4, 0, 4, 0);
    graphics.draw_line(pen(fore_color, 1), 4, 1, 4, 1);
    graphics.draw_line(pen(fore_color, 1), 4, 2, 4, 2);
    graphics.draw_line(pen(fore_color, 1), 4, 3, 4, 3);
    graphics.draw_line(pen(fore_color, 1), 4, 4, 4, 4);
    graphics.draw_line(pen(fore_color, 1), 4, 5, 4, 5);
    graphics.draw_line(pen(fore_color, 1), 4, 6, 4, 6);
    graphics.draw_line(pen(fore_color, 1), 4, 7, 4, 7);
    
    graphics.draw_line(pen(fore_color, 1), 6, 0, 6, 0);
    graphics.draw_line(pen(fore_color, 1), 6, 1, 6, 1);
    graphics.draw_line(pen(fore_color, 1), 6, 2, 6, 2);
    graphics.draw_line(pen(fore_color, 1), 6, 3, 6, 3);
    graphics.draw_line(pen(fore_color, 1), 6, 4, 6, 4);
    graphics.draw_line(pen(fore_color, 1), 6, 5, 6, 5);
    graphics.draw_line(pen(fore_color, 1), 6, 6, 6, 6);
    graphics.draw_line(pen(fore_color, 1), 6, 7, 6, 7);
    return bitmap;
  }

  image create_dark_horizontal_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 0, 0, 0, 0);
    graphics.draw_line(pen(fore_color, 1), 1, 0, 1, 0);
    graphics.draw_line(pen(fore_color, 1), 2, 0, 2, 0);
    graphics.draw_line(pen(fore_color, 1), 3, 0, 3, 0);
    graphics.draw_line(pen(fore_color, 1), 4, 0, 4, 0);
    graphics.draw_line(pen(fore_color, 1), 5, 0, 5, 0);
    graphics.draw_line(pen(fore_color, 1), 6, 0, 6, 0);
    graphics.draw_line(pen(fore_color, 1), 7, 0, 7, 0);
    
    graphics.draw_line(pen(fore_color, 1), 0, 1, 0, 1);
    graphics.draw_line(pen(fore_color, 1), 1, 1, 1, 1);
    graphics.draw_line(pen(fore_color, 1), 2, 1, 2, 1);
    graphics.draw_line(pen(fore_color, 1), 3, 1, 3, 1);
    graphics.draw_line(pen(fore_color, 1), 4, 1, 4, 1);
    graphics.draw_line(pen(fore_color, 1), 5, 1, 5, 1);
    graphics.draw_line(pen(fore_color, 1), 6, 1, 6, 1);
    graphics.draw_line(pen(fore_color, 1), 7, 1, 7, 1);

    graphics.draw_line(pen(fore_color, 1), 0, 4, 0, 4);
    graphics.draw_line(pen(fore_color, 1), 1, 4, 1, 4);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    graphics.draw_line(pen(fore_color, 1), 3, 4, 3, 4);
    graphics.draw_line(pen(fore_color, 1), 4, 4, 4, 4);
    graphics.draw_line(pen(fore_color, 1), 5, 4, 5, 4);
    graphics.draw_line(pen(fore_color, 1), 6, 4, 6, 4);
    graphics.draw_line(pen(fore_color, 1), 7, 4, 7, 4);

    graphics.draw_line(pen(fore_color, 1), 0, 5, 0, 5);
    graphics.draw_line(pen(fore_color, 1), 1, 5, 1, 5);
    graphics.draw_line(pen(fore_color, 1), 2, 5, 2, 5);
    graphics.draw_line(pen(fore_color, 1), 3, 5, 3, 5);
    graphics.draw_line(pen(fore_color, 1), 4, 5, 4, 5);
    graphics.draw_line(pen(fore_color, 1), 5, 5, 5, 5);
    graphics.draw_line(pen(fore_color, 1), 6, 5, 6, 5);
    graphics.draw_line(pen(fore_color, 1), 7, 5, 7, 5);
    return bitmap;
  }
  
  image create_dark_vertical_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 2, 0, 2, 0);
    graphics.draw_line(pen(fore_color, 1), 2, 1, 2, 1);
    graphics.draw_line(pen(fore_color, 1), 2, 2, 2, 2);
    graphics.draw_line(pen(fore_color, 1), 2, 3, 2, 3);
    graphics.draw_line(pen(fore_color, 1), 2, 4, 2, 4);
    graphics.draw_line(pen(fore_color, 1), 2, 5, 2, 5);
    graphics.draw_line(pen(fore_color, 1), 2, 6, 2, 6);
    graphics.draw_line(pen(fore_color, 1), 2, 7, 2, 7);
    
    graphics.draw_line(pen(fore_color, 1), 3, 0, 3, 0);
    graphics.draw_line(pen(fore_color, 1), 3, 1, 3, 1);
    graphics.draw_line(pen(fore_color, 1), 3, 2, 3, 2);
    graphics.draw_line(pen(fore_color, 1), 3, 3, 3, 3);
    graphics.draw_line(pen(fore_color, 1), 3, 4, 3, 4);
    graphics.draw_line(pen(fore_color, 1), 3, 5, 3, 5);
    graphics.draw_line(pen(fore_color, 1), 3, 6, 3, 6);
    graphics.draw_line(pen(fore_color, 1), 3, 7, 3, 7);
    
    graphics.draw_line(pen(fore_color, 1), 6, 0, 6, 0);
    graphics.draw_line(pen(fore_color, 1), 6, 1, 6, 1);
    graphics.draw_line(pen(fore_color, 1), 6, 2, 6, 2);
    graphics.draw_line(pen(fore_color, 1), 6, 3, 6, 3);
    graphics.draw_line(pen(fore_color, 1), 6, 4, 6, 4);
    graphics.draw_line(pen(fore_color, 1), 6, 5, 6, 5);
    graphics.draw_line(pen(fore_color, 1), 6, 6, 6, 6);
    graphics.draw_line(pen(fore_color, 1), 6, 7, 6, 7);
    
    graphics.draw_line(pen(fore_color, 1), 7, 0, 7, 0);
    graphics.draw_line(pen(fore_color, 1), 7, 1, 7, 1);
    graphics.draw_line(pen(fore_color, 1), 7, 2, 7, 2);
    graphics.draw_line(pen(fore_color, 1), 7, 3, 7, 3);
    graphics.draw_line(pen(fore_color, 1), 7, 4, 7, 4);
    graphics.draw_line(pen(fore_color, 1), 7, 5, 7, 5);
    graphics.draw_line(pen(fore_color, 1), 7, 6, 7, 6);
    graphics.draw_line(pen(fore_color, 1), 7, 7, 7, 7);
    return bitmap;
  }

  image create_dashed_downward_diagonal_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 0, 0, 0, 0);
    graphics.draw_line(pen(fore_color, 1), 4, 0, 4, 0);
    graphics.draw_line(pen(fore_color, 1), 1, 1, 1, 1);
    graphics.draw_line(pen(fore_color, 1), 5, 1, 5, 1);
    graphics.draw_line(pen(fore_color, 1), 2, 6, 2, 6);
    graphics.draw_line(pen(fore_color, 1), 6, 6, 6, 6);
    graphics.draw_line(pen(fore_color, 1), 3, 7, 3, 7);
    graphics.draw_line(pen(fore_color, 1), 7, 7, 7, 7);
    return bitmap;
  }

  image create_dashed_upward_diagonal_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 3, 0, 3, 0);
    graphics.draw_line(pen(fore_color, 1), 7, 0, 7, 0);
    graphics.draw_line(pen(fore_color, 1), 2, 1, 2, 1);
    graphics.draw_line(pen(fore_color, 1), 6, 1, 6, 1);
    graphics.draw_line(pen(fore_color, 1), 1, 6, 1, 6);
    graphics.draw_line(pen(fore_color, 1), 5, 6, 5, 6);
    graphics.draw_line(pen(fore_color, 1), 0, 7, 0, 7);
    graphics.draw_line(pen(fore_color, 1), 4, 7, 4, 7);
    return bitmap;
  }
}

hatch_brush::hatch_brush() {
  data_->hatch_style_ = xtd::drawing::drawing2d::hatch_style::horizontal;
  data_->fore_color_ = xtd::drawing::color::black;
  data_->back_color_ = xtd::drawing::color::black;
  recreate_handle();
}

hatch_brush::hatch_brush(xtd::drawing::drawing2d::hatch_style hatch_style, const xtd::drawing::color& fore_color, const xtd::drawing::color& back_color) {
  data_->hatch_style_ = hatch_style;
  data_->fore_color_ = fore_color;
  data_->back_color_ = back_color;
  recreate_handle();
}

void hatch_brush::recreate_handle() {
  std::map<xtd::drawing::drawing2d::hatch_style, delegate<image(const color&, const color&)>> textures {
    {hatch_style::horizontal, {create_horizontal_texture}},
    {hatch_style::vertical, {create_vertical_texture}},
    {hatch_style::forward_diagonal, {create_forward_diagonal_texture}},
    {hatch_style::backward_diagonal, {create_backward_diagonal_texture}},
    {hatch_style::cross, {create_cross_texture}},
    {hatch_style::diagonal_cross, {create_diagonal_cross_texture}},
    {hatch_style::percent_05, {create_percent_05_texture}},
    {hatch_style::percent_10, {create_percent_10_texture}},
    {hatch_style::percent_20, {create_percent_20_texture}},
    {hatch_style::percent_25, {create_percent_25_texture}},
    {hatch_style::percent_30, {create_percent_30_texture}},
    {hatch_style::percent_40, {create_percent_40_texture}},
    {hatch_style::percent_50, {create_percent_50_texture}},
    {hatch_style::percent_60, {create_percent_60_texture}},
    {hatch_style::percent_70, {create_percent_70_texture}},
    {hatch_style::percent_75, {create_percent_75_texture}},
    {hatch_style::percent_80, {create_percent_80_texture}},
    {hatch_style::percent_90, {create_percent_90_texture}},
    {hatch_style::light_downward_diagonal, {create_light_downward_diagonal_texture}},
    {hatch_style::light_upward_diagonal, {create_light_upward_diagonal_texture}},
    {hatch_style::dark_downward_diagonal, {create_dark_downward_diagonal_texture}},
    {hatch_style::dark_upward_diagonal, {create_dark_upward_diagonal_texture}},
    {hatch_style::wide_downward_diagonal, {create_wide_downward_diagonal_texture}},
    {hatch_style::wide_upward_diagonal, {create_wide_upward_diagonal_texture}},
    {hatch_style::light_horizontal, {create_light_horizontal_texture}},
    {hatch_style::light_vertical, {create_light_vertical_texture}},
    {hatch_style::narrow_horizontal, {create_narrow_horizontal_texture}},
    {hatch_style::narrow_vertical, {create_narrow_vertical_texture}},
    {hatch_style::dark_horizontal, {create_dark_horizontal_texture}},
    {hatch_style::dark_vertical, {create_dark_vertical_texture}},
    {hatch_style::dashed_downward_diagonal, {create_dashed_downward_diagonal_texture}},
    {hatch_style::dashed_upward_diagonal, {create_dashed_upward_diagonal_texture}},
  };
  auto it = textures.find(data_->hatch_style_);
  native::brush::texture(brush::data_->handle_, (it != textures.end() ? it->second(data_->fore_color_, data_->back_color_) : create_empty_texture(data_->fore_color_, data_->back_color_)).handle());
}

hatch_brush::hatch_brush(const hatch_brush& value) : brush(value) {
  data_ = value.data_;
}

hatch_brush& hatch_brush::operator=(const hatch_brush& value) {
  brush::operator=(value);
  data_ = value.data_;
  return *this;
}

hatch_brush& hatch_brush::hatch_style(xtd::drawing::drawing2d::hatch_style hatch_style) {
  if (data_->hatch_style_ != hatch_style) {
    data_->hatch_style_ = hatch_style;
    recreate_handle();
  }
  return *this;
}

hatch_brush& hatch_brush::back_color(xtd::drawing::color back_color) {
  if (data_->back_color_ != back_color) {
    data_->back_color_ = back_color;
    recreate_handle();
  }
  return *this;
}

hatch_brush& hatch_brush::fore_color(xtd::drawing::color fore_color) {
  if (data_->fore_color_ != fore_color) {
    data_->fore_color_ = fore_color;
    recreate_handle();
  }
  return *this;
}
