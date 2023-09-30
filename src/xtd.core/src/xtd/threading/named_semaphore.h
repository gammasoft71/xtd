#pragma once
#include "semaphore_base.h"
#include "../../../include/xtd/invalid_operation_exception.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/named_semaphore>
#undef __XTD_CORE_NATIVE_LIBRARY__

class xtd::threading::semaphore::named_semaphore : public semaphore_base {
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
