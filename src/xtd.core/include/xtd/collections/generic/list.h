/// @file
/// @brief Contains xtd::collections::generic::list struct.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "helpers/allocator.h"
#include "ilist.h"
#include "../../argument_exception.h"
#include "../../argument_out_of_range_exception.h"
#include "../../box_integer.h"
#include "../../invalid_operation_exception.h"
#include "../../is.h"
#include "../../literals.h"
#include "../../object.h"
#include "../../ustring.h"
#include <utility>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents a strongly typed list of objects that can be accessed by index. Provides methods to search, sort, and manipulate lists.
      /// ```cpp
      /// template<typename type_t>
      /// class list : public xtd::object, xtd::collections::generic::ilist<type_t>, public xtd::iequatable<xtd::collections::generic::list<type_t>>
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/list
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @remarks The xtd::collections::generic::list <type_t> class instanciate as xtd::collections::generic::list::base_type a [std::vector](https://en.cppreference.com/w/cpp/container/vector) with xtd::collections::generic::helpers::allocator instead [std::allocator](https://en.cppreference.com/w/cpp/memory/allocator). Use xtd::collections::generic::list::get_base_type() to access the underlying [std::vector](https://en.cppreference.com/w/cpp/container/vector).
      /// @remarks The xtd::collections::generic::list <type_t> class can also be used to manage a dynamic array of `bool` exactly as other types unlike [std::vector](https://en.cppreference.com/w/cpp/container/vector) with xtd::collections::generic::helpers::allocator instead [std::allocator](https://en.cppreference.com/w/cpp/memory/allocator). When the `type_t`is `bool` The underlying [std::vector](https://en.cppreference.com/w/cpp/container/vector) uses xtd::byte.
      /// @remarks The xtd::collections::generic::list <type_t> class is the generic equivalent of the xtd::collections::array_list class. It implements the xtd::collections::generic::ilist <type_t> generic interface by using an array whose size is dynamically increased as required.
      /// @remarks You can add items to a xtd::collections::generic::list <type_t> by using the xtd::collections::generic::list::add or xtd::collections::generic::list::add_range methods.
      /// @remarks The xtd::collections::generic::list <type_t> class uses both an equality comparer and an ordering comparer.
      /// * Methods such as xtd::collections::generic::list::contains, xtd::collections::generic::list::index_of, xtd::collections::generic::list::last_index_of, and xtd::collections::generic::list::remove use an equality comparer for the list elements. The default equality comparer for type `type_t` is determined as follows. If type `type_t` implements the xtd::iequatable <type_t> generic interface, then the equality comparer is the xtd::iequatable::equals method of that interface; otherwise, if the `type_t`inherits of the xtd::object class, the default equality comparer is xtd::object::equals. If the `type_t` does not implement the xtd::iequality <type_t> interface and does not inherit from xtd::object, the `type_t` must implement the euqality operator : `bool operator ==(const type_t& rhs) const noexcept`.
      /// * Methods such as xtd::collections::generic::list::binary_search and xtd::collections::generic::list::sort use an ordering comparer for the list elements. The default comparer for type `type_t` is determined as follows. If type `type_t` implements the xtd::icomparable <type_t> generic interface, then the default comparer is the xtd::icomaprable::compare_to method of that interface. If the `type_t` type does not implement the xtd::icomparable <type_t> interface, the `type_t` type must implement the less than operator : `bool operator <(const type_t& rhs) const noexcept`.
      /// @remarks The xtd::collections::generic::list <type_t> is not guaranteed to be sorted. You must sort the xtd::collections::generic::list <type_t> before performing operations (such as xtd::collections::binary_search) that require the xtd::collections::generic::list <type_t> to be sorted.
      /// @remarks Elements in this collection can be accessed using an integer index. Indexes in this collection are zero-based.
      /// @remarks For an immutable version of the xtd::collections::generic::list <type_t> class, see xtd::collections::immutale::immutable_list <type_t>.
      /// @par Performance considerations
      /// As xtd::collections::generic::list <type_t> instantiates and uses only the methods of [std::vector](https://en.cppreference.com/w/cpp/container/vector), the performance of xtd::collections::generic::list <type_t> is practically identical to that of [std::vector](https://en.cppreference.com/w/cpp/container/vector).
      /// @par Examples
      /// The following example demonstrates how to add, remove, and insert a simple business object in a xtd::collections::generic::list <type_t>.
      /// @include generic_list.cpp
      /// The following example demonstrates several properties and methods of the xtd::collections::generic::list <type_t> generic class of type string. (For an example of a xtd::collections::generic::list <type_t> of complex types, see the xtd::collections::generic::list::contains method.)
      ///
      /// The parameterless constructor is used to create a list of strings with the default capacity. The xtd::collections::generic::list::capacity property is displayed and then the xtd::collections::generic::list::add method is used to add several items. The items are listed, and the xtd::collections::generic::list::capacity property is displayed again, along with the xtd::collections::generic::list::count property, to show that the capacity has been increased as needed.
      ///
      /// The xtd::collections::generic::list::contains method is used to test for the presence of an item in the list, the Insert method is used to insert a new item in the middle of the list, and the contents of the list are displayed again.
      ///
      /// The default xtd::collections::generic::list::operator [] is used to retrieve an item, the xtd::collections::generic::list::remove method is used to remove the first instance of the duplicate item added earlier, and the contents are displayed again. The xtd::collections::generic::list::remove method always removes the first instance it encounters.
      ///
      /// The xtd::collections::generic::list::trim_excess method is used to reduce the capacity to match the count, and the xtd::collections::generic::list::capacity and xtd::collections::generic::list::count properties are displayed. If the unused capacity had been less than 10 percent of total capacity, the list would not have been resized.
      ///
      /// Finally, the xtd::collections::generic::list::clear method is used to remove all items from the list, and the xtd::collections::generic::list::capacity and xtd::collections::generic::list::count properties are displayed.
      /// @include generic_list2.cpp
      template<typename type_t>
      class list : public xtd::object, public xtd::collections::generic::ilist<type_t>, public xtd::iequatable<xtd::collections::generic::list<type_t>> {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the list value type.
        using value_type = type_t;
        /// @brief Represents the list allocator type.
        using allocator_type = helpers::allocator<typename std::conditional<std::is_same<bool, value_type>::value, xtd::byte, value_type>::type>;
        /// @brief Represents the list base type.
        using base_type = std::vector<typename std::conditional<std::is_same<bool, value_type>::value, xtd::byte, value_type>::type, allocator_type>;
        /// @brief Represents the list size type (usually xtd::size).
        using size_type = xtd::size;
        /// @brief Represents the list difference type (usually xtd::ptrdiff).
        using difference_type = xtd::ptrdiff;
        /// @brief Represents the reference of list value type.
        using reference = value_type&;
        /// @brief Represents the const reference of list value type.
        using const_reference = const value_type&;
        /// @brief Represents the pointer of list value type.
        using pointer = value_type*;
        /// @brief Represents the const pointer of list value type.
        using const_pointer = const value_type*;
        /// @brief Represents the iterator of list value type.
        using iterator = ilist<type_t>::iterator;
        /// @brief Represents the const iterator of list value type.
        using const_iterator = ilist<type_t>::const_iterator;
        /// @brief Represents the reverse iterator of list value type.
        using reverse_iterator = base_type::reverse_iterator;
        /// @brief Represents the const reverse iterator of list value type.
        using const_reverse_iterator = base_type::const_reverse_iterator;
        /// @}
        
        /// @name Public Fields
        
        /// @{
        /// @brief This is a special value equal to the maximum value representable by the type xtd::size.
        inline static constexpr xtd::size npos = ilist<type_t>::npos;
        /// @}
        
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::collections::generic::list class that is empty.
        /// @remarks The capacity of a xtd::collections::generic::list is the number of elements that the xtd::collections::generic::list can hold. As elements are added to a xtd::collections::generic::list, the capacity is automatically increased as required by reallocating the internal array.
        /// @remarks If the size of the collection can be estimated, using the xtd::collections::generic::list(xtd::size) constructor and specifying the initial capacity eliminates the need to perform a number of resizing operations while adding elements to the xtd::collections::generic::list.
        /// @remarks The capacity can be decreased by calling the xtd::collections::generic::list::trim_excess method or by setting the xtd::collections::generic::list::capacity property explicitly. Decreasing the capacity reallocates memory and copies all the elements in the xtd::collections::generic::list.
        /// @remarks This constructor is an O(1) operation.
        /// @remarks The following code example demonstrates the default constructor of the xtd::collections::generic::list generic class. The default constructor creates a list with the default capacity, as demonstrated by displaying the xtd::collections::generic::list::capacity property.
        /// @par Examples
        /// The code example adds, inserts, and removes items, showing how the capacity changes as these methods are used.
        /// @include list.cpp
        list() noexcept = default;
        
        /// @brief Initializes a new instance of the xtd::collections::generic::list <type_t> class that contains elements copied from the specified collection and has sufficient capacity to accommodate the number of elements copied.
        /// @param collection The collection whose elements are copied to the new list.
        /// @exception ArgumentNullException The parameters collection is null or element reference null in collection.
        /// @remarks The elements are copied onto the xtd::collections::generic::list <type_t> in the same order they are read by the enumerator of the collection.
        /// @remarks This constructor is an O(n) operation, where n is the number of elements in collection.
        /// @par Examples
        /// The following code example demonstrates the xtd::collections::generic::list <type_t> constructor and various methods of the xtd::collections::generic::list <type_t> class that act on ranges. An array of strings is created and passed to the constructor, populating the list with the elements of the array. The Capacity property is then displayed, to show that the initial capacity is exactly what is required to hold the input elements.
        /// @include List2.cpp
        //list(const ienumerable<type_t>& collection) : {
        //  for (const type_t& value : collection)
        //    add(value);
        //}
        
        /// @brief Initializes a new instance of the xtd::collections::generic::list class that is empty and has the specified initial capacity.
        /// @param capacity The number of elements that the new list can initially store.
        /// @remarks The capacity of a xtd::collections::generic::list is the number of elements that the xtd::collections::generic::list can hold. As elements are added to a xtd::collections::generic::list, the capacity is automatically increased as required by reallocating the internal array.
        /// @remarks If the size of the collection can be estimated, specifying the initial capacity eliminates the need to perform a number of resizing operations while adding elements to the xtd::collections::generic::list.
        /// @remarks The capacity can be decreased by calling the xtd::collections::generic::list::trim_excess method or by setting the xtd::collections::generic::list::cpacity property explicitly. Decreasing the capacity reallocates memory and copies all the elements in the xtd::collections::generic::list.
        /// @remarks This constructor is an O(n) operation, where n is capacity.
        /// @remarks The following code example demonstrates the xtd::collections::generic::list::as_read_only method. A xtd::collections::generic::list of strings with a capacity of 4 is created, because the ultimate size of the list is known to be exactly 4. The list is populated with four strings, and the AsReadOnly method is used to get a read-only xtd::collections::generic::ilist generic interface implementation that wraps the original list.
        /// @par Examples
        /// An element of the original list is set to "Coelophysis" using the `item` property, and the contents of the read-only list are displayed again to demonstrate that it is just a wrapper for the original list.
        /// @include list3.cpp
        //list(xtd::size capacity) {items_.reserve(capacity);}
        
        /// @brief Constructs an empty container with the given allocator.
        /// @param alloc The allocator to use for all memory allocations of this container.
        explicit list(const allocator_type& alloc) noexcept : items_(alloc) {}
        /// @brief Constructs the container with specified count copies of elements with specified value.
        /// @param count The size of the container.
        /// @param value The value to initialize elements of the container with.
        /// @param alloc The allocator to use for all memory allocations of this container.
        list(size_type count, const type_t& value, const allocator_type& alloc = allocator_type()) : items_(count, value, alloc) {}
        /// @brief Constructs the container with specified count default-inserted instances of type_t. No copies are made.
        /// @param count The size of the container.
        /// @param alloc The allocator to use for all memory allocations of this container.
        explicit list(size_type count, const allocator_type& alloc = allocator_type()) : items_(count, alloc) {}
        /// @brief Constructs the container with the contents of the range [first, last).
        /// @param first The first iterator the range to copy the elements from.
        /// @param last The last iterator the range to copy the elements from.
        /// @param alloc The allocator to use for all memory allocations of this container.
        template<typename input_iterator_t>
        list(input_iterator_t first, input_iterator_t last, const allocator_type& alloc = allocator_type()) : items_(first, last, alloc) {}
        
        /// @brief Default copy constructor with specified list.
        /// @param list The xtd::collections::generic::list which elements will be inserted from.
        list(const list& list) = default;
        /// @brief Copy constructor with specified base type list.
        /// @param list The xtd::collections::generic::list::base_type which elements will be inserted from.
        list(const base_type& list) : items_(list) {}
        /// @brief Default copy constructor with specified list, and allocator.
        /// @param list The xtd::collections::generic::list which elements will be inserted from.
        /// @param alloc The allocator to use for all memory allocations of this container.
        list(const list& list, const allocator_type& alloc) : items_(list.items_, alloc) {}
        /// @brief Default copy constructor with specified base type list, and allocator.
        /// @param list The xtd::collections::generic::list which elements will be inserted from.
        /// @param alloc The allocator to use for all memory allocations of this container.
        list(const base_type& list, const allocator_type& alloc) : items_(list, alloc) {}
        /// @brief Constructs the container with the contents of the specified initializer list, and allocator.
        /// @param items The initializer list to initialize the elements of the container with.
        /// @param alloc The allocator to use for all memory allocations of this container.
        list(std::initializer_list<type_t> items, const allocator_type& alloc = allocator_type()) : items_(alloc) {assign(items);}
        
        /// @brief Move constructor with specified list.
        /// @param list The xtd::collections::generic::list::base_type which elements will be moved from.
        list(list&& other) : items_(std::move(other.items_)), version_(std::move(other.version_)) {other.version_= 0;}
        /// @brief Move constructor with specified base type list.
        /// @param list The xtd::collections::generic::list::base_type which elements will be moved from.
        list(base_type&& other) : items_(std::move(other)) {}
        /// @brief Move constructor with specified list, and allocator.
        /// @param list The xtd::collections::generic::list::base_type which elements will be moved from.
        /// @param alloc The allocator to use for all memory allocations of this container.
        list(list&& other, const allocator_type& alloc) : items_(other.items_, alloc), version_{std::move(other.version_)} {}
        /// @brief Move constructor with specified base tyoe list, and allocator.
        /// @param list The xtd::collections::generic::list::base_type which elements will be moved from.
        /// @param alloc The allocator to use for all memory allocations of this container.
        list(base_type&& other, const allocator_type& alloc) : items_(other, alloc) {}
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Returns a reference to the last element in the container.
        /// @return Reference to the first element.
        /// @remarks Calling front on an empty container causes undefined behavior.
        virtual reference back() {return (*this)[count() - 1];}
        /// @brief Returns a reference to the last element in the container.
        /// @return Reference to the first element.
        /// @remarks Calling front on an empty container causes undefined behavior.
        virtual const_reference back() const {return (*this)[count() - 1];}
        
        /// @brief Returns an iterator to the first element of the enumarable.
        /// @return Iterator to the first element.
        const_iterator begin() const noexcept override {return ienumerable<value_type>::begin();}
        /// @brief Returns an iterator to the first element of the enumarable.
        /// @return Iterator to the first element.
        iterator begin() noexcept override {return ienumerable<value_type>::begin();}

        /// @brief Gets the total number of elements the internal data structure can hold without resizing.
        /// @return Capacity of the currently allocated storage.
        /// @exceptions xtd::argument_out_of_range_exception xtd::collections::generic::list::capacity is set to a value that is less than xtd::collections::generic::list::count.
        /// @par Examples
        /// The following example demonstrates how to add, remove, and insert a simple business object in a xtd::collections::generic::list <type_t>.
        /// @include generic_list.cpp
        /// The following example demonstrates several properties and methods of the xtd::collections::generic::list <type_t> generic class of type string. (For an example of a xtd::collections::generic::list <type_t> of complex types, see the xtd::collections::generic::list::contains method.)
        ///
        /// The parameterless constructor is used to create a list of strings with the default capacity. The xtd::collections::generic::list::capacity property is displayed and then the xtd::collections::generic::list::add method is used to add several items. The items are listed, and the xtd::collections::generic::list::capacity property is displayed again, along with the xtd::collections::generic::list::count property, to show that the capacity has been increased as needed.
        ///
        /// The xtd::collections::generic::list::contains method is used to test for the presence of an item in the list, the Insert method is used to insert a new item in the middle of the list, and the contents of the list are displayed again.
        ///
        /// The default xtd::collections::generic::list::operator [] is used to retrieve an item, the xtd::collections::generic::list::remove method is used to remove the first instance of the duplicate item added earlier, and the contents are displayed again. The xtd::collections::generic::list::remove method always removes the first instance it encounters.
        ///
        /// The xtd::collections::generic::list::trim_excess method is used to reduce the capacity to match the count, and the xtd::collections::generic::list::capacity and xtd::collections::generic::list::count properties are displayed. If the unused capacity had been less than 10 percent of total capacity, the list would not have been resized.
        ///
        /// Finally, the xtd::collections::generic::list::clear method is used to remove all items from the list, and the xtd::collections::generic::list::capacity and xtd::collections::generic::list::count properties are displayed.
        /// @include generic_list2.cpp
        /// @remarks xtd::collections::generic::list::capacity is the number of elements that the xtd::collections::generic::list <type_t> can store before resizing is required, whereas xtd::collections::generic::list::count is the number of elements that are actually in the xtd::collections::generic::list <type_t>.
        /// @remarks xtd::collections::generic::list::capacity is always greater than or equal to xtd::collections::generic::list::count. If xtd::collections::generic::list::count exceeds xtd::collections::generic::list::capacity while adding elements, the capacity is increased by automatically reallocating the internal array before copying the old elements and adding the new elements.
        /// @remarks If the capacity is significantly larger than the count and you want to reduce the memory used by the xtd::collections::generic::list <type_t>, you can decrease capacity by calling the xtd::collections::generic::list::trim_excess method or by setting the xtd::collections::generic::list::capacity property explicitly to a lower value. When the value of xtd::collections::generic::list::capacity is set explicitly, the internal array is also reallocated to accommodate the specified capacity, and all the elements are copied.
        /// @remarks Retrieving the value of this property is an O(1) operation; setting the property is an O(n) operation, where n is the new capacity.
        virtual size_type capacity() const noexcept {return items_.capacity();}
        /// @brief Sets the total number of elements the internal data structure can hold without resizing.
        /// @return Capacity of the currently allocated storage.
        /// @exceptions xtd::argument_out_of_range_exception xtd::collections::generic::list::capacity is set to a value that is less than xtd::collections::generic::list::count.
        /// @par Examples
        /// The following example demonstrates how to add, remove, and insert a simple business object in a xtd::collections::generic::list <type_t>.
        /// @include generic_list.cpp
        /// The following example demonstrates several properties and methods of the xtd::collections::generic::list <type_t> generic class of type string. (For an example of a xtd::collections::generic::list <type_t> of complex types, see the xtd::collections::generic::list::contains method.)
        ///
        /// The parameterless constructor is used to create a list of strings with the default capacity. The xtd::collections::generic::list::capacity property is displayed and then the xtd::collections::generic::list::add method is used to add several items. The items are listed, and the xtd::collections::generic::list::capacity property is displayed again, along with the xtd::collections::generic::list::count property, to show that the capacity has been increased as needed.
        ///
        /// The xtd::collections::generic::list::contains method is used to test for the presence of an item in the list, the Insert method is used to insert a new item in the middle of the list, and the contents of the list are displayed again.
        ///
        /// The default xtd::collections::generic::list::operator [] is used to retrieve an item, the xtd::collections::generic::list::remove method is used to remove the first instance of the duplicate item added earlier, and the contents are displayed again. The xtd::collections::generic::list::remove method always removes the first instance it encounters.
        ///
        /// The xtd::collections::generic::list::trim_excess method is used to reduce the capacity to match the count, and the xtd::collections::generic::list::capacity and xtd::collections::generic::list::count properties are displayed. If the unused capacity had been less than 10 percent of total capacity, the list would not have been resized.
        ///
        /// Finally, the xtd::collections::generic::list::clear method is used to remove all items from the list, and the xtd::collections::generic::list::capacity and xtd::collections::generic::list::count properties are displayed.
        /// @include generic_list2.cpp
        /// @remarks xtd::collections::generic::list::capacity is the number of elements that the xtd::collections::generic::list <type_t> can store before resizing is required, whereas xtd::collections::generic::list::count is the number of elements that are actually in the xtd::collections::generic::list <type_t>.
        /// @remarks xtd::collections::generic::list::capacity is always greater than or equal to xtd::collections::generic::list::count. If xtd::collections::generic::list::count exceeds xtd::collections::generic::list::capacity while adding elements, the capacity is increased by automatically reallocating the internal array before copying the old elements and adding the new elements.
        /// @remarks If the capacity is significantly larger than the count and you want to reduce the memory used by the xtd::collections::generic::list <type_t>, you can decrease capacity by calling the xtd::collections::generic::list::trim_excess method or by setting the xtd::collections::generic::list::capacity property explicitly to a lower value. When the value of xtd::collections::generic::list::capacity is set explicitly, the internal array is also reallocated to accommodate the specified capacity, and all the elements are copied.
        /// @remarks Retrieving the value of this property is an O(1) operation; setting the property is an O(n) operation, where n is the new capacity.
        virtual void capacity(size_type value) {
          if (value < count()) throw argument_out_of_range_exception {csf_};
          items_.reserve(value);
        }

        /// @brief Returns an iterator to the first element of the enumarable.
        /// @return Iterator to the first element.
        const_iterator cbegin() const noexcept override {return ienumerable<value_type>::cbegin();}
        
        /// @brief Returns an iterator to the element following the last element of the enumarable.
        /// @return Iterator to the element following the last element.
        const_iterator cend() const noexcept override {return ienumerable<value_type>::cend();}

        /// @brief Gets the number of elements contained in the xtd::collections::generic::list <type_t>.
        /// @return The number of elements contained in the xtd::collections::generic::list <type_t>.
        /// @par Examples
        /// The following example demonstrates how to add, remove, and insert a simple business object in a xtd::collections::generic::list <type_t>.
        /// @include generic_list.cpp
        /// The following example demonstrates several properties and methods of the xtd::collections::generic::list <type_t> generic class of type string. (For an example of a xtd::collections::generic::list <type_t> of complex types, see the xtd::collections::generic::list::contains method.)
        ///
        /// The parameterless constructor is used to create a list of strings with the default capacity. The xtd::collections::generic::list::capacity property is displayed and then the xtd::collections::generic::list::add method is used to add several items. The items are listed, and the xtd::collections::generic::list::capacity property is displayed again, along with the xtd::collections::generic::list::count property, to show that the capacity has been increased as needed.
        ///
        /// The xtd::collections::generic::list::contains method is used to test for the presence of an item in the list, the Insert method is used to insert a new item in the middle of the list, and the contents of the list are displayed again.
        ///
        /// The default xtd::collections::generic::list::operator [] is used to retrieve an item, the xtd::collections::generic::list::remove method is used to remove the first instance of the duplicate item added earlier, and the contents are displayed again. The xtd::collections::generic::list::remove method always removes the first instance it encounters.
        ///
        /// The xtd::collections::generic::list::trim_excess method is used to reduce the capacity to match the count, and the xtd::collections::generic::list::capacity and xtd::collections::generic::list::count properties are displayed. If the unused capacity had been less than 10 percent of total capacity, the list would not have been resized.
        ///
        /// Finally, the xtd::collections::generic::list::clear method is used to remove all items from the list, and the xtd::collections::generic::list::capacity and xtd::collections::generic::list::count properties are displayed.
        /// @include generic_list2.cpp
        /// @remarks xtd::collections::generic::list::capacity is the number of elements that the xtd::collections::generic::list <type_t> can store before resizing is required, whereas xtd::collections::generic::list::count is the number of elements that are actually in the xtd::collections::generic::list <type_t>.
        /// @remarks xtd::collections::generic::list::capacity is always greater than or equal to xtd::collections::generic::list::count. If xtd::collections::generic::list::count exceeds xtd::collections::generic::list::capacity while adding elements, the capacity is increased by automatically reallocating the internal array before copying the old elements and adding the new elements.
        /// @remarks If the capacity is significantly larger than the count and you want to reduce the memory used by the xtd::collections::generic::list <type_t>, you can decrease capacity by calling the xtd::collections::generic::list::trim_excess method or by setting the xtd::collections::generic::list::capacity property explicitly to a lower value. When the value of xtd::collections::generic::list::capacity is set explicitly, the internal array is also reallocated to accommodate the specified capacity, and all the elements are copied.
        /// @remarks Retrieving the value of this property is an O(1) operation; setting the property is an O(n) operation, where n is the new capacity.
        xtd::size count() const noexcept override {return items_.size();}
        
        /// @brief Returns a reverse iterator to the first element of the reversed vector. It corresponds to the last element of the non-reversed vector. If the vector is empty, the returned iterator is equal to xtd::collections::generic::list::rend().
        /// @return Reverse iterator to the first element.
        /// @remarks If the vector is empty, the returned iterator will be equal to xtd::collections::generic::list::rend().
        const_reverse_iterator crbegin() const noexcept {return items_.crbegin();}
        
        /// @brief Returns a reverse iterator to the element following the last element of the reversed vector. It corresponds to the element preceding the first element of the non-reversed vector. This element acts as a placeholder, attempting to access it results in undefined behavior.
        /// @return Reverse iterator to the element following the last element.
        /// @remarks This element acts as a placeholder; attempting to access it results in undefined behavior.
        const_reverse_iterator crend() const noexcept {return items_.crend();}

        /// @brief Checks if the container has no elements, i.e. whether xtd::collections::generic::list::begin() == xtd::collections::generic::list::end().
        /// @return true if the container is empty, false otherwise.
        virtual bool empty() const noexcept {return items_.empty();}

        /// @brief Returns an iterator to the element following the last element of the enumarable.
        /// @return Iterator to the element following the last element.
        const_iterator end() const noexcept override {return ienumerable<value_type>::end();}
        /// @brief Returns an iterator to the element following the last element of the enumarable.
        /// @return Iterator to the element following the last element.
        iterator end() noexcept override {return ienumerable<value_type>::end();}

        /// @brief Returns pointer to the underlying array serving as element storage.
        /// @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to the address of the first element.
        /// @remarks The pointer is such that range [xtd::collections::generic::list::data(), xtd::collections::generic::list::data() + xtd::collections::generic::list::size()) is always a valid range, even if the container is empty (xtd::collections::generic::list::data() is not dereferenceable in that case).
        virtual pointer data() noexcept {return (pointer)items_.data();}
        /// @brief Returns pointer to the underlying array serving as element storage.
        /// @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to the address of the first element.
        /// @remarks The pointer is such that range [xtd::collections::generic::list::data(), xtd::collections::generic::list::data() + xtd::collections::generic::list::size()) is always a valid range, even if the container is empty (xtd::collections::generic::list::data() is not dereferenceable in that case).
        virtual const_pointer data() const noexcept {return (const_pointer)items_.data();}
        
        /// @brief Returns a reference to the first element in the container.
        /// @return Reference to the first element.
        /// @remarks Calling front on an empty container causes undefined behavior.
        virtual reference front() {return (*this)[0];}
        /// @brief Returns a reference to the first element in the container.
        /// @return Reference to the first element.
        /// @remarks Calling front on an empty container causes undefined behavior.
        virtual const_reference front() const {return (*this)[0];}
        
        bool is_fixed_size() const noexcept override {return false;}
        bool is_read_only() const noexcept override {return false;}
        bool is_synchronized() const noexcept override {return false;}
        
        /// @brief Returns the maximum number of elements the container is able to hold due to system or library implementation limitations, i.e. std::distance(xtd::collections::generic::list::begin(), xtd::collections::generic::list::end()) for the largest container.
        /// @return Maximum number of elements.
        virtual size_type max_size() const noexcept {return items_.max_size();}
        
        /// @brief Returns a reverse iterator to the first element of the reversed vector. It corresponds to the last element of the non-reversed vector. If the vector is empty, the returned iterator is equal to xtd::collections::generic::list::rend().
        /// @return Reverse iterator to the first element.
        /// @remarks If the vector is empty, the returned iterator will be equal to xtd::collections::generic::list::rend().
        reverse_iterator rbegin() noexcept {return items_.rbegin();}
        /// @brief Returns a reverse iterator to the first element of the reversed vector. It corresponds to the last element of the non-reversed vector. If the vector is empty, the returned iterator is equal to xtd::collections::generic::list::rend().
        /// @return Reverse iterator to the first element.
        /// @remarks If the vector is empty, the returned iterator will be equal to xtd::collections::generic::list::rend().
        const_reverse_iterator rbegin() const noexcept {return items_.rbegin();}
        
        /// @brief Returns a reverse iterator to the element following the last element of the reversed vector. It corresponds to the element preceding the first element of the non-reversed vector. This element acts as a placeholder, attempting to access it results in undefined behavior.
        /// @return Reverse iterator to the element following the last element.
        /// @remarks This element acts as a placeholder; attempting to access it results in undefined behavior.
        reverse_iterator rend() noexcept {return items_.rend();}
        /// @brief Returns a reverse iterator to the element following the last element of the reversed vector. It corresponds to the element preceding the first element of the non-reversed vector. This element acts as a placeholder, attempting to access it results in undefined behavior.
        /// @return Reverse iterator to the element following the last element.
        /// @remarks This element acts as a placeholder; attempting to access it results in undefined behavior.
        const_reverse_iterator rend() const noexcept {return items_.rend();}

        /// @brief Returns the number of elements in the container, i.e. std::distance(xtd::collections::generic::list::begin(), xtd::collections::generic::list::end()).
        /// @return The number of elements in the container.
        virtual size_type size() const noexcept {return items_.size();}

        const xtd::object& sync_root() const noexcept override {return sync_root_;}
        /// @}
        
        /// @name Public Methods
        
        /// @{
        void add(const type_t& item) override {items_.push_back(item);}
        
        /// @brief Replaces the contents with count copies of value value.
        /// @param count The new size of the container.
        /// @param value The value to initialize elements of the container with.
        void assign(size_type count, const type_t& value) {
          ++version_;
          items_.assign(count, value);
        }
        
        /// @brief Replaces the contents with copies of those in the range [first, last).
        /// @param first The first iterator the range to copy the elements from.
        /// @param last The last iterator the range to copy the elements from.
        /// @warning The behavior is undefined if either argument is an iterator this current instance.
        template<typename input_iterator_t>
        void assign(input_iterator_t first, input_iterator_t last) {
          ++version_;
          items_.assign(first, last);
        }
        
        /// @brief Replaces the contents with the elements from the initializer list items_.
        /// @param items the initializer list to copy the values from.
        virtual void assign(std::initializer_list<type_t> items) {
          ++version_;
          clear();
          for (auto item : items)
            items_.push_back(item);
        }
        
        /// @brief Returns a reference to the element at specified location pos, with bounds checking.
        /// @param index The position of the element to return.
        /// @return Reference to the requested element.
        /// @exception std::out_of_range If pos is not within the range of the container.
        virtual reference at(size_type index) {
          if (index >= count()) throw argument_out_of_range_exception {csf_};
          return (reference)items_.at(index);
        }
        /// @brief Returns a reference to the element at specified location pos, with bounds checking.
        /// @param index The position of the element to return.
        /// @return Reference to the requested element.
        /// @exception std::out_of_range If pos is not within the range of the container.
        virtual const_reference at(size_type index) const {
          if (index >= count()) throw argument_out_of_range_exception {csf_};
          thread_local auto item = value_type {};
          item = static_cast<value_type>(items_.at(index));
          return item;
        }
        
        void clear() override {
          ++version_;
          items_.clear();
        }
        
        bool contains(const type_t& value) const noexcept override {
          for (const type_t& item : items_)
            if (item == value) return true;
          return false;
        }

        /// @brief Copies the entire xtd::collections::generic::list <type_t> to a compatible one-dimensional array.
        /// @param array The one-dimensional Array that is the destination of the elements copied from ICollection. The Array must have zero-based indexing.
        /// @exception ArgumentNullException array is null.
        /// @exception ArgumentException The number of elements in the source xtd::collections::generic::list <type_t> is greater than the number of elements that the destination array can contain.
        /// @remarks TThis method uses Array.Copy to copy the elements.
        /// @remarks The elements are copied to the Array in the same order in which the enumerator iterates through the xtd::collections::generic::list <type_t>.
        /// @remarks This method is an O(n) operation, where n is Count.
        /// @par Examples
        /// The following code example demonstrates all three overloads of the CopyTo method. A xtd::collections::generic::list <type_t> of strings is created and populated with 5 strings. An empty string array of 15 elements is created, and the CopyTo(T[]) method overload is used to copy all the elements of the list to the array beginning at the first element of the array. The CopyTo(T[], Int32) method overload is used to copy all the elements of the list to the array beginning at array index 6 (leaving index 5 empty). Finally, the CopyTo(Int32, T[], Int32, Int32) method overload is used to copy 3 elements from the list, beginning with index 2, to the array beginning at array index 12 (leaving index 11 empty). The contents of the array are then displayed.
        /// @include ListCopyTo.cpp
        virtual void copy_to(xtd::array<type_t>& array) const {copy_to(0, array, 0, count());}

        void copy_to(xtd::array<type_t>& array, xtd::size array_index) const override {copy_to(0, array, array_index, count());}
  
        /// @brief Copies the entire xtd::collections::generic::list <type_t> to a compatible one-dimensional array, starting at the specified index of the target array.
        /// @param index The zero-based index in the source xtd::collections::generic::list <type_t> at which copying begins.
        /// @param array The one-dimensional Array that is the destination of the elements copied from ICollection. The Array must have zero-based indexing.
        /// @param arrayIndex The zero-based index in array at which copying begins;
        /// @param count The number of elements to copy.
        /// @exception ArgumentNullException array is null.
        /// @exception ArgumentOutOfRangeException The arrayIndex or count is less than 0.
        /// @exception ArgumentException The number of elements in the source xtd::collections::generic::list <type_t> is greater than the number of elements that the destination array can contain.
        /// @remarks TThis method uses Array.Copy to copy the elements.
        /// @remarks The elements are copied to the Array in the same order in which the enumerator iterates through the xtd::collections::generic::list <type_t>.
        /// @remarks This method is an O(n) operation, where n is Count.
        /// @par Examples
        /// The following code example demonstrates all three overloads of the CopyTo method. A xtd::collections::generic::list <type_t> of strings is created and populated with 5 strings. An empty string array of 15 elements is created, and the CopyTo(T[]) method overload is used to copy all the elements of the list to the array beginning at the first element of the array. The CopyTo(T[], Int32) method overload is used to copy all the elements of the list to the array beginning at array index 6 (leaving index 5 empty). Finally, the CopyTo(Int32, T[], Int32, Int32) method overload is used to copy 3 elements from the list, beginning with index 2, to the array beginning at array index 12 (leaving index 11 empty). The contents of the array are then displayed.
        /// @include ListCopyTo.cpp
        virtual void copy_to(xtd::size index, xtd::array<type_t>& array, xtd::size array_index, xtd::size count) const {
          if (index + count > this->count() || array_index + count > array.size()) throw xtd::argument_exception {csf_};
          auto i = 0_z, c = 0_z;
          for (const type_t& item : *this) {
            if (i >= index + count) return;
            if (i >= index) {
              array[array_index + c] = item;
              c += 1;
            }
            i += 1;
          }
        }

        /// @brief Inserts a new element into the container directly before `pos`.
        /// @param pos The iterator before which the new element will be constructed.
        /// @param args arguments to forward to the constructor of the element.
        /// @remarks The element is constructed through [std::allocator_traits::construct](https://en.cppreference.com/w/cpp/memory/allocator_traits/construct), which typically uses placement-new to construct the element in-place at a location provided by the container. However, if the required location has been occupied by an existing element, the inserted element is constructed at another location at first, and then move assigned into the required location.
        /// @remarks The arguments `args...` are forwarded to the constructor as `std::forward<args_t>(args)....` `args...` may directly or indirectly refer to a value in the container.
        /// @remarks If after the operation the new xtd::collections::generic::list::size() is greater than old xtd::collections::generic::list::capacity() a reallocation takes place, in which case all iterators (including the xtd::collections::generic::list::end() iterator) and all references to the elements are invalidated. Otherwise, only the iterators and references before the insertion point remain valid.
        template<typename... args_t>
        iterator emplace(const_iterator pos, args_t&&... args) {
          ++version_;
          return items_.eplace(std::forward<args_t>(args)...);
        }
        
        /// @brief Appends a new element to the end of the container. The element is constructed through [std::allocator_traits::construct](https://en.cppreference.com/w/cpp/memory/allocator_traits/construct), which typically uses placement-new to construct the element in-place at the location provided by the container. The arguments `args...` are forwarded to the constructor as `std::forward<Args>(args)...`.
        /// @param args The arguments to forward to the constructor of the element.
        /// @return A reference to the inserted element.
        /// @remarks If after the operation the new xtd::collections::generic::list::size() is greater than old xtd::collections::generic::list::capacity() a reallocation takes place, in which case all iterators (including the xtd::collections::generic::list::end() iterator) and all references to the elements are invalidated. Otherwise only the xtd::collections::generic::list::end() iterator is invalidated.
        template<typename... args_t>
        reference emplace_back(args_t&&... args) {
          ++version_;
          return items_.emplace_back(std::forward<args_t>(args)...);
        }
        
        bool equals(const object& obj) const noexcept override {return is<list<value_type>>(obj) && equals(static_cast<const list<value_type>&>(obj));}
        bool equals(const list& rhs) const noexcept override {return items_ == rhs.items_ && version_ == rhs.version_;}

        /// @brief Erases the specified elements from the container.
        /// @param pos The iterator to the element to remove.
        /// @return Iterator following the last removed element.
        /// @remarks Removes the element at `pos`.
        /// @remarks Iterators (including the xtd::collections::generic::list::end() iterator) and references to the elements at or after the point of the erase are invalidated.
        /// @remarks The iterator `pos` must be valid and dereferenceable. Thus the xtd::collections::generic::list::end() iterator (which is valid, but is not dereferenceable) cannot be used as a value for `pos.
        /// @remarks If `pos` refers to the last element, then thextd::collections::generic::list:: end() iterator is returned.
        virtual iterator erase(const_iterator pos) {
          ++version_;
          return to_iterator(items_.erase(to_base_type_iterator(pos)));
        }
        /// @brief Erases the specified elements from the container.
        /// @param pos The iterator to the element to remove.
        /// @return Iterator following the last removed element.
        /// @remarks Removes the elements in the range [`first`, `last`).
        /// @remarks Iterators (including the xtd::collections::generic::list::end() iterator) and references to the elements at or after the point of the erase are invalidated.
        /// @remarks The iterator `first` does not need to be dereferenceable if `first == last`: erasing an empty range is a no-op.
        /// @remarks If `last == end()` prior to removal, then the updated xtd::collections::generic::list::end() iterator is returned.
        /// @remarks If [`first`, `last`) is an empty range, then `last` is returned.
        virtual iterator erase(const_iterator first, const_iterator last) {
          ++version_;
          return to_iterator(items_.erase(to_base_type_iterator(first), to_base_type_iterator(last)));
        }
        
        /// @brief Returns the allocator associated with the container.
        /// @return The associated allocator.
        virtual allocator_type get_allocator() const {return items_.get_allocator();}
        
        /// @brief Returns the underlying base type.
        /// @return The underlying base type.
        /// @warning Don't manipulate the xtd::collections::generic::list::base_type yourself, otherwise the expected result may be undefined.
        virtual base_type& get_base_type() noexcept {return items_;}
        /// @brief Returns the underlying base type.
        /// @return The underlying base type.
        virtual const base_type& get_base_type() const noexcept {return items_;}

        enumerator<value_type> get_enumerator() const noexcept override {
          class list_enumerator : public ienumerator<value_type> {
          public:
            explicit list_enumerator(const list& items, xtd::int64 version) : items_(items), version_(version) {}
            const value_type& current() const override {
              if (version_ != items_.version_) throw xtd::invalid_operation_exception {"Collection was modified; enumeration operation may not execute.", csf_};
              thread_local auto item = value_type {};
              item = static_cast<value_type>(items_[index_]);
              return item;
            }
            bool move_next() override {
              if (version_ != items_.version_) throw xtd::invalid_operation_exception {"Collection was modified; enumeration operation may not execute.", csf_};
              return ++index_ < items_.count();
            }
            void reset() override {index_ = xtd::box_integer<xtd::size>::max_value;}
            
          protected:
            const list& items_;
            xtd::size index_ = xtd::box_integer<xtd::size>::max_value;
            xtd::int64 version_ = 0;
          };
          return {new_ptr<list_enumerator>(*this, version_)};
        }
        
        /// @brief Determines the index of a specific item in the List.xtd::collections::generic::list <type_t>.
        /// @param value The object to locate in the List.
        /// @return The index of value if found in the list; otherwise, xtd::collections::generic::ilist::npos.
        xtd::size index_of(const type_t& value) const noexcept override {
          if (count() == 0)  return npos;
          return index_of(value, 0, count());
        }

        /// @brief Determines the index of a specific item in the xtd::collections::generic::list <type_t>.
        /// @param value The object to locate in the xtd::collections::generic::list <type_t>.
        /// @param index The zero-based starting index of the search.
        /// @return The index of value if found in the xtd::collections::generic::list; otherwise, xtd::collections::generic::ilist::npos.
        /// @exception xtd::argument_out_of_range_exception `index` is outside the range of valid indexes for the xtd::collections::generic::list <type_t>.
        virtual xtd::size index_of(const type_t& value, xtd::size index) const {return index_of(value, index, count() - index);}
        
        /// @brief Determines the index of a specific item in the xtd::collections::generic::list <type_t>.
        /// @param value The object to locate in the xtd::collections::generic::list <type_t>.
        /// @param index The zero-based starting index of the search.
        /// @param count The number of elements in the section to search
        /// @return The index of value if found in the xtd::collections::generic::list; otherwise, xtd::collections::generic::ilist::npos.
        /// @exception xtd::argument_out_of_range_exception `index` and `countù  do not specify a valid section in the xtd::collections::generic::list <type_t>.
        virtual xtd::size index_of(const type_t& value, xtd::size index, xtd::size count) const {
          if (index >= this->count()) throw xtd::argument_out_of_range_exception {csf_};
          if (index + count > this->count()) throw xtd::argument_out_of_range_exception {csf_};

          for (auto i = index; i < index + count; ++i)
            if (items_[i] == value) return i;
          return npos;
        }

        /// @brief Inserts elements at the specified location in the container.
        /// @param pos the iterator before which the content will be inserted (pos may be the end() iterator).
        /// @param value The element value to insert.
        /// @return The iterator pointing to the inserted `value`.
        /// @remarks Inserts `value` before pos.
        /// @remarks If after the operation the new xtd::collections::generic::list::size() is greater than old xtd::collections::generic::list::capacity() a reallocation takes place, in which case all iterators (including the xtd::collections::generic::list::end() iterator) and all references to the elements are invalidated. Otherwise, only the iterators and references before the insertion point remain valid.
        virtual iterator insert(const_iterator pos, const type_t& value) {
          ++version_;
          return to_iterator(items_.insert(to_base_type_iterator(pos), value));
        }
        /// @brief Inserts elements at the specified location in the container.
        /// @param pos the iterator before which the content will be inserted (pos may be the end() iterator).
        /// @param value The element value to insert.
        /// @return The iterator pointing to the inserted `value`.
        /// @remarks Inserts `value` before pos.
        /// @remarks If after the operation the new xtd::collections::generic::list::size() is greater than old xtd::collections::generic::list::capacity() a reallocation takes place, in which case all iterators (including the xtd::collections::generic::list::end() iterator) and all references to the elements are invalidated. Otherwise, only the iterators and references before the insertion point remain valid.
        virtual iterator insert(const_iterator pos, const type_t&& value) {
          ++version_;
          return to_iterator(items_.insert(to_base_type_iterator(pos), value));
        }
        /// @brief Inserts elements at the specified location in the container.
        /// @param pos the iterator before which the content will be inserted (pos may be the end() iterator).
        /// @param count The number of elements to insert.
        /// @param value The element value to insert.
        /// @return The iterator pointing to the first element inserted, or `pos` if `count == 0`.
        /// @remarks Iterator pointing to the first element inserted, or `pos` if `count == 0`.
        /// @remarks If after the operation the new xtd::collections::generic::list::size() is greater than old xtd::collections::generic::list::capacity() a reallocation takes place, in which case all iterators (including the xtd::collections::generic::list::end() iterator) and all references to the elements are invalidated. Otherwise, only the iterators and references before the insertion point remain valid.
        virtual iterator insert(const_iterator pos, size_type count, const type_t& value) {
          ++version_;
          return to_iterator(items_.insert(to_base_type_iterator(pos), count, value));
        }
        /// @brief Inserts elements at the specified location in the container.
        /// @param first The first range of elements to insert, cannot be iterators into container for which insert is called
        /// @param last The last range of elements to insert, cannot be iterators into container for which insert is called
        /// @return The iterator pointing to the first element inserted, or `pos` if `first == last`.
        /// @remarks Inserts elements from range [`first`, `last`) before `pos`.
        /// @remarks If `first` and `last` are iterators into `*this`, the behavior is undefined.
        /// @remarks If after the operation the new xtd::collections::generic::list::size() is greater than old xtd::collections::generic::list::capacity() a reallocation takes place, in which case all iterators (including the xtd::collections::generic::list::end() iterator) and all references to the elements are invalidated. Otherwise, only the iterators and references before the insertion point remain valid.
        template<typename input_iterator_t>
        iterator insert(const_iterator pos, input_iterator_t first, input_iterator_t last) {
          ++version_;
          return items_.insert(pos, first, last);
        }
        /// @brief Inserts elements at the specified location in the container.
        /// @param pos the iterator before which the content will be inserted (pos may be the end() iterator).
        /// @param items The initializer list to insert the values from.
        /// @return The iterator pointing to the first element inserted, or `pos` if `items` is empty.
        /// @remarks Inserts `value` before pos.
        /// @remarks Inserts elements from initializer list `items` before `pos`.
        virtual iterator insert(const_iterator pos, const std::initializer_list<type_t>& items) {
          ++version_;
          auto result = iterator {};
          auto base_pos = to_base_type_iterator(pos);
          for (auto item : items)
            result = to_iterator(items_.insert(base_pos++, item));
          return result;
        }
        
        /// @brief Inserts an element into the xtd::collections::generic::list <type_t> at the specified index.
        /// @param index The zero-based index at which the new element should be inserted.
        /// @param value The element should be inserted into the xtd::collections::generic::list <type_t>.
        /// @exception xtd::argument_out_of_range_exception index is is greater than xtd::collections::generic::list::count.
        /// @remarks xtd::collections::generic::list <type_t> allows duplicate elements.
        void insert(xtd::size index, const type_t& value) override {
          ++version_;
          if (index >= count()) throw xtd::argument_out_of_range_exception {csf_};
          items_.insert(items_.begin() + index, value);
        }

        /// @brief Removes the last element of the container.
        /// @remarks Calling pop_back on an empty container results in undefined behavior.
        /// @remarks Iterators (including the xtd::collections::generic::list::end() iterator) and references to the last element are invalidated.
        virtual void pop_back() {
          ++version_;
          items_.pop_back();
        }
        
        /// @brief Appends the given element value to the end of the container.
        /// @param value The value of the element to append.
        /// @remarks If after the operation the new xtd::collections::generic::list::size() is greater than old xtd::collections::generic::list::capacity() a reallocation takes place, in which case all iterators (including the xtd::collections::generic::list::end() iterator) and all references to the elements are invalidated. Otherwise only the xtd::collections::generic::list::end() iterator is invalidated.
        /// @remarks The new element is initialized as a copy of `value`.
        virtual void push_back(const type_t& value) {
          ++version_;
          items_.push_back(value);
        }
        /// @brief Appends the given element value to the end of the container.
        /// @param value The value of the element to append.
        /// @remarks If after the operation the new xtd::collections::generic::list::size() is greater than old xtd::collections::generic::list::capacity() a reallocation takes place, in which case all iterators (including the xtd::collections::generic::list::end() iterator) and all references to the elements are invalidated. Otherwise only the xtd::collections::generic::list::end() iterator is invalidated.
        /// @remarks `value` is moved into the new element.
        virtual void push_back(type_t&& value) {
          ++version_;
          items_.push_back(value);
        }
        
        bool remove(const type_t& item) override {
          if (count() == 0)  return false;
          for (typename base_type::iterator it = items_.begin(); it != items_.end() ; it++) {
            if (*it == item) {
              items_.erase(it);
              return true;
            }
          }
          return false;
        }
        
        /// @brief Removes the element at the specified index of the xtd::collections::generic::list <type_t>.
        /// @param index The zero-based index of the item to remove
        /// @return None.
        /// @exception ArgumentOutOfRangeException index is less than 0 or index is greater than Count.
        void remove_at(xtd::size index) override {
          if (index > count()) throw xtd::argument_out_of_range_exception {csf_};

          ++version_;
          if (index == count() - 1) pop_back();
          else items_.erase(items_.begin() + index);
        }

        /// @brief Resizes the container to contain `count` elements, does nothing if `count == size().
        /// @param count The new size of the container.
        /// @remarks If the current size is greater than `count`, the container is reduced to its first `count` elements.
        /// @remarks If the current size is less than `count`, additional default-inserted elements are appended.
        virtual void resize(size_type count) {
          ++version_;
          items_.resize(count);
        }
        /// @brief Resizes the container to contain `count` elements, does nothing if `count == size().
        /// @param count The new size of the container.
        /// @param value The value to initialize the new elements with.
        /// @remarks If the current size is greater than `count`, the container is reduced to its first `count` elements.
        /// @remarks If the current size is less than `count`, additional copies of `value` are appended.
        virtual void resize(size_type count, const value_type& value) {
          ++version_;
          items_.resize(count, value);
        }

        /// @brief Requests the removal of unused capacity.
        /// @remarks It is a non-binding request to reduce xtd::collections::generic::list::capacity() to xtd::collections::generic::list::size(). It depends on the implementation whether the request is fulfilled.
        /// @remarks If reallocation occurs, all iterators (including the xtd::collections::generic::list::end() iterator) and all references to the elements are invalidated. If no reallocation occurs, no iterators or references are invalidated.
        virtual void shrink_to_fit() {items_.shrink_to_fit();}

        /// @brief Exchanges the contents and capacity of the container with those of other. Does not invoke any move, copy, or swap operations on individual elements.
        /// @remarks All iterators and references remain valid. The xtd::collections::generic::list::end() iterator is invalidated.
        virtual void swap(list& other) noexcept {
          ++version_;
          items_.swap(other.items_);
        }

        ustring to_string() const noexcept override {return xtd::ustring::format("[{}]", xtd::ustring::join(", ", *this));}
        
        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlyong base type.
        virtual const base_type& to_base_type() const noexcept {return items_;}
        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlyong base type.
        virtual base_type& to_base_type() noexcept {return items_;}
        
        /// @brief Sets the capacity to the actual number of elements in the List<T>, if that number is less than a threshold value.
        /// @par Examples
        /// The following example demonstrates how to add, remove, and insert a simple business object in a xtd::collections::generic::list <type_t>.
        /// @include generic_list.cpp
        /// The following example demonstrates several properties and methods of the xtd::collections::generic::list <type_t> generic class of type string. (For an example of a xtd::collections::generic::list <type_t> of complex types, see the xtd::collections::generic::list::contains method.)
        ///
        /// The parameterless constructor is used to create a list of strings with the default capacity. The xtd::collections::generic::list::capacity property is displayed and then the xtd::collections::generic::list::add method is used to add several items. The items are listed, and the xtd::collections::generic::list::capacity property is displayed again, along with the xtd::collections::generic::list::count property, to show that the capacity has been increased as needed.
        ///
        /// The xtd::collections::generic::list::contains method is used to test for the presence of an item in the list, the Insert method is used to insert a new item in the middle of the list, and the contents of the list are displayed again.
        ///
        /// The default xtd::collections::generic::list::operator [] is used to retrieve an item, the xtd::collections::generic::list::remove method is used to remove the first instance of the duplicate item added earlier, and the contents are displayed again. The xtd::collections::generic::list::remove method always removes the first instance it encounters.
        ///
        /// The xtd::collections::generic::list::trim_excess method is used to reduce the capacity to match the count, and the xtd::collections::generic::list::capacity and xtd::collections::generic::list::count properties are displayed. If the unused capacity had been less than 10 percent of total capacity, the list would not have been resized.
        ///
        /// Finally, the xtd::collections::generic::list::clear method is used to remove all items from the list, and the xtd::collections::generic::list::capacity and xtd::collections::generic::list::count properties are displayed.
        /// @include generic_list2.cpp
        /// @remarks This method can be used to minimize a collection's memory overhead if no new elements will be added to the collection. The cost of reallocating and copying a large xtd::collections::generic::list <type_t> can be considerable, however, so the xtd::collections::generic::list::trim_excess method does nothing if the list is at more than 90 percent of capacity. This avoids incurring a large reallocation cost for a relatively small gain.
        /// @remarks This method is an O(n) operation, where n is xtd::collections::generic::list::count.
        /// @remarks To reset a xtd::collections::generic::list <type_t> to its initial state, call the xtd::collections::generic::list::clear method before calling the xtd::collections::generic::list::trim_excess method. Trimming an empty xtd::collections::generic::list <type_t> sets the capacity of the xtd::collections::generic::list <type_t> to the default capacity.
        /// @remarks The capacity can also be set using the xtd::collections::generic::list::capacity property.
        virtual void trim_excess() {items_.shrink_to_fit();}
        /// @}
        
        /// @name Public Operators
        
        /// @{
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of other.
        /// @param other Another container to use as data source.
        /// @return This current instance.
        list& operator =(const list& other) = default;
        /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in other is moved from other into this container). other is in a valid but unspecified state afterwards.
        /// @param other Another base type container to use as data source.
        /// @return This current instance.
        list& operator =(const list&& other) noexcept {
          version_ = std::move(other.version_);
          items_ = std::move(other.items_);
          return *this;
        }
        /// @brief Replaces the contents with those identified by initializer list ilist.
        /// @param items Initializer list to use as data source
        /// @return This current instance.
        list& operator =(std::initializer_list<type_t>& items) {
          version_ = 0;
          items_ = items;
          return *this;
        }

        /// @brief Returns a reference to the element at specified location pos.
        /// @param index The position of the element to return.
        /// @return Reference to the requested element.
        ///@remarks  No bounds checking is performed.
        const_reference operator [](size_type index) const override {
          if (index >= count()) throw argument_out_of_range_exception {csf_};
          thread_local auto item = value_type {};
          item = static_cast<value_type>(items_[index]);
          return item;
        }
        /// @brief Returns a reference to the element at specified location pos.
        /// @param index The position of the element to return.
        /// @return Reference to the requested element.
        ///@remarks  No bounds checking is performed.
        reference operator [](size_type index) override {
          if (index >= count()) throw argument_out_of_range_exception {csf_};
          return (reference)items_[index];
        }

        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlyong base type.
        virtual operator const base_type&() const noexcept {return items_;}
        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlyong base type.
        virtual operator base_type&() noexcept {return items_;}
        /// @}
        
      private:
        base_type::iterator to_base_type_iterator(iterator value) noexcept {return items_.begin() + (value - begin());}
        iterator to_iterator(base_type::iterator value) noexcept {return begin() + (value - items_.begin());}
        
        base_type items_;
        xtd::int64 version_ = 0;
        xtd::object sync_root_;
      };
    }
    
  }
}
