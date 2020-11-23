#include <xtd/xtd>
#include "properties/settings.hpp"

using namespace xtd::forms;

int main() {
  auto main_form = control::create<form>("Settings example");

  auto colored_panel = control::create<panel>(*main_form, "", {10, 100});

  auto color_chooser = control::create<color_picker>(*main_form, "", {10, 10}, {75, 25});
  color_chooser->color_changed += [&] {
    colored_panel->back_color(color_chooser->color());
  };

  auto save_button = control::create<button>(*main_form, "&Save", {100, 10});
  save_button->click += [&] {
    settings_command::properties::settings::default_settings().color(colored_panel->back_color());
    settings_command::properties::settings::default_settings().save();
  };
  
  auto reload_button = control::create<button>(*main_form, "&Reload", {10, 50});
  reload_button->click += [&] {
    settings_command::properties::settings::default_settings().reload();
    colored_panel->back_color(settings_command::properties::settings::default_settings().color());
    color_chooser->color(settings_command::properties::settings::default_settings().color());
  };
  
  auto reset_button = control::create<button>(*main_form, "Rese&t", {100, 50});
  reset_button->click += [&] {
    settings_command::properties::settings::default_settings().reset();
    reload_button->perform_click();
  };

  reload_button->perform_click();
  application::run(*main_form);
}
