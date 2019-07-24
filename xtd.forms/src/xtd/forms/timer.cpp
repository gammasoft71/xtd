#include "../../../include/xtd/forms/timer.hpp"
#include "../../native/timer_api.hpp"

using namespace xtd;
using namespace xtd::forms;

void timer::enabled(bool enabled) {
  if (this->enabled_ != enabled) {
    this->enabled_ = enabled;
    if (this->enabled_ == true)
      this->handle_ = native::timer_api::create(this->interval_, {*this, &timer::on_tick});
    else
      native::timer_api::destroy(this->handle_);
  }
}

void timer::interval(int interval) {
  if (this->interval_ != interval) {
    this->interval_ = interval;
    
    if (this->enabled_ == true) {
      this->Stop();
      this->Start();
    }
  }
}
