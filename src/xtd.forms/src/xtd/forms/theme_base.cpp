#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/theme_base.h"

using namespace xtd::forms;

const theme_base theme_base::empty {};
theme_base::theme_name_collection theme_base::theme_names_ {"gnome", "gnome (dark)", "gnome (light)", "kde", "kde (dark)", "kde (light)", "macos", "macos (dark)", "macos (light)", "symbolic", "symbolic (dark)", "symbolic (light)", "windows", "windows (dark)", "windows (light)", "xtd", "xtd (dark)", "xtd (light)"};

xtd::ustring theme_base::default_theme_name() {
  return xtd::environment::os_version().desktop_environment() == "" ? fallback_theme_name() :  xtd::environment::os_version().desktop_environment();
  /*
  if (application::style_sheet().theme().name() == "Gnome (dark)") return "gnome (dark)";
  if (application::style_sheet().theme().name() == "Gnome (light)") return "gnome (light)";
  if (application::style_sheet().theme().name() == "KDE (dark)") return "kde (dark)";
  if (application::style_sheet().theme().name() == "KDE (light)") return "kde (light)";
  if (application::style_sheet().theme().name() == "macOS (dark)") return "macos (dark)";
  if (application::style_sheet().theme().name() == "macOS (light)") return "macos (light)";
  if (application::style_sheet().theme().name() == "Symbolic (dark)") return "symbolic (dark)";
  if (application::style_sheet().theme().name() == "Symbolic (light)") return "symbolic (light)";
  if (application::style_sheet().theme().name() == "Windows (dark)") return "windows (dark)";
  if (application::style_sheet().theme().name() == "Windows (light)") return "windows (light)";
  if (application::style_sheet().theme().name() == "xtd (dark)") return "xtd (dark)";
  if (application::style_sheet().theme().name() == "xtd (light)") return "xtd (light)";
  return fallback_theme_name();
   */
}
