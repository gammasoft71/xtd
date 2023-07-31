#include "named_semaphore.h"
#include "unnamed_semaphore.h"
#include "../../../include/xtd/argument_out_of_range_exception.h"
#include "../../../include/xtd/object_closed_exception.h"
#include "../../../include/xtd/invalid_operation_exception.h"
#include "../../../include/xtd/io/io_exception.h"
#include "../../../include/xtd/io/path_too_long_exception.h"
#include "../../../include/xtd/threading/abandoned_mutex_exception.h"

using namespace xtd;
using namespace xtd::threading;

class semaphore::semaphore_base {
public:
  virtual ~semaphore_base() = default;
  
  virtual intptr handle() const noexcept = 0;
  virtual void handle(intptr value) = 0;
  virtual bool create(int32 initial_count, int32 maximum_count) = 0;
  virtual bool create(int32 initial_count, int32 maximum_count, const ustring& name) = 0;
  virtual void destroy() = 0;
  virtual bool open(const ustring& name) = 0;
  virtual bool signal(bool& io_error, int32 release_count, int32& previous_count) = 0;
  virtual uint32 wait(int32 milliseconds_timeout) = 0;
};

class semaphore::named_semaphore : public semaphore_base {
public:
  ~named_semaphore() {destroy();}

  intptr handle() const noexcept override {
    return handle_;
  }
  
  void handle(intptr value) override {
    handle_ = value;
  }
  
  bool create(int32 initial_count, int32 maximum_count) override {
    throw invalid_operation_exception {csf_};
  }
  
  bool create(int32 initial_count, int32 maximum_count, const ustring& name) override {
    name_ = name;
    handle_ = native::named_semaphore::create(initial_count, maximum_count, name);
    return handle_ != invalid_handle;
  }
  
  void destroy() override {
    if (handle_ == invalid_handle) return;
    native::named_semaphore::destroy(handle_, name_);
    handle_ = invalid_handle;
  }
  
  bool open(const ustring& name) override {
    name_ = name;
    handle_ = native::named_semaphore::open(name);
    return handle_ != invalid_handle;
  }

  bool signal(bool& io_error, int32 release_count, int32& previous_count) override {
    io_error = false;
    return native::named_semaphore::signal(handle_, release_count, previous_count, io_error);
  }
  
  uint32 wait(int32 milliseconds_timeout) override {
    return native::named_semaphore::wait(handle_, milliseconds_timeout);
  }
  
private:
  intptr handle_ = invalid_handle;
  ustring name_;
};

class semaphore::unnamed_semaphore : public semaphore_base {
public:
  ~unnamed_semaphore() {destroy();}

  intptr handle() const noexcept override {
    return handle_ ? reinterpret_cast<intptr>(handle_.get()) : invalid_handle;
  }
  
  void handle(intptr value) override {
    throw invalid_operation_exception {csf_};
  }

  bool create(int32 initial_count, int32 maximum_count) override {
    handle_ = std::make_shared<data>();
    handle_->maximum_count = maximum_count;
    uint32 error = 0;
    for (auto index = 0; !error && index < initial_count; ++index)
      error = wait(-1);
    if (error) return false;
    return true;
  }
  
  bool create(int32 initial_count, int32 maximum_count, const ustring& name) override {
    throw invalid_operation_exception {csf_};
  }

  void destroy() override {
    if (!handle_) return;
    handle_.reset();
  }
  
  bool open(const ustring& name) override {
    throw invalid_operation_exception {csf_};
  }

  bool signal(bool& io_error, int32 release_count, int32& previous_count) override {
    std::unique_lock<std::mutex> lock(handle_->mutex);
    previous_count = handle_->count;
    for (int count = 0; count < release_count; ++count) {
      if (handle_->count + 1 >= handle_->maximum_count) {
        io_error = true;
        return false;
      }
      handle_->count++;
      handle_->condition.notify_one();
    }
    return true;
  }

