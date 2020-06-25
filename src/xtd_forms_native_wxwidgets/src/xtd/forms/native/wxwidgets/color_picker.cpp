#include <xtd/forms/native/color_picker.h>
#include <xtd/forms/native/content_alignment.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_color_picker.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

color color_picker::color(intptr_t control) {
  if (!control) return {};
  wxColour colour = static_cast<wxColourPickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetColour();
//#if defined (__APPLE__)
//  return color::from_handle(reinterpret_cast<intptr_t>(colour.OSXGetNSColor()));
//#endif
  return color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
}

void color_picker::color(intptr_t control, const drawing::color& color) {
  if (control == 0) return;
#if defined (__APPLE__)
  if (color.handle())
    static_cast<wxColourPickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetColour(wxColour(reinterpret_cast<WX_NSColor>(color.handle())));
  else
    static_cast<wxColourPickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetColour(wxColour(color.r(), color.g(), color.b(), color.a()));
#else
  static_cast<wxColourPickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetColour(wxColour(color.r(), color.g(), color.b(), color.a()));
#endif
}
