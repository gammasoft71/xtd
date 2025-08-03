#include "../properties/settings.hpp"
#include <xtd/xtd>

using namespace application_settings::properties;

auto main() -> int {
  auto main_form = form::create(settings::default_settings().text(), form_start_position::manual);
  
  auto back_color_picker = color_picker::create(main_form, main_form.back_color(), {10, 10}, {75, 25});
  back_color_picker.color_picker_changed += delegate_ {
    main_form.back_color(back_color_picker.color());
  };
  
  auto save_button = button::create(main_form, "&Save", {90, 10});
  save_button.click += delegate_ {
    settings::default_settings().size(main_form.client_size());
    settings::default_settings().location(main_form.location());
    settings::default_settings().back_color(main_form.back_color());
    settings::default_settings().save();
  };
  
  auto reload_button = button::create(main_form, "&Reload", {170, 10});
  reload_button.click += delegate_ {
    main_form.client_size(settings::default_settings().size());
    main_form.location(settings::default_settings().location());
    main_form.back_color(settings::default_settings().back_color());
    back_color_picker.color(settings::default_settings().back_color());
  };
  
  auto reset_button = button::create(main_form, "R&eset", {250, 10});
  reset_button.click += delegate_ {
    settings::default_settings().reset();
    reload_button.perform_click();
  };
  
  reload_button.perform_click();
  
  application::run(main_form);
}
