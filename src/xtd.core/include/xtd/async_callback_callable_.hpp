/// @file
/// @brief Contains xtd::async_callback_callable concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/callable> or <xtd/callable.hpp> instead."


/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the assync callable callable (function, method, xtd::delegate, xtd::event, std::functional) concept.
  /// @par Definition
  /// ```cpp
  /// @brief Represents the async callback callable (function, method, xtd::delegate, xtd::event, std::functional) concept.
  /// concept async_callback_callable = xtd::invocable<function_t, void, xtd::async_result>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/async_callback_callable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  template<typename function_t>
  struct async_callback_callable;
}
