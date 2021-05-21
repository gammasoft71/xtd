#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/color_dialog.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/color_dialog.h"
#include "xtd_forms_common_dialog_closed_caller.h"

using namespace xtd;
using namespace xtd::forms;

void color_dialog::reset() {
  dialog_result_ = xtd::forms::dialog_result::none;
  color_ = drawing::color::black;
  custom_colors_ = std::vector<xtd::drawing::color>(16, xtd::drawing::color::white);
  options_ = CC_ALPHACOLOR | CC_PREVENTFULLOPEN;
}

bool color_dialog::run_dialog(intptr_t owner) {
  return native::color_dialog::run_dialog(owner, color_, custom_colors_, options_);
}

void color_dialog::run_sheet(intptr_t owner) {
  if (!owner) run_dialog(owner);
  else native::color_dialog::run_sheet({*new __xtd_forms_common_dialog_closed_caller__(this), &__xtd_forms_common_dialog_closed_caller__::on_common_dialog_closed}, owner, color_, custom_colors_, options_);
}
