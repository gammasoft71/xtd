#pragma once
#include <xtd/xtd.delegates>
#include <wx/timer.h>

namespace xtd {
  namespace forms {
    namespace native {
      class wx_timer {
      public:
        wx_timer(delegate<void(const event_args&)> tick) : tick_(tick) {
          this->timer_.Bind(wxEVT_TIMER, [&](wxTimerEvent& event) {
            this->tick_(event_args::empty);
          });
        }
        
        wxTimer& timer() {return this->timer_;}
        
      private:
        delegate<void(const event_args&)> tick_;
        wxTimer timer_;
      };
    }
  }
}
