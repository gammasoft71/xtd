/// @file
/// @brief Contains xtd::collections::generic::stack <value_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "helpers/raw_stack.hpp"
#include "icollection.hpp"
#include "../../size.hpp"
#include "../../string.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents a last-in, first-out collection of objects.
      /// @par Definition
      /// ```cpp
      /// template<class type_t, class container_t = std::deque<type_t>>
      /// class stack : public xtd::object, public xtd::collections::generic::icollection<type_t>;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/stack>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @remarks This class implements a generic stack as a circular array. Objects stored in a xtd::collections::generic::stack <type_t> are inserted at one end and removed from the other. Queues and stacks are useful when you need temporary storage for information; that is, when you might want to discard an element after retrieving its value. Use xtd::collections::generic::stack <type_t> if you need to access the information in the same order that it is stored in the collection. Use xtd::collections::generic::stack <type_t> if you need to access the information in reverse order. Use xtd::collections::generic::concurrent_queue <type_t> or xtd::collections::generic::concurrent_stack <type_t> if you need to access the collection from multiple threads concurrently.
      /// @remarks Three main operations can be performed on a xtd::collections::generic::stack <type_t> and its elements:
      ///   * xtd::collections::generic::stack::push adds an element to the end of the xtd::collections::generic::stack <type_t>.
      ///   * xtd::collections::generic::stack::pop removes the oldest element from the start of the xtd::collections::generic::stack <type_t>.
      ///   * xtd::collections::generic::stack::peek peek returns the oldest element that is at the start of the xtd::collections::generic::stack <type_t> but does not remove it from the xtd::collections::generic::stack <type_t>.
      /// @remarks The capacity of a xtd::collections::generic::stack <type_t> is the number of elements the xtd::collections::generic::stack <type_t> can hold. As elements are added to a xtd::collections::generic::stack <type_t>, the capacity is automatically increased as required by reallocating the internal array. The capacity can be decreased by calling xtd::collections::generic::stack::trim_excess.
      /// @remarks xtd::collections::generic::stack <type_t> allows duplicate elements.
      /// @tparam type_t The value type of the generic container.
      /// @tparam container_t The underlying container type used by xtd::collections::generic::helpers::raw_stack. The default container type is [std::deque](https://en.cppreference.com/w/cpp/container/deque.html).
      /// @par Examples
      /// The following code example demonstrates several methods of the xtd::collections::generic::stack <type_t> generic class. The code example creates a stack of strings with default capacity and uses the xtd::collections::generic::stack::push method to stack five strings. The elements of the stack are enumerated, which does not change the state of the stack. The xtd::collections::generic::stack::pop method is used to pop the first string. The xtd::collections::generic::stack::peek method is used to look at the next item in the stack, and then the xtd::collections::generic::stack::pop method is used to pop it.
      /// The xtd::collections::generic::stack::to_array method is used to create an array and copy the stack elements to it, then the array is passed to the xtd::collections::generic::stack <type_t> constructor that takes xtd::collections::generic::ienumerable <type_t>, creating a copy of the stack. The elements of the copy are displayed.
      /// An array twice the size of the stack is created, and the xtd::collections::generic::stack::copy_to method is used to copy the array elements beginning at the middle of the array. The xtd::collections::generic::stack <type_t> constructor is used again to create a second copy of the stack containing three null elements at the beginning.
      /// The xtd::collections::generic::stack::contains method is used to show that the string "four" is in the first copy of the stack, after which the Clear method clears the copy and the xtd::collections::generic::stack::count property shows that the stack is empty.
      /// @include generic_stack.cpp
      template<class type_t, class container_t = std::deque<type_t>>
      class stack : public xtd::object, public xtd::collections::generic::icollection<type_t> {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the list value type.
        using value_type = typename icollection<type_t>::value_type;
        /// @brief Represents the list base type.
        using base_type = xtd::collections::generic::helpers::raw_stack<value_type, container_t>;
        /// @brief Represents the list size type (usually xtd::size).
        using size_type = xtd::size;
        /// @brief Represents the reference of list value type.
        using reference = value_type&;
        /// @brief Represents the const reference of list value type.
        using const_reference = const value_type&;
        /// @}
        
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::collections::generic::stack <type_t> class that is empty and has the default initial capacity.
        stack() = default;
        /// @brief Move constructor with specified stack.
        /// @param stack The xtd::collections::generic::stack <type_t> which elements will be moved from.
        stack(stack&& stack) {
          data_ = std::move(stack.data_);
          stack.data_ = new_ptr<stack_data>();
        }
        /// @brief Default copy constructor with specified stack.
        /// @param stack The xtd::collections::generic::stack <type_t> which elements will be inserted from.
        stack(const stack& stack) = default;
        /// @brief Move constructor with specified stack.
        /// @param stack The std::stack <type_t> which elements will be moved from.
        stack(std::stack<type_t>&& stack) {
          auto tmp = std::vector<type_t> {};
          tmp.reserve(stack.size());
          
          while (!stack.empty()) {
            tmp.push_back(std::move(stack.top()));
            stack.pop();
          }
          
          for (auto iterator = tmp.rbegin(); iterator != tmp.rend(); ++iterator)
            data_->items.push(*iterator);
          
          ensure_capacity(count());
        }
        /// @brief Default copy constructor with specified stack.
        /// @param stack The std::stack <type_t> which elements will be inserted from.
        stack(const std::stack<type_t>& stack) {
          struct std_stack : public std::stack<type_t> {
            std_stack(const std::stack<type_t>& stack) : ptr {reinterpret_cast<const std_stack*>(&stack)} {}
            auto begin() const {return ptr->c.begin();}
            auto end() const {return ptr->c.end();}
            const std_stack* ptr;
          };
          auto items = std_stack {stack};
          data_->items = base_type(items.begin(), items.end());
          ensure_capacity(count());
        }
        /// @brief Initializes a new instance of the xtd::collections::generic::stack <type_t> class that contains elements copied from the specified collection and has sufficient capacity to accommodate the number of elements copied.
        /// @param collection The collection whose elements are copied to the new xtd::collections::generic::stack <type_t>.
        stack(const ienumerable<value_type>& collection) {
          for (auto item : collection)
            data_->items.push(item);
          ensure_capacity(count());
        }
        /// @brief Initializes a new instance of the xtd::collections::generic::stack <type_t> class that is empty and has the specified initial capacity.
        /// @param capacity The initial number of elements that the xtd::collections::generic::stack <type_t> can contain.
        stack(size_type capacity) {
          data_->items.reserve(capacity);
        }
        /// @brief Constructs the container with the contents of the specified initializer list, and allocator.
        /// @param items The initializer list to initialize the elements of the container with.
        stack(std::initializer_list<type_t> il) {
          data_->items = base_type {il};
          ensure_capacity(count());
        }
        /// @brief Constructs the container with the contents of the range [first, last).
        /// @param first The first iterator the range to copy the elements from.
        /// @param last The last iterator the range to copy the elements from.
        template < std::input_iterator input_iterator_t >
        stack(input_iterator_t first, input_iterator_t last) {
          for (auto iterator = first; iterator != last; ++iterator)
            push(*iterator);
          ensure_capacity(count());
        }
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the total numbers of elements the internal data structure can hold without resizing.
        /// @return The total numbers of elements the internal data structure can hold without resizing.
        auto capacity() const noexcept -> size_type {return data_->items.capacity();}
        /// @brief Gets the number of nodes actually contained in the xtd::collections::generic::stack <type_t>.
        /// @return The number of nodes actually contained in the xtd::collections::generic::stack <type_t>.
        /// @remarks Retrieving the value of this property is an O(1) operation.
        [[nodiscard]] auto count() const noexcept -> size_type override {return data_->items.size();}
        
        /// @brief Gets a std::stack<type_t>.
        /// @return A std::stack<type_t>.
        auto items() const {return std::stack<type_t>(std::deque<type_t>(data_->items.begin(), data_->items.end()));}
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Removes all elements from the xtd::collections::generic::stack <type_t>.
        /// @remarks Count is set to zero, and references to other objects from elements of the collection are also released.
        /// @remarks The capacity remains unchanged. To reset the capacity of the xtd::collections::generic::stack <type_t>, call xtd::collections::generic::stack::trim_excess. Trimming an empty xtd::collections::generic::stack <type_t> sets the capacity of the xtd::collections::generic::stack <type_t> to the default capacity.
        /// @remarks This method is an O(n) operation, where n is Count.
        auto clear() -> void override {
          data_->items.clear();
          ++data_->version;
        }
        
        /// @brief Determines whether an element is in the xtd::collections::generic::stack <type_t>.
        /// @param item The object to locate in the xtd::collections::generic::stack <type_t>.
        /// @return `true` if `item` is found in the xtd::collections::generic::stack <type_t>; otherwise, `false`.
        auto contains(const_reference value) const noexcept -> bool override {
          for (const auto& item : data_->items)
            if (xtd::collections::generic::helpers::equator<type_t> {}(item, value)) return true;
          return false;
        }
        
        /// @brief Copies the entire xtd::colllections::generic::linked_list <type_t> to a compatible one-dimensional array, starting at the specified index of the target array.
        /// @param array The one-dimensional Array that is the destination of the elements copied from xtd::colllections::generic::linked_list <type_t>. The Array must have zero-based indexing.
        /// @param array_index The zero-based index in array at which copying begins.
        /// @exception xtd::argument_out_of_range_exception The number of elements in the source xtd::colllections::generic::linked_list <type_t> is greater than the available space from arrayIndex to the end of the destination array.
        /// @remarks This method uses xtd::array::copy to copy the elements.
        /// @remarks The elements are copied to the xtd::array in the same order in which the enumerator iterates through the xtd::colllections::generic::linked_list <type_t>.
        /// @remarks This method is an O(n) operation, where n is xtd::colllections::generic::linked_list::count.
        auto copy_to(xtd::array<type_t>& array, size_type array_index) const -> void override {
          if (array_index + count() > array.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          for (const auto& item : data_->items)
            array[array_index++] = item;
        }
        
        /// @brief Removes and returns the object at the beginning of the xtd::collections::generic::stack <type_t>.
        /// @return The object that is removed from the beginning of the xtd::collections::generic::stack <type_t>.
        /// @exception xtd::invalid_operation_exception The xtd::collections::generic::stack <type_t> is empty.
        auto pop() -> value_type {
          auto result = value_type {};
          if (!try_pop(result)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          return result;
        }
        
        /// @brief Adds an object to the end of the xtd::collections::generic::stack <type_t>.
        /// @param item The object to add to the xtd::collections::generic::stack <type_t>. The value can be null for reference types.
        auto push(const_reference value) -> void {
          data_->items.push(value);
          ensure_capacity(count());
          ++data_->version;
        }
        
        /// @brief Adds an object to the end of the xtd::collections::generic::stack <type_t>.
        /// @param item The object to add to the xtd::collections::generic::stack <type_t>. The value can be null for reference types.
        auto push(value_type&& value) -> void {
          data_->items.push(std::move(value));
          ensure_capacity(count());
          ++data_->version;
        }
        
        /// @brief Ensures that the capacity of this stack is at least the specified `capacity`. If the current capacity is less than `capacity`, it is increased to at least the specified `capacity`.
        /// @param capacity The minimum capacity to ensure.
        /// @return The new capacity of this stack.
        auto ensure_capacity(size_type capacity) -> size_type {
          if (data_->items.capacity() < capacity) data_->items.reserve(capacity);
          return data_->items.capacity();
        }
        
        /// @brief Returns an enumerator that iterates through the xtd::collections::generic::stack <type_t>.
        /// @return A xtd::collections::generic::.enumerator for the xtd::collections::generic::stack <type_t>.
        enumerator<value_type> get_enumerator() const noexcept override {
          struct stack_enumerator : public ienumerator < value_type > {
            explicit stack_enumerator(const stack & items, xtd::size version) : items_(items), version_(version) {}
            
            const value_type& current() const override {
              if (iterator_ == items_.data_->items.crend()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
              if (version_ != items_.data_->version) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; enumeration operation may not execute.");
              return *iterator_;
            }
            
            bool move_next() override {
              if (version_ != items_.data_->version) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; enumeration operation may not execute.");
              if (index_++ && iterator_ != items_.data_->items.crend()) ++iterator_;
              else iterator_ = items_.data_->items.crbegin();
              return iterator_ != items_.data_->items.crend();
            }
            
            void reset() override {
              index_ = 0;
              version_ = items_.data_->version;
              iterator_ = items_.data_->items.crend();
            }
            
          private:
            size_type index_ = 0;
            const stack& items_;
            typename base_type::const_reverse_iterator iterator_ = items_.data_->items.crend();
            size_type version_ = 0;
          };
          return {new_ptr < stack_enumerator > (self_, data_->version)};
        }
        
        /// @brief Returns the object at the beginning of the xtd::collections::generic::stack <type_t>
        /// without removing it.
        /// @return The object at the beginning of the xtd::collections::generic::stack <type_t>.
        /// @exception xtd::invalid_operation_exception The xtd::collections::generic::stack <type_t> is empty.
        [[nodiscard]] auto peek() const -> value_type {
          auto result = value_type {};
          if (!try_peek(result)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          return result;
        }
        
        /// @brief Copies the xtd::collections::generic::stack <type_t> elements to a new array.
        /// @return A new array containing elements copied from the xtd::collections::generic::stack <type_t>.
        auto to_array() const -> xtd::array<value_type> {
          auto array = xtd::array<value_type>(count());
          copy_to(array, 0);
          return array;
        }
        
        /// @brief Returns a xtd::string that represents the current object.
        /// @return A string that represents the current object.
        auto to_string() const noexcept -> string override {return xtd::string::format("[{}]", xtd::string::join(", ", self_));}
        
        /// @brief Sets the capacity to the actual number of elements in the xtd::collections::generic::stack <type_t>, if that number is less than 90 percent of current capacity.
        /// @remarks This method can be used to minimize a collection's memory overhead if no new elements will be added to the collection. The cost of reallocating and copying a large xtd::collections::generic::stack <type_t> can be considerable, however, so the xtd::collections::generic::stack::trim_excess method does nothing if the list is at more than 90 percent of capacity. This avoids incurring a large reallocation cost for a relatively small gain.
        /// @remarks This method is an O(n) operation, where n is xtd::collections::generic::stack::count.
        /// @remarks To reset a xtd::collections::generic::stack <type_t> to its initial state, call the xtd::collections::generic::stack::clear method before calling xtd::collections::generic::stack::trim_excess method. Trimming an empty xtd::collections::generic::stack <type_t> sets the capacity of the xtd::collections::generic::stack <type_t> to the default capacity.
        auto trim_excess() -> void {
          if (count() < static_cast<xtd::size>(capacity() * 0.9)) trim_excess(count());
        }
        
        /// @brief Sets the capacity of a xtd::collections::generic::stack <type_t> object to the specified number of entries.
        /// @param capacity The new capacity.
        /// @exception xtd::argument_out_of_range_exception Passed capacity is lower than entries count.
        auto trim_excess(size_type capacity) -> void {
          if (capacity < count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          auto temp = base_type {};
          temp.reserve(capacity);
          for (auto& i : data_->items)
            temp.push(i);
          data_->items = std::move(temp);
          ++data_->version;
        }
        
        /// @brief Removes the object at the beginning of the xtd::collections::generic::stack <type_t>, and copies it to the result parameter.
        /// @param The removed object.
        /// @return `true` if the object is successfully removed; `false` if the xtd::collections::generic::stack <type_t> is empty.
        [[nodiscard]] auto try_pop(value_type& result) noexcept -> bool {
          if (!try_peek(result)) return false;
          data_->items.pop();
          ++data_->version;
          return true;
        }
        
        /// @brief Returns a value that indicates whether there is an object at the beginning of the xtd::collections::generic::stack <type_t>, and if one is present, copies it to the result parameter. The object is not removed from the xtd::collections::generic::stack <type_t>.
        /// @param If present, the object at the beginning of the xtd::collections::generic::stack <type_t>; otherwise, the default value of `type_t`.
        /// @return `true` if there is an object at the beginning of the xtd::collections::generic::stack <type_t>; `false` if the xtd::collections::generic::stack <type_t> is empty.
        [[nodiscard]] auto try_peek(value_type& result) const noexcept -> bool {
          result = count() ? data_->items.top() : type_t {};
          return count();
        }
        /// @}
        
        /// @name Public Operators
        
        /// @{
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of other.
        /// @param other Another container to use as data source.
        /// @return This current instance.
        auto operator =(const stack& other) -> stack& = default;
        /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in other is moved from other into this container). other is in a valid but unspecified state afterwards.
        /// @param other Another base type container to use as data source.
        /// @return This current instance.
        auto operator =(stack&& other) noexcept -> stack& {
          data_->items = std::move(other.data_->items);
          ++data_->version;
          return self_;
        }
        /// @brief Replaces the contents with those identified by initializer list ilist.
        /// @param items Initializer list to use as data source
        /// @return This current instance.
        auto operator =(const std::initializer_list<type_t>& items) -> stack& {
          data_->items = items;
          ++data_->version;
          return self_;
        }
        
        /// @brief Gets a std::stack<type_t>.
        /// @return A std::stack<type_t>.
        operator std::stack<type_t>() const {return items();}
        /// @}
        
      private:
        auto is_read_only() const noexcept -> bool override {return false;}
        auto is_synchronized() const noexcept -> bool override {return false;}
        const xtd::object& sync_root() const noexcept override {return data_->sync_root;}
        auto add(const type_t& value) -> void override {push(value);}
        auto remove(const type_t&) -> bool override {return false;}
        
        struct stack_data {
          base_type items;
          xtd::object sync_root;
          xtd::size version = 0;
        };
        
        xtd::ptr<stack_data> data_ = xtd::new_ptr<stack_data>();
      };
      
      /// @cond
      // Deduction guides for xtd::collections::generic::stack
      // {
      template < class type_t, class container_t>
      stack(stack< type_t, container_t>&&) -> stack<type_t, container_t>;
      
      template < class type_t, class container_t>
      stack(const stack<type_t, container_t>&) -> stack<type_t, container_t>;
      
      template < class type_t>
      stack(const ienumerable<type_t>&) -> stack<type_t>;
      
      template < class type_t>
      stack(std::initializer_list<type_t>) -> stack<type_t>;
      
      template <class input_iterator_t>
      stack(input_iterator_t, input_iterator_t) -> stack<std::iter_value_t<input_iterator_t>>;
      // }
      /// @endcond
    }
  }
}
