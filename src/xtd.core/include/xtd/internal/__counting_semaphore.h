/// @file
/// @brief Contains internal char8_t type.
#pragma once
/// @cond
#if !defined(__XTD_CORE_COUNTING_SEMAPHORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <iostream>
#include <string>

/// @cond
#if defined(__cpp_lib_semaphore)
#include <semaphore>
#else
#include <cstddef>
#include <mutex>
#include <condition_variable>

namespace std {
  template<std::ptrdiff_t least_max_value = std::numeric_limits<std::ptrdiff_t>::max()>
  class counting_semaphore {
  public:
    static constexpr std::ptrdiff_t max() noexcept {return least_max_value;}
    explicit counting_semaphore(std::ptrdiff_t desired = 0) : count_(desired) {}
    counting_semaphore(const counting_semaphore&) = delete;
    
    void acquire() {
      std::unique_lock<std::mutex> lock(mutex_);
      while (count_ <= 0) {
        condition_.wait(lock);
      }
      --count_;
    }
    
    bool try_acquire() noexcept {
      std::unique_lock<std::mutex> lock(mutex_);
      if (count_ > 0) {
        --count_;
        return true;
      }
      return false;
    }
    
    bool try_acquire_for(const std::chrono::milliseconds& duration) {
      std::unique_lock<std::mutex> lock(mutex_);
      if (condition_.wait_for(lock, duration, [this]() { return count_ > 0; })) {
        --count_;
        return true;
      }
      return false;
    }
    
    template< class clock_t, class duration_t >
    bool try_acquire_until(const std::chrono::time_point<clock_t, duration_t>& timeout_time) {
      return try_acquire_until(timeout_time, [this] {return count_ > 0;});
    }
    
    template< class clock_t, class duration_t, class predicate_t >
    bool try_acquire_until(const std::chrono::time_point<clock_t, duration_t>& timeout_time, predicate_t stop_waiting) {
      std::unique_lock<std::mutex> lock(mutex_);
      if (condition_.wait_until(lock, timeout_time, stop_waiting)) {
        --count_;
        return true;
      }
      return false;
    }
    
    void release(std::ptrdiff_t update = 1) {
      std::lock_guard<std::mutex> lock(mutex_);
      for (std::ptrdiff_t index = 0; index < update; ++index) {
        ++count_;
        condition_.notify_one();
      }
    }
    
    std::ptrdiff_t available() const {
      std::lock_guard<std::mutex> lock(mutex_);
      return count_;
    }
    
  private:
    mutable std::mutex mutex_;
    std::condition_variable condition_;
    std::ptrdiff_t count_;
  };
}
#endif
/// @endcond
