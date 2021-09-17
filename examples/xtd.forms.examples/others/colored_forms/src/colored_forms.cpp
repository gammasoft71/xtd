#include <vector>
#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  auto form_main = control::create<forms::form>("Main Form", {screen::primary_screen().working_area().width() - 340, 40});
  form_main->start_position(form_start_position::manual);

  auto button = control::create<forms::button>(*form_main, "Create", {10, 10});
  button->click += [&] {
    static vector<shared_ptr<form>> forms;
    static auto form_color = known_color::alice_blue;
    
    auto form = control::create<forms::form>(ustring::format("{}", form_color));
    form->back_color(color::from_known_color(form_color));
    form->visible(true);
    forms.push_back(move(form));
    
    form_color = form_color != known_color::yellow_green ? static_cast<known_color>(static_cast<int>(form_color) + 1) : known_color::alice_blue;
  };

  application::run(*form_main);
}
