#include <tuple>
#include <xtd/forms/native/date_time_picker.h>
#include <xtd/forms/native/content_alignment.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_date_time_picker.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

std::chrono::system_clock::time_point date_time_picker::value(intptr_t control) {
  if (!control) return {};
  wxDateTime wx_date_time;
  if (dynamic_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control()))
    wx_date_time = static_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
  else
    wx_date_time = static_cast<wxDatePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
  return std::chrono::system_clock::from_time_t(wx_date_time.GetTicks());
}

void date_time_picker::value(intptr_t control, std::chrono::system_clock::time_point date_time) {
  if (control == 0) return;
  wxDateTime wx_date_time {std::chrono::system_clock::to_time_t(date_time)};
  if (dynamic_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control()))
    static_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(wx_date_time);
  else
    static_cast<wxDatePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(wx_date_time);
}
