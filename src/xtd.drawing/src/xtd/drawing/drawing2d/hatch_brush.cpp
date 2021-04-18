#include "../../../../include/xtd/drawing/drawing2d/hatch_brush.h"
#include "../../../../include/xtd/drawing/bitmap.h"
#include <xtd/delegate.h>
#include <xtd/drawing/native/brush.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;

namespace {
  image create_horizontal_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 0, 5, 8, 5);
    return bitmap;
  }

  image create_vertical_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 5, 0, 5, 8);
    return bitmap;
  }

  image create_forward_diagonal_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 0, 0, 7, 7);
    return bitmap;
  }

  image create_backward_diagonal_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 7, 0, 0, 7);
    return bitmap;
  }

  image create_cross_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 0, 5, 8, 5);
    graphics.draw_line(pen(fore_color, 1), 5, 0, 5, 8);
    return bitmap;
  }

  image create_diagonal_cross_texture(const color& fore_color, const color& back_color) {
    auto bitmap = drawing::bitmap(8, 8);
    auto graphics = drawing::graphics::from_image(bitmap);
    graphics.clear(back_color);
    graphics.draw_line(pen(fore_color, 1), 0, 0, 7, 7);
    graphics.draw_line(pen(fore_color, 1), 7, 0, 0, 7);
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
  };
  auto it = textures.find(data_->hatch_style_);
  native::brush::texture(brush::data_->handle_, (it != textures.end() ? it->second(data_->fore_color_, data_->back_color_) : xtd::drawing::image::empty).handle());
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
