#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/delegate>
#include <xtd/event_args>
#include <wx/app.h>
#include <wx/timer.h>

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class timer;
      class wx_timer {
        friend xtd::forms::native::control;
        friend xtd::forms::native::timer;
      private:
        explicit wx_timer(delegate<void(const event_args&)> tick) : tick_(tick) {
          timer_.Bind(wxEVT_TIMER, &wx_timer::on_tick, this);
        }
        
        ~wx_timer() {
          timer_.Unbind(wxEVT_TIMER, &wx_timer::on_tick, this);
        }
        
        wxTimer& timer() {return timer_;}
        
      private:
        void on_tick(wxTimerEvent& event) {
          try {
            tick_(event_args::empty);
            if (wxTheApp) wxTheApp->Yield();
          } catch (...) {
          }
        }
        
        delegate<void(const event_args&)> tick_;
        wxTimer timer_;
      };
    }
  }
}
