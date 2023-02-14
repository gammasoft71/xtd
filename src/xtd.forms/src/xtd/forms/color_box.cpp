#include "../../../include/xtd/forms/color_box.h"

using namespace xtd;
using namespace xtd::forms;

xtd::forms::dialog_result color_box::show(xtd::drawing::color& color, const xtd::forms::iwin32_window& owner) {return show_color_box(color, &owner);}

xtd::forms::dialog_result color_box::show(xtd::drawing::color& color, const xtd::forms::iwin32_window& owner, const xtd::ustring& title) {return show_color_box(color, &owner, title);}

xtd::forms::dialog_result color_box::show(xtd::drawing::color& color, const xtd::forms::iwin32_window& owner, const xtd::ustring& title, color_box_styles styles) {return show_color_box(color, &owner, title, styles);}

xtd::forms::dialog_result color_box::show(xtd::drawing::color& color, const xtd::forms::iwin32_window& owner, const xtd::ustring& title, color_box_styles styles, const std::vector<xtd::drawing::color>& custom_colors) {return show_color_box(color, &owner, title, styles, custom_colors);}

xtd::forms::dialog_result color_box::show(xtd::drawing::color& color) {return show_color_box(color, nullptr);}

xtd::forms::dialog_result color_box::show(xtd::drawing::color& color, const xtd::ustring& title) {return show_color_box(color, nullptr, title);}

xtd::forms::dialog_result color_box::show(xtd::drawing::color& color, const xtd::ustring& title, color_box_styles styles) {return show_color_box(color, nullptr, title, styles);}

xtd::forms::dialog_result color_box::show(xtd::drawing::color& color, const xtd::ustring& title, color_box_styles styles, const std::vector<xtd::drawing::color>& custom_colors) {return show_color_box(color, nullptr, title, styles, custom_colors);}

xtd::forms::dialog_result color_box::show_color_box(xtd::drawing::color& color, const xtd::forms::iwin32_window* owner, const xtd::ustring& title, color_box_styles styles, const std::optional<std::vector<xtd::drawing::color>>& custom_colors) {
  xtd::forms::color_dialog dialog;
  dialog.color(color);
  dialog.alpha_color((styles & color_box_styles::alpha_color) == color_box_styles::alpha_color);
  dialog.allow_full_open((styles & color_box_styles::allow_full_open) == color_box_styles::allow_full_open);
  dialog.any_color((styles & color_box_styles::any_color) == color_box_styles::any_color);
  dialog.full_open((styles & color_box_styles::full_open) == color_box_styles::full_open);
  dialog.show_help((styles & color_box_styles::show_help) == color_box_styles::show_help);
  dialog.title(title);
  if (custom_colors.has_value()) dialog.custom_colors(custom_colors.value());
  dialog.solid_color_only((styles & color_box_styles::solid_color_only) == color_box_styles::solid_color_only);
  xtd::forms::dialog_result result = owner ? dialog.show_sheet_dialog(*owner) : dialog.show_dialog();
  if (result == xtd::forms::dialog_result::ok) color = dialog.color();
  return result;
}
