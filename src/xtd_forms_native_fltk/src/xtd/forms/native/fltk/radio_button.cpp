#include <xtd/forms/native/radio_button.hpp>
#include "fl_radio_button.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

bool radio_button::checked(intptr_t control) {
  if (control == 0) return false;
  return static_cast<Fl_Radio_Toggle_Button*>(reinterpret_cast<control_handler*>(control)->control())->state();
}

void radio_button::checked(intptr_t control, bool checked) {
  if (control == 0) return;
  static_cast<Fl_Radio_Toggle_Button*>(reinterpret_cast<control_handler*>(control)->control())->state(checked);
}
