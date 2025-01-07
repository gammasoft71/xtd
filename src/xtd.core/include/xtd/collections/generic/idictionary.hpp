/// @file
/// @brief Contains xtd::collections::generic::icomparer <type_t> interface.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "icollection.hpp"
#include "key_value_pair.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents a generic collection of key/value pairs.
      /// @par Definition
      /// ```cpp
      /// template<typename type_t>
      /// class idictionary interface_
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/idictionary
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections interfaces
      /// @remarks The idictionary <key_t, value_t> interface is the base interface for generic collections of key/value pairs.
      /// @remarks Each element is a key/value pair stored in a key_value_pair <key_t, value_t> object.
      /// @remarks Each pair must have a unique key. Implementations can vary in whether they allow key to be empty. The value can be empty and does not have to be unique. The idictionary <key_t, value_t> interface allows the contained keys and values to be enumerated, but it does not imply any particular sort order.
      /// @remarks The foreach statement of the C# language (For Each in Visual Basic, for each in C++) returns an object of the type of the elements in the collection. Since each element of the IDictionary<TKey,TValue> is a key/value pair, the element type is not the type of the key or the type of the value. Instead, the element type is KeyValuePair<TKey,TValue>. For example:
      template<typename key_t, typename value_t>
      class idictionary interface_ {
      public:
      };
    }
  }
}
