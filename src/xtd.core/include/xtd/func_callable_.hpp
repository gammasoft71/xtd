/// @file
/// @brief Contains xtd::func_callable concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/callable> or <xtd/callable.hpp> instead."


/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the func callable (function, method, xtd::delegate, xtd::event, std::functional) concept.
  /// @par Definition
  /// ```cpp
  /// template<class function_t, class result_t = void, class... args_t>
  /// concept concept func_callable = xtd::invocable<function_t, result_t, args_t...>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/func_callable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  template<class function_t, class result_t = void, class... args_t>
  struct callable;
}
