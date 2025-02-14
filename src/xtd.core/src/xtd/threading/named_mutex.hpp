#pragma once
#include "mutex_base.hpp"
#include "../../../include/xtd/invalid_operation_exception.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/named_mutex>
#undef __XTD_CORE_NATIVE_LIBRARY__

class xtd::threading::mutex::named_mutex : public mutex::mutex_base {
public:
  ~named_mutex() {destroy();}

  intptr handle() const noexcept override {
    return handle_;
  }
  
  void handle(intptr value) override {
    handle_ = value;
  }
  
  bool create(bool initially_owned) override {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
  }
  
  bool create(bool initially_owned, const string& name) override {
    name_ = name;
    handle_ = native::named_mutex::create(initially_owned, name);
    return handle_ != invalid_handle;
  }
  
  void destroy() override {
    if (handle_ == invalid_handle) return;
    native::named_mutex::destroy(handle_, name_);
    handle_ = invalid_handle;
  }
  
  bool open(const string& name) override {
    name_ = name;
    handle_ = native::named_mutex::open(name);
    return handle_ != invalid_handle;
  }
  
  bool signal(bool& io_error) override {
    io_error = false;
    return native::named_mutex::signal(handle_, io_error);
  }
  
  uint32 wait(int32 milliseconds_timeout) override {
    return native::named_mutex::wait(handle_, milliseconds_timeout);
  }
  
private:
  intptr handle_ = invalid_handle;
  string name_;
};
