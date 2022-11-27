#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/font_dialog.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/font_dialog.h"
#include "xtd_forms_common_dialog_closed_caller.h"

using namespace xtd;
using namespace xtd::forms;

void font_dialog::reset() noexcept {
  set_dialog_result(xtd::forms::dialog_result::none);
  color_ = application::style_sheet().system_colors().control_text();
  font_ = drawing::system_fonts::default_font();
  max_size_ = 0;
  min_size_ = 0;
  options_ = CF_TTONLY;
  show_color_ = false;
}

void font_dialog::on_apply(const event_args& e) {
  apply(*this, e);
}

bool font_dialog::run_dialog(intptr_t owner) {
  return native::font_dialog::run_dialog(owner, font_, color_, options_, min_size_, max_size_, show_color_);
}

void font_dialog::run_sheet(intptr_t owner) {
  if (!owner) run_dialog(owner);
  else native::font_dialog::run_sheet({*new __xtd_forms_common_dialog_closed_caller__(this), &__xtd_forms_common_dialog_closed_caller__::on_common_dialog_closed}, owner, font_, color_, options_, min_size_, max_size_, show_color_);
}
