#include <xtd/drawing/native/font.hpp>
#include <wx/app.h>
#include <wx/dcscreen.h>
#include <wx/font.h>


namespace {
#if defined(__WXOSX__)
  constexpr float device_unit_scale_correction =  4.0f / 3.0f;
#else
  constexpr float device_unit_scale_correction =  1.0f;
#endif
}

using namespace xtd::drawing::native;

intptr_t font::create(const std::string& name, float em_size, bool bold, bool italic, bool underline, bool strikeout, uint8_t gdi_char_set, bool gdi_vertical_font) {
  wxFont* font = new wxFont(em_size * device_unit_scale_correction, wxFontFamily::wxFONTFAMILY_DEFAULT, italic ? wxFontStyle::wxFONTSTYLE_ITALIC : wxFontStyle::wxFONTSTYLE_NORMAL, bold ? wxFontWeight::wxFONTWEIGHT_BOLD : wxFontWeight::wxFONTWEIGHT_NORMAL, underline, name);
  font->SetPointSize(em_size * device_unit_scale_correction);
  font->SetStrikethrough(strikeout);
  return reinterpret_cast<intptr_t>(font);
}

intptr_t font::create_from_hdc(intptr_t hdc) {
  return reinterpret_cast<intptr_t>(new wxFont(reinterpret_cast<wxDC*>(hdc)->GetFont()));
}

intptr_t font::create_from_hfont(intptr_t hfont) {
  return reinterpret_cast<intptr_t>(new wxFont(*reinterpret_cast<wxFont*>(hfont)));
}

void font::destroy(intptr_t font) {
  delete reinterpret_cast<wxFont*>(font);
}

int32_t font::dpi() {
  if (!wxTheApp) return 0;
  wxScreenDC hdc;
  wxSize dpi = hdc.GetPPI();
  return dpi.GetHeight();
}

void font::get_information(intptr_t font, std::string& name, float& em_size, bool& bold, bool& italic, bool& underline, bool& strikeout, uint8_t& gdi_char_set, bool& gdi_vertical_font) {
  wxFont* wx_font = reinterpret_cast<wxFont*>(font);
  name = wx_font->GetFaceName();
  em_size = static_cast<float>(wx_font->GetPointSize()) / device_unit_scale_correction;
  bold = wx_font->GetWeight() > wxFontWeight::wxFONTWEIGHT_NORMAL;
  italic = wx_font->GetStyle() > wxFontStyle::wxFONTSTYLE_NORMAL;
  underline = wx_font->GetUnderlined();
  strikeout = wx_font->GetStrikethrough();
  gdi_char_set = 0;
  gdi_vertical_font = false;
}

float font::height(intptr_t font) {
  if (!wxTheApp) return 0;
  wxScreenDC hdc;
  wxFont current_font = hdc.GetFont();
  hdc.SetFont(*reinterpret_cast<wxFont*>(font));
  wxFontMetrics metrics = hdc.GetFontMetrics();
  hdc.SetFont(current_font);
  return static_cast<float>(metrics.height);
}

float font::height(intptr_t font, intptr_t hdc) {
  if (!wxTheApp) return 0;
  wxFont current_font = reinterpret_cast<wxDC*>(hdc)->GetFont();
  reinterpret_cast<wxDC*>(hdc)->SetFont(*reinterpret_cast<wxFont*>(font));
  wxFontMetrics metrics = reinterpret_cast<wxDC*>(hdc)->GetFontMetrics();
  reinterpret_cast<wxDC*>(hdc)->SetFont(current_font);
  return static_cast<float>(metrics.height);
}

float font::height(intptr_t font, float dpi) {
  if (!wxTheApp) return 0;
  wxScreenDC hdc;
  wxSize current_dpi = hdc.GetPPI();
  wxFont current_font = hdc.GetFont();
  hdc.SetFont(*reinterpret_cast<wxFont*>(font));
  wxFontMetrics metrics = hdc.GetFontMetrics();
  hdc.SetFont(current_font);
  return static_cast<float>(metrics.height) / current_dpi.GetWidth() * dpi;
}
