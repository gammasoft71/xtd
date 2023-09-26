#if defined(__WXGTK__)
#include <xtd/types>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses"
#include <gtk/gtk.h>
#pragma GCC diagnostic pop

GdkPixbuf* __gtk_get_image_from_name__(const char* name, xtd::int32 width, xtd::int32 /*height*/) {
  if (name[0] == 0) return 0;
  auto icon_theme = gtk_icon_theme_get_default();
  const char* icon_names[] = {name, nullptr};
  GtkIconInfo* iconInfo = gtk_icon_theme_choose_icon(icon_theme, icon_names, width, GtkIconLookupFlags::GTK_ICON_LOOKUP_FORCE_SIZE);
  GError* error = nullptr;
  GdkPixbuf* icon =  iconInfo ? gtk_icon_info_load_icon(iconInfo, &error) : nullptr;
  if (!error && icon) return icon;
  return 0;
}
#endif
