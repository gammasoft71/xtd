#include <xtd/drawing/native/system_colors.h>
#include <wx/settings.h>

#include <cstdint>
#include <map>
#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/textctrl.h>

#if defined(__WXMSW__)
#include <Windows.h>
int __xtd_win32_enable_dark_mode__ = -1;
#endif

#if defined(__APPLE__)
intptr_t __xtd__macos_system_colors_accent_control__();
intptr_t __xtd__macos_system_colors_button_face__();
intptr_t __xtd__macos_system_colors_button_text__();
intptr_t __xtd__macos_system_colors_control__();
intptr_t __xtd__macos_system_colors_control_text__();
#endif

using namespace xtd::drawing::native;

namespace {
  bool dark_mode() {
#if defined(__WXMSW__)
    DWORD value = 0, value_size = sizeof(value);
    if (RegGetValue(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", L"AppsUseLightTheme", RRF_RT_REG_DWORD, nullptr, &value, &value_size) == ERROR_SUCCESS)
      return __xtd_win32_enable_dark_mode__ != 0 && (value == 0 || __xtd_win32_enable_dark_mode__ == 1);
#endif
    return false;
  }

  uint32_t to_argb(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue) {
    return (alpha << 24) + (red << 16) + (green << 8) + blue;
  }

  uint32_t to_argb(const wxColour color) {
    return ::to_argb(color.Alpha(), color.Red(), color.Green(), color.Blue());
  }
}

bool system_colors::force_set_system_color() {
  return ::dark_mode();
}

uint32_t system_colors::to_argb(intptr_t color) {
  return static_cast<uint32_t>(color);
}

intptr_t system_colors::accent() {
  if (::dark_mode()) return ::to_argb(255, 154, 154, 154);
#if defined(__APPLE__)
  return __xtd__macos_system_colors_accent_control__();
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUHILIGHT));
#endif
}

intptr_t system_colors::active_border() {
  if (::dark_mode()) return ::to_argb(255, 154, 154, 154);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVEBORDER));
}

intptr_t system_colors::active_caption() {
  if (::dark_mode()) return ::to_argb(255, 154, 154, 154);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVECAPTION));
}

intptr_t system_colors::active_caption_text() {
  if (::dark_mode()) return ::to_argb(255, 255, 255, 255);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_CAPTIONTEXT));
}

intptr_t system_colors::app_workspace() {
  if (::dark_mode()) return ::to_argb(255, 38, 38, 38);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_APPWORKSPACE));
}

intptr_t system_colors::button_face() {
  if (::dark_mode()) return ::to_argb(255, 38, 38, 38);
#if defined(__APPLE__)
  return __xtd__macos_system_colors_button_face__();
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
#endif
}

intptr_t system_colors::button_highlight() {
  if (::dark_mode()) return ::to_argb(255, 74, 74, 74);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT));
}

intptr_t system_colors::button_shadow() {
  if (::dark_mode()) return ::to_argb(255, 35, 35, 35);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW));
}

intptr_t system_colors::control() {
  if (::dark_mode()) return ::to_argb(255, 38, 38, 38);
#if defined(__APPLE__)
  return __xtd__macos_system_colors_control__();
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
#endif
}

intptr_t system_colors::control_dark() {
  if (::dark_mode()) return ::to_argb(255, 35, 35, 35);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW));
}

intptr_t system_colors::control_dark_dark() {
  if (::dark_mode()) return ::to_argb(255, 23, 23, 23);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DDKSHADOW));
}

intptr_t system_colors::control_light() {
  if (::dark_mode()) return ::to_argb(255, 74, 74, 74);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DLIGHT));
}

intptr_t system_colors::control_light_light() {
  if (::dark_mode()) return ::to_argb(255, 74, 74, 74);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT));
}

intptr_t system_colors::control_text() {
  if (::dark_mode()) return ::to_argb(255, 255, 255, 255);
#if defined(__APPLE__)
  return __xtd__macos_system_colors_control_text__();
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNTEXT));
#endif
}

intptr_t system_colors::desktop() {
  if (::dark_mode()) return ::to_argb(255, 154, 154, 184);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_DESKTOP));
}

intptr_t system_colors::gradient_active_caption() {
  if (::dark_mode()) return ::to_argb(255, 154, 154, 154);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTACTIVECAPTION));
}

intptr_t system_colors::gradient_inactive_caption() {
  if (::dark_mode()) return ::to_argb(255, 154, 154, 184);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTINACTIVECAPTION));
}

intptr_t system_colors::gray_text() {
  if (::dark_mode()) return ::to_argb(255, 107, 107, 107);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRAYTEXT));
}

intptr_t system_colors::highlight() {
  if (::dark_mode()) return ::to_argb(255, 49, 79, 120);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHT));
}

intptr_t system_colors::highlight_text() {
  if (::dark_mode()) return ::to_argb(255, 255, 255, 255);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHTTEXT));
}

intptr_t system_colors::hot_track() {
  if (::dark_mode()) return ::to_argb(255, 223, 223, 223);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HOTLIGHT));
}

intptr_t system_colors::inactive_border() {
  if (::dark_mode()) return ::to_argb(255, 154, 154, 184);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVEBORDER));
}

intptr_t system_colors::inactive_caption() {
  if (::dark_mode()) return ::to_argb(255, 154, 154, 184);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTION));
}

intptr_t system_colors::inactive_caption_text() {
  if (::dark_mode()) return ::to_argb(255, 107, 107, 107);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTIONTEXT));
}

intptr_t system_colors::info() {
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOBK));
}

intptr_t system_colors::info_text() {
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOTEXT));
}

intptr_t system_colors::menu() {
  if (::dark_mode()) return ::to_argb(255, 0, 0, 0);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENU));
}

intptr_t system_colors::menu_bar() {
  if (::dark_mode()) return ::to_argb(255, 0, 0, 0);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUBAR));
}

intptr_t system_colors::menu_highlight() {
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUHILIGHT));
}

intptr_t system_colors::menu_text() {
  if (::dark_mode()) return ::to_argb(255, 255, 255, 255);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUTEXT));
}

intptr_t system_colors::scroll_bar() {
  if (::dark_mode()) return ::to_argb(255, 38, 38, 38);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_SCROLLBAR));
}

intptr_t system_colors::window() {
  if (::dark_mode()) return ::to_argb(255, 23, 23, 23);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOW));
}

intptr_t system_colors::window_frame() {
  if (::dark_mode()) return ::to_argb(255, 154, 154, 184);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWFRAME));
}

intptr_t system_colors::window_text() {
  if (::dark_mode()) return ::to_argb(255, 255, 255, 255);
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWTEXT));
}
