#include "../../../include/xtd/threading/timer.hpp"
#include "../../../include/xtd/threading/auto_reset_event.hpp"
#include "../../../include/xtd/threading/thread_pool.hpp"
#include "../../../include/xtd/argument_out_of_range_exception.hpp"
#include "../../../include/xtd/invalid_operation_exception.hpp"

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::threading;

struct timer::data {
  timer_callback callback;
  bool closed{false};
  int32 due_time{-1};
  auto_reset_event event {true};
  auto_reset_event sleep {false};
  int32 period {-1};
  any_object state{object()};
  wait_callback timer_proc = wait_callback {[self = this] {
    if (self->due_time > 0) self->sleep.wait_one(self->due_time);
    while (!self->closed) {
      thread_pool::queue_user_work_item(self->callback, self->state);
      self->sleep.wait_one(self->period);
      if (self->period == 0) break;
    }
    self->event.set();
  }};
};

timer::timer(const timer_callback& callback) : timer(callback, object {}, -1, -1) {
}

timer::timer(const timer_callback& callback, int32 due_time, int32 period) : timer(callback, object {}, due_time, period) {
}

timer::timer(const timer_callback& callback, int64 due_time, int64 period) : timer(callback, object {}, as<int32>(due_time), as<int32>(period)) {
}

timer::timer(const timer_callback& callback, const time_span& due_time, const time_span& period) : timer(callback, object {}, as<int32>(due_time.total_milliseconds_duration().count()), as<int32>(period.total_milliseconds_duration().count())) {
}

timer::timer(const timer_callback& callback, uint32 due_time, uint32 period) : timer(callback, object {}, as<int32>(due_time), as<int32>(period)) {
}

timer::timer(const timer_callback& callback, const any_object& state, int32 due_time, int32 period) : data_(xtd::new_sptr<data>()) {
  data_->callback = callback;
  data_->state = state;
  data_->due_time = due_time;
  data_->period = period;
  change(due_time, period);
}

timer::timer(const timer_callback& callback, const any_object& state, int64 due_time, int64 period) : timer(callback, state, as<int32>(due_time), as<int32>(period)) {
}

timer::timer(const timer_callback& callback, const any_object& state, const time_span& due_time, const time_span& period) : timer(callback, state, as<int32>(due_time.total_milliseconds_duration().count()), as<int32>(period.total_milliseconds_duration().count())) {
}

timer::timer(const timer_callback& callback, const any_object& state, uint32 due_time, uint32 period) : timer(callback, state, as<int32>(due_time), as<int32>(period)) {
}

timer::timer(const timer& timer) : data_(timer.data_) {
}

timer& timer::operator=(const timer& timer) {
  if (data_.use_count() == 1) close();
  data_ = timer.data_;
  return *this;
}

timer::~timer() {
  if (data_.use_count() == 1) close();
}

void timer::change(int32 due_time, int32 period) {
  if (data_->callback.is_empty()) throw_helper::throws(exception_case::invalid_operation);
  if (due_time < timeout::infinite || period < timeout::infinite) throw_helper::throws(exception_case::argument_out_of_range);
  
  data_->due_time = due_time;
  data_->period = period;
  close();
  data_->closed = false;
  data_->sleep.reset();
  thread_pool::queue_user_work_item(data_->timer_proc);
}

void timer::change(int64 due_time, int64 period) {
  this->change(as<int32>(due_time), as<int32>(period));
}

void timer::change(const time_span& due_time, const time_span& period) {
  this->change(as<int32>(due_time.total_milliseconds_duration().count()), as<int32>(period.total_milliseconds_duration().count()));
}

void timer::change(uint32 due_time, uint32 period) {
  this->change(as<int32>(due_time), as<int32>(period));
}

void timer::close() {
  if (data_->closed) return;
  data_->closed = true;
  data_->sleep.set();
  data_->event.wait_one();
}
