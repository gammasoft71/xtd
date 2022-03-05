#include "../../../include/xtd/forms/text_renderer.h"
#include <xtd/drawing/string_format.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

void text_renderer::draw_text(xtd::drawing::graphics& g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const itext_model& text_model) {
  g.draw_string(text, text_model.font(), solid_brush(text_model.color()), bounds, text_model.make_string_format());
}
