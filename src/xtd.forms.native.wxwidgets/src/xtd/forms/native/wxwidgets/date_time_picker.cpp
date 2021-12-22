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

void date_time_picker::allowable_dates(const intptr_t control, date_time min_date, date_time max_date) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  wxDateTime wx_min_date {min_date.to_time_t()};
  wxDateTime wx_max_date {max_date.to_time_t()};
  if (dynamic_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())) {
    // No range for WxTimePickerCtrl
    //static_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetRange(wx_min_date, wx_max_date);
  } else
    static_cast<wxDatePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetRange(wx_min_date, wx_max_date);
}

date_time date_time_picker::value(intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }
  if (dynamic_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())) {
    int32_t hour, min, sec;
    static_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetTime(&hour, &min, &sec);
    date_time now = date_time::now();
    return date_time(now.year(), now.month(), now.day(), static_cast<uint32_t>(hour), static_cast<uint32_t>(min), static_cast<uint32_t>(sec));
  } else {
    wxDateTime wx_date_time;
    wx_date_time = static_cast<wxDatePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
    return date_time::from_time_t(wx_date_time.GetTicks());
  }
}

void date_time_picker::value(intptr_t control, date_time value) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  wxDateTime wx_value {value.to_time_t()};
  if (dynamic_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control()))
    static_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetTime(value.hour(), value.minute(), value.second());
  else
    static_cast<wxDatePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(wx_value);
}
