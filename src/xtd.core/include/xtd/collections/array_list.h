/// @file
/// @brief Contains xtd::collections::array_list typedef.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "generic/list.h"
#include "../any.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Represents a collection of std::any.
    /// ```cpp
    /// using array_list = xtd::collections::generic::list<std::any>
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/collections/array_list>
    /// ```
    /// @par Namespace
    /// xtd::collections
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core collections
    /// @par Examples
    /// The following example shows hows to use xtd::collections::array_list.
    /// @include array_list.cpp
    using array_list = generic::list<std::any>;
  }
}
