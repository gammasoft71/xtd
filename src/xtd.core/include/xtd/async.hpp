/// @file
/// @brief Contains xtd::async struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "xtd/threading/manual_reset_event.hpp"
#include <coroutine>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the async struct.
  /// @par Header
  /// ```cpp
  /// #include <xtd/async>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  struct async {
    struct promise_type {
      xtd::threading::manual_reset_event completed;
      
      async get_return_object() { return async{this}; }
      
      std::suspend_never initial_suspend() { return {}; }
      
      auto final_suspend() noexcept {
        struct final_awaiter {
          bool await_ready() noexcept { return false; }
          void await_suspend(std::coroutine_handle<promise_type> h) noexcept {
            h.promise().completed.set();
          }
          void await_resume() noexcept {}
        };
        return final_awaiter{};
      }
      
      void return_void() {}
      void unhandled_exception() { std::terminate(); }
    };
    
    promise_type* promise;
    
    void wait() const {
      promise->completed.wait_one();
    }
  };
}
