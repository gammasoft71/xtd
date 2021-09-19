#include <cmath>
#include "../../../include/xtd/forms/animation.h"

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;

animation::animation() {
  double_buffered(true);
  size(default_size());
  frames_timer_.tick += {*this, &animation::on_frames_timer_tick};
}

int64_t animation::elapsed_milliseconds() const {
  return stopwatch_.elapsed_nanoseconds();
}

int32_t animation::frame_counter() const {
  return frame_counter_;
}

int32_t animation::frames_per_second() const {
  return frames_per_second_;
}

animation& animation::frames_per_second(int32_t value) {
  if (frames_per_second_ != value) {
    frames_per_second_ = value;
    if (!frames_per_second_) frames_timer_.interval_milliseconds(std::numeric_limits<int32_t>::max());
    else frames_timer_.interval_milliseconds(static_cast<int32_t>(ceil(1000.0 / frames_per_second_)));
  }
  return *this;
}

bool animation::is_running() const {
  return frames_timer_.enabled();
}

void animation::start() {
  frames_timer_.enabled(frames_per_second_);
}

void animation::stop() {
  frames_timer_.enabled(false);
}

void animation::on_updated(const animation_updated_event_args& e) {
  updated(*this, e);
}

void animation::on_frames_timer_tick(object& timer, const event_args& e) {
  ++frame_counter_;
  on_updated(animation_updated_event_args(frame_counter_, stopwatch_.elapsed_milliseconds()));
  invalidate();
  stopwatch_ = stopwatch::start_new();
}
