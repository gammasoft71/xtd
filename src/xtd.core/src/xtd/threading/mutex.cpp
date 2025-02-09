#include "named_mutex.hpp"
#include "unnamed_mutex.hpp"
#include "../../../include/xtd/argument_out_of_range_exception.hpp"
#include "../../../include/xtd/object_closed_exception.hpp"
#include "../../../include/xtd/io/io_exception.hpp"
#include "../../../include/xtd/io/path_too_long_exception.hpp"
#include "../../../include/xtd/threading/abandoned_mutex_exception.hpp"

using namespace xtd;
using namespace xtd::threading;

mutex::mutex() : mutex(false) {
}

mutex::mutex(bool initially_owned) : mutex(initially_owned, string::empty_string) {
}

mutex::mutex(const string& name) : mutex(false, name) {
}

mutex::mutex(const string& name, bool& created_new) : mutex(false, name, created_new) {
}

mutex::mutex(bool initially_owned, const string& name) : name_(name) {
  if (name.size() > native::named_mutex::max_name_size()) throw io::path_too_long_exception {};
  auto created_new = false;
  create(initially_owned, created_new);
}

mutex::mutex(bool initially_owned, const string& name, bool& created_new) : name_(name) {
  create(initially_owned, created_new);
}

mutex::~mutex() {
  close();
}

intptr mutex::handle() const noexcept {
  return mutex_ ? mutex_->handle() : invalid_handle;
}

void mutex::handle(intptr value) {
  mutex_->handle(value);
}

mutex::native_handle_type mutex::native_handle() const noexcept {
  return handle();
}

void mutex::close() {
  if (mutex_.use_count() == 1) {
    mutex_->destroy();
    mutex_.reset();
  }
}

int32 mutex::compare_to(const mutex& value) const noexcept {
  return handle() < value.handle() ? - 1 : handle() > value.handle() ? 1 : 0;
}

bool mutex::equals(const object& obj) const noexcept {
  return is<mutex>(obj) && equals(static_cast<const mutex&>(obj));
}

bool mutex::equals(const mutex& other) const noexcept {
  return mutex_ == other.mutex_ && name_ == other.name_;
}

void mutex::lock() {
  wait_one();
}

mutex mutex::open_existing(const string& name) {
  if (name.empty()) throw argument_exception {};
  if (name.size() > native::named_mutex::max_name_size()) throw io::path_too_long_exception {};
  auto result = mutex{};
  if (!try_open_existing(name, result)) throw io::io_exception {};
  return result;
}

void mutex::release_mutex() {
  if (!signal()) throw io::io_exception {};
}

bool mutex::try_lock() noexcept {
  try {
    return wait_one(0);
  } catch(...) {
    return false;
  }
}

bool mutex::try_lock_for(const time_span& timeout) noexcept {
  try {
    return wait_one(static_cast<int32>(timeout.total_milliseconds()));
  } catch(...) {
    return false;
  }
}

bool mutex::try_lock_until(const date_time& timeout_time) noexcept {
  try {
    return try_lock_for(date_time::now() - timeout_time);
  } catch(...) {
    return false;
  }
}

bool mutex::try_open_existing(const string& name, mutex& result) noexcept {
  result.close();
  if (string::is_empty(name)) return false;
  if (name.size() > native::named_mutex::max_name_size()) return false;
  auto new_mutex = mutex {};
  new_mutex.name_ = name;
  new_mutex.mutex_ = xtd::new_sptr<mutex::named_mutex>();
  if (!new_mutex.mutex_->open(new_mutex.name_)) return false;
  result = new_mutex;
  return true;
}

void mutex::unlock() {
  release_mutex();
}

bool mutex::signal() {
  if (!mutex_) throw object_closed_exception {};
  auto io_error = false;
  auto result = mutex_->signal(io_error);
  if (io_error) throw io::io_exception {};
  return result;
}

bool mutex::wait(int32 milliseconds_timeout) {
  if (!mutex_) throw object_closed_exception {};
  if (milliseconds_timeout < -1) throw argument_out_of_range_exception {};
  auto result = mutex_->wait(milliseconds_timeout);
  if (result == 0xFFFFFFFF) throw io::io_exception {};
  if (result == 0x00000080) throw abandoned_mutex_exception {};
  if (result == 0x00000102) return false;
  return true;
}

void mutex::create(bool initially_owned, bool& created_new) {
  created_new = true;
  if (name_.empty()) {
    mutex_ = xtd::new_sptr<mutex::unnamed_mutex>();
    if (!mutex_->create(initially_owned)) throw io::io_exception {};
  } else {
    mutex_ = xtd::new_sptr<mutex::named_mutex>();
    created_new = mutex_->create(initially_owned, name_);
    if (!created_new && !mutex_->open(name_)) throw io::io_exception {};
  }
}
