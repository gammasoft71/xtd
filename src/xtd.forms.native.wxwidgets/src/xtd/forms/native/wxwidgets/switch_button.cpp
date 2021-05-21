#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/switch_button.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_switch_button.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void switch_button::checked(intptr_t control, bool checked) {
  if (control == 0 || reinterpret_cast<wx_switch_button*>(control)->owner_draw_) return;
  static_cast<wxToggleButton*>(reinterpret_cast<wx_switch_button*>(control)->control())->SetValue(checked);
}
