#include <xtd/io/path.h>
#include <xtd/convert_string.h>
#include <xtd/forms/open_file_name_flags.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/file_dialog.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <wx/filedlg.h>
#include <wx/windowptr.h>

using namespace std::literals;
using namespace xtd;
using namespace xtd::io;
using namespace xtd::forms::native;

namespace {
  // Workaround : with wxWidgets version <= 3.1.4 FileDialog ShowWindowModal method doesn't exists on other platform that macOS
  #if defined(__APPLE__)
  using FileDialog = wxFileDialog;
  #else
  class FileDialog : public wxFileDialog {
  public:
    FileDialog(wxWindow *parent, const wxString& message = wxFileSelectorPromptStr, const wxString& defaultDir = wxEmptyString, const wxString& defaultFile = wxEmptyString, const wxString& wildCard = wxFileSelectorDefaultWildcardStr, long style = wxFD_DEFAULT_STYLE, const wxPoint& pos = wxDefaultPosition, const wxSize& sz = wxDefaultSize, const wxString& name = wxFileDialogNameStr) : wxFileDialog(parent, message, defaultDir, defaultFile, wildCard, style, pos, sz, name) {}
    void ShowWindowModal() {
      SetReturnCode(ShowModal());
      wxWindowModalDialogEvent event(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, GetId());
      event.SetEventObject(this);
      wxPostEvent(this, event);
    }
  };
  #endif

  wxWindowPtr<FileDialog> create_file_dialog(intptr_t hwnd, bool open_dialog, const ustring& default_ext, ustring& file_name, std::vector<ustring>& file_names, const ustring& filter, size_t filter_index, const ustring& initial_directory, size_t options, bool support_multi_dotted_extensions, const ustring& title) {
    long wx_style = open_dialog ? wxFD_OPEN : wxFD_SAVE;
    if ((options & OFN_NODEREFERENCELINKS) == OFN_NODEREFERENCELINKS) wx_style |= wxFD_NO_FOLLOW;
    if ((options & OFN_FILEMUSTEXIST) == OFN_FILEMUSTEXIST) wx_style |= wxFD_FILE_MUST_EXIST;
    if ((options & OFN_NOCHANGEDIR) != OFN_NOCHANGEDIR) wx_style |= wxFD_CHANGE_DIR;
    if ((options & OFN_SHOWPREVIEW) == OFN_SHOWPREVIEW) wx_style |= wxFD_PREVIEW;
    if ((options & OFN_ALLOWMULTISELECT) == OFN_ALLOWMULTISELECT) wx_style |= wxFD_MULTIPLE;
    if ((options & OFN_FORCESHOWHIDDEN) == OFN_FORCESHOWHIDDEN) wx_style |= wxFD_SHOW_HIDDEN;
    wxWindowPtr<FileDialog> file_dialog(new FileDialog(hwnd == 0 ? nullptr : reinterpret_cast<control_handler*>(hwnd)->control(), convert_string::to_wstring(title), convert_string::to_wstring(initial_directory), convert_string::to_wstring(file_name), convert_string::to_wstring(filter), wx_style));
    file_dialog->SetFilterIndex(static_cast<int32_t>(filter_index - 1));
    return file_dialog;
  }

  void get_results(const FileDialog& dialog, size_t options, ustring& file_name, std::vector<ustring>& file_names) {
    if ((options & OFN_ALLOWMULTISELECT) != OFN_ALLOWMULTISELECT)
      file_name = convert_string::to_string(dialog.GetPath().c_str().AsWChar());
    else {
      wxArrayString files;
      dialog.GetFilenames(files);
      for (wxString file : files)
        file_names.push_back(path::combine(convert_string::to_string(dialog.GetDirectory().c_str().AsWChar()), convert_string::to_string(file.c_str().AsWChar())));
      file_name = file_names[0];
    }
  }
}

bool file_dialog::run_open_dialog(intptr_t hwnd, const ustring& default_ext, ustring& file_name, std::vector<ustring>& file_names, const ustring& filter, size_t filter_index, const ustring& initial_directory, size_t options, bool support_multi_dotted_extensions, const ustring& title) {
  wxWindowPtr<FileDialog> dialog(create_file_dialog(hwnd, true, default_ext, file_name, file_names, filter, filter_index, initial_directory, options, support_multi_dotted_extensions, title));
  auto result = dialog->ShowModal() == wxID_OK;
  if (result) get_results(*dialog, options, file_name, file_names);
  return result;
}

void file_dialog::run_open_sheet(xtd::delegate<void(bool)> on_dialog_closed, intptr_t hwnd, const ustring& default_ext, ustring& file_name, std::vector<ustring>& file_names, const ustring& filter, size_t filter_index, const ustring& initial_directory, size_t options, bool support_multi_dotted_extensions, const ustring& title) {
  wxWindowPtr<FileDialog> dialog(create_file_dialog(hwnd, true, default_ext, file_name, file_names, filter, filter_index, initial_directory, options, support_multi_dotted_extensions, title));
  dialog->Bind(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, [dialog, on_dialog_closed, options, &file_name, &file_names](wxWindowModalDialogEvent& event) {
    auto result = event.GetReturnCode() == wxID_OK;
    if (result) get_results(*dialog, options, file_name, file_names);
    on_dialog_closed(result);
  });
  dialog->ShowWindowModal();
}

bool file_dialog::run_save_dialog(intptr_t hwnd, const ustring& default_ext, ustring& file_name, std::vector<ustring>& file_names, const ustring& filter, size_t filter_index, const ustring& initial_directory, size_t options, bool support_multi_dotted_extensions, const ustring& title) {
  wxWindowPtr<FileDialog> dialog(create_file_dialog(hwnd, false, default_ext, file_name, file_names, filter, filter_index, initial_directory, options, support_multi_dotted_extensions, title));
  auto result = dialog->ShowModal() == wxID_OK;
  if (result) file_name = dialog->GetPath().c_str().AsWChar();
  return result;
}

void file_dialog::run_save_sheet(xtd::delegate<void(bool)> on_dialog_closed, intptr_t hwnd, const ustring& default_ext, ustring& file_name, std::vector<ustring>& file_names, const ustring& filter, size_t filter_index, const ustring& initial_directory, size_t options, bool support_multi_dotted_extensions, const ustring& title) {
  wxWindowPtr<FileDialog> dialog(create_file_dialog(hwnd, false, default_ext, file_name, file_names, filter, filter_index, initial_directory, options, support_multi_dotted_extensions, title));
  dialog->Bind(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, [dialog, on_dialog_closed, &file_name](wxWindowModalDialogEvent& event) {
    auto result = event.GetReturnCode() == wxID_OK;
    if (result) file_name = dialog->GetPath().c_str().AsWChar();
    on_dialog_closed(result);
  });
  dialog->ShowWindowModal();
}
