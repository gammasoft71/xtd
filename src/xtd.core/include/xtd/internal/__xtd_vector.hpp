/// @file
/// @brief Contains __xtd_vector__ class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <vector>

/// @cond
/// @internal
/// @brief Internal vector-like container used as a storage backend for xtd collections.
///
/// This class exists as a replacement for `std::vector` in xtd internals for the following reasons:
/// - Avoids the specialization and proxy reference issues of `std::vector<bool>`.
/// - Provides a unified and consistent storage type across all xtd containers (`list<type_t>`, `array<type_t>`, etc.).
/// - Ensures predictable behavior and simplifies LINQ integration when non-lazy enumerables need regeneration.
///
/// Notes:
/// - This type is *not* intended to be part of the public xtd API.
/// - Do not expose `__xtd_vector__` directly in public headers.
/// - Safe to use without moderation inside `xtd::internal` namespace.
///
/// @tparam type_t The element type stored in the container.
/// @remarks Semantics are intentionally aligned with `std::vector` where possible for familiarity.
template<class type_t, class allocator_t = std::allocator<type_t>>
class __xtd_vector__ {
public:
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
  //using iterator = typename base_type::iterator;
  class iterator {
  public:
    using iterator_base_type = typename base_type::iterator;
    using iterator_category = std::random_access_iterator_tag;
    using value_type        = type_t;
    using difference_type   = std::ptrdiff_t;
    using pointer           = type_t*;
    using reference         = type_t&;
    
    iterator() = default;
    explicit iterator(iterator_base_type it) : it_(it) {}
    
    reference operator*()  const { return reinterpret_cast<reference>(*it_); }
    pointer   operator->() const { return reinterpret_cast<pointer>(std::addressof(*it_)); }
    
    iterator & operator++()    { ++it_; return *this; }
    iterator  operator++(int) { iterator tmp(*this); ++(*this); return tmp; }
    iterator & operator--()    { --it_; return *this; }
    iterator  operator--(int) { iterator tmp(*this); --(*this); return tmp; }
    
    iterator & operator+=(difference_type n) { it_ += n; return *this; }
    iterator  operator+(difference_type n) const { return iterator(it_ + n); }
    iterator & operator-=(difference_type n) { it_ -= n; return *this; }
    iterator  operator-(difference_type n) const { return iterator(it_ - n); }
    difference_type operator-(const iterator & other) const { return it_ - other.it_; }
    
    reference operator[](difference_type n) const { return reinterpret_cast<reference>(it_[n]); }
    
    bool operator==(const iterator & other) const { return it_ == other.it_; }
    bool operator!=(const iterator & other) const { return it_ != other.it_; }
    bool operator< (const iterator & other) const { return it_ <  other.it_; }
    bool operator<=(const iterator & other) const { return it_ <= other.it_; }
    bool operator> (const iterator & other) const { return it_ >  other.it_; }
    bool operator>=(const iterator & other) const { return it_ >= other.it_; }
    
    iterator_base_type to_base_type() const {return it_;}
    
  private:
    friend class __xtd_vector__;
    iterator_base_type it_;
  };
  //using const_iterator = typename base_type::const_iterator;
  class const_iterator {
  public:
    using iterator_base_type = typename base_type::const_iterator;
    using iterator_category = std::random_access_iterator_tag;
    using value_type        = const type_t;
    using difference_type   = std::ptrdiff_t;
    using pointer           = const type_t*;
    using reference         = const type_t&;
    
    const_iterator() = default;
    explicit const_iterator(iterator_base_type it) : it_(it) {}
    // conversion depuis iterator
    const_iterator(const iterator & it) : it_(it.it_) {}
    
    reference operator*()  const { return reinterpret_cast<reference>(*it_); }
    pointer   operator->() const { return reinterpret_cast<pointer>(std::addressof(*it_)); }
    
    const_iterator & operator++()    { ++it_; return *this; }
    const_iterator  operator++(int) { const_iterator tmp(*this); ++(*this); return tmp; }
    const_iterator & operator--()    { --it_; return *this; }
    const_iterator  operator--(int) { const_iterator tmp(*this); --(*this); return tmp; }
    
