/// @file
/// @brief Contains xtd::func delegate.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "delegate.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a delegate that has variables parameters and returns a value of the type specified by the result_t type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename result_t, typename... arguments_t>
  using func = delegate<result_t(arguments_t...)>;
}
