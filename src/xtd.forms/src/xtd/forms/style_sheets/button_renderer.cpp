#include "../../../../include/xtd/forms/style_sheets/button_renderer.h"
#include "../../../../include/xtd/forms/style_sheets/button_data.h"
#include "../../../../include/xtd/forms/style_sheets/pseudo_state.h"
#include <xtd/drawing/drawing2d/linear_gradient_brush.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/diagnostics/debug.h>
#include <xtd/console.h>
#include <xtd/invalid_operation_exception.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::forms;
using namespace style_sheets;
using namespace visual_styles;

class control_styles {
public:
  using button_datas_t = std::map<xtd::forms::style_sheets::pseudo_state, xtd::forms::style_sheets::button_data>;

  static const button_datas_t& button_datas() {
    static button_datas_t datas = {
      // Standard
      {xtd::forms::style_sheets::pseudo_state::standard, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color_style::linear_gradient, {system_colors::button_face(), system_colors::button_face()}, 180), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::pressed, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color_style::linear_gradient, {color::from_argb(93, 255, 255, 255), color::from_argb(93, 255, 255, 255)}, 180), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::checked, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color_style::linear_gradient, {color::from_argb(93, 255, 255, 255), color::from_argb(93, 255, 255, 255)}, 180), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::mixed, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color_style::linear_gradient, {color::from_argb(78, 255, 255, 255), color::from_argb(78, 255, 255, 255)}, 180), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::hot, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color_style::linear_gradient, {system_colors::button_face(), system_colors::button_face()}, 180), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::standard | xtd::forms::style_sheets::pseudo_state::disabled, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color_style::linear_gradient, {color::from_argb(35, 255, 255, 255), color::from_argb(35, 255, 255, 255)}, 180), std::nullopt, std::nullopt}, {color_data(system_colors::gray_text()), content_alignment::middle_center, system_fonts::default_font()}}},

      // Default state
      {xtd::forms::style_sheets::pseudo_state::default_state, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color_style::linear_gradient, {color::from_argb(0xFF177AE5), color::from_argb(0xFF166ECD)}, 180), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::pressed, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color_style::linear_gradient, {color::from_argb(0xFF24A0F2), color::from_argb(0xFF2194E5)}, 180), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::checked, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color_style::linear_gradient, {color::from_argb(0xFF24A0F2), color::from_argb(0xFF2194E5)}, 180), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::mixed, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color_style::linear_gradient, {color::from_argb(0xFF24A0F2), color::from_argb(0xFF2194E5)}, 180), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::hot, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color_style::linear_gradient, {color::from_argb(0xFF177AE5), color::from_argb(0xFF166ECD)}, 180), std::nullopt, std::nullopt}, {color_data(system_colors::control_text()), content_alignment::middle_center, system_fonts::default_font()}}},
      {xtd::forms::style_sheets::pseudo_state::default_state | xtd::forms::style_sheets::pseudo_state::disabled, xtd::forms::style_sheets::button_data {{padding(0, 1, 0, 1), {color_data(system_colors::control_dark()), border_style::outset, 1, 5}, padding(1, 1, 1, 3), color_data(color_style::linear_gradient, {color::from_argb(35, 255, 255, 255), color::from_argb(35, 255, 255, 255)}, 180), std::nullopt, std::nullopt}, {color_data(system_colors::gray_text()), content_alignment::middle_center, system_fonts::default_font()}}},
    };
    return datas;
  }
};

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds) {
  draw_button(graphics, bounds, flat_style::standard, push_button_state::normal, false, nullopt, "", nullopt, nullopt, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, flat_style button_style) {
  draw_button(graphics, bounds, button_style, push_button_state::normal, false, nullopt, "", nullopt, nullopt, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, flat_style button_style, push_button_state button_state, bool default_button) {
  draw_button(graphics, bounds, button_style, button_state, default_button, nullopt, "", nullopt, nullopt, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, flat_style button_style, push_button_state button_state, bool default_button, const optional<color>& back_color) {
  draw_button(graphics, bounds, button_style, button_state, default_button, nullopt, "", nullopt, nullopt, nullopt);
}

void button_renderer::draw_button(graphics& graphics, const rectangle& bounds, flat_style button_style, push_button_state button_state, bool default_button, const optional<color>& back_color, const ustring& text, const optional<text_format_flags>& text_flags, const optional<color>& fore_color, const optional<font>& font) {
  diagnostics::debug::write_line(ustring::format("button_state = {}", button_state));
  
  auto current_button_data = control_styles::button_datas().end();
  if (default_button) {
    switch (button_state) {
      case push_button_state::normal: current_button_data = control_styles::button_datas().find(pseudo_state::default_state); break;
      case push_button_state::hot: current_button_data = control_styles::button_datas().find(pseudo_state::default_state | pseudo_state::hot); break;
      case push_button_state::pressed: current_button_data = control_styles::button_datas().find(pseudo_state::default_state | pseudo_state::pressed); break;
      case push_button_state::checked: current_button_data = control_styles::button_datas().find(pseudo_state::default_state | pseudo_state::checked); break;
      case push_button_state::disabled: current_button_data = control_styles::button_datas().find(pseudo_state::default_state | pseudo_state::disabled); break;
      case push_button_state::default_state: current_button_data = control_styles::button_datas().find(pseudo_state::default_state); break;
    }
  } else {
    switch (button_state) {
      case push_button_state::normal: current_button_data = control_styles::button_datas().find(pseudo_state::standard); break;
      case push_button_state::hot: current_button_data = control_styles::button_datas().find(pseudo_state::standard | pseudo_state::hot); break;
      case push_button_state::pressed: current_button_data = control_styles::button_datas().find(pseudo_state::standard | pseudo_state::pressed); break;
      case push_button_state::checked: current_button_data = control_styles::button_datas().find(pseudo_state::standard | pseudo_state::checked); break;
      case push_button_state::disabled: current_button_data = control_styles::button_datas().find(pseudo_state::standard | pseudo_state::disabled); break;
      case push_button_state::default_state:  current_button_data = control_styles::button_datas().find(pseudo_state::default_state); break;
    }
  }

  if (current_button_data == control_styles::button_datas().end()) throw invalid_operation_exception(csf_);

  box_renderer::draw_box(graphics, bounds, current_button_data->second.box());
  text_renderer::draw_text(graphics, current_button_data->second.box().get_content_rectangle(bounds), text, current_button_data->second.text());
}
