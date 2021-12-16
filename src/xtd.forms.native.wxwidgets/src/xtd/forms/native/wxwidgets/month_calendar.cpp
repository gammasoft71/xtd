#include <xtd/argument_exception.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/month_calendar.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_month_calendar.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void month_calendar::value(const intptr_t control, const std::chrono::system_clock::time_point date) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }

  wxCalendarCtrl* wx_calendar_ctrl = static_cast<wxCalendarCtrl*>(reinterpret_cast<control_handler*>(control)->control());
  wx_calendar_ctrl->SetDate(wxDateTime(std::chrono::system_clock::to_time_t(date)));
}

std::chrono::system_clock::time_point month_calendar::value(const intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return std::chrono::system_clock::time_point();
  }

  wxCalendarCtrl* wx_calendar_ctrl = static_cast<wxCalendarCtrl*>(reinterpret_cast<control_handler*>(control)->control());
  return std::chrono::system_clock::from_time_t(wx_calendar_ctrl->GetDate().GetTicks());
}
