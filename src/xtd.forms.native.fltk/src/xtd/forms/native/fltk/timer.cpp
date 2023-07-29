#include <stdexcept>
#include <xtd/forms/native/timer.hpp>
#include "fl_timer.hpp"

using namespace xtd;
using namespace xtd::forms::native;

intmax_t timer::create(int_least32_t interval, const delegate<void(const event_args&)>& tick) {
  fl_timer* timer = new class fl_timer(tick);
  timer->Start(interval);
  return reinterpret_cast<intmax_t>(timer);
}

void timer::destroy(intmax_t handle) {
  reinterpret_cast<class fl_timer*>(handle)->Stop();
  delete reinterpret_cast<class fl_timer*>(handle);
}
