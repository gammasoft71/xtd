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
  wx_calendar_ctrl->SetDateRange(min_date.to_time_t(), max_date.to_time_t());
}

void month_calendar::selection_range(const intptr_t control, date_time date_start, date_time date_end) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }

  wxCalendarCtrl* wx_calendar_ctrl = static_cast<wxCalendarCtrl*>(reinterpret_cast<control_handler*>(control)->control());
  wx_calendar_ctrl->SetDate(date_start.to_time_t());
}

pair<date_time, date_time> month_calendar::selection_range(const intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }

  auto date = date_time(date_time::from_time_t(static_cast<wxCalendarCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetDate().GetTicks(), date_time_kind::local).ticks(), date_time_kind::unspecified);
  return {date, date};
}
