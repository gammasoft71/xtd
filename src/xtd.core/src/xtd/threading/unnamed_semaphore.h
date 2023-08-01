#pragma once
#include "semaphore_base.h"
#include <condition_variable>
#include <mutex>
#include "../../../include/xtd/invalid_operation_exception.h"

class xtd::threading::semaphore::unnamed_semaphore : public semaphore_base {
public:
  ~unnamed_semaphore() {destroy();}

  intptr handle() const noexcept override {
    return handle_ ? reinterpret_cast<intptr>(handle_.get()) : invalid_handle;
  }
  
  void handle(intptr value) override {
    throw invalid_operation_exception {csf_};
  }

  bool create(int32 initial_count, int32 maximum_count) override {
    handle_ = std::make_shared<data>();
    handle_->maximum_count = maximum_count;
    uint32 error = 0;
    for (auto index = 0; !error && index < initial_count; ++index)
      error = wait(-1);
    if (error) return false;
    return true;
  }
  
  bool create(int32 initial_count, int32 maximum_count, const ustring& name) override {
    throw invalid_operation_exception {csf_};
  }

  void destroy() override {
    if (!handle_) return;
    handle_.reset();
  }
  
  bool open(const ustring& name) override {
    throw invalid_operation_exception {csf_};
  }

  bool signal(bool& io_error, int32 release_count, int32& previous_count) override {
    std::unique_lock<std::mutex> lock(handle_->mutex);
    previous_count = handle_->count;
    for (int count = 0; count < release_count; ++count) {
      if (handle_->count + 1 >= handle_->maximum_count) {
        io_error = true;
        return false;
      }
      handle_->count++;
      handle_->condition.notify_one();
    }
    return true;
  }

  uint32 wait(int32 milliseconds_timeout) override {
    std::unique_lock<std::mutex> lock(handle_->mutex);
    if (handle_->count == 0) return 0xFFFFFFFF;

    if (milliseconds_timeout == -1) {
      handle_->condition.wait(lock);
      handle_->count--;
      return 0x00000000;
    }
    if (handle_->condition.wait_for(lock, std::chrono::milliseconds {milliseconds_timeout}) == std::cv_status::timeout) return 0x00000102;
    handle_->count--;
    return 0x00000000;
  }
  
private:
  struct data {
    std::condition_variable condition;
    int count = 0;
    int maximum_count = std::numeric_limits<int>::max();
    std::mutex mutex;
  };
  std::shared_ptr<data> handle_;
};
