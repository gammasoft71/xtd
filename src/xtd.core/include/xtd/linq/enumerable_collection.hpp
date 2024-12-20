/// @file
/// @brief Contains xtd::linq::enumerable_collection <type_t> alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../collections/generic/list.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides classes and interfaces that support queries that use Language-Integrated Query (LINQ).
  namespace linq {
    /// @brief Represent an enumerable collection.
    /// @par Definition
    /// ```cpp
    /// template<typename type_t>
    /// using enumerable_collection = xtd::collections::generic::list<type_t>;
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/linq/enumerable_collection
    /// ```
    /// @par Namespace
    /// xtd::linq
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core linq
    template<typename type_t>
    using enumerable_collection = xtd::collections::generic::list<type_t>;
  }
}
