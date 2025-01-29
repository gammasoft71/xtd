/// @file
/// @brief Contains xtd::collections::comparer alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "generic/comparer.hpp"
#include "../any_object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Exposes a method that compares two objects.
    /// ```cpp
    /// using comparer = xtd::collections::generic::comparer<xtd::any_object>;
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/collections/comparer>
    /// ```
    /// @par Namespace
    /// xtd::collections
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core collections
    using comparer = xtd::collections::generic::comparer<xtd::any_object>;
  }
}
