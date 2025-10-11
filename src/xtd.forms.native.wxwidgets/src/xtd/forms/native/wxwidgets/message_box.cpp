#include <wx/app.h>
#include <wx/msgdlg.h>
#include <wx/windowptr.h>
#undef interface
#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.hpp"
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.hpp"
#include <xtd/forms/native/application>
#include <xtd/forms/native/message_box>
#include <xtd/forms/native/dialog_box_identifiers>
#include <xtd/forms/native/message_box_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/convert_string>
#include <xtd/globalization/translator>

using namespace xtd;
using namespace xtd::forms::native;

#if defined(__WXMSW__)
namespace {
  auto handle_hook = HHOOK{};
  LRESULT CALLBACK callbackProc(INT ncode, WPARAM wparam, LPARAM lparam) {
    if (ncode == HCBT_ACTIVATE) {
      allow_dark_mode_for_window(static_cast<intptr>(wparam));
      refresh_title_bar_theme_color(static_cast<intptr>(wparam));
      UnhookWindowsHookEx(handle_hook);
    } else
      CallNextHookEx(handle_hook, ncode, wparam, lparam);
    return 0;
  }
}

int32 message_box::show(intptr control, const string& text, const string& caption, uint32 style, bool displayHelpButton) {
  handle_hook = SetWindowsHookExW(WH_CBT, &callbackProc, 0, GetCurrentThreadId());
  return MessageBoxW(control == 0 ? ((!control && wxTheApp && wxTheApp->GetTopWindow()) ? wxTheApp->GetTopWindow()->GetHandle() : 0) : reinterpret_cast<control_handler*>(control)->control()->GetHandle(), convert_string::to_wstring(text).chars().c_str(), convert_string::to_wstring(caption).chars().c_str(), style + (displayHelpButton ? 0x00004000L : 0));
}

void message_box::show_sheet(xtd::delegate<void(int32)> on_dialog_closed, intptr control, const string& text, const string& caption, uint32 style, bool display_help_button) {
  on_dialog_closed(show(control, text, caption, style, display_help_button));
}
#elif !defined(__WXOSX__)
namespace {
  int32 convert_to_dialog_result(int32 wx_result, uint32 style) {
    switch (wx_result) {
      case wxID_OK: return (style & MB_RETRYCANCEL) == MB_RETRYCANCEL ? IDRETRY : IDOK;
      case wxID_CANCEL: return (style & MB_YESNOCANCEL) == MB_YESNOCANCEL ? IDCANCEL : (style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE ? IDIGNORE : (style & MB_RETRYCANCEL) == MB_RETRYCANCEL ? IDCANCEL : (style & MB_YESNO) == MB_YESNO ? IDNO : IDCANCEL;
      case wxID_YES: return (style & MB_YESNOCANCEL) == MB_YESNOCANCEL ? IDYES : (style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE ? IDABORT : IDYES;
      case wxID_NO: return (style & MB_YESNOCANCEL) == MB_YESNOCANCEL ? IDNO : (style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE ? IDRETRY : IDNO;
    }
    return IDOK;
  }
  
  int32 convert_to_buttons(uint32 style) {
    if ((style & MB_RETRYCANCEL) == MB_RETRYCANCEL) return wxOK | wxCANCEL;
    if ((style & MB_YESNOCANCEL) == MB_YESNOCANCEL) return wxYES_NO | wxCANCEL;
    if ((style & MB_YESNO) == MB_YESNO) return wxYES_NO;
    if ((style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE) return wxYES_NO | wxCANCEL;
    if ((style & MB_OKCANCEL) == MB_OKCANCEL)return wxOK | wxCANCEL;
    return wxOK;
  }
  
  int32 convert_to_icon(uint32 style) {
    if ((style & MB_ICONINFORMATION) == MB_ICONINFORMATION) return wxICON_INFORMATION;
    if ((style & MB_ICONEXCLAMATION) == MB_ICONEXCLAMATION) return wxICON_EXCLAMATION;
    if ((style & MB_ICONQUESTION) == MB_ICONQUESTION) return wxICON_QUESTION;
    if ((style & MB_ICONSTOP) == MB_ICONSTOP) return wxICON_STOP;
    return wxICON_NONE;
  }
  
  int32 convert_to_option(uint32 style) {
    int32 option = 0;
    if ((style & MB_RIGHT) == MB_RIGHT) option = wxRIGHT;
    return option;
  }
  
  void set_button_labels(wxMessageDialog& dialog, uint32 style) {
    if ((style & MB_RETRYCANCEL) == MB_RETRYCANCEL) dialog.SetOKCancelLabels("Retry"_t, "Cancel"_t);
    if ((style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE) dialog.SetYesNoCancelLabels("Abort"_t, "Retry"_t, "Ignore"_t);
    if ((style & MB_YESNOCANCEL) == MB_YESNOCANCEL) dialog.SetYesNoCancelLabels("Yes"_t, "No"_t, "Cancel"_t);
  }
}

int32 message_box::show(intptr control, const string& text, const string& caption, uint32 style, bool display_help_button) {
  native::application::initialize(); // Must be first
  wxMessageDialog dialog(control == 0 ? nullptr : reinterpret_cast<control_handler*>(control)->control(), convert_string::to_wstring(text).chars().c_str(), xtd::convert_string::to_wstring(caption).chars().c_str(), convert_to_buttons(style) + convert_to_icon(style) + convert_to_option(style) + (display_help_button ? wxHELP : 0));
  set_button_labels(dialog, style);
  return convert_to_dialog_result(dialog.ShowModal(), style);
}

void message_box::show_sheet(xtd::delegate<void(int32)> on_dialog_closed, intptr control, const string& text, const string& caption, uint32 style, bool display_help_button) {
  native::application::initialize(); // Must be first
  on_dialog_closed(show(control, text, caption, style, display_help_button));
}
#endif
