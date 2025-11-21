/// @file
/// @brief Contains xtd::collections::generic::helpers::raw_array class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <queue>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief The xtd::collections::generic::helpers namespace contains helpers for generic collections, sush as comparer, equator an hasher structs.
      namespace helpers {
        template<class type_t, class container_t = std::deque<type_t>>
        class raw_queue final : public std::queue<type_t, container_t> {
        public:
          /// @name Public Alias
          
          /// @{
          using base_type = std::queue<type_t, container_t>;
          using value_type = typename base_type::value_type;
          using size_type = typename base_type::size_type;
          /// @}
          
          /// @name Public Constructors
          
          /// @{
          raw_queue() {shrink_to_fit();}
          explicit raw_queue(size_type capacity) {
            shrink_to_fit();
            ensure_capacity(capacity);
          }
          explicit raw_queue(const container_t& cont) : base_type(cont) {shrink_to_fit();}
          explicit raw_queue(container_t&& cont) : base_type(std::move(cont)) {shrink_to_fit();}
          raw_queue(const raw_queue& other) : base_type(other) {shrink_to_fit();}
          raw_queue(raw_queue&& other) : base_type(std::move(other)) {shrink_to_fit();}
          template<class input_iterator_t>
          raw_queue(input_iterator_t first, input_iterator_t last) : base_type(first, last) {shrink_to_fit();}
          template<class allocator_t>
          explicit raw_queue(const allocator_t& alloc) : base_type(alloc) {shrink_to_fit();}
          template<class allocator_t>
          raw_queue(const container_t& cont, const allocator_t& alloc) : base_type(cont, alloc) {shrink_to_fit();}
          template<class allocator_t>
          raw_queue(container_t&& cont, const allocator_t& alloc) : base_type(std::move(cont), alloc) {shrink_to_fit();}
          template<class allocator_t >
          raw_queue(const raw_queue& other, const allocator_t& alloc) : base_type(other, alloc) {shrink_to_fit();}
          template<class allocator_t >
          raw_queue(raw_queue&& other, const allocator_t& alloc) : base_type(std::move(other), alloc) {shrink_to_fit();}
          template<class input_iterator_t, class allocator_t >
          raw_queue(input_iterator_t first, input_iterator_t last, const allocator_t& alloc) : base_type(first, last, alloc) {shrink_to_fit();}
          /// @}
          
          /// @name Public Properties
          
          /// @{
          const base_type& items() const noexcept {return *this;}
          base_type& items() noexcept {return *this;}
          /// @}
          
          /// @name Public Mathods
          
          /// @{
          auto begin() const {return base_type::c.cbegin();}
          auto cbegin() const {return base_type::c.cbegin();}
          
          auto end() const {return base_type::c.cend();}
          auto cend() const {return base_type::c.cend();}
          
          size_type capacity() const noexcept {return capacity_;}
          
          void push(value_type&& value) {
            base_type::push(std::move(value));
            ensure_capacity(base_type::c.size());
          }
          
          void pop() {
            base_type::pop();
          }
          
          void push(const value_type& value) {
            base_type::push(value);
            ensure_capacity(base_type::c.size());
          }
          
          void shrink_to_fit() {
            base_type::c.shrink_to_fit();
            ensure_capacity(base_type::c.size());
          }
          
          size_type size() const noexcept {
            return base_type::c.size();
          }
          
          void reserve(size_type count) {
            if (capacity_ >= count) return;
            ensure_capacity(count);
          }
          /// @}
          
          /// @name Public Operators
          
          /// @{
          operator const base_type&() const noexcept {return *this;}
          operator base_type&() noexcept {return *this;}
          /// @}
          
        private:
          void ensure_capacity(size_type capacity) {
            if (capacity <= capacity_) return;
            capacity_ = capacity;
            auto original_size = base_type::size();
            base_type::c.resize(capacity_);
            base_type::c.resize(original_size); // Restore the original size and the capacity remains unchanged.
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
