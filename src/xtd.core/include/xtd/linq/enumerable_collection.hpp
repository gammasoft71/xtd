/// @file
/// @brief Contains xtd::linq::enumerable_collection <type_t> struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../collections/generic/helpers/allocator.hpp"
#include "../collections/generic/extensions/enumerable.hpp"
#include "../collections/generic/enumerator.hpp"
#include "../new_ptr.hpp"
#include <limits>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace collections::generic {
    template<typename type_t>
    class ienumerable;
  }
  /// @endcond

  /// @brief Provides classes and interfaces that support queries that use Language-Integrated Query (LINQ).
  namespace linq {
    /// @cond
    class enumerable;
    /// @endcond
    
    /// @brief Represent an enumerable collection.
    /// @par Definition
    /// ```cpp
    /// template<typename type_t>
    /// struct enumerable_collection : xtd::collections::generic::ienumerable<type_t>;
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
    struct enumerable_collection : xtd::collections::generic::ienumerable<type_t> {
      xtd::collections::generic::enumerator<type_t> get_enumerator() const override {
        return xtd::collections::generic::enumerator<>::create(items);
      }

    private:
      friend class xtd::linq::enumerable;
      enumerable_collection() = default;
      std::vector<type_t> items;
    };
  }
}
