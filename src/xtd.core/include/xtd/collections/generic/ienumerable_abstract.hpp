/// @file
/// @brief Contains xtd::collections::generic::ienumerable_abstract class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once

#if !defined(__XTD_IENUMERABLE_INTERNAL__)
#error "Do not include this file: Internal use only. Include <xtd/collections/generic/ienumerable> or <xtd/xtd/collections/generic/ienumerable.hpp> instead."
#endif

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @cond
      template <class type_t>
      class ienumerable;
      /// @endcond
      
      /// @brief Abstract object that represent ienumerable.
      /// @par Definition
      /// ```cpp
      /// class ienumerable_abstract abstract_;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/ienumerable_abstract>
      /// ```
      /// @par Namespace
      /// xtd
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      class ienumerable_abstract {
      private:
        template<class type_t>
        friend class ienumerable;
        
        ienumerable_abstract() = default;
      };
    }
  }
}
