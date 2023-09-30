#include "../../../include/xtd/forms/color_box.h"
#include "../../../include/xtd/forms/color_dialog.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

dialog_result color_box::show(drawing::color& color, const iwin32_window& owner) {return show_color_box(color, &owner);}

dialog_result color_box::show(drawing::color& color, const iwin32_window& owner, const ustring& title) {return show_color_box(color, &owner, title);}

dialog_result color_box::show(drawing::color& color, const iwin32_window& owner, const ustring& title, color_box_styles styles) {return show_color_box(color, &owner, title, styles);}

dialog_result color_box::show(drawing::color& color, const iwin32_window& owner, const ustring& title, color_box_styles styles, const vector<drawing::color>& custom_colors) {return show_color_box(color, &owner, title, styles, custom_colors);}

dialog_result color_box::show(drawing::color& color) {return show_color_box(color, nullptr);}

dialog_result color_box::show(drawing::color& color, const ustring& title) {return show_color_box(color, nullptr, title);}

dialog_result color_box::show(drawing::color& color, const ustring& title, color_box_styles styles) {return show_color_box(color, nullptr, title, styles);}

dialog_result color_box::show(drawing::color& color, const ustring& title, color_box_styles styles, const vector<drawing::color>& custom_colors) {return show_color_box(color, nullptr, title, styles, custom_colors);}

dialog_result color_box::show_color_box(drawing::color& color, const iwin32_window* owner, const ustring& title, color_box_styles styles, const optional<vector<drawing::color>>& custom_colors) {
  auto dialog = color_dialog {};
  dialog.color(color);
  dialog.alpha_color((styles & color_box_styles::alpha_color) == color_box_styles::alpha_color);
  dialog.allow_full_open((styles & color_box_styles::allow_full_open) == color_box_styles::allow_full_open);
  dialog.any_color((styles & color_box_styles::any_color) == color_box_styles::any_color);
  dialog.full_open((styles & color_box_styles::full_open) == color_box_styles::full_open);
  dialog.show_help((styles & color_box_styles::show_help) == color_box_styles::show_help);
  dialog.title(title);
  if (custom_colors.has_value()) dialog.custom_colors(custom_colors.value());
  dialog.solid_color_only((styles & color_box_styles::solid_color_only) == color_box_styles::solid_color_only);
  auto result = owner ? dialog.show_sheet_dialog(*owner) : dialog.show_dialog();
  if (result == dialog_result::ok) color = dialog.color();
  return result;
}
