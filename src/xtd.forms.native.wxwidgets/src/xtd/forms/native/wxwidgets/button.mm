#if defined(__WXOSX__)
#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_button"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_color_picker"
#include <xtd/forms/native/button>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <Quartz/Quartz.h>
#include <Availability.h>

using namespace xtd;
using namespace xtd::forms::native;

void __set_button_bezel_style__(wxAnyButton* control, int32 height) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  NSButton* button = reinterpret_cast<NSButton*>(control->GetHandle());
#ifdef __MAC_14_0
  [button setBezelStyle: height <= 25 ? NSBezelStylePush : NSBezelStyleFlexiblePush];
#else
  [button setBezelStyle: height <= 25 ? NSBezelStyleRounded : NSBezelStyleRegularSquare];
#endif
}
#endif
