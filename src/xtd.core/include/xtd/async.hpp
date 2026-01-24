/// @file
/// @brief Contains xtd::async struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
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
      async get_return_object() {return {};}
      std::suspend_never initial_suspend() {return {};}
      std::suspend_never final_suspend() noexcept {return {};}
      void return_void() {}
      void unhandled_exception() {}
    };
  };
}
