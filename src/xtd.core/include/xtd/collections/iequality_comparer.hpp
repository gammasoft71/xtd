/// @file
/// @brief Contains xtd::collections::iequality_comparer alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "generic/iequality_comparer.hpp"
#include "../as.hpp"
#include "../any_object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Defines methods to support the comparison of objects for equality.
    /// ```cpp
    /// using iequality_comparer = xtd::collections::generic::iequality_comparer<xtd::any_object>
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/collections/iequality_comparer>
    /// ```
    /// @par Namespace
    /// xtd::collections
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core interfaces collections
    /// @remarks This interface allows the implementation of customized equality comparison for collections. That is, you can create your own definition of equality, and specify that this definition be used with a collection type that accepts the xtd::collections::iequality_comparer interface. In the xtd framework, constructors of the xtd::collections::hashtable, xtd::collections::specialized::name_value_collection, and xtd::collections::specialized::ordered_dictionary collection types accept this interface.
    /// @remarks For the generic version of this interface, see xtd::collections::generic::iequality_comparer <type_t>.
    /// @remarks The xtd::collections::iequality_comparer interface supports only equality comparisons. Customization of comparisons for sorting and ordering is provided by the xtd::collections::icomparer interface.
    using iequality_comparer = generic::iequality_comparer<xtd::any_object>;
  }
}
