#pragma once
#include "mutex_base.h"
#include "../../../include/xtd/invalid_operation_exception.h"
#include <mutex>

class xtd::threading::mutex::unnamed_mutex : public mutex_base {
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
    if (initially_owned) wait(0);
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

  uint32 wait(int32 milliseconds_timeout) override {
    if (milliseconds_timeout == timeout::infinite) handle_->lock();
    else if (handle_->try_lock_for(std::chrono::milliseconds {milliseconds_timeout}) == false) return 0x00000102;
    
    return 0x00000000;
  }
  
private:
  std::shared_ptr<std::recursive_timed_mutex> handle_;
};
