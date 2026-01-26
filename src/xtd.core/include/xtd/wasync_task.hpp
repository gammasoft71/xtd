/// @file
/// @brief Contains xtd::wasync_task struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "async_task.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the wasync_task struct.
  /// @par Header
  /// ```cpp
  /// #include <xtd/wasync_task>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  struct wasync_task {
    struct promise_type {
      xtd::threading::manual_reset_event completed;
      xtd::runtime::exception_services::exception_dispatch_info exception;
      
      wasync_task get_return_object() {
        return wasync_task{std::coroutine_handle<promise_type>::from_promise(*this)};
      }
      
      std::suspend_never initial_suspend() { return {}; }
      
      auto final_suspend() noexcept {
        struct final_awaiter {
          bool await_ready() noexcept { return false; }
          void await_suspend(std::coroutine_handle<promise_type> h) noexcept {h.promise().completed.set();}
          void await_resume() noexcept {}
        };
        return final_awaiter{};
      }
      
      void return_void() {}
      void unhandled_exception() {
        exception = exception.capture();
      }
    };
    
    std::coroutine_handle<promise_type> handle;
    
    ~wasync_task() {
      wait();
      if (handle) handle.destroy();
    }
    
    auto wait() const -> void {wait(xtd::threading::timeout::infinite);}
    auto wait(xtd::int32 milliseconds_timeout) const -> bool {
      auto result = handle.promise().completed.wait_one(milliseconds_timeout);
      if (handle.promise().exception) handle.promise().exception.rethrow();
      return result;
    }
    auto wait(xtd::time_span timeout) const -> bool {return wait(xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()));}
  };
}

#include "wasync.hpp"
