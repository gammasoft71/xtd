#if defined(__APPLE__)
#include <Quartz/Quartz.h>
#include <xtd/types.h>

intptr_t __macos_get_image_from_name__(const char* name, xtd::int32 width, xtd::int32 height) {
  return 0;
}

#endif
