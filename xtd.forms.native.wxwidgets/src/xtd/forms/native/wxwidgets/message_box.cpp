#include <stdexcept>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/message_box.hpp>
#include <xtd/forms/native/window_message_box.hpp>
#include "control_handler.hpp"
#include <wx/app.h>
#include <wx/msgdlg.h>

using namespace xtd::forms::native;

#if defined(_WIN32)
int32_t message_box::show(intptr_t control, const std::string& text, const std::string& caption, uint32_t style, bool displayHelpButton) {
  return MessageBoxA(control == 0 ? nullptr : reinterpret_cast<control_handler*>(control)->control()->GetHandle(), text.c_str(), caption.c_str(), style + (displayHelpButton ? 0x00004000L : 0));
}
#else
namespace {
  int32_t convert_to_dialog_result(int32_t wx_result, uint32_t style) {
    switch (wx_result) {
      case wxID_OK: return (style & MB_RETRYCANCEL) == MB_RETRYCANCEL ? IDRETRY : IDOK;
      case wxID_CANCEL: return IDCANCEL;
      case wxID_YES: return (style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE ? IDABORT : IDYES;
      case wxID_NO: return (style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE ? IDRETRY : IDNO;
    }
    return IDOK;
  }
  
  int32_t convert_to_buttons(uint32_t style) {
    if ((style & MB_OKCANCEL) == MB_OKCANCEL)return wxOK | wxCANCEL;
    if ((style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE) return wxYES_NO;
    if ((style & MB_YESNOCANCEL) == MB_YESNOCANCEL) return wxYES_NO | wxCANCEL;
    if ((style & MB_YESNO) == MB_YESNO) return wxYES_NO;
    if ((style & MB_RETRYCANCEL) == MB_RETRYCANCEL) return wxOK | wxCANCEL;
    return wxOK;
  }
  
  int32_t convert_to_icon(uint32_t style) {
    if ((style & MB_ICONSTOP) == MB_ICONSTOP) return wxICON_STOP;
    if ((style & MB_ICONQUESTION) == MB_ICONQUESTION) return wxICON_QUESTION;
    if ((style & MB_ICONEXCLAMATION) == MB_ICONEXCLAMATION) return wxICON_EXCLAMATION;
    if ((style & MB_ICONINFORMATION) == MB_ICONINFORMATION) return wxICON_INFORMATION;
    return wxICON_NONE;
  }
  
  int32_t convert_to_option(uint32_t style) {
    int32_t option = 0;
    if ((style & MB_RIGHT) == MB_RIGHT) option = wxRIGHT;
    return option;
  }
  
  void set_button_labels(wxMessageDialog& dialog, uint32_t style) {
    if ((style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE) dialog.SetYesNoCancelLabels("Abort", "Retry", wxID_IGNORE);
    if ((style & MB_RETRYCANCEL) == MB_RETRYCANCEL) dialog.SetOKCancelLabels("Retry", wxID_CANCEL);
  }
}

int32_t message_box::show(intptr_t control, const std::string& text, const std::string& caption, uint32_t style, bool display_help_button) {
  native::application::initialize(); // Must be first
  wxMessageDialog dialog(control == 0 ? nullptr : reinterpret_cast<control_handler*>(control)->control(), text, caption, convert_to_buttons(style) + convert_to_icon(style) + convert_to_option(style) + (display_help_button ? wxHELP : 0));
  set_button_labels(dialog, style);
  return convert_to_dialog_result(dialog.ShowModal(), style);
}
#endif
