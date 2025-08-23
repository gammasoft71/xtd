#include "../../../include/xtd/threading/countdown_event.hpp"
#include "../../../include/xtd/threading/manual_reset_event.hpp"
#include "../../../include/xtd/diagnostics/stopwatch.hpp"
#include "../../../include/xtd/operation_canceled_exception.hpp"
#include "../../../include/xtd/argument_out_of_range_exception.hpp"
#include "../../../include/xtd/invalid_operation_exception.hpp"
#include "../../../include/xtd/object_closed_exception.hpp"
#include "../../../include/xtd/lock.hpp"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::helpers;
using namespace xtd::threading;

struct countdown_event::data : object {
  const threading::cancellation_token* cancellation_token = nullptr;
  int32 current_count = 0;
  int32 initial_count = 0;
  manual_reset_event event {false};
};

countdown_event::countdown_event() : countdown_event(0) {
}

countdown_event::countdown_event(int32 initial_count) : data_(xtd::new_sptr<data>()) {
  if (initial_count < 0) throw_helper::throws(exception_case::argument_out_of_range);
  data_->current_count = initial_count;
  data_->initial_count = initial_count;
  if (data_->current_count == 0) data_->event.set();
}

countdown_event& countdown_event::operator =(const countdown_event& other) {
  close();
  data_ = other.data_;
  return *this;
}

countdown_event::~countdown_event() {
  if (data_.use_count() == 1) close();
}

int32 countdown_event::current_count() const {
  if (!data_) throw_helper::throws(exception_case::object_closed);
  return data_->current_count;
}

int32 countdown_event::initial_count() const {
  if (!data_) throw_helper::throws(exception_case::object_closed);
  return data_->initial_count;
}

bool countdown_event::is_set() const {
  if (!data_) throw_helper::throws(exception_case::object_closed);
  return data_->current_count == 0;
}

const xtd::threading::wait_handle& countdown_event::wait_handle() const {
  if (!data_) throw_helper::throws(exception_case::object_closed);
  return data_->event;
}

xtd::threading::wait_handle& countdown_event::wait_handle() {
  if (!data_) throw_helper::throws(exception_case::object_closed);
  return data_->event;
}

void countdown_event::close() {
  data_.reset();
}

void countdown_event::add_count() {
  if (!data_) throw_helper::throws(exception_case::object_closed);
  add_count(1);
}

void countdown_event::add_count(int32 count) {
  if (!data_) throw_helper::throws(exception_case::object_closed);
  if (count < 0) throw_helper::throws(exception_case::argument_out_of_range);
  if (data_->current_count == 0) throw_helper::throws(exception_case::invalid_operation);
  lock_(*data_) data_->current_count += count;
}

void countdown_event::reset() {
  if (!data_) throw_helper::throws(exception_case::object_closed);
  reset(data_->initial_count);
}

void countdown_event::reset(int32 count) {
  if (!data_) throw_helper::throws(exception_case::object_closed);
  if (count < 0) throw_helper::throws(exception_case::argument_out_of_range);
  lock_(*data_) {
    data_->event.reset();
    data_->initial_count = count;
    data_->current_count = count;
  }
}

bool countdown_event::signal() {
  return signal(1);
}

bool countdown_event::signal(int32 signal_count) {
  if (!data_) throw_helper::throws(exception_case::object_closed);
  if (data_->current_count == 0) throw_helper::throws(exception_case::invalid_operation);
  if (signal_count < 0 || signal_count > data_->current_count) throw_helper::throws(exception_case::argument_out_of_range);
  auto lock = threading::lock {*data_};
  data_->current_count -= signal_count;
  if (data_->current_count == 0) data_->event.set();
  return data_->current_count == 0;
}

bool countdown_event::try_add_count() noexcept {
  return try_add_count(1);
}

bool countdown_event::try_add_count(int32 count) noexcept {
  if (!data_ || count < 0 || data_->current_count == 0) return false;
  lock_(*data_) data_->current_count += count;
  return true;
}

void countdown_event::wait() {
  wait(timeout::infinite);
}

bool countdown_event::wait(int32 milliseconds_timeout) {
  if (!data_) throw_helper::throws(exception_case::object_closed);
  if (milliseconds_timeout < timeout::infinite) throw_helper::throws(exception_case::argument_out_of_range);
  if (!data_->cancellation_token) return data_->event.wait_one(milliseconds_timeout);
  if (milliseconds_timeout == timeout::infinite) return wait_wtih_cancellation_token();
  return wait_wtih_cancellation_token(milliseconds_timeout);
}

void countdown_event::wait(const cancellation_token& cancellation_token) {
  wait(timeout::infinite, cancellation_token);
}

bool countdown_event::wait(const time_span& timeout) {
  return wait(as<int32>(timeout.total_milliseconds()));
}

bool countdown_event::wait(int32 milliseconds_timeout, const cancellation_token& cancellation_token) {
  data_->cancellation_token = &cancellation_token;
  return wait(milliseconds_timeout);
}

bool countdown_event::wait(const time_span& timeout, const cancellation_token& cancellation_token) {
  return wait(as<int32>(timeout.total_milliseconds()), cancellation_token);
}

bool countdown_event::wait_wtih_cancellation_token() {
  auto result = false;
  while (!result) {
    if (data_->cancellation_token->is_cancellation_requested()) throw_helper::throws(exception_case::operation_canceled);
    result = data_->event.wait_one(1);
  }
  return result;
}

bool countdown_event::wait_wtih_cancellation_token(int32 milliseconds_timeout) {
  auto sw = stopwatch::start_new();
  auto result = false;
  while (!result && sw.elapsed_milliseconds() <= milliseconds_timeout) {
    if (data_->cancellation_token->is_cancellation_requested()) throw_helper::throws(exception_case::operation_canceled);
    result = data_->event.wait_one(1);
  }
  return result;
}
