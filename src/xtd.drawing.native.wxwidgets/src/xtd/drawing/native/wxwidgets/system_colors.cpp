#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/system_colors>
#include <xtd/drawing/native/toolkit>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/as>
#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <cstdint>
#include <map>

using namespace xtd;
using namespace xtd::drawing::native;

#if defined(__WXMSW__)
#include <Windows.h>
// Like Windows.h (with NOMINMAX defined), some includes define max as a macro and this causes compilation errors.
#undef max
// Like Windows.h (with NOMINMAX defined), some includes define min as a macro and this causes compilation errors.
#undef min
drawing_native_export_ int32 __xtd_win32_enable_dark_mode__ = -1;
#endif

#if defined(__WXOSX__)
intptr __xtd__macos_system_colors_accent_control__();
intptr __xtd__macos_system_colors_accent_text__();
intptr __xtd__macos_system_colors_active_border__();
intptr __xtd__macos_system_colors_button_face__();
intptr __xtd__macos_system_colors_button_text__();
intptr __xtd__macos_system_colors_control__();
intptr __xtd__macos_system_colors_control_text__();
intptr __xtd__macos_system_colors_text_box__();
intptr __xtd__macos_system_colors_text_box_text__();
#endif

namespace {
  bool is_windows_dark_mode() {
    #if defined(__WXMSW__)
    auto value = DWORD{};
    auto value_size = DWORD {sizeof(value)};
    if (RegGetValue(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", L"AppsUseLightTheme", RRF_RT_REG_DWORD, nullptr, &value, &value_size) == ERROR_SUCCESS)
      return __xtd_win32_enable_dark_mode__ != 0 && (value == 0 || __xtd_win32_enable_dark_mode__ == 1);
    #endif
    return false;
  }
  
  uint32 to_argb(const wxColour color) {
    return (color.Alpha() << 24) + (color.Red() << 16) + (color.Green() << 8) + color.Blue();
  }
}

uint32 system_colors::to_argb(intptr color) {
  return as<uint32>(color);
}

intptr system_colors::accent() {
  toolkit::initialize(); // Must be first
  #if defined(__WXOSX__)
  return __xtd__macos_system_colors_accent_control__();
  #elif defined(__WXMSW__)
  if (is_windows_dark_mode()) return 0xFF00A0FA;
  return highlight();
  #else
  return highlight();
  #endif
}

intptr system_colors::accent_text() {
  toolkit::initialize(); // Must be first
  #if defined(__WXOSX__)
  return __xtd__macos_system_colors_accent_text__();
  #else
  if (is_windows_dark_mode()) return 0xFFFFFFFF;
  return highlight_text();
  #endif
}

intptr system_colors::active_border() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF2C2C2C;
  #if defined(__WXOSX__)
  return __xtd__macos_system_colors_active_border__();
  #else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVEBORDER));
  #endif
}

intptr system_colors::active_caption() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF000000;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVECAPTION));
}

intptr system_colors::active_caption_text() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFFFFFFFF;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_CAPTIONTEXT));
}

intptr system_colors::active_text() {
  toolkit::initialize(); // Must be first
  if (wxSystemSettings::GetAppearance().IsDark() || is_windows_dark_mode()) return 0xFFD03E3D;
  return 0xFFFF0000;
}

intptr system_colors::app_workspace() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF191919;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_APPWORKSPACE));
}

intptr system_colors::button_face() {
  toolkit::initialize(); // Must be first
  #if defined(__WXOSX__)
  return __xtd__macos_system_colors_button_face__();
  #elif defined(__WXMSW__)
  if (is_windows_dark_mode()) return 0xFF353535;
  return ::to_argb(0xFFFFFFFF);
  #else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
  #endif
}

intptr system_colors::button_highlight() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF00A0FA;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT));
}

intptr system_colors::button_shadow() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF232323;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW));
}

intptr system_colors::control() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF191919;
  #if defined(__WXOSX__)
  return __xtd__macos_system_colors_control__();
  #else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
  #endif
}

intptr system_colors::control_dark() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF232323;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW));
}

intptr system_colors::control_dark_dark() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF171717;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DDKSHADOW));
}

intptr system_colors::control_light() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF4A4A4A;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DLIGHT));
}

intptr system_colors::control_light_light() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF4A4A4A;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT));
}

intptr system_colors::control_text() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0XFFFFFFFF;
  #if defined(__WXOSX__)
  return __xtd__macos_system_colors_control_text__();
  #else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNTEXT));
  #endif
}

intptr system_colors::desktop() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF0078D7;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_DESKTOP));
}

intptr system_colors::gradient_active_caption() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF000000;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTACTIVECAPTION));
}

intptr system_colors::gradient_inactive_caption() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF2B2B2B;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTINACTIVECAPTION));
}

intptr system_colors::gray_text() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF6B6B6B;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRAYTEXT));
}

intptr system_colors::highlight() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF4D4D4D;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHT));
}

intptr system_colors::highlight_text() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFFFFFFFF;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHTTEXT));
}

intptr system_colors::hot_track() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF4D4D4D;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HOTLIGHT));
}

intptr system_colors::inactive_border() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF414143;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVEBORDER));
}

intptr system_colors::inactive_caption() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF2B2B2B;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTION));
}

intptr system_colors::inactive_caption_text() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF494949;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTIONTEXT));
}

intptr system_colors::info() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF2B2B2B;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOBK));
}

intptr system_colors::info_text() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0XFFFFFFFF;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOTEXT));
}

intptr system_colors::link_text() {
  toolkit::initialize(); // Must be first
  if (wxSystemSettings::GetAppearance().IsDark() || is_windows_dark_mode()) return 0xFF1E90FF;
  return 0xFF0000FF;
}

intptr system_colors::menu() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF2B2B2B;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENU));
}

intptr system_colors::menu_bar() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0XFF000000;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUBAR));
}

intptr system_colors::menu_highlight() {
  toolkit::initialize(); // Must be first
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUHILIGHT));
}

intptr system_colors::menu_text() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFFFFFFFF;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUTEXT));
}

intptr system_colors::scroll_bar() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF171717;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_SCROLLBAR));
}

intptr system_colors::shadow_text() {
  toolkit::initialize(); // Must be first
  if (wxSystemSettings::GetAppearance().IsDark() || is_windows_dark_mode())  return 0xFF000000;
  return 0xFF696969;
}

intptr system_colors::text_box() {
  toolkit::initialize(); // Must be first
  #if defined(__WXOSX__)
  return __xtd__macos_system_colors_text_box__();
  #else
  if (is_windows_dark_mode()) return 0xFF121212;
  return window();
  #endif
}

intptr system_colors::text_box_text() {
  toolkit::initialize(); // Must be first
  #if defined(__WXOSX__)
  return __xtd__macos_system_colors_text_box_text__();
  #else
  if (is_windows_dark_mode()) return 0xFFFFFFFF;
  return window_text();
  #endif
}

intptr system_colors::visited_text() {
  toolkit::initialize(); // Must be first
  if (wxSystemSettings::GetAppearance().IsDark() || is_windows_dark_mode()) return 0xFF87CEEB;
  return 0xFF800080;
}

intptr system_colors::window() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF202020;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOW));
}

intptr system_colors::window_frame() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFF333333;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWFRAME));
}

intptr system_colors::window_text() {
  toolkit::initialize(); // Must be first
  if (is_windows_dark_mode()) return 0xFFFFFFFF;
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWTEXT));
}
