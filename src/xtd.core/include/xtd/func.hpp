/// @file
/// @brief Contains xtd::func delegate.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "delegate.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a delegate that has variables parameters and returns a value of the type specified by the result_t type.
  /// ```cpp
  /// using event_handler = xtd::delegate<void(xtd::object& sender, const xtd::event_args& e)>;
  /// ```
  /// @tparam result_t The type of the return value of the method that this delegate encapsulates.
  /// @tparam ...arguments_t The type of parameter list of the method that this delegate encapsulates.
  /// @param arguments The parameter list of the method that this delegate encapsulates.
  /// @return The return value of the method that this delegate encapsulates.
  /// @par Header
  /// ```cpp
  /// #include <xtd/func>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system delegates
  template<class result_t, class ...arguments_t>
  using func = xtd::delegate<result_t(arguments_t... arguments)>;
}
