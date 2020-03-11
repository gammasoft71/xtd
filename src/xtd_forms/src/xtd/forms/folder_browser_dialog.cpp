#include <xtd/forms/native/folder_browser_dialog.h>
#include "../../../include/xtd/forms/folder_browser_dialog.h"

using namespace xtd;
using namespace xtd::forms;

void folder_browser_dialog::reset() {
  this->options_ = BIF_USENEWUI;
}

bool folder_browser_dialog::run_dialog(intptr_t owner) {
  return native::folder_browser_dialog::run_dialog(owner, this->description_, this->root_folder_, this->selected_path_, this->options_);
}
