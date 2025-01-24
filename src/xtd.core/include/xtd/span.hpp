/// @file
/// @brief Contains xtd::span class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "collections/generic/helpers/wrap_pointer_iterator.hpp"
#include "collections/generic/helpers/wrap_pointer_reverse_iterator.hpp"
#include "argument_null_exception.hpp"
#include "argument_out_of_range_exception.hpp"
#include "array.hpp"
#include "dynamic_extent.hpp"
#include "iequatable.hpp"
#include "is.hpp"
#include "null.hpp"
#include "object.hpp"
#include "ptrdiff.hpp"
#include "typeof.hpp"
#include <type_traits>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template<class type_t, xtd::size extent = dynamic_extent>
  class span : public xtd::object, public xtd::iequatable<xtd::span<type_t, extent>> {
  public:
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
    using iterator = const xtd::collections::generic::helpers::wrap_pointer_iterator<pointer>;
    /// @brief Represents the const iterator of span value type.
    using const_iterator = const xtd::collections::generic::helpers::wrap_pointer_iterator<pointer>;
    /// @brief Represents the reverse iterator of span value type.
    using reverse_iterator = xtd::collections::generic::helpers::wrap_pointer_reverse_iterator<pointer>;
    /// @brief Represents the const reverse iterator of span value type.
    using const_reverse_iterator = xtd::collections::generic::helpers::wrap_pointer_reverse_iterator<pointer>;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    
    template <xtd::size count = 0>
    span() : data_ {xtd::null}, length_ {0} {};
    
    template<class iterator_t>
    span(iterator_t first, iterator_t last) : data_ {const_cast<type_t*>(&(*first))}, length_ {extent != dynamic_extent ? extent : static_cast<size_type>(std::distance(first, last))} {}
    
    template<class collection_t>
    explicit span(const collection_t& items) noexcept : span {items, size_type {0}, items.size()} {}
    template<class collection_t>
    explicit span(collection_t& items) noexcept : span {items, size_type {0}, items.size()} {}
    template<class collection_t>
    span(const collection_t& items, xtd::size count) : span {items, size_type {0}, count} {}
    template<class collection_t>
    span(collection_t& items, xtd::size count) : span {items, size_type {0}, count} {}
    template<class collection_t>
    span(const collection_t& items, xtd::size offset, xtd::size count) : data_ {const_cast<type_t*>(items.data() + offset)}, length_ {extent != dynamic_extent ? extent : count} {
      if (offset + count > items.size()) throw argument_out_of_range_exception {};
    }
    template<class collection_t>
    span(collection_t& items, xtd::size offset, xtd::size count) : data_ {const_cast<type_t*>(items.data()) + offset}, length_ {extent != dynamic_extent ? extent : count} {
      if (offset + count > items.size()) throw argument_out_of_range_exception {};
    }
    
    span(std::initializer_list<type_t> items) noexcept : data_ {const_cast<type_t*>(&(*items.begin()))}, length_ {extent != dynamic_extent ? extent : items.size()} {}
    
    span(const type_t* data, size_type size) : data_ {const_cast<type_t*>(data)}, length_ {extent != dynamic_extent ? extent : size} {
      if (!data) throw argument_null_exception {};
    }
    span(type_t* data, size_type size) : data_ {data}, length_ {extent != dynamic_extent ? extent : size} {
      if (!data) throw argument_null_exception {};
    }
    
    template<xtd::size len>
    constexpr span(const type_t (&array)[len]) noexcept : data_ {array}, length_ {extent != dynamic_extent ? extent : len} {}
    template<xtd::size len>
    constexpr span(type_t (&array)[len]) noexcept : data_ {array}, length_ {extent != dynamic_extent ? extent : len} {}
    
    template<class array_type_t, xtd::size len>
    constexpr span(const std::array<array_type_t, len>& array) noexcept : data_ {const_cast<type_t*>(array.data())}, length_ {extent != dynamic_extent ? extent : len} {}
    template<class array_type_t, xtd::size len>
    constexpr span(std::array<array_type_t, len>& array) noexcept : data_ {array.data()}, length_ {extent != dynamic_extent ? extent : len} {}
    
    span(span&& items) = default;
    span(const span& items) = default;
    
    span& operator =(span&& items) = default;
    span& operator =(const span& items) = default;
    /// @}
    
    /// @name Public Properties
    
    /// @{
    const_reference back() const {
      if (empty()) throw argument_out_of_range_exception {};
      return *(data_ + length_ - 1);
    }
    
    const_iterator begin() const {return cbegin();}
    iterator begin() {return iterator {data_};}
    
    const_iterator cbegin() const {return const_iterator {data_};}
    const_iterator cend() const {return const_iterator {data_ + length_};}
    
    const_reverse_iterator crbegin() const {return const_reverse_iterator {data_ + length_};}
    reverse_iterator crend() const {return reverse_iterator {data_};}
    
    constexpr const_pointer data() const noexcept {return data_;}
    
    constexpr bool empty() const noexcept {return is_empty();}
    
    const_iterator end() const {return cend();}
    iterator end() {return iterator {data_ + length_};}
    
    const_reference front() const {
      if (empty()) throw argument_out_of_range_exception {};
      return *data_;
    }
    
    constexpr bool is_empty() const noexcept {return !length_;}

    constexpr size_type length() const noexcept {return length_;}

    const_reverse_iterator rbegin() const {return crbegin();}
    reverse_iterator rbegin() {return reverse_iterator {data_ + length_};}
    
    const_reverse_iterator rend() const {return crend();}
    reverse_iterator rend() {return reverse_iterator {data_};}
    
    constexpr size_type size() const noexcept {return length();}
    
    constexpr size_type size_bytes() const noexcept {return length_ * sizeof(value_type);}
    /// @}
    
    /// @name Public Methods
    
    /// @{
    const_reference at(size_type index) const {
      if (index >= length_) throw argument_out_of_range_exception {};
      return *(data_ + index);
    }
    reference at(size_type index) {
      if (index >= length_) throw argument_out_of_range_exception {};
      return *(data_ + index);
    }
    
    void clear() noexcept {
      for (auto& item : *this)
        item = value_type {};
    }
    
    bool equals(const object& obj) const noexcept override {return is<span<value_type>>(obj) && equals(static_cast<const span<value_type>&>(obj));}
    bool equals(const span& rhs) const noexcept override {
      if (size() != rhs.size()) return false;
      for (size_type i = 0; i < size(); i++)
        if (!xtd::collections::generic::helpers::equator<type_t> {}(at(i), rhs.at(i))) return false;
      return true;
    }
    
    template<xtd::size count__>
    span<element_type, count__> first() const {
      if (count__ > length_) throw argument_out_of_range_exception {};
      return span<element_type, count__> {data_, count__};
    }
    
    template<xtd::size count__>
    span<type_t, count__> last() const {
      if (count__ > length_) throw argument_out_of_range_exception {};
      return span<type_t, count__> {data_ + length_ - count__, count__};
    }
    
    span<type_t> slice(size_type offset, size_type count) const {
      if (offset + count > length_) throw argument_out_of_range_exception {};
      return span<type_t> {data_ + offset, count};
    }
    
    span<type_t> subspan(size_type offset, size_type count) const {
      return slice(offset, count);
    }
    
    xtd::array<type_t> to_array() const noexcept {
      if (data_ == null || length_ == 0) return xtd::array<type_t> {};
      return xtd::array<type_t> {data_, length_};
    }
    
    string to_string() const noexcept override {
      if (typeof_<type_t>() == typeof_<char>()) return xtd::string::join("", *this);
      return xtd::string::format("[{}]", xtd::string::join(", ", *this));
    }
    /// @}
    
    /// @name Public Operators
    
    /// @{
    const_reference operator[](size_type index) const {return at(index);}
    reference operator[](size_type index) {return at(index);}
    /// @}

  private:
    pointer data_ = null;
    size_type length_ = size_type {};
  };
  
  /// @cond
  // C++17 deduction guides for xtd::span
  // {
  template<class iterator_t>
  span(iterator_t first, iterator_t last) -> span<typename iterator_t::value_type>;
  
  template<class collection_t>
  explicit span(const collection_t& items) noexcept -> span<typename collection_t::value_type>;
  
  template<class collection_t>
  explicit span(collection_t& items) noexcept -> span<typename collection_t::value_type>;
  
  template<class collection_t>
  span(const collection_t& items, xtd::size) -> span<typename collection_t::value_type>;
  
  template<class collection_t>
  span(collection_t& items, xtd::size) -> span<typename collection_t::value_type>;
  
  template<class collection_t>
  span(const collection_t& items, xtd::size, xtd::size) -> span<typename collection_t::value_type>;
  
  template<class collection_t>
  span(collection_t& items, xtd::size, xtd::size) -> span<typename collection_t::value_type>;

  template<class type_t>
  span(std::initializer_list<type_t>) noexcept -> span<type_t>;
  
  template<class type_t>
  span(const type_t* data, xtd::size size) -> span<type_t>;
  
  template<class type_t>
  span(type_t* data, xtd::size size) -> span<type_t>;
  
  template<class type_t, xtd::size len>
  span(const type_t (&array)[len]) noexcept -> span<type_t>;
  
  template<class type_t, xtd::size len>
  span(type_t (&array)[len]) noexcept -> span<type_t>;
  
  template< class type_t, xtd::size len>
  span(const std::array<type_t, len>& array) noexcept -> span<type_t>;
  
  template< class type_t, xtd::size len>
  span(std::array<type_t, len>& array) noexcept -> span<type_t>;
  // }
  /// @endcond
}
