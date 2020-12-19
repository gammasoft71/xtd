#include <xtd/xtd>

using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  settings settings;
  auto main_form = control::create<form>("Settings example");
  main_form->start_position(form_start_position::manual);
  
  auto back_color_picker = control::create<color_picker>(*main_form, "", {10, 10}, {75, 25});
  back_color_picker->color_changed += [&] {
    main_form->back_color(back_color_picker->color());
  };
  
  auto save_button = control::create<button>(*main_form, "&Save", {90, 10});
  save_button->click += [&] {
    settings.write("size", main_form->client_size());
    settings.write("location", main_form->location());
    settings.write("back_color", main_form->back_color());
    settings.save();
  };
  
  auto reload_button = control::create<button>(*main_form, "&Reload", {170, 10});
  reload_button->click += [&] {
    main_form->client_size(settings.read("size", size {335, 45}));
    main_form->location(settings.read("location", point {100, 50}));
    main_form->back_color(settings.read("back_color", main_form->default_back_color()));
    back_color_picker->color(main_form->back_color());
  };
  
  auto reset_button = control::create<button>(*main_form, "R&eset", {250, 10});
  reset_button->click += [&] {
    settings.reset();
    reload_button->perform_click();
  };
  
  reload_button->perform_click();
  
  application::run(*main_form);
}
