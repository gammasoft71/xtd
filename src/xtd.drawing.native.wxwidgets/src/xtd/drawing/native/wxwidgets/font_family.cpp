#include <algorithm>
#include <cmath>
#include <xtd/convert_string.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/font.h>
#include <xtd/drawing/native/font_family.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <wx/app.h>
#include <wx/colour.h>
#include <wx/fontenum.h>
#include <wx/dcscreen.h>

using namespace xtd;
using namespace xtd::drawing::native;

namespace {
#if defined(__APPLE__)
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

intptr_t font_family::create(const ustring& name) {
  if (name == ".AppleSystemUIFont") return reinterpret_cast<intptr_t>(new ustring(name));
  return wxFontEnumerator::IsValidFacename(name) ? reinterpret_cast<intptr_t>(new ustring(name)) : 0;
}

void font_family::destroy(intptr_t font_family) {
  delete reinterpret_cast<ustring*>(font_family);
}

ustring font_family::generic_serif_name() {
  /*
  wxFontInfo font_info;
  font_info.Family(wxFONTFAMILY_ROMAN);
  wxFont font(font_info);
  return font.GetFaceName().c_str().AsWChar();
   */
#if defined(__WXMSW__)
  return L"Times New Roman";
#elif defined(__APPLE__)
  return L"Times New Roman";
#elif defined(__WXGTK__)
  return L"Serif";
#else
  return L"Serif";
#endif
}

ustring font_family::generic_sans_serif_name() {
  /*
  wxFontInfo font_info;
  font_info.Family(wxFONTFAMILY_SWISS);
  wxFont font(font_info);
  return font.GetFaceName().c_str().AsWChar();
   */
#if defined(__WXMSW__)
  return L"Microsoft Sans Serif";
#elif defined(__APPLE__)
  return L"Arial";
#elif defined(__WXGTK__)
  return L"Sans";
#else
  return L"Sans";
#endif
}

ustring font_family::generic_monospace_name() {
  /*
  wxFontInfo font_info;
  font_info.Family(wxFONTFAMILY_TELETYPE);
  wxFont font(font_info);
  return font.GetFaceName().c_str().AsWChar();
   */
#if defined(__WXMSW__)
  return L"Courier New";
#elif defined(__APPLE__)
  return L"Courier";
#elif defined(__WXGTK__)
  return L"Monospace";
#else
  return L"Monospace";
#endif
}

std::vector<ustring> font_family::installed_font_families() {
  std::vector<ustring> families;
  for (const wxString& name : wxFontEnumerator::GetFacenames())
    if (name[0] != '@') families.push_back(name.c_str().AsWChar());
  std::sort(families.begin(), families.end());
  return families;
}

int32_t font_family::get_cell_ascent(intptr_t font_family, int32_t em_height, bool bold, bool italic, bool underline, bool strikeout) {
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

int32_t font_family::get_cell_descent(intptr_t font_family, int32_t em_height, bool bold, bool italic, bool underline, bool strikeout) {
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

int32_t font_family::get_line_spacing(intptr_t font_family, int32_t em_height, bool bold, bool italic, bool underline, bool strikeout) {
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

ustring font_family::get_name(intptr_t font_family, int32_t language) {
  return *reinterpret_cast<ustring*>(font_family);
}

bool font_family::is_style_available(intptr_t font_family, bool bold, bool italic, bool underline, bool strikeout) {
  return true;
}
