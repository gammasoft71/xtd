#include <xtd/forms/native/folder_browser_dialog.h>
#include "../../../include/xtd/forms/folder_browser_dialog.h"

using namespace xtd;
using namespace xtd::forms;

void folder_browser_dialog::reset() {
  dialog_result_ = xtd::forms::dialog_result::none;
  options_ = BIF_USENEWUI;
}

bool folder_browser_dialog::run_dialog(intptr_t owner) {
  return native::folder_browser_dialog::run_dialog(owner, description_, root_folder_, selected_path_, options_);
}

void folder_browser_dialog::run_sheet_dialog(intptr_t owner) {
  /// @todo call native::color_dialog::run_sheeet_dialog and catch close event...
  on_common_dialog_closed(common_dialog_closed_event_args(native::folder_browser_dialog::run_dialog(owner, description_, root_folder_, selected_path_, options_) ? dialog_result::ok : dialog_result::cancel));
}
