#if defined(__APPLE__)
#include "get_double_click_time.hpp"
#include <xtd/int32>
#include <AppKit/NSEvent.h>

xtd::int32 get_double_click_time() {
  return [NSEvent doubleClickInterval] * 1000;
}
#endif
