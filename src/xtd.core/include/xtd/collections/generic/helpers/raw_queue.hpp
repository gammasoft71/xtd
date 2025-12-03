/// @file
/// @brief Contains xtd::collections::generic::helpers::raw_queue class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <queue>
#include "../../../self.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, OS, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief The xtd::collections::generic::helpers namespace contains helper classes for generic collections, such as comparers, hashers, and utility containers.
      namespace helpers {
        /// @brief Provides a raw, contiguous memory based FIFO (first-in, first-out) queue.
        /// @par Header
        /// ```cpp
        /// #include <xtd/collections/generic/helpers/raw_queue>
        /// ```
        /// @par Namespace
        /// xtd::collections::generic::helpers
        /// @par Library
        /// xtd.core
        /// @ingroup xtd_core helpers_generic_collections
        /// @details
        /// raw_queue is a lightweight wrapper over std::queue that exposes additional methods
        /// such as capacity control, iterators, reserve, and shrink_to_fit. It is intended as a
        /// base class for xtd::collections::generic::queue, providing stack-friendly, high-performance
        /// queue operations while maintaining the same interface as std::queue.
        /// @tparam type_t The type of elements stored in the queue.
        /// @tparam container_t The underlying container used to store elements. Defaults to std::deque<type_t>.
        /// @par Example
        /// @code
        /// auto q = xtd::collections::generic::helpers::raw_queue<int> {};
        /// q.push(1);
        /// q.push(2);
        /// println(q.front()); // 1
        /// q.pop();
        /// println(q.front();) // 2
        /// @endcode
        template<class type_t, class container_t = std::deque<type_t>>
        class raw_queue final : public std::queue<type_t, container_t> {
        public:
          /// @name Public Aliases
          
          /// @{
          using base_type = std::queue<type_t, container_t>; ///< The base STL queue type.
          using container_type = typename base_type::container_type; ///< The underlying container type.
          using value_type = typename base_type::value_type; ///< Type of elements stored.
          using size_type = typename base_type::size_type; ///< Unsigned integer type used for size and capacity.
          using reference = typename base_type::reference; ///< Reference to element type.
          using const_reference = typename base_type::const_reference; ///< Const reference to element type.
          using iterator = typename container_type::const_iterator; ///< Const iterator type.
          using const_iterator = typename container_type::const_iterator; ///< Const iterator type.
          /// @}
          
          /// @name Public Constructors
          
          /// @{
          /// @brief Default constructor. Initializes an empty queue.
          /// @remarks Capacity is initialized to zero.
          raw_queue() {shrink_to_fit();}
          
          /// @brief Constructs an empty queue with reserved capacity.
          /// @param capacity The initial capacity to reserve.
          /// @remarks Internally resizes the container to optimize future push operations.
          explicit raw_queue(size_type capacity) {
            shrink_to_fit();
            ensure_capacity(capacity);
          }
          
          /// @brief Copy constructor.
          raw_queue(const raw_queue& other) : base_type(other) {shrink_to_fit();}
          
          /// @brief Move constructor.
          /// @param other Another raw_queue to move from.
          /// @note The moved-from queue will be empty after this operation.
          raw_queue(raw_queue&& other) : base_type(std::move(other)) {shrink_to_fit();}
          
          /// @brief Constructs a queue from a range of iterators.
          /// @tparam input_iterator_t Input iterator type.
          /// @param first Iterator to the first element.
          /// @param last Iterator past the last element.
          template<class input_iterator_t>
          raw_queue(input_iterator_t first, input_iterator_t last) : base_type(first, last) {shrink_to_fit();}
          
          /// @brief Constructs a queue with a specific allocator.
          template<class allocator_t>
          explicit raw_queue(const allocator_t& alloc) : base_type(alloc) {shrink_to_fit();}
          /// @}
          
          /// @name Public Properties
          
          /// @{
          /// @brief Gets the reserved capacity of the queue.
          /// @return The reserved capacity of the queue.
          auto capacity() const noexcept -> size_type {return capacity_;}
          
          /// @brief Access to the underlying base queue.
          /// @return The underlying base queue.
          auto items() noexcept -> base_type& {return self_;}
          /// @brief Access to the underlying base queue.
          /// @return The underlying base queue.
          auto items() const noexcept -> const base_type& {return self_;}

          /// @brief Gets the number of elements in the queue.
          /// @return The number of elements in the queue.
          auto size() const noexcept -> size_type {return base_type::c.size();}
          /// @}
          
          /// @name Public Methods
          
          /// @{
          /// @brief Gets a const iterator to the beginning of the queue.
          /// @return Iterator to the beginning of the queue.
          auto begin() const -> const_iterator {return base_type::c.cbegin();}

          /// @brief Gets a const iterator to the beginning of the queue.
          /// @return Iterator to the beginning of the queue.
          auto cbegin() const -> const_iterator {return base_type::c.cbegin();}

          /// @brief Gets a const iterator to the end of the queue.
          /// @return Iterator to the end of the queue.
          auto cend() const -> const_iterator {return base_type::c.cend();}

          /// @brief Gets a const iterator to the end of the queue.
          /// @return Iterator to the end of the queue.
          auto end() const -> const_iterator {return base_type::c.cend();}
          
          /// @brief Adds a copy of the element at the back of the queue.
          /// @param value The value to push.
          /// @remarks Capacity is automatically increased if needed.
          auto push(const value_type& value) -> void {
            base_type::push(value);
            ensure_capacity(base_type::c.size());
          }
          
          /// @brief Moves the element into the back of the queue.
          /// @param value The value to push.
          /// @remarks Capacity is automatically increased if needed.
          auto push(value_type&& value) -> void {
            base_type::push(std::move(value));
            ensure_capacity(base_type::c.size());
          }
          
          /// @brief Removes the element at the front of the queue.
          /// @warning Calling pop() on an empty queue is undefined behavior.
          auto pop() -> void {base_type::pop();}
          
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
          raw_queue& operator=(const raw_queue& other) = default; ///< Copy assignment
          raw_queue& operator=(raw_queue&& other) = default; ///< Move assignment
          operator const base_type&() const noexcept {return self_;} ///< Cast to const base_type
          operator base_type&() noexcept {return self_;} ///< Cast to base_type
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
        // Deduction guides for xtd::collections::generic::helpers::raw_queue
        // {
        template<class container_t>
        raw_queue(container_t) -> raw_queue<typename container_t::value_type, container_t>;
        
        template<class container_t, class allocator_t>
        raw_queue(container_t, allocator_t) -> raw_queue<typename container_t::value_type, container_t>;
        
        template< class input_iterator_t>
        raw_queue(input_iterator_t, input_iterator_t) -> raw_queue<typename std::iterator_traits<input_iterator_t>::value_type>;
        
        template< class input_iterator_t, class allocator_t>
        raw_queue(input_iterator_t, input_iterator_t, allocator_t) -> raw_queue<typename std::iterator_traits<input_iterator_t>::value_type, std::deque<typename std::iterator_traits<input_iterator_t>::value_type, allocator_t>>;
        // }
        /// @endcond
      }
    }
  }
}
