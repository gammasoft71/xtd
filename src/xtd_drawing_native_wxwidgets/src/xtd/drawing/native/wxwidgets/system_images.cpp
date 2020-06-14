#include <atomic>
#if defined(__WXGTK__)
#include <gtk/gtk.h>
#endif
#include <wx/image.h>
#include <wx/bitmap.h>
#include <xtd/drawing/native/system_images.h>
#include <xtd/environment.h>
#include <xtd/xtd.io>
#include <xtd/xtd.strings>

using namespace xtd;
using namespace xtd::drawing::native;

#if defined(__WXOSX__)
intptr_t __osx_get_image_from_name__(const char* name, int32_t width, int32_t height);
#endif

std::string system_images::default_theme() {
  /*
   if (environment::os_version().is_windows_platform()) return "windows";
   if (environment::os_version().is_osx_platform()) return "macos";
   if (environment::os_version().is_linux_platform()) return "gnome";
   return "symbols";
   */

#if defined(__WXMSW__)
  return "windows";
#elif defined(__WXGTK__)
  auto current_desktop = xtd::environment::get_environment_variable("XDG_CURRENT_DESKTOP");
  if (current_desktop.empty()) return "symbols";
  if (strings::contains(current_desktop, "GNOME")) return "gnome";
  if (strings::contains(current_desktop, "KDE")) return "kde";
  return strings::to_lower(current_desktop);
#elif defined(__WXOSX__)
  return "macos";
#endif
  return "symbols";
}

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
  if (error || !icon) return 0;
  return reinterpret_cast<intptr_t>(new wxImage(wxBitmap(icon).ConvertToImage()));
#elif defined(__WXOSX__)
  return __osx_get_image_from_name__(name.c_str(), width, height);
#endif
  return 0;
}
