#include <xtd/xtd.io>
#include <xtd/forms/native/folder_browser_dialog.hpp>
#include <xtd/forms/folder_browser_dialog_flags.hpp>
#include <wx/dirdlg.h>

using namespace xtd;
using namespace xtd::forms::native;

bool folder_browser_dialog::run_dialog(intptr_t hwnd, const ustring& description, environment::special_folder root_folder, ustring& selected_path, size_t options_) {
  ustring path = environment::get_folder_path(root_folder);
  if (!selected_path.empty() && wxDirExists(selected_path.str())) path = selected_path;

  wxDirDialog dialog(reinterpret_cast<wxWindow*>(hwnd), description.wstr(), path.wstr());
  if (dialog.ShowModal() != wxID_OK) return false;
  selected_path = dialog.GetPath().ToStdString();
  return true;
}
