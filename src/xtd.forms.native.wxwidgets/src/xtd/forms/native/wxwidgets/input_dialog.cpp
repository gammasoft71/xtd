#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.hpp"
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.hpp"
#include <xtd/forms/native/application>
#include <xtd/forms/native/dialog_box_identifiers>
#include <xtd/forms/native/input_dialog>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/system_colors>
#include <xtd/convert_string>
#include <wx/textdlg.h>
#include <wx/windowptr.h>

using namespace xtd;
using namespace xtd::forms::native;

namespace {
  #if defined(__WXMSW__)
  auto handle_hook = HHOOK {};
  LRESULT CALLBACK callbackProc(INT ncode, WPARAM wparam, LPARAM lparam) {
    if (ncode == HCBT_ACTIVATE) {
      allow_dark_mode_for_window(static_cast<intptr>(wparam));
      refresh_title_bar_theme_color(static_cast<intptr>(wparam));
      UnhookWindowsHookEx(handle_hook);
    } else
      CallNextHookEx(handle_hook, ncode, wparam, lparam);
    return 0;
  }
  #endif
  
  wxTextEntryDialog* create_text_entry_dialog(intptr control, const string& text, const string& message, string& value, int32 character_casing, bool multiline, bool use_system_password_char) {
    #if defined(__WXMSW__)
    handle_hook = SetWindowsHookExW(WH_CBT, &callbackProc, 0, GetCurrentThreadId());
    #endif
    int32 style = wxTextEntryDialogStyle;
    if (multiline) style |= wxTE_MULTILINE;
    if (use_system_password_char) style |= wxTE_PASSWORD;
    wxTextEntryDialog* text_entry_dialog = new wxTextEntryDialog(control == 0 ? nullptr : reinterpret_cast<control_handler*>(control)->control(), message == "" ? L" " : convert_string::to_wstring(message).c_str(), convert_string::to_wstring(text).c_str(), convert_string::to_wstring(value).c_str(), style);
    if (character_casing == 1) text_entry_dialog->ForceUpper();
    
    #if defined(__WXMSW__)
    // Idem : if (application::dark_mode_enabled()) {
    if (drawing::system_colors::window().get_lightness() < 0.5) {
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

bool input_dialog::run_dialog(intptr control, const string& text, const string& message, string& value, int32 character_casing, bool multiline, bool use_system_password_char, bool word_wrap) {
  wxWindowPtr<wxTextEntryDialog> text_entry_dialog(create_text_entry_dialog(control, text, message, value, character_casing, multiline, use_system_password_char));
  int32 result = text_entry_dialog->ShowModal() == wxID_OK ? IDOK : IDCANCEL;
  if (result == IDCANCEL) return false;
  
  if (character_casing == 1) value = text_entry_dialog->GetValue().Upper().c_str().AsWChar();
  else if (character_casing == 2) value = text_entry_dialog->GetValue().Lower().c_str().AsWChar();
  else value = text_entry_dialog->GetValue().c_str().AsChar();
  return true;
}

void input_dialog::run_sheet(xtd::delegate<void(bool)> on_dialog_closed, intptr control, const string& text, const string& message, string& value, int32 character_casing, bool multiline, bool use_system_password_char, bool word_wrap) {
  //wxWindowPtr<wxTextEntryDialog> text_entry_dialog(create_text_entry_dialog(control, text, message, value, character_casing, multiline, use_system_password_char, word_wrap));
  wxTextEntryDialog* text_entry_dialog(create_text_entry_dialog(control, text, message, value, character_casing, multiline, use_system_password_char));
  text_entry_dialog->Bind(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, [text_entry_dialog, on_dialog_closed, &value, character_casing](wxWindowModalDialogEvent & event) {
    auto result = event.GetReturnCode() == wxID_OK;
    if (result) {
      if (character_casing == 1) value = text_entry_dialog->GetValue().Upper().c_str().AsWChar();
      else if (character_casing == 2) value = text_entry_dialog->GetValue().Lower().c_str().AsWChar();
      else value = text_entry_dialog->GetValue().c_str().AsWChar();
    }
    on_dialog_closed(result);
    text_entry_dialog->Destroy();
  });
  text_entry_dialog->ShowWindowModal();
}
