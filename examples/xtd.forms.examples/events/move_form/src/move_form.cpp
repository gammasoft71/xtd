#include <xtd/forms/application>
#include <xtd/forms/form>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

auto main() -> int {
  auto main_form = form::create("Move form");
  auto mouse_location = point::empty;
  main_form.mouse_down += delegate_(object & sender, const mouse_event_args & e) {
    mouse_location = e.location();
    main_form.cursor(cursors::no_move_2d());
  };
  main_form.mouse_up += delegate_(object & sender, const mouse_event_args & e) {
    mouse_location = point::empty;
    main_form.cursor(cursors::default_cursor());
  };
  main_form.mouse_move += delegate_(object & sender, const mouse_event_args & e) {
    if (mouse_location != point::empty) main_form.location(main_form.location() + e.location() - mouse_location);
  };
  application::run(main_form);
}
