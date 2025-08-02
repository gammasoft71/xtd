#include <wx/app.h>
#undef interface
#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_timer.hpp"
#include <xtd/forms/native/application>
#include <xtd/forms/native/timer>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>

using namespace xtd;
using namespace xtd::forms::native;
using namespace xtd::helpers;

intptr timer::create(int32 interval, const delegate<void(const event_args&)>& tick) {
  application::initialize(); // Must be first
  wx_timer* timer = new class wx_timer(tick);
  if (interval <= 0) interval = 1;
  timer->timer().Start(interval);
  return reinterpret_cast<intptr>(timer);
}

void timer::destroy(intptr handle) {
  if (!handle) throw_helper::throws(exception_case::argument);
  if (!wxTheApp) return;
  wx_timer* timer = reinterpret_cast<class wx_timer*>(handle);
  timer->timer().Stop();
  delete timer;
}
