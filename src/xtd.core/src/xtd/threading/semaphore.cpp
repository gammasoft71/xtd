#include "../../../include/xtd/threading/semaphore.h"
#include "../../../include/xtd/argument_out_of_range_exception.h"
#include "../../../include/xtd/object_closed_exception.h"
#include "../../../include/xtd/invalid_operation_exception.h"
#include "../../../include/xtd/io//io_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/named_semaphore.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <mutex>

using namespace xtd;
using namespace xtd::threading;

class semaphore::semaphore_base {
public:
  virtual ~semaphore_base() = default;
  
  virtual intptr_t handle() const noexcept = 0;
  virtual void handle(intptr_t value) = 0;
  virtual bool create() = 0;
  virtual bool create(const ustring& name, bool& create_new) = 0;
  virtual void destroy() = 0;
  virtual bool signal(bool& io_error) = 0;
  virtual bool wait(int32_t milliseconds_timeout, bool& io_error) = 0;
};

class semaphore::named_semaphore : public semaphore_base {
public:
  ~named_semaphore() {destroy();}

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
    handle_ = native::named_semaphore::create(name, create_new);
    return handle_ != invalid_handle;
  }
  
  void destroy() override {
    if (handle_ == invalid_handle) return;
    native::named_semaphore::destroy(handle_, name_);
    handle_ = invalid_handle;
  }
  
  bool signal(bool& io_error) override {
    io_error = false;
    return native::named_semaphore::signal(handle_, io_error);
  }
  
  bool wait(int32_t milliseconds_timeout, bool& io_error) override {
    io_error = false;
    return native::named_semaphore::wait(handle_, milliseconds_timeout, io_error);
  }
  
private:
  intptr_t handle_ = invalid_handle;
  ustring name_;
};

class semaphore::unnamed_semaphore : public semaphore_base {
public:
  ~unnamed_semaphore() {destroy();}

  intptr_t handle() const noexcept override {
    return handle_ ? reinterpret_cast<intptr_t>(handle_.get()) : invalid_handle;
  }
  
  void handle(intptr_t value) override {
    handle_.reset(reinterpret_cast<std::timed_mutex*>(value));
  }

  bool create() override {
    handle_ = std::make_shared<std::timed_mutex>();
    return true;
  }
  
  bool create(const ustring& name, bool& create_new) override {
    throw invalid_operation_exception {csf_};
  }

  void destroy() override {
    if (!handle_) return;
    handle_.reset();
  }

  bool signal(bool& io_error) override {
    io_error = false;
    handle_->unlock();
    return true;
  }

  bool wait(int32_t milliseconds_timeout, bool& io_error) override {
    io_error = false;
    if (milliseconds_timeout != timeout::infinite) return handle_->try_lock_for(std::chrono::milliseconds {milliseconds_timeout});
    handle_->lock();
    return true;
  }
  
private:
  std::shared_ptr<std::timed_mutex> handle_;
};

semaphore::semaphore() : semaphore(false) {
}

semaphore::semaphore(bool initially_owned) {
  bool created_new = false;
  create(initially_owned, created_new);
}

semaphore::semaphore(bool initially_owned, const ustring& name) : name_(name) {
  bool created_new = false;
  create(initially_owned, created_new);
}

semaphore::semaphore(bool initially_owned, const ustring& name, bool created_new) : name_(name) {
  create(initially_owned, created_new);
}

semaphore::~semaphore() {
  close();
}

intptr_t semaphore::handle() const noexcept {
  return semaphore_ ? semaphore_->handle() : invalid_handle;
}

void semaphore::handle(intptr_t value) {
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

void semaphore::release() {
  if (!signal()) throw io::io_exception {csf_};
}

bool semaphore::try_open_existing(const ustring& name, semaphore& result) noexcept {
  if (ustring::is_empty(name)) return false;
  auto new_semaphore = semaphore {};
  new_semaphore.name_ = name;
  new_semaphore.semaphore_ = std::make_shared<semaphore::named_semaphore>();
  bool created_new = true;
  if (new_semaphore.semaphore_->create(new_semaphore.name_, created_new)) return false;
  if (created_new) return false;
  result = new_semaphore;
  return true;
}

bool semaphore::signal() {
  if (!semaphore_) throw object_closed_exception {csf_};
  bool io_error = false;
  auto result = semaphore_->signal(io_error);
  if (io_error) throw io::io_exception {csf_};
  return result;
}

bool semaphore::wait(int32_t milliseconds_timeout) {
  if (!semaphore_) throw object_closed_exception {csf_};
  if (milliseconds_timeout < -1) throw argument_out_of_range_exception {csf_};
  bool io_error = false;
  auto result = semaphore_->wait(milliseconds_timeout, io_error);
  if (io_error) throw io::io_exception {csf_};
  return result;
}

void semaphore::create(bool initially_owned, bool& created_new) {
  created_new = true;
  if (name_.empty()) {
    semaphore_ = std::make_shared<semaphore::unnamed_semaphore>();
    if (!semaphore_->create()) throw io::io_exception(csf_);
  } else {
    semaphore_ = std::make_shared<semaphore::named_semaphore>();
    if (!semaphore_->create(name_, created_new)) throw io::io_exception(csf_);
  }
  if (initially_owned) wait_one();
}
