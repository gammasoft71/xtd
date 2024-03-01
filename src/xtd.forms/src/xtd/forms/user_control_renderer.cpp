#include "../../../include/xtd/forms/style_sheets/button.h"
#include "../../../include/xtd/forms/style_sheets/pseudo_state.h"
#include "../../../include/xtd/forms/style_sheets/style_sheet.h"
#include "../../../include/xtd/forms/user_control_renderer.h"
#include <xtd/drawing/color_transformer>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;
using namespace xtd::forms::visual_styles;

void user_control_renderer::draw_user_control(graphics& graphics, const rectangle& bounds) {
  draw_user_control(graphics, bounds, control_state::normal, nullopt);
}

void user_control_renderer::draw_user_control(graphics& graphics, const rectangle& bounds, control_state control_state) {
  draw_user_control(graphics, bounds, control_state, nullopt);
}

void user_control_renderer::draw_user_control(graphics& graphics, const rectangle& bounds, control_state control_state, const optional<color>& back_color) {
  draw_user_control(style_sheet::current_style_sheet(), graphics, bounds, control_state, back_color, nullopt, border_sides::none);
}

void user_control_renderer::draw_user_control(const style_sheets::style_sheet& style_sheet, graphics& graphics, const rectangle& bounds, control_state state, const optional<color>& back_color, const optional<xtd::forms::border_style>& border, xtd::forms::border_sides sides) {
  auto current_style_sheet = style_sheets::user_control {};
  switch (state) {
    case control_state::normal: current_style_sheet = style_sheet.user_control(style_sheets::pseudo_state::standard); break;
    case control_state::hot: current_style_sheet = style_sheet.user_control(style_sheets::pseudo_state::standard | pseudo_state::hover); break;
    case control_state::pressed: current_style_sheet = style_sheet.user_control(style_sheets::pseudo_state::standard | pseudo_state::pressed); break;
    case control_state::disabled: current_style_sheet = style_sheet.user_control(style_sheets::pseudo_state::standard | pseudo_state::disabled); break;
  }
  
  if (back_color) current_style_sheet.background_color(back_color.value());
  if (border) {
    if (current_style_sheet.background_color() == color::transparent) current_style_sheet.border_color(xtd::forms::style_sheets::border_color(style_sheet::current_style_sheet().user_control().color()));
    else current_style_sheet.border_color(border_color(current_style_sheet.background_color().is_dark() ? color_transformer::light(current_style_sheet.background_color(), 2.0 / 3) : color_transformer::dark(current_style_sheet.background_color(), 1.0 / 3)));
    auto [border_type, border_width, border_radius] = style_sheets::style_sheet::to_border_type(border.value());
    current_style_sheet.border_style(style_sheets::border_style((sides & border_sides::left) == border_sides::left ? border_type : style_sheets::border_type::none, (sides & border_sides::top) == border_sides::top ? border_type : style_sheets::border_type::none, (sides & border_sides::right) == border_sides::right ? border_type : style_sheets::border_type::none, (sides & border_sides::bottom) == border_sides::bottom ? border_type : style_sheets::border_type::none));
    current_style_sheet.border_width(style_sheets::border_width(length(border_width)));
    current_style_sheet.border_radius(style_sheets::border_radius(length(border_radius)));
  }
  
  box_renderer::draw_box(graphics, bounds, current_style_sheet);
}
