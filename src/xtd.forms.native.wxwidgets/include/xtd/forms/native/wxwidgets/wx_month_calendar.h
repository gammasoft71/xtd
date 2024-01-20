#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "control_handler.h"
#include <xtd/drawing/system_colors>
#include <xtd/forms/native/create_params>
#include <xtd/forms/native/month_calendar_styles>
#include <xtd/argument_exception>
#include <xtd/chrono>
#include <xtd/date_time>
#include <wx/calctrl.h>
#include <wx/panel.h>
#include <vector>

namespace xtd {
  namespace forms {
    namespace native {
      class wx_month_calendar;
      
      class wxMonthCalendar : public wxControl {
      public:
      
        explicit wxMonthCalendar(wxWindow* parent, wxWindowID winid, const wxPoint& pos, const wxSize& size, long wx_styles) : wxControl(parent, winid, pos, size) {
          calendarCtrl = new wxCalendarCtrl(this, wxID_ANY, /*wxDefaultDateTime*/ wxDateTime(), {0, 0}, {240, 162}, wx_styles);
        }
        
        wxCalendarCtrl* calendarCtrl = nullptr;
      };
      
      class control;
      class month_calendar;
      
      class wx_month_calendar : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::month_calendar;
      private:
        explicit wx_month_calendar(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t, csf_);
          control_handler::create<wxMonthCalendar>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()), style_to_wx_style(create_params.style, create_params.ex_style));
          if ((create_params.style & MCS_NOTODAY) == MCS_NOTODAY) show_today = false;
          if ((create_params.style & MCS_NOTODAYCIRCLE) == MCS_NOTODAYCIRCLE) show_today_circle = false;
          static_cast<wxMonthCalendar*>(control())->calendarCtrl->Bind(wxEVT_CALENDAR_PAGE_CHANGED, &wx_month_calendar::on_page_changed, this);
          static_cast<wxMonthCalendar*>(control())->calendarCtrl->Bind(wxEVT_CALENDAR_YEAR_CHANGED, &wx_month_calendar::on_year_changed, this);
          #if defined(__WXMSW__)
          if (xtd::drawing::system_colors::window().is_dark()) {
            static_cast<wxMonthCalendar*>(control())->SetBackgroundColour(wxColour(xtd::drawing::system_colors::button_face().r(), xtd::drawing::system_colors::button_face().g(), xtd::drawing::system_colors::button_face().b(), xtd::drawing::system_colors::button_face().a()));
            static_cast<wxMonthCalendar*>(control())->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = common_control_style_to_wx_style(style, ex_style);
          
          if ((style & MCS_WEEKNUMBERS) == MCS_WEEKNUMBERS) wx_style |= wxCAL_SHOW_WEEK_NUMBERS;
          
          return wx_style;
        }
        
        void on_page_changed(wxCalendarEvent& e) {
          current_month = static_cast<uint32>(e.GetDate().GetMonth()) + 1;
          change_attribute_dates(this);
        }
        
        void on_year_changed(wxCalendarEvent& e) {
          current_year = static_cast<uint32>(e.GetDate().GetYear());
          change_attribute_dates(this);
        }
        
      public:
        static void change_attribute_dates(wx_month_calendar* wx_month_calendar) {
          wxCalendarCtrl* wx_calendar_ctrl = static_cast<wxMonthCalendar*>(wx_month_calendar->control())->calendarCtrl;
          for (size_t day = 1; day <= 31; ++day)
            wx_calendar_ctrl->ResetAttr(day);
          for (auto date : wx_month_calendar->annually_bolded_dates) {
            if (static_cast<uint32>(wx_calendar_ctrl->GetDate().GetMonth()) + 1 == date.month()) {
              wxCalendarDateAttr* attr = new wxCalendarDateAttr();
              if (wx_calendar_ctrl->GetAttr(static_cast<size_t>(date.day())) != nullptr)
                *attr = *wx_calendar_ctrl->GetAttr(static_cast<size_t>(date.day()));
              wxFont font = attr->GetFont();
              font = font.MakeBold();
              attr->SetFont(font);
              wx_calendar_ctrl->SetAttr(static_cast<size_t>(date.day()), attr);
            }
          }
          
          for (auto date : wx_month_calendar->monthly_bolded_dates) {
            wxCalendarDateAttr* attr = new wxCalendarDateAttr();
            if (wx_calendar_ctrl->GetAttr(static_cast<size_t>(date.day())) != nullptr)
              *attr = *wx_calendar_ctrl->GetAttr(static_cast<size_t>(date.day()));
            wxFont font = attr->GetFont();
            font = font.MakeBold();
            attr->SetFont(font);
            wx_calendar_ctrl->SetAttr(static_cast<size_t>(date.day()), attr);
          }
          
          for (auto date : wx_month_calendar->bolded_dates) {
            if (static_cast<uint32>(wx_calendar_ctrl->GetDate().GetMonth()) + 1 == date.month() && static_cast<uint32>(wx_calendar_ctrl->GetDate().GetYear()) == date.year()) {
              wxCalendarDateAttr* attr = new wxCalendarDateAttr();
              if (wx_calendar_ctrl->GetAttr(static_cast<size_t>(date.day())) != nullptr)
                *attr = *wx_calendar_ctrl->GetAttr(static_cast<size_t>(date.day()));
              wxFont font = attr->GetFont();
              font = font.MakeBold();
              attr->SetFont(font);
              wx_calendar_ctrl->SetAttr(static_cast<size_t>(date.day()), attr);
            }
          }
          
          wx_calendar_ctrl->Mark(wx_month_calendar->today_date.day(), false);
          if (wx_month_calendar->current_month == wx_month_calendar->today_date.month() && wx_month_calendar->current_year == wx_month_calendar->today_date.year())
            wx_calendar_ctrl->Mark(wx_month_calendar->today_date.day(), wx_month_calendar->show_today_circle);
        }
        
        std::vector<xtd::date_time> annually_bolded_dates;
        std::vector<xtd::date_time> bolded_dates;
        std::vector<xtd::date_time> monthly_bolded_dates;
        xtd::date_time today_date = xtd::date_time::now();
        uint32 current_month = xtd::date_time::now().month();
        uint32 current_year = xtd::date_time::now().year();
        bool show_today = true;
        bool show_today_circle = true;
      };
    }
  }
}
