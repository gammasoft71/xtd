#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/color_picker>
#include <xtd/forms/form>
#include <xtd/forms/settings>

using namespace xtd::drawing;
using namespace xtd::forms;

auto main()->int {
  settings settings;
  auto main_form = form::create("Settings example", form_start_position::manual);
  
  auto back_color_picker = color_picker::create(main_form, main_form.back_color(), {10, 10}, {75, 25});
  back_color_picker.color_picker_changed += [&] {
    main_form.back_color(back_color_picker.color());
  };
  
  auto save_button = button::create(main_form, "&Save", {90, 10});
  save_button.click += [&] {
    settings.write("size", main_form.client_size());
    settings.write("location", main_form.location());
    settings.write("back_color", main_form.back_color());
    settings.save();
  };
  
  auto reload_button = button::create(main_form, "&Reload", {170, 10});
  reload_button.click += [&] {
    main_form.client_size(settings.read("size", size {335, 45}));
    main_form.location(settings.read("location", point {100, 50}));
    main_form.back_color(settings.read("back_color", main_form.back_color()));
    back_color_picker.color(main_form.back_color());
  };
  
  auto reset_button = button::create(main_form, "R&eset", {250, 10});
  reset_button.click += [&] {
    settings.reset();
    reload_button.perform_click();
  };
  
  reload_button.perform_click();
  
  application::run(main_form);
}
