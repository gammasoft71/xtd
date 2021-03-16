#pragma once

#include "delegate.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a delegate that has variable parameters and does not return a value.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename... arguments_t>
  using action = delegate <void(arguments_t...)>;
}
