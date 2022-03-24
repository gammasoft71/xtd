#include "../../../include/xtd/forms/control_paint.h"
#include "../../../include/xtd/forms/text_renderer.h"
#include <xtd/drawing/string_format.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

void text_renderer::draw_shadow_text(xtd::drawing::graphics& g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const itext_model& text_model, const ibox_model& box) {
  auto back_color = box.background_image().colors().size() != 0 ? box.background_image().colors()[0] : box.background_color();
  g.draw_string(text, text_model.font(), solid_brush(control_paint::dark(back_color)), rectangle::offset(bounds, {1, 1}), text_model.make_string_format());
  g.draw_string(text, text_model.font(), solid_brush(text_model.color()), rectangle::offset(bounds, {-1, -1}), text_model.make_string_format());
}

void text_renderer::draw_text(xtd::drawing::graphics& g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const itext_model& text_model) {
  g.draw_string(text, text_model.font(), solid_brush(text_model.color()), bounds, text_model.make_string_format());
}
