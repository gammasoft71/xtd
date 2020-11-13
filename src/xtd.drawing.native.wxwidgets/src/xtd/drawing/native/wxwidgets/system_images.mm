#if defined(__APPLE__)
#include <Quartz/Quartz.h>

intptr_t __macos_get_image_from_name__(const char* name, int32_t width, int32_t height) {
  return 0;
}

#endif
