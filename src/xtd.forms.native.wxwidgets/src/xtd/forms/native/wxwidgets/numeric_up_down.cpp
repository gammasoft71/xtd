#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/numeric_up_down.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_numeric_up_down.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void numeric_up_down::decimal_place(intptr_t control, int32_t decimal_place) {
  if (!control) return;
  static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->SetDigits(decimal_place);
}

void numeric_up_down::increment(intptr_t control, double increment) {
  if (!control) return;
  static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->SetIncrement(increment);
}

void numeric_up_down::maximum(intptr_t control, double maximum) {
  if (!control) return;
  static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->SetRange(static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->GetMin(), maximum);
}

void numeric_up_down::minimum(intptr_t control, double minimum) {
  if (!control) return;
  static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->SetRange(minimum, static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->GetMax());
}

void numeric_up_down::value(intptr_t control, double value) {
  if (!control) return;
  static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(value);
  // Workaround : with wxWidgets version <= 3.1.4 when wxSpinCtrlDouble lost focus the value is changed by error.
  reinterpret_cast<wx_numeric_up_down*>(control)->value_ = value;
}

double numeric_up_down::value(intptr_t control) {
  if (!control) return .0;
  return static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
}
