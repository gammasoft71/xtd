#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/font>
#include <xtd/drawing/native/toolkit>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/convert_string>
#include <wx/app.h>
#include <wx/dcscreen.h>
#include <wx/font.h>

using namespace xtd;
using namespace xtd::drawing::native;

bool __enable_font_size_correction__ = true;

namespace {
  int32 dpi() {
    if (!wxTheApp) return 72;
    wxScreenDC hdc;
    wxSize dpi = hdc.GetPPI();
    return dpi.GetHeight();
  }
  
  float points_to_native_font_size_correction(float size) {
    if (!__enable_font_size_correction__) return size;
    #if defined(__WXOSX__)
    return size / dpi() * 96.0f;
    #elif defined (__WXGTK__)
    return size / dpi() * 92.0f;
    #endif
    return size;
  }
  float native_font_size_correction_to_points(float size) {
    if (!__enable_font_size_correction__) return size;
    #if defined(__WXOSX__)
    return size / 96.0f * dpi();
    #elif defined (__WXGTK__)
    return size / 92.0f * dpi();
    #endif
    return size;
  }
}

intptr font::create(const ustring& name, float em_size, bool bold, bool italic, bool underline, bool strikeout, xtd::byte gdi_char_set, bool gdi_vertical_font) {
  toolkit::initialize(); // Must be first
  wxFont* font = new wxFont(points_to_native_font_size_correction(em_size), wxFontFamily::wxFONTFAMILY_DEFAULT, italic ? wxFontStyle::wxFONTSTYLE_ITALIC : wxFontStyle::wxFONTSTYLE_NORMAL, bold ? wxFontWeight::wxFONTWEIGHT_BOLD : wxFontWeight::wxFONTWEIGHT_NORMAL, underline, name == ".AppleSystemUIFont" ? L"" : convert_string::to_wstring(name));
  font->SetPointSize(points_to_native_font_size_correction(em_size));
  font->SetStrikethrough(strikeout);
  return reinterpret_cast<intptr>(font);
}

intptr font::create_from_hdc(intptr hdc) {
  toolkit::initialize(); // Must be first
  return reinterpret_cast<intptr>(new wxFont(reinterpret_cast<wxDC*>(hdc)->GetFont()));
}

intptr font::create_from_hfont(intptr hfont) {
  toolkit::initialize(); // Must be first
  return reinterpret_cast<intptr>(new wxFont(*reinterpret_cast<wxFont*>(hfont)));
}

void font::destroy(intptr font) {
  delete reinterpret_cast<wxFont*>(font);
}

int32 font::dpi() {
  toolkit::initialize(); // Must be first
  return ::dpi();
}

void font::get_information(intptr font, ustring& name, float& em_size, bool& bold, bool& italic, bool& underline, bool& strikeout, xtd::byte& gdi_char_set, bool& gdi_vertical_font) {
  toolkit::initialize(); // Must be first
  wxFont* wx_font = reinterpret_cast<wxFont*>(font);
  name = wx_font->GetFaceName().c_str().AsWChar();
  em_size = native_font_size_correction_to_points(static_cast<float>(wx_font->GetPointSize()));
  bold = wx_font->GetWeight() > wxFontWeight::wxFONTWEIGHT_NORMAL;
  italic = wx_font->GetStyle() > wxFontStyle::wxFONTSTYLE_NORMAL;
  underline = wx_font->GetUnderlined();
  strikeout = wx_font->GetStrikethrough();
  gdi_char_set = 0;
  gdi_vertical_font = false;
}

float font::height(intptr font) {
  toolkit::initialize(); // Must be first
  if (!wxTheApp) return reinterpret_cast<wxFont*>(font)->GetPixelSize().GetHeight();
  wxScreenDC hdc;
  wxFont current_font = hdc.GetFont();
  hdc.SetFont(*reinterpret_cast<wxFont*>(font));
  wxFontMetrics metrics = hdc.GetFontMetrics();
  hdc.SetFont(current_font);
  return static_cast<float>(metrics.height);
}

float font::height(intptr font, intptr hdc) {
  toolkit::initialize(); // Must be first
  if (!wxTheApp) return reinterpret_cast<wxFont*>(font)->GetPixelSize().GetHeight();
  wxFont current_font = reinterpret_cast<wxDC*>(hdc)->GetFont();
  reinterpret_cast<wxDC*>(hdc)->SetFont(*reinterpret_cast<wxFont*>(font));
  wxFontMetrics metrics = reinterpret_cast<wxDC*>(hdc)->GetFontMetrics();
  reinterpret_cast<wxDC*>(hdc)->SetFont(current_font);
  return static_cast<float>(metrics.height);
}
