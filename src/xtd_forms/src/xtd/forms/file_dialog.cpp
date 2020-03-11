#include "../../../include/xtd/forms/file_dialog.h"

using namespace xtd;
using namespace xtd::forms;

void file_dialog::reset() {
  auto_upgrade_enabled_ = true;
  default_ext_ = "";
  file_name_ = "";
  file_names_.clear();
  filter_ = "";
  filter_index_ = 1;
  initial_directory_ = "";
  options_ = OFN_HIDEREADONLY | OFN_PATHMUSTEXIST | OFN_ADDEXTENSION;
  support_multi_dotted_extensions_ = true;
  title_ = "";
}

bool file_dialog::run_dialog(intptr_t hwnd_owner) {
  return run_file_dialog(hwnd_owner);
}
