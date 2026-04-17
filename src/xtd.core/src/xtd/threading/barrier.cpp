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
using namespace xtd::helpers;
using namespace xtd::diagnostics;
using namespace xtd::threading;

struct barrier::data : object {
  const threading::cancellation_token* cancellation_token = nullptr;
  std::atomic<usize> current_phase_number = 0;
  std::atomic<usize> participant_count = 0;
  std::atomic<usize> participants_remaining = 0;
  barrier::post_phase_action post_phase_action;
  bool run_post_phase_action = false;
  semaphore phase_semaphore;
  bool throw_barrier_post_phase_exception = false;
};

barrier::barrier() : barrier(0) {
}

barrier::barrier(size participant_count) : barrier(participant_count, {}) {
}

barrier::barrier(size participant_count, barrier::post_phase_action post_phase_action) : data_(xtd::new_sptr<data>()) {
  if (participant_count > as<usize>(int16_object::max_value)) throw_helper::throws(exception_case::argument_out_of_range);
  data_->participant_count = participant_count;
  data_->participants_remaining = participant_count;
  data_->post_phase_action = post_phase_action;
}

auto barrier::operator =(const barrier& other) -> barrier& {
  close();
  data_ = other.data_;
  return *this;
}

barrier::~barrier() {
  if (data_.use_count() == 1) close();
}

auto barrier::current_phase_number() const -> size {
  if (!data_) throw_helper::throws(exception_case::object_closed);
  return data_->current_phase_number;
}

auto barrier::participant_count() const -> size {
  if (!data_) throw_helper::throws(exception_case::object_closed);
  return data_->participant_count;
}

auto barrier::participants_remaining() const -> size {
  if (!data_) throw_helper::throws(exception_case::object_closed);
  return data_->participants_remaining;
}

auto barrier::add_participant() -> size {
  return add_participants(1);
}

auto barrier::add_participants(size participant_count) -> size {
  if (!data_) throw_helper::throws(exception_case::object_closed);
  auto lock = threading::lock {*data_};
  if (data_->participant_count + participant_count > as<usize>(int16_object::max_value)) throw_helper::throws(exception_case::argument_out_of_range);
  if (data_->run_post_phase_action) throw_helper::throws(exception_case::invalid_operation);
  data_->participant_count += participant_count;
  data_->participants_remaining += participant_count;
  return data_->current_phase_number;
}

auto barrier::close() -> void {
  data_.reset();
}

auto barrier::remove_participant() -> size {
  return remove_participants(1);
}

auto barrier::remove_participants(size participant_count) -> size {
  if (!data_) throw_helper::throws(exception_case::object_closed);
  auto lock = threading::lock {*data_};
  if (data_->participant_count < participant_count) throw_helper::throws(exception_case::argument_out_of_range);
  if (data_->participant_count == 0 || data_->run_post_phase_action || data_->participants_remaining < data_->participant_count - participant_count) throw_helper::throws(exception_case::invalid_operation);
  data_->participant_count -= participant_count;
  data_->participants_remaining -= participant_count;
  return data_->current_phase_number;
}

auto barrier::signal_and_wait() -> void {
  signal_and_wait(timeout::infinite);
}

auto barrier::signal_and_wait(int32 milliseconds_timeout) -> bool {
  if (milliseconds_timeout < timeout::infinite) throw_helper::throws(exception_case::argument_out_of_range);
  if (!data_) throw_helper::throws(exception_case::object_closed);
  lock_(*data_) {
    data_->participants_remaining--;
    
    if (data_->participants_remaining == 0) {
      data_->run_post_phase_action = true;
      try {
        if (!data_->post_phase_action.is_empty()) data_->post_phase_action(*this);
      } catch (...) {
        data_->throw_barrier_post_phase_exception = true;
      }
      data_->run_post_phase_action = false;
      
      ++data_->current_phase_number;
      data_->participants_remaining.exchange(data_->participant_count);
      
      for (auto i = 0_z; i < data_->participant_count; i++)
        data_->phase_semaphore.release();
    }
  }
  
  auto result = false;
  
  if (!data_->cancellation_token) result = data_->phase_semaphore.wait_one(milliseconds_timeout);
  else if (milliseconds_timeout == timeout::infinite) result = wait_wtih_cancellation_token();
  else result = wait_wtih_cancellation_token(milliseconds_timeout);
  if (data_->throw_barrier_post_phase_exception) throw_helper::throws(exception_case::barrier_post_phase);
  return result;
}

auto barrier::signal_and_wait(const cancellation_token& cancellation_token) -> bool {
  return signal_and_wait(timeout::infinite, cancellation_token);
}

auto barrier::signal_and_wait(const time_span& timeout) -> bool {
  return signal_and_wait(as<int32>(timeout.total_milliseconds()));
}

auto barrier::signal_and_wait(int32 milliseconds_timeout, const cancellation_token& cancellation_token) -> bool {
  data_->cancellation_token = &cancellation_token;
  return signal_and_wait(milliseconds_timeout);
}

auto barrier::signal_and_wait(const time_span& timeout, const cancellation_token& cancellation_token) -> bool {
  return signal_and_wait(as<int32>(timeout.total_milliseconds()), cancellation_token);
}

auto barrier::wait_wtih_cancellation_token() -> bool {
  auto result = false;
  while (!result) {
    if (data_->cancellation_token->is_cancellation_requested()) throw_helper::throws(exception_case::operation_canceled);
    result = data_->phase_semaphore.wait_one(1);
  }
  return result;
}

auto barrier::wait_wtih_cancellation_token(int32 milliseconds_timeout) -> bool {
  auto sw = stopwatch::start_new();
  auto result = false;
  while (!result && sw.elapsed_milliseconds() <= milliseconds_timeout) {
    if (data_->cancellation_token->is_cancellation_requested()) throw_helper::throws(exception_case::operation_canceled);
    result = data_->phase_semaphore.wait_one(1);
  }
  return result;
}
