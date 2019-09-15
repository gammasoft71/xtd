#pragma once
#include <xtd/xtd.delegates>
#include <wx/timer.h>

namespace xtd {
  namespace forms {
    namespace native {
      class wx_timer : public wxTimer {
      public:
        wx_timer(delegate<void(const event_args&)> tick) : wxTimer(), tick_(tick) {}
        
      private:
        void Notify() override {this->tick_(event_args::empty);}
        delegate<void(const event_args&)> tick_;
      };
    }
  }
}
