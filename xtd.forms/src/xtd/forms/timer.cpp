#include <xtd/forms/native/timer.hpp>
#include "../../../include/xtd/forms/timer.hpp"

using namespace xtd;
using namespace xtd::forms;

void timer::enabled(bool enabled) {
  if (this->enabled_ != enabled) {
    this->enabled_ = enabled;
    if (this->enabled_ == true)
      this->handle_ = native::timer::create(this->interval_, {*this, &timer::on_tick});
    else
      native::timer::destroy(this->handle_);
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
