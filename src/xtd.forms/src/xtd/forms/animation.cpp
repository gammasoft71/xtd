#include <cmath>
#include "../../../include/xtd/forms/animation.h"

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;

animation::animation() noexcept {
  double_buffered(true);
  set_can_focus(false);
  set_style(control_styles::resize_redraw, true);
  data_->frames_timer.tick += {*this, &animation::on_frames_timer_tick};
}

drawing::size animation::default_size() const {
  return {200, 100};
}

int64_t animation::elapsed_milliseconds() const noexcept {
  return data_->stopwatch.elapsed_nanoseconds();
}

int32_t animation::frame_counter() const noexcept {
  return data_->frame_counter;
}

int32_t animation::frames_per_second() const noexcept {
  return data_->frames_per_second;
}

animation& animation::frames_per_second(int32_t value) {
  if (data_->frames_per_second != value) {
    data_->frames_per_second = value;
    if (!data_->frames_per_second) data_->frames_timer.interval_milliseconds(std::numeric_limits<int32_t>::max());
    else data_->frames_timer.interval_milliseconds(static_cast<int32_t>(ceil(1000.0 / data_->frames_per_second)));
  }
  return *this;
}

bool animation::is_running() const noexcept {
  return data_->frames_timer.enabled();
}

void animation::start() {
  data_->frames_timer.enabled(data_->frames_per_second);
}

void animation::stop() {
  data_->frames_timer.enabled(false);
}

void animation::on_updated(const animation_updated_event_args& e) {
  updated(*this, e);
}

void animation::on_frames_timer_tick(object& timer, const event_args& e) {
  ++data_->frame_counter;
  on_updated(animation_updated_event_args(data_->frame_counter, data_->stopwatch.elapsed_milliseconds()));
  invalidate();
  data_->stopwatch = stopwatch::start_new();
}
