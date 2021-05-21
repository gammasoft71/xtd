#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/argument_exception.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/progress_bar_styles.h>
#include <wx/gauge.h>
#include <wx/timer.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class progress_bar;
      class wx_progress_bar : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::progress_bar;
      private:
        wx_progress_bar(const forms::create_params& create_params) {
          if (!create_params.parent()) throw xtd::argument_exception("control must have a parent"_t, caller_info_);
          control_handler::create<wxGauge>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, 100, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
#if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
#endif

          timer_marquee.Bind(wxEVT_TIMER, [&](wxTimerEvent& event) {
            if (event.GetTimer().GetId() == timer_marquee.GetId() && !static_cast<wxGauge*>(control())->IsBeingDeleted())
              static_cast<wxGauge*>(control())->Pulse();
          });
        }
        
        ~wx_progress_bar() {
          timer_marquee.Stop();
        }

        void marquee(bool marquee, size_t animation_speed) {
          if (marquee) timer_marquee.Start(static_cast<int32_t>(animation_speed));
          else timer_marquee.Stop();
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;
          
          if ((style & PBS_SMOOTH) == PBS_SMOOTH) wx_style |= wxGA_SMOOTH;
          if ((style & PBS_VERTICAL) == PBS_VERTICAL) wx_style |= wxGA_VERTICAL;
          else wx_style |= wxGA_HORIZONTAL;

          return wx_style;
        }

        int32_t minimum_ = 0;
        int32_t maximum_ = 100;
        wxTimer timer_marquee;
      };
    }
  }
}
