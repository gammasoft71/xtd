#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/system_fonts.h>
#include <xtd/drawing/native/toolkit.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <wx/font.h>
#include <wx/settings.h>

using namespace xtd::drawing::native;

intptr_t system_fonts::caption_font() {
  toolkit::initialize(); // Must be first
  #if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
  #else
  return reinterpret_cast<intptr_t>(new wxFont(wxSystemSettings::GetFont(wxSystemFont::wxSYS_DEFAULT_GUI_FONT)));
  #endif
}

intptr_t system_fonts::default_font() {
  toolkit::initialize(); // Must be first
  #if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
  #else
  return reinterpret_cast<intptr_t>(new wxFont(wxSystemSettings::GetFont(wxSystemFont::wxSYS_DEFAULT_GUI_FONT)));
  #endif
}

intptr_t system_fonts::dialog_font() {
  toolkit::initialize(); // Must be first
  #if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
  #else
  return reinterpret_cast<intptr_t>(new wxFont(wxSystemSettings::GetFont(wxSystemFont::wxSYS_DEFAULT_GUI_FONT)));
  #endif
}

intptr_t system_fonts::icon_title_font() {
  toolkit::initialize(); // Must be first
  #if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
  #else
  return reinterpret_cast<intptr_t>(new wxFont(wxSystemSettings::GetFont(wxSystemFont::wxSYS_DEFAULT_GUI_FONT)));
  #endif
}

intptr_t system_fonts::menu_font() {
  toolkit::initialize(); // Must be first
  #if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
  #else
  return reinterpret_cast<intptr_t>(new wxFont(wxSystemSettings::GetFont(wxSystemFont::wxSYS_DEFAULT_GUI_FONT)));
  #endif
}

intptr_t system_fonts::message_box_font() {
  toolkit::initialize(); // Must be first
  #if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
  #else
  return reinterpret_cast<intptr_t>(new wxFont(wxSystemSettings::GetFont(wxSystemFont::wxSYS_DEFAULT_GUI_FONT)));
  #endif
}

intptr_t system_fonts::small_caption_font() {
  toolkit::initialize(); // Must be first
  #if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
  #else
  return reinterpret_cast<intptr_t>(new wxFont(wxSystemSettings::GetFont(wxSystemFont::wxSYS_DEFAULT_GUI_FONT)));
  #endif
}

intptr_t system_fonts::status_font() {
  toolkit::initialize(); // Must be first
#if defined(__APPLE__)
  return reinterpret_cast<intptr_t>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
#else
  return reinterpret_cast<intptr_t>(new wxFont(wxSystemSettings::GetFont(wxSystemFont::wxSYS_DEFAULT_GUI_FONT)));
#endif
}

intptr_t system_fonts::toolbar_font() {
  toolkit::initialize(); // Must be first
#if defined(__APPLE__)
  auto font = new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_SMALL);
  return reinterpret_cast<intptr_t>(font);
#else
  return reinterpret_cast<intptr_t>(new wxFont(wxSystemSettings::GetFont(wxSystemFont::wxSYS_DEFAULT_GUI_FONT)));
#endif
}
