/// @file
/// @brief Contains xtd::collections::ienumerable alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "generic/ienumerable.hpp"
#include "enumerator.hpp"
#include "../as.hpp"
#include "../any_object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Exposes an enumerator, which supports a simple iteration over a non-generic collection.
    /// ```cpp
    /// using ienumerable = xtd::collections::generic::ienumerable<xtd::any_object>
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/collections/ienumerable>
    /// ```
    /// @par Namespace
    /// xtd::collections
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core collections interfaces
    /// @par Examples
    /// The following code example demonstrates the best practice for iterating a custom collection by implementing the xtd::collection::ienumerable and xtd::collection::ienumerator interfaces. In this example, members of these interfaces are not explicitly called, but they are implemented to support the use of `for each` to iterate through the collection. This example is a complete Console app.
    /// @include ienumerable.cpp
    /// @remarks xtd::collections::ienumerable is the base interface for all non-generic collections that can be enumerated. For the generic version of this interface see xtd::collections::generic::ieumerable <type_t>. xtd::collections::ienumerable contains a single method, xtd::collections::ienumerable::get_enumerator, which returns an xtd::collections::ienumerator. xtd::collections::ienumerator provides the ability to iterate through the collection by exposing a xtd::collections::ienumerator::current property and xtd::collections::ienumerator::move_next and xtd::collections::ienumeraror::reset methods.
    /// @remarks It is a best practice to implement xtd::collections::ienumerable and xtd::collections::ienumerator on your collection classes to enable the for each syntax, however implementing xtd::collections::ienumerable is not required. If your collection does not implement xtd::collections::ienumerable, you must still follow the iterator pattern to support this syntax by providing a xtd::collections::ienumerable::get_enumerator method that returns an interface, class or struct. You must provide a class that contains a xtd::collections::ienumerator::current property, and xtd::collections::ienumerator::move_next and Reset methods as described by xtd::collections::ienumerator, but the class does not have to implement xtd::collections::ienumerator.
    using ienumerable = generic::ienumerable<xtd::any_object>;
  }
}