    const_iterator & operator+=(difference_type n) { it_ += n; return *this; }
    const_iterator  operator+(difference_type n) const { return const_iterator(it_ + n); }
    const_iterator & operator-=(difference_type n) { it_ -= n; return *this; }
    const_iterator  operator-(difference_type n) const { return const_iterator(it_ - n); }
    difference_type operator-(const const_iterator & other) const { return it_ - other.it_; }
    
    reference operator[](difference_type n) const { return reinterpret_cast<reference>(it_[n]); }
    
    bool operator==(const const_iterator & other) const { return it_ == other.it_; }
    bool operator!=(const const_iterator & other) const { return it_ != other.it_; }
    bool operator< (const const_iterator & other) const { return it_ <  other.it_; }
    bool operator<=(const const_iterator & other) const { return it_ <= other.it_; }
    bool operator> (const const_iterator & other) const { return it_ >  other.it_; }
    bool operator>=(const const_iterator & other) const { return it_ >= other.it_; }
    
    iterator_base_type to_base_type() const {return it_;}
    
  private:
    friend class __xtd_vector__;
    iterator_base_type it_;
  };
  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;
  
  __xtd_vector__() noexcept = default;
  explicit __xtd_vector__(const allocator_type & alloc) noexcept : items_(alloc) {}
  __xtd_vector__(size_type count, const type_t& value, const allocator_type& alloc = allocator_type()) : items_(count, value, alloc) {}
  explicit __xtd_vector__(size_type count, const allocator_type& alloc = allocator_type()) : items_(count, alloc) {}
  template<class input_iterator_t>
  __xtd_vector__(input_iterator_t first, input_iterator_t last, const allocator_type& alloc = allocator_type()) : items_(first, last, alloc) {}
  __xtd_vector__(const __xtd_vector__ & vector) : items_(vector.items_) {}
  __xtd_vector__(const base_type & vector) : items_(vector) {}
  __xtd_vector__(const __xtd_vector__ & vector, const allocator_type & alloc) : items_(vector.items_, alloc) {}
  __xtd_vector__(const base_type & vector, const allocator_type & alloc) : items_(vector, alloc) {}
  __xtd_vector__(std::initializer_list<type_t> items, const allocator_type& alloc = allocator_type()) requires(!std::is_same_v<type_t, bool>) : items_(items, alloc) {}
  __xtd_vector__(std::initializer_list<bool> items, const allocator_type& alloc = allocator_type()) requires(std::is_same_v<type_t, bool>)  : items_(alloc) {
    items_.reserve(items.size());
    for (auto b : items)
      items_.push_back(b ? 1 : 0);
  }
  __xtd_vector__(__xtd_vector__&& other) : items_(std::move(other.items_)) {}
  __xtd_vector__(base_type&& other) : items_(std::move(other)) {}
  __xtd_vector__(__xtd_vector__&& other, const allocator_type & alloc) : items_(std::move(other.items_), alloc) {}
  __xtd_vector__(base_type&& other, const allocator_type & alloc) : items_(std::move(other), alloc) {}
  
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
  
  const_base_type & items() const noexcept {return items_;}
  base_type & items() noexcept {return items_;}
  
  size_type max_size() const noexcept {return items_.max_size();}
  
  reverse_iterator rbegin() noexcept {return reverse_iterator(end());}
  const_reverse_iterator rbegin() const noexcept {return const_reverse_iterator(end());}
  
  reverse_iterator rend() noexcept {return reverse_iterator(begin());}
  const_reverse_iterator rend() const noexcept {return const_reverse_iterator(begin());}
  
  size_type size() const noexcept {return items_.size();}
  
  void assign(size_type count, const type_t& value) {items_.assign(count, value);}
  template<class input_iterator_t>
  void assign(input_iterator_t first, input_iterator_t last) {items_.assign(first, last);}
  void assign(std::initializer_list<type_t> items) {items_.assign(items.begin(), items.end());}
  
  reference at(size_type index) {return reinterpret_cast<reference>(items_.at(index));}
  const_reference at(size_type index) const {return reinterpret_cast<const_reference>(items_.at(index));}
  
  void clear() {items_.clear();}
  
