#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

int main() {
  settings settings;
  auto main_form = control::create<form>("Test Gui");
  main_form->start_position(form_start_position::manual);

  auto color_picker = control::create<forms::color_picker>(*main_form, "", {10, 10}, {75, 25});
  color_picker->color_changed += [&] {
    main_form->back_color(color_picker->color());
  };

  auto save_button = control::create<button>(*main_form, "&Save", {90, 10});
  save_button->click += [&] {
    settings.write("client_size", main_form->client_size());
    settings.write("location", main_form->location());
    settings.write("back_color", main_form->back_color());
    settings.save();
  };

  auto reload_button = control::create<button>(*main_form, "&Reload", {170, 10});
  reload_button->click += [&] {
    main_form->client_size(settings.read("client_size", drawing::size {360, 80}));
    main_form->location(settings.read("location", drawing::point {100, 50}));
    main_form->back_color(settings.read("back_color", main_form->default_back_color()));
    color_picker->color(main_form->back_color());
  };

  auto reset_button = control::create<button>(*main_form, "R&eset", {250, 10});
  reset_button->click += [&] {
    settings.reset();
    reload_button->perform_click();
  };
  
  reload_button->perform_click();

  application::run(*main_form);
}
