#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_date_time_picker.hpp"
#include <xtd/forms/native/date_time_picker>
#include <xtd/forms/native/content_alignment>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <tuple>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::forms::native;
using namespace xtd::helpers;

void date_time_picker::allowable_dates(const intptr control, date_time min_date, date_time max_date) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().chars().c_str());
    return;
  }
  wxDateTime wx_min_date_time(min_date.day(), static_cast<wxDateTime::Month>(min_date.month() - 1), min_date.year(), min_date.hour(), min_date.minute(), min_date.second());
  wxDateTime wx_max_date_time(max_date.day(), static_cast<wxDateTime::Month>(max_date.month() - 1), max_date.year(), max_date.hour(), max_date.minute(), max_date.second());
  if (dynamic_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())) {
    // No range for WxTimePickerCtrl
    //static_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetRange(wx_min_date_time, wx_max_date_time);
  } else
    static_cast<wxDatePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetRange(wx_min_date_time, wx_max_date_time);
}

date_time date_time_picker::value(intptr control) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().chars().c_str());
    return {};
  }
  wxDateTime wx_date_time;
  if (dynamic_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control()))
    wx_date_time = static_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
  else
    wx_date_time = static_cast<wxDatePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
  return date_time(wx_date_time.GetYear(), static_cast<uint32>(wx_date_time.GetMonth()) + 1, wx_date_time.GetDay(), wx_date_time.GetHour(), wx_date_time.GetMinute(), wx_date_time.GetSecond(), date_time_kind::unspecified);
}

void date_time_picker::value(intptr control, date_time value) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().chars().c_str());
    return;
  }
  wxDateTime wx_date_time(value.day(), static_cast<wxDateTime::Month>(value.month() - 1), value.year(), value.hour(), value.minute(), value.second());
  if (dynamic_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control()))
    static_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(wx_date_time);
  else
    static_cast<wxDatePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(wx_date_time);
}
