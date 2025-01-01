/// @file
/// @brief Contains xtd::collections::array_list typedef.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "generic/list.hpp"
#include "ilist.hpp"
#include "../as.hpp"
#include "../any_object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Represents a collection of std::any.
    /// ```cpp
    /// using array_list = xtd::collections::generic::list<xtd::any_object>
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
    /// @remarks TTo add a class, structure or any other type unknown to xtd, you need to implement the xtd::iequatable and xtd::icompoabale interfaces or overrride the == and < operetors.
    using array_list = generic::list<xtd::any_object>;
  }
}
