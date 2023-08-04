#include "named_event_wait_handle.h"
#include "unnamed_event_wait_handle.h"
#include "../../../include/xtd/argument_out_of_range_exception.h"
#include "../../../include/xtd/object_closed_exception.h"
#include "../../../include/xtd/io/io_exception.h"
#include "../../../include/xtd/io/path_too_long_exception.h"
#include "../../../include/xtd/threading/abandoned_mutex_exception.h"

using namespace xtd;
using namespace xtd::threading;

event_wait_handle::event_wait_handle() : event_wait_handle(false) {
}

event_wait_handle::event_wait_handle(bool initial_state) : event_wait_handle(initial_state, event_reset_mode::auto_reset, "") {
}

event_wait_handle::event_wait_handle(const ustring& name) : event_wait_handle(false, event_reset_mode::auto_reset, name) {
}

event_wait_handle::event_wait_handle(const ustring& name, bool& created_new) : event_wait_handle(false, event_reset_mode::auto_reset, name, created_new) {
}

event_wait_handle::event_wait_handle(bool initial_state, const ustring& name)  : event_wait_handle(initial_state, event_reset_mode::auto_reset, name) {
}

event_wait_handle::event_wait_handle(bool initial_state, const ustring& name, bool& created_new)  : event_wait_handle(initial_state, event_reset_mode::auto_reset, name, created_new) {
}

event_wait_handle::event_wait_handle(bool initial_state, event_reset_mode mode)  : event_wait_handle(initial_state, mode, "") {
  
}
event_wait_handle::event_wait_handle(bool initial_state, event_reset_mode mode, const ustring& name) : mode_(mode), name_(name){
  if (!enum_object<>::is_defined(mode)) throw argument_exception {csf_};
  if (name.size() > native::named_event_wait_handle::max_name_size()) throw io::path_too_long_exception {csf_};
  bool created_new = false;
  create(initial_state, created_new);
}

event_wait_handle::event_wait_handle(bool initial_state, event_reset_mode mode, const ustring& name, bool& created_new) : mode_(mode), name_(name) {
  create(initial_state, created_new);
}

event_wait_handle::~event_wait_handle() {
  close();
}

intptr event_wait_handle::handle() const noexcept {
  return event_wait_handle_ ? event_wait_handle_->handle() : invalid_handle;
}

void event_wait_handle::handle(intptr value) {
  event_wait_handle_->handle(value);
}

void event_wait_handle::close() {
  if (event_wait_handle_.use_count() == 1) {
    event_wait_handle_->destroy();
    event_wait_handle_.reset();
  }
}

bool event_wait_handle::equals(const event_wait_handle& value) const noexcept {
  return event_wait_handle_ == value.event_wait_handle_ && name_ == value.name_;
}

event_wait_handle event_wait_handle::open_existing(const ustring& name) {
  if (name.empty()) throw argument_exception {csf_};
  if (name.size() > native::named_event_wait_handle::max_name_size()) throw io::path_too_long_exception {csf_};
  auto result = event_wait_handle{};
  if (!try_open_existing(name, result)) throw io::io_exception {csf_};
  return result;
}

bool event_wait_handle::reset() {
  if (!event_wait_handle_) throw object_closed_exception {csf_};
  bool io_error = false;
  auto result = event_wait_handle_->reset(io_error);
  if (io_error) throw io::io_exception {csf_};
  return result;
}

bool event_wait_handle::set() {
  if (!event_wait_handle_) throw object_closed_exception {csf_};
  bool io_error = false;
  auto result = event_wait_handle_->set(io_error);
  if (io_error) throw io::io_exception {csf_};
  return result;
}

bool event_wait_handle::try_open_existing(const ustring& name, event_wait_handle& result) noexcept {
  result.close();
  if (ustring::is_empty(name)) return false;
  if (name.size() > native::named_event_wait_handle::max_name_size()) return false;
  auto new_event_wait_handle = event_wait_handle {};
  new_event_wait_handle.name_ = name;
  new_event_wait_handle.event_wait_handle_ = std::make_shared<event_wait_handle::named_event_wait_handle>();
  if (!new_event_wait_handle.event_wait_handle_->open(new_event_wait_handle.name_)) return false;
  result = new_event_wait_handle;
  return true;
}

bool event_wait_handle::signal() {
  return set();
}

bool event_wait_handle::wait(int32 milliseconds_timeout) {
  if (!event_wait_handle_) throw object_closed_exception {csf_};
  if (milliseconds_timeout < -1) throw argument_out_of_range_exception {csf_};
  auto result = event_wait_handle_->wait(milliseconds_timeout);
  if (result == 0xFFFFFFFF) throw io::io_exception {csf_};
  if (result == 0x00000080) throw abandoned_mutex_exception {csf_};
  if (result == 0x00000102) return false;
  return true;
}

void event_wait_handle::create(bool initial_state, bool& created_new) {
  created_new = true;
  if (name_.empty()) {
    event_wait_handle_ = std::make_shared<event_wait_handle::unnamed_event_wait_handle>();
    if (!event_wait_handle_->create(initial_state, mode_ == xtd::threading::event_reset_mode::manual_reset)) throw io::io_exception(csf_);
  } else {
    event_wait_handle_ = std::make_shared<event_wait_handle::named_event_wait_handle>();
    created_new = event_wait_handle_->create(initial_state, mode_ == xtd::threading::event_reset_mode::manual_reset, name_);
    if (!created_new && !event_wait_handle_->open(name_)) throw io::io_exception(csf_);
  }
}
