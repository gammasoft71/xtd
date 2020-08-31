#include "../../../include/xtd/forms/theme.h"

using namespace xtd::forms;

const theme theme::empty {};
theme theme::current_theme_;

theme theme::theme_from_name(const std::string& name) {
  if (name == default_theme_name()) return theme(default_theme_name(), theme_style::system_auto, true);
  if (name == "gnome") return theme("gnome", theme_style::system_auto);
  if (name == "gnome (dark)") return theme("gnome (dark)", theme_style::dark);
  if (name == "gnome (light)") return theme("gnome (light)", theme_style::light);
  if (name == "kde") return theme("kde", theme_style::system_auto);
  if (name == "kde (dark)") return theme("kde (dark)", theme_style::dark);
  if (name == "kde (light)") return theme("kde (light)", theme_style::light);
  if (name == "macos") return theme("macos", theme_style::system_auto);
  if (name == "macos (dark)") return theme("macos (dark)", theme_style::dark);
  if (name == "macos (light)") return theme("macos (light)", theme_style::light);
  if (name == "windows") return theme("windows", theme_style::system_auto);
  if (name == "windows (dark)") return theme("windows (dark)", theme_style::dark);
  if (name == "windows (light)") return theme("windows (light)", theme_style::light);
  return default_theme();
}