  template<class ...args_t>
  iterator emplace(const_iterator pos, args_t&&... args) {return to_type_iterator(items_.emplace(pos.to_base_type(), std::forward<args_t>(args)...));}
  template<class ...args_t>
  reference emplace_back(args_t&&... args) {return reinterpret_cast<reference>(items_.emplace_back(std::forward<args_t>(args)...));}
  
  iterator erase(const_iterator pos) {return to_type_iterator(items_.erase(pos.to_base_type()));}
  iterator erase(const_iterator first, const_iterator last) {return to_type_iterator(items_.erase(first.to_base_type(), last.to_base_type()));}
  
  allocator_type get_allocator() const {return items_.get_allocator();}
  
  base_type & get_base_type() noexcept {return items_;}
  const base_type & get_base_type() const noexcept {return items_;}
  
  iterator insert(const_iterator pos, const type_t& value) {return to_type_iterator(items_.insert(pos.to_base_type(), value));}
  iterator insert(const_iterator pos, type_t&& value) {return to_type_iterator(items_.insert(pos.to_base_type(), std::move(value)));}
  iterator insert(const_iterator pos, size_type count, const type_t& value) {return to_type_iterator(items_.insert(pos.to_base_type(), count, value));}
  iterator insert(const_iterator pos, size_type count, type_t&& value) {return to_type_iterator(items_.insert(pos.to_base_type(), count, std::move(value)));}
  template<class input_iterator_t>
  iterator insert(const_iterator pos, input_iterator_t first, input_iterator_t last) {return to_type_iterator(items_.insert(pos.to_base_type(), first, last));}
  iterator insert(const_iterator pos, const std::initializer_list<type_t>& items) {return to_type_iterator(items_.insert(pos.to_base_type(), items.begin(), items.end()));}
  
  void pop_back() {items_.pop_back();}
  void push_back(const type_t& value) {items_.push_back(value);}
  void push_back(type_t&& value) {items_.push_back(std::move(value));}
  
  void reserve(size_type new_cap) {items_.reserve(new_cap);}
  
  void resize(size_type count)  {resize(count, value_type {});}
  void resize(size_type count, const value_type & value) {items_.resize(count, value);}
  
  void shrink_to_fit() {items_.shrink_to_fit();}
  
  void swap(__xtd_vector__ & other) noexcept {items_.swap(other.items_);}
  
  __xtd_vector__& operator =(const __xtd_vector__ & other) = default;
  __xtd_vector__& operator =(__xtd_vector__&& other) noexcept  = default;
  __xtd_vector__& operator =(std::initializer_list<type_t>& items) requires(!std::is_same_v<type_t, bool>) {
    items_ = items;
    return *this;
  }
  __xtd_vector__& operator =(std::initializer_list<bool>& items) requires(std::is_same_v<type_t, bool>) {
    items_.clear();
    items_.reserve(items.size());
    for (auto b : items)
      items_.push_back(b ? 1 : 0);
    return *this;
  }
  
  const_reference operator [](size_type index) const {return at(index);}
  reference operator [](size_type index) {return at(index);}
  
  operator const base_type & () const noexcept {return items_;}
  operator base_type & () noexcept {return items_;}
  
private:
  iterator to_type_iterator(typename base_type::iterator it) { return iterator(it); }
  const_iterator to_type_iterator(typename base_type::const_iterator it) const { return const_iterator(it); }
  
  base_type items_;
};

template<class type_t>
__xtd_vector__(std::initializer_list<type_t>) -> __xtd_vector__<type_t, std::allocator<type_t >>;

template<class type_t>
__xtd_vector__(const std::vector<type_t>&) -> __xtd_vector__<type_t, std::allocator<type_t >>;

template<class type_t, class allocator_t = std::allocator<type_t>>
__xtd_vector__(const __xtd_vector__<type_t, allocator_t>&) -> __xtd_vector__<type_t, allocator_t>;

template<class type_t>
__xtd_vector__(std::vector<type_t>&&) -> __xtd_vector__<type_t, std::allocator<type_t >>;

template<class type_t, class allocator_t = std::allocator<type_t>>
__xtd_vector__(__xtd_vector__<type_t, allocator_t>&&) -> __xtd_vector__<type_t, allocator_t>;
/// @endcond
