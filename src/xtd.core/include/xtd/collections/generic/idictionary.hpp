/// @file
/// @brief Contains xtd::collections::generic::idictionary <key_t, value_t> interface.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "icollection.hpp"
#include "key_value_pair.hpp"
#define __XTD_CORE_INTERNAL__
#include "../../internal/__list_definition.hpp"
#undef __XTD_CORE_INTERNAL__
//#include "list.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents a generic collection of key/value pairs.
      /// @par Definition
      /// ```cpp
      /// template<typename key_t, typename value_t>
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
      template<typename key_t, typename value_t>
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
        /// @brief Gets the number of elements contained in the xtd::collections::generic::icollection <type_t>.
        /// @return The number of elements contained in the xtd::collections::generic::icollection <type_t>.
        [[nodiscard]] virtual auto count() const noexcept -> xtd::usize = 0;
        
        
        /// @brief Gets a value indicating whether the xtd::collections::generic::icollection <type_t> is read-only.
        /// @return `true` if the xtd::collections::generic::icollection <type_t> is read-only; otherwise, `false`.
        /// @remarks A collection that is read-only does not allow the addition or removal of elements after the collection is created. Note that read-only in this context does not indicate whether individual elements of the collection can be modified, since the xtd::collections::generic::icollection <type_t> interface only supports addition and removal operations. For example, the xtd::collections::generic::icollection::is_read_only property of an array that is cast or converted to an xtd::collections::generic::icollection <type_t> object returns `true`, even though individual array elements can be modified.
        [[nodiscard]] virtual auto is_read_only() const noexcept -> bool = 0;
        
        /// @brief Gets a value indicating whether access to the xtd::collections::generic::icollection <type_t> is synchronized (thread safe).
        /// @return `true` if access to the xtd::collections::generic::icollection <type_t> is synchronized (thread safe); otherwise, `false`.
        /// @remarks xtd::collections::generic::icollection::sync_root returns an object, which can be used to synchronize access to the xtd::collections::generic::icollection <type_t>.
        /// @remarks Most collection classes in the xtd::collections namespace also implement a `synchronized` method, which provides a synchronized wrapper around the underlying collection.
        /// @remarks Enumerating through a collection is intrinsically not a thread-safe procedure. Even when a collection is synchronized, other threads can still modify the collection, which causes the enumerator to throw an exception. To guarantee thread safety during enumeration, you can either lock the collection during the entire enumeration or catch the exceptions resulting from changes made by other threads.
        /// @remarks The following code example shows how to lock the collection using the xtd::collections::generic::icollection::sync_root property during the entire enumeration.
        /// @code
        /// icollection& my_collection = some_collection;
        /// lock_(my_collection.sync_root()) {
        ///   for (const auto& item : my_collection) {
        ///     // Insert your code here.
        ///   }
        /// }
        /// @endcode
        [[nodiscard]] virtual auto is_synchronized() const noexcept -> bool = 0;

        /// @brief Gets an xtd::collections::generic::icollection <type_t> containing the keys of the xtd::collections::generic::idictionary <key_t, value_t>.
        /// @return An xtd::collections::generic::icollection <type_t> containing the keys of the object that implements xtd::collections::generic::idictionary <key_t, value_t>.
        /// @remarks The order of the keys in the returned xtd::collections::generic::icollection <type_t> is unspecified, but it is guaranteed to be the same order as the corresponding values in the xtd::collections::generic::icollection <type_t> returned by the xtd::collections::generic::idictionary::values property.
        [[nodiscard]] virtual auto keys() const noexcept -> key_collection = 0;
        
        /// @brief Gets an object that can be used to synchronize access to the the xtd::collections::generic::icollection <type_t>.
        /// @return An object that can be used to synchronize access to the the xtd::collections::generic::icollection <type_t>.
        /// @remarks For collections whose underlying store is not publicly available, the expected implementation is to return the current instance. Note that the pointer to the current instance might not be sufficient for collections that wrap other collections; those should return the underlying collection's `sync_root` property.
        /// @remarks Most collection classes in the xts::.collections namespace also implement a `synchronized` method, which provides a synchronized wrapper around the underlying collection. However, derived classes can provide their own synchronized version of the collection using the xtd::collections::generic::icollection::sync_root property. The synchronizing code must perform operations on the xtd::collections::generic::icollection::sync_root property of the collection, not directly on the collection. This ensures proper operation of collections that are derived from other objects. Specifically, it maintains proper synchronization with other threads that might be simultaneously modifying the collection instance.
        /// @remarks In the absence of a `synchronized` method on a collection, the expected usage for the xtd::collections::generic::icollection::sync_root looks as follows:
        /// @code
        /// icollection& my_collection = some_collection;
        /// lock_(my_collection.sync_root()) {
        ///   // Some operation on the collection, which is now thread safe.
        /// }
        /// @encode
        /// @remarks Enumerating through a collection is intrinsically not a thread-safe procedure. Even when a collection is synchronized, other threads can still modify the collection, which causes the enumerator to throw an exception. To guarantee thread safety during enumeration, you can either lock the collection during the entire enumeration or catch the exceptions resulting from changes made by other threads.
        /// @remarks The following code example shows how to lock the collection using the xtd::collections::generic::icollection::sync_root property during the entire enumeration.
        /// @code
        /// icollection& my_collection = some_collection;
        /// lock_(my_collection.sync_root()) {
        ///   for (const auto& item : my_collection) {
        ///     // Insert your code here.
        ///   }
        /// }
        /// @endcode
        [[nodiscard]] virtual auto sync_root() const noexcept -> const xtd::object& = 0;

        /// @brief Gets an xtd::collections::generic::icollection <type_t> containing the values of the xtd::collections::generic::idictionary <key_t, value_t>.
        /// @return An xtd::collections::generic::icollection <type_t> containing the values of the object that implements xtd::collections::generic::idictionary <key_t, value_t>.
        /// @remarks The order of the values in the returned xtd::collections::generic::icollection <type_t> is unspecified, but it is guaranteed to be the same order as the corresponding values in the xtd::collections::generic::icollection <type_t> returned by the xtd::collections::generic::idictionary::keys property.
        [[nodiscard]] virtual auto values() const noexcept -> value_collection = 0;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Adds an item to the xtd::collections::generic::icollection <type_t>.
        /// @param item The object to add to the xtd::collections::generic::icollection <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::icollection <type_t> is read-only.
        virtual auto add(const xtd::collections::generic::key_value_pair<key_t, value_t>& item) -> void = 0;
        
        /// @brief Adds an element with the provided key and value to the xtd::collections::generic::idictionary <key_t, value_t>.
        /// @param key The object to use as the key of the element to add.
        /// @param value The object to use as the value of the element to add.
        /// @exception xtd::argument_exception An element with the same key already exists in the xtd::collections::generic::idictionary <key_t, value_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::idictionary <key_t, value_t> is read-only.
        /// @remarks You can also use the `operator []` to add new elements by setting the value of a key that does not exist in the dictionary; for example, `my_collection["my_nonexistent_key"] = my_value`. However, if the specified key already exists in the dictionary, setting the `operator []` overwrites the old value. In contrast, the xtd::collections::generic::idictionary::add method does not modify existing elements.
        /// @remarks Implementations can vary in how they determine equality of objects; for example, the xtd::collections::generic::list <type_t> class uses xtd::collections::generic::comparer::default_comparer, whereas the xtd::collections::generic::dictionary <key_t,value_t> class allows the user to specify the xtd::collections::generic::icomparer <type_t> implementation to use for comparing keys.
        virtual auto add(const key_t& key, const value_t& value) -> void = 0;
        
        /// @brief Removes all items from the xtd::collections::generic::icollection <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::icollection <type_t> is read-only.
        /// @remarks xtd::collections::generic::icollection::count must be set to 0, and references to other objects from elements of the collection must be released.
        virtual auto clear() -> void = 0;
        
        /// @brief Determines whether the xtd::collections::generic::icollection <type_t> contains a specific value.
        /// @param item The object to locate in the xtd::collections::generic::icollection <type_t>.
        /// @return `true` if item is found in the xtd::collections::generic::icollection <type_t>; otherwise, `false`.
        /// @remarks Implementations can vary in how they determine equality of objects; for example, xtd::collections::generic::list <type_t> uses xtd::collections::generic::compoarer <type_t>::default_comparer, whereas xtd::collections::generic::dictionary <key_t, value_t> allows the user to specify the xtd::collections::generic::icompoarer <type_t> implementation to use for comparing keys.
        [[nodiscard]] virtual auto contains(const xtd::collections::generic::key_value_pair<key_t, value_t>& item) const noexcept -> bool = 0;

        /// @brief Determines whether the xtd::collections::generic::idictionary <key_t, value_t> contains an element with the specified key.
        /// @param key The key to locate in the xtd::collections::generic::idictionary <key_t, value_t>.
        /// @return `true` if the xtd::collections::generic::idictionary <key_t, value_t> contains an element with the key; otherwise, `false`.
        /// @remarks Implementations can vary in how they determine equality of objects; for example, the xtd::collections::generic::list <type_t> class uses xtd::collections::generic::comparer <type_t>.Default, whereas the xtd::collections::generic::dictionary <key_t, value_t> class allows the user to specify the xtd::collections::generic::icomparer <type_t>x implementation to use for comparing keys.
        [[nodiscard]] virtual auto contains_key(const key_t& key) const noexcept -> bool = 0;
        
        /// @brief Copies the elements of the xtd::collections::generic::icollection <type_t> to an xtd::array, starting at a particular xtd::array index.
        /// @param array The one-dimensional xtd::array that is the destination of the elements copied from xtd::collections::generic::icollection <type_t>. The xtd::array must have zero-based indexing.
        /// @param array_index The zero-based index in `array` at which copying begins.
        /// @exception xtd::argument_exception The number of elements in the source xtd::collections::generic::icollection <type_t> is greater than the available space from `array_index` to the end of the destination `array`.
        virtual auto copy_to(xtd::array<xtd::collections::generic::key_value_pair<key_t, value_t>>& array, xtd::usize array_index) const -> void = 0;
        
        /// @brief Returns an enumerator that iterates through a collection.
        /// @return An xtd::collections::generic::enumerator object that can be used to iterate through the collection.
        [[nodiscard]] virtual auto get_enumerator() const -> xtd::collections::generic::enumerator<xtd::collections::generic::key_value_pair<key_t, value_t>> = 0;
        
        /// @brief Removes the first occurrence of a specific object from the xtd::collections::generic::icollection <type_t>.
        /// @param item The object to remove from the xtd::collections::generic::icollection <type_t>.
        /// @return `true` if item was successfully removed from the xtd::collections::generic::icollection <type_t>; otherwise, `false`. This method also returns `false` if item is not found in the original xtd::collections::generic::icollection <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::icollection <type_t> is read-only.
        /// @remarks Implementations can vary in how they determine equality of objects; for example, xtd::collections::generic::list <type_t> uses xtd::collections::generic::compoarer <type_t>::default_comparer, whereas, xtd::collections::generic::dictionary <key_t, value_t> allows the user to specify the xtd::collections::generic::icompoarer <type_t> implementation to use for comparing keys.
        /// @remarks In collections of contiguous elements, such as lists, the elements that follow the removed element move up to occupy the vacated spot. If the collection is indexed, the indexes of the elements that are moved are also updated. This behavior does not apply to collections where elements are conceptually grouped into buckets, such as a hash table.
        virtual auto remove(const xtd::collections::generic::key_value_pair<key_t, value_t>& item) -> bool = 0;

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
        [[nodiscard]] virtual auto try_get_value(const key_t& key, value_t& value) const -> bool = 0;
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
        [[nodiscard]] virtual auto operator [](const key_t& key) const -> const value_t& = 0;
        /// @brief Sets the element with the specified key.
        /// @param key The key of the element to set.
        /// @return The element with the specified key.
        /// @exception xtd::collections::generic::key_not_found_exception The property is retrieved and key is not found.
        /// @exception xtd::not_supported_exception The property is set and the xtd::collections::generic::idictionary <key_t, value_t> is read-only.
        /// @remarks This property provides the ability to access a specific element in the collection by using the following syntax: `my_collection[key]`.
        /// @remarks You can also use the `operator []` to add new elements by setting the value of a key that does not exist in the dictionary; for example, `my_collection["my_nonexistent_key"] = my_value`. However, if the specified key already exists in the dictionary, setting the `operator []` overwrites the old value. In contrast, the xtd::collections::generic::idictionary::add method does not modify existing elements.
        /// @remarks Implementations can vary in how they determine equality of objects; for example, the xtd::collections::generic::list <type_t> class uses xtd::collections::generic::comparer::default_comparer, whereas the xtd::collections::generic::dictionary <key_t,value_t> class allows the user to specify the xtd::collections::generic::icomparer <type_t> implementation to use for comparing keys.
        [[nodiscard]] virtual auto operator [](const key_t& key) -> value_t& = 0;
        /// @}
      };
    }
  }
}

