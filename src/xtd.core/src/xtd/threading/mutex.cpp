#include "../../../include/xtd/threading/mutex.h"
#include "../../../include/xtd/argument_out_of_range_exception.h"
#include "../../../include/xtd/object_closed_exception.h"
#include "../../../include/xtd/invalid_operation_exception.h"
#include "../../../include/xtd/io//io_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/mutex.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::threading;

class mutex::mutex_base {
public:
  mutex_base() = default;
  mutex_base(mutex_base&&) = default;
  mutex_base(const mutex_base&) = default;
  mutex_base& operator=(const mutex_base&) = default;
  virtual ~mutex_base() {}
  
  virtual intptr_t handle() const noexcept = 0;
  virtual void handle(intptr_t value) = 0;
  virtual void create() = 0;
  virtual void create(const ustring& name, bool& create_new) = 0;
  virtual void destroy() = 0;
  virtual bool signal() = 0;
  virtual bool wait(int32_t milliseconds_timeout) = 0;
};

class mutex::named_mutex : public mutex_base {
public:
  named_mutex() = default;
  named_mutex(named_mutex&&) = default;
  named_mutex(const named_mutex&) = default;
  named_mutex& operator=(const named_mutex&) = default;

  intptr_t handle() const noexcept override {
    return reinterpret_cast<intptr_t>(handle_.get());
  }
  
  void handle(intptr_t value) override {
    handle_.reset(reinterpret_cast<std::recursive_timed_mutex*>(value));
  }

  void create() override {
    handle_ = std::make_shared<std::recursive_timed_mutex>();
  }
  
  void create(const ustring& name, bool& create_new) override {
    throw invalid_operation_exception {csf_};
  }

  void destroy() override {
    handle_.reset();
  }

  bool signal() override {
    if (!handle_) throw object_closed_exception {csf_};
    auto result = false;
    handle_->unlock();
    std::swap(locked_, result);
    return result;
  }

  bool wait(int32_t milliseconds_timeout) override {
    if (!handle_) throw object_closed_exception {csf_};
    if (milliseconds_timeout < -1) throw argument_out_of_range_exception {csf_};
    
    if (milliseconds_timeout != timeout::infinite) return (locked_ = handle_->try_lock_for(std::chrono::milliseconds {milliseconds_timeout}));
    handle_->lock();
    locked_ = true;
    return locked_;
  }
  
private:
  std::shared_ptr<std::recursive_timed_mutex> handle_;
  bool locked_ = false;
};

class mutex::unnamed_mutex : public mutex_base {
public:
  unnamed_mutex() = default;
  unnamed_mutex(unnamed_mutex&&) = default;
  unnamed_mutex(const unnamed_mutex&) = default;
  unnamed_mutex& operator=(const unnamed_mutex&) = default;
  
  intptr_t handle() const noexcept override {
    return handle_;
  }
  
  void handle(intptr_t value) override {
    handle_ = value;
  }
  
  void create() override {
  }
  
  void create(const ustring& name, bool& create_new) override {
  }

  void destroy() override {
  }
  
 bool signal() override {
    return false;
  }
  
  bool wait(int32_t milliseconds_timeout) override {
    return false;
  }

private:
  intptr_t handle_ = invalid_handle;
};

mutex::mutex() : mutex_(std::make_shared<mutex::named_mutex>()) {
}

intptr_t mutex::handle() const noexcept {
  return mutex_->handle();
}

void mutex::handle(intptr_t value) {
  mutex_->handle(value);
}

void mutex::close() {
  return mutex_->destroy();
}

mutex mutex::open_existing(const ustring& name) {
  if (ustring::is_empty(name)) throw argument_exception {csf_};
  auto result = mutex {};
  bool create_new = false;
  result.mutex_->create(name, create_new);
  if (handle() == invalid_handle) throw io::io_exception {csf_};
  return result;
}

bool mutex::signal() {
  return mutex_->signal();
}

bool mutex::wait(int32_t milliseconds_timeout) {
  return mutex_->wait(milliseconds_timeout);
}
