#include <map>
#include <xtd/forms/native/toggle_button.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_toggle_button.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void toggle_button::check_state(intptr_t control, int state) {
  if (control == 0 || reinterpret_cast<wx_toggle_button*>(control)->owner_draw_) return;
  static_cast<wxToggleButton*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(state);
}
