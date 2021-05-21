#include <stdexcept>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/timer.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_timer.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::forms::native;

intptr_t timer::create(int32_t interval, const delegate<void(const event_args&)>& tick) {
  application::initialize(); // Must be first
  wx_timer* timer = new class wx_timer(tick);
  timer->timer().Start(interval);
  return reinterpret_cast<intptr_t>(timer);
}

void timer::destroy(intptr_t handle) {
  wx_timer* timer = reinterpret_cast<class wx_timer*>(handle);
  timer->timer().Stop();
  delete timer;
}
