#include <xtd/argument_exception.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/month_calendar.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_month_calendar.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

namespace {
  void change_attribute_dates(wxCalendarCtrl* wx_calendar_ctrl, const std::vector<xtd::date_time>& annually_dates, const std::vector<xtd::date_time>& dates) {
    for (size_t day = 1; day <= 31; ++day)
      wx_calendar_ctrl->wxCalendarCtrlBase::ResetAttr(day);
    for (auto date : annually_dates) {
      if (static_cast<uint32_t>(wx_calendar_ctrl->GetDate().GetMonth()) + 1 == date.month()) {
        wxCalendarDateAttr* attr = new wxCalendarDateAttr();
        if (wx_calendar_ctrl->GetAttr(static_cast<size_t>(date.day())) != null)
          *attr = *wx_calendar_ctrl->GetAttr(static_cast<size_t>(date.day()));
        wxFont font = attr->GetFont();
        font = font.MakeBold();
        attr->SetFont(font);
        wx_calendar_ctrl->SetAttr(static_cast<size_t>(date.day()), attr);
      }
    }
   
    for (auto date : dates) {
      if (static_cast<uint32_t>(wx_calendar_ctrl->GetDate().GetMonth()) + 1 == date.month() && static_cast<uint32_t>(wx_calendar_ctrl->GetDate().GetYear()) == date.year()) {
        wxCalendarDateAttr* attr = new wxCalendarDateAttr();
        if (wx_calendar_ctrl->GetAttr(static_cast<size_t>(date.day())) != null)
          *attr = *wx_calendar_ctrl->GetAttr(static_cast<size_t>(date.day()));
        wxFont font = attr->GetFont();
        font = font.MakeBold();
        attr->SetFont(font);
        wx_calendar_ctrl->SetAttr(static_cast<size_t>(date.day()), attr);
      }
    }
  }
}

void month_calendar::annually_bolded_dates(const intptr_t control, const std::vector<xtd::date_time>& dates) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  
  reinterpret_cast<wx_month_calendar*>(control)->annually_bolded_dates = dates;
  change_attribute_dates(static_cast<wxMonthCalendar*>(reinterpret_cast<control_handler*>(control)->control())->calendarCtrl, reinterpret_cast<wx_month_calendar*>(control)->annually_bolded_dates, reinterpret_cast<wx_month_calendar*>(control)->bolded_dates);
}

void month_calendar::bolded_dates(const intptr_t control, const std::vector<xtd::date_time>& dates) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  
  reinterpret_cast<wx_month_calendar*>(control)->bolded_dates = dates;
  change_attribute_dates(static_cast<wxMonthCalendar*>(reinterpret_cast<control_handler*>(control)->control())->calendarCtrl, reinterpret_cast<wx_month_calendar*>(control)->annually_bolded_dates, reinterpret_cast<wx_month_calendar*>(control)->bolded_dates);
}

void month_calendar::allowable_dates(const intptr_t control, date_time min_date, date_time max_date) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  
  wxCalendarCtrl* wx_calendar_ctrl = static_cast<wxMonthCalendar*>(reinterpret_cast<control_handler*>(control)->control())->calendarCtrl;
  wxDateTime wx_min_date_time(min_date.day(), static_cast<wxDateTime::Month>(min_date.month() - 1), min_date.year());
  wxDateTime wx_max_date_time(max_date.day(), static_cast<wxDateTime::Month>(max_date.month() - 1), max_date.year());
  wx_calendar_ctrl->SetDateRange(wx_min_date_time, wx_max_date_time);
}

void month_calendar::selection_range(const intptr_t control, date_time date_start, date_time date_end) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  
  wxCalendarCtrl* wx_calendar_ctrl = static_cast<wxMonthCalendar*>(reinterpret_cast<control_handler*>(control)->control())->calendarCtrl;
  wxDateTime wx_date_time(date_start.day(), static_cast<wxDateTime::Month>(date_start.month() - 1), date_start.year());
  wx_calendar_ctrl->SetDate(wx_date_time);
}

pair<date_time, date_time> month_calendar::selection_range(const intptr_t control) {
  if (!control || !wxTheApp) throw argument_exception(csf_);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }
  
  wxDateTime wx_date_time = static_cast<wxMonthCalendar*>(reinterpret_cast<control_handler*>(control)->control())->calendarCtrl->GetDate();
  date_time date = date_time(wx_date_time.GetYear(), static_cast<uint32_t>(wx_date_time.GetMonth()) + 1, wx_date_time.GetDay(), 0, 0, 0, date_time_kind::unspecified);
  return {date, date};
}
