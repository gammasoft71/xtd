#include <xtd/argument_exception.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/month_calendar.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_month_calendar.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace std;
using namespace std::chrono;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void month_calendar::allowable_dates(const intptr_t control, system_clock::time_point min_date, system_clock::time_point max_date) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }

  if (system_clock::to_time_t(min_date) < 0) min_date = system_clock::from_time_t(0);
  if (system_clock::to_time_t(min_date) < 0) min_date = system_clock::from_time_t(0);
  if (system_clock::to_time_t(max_date) < 0) max_date = system_clock::from_time_t(0);

  wxCalendarCtrl* wx_calendar_ctrl = static_cast<wxCalendarCtrl*>(reinterpret_cast<control_handler*>(control)->control());
  wx_calendar_ctrl->SetDateRange(wxDateTime(system_clock::to_time_t(min_date)), system_clock::to_time_t(max_date));
}

void month_calendar::selection_range(const intptr_t control, system_clock::time_point date_start, system_clock::time_point date_end) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }

  if (system_clock::to_time_t(date_start) < 0) date_start = system_clock::from_time_t(0);
  if (system_clock::to_time_t(date_end) < 0) date_end = system_clock::from_time_t(0);

  wxCalendarCtrl* wx_calendar_ctrl = static_cast<wxCalendarCtrl*>(reinterpret_cast<control_handler*>(control)->control());
  wx_calendar_ctrl->SetDate(wxDateTime(system_clock::to_time_t(date_start)));
}

pair<system_clock::time_point, system_clock::time_point> month_calendar::selection_range(const intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }

  auto date = system_clock::from_time_t(static_cast<wxCalendarCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetDate().GetTicks());
  return {date, date};
}
