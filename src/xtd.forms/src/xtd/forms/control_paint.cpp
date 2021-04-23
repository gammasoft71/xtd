#include "../../../include/xtd/forms/control_paint.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

void control_paint::draw_image(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& clip_rectangle, const xtd::drawing::image& image, xtd::forms::image_layout image_layout) {
  if (image_layout == xtd::forms::image_layout::none) {
    graphics.draw_image(image, clip_rectangle.location());
  } else if (image_layout == xtd::forms::image_layout::tile) {
    for (int32_t y = 0; y < clip_rectangle.height(); y += image.size().height())
    for (int32_t x = 0; x < clip_rectangle.width(); x += image.size().width())
    graphics.draw_image(image, x, y);
  } else if (image_layout == xtd::forms::image_layout::center) {
    graphics.draw_image(image, clip_rectangle.x() + (clip_rectangle.width() - image.width()) / 2, clip_rectangle.y() + (clip_rectangle.height() - image.height()) / 2);
  } if (image_layout == xtd::forms::image_layout::stretch) {
    graphics.draw_image(image, clip_rectangle);
  } else if (image_layout == xtd::forms::image_layout::zoom) {
    auto image_size = std::min(clip_rectangle.width(), clip_rectangle.height());
    auto image_rect = xtd::drawing::rectangle((clip_rectangle.width() - image_size) / 2, (clip_rectangle.height() - image_size) / 2, image_size, image_size);
    graphics.draw_image(image, image_rect);
  }
}

void control_paint::draw_image_disabled(xtd::drawing::graphics& graphics, const xtd::drawing::image& image, int32_t x, int32_t y, float brightness) {
  graphics.draw_image_disabled(image, x, y, brightness);
}
