#include "../../../include/xtd/threading/mutex.h"
#include "../../../include/xtd/argument_out_of_range_exception.h"
#include "../../../include/xtd/object_closed_exception.h"
#include "../../../include/xtd/invalid_operation_exception.h"
#include "../../../include/xtd/io//io_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/named_mutex.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <mutex>

using namespace xtd;
using namespace xtd::threading;

class mutex::mutex_base {
public:
  virtual ~mutex_base() = default;
  
  virtual intptr handle() const noexcept = 0;
  virtual void handle(intptr value) = 0;
  virtual bool create(bool initially_owned) = 0;
  virtual bool create(bool initially_owned, const ustring& name) = 0;
  virtual void destroy() = 0;
  virtual bool open(const ustring& name) = 0;
  virtual bool signal(bool& io_error) = 0;
  virtual bool wait(int32 milliseconds_timeout, bool& io_error) = 0;
};

class mutex::named_mutex : public mutex_base {
public:
  ~named_mutex() {destroy();}

  intptr handle() const noexcept override {
    return handle_;
  }
  
  void handle(intptr value) override {
    handle_ = value;
  }
  
  bool create(bool initially_owned) override {
    throw invalid_operation_exception {csf_};
  }
  
  bool create(bool initially_owned, const ustring& name) override {
    name_ = name;
    handle_ = native::named_mutex::create(initially_owned, name);
    return handle_ != invalid_handle;
  }
  
  void destroy() override {
    if (handle_ == invalid_handle) return;
    native::named_mutex::destroy(handle_, name_);
    handle_ = invalid_handle;
  }
  
  bool open(const ustring& name) override {
    name_ = name;
    handle_ = native::named_mutex::open(name);
    return handle_ != invalid_handle;
  }
  
  bool signal(bool& io_error) override {
    io_error = false;
    return native::named_mutex::signal(handle_, io_error);
  }
  
  bool wait(int32 milliseconds_timeout, bool& io_error) override {
    io_error = false;
    return native::named_mutex::wait(handle_, milliseconds_timeout, io_error);
  }
  
private:
  intptr handle_ = invalid_handle;
  ustring name_;
};

class mutex::unnamed_mutex : public mutex_base {
public:
  ~unnamed_mutex() {destroy();}

  intptr handle() const noexcept override {
    return handle_ ? reinterpret_cast<intptr>(handle_.get()) : invalid_handle;
  }
  
  void handle(intptr value) override {
    handle_.reset(reinterpret_cast<std::recursive_timed_mutex*>(value));
  }

  bool create(bool initially_owned) override {
    handle_ = std::make_shared<std::recursive_timed_mutex>();
    bool io_error = false;
    if (initially_owned) return wait(-1, io_error);
    return true;
  }
  
  bool create(bool initially_owned, const ustring& name) override {
    throw invalid_operation_exception {csf_};
  }

  void destroy() override {
    if (!handle_) return;
    handle_.reset();
  }
  
  bool open(const ustring& name) override {
    throw invalid_operation_exception {csf_};
  }

  bool signal(bool& io_error) override {
    io_error = false;
    handle_->unlock();
    return true;
  }

  bool wait(int32 milliseconds_timeout, bool& io_error) override {
    io_error = false;
    if (milliseconds_timeout != timeout::infinite) return handle_->try_lock_for(std::chrono::milliseconds {milliseconds_timeout});
    handle_->lock();
    return true;
  }
  
private:
  std::shared_ptr<std::recursive_timed_mutex> handle_;
};

mutex::mutex() : mutex(false) {
}

mutex::mutex(bool initially_owned) : mutex(initially_owned, "") {
}

mutex::mutex(bool initially_owned, const ustring& name) : name_(name) {
  bool created_new = false;
  create(initially_owned, created_new);
}

mutex::mutex(bool initially_owned, const ustring& name, bool created_new) : name_(name) {
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

void mutex::close() {
  if (mutex_.use_count() == 1) {
    mutex_->destroy();
    mutex_.reset();
  }
}

mutex mutex::open_existing(const ustring& name) {
  if (name.empty()) throw argument_exception {csf_};
  auto result = mutex{};
  if (!try_open_existing(name, result)) throw argument_exception {csf_};
  return result;
}

void mutex::release_mutex() {
  if (!signal()) throw io::io_exception {csf_};
}

bool mutex::try_open_existing(const ustring& name, mutex& result) noexcept {
  if (ustring::is_empty(name)) return false;
  auto new_mutex = mutex {};
  new_mutex.name_ = name;
  new_mutex.mutex_ = std::make_shared<mutex::named_mutex>();
  if (new_mutex.mutex_->open(new_mutex.name_)) return false;
  result = new_mutex;
  return true;
}

bool mutex::signal() {
  if (!mutex_) throw object_closed_exception {csf_};
  bool io_error = false;
  auto result = mutex_->signal(io_error);
  if (io_error) throw io::io_exception {csf_};
  return result;
}

bool mutex::wait(int32 milliseconds_timeout) {
  if (!mutex_) throw object_closed_exception {csf_};
  if (milliseconds_timeout < -1) throw argument_out_of_range_exception {csf_};
  bool io_error = false;
  auto result = mutex_->wait(milliseconds_timeout, io_error);
  if (io_error) throw io::io_exception {csf_};
  return result;
}

void mutex::create(bool initially_owned, bool& created_new) {
  created_new = true;
  if (name_.empty()) {
    mutex_ = std::make_shared<mutex::unnamed_mutex>();
    if (!mutex_->create(initially_owned)) throw io::io_exception(csf_);
  } else {
    mutex_ = std::make_shared<mutex::named_mutex>();
    created_new = mutex_->create(initially_owned, name_);
    if (!created_new && !mutex_->open(name_)) throw io::io_exception(csf_);
  }
}
