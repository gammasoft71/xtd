#include "../../../include/xtd/threading/semaphore.h"
#include "../../../include/xtd/argument_out_of_range_exception.h"
#include "../../../include/xtd/object_closed_exception.h"
#include "../../../include/xtd/invalid_operation_exception.h"
#include "../../../include/xtd/io//io_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/named_semaphore.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <condition_variable>
#include <mutex>

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
  virtual bool signal(bool& io_error, int32& previous_count) = 0;
  virtual bool wait(int32 milliseconds_timeout, bool& io_error) = 0;
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

  bool signal(bool& io_error, int32& previous_count) override {
    io_error = false;
    return native::named_semaphore::signal(handle_, previous_count, io_error);
  }
  
  bool wait(int32 milliseconds_timeout, bool& io_error) override {
    io_error = false;
    return native::named_semaphore::wait(handle_, milliseconds_timeout, io_error);
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
    bool io_error = false;
    for (auto index = 0; !io_error && index < initial_count; ++index)
      wait(-1, io_error);
    if (io_error) return false;
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

  bool signal(bool& io_error, int32& previous_count) override {
    if (handle_->count + 1 >= handle_->maximum_count) {
      io_error = true;
      return false;
    }
    previous_count = handle_->count;
    std::unique_lock<std::mutex> lock(handle_->mutex);
    handle_->count++;
    handle_->condition.notify_one();
    return true;
  }

  bool wait(int32 milliseconds_timeout, bool& io_error) override {
    if (milliseconds_timeout == -1) {
      std::unique_lock<std::mutex> lock(handle_->mutex);
      while (handle_->count == 0)
        handle_->condition.wait(lock);
      return handle_->count--;
    }
    std::unique_lock<std::mutex> lock(handle_->mutex);
    while (handle_->count == 0)
      handle_->condition.wait_for(lock, std::chrono::milliseconds {milliseconds_timeout});
    return handle_->count--;
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

semaphore::semaphore(int32 initial_count, int32 maximum_count) {
  bool created_new = false;
  create(initial_count, maximum_count, created_new);
}

semaphore::semaphore(int32 initial_count, int32 maximum_count, const ustring& name) : name_(name) {
  bool created_new = false;
  create(initial_count, maximum_count, created_new);
}

semaphore::semaphore(int32 initial_count, int32 maximum_count, const ustring& name, bool created_new) : name_(name) {
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

semaphore semaphore::open_existing(const ustring& name) {
  auto result = semaphore{};
  if (!try_open_existing(name, result)) throw argument_exception {csf_};
  return result;
}

int32 semaphore::release() {
  if (!semaphore_) throw object_closed_exception {csf_};
  if (count_ + 1 >= maximum_count_) throw semaphore_full_exception {csf_};
  bool io_error = false;
  int32 previous_count = 0;
  semaphore_->signal(io_error, previous_count);
  if (previous_count != -1) count_ = previous_count;
  if (io_error) throw io::io_exception {csf_};
  return count_++;
}

bool semaphore::try_open_existing(const ustring& name, semaphore& result) noexcept {
  if (ustring::is_empty(name)) return false;
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
  bool io_error = false;
  auto result = semaphore_->wait(milliseconds_timeout, io_error);
  if (io_error) throw io::io_exception {csf_};
  return result;
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
