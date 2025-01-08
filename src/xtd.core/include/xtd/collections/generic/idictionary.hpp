/// @file
/// @brief Contains xtd::collections::generic::icomparer <type_t> interface.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "icollection.hpp"
#include "key_value_pair.hpp"
#include "list.hpp"

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
      class idictionary : public xtd::collections::generic::ienumerable<xtd::collections::generic::key_value_pair<key_t, value_t>> /* xtd::collections::generic::icollection<xtd::collections::generic::key_value_pair<key_t, value_t>> */ {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the dictionary key type.
        using key_type = key_t;
        /// @brief Represents the dictionary mapped type.
        using mapped_type = value_t;
        /// @brief Represents the dictionary value type.
        using value_type = xtd::collections::generic::key_value_pair<key_type, mapped_type>;
        /// @brief Represents the iterator of xtd::collections::generic::ienumerable value type.
        using iterator = typename xtd::collections::generic::icollection<value_type>::iterator;
        /// @brief Represents the const iterator of xtd::collections::generic::ienumerable value type.
        using const_iterator = typename xtd::collections::generic::icollection<value_type>::const_iterator;
        /// @brief Represents the idictionary key collection type.
        using key_collection = xtd::collections::generic::list<key_type>;
        /// @brief Represents the idictionary value collection type.
        using value_collection = xtd::collections::generic::list<mapped_type>;
        /// @}
        
        /// @name Public Properties

        /// @{
        /// @brief Gets an xtd::collections::generic::icollection <type_t> containing the keys of the xtd::collections::generic::idictionary <key_t, value_t>.
        /// @return An xtd::collections::generic::icollection <type_t> containing the keys of the object that implements xtd::collections::generic::idictionary <key_t, value_t>.
        /// @remarks The order of the keys in the returned xtd::collections::generic::icollection <type_t> is unspecified, but it is guaranteed to be the same order as the corresponding values in the xtd::collections::generic::icollection <type_t> returned by the xtd::collections::generic::idictionary::values property.
        virtual key_collection keys() const noexcept = 0;

        /// @brief Gets an xtd::collections::generic::icollection <type_t> containing the values of the xtd::collections::generic::idictionary <key_t, value_t>.
        /// @return An xtd::collections::generic::icollection <type_t> containing the values of the object that implements xtd::collections::generic::idictionary <key_t, value_t>.
        /// @remarks The order of the values in the returned xtd::collections::generic::icollection <type_t> is unspecified, but it is guaranteed to be the same order as the corresponding values in the xtd::collections::generic::icollection <type_t> returned by the xtd::collections::generic::idictionary::keys property.
        virtual value_collection values() const noexcept = 0;
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
