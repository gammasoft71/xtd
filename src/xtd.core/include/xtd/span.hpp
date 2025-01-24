/// @file
/// @brief Contains xtd::span class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "argument_out_of_range_exception.hpp"
#include "null.hpp"
#include "object.hpp"
#include "ptrdiff.hpp"
#include "size.hpp"
#include <limits>
#include <type_traits>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  inline constexpr xtd::size dynamic_extent = std::numeric_limits<xtd::size>::max();
  
  template<class type_t, xtd::size count_ = dynamic_extent>
  class span : public xtd::object {
  public:
    template<class pointer_t>
    class wrap_pointer_iterator {
    public:
      wrap_pointer_iterator(pointer_t data) noexcept : data_ {data} {}
      
      const std::remove_pointer_t<pointer_t> operator *() const noexcept {return *data_;}
      std::remove_pointer_t<pointer_t> operator *() noexcept {return *data_;}
      
      const pointer_t operator ->() const noexcept {return data_;}
      pointer_t operator ->() noexcept {return data_;}
      
      wrap_pointer_iterator& operator ++() const noexcept {++data_; return *const_cast<wrap_pointer_iterator*>(this);}
      wrap_pointer_iterator operator ++(int) const noexcept {auto current = *this; operator ++(); return current;}
      
      wrap_pointer_iterator operator +(xtd::size value) const noexcept {return wrap_pointer_iterator {data_ + value};}
      xtd::ptrdiff operator -(wrap_pointer_iterator value) const noexcept {return data_ - value.data_;}
      
      bool operator ==(const wrap_pointer_iterator& rhs) const noexcept {return data_ == rhs.data_;}
      bool operator !=(const wrap_pointer_iterator& rhs) const  noexcept {return !operator==(rhs);}
      
    private:
      mutable pointer_t data_ = nullptr;
    };
    
    template<class pointer_t>
    class wrap_pointer_reverse_iterator {
    public:
      wrap_pointer_reverse_iterator(pointer_t data) noexcept : data_ {data - 1} {}
      
      const std::remove_pointer_t<pointer_t> operator *() const noexcept {return *data_;}
      std::remove_pointer_t<pointer_t> operator *() noexcept {return *data_;}
      
      const pointer_t operator ->() const noexcept {return data_;}
      pointer_t operator ->() noexcept {return data_;}
      
      wrap_pointer_reverse_iterator& operator ++() const noexcept {--data_; return *const_cast<wrap_pointer_reverse_iterator*>(this);}
      wrap_pointer_reverse_iterator operator ++(int) const noexcept {auto current = *this; operator ++(); return current;}
      
      wrap_pointer_reverse_iterator operator +(xtd::size value) const noexcept {return wrap_pointer_reverse_iterator {data_ - value};}
      xtd::ptrdiff operator -(wrap_pointer_reverse_iterator value) const noexcept {return  data_ + value.data_;}
      
      bool operator ==(const wrap_pointer_reverse_iterator& rhs) const noexcept {return data_ == rhs.data_;}
      bool operator !=(const wrap_pointer_reverse_iterator& rhs) const noexcept {return !operator==(rhs);}
      
    private:
      mutable pointer_t data_ = nullptr;
    };
    
    /// @name Public Aliases
    
    /// @{
    /// @brief Represents the span elemeent type.
    using element_type = type_t;
    /// @brief Represents the span value type.
    using value_type = std::remove_cv_t<type_t>;
    /// @brief Represents the span size type (usually xtd::size).
    using size_type = xtd::size;
    /// @brief Represents the span difference type (usually xtd::ptrdiff).
    using difference_type = xtd::ptrdiff;
    /// @brief Represents the span pointer type.
    using pointer = type_t*;
    /// @brief Represents the span const pointer type.
    using const_pointer = const type_t*;
    /// @brief Represents the span reference type.
    using reference = type_t&;
    /// @brief Represents the span const reference type.
    using const_reference = const type_t&;
    /// @brief Represents the iterator of span value type.
    using iterator = const wrap_pointer_iterator<pointer>;
    /// @brief Represents the const iterator of span value type.
    using const_iterator = const wrap_pointer_iterator<pointer>;
    /// @brief Represents the reverse iterator of span value type.
    using reverse_iterator = wrap_pointer_reverse_iterator<pointer>;
    /// @brief Represents the const reverse iterator of span value type.
    using const_reverse_iterator = wrap_pointer_reverse_iterator<pointer>;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    span() = default;
    template<class iterator_t>
    explicit span(iterator_t first, iterator_t last) : data_ {const_cast<type_t*>(&(*first))}, size_ {static_cast<size_type>(std::distance(first, last))} {}
    template<class collection_t>
    explicit span(const collection_t& items) : data_ {const_cast<type_t*>(items.data())}, size_ {items.size()} {}
    template<class collection_t>
    explicit span(collection_t& items) : data_ {items.data()}, size_ {items.size()} {}
    template<class collection_t>
    explicit span(const collection_t& items, xtd::size count) : data_ {const_cast<type_t*>(items.data())}, size_ {count} {}
    template<class collection_t>
    explicit span(collection_t& items, xtd::size count) : data_ {items.data()}, size_ {count} {}
    template<class collection_t>
    explicit span(const collection_t& items, xtd::size offset, xtd::size count) : data_ {const_cast<type_t*>(items.data() + offset)}, size_ {count} {
      if (offset + count > items.size()) throw argument_out_of_range_exception {};
    }
    template<class collection_t>
    explicit span(collection_t& items, xtd::size offset, xtd::size count) : data_ {items.data() + offset}, size_ {count} {
      if (offset + count > items.size()) throw argument_out_of_range_exception {};
    }
    explicit span(std::initializer_list<type_t> items) noexcept : data_ {const_cast<type_t*>(&(*items.begin()))}, size_ {items.size()} {}
    explicit span(const type_t* data, size_type size) : data_ {const_cast<type_t*>(data)}, size_ {size} {}
    explicit span(type_t* data, size_type size) : data_ {data}, size_ {size} {}
    template<xtd::size len_>
    constexpr span(const type_t (&array)[len_]) noexcept : data_ {array}, size_ {len_} {}
    template<xtd::size len_>
    constexpr span(type_t (&array)[len_]) noexcept : data_ {array}, size_ {len_} {}
    template< class array_type_t, xtd::size len_>
    constexpr span(const std::array<array_type_t, len_>& array) noexcept : data_ {const_cast<type_t*>(array.data())}, size_ {len_} {}
    template< class array_type_t, xtd::size len_>
    constexpr span(std::array<array_type_t, len_>& array) noexcept : data_ {array.data()}, size_ {len_} {}
    span(span&& items) = default;
    span(const span& items) = default;

    span& operator =(span&& items) = default;
    span& operator =(const span& items) = default;
    /// @}
    
    /// @name Public Properties
    
    /// @{
    const_reference back() const {
      if (empty()) throw argument_out_of_range_exception {};
      return *(data_ + size_ - 1);
    }

    const_iterator begin() const {return cbegin();}
    iterator begin() {return iterator {data_};}

    const_iterator cbegin() const {return const_iterator {data_};}
    const_iterator cend() const {return const_iterator {data_ + size_};}

    const_reverse_iterator crbegin() const {return const_reverse_iterator {data_ + size_};}
    reverse_iterator crend() const {return reverse_iterator {data_};}
    
    constexpr const_pointer data() const noexcept {return data_;}
    
    constexpr bool empty() const noexcept {return !size_;}

    const_iterator end() const {return cend();}
    iterator end() {return iterator {data_ + size_};}

    const_reference front() const {
      if (empty()) throw argument_out_of_range_exception {};
      return *data_;
    }
    
    const_reverse_iterator rbegin() const {return crbegin();}
    reverse_iterator rbegin() {return reverse_iterator {data_ + size_};}
    
    const_reverse_iterator rend() const {return crend();}
    reverse_iterator rend() {return reverse_iterator {data_};}

    constexpr size_type size() const noexcept {return size_;}
    
    constexpr size_type size_bytes() const noexcept {return size_ * sizeof(value_type);}
    /// @}
    
    /// @name Public Methods
    
    /// @{
    const_reference at(size_type index) const {
      if (index >= size_) throw argument_out_of_range_exception {};
      return *(data_ + index);
    }
    reference at(size_type index) {
      if (index >= size_) throw argument_out_of_range_exception {};
      return *(data_ + index);
    }

    template<xtd::size count__>
    span<element_type, count__> first() const {
      if (count__ > size_) throw argument_out_of_range_exception {};
      return span<element_type, count__> {data_, count__};
    }
    
    template<xtd::size count__>
    span<type_t, count__> last() const {
      if (count__ > size_) throw argument_out_of_range_exception {};
      return span<type_t, count__> {data_ + size_ - count__, count__};
    }
    
    span<type_t> subspan(size_type offset, size_type count) const {
      if (offset + count > size_) throw argument_out_of_range_exception {};
      return span<type_t> {data_ + offset, count};
    }

    string to_string() const noexcept override {return xtd::string::format("[{}]", xtd::string::join(", ", *this));}
    /// @}
    
    /// @name Public Operators
    
    /// @{
    const_reference operator[](size_type index) const {return at(index);}
    reference operator[](size_type index) {return at(index);}
    /// @}

  private:
    pointer data_ = null;
    size_type size_ = count_;
  };
}
