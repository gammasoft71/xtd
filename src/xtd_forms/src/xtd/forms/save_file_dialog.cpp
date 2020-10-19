#include <xtd/forms/native/file_dialog.h>
#include "../../../include/xtd/forms/save_file_dialog.h"

using namespace xtd;
using namespace xtd::forms;

bool save_file_dialog::run_file_dialog(intptr_t owner) {
  return native::file_dialog::run_save_dialog(owner, default_ext_, file_name_, file_names_, filter_, filter_index_, initial_directory_, options_, support_multi_dotted_extensions_, title_);
}

void save_file_dialog::run_file_sheet(intptr_t owner) {
  /// @todo call native::color_dialog::run_sheeet_dialog and catch close event...
  on_common_dialog_closed(common_dialog_closed_event_args(native::file_dialog::run_save_dialog(owner, default_ext_, file_name_, file_names_, filter_, filter_index_, initial_directory_, options_, support_multi_dotted_extensions_, title_) ? dialog_result::ok : dialog_result::cancel));
}
