#include <xtd/xtd>

auto main() -> int {
  auto colored_forms = list<ptr<form>> {};
  auto form_color = known_color::alice_blue;
  auto form_main = form::create("Main Form", point {screen::primary_screen().working_area().width - 340, 40});
  auto create_button = button::create(form_main, "Create", {10, 10});

  create_button.click += delegate_ {
    auto colored_form = new_ptr<form>();
    colored_form->text(enum_object<>::to_string(form_color)).back_color(color::from_known_color(form_color)).visible(true);
    colored_forms.add(colored_form);
    form_color = form_color != known_color::yellow_green ? as<known_color>(as<int>(form_color) + 1) : known_color::alice_blue;
  };
  
  application::run(form_main);
}
