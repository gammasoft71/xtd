/// @file
/// @brief Contains xtd::span class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__
#include "collections/generic/helpers/wrap_pointer_iterator.hpp"
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
#include <ranges>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a non-owning view over a contiguous sequence of objects.
  /// @par Definition
  /// ```cpp
  /// template<class type_t, xtd::size extent = dynamic_extent>
  /// class span : public xtd::object, public xtd::iequatable<xtd::span<type_t, extent>>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/span>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks The class template xtd::span describes an object that can refer to a contiguous sequence of objects with the first element of the sequence at position zero. A span can either have a static extent, in which case the number of elements in the sequence is known at compile-time and encoded in the type, or a dynamic extent.
  /// @par Examples
  /// Create a span from memory.
  /// @include span_from_memory.cpp
  ///
  /// Create a span over an array.
  /// @include span_over_array.cpp
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
    using reverse_iterator = std::reverse_iterator<iterator>;
    /// @brief Represents the const reverse iterator of span value type.
    using const_reverse_iterator = const std::reverse_iterator<iterator>;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Creates an empty xtd::span whose xtd::span::data is null and xtd::span::size is 0.
    template <xtd::size count = 0>
    span() : data_ {xtd::null}, length_ {0} {};
    
    /// @brief 
    /// @brief Creates an xtd::span with specified iterators.
    /// @param first The iterator to the first element of the sequence.
    /// @param last The iterator to the last element of the sequence.
    template<class iterator_t>
    span(iterator_t first, iterator_t last) : data_ {const_cast<type_t*>(&(*first))}, length_ {extent != dynamic_extent ? extent : static_cast<size_type>(std::distance(first, last))} {}
#if defined(__xtd__cpp_lib_ranges)
    /// @brief Creates an xtd::span with specified range.
    /// @param range The range to construct a view for.
    template<class range_t>
    span(range_t&& range) noexcept : data_ {const_cast<type_t*>(std::ranges::data(range))}, length_ {extent != dynamic_extent ? extent : std::ranges::size(range)} {}
#else
    /// @brief Creates an xtd::span with specified range.
    /// @param range The range to construct a view for.
    template<class range_t>
    span(range_t&& range) noexcept : data_ {const_cast<type_t*>(range.data())}, length_ {extent != dynamic_extent ? extent : range.size()} {}
