#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_numeric_up_down.hpp"
#include <xtd/forms/native/numeric_up_down>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::forms::native;
using namespace xtd::helpers;

void numeric_up_down::decimal_place(intptr control, int32 decimal_place) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->SetDigits(decimal_place);
}

void numeric_up_down::increment(intptr control, double increment) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->SetIncrement(increment);
}

void numeric_up_down::maximum(intptr control, double maximum) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->SetRange(static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->GetMin(), maximum);
}

void numeric_up_down::minimum(intptr control, double minimum) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->SetRange(minimum, static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->GetMax());
}

void numeric_up_down::value(intptr control, double value) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(value);
  // Workaround : with wxWidgets version <= 3.1.4 when wxSpinCtrlDouble lost focus the value is changed by error.
  reinterpret_cast<wx_numeric_up_down*>(control)->value_ = value;
}

double numeric_up_down::value(intptr control) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return 0.;
  }
  return static_cast<wxSpinCtrlDouble*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
}
