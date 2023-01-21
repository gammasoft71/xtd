#include <vector>
#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

auto main()->int {
  auto form_main = form::create("Main Form", point {screen::primary_screen().working_area().width() - 340, 40});
  form_main.start_position(form_start_position::manual);
  
  auto button = button::create(form_main, "Create", {10, 10});
  button.click += [&] {
    static vector<shared_ptr<form>> forms;
    static auto form_color = known_color::alice_blue;
    
    auto form = make_unique<forms::form>();
    form->text(ustring::format("{}", form_color));
    form->back_color(color::from_known_color(form_color));
    form->visible(true);
    forms.push_back(std::move(form));
    
    form_color = form_color != known_color::yellow_green ? known_color(int(form_color) + 1) : known_color::alice_blue;
  };
  
  application::run(form_main);
}
