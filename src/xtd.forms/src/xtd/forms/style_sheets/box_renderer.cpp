#include "../../../../include/xtd/forms/style_sheets/box_renderer.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

void box_renderer::draw_box(graphics& graphics, const rectangle& bounds) {
  draw_box(graphics, bounds, box_data());
}

void box_renderer::draw_box(graphics& graphics, const rectangle& bounds, const box_data& data) {
  border_renderer::draw_border(graphics, data.get_border_rectangle(bounds), data.borders());
  auto content_rect = data.get_content_rectangle(bounds);
  graphics.fill_rounded_rectangle(*color_data::make_brush(data.background_color(), content_rect), content_rect, data.borders()[0].radius());
}
