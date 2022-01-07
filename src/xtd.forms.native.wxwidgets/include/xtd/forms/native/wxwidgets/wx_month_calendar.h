#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/argument_exception.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/create_params.h>
#include "control_handler.h"
#include <wx/calctrl.h>
#include <wx/panel.h>
#include <chrono>

namespace xtd {
  namespace forms {
    namespace native {
      class wx_month_calendar;
      
      class wxMonthCalendar : public wxPanel {
      public:
        explicit wxMonthCalendar(wxWindow* parent, wxWindowID winid = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize) : wxPanel(parent, winid, pos, size) {
        }
        
        wxCalendarCtrl* calendarCtrl = new wxCalendarCtrl(this, wxID_ANY, wxDefaultDateTime, {0, 0}, wxDefaultSize, wxCAL_SHOW_HOLIDAYS);
      };
      
      class control;
      class month_calendar;
      
      class wx_month_calendar : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::month_calendar;
      private:
        explicit wx_month_calendar(const xtd::forms::create_params& create_params) {
          if (!create_params.parent()) throw xtd::argument_exception("control must have a parent"_t, csf_);
          control_handler::create<wxMonthCalendar>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxPoint(create_params.location().x(), create_params.location().y()), wxSize(create_params.size().width(), create_params.size().height()));
          #if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().is_dark()) {
            static_cast<wxCalendarCtrl*>(control())->SetBackgroundColour(wxColour(xtd::drawing::system_colors::button_face().r(), xtd::drawing::system_colors::button_face().g(), xtd::drawing::system_colors::button_face().b(), xtd::drawing::system_colors::button_face().a()));
            static_cast<wxCalendarCtrl*>(control())->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
        }
      };
    }
  }
}
