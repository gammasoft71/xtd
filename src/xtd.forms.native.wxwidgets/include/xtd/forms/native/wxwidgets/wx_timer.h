#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/delegate.h>
#include <xtd/event_args.h>
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
        wx_timer(delegate<void(const event_args&)> tick) : tick_(tick) {
          timer_.Bind(wxEVT_TIMER, [&](wxTimerEvent& event) {
            try {
              tick_(event_args::empty);
            } catch(...) {
            }
          });
        }
        
        wxTimer& timer() {return timer_;}
        
      private:
        delegate<void(const event_args&)> tick_;
        wxTimer timer_;
      };
    }
  }
}
