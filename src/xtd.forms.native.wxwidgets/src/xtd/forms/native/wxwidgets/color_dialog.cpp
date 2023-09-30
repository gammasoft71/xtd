#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.h"
#include <xtd/forms/native/color_dialog>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/choose_color_flags>
#include <wx/colordlg.h>
#if defined(__WXGTK__)
#undef interface_
#include <gtk/gtk.h>
#endif

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

#if defined(__WXGTK__)
bool color_dialog::run_dialog(intptr hwnd, const xtd::ustring& title, drawing::color& color, std::vector<xtd::drawing::color>& custom_colors, size_t options) {
  auto dialog = gtk_color_chooser_dialog_new(title == "" ? "Color" : title.c_str(), hwnd == 0 ? nullptr : GTK_WINDOW(reinterpret_cast<control_handler*>(hwnd)->control()->GetHandle()));
  gtk_color_chooser_set_use_alpha(GTK_COLOR_CHOOSER(dialog), (options & CC_ALPHACOLOR) == CC_ALPHACOLOR);
  GdkRGBA gdk_rgba {static_cast<double>(color.r()) / 255, static_cast<double>(color.g()) / 255, static_cast<double>(color.b()) / 255, static_cast<double>(color.a()) / 255};
  gtk_color_chooser_set_rgba(GTK_COLOR_CHOOSER(dialog), &gdk_rgba);
  bool result = gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_OK;
  if (result) {
    gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(dialog), &gdk_rgba);
    color = drawing::color::from_argb(gdk_rgba.alpha * 255, gdk_rgba.red * 255, gdk_rgba.green * 255, gdk_rgba.blue * 255);
  }
  gtk_widget_destroy(dialog);
  return result;
}
#else
bool color_dialog::run_dialog(intptr hwnd, const xtd::ustring& title, drawing::color& color, std::vector<xtd::drawing::color>& custom_colors, size_t options) {
  wxColourData color_data;
  color_data.SetChooseAlpha((options & CC_ALPHACOLOR) == CC_ALPHACOLOR);
  color_data.SetChooseFull((options & CC_FULLOPEN) == CC_FULLOPEN);
  color_data.SetColour(wxColour(color.r(), color.g(), color.b(), color.a()));
  for (size_t index = 0; index < custom_colors.size(); ++index)
    color_data.SetCustomColour(static_cast<int32>(index), wxColour(custom_colors[index].r(), custom_colors[index].g(), custom_colors[index].b(), custom_colors[index].a()));
  #if defined(__WXMSW__)
  handle_hook = SetWindowsHookExW(WH_CBT, &callbackProc, 0, GetCurrentThreadId());
  #endif
  wxColourDialog dialog(hwnd == 0 ? nullptr : reinterpret_cast<control_handler*>(hwnd)->control(), &color_data);
  dialog.SetParent(hwnd == 0 ? nullptr : reinterpret_cast<control_handler*>(hwnd)->control());
  dialog.SetTitle(title == "" ? "Color" : title);
  bool result = dialog.ShowModal() == wxID_OK;
  if (result) {
    wxColour colour = dialog.GetColourData().GetColour();
    color = drawing::color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
  }
  for (size_t index = 0; index < custom_colors.size(); ++index) {
    wxColour custom_colour = dialog.GetColourData().GetCustomColour(static_cast<int32>(index));
    custom_colors[index] = xtd::drawing::color::from_argb(custom_colour.Alpha(), custom_colour.Red(), custom_colour.Green(), custom_colour.Blue());
  }
  return result;
}
#endif

void color_dialog::run_sheet(xtd::delegate<void(bool)> on_dialog_closed, intptr hwnd, const xtd::ustring& title, drawing::color& color, std::vector<xtd::drawing::color>& custom_colors, size_t options) {
  on_dialog_closed(run_dialog(hwnd, title, color, custom_colors, options));
}
