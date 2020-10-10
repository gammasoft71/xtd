#include <codecvt>
#include <stdexcept>
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/message_box.h>
#include <xtd/forms/native/message_box_styles.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.h"
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

int32_t message_box::show(intptr_t control, const std::string& text, const std::string& caption, uint32_t style, bool displayHelpButton) {
#pragma warning(push)
#pragma warning(suppress:4996)
  handle_hook = SetWindowsHookExW(WH_CBT, &callbackProc, 0, GetCurrentThreadId());
  return MessageBoxW(control == 0 ? nullptr : reinterpret_cast<control_handler*>(control)->control()->GetHandle(), std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().from_bytes(text.c_str()).c_str(), std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().from_bytes(caption.c_str()).c_str(), style + (displayHelpButton ? 0x00004000L : 0));
#pragma warning(pop)
}
//#elif !defined(__APPLE__)
#else
namespace {
  constexpr int32_t MB_BUTTONS_MASK = 0xF;
  constexpr int32_t MB_ICON_MASK = 0xF0;
}

namespace {
  int32_t convert_to_dialog_result(int32_t wx_result, uint32_t style) {
    switch (wx_result) {
      case wxID_OK: return (style & MB_BUTTONS_MASK) == MB_RETRYCANCEL ? IDRETRY : IDOK;
      case wxID_CANCEL: return (style & MB_BUTTONS_MASK) == MB_ABORTRETRYIGNORE ? IDIGNORE : (style & MB_BUTTONS_MASK) == MB_YESNO ? IDNO : (style & MB_BUTTONS_MASK) == MB_OK ? IDOK : IDCANCEL;
      case wxID_YES: return (style & MB_BUTTONS_MASK) == MB_ABORTRETRYIGNORE ? IDABORT : IDYES;
      case wxID_NO: return (style & MB_BUTTONS_MASK) == MB_ABORTRETRYIGNORE ? IDRETRY : IDNO;
    }
    return IDOK;
  }
  
  int32_t convert_to_buttons(uint32_t style) {
    if ((style & MB_BUTTONS_MASK) == MB_RETRYCANCEL) return wxOK | wxCANCEL;
    if ((style & MB_BUTTONS_MASK) == MB_YESNOCANCEL) return wxYES_NO | wxCANCEL;
    if ((style & MB_BUTTONS_MASK) == MB_YESNO) return wxYES_NO;
    if ((style & MB_BUTTONS_MASK) == MB_ABORTRETRYIGNORE) return wxYES_NO | wxCANCEL;
    if ((style & MB_BUTTONS_MASK) == MB_OKCANCEL)return wxOK | wxCANCEL;
    return wxOK;
  }
  
  int32_t convert_to_icon(uint32_t style) {
    if ((style & MB_ICON_MASK) == MB_ICONINFORMATION) return wxICON_INFORMATION;
    if ((style & MB_ICON_MASK) == MB_ICONEXCLAMATION) return wxICON_EXCLAMATION;
    if ((style & MB_ICON_MASK) == MB_ICONQUESTION) return wxICON_QUESTION;
    if ((style & MB_ICON_MASK) == MB_ICONSTOP) return wxICON_STOP;
    return wxICON_NONE;
  }
  
  int32_t convert_to_option(uint32_t style) {
    int32_t option = 0;
    if ((style & MB_RIGHT) == MB_RIGHT) option = wxRIGHT;
    return option;
  }
  
  void set_button_labels(wxMessageDialog& dialog, uint32_t style) {
    if ((style & MB_BUTTONS_MASK) == MB_RETRYCANCEL) dialog.SetOKCancelLabels("Retry", wxID_CANCEL);
    if ((style & MB_BUTTONS_MASK) == MB_YESNOCANCEL) dialog.SetYesNoCancelLabels("Yes", "No", wxID_CANCEL);
    if ((style & MB_BUTTONS_MASK) == MB_ABORTRETRYIGNORE) dialog.SetYesNoCancelLabels("Abort", "Retry", "Ignore");
  }
}

int32_t message_box::show(intptr_t control, const std::string& text, const std::string& caption, uint32_t style, bool display_help_button) {
  native::application::initialize(); // Must be first
  wxMessageDialog dialog(control == 0 ? nullptr : reinterpret_cast<control_handler*>(control)->control(), {text.c_str(), wxMBConvUTF8()}, {caption.c_str(), wxMBConvUTF8()}, convert_to_buttons(style) + convert_to_icon(style) + convert_to_option(style) + (display_help_button ? wxHELP : 0));
  set_button_labels(dialog, style);
#if !defined(__APPLE__)
  return convert_to_dialog_result(dialog.ShowModal(), style);
#else
  if (!control) return convert_to_dialog_result(dialog.ShowModal(), style);
  int32_t result = wxID_ANY;
  dialog.Bind(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, [&](wxWindowModalDialogEvent& event) {
    result = event.GetReturnCode();
  });
  dialog.SetParent(reinterpret_cast<control_handler*>(control)->control());
  dialog.ShowWindowModal();
  while (result == wxID_ANY)
    wxYield();
  return convert_to_dialog_result(result, style);
#endif
}

#endif

void message_box::show_sheet(xtd::delegate<void(int)> on_message_box_closed, intptr_t control, const std::string& text, const std::string& caption, uint32_t style, bool display_help_button) {
  native::application::initialize(); // Must be first
#if !defined(__APPLE__)
  on_message_box_closed(show(control, text, caption, style, display_help_button));
#else
  if (!control) return on_message_box_closed(show(control, text, caption, style, display_help_button));
  wxWindowPtr<wxMessageDialog> dialog(new wxMessageDialog(control == 0 ? nullptr : reinterpret_cast<control_handler*>(control)->control(), {text.c_str(), wxMBConvUTF8()}, {caption.c_str(), wxMBConvUTF8()}, convert_to_buttons(style) + convert_to_icon(style) + convert_to_option(style) + (display_help_button ? wxHELP : 0)));
  set_button_labels(*dialog, style);
  int32_t result = wxID_ANY;
  dialog->Bind(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, [on_message_box_closed, dialog, style](wxWindowModalDialogEvent& event) {
    on_message_box_closed(convert_to_dialog_result(event.GetReturnCode(), style));
  });
  dialog->SetParent(reinterpret_cast<control_handler*>(control)->control());
  dialog->ShowWindowModal();
#endif
}
