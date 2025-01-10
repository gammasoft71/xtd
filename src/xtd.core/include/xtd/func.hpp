/// @file
/// @brief Contains xtd::func delegate.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "delegate.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a delegate that has variables parameters and returns a value of the type specified by the result_t type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class result_t, class ...arguments_t>
  using func = delegate<result_t(arguments_t...)>;
}
