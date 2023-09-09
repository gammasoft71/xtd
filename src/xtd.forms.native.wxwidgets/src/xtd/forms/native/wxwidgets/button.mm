#if defined(__WXOSX__)
#include <xtd/argument_exception.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/button.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_button.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_color_picker.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <Quartz/Quartz.h>

using namespace xtd;
using namespace xtd::forms::native;

void __set_button_bezel_style__(wxAnyButton* control, int32 height) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  NSButton* button = reinterpret_cast<NSButton*>(control->GetHandle());
  [button setBezelStyle: height <= 25 ? NSBezelStyleRounded : NSBezelStyleRegularSquare];
}
#endif
