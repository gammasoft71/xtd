#include "../../../include/xtd/forms/control_paint.h"
#include "../../../include/xtd/forms/image_renderer.h"
#include <xtd/drawing/string_format>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

void image_renderer::draw_image(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::drawing::image& image, bool enabled, const xtd::drawing::color& back_color, const xtd::forms::style_sheets::iimage_model& data) {
  draw_image(graphics, bounds, image, enabled, back_color.get_brightness(), data);
}

void image_renderer::draw_image(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::drawing::image& image, bool enabled, float brigthtness, const xtd::forms::style_sheets::iimage_model& data) {
  if (image == drawing::image::empty) return;
  auto image_bounds = compute_image_bounds(bounds, image.size(), data.image_alignment());
  if (enabled) graphics.draw_image(image, image_bounds.location());
  else control_paint::draw_image_disabled(graphics, image, image_bounds.location(), brigthtness);
}

rectangle image_renderer::compute_image_bounds(const xtd::drawing::rectangle& bounds, const xtd::drawing::size& image_size, content_alignment align) noexcept {
  switch (align) {
    case content_alignment::top_left: return {bounds.left(), bounds.top(), image_size.width(), image_size.height()};
    case content_alignment::top_center: return {bounds.left() + (bounds.width() - image_size.width()) / 2, bounds.top(), image_size.width(), image_size.height()};
    case content_alignment::top_right: return {bounds.right() - image_size.width(), bounds.top(), image_size.width(), image_size.height()};
    case content_alignment::middle_left: return {bounds.left(), bounds.top() + (bounds.height() - image_size.height()) / 2, image_size.width(), image_size.height()};
    case content_alignment::middle_center: return {bounds.left() + (bounds.width() - image_size.width()) / 2, bounds.top() + (bounds.height() - image_size.height()) / 2, image_size.width(), image_size.height()};
    case content_alignment::middle_right: return {bounds.right() - image_size.width(), bounds.top() + (bounds.height() - image_size.height()) / 2, image_size.width(), image_size.height()};
    case content_alignment::bottom_left: return {bounds.left(), bounds.bottom() - image_size.height(), image_size.width(), image_size.height()};
    case content_alignment::bottom_center: return {bounds.left() + (bounds.width() - image_size.width()) / 2, bounds.top() + bounds.height() - image_size.height(), image_size.width(), image_size.height()};
    case content_alignment::bottom_right: return {bounds.right() - image_size.width(), bounds.bottom() - image_size.height(), image_size.width(), image_size.height()};
  }
  return {};
}
