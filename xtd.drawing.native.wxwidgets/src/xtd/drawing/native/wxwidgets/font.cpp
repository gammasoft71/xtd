#include <xtd/drawing/native/font.hpp>
#include <wx/app.h>
#include <wx/dcscreen.h>
#include <wx/font.h>

using namespace xtd::drawing::native;

intptr_t font::create(const std::string& name, float em_size, bool bold, bool italic, bool underline, bool strikeout, uint8_t gdi_char_set, bool gdi_vertical_font) {
  wxFont* font = new wxFont(em_size, wxFontFamily::wxFONTFAMILY_DEFAULT, italic ? wxFontStyle::wxFONTSTYLE_ITALIC : wxFontStyle::wxFONTSTYLE_NORMAL, bold ? wxFontWeight::wxFONTWEIGHT_BOLD : wxFontWeight::wxFONTWEIGHT_NORMAL, underline, name);
  font->SetPointSize(em_size);
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
