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
        /// #include <xtd/collections/generic/helpers/raw_queue>
        /// ```
        /// @par Namespace
        /// xtd::collections::generic::helpers
        /// @par Library
        /// xtd.core
        /// @ingroup xtd_core helpers_generic_collections
        template<class type_t, class allocator_t = std::allocator<type_t>>
        class raw_array {
        public:
          /// @name Public Aliases
          
          /// @{
          using value_type = type_t;
          using storage_value_type = std::conditional_t<std::is_same_v<value_type, bool>, std::uint8_t, value_type >;
          using storage_allocator_type = typename std::allocator_traits<allocator_t>::template rebind_alloc<storage_value_type>;
          using base_type = std::vector<storage_value_type, storage_allocator_type>;
          using const_base_type = const base_type;
          using allocator_type = typename base_type::allocator_type;
          using size_type = size_t;
          using difference_type = std::ptrdiff_t;
          using reference = value_type&;
          using const_reference = const value_type&;
          using pointer = value_type*;
          using const_pointer = const value_type*;
          /// @}
          
          /// @name Public Iterators
          
          /// @{
          //using iterator = typename base_type::iterator;
          class iterator {
          public:
            using iterator_base_type = typename base_type::iterator;
            using iterator_category = std::random_access_iterator_tag;
            using value_type = type_t;
            using difference_type = std::ptrdiff_t;
            using pointer = type_t*;
            using reference = type_t&;
            
            iterator() = default;
            explicit iterator(iterator_base_type it) : it_(it) {}
            
            reference operator *() const {return reinterpret_cast<reference>(*it_);}
            pointer operator ->() const {return reinterpret_cast<pointer>(std::addressof(*it_));}
            
            iterator& operator ++() {++it_; return *this;}
            iterator operator ++(int) {iterator tmp(*this); ++(*this); return tmp;}
            iterator& operator --() {--it_; return *this;}
            iterator operator --(int) {iterator tmp(*this); --(*this); return tmp;}
            
            iterator& operator +=(difference_type n) {it_ += n; return *this;}
            iterator operator +(difference_type n) const {return iterator(it_ + n);}
            iterator& operator -=(difference_type n) {it_ -= n; return *this;}
            iterator operator -(difference_type n) const {return iterator(it_ - n);}
            difference_type operator -(const iterator & other) const {return it_ - other.it_;}
            
            reference operator [](difference_type n) const {return reinterpret_cast<reference>(it_[n]);}
            
            bool operator ==(const iterator & other) const {return it_ == other.it_;}
            bool operator !=(const iterator & other) const {return it_ != other.it_;}
            bool operator <(const iterator & other) const {return it_ <  other.it_;}
            bool operator <=(const iterator & other) const {return it_ <= other.it_;}
            bool operator >(const iterator & other) const {return it_ >  other.it_;}
            bool operator >=(const iterator & other) const {return it_ >= other.it_;}
            
            iterator_base_type to_base_type() const {return it_;}
            
          private:
            friend class raw_array;
            iterator_base_type it_;
          };
          //using const_iterator = typename base_type::const_iterator;
          class const_iterator {
          public:
            using iterator_base_type = typename base_type::const_iterator;
            using iterator_category = std::random_access_iterator_tag;
            using value_type = const type_t;
            using difference_type = std::ptrdiff_t;
            using pointer = const type_t*;
            using reference = const type_t&;
            
            const_iterator() = default;
            explicit const_iterator(iterator_base_type it) : it_(it) {}
            const_iterator(const iterator & it) : it_(it.it_) {}
            
            reference operator*() const {return reinterpret_cast<reference>(*it_);}
            pointer operator->() const {return reinterpret_cast<pointer>(std::addressof(*it_));}
            
            const_iterator& operator ++() {++it_; return *this;}
            const_iterator operator ++(int) {const_iterator tmp(*this); ++(*this); return tmp;}
            const_iterator& operator --() {--it_; return *this;}
            const_iterator operator --(int) {const_iterator tmp(*this); --(*this); return tmp;}
            
            const_iterator& operator +=(difference_type n) {it_ += n; return *this;}
            const_iterator operator +(difference_type n) const {return const_iterator(it_ + n);}
            const_iterator& operator -=(difference_type n) {it_ -= n; return *this;}
            const_iterator operator -(difference_type n) const {return const_iterator(it_ - n);}
            difference_type operator -(const const_iterator & other) const {return it_ - other.it_;}
            
            reference operator [](difference_type n) const { return reinterpret_cast<reference>(it_[n]);}
            
            bool operator ==(const const_iterator & other) const {return it_ == other.it_;}
            bool operator !=(const const_iterator & other) const {return it_ != other.it_;}
            bool operator <(const const_iterator & other) const {return it_ <  other.it_;}
            bool operator <=(const const_iterator & other) const {return it_ <= other.it_;}
            bool operator >(const const_iterator & other) const {return it_ >  other.it_;}
            bool operator >=(const const_iterator & other) const {return it_ >= other.it_;}
            
            iterator_base_type to_base_type() const {return it_;}
            
          private:
            friend class raw_array;
            iterator_base_type it_;
          };
          using reverse_iterator = std::reverse_iterator<iterator>;
          using const_reverse_iterator = std::reverse_iterator<const_iterator>;
          /// @}
          
          /// @name Public Fields
          
          /// @{
          inline static constexpr size_type npos = std::numeric_limits<size_type>::max();
          static inline constexpr size_type bpos = 0;
          static inline constexpr size_type epos = npos - 1;
          /// @}
          
          /// @name Public Constructors
          
          /// @{
          raw_array() noexcept = default;
          explicit raw_array(const allocator_type & alloc) noexcept : items_(alloc) {}
          raw_array(size_type count, const type_t& value, const allocator_type& alloc = allocator_type()) : items_(count, value, alloc) {}
          explicit raw_array(size_type count, const allocator_type& alloc = allocator_type()) : items_(count, alloc) {}
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
          reference back() {return at(size() - 1);}
          const_reference back() const {return at(size() - 1);}
          
          iterator begin() noexcept {return to_type_iterator(items_.begin());}
          const_iterator begin() const noexcept {return to_type_iterator(items_.cbegin());}
          
          size_type capacity() const noexcept {return items_.capacity();}
          
          const_iterator cbegin() const noexcept {return to_type_iterator(items_.cbegin());}
          const_iterator cend() const noexcept {return to_type_iterator(items_.cend()); }
          
          const_reverse_iterator crbegin() const noexcept {return const_reverse_iterator(end());}
          const_reverse_iterator crend() const noexcept {return const_reverse_iterator(begin());}
          
          pointer data() noexcept {return reinterpret_cast<pointer>(items_.data());}
          const_pointer data() const noexcept {return reinterpret_cast<const_pointer>(items_.data());}
          
          bool empty() const noexcept {return items_.empty();}
          
          iterator end() noexcept {return to_type_iterator(items_.end());}
          const_iterator end() const noexcept {return to_type_iterator(items_.cend());}
          
          reference front() {return at(0);}
          const_reference front() const {return at(0);}
          
          const_base_type& items() const noexcept {return items_;}
          base_type& items() noexcept {return items_;}
          
          size_type max_size() const noexcept {return std::min(items_.max_size(), npos / 2);}
          
          reverse_iterator rbegin() noexcept {return reverse_iterator(end());}
          const_reverse_iterator rbegin() const noexcept {return const_reverse_iterator(end());}
          
          reverse_iterator rend() noexcept {return reverse_iterator(begin());}
          const_reverse_iterator rend() const noexcept {return const_reverse_iterator(begin());}
          
          size_type size() const noexcept {return items_.size();}
          
          size_type version() const noexcept {return version_;}
          /// @}
          
          /// @name Public Methods
          
          /// @{
          void assign(size_type count, const type_t& value) {
            ++version_;
            items_.assign(count, value);
          }
          template<class input_iterator_t>
          void assign(input_iterator_t first, input_iterator_t last) {
            ++version_;
            items_.assign(first, last);
          }
          void assign(std::initializer_list<type_t> items) {
            ++version_;
            items_.assign(items.begin(), items.end());
          }
          
          reference at(size_type index) {return reinterpret_cast<reference>(items_.at(index > npos / 2 ? size() - (npos - index) : index));}
          const_reference at(size_type index) const {return reinterpret_cast<const_reference>(items_.at(index > npos / 2 ? size() - (npos - index) : index));}
          
          void clear() {
            ++version_;
            items_.clear();
          }
          
          template<class ...args_t>
          iterator emplace(const_iterator pos, args_t&&... args) {
            ++version_;
            return to_type_iterator(items_.emplace(pos.to_base_type(), std::forward<args_t>(args)...));
          }
          template<class ...args_t>
          reference emplace_back(args_t&&... args) {
            ++version_;
            return reinterpret_cast<reference>(items_.emplace_back(std::forward<args_t>(args)...));
          }
          
          iterator erase(const_iterator pos) {
            ++version_;
            return to_type_iterator(items_.erase(pos.to_base_type()));
          }
          iterator erase(const_iterator first, const_iterator last) {
            ++version_;
            return to_type_iterator(items_.erase(first.to_base_type(), last.to_base_type()));
          }
          
          allocator_type get_allocator() const {return items_.get_allocator();}
          
          size_type increment_version() noexcept {return ++version_;}
          
          iterator insert(const_iterator pos, const type_t& value) {
            ++version_;
            return to_type_iterator(items_.insert(pos.to_base_type(), value));
          }
          iterator insert(const_iterator pos, type_t&& value) {
            ++version_;
            return to_type_iterator(items_.insert(pos.to_base_type(), std::move(value)));
          }
          iterator insert(const_iterator pos, size_type count, const type_t& value) {
            ++version_;
            return to_type_iterator(items_.insert(pos.to_base_type(), count, value));
          }
          iterator insert(const_iterator pos, size_type count, type_t&& value) {
            ++version_;
            return to_type_iterator(items_.insert(pos.to_base_type(), count, std::move(value)));
          }
          template<class input_iterator_t>
          iterator insert(const_iterator pos, input_iterator_t first, input_iterator_t last) {
            ++version_;
            return to_type_iterator(items_.insert(pos.to_base_type(), first, last));
          }
          iterator insert(const_iterator pos, const std::initializer_list<type_t>& items) {
            ++version_;
            return to_type_iterator(items_.insert(pos.to_base_type(), items.begin(), items.end()));
          }
          
          void pop_back() {
            ++version_;
            items_.pop_back();
          }
          void push_back(const type_t& value) {
            ++version_;
            items_.push_back(value);
          }
          void push_back(type_t&& value) {
            ++version_;
            items_.push_back(std::move(value));
          }
          
          void reserve(size_type new_cap) {items_.reserve(new_cap);}
          
          void resize(size_type count) {
            ++version_;
            resize(count, value_type {});
          }
          void resize(size_type count, const value_type & value) {
            ++version_;
            items_.resize(count, value);
          }
          
          void shrink_to_fit() {items_.shrink_to_fit();}
          
          void swap(raw_array & other) noexcept {
            ++version_;
            items_.swap(other.items_);
          }
          /// @}
          
          /// @name Public Operators
          /// @{
          raw_array& operator =(const raw_array & other) = default;
          raw_array& operator =(raw_array&& other) noexcept  = default;
          raw_array& operator =(std::initializer_list<type_t>& items) requires(!std::is_same_v<type_t, bool>) {
            ++version_;
            items_ = items;
            return *this;
          }
          raw_array& operator =(std::initializer_list<bool>& items) requires(std::is_same_v<type_t, bool>) {
            ++version_;
            items_.clear();
            items_.reserve(items.size());
            for (auto b : items)
              items_.push_back(b ? 1 : 0);
            return *this;
          }
          
          friend bool operator ==(const raw_array<type_t>& a, const raw_array<type_t>& b) {
            return a.items() == b.items();
          }
          friend bool operator ==(const raw_array<type_t>& a, const std::vector<type_t>& b) {
            return a.items() == b;
          }
          friend bool operator ==(const std::vector<type_t>& a, const raw_array<type_t>& b) {
            return a == b.items();
          }
          
          friend bool operator !=(const raw_array<type_t>& a, const raw_array<type_t>& b) {
            return a.items() != b.items();
          }
          friend bool operator !=(const raw_array<type_t>& a, const std::vector<type_t>& b) {
            return a.items() != b;
          }
          friend bool operator !=(const std::vector<type_t>& a, const raw_array<type_t>& b) {
            return a != b.items();
          }
          
          const_reference operator [](size_type index) const {return at(index);}
          reference operator [](size_type index) {return at(index);}
          
          operator const base_type& () const noexcept {return items_;}
          operator base_type& () noexcept {return items_;}
          /// @}
          
        private:
          iterator to_type_iterator(typename base_type::iterator it) { return iterator(it); }
          const_iterator to_type_iterator(typename base_type::const_iterator it) const { return const_iterator(it); }
          
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
