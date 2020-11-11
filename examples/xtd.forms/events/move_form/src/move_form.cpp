#include <xtd/xtd.forms>

using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  auto main_form = control::create<form>("Move form");
  auto mouse_location = point::empty;
  main_form->mouse_down += [&](control& sender, const mouse_event_args& e) {
    mouse_location = e.location();
    main_form->cursor(cursors::no_move_2d());
  };
  main_form->mouse_up += [&](control& sender, const mouse_event_args& e) {
    mouse_location = point::empty;
    main_form->cursor(cursors::default_cursor());
  };
  main_form->mouse_move += [&](control& sender, const mouse_event_args& e) {
    if (mouse_location != point::empty) main_form->location(main_form->location() + e.location() - mouse_location);
  };
  application::run(*main_form);
}
