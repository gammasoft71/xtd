/// @file
/// @brief Contains xtd::collections::idictionary alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "generic/idictionary.hpp"
#include "enumerator.hpp"
#include "../as.hpp"
#include "../any_object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief interface IComparer exposes a method that compares two objects.
    /// ```cpp
    /// using idictionary = xtd::collections::generic::idictionary<xtd::any_object, xtd::any_object>
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/collections/idictionary>
    /// ```
    /// @par Namespace
    /// xtd::collections
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core interfaces collections
    using idictionary = generic::idictionary<xtd::any_object, xtd::any_object>;
  }
}
