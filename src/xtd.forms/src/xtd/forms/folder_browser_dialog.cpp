#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/folder_browser_dialog.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/folder_browser_dialog.h"
#include "xtd_forms_common_dialog_closed_caller.h"

using namespace xtd;
using namespace xtd::forms;

void folder_browser_dialog::reset() {
  dialog_result_ = xtd::forms::dialog_result::none;
  options_ = BIF_USENEWUI;
}

bool folder_browser_dialog::run_dialog(intptr_t owner) {
  return native::folder_browser_dialog::run_dialog(owner, description_, root_folder_, selected_path_, options_);
}

void folder_browser_dialog::run_sheet(intptr_t owner) {
  if (!owner) run_dialog(owner);
  else native::folder_browser_dialog::run_sheet({*new __xtd_forms_common_dialog_closed_caller__(this), &__xtd_forms_common_dialog_closed_caller__::on_common_dialog_closed}, owner, description_, root_folder_, selected_path_, options_);
}
