#include <memory>
#include <vector>
#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  vector<shared_ptr<form>> colored_forms;
  auto form_color = known_color::alice_blue;

  auto main_form = control::create<forms::form>("Main form", {screen::primary_screen().working_area().width() - 340, 40});
  main_form->start_position(form_start_position::manual);

  auto new_form_button = control::create<forms::button>(*main_form, "New form", {10, 10});
  new_form_button->click += [&] {
    auto colored_form = control::create<forms::form>(strings::format("{}", form_color));
    colored_form->back_color(color::from_known_color(form_color));
    colored_form->visible(true);
    colored_forms.push_back(move(colored_form));
    form_color = form_color != known_color::yellow_green ? static_cast<known_color>(static_cast<int>(form_color) + 1) : known_color::alice_blue;
    main_form->activate();
  };
  
  application::run(*main_form);
}
