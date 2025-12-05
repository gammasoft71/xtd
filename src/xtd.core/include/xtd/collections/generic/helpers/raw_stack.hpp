/// @file
/// @brief Contains xtd::collections::generic::helpers::raw_stack class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <stack>
#include "../../../self.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, OS, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief The xtd::collections::generic::helpers namespace contains helper classes for generic collections, such as comparers, hashers, and utility containers.
      namespace helpers {
        /// @brief Provides a raw, contiguous memory based LIFO (last-in, first-out) stack.
        /// @par Header
        /// ```cpp
        /// #include <xtd/collections/generic/helpers/raw_stack>
        /// ```
        /// @par Namespace
        /// xtd::collections::generic::helpers
        /// @par Library
        /// xtd.core
        /// @ingroup xtd_core helpers_generic_collections
        /// @details
        /// raw_stack is a lightweight wrapper over std::stack that exposes additional methods
        /// such as capacity control, iterators, reserve, and shrink_to_fit. It is intended as a
        /// base class for xtd::collections::generic::stack, providing stack-friendly, high-performance
        /// stack operations while maintaining the same interface as std::stack.
        /// @tparam type_t The type of elements stored in the stack.
        /// @tparam container_t The underlying container used to store elements. Defaults to std::deque<type_t>.
        /// @par Example
        /// @code
        /// auto q = xtd::collections::generic::helpers::raw_stack<int> {};
        /// q.push(1);
        /// q.push(2);
        /// println(q.front()); // 2
        /// q.pop();
        /// println(q.front();) // 1
        /// @endcode
        template<class type_t, class container_t = std::deque<type_t>>
        class raw_stack final : public std::stack<type_t, container_t> {
        public:
          /// @name Public Aliases
          
          /// @{
          using base_type = std::stack<type_t, container_t>; ///< The base STL stack type.
          using container_type = typename base_type::container_type; ///< The underlying container type.
          using value_type = typename base_type::value_type; ///< Type of elements stored.
          using size_type = typename base_type::size_type; ///< Unsigned integer type used for size and capacity.
          using reference = typename base_type::reference; ///< Reference to element type.
          using const_reference = typename base_type::const_reference; ///< Const reference to element type.
          using const_iterator = typename container_type::const_iterator; ///< Const iterator type.
          /// @}
          
          /// @name Public Constructors
          
          /// @{
          /// @brief Default constructor. Initializes an empty stack.
          /// @remarks Capacity is initialized to zero.
          raw_stack() {shrink_to_fit();}
          
          /// @brief Constructs an empty stack with reserved capacity.
          /// @param capacity The initial capacity to reserve.
          /// @remarks Internally resizes the container to optimize future push operations.
          explicit raw_stack(size_type capacity) {
            shrink_to_fit();
            ensure_capacity(capacity);
          }
          
          /// @brief Copy constructor.
          raw_stack(const raw_stack& other) : base_type(other) {shrink_to_fit();}
          
          /// @brief Move constructor.
          /// @param other Another raw_stack to move from.
          /// @note The moved-from stack will be empty after this operation.
          raw_stack(raw_stack&& other) : base_type(std::move(other)) {shrink_to_fit();}
          
          /// @brief Constructs a stack from a range of iterators.
          /// @tparam input_iterator_t Input iterator type.
          /// @param first Iterator to the first element.
          /// @param last Iterator past the last element.
          template<class input_iterator_t>
          raw_stack(input_iterator_t first, input_iterator_t last) : base_type(first, last) {shrink_to_fit();}
          
          /// @brief Constructs a stack with a specific allocator.
          template<class allocator_t>
          explicit raw_stack(const allocator_t& alloc) : base_type(alloc) {shrink_to_fit();}
          /// @}
          
          /// @name Public Properties
          
          /// @{
          /// @brief Gets a const iterator to the beginning of the stack.
          /// @return Iterator to the beginning of the stack.
          auto begin() const -> const_iterator {return base_type::c.cbegin();}
          
          /// @brief Gets the reserved capacity of the stack.
          /// @return The reserved capacity of the stack.
          auto capacity() const noexcept -> size_type {return capacity_;}
          
          /// @brief Gets a const iterator to the beginning of the stack.
          /// @return Iterator to the beginning of the stack.
          auto cbegin() const -> const_iterator {return base_type::c.cbegin();}
          
          /// @brief Gets a const iterator to the end of the stack.
          /// @return Iterator to the end of the stack.
          auto cend() const -> const_iterator {return base_type::c.cend();}
          
          /// @brief Gets a const iterator to the end of the stack.
          /// @return Iterator to the end of the stack.
          auto end() const -> const_iterator {return base_type::c.cend();}
          
          /// @brief Access to the underlying base stack.
          /// @return The underlying base stack.
          auto items() noexcept -> base_type& {return self_;}
          /// @brief Access to the underlying base stack.
          /// @return The underlying base stack.
          auto items() const noexcept -> const base_type& {return self_;}
          
          /// @brief Gets the number of elements in the stack.
          /// @return The number of elements in the stack.
          auto size() const noexcept -> size_type {return base_type::c.size();}
          /// @}
          
          /// @name Public Methods
          
          /// @{
          /// @brief Removes all elements from the stack.
          auto clear() -> void {base_type::c.clear();}
          
          /// @brief Adds a copy of the element at the back of the stack.
          /// @param value The value to push.
          /// @remarks Capacity is automatically increased if needed.
          auto push(const value_type& value) -> void {
            base_type::push(value);
            ensure_capacity(base_type::c.size());
          }
          
          /// @brief Moves the element into the back of the stack.
          /// @param value The value to push.
          /// @remarks Capacity is automatically increased if needed.
          auto push(value_type&& value) -> void {
            base_type::push(std::move(value));
            ensure_capacity(base_type::c.size());
          }
          
          /// @brief Removes the element at the front of the stack.
          /// @warning Calling pop() on an empty stack is undefined behavior.
          auto pop() -> void {
            base_type::pop();
            ensure_capacity(size());
          }
          
          /// @brief Reserves storage to hold at least `count` elements.
          /// @param count Number of elements to reserve space for.
          /// @remarks This allows you to optimize push operations by pre-allocating memory.
          auto reserve(size_type count) -> void {
            if (capacity_ >= count) return;
            ensure_capacity(count);
          }
          
          /// @brief Reduces capacity to fit the current size.
          /// @remarks Use this to minimize memory usage after many pop operations.
          auto shrink_to_fit() -> void {
            base_type::c.shrink_to_fit();
            capacity_ = base_type::c.size();
          }
          /// @}
          
          /// @name Public Operators
          
          /// @{
          raw_stack& operator=(const raw_stack& other) = default; ///< Copy assignment
          raw_stack& operator=(raw_stack&& other) = default; ///< Move assignment
          operator const base_type& () const noexcept {return self_;} ///< Cast to const base_type
          operator base_type& () noexcept {return self_;} ///< Cast to base_type
          /// @}
          
        private:
          auto ensure_capacity(size_type capacity) -> void {
            if (capacity <= capacity_) return;
            capacity_ = capacity;
            auto original_size = base_type::size();
            base_type::c.resize(capacity_);
            base_type::c.resize(original_size); // Restore size while keeping capacity.
          }
          
          size_type capacity_ = base_type::size();
        };
        
        /// @cond
        // Deduction guides for xtd::collections::generic::helpers::raw_stack
        // {
        template<class container_t>
        raw_stack(container_t) -> raw_stack<typename container_t::value_type, container_t>;
        
        template<class container_t, class allocator_t>
        raw_stack(container_t, allocator_t) -> raw_stack<typename container_t::value_type, container_t>;
        
        template< class input_iterator_t>
        raw_stack(input_iterator_t, input_iterator_t) -> raw_stack<typename std::iterator_traits<input_iterator_t>::value_type>;
        
        template< class input_iterator_t, class allocator_t>
        raw_stack(input_iterator_t, input_iterator_t, allocator_t) -> raw_stack<typename std::iterator_traits<input_iterator_t>::value_type, std::deque<typename std::iterator_traits<input_iterator_t>::value_type, allocator_t>>;
        // }
        /// @endcond
      }
    }
  }
}
