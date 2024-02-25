#include "settings_form.h"
#include "../properties/settings.h"
#include <xtd/forms/open_file_dialog>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtdc_gui;

settings_form::settings_form() {
  controls().push_back_range({auto_close_label_, auto_close_check_box_, use_default_ide_label_, use_default_ide_check_box_, ide_path_label_, ide_path_text_box_, ide_path_button_});
  text(environment::os_version().is_macos() && environment::os_version().version().major() < 13 ? "Preferences" :  "Settings...");
  maximize_box(false);
  minimize_box(false);
  form_border_style(forms::form_border_style::fixed_3d);
  if (environment::os_version().is_macos()) back_color(application::style_sheet().system_colors().app_workspace());
  client_size({500, 200});
  start_position(form_start_position::manual);
  location(properties::settings::default_settings().settings_form_location());
  form_closed += [&] {properties::settings::default_settings().settings_form_location(location()).save();};
  
  auto_close_label_.location({0, 41});
  auto_close_label_.text("After open/create:");
  auto_close_label_.text_align(xtd::forms::content_alignment::middle_right);
  auto_close_label_.width(200);
  
  auto_close_check_box_.location({205, 40});
  auto_close_check_box_.text("Auto close");
  auto_close_check_box_.checked(properties::settings::default_settings().auto_close());
  auto_close_check_box_.width(295);
  auto_close_check_box_.checked_changed += [&] {properties::settings::default_settings().auto_close(auto_close_check_box_.checked()).save();};
  
  use_default_ide_label_.location({0, 71});
  use_default_ide_label_.text("When open/create project :");
  use_default_ide_label_.text_align(xtd::forms::content_alignment::middle_right);
  use_default_ide_label_.width(200);
  
  use_default_ide_check_box_.location({205, 70});
  use_default_ide_check_box_.text("Use default IDE");
  use_default_ide_check_box_.checked(properties::settings::default_settings().use_defaul_ide());
  use_default_ide_check_box_.width(295);
  use_default_ide_check_box_.checked_changed += [&] {
    properties::settings::default_settings().use_defaul_ide(use_default_ide_check_box_.checked()).save();
    ide_path_label_.enabled(!use_default_ide_check_box_.checked());
    ide_path_text_box_.enabled(!use_default_ide_check_box_.checked());
    ide_path_button_.enabled(!use_default_ide_check_box_.checked());
  };

  ide_path_label_.enabled(!use_default_ide_check_box_.checked());
  ide_path_label_.location({0, 101});
  ide_path_label_.text("IDE path :");
  ide_path_label_.text_align(xtd::forms::content_alignment::middle_right);
  ide_path_label_.width(200);
  
  ide_path_text_box_.enabled(!use_default_ide_check_box_.checked());
  ide_path_text_box_.location({205, 100});
  ide_path_text_box_.text(properties::settings::default_settings().user_path_ide());
  ide_path_text_box_.width(200);
  ide_path_text_box_.text_changed += [&] {properties::settings::default_settings().user_path_ide(ide_path_text_box_.text()).save();};
  
  ide_path_button_.enabled(!use_default_ide_check_box_.checked());
  ide_path_button_.location({415, 100});
  ide_path_button_.text("Browse...");
  ide_path_button_.click += [&] {
    open_file_dialog dialog;
    
    if (dialog.show_sheet_dialog(*this) == dialog_result::ok) ide_path_text_box_.text(dialog.file_name());
  };
}

void settings_form::on_form_closed(const form_closed_event_args& e) {
  form::on_form_closed(e);
  properties::settings::default_settings().auto_close(auto_close_check_box_.checked()).save();
}
