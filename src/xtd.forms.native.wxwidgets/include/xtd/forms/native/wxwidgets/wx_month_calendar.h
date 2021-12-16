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
#include <chrono>

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class month_calendar;
      class wx_month_calendar : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::month_calendar;
      private:
        wx_month_calendar(const xtd::forms::create_params& create_params) {
          if (!create_params.parent()) throw xtd::argument_exception("control must have a parent"_t, csf_);
            control_handler::create<wxCalendarCtrl>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxDefaultDateTime, wxPoint(create_params.location().x(), create_params.location().y()), wxSize(create_params.size().width(), create_params.size().height()), wxCAL_SHOW_HOLIDAYS);
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
