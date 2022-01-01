#include <xtd/argument_exception.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/month_calendar.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_month_calendar.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void month_calendar::allowable_dates(const intptr_t control, date_time min_date, date_time max_date) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }

  wxCalendarCtrl* wx_calendar_ctrl = static_cast<wxCalendarCtrl*>(reinterpret_cast<control_handler*>(control)->control());
  wx_calendar_ctrl->SetDateRange({min_date.to_tm()}, {max_date.to_tm()});
}

void month_calendar::selection_range(const intptr_t control, date_time date_start, date_time date_end) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }

  wxCalendarCtrl* wx_calendar_ctrl = static_cast<wxCalendarCtrl*>(reinterpret_cast<control_handler*>(control)->control());
  wx_calendar_ctrl->SetDate({date_start.to_tm()});
}

pair<date_time, date_time> month_calendar::selection_range(const intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }

  wxDateTime wx_date_time = static_cast<wxCalendarCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetDate();
  date_time date = date_time(static_cast<uint32_t>(wx_date_time.GetYear()), static_cast<uint32_t>(wx_date_time.GetMonth()), static_cast<uint32_t>(wx_date_time.GetDay()), static_cast<uint32_t>(wx_date_time.GetHour()), static_cast<uint32_t>(wx_date_time.GetHour()), static_cast<uint32_t>(wx_date_time.GetMinute()), static_cast<uint32_t>(wx_date_time.GetSecond()), date_time_kind::unspecified);
  return {date, date};
}
