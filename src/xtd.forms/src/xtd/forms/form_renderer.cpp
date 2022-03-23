#include "../../../include/xtd/forms/form_renderer.h"
#include "../../../include/xtd/forms/style_sheets/form.h"
#include "../../../include/xtd/forms/style_sheets/pseudo_state.h"
#include "../../../include/xtd/forms/style_sheets/style_sheet.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;
using namespace xtd::forms::visual_styles;

void form_renderer::draw_form(const xtd::forms::style_sheets::style_sheet& style_sheet, xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, xtd::forms::visual_styles::form_state form_state, const std::optional<xtd::drawing::color>& back_color) {
  style_sheets::form current_form_style_sheet;
  switch (form_state) {
    case control_state::normal: current_form_style_sheet = style_sheet.form(style_sheets::pseudo_state::standard); break;
    case control_state::hot: current_form_style_sheet = style_sheet.form(style_sheets::pseudo_state::standard | pseudo_state::hover); break;
    case control_state::pressed: current_form_style_sheet = style_sheet.form(style_sheets::pseudo_state::standard | pseudo_state::pressed); break;
    case control_state::disabled: current_form_style_sheet = style_sheet.form(style_sheets::pseudo_state::standard | pseudo_state::disabled); break;
  }
  
  box_renderer::draw_box(graphics, bounds, current_form_style_sheet);
}