#endif
    /// @brief Creates an xtd::span with specified collection.
    /// @param items The collection to construct a view for.
    template<class collection_t>
    span(const collection_t& items) noexcept : span {items, size_type {0}, items.size()} {}
    /// @brief Creates an xtd::span with specified collection.
    /// @param items The collection to construct a view for.
    template<class collection_t>
    span(collection_t& items) noexcept : span {items, size_type {0}, items.size()} {}
    /// @brief Creates an xtd::span with specified collection and count.
    /// @param items The collection to construct a view for.
    /// @param count The number of elements in the collection.
    /// @exception xtd::argument_out_of_range_exception if count is greater than items size.
    template<class collection_t>
    span(const collection_t& items, xtd::size count) : span {items, size_type {0}, count} {}
    /// @brief Creates an xtd::span with specified collection and count.
    /// @param items The collection to construct a view for.
    /// @param count The number of elements in the collection.
    /// @exception xtd::argument_out_of_range_exception if count is greater than items size.
    template<class collection_t>
    span(collection_t& items, xtd::size count) : span {items, size_type {0}, count} {}
    /// @brief Creates an xtd::span with specified collection, offest and count.
    /// @param items The collection to construct a view for.
    /// @param offset The offset in the collection.
    /// @param count The number of elements in the collection.
    /// @exception xtd::argument_out_of_range_exception if offset or offset + count are greater than items size.
    template<class collection_t>
    span(const collection_t& items, xtd::size offset, xtd::size count) : data_ {const_cast<type_t*>(items.data() + offset)}, length_ {extent != dynamic_extent ? extent : count} {
      if (offset + count > items.size()) throw argument_out_of_range_exception {};
    }
    /// @brief Creates an xtd::span with specified collection, offest and count.
    /// @param items The collection to construct a view for.
    /// @param offset The offset in the collection.
    /// @param count The number of elements in the collection.
    /// @exception xtd::argument_out_of_range_exception if offset or offset + count are greater than items size.
    template<class collection_t>
    span(collection_t& items, xtd::size offset, xtd::size count) : data_ {const_cast<type_t*>(items.data()) + offset}, length_ {extent != dynamic_extent ? extent : count} {
      if (offset + count > items.size()) throw argument_out_of_range_exception {};
    }
    /// @brief Creates an xtd::span with specified initializer list.
    /// @param items The initializer list to construct a view for.
    span(std::initializer_list<type_t> items) noexcept : data_ {const_cast<type_t*>(&(*items.begin()))}, length_ {extent != dynamic_extent ? extent : items.size()} {}
    /// @brief Creates an xtd::span with specified data pointer and count.
    /// @param data The data pointer to construct a view for.
    /// @param count The number of elements to constuct.
    span(const type_t* data, size_type count) : data_ {const_cast<type_t*>(data)}, length_ {extent != dynamic_extent ? extent : count} {
      if (!data) throw argument_null_exception {};
    }
    /// @brief Creates an xtd::span with specified data pointer and count.
    /// @param data The data pointer to construct a view for.
    /// @param count The number of elements to constuct.
    span(type_t* data, size_type count) : data_ {data}, length_ {extent != dynamic_extent ? extent : count} {
      if (!data) throw argument_null_exception {};
    }
    /// @brief Creates an xtd::span with specified native array.
    /// @param array The native array to construct a view for.
    template<xtd::size len>
    constexpr span(const type_t (&array)[len]) noexcept : data_ {array}, length_ {extent != dynamic_extent ? extent : len} {}
    /// @brief Creates an xtd::span with specified native array.
    /// @param array The native array to construct a view for.
    template<xtd::size len>
    constexpr span(type_t (&array)[len]) noexcept : data_ {array}, length_ {extent != dynamic_extent ? extent : len} {}
    /// @brief Creates an xtd::span with specified std::array.
    /// @param array The std::array to construct a view for.
    template<class array_type_t, xtd::size len>
    constexpr span(const std::array<array_type_t, len>& array) noexcept : data_ {const_cast<type_t*>(array.data())}, length_ {extent != dynamic_extent ? extent : len} {}
    /// @brief Creates an xtd::span with specified std::array.
    /// @param array The std::array to construct a view for.
    template<class array_type_t, xtd::size len>
    constexpr span(std::array<array_type_t, len>& array) noexcept : data_ {array.data()}, length_ {extent != dynamic_extent ? extent : len} {}
    /// @}

    /// @cond
    span(span&& items) = default;
    span(const span& items) = default;
    
    span& operator =(span&& items) = default;
    span& operator =(const span& items) = default;
    /// @endcond
    
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
    
    const_reverse_iterator crbegin() const {return const_reverse_iterator {iterator {data_ + length_}};}
    const_reverse_iterator crend() const {return const_reverse_iterator {iterator {data_}};}
    
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
    reverse_iterator rbegin() {return reverse_iterator {iterator {data_ + length_}};}
    
    const_reverse_iterator rend() const {return crend();}
    reverse_iterator rend() {return reverse_iterator {iterator {data_}};}
    
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

    template<xtd::size start, size_type lenght = xtd::dynamic_extent>
    span<type_t> slice() const {
      return lenght == xtd::dynamic_extent ? slice(start) : slice(start, lenght);
    }

    span<type_t> slice(size_type start) const {
      return slice(start, length_ - start);
    }
    
    span<type_t> slice(size_type start, size_type length) const {
      if (start + length > length_) throw argument_out_of_range_exception {};
      return span<type_t> {data_ + start, length};
    }

    template<xtd::size offset, size_type count = xtd::dynamic_extent>
    span<type_t> subspan() const {
      return count == xtd::dynamic_extent ? slice(offset) : slice(offset, count);
    }
    
    span<type_t> subspan(size_type offset, size_type count = xtd::dynamic_extent) const {
      return count == xtd::dynamic_extent ? slice(offset) : slice(offset, count);
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
  
  template<class range_t>
  span(range_t&& items) noexcept -> span<typename range_t::value_type>;
  
  template<class collection_t>
  span(const collection_t& items) noexcept -> span<typename collection_t::value_type>;
  
  template<class collection_t>
  span(collection_t& items) noexcept -> span<typename collection_t::value_type>;
  
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
