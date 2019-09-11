#include <stdexcept>
#include <xtd/forms/native/timer.hpp>
#include <wx/timer.h>

using namespace xtd;
using namespace xtd::forms::native;

namespace {
  class wx_timer : public wxTimer {
  public:
    wx_timer(const delegate<void(const event_args&)>& tick) : tick_(tick) {
      this->Bind(wxEVT_TIMER, [&](wxTimerEvent& event) {
        if (event.GetTimer().GetId() == this->GetId())
          this->tick_(event_args::empty);
        event.StopPropagation();
        });
    }
    
  private:
    delegate<void(const event_args&)> tick_;
  };
}

intptr_t timer::create(int32_t interval, const delegate<void(const event_args&)>& tick) {
  wx_timer* timer = new class wx_timer(tick);
  timer->Start(interval);
  return reinterpret_cast<intptr_t>(timer);
}

void timer::destroy(intptr_t handle) {
  wx_timer* timer = reinterpret_cast<class wx_timer*>(handle);
  timer->Stop();
  delete timer;
}
