#include "../../../include/xtd/threading/timer.h"
#include "../../../include/xtd/threading/auto_reset_event.h"
#include "../../../include/xtd/threading/thread_pool.h"
#include "../../../include/xtd/argument_out_of_range_exception.h"
#include "../../../include/xtd/invalid_operation_exception.h"

using namespace xtd;
using namespace xtd::threading;

struct timer::data {
  timer_callback callback;
  bool closed{false};
  int32 due_time{-1};
  auto_reset_event event {true};
  auto_reset_event sleep {false};
  int32 period {-1};
  std::any state{this};
  wait_callback timer_proc = wait_callback {[&] {
    if (due_time > 0) sleep.wait_one(due_time);
    while (!closed) {
      callback(state);
      sleep.wait_one(period);
    }
    event.set();
  }};
};

timer::timer(const timer_callback& callback) : timer(callback, this, -1, -1) {
}

timer::timer(const timer_callback& callback, int32 due_time, int32 period) : timer(callback, this, due_time, period) {
}

timer::timer(const timer_callback& callback, int64 due_time, int64 period) : timer(callback, this, as<int32>(due_time), as<int32>(period)) {
}

timer::timer(const timer_callback& callback, const time_span& due_time, const time_span& period) : timer(callback, this, due_time.total_milliseconds_duration().count(), period.total_milliseconds_duration().count()) {
}

timer::timer(const timer_callback& callback, uint32 due_time, uint32 period) : timer(callback, this, as<int32>(due_time), as<int32>(period)) {
}

timer::timer(const timer_callback& callback, std::any state, int32 due_time, int32 period) : data_(std::make_shared<data>()) {
  data_->callback = callback;
  data_->state = state;
  data_->due_time = due_time;
  data_->period = period;
  change(due_time, period);
}

timer::timer(const timer_callback& callback, std::any state, int64 due_time, int64 period) : timer(callback, state, as<int32>(due_time), as<int32>(period)) {
}

timer::timer(const timer_callback& callback, std::any state, const time_span& due_time, const time_span& period) : timer(callback, state, due_time.total_milliseconds_duration().count(), period.total_milliseconds_duration().count()) {
}

timer::timer(const timer_callback& callback, std::any state, uint32 due_time, uint32 period) : timer(callback, state, as<int32>(due_time), as<int32>(period)) {
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
  if (data_->callback.is_empty()) throw invalid_operation_exception {csf_};
  if (due_time < timeout::infinite || period < timeout::infinite) throw argument_out_of_range_exception {csf_};
  
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
  this->change(due_time.total_milliseconds_duration().count(), period.total_milliseconds_duration().count());
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
