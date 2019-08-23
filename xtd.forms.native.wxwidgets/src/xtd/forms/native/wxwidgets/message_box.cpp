#include <stdexcept>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/message_box.hpp>
#include <xtd/forms/native/window_message_box.hpp>
#include "control_handler.hpp"
#include <wx/msgdlg.h>

using namespace xtd::forms::native;

namespace {
  int32_t convert_to_dialog_result(int32_t wx_result, uint32_t style) {
    int32_t dialog_result = IDOK;
    switch (wx_result) {
      case wxID_OK: dialog_result = (style & MB_RETRYCANCEL) == MB_RETRYCANCEL ? IDRETRY : IDOK; break;
      case wxID_CANCEL: dialog_result = IDCANCEL; break;
      case wxID_YES: dialog_result = (style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE ? IDABORT : IDYES; break;
      case wxID_NO: dialog_result = (style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE ? IDRETRY : IDNO; break;
      default: break;
    }
    return dialog_result;
  }
  
  int32_t convert_to_buttons(uint32_t style) {
    int32_t buttons = wxOK;
    if ((style & MB_OKCANCEL) == MB_OKCANCEL) buttons = wxOK | wxCANCEL;
    if ((style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE) buttons = wxYES_NO;
    if ((style & MB_YESNOCANCEL) == MB_YESNOCANCEL) buttons = wxYES_NO | wxCANCEL;
    if ((style & MB_YESNO) == MB_YESNO) buttons = wxYES_NO;
    if ((style & MB_RETRYCANCEL) == MB_RETRYCANCEL) buttons = wxOK | wxCANCEL;
    return buttons;
  }
  
  int32_t convert_to_icon(uint32_t style) {
    int32_t icon = wxICON_NONE;
    if ((style & MB_ICONSTOP) == MB_ICONSTOP) icon = wxICON_STOP;
    if ((style & MB_ICONQUESTION) == MB_ICONQUESTION) icon = wxICON_QUESTION;
    if ((style & MB_ICONEXCLAMATION) == MB_ICONEXCLAMATION) icon = wxICON_EXCLAMATION;
    if ((style & MB_ICONINFORMATION) == MB_ICONINFORMATION) icon = wxICON_INFORMATION;
    return icon;
  }
  
  int32_t convert_to_option(uint32_t style) {
    int32_t option = 0;
    if ((style & MB_RIGHT) == MB_RIGHT) option = wxRIGHT;
    return option;
  }

  void set_button_labels(wxMessageDialog&dialog, uint32_t style) {
    if ((style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE) dialog.SetYesNoCancelLabels("Abort", "Retry", wxID_IGNORE);
    if ((style & MB_RETRYCANCEL) == MB_RETRYCANCEL) dialog.SetOKCancelLabels("Retry", wxID_CANCEL);
  }
}

int32_t message_box::show(intptr_t hwnd, const std::string& text, const std::string& caption, uint32_t style, bool display_help_button) {
  native::application::initialize_application();
  wxMessageDialog dialog(hwnd == 0 ? nullptr : reinterpret_cast<control_handler*>(hwnd)->control(), text, caption, convert_to_buttons(style) + convert_to_icon(style) + convert_to_option(style) + (display_help_button ? wxHELP : 0));
  set_button_labels(dialog, style);
  return convert_to_dialog_result(dialog.ShowModal(), style);
}
