/// @file
/// @brief Contains xtd::collections::generic::ilist <type_t> interface.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "icollection.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents a collection of objects that can be individually accessed by index.
      /// @par Definition
      /// ```cpp
      /// template<typename type_t>
      /// class ilist : public xtd::collections::generic::icollection<type_t>
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/ilist
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core interfaces
      /// @remarks The xtd::collections::generic::ilist <type_t> interface is the base interface for classes in the xtd::collections::generic namespace.
      /// @remarks The xtd::collections::generic::ilist <type_t> interface extends xtd::collections::generic::ienumerable <type_t>; xtd::collections::generic::idictionary <key_t, value_t> and xtd::collections::generic::ilist <type_t> are more specialized interfaces that extend xtd::collections::generic::ilist <type_t>. A xtd::collections::generic::idictionary <key_t, value_t> implementation is a collection of key/value pairs, like the xtd::collections::generic::dictoinary <key_t, value_t> class. A xtd::collections::generic::ilist <type_t> implementation is a collection of values, and its members can be accessed by index, like the xtd::collections::generic::list <type_t> class.
      /// @remarks If neither the xtd::collections::generic::idictionary <key_t, value_t> interface nor the xtd::collections::generic::ilist <type_t> interface meet the requirements of the required collection, derive the new collection class from the xtd::collections::generic::ilist <type_t> interface instead for more flexibility.
      template<typename type_t>
      class ilist : public icollection<type_t> {
      public:
        /// @name Public Properties
        
        /// @{
        /// @}

        /// @name Public Methods
        
        /// @{
        /// @}

        /// @name Public Operators
        
        /// @{
        /// @}
      };
    }
  }
}
