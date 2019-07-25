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
        this->tick_(event_args::empty);
      });
    }
    
  private:
    delegate<void(const event_args&)> tick_;
  };
}

intptr_t timer::create(int interval, const delegate<void(const event_args&)>& tick) {
  wx_timer* timer = new class wx_timer(tick);
  timer->Start(interval);
  return reinterpret_cast<intptr_t>(timer);
}

void timer::destroy(intptr_t handle) {
  if (handle == 0) return;
  wx_timer* timer = reinterpret_cast<class wx_timer*>(handle);
  timer->Stop();
  delete timer;
}
