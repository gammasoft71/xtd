#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/up_down_button.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_up_down_button.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void up_down_button::maximum(intptr_t control, int32_t maximum) {
  if (!control) return;
  static_cast<wxSpinButton*>(reinterpret_cast<control_handler*>(control)->control())->SetRange(static_cast<wxSpinButton*>(reinterpret_cast<control_handler*>(control)->control())->GetMin(), maximum);
}

void up_down_button::minimum(intptr_t control, int32_t minimum) {
  if (!control) return;
  static_cast<wxSpinButton*>(reinterpret_cast<control_handler*>(control)->control())->SetRange(minimum, static_cast<wxSpinButton*>(reinterpret_cast<control_handler*>(control)->control())->GetMax());
}

void up_down_button::value(intptr_t control, int32_t value) {
  if (!control) return;
  static_cast<wxSpinButton*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(value);
}

int32_t up_down_button::value(intptr_t control) {
  if (!control) return .0;
  return static_cast<wxSpinButton*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
}
