#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/system_images>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/convert_string>
#include <xtd/environment>
#include <wx/image.h>
#include <wx/bitmap.h>

using namespace xtd;
using namespace xtd::drawing::native;

#if defined(__WXGTK__)
GdkPixbuf* __gtk_get_image_from_name__(const char* name, int32 width, int32 height);
#elif defined(__WXOSX__)
intptr __macos_get_image_from_name__(const char* name, int32 width, int32 height);
#endif

intptr system_images::from_name(const ustring& name, int32 width, int32 height) {
  #if defined(__WXMSW__)
  return 0;
  #elif defined(__WXGTK__)
  GdkPixbuf* icon = __gtk_get_image_from_name__(name.c_str(), width, height);
  if (icon) return reinterpret_cast<intptr>(new wxImage(wxBitmap(icon).ConvertToImage()));
  return 0;
  #elif defined(__WXOSX__)
  intptr icon = __macos_get_image_from_name__(name.c_str(), width, height);
  if (icon) return icon;
  return 0;
  #endif
}
