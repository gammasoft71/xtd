#include "../../../include/xtd/threading/countdown_event.h"
#include "../../../include/xtd/threading/manual_reset_event.h"
#include "../../../include/xtd/argument_out_of_range_exception.h"
#include "../../../include/xtd/invalid_operation_exception.h"
#include "../../../include/xtd/object_closed_exception.h"
#include "../../../include/xtd/lock.h"

using namespace xtd;
using namespace xtd::threading;

struct countdown_event::data : object {
  int32 current_count = 0;
  int32 initial_count = 0;
  manual_reset_event event {false};
};

countdown_event::countdown_event() : countdown_event(0) {
}

countdown_event::countdown_event(int32 initial_count) : data_(std::make_shared<data>()) {
  if (initial_count < 0) throw argument_out_of_range_exception {csf_};
  data_->current_count = initial_count;
  data_->initial_count = initial_count;
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
  if (!data_) throw object_closed_exception {csf_};
  return data_->current_count;
}

int32 countdown_event::initial_count() const {
  if (!data_) throw object_closed_exception {csf_};
  return data_->initial_count;
}

bool countdown_event::is_set() const {
  if (!data_) throw object_closed_exception {csf_};
  return data_->current_count == 0;
}

const xtd::threading::wait_handle& countdown_event::wait_handle() const {
  if (!data_) throw object_closed_exception {csf_};
  return data_->event;
}

xtd::threading::wait_handle& countdown_event::wait_handle() {
  if (!data_) throw object_closed_exception {csf_};
  return data_->event;
}

void countdown_event::close() {
  data_.reset();
}

void countdown_event::add_count() {
  if (!data_) throw object_closed_exception {csf_};
  reset(1);
}

void countdown_event::add_count(int32 count) {
  if (!data_) throw object_closed_exception {csf_};
  if (count < 0) throw argument_out_of_range_exception {csf_};
  if (data_->current_count == 0) throw invalid_operation_exception {csf_};
  lock_(*data_) data_->current_count += count;
}

void countdown_event::reset() {
  if (!data_) throw object_closed_exception {csf_};
  reset(data_->initial_count);
}

void countdown_event::reset(int32 count) {
  if (!data_) throw object_closed_exception {csf_};
  if (count < 0) throw argument_out_of_range_exception {csf_};
  lock_(*data_) {
    data_->event.reset();
    data_->initial_count = count;
    data_->current_count = count;
  }
}

void countdown_event::signal() {
  if (!data_) throw object_closed_exception {csf_};
  signal(1);
}

void countdown_event::signal(int32 signal_count) {
  if (!data_) throw object_closed_exception {csf_};
  if (signal_count < 0 || signal_count > data_->current_count) throw argument_out_of_range_exception {csf_};
  lock_(*data_) {
    data_->current_count -= signal_count;
    if (data_->current_count == 0) data_->event.set();
  }
}

bool countdown_event::try_add_count() noexcept {
  return try_add_count(1);
}

bool countdown_event::try_add_count(int32 count) noexcept {
  if (!data_ || count < 0 || data_->current_count == 0) return false;
  lock_(*data_) data_->current_count += count;
  return true;
}
