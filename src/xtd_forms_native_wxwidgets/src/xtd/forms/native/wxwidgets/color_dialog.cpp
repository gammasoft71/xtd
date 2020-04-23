#include <xtd/forms/native/color_dialog.h>
#include <xtd/forms/color_dialog_flags.h>
#include <wx/colordlg.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.h"

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

bool color_dialog::run_dialog(intptr_t hwnd, drawing::color& color, std::optional<std::vector<int32_t>>& custom_colors, size_t options) {
  wxColourData color_data;
#if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
  color_data.SetChooseAlpha((options & CC_ALPHACOLOR) == CC_ALPHACOLOR);
#endif
  color_data.SetChooseFull((options & CC_FULLOPEN) == CC_FULLOPEN);
  color_data.SetColour(wxColour(color.r(), color.g(), color.b(), color.a()));
  if (custom_colors.has_value()) {
    size_t max_index = custom_colors.value().size() > 16 ? 16 : custom_colors.value().size();
    for(size_t index = 0; index < max_index; ++index)
      color_data.SetCustomColour(index, wxColour(custom_colors.value()[index]));
  }
#if defined(__WXMSW__)
  //handle_hook = SetWindowsHookExW(WH_CBT, &callbackProc, 0, GetCurrentThreadId());
#endif
  wxColourDialog dialog(reinterpret_cast<wxWindow*>(hwnd), &color_data);
  if (dialog.ShowModal() != wxID_OK) return false;
  wxColour colour = dialog.GetColourData().GetColour();
  color = drawing::color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
  std::vector<int32_t> colors;
  if (custom_colors.has_value()) {
    size_t max_index = custom_colors.value().size() > 16 ? 16 : custom_colors.value().size();
    for(size_t index = 0; index < max_index; ++index)
      custom_colors.value()[index] = color_data.GetCustomColour(index).GetRGB();
  }
  return true;
}
