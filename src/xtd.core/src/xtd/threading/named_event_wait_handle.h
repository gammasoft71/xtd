#pragma once
#include "event_wait_handle_base.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/named_event_wait_handle>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include "../../../include/xtd/invalid_operation_exception"
#include <atomic>

class xtd::threading::event_wait_handle::named_event_wait_handle : public event_wait_handle_base {
public:
  ~named_event_wait_handle() {destroy();}

  intptr handle() const noexcept override {
    return handle_;
  }
  
  void handle(intptr value) override {
    handle_ = value;
  }
  
  bool create(bool initial_state, bool manual_reset) override {
    throw invalid_operation_exception {csf_};
  }
  
  bool create(bool initial_state, bool manual_reset, const ustring& name) override {
    name_ = name;
    is_set_ = initial_state;
    handle_ = native::named_event_wait_handle::create(initial_state, manual_reset, name);
    manual_reset_ = manual_reset;
    
    return handle_ != invalid_handle;
  }
  
  void destroy() override {
    if (handle_ == invalid_handle) return;
    native::named_event_wait_handle::destroy(handle_, name_);
    handle_ = invalid_handle;
  }
  
  bool open(const ustring& name) override {
    name_ = name;
    handle_ = native::named_event_wait_handle::open(name);
    return handle_ != invalid_handle;
  }

  bool set(bool& io_error) override {
    io_error = false;
    if (is_set_) return true;
    return native::named_event_wait_handle::set(handle_, io_error);
  }

  bool reset(bool& io_error) override {
    io_error = false;
    auto result = native::named_event_wait_handle::reset(handle_, io_error);
    if (io_error == false) is_set_ = true;

    return result;
  }

  uint32 wait(int32 milliseconds_timeout) override {
    auto result = native::named_event_wait_handle::wait(handle_, milliseconds_timeout, manual_reset_);
    if (!manual_reset_ && result == 0) is_set_ = false;
    return result;
  }
  
private:
  intptr handle_ = invalid_handle;
  bool manual_reset_ = false;
  std::atomic<bool> is_set_ = false;
  ustring name_;
};
