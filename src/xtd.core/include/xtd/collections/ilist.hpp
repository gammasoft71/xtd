/// @file
/// @brief Contains xtd::collections::ilist alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "generic/ilist.hpp"
#include "icollection.hpp"
#include "../as.hpp"
#include "../any_object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Represents a non-generic collection of objects that can be individually accessed by index.
    /// ```cpp
    /// using ilist = xtd::collections::generic::ilist<xtd::any_object>
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/collections/ilist>
    /// ```
    /// @par Namespace
    /// xtd::collections
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core collections interfaces
    /// par Examples
    /// The following example demonstrates the implementation of the xtd::collections::ilist interface to create a simple, fixed-size list.
    /// @include ilist.cpp
    /// @remarks xtd::collections::ilist is a descendant of the xtd::collections::icollection interface and is the base interface of all non-generic lists. xtd::collections::ilist implementations fall into three categories: read-only, fixed-size, and variable-size. A read-only xtd::collections::ilist cannot be modified. A fixed-size xtd::collections::ilist does not allow the addition or removal of elements, but it allows the modification of existing elements. A variable-size xtd::collections::ilist allows the addition, removal, and modification of elements.
    /// @remarks For the generic version of this interface, see xtd::collections::generic::ilist <type_t>.
    using ilist = generic::ilist<xtd::any_object>;
  }
}
