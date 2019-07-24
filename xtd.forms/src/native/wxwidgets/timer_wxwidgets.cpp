#include <stdexcept>
#include "../timer_api.hpp"
#include <wx/timer.h>

using namespace native;
using namespace xtd;

namespace {
  class timer : public wxTimer {
  public:
    timer(const delegate<void(const event_args&)>& tick) : tick_(tick) {
      this->Bind(wxEVT_TIMER, [&](wxTimerEvent& event) {
        this->tick_(event_args::empty);
      });
    }
    
  private:
    delegate<void(const event_args&)> tick_;
  };
}



intptr_t timer_api::create(int interval, const delegate<void(const event_args&)>& tick) {
  timer* timer = new class timer(tick);
  timer->Start(interval);
  return reinterpret_cast<intptr_t>(timer);
}

void timer_api::destroy(intptr_t handle) {
  if (handle == 0) return;
  timer* timer = reinterpret_cast<class timer*>(handle);
  timer->Stop();
  delete timer;
}
