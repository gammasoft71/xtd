#include <xtd/drawing/native/system_images.h>
#include <xtd/xtd.io>
#include <xtd/xtd.strings>
#include <atomic>
#if defined(__WXGTK__)
#include <gtk/gtk.h>
#endif
#include <wx/image.h>
#include <wx/bitmap.h>

using namespace xtd;
using namespace xtd::drawing::native;

#if defined(__WXOSX__)
intptr_t __osx_get_image_from_name__(const char* name, int32_t width, int32_t height);
#endif

intptr_t system_images::from_name(const std::string& name, int32_t width, int32_t height) {
#if defined(__WXMSW__)
  return 0;
#elif defined(__WXGTK__)
  if (name.empty()) return 0;
  auto icon_theme = gtk_icon_theme_get_default();
  const char* icon_names[] = {name.c_str(), nullptr};
  GtkIconInfo* iconInfo = gtk_icon_theme_choose_icon(icon_theme, icon_names, width, GtkIconLookupFlags::GTK_ICON_LOOKUP_FORCE_SIZE);
  GError* error = nullptr;
  auto icon = gtk_icon_info_load_icon(iconInfo, &error);
  if (!icon) return 0;
  return reinterpret_cast<intptr_t>(new wxBitmap(icon));
#elif defined(__WXOSX__)
  return __osx_get_image_from_name__(name.c_str(), width, height);
#endif
  return 0;
}
