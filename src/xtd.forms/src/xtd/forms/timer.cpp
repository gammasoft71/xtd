#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/timer.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/timer.h"
#include <xtd/as.h>

using namespace xtd;
using namespace xtd::forms;

struct timer::data {
  bool enabled = false;
  int32 interval = 100;
  intptr handle = 0;
};

timer::timer() : data_(std::make_shared<data>()) {
}

timer::~timer() {
  stop();
}

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

time_span timer::interval() const noexcept {
  return time_span {data_->interval};
}

void timer::interval(const time_span& interval) {
  interval_milliseconds(as<int32>(interval.total_milliseconds_duration().count()));
}

int32 timer::interval_milliseconds() const noexcept {
  return data_->interval;
}

void timer::interval_milliseconds(int32 interval) {
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
