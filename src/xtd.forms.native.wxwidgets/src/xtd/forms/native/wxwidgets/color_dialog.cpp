#include <xtd/forms/choose_color_flags.h>
#include <wx/colordlg.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/color_dialog.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

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

bool color_dialog::run_dialog(intptr_t hwnd, drawing::color& color, std::vector<xtd::drawing::color>& custom_colors, size_t options) {
  wxColourData color_data;
  color_data.SetChooseAlpha((options & CC_ALPHACOLOR) == CC_ALPHACOLOR);
  color_data.SetChooseFull((options & CC_FULLOPEN) == CC_FULLOPEN);
  color_data.SetColour(wxColour(color.r(), color.g(), color.b(), color.a()));
  for(size_t index = 0; index < custom_colors.size(); ++index) {
    color_data.SetCustomColour(static_cast<int32_t>(index), wxColour(custom_colors[index].r(), custom_colors[index].g(), custom_colors[index].b(), custom_colors[index].a()));
  }
#if defined(__WXMSW__)
  handle_hook = SetWindowsHookExW(WH_CBT, &callbackProc, 0, GetCurrentThreadId());
#endif
  wxColourDialog dialog(hwnd == 0 ? nullptr : reinterpret_cast<control_handler*>(hwnd)->control(), &color_data);
  dialog.SetParent(hwnd == 0 ? nullptr : reinterpret_cast<control_handler*>(hwnd)->control());
  bool result = dialog.ShowModal() == wxID_OK;
  if (result) {
    wxColour colour = dialog.GetColourData().GetColour();
    color = drawing::color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
  }
  for(size_t index = 0; index < custom_colors.size(); ++index) {
    wxColour custom_colour = dialog.GetColourData().GetCustomColour(static_cast<int32_t>(index));
    custom_colors[index] = xtd::drawing::color::from_argb(custom_colour.Alpha(), custom_colour.Red(), custom_colour.Green(), custom_colour.Blue());
  }
  return result;
}

void color_dialog::run_sheet(xtd::delegate<void(bool)> on_dialog_closed, intptr_t hwnd, drawing::color& color, std::vector<xtd::drawing::color>& custom_colors, size_t options) {
  on_dialog_closed(run_dialog(hwnd, color, custom_colors, options));
}
