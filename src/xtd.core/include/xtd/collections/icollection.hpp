/// @file
/// @brief Contains xtd::collections::ienumerator alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "generic/icollection.hpp"
#include "ienumerable.hpp"
#include "../as.hpp"
#include "../any_object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Defines size, enumerators, and synchronization methods for all nongeneric collections.
    /// ```cpp
    /// using icollection = xtd::collections::generic::icollection<xtd::any_object>
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/collections/icollection>
    /// ```
    /// @par Namespace
    /// xtd::collections
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core interfaces collections
    /// @remarks The xtd::collections::icollection interface is the base interface for classes in the xtd::collections namespace. Its generic equivalent is the xtd::collections::genric::icollection <type_t> interface.
    /// @remarks The xtd::collections::icollection interface extends xtd::collections::ienumerable; xtd::collections::idictionary and xtd::collections::ilist are more specialized interfaces that extend xtd::collections::icollection. An xtd::collections::idictionary implementation is a collection of key/value pairs, like the xtd::collections::hashtable class. An xtd::collections::ilist implementation is a collection of values and its members can be accessed by index, like the xtd::collections::array_list class.
    /// @remarks Some collections that limit access to their elements, such as the xtd::collections::queue class and the xtd::collections::stack class, directly implement the xtd::collections::icollection interface.
    /// @remarks If neither the xtd::collections::idictionary interface nor the xtd::collections::ilist interface meet the requirements of the required collection, derive the new collection class from the xtd::collections::icollection interface instead for more flexibility.
    /// @remarks For the generic version of this interface, see xtd::collections::generic::icollection <type_t>.
    using icollection = generic::icollection<xtd::any_object>;
  }
}
