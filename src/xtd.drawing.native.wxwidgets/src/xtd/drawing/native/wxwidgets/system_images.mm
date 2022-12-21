#if defined(__WXOSX__)
#include <Quartz/Quartz.h>
#include <xtd/types.h>

using namespace xtd;

intptr __macos_get_image_from_name__(const char* name, int32 width, int32 height) {
  return 0;
}

#endif
