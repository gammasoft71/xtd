#include "../../../include/xtd/threading/barrier.hpp"
#include "../../../include/xtd/threading/semaphore.hpp"
#include "../../../include/xtd/diagnostics/stopwatch.hpp"
#include "../../../include/xtd/argument_out_of_range_exception.hpp"
#include "../../../include/xtd/as.hpp"
#include "../../../include/xtd/int16_object.hpp"
#include "../../../include/xtd/invalid_operation_exception.hpp"
#include "../../../include/xtd/object_closed_exception.hpp"
#include "../../../include/xtd/operation_canceled_exception.hpp"
#include "../../../include/xtd/lock.hpp"
#include <atomic>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::threading;

struct barrier::data : object {
  const threading::cancellation_token* cancellation_token = nullptr;
  std::atomic<int32> current_phase_number = 0;
  std::atomic<int32> participant_count = 0;
  std::atomic<int32> participants_remaining = 0;
  barrier::post_phase_action post_phase_action;
  bool run_post_phase_action = false;
  semaphore phase_semaphore;
  bool throw_barrier_post_phase_exception = false;
};

barrier::barrier() : barrier(0) {
}

barrier::barrier(int32 participant_count) : barrier(participant_count, {}) {
}

barrier::barrier(int32 participant_count, barrier::post_phase_action post_phase_action) : data_(xtd::new_sptr<data>()) {
  if (participant_count < 0 || participant_count > int16_object::max_value) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  data_->participant_count = participant_count;
  data_->participants_remaining = participant_count;
  data_->post_phase_action = post_phase_action;
}

barrier& barrier::operator =(const barrier& other) {
  close();
  data_ = other.data_;
  return *this;
}

barrier::~barrier() {
  if (data_.use_count() == 1) close();
}

int32 barrier::current_phase_number() const {
  if (!data_) throw object_closed_exception {};
  return data_->current_phase_number;
}

int32 barrier::participant_count() const {
  if (!data_) throw object_closed_exception {};
  return data_->participant_count;
}

int32 barrier::participants_remaining() const {
  if (!data_) throw object_closed_exception {};
  return data_->participants_remaining;
}

int32 barrier::add_participant() {
  return add_participants(1);
}

int32 barrier::add_participants(int32 participant_count) {
  if (!data_) throw object_closed_exception {};
  auto lock = lock_guard {*data_};
  if (participant_count < 0 || data_->participant_count + participant_count > int16_object::max_value) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  if (data_->run_post_phase_action) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
  data_->participant_count += participant_count;
  data_->participants_remaining += participant_count;
  return data_->current_phase_number;
}

void barrier::close() {
  data_.reset();
}

int32 barrier::remove_participant() {
  return remove_participants(1);
}

int32 barrier::remove_participants(int32 participant_count) {
  if (!data_) throw object_closed_exception {};
  auto lock = lock_guard {*data_};
  if (participant_count < 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  if (data_->participant_count == 0 || data_->run_post_phase_action || data_->participants_remaining < data_->participant_count - participant_count) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
  if (data_->participant_count < participant_count) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  data_->participant_count -= participant_count;
  data_->participants_remaining -= participant_count;
  return data_->current_phase_number;
}

void barrier::signal_and_wait() {
  signal_and_wait(timeout::infinite);
}

bool barrier::signal_and_wait(int32 milliseconds_timeout) {
  if (milliseconds_timeout < timeout::infinite) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  if (!data_) throw object_closed_exception {};
  lock_(*data_) {
    data_->participants_remaining--;
    
    if (data_->participants_remaining == 0) {
      data_->run_post_phase_action = true;
      try {
        if (!data_->post_phase_action.is_empty()) data_->post_phase_action(*this);
      } catch(...) {
        data_->throw_barrier_post_phase_exception = true;
      }
      data_->run_post_phase_action = false;

      ++data_->current_phase_number;
      data_->participants_remaining.exchange(data_->participant_count);
      
      for (int i = 0; i < data_->participant_count; i++)
        data_->phase_semaphore.release();
    }
  }
  
  auto result = false;
  
  if (!data_->cancellation_token) result = data_->phase_semaphore.wait_one(milliseconds_timeout);
  else if (milliseconds_timeout == timeout::infinite) result = wait_wtih_cancellation_token();
  else result = wait_wtih_cancellation_token(milliseconds_timeout);
  if (data_->throw_barrier_post_phase_exception) throw barrier_post_phase_exception {};
  return result;
}

bool barrier::signal_and_wait(const cancellation_token& cancellation_token) {
  return signal_and_wait(timeout::infinite, cancellation_token);
}

bool barrier::signal_and_wait(const time_span& timeout) {
  return signal_and_wait(as<int32>(timeout.total_milliseconds()));
}

bool barrier::signal_and_wait(int32 milliseconds_timeout, const cancellation_token& cancellation_token) {
  data_->cancellation_token = &cancellation_token;
  return signal_and_wait(milliseconds_timeout);
}

bool barrier::signal_and_wait(const time_span& timeout, const cancellation_token& cancellation_token) {
  return signal_and_wait(as<int32>(timeout.total_milliseconds()), cancellation_token);
}

bool barrier::wait_wtih_cancellation_token() {
  auto result = false;
  while (!result) {
    if (data_->cancellation_token->is_cancellation_requested()) throw operation_canceled_exception {};
    result = data_->phase_semaphore.wait_one(1);
  }
  return result;
}

bool barrier::wait_wtih_cancellation_token(int32 milliseconds_timeout) {
  auto sw = stopwatch::start_new();
  auto result = false;
  while (!result && sw.elapsed_milliseconds() <= milliseconds_timeout) {
    if (data_->cancellation_token->is_cancellation_requested()) throw operation_canceled_exception {};
    result = data_->phase_semaphore.wait_one(1);
  }
  return result;
}
