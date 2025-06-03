#include "settings_form.hpp"
#include "../properties/settings.hpp"
#include <xtd/forms/application>

using namespace ball;
using namespace xtd;
using namespace xtd::forms;

settings_form::settings_form() {
  text(environment::os_version().is_macos() && environment::os_version().version().major() < 13 ? "Preferences" :  "Settings...");
  maximize_box(false);
  minimize_box(false);
  form_border_style(forms::form_border_style::fixed_3d);
  if (environment::os_version().is_macos()) back_color(application::style_sheet().system_colors().app_workspace());
  client_size({500, 200});
  start_position(form_start_position::manual);
  location(properties::settings::default_settings().settings_form_location());
}
