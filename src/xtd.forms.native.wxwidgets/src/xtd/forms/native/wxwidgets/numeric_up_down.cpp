#include <xtd/argument_exception.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/numeric_up_down.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_numeric_up_down.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void numeric_up_down::decimal_place(intptr control, int32 decimal_place) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->SetDigits(decimal_place);
}

void numeric_up_down::increment(intptr control, double increment) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->SetIncrement(increment);
}

void numeric_up_down::maximum(intptr control, double maximum) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->SetRange(static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->GetMin(), maximum);
}

void numeric_up_down::minimum(intptr control, double minimum) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->SetRange(minimum, static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->GetMax());
}

void numeric_up_down::value(intptr control, double value) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(value);
  // Workaround : with wxWidgets version <= 3.1.4 when wxSpinCtrlDouble lost focus the value is changed by error.
  reinterpret_cast<wx_numeric_up_down*>(control)->value_ = value;
}

double numeric_up_down::value(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return 0.;
  }
  return static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
}
