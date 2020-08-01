#if defined(__WXGTK__)
#include <gtk/gtk.h>

GdkPixbuf* __gtk_get_image_from_name__(const char* name, int32_t width, int32_t height) {
  if (name[0] == 0) return 0;
  auto icon_theme = gtk_icon_theme_get_default();
  const char* icon_names[] = {name, nullptr};
  GtkIconInfo* iconInfo = gtk_icon_theme_choose_icon(icon_theme, icon_names, width, GtkIconLookupFlags::GTK_ICON_LOOKUP_FORCE_SIZE);
  GError* error = nullptr;
  GdkPixbuf* icon = gtk_icon_info_load_icon(iconInfo, &error);
  if (!error && icon) return icon;
  return 0;
}
#endif
