#include <tuple>
#include <xtd/argument_exception.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/date_time_picker.h>
#include <xtd/forms/native/content_alignment.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_date_time_picker.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void date_time_picker::allowable_dates(const intptr control, date_time min_date, date_time max_date) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
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
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
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
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  wxDateTime wx_date_time(value.day(), static_cast<wxDateTime::Month>(value.month() - 1), value.year(), value.hour(), value.minute(), value.second());
  if (dynamic_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control()))
    static_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(wx_date_time);
  else
    static_cast<wxDatePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(wx_date_time);
}
