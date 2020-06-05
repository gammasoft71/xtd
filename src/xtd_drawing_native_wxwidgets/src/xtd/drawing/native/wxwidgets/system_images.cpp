#include <xtd/drawing/native/system_images.h>
#include <xtd/xtd.io>
#include <xtd/xtd.strings>
#include <atomic>
#include <wx/image.h>
#include <wx/palette.h>
#include <wx/stream.h>

using namespace xtd;
using namespace xtd::drawing::native;

#if defined(__WXOSX__)
intptr_t __osx_get_image_from_name__(const char* name, int32_t width, int32_t height);
#endif

intptr_t system_images::from_name(const std::string& name, int32_t width, int32_t height) {
#if defined(__WXMSW__)
  return 0;
#elif defined(__WXGTK__)
  /// @todo get systemicons....
  return 0;
#elif defined(__WXOSX__)
  return __osx_get_image_from_name__(name.c_str(), width, height);
#endif
  return 0;
}
