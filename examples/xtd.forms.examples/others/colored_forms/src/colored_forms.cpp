#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/screen>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

auto main() -> int {
  auto colored_forms = std::vector<std::unique_ptr<form>> {};
  auto form_color = known_color::alice_blue;
  auto form_main = form::create("Main Form", point {screen::primary_screen().working_area().width() - 340, 40});
  auto create_button = button::create(form_main, "Create", {10, 10});

  create_button.click += [&] {
    auto colored_form = std::make_unique<form>();
    colored_form->text(enum_object<>::to_string(form_color)).back_color(color::from_known_color(form_color)).visible(true);
    colored_forms.push_back(std::move(colored_form));
    form_color = form_color != known_color::yellow_green ? as<known_color>(as<int>(form_color) + 1) : known_color::alice_blue;
  };
  
  application::run(form_main);
}
