#include <xtd/forms/native/file_dialog.h>
#include "../../../include/xtd/forms/open_file_dialog.h"

using namespace xtd;
using namespace xtd::forms;

bool open_file_dialog::run_file_dialog(intptr_t hwnd_owner) {
  return native::file_dialog::run_open_dialog(hwnd_owner, default_ext_, file_name_, file_names_, filter_, filter_index_, initial_directory_, options_, support_multi_dotted_extensions_, title_);
}
