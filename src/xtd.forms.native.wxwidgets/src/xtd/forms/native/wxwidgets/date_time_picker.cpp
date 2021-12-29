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
  wxDateTime wx_date_time;
  if (dynamic_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control()))
    wx_date_time = static_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
  else
    wx_date_time = static_cast<wxDatePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
  return date_time(date_time::from_time_t(wx_date_time.GetTicks(), date_time_kind::local).ticks(), date_time_kind::unspecified);
}

void date_time_picker::value(intptr_t control, date_time value) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  wxDateTime wx_value {value.to_time_t()};
  if (dynamic_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control()))
    static_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(wx_value);
  else
    static_cast<wxDatePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(wx_value);
}
