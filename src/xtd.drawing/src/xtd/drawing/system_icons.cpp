#include "../../../include/xtd/drawing/system_icons"

using namespace xtd::drawing;

icon system_icons::application() noexcept {
  return application(default_size());
}

icon system_icons::application(const size& size) noexcept {
  return from_name("application-x-executable", size);
}

icon system_icons::asterisk() noexcept {
  return information(default_size());
}

icon system_icons::asterisk(const size& size) noexcept {
  return information(size);
}

icon system_icons::error() noexcept {
  return error(default_size());
}

icon system_icons::error(const size& size) noexcept {
  return from_name("dialog-error", size);
}

icon system_icons::exclamation() noexcept {
  return exclamation(default_size());
}

icon system_icons::exclamation(const size& size) noexcept {
  return from_name("dialog-warning", size);
}

icon system_icons::hand() noexcept {
  return error(default_size());
}

icon system_icons::hand(const size& size) noexcept {
  return error(size);
}

icon system_icons::information() noexcept {
  return information(default_size());
}

icon system_icons::information(const size& size) noexcept {
  return from_name("dialog-information", size);
}

icon system_icons::question() noexcept {
  return question(default_size());
}

icon system_icons::question(const size& size) noexcept {
  return from_name("dialog-question", size);
}

icon system_icons::shield() noexcept {
  return shield(default_size());
}

icon system_icons::shield(const size& size) noexcept {
  return from_name("dialog-password", size);
}

icon system_icons::warning() noexcept {
  return exclamation(default_size());
}

icon system_icons::warning(const size& size) noexcept {
  return exclamation(size);
}

icon system_icons::win_logo() noexcept {
  return windows_logo(default_size());
}

icon system_icons::win_logo(const size& size) noexcept {
  return windows_logo(size);
}

size system_icons::default_size() noexcept {
  return {32, 32};
}

icon system_icons::kde_logo() noexcept {
  return kde_logo(default_size());
}

icon system_icons::kde_logo(const size& size) noexcept {
  return from_name("kde", "start-here", size);
}

icon system_icons::macos_logo() noexcept {
  return macos_logo(default_size());
}

icon system_icons::macos_logo(const size& size) noexcept {
  return from_name("macos", "start-here", size);
}

icon system_icons::gnome_logo() noexcept {
  return gnome_logo(default_size());
}

icon system_icons::gnome_logo(const size& size) noexcept {
  return from_name("gnome", "start-here", size);
}

icon system_icons::symbolic_logo() noexcept {
  return symbolic_logo(default_size());
}

icon system_icons::symbolic_logo(const size& size) noexcept {
  return from_name("symbolic", "start-here", size);
}

icon system_icons::windows_logo() noexcept {
  return windows_logo(default_size());
}

icon system_icons::windows_logo(const size& size) noexcept {
  return from_name("windows", "start-here", size);
}

icon system_icons::gammasoft() noexcept {
  return gammasoft(default_size());
}

icon system_icons::gammasoft(const size& size) noexcept {
  return from_name("gammasoft", size);
}

icon system_icons::xtd_logo() noexcept {
  return xtd_logo(default_size());
}

icon system_icons::xtd_logo(const size& size) noexcept {
  return from_name("xtd", size);
}

icon system_icons::xtd_forms_logo() noexcept {
  return xtd_forms_logo(default_size());
}

icon system_icons::xtd_forms_logo(const size& size) noexcept {
  return from_name("xtd-forms", size);
}

icon system_icons::from_name(const xtd::ustring& name) {
  return from_name(system_images_base::default_theme(), name, default_size());
}

icon system_icons::from_name(const xtd::ustring& name, const size& size) {
  return from_name(system_images_base::default_theme(), name, size);
}

icon system_icons::from_name(const xtd::ustring& theme, const xtd::ustring& name) {
  return from_name(theme, name, default_size());
}

icon system_icons::from_name(const xtd::ustring& theme, const xtd::ustring& name, const size& size) {
  return icon::from_bitmap(bitmap(system_images::from_name(theme, name, size)));
}
