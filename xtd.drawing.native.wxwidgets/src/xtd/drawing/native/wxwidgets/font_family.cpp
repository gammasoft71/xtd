#include <xtd/drawing/native/font_family.hpp>
#include <wx/app.h>
#include <wx/colour.h>
#include <wx/fontenum.h>
#include <wx/dcscreen.h>

using namespace xtd::drawing::native;

void font_family::destroy(intptr_t font_family) {
  delete reinterpret_cast<std::string*>(font_family);
}

intptr_t font_family::from_name(const std::string& name) {
  return wxFontEnumerator::IsValidFacename(name) ? reinterpret_cast<intptr_t>(new std::string(name)) : 0;
}

std::string font_family::generic_serif_name() {
#if defined(__WXMSW__)
  return "Times New Roman";
#elif defined(__WXOSX__)
  return "Times";
#elif defined(__WXGTK__)
  return "Serif";
#else
  return "Serif";
#endif
}

std::string font_family::generic_sans_serif_name() {
#if defined(__WXMSW__)
  return "Microsoft Sans Serif";
#elif defined(__WXOSX__)
  return "Helvetica";
#elif defined(__WXGTK__)
  return "Sans";
#else
  return "Sans";
#endif
}

std::string font_family::generic_monospace_name() {
#if defined(__WXMSW__)
  return "Courier New";
#elif defined(__WXOSX__)
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
    families.push_back(name.ToStdString());
  return families;
}

int32_t font_family::get_cell_ascent(intptr_t font_family, bool bold, bool italic, bool underline, bool strikeout) {
  if (!wxTheApp) return 0;
  wxScreenDC hdc;
  wxFont font(hdc.GetFont().GetPixelSize(), wxFontFamily::wxFONTFAMILY_DEFAULT, italic ? wxFontStyle::wxFONTSTYLE_ITALIC : wxFontStyle::wxFONTSTYLE_NORMAL, bold ? wxFontWeight::wxFONTWEIGHT_BOLD : wxFontWeight::wxFONTWEIGHT_NORMAL, underline, *reinterpret_cast<std::string*>(font_family));
  font.SetStrikethrough(strikeout);
  hdc.SetFont(font);
  wxFontMetrics metrics = hdc.GetFontMetrics();
  return metrics.ascent;
}

int32_t font_family::get_cell_descent(intptr_t font_family, bool bold, bool italic, bool underline, bool strikeout) {
  if (!wxTheApp) return 0;
  wxScreenDC hdc;
  wxFont font(hdc.GetFont().GetPixelSize(), wxFontFamily::wxFONTFAMILY_DEFAULT, italic ? wxFontStyle::wxFONTSTYLE_ITALIC : wxFontStyle::wxFONTSTYLE_NORMAL, bold ? wxFontWeight::wxFONTWEIGHT_BOLD : wxFontWeight::wxFONTWEIGHT_NORMAL, underline, *reinterpret_cast<std::string*>(font_family));
  font.SetStrikethrough(strikeout);
  hdc.SetFont(font);
  wxFontMetrics metrics = hdc.GetFontMetrics();
  return metrics.descent;
}
