#if defined(__APPLE__)
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/button.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_button.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_color_picker.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <Quartz/Quartz.h>

using namespace xtd::forms::native;

void __set_button_bezel_style__(wxButton* control, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (control == 0) return;
  NSButton* button = (NSButton*)control->GetHandle();
  [button setWantsLayer:YES];
  if (height >= 20 && height <= 25)
    [button setBezelStyle: NSBezelStyleRounded];
  else {
    [button setBezelStyle: NSBezelStyleRegularSquare];
    [button setFrameOrigin:NSMakePoint(x, y)];
    [button setFrameSize:NSMakeSize(width, height)];
  }
}
#endif
