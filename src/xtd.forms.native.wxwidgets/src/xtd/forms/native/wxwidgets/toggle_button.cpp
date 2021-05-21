#include <map>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/toggle_button.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_toggle_button.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void toggle_button::check_state(intptr_t control, int state) {
  if (control == 0 || reinterpret_cast<wx_toggle_button*>(control)->owner_draw_) return;
  static_cast<wxToggleButton*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(state);
}
