#include <stdexcept>
#include <xtd/forms/native/timer.hpp>
#include "fl_timer.hpp"

using namespace xtd;
using namespace xtd::forms::native;

intptr_t timer::create(int32_t interval, const delegate<void(const event_args&)>& tick) {
  fl_timer* timer = new class fl_timer(tick);
  timer->Start(interval);
  return reinterpret_cast<intptr_t>(timer);
}

void timer::destroy(intptr_t handle) {
  fl_timer* timer = reinterpret_cast<class fl_timer*>(handle);
  timer->Stop();
  delete timer;
}
