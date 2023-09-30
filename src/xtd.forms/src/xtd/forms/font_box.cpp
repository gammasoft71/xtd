#include "../../../include/xtd/forms/font_box.h"
#include "../../../include/xtd/forms/font_dialog.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

dialog_result font_box::show(font& font) {
  return show_font_box(font);
}

dialog_result font_box::show(font& font, const font_box_options options) {
  return show_font_box(font, nullptr, nullptr, options);
}

dialog_result font_box::show(font& font, const iwin32_window& owner) {
  return show_font_box(font, nullptr, &owner);
}

dialog_result font_box::show(font& font, const iwin32_window& owner, const font_box_options options) {
  return show_font_box(font, nullptr, &owner, options);
}

dialog_result font_box::show(font& font, color& color) {
  return show_font_box(font, &color);
}

dialog_result font_box::show(font& font, color& color, const font_box_options options) {
  return show_font_box(font, &color, nullptr, options);
}

dialog_result font_box::show(font& font, color& color, const iwin32_window& owner) {
  return show_font_box(font, &color, &owner);
}

dialog_result font_box::show(font& font, color& color, const iwin32_window& owner, const font_box_options options) {
  return show_font_box(font, &color, &owner, options);
}

dialog_result font_box::show_font_box(font& font, color* color, const iwin32_window* owner, font_box_options options) {
  auto dialog = font_dialog {};
  if (color) {
    options |= font_box_options::show_color;
    dialog.color(*color);
  }
  dialog.allow_simulation((options & font_box_options::allow_simulations) == font_box_options::allow_simulations)
  .allow_vector_fonts((options & font_box_options::allow_vector_fonts) == font_box_options::allow_vector_fonts)
  .allow_vertical_fonts((options & font_box_options::allow_vertical_fonts) == font_box_options::allow_vertical_fonts)
  .allow_script_change((options & font_box_options::allow_script_change) == font_box_options::allow_script_change)
  .fixed_pitch_only((options & font_box_options::fixed_pitch_only) == font_box_options::fixed_pitch_only)
  .font(font)
  .script_only((options & font_box_options::scripts_only) == font_box_options::scripts_only)
  .show_apply((options & font_box_options::show_apply) == font_box_options::show_apply)
  .show_color((options & font_box_options::show_color) == font_box_options::show_color)
  .show_effect((options & font_box_options::show_effects) == font_box_options::show_effects)
  .show_help((options & font_box_options::show_help) == font_box_options::show_help);
  auto res = owner ? dialog.show_sheet_dialog(*owner) : dialog.show_dialog();
  if (res == dialog_result::ok) {
    font = dialog.font();
    if (color) *color = dialog.color();
  }
  return res;
}
