#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/font>
#include <xtd/drawing/native/font_family>
#include <xtd/drawing/native/toolkit>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/convert_string>
#include <wx/app.h>
#include <wx/colour.h>
#include <wx/fontenum.h>
#include <wx/dcscreen.h>
#include <algorithm>
#include <cmath>

using namespace xtd;
using namespace xtd::drawing::native;

namespace {
  #if defined(__WXOSX__)
  float pixel_to_native_font_graphics_untit(float size) {
    return size;  // font is in points
  }
  #else
  float pixel_to_native_font_graphics_untit(float size) {
    auto dpi = 72;
    if (wxTheApp) {
      wxScreenDC hdc;
      dpi = hdc.GetPPI().GetHeight();
    }
    return size / 96.0f * dpi;  // font is in pixels and not in points
  }
  #endif
}

intptr font_family::create(const ustring& name) {
  toolkit::initialize(); // Must be first
  if (name == ".AppleSystemUIFont") return reinterpret_cast<intptr>(new ustring(name));
  return wxFontEnumerator::IsValidFacename(name) ? reinterpret_cast<intptr>(new ustring(name)) : 0;
}

void font_family::destroy(intptr font_family) {
  delete reinterpret_cast<ustring*>(font_family);
}

ustring font_family::generic_serif_name() {
  toolkit::initialize(); // Must be first
  /*
  wxFontInfo font_info;
  font_info.Family(wxFONTFAMILY_ROMAN);
  wxFont font(font_info);
  return font.GetFaceName().c_str().AsWChar();
   */
  #if defined(__WXMSW__)
  return L"Times New Roman";
  #elif defined(__WXOSX__)
  return L"Times New Roman";
  #elif defined(__WXGTK__)
  return L"Serif";
  #else
  return L"Serif";
  #endif
}

ustring font_family::generic_sans_serif_name() {
  toolkit::initialize(); // Must be first
  /*
  wxFontInfo font_info;
  font_info.Family(wxFONTFAMILY_SWISS);
  wxFont font(font_info);
  return font.GetFaceName().c_str().AsWChar();
   */
  #if defined(__WXMSW__)
  return L"Microsoft Sans Serif";
  #elif defined(__WXOSX__)
  return L"Arial";
  #elif defined(__WXGTK__)
  return L"Sans";
  #else
  return L"Sans";
  #endif
}

ustring font_family::generic_monospace_name() {
  toolkit::initialize(); // Must be first
  /*
  wxFontInfo font_info;
  font_info.Family(wxFONTFAMILY_TELETYPE);
  wxFont font(font_info);
  return font.GetFaceName().c_str().AsWChar();
   */
  #if defined(__WXMSW__)
  return L"Courier New";
  #elif defined(__WXOSX__)
  return L"Courier New";
  #elif defined(__WXGTK__)
  return L"Monospace";
  #else
  return L"Monospace";
  #endif
}

std::vector<ustring> font_family::installed_font_families() {
  toolkit::initialize(); // Must be first
  std::vector<ustring> families;
  for (const wxString& name : wxFontEnumerator::GetFacenames())
    if (name[0] != '@') families.push_back(name.c_str().AsWChar());
  std::sort(families.begin(), families.end());
  return families;
}

int32 font_family::get_cell_ascent(intptr font_family, int32 em_height, bool bold, bool italic, bool underline, bool strikeout) {
  toolkit::initialize(); // Must be first
  if (!wxTheApp) return em_height;
  wxScreenDC hdc;
  wxFont font(pixel_to_native_font_graphics_untit(em_height), wxFontFamily::wxFONTFAMILY_DEFAULT, italic ? wxFontStyle::wxFONTSTYLE_ITALIC : wxFontStyle::wxFONTSTYLE_NORMAL, bold ? wxFontWeight::wxFONTWEIGHT_BOLD : wxFontWeight::wxFONTWEIGHT_NORMAL, underline, convert_string::to_wstring(*reinterpret_cast<ustring*>(font_family)));
  font.SetStrikethrough(strikeout);
  wxFont default_font = hdc.GetFont();
  hdc.SetFont(font);
  wxFontMetrics metrics = hdc.GetFontMetrics();
  hdc.SetFont(default_font);
  return std::round(static_cast<double>(metrics.ascent) / metrics.height * em_height);
}

int32 font_family::get_cell_descent(intptr font_family, int32 em_height, bool bold, bool italic, bool underline, bool strikeout) {
  toolkit::initialize(); // Must be first
  if (!wxTheApp) return 0;
  wxScreenDC hdc;
  wxFont font(pixel_to_native_font_graphics_untit(em_height), wxFontFamily::wxFONTFAMILY_DEFAULT, italic ? wxFontStyle::wxFONTSTYLE_ITALIC : wxFontStyle::wxFONTSTYLE_NORMAL, bold ? wxFontWeight::wxFONTWEIGHT_BOLD : wxFontWeight::wxFONTWEIGHT_NORMAL, underline, convert_string::to_wstring(*reinterpret_cast<ustring*>(font_family)));
  font.SetStrikethrough(strikeout);
  wxFont default_font = hdc.GetFont();
  hdc.SetFont(font);
  wxFontMetrics metrics = hdc.GetFontMetrics();
  hdc.SetFont(default_font);
  return std::round(static_cast<double>(metrics.descent) / metrics.height * em_height);
}

int32 font_family::get_line_spacing(intptr font_family, int32 em_height, bool bold, bool italic, bool underline, bool strikeout) {
  toolkit::initialize(); // Must be first
  if (!wxTheApp) return em_height;
  wxScreenDC hdc;
  wxFont font(pixel_to_native_font_graphics_untit(em_height), wxFontFamily::wxFONTFAMILY_DEFAULT, italic ? wxFontStyle::wxFONTSTYLE_ITALIC : wxFontStyle::wxFONTSTYLE_NORMAL, bold ? wxFontWeight::wxFONTWEIGHT_BOLD : wxFontWeight::wxFONTWEIGHT_NORMAL, underline, convert_string::to_wstring(*reinterpret_cast<ustring*>(font_family)));
  font.SetStrikethrough(strikeout);
  wxFont default_font = hdc.GetFont();
  hdc.SetFont(font);
  wxFontMetrics metrics = hdc.GetFontMetrics();
  hdc.SetFont(default_font);
  return std::round(static_cast<double>(metrics.height + metrics.externalLeading) / metrics.height * em_height);
}

ustring font_family::get_name(intptr font_family, int32 language) {
  toolkit::initialize(); // Must be first
  return *reinterpret_cast<ustring*>(font_family);
}

bool font_family::is_style_available(intptr font_family, bool bold, bool italic, bool underline, bool strikeout) {
  toolkit::initialize(); // Must be first
  return true;
}
