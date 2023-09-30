#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/system_fonts>
#include <xtd/drawing/native/toolkit>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <wx/font.h>
#include <wx/settings.h>

using namespace xtd;
using namespace xtd::drawing::native;

bool __enable_system_font_size__ = false;

#if !defined(__WXOSX__)
namespace {

  wxFont GetDefaultGuiFont() {
    auto font = wxSystemSettings::GetFont(wxSystemFont::wxSYS_DEFAULT_GUI_FONT);
    auto pointSize = font.GetPointSize();
    #if defined(__WXGTK__)
    if (!__enable_system_font_size__ && pointSize > 9) pointSize = 9;
    #endif
    return wxFont(pointSize, font.GetFamily(), font.GetStyle(), font.GetWeight(), font.GetUnderlined(), font.GetFaceName(), font.GetEncoding());
  }
}
#endif

intptr system_fonts::caption_font() {
  toolkit::initialize(); // Must be first
  #if defined(__WXOSX__)
  return reinterpret_cast<intptr>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
  #else
  return reinterpret_cast<intptr>(new wxFont(GetDefaultGuiFont()));
  #endif
}

intptr system_fonts::default_font() {
  toolkit::initialize(); // Must be first
  #if defined(__WXOSX__)
  return reinterpret_cast<intptr>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
  #else
  return reinterpret_cast<intptr>(new wxFont(GetDefaultGuiFont()));
  #endif
}

intptr system_fonts::dialog_font() {
  toolkit::initialize(); // Must be first
  #if defined(__WXOSX__)
  return reinterpret_cast<intptr>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
  #else
  return reinterpret_cast<intptr>(new wxFont(GetDefaultGuiFont()));
  #endif
}

intptr system_fonts::icon_title_font() {
  toolkit::initialize(); // Must be first
  #if defined(__WXOSX__)
  return reinterpret_cast<intptr>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
  #else
  return reinterpret_cast<intptr>(new wxFont(GetDefaultGuiFont()));
  #endif
}

intptr system_fonts::menu_font() {
  toolkit::initialize(); // Must be first
  #if defined(__WXOSX__)
  return reinterpret_cast<intptr>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
  #else
  return reinterpret_cast<intptr>(new wxFont(GetDefaultGuiFont()));
  #endif
}

intptr system_fonts::message_box_font() {
  toolkit::initialize(); // Must be first
  #if defined(__WXOSX__)
  return reinterpret_cast<intptr>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
  #else
  return reinterpret_cast<intptr>(new wxFont(GetDefaultGuiFont()));
  #endif
}

intptr system_fonts::small_caption_font() {
  toolkit::initialize(); // Must be first
  #if defined(__WXOSX__)
  return reinterpret_cast<intptr>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_NORMAL));
  #else
  return reinterpret_cast<intptr>(new wxFont(GetDefaultGuiFont()));
  #endif
}

intptr system_fonts::status_font() {
  toolkit::initialize(); // Must be first
  #if defined(__WXOSX__)
  return reinterpret_cast<intptr>(new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_SMALL));
  #else
  return reinterpret_cast<intptr>(new wxFont(GetDefaultGuiFont()));
  #endif
}

intptr system_fonts::tool_font() {
  toolkit::initialize(); // Must be first
  #if defined(__WXOSX__)
  auto font = new wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_SMALL);
  return reinterpret_cast<intptr>(font);
  #else
  return reinterpret_cast<intptr>(new wxFont(GetDefaultGuiFont()));
  #endif
}
