#include <xtd/drawing/native/system_colors.hpp>
#include <wx/settings.h>

using namespace xtd::drawing::native;

namespace {
  uint32_t to_argb(const wxColour color) {
    return (color.Alpha() << 24) + (color.Red() << 16) + (color.Green() << 8) + color.Blue();
  }
}

uint32_t system_colors::to_argb(intptr_t color){
#if defined(__APPLE__)
  return ::to_argb(wxColour(reinterpret_cast<WX_NSColor>(color)));
#else
  return reinterpret_cast<uint32_t>(color);
#endif
}

intptr_t system_colors::active_border() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVEBORDER).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVEBORDER));
#endif
}

intptr_t system_colors::active_caption() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVECAPTION).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVECAPTION));
#endif
}

intptr_t system_colors::active_caption_text() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTIONTEXT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTIONTEXT));
#endif
}

intptr_t system_colors::app_workspace() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_APPWORKSPACE).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_APPWORKSPACE));
#endif
}

intptr_t system_colors::button_face() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
#endif
}

intptr_t system_colors::button_highlight() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT));
#endif
}

intptr_t system_colors::button_shadow() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW));
#endif
}

intptr_t system_colors::control() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
#endif
}

intptr_t system_colors::control_dark() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW));
#endif
}

intptr_t system_colors::control_dark_dark() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DDKSHADOW).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DDKSHADOW));
#endif
}

intptr_t system_colors::control_light() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DLIGHT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DLIGHT));
#endif
}

intptr_t system_colors::control_light_light() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT));
#endif
}

intptr_t system_colors::control_text() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNTEXT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNTEXT));
#endif
}

intptr_t system_colors::desktop() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_DESKTOP).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_DESKTOP));
#endif
}

intptr_t system_colors::gradient_active_caption() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTACTIVECAPTION).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTACTIVECAPTION));
#endif
}

intptr_t system_colors::gradient_inactive_caption() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTINACTIVECAPTION).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTINACTIVECAPTION));
#endif
}

intptr_t system_colors::gray_text() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRAYTEXT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRAYTEXT));
#endif
}

intptr_t system_colors::highlight() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHT));
#endif
}

intptr_t system_colors::highlight_text() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHTTEXT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHTTEXT));
#endif
}

intptr_t system_colors::hot_track() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HOTLIGHT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HOTLIGHT));
#endif
}

intptr_t system_colors::inactive_border() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVEBORDER).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVEBORDER));
#endif
}

intptr_t system_colors::inactive_caption() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTION).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTION));
#endif
}

intptr_t system_colors::inactive_caption_text() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTIONTEXT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTIONTEXT));
#endif
}

intptr_t system_colors::info() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOBK).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOBK));
#endif
}

intptr_t system_colors::info_text() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOTEXT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOTEXT));
#endif
}

intptr_t system_colors::menu() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENU).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENU));
#endif
}

intptr_t system_colors::menu_bar() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUBAR).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUBAR));
#endif
}

intptr_t system_colors::menu_highlight() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUHILIGHT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUHILIGHT));
#endif
}

intptr_t system_colors::menu_text() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUTEXT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUTEXT));
#endif
}

intptr_t system_colors::scroll_bar() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_SCROLLBAR).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_SCROLLBAR));
#endif
}

intptr_t system_colors::window() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOW).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOW));
#endif
}

intptr_t system_colors::window_frame() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWFRAME).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWFRAME));
#endif
}

intptr_t system_colors::window_text() {
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWTEXT).OSXGetNSColor());
#else
  return ::to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWTEXT));
#endif
}
