#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/timer.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/timer.h"

using namespace xtd;
using namespace xtd::forms;

bool timer::enabled() const noexcept {
  return data_->enabled;
}

void timer::enabled(bool enabled) {
  if (data_->enabled != enabled) {
    data_->enabled = enabled;
    if (data_->enabled == true) data_->handle = native::timer::create(data_->interval, {*this, &timer::on_tick});
    else native::timer::destroy(data_->handle);
  }
}

std::chrono::milliseconds timer::interval() const noexcept {
  return std::chrono::milliseconds(data_->interval);
}

int32_t timer::interval_milliseconds() const noexcept {
  return data_->interval;
}

void timer::interval_milliseconds(int32_t interval) {
  if (data_->interval != interval) {
    data_->interval = interval;
    if (data_->enabled == true) restart();
  }
}

void timer::start() {
  enabled(true);
}

void timer::stop() {
  enabled(false);
}

void timer::on_tick(const event_args& e) {
  tick(*this, e);
}

void timer::restart() {
  stop();
  start();
}
