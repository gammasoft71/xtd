#include <xtd/xtd.io>
#include <xtd/forms/native/folder_browser_dialog.hpp>
#include <xtd/forms/folder_browser_dialog_flags.hpp>
#include <wx/filefn.h>
#include <wx/dirdlg.h>

using namespace xtd;
using namespace xtd::forms::native;

#if defined(__WXMSW__)
#include <windows.h>
#include <CommCtrl.h>
#include <ShlObj.h>

bool folder_browser_dialog::run_dialog(intptr_t hwnd, const ustring& description, environment::special_folder root_folder, ustring& selected_path, size_t options) {
  CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

  BROWSEINFO browser_info;
  ZeroMemory(&browser_info, sizeof(browser_info));

  browser_info.hwndOwner = reinterpret_cast<wxWindow*>(hwnd)->GetHandle();
  PIDLIST_ABSOLUTE root_path;
  if (root_folder != environment::special_folder::desktop && SHParseDisplayName(ustring(environment::get_folder_path(root_folder)).wc_str(), nullptr, &root_path, SFGAO_FILESYSTEM, nullptr) == S_OK)
    browser_info.pidlRoot = root_path;
  browser_info.lParam = reinterpret_cast<LPARAM>(selected_path.wc_str());
  browser_info.lpszTitle = description.wc_str();
  browser_info.ulFlags = options;

  PCIDLIST_ABSOLUTE result = SHBrowseForFolder(&browser_info);
  if (!result) return false;
  wchar_t path[MAX_PATH];
  SHGetPathFromIDList(result, path);

  selected_path = path;
  return true;
}
#else
bool folder_browser_dialog::run_dialog(intptr_t hwnd, const ustring& description, environment::special_folder root_folder, ustring& selected_path, size_t options) {
  ustring path = environment::get_folder_path(root_folder);
  if (!selected_path.empty() && wxDirExists(selected_path.str())) path = selected_path;

  long wx_style = wxDD_DEFAULT_STYLE;
  
  wxDirDialog dialog(reinterpret_cast<wxWindow*>(hwnd), description.str(), path.str(), wx_style);
  if (dialog.ShowModal() != wxID_OK) return false;
  selected_path = dialog.GetPath().ToStdString();
  return true;
}
#endif
