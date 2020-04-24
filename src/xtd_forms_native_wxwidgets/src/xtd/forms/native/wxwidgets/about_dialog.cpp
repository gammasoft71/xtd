#include <xtd/forms/native/about_dialog.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.h"
#include <wx/aboutdlg.h>

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

bool about_dialog::run_dialog(intptr_t hwnd, const std::string& name, const std::string& description, const std::string& version, const std::string& long_version, const std::string& copyright) {
  wxAboutDialogInfo about_info;
  about_info.SetName(name);
  about_info.SetDescription(description);
  about_info.SetVersion(version, long_version);
  about_info.SetCopyright(copyright);
#if defined(__WXMSW__)
  handle_hook = SetWindowsHookExW(WH_CBT, &callbackProc, 0, GetCurrentThreadId());
#endif
  wxAboutBox(about_info, hwnd ? reinterpret_cast<control_handler*>(hwnd)->control() : nullptr);
  return true;
}
