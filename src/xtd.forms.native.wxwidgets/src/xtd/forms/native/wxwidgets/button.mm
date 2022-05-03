#if defined(__APPLE__)
#include <xtd/argument_exception.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/button.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_button.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_color_picker.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <Quartz/Quartz.h>

using namespace xtd;
using namespace xtd::forms::native;

void __set_button_bezel_style__(wxButton* control, int32_t x, int32_t y, int32_t width, int32_t height) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (height <= 25) return;
  NSButton* button = reinterpret_cast<NSButton*>(control->GetHandle());
  [button setWantsLayer:YES];
  [button setBezelStyle: NSBezelStyleRegularSquare];
  [button setFrameOrigin:NSMakePoint(x, y)];
  [button setFrameSize:NSMakeSize(width, height)];
}
#endif