  uint32 wait(int32 milliseconds_timeout) override {
    std::unique_lock<std::mutex> lock(handle_->mutex);
    if (handle_->count == 0) return 0xFFFFFFFF;

    if (milliseconds_timeout == -1) {
      handle_->condition.wait(lock);
      handle_->count--;
      return 0x00000000;
    }
    if (handle_->condition.wait_for(lock, std::chrono::milliseconds {milliseconds_timeout}) == std::cv_status::timeout) return 0x00000102;
    handle_->count--;
    return 0x00000000;
  }
  
private:
  struct data {
    std::condition_variable condition;
    int count = 0;
    int maximum_count = std::numeric_limits<int>::max();
    std::mutex mutex;
  };
  std::shared_ptr<data> handle_;
};

semaphore::semaphore() : semaphore(0, int32_object::max_value) {
}

semaphore::semaphore(int32 initial_count, int32 maximum_count) : semaphore(initial_count, maximum_count, "") {
}

semaphore::semaphore(int32 initial_count, int32 maximum_count, const ustring& name) : name_(name) {
  bool created_new = false;
  create(initial_count, maximum_count, created_new);
}

semaphore::semaphore(int32 initial_count, int32 maximum_count, const ustring& name, bool created_new) : name_(name) {
  if (name.size() > native::named_semaphore::max_name_size()) throw io::path_too_long_exception {csf_};
  if (initial_count > maximum_count) throw argument_exception {csf_};
  if (maximum_count < 1 || initial_count < 0) throw argument_out_of_range_exception {csf_};
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

bool semaphore::equals(const semaphore& value) const noexcept {
  return semaphore_ == value.semaphore_ && name_ == value.name_;
}

semaphore semaphore::open_existing(const ustring& name) {
  if (name.empty()) throw argument_exception {csf_};
  if (name.size() > native::named_semaphore::max_name_size()) throw io::path_too_long_exception {csf_};
  auto result = semaphore{};
  if (!try_open_existing(name, result)) throw argument_exception {csf_};
  return result;
}

int32 semaphore::release() {
  return release(1);
}

int32 semaphore::release(int32 release_count) {
  if (release_count < 1) throw argument_out_of_range_exception {csf_};
  if (!semaphore_) throw object_closed_exception {csf_};
  if (count_ + release_count >= maximum_count_) throw semaphore_full_exception {csf_};
  bool io_error = false;
  int32 previous_count = 0;
  semaphore_->signal(io_error, release_count, previous_count);
  if (previous_count != -1) count_ = previous_count;
  if (io_error) throw io::io_exception {csf_};
  return count_++;
}

bool semaphore::try_open_existing(const ustring& name, semaphore& result) noexcept {
  if (ustring::is_empty(name)) return false;
  if (name.size() > native::named_semaphore::max_name_size()) return false;
  auto new_semaphore = semaphore {};
  new_semaphore.name_ = name;
  new_semaphore.semaphore_ = std::make_shared<semaphore::named_semaphore>();
  if (new_semaphore.semaphore_->open(new_semaphore.name_)) return false;
  result = new_semaphore;
  return true;
}

bool semaphore::signal() {
  release();
  return true;
}

bool semaphore::wait(int32 milliseconds_timeout) {
  if (!semaphore_) throw object_closed_exception {csf_};
  if (milliseconds_timeout < -1) throw argument_out_of_range_exception {csf_};
  auto result = semaphore_->wait(milliseconds_timeout);
  if (result == 0xFFFFFFFF) throw io::io_exception {csf_};
  if (result == 0x00000080) throw abandoned_mutex_exception {csf_};
  if (result == 0x00000102) return false;
  return true;
}

void semaphore::create(int32 initial_count, int32 maximum_count, bool& created_new) {
  created_new = true;
  if (name_.empty()) {
    semaphore_ = std::make_shared<semaphore::unnamed_semaphore>();
    if (!semaphore_->create(initial_count, maximum_count)) throw io::io_exception(csf_);
  } else {
    semaphore_ = std::make_shared<semaphore::named_semaphore>();
    created_new = semaphore_->create(initial_count, maximum_count, name_);
    if (!created_new && !semaphore_->open(name_)) throw io::io_exception(csf_);
  }
}
