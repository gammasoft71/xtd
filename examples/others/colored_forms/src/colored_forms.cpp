#include <memory>
#include <vector>
#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  vector<shared_ptr<form>> forms;
  auto form_color = known_color::alice_blue;

  button button;
  button.text("Create");
  button.location({10, 10});
  button.click += [&] {
    auto form = make_shared<forms::form>();
    form->back_color(color::from_known_color(form_color));
    form->text(strings::format("{}", form_color));
    form->visible(true);
    forms.push_back(form);
    form_color = form_color != known_color::yellow_green ? static_cast<known_color>(static_cast<int>(form_color) + 1) : known_color::alice_blue;
  };

  form form_main;
  form_main.text("Main Form");
  form_main.start_position(form_start_position::manual);
  form_main.location({screen::primary_screen().working_area().width() - form_main.width() - 40, 40});
  form_main.controls().push_back(button);
  application::run(form_main);
}
