#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/color_picker>
#include <xtd/forms/form>
#include <xtd/forms/panel>
#include "properties/settings.h"

using namespace xtd::forms;

auto main() -> int {
  auto main_form = form::create("Settings example");
  
  auto colored_panel = panel::create(main_form, {10, 100});
  
  auto color_chooser = color_picker::create(main_form, colored_panel.back_color(), {10, 10}, {75, 25});
  color_chooser.color_picker_changed += [&] {
    colored_panel.back_color(color_chooser.color());
  };
  
  auto save_button = button::create(main_form, "&Save", {100, 10});
  save_button.click += [&] {
    settings_command::properties::settings::default_settings().color(colored_panel.back_color());
    settings_command::properties::settings::default_settings().save();
  };
  
  auto reload_button = button::create(main_form, "&Reload", {10, 50});
  reload_button.click += [&] {
    settings_command::properties::settings::default_settings().reload();
    colored_panel.back_color(settings_command::properties::settings::default_settings().color());
    color_chooser.color(settings_command::properties::settings::default_settings().color());
  };
  
  auto reset_button = button::create(main_form, "Rese&t", {100, 50});
  reset_button.click += [&] {
    settings_command::properties::settings::default_settings().reset();
    reload_button.perform_click();
  };
  
  reload_button.perform_click();
  application::run(main_form);
}
