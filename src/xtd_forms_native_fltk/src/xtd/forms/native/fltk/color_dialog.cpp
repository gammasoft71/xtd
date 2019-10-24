#include <xtd/forms/native/color_dialog.hpp>
#include <xtd/forms/window_color_dialog.hpp>
#include <FL/Fl_Color_Chooser.H>

using namespace xtd;
using namespace xtd::forms::native;

bool color_dialog::run_dialog(intptr_t hwnd, drawing::color& color, std::optional<std::vector<int32_t>>& custom_colors, size_t options) {
  uchar r = color.r();
  uchar g = color.g();
  uchar b = color.b();
  if (fl_color_chooser("Color", r, g, b) == 0)
    return false;
  color = drawing::color::from_argb(r, g, b);
  return true;
}
