/// @file
/// @brief Contains xtd::collections::generic::ilist <type_t> interface.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "icollection.hpp"
#include "extensions/list_common.hpp"
#include "../../epos.hpp"
#include "../../npos.hpp"
#include "../../usize.hpp"

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
      /// #include <xtd/collections/generic/ilist>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections interfaces
      /// @par Examples
      /// The following example implements the xtd::collections::generic::ilist <type_t> interface to create a collection of custom `box` objects named `box_collection`. Each `box` has `height`, `length`, and `width` properties, which are used to define equality. Equality can be defined as all dimensions being the same or the volume being the same. The `box` class implements the xtd::iequatable <type_t> interface to define the default equality as the dimensions being the same.
      ///
      /// The `box_collection` class implements the xtd::collections::generic::ibox::index_of method to use the default equality to determine whether a `box` is in the collection. This method is used by the xtd::collections::generic::icollection::add method so that each `box` added to the collection has a unique set of dimensions. The `box_collection` class also provides an overload of the xtd::collections::generic::icollection::contains method that takes a specified xtd::collections::generic::iequality_comparer <type_t> interface, such as `box_same_dimensions` and `box_same_volume` classes in the example.
      ///
      /// This example also implements an xtd::collections::generic::ienumerator <type_t> interface for the `box_collection` class so that the collection can be enumerated.
      /// @include generic_ilist.cpp
      /// @remarks The xtd::collections::generic::ilist <type_t> interface is the base interface for classes in the xtd::collections::generic namespace.
      /// @remarks The xtd::collections::generic::ilist <type_t> interface extends xtd::collections::generic::ienumerable <type_t>; xtd::collections::generic::idictionary <key_t, value_t> and xtd::collections::generic::ilist <type_t> are more specialized interfaces that extend xtd::collections::generic::ilist <type_t>. A xtd::collections::generic::idictionary <key_t, value_t> implementation is a collection of key/value pairs, like the xtd::collections::generic::dictoinary <key_t, value_t> class. A xtd::collections::generic::ilist <type_t> implementation is a collection of values, and its members can be accessed by index, like the xtd::collections::generic::list <type_t> class.
      /// @remarks If neither the xtd::collections::generic::idictionary <key_t, value_t> interface nor the xtd::collections::generic::ilist <type_t> interface meet the requirements of the required collection, derive the new collection class from the xtd::collections::generic::ilist <type_t> interface instead for more flexibility.
      template<typename type_t>
      class ilist : public xtd::collections::generic::icollection<type_t>, public xtd::collections::generic::extensions::list_common<type_t, ilist<type_t>> {
      public:
        /// @name Public Fields
        
        /// @{
        /// @brief Represents a value that is not a valid position in a collection.
        /// @remarks This constant is typically used to indicate the absence of an index or a failed search operation. It is equivalent to the maximum value of xtd::usize.
        /// @par Examples
        /// ```cpp
        /// auto items = list {1, 2, 3};
        /// if (items.index_of(42) == items.npos)
        ///   console::write_line("Value not found");
        /// ```
        inline static constexpr xtd::usize npos = xtd::npos;
        
        /// @brief Represents the index of the last valid element in a collection.
        /// @remarks Unlike xtd::npos (which means "no position"), xtd::epos points to the last accessible element of a collection. It is equivalent to `items.count() - 1`.
        /// @note This constant is provided for readability and convenience. For example, `items[xtd::epos]` directly accesses the last element without manually subtracting one from the collection count.
        /// @remarks The epos is equivalent to `~1_z`. With bitwise operator the code is more concise.
        /// @par Examples
        /// ```cpp
        /// auto items = list {10, 20, 30, 40};
        /// console::write_line(items[epos]); // Prints 40
        /// console::write_line(items[epos - 1]); // Prints 30
        /// ```
        /// The wollowing exemple shows the same example with bitwise operator as index.
        /// ```cpp
        /// auto items = list {10, 20, 30, 40};
        /// console::write_line(items[~1_i]); // Prints 40
        /// console::write_line(items[~2_i]); // Prints 30
        /// ```
        static inline constexpr xtd::usize epos = npos - 1;
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the number of elements contained in the xtd::collections::generic::icollection <type_t>.
        /// @return The number of elements contained in the xtd::collections::generic::icollection <type_t>.
        [[nodiscard]] virtual auto count() const noexcept -> xtd::usize = 0;
        
        /// @brief Returns pointer to the underlying array serving as element storage.
        /// @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to the address of the first element.
        /// @remarks The pointer is such that range [xtd::collections::generic::list::data(), xtd::collections::generic::list::data() + xtd::collections::generic::list::count()) is always a valid range, even if the container is empty (xtd::collections::generic::list::data() is not dereferenceable in that case).
        [[nodiscard]] virtual auto data() noexcept -> type_t* = 0;

        /// @brief Gets a value indicating whether the xtd::collections::generic::ilist <type_t> has a fixed size.
        /// @return `true` if the xtd::collections::generic::ilist <type_t> has a fixed size; otherwise, `false`.
        /// @remarks A collection with a fixed size does not allow the addition or removal of elements after the collection is created, but it allows the modification of existing elements.
        virtual auto is_fixed_size() const noexcept -> bool = 0;
        
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
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Adds an item to the xtd::collections::generic::icollection <type_t>.
        /// @param item The object to add to the xtd::collections::generic::icollection <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::icollection <type_t> is read-only.
        virtual auto add(const type_t& item) -> void = 0;
        
        /// @brief Removes all items from the xtd::collections::generic::icollection <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::icollection <type_t> is read-only.
        /// @remarks xtd::collections::generic::icollection::count must be set to 0, and references to other objects from elements of the collection must be released.
        virtual auto clear() -> void = 0;
        
        /// @brief Determines whether the xtd::collections::generic::icollection <type_t> contains a specific value.
        /// @param item The object to locate in the xtd::collections::generic::icollection <type_t>.
        /// @return `true` if item is found in the xtd::collections::generic::icollection <type_t>; otherwise, `false`.
        /// @remarks Implementations can vary in how they determine equality of objects; for example, xtd::collections::generic::list <type_t> uses xtd::collections::generic::compoarer <type_t>::default_comparer, whereas xtd::collections::generic::dictionary <key_t, value_t> allows the user to specify the xtd::collections::generic::icompoarer <type_t> implementation to use for comparing keys.
        [[nodiscard]] virtual auto contains(const type_t& item) const noexcept -> bool = 0;
        
        /// @brief Copies the elements of the xtd::collections::generic::icollection <type_t> to an xtd::array, starting at a particular xtd::array index.
        /// @param array The one-dimensional xtd::array that is the destination of the elements copied from xtd::collections::generic::icollection <type_t>. The xtd::array must have zero-based indexing.
        /// @param array_index The zero-based index in `array` at which copying begins.
        /// @exception xtd::argument_exception The number of elements in the source xtd::collections::generic::icollection <type_t> is greater than the available space from `array_index` to the end of the destination `array`.
        virtual auto copy_to(xtd::array<type_t>& array, xtd::usize array_index) const -> void = 0;
        
        /// @brief Returns an enumerator that iterates through a collection.
        /// @return An xtd::collections::generic::enumerator object that can be used to iterate through the collection.
        [[nodiscard]] virtual auto get_enumerator() const -> xtd::collections::generic::enumerator<type_t> = 0;

        /// @brief Determines the index of a specific item in the xtd::collections::generic::ilist <type_t>.
        /// @param item The object to locate in the xtd::collections::generic::ilist <type_t>.
        /// @return The index of item if found in the list; otherwise, xtd::collections::generic::ilist::npos.
        /// @remarks If an object occurs multiple times in the list, the xtd::collections::generic::ilist::index_of method always returns the first instance found.
        [[nodiscard]] virtual auto index_of(const type_t& item) const noexcept -> xtd::usize = 0;
        
        /// @brief Inserts an item to the xtd::collections::generic::ilist <type_t> at the specified index.
        /// @param index The zero-based index at which item should be inserted.
        /// @param item The object to insert into the xtd::collections::generic::ilist <type_t>.
        /// @exception xtd::argument_out_of_range_exception `index` is not a valid index in the xtd::collections::generic::ilist <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::ilist <type_t> is read-only.
        /// @remarks If `index` equals the number of items in the xtd::collections::generic::ilist <type_t>, then item is appended to the list.
        /// @remarks In collections of contiguous elements, such as lists, the elements that follow the insertion point move down to accommodate the new element. If the collection is indexed, the indexes of the elements that are moved are also updated. This behavior does not apply to collections where elements are conceptually grouped into buckets, such as a hash table.
        virtual auto insert(xtd::usize index, const type_t& item) -> void = 0;
        
        /// @brief Removes the first occurrence of a specific object from the xtd::collections::generic::icollection <type_t>.
        /// @param item The object to remove from the xtd::collections::generic::icollection <type_t>.
        /// @return `true` if item was successfully removed from the xtd::collections::generic::icollection <type_t>; otherwise, `false`. This method also returns `false` if item is not found in the original xtd::collections::generic::icollection <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::icollection <type_t> is read-only.
        /// @remarks Implementations can vary in how they determine equality of objects; for example, xtd::collections::generic::list <type_t> uses xtd::collections::generic::compoarer <type_t>::default_comparer, whereas, xtd::collections::generic::dictionary <key_t, value_t> allows the user to specify the xtd::collections::generic::icompoarer <type_t> implementation to use for comparing keys.
        /// @remarks In collections of contiguous elements, such as lists, the elements that follow the removed element move up to occupy the vacated spot. If the collection is indexed, the indexes of the elements that are moved are also updated. This behavior does not apply to collections where elements are conceptually grouped into buckets, such as a hash table.
        virtual auto remove(const type_t& item) -> bool = 0;

        /// @brief Removes the xtd::collections::generic::ilist <type_t> item at the specified index.
        /// @param index The zero-based index of the item to remove.
        /// @exception xtd::argument_out_of_range_exception `index` is not a valid index in the xtd::collections::generic::ilist <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::ilist <type_t> is read-only.
        /// @remarks In collections of contiguous elements, such as lists, the elements that follow the removed element move up to occupy the vacated spot. If the collection is indexed, the indexes of the elements that are moved are also updated. This behavior does not apply to collections where elements are conceptually grouped into buckets, such as a hash table.
        virtual auto remove_at(xtd::usize index) -> void = 0;
        /// @}
        
        /// @name Public Operators
        
        /// @{
        using xtd::collections::generic::extensions::list_common<type_t, ilist<type_t>>::operator [];
        using xtd::collections::generic::extensions::list_common<type_t, ilist<type_t>>::operator ();
        /// @brief Gets the element at the specified index.
        /// @param index The zero-based index of the element to get.
        /// @remarks This operator provides the ability to access a specific element in the collection by using the following syntax: `my_collection[index]`.
        virtual auto operator [](xtd::usize index) const -> const type_t& = 0;
        /// @brief Sets the element at the specified index.
        /// @param index The zero-based index of the element to set.
        /// @remarks This operator provides the ability to access a specific element in the collection by using the following syntax: `my_collection[index]`.
        virtual auto operator [](xtd::usize index) -> type_t& = 0;
        /// @}
      };
    }
  }
}
