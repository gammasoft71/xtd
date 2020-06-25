#include <xtd/forms/native/font_picker.h>
#include <xtd/forms/native/content_alignment.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_font_picker.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

color font_picker::color(intptr_t control) {
  if (!control) return {};
  wxColour colour;
#if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
  colour = static_cast<wxFontPickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetSelectedColour();
#if defined (__APPLE__)
  return color::from_handle(reinterpret_cast<intptr_t>(colour.OSXGetNSColor()));
#endif
#endif
  return color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
}

void font_picker::color(intptr_t control, const drawing::color& color) {
  if (control == 0) return;
#if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
#if defined (__APPLE__)
  if (color.handle())
    static_cast<wxFontPickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetSelectedColour(wxColour(reinterpret_cast<WX_NSColor>(color.handle())));
  else
    static_cast<wxFontPickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetSelectedColour(wxColour(color.r(), color.g(), color.b(), color.a()));
#else
  static_cast<wxFontPickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetSelectedColour(wxColour(color.r(), color.g(), color.b(), color.a()));
#endif
#endif
}

font font_picker::font(intptr_t control) {
  wxFont font;
  if (control) font = static_cast<wxFontPickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetSelectedFont();
  return drawing::font::from_hfont(reinterpret_cast<intptr_t>(new wxFont(font)));
}

void font_picker::font(intptr_t control, const drawing::font& font) {
  if (control == 0) return;
  static_cast<wxFontPickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetSelectedFont(*reinterpret_cast<wxFont*>(font.handle()));
}
