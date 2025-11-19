/// @file
/// @brief Contains xtd::collections::generic::queue <value_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "linked_list.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents a collection of objects that is maintained in sorted order.
      /// @par Definition
      /// ```cpp
      /// template<class type_t, class container_t = std::deque<type_t>>
      /// using queue = std::stack<type_t, container_t>;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/queue>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @remarks The xtd::collections::generic::sorted_set class is same as [std::set](https://en.cppreference.com/w/cpp/container/set).
      /// @remarks A xtd::collections::generic::sorted_set object maintains a sorted order without affecting performance as elements are inserted and deleted. Duplicate elements are ! allowed. Changing the sort values of existing items is ! supported and may lead to unexpected behavior.
      /// @par Examples
      /// The following example demonstrates how to merge two disparate sets. This example creates two xtd::collections::generic::sorted_set objects, and populates them with even and odd numbers, respectively. A third xtd::collections::generic::sorted_set object is created from the set that contains the even numbers. The example then calls the UnionWith method, which adds the odd number set to the third set.
      /// @include sorted_set.cpp
      template<class type_t, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
      class queue : public xtd::object, public xtd::collections::generic::icollection<type_t> {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the list value type.
        using value_type = typename icollection<type_t>::value_type;
        /// @brief Represents the list base type.
        using base_type = xtd::collections::generic::linked_list<value_type, allocator_t>;
        /// @brief Represents the list size type (usually xtd::size).
        using size_type = xtd::size;
        /// @brief Represents the reference of list value type.
        using reference = value_type&;
        /// @brief Represents the const reference of list value type.
        using const_reference = const value_type&;
        /// @}
        
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::collections::generic::queue <type_t> class that is empty and has the default initial capacity.
        queue() = default;
        /// @brief Move constructor with specified list.
        /// @param queue The xtd::collections::generic::queue <type_t> which elements will be moved from.
        queue(queue&& queue) = default;
        /// @brief Default copy constructor with specified list.
        /// @param linked_list The xtd::collections::generic::linked_list <type_t> which elements will be inserted from.
        queue(const queue& queue) = default;
        /// @brief Initializes a new instance of the xtd::collections::generic::queue <type_t> class that contains elements copied from the specified collection and has sufficient capacity to accommodate the number of elements copied.
        /// @param collection The collection whose elements are copied to the new xtd::collections::generic::queue <type_t>.
        queue(const ienumerable<value_type>& collection) {
          data_->items = base_type {collection};
          ensure_capacity(count());
        }
        /// @brief Initializes a new instance of the xtd::collections::generic::queue <type_t> class that is empty and has the specified initial capacity.
        /// @param capacity The initial number of elements that the xtd::collections::generic::queue <type_t> can contain.
        queue(size_type capacity) {
          data_->capacity = capacity;
        }
        /// @brief Constructs the container with the contents of the specified initializer list, and allocator.
        /// @param items The initializer list to initialize the elements of the container with.
        queue(std::initializer_list<type_t> il) {
          data_->items = base_type {il};
          ensure_capacity(count());
        }
        /// @brief Constructs the container with the contents of the range [first, last).
        /// @param first The first iterator the range to copy the elements from.
        /// @param last The last iterator the range to copy the elements from.
        template < std::input_iterator input_iterator_t >
        queue(input_iterator_t first, input_iterator_t last) {
          for (auto iterator = first; iterator != last; ++iterator)
            enqueue(*iterator);
          ensure_capacity(count());
        }
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the total numbers of elements the internal data structure can hold without resizing.
        /// @return The total numbers of elements the internal data structure can hold without resizing.
        size_type capacity() const noexcept {return data_->capacity;}
        /// @brief Gets the number of nodes actually contained in the xtd::collections::generic::queue <type_t>.
        /// @return The number of nodes actually contained in the xtd::collections::generic::queue <type_t>.
        /// @remarks Retrieving the value of this property is an O(1) operation.
        size_type count() const noexcept override {return data_->items.count();}
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Removes all elements from the Queue<T>.
        void clear() override {
          data_->items.clear();
        }
        
        /// @brief Determines whether an element is in the xtd::collections::generic::queue <type_t>.
        /// @param item The object to locate in the xtd::collections::generic::queue <type_t>.
        /// @return `true` if item is found in the xtd::collections::generic::queue <type_t>; otherwise, `false`.
        bool contains(const_reference value) const noexcept override {
          return data_->items.contains(value);
        }
        
        /// @brief Copies the entire xtd::colllections::generic::linked_list <type_t> to a compatible one-dimensional array, starting at the specified index of the target array.
        /// @param array The one-dimensional Array that is the destination of the elements copied from xtd::colllections::generic::linked_list <type_t>. The Array must have zero-based indexing.
        /// @param array_index The zero-based index in array at which copying begins.
        /// @exception xtd::argument_out_of_range_exception The number of elements in the source xtd::colllections::generic::linked_list <type_t> is greater than the available space from arrayIndex to the end of the destination array.
        /// @remarks This method uses xtd::array::copy to copy the elements.
        /// @remarks The elements are copied to the xtd::array in the same order in which the enumerator iterates through the xtd::colllections::generic::linked_list <type_t>.
        /// @remarks This method is an O(n) operation, where n is xtd::colllections::generic::linked_list::count.
        void copy_to(xtd::array<type_t>& array, size_type array_index) const override {
          data_->items.copy_to(array, array_index);
        }
        
        /// @brief Removes and returns the object at the beginning of the xtd::collections::generic::queue <type_t>.
        /// @return The object that is removed from the beginning of the xtd::collections::generic::queue <type_t>.
        /// @exception xtd::invalid_operation_exception The xtd::collections::generic::queue <type_t> is empty.
        value_type dequeue() {
          value_type copy = peek();
          data_->items.remove_first();
          return copy;
        }
        
        /// @brief Adds an object to the end of the xtd::collections::generic::queue <type_t>.
        /// @param item The object to add to the xtd::collections::generic::queue <type_t>. The value can be null for reference types.
        void enqueue(const_reference value) {
          data_->items.add_last(value);
          ensure_capacity(count());
        }
        
        size_type ensure_capacity(size_type capacity) {
          if (data_->capacity < capacity) data_->capacity = capacity;
          return data_->capacity;
        }
        
        /// @brief Returns an enumerator that iterates through the xtd::collections::generic::queue <type_t>.
        /// @return A xtd::collections::generic::.enumerator for the xtd::collections::generic::queue <type_t>.
        enumerator < value_type > get_enumerator() const noexcept override {
          return data_->items.get_enumerator();
        }
        /// @brief Returns the object at the beginning of the xtd::collections::generic::queue <type_t>
        /// without removing it.
        /// @return The object at the beginning of the xtd::collections::generic::queue <type_t>.
        /// @exception xtd::invalid_operation_exception The xtd::collections::generic::queue <type_t> is empty.
        const_reference peek() const {
          if (count() == 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          return data_->items.first()->value();
        }
        /// @brief Returns the object at the beginning of the xtd::collections::generic::queue <type_t>
        /// without removing it.
        /// @return The object at the beginning of the xtd::collections::generic::queue <type_t>.
        /// @exception xtd::invalid_operation_exception The xtd::collections::generic::queue <type_t> is empty.
        reference& peek() {
          if (count() == 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          return data_->items.first()->value();
        }
        
        /// @brief Copies the xtd::collections::generic::queue <type_t> elements to a new array.
        /// @return A new array containing elements copied from the xtd::collections::generic::queue <type_t>.
        xtd::array<value_type> to_array() const {
          auto array = xtd::array<value_type>(count());
          copy_to(array, 0);
          return array;
        }
        
        /// @brief Returns a xtd::string that represents the current object.
        /// @return A string that represents the current object.
        string to_string() const noexcept override {return data_->items.to_string();}
        
        /// @brief Sets the capacity to the actual number of elements in the xtd::collections::generic::queue <type_t>,
        /// if that number is less than 90 percent of current capacity.
        void trim_excess() {
          data_->capacity = count();
        }
        /// @}
        
      private:
        bool is_read_only() const noexcept override {return false;}
        bool is_synchronized() const noexcept override {return false;}
        const xtd::object& sync_root() const noexcept override {return xtd::as<icollection<value_type>>(data_->items).sync_root();}
        void add(const type_t& value) override {enqueue(value);}
        bool remove(const type_t&) override {return false;}
        
        struct queue_data {
          base_type items;
          xtd::size capacity = 0;
        };
        
        xtd::ptr<queue_data> data_ = xtd::new_ptr<queue_data>();
      };
      
      /// @cond
      // Deduction guides for xtd::collections::generic::linked_list
      // {
      template < class type_t, class allocator_t = xtd::collections::generic::helpers::allocator < type_t>>
      queue(queue < type_t, allocator_t >&&) -> queue < type_t, allocator_t >;
      
      template < class type_t, class allocator_t = xtd::collections::generic::helpers::allocator < type_t>>
      queue(const queue < type_t, allocator_t >&) -> queue < type_t, allocator_t >;
      
      template < class type_t>
      queue(const ienumerable < type_t >&) -> queue < type_t >;
      
      template < class type_t>
      queue(std::initializer_list < type_t >) -> queue < type_t >;
      
      template <class input_iterator_t>
      queue(input_iterator_t, input_iterator_t) -> queue<typename input_iterator_t::value_type>;
      // }
      /// @endcond
    }
  }
}
