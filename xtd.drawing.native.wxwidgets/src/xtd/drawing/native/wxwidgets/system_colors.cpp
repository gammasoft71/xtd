#include <xtd/drawing/native/system_colors.hpp>
#include <wx/log.h>
#include <wx/settings.h>

using namespace xtd::drawing::native;

namespace {
  unsigned int to_argb(const wxColour color) {
    return (color.Alpha() << 24) + (color.Red() << 16) + (color.Green() << 8) + color.Blue();
  }
}

unsigned int system_colors::active_border() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVEBORDER));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::active_caption() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_ACTIVECAPTION));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::active_caption_text() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTIONTEXT));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::app_workspace() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_APPWORKSPACE));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::button_face() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::button_highlight() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::button_shadow() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::control() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::control_dark() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNSHADOW));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::control_dark_dark() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DDKSHADOW));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::control_light() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_3DLIGHT));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::control_light_light() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNHIGHLIGHT));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::control_text() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNTEXT));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::desktop() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_DESKTOP));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::gradient_active_caption() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTACTIVECAPTION));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::gradient_inactive_caption() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRADIENTINACTIVECAPTION));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::gray_text() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_GRAYTEXT));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::highlight() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHT));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::highlight_text() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HIGHLIGHTTEXT));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::hot_track() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_HOTLIGHT));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::inactive_border() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVEBORDER));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::inactive_caption() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTION));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::inactive_caption_text() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INACTIVECAPTIONTEXT));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::info() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOBK));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::info_text() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_INFOTEXT));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::menu() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENU));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::menu_bar() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUBAR));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::menu_highlight() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUHILIGHT));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::menu_text() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUTEXT));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::scroll_bar() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_SCROLLBAR));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::window() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOW));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::window_frame() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWFRAME));
  wxLog::EnableLogging(true);
  return argb;
}

unsigned int system_colors::window_text() {
  wxLog::EnableLogging(false);
  unsigned int argb = to_argb(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOWTEXT));
  wxLog::EnableLogging(true);
  return argb;
}
