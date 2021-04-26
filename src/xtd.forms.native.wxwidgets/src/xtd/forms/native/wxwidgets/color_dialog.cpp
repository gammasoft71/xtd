#include <xtd/forms/native/color_dialog.h>
#include <xtd/forms/choose_color_flags.h>
#include <wx/colordlg.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
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

bool color_dialog::run_dialog(intptr_t hwnd, drawing::color& color, std::optional<std::vector<uint32_t>>& custom_colors, size_t options) {
  wxColourData color_data;
  color_data.SetChooseAlpha((options & CC_ALPHACOLOR) == CC_ALPHACOLOR);
  color_data.SetChooseFull((options & CC_FULLOPEN) == CC_FULLOPEN);
  color_data.SetColour(wxColour(color.r(), color.g(), color.b(), color.a()));
  if (custom_colors.has_value()) {
    size_t max_index = custom_colors.value().size() > 16 ? 16 : custom_colors.value().size();
    for(size_t index = 0; index < max_index; ++index) {
      xtd::drawing::color custom_color = xtd::drawing::color::from_argb(custom_colors.value()[index]);
      color_data.SetCustomColour(static_cast<int32_t>(index), wxColour(custom_color.r(), custom_color.g(), custom_color.b(), custom_color.a()));
    }
  }
#if defined(__WXMSW__)
  handle_hook = SetWindowsHookExW(WH_CBT, &callbackProc, 0, GetCurrentThreadId());
#endif
  wxColourDialog dialog(hwnd == 0 ? nullptr : reinterpret_cast<control_handler*>(hwnd)->control(), &color_data);
  dialog.SetParent(hwnd == 0 ? nullptr : reinterpret_cast<control_handler*>(hwnd)->control());
  if (dialog.ShowModal() != wxID_OK) return false;
  wxColour colour = dialog.GetColourData().GetColour();
  color = drawing::color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
  std::vector<int32_t> colors;
  if (custom_colors.has_value()) {
    size_t max_index = custom_colors.value().size() > 16 ? 16 : custom_colors.value().size();
    for(size_t index = 0; index < max_index; ++index) {
      xtd::drawing::color custom_color = xtd::drawing::color::from_argb(color_data.GetCustomColour(static_cast<int32_t>(index)).Alpha(), color_data.GetCustomColour(static_cast<int32_t>(index)).Red(), color_data.GetCustomColour(static_cast<int32_t>(index)).Green(), color_data.GetCustomColour(static_cast<int32_t>(index)).Blue());
      custom_colors.value()[index] = custom_color.to_argb();
    }
  }
  return true;
}

void color_dialog::run_sheet(xtd::delegate<void(bool)> on_dialog_closed, intptr_t hwnd, drawing::color& color, std::optional<std::vector<uint32_t>>& custom_colors, size_t options) {
  on_dialog_closed(run_dialog(hwnd, color, custom_colors, options));
}
