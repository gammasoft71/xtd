#if defined(__APPLE__)
#include "get_double_click_time.h"
#include <AppKit/NSEvent.h>
#include <xtd/types>

xtd::int32 get_double_click_time() {
  return [NSEvent doubleClickInterval] * 1000;
}
#endif
