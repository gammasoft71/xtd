#include <xtd/xtd.io>
#include <xtd/forms/native/folder_browser_dialog.h>
#include <xtd/forms/folder_browser_dialog_flags.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"

#include <wx/filefn.h>
#include <wx/dirdlg.h>
#include <wx/windowptr.h>

using namespace xtd;
using namespace xtd::forms::native;

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
      wxWindowModalDialogEvent event(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, this->GetId());
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
  dialog->ShowWindowModal();
  dialog->Bind(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, [dialog, on_dialog_closed, &selected_path](wxWindowModalDialogEvent& event) {
    auto result = event.GetReturnCode() == wxID_OK;
    selected_path = dialog->GetPath().utf8_str().data();
    on_dialog_closed(result);
  });
}
