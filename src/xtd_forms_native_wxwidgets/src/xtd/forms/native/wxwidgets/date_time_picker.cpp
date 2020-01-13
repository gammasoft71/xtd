#include <tuple>
#include <xtd/forms/native/date_time_picker.hpp>
#include <xtd/forms/native/content_alignment.hpp>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_date_time_picker.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  std::tuple<wxDateTime, wxDateTime> GetRange(intptr_t control) {
    if (!dynamic_cast<wxDatePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())) return {};
    wxDateTime wx_min_date, wx_max_date;
    static_cast<wxDatePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetRange(&wx_min_date, &wx_max_date);
    return {wx_min_date, wx_max_date};
  }
}

void date_time_picker::max_date(intptr_t control, const std::tm& max_date) {
  if (control == 0) return;
  auto [wx_min_date, wx_max_date] = GetRange(control);
  wx_max_date = wxDateTime {static_cast<wxDateTime::wxDateTime_t>(max_date.tm_mday), static_cast<wxDateTime::Month>(max_date.tm_mon), 1900 + max_date.tm_year, static_cast<wxDateTime::wxDateTime_t>(max_date.tm_hour), static_cast<wxDateTime::wxDateTime_t>(max_date.tm_min), static_cast<wxDateTime::wxDateTime_t>(max_date.tm_sec)};
  if (dynamic_cast<wxDatePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control()))
    static_cast<wxDatePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetRange(wx_min_date, wx_max_date);
}

void date_time_picker::min_date(intptr_t control, const std::tm& min_date) {
  if (control == 0) return;
  auto [wx_min_date, wx_max_date] = GetRange(control);
  wx_min_date = wxDateTime {static_cast<wxDateTime::wxDateTime_t>(min_date.tm_mday), static_cast<wxDateTime::Month>(min_date.tm_mon), 1900 + min_date.tm_year, static_cast<wxDateTime::wxDateTime_t>(min_date.tm_hour), static_cast<wxDateTime::wxDateTime_t>(min_date.tm_min), static_cast<wxDateTime::wxDateTime_t>(min_date.tm_sec)};
  if (dynamic_cast<wxDatePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control()))
    static_cast<wxDatePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetRange(wx_min_date, wx_max_date);
}

std::tm date_time_picker::value(intptr_t control) {
  if (!control) return {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, nullptr};
  wxDateTime wx_date_time;
  if (dynamic_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control()))
    wx_date_time = static_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
  else
    wx_date_time = static_cast<wxDatePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetValue();
  return {wx_date_time.GetSecond(), wx_date_time.GetMinute(), wx_date_time.GetHour(), wx_date_time.GetDay(), wx_date_time.GetMonth(), wx_date_time.GetYear() - 1900, wx_date_time.GetWeekDay(), wx_date_time.GetDayOfYear(), wx_date_time.IsDST(), 0, nullptr};
}

void date_time_picker::value(intptr_t control, const std::tm& date_time) {
  if (control == 0) return;
  wxDateTime wx_date_time {static_cast<wxDateTime::wxDateTime_t>(date_time.tm_mday), static_cast<wxDateTime::Month>(date_time.tm_mon), 1900 + date_time.tm_year, static_cast<wxDateTime::wxDateTime_t>(date_time.tm_hour), static_cast<wxDateTime::wxDateTime_t>(date_time.tm_min), static_cast<wxDateTime::wxDateTime_t>(date_time.tm_sec)};
  if (dynamic_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control()))
    static_cast<wxTimePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(wx_date_time);
  else
    static_cast<wxDatePickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(wx_date_time);
}
