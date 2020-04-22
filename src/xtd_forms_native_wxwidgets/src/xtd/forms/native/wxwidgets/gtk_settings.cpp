#if defined(__WXGTK__)
#include <gtk/gtk.h>

void __gtk_button_image__(bool button_image) {
  g_object_set(gtk_settings_get_default(), "gtk-button-images", button_image, nullptr);
}

void __gtk_application_prefer_dark_theme__(bool prefer_dark_theme) {
  g_object_set(gtk_settings_get_default(), "gtk-application-prefer-dark-theme", prefer_dark_theme, nullptr);
}
#endif
