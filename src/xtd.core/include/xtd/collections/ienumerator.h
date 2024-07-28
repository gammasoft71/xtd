/// @file
/// @brief Contains xtd::collections::ienumerator alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "generic/ienumerator.h"
#include "../as.h"
#include "../any_object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Supports a simple iteration over a non-generic collection.
    /// ```cpp
    /// using ienumerator = xtd::collections::generic::ienumerator<xtd::any_object>
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/collections/ienumerator>
    /// ```
    /// @par Namespace
    /// xtd::collections
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core interfaces
    using ienumerator = generic::ienumerator<xtd::any_object>;
  }
}
