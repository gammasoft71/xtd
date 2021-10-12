#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/system_colors.h>
#include <xtd/drawing/native/toolkit.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <wx/settings.h>

#include <cstdint>
#include <map>
#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/textctrl.h>

#if defined(__WXMSW__)
#include <Windows.h>
#undef max
#undef min
drawing_native_export_ int __xtd_win32_enable_dark_mode__ = -1;
#endif

#if defined(__APPLE__)
intptr_t __xtd__macos_system_colors_accent_control__();
intptr_t __xtd__macos_system_colors_accent_text__();
intptr_t __xtd__macos_system_colors_active_border__();
intptr_t __xtd__macos_system_colors_button_face__();
intptr_t __xtd__macos_system_colors_button_text__();
intptr_t __xtd__macos_system_colors_control__();
intptr_t __xtd__macos_system_colors_control_text__();
intptr_t __xtd__macos_system_colors_text_box__();
intptr_t __xtd__macos_system_colors_text_box_text__();
#endif

using namespace xtd::drawing::native;

namespace {
  bool is_windows_dark_mode() {
#if defined(__WXMSW__)
    DWORD value = 0, value_size = sizeof(value);
    if (RegGetValue(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", L"AppsUseLightTheme", RRF_RT_REG_DWORD, nullptr, &value, &value_size) == ERROR_SUCCESS)
      return __xtd_win32_enable_dark_mode__ != 0 && (value == 0 || __xtd_win32_enable_dark_mode__ == 1);
#endif
    return false;
  }
  
  uint32_t to_argb(const wxColour color) {
    return (color.Alpha() << 24) + (color.Red() << 16) + (color.Green() << 8) + color.Blue();
  }
}

uint32_t system_colors::to_argb(intptr_t color) {
  return color;
}

intptr_t system_colors::accent() {
  toolkit::initialize(); // Must be first
#if defined(__APPLE__)
  return __xtd__macos_system_colors_accent_control__();
#elif defined(__WXMSW__)
  if (is_windows_dark_mode()) return 0xFF00A0FA;
  return 0xFFD2E8F8;
#else
  return menu_highlight();
#endif
}

intptr_t system_colors::accent_text() {
  toolkit::initialize(); // Must be first
#if defined(__APPLE__)
  return __xtd__macos_system_colors_accent_text__();
#else
  if (is_windows_dark_mode()) return 0xFFFFFFFF;
  return highlight_text();
#endif
}

intptr_t system_colors::active_border() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF2C2C2C;
#if defined(__APPLE__)
  return __xtd__macos_system_colors_active_border__();
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVEBORDER));
#endif
}

intptr_t system_colors::active_caption() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF000000;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVECAPTION));
}

intptr_t system_colors::active_caption_text() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFFFFFFFF;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_CAPTIONTEXT));
}

intptr_t system_colors::app_workspace() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF191919;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_APPWORKSPACE));
}

intptr_t system_colors::button_face() {
  toolkit::initialize(); // Must be first
#if defined(__APPLE__)
  return __xtd__macos_system_colors_button_face__();
#elif defined(__WXMSW__)
  if (is_windows_dark_mode()) return 0xFF353535;
  return ::to_argb(0xFFFFFFFF);
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
#endif
}

intptr_t system_colors::button_highlight() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF00A0FA;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT));
}

intptr_t system_colors::button_shadow() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF232323;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW));
}

intptr_t system_colors::control() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF191919;
#if defined(__APPLE__)
  return __xtd__macos_system_colors_control__();
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
#endif
}

intptr_t system_colors::control_dark() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF232323;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW));
}

intptr_t system_colors::control_dark_dark() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF171717;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DDKSHADOW));
}

intptr_t system_colors::control_light() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF4A4A4A;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DLIGHT));
}

intptr_t system_colors::control_light_light() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF4A4A4A;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT));
}

intptr_t system_colors::control_text() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0XFFFFFFFF;
#if defined(__APPLE__)
  return __xtd__macos_system_colors_control_text__();
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNTEXT));
#endif
}

intptr_t system_colors::desktop() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF0078D7;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_DESKTOP));
}

intptr_t system_colors::gradient_active_caption() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF000000;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTACTIVECAPTION));
}

intptr_t system_colors::gradient_inactive_caption() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF2B2B2B;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTINACTIVECAPTION));
}

intptr_t system_colors::gray_text() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF6B6B6B;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRAYTEXT));
}

intptr_t system_colors::highlight() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF4D4D4D;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHT));
}

intptr_t system_colors::highlight_text() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFFFFFFFF;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHTTEXT));
}

intptr_t system_colors::hot_track() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF4D4D4D;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HOTLIGHT));
}

intptr_t system_colors::inactive_border() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF414143;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVEBORDER));
}

intptr_t system_colors::inactive_caption() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF2B2B2B;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTION));
}

intptr_t system_colors::inactive_caption_text() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF494949;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTIONTEXT));
}

intptr_t system_colors::info() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF2B2B2B;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOBK));
}

intptr_t system_colors::info_text() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0XFFFFFFFF;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOTEXT));
}

intptr_t system_colors::menu() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF2B2B2B;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENU));
}

intptr_t system_colors::menu_bar() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0XFF000000;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUBAR));
}

intptr_t system_colors::menu_highlight() {
  toolkit::initialize(); // Must be first
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUHILIGHT));
}

intptr_t system_colors::menu_text() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFFFFFFFF;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUTEXT));
}

intptr_t system_colors::scroll_bar() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF171717;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_SCROLLBAR));
}

intptr_t system_colors::text_box() {
  toolkit::initialize(); // Must be first
#if defined(__APPLE__)
  return __xtd__macos_system_colors_text_box__();
#else
  if (is_windows_dark_mode()) return 0xFF121212;
  return window();
#endif
}

intptr_t system_colors::text_box_text() {
  toolkit::initialize(); // Must be first
#if defined(__APPLE__)
  
  return __xtd__macos_system_colors_text_box_text__();
#else
  if (is_windows_dark_mode()) return 0xFFFFFFFF;
  return window_text();
#endif
}

intptr_t system_colors::window() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF202020;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOW));
}

intptr_t system_colors::window_frame() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF333333;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWFRAME));
}

intptr_t system_colors::window_text() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFFFFFFFF;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWTEXT));
}
