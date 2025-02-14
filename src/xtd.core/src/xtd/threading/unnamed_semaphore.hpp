#pragma once

#include "semaphore_base.hpp"
#include "../../../include/xtd/int32_object.hpp"
#include "../../../include/xtd/semaphore.hpp"
#include "../../../include/xtd/invalid_operation_exception.hpp"
#include "../../../include/xtd/threading/interlocked.hpp"
#include <atomic>
#include <condition_variable>

class xtd::threading::semaphore::unnamed_semaphore : public semaphore_base {
public:
  ~unnamed_semaphore() {destroy();}

  intptr handle() const noexcept override {
    return handle_ ? reinterpret_cast<intptr>(handle_.get()) : invalid_handle;
  }
  
  void handle(intptr value) override {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
  }

  bool create(int32 initial_count, int32 maximum_count) override {
    handle_ = xtd::new_sptr<data>();
    handle_->maximum_count = maximum_count;
    handle_->semaphore.release(static_cast<std::ptrdiff_t>(initial_count));
    handle_->count += initial_count;
    return true;
  }
  
  bool create(int32 initial_count, int32 maximum_count, const string& name) override {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
  }

  void destroy() override {
    if (!handle_) return;
    handle_.reset();
  }
  
  bool open(const string& name) override {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
  }

  bool signal(bool& io_error, int32 release_count, int32& previous_count) override {
    if (handle_->count + release_count > handle_->maximum_count) return false;
    previous_count = handle_->count;
    handle_->semaphore.release(static_cast<std::ptrdiff_t>(release_count));
    handle_->count += release_count;
    return true;
  }

  uint32 wait(int32 milliseconds_timeout) override {
    if (milliseconds_timeout == timeout::infinite) handle_->semaphore.acquire();
    else if (handle_->semaphore.try_acquire_for(std::chrono::milliseconds {milliseconds_timeout}) == false) return 0x00000102;

    --handle_->count;
    return 0x00000000;
  }
  
private:
  struct data {
    std::atomic<int32> count = 0;
    std::atomic<int32> maximum_count = std::numeric_limits<int>::max();
    std::counting_semaphore<int32_object::max_value> semaphore {0};
  };
  xtd::sptr<data> handle_;
};
