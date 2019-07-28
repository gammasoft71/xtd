#include <memory>
#include <vector>
#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  vector<shared_ptr<form>> forms;
  known_color form_color = known_color::alice_blue;
  point location {20, 20};

  form main_form;
  main_form.text("Main Form");
  //main_form.start_position(form_start_position::manual);
  //main_form.location({screen::all_screens()[0].working_area().width() - main_form.width() - 20, 43});
  main_form.location({1280 - main_form.width() - 20, 43});

  button button;
  button.parent(main_form);
  button.text("Create");
  button.location({10, 10});
  button.click += [&](const control& sender, const event_args& e) {
    shared_ptr<form> form = make_shared<forms::form>();
    form->back_color(color::from_known_color(form_color));
    form->location(location);
    form->text(strings::format("{}", form_color));
    form->visible(true);
    forms.push_back(form);
    form_color = form_color != known_color::yellow_green ? (known_color)((int)form_color + 1) : known_color::alice_blue;
    location = {location.x() < 180 ? location.x() + 20 : 20, location.y() < 180 ? location.y() + 20 : 20};
  };
  
  application::run(main_form);
}
