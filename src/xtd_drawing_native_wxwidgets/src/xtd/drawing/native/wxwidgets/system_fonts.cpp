#include <xtd/drawing/native/system_fonts.h>
#include <wx/font.h>
#include <wx/settings.h>

using namespace xtd::drawing::native;

intptr_t system_fonts::caption_font() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
#else
  return reinterpret_cast<intptr_t>(new wxFont(wxSystemSettings::GetFont(wxSystemFont::wxSYS_DEFAULT_GUI_FONT)));
#endif
}

intptr_t system_fonts::default_font() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
#else
  return reinterpret_cast<intptr_t>(new wxFont(wxSystemSettings::GetFont(wxSystemFont::wxSYS_DEFAULT_GUI_FONT)));
#endif
}

intptr_t system_fonts::dialog_font() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
#else
  return reinterpret_cast<intptr_t>(new wxFont(wxSystemSettings::GetFont(wxSystemFont::wxSYS_DEFAULT_GUI_FONT)));
#endif
}

intptr_t system_fonts::icon_title_font() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
#else
  return reinterpret_cast<intptr_t>(new wxFont(wxSystemSettings::GetFont(wxSystemFont::wxSYS_DEFAULT_GUI_FONT)));
#endif
}

intptr_t system_fonts::menu_font() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
#else
  return reinterpret_cast<intptr_t>(new wxFont(wxSystemSettings::GetFont(wxSystemFont::wxSYS_DEFAULT_GUI_FONT)));
#endif
}

intptr_t system_fonts::message_box_font() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
#else
  return reinterpret_cast<intptr_t>(new wxFont(wxSystemSettings::GetFont(wxSystemFont::wxSYS_DEFAULT_GUI_FONT)));
#endif
}

intptr_t system_fonts::small_caption_font() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
#else
  return reinterpret_cast<intptr_t>(new wxFont(wxSystemSettings::GetFont(wxSystemFont::wxSYS_DEFAULT_GUI_FONT)));
#endif
}

intptr_t system_fonts::status_font() {
#if defined(__WXOSX__)
  return reinterpret_cast<intptr_t>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
#else
  return reinterpret_cast<intptr_t>(new wxFont(wxSystemSettings::GetFont(wxSystemFont::wxSYS_DEFAULT_GUI_FONT)));
#endif
}
