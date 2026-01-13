/// @file
/// @brief Contains xtd::collections::generic::helpers::raw_array class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <algorithm>
#include <cstdint>
#include <limits>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief The xtd::collections::generic::helpers namespace contains helpers for generic collections, sush as comparer, equator an hasher structs.
      namespace helpers {
        /// @brief Internal vector-like container used as a storage backend for xtd collections.
        /// @par Header
        /// ```cpp
        /// #include <xtd/collections/generic/helpers/raw_array>
        /// ```
        /// @par Namespace
        /// xtd::collections::generic::helpers
        /// @par Library
        /// xtd.core
        /// @ingroup xtd_core helpers_generic_collections
        template<class type_t, class allocator_t = std::allocator<type_t>>
        class raw_array {
          using internal_storage_value_type = std::conditional_t<std::is_same_v<type_t, bool>, std::uint8_t, type_t>;
          using internal_storage_allocator_type = typename std::allocator_traits<allocator_t>::template rebind_alloc<internal_storage_value_type>;
          using internal_base_type = std::vector<internal_storage_value_type, internal_storage_allocator_type>;
          
          class internal_iterator {
          public:
            using iterator_base_type = typename internal_base_type::iterator;
            using iterator_category = std::random_access_iterator_tag;
            using value_type = type_t;
            using difference_type = std::ptrdiff_t;
            using pointer = type_t*;
            using reference = type_t&;
            
            internal_iterator() = default;
            explicit internal_iterator(iterator_base_type it) : it_(it) {}
            
            reference operator *() const {return reinterpret_cast<reference>(*it_);}
            pointer operator ->() const {return reinterpret_cast<pointer>(std::addressof(*it_));}
            
            internal_iterator& operator ++() {++it_; return *this;}
            internal_iterator operator ++(int) {internal_iterator tmp(*this); ++(*this); return tmp;}
            internal_iterator& operator --() {--it_; return *this;}
            internal_iterator operator --(int) {internal_iterator tmp(*this); --(*this); return tmp;}
            
            internal_iterator& operator +=(difference_type n) {it_ += n; return *this;}
            internal_iterator operator +(difference_type n) const {return internal_iterator(it_ + n);}
            internal_iterator& operator -=(difference_type n) {it_ -= n; return *this;}
            internal_iterator operator -(difference_type n) const {return internal_iterator(it_ - n);}
            difference_type operator -(const internal_iterator & other) const {return it_ - other.it_;}
            
            reference operator [](difference_type n) const {return reinterpret_cast<reference>(it_[n]);}
            
            bool operator ==(const internal_iterator & other) const {return it_ == other.it_;}
            bool operator !=(const internal_iterator & other) const {return it_ != other.it_;}
            bool operator <(const internal_iterator & other) const {return it_ <  other.it_;}
            bool operator <=(const internal_iterator & other) const {return it_ <= other.it_;}
            bool operator >(const internal_iterator & other) const {return it_ >  other.it_;}
            bool operator >=(const internal_iterator & other) const {return it_ >= other.it_;}
            
            iterator_base_type to_base_type() const {return it_;}
            
          private:
            friend class raw_array;
            iterator_base_type it_;
          };
          
          class internal_const_iterator {
          public:
            using iterator_base_type = typename internal_base_type::const_iterator;
            using iterator_category = std::random_access_iterator_tag;
            using value_type = const type_t;
            using difference_type = std::ptrdiff_t;
            using pointer = const type_t*;
            using reference = const type_t&;
            
            internal_const_iterator() = default;
            explicit internal_const_iterator(iterator_base_type it) : it_(it) {}
            internal_const_iterator(const internal_iterator & it) : it_(it.it_) {}
            
            reference operator*() const {return reinterpret_cast<reference>(*it_);}
            pointer operator->() const {return reinterpret_cast<pointer>(std::addressof(*it_));}
            
            internal_const_iterator& operator ++() {++it_; return *this;}
            internal_const_iterator operator ++(int) {internal_const_iterator tmp(*this); ++(*this); return tmp;}
            internal_const_iterator& operator --() {--it_; return *this;}
            internal_const_iterator operator --(int) {internal_const_iterator tmp(*this); --(*this); return tmp;}
            
            internal_const_iterator& operator +=(difference_type n) {it_ += n; return *this;}
            internal_const_iterator operator +(difference_type n) const {return internal_const_iterator(it_ + n);}
            internal_const_iterator& operator -=(difference_type n) {it_ -= n; return *this;}
            internal_const_iterator operator -(difference_type n) const {return internal_const_iterator(it_ - n);}
            difference_type operator -(const internal_const_iterator & other) const {return it_ - other.it_;}
            
            reference operator [](difference_type n) const { return reinterpret_cast<reference>(it_[n]);}
            
            bool operator ==(const internal_const_iterator & other) const {return it_ == other.it_;}
            bool operator !=(const internal_const_iterator & other) const {return it_ != other.it_;}
            bool operator <(const internal_const_iterator & other) const {return it_ <  other.it_;}
            bool operator <=(const internal_const_iterator & other) const {return it_ <= other.it_;}
            bool operator >(const internal_const_iterator & other) const {return it_ >  other.it_;}
            bool operator >=(const internal_const_iterator & other) const {return it_ >= other.it_;}
            
            iterator_base_type to_base_type() const {return it_;}
            
          private:
            friend class raw_array;
            iterator_base_type it_;
          };
        public:
          /// @name Public Aliases
          
          /// @{
          using value_type = type_t; ///< Type of the elements.
          using base_type = internal_base_type; ///< Underlying vector type.
          using const_base_type = const base_type; ///< Const version of base_type.
          using allocator_type = typename base_type::allocator_type; ///< Allocator type.
          using size_type = size_t; ///< Type used for sizes.
          using difference_type = std::ptrdiff_t; ///< Type used for differences between iterators.
          using reference = value_type&; ///< Reference to element.
          using const_reference = const value_type&; ///< Const reference to element.
          using pointer = value_type*; ///< Pointer to element.
          using const_pointer = const value_type*; ///< Const pointer to element.
          using iterator = internal_iterator; ///< Forward iterator for raw_array.
          using const_iterator = internal_const_iterator; ///< Const forward iterator for raw_array.
          using reverse_iterator = std::reverse_iterator<iterator>; ///< Reverse iterator.
          using const_reverse_iterator = std::reverse_iterator<const_iterator>; ///< Const reverse iterator.
          /// @}
          
          /// @name Public Fields
          
          /// @{
          inline static constexpr size_type npos = std::numeric_limits<size_type>::max(); ///< Represents an invalid index.
          static inline constexpr size_type bpos = 0; ///< Beginning position.
          static inline constexpr size_type epos = npos - 1; ///< End position.
          /// @}
          
          /// @name Public Constructors
          
          /// @{
          /// @brief Create a new raw_array instance.
          raw_array() noexcept = default;
          /// @brief Create a new raw_array instance with specified allocator.
          /// @param alloc The allocator associate to this instance.
          explicit raw_array(const allocator_type & alloc) noexcept : items_(alloc) {}
          /// @brief Create a new raw_array instance with specified count, value, and allocator.
          /// @param count Represents the number of `value` to fill this instance.
          /// @param value The value to fill this instance.
          /// @param alloc The allocator associate to this instance.
          raw_array(size_type count, const type_t& value, const allocator_type& alloc = allocator_type()) : items_(count, value, alloc) {}
          /// @brief Create a new raw_array instance with specified count, and allocator.
          /// @param count Represents the number of items of this instance.
          /// @param alloc The allocator associate to this instance.
          explicit raw_array(size_type count, const allocator_type& alloc = allocator_type()) : items_(count, alloc) {}
          /// @brief Create a new raw_array instance with specified first iterator, last iterator, and allocator.
          /// @param first The first iteraror of the range to copy in this instances.
          /// @param last The last iteraror of the range to copy in this instances.
          /// @param alloc The allocator associate to this instance.
          template<class input_iterator_t>
          raw_array(input_iterator_t first, input_iterator_t last, const allocator_type& alloc = allocator_type()) : items_(first, last, alloc) {}
          raw_array(const raw_array & vector) : items_(vector.items_) {}
          raw_array(const base_type & vector) : items_(vector) {}
          raw_array(const raw_array & vector, const allocator_type & alloc) : items_(vector.items_, alloc) {}
          raw_array(const base_type & vector, const allocator_type & alloc) : items_(vector, alloc) {}
          raw_array(std::initializer_list<type_t> items, const allocator_type& alloc = allocator_type()) requires(!std::is_same_v<type_t, bool>) : items_(items, alloc) {}
          raw_array(std::initializer_list<bool> items, const allocator_type& alloc = allocator_type()) requires(std::is_same_v<type_t, bool>)  : items_(alloc) {
            items_.reserve(items.size());
            for (auto b : items)
              items_.push_back(b ? 1 : 0);
          }
          raw_array(raw_array&& other) : items_(std::move(other.items_)) {}
          raw_array(base_type&& other) : items_(std::move(other)) {}
          raw_array(raw_array&& other, const allocator_type & alloc) : items_(std::move(other.items_), alloc) {}
          raw_array(base_type&& other, const allocator_type & alloc) : items_(std::move(other), alloc) {}
          /// @}
          
          /// @name Public Properties
          
          /// @{
          auto back() -> reference {return at(size() - 1);}
          auto back() const -> const_reference {return at(size() - 1);}
          
          auto begin() noexcept -> iterator {return to_type_iterator(items_.begin());}
          auto begin() const noexcept -> const_iterator {return to_type_iterator(items_.cbegin());}
          
          auto capacity() const noexcept -> size_type {return items_.capacity();}
          
          auto cbegin() const noexcept -> const_iterator {return to_type_iterator(items_.cbegin());}
          auto cend() const noexcept -> const_iterator {return to_type_iterator(items_.cend()); }
          
          auto crbegin() const noexcept -> const_reverse_iterator {return const_reverse_iterator(end());}
          auto crend() const noexcept -> const_reverse_iterator {return const_reverse_iterator(begin());}
          
          auto data() noexcept -> pointer {return reinterpret_cast<pointer>(items_.data());}
          auto data() const noexcept -> const_pointer {return reinterpret_cast<const_pointer>(items_.data());}
          
          auto empty() const noexcept -> bool {return items_.empty();}
          
          auto end() noexcept -> iterator {return to_type_iterator(items_.end());}
          auto end() const noexcept -> const_iterator {return to_type_iterator(items_.cend());}
          
          auto front() -> reference {return at(0);}
          auto front() const -> const_reference {return at(0);}
          
          auto items() const noexcept -> const_base_type& {return items_;}
          auto items() noexcept -> base_type& {return items_;}
          
          auto max_size() const noexcept -> size_type {return std::min(items_.max_size(), npos / 2);}
          
          auto rbegin() noexcept -> reverse_iterator {return reverse_iterator(end());}
          auto rbegin() const noexcept -> const_reverse_iterator {return const_reverse_iterator(end());}
          
          auto rend() noexcept -> reverse_iterator {return reverse_iterator(begin());}
          auto rend() const noexcept -> const_reverse_iterator {return const_reverse_iterator(begin());}
          
          auto size() const noexcept -> size_type {return items_.size();}
          
          auto version() const noexcept -> size_type {return version_;}
          /// @}
          
          /// @name Public Methods
          
          /// @{
          auto assign(size_type count, const type_t& value) -> void {++version_; items_.assign(count, value);}
          template<class input_iterator_t>
          auto assign(input_iterator_t first, input_iterator_t last) -> void {++version_; items_.assign(first, last);}
          auto assign(std::initializer_list<type_t> items) -> void {++version_; items_.assign(items.begin(), items.end());}
          
          auto at(size_type index) -> reference {return reinterpret_cast<reference>(items_.at(index > npos / 2 ? size() - (npos - index) : index));}
          auto at(size_type index) const -> const_reference {return reinterpret_cast<const_reference>(items_.at(index > npos / 2 ? size() - (npos - index) : index));}
          
          auto clear() -> void {++version_; items_.clear();}
          
          template<class ...args_t>
          auto emplace(const_iterator pos, args_t&&... args) -> iterator {++version_; return to_type_iterator(items_.emplace(pos.to_base_type(), std::forward<args_t>(args)...));}
          template<class ...args_t>
          auto emplace_back(args_t&&... args) -> reference {++version_; return reinterpret_cast<reference>(items_.emplace_back(std::forward<args_t>(args)...));}
          
          auto erase(const_iterator pos) -> iterator {++version_; return to_type_iterator(items_.erase(pos.to_base_type()));}
          auto erase(const_iterator first, const_iterator last) -> iterator {++version_; return to_type_iterator(items_.erase(first.to_base_type(), last.to_base_type()));}
          
          auto get_allocator() const -> allocator_type {return items_.get_allocator();}
          
          auto increment_version() noexcept -> size_type {return ++version_;}
          
          auto insert(const_iterator pos, const type_t& value) -> iterator {++version_; return to_type_iterator(items_.insert(pos.to_base_type(), value));}
          auto insert(const_iterator pos, type_t&& value) -> iterator {++version_; return to_type_iterator(items_.insert(pos.to_base_type(), std::move(value)));}
          auto insert(const_iterator pos, size_type count, const type_t& value) -> iterator {++version_; return to_type_iterator(items_.insert(pos.to_base_type(), count, value));}
          auto insert(const_iterator pos, size_type count, type_t&& value) -> iterator {++version_; return to_type_iterator(items_.insert(pos.to_base_type(), count, std::move(value)));}
          template<class input_iterator_t>
          auto insert(const_iterator pos, input_iterator_t first, input_iterator_t last) -> iterator {++version_; return to_type_iterator(items_.insert(pos.to_base_type(), first, last));}
          auto insert(const_iterator pos, const std::initializer_list<type_t>& items) -> iterator {++version_; return to_type_iterator(items_.insert(pos.to_base_type(), items.begin(), items.end()));}
          
          auto pop_back() -> void {++version_; items_.pop_back();}
          auto push_back(const type_t& value) -> void {++version_; items_.push_back(value);}
          auto push_back(type_t&& value) -> void {++version_; items_.push_back(std::move(value));}
          
          auto reserve(size_type new_cap) -> void {++version_; items_.reserve(new_cap);}
          
          auto resize(size_type count) -> void {++version_; resize(count, value_type {});}
          auto resize(size_type count, const value_type & value) -> void {++version_; items_.resize(count, value);}
          
          auto shrink_to_fit() -> void {++version_; items_.shrink_to_fit();}
          
          auto swap(raw_array & other) noexcept -> void {++version_; items_.swap(other.items_);}
          /// @}
          
          /// @name Public Operators
          /// @{
          auto operator =(const raw_array & other) -> raw_array& = default;
          auto operator =(raw_array&& other) noexcept -> raw_array&  = default;
          auto operator =(std::initializer_list<type_t>& items) -> raw_array& requires(!std::is_same_v<type_t, bool>) {
            ++version_;
            items_ = items;
            return *this;
          }
          auto operator =(std::initializer_list<bool>& items) -> raw_array& requires(std::is_same_v<type_t, bool>) {
            ++version_;
            items_.clear();
            items_.reserve(items.size());
            for (auto b : items)
              items_.push_back(b ? 1 : 0);
            return *this;
          }
          
          friend auto operator ==(const raw_array<type_t>& a, const raw_array<type_t>& b) -> bool {
            return a.items() == b.items();
          }
          friend auto operator ==(const raw_array<type_t>& a, const std::vector<type_t>& b) -> bool {
            return a.items() == b;
          }
          friend auto operator ==(const std::vector<type_t>& a, const raw_array<type_t>& b) -> bool {
            return a == b.items();
          }
          
          friend auto operator !=(const raw_array<type_t>& a, const raw_array<type_t>& b) -> bool {
            return a.items() != b.items();
          }
          friend auto operator !=(const raw_array<type_t>& a, const std::vector<type_t>& b) -> bool {
            return a.items() != b;
          }
          friend auto operator !=(const std::vector<type_t>& a, const raw_array<type_t>& b) -> bool {
            return a != b.items();
          }
          
          auto operator [](size_type index) const -> const_reference {return at(index);}
          auto operator [](size_type index) -> reference {return at(index);}
          
          operator const base_type& () const noexcept {return items_;}
          operator base_type& () noexcept {return items_;}
          /// @}
          
        private:
          auto to_type_iterator(typename base_type::iterator it) -> iterator { return iterator(it); }
          auto to_type_iterator(typename base_type::const_iterator it) const -> const_iterator { return const_iterator(it); }
          
          base_type items_;
          size_type version_ = 0;
        };
        
        /// @cond
        // Deduction guides for xtd::collections::generic::helpers::raw_array
        // {
        template<class type_t>
        raw_array(std::initializer_list<type_t>) -> raw_array<type_t, std::allocator<type_t >>;
        
        template<class type_t>
        raw_array(const std::vector<type_t>&) -> raw_array<type_t, std::allocator<type_t >>;
        
        template<class type_t, class allocator_t = std::allocator<type_t>>
        raw_array(const raw_array<type_t, allocator_t>&) -> raw_array<type_t, allocator_t>;
        
        template<class type_t>
        raw_array(std::vector<type_t>&&) -> raw_array<type_t, std::allocator<type_t >>;
        
        template<class type_t, class allocator_t = std::allocator<type_t>>
        raw_array(raw_array<type_t, allocator_t>&&) -> raw_array<type_t, allocator_t>;
        // }
        /// @endcond
      }
    }
  }
}
