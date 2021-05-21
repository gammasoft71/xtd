#include <xtd/forms/browser_info_flags.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/folder_browser_dialog.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

#include <wx/filefn.h>
#include <wx/dirdlg.h>
#include <wx/windowptr.h>

using namespace xtd;
using namespace xtd::forms::native;

#if defined(__WXMSW__)
#include <ShlObj.h>
using namespace std;
namespace {
  int CALLBACK OnBrowserCalllback(HWND hwnd, UINT message, LPARAM lParam, LPARAM data) {
    if (message == BFFM_INITIALIZED && !wstring(reinterpret_cast<wchar_t*>(data)).empty())
      SendMessage(hwnd, BFFM_SETSELECTION, 1, data);
    return 0;
  }
}

bool folder_browser_dialog::run_dialog(intptr_t hwnd, const std::string& description, environment::special_folder root_folder, std::string& selected_path, size_t options) {
  BROWSEINFO browserInfo = { 0 };
  browserInfo.hwndOwner = hwnd == 0 ? nullptr : reinterpret_cast<control_handler*>(hwnd)->control()->GetHandle();
  PIDLIST_ABSOLUTE pidlRoot;
  SHGetSpecialFolderLocation(reinterpret_cast<HWND>(hwnd), static_cast<int>(root_folder), &pidlRoot);
  browserInfo.lpfn = OnBrowserCalllback;
  wstring wselected_path = wxString(selected_path.c_str(), wxMBConvUTF8()).ToStdWstring();
  browserInfo.lParam = reinterpret_cast<LPARAM>(wselected_path.c_str());
  wstring wdescription = wxString(description.c_str(), wxMBConvUTF8()).ToStdWstring();
  browserInfo.lpszTitle = wdescription.c_str();

  browserInfo.ulFlags = options;

  PCIDLIST_ABSOLUTE result = SHBrowseForFolder(&browserInfo);
  if (result) {
    wchar_t path[MAX_PATH];
    SHGetPathFromIDList(result, path);
    selected_path = wxString(path).ToUTF8().data();
    return true;
  }
  return false;
}

void folder_browser_dialog::run_sheet(xtd::delegate<void(bool)> on_dialog_closed, intptr_t hwnd, const std::string& description, environment::special_folder root_folder, std::string& selected_path, size_t options) {
  on_dialog_closed(run_dialog(hwnd, description, root_folder, selected_path, options));
}

#else
namespace {
// Workaround : with wxWidgets version <= 3.1.4 wxDirDialog ShowWindowModal method doesn't exists on other platform that macOS
#if defined(__APPLE__)
  using DirDialog = wxDirDialog;
#else
  class DirDialog : public wxDirDialog {
  public:
    DirDialog(wxWindow *parent, const wxString& message = wxDirSelectorPromptStr, const wxString& defaultPath = "", long style = wxDD_DEFAULT_STYLE, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, const wxString& name = wxDirDialogNameStr) : wxDirDialog(parent, message, defaultPath, style, pos, size, name) {}
    void ShowWindowModal() {
      SetReturnCode(ShowModal());
      wxWindowModalDialogEvent event(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, GetId());
      event.SetEventObject(this);
      wxPostEvent(this, event);
    }
  };
#endif
}

bool folder_browser_dialog::run_dialog(intptr_t hwnd, const std::string& description, environment::special_folder root_folder, std::string& selected_path, size_t options) {
  wxWindowPtr<DirDialog> dialog(new DirDialog(hwnd == 0 ? nullptr : reinterpret_cast<control_handler*>(hwnd)->control(), {description.c_str(), wxMBConvUTF8()}, {(!selected_path.empty() && wxDirExists({selected_path.c_str(), wxMBConvUTF8()}) ? selected_path : environment::get_folder_path(root_folder)).c_str(), wxMBConvUTF8()}, wxDD_DEFAULT_STYLE));
  if (dialog->ShowModal() != wxID_OK) return false;
  selected_path = dialog->GetPath().utf8_str().data();
  return true;
}

void folder_browser_dialog::run_sheet(xtd::delegate<void(bool)> on_dialog_closed, intptr_t hwnd, const std::string& description, environment::special_folder root_folder, std::string& selected_path, size_t options) {
  wxWindowPtr<DirDialog> dialog(new DirDialog(hwnd == 0 ? nullptr : reinterpret_cast<control_handler*>(hwnd)->control(), {description.c_str(), wxMBConvUTF8()}, {(!selected_path.empty() && wxDirExists({selected_path.c_str(), wxMBConvUTF8()}) ? selected_path : environment::get_folder_path(root_folder)).c_str(), wxMBConvUTF8()}, wxDD_DEFAULT_STYLE));
  dialog->Bind(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, [dialog, on_dialog_closed, &selected_path](wxWindowModalDialogEvent& event) {
    auto result = event.GetReturnCode() == wxID_OK;
    selected_path = dialog->GetPath().utf8_str().data();
    on_dialog_closed(result);
  });
  dialog->ShowWindowModal();
}
#endif
