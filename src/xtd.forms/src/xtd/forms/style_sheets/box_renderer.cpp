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
  auto bounds_rect = bounds;
  if (data.width() != nullopt) bounds_rect = rectangle(bounds_rect.x(), bounds_rect.y(), data.margin().left() + data.borders()[3].width() + data.padding().left() + data.width().value() + data.padding().right() + data.borders()[1].width() + data.margin().right(), bounds_rect.height());
  if (data.height() != nullopt) bounds_rect = rectangle(bounds_rect.x(), bounds_rect.y(), bounds_rect.width(), data.margin().top() + data.borders()[0].width() + data.padding().top() + data.height().value() + data.padding().bottom() + data.borders()[2].width() + data.margin().bottom());
  
  auto border_rect = rectangle::offset(bounds_rect, data.margin().left(), data.margin().top());
  border_rect = rectangle::inflate(border_rect, -data.margin().right() - data.margin().left(), -data.margin().bottom() - data.margin().top());
  border_renderer::draw_border(graphics, border_rect, data.borders());
  
  auto background_rect = rectangle::offset(border_rect, data.borders()[3].width(), data.borders()[0].width());
  background_rect = rectangle::inflate(background_rect, -data.borders()[3].width() - data.borders()[1].width(), -data.borders()[0].width() - data.borders()[2].width());
  graphics.fill_rounded_rectangle(*data.background_color(), background_rect, data.borders()[0].radius());
}
