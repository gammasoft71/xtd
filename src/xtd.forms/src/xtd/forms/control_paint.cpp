#include "../../../include/xtd/forms/control_paint.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

void control_paint::draw_button(xtd::drawing::graphics& graphics, int32_t x, int32_t y, int32_t width, int32_t height, xtd::forms::button_state state) {
}

void control_paint::draw_image(xtd::drawing::graphics& graphics, const xtd::drawing::image& image, int32_t x, int32_t y, int32_t width, int32_t height, xtd::forms::image_layout image_layout) {
  if (image_layout == xtd::forms::image_layout::none) {
    graphics.draw_image(image, x, y);
  } else if (image_layout == xtd::forms::image_layout::tile) {
    for (int32_t offset_y = 0; offset_y < height; offset_y += image.size().height())
      for (int32_t offset_x = 0; offset_x < width; offset_x += image.size().width())
        graphics.draw_image(image, x + offset_x, y + offset_y);
  } else if (image_layout == xtd::forms::image_layout::center) {
    graphics.draw_image(image, x + (width - image.width()) / 2, y + (height - image.height()) / 2);
  } else if (image_layout == xtd::forms::image_layout::stretch) {
    graphics.draw_image(image, x, y, width, height);
  } else if (image_layout == xtd::forms::image_layout::zoom) {
    auto image_size = std::min(width, height);
    auto image_rect = xtd::drawing::rectangle((width - image_size) / 2, (height - image_size) / 2, image_size, image_size);
    graphics.draw_image(image, image_rect);
  }
}

void control_paint::draw_image_disabled(xtd::drawing::graphics& graphics, const xtd::drawing::image& image, int32_t x, int32_t y, float brightness) {
  graphics.draw_image_disabled(image, x, y, brightness);
}
