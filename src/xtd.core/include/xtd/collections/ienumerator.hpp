/// @file
/// @brief Contains xtd::collections::ienumerator alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "generic/ienumerator.hpp"
#include "../as.hpp"
#include "../any_object.hpp"

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
    /// @ingroup xtd_core interfaces collections
    /// The following code example demonstrates the best practice for iterating a custom collection by implementing the xtd::collection::ienumerable and xtd::collection::ienumerator interfaces. In this example, members of these interfaces are not explicitly called, but they are implemented to support the use of `for each` to iterate through the collection. This example is a complete Console app.
    /// @include ienumerable.cpp
    /// @remarks xtd::collections::ienumerator is the base interface for all non-generic enumerators. Its generic equivalent is the xtd::collections::generic::iznumerator <type_t> interface.
    /// @remarks The for each statement of the C++ language hides the complexity of the enumerators. Therefore, using for each is recommended instead of directly manipulating the enumerator.
    /// @remarks Enumerators can be used to read the data in the collection, but they cannot be used to modify the underlying collection.
    /// @remarks The xtd::collections::ienumerator::reset method is provided for COM interoperability and does not need to be fully implemented; instead, the implementer can throw a xtd::not_supported_exception.
    /// @remarks Initially, the enumerator is positioned before the first element in the collection. You must call the xtd::collections::ienumerator::MMoveN_next method to advance the enumerator to the first element of the collection before reading the value of xtd::collections::ienumerator::current; otherwise, xtd::collections::ienumerator::current is undefined.
    /// @remarks xtd::collections::ienumerator::current returns the same object until either xtd::collections::ienumerator::move_next or xtd::collections::ienumerator::reset is called. xtd::collections::ienumerator::move_next sets xtd::collections::ienumerator::current to the next element.
    /// @remarks If xtd::collections::ienumerator::move_next passes the end of the collection, the enumerator is positioned after the last element in the collection and xtd::collections::ienumerator::move_next returns `false`. When the enumerator is at this position, subsequent calls to xtd::collections::ienumerator::move_next also return `false`. If the last call to xtd::collections::ienumerator::move_next returned `false`, xtd::collections::ienumerator::current is undefined.
    /// @remarks To set xtd::collections::ienumerator::current to the first element of the collection again, you can call Reset, if it's implemented, followed by xtd::collections::ienumerator::move_next. If xtd::collections::ienumerator::reset is not implemented, you must create a new enumerator instance to return to the first element of the collection.
    /// @remarks If changes are made to the collection, such as adding, modifying, or deleting elements, the behavior of the enumerator is undefined.
    /// @remarks The enumerator does not have exclusive access to the collection; therefore, enumerating through a collection is intrinsically not a thread-safe procedure. Even when a collection is synchronized, other threads can still modify the collection, which causes the enumerator to throw an exception. To guarantee thread safety during enumeration, you can either lock the collection during the entire enumeration or catch the exceptions resulting from changes made by other threads.
    using ienumerator = generic::ienumerator<xtd::any_object>;
  }
}
