#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/file_dialog.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/open_file_dialog.h"
#include "xtd_forms_common_dialog_closed_caller.h"

using namespace xtd;
using namespace xtd::forms;

bool open_file_dialog::run_file_dialog(intptr_t owner) {
  return native::file_dialog::run_open_dialog(owner, default_ext_, file_name_, file_names_, filter_, filter_index_, initial_directory_, options_, support_multi_dotted_extensions_, title_);
}

void open_file_dialog::run_file_sheet(intptr_t owner) {
  if (!owner) run_file_dialog(owner);
  else native::file_dialog::run_open_sheet({*new __xtd_forms_common_dialog_closed_caller__(this), &__xtd_forms_common_dialog_closed_caller__::on_common_dialog_closed}, owner, default_ext_, file_name_, file_names_, filter_, filter_index_, initial_directory_, options_, support_multi_dotted_extensions_, title_);
}
