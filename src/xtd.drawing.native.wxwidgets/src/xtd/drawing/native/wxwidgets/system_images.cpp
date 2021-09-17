#include <atomic>
#include <wx/image.h>
#include <wx/bitmap.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/system_images.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/convert_string.h>
#include <xtd/environment.h>

using namespace xtd;
using namespace xtd::drawing::native;

#if defined(__WXGTK__)
GdkPixbuf* __gtk_get_image_from_name__(const char* name, int32_t width, int32_t height);
#elif defined(__APPLE__)
intptr_t __macos_get_image_from_name__(const char* name, int32_t width, int32_t height);
#endif

intptr_t system_images::from_name(const ustring& name, int32_t width, int32_t height) {
#if defined(__WXMSW__)
  return 0;
#elif defined(__WXGTK__)
  GdkPixbuf* icon = __gtk_get_image_from_name__(name.c_str(), width, height);
  if (icon) return reinterpret_cast<intptr_t>(new wxImage(wxBitmap(icon).ConvertToImage()));
  return 0;
#elif defined(__APPLE__)
  intptr_t icon = __macos_get_image_from_name__(name.c_str(), width, height);
  if (icon) return icon;
  return 0;
#endif
}
