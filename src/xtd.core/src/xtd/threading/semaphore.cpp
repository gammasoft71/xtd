#include "named_semaphore.hpp"
#include "unnamed_semaphore.hpp"
#include "../../../include/xtd/argument_out_of_range_exception.hpp"
#include "../../../include/xtd/object_closed_exception.hpp"
#include "../../../include/xtd/io/io_exception.hpp"
#include "../../../include/xtd/io/path_too_long_exception.hpp"
#include "../../../include/xtd/threading/abandoned_mutex_exception.hpp"
#include <atomic>

using namespace xtd;
using namespace xtd::threading;

struct semaphore::data {
  std::atomic<int32> count = 0;
  std::atomic<int32> maximum_count = int32_object::max_value;
  string name;
};

semaphore::semaphore() : semaphore(0, int32_object::max_value) {
}

semaphore::semaphore(const string& name) : semaphore(0, int32_object::max_value, name) {
}

semaphore::semaphore(const string& name, bool& created_new) : semaphore(0, int32_object::max_value, name, created_new) {
}

semaphore::semaphore(int32 initial_count) : semaphore(initial_count, int32_object::max_value, string::empty_string) {
}

semaphore::semaphore(int32 initial_count, const string& name) : semaphore(initial_count, int32_object::max_value, name) {
}

semaphore::semaphore(int32 initial_count, const string& name, bool& created_new) : semaphore(initial_count, int32_object::max_value, name, created_new) {
}

semaphore::semaphore(int32 initial_count, int32 maximum_count) : semaphore(initial_count, maximum_count, string::empty_string) {
}

semaphore::semaphore(int32 initial_count, int32 maximum_count, const string& name) : data_(xtd::new_sptr<data>()) {
  data_->name = name;
  auto created_new = false;
  create(initial_count, maximum_count, created_new);
}

semaphore::semaphore(int32 initial_count, int32 maximum_count, const string& name, bool& created_new) : data_(xtd::new_sptr<data>()) {
  if (name.size() > native::named_semaphore::max_name_size()) throw io::path_too_long_exception {};
  if (initial_count > maximum_count) throw argument_exception {};
  if (maximum_count < 1 || initial_count < 0) throw argument_out_of_range_exception {};
  data_->name = name;
  create(initial_count, maximum_count, created_new);
}

semaphore::~semaphore() {
  close();
}

intptr semaphore::handle() const noexcept {
  return semaphore_ ? semaphore_->handle() : invalid_handle;
}

void semaphore::handle(intptr value) {
  semaphore_->handle(value);
}

void semaphore::close() {
  if (semaphore_.use_count() == 1) {
    semaphore_->destroy();
    semaphore_.reset();
  }
}

int32 semaphore::compare_to(const semaphore& value) const noexcept {
  return handle() < value.handle() ? - 1 : handle() > value.handle() ? 1 : 0;
}

bool semaphore::equals(const object& obj) const noexcept {
  return is<semaphore>(obj) && equals(static_cast<const semaphore&>(obj));
}

bool semaphore::equals(const semaphore& other) const noexcept {
  return handle() == other.handle();
}

semaphore semaphore::open_existing(const string& name) {
  if (name.empty()) throw argument_exception {};
  if (name.size() > native::named_semaphore::max_name_size()) throw io::path_too_long_exception {};
  auto result = semaphore{};
  if (!try_open_existing(name, result)) throw io::io_exception {};
  return result;
}

int32 semaphore::release() {
  return release(1);
}

int32 semaphore::release(int32 release_count) {
  if (release_count < 1) throw argument_out_of_range_exception {};
  if (!semaphore_) throw object_closed_exception {};
  if (data_->count + release_count > data_->maximum_count) throw semaphore_full_exception {};
  auto io_error = false;
  auto previous_count = -1;
  semaphore_->signal(io_error, release_count, previous_count);
  if (previous_count != -1) data_->count.exchange(previous_count);
  if (io_error) throw io::io_exception {};
  previous_count = data_->count;
  data_->count += release_count;
  return previous_count;
}

bool semaphore::try_open_existing(const string& name, semaphore& result) noexcept {
  result.close();
  if (string::is_empty(name)) return false;
  if (name.size() > native::named_semaphore::max_name_size()) return false;
  auto new_semaphore = semaphore {};
  new_semaphore.data_->name = name;
  new_semaphore.semaphore_ = xtd::new_sptr<semaphore::named_semaphore>();
  if (!new_semaphore.semaphore_->open(new_semaphore.data_->name)) return false;
  result = new_semaphore;
  return true;
}

bool semaphore::signal() {
  release();
  return true;
}

bool semaphore::wait(int32 milliseconds_timeout) {
  if (!semaphore_) throw object_closed_exception {};
  if (milliseconds_timeout < -1) throw argument_out_of_range_exception {};
  auto result = semaphore_->wait(milliseconds_timeout);
  if (result == 0xFFFFFFFF) throw io::io_exception {};
  if (result == 0x00000080) throw abandoned_mutex_exception {};
  if (result == 0x00000102) return false;
  --data_->count;
  return true;
}

void semaphore::create(int32 initial_count, int32 maximum_count, bool& created_new) {
  data_->count.exchange(initial_count);
  data_->maximum_count = maximum_count;
  created_new = true;
  if (data_->name.empty()) {
    semaphore_ = xtd::new_sptr<semaphore::unnamed_semaphore>();
    if (!semaphore_->create(initial_count, maximum_count)) throw io::io_exception {};
  } else {
    semaphore_ = xtd::new_sptr<semaphore::named_semaphore>();
    created_new = semaphore_->create(initial_count, maximum_count, data_->name);
    if (!created_new && !semaphore_->open(data_->name)) throw io::io_exception {};
  }
}
