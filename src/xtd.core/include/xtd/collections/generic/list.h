/// @file
/// @brief Contains xtd::collections::generic::list struct.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "helpers/allocator.h"
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
      /// class list : public xtd::object, xtd::collections::generic::icollection<type_t>, xtd::collections::generic::ienumerable<type_t>, xtd::collections::generic::ilist<type_t>
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
      /// @remarks The xtd::collections::generic::list class instanciate as xtd::collections::generic::list::base_type a [std::vector](https://en.cppreference.com/w/cpp/container/vector) with xtd::collections::generic::helpers::allocator instead [std::allocator](https://en.cppreference.com/w/cpp/memory/allocator).
      template<typename type_t>
      class list : public object /*, icollection<type_t>*/ /*, ienumerable<type_t>*/ /*, ilist<type_t>*/ {
      public:
        /// @name Public Alias
        
        /// @{
        /// @brief Represents the list value type.
        using value_type = type_t;
        /// @brief Represents the list allocator type.
        using allocator_type = helpers::allocator<value_type>;
        /// @brief Represents the list base type.
        using base_type = std::vector<value_type, allocator_type>;
        /// @brief Represents the list size type (usually xtd::size).
        using size_type = base_type::size_type;
        /// @brief Represents the list difference type (usually xtd::ptrdiff).
        using difference_type = base_type::difference_type;
        /// @brief Represents the reference of list value type.
        using reference = base_type::reference;
        /// @brief Represents the const reference of list value type.
        using const_reference = base_type::const_reference;
        /// @brief Represents the pointer of list value type.
        using pointer = base_type::pointer;
        /// @brief Represents the const pointer of list value type.
        using const_pointer = base_type::const_pointer;
        /// @brief Represents the iterator of list value type.
        using iterator = base_type::iterator;
        /// @brief Represents the const iterator of list value type.
        using const_iterator = base_type::const_iterator;
        /// @brief Represents the reverse iterator of list value type.
        using reverse_iterator = base_type::reverse_iterator;
        /// @brief Represents the const reverse iterator of list value type.
        using const_reverse_iterator = base_type::const_reverse_iterator;
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
        
        /// @brief Initializes a new instance of the List<T> class that contains elements copied from the specified collection and has sufficient capacity to accommodate the number of elements copied.
        /// @param collection The collection whose elements are copied to the new list.
        /// @exception ArgumentNullException The parameters collection is null or element reference null in collection.
        /// @remarks The elements are copied onto the List<T> in the same order they are read by the enumerator of the collection.
        /// @remarks This constructor is an O(n) operation, where n is the number of elements in collection.
        /// @par Examples
        /// The following code example demonstrates the List<T> constructor and various methods of the List<T> class that act on ranges. An array of strings is created and passed to the constructor, populating the list with the elements of the array. The Capacity property is then displayed, to show that the initial capacity is exactly what is required to hold the input elements.
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
        explicit list(const allocator_type& alloc) noexcept : items_{alloc} {}
        /// @brief Constructs the container with specified count copies of elements with specified value.
        /// @param count The size of the container.
        /// @param value The value to initialize elements of the container with.
        /// @param alloc The allocator to use for all memory allocations of this container.
        list(size_type count, const type_t& value, const allocator_type& alloc = allocator_type()) : items_{count, value, alloc} {}
        /// @brief Constructs the container with specified count default-inserted instances of type_t. No copies are made.
        /// @param count The size of the container.
        /// @param alloc The allocator to use for all memory allocations of this container.
        explicit list(size_type count, const allocator_type& alloc = allocator_type()) : items_{count, alloc} {}
        /// @brief Constructs the container with the contents of the range [first, last).
        /// @param first The first iterator the range to copy the elements from.
        /// @param last The last iterator the range to copy the elements from.
        /// @param alloc The allocator to use for all memory allocations of this container.
        template<typename input_iterator_t>
        list(input_iterator_t first, input_iterator_t last, const allocator_type& alloc = allocator_type()) : items_{first, last, alloc} {}
        
        /// @brief Default copy constructor with specified list.
        /// @param list The xtd::collections::generic::list which elements will be inserted from.
        list(const list& list) = default;
        /// @brief Copy constructor with specified base type list.
        /// @param list The xtd::collections::generic::list::base_type which elements will be inserted from.
        list(const base_type& list) : items_{list} {}
        /// @brief Default copy constructor with specified list, and allocator.
        /// @param list The xtd::collections::generic::list which elements will be inserted from.
        /// @param alloc The allocator to use for all memory allocations of this container.
        list(const list& list, const allocator_type& alloc) : items_{list.items_, alloc} {}
        /// @brief Default copy constructor with specified base type list, and allocator.
        /// @param list The xtd::collections::generic::list which elements will be inserted from.
        /// @param alloc The allocator to use for all memory allocations of this container.
        list(const base_type& list, const allocator_type& alloc) : items_{list, alloc} {}
        /// @brief Constructs the container with the contents of the specified initializer list, and allocator.
        /// @param items The initializer list to initialize the elements of the container with.
        /// @param alloc The allocator to use for all memory allocations of this container.
        list(std::initializer_list<type_t> items, const allocator_type& alloc = allocator_type()) : items_{items_, alloc} {}
        
        /// @brief Move constructor with specified list.
        /// @param list The xtd::collections::generic::list::base_type which elements will be moved from.
        list(list&& other) = default;
        /// @brief Move constructor with specified base type list.
        /// @param list The xtd::collections::generic::list::base_type which elements will be moved from.
        list(base_type&& other) : items_(other) {}
        /// @brief Move constructor with specified list, and allocator.
        /// @param list The xtd::collections::generic::list::base_type which elements will be moved from.
        /// @param alloc The allocator to use for all memory allocations of this container.
        list(list&& other, const allocator_type& alloc) : items_{other.items_, alloc}, operation_number_{std::move(other.operation_number_)} {}
        /// @brief Move constructor with specified base tyoe list, and allocator.
        /// @param list The xtd::collections::generic::list::base_type which elements will be moved from.
        /// @param alloc The allocator to use for all memory allocations of this container.
        list(base_type&& other, const allocator_type& alloc) : items_{other, alloc} {}
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Returns a reference to the last element in the container.
        /// @return Reference to the first element.
        /// @remarks Calling front on an empty container causes undefined behavior.
        reference back() {return items_.back();}
        /// @brief Returns a reference to the last element in the container.
        /// @return Reference to the first element.
        /// @remarks Calling front on an empty container causes undefined behavior.
        const_reference back() const {return items_.back();}
        
        /// @brief Returns an iterator to the first element of the vector.
        /// @return Iterator to the first element.
        /// @remarks If the vector is empty, the returned iterator will be equal to xtd::collections::generic::list::end().
        iterator begin() noexcept {return items_.begin();}
        /// @brief Returns an iterator to the first element of the vector.
        /// @return Iterator to the first element.
        /// @remarks If the vector is empty, the returned iterator will be equal to xtd::collections::generic::list::end().
        const_iterator begin() const noexcept {return items_.begin();}
        /// @brief Returns an iterator to the first element of the vector.
        /// @return Iterator to the first element.
        /// @remarks If the vector is empty, the returned iterator will be equal to xtd::collections::generic::list::end().
        const_iterator cbegin() const noexcept {return items_.cbegin();}
        
        /// @brief Returns the number of elements that the container has currently allocated space for.
        /// @return Capacity of the currently allocated storage.
        size_type capacity() const noexcept {return items_.max_size();}
        
        /// @brief Checks if the container has no elements, i.e. whether xtd::collections::generic::list::begin() == xtd::collections::generic::list::end().
        /// @return true if the container is empty, false otherwise.
        bool empty() const noexcept {return items_.empty();}
        
        /// @brief Returns an iterator to the element following the last element of the vector.
        /// @return Iterator to the element following the last element.
        /// @remarks This element acts as a placeholder; attempting to access it results in undefined behavior.
        iterator end() noexcept {return items_.end();}
        /// @brief Returns an iterator to the element following the last element of the vector.
        /// @return Iterator to the element following the last element.
        /// @remarks This element acts as a placeholder; attempting to access it results in undefined behavior.
        const_iterator end() const noexcept {return items_.end();}
        /// @brief Returns an iterator to the element following the last element of the vector.
        /// @return Iterator to the element following the last element.
        /// @remarks This element acts as a placeholder; attempting to access it results in undefined behavior.
        const_iterator cend() const noexcept {return items_.cend();}
        
        /// @brief Returns pointer to the underlying array serving as element storage.
        /// @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to the address of the first element.
        /// @remarks The pointer is such that range [xtd::collections::generic::list::data(), xtd::collections::generic::list::data() + xtd::collections::generic::list::size()) is always a valid range, even if the container is empty (xtd::collections::generic::list::data() is not dereferenceable in that case).
        type_t* data() noexcept {return items_.data();}
        /// @brief Returns pointer to the underlying array serving as element storage.
        /// @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to the address of the first element.
        /// @remarks The pointer is such that range [xtd::collections::generic::list::data(), xtd::collections::generic::list::data() + xtd::collections::generic::list::size()) is always a valid range, even if the container is empty (xtd::collections::generic::list::data() is not dereferenceable in that case).
        const type_t* data() const noexcept {return items_.data();}
        
        /// @brief Returns a reference to the first element in the container.
        /// @return Reference to the first element.
        /// @remarks Calling front on an empty container causes undefined behavior.
        reference front() {return items_.front();}
        /// @brief Returns a reference to the first element in the container.
        /// @return Reference to the first element.
        /// @remarks Calling front on an empty container causes undefined behavior.
        const_reference front() const {return items_.front();}
        
        /// @brief Returns the maximum number of elements the container is able to hold due to system or library implementation limitations, i.e. std::distance(xtd::collections::generic::list::begin(), xtd::collections::generic::list::end()) for the largest container.
        /// @return Maximum number of elements.
        size_type max_size() const noexcept {return items_.max_size();}
        
        /// @brief Requests the removal of unused capacity.
        /// @remarks It is a non-binding request to reduce xtd::collections::generic::list::capacity() to xtd::collections::generic::list::size(). It depends on the implementation whether the request is fulfilled.
        /// @remarks If reallocation occurs, all iterators (including the xtd::collections::generic::list::end() iterator) and all references to the elements are invalidated. If no reallocation occurs, no iterators or references are invalidated.
        void shrink_to_fit() {items_.shrink_to_fit();}
        
        /// @brief Returns the number of elements in the container, i.e. std::distance(xtd::collections::generic::list::begin(), xtd::collections::generic::list::end()).
        /// @return The number of elements in the container.
        size_type size() const noexcept {return items_.size();}
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Replaces the contents with count copies of value value.
        /// @param count The new size of the container.
        /// @param value The value to initialize elements of the container with.
        void assign(size_type count, const type_t& value) {
          ++operation_number_;
          items_.assign(count, value);
        }
        
        /// @brief Replaces the contents with copies of those in the range [first, last).
        /// @param first The first iterator the range to copy the elements from.
        /// @param last The last iterator the range to copy the elements from.
        /// @warning The behavior is undefined if either argument is an iterator this current instance.
        template<typename input_iterator_t>
        void assign(input_iterator_t first, input_iterator_t last) {
          ++operation_number_;
          items_.assign(first, last);
        }
        
        /// @brief Replaces the contents with the elements from the initializer list items_.
        /// @param items the initializer list to copy the values from.
        void assign(std::initializer_list<type_t> items) {
          ++operation_number_;
          items_.assign(items);
        }
        
        /// @brief Returns a reference to the element at specified location pos, with bounds checking.
        /// @param pos The position of the element to return.
        /// @return Reference to the requested element.
        /// @exception std::out_of_range If pos is not within the range of the container.
        reference at(size_type pos) {return items_.at(pos);}
        /// @brief Returns a reference to the element at specified location pos, with bounds checking.
        /// @param pos The position of the element to return.
        /// @return Reference to the requested element.
        /// @exception std::out_of_range If pos is not within the range of the container.
        const_reference at(size_type pos) const {return items_.at(pos);}
        
        /// @brief Erases all elements from the container. After this call, xtd::collections::generic::list::size() returns zero.
        /// @remarks Invalidates any references, pointers, and iterators referring to contained elements. Any past-the-end iterators are also invalidated.
        /// @remarks Leaves the xtd::collections::generic::list::capacity() of the vector unchanged (Note: the standard's restriction on the changes to capacity is in the specification of xtd::collections::generic::list::reserve(), see [SO](https://stackoverflow.com/a/18467916)).
        void clear() {
          ++operation_number_;
          items_.clear();
        }
        
        /// @brief Inserts a new element into the container directly before `pos`.
        /// @param pos The iterator before which the new element will be constructed.
        /// @param args arguments to forward to the constructor of the element.
        /// @remarks The element is constructed through [std::allocator_traits::construct](https://en.cppreference.com/w/cpp/memory/allocator_traits/construct), which typically uses placement-new to construct the element in-place at a location provided by the container. However, if the required location has been occupied by an existing element, the inserted element is constructed at another location at first, and then move assigned into the required location.
        /// @remarks The arguments `args...` are forwarded to the constructor as `std::forward<args_t>(args)....` `args...` may directly or indirectly refer to a value in the container.
        /// @remarks If after the operation the new xtd::collections::generic::list::size() is greater than old xtd::collections::generic::list::capacity() a reallocation takes place, in which case all iterators (including the xtd::collections::generic::list::end() iterator) and all references to the elements are invalidated. Otherwise, only the iterators and references before the insertion point remain valid.
        template<typename... args_t>
        iterator emplace(const_iterator pos, args_t&&... args) {
          ++operation_number_;
          return items_.eplace(std::forward<args_t>(args)...);
        }
        
        /// @brief Appends a new element to the end of the container. The element is constructed through [std::allocator_traits::construct](https://en.cppreference.com/w/cpp/memory/allocator_traits/construct), which typically uses placement-new to construct the element in-place at the location provided by the container. The arguments `args...` are forwarded to the constructor as `std::forward<Args>(args)...`.
        /// @param args The arguments to forward to the constructor of the element.
        /// @return A reference to the inserted element.
        /// @remarks If after the operation the new xtd::collections::generic::list::size() is greater than old xtd::collections::generic::list::capacity() a reallocation takes place, in which case all iterators (including the xtd::collections::generic::list::end() iterator) and all references to the elements are invalidated. Otherwise only the xtd::collections::generic::list::end() iterator is invalidated.
        template<typename... args_t>
        reference emplace_back(args_t&&... args) {
          ++operation_number_;
          return items_.emplace_back(std::forward<args_t>(args)...);
        }
        
        /// @brief Erases the specified elements from the container.
        /// @param pos The iterator to the element to remove.
        /// @return Iterator following the last removed element.
        /// @remarks Removes the element at `pos`.
        /// @remarks Iterators (including the xtd::collections::generic::list::end() iterator) and references to the elements at or after the point of the erase are invalidated.
        /// @remarks The iterator `pos` must be valid and dereferenceable. Thus the xtd::collections::generic::list::end() iterator (which is valid, but is not dereferenceable) cannot be used as a value for `pos.
        /// @remarks If `pos` refers to the last element, then thextd::collections::generic::list:: end() iterator is returned.
        iterator erase(const_iterator pos) {
          ++operation_number_;
          return items_.erase(pos);
        }
        /// @brief Erases the specified elements from the container.
        /// @param pos The iterator to the element to remove.
        /// @return Iterator following the last removed element.
        /// @remarks Removes the elements in the range [`first`, `last`).
        /// @remarks Iterators (including the xtd::collections::generic::list::end() iterator) and references to the elements at or after the point of the erase are invalidated.
        /// @remarks The iterator `first` does not need to be dereferenceable if `first == last`: erasing an empty range is a no-op.
        /// @remarks If `last == end()` prior to removal, then the updated xtd::collections::generic::list::end() iterator is returned.
        /// @remarks If [`first`, `last`) is an empty range, then `last` is returned.
        iterator erase(const_iterator first, const_iterator last) {
          ++operation_number_;
          return items_.erase(first, last);
        }
        
        /// @brief Returns the allocator associated with the container.
        /// @return The associated allocator.
        allocator_type get_allocator() const {return items_.get_allocator();}
        
        /// @brief Inserts elements at the specified location in the container.
        /// @param pos the iterator before which the content will be inserted (pos may be the end() iterator).
        /// @param value The element value to insert.
        /// @return The iterator pointing to the inserted `value`.
        /// @remarks Inserts `value` before pos.
        /// @remarks If after the operation the new xtd::collections::generic::list::size() is greater than old xtd::collections::generic::list::capacity() a reallocation takes place, in which case all iterators (including the xtd::collections::generic::list::end() iterator) and all references to the elements are invalidated. Otherwise, only the iterators and references before the insertion point remain valid.
        iterator insert(const_iterator pos, const type_t& value) {
          ++operation_number_;
          return items_.insert(pos, value);
        }
        /// @brief Inserts elements at the specified location in the container.
        /// @param pos the iterator before which the content will be inserted (pos may be the end() iterator).
        /// @param value The element value to insert.
        /// @return The iterator pointing to the inserted `value`.
        /// @remarks Inserts `value` before pos.
        /// @remarks If after the operation the new xtd::collections::generic::list::size() is greater than old xtd::collections::generic::list::capacity() a reallocation takes place, in which case all iterators (including the xtd::collections::generic::list::end() iterator) and all references to the elements are invalidated. Otherwise, only the iterators and references before the insertion point remain valid.
        iterator insert(const_iterator pos, const type_t&& value) {
          ++operation_number_;
          return items_.insert(pos, value);
        }
        /// @brief Inserts elements at the specified location in the container.
        /// @param pos the iterator before which the content will be inserted (pos may be the end() iterator).
        /// @param count The number of elements to insert.
        /// @param value The element value to insert.
        /// @return The iterator pointing to the first element inserted, or `pos` if `count == 0`.
        /// @remarks Iterator pointing to the first element inserted, or `pos` if `count == 0`.
        /// @remarks If after the operation the new xtd::collections::generic::list::size() is greater than old xtd::collections::generic::list::capacity() a reallocation takes place, in which case all iterators (including the xtd::collections::generic::list::end() iterator) and all references to the elements are invalidated. Otherwise, only the iterators and references before the insertion point remain valid.
        iterator insert(const_iterator pos, size_type count, const type_t& value) {
          ++operation_number_;
          return items_.insert(pos, count, value);
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
          ++operation_number_;
          return items_.insert(pos, first, last);
        }
        /// @brief Inserts elements at the specified location in the container.
        /// @param pos the iterator before which the content will be inserted (pos may be the end() iterator).
        /// @param items The initializer list to insert the values from.
        /// @return The iterator pointing to the first element inserted, or `pos` if `items` is empty.
        /// @remarks Inserts `value` before pos.
        /// @remarks Inserts elements from initializer list `items` before `pos`.
        iterator insert(const_iterator pos, const std::initializer_list<type_t>& items) {
          ++operation_number_;
          return items_.insert(pos, items);
        }
        
        /// @brief Removes the last element of the container.
        /// @remarks Calling pop_back on an empty container results in undefined behavior.
        /// @remarks Iterators (including the xtd::collections::generic::list::end() iterator) and references to the last element are invalidated.
        void pop_back() {
          ++operation_number_;
          items_.pop_back();
        }
        
        /// @brief Appends the given element value to the end of the container.
        /// @param value The value of the element to append.
        /// @remarks If after the operation the new xtd::collections::generic::list::size() is greater than old xtd::collections::generic::list::capacity() a reallocation takes place, in which case all iterators (including the xtd::collections::generic::list::end() iterator) and all references to the elements are invalidated. Otherwise only the xtd::collections::generic::list::end() iterator is invalidated.
        /// @remarks The new element is initialized as a copy of `value`.
        void push_back(const type_t& value) {
          ++operation_number_;
          items_.push_back(value);
        }
        /// @brief Appends the given element value to the end of the container.
        /// @param value The value of the element to append.
        /// @remarks If after the operation the new xtd::collections::generic::list::size() is greater than old xtd::collections::generic::list::capacity() a reallocation takes place, in which case all iterators (including the xtd::collections::generic::list::end() iterator) and all references to the elements are invalidated. Otherwise only the xtd::collections::generic::list::end() iterator is invalidated.
        /// @remarks `value` is moved into the new element.
        void push_back(type_t&& value) {
          ++operation_number_;
          items_.push_back(value);
        }
        
        /// @brief Resizes the container to contain `count` elements, does nothing if `count == size().
        /// @param count The new size of the container.
        /// @remarks If the current size is greater than `count`, the container is reduced to its first `count` elements.
        /// @remarks If the current size is less than `count`, additional default-inserted elements are appended.
        void resize(size_type count) {
          ++operation_number_;
          items_.resize(count);
        }
        /// @brief Resizes the container to contain `count` elements, does nothing if `count == size().
        /// @param count The new size of the container.
        /// @param value The value to initialize the new elements with.
        /// @remarks If the current size is greater than `count`, the container is reduced to its first `count` elements.
        /// @remarks If the current size is less than `count`, additional copies of `value` are appended.
        void resize(size_type count, const value_type& value) {
          ++operation_number_;
          items_.resize(count, value);
        }
        
        ustring to_string() const noexcept override {return ustring::format("{}", items_);}
        
        void swap(list& other) noexcept {
          ++operation_number_;
          items_.swap(other.items_);
        }
        /// @}
        
        /// @name Public Operators
        
        /// @{
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of other.
        /// @param other Another container to use as data source.
        /// @return This current instance.
        list& operator =(const list& other) = default;
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of baste type other.
        /// @param other Another base type container to use as data source.
        /// @return This current instance.
        /*
        list& operator =(const base_type& other) {
          items_ = other;
          operation_number_ = 0;
          return *this;
        }*/
        /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in other is moved from other into this container). other is in a valid but unspecified state afterwards.
        /// @param other Another base type container to use as data source.
        /// @return This current instance.
        list& operator =(const list&& other) noexcept = default;
        /// @brief Replaces the contents with those identified by initializer list ilist.
        /// @param items Initializer list to use as data source
        /// @return This current instance.
        list& operator =(std::initializer_list<type_t>& items) {
          operation_number_ = 0;
          items_ = items;
          return *this;
        }
        /// @brief Returns a reference to the element at specified location pos.
        /// @param pos The position of the element to return.
        /// @return Reference to the requested element.
        ///@remarks  No bounds checking is performed.
        reference operator [](size_type pos) {return items_[pos];}
        /// @brief Returns a reference to the element at specified location pos.
        /// @param pos The position of the element to return.
        /// @return Reference to the requested element.
        ///@remarks  No bounds checking is performed.
        const_reference operator [](size_type pos) const {return items_[pos];}
        /// @}
        
      private:
        base_type items_;
        xtd::int64 operation_number_ = 0;
        xtd::object sync_root_;
      };
    }
  }
}
