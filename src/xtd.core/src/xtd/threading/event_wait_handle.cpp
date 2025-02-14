#include "named_event_wait_handle.hpp"
#include "unnamed_event_wait_handle.hpp"
#include "../../../include/xtd/argument_out_of_range_exception.hpp"
#include "../../../include/xtd/object_closed_exception.hpp"
#include "../../../include/xtd/io/io_exception.hpp"
#include "../../../include/xtd/io/path_too_long_exception.hpp"
#include "../../../include/xtd/threading/abandoned_mutex_exception.hpp"
#include "../../../include/xtd/threading/event_wait_handle.hpp"
#include <atomic>

using namespace xtd;
using namespace xtd::threading;

struct event_wait_handle::data {
  xtd::uptr<event_wait_handle_base> event_wait_handle;
  event_reset_mode mode = event_reset_mode::auto_reset;
  std::atomic<bool> is_set = false;
  string name;
};

event_wait_handle::event_wait_handle() : event_wait_handle(false) {
}

event_wait_handle::event_wait_handle(bool initial_state) : event_wait_handle(initial_state, event_reset_mode::auto_reset, string::empty_string) {
}

event_wait_handle::event_wait_handle(const string& name) : event_wait_handle(false, event_reset_mode::auto_reset, name) {
}

event_wait_handle::event_wait_handle(const string& name, bool& created_new) : event_wait_handle(false, event_reset_mode::auto_reset, name, created_new) {
}

event_wait_handle::event_wait_handle(bool initial_state, const string& name) : event_wait_handle(initial_state, event_reset_mode::auto_reset, name) {
}

event_wait_handle::event_wait_handle(bool initial_state, const string& name, bool& created_new) : event_wait_handle(initial_state, event_reset_mode::auto_reset, name, created_new) {
}

event_wait_handle::event_wait_handle(bool initial_state, event_reset_mode mode) : event_wait_handle(initial_state, mode, string::empty_string) {
  
}
event_wait_handle::event_wait_handle(bool initial_state, event_reset_mode mode, const string& name) : data_(xtd::new_sptr<event_wait_handle::data>()) {
  data_->mode = mode;
  data_->name = name;
  data_->is_set = initial_state;
  if (!enum_object<>::is_defined(mode)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  if (name.size() > native::named_event_wait_handle::max_name_size()) throw io::path_too_long_exception {};
  auto created_new = false;
  create(initial_state, created_new);
}

event_wait_handle::event_wait_handle(bool initial_state, event_reset_mode mode, const string& name, bool& created_new) : data_(xtd::new_sptr<event_wait_handle::data>()) {
  data_->mode = mode;
  data_->name = name;
  data_->is_set = initial_state;
  create(initial_state, created_new);
}

event_wait_handle::~event_wait_handle() {
  close();
}

intptr event_wait_handle::handle() const noexcept {
  return data_->event_wait_handle ? data_->event_wait_handle->handle() : invalid_handle;
}

void event_wait_handle::handle(intptr value) {
  data_->event_wait_handle->handle(value);
}

void event_wait_handle::close() {
  if (data_.use_count() == 1 && data_->event_wait_handle) {
    data_->event_wait_handle->destroy();
    data_->event_wait_handle.reset();
  }
}

int32 event_wait_handle::compare_to(const event_wait_handle& value) const noexcept {
  return handle() < value.handle() ? - 1 : handle() > value.handle() ? 1 : 0;
}

bool event_wait_handle::equals(const object& obj) const noexcept {
  return is<event_wait_handle>(obj) && equals(static_cast<const event_wait_handle&>(obj));
}

bool event_wait_handle::equals(const event_wait_handle& other) const noexcept {
  return handle() == other.handle();
}

event_wait_handle event_wait_handle::open_existing(const string& name) {
  if (name.empty()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  if (name.size() > native::named_event_wait_handle::max_name_size()) throw io::path_too_long_exception {};
  auto result = event_wait_handle{};
  if (!try_open_existing(name, result)) throw io::io_exception {};
  return result;
}

bool event_wait_handle::reset() {
  if (!data_) throw object_closed_exception {};
  auto io_error = false;
  auto result = data_->event_wait_handle->reset(io_error);
  if (io_error) throw io::io_exception {};
  return result;
}

bool event_wait_handle::set() {
  if (!data_) throw object_closed_exception {};
  if (data_->is_set) return true;
  auto io_error = false;
  auto result = data_->event_wait_handle->set(io_error);
  if (io_error) throw io::io_exception {};
  data_->is_set = true;
  return result;
}

bool event_wait_handle::try_open_existing(const string& name, event_wait_handle& result) noexcept {
  result.close();
  if (string::is_empty(name)) return false;
  if (name.size() > native::named_event_wait_handle::max_name_size()) return false;
  auto new_event_wait_handle = event_wait_handle {};
  new_event_wait_handle.data_->name = name;
  new_event_wait_handle.data_->event_wait_handle = xtd::new_uptr<event_wait_handle::named_event_wait_handle>();
  if (!new_event_wait_handle.data_->event_wait_handle->open(new_event_wait_handle.data_->name)) return false;
  result = new_event_wait_handle;
  return true;
}

bool event_wait_handle::signal() {
  return set();
}

bool event_wait_handle::wait(int32 milliseconds_timeout) {
  if (!data_) throw object_closed_exception {};
  if (milliseconds_timeout < -1) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  auto result = data_->event_wait_handle->wait(milliseconds_timeout);
  if (result == 0xFFFFFFFF) throw io::io_exception {};
  if (result == 0x00000080) throw abandoned_mutex_exception {};
  if (result == 0x00000102) return false;
  data_->is_set = false;
  return true;
}

void event_wait_handle::create(bool initial_state, bool& created_new) {
  created_new = true;
  if (data_->name.empty()) {
    data_->event_wait_handle = xtd::new_uptr<event_wait_handle::unnamed_event_wait_handle>();
    if (!data_->event_wait_handle->create(initial_state, data_->mode == xtd::threading::event_reset_mode::manual_reset)) throw io::io_exception {};
  } else {
    data_->event_wait_handle = xtd::new_uptr<event_wait_handle::named_event_wait_handle>();
    created_new = data_->event_wait_handle->create(initial_state, data_->mode == xtd::threading::event_reset_mode::manual_reset, data_->name);
    if (!created_new && !data_->event_wait_handle->open(data_->name)) throw io::io_exception {};
  }
}
