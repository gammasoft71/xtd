#include <xtd/drawing/native/system_colors.hpp>
#include <wx/settings.h>

using namespace xtd::drawing::native;

namespace {
  uint32_t to_argb(const wxColour color) {
    return (color.Alpha() << 24) + (color.Red() << 16) + (color.Green() << 8) + color.Blue();
  }
}

uint32_t system_colors::active_border() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVEBORDER));
}

uint32_t system_colors::active_caption() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVECAPTION));
}

uint32_t system_colors::active_caption_text() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTIONTEXT));
}

uint32_t system_colors::app_workspace() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_APPWORKSPACE));
}

uint32_t system_colors::button_face() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
}

uint32_t system_colors::button_highlight() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT));
}

uint32_t system_colors::button_shadow() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW));
}

uint32_t system_colors::control() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
}

uint32_t system_colors::control_dark() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW));
}

uint32_t system_colors::control_dark_dark() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DDKSHADOW));
}

uint32_t system_colors::control_light() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DLIGHT));
}

uint32_t system_colors::control_light_light() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT));
}

uint32_t system_colors::control_text() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNTEXT));
}

uint32_t system_colors::desktop() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_DESKTOP));
}

uint32_t system_colors::gradient_active_caption() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTACTIVECAPTION));
}

uint32_t system_colors::gradient_inactive_caption() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTINACTIVECAPTION));
}

uint32_t system_colors::gray_text() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRAYTEXT));
}

uint32_t system_colors::highlight() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHT));
}

uint32_t system_colors::highlight_text() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHTTEXT));
}

uint32_t system_colors::hot_track() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HOTLIGHT));
}

uint32_t system_colors::inactive_border() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVEBORDER));
}

uint32_t system_colors::inactive_caption() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTION));
}

uint32_t system_colors::inactive_caption_text() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTIONTEXT));
}

uint32_t system_colors::info() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOBK));
}

uint32_t system_colors::info_text() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOTEXT));
}

uint32_t system_colors::menu() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENU));
}

uint32_t system_colors::menu_bar() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUBAR));
}

uint32_t system_colors::menu_highlight() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUHILIGHT));
}

uint32_t system_colors::menu_text() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUTEXT));
}

uint32_t system_colors::scroll_bar() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_SCROLLBAR));
}

uint32_t system_colors::window() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOW));
}

uint32_t system_colors::window_frame() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWFRAME));
}

uint32_t system_colors::window_text() {
  return to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWTEXT));
}
