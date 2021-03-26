#include <xtd/cdebug.h>
#include <xtd/forms/native/button.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_button.h"

using namespace xtd;
using namespace xtd::forms::native;

void button::set_default_button(intptr_t control) {
  if (control == 0 || reinterpret_cast<wx_button*>(control)->owner_draw_) return;
  static_cast<wxButton*>(reinterpret_cast<control_handler*>(control)->control())->SetDefault();
}
