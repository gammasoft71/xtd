#pragma once
#include <xtd/delegate.h>
#include <xtd/event_args.h>
#include <wx/timer.h>

namespace xtd {
  namespace forms {
    namespace native {
      class wx_timer {
      public:
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
