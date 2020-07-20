#include <xtd/drawing/system_colors.h>
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/input_box.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.h"
#include <wx/textdlg.h>

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
    }
    else
      CallNextHookEx(handle_hook, ncode, wparam, lparam);
    return 0;
  }
}
#endif

bool input_box::run_dialog(intptr_t hwnd, const std::string& text, const std::string& caption, std::string& value, bool multiline, bool use_system_password_char) {
#if defined(__WXMSW__)
  handle_hook = SetWindowsHookExW(WH_CBT, &callbackProc, 0, GetCurrentThreadId());
#endif
  int style = wxTextEntryDialogStyle;
  if (multiline) style |= wxTE_MULTILINE;
  if (use_system_password_char) style |= wxTE_PASSWORD;
  wxTextEntryDialog text_entry_dialog(reinterpret_cast<wxWindow*>(hwnd), text == "" ? " " : text, caption, value, style);
  
#if defined(__WXMSW__)
  if (application::dark_mode_enabled()) {
    text_entry_dialog.SetBackgroundColour({xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b()});
    for (auto child : text_entry_dialog.GetChildren()) {
      auto back_color = dynamic_cast<wxTextEntry*>(child) ? xtd::drawing::system_colors::window() : xtd::drawing::system_colors::control();
      auto fore_color = dynamic_cast<wxTextEntry*>(child) ? xtd::drawing::system_colors::window_text() : xtd::drawing::system_colors::control_text();
      child->SetBackgroundColour({back_color.r(), back_color.g(), back_color.b()});
      child->SetForegroundColour({fore_color.r(), fore_color.g(), fore_color.b()});
    }
  }
#endif
  if (text_entry_dialog.ShowModal() != wxID_OK) return false;
  value = text_entry_dialog.GetValue();
  return true;
}
