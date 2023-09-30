#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_month_calendar.h"
#include <xtd/forms/native/month_calendar>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <xtd/unused>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void month_calendar::annually_bolded_dates(intptr control, const std::vector<xtd::date_time>& dates) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  
  reinterpret_cast<wx_month_calendar*>(control)->annually_bolded_dates = dates;
  reinterpret_cast<wx_month_calendar*>(control)->change_attribute_dates(reinterpret_cast<wx_month_calendar*>(control));
}

void month_calendar::bolded_dates(intptr control, const std::vector<xtd::date_time>& dates) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  
  reinterpret_cast<wx_month_calendar*>(control)->bolded_dates = dates;
  reinterpret_cast<wx_month_calendar*>(control)->change_attribute_dates(reinterpret_cast<wx_month_calendar*>(control));
}

void month_calendar::calendar_dimensions(intptr control, const xtd::drawing::size& value) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  
  // Does not exists in wxWidgets...
}

void month_calendar::first_day_of_week(intptr control, uint32 day) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  
  wxCalendarCtrl* wx_calendar_ctrl = static_cast<wxMonthCalendar*>(reinterpret_cast<control_handler*>(control)->control())->calendarCtrl;
  auto style = wx_calendar_ctrl->GetWindowStyle();
  style &= ~(wxCAL_MONDAY_FIRST | wxCAL_SUNDAY_FIRST);
  switch (day) {
    case 0: style |= wxCAL_MONDAY_FIRST; break;
    case 1: break;
    case 2: break;
    case 3: break;
    case 4: break;
    case 5: break;
    case 6: style |= wxCAL_SUNDAY_FIRST; break;
    case 7: break;
    default: break;
  }
  wx_calendar_ctrl->SetWindowStyle(style);
}

std::tuple<uint32, xtd::date_time> month_calendar::hit_test(intptr control, const xtd::drawing::point& point) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return make_tuple(0, xtd::date_time());
  }
  
  wxCalendarCtrl* wx_calendar_ctrl = static_cast<wxMonthCalendar*>(reinterpret_cast<control_handler*>(control)->control())->calendarCtrl;
  uint32 hit_area = 0;
  wxDateTime time;
  
  wxCalendarHitTestResult result = wx_calendar_ctrl->HitTest({point.x(), point.y()}, &time);
  switch (result) {
    case wxCalendarHitTestResult::wxCAL_HITTEST_NOWHERE: hit_area = 0; break;
    case wxCalendarHitTestResult::wxCAL_HITTEST_HEADER: hit_area = 1; break;
    case wxCalendarHitTestResult::wxCAL_HITTEST_DAY: hit_area = 7; break;
    case wxCalendarHitTestResult::wxCAL_HITTEST_INCMONTH: hit_area = 4; break;
    case wxCalendarHitTestResult::wxCAL_HITTEST_DECMONTH: hit_area = 5; break;
    case wxCalendarHitTestResult::wxCAL_HITTEST_SURROUNDING_WEEK: hit_area = 11; break;
    case wxCalendarHitTestResult::wxCAL_HITTEST_WEEK: hit_area = 11; break;
    default: hit_area = 0; break;
  }
  
  return make_tuple(hit_area, date_time(time.GetYear(), static_cast<uint32>(time.GetMonth()) + 1, time.GetDay(), 0, 0, 0, date_time_kind::unspecified));
}

void month_calendar::allowable_dates(intptr control, date_time min_date, date_time max_date) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  
  wxCalendarCtrl* wx_calendar_ctrl = static_cast<wxMonthCalendar*>(reinterpret_cast<control_handler*>(control)->control())->calendarCtrl;
  wxDateTime wx_min_date_time(min_date.day(), static_cast<wxDateTime::Month>(min_date.month() - 1), min_date.year());
  wxDateTime wx_max_date_time(max_date.day(), static_cast<wxDateTime::Month>(max_date.month() - 1), max_date.year());
  wx_calendar_ctrl->SetDateRange(wx_min_date_time, wx_max_date_time);
}

void month_calendar::max_selection_count(intptr control, uint32 value) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  
  // Does not exists in wxWidgets...
}

void month_calendar::monthly_bolded_dates(intptr control, const std::vector<xtd::date_time>& dates) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  
  reinterpret_cast<wx_month_calendar*>(control)->monthly_bolded_dates = dates;
  reinterpret_cast<wx_month_calendar*>(control)->change_attribute_dates(reinterpret_cast<wx_month_calendar*>(control));
}

void month_calendar::selection_range(intptr control, date_time date_start, date_time date_end) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  
  wxCalendarCtrl* wx_calendar_ctrl = static_cast<wxMonthCalendar*>(reinterpret_cast<control_handler*>(control)->control())->calendarCtrl;
  wxDateTime wx_date_time(date_start.day(), static_cast<wxDateTime::Month>(date_start.month() - 1), date_start.year());
  reinterpret_cast<wx_month_calendar*>(control)->current_month = date_start.month();
  reinterpret_cast<wx_month_calendar*>(control)->current_year = date_start.year();
  unused_(date_end);
  wx_calendar_ctrl->SetDate(wx_date_time);
}

pair<date_time, date_time> month_calendar::selection_range(intptr control) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return {};
  }
  
  wxDateTime wx_date_time = static_cast<wxMonthCalendar*>(reinterpret_cast<control_handler*>(control)->control())->calendarCtrl->GetDate();
  date_time date = date_time(wx_date_time.GetYear(), static_cast<uint32>(wx_date_time.GetMonth()) + 1, wx_date_time.GetDay(), 0, 0, 0, date_time_kind::unspecified);
  return {date, date};
}

xtd::drawing::size month_calendar::single_month_size(intptr control) {
  return {240, 162};
}

void month_calendar::title_back_color(intptr control, const xtd::drawing::color& color) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  wxCalendarCtrl* wx_calendar_ctrl = static_cast<wxMonthCalendar*>(reinterpret_cast<control_handler*>(control)->control())->calendarCtrl;
  wx_calendar_ctrl->SetHeaderColours(wx_calendar_ctrl->GetHeaderColourFg(), {color.r(), color.g(), color.b(), color.a()});
}

void month_calendar::title_fore_color(intptr control, const xtd::drawing::color& color) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  wxCalendarCtrl* wx_calendar_ctrl = static_cast<wxMonthCalendar*>(reinterpret_cast<control_handler*>(control)->control())->calendarCtrl;
  wx_calendar_ctrl->SetHeaderColours({color.r(), color.g(), color.b(), color.a()}, wx_calendar_ctrl->GetHeaderColourBg());
}

void month_calendar::today_date(intptr control, const xtd::date_time& value) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  
  reinterpret_cast<wx_month_calendar*>(control)->today_date = value;
  reinterpret_cast<wx_month_calendar*>(control)->change_attribute_dates(reinterpret_cast<wx_month_calendar*>(control));
}

void month_calendar::trailing_fore_color(intptr control, const xtd::drawing::color& color) {
  if (!control || !wxTheApp) throw argument_exception {csf_};
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", __FILE__, __LINE__, __func__);
    return;
  }
  // Does not exists in wxWidgets...
}
