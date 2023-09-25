#pragma once
#include "event_wait_handle_base.h"
#include <condition_variable>
#include "../../../include/xtd/semaphore"
#include "../../../include/xtd/invalid_operation_exception"
#include "../../../include/xtd/threading/interlocked"

class xtd::threading::event_wait_handle::unnamed_event_wait_handle : public event_wait_handle_base {
public:
  ~unnamed_event_wait_handle() {destroy();}

  intptr handle() const noexcept override {
    return handle_ ? reinterpret_cast<intptr>(handle_.get()) : invalid_handle;
  }
  
  void handle(intptr value) override {
    throw invalid_operation_exception {csf_};
  }

  bool create(bool initial_state, bool manual_reset) override {
    handle_ = std::make_shared<data>();
    handle_->manual_reset = manual_reset;
    if (initial_state) handle_->semaphore.release();
    return true;
  }
  
  bool create(bool initial_state, bool manual_reset, const ustring& name) override {
    throw invalid_operation_exception {csf_};
  }

  void destroy() override {
    if (!handle_) return;
    handle_.reset();
  }
  
  bool open(const ustring& name) override {
    throw invalid_operation_exception {csf_};
  }

  bool set(bool& io_error) override {
    handle_->semaphore.release();
    return true;
  }
  
  bool reset(bool& io_error) override {
    while (handle_->semaphore.try_acquire());
    return true;
  }
  
  uint32 wait(int32 milliseconds_timeout) override {
    if (milliseconds_timeout == timeout::infinite) handle_->semaphore.acquire();
    else if (handle_->semaphore.try_acquire_for(std::chrono::milliseconds {milliseconds_timeout}) == false) return 0x00000102;

    if (handle_->manual_reset) {
      auto io_error = false;
      set(io_error);
    }
    
    return 0x00000000;
  }
  
private:
  struct data {
    bool manual_reset = false;
    std::binary_semaphore semaphore {0};
  };
  std::shared_ptr<data> handle_;
};
