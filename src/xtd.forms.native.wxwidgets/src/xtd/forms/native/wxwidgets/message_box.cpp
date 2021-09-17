#include <codecvt>
#include <stdexcept>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/message_box.h>
#include <xtd/forms/native/dialog_box_identifiers.h>
#include <xtd/forms/native/message_box_styles.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/convert_string.h>
#include <wx/app.h>
#include <wx/msgdlg.h>
#include <wx/windowptr.h>

using namespace xtd;
using namespace xtd::forms::native;

#if defined(__WXMSW__)
namespace {
  HHOOK handle_hook;
  LRESULT CALLBACK callbackProc(INT ncode, WPARAM wparam, LPARAM lparam) {
    if (ncode == HCBT_ACTIVATE) {
      allow_dark_mode_for_window(static_cast<intptr_t>(wparam));
      refresh_title_bar_theme_color(static_cast<intptr_t>(wparam));
      UnhookWindowsHookEx(handle_hook);
    } else
      CallNextHookEx(handle_hook, ncode, wparam, lparam);
    return 0;
  }
}

int32_t message_box::show(intptr_t control, const ustring& text, const ustring& caption, uint32_t style, bool displayHelpButton) {
  handle_hook = SetWindowsHookExW(WH_CBT, &callbackProc, 0, GetCurrentThreadId());
  return MessageBoxW(control == 0 ? ((!control && wxTheApp && wxTheApp->GetTopWindow()) ? wxTheApp->GetTopWindow()->GetHandle() : 0) : reinterpret_cast<control_handler*>(control)->control()->GetHandle(), convert_string::to_wstring(text).c_str(), convert_string::to_wstring(caption).c_str(), style + (displayHelpButton ? 0x00004000L : 0));
}

void message_box::show_sheet(xtd::delegate<void(int)> on_dialog_closed, intptr_t control, const ustring& text, const ustring& caption, uint32_t style, bool display_help_button) {
  on_dialog_closed(show(control, text, caption, style, display_help_button));
}
#elif !defined(__APPLE__)
namespace {
  int32_t convert_to_dialog_result(int32_t wx_result, uint32_t style) {
    switch (wx_result) {
      case wxID_OK: return (style & MB_RETRYCANCEL) == MB_RETRYCANCEL ? IDRETRY : IDOK;
      case wxID_CANCEL: return (style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE ? IDIGNORE : (style & MB_YESNO) == MB_YESNO ? IDNO : (style & MB_OK) == MB_OK ? IDOK : IDCANCEL;
      case wxID_YES: return (style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE ? IDABORT : IDYES;
      case wxID_NO: return (style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE ? IDRETRY : IDNO;
    }
    return IDOK;
  }
  
  int32_t convert_to_buttons(uint32_t style) {
    if ((style & MB_RETRYCANCEL) == MB_RETRYCANCEL) return wxOK|wxCANCEL;
    if ((style & MB_YESNOCANCEL) == MB_YESNOCANCEL) return wxYES_NO|wxCANCEL;
    if ((style & MB_YESNO) == MB_YESNO) return wxYES_NO;
    if ((style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE) return wxYES_NO|wxCANCEL;
    if ((style & MB_OKCANCEL) == MB_OKCANCEL)return wxOK|wxCANCEL;
    return wxOK;
  }
  
  int32_t convert_to_icon(uint32_t style) {
    if ((style & MB_ICONINFORMATION) == MB_ICONINFORMATION) return wxICON_INFORMATION;
    if ((style & MB_ICONEXCLAMATION) == MB_ICONEXCLAMATION) return wxICON_EXCLAMATION;
    if ((style & MB_ICONQUESTION) == MB_ICONQUESTION) return wxICON_QUESTION;
    if ((style & MB_ICONSTOP) == MB_ICONSTOP) return wxICON_STOP;
    return wxICON_NONE;
  }
  
  int32_t convert_to_option(uint32_t style) {
    int32_t option = 0;
    if ((style & MB_RIGHT) == MB_RIGHT) option = wxRIGHT;
    return option;
  }
  
  void set_button_labels(wxMessageDialog& dialog, uint32_t style) {
    if ((style & MB_RETRYCANCEL) == MB_RETRYCANCEL) dialog.SetOKCancelLabels("Retry", wxID_CANCEL);
    if ((style & MB_YESNOCANCEL) == MB_YESNOCANCEL) dialog.SetYesNoCancelLabels("Yes", "No", wxID_CANCEL);
    if ((style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE) dialog.SetYesNoCancelLabels("Abort", "Retry", "Ignore");
  }
}

int32_t message_box::show(intptr_t control, const ustring& text, const ustring& caption, uint32_t style, bool display_help_button) {
  native::application::initialize(); // Must be first
  wxMessageDialog dialog(control == 0 ? nullptr : reinterpret_cast<control_handler*>(control)->control(), convert_string::to_wstring(text), xtd::convert_string::to_wstring(caption), convert_to_buttons(style) + convert_to_icon(style) + convert_to_option(style) + (display_help_button ? wxHELP : 0));
  set_button_labels(dialog, style);
  return convert_to_dialog_result(dialog.ShowModal(), style);
}

void message_box::show_sheet(xtd::delegate<void(int32_t)> on_dialog_closed, intptr_t control, const ustring& text, const ustring& caption, uint32_t style, bool display_help_button) {
  native::application::initialize(); // Must be first
  on_dialog_closed(show(control, text, caption, style, display_help_button));
}
#endif
