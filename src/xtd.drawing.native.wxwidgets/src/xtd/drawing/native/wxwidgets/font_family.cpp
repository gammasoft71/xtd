#include <algorithm>
#include <cmath>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/font.h>
#include <xtd/drawing/native/font_family.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <wx/app.h>
#include <wx/colour.h>
#include <wx/fontenum.h>
#include <wx/dcscreen.h>

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

intptr_t font_family::create(const std::string& name) {
  if (name == ".AppleSystemUIFont") return reinterpret_cast<intptr_t>(new std::string(name));
  return wxFontEnumerator::IsValidFacename(name) ? reinterpret_cast<intptr_t>(new std::string(name)) : 0;
}

void font_family::destroy(intptr_t font_family) {
  delete reinterpret_cast<std::string*>(font_family);
}

std::string font_family::generic_serif_name() {
  /*
  wxFontInfo font_info;
  font_info.Family(wxFONTFAMILY_ROMAN);
  wxFont font(font_info);
  return font.GetFaceName().utf8_str().data();
   */
#if defined(__WXMSW__)
  return "Times New Roman";
#elif defined(__APPLE__)
  return "Times New Roman";
#elif defined(__WXGTK__)
  return "Serif";
#else
  return "Serif";
#endif
}

std::string font_family::generic_sans_serif_name() {
  /*
  wxFontInfo font_info;
  font_info.Family(wxFONTFAMILY_SWISS);
  wxFont font(font_info);
  return font.GetFaceName().utf8_str().data();
   */
#if defined(__WXMSW__)
  return "Microsoft Sans Serif";
#elif defined(__APPLE__)
  return "Arial";
#elif defined(__WXGTK__)
  return "Sans";
#else
  return "Sans";
#endif
}

std::string font_family::generic_monospace_name() {
  /*
  wxFontInfo font_info;
  font_info.Family(wxFONTFAMILY_TELETYPE);
  wxFont font(font_info);
  return font.GetFaceName().utf8_str().data();
   */
#if defined(__WXMSW__)
  return "Courier New";
#elif defined(__APPLE__)
  return "Courier";
#elif defined(__WXGTK__)
  return "Monospace";
#else
  return "Monospace";
#endif
}

std::vector<std::string> font_family::installed_font_families() {
  std::vector<std::string> families;
  for (const wxString& name : wxFontEnumerator::GetFacenames())
    if (name[0] != '@') families.push_back(name.utf8_str().data());
  std::sort(families.begin(), families.end());
  return families;
}

int32_t font_family::get_cell_ascent(intptr_t font_family, int32_t em_height, bool bold, bool italic, bool underline, bool strikeout) {
  if (!wxTheApp) return em_height;
  wxScreenDC hdc;
  wxFont font(pixel_to_native_font_graphics_untit(em_height), wxFontFamily::wxFONTFAMILY_DEFAULT, italic ? wxFontStyle::wxFONTSTYLE_ITALIC : wxFontStyle::wxFONTSTYLE_NORMAL, bold ? wxFontWeight::wxFONTWEIGHT_BOLD : wxFontWeight::wxFONTWEIGHT_NORMAL, underline, *reinterpret_cast<std::string*>(font_family));
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
  wxFont font(pixel_to_native_font_graphics_untit(em_height), wxFontFamily::wxFONTFAMILY_DEFAULT, italic ? wxFontStyle::wxFONTSTYLE_ITALIC : wxFontStyle::wxFONTSTYLE_NORMAL, bold ? wxFontWeight::wxFONTWEIGHT_BOLD : wxFontWeight::wxFONTWEIGHT_NORMAL, underline, *reinterpret_cast<std::string*>(font_family));
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
  wxFont font(pixel_to_native_font_graphics_untit(em_height), wxFontFamily::wxFONTFAMILY_DEFAULT, italic ? wxFontStyle::wxFONTSTYLE_ITALIC : wxFontStyle::wxFONTSTYLE_NORMAL, bold ? wxFontWeight::wxFONTWEIGHT_BOLD : wxFontWeight::wxFONTWEIGHT_NORMAL, underline, *reinterpret_cast<std::string*>(font_family));
  font.SetStrikethrough(strikeout);
  wxFont default_font = hdc.GetFont();
  hdc.SetFont(font);
  wxFontMetrics metrics = hdc.GetFontMetrics();
  hdc.SetFont(default_font);
  return std::round(static_cast<double>(metrics.height + metrics.externalLeading) / metrics.height * em_height);
}

std::string font_family::get_name(intptr_t font_family, int32_t language) {
  return *reinterpret_cast<std::string*>(font_family);
}

bool font_family::is_style_avaible(intptr_t font_family, bool bold, bool italic, bool underline, bool strikeout) {
  return true;
}
