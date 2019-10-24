#if defined(__APPLE__)
#include <xtd/forms/native/button.hpp>
#include "wx_button.hpp"
#include <Quartz/Quartz.h>

using namespace xtd::forms::native;

void __set_button_bezel_style__(wxButton* control, size_t height) {
  NSButton* button = (NSButton*)control->GetHandle();
  [button setBezelStyle: height <= 32 ? NSBezelStyleRounded : NSBezelStyleSmallSquare];
}
#endif
