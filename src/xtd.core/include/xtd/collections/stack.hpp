/// @file
/// @brief Contains xtd::collections::stack alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "generic/stack.hpp"
#include "ilist.hpp"
#include "../as.hpp"
#include "../any_object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Represents a collection of std::any.
    /// ```cpp
    /// using stack = xtd::collections::generic::stack<xtd::any_object>
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/collections/stack>
    /// ```
    /// @par Namespace
    /// xtd::collections
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core collections
    /// @par Examples
    /// The following example shows hows to use xtd::collections::stack.
    /// @include stack.cpp
    /// @remarks TTo add a class, structure or any other type unknown to xtd, you need to implement the xtd::iequatable and xtd::icompoabale interfaces or overrride the == and < operetors.
    using stack = generic::stack<xtd::any_object>;
  }
}
