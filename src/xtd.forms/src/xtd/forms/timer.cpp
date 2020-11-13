#include <xtd/forms/native/timer.h>
#include "../../../include/xtd/forms/timer.h"

using namespace xtd;
using namespace xtd::forms;

void timer::enabled(bool enabled) {
  if (enabled_ != enabled) {
    enabled_ = enabled;
    if (enabled_ == true)
      handle_ = native::timer::create(interval_, {*this, &timer::on_tick});
    else
      native::timer::destroy(handle_);
  }
}

void timer::interval(int32_t interval) {
  if (interval_ != interval) {
    interval_ = interval;
    
    if (enabled_ == true) {
      stop();
      start();
    }
  }
}

void timer::on_tick(const event_args& e) {
  tick(*this, e);
}
