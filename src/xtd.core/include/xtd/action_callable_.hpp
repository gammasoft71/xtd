/// @file
/// @brief Contains xtd::action_callable concept documentation.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#error "Do not include this file: Internal use only. Include <xtd/callable> or <xtd/callable.hpp> instead."


/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the action callable (actiontion, method, xtd::delegate, xtd::event, std::actiontional) concept.
  /// @par Definition
  /// ```cpp
  /// template<class actiontion_t, class... args_t>
  /// concept concept action_callable = xtd::invocable<actiontion_t, void, args_t...>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/action_callable>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core concepts
  template<class function_t, class result_t = void, class... args_t>
  struct action_callable;
}
