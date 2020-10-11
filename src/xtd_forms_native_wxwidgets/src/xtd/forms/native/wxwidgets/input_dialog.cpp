#include <xtd/drawing/system_colors.h>
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/dialog_box_ids.h>
#include <xtd/forms/native/input_dialog.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.h"
#include <wx/textdlg.h>
#include <wx/windowptr.h>

using namespace xtd;
using namespace xtd::forms::native;

namespace {
#if defined(__WXMSW__)
  HHOOK handle_hook;
  LRESULT CALLBACK callbackProc(INT ncode, WPARAM wparam, LPARAM lparam) {
    if (ncode == HCBT_ACTIVATE) {
      allow_dark_mode_for_window(static_cast<intptr_t>(wparam));
      refresh_title_bar_theme_color(static_cast<intptr_t>(wparam));
      UnhookWindowsHookEx(handle_hook);
    }
    else
      CallNextHookEx(handle_hook, ncode, wparam, lparam);
    return 0;
  }
#endif

  wxTextEntryDialog* create_text_entry_dialog(intptr_t control, const std::string& text, const std::string& message, std::string& value, bool multiline, bool use_system_password_char) {
#if defined(__WXMSW__)
    handle_hook = SetWindowsHookExW(WH_CBT, &callbackProc, 0, GetCurrentThreadId());
#endif
    int style = wxTextEntryDialogStyle;
    if (multiline) style |= wxTE_MULTILINE;
    if (use_system_password_char) style |= wxTE_PASSWORD;
    wxTextEntryDialog* text_entry_dialog = new wxTextEntryDialog(control == 0 ? nullptr : reinterpret_cast<control_handler*>(control)->control(), message == "" ? " " : message, text, value, style);
    
#if defined(__WXMSW__)
    if (application::dark_mode_enabled()) {
      text_entry_dialog->SetBackgroundColour({xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b()});
      for (auto child : text_entry_dialog->GetChildren()) {
        auto back_color = dynamic_cast<wxTextEntry*>(child) ? xtd::drawing::system_colors::window() : xtd::drawing::system_colors::control();
        auto fore_color = dynamic_cast<wxTextEntry*>(child) ? xtd::drawing::system_colors::window_text() : xtd::drawing::system_colors::control_text();
        child->SetBackgroundColour({back_color.r(), back_color.g(), back_color.b()});
        child->SetForegroundColour({fore_color.r(), fore_color.g(), fore_color.b()});
      }
    }
#endif
    return text_entry_dialog;
  }
}

int32_t input_dialog::show_dialog(intptr_t control, const std::string& text, const std::string& message, std::string& value, bool multiline, bool use_system_password_char) {
  wxTextEntryDialog* text_entry_dialog = create_text_entry_dialog(control, text, message, value, multiline, use_system_password_char);
  int result = text_entry_dialog->ShowModal() == wxID_OK ? IDOK : IDCANCEL;
  if (result == IDOK) value = text_entry_dialog->GetValue().ToUTF8().data();
  return result;
}

void input_dialog::show_sheet(xtd::delegate<void(int32_t, const std::string&)> on_dialog_closed, intptr_t control, const std::string& text, const std::string& message, std::string& value, bool multiline, bool use_system_password_char) {
  wxTextEntryDialog* text_entry_dialog = create_text_entry_dialog(control, text, message, value, multiline, use_system_password_char);

  text_entry_dialog->Bind(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, [text_entry_dialog, on_dialog_closed, &value](wxWindowModalDialogEvent& event) {
    auto result = event.GetReturnCode() == wxID_OK ? IDOK : IDCANCEL;
    if (result == IDOK) value = text_entry_dialog->GetValue().ToUTF8().data();
    on_dialog_closed(result, text_entry_dialog->GetValue().ToUTF8().data());
    text_entry_dialog->Destroy();
  });
  text_entry_dialog->ShowWindowModal();
}

int32_t input_dialog::show_sheet_dialog(intptr_t control, const std::string& text, const std::string& message, std::string& value, bool multiline, bool use_system_password_char) {
  wxTextEntryDialog* text_entry_dialog = create_text_entry_dialog(control, text, message, value, multiline, use_system_password_char);
  int result = IDNONE;
  
  if (!control) {
    result = text_entry_dialog->ShowModal() == wxID_OK ? IDOK : IDCANCEL;
    if (result == IDOK) value = text_entry_dialog->GetValue().ToUTF8().data();
    return result;
  }
  
  text_entry_dialog->Bind(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, [text_entry_dialog, &result, &value](wxWindowModalDialogEvent& event) {
    result = event.GetReturnCode() == wxID_OK ? IDOK : IDCANCEL;
    if (result == IDOK) value = text_entry_dialog->GetValue().ToUTF8().data();
    text_entry_dialog->Destroy();
  });
  text_entry_dialog->ShowWindowModal();
  while (result == IDNONE)
    wxYield();
  return result;
}
