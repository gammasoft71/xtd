#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.h"
#include <xtd/forms/native/font_dialog>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/choose_font_flags>
#include <wx/fontdlg.h>

using namespace xtd;
using namespace xtd::forms::native;

#if defined(__WXMSW__)
namespace {
  HHOOK handle_hook;
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
#endif

bool font_dialog::run_dialog(intptr hwnd, drawing::font& font, drawing::color& color, size_t options, size_t min_size, size_t max_size, bool show_color) {
  wxFontData font_data;
  font_data.SetColour(wxColour(color.r(), color.g(), color.b(), color.a()));
  font_data.SetInitialFont(*reinterpret_cast<wxFont*>(font.handle()));
  font_data.SetRange(static_cast<int32>(min_size), static_cast<int32>(max_size));
  font_data.SetShowHelp((options & CF_SHOWHELP) == CF_SHOWHELP);
  #if defined(__WXMSW__)
  handle_hook = SetWindowsHookExW(WH_CBT, &callbackProc, 0, GetCurrentThreadId());
  #endif
  wxFontDialog dialog(hwnd == 0 ? nullptr : reinterpret_cast<control_handler*>(hwnd)->control(), font_data);
  dialog.SetParent(hwnd == 0 ? nullptr : reinterpret_cast<control_handler*>(hwnd)->control());
  if (dialog.ShowModal() != wxID_OK) return false;
  font = drawing::font(reinterpret_cast<intptr>(new wxFont(dialog.GetFontData().GetChosenFont())));
  wxColour colour = dialog.GetFontData().GetColour();
  color = drawing::color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
  return true;
}

void font_dialog::run_sheet(xtd::delegate<void(bool)> on_dialog_closed, intptr hwnd, drawing::font& font, drawing::color& color, size_t options, size_t min_size, size_t max_size, bool show_color) {
  on_dialog_closed(run_dialog(hwnd, font, color, options, min_size, max_size, show_color));
}
