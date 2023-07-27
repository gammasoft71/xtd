#include "../../../include/xtd/threading/mutex.h"
#include "../../../include/xtd/argument_out_of_range_exception.h"
#include "../../../include/xtd/object_closed_exception.h"
#include "../../../include/xtd/invalid_operation_exception.h"
#include "../../../include/xtd/io//io_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/mutex.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <mutex>

using namespace xtd;
using namespace xtd::threading;

class mutex::mutex_base {
public:
  /*
  mutex_base() = default;
  mutex_base(mutex_base&&) = default;
  mutex_base(const mutex_base&) = default;
  mutex_base& operator=(const mutex_base&) = default;
   */
  virtual ~mutex_base() {}
  
  virtual intptr_t handle() const noexcept = 0;
  virtual void handle(intptr_t value) = 0;
  virtual bool create() = 0;
  virtual bool create(const ustring& name, bool& create_new) = 0;
  virtual void destroy() = 0;
  virtual bool signal() = 0;
  virtual bool wait(int32_t milliseconds_timeout) = 0;
};

class mutex::named_mutex : public mutex_base {
public:
  /*
  named_mutex() = default;
  named_mutex(named_mutex&&) = default;
  named_mutex(const named_mutex&) = default;
  named_mutex& operator=(const named_mutex&) = default;
   */
  
  intptr_t handle() const noexcept override {
    return handle_;
  }
  
  void handle(intptr_t value) override {
    handle_ = value;
  }
  
  bool create() override {
    throw invalid_operation_exception {csf_};
  }
  
  bool create(const ustring& name, bool& create_new) override {
    name_ = name;
    handle_ = native::mutex::create(name, create_new);
    return handle_ != invalid_handle;
  }
  
  void destroy() override {
    native::mutex::destroy(handle_, name_);
  }
  
  bool signal() override {
    return native::mutex::signal(handle_);
  }
  
  bool wait(int32_t milliseconds_timeout) override {
    return native::mutex::wait(handle_, milliseconds_timeout);
  }
  
private:
  intptr_t handle_ = invalid_handle;
  ustring name_;
};

class mutex::unnamed_mutex : public mutex_base {
public:
  /*
  unnamed_mutex() = default;
  unnamed_mutex(unnamed_mutex&&) = default;
  unnamed_mutex(const unnamed_mutex&) = default;
  unnamed_mutex& operator=(const unnamed_mutex&) = default;
   */

  intptr_t handle() const noexcept override {
    return reinterpret_cast<intptr_t>(handle_.get());
  }
  
  void handle(intptr_t value) override {
    handle_.reset(reinterpret_cast<std::recursive_timed_mutex*>(value));
  }

  bool create() override {
    handle_ = std::make_shared<std::recursive_timed_mutex>();
    return true;
  }
  
  bool create(const ustring& name, bool& create_new) override {
    throw invalid_operation_exception {csf_};
  }

  void destroy() override {
    handle_.reset();
  }

  bool signal() override {
    auto result = false;
    handle_->unlock();
    std::swap(locked_, result);
    return result;
  }

  bool wait(int32_t milliseconds_timeout) override {
    if (milliseconds_timeout != timeout::infinite) return (locked_ = handle_->try_lock_for(std::chrono::milliseconds {milliseconds_timeout}));
    handle_->lock();
    locked_ = true;
    return locked_;
  }
  
private:
  std::shared_ptr<std::recursive_timed_mutex> handle_;
  bool locked_ = false;
};

mutex::mutex() {
  bool created_new = false;
  create(false, created_new);
}

mutex::mutex(bool initially_owned) {
  bool created_new = false;
  create(initially_owned, created_new);
}

mutex::mutex(bool initially_owned, const ustring& name) : name_(name) {
  bool created_new = false;
  create(initially_owned, created_new);
}

mutex::mutex(bool initially_owned, const ustring& name, bool created_new) : name_(name) {
  create(initially_owned, created_new);
}

intptr_t mutex::handle() const noexcept {
  return mutex_->handle();
}

void mutex::handle(intptr_t value) {
  mutex_->handle(value);
}

void mutex::close() {
  if (mutex_.use_count() == 1) mutex_->destroy();
}

mutex mutex::open_existing(const ustring& name) {
  auto result = mutex{};
  if (!try_open_existing(name, result)) throw argument_exception {csf_};
  return result;
}

bool mutex::try_open_existing(const ustring& name, mutex& result) {
  if (ustring::is_empty(name)) return false;
  auto new_mutex = mutex {};
  new_mutex.name_ = name;
  new_mutex.mutex_ = std::make_shared<mutex::named_mutex>();
  bool created_new = true;
  if (new_mutex.mutex_->create(new_mutex.name_, created_new)) return false;
  if (created_new) return false;
  result = new_mutex;
  return true;
}

bool mutex::signal() {
  if (!mutex_) throw object_closed_exception {csf_};
  return mutex_->signal();
}

bool mutex::wait(int32_t milliseconds_timeout) {
  if (!mutex_) throw object_closed_exception {csf_};
  if (milliseconds_timeout < -1) throw argument_out_of_range_exception {csf_};
  return mutex_->wait(milliseconds_timeout);
}

void mutex::create(bool initially_owned, bool& created_new) {
  created_new = true;
  if (name_.empty()) {
    mutex_ = std::make_shared<mutex::unnamed_mutex>();
    if (!mutex_->create()) throw io::io_exception(csf_);
  } else {
    mutex_ = std::make_shared<mutex::named_mutex>();
    if (!mutex_->create(name_, created_new)) throw io::io_exception(csf_);
  }
  if (initially_owned) wait_one();
}
