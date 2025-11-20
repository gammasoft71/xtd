/// @file
/// @brief Contains xtd::collections::generic::idictionary <key_t, value_t> interface.
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
      /// template<class key_t, class value_t>
      /// class idictionary : public xtd::collections::generic::icollection<xtd::collections::generic::key_value_pair<key_t, value_t>>;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/idictionary>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections interfaces
      /// @remarks The xtd::collections::generic::idictionary <key_t, value_t> interface is the base interface for generic collections of key/value pairs.
      /// @remarks Each element is a key/value pair stored in a xtd::collections::generic::key_value_pair <key_t, value_t> object.
      /// @remarks Each pair must have a unique key. Implementations can vary in whether they allow key to be empty. The value can be empty and does not have to be unique. The idictionary <key_t, value_t> interface allows the contained keys and values to be enumerated, but it does not imply any particular sort order.
      /// @remarks The for each statement returns an object of the type of the elements in the collection. Since each element of the xtd::collections::generic::idictionary <key_t, value_t> is a key/value pair, the element type is not the type of the key or the type of the value. Instead, the element type is xtd::collections::generic::key_value_pair <key_t, value_t>. For example:
      /// ```cpp
      /// for (const key_value_pair<int, string>& kvp : my_dictionary)
      ///   console::write_line("key = {}, value = {}", kvp.key(), kvp.value());
      /// ```
      /// @remarks Or with `auto` key type and the value type. For example:
      /// ```cpp
      /// for (const auto& [key, value] : my_dictionary)
      ///   console::write_line("key = {}, value = {}", key, value);
      /// ```
      template<class key_t, class value_t>
      class idictionary : public xtd::collections::generic::icollection<xtd::collections::generic::key_value_pair<key_t, value_t>> {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the dictionary key type.
        using key_type = key_t;
        /// @brief Represents the dictionary mapped type.
        using mapped_type = value_t;
        /// @brief Represents the xtd::collections::generic::idictionary value type.
        using value_type = typename xtd::collections::generic::icollection<xtd::collections::generic::key_value_pair<key_t, value_t>>::value_type;
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
        virtual auto keys() const noexcept -> key_collection = 0;
        
        /// @brief Gets an xtd::collections::generic::icollection <type_t> containing the values of the xtd::collections::generic::idictionary <key_t, value_t>.
        /// @return An xtd::collections::generic::icollection <type_t> containing the values of the object that implements xtd::collections::generic::idictionary <key_t, value_t>.
        /// @remarks The order of the values in the returned xtd::collections::generic::icollection <type_t> is unspecified, but it is guaranteed to be the same order as the corresponding values in the xtd::collections::generic::icollection <type_t> returned by the xtd::collections::generic::idictionary::keys property.
        virtual auto values() const noexcept -> value_collection = 0;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        using xtd::collections::generic::icollection<xtd::collections::generic::key_value_pair<key_t, value_t>>::add;
        /// @brief Adds an element with the provided key and value to the xtd::collections::generic::idictionary <key_t, value_t>.
        /// @param key The object to use as the key of the element to add.
        /// @param value The object to use as the value of the element to add.
        /// @exception xtd::argument_exception An element with the same key already exists in the xtd::collections::generic::idictionary <key_t, value_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::idictionary <key_t, value_t> is read-only.
        /// @remarks You can also use the `operator []` to add new elements by setting the value of a key that does not exist in the dictionary; for example, `my_collection["my_nonexistent_key"] = my_value`. However, if the specified key already exists in the dictionary, setting the `operator []` overwrites the old value. In contrast, the xtd::collections::generic::idictionary::add method does not modify existing elements.
        /// @remarks Implementations can vary in how they determine equality of objects; for example, the xtd::collections::generic::list <type_t> class uses xtd::collections::generic::comparer::default_comparer, whereas the xtd::collections::generic::dictionary <key_t,value_t> class allows the user to specify the xtd::collections::generic::icomparer <type_t> implementation to use for comparing keys.
        virtual auto add(const key_t& key, const value_t& value) -> void = 0;
        
        /// @brief Determines whether the xtd::collections::generic::idictionary <key_t, value_t> contains an element with the specified key.
        /// @param key The key to locate in the xtd::collections::generic::idictionary <key_t, value_t>.
        /// @return `true` if the xtd::collections::generic::idictionary <key_t, value_t> contains an element with the key; otherwise, `false`.
        /// @remarks Implementations can vary in how they determine equality of objects; for example, the xtd::collections::generic::list <type_t> class uses xtd::collections::generic::comparer <type_t>.Default, whereas the xtd::collections::generic::dictionary <key_t, value_t> class allows the user to specify the xtd::collections::generic::icomparer <type_t>x implementation to use for comparing keys.
        virtual auto contains_key(const key_t& key) const noexcept -> bool = 0;
        
        using xtd::collections::generic::icollection<xtd::collections::generic::key_value_pair<key_t, value_t>>::remove;
        /// @brief Removes the element with the specified key from the xtd::collections::generic::idictionary <key_t, value_t>.
        /// @param key The key of the element to remove.
        /// @return `true` if the element is successfully removed; otherwise, `false`. This method also returns `false` if key was not found in the original xtd::collections::generic::idictionary <key_t, value_t>.
        /// @remarks Implementations can vary in how they determine equality of objects; for example, the xtd::collections::generic::list <type_t> class uses xtd::collections::generic::comparer <type_t>.Default, whereas the xtd::collections::generic::dictionary <key_t, value_t> class allows the user to specify the xtd::collections::generic::icomparer <type_t>x implementation to use for comparing keys.
        virtual auto remove(const key_t& key) noexcept -> bool = 0;
        
        /// @brief Gets the value associated with the specified key.
        /// @param key The key whose value to get.
        /// @param value When this method returns, the value associated with the specified key, if the key is found; otherwise, the default value for the type of the `value` parameter.
        /// @return `true` if the object that implements xtd::collections::generic::idictionary <key_t, value_t> contains an element with the specified key; otherwise, `false`.
        /// @remarks This method combines the functionality of the xtd::collections::generic::idictionary::contains_key method and the xtd::collections::generic::idictionary::operator [] property.
        /// @remarks If the key is not found, then the value parameter gets the appropriate default value for the type `value_t`; for example, zero (0) for integer types, `false` for Boolean types, and null for reference types
        virtual auto try_get_value(const key_t& key, value_t& value) const -> bool = 0;
        /// @}
        
        /// @name Public Operators
        
        /// @{
        /// @brief Gets the element with the specified key.
        /// @param key The key of the element to get.
        /// @return The element with the specified key.
        /// @exception xtd::collections::generic::key_not_found_exception The property is retrieved and key is not found.
        /// @exception xtd::not_supported_exception The property is set and the xtd::collections::generic::idictionary <key_t, value_t> is read-only.
        /// @remarks This property provides the ability to access a specific element in the collection by using the following syntax: `my_collection[key]`.
        /// @remarks You can also use the `operator []` to add new elements by setting the value of a key that does not exist in the dictionary; for example, `my_collection["my_nonexistent_key"] = my_value`. However, if the specified key already exists in the dictionary, setting the `o`perator []` overwrites the old value. In contrast, the xtd::collections::generic::idictionary::add method does not modify existing elements.
        /// @remarks Implementations can vary in how they determine equality of objects; for example, the xtd::collections::generic::list <type_t> class uses xtd::collections::generic::comparer::default_comparer, whereas the xtd::collections::generic::dictionary <key_t,value_t> class allows the user to specify the xtd::collections::generic::icomparer <type_t> implementation to use for comparing keys.
        virtual auto operator [](const key_t& key) const -> const value_t& = 0;
        /// @brief Sets the element with the specified key.
        /// @param key The key of the element to set.
        /// @return The element with the specified key.
        /// @exception xtd::collections::generic::key_not_found_exception The property is retrieved and key is not found.
        /// @exception xtd::not_supported_exception The property is set and the xtd::collections::generic::idictionary <key_t, value_t> is read-only.
        /// @remarks This property provides the ability to access a specific element in the collection by using the following syntax: `my_collection[key]`.
        /// @remarks You can also use the `operator []` to add new elements by setting the value of a key that does not exist in the dictionary; for example, `my_collection["my_nonexistent_key"] = my_value`. However, if the specified key already exists in the dictionary, setting the `operator []` overwrites the old value. In contrast, the xtd::collections::generic::idictionary::add method does not modify existing elements.
        /// @remarks Implementations can vary in how they determine equality of objects; for example, the xtd::collections::generic::list <type_t> class uses xtd::collections::generic::comparer::default_comparer, whereas the xtd::collections::generic::dictionary <key_t,value_t> class allows the user to specify the xtd::collections::generic::icomparer <type_t> implementation to use for comparing keys.
        virtual auto operator [](const key_t& key) -> value_t& = 0;
        /// @}
      };
    }
  }
}

