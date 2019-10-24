#include <xtd/drawing/native/fl_font.hpp>
#include <xtd/forms/native/font_dialog.hpp>
#include <xtd/forms/window_font_dialog.hpp>
#include "fl_font_chooser.hpp"

using namespace xtd;
using namespace xtd::forms::native;

bool font_dialog::run_dialog(intptr_t hwnd, drawing::font& font, drawing::color& color, size_t options, size_t min_size, size_t max_size, bool show_color) {
  Fl_Font flfont = reinterpret_cast<drawing::native::fl_font*>(font.handle())->font();
  Fl_Fontsize flfontsize = reinterpret_cast<drawing::native::fl_font*>(font.handle())->size();
  Fl_Color flcolor = fl_rgb_color(color.r(), color.g(), color.b());
  if (fl_font_chooser("Font", flfont, flfontsize, flcolor) == 0) return false;
  font = drawing::font(reinterpret_cast<intptr_t>(new drawing::native::fl_font(flfont, flfontsize)));
  color = drawing::color::from_argb(static_cast<uint32_t>(flcolor) >> 8);
  return true;
}
