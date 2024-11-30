/// @file
/// @brief Contains xtd::collections::ienumerator alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "generic/enumerator.hpp"
#include "ienumerator.hpp"
#include "../as.hpp"
#include "../any_object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Supports a simple iteration over a non-generic collection.
    /// ```cpp
    /// using enumerator = xtd::collections::generic::enumerator<xtd::any_object>
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/collections/ienumerator>
    /// ```
    /// @par Namespace
    /// xtd::collections
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core collections
    /// @remarks The xtd::collections::enumerator class is used to encapsulate an xtd::collections::ienumerator.
    using enumerator = generic::enumerator<xtd::any_object>;
  }
}
