#include <xtd/forms/native/font_dialog.h>
#include "../../../include/xtd/forms/font_dialog.h"

using namespace xtd;
using namespace xtd::forms;

void font_dialog::reset() {
  dialog_result_ = xtd::forms::dialog_result::none;
  color_ = xtd::forms::theme_colors::current_theme().control_text();
  font_ = drawing::system_fonts::default_font();
  max_size_ = 0;
  min_size_ = 0;
  options_ = CF_TTONLY;
  show_color_ = false;
}

void font_dialog::on_apply(const event_args &e) {
  apply(*this, e);
}

bool font_dialog::run_dialog(intptr_t owner) {
  return native::font_dialog::run_dialog(owner, font_, color_, options_, min_size_, max_size_, show_color_);
}

void font_dialog::run_sheet_dialog(intptr_t owner) {
  /// @todo call native::color_dialog::run_sheeet_dialog and catch close event...
  on_common_dialog_closed(common_dialog_closed_event_args(native::font_dialog::run_dialog(owner, font_, color_, options_, min_size_, max_size_, show_color_) ? dialog_result::ok : dialog_result::cancel));
}
