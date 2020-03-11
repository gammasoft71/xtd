#include <xtd/xtd.io>
#include <xtd/forms/native/folder_browser_dialog.h>
#include <xtd/forms/folder_browser_dialog_flags.h>
#include <wx/filefn.h>
#include <wx/dirdlg.h>

using namespace xtd;
using namespace xtd::forms::native;

bool folder_browser_dialog::run_dialog(intptr_t hwnd, const std::string& description, environment::special_folder root_folder, std::string& selected_path, size_t options) {
  std::string path = environment::get_folder_path(root_folder);
  if (!selected_path.empty() && wxDirExists({selected_path.c_str(), wxMBConvUTF8()})) path = selected_path;

  long wx_style = wxDD_DEFAULT_STYLE;
  
  wxDirDialog dialog(reinterpret_cast<wxWindow*>(hwnd), {description.c_str(), wxMBConvUTF8()}, {path.c_str(), wxMBConvUTF8()}, wx_style);
  if (dialog.ShowModal() != wxID_OK) return false;
  selected_path = dialog.GetPath().utf8_str().data();
  return true;
}
