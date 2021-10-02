/// @file
/// @brief Contains xtd::predicate delegate.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "delegate.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a delegate that defines a set of criteria and determines whether the specified object meets those criteria.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename type_t>
  using predicate = delegate<bool(type_t)>;
}
