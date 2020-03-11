#include <xtd/forms/native/timer.h>
#include "../../../include/xtd/forms/timer.h"

using namespace xtd;
using namespace xtd::forms;

void timer::enabled(bool enabled) {
  if (data_->enabled_ != enabled) {
    data_->enabled_ = enabled;
    if (data_->enabled_ == true)
      data_->handle_ = native::timer::create(data_->interval_, {*this, &timer::on_tick});
    else
      native::timer::destroy(data_->handle_);
  }
}

void timer::interval(int32_t interval) {
  if (data_->interval_ != interval) {
    data_->interval_ = interval;
    
    if (data_->enabled_ == true) {
      stop();
      start();
    }
  }
}

void timer::on_tick(const event_args& e) {
  tick(*this, e);
}
