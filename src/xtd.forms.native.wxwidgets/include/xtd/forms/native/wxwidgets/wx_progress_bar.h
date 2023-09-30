#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "control_handler.h"
#include <xtd/drawing/system_colors>
#include <xtd/forms/native/create_params>
#include <xtd/forms/native/progress_bar_styles>
#include <xtd/argument_exception>
#include <wx/gauge.h>
#include <wx/timer.h>

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class progress_bar;
      class wx_progress_bar : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::progress_bar;
      private:
        explicit wx_progress_bar(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t, csf_);
          control_handler::create<wxGauge>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, 100, wxPoint(create_params.location.x(), create_params.location.y()), wxDefaultSize, style_to_wx_style(create_params.style, create_params.ex_style));
          control()->SetSize(wxSize(create_params.size.width(), create_params.size.height()));
          #if defined(__WXMSW__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
          
          timer_marquee.Bind(wxEVT_TIMER, &wx_progress_bar::on_progrress_marquee_timer, this);
        }
        
        ~wx_progress_bar() {
          timer_marquee.Unbind(wxEVT_TIMER, &wx_progress_bar::on_progrress_marquee_timer, this);
          timer_marquee.Stop();
        }
        
        void on_progrress_marquee_timer(wxTimerEvent& event) {
          if (event.GetTimer().GetId() == timer_marquee.GetId() && control() && !static_cast<wxGauge*>(control())->IsBeingDeleted())
            static_cast<wxGauge*>(control())->Pulse();
        }
        
        void marquee(bool marquee, size_t animation_speed) {
          if (marquee) timer_marquee.Start(static_cast<int32>(animation_speed));
          else timer_marquee.Stop();
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;
          
          if ((style & WS_TABSTOP) != WS_TABSTOP) wx_style |= wxTAB_TRAVERSAL;
          if ((style & PBS_SMOOTH) == PBS_SMOOTH) wx_style |= wxGA_SMOOTH;
          if ((style & PBS_VERTICAL) == PBS_VERTICAL) wx_style |= wxGA_VERTICAL;
          else wx_style |= wxGA_HORIZONTAL;
          
          return wx_style;
        }
        
        int32 minimum_ = 0;
        int32 maximum_ = 100;
        wxTimer timer_marquee;
      };
    }
  }
}
