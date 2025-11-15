/// @file
/// @brief Contains xtd::read_only_span class.
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
#include "index_out_of_range_exception.hpp"
#include "is.hpp"
#include "null.hpp"
#include "object.hpp"
#include "ptrdiff.hpp"
#include "views/views.hpp"
#include "span.hpp"
#include "typeof.hpp"
#include <type_traits>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a non-owning view over a contiguous sequence of objects.
  /// @par Definition
  /// ```cpp
  /// template<class type_t, xtd::size extent = dynamic_extent>
  /// class read_only_span : public xtd::object, public xtd::iequatable<xtd::read_only_span<type_t, extent>>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/read_only_span>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks The class template xtd::read_only_span describes an object that can refer to a contiguous sequence of objects with the first element of the sequence at position zero. A read_only_span can either have a static extent, in which case the number of elements in the sequence is known at compile-time and encoded in the type, or a dynamic extent.
  /// @remarks The referenced data can't be modified through a xtd::read_only_span object. To prevent this, use a xtd::only_span`:
  /// ```cpp
  /// int numbers[] = {0, 1, 2};
  /// read_only_span<int> read_only_span_numbers = numbers;
  /// read_only_span_numbers[0] = 42; // ERROR: read_only_span_numbers[0] is read-only
  /// span<int> span_numbers = numbers;
  /// span_numbers[0] = 42; // numbers == {42, 1, 2};
  /// ```
  template<class type_t, xtd::size extent = dynamic_extent>
  class read_only_span : public xtd::object, public xtd::iequatable<xtd::read_only_span<type_t, extent>> {
  public:
    /// @name Public Aliases
    
    /// @{
    /// @brief Represents the read_only_span elemeent type.
    using element_type = std::add_cv_t<type_t>;
    /// @brief Represents the read_only_span value type.
    using value_type = std::add_cv_t<type_t>;
    /// @brief Represents the read_only_span size type (usually xtd::size).
    using size_type = xtd::size;
    /// @brief Represents the read_only_span difference type (usually xtd::ptrdiff).
    using difference_type = xtd::ptrdiff;
    /// @brief Represents the read_only_span pointer type.
    using pointer = const type_t*;
    /// @brief Represents the read_only_span const pointer type.
    using const_pointer = const type_t*;
    /// @brief Represents the read_only_span reference type.
    using reference = const type_t&;
    /// @brief Represents the read_only_span const reference type.
    using const_reference = const type_t&;
    /// @brief Represents the iterator of read_only_span value type.
    using iterator = const xtd::collections::generic::helpers::wrap_pointer_iterator<pointer>;
    /// @brief Represents the const iterator of read_only_span value type.
    using const_iterator = const xtd::collections::generic::helpers::wrap_pointer_iterator<pointer>;
    /// @brief Represents the reverse iterator of read_only_span value type.
    using reverse_iterator = const std::reverse_iterator<xtd::collections::generic::helpers::wrap_pointer_iterator<pointer>>;
    /// @brief Represents the const reverse iterator of read_only_span value type.
    using const_reverse_iterator = const std::reverse_iterator<xtd::collections::generic::helpers::wrap_pointer_iterator<pointer>>;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Creates an empty xtd::read_only_span whose xtd::read_only_span::data is null and xtd::read_only_span::size is 0.
    template <xtd::size count = 0>
    constexpr read_only_span() : data_ {xtd::null}, length_ {0} {}
    
    /// @brief
    /// @brief Creates an xtd::read_only_span with specified iterators.
    /// @param first The iterator to the first element of the sequence.
    /// @param last The iterator to the last element of the sequence.
    template<class iterator_t>
    constexpr read_only_span(iterator_t first, iterator_t last) : data_ { & (*first)}, length_ {extent != dynamic_extent ? extent : static_cast<size_type>(std::distance(first, last))} {}
    /* Conflict with read_only_span(collection_t& items, xtd::size count)
    /// @brief Creates an xtd::read_only_span with specified iterator and count.
    /// @param first The iterator to the first element of the sequence.
    /// @param count The number of elements in the iteration.
    template<class iterator_t>
    read_only_span(iterator_t first, xtd::size count) : data_ {&(*first)}, length_ {extent != dynamic_extent ? extent : count} {}
     */
    #if defined(__xtd__cpp_lib_type_identity)
    /// @brief Creates an xtd::read_only_span with specified native array.
    /// @param array The native array to construct a view for.
    template<xtd::size len>
    constexpr read_only_span(const std::type_identity_t<element_type> (&array)[len]) noexcept : data_ {array}, length_ {extent != dynamic_extent ? extent : len} {}
    #else
    /// @brief Creates an xtd::read_only_span with specified native array.
    /// @param array The native array to construct a view for.
    template<xtd::size len>
    constexpr read_only_span(const element_type(&array)[len]) noexcept : data_ {array}, length_ {extent != dynamic_extent ? extent : len} {}
    #endif
    /// @brief Creates an xtd::read_only_span with specified std::array.
    /// @param array The std::array to construct a view for.
    template<class array_type_t, xtd::size len>
    constexpr read_only_span(const std::array<array_type_t, len>& array) noexcept : data_ {array.data()}, length_ {extent != dynamic_extent ? extent : len} {}
    #if defined(__xtd__cpp_lib_ranges)
    /// @brief Creates an xtd::read_only_span with specified range.
    /// @param range The range to construct a view for.
    template<class range_t>
    constexpr read_only_span(range_t&& range) noexcept : data_ {std::ranges::data(range)}, length_ {extent != dynamic_extent ? extent : std::ranges::size(range)} {}
    #else
    /// @brief Creates an xtd::read_only_span with specified range.
    /// @param range The range to construct a view for.
    template<class range_t>
    constexpr read_only_span(range_t&& range) noexcept : data_ {range.data()}, length_ {extent != dynamic_extent ? extent : range.size()} {}
    #endif
    /// @brief Creates an xtd::read_only_span with specified initializer list.
    /// @param items The initializer list to construct a view for.
    constexpr read_only_span(std::initializer_list<type_t> items) noexcept : data_ {items.begin()}, length_ {extent != dynamic_extent ? extent : items.size()} {}
    /* Conflict with read_only_span(range_t&& range) noexcept
    /// @brief Creates an xtd::span with specified collection.
    /// @param items The collection to construct a view for.
    /// @exception xtd::argument_out_of_range_exception if length is greater than items size.
    template<class collection_t>
    constexpr read_only_span(collection_t& items) noexcept : span {items, size_type {0}, items.size()} {}
     */
    /// @brief Creates an xtd::read_only_span with specified collection and count.
    /// @param items The collection to construct a view for.
    /// @param length The number of elements in the collection.
    /// @exception xtd::argument_out_of_range_exception if length is greater than items size.
    template<class collection_t>
    constexpr read_only_span(const collection_t& items, size_type length) : read_only_span {items, size_type {0}, length} {}
    /// @brief Creates an xtd::read_only_span with specified collection, offest and count.
    /// @param items The collection to construct a view for.
    /// @param start The offset in the collection.
    /// @param length The number of elements in the collection.
    /// @exception xtd::argument_out_of_range_exception if offset or offset + length are greater than items size.
    template<class collection_t>
    constexpr read_only_span(const collection_t& items, size_type start, size_type length) : data_ {items.data() + start}, length_ {extent != dynamic_extent ? extent : length} {
      if (start + length > items.size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
    }
    /// @brief Creates an xtd::read_only_span with specified data pointer and count.
    /// @param data The data pointer to construct a view for.
    /// @param length The number of elements to constuct.
    constexpr read_only_span(const type_t* data, size_type length) : data_ {data}, length_ {extent != dynamic_extent ? extent : length} {
      if (!data) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_null);
    }
    /// @}
    
    /// @cond
    constexpr read_only_span(read_only_span&& items) = default;
    constexpr read_only_span(const read_only_span& items) = default;
    
    read_only_span& operator =(read_only_span&& items) = default;
    read_only_span& operator =(const read_only_span& items) = default;
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets the last element.
    /// @return The last element.
    /// @exception argument_out_of_range_exception if xtd::san i empty.
    const_reference back() const {
      if (empty()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      return *(data_ + length_ - 1);
    }
    
    /// @brief Returns an iterator to the beginning.
    /// @return The iterator of the first element.
    const_iterator begin() const {return cbegin();}
    
    /// @brief Returns an iterator to the beginning.
    /// @return The iterator of the first element.
    const_iterator cbegin() const {return const_iterator {data_};}
    /// @brief Returns an iterator to the end.
    /// @return The iterator to the element following the last element.
    const_iterator cend() const {return const_iterator {data_ + length_};}
    
    /// @brief Returns a reverse iterator to the beginning.
    /// @return The reverse iterator of the first element.
    const_reverse_iterator crbegin() const {return const_reverse_iterator {iterator {data_ + length_}};}
    /// @brief Returns a reverse iterator to the end.
    /// @return The reverse iterator to the element following the last element.
    const_reverse_iterator crend() const {return const_reverse_iterator {iterator {data_}};}
    
    /// @brief Gets direct access to the underlying contiguous storage
    /// @return A pointer to the beginning of the sequence.
    constexpr const_pointer data() const noexcept {return data_;}
    
    /// @brief Returns a value that indicates whether the current xtd::read_only_span <type_t> is empty.
    /// @return `true` if the current read_only_span is empty; otherwise, `false`.
    constexpr bool empty() const noexcept {return is_empty();}
    
    /// @brief Returns an empty xtd::read_only_span <type_t> object.
    /// @return An empty xtd::read_only_span <type_t> object.
    static const read_only_span empty_read_only_span;
    
    /// @brief Returns an iterator to the end.
    /// @return The iterator to the element following the last element.
    const_iterator end() const {return cend();}
    
    /// @brief Gets the first element.
    /// @return The first element.
    /// @exception argument_out_of_range_exception if xtd::san i empty.
    const_reference front() const {
      if (empty()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      return *data_;
    }
    
    /// @brief Returns a value that indicates whether the current xtd::read_only_span <type_t> is empty.
    /// @return `true` if the current read_only_span is empty; otherwise, `false`.
    constexpr bool is_empty() const noexcept {return !length_;}
    
    /// @brief Returns the length of the current read_only_span.
    /// @return The length of the current read_only_span.
    constexpr size_type length() const noexcept {return length_;}
    
    /// @brief Returns a reverse iterator to the beginning.
    /// @return The reverse iterator of the first element.
    const_reverse_iterator rbegin() const {return crbegin();}
    
    /// @brief Returns a reverse iterator to the end.
    /// @return The reverse iterator to the element following the last element.
    const_reverse_iterator rend() const {return crend();}
    
    /// @brief Returns the number of elements
    /// @return The number of elements in the read_only_span.
    constexpr size_type size() const noexcept {return length();}
    
    /// @brief Returns the size of the sequence in bytes
    /// @return The size of the sequence in bytes, i.e., `size() * sizeof(element_type)`.
    constexpr size_type size_bytes() const noexcept {return length_ * sizeof(value_type);}
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Gets the specified element with bounds checking.
    /// @param pos The position of the element to return.
    /// @return Reference to the requested element.
    /// @exception xtd::index_out_of_range_exception `index` is less than zero or greater than or equal to xtd::read_only_span::length.
    const_reference at(size_type pos) const {
      if (pos >= length_) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      return *(data_ + pos);
    }
    
    /// @brief Copies the contents of this xtd::read_only_span <type_t> into a destination xtd:span <type_t>.
    /// @param destinaton The destination xtd::read_only_span <type_t> object.
    /// @exception xtd::argument_exception `destination` is shorter than the source xtd::span <type_t>.
    template<xtd::size length>
    void copy_to(span<type_t, length>& destination) const {
      if (!try_copy_to(destination))
        xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
    }
    
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    bool equals(const object& obj) const noexcept override {return is<read_only_span<value_type>>(obj) && equals(static_cast<const read_only_span<value_type>& > (obj));}
    /// @brief Indicates whether the current object is equal to another object of the same type.
    /// @param obj An object to compare with this object.
    /// @return `true` if the current object is equal to the other parameter; otherwise, `false`.
    bool equals(const read_only_span& rhs) const noexcept override {return length() == rhs.length() && data() == rhs.data();}
    
    /// @brief Obtains a subspan consisting of the first `count` elements of the sequence.
    /// @param count The count elements.
    /// @return A read_only_span `r` that is a view over the first `count` elements of `*this`, such that `r.data() == this->data() && r.size() == count`.
    template<xtd::size count>
    read_only_span<type_t, count> first() const {
      if (count > length_) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      return read_only_span<type_t, count> {data_, count};
    }
    /// @brief Obtains a subspan consisting of the first `count` elements of the sequence.
    /// @param count The count elements.
    /// @return A read_only_span `r` that is a view over the first `count` elements of `*this`, such that `r.data() == this->data() && r.size() == count`.
    read_only_span<type_t> first(xtd::size count) const {
      if (count > length_) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      return read_only_span<type_t> {data_, count};
    }
    
    /// @brief Serves as a hash function for a particular type.
    /// @return A hash code for the current object.
    xtd::size get_hash_code() const noexcept override {
      auto result = hash_code {};
      for (const auto& item : *this)
        result.add(item);
      return result.to_hash_code();
    }
    
    /// @brief Obtains a subspan consisting of the last N elements of the sequence
    /// @param count The count elements.
    /// @return A read_only_span `r` that is a view over the last `count` elements of `*this`, such that `r.data() == this->data() + (this->size() - count) && r.size() == count`.
    template<xtd::size count>
    read_only_span<type_t, count> last() const {
      if (count > length_) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      return read_only_span<type_t, count> {data_ + length_ - count, count};
    }
    /// @brief Obtains a subspan consisting of the last N elements of the sequence
    /// @param count The count elements.
    /// @return A read_only_span `r` that is a view over the last `count` elements of `*this`, such that `r.data() == this->data() + (this->size() - count) && r.size() == count`.
    read_only_span<type_t> last(xtd::size count) const {
      if (count > length_) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      return read_only_span<type_t> {data_ + length_ - count, count};
    }
    
    /// @brief Forms a slice out of the current read_only_span starting at a specified index for a specified length.
    /// @param start The zero-based index at which to begin this slice.
    /// @param length The desired length for the slice.
    /// @return A read_only_span that consists of length elements from the current read_only_span starting at start.
    /// @exception xtd::argument_out_of_range_exception `start` or `start + length` is less than zero or greater than xtd::read_only_span::length.
    template<xtd::size start, size_type lenght = xtd::dynamic_extent>
    read_only_span<type_t> slice() const {
      return lenght == xtd::dynamic_extent ? slice(start) : slice(start, lenght);
    }
    
    /// @brief Forms a slice out of the current read_only_span that begins at a specified index.
    /// @param start The zero-based index at which to begin the slice.
    /// @return A read_only_span that consists of all elements of the current read_only_span from `start` to the end of the read_only_span.
    /// @exception xtd::argument_out_of_range_exception `start` is less than zero or greater than xtd::read_only_span::length.
    read_only_span<type_t> slice(size_type start) const {
      return slice(start, length_ - start);
    }
    
    /// @brief Forms a slice out of the current read_only_span starting at a specified index for a specified length.
    /// @param start The zero-based index at which to begin this slice.
    /// @param length The desired length for the slice.
    /// @return A read_only_span that consists of length elements from the current read_only_span starting at start.
    /// @exception xtd::argument_out_of_range_exception `start` or `start + length` is less than zero or greater than xtd::read_only_span::length.
    read_only_span<type_t> slice(size_type start, size_type length) const {
      if (start > length_ || start + length > length_) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      return read_only_span<type_t> {data_ + start, length};
    }
    
    /// @brief Forms a subspan of the current read_only_span starting at a specified index for a specified length.
    /// @param offset The zero-based index at which to begin this slice.
    /// @param count The desired length for the slice.
    /// @return A read_only_span that consists of length elements from the current read_only_span starting at start.
    /// @exception xtd::argument_out_of_range_exception `offset` or `offset + count` is less than zero or greater than xtd::read_only_span::length.
    template<xtd::size offset, size_type count = xtd::dynamic_extent>
    read_only_span<type_t> subspan() const {
      return count == xtd::dynamic_extent ? slice(offset) : slice(offset, count);
    }
    
    /// @brief Forms a subspan of the current read_only_span starting at a specified index for a specified length.
    /// @param offset The zero-based index at which to begin this slice.
    /// @param count The desired length for the slice.
    /// @return A read_only_span that consists of length elements from the current read_only_span starting at start.
    /// @exception xtd::argument_out_of_range_exception `offset` or `offset + count` is less than zero or greater than xtd::read_only_span::length.
    read_only_span<type_t> subspan(size_type offset, size_type count = xtd::dynamic_extent) const {
      return count == xtd::dynamic_extent ? slice(offset) : slice(offset, count);
    }
    
    /// @brief Copies the contents of this read_only_span into a new array.
    /// @return An array containing the data in the current read_only_span.
    xtd::array<std::remove_cv_t<type_t>> to_array() const noexcept {
      return data_ && length_ ? xtd::array<std::remove_cv_t<type_t>>(data_, length_) : xtd::array<std::remove_cv_t<type_t >> {};
    }
    
    /// @brief Returns the string representation of this xtd::read_only_span <type_t> object.
    /// @return The string representation of this xtd::read_only_span <type_t> object.
    /// @remarks For a xtd::read_only_span <type_t>, the xtd::read_only_span::to_string method returns a xtd::string that contains the characters pointed to by the xtd::read_only_span <type_t>. Otherwise, it returns a xtd::string with collection sequance string of the elements that the xtd::read_only_span <type_t> contains separated by `, `.
    string to_string() const noexcept override {
      if (typeof_<type_t>() == typeof_<char>()) return xtd::string::join("", *this);
      return xtd::string::format("[{}]", xtd::string::join(", ", *this));
    }
    
    /// @brief Attempts to copy the current xtd::read_only_span <type_t> to a destination xtd::read_only_span <type_t> and returns a value that indicates whether the copy operation succeeded.
    /// @param destination The target of the copy operation.
    /// @return `true` if the copy operation succeeded; otherwise, `false`.
    /// @remarks This method copies all of `source` to `destination` even if `source` and `destination` overlap.
    template<xtd::size length>
    bool try_copy_to(span<type_t, length>& destination) const noexcept {
      if (destination.length() < this->length()) return false;
      for (auto index = xtd::size {}; index < length_; ++index)
        destination.at(index) = at(index);
      return true;
    }
    /// @}
    
    /// @name Public Operators
    
    /// @{
    /// @brief Gets the element at the specified zero-based index.
    /// @param index The zero-based index of the element.
    /// @return The element at the specified index.
    /// @exception xtd::index_out_of_range_exception `index` is less than zero or greater than or equal to xtd::read_only_span::length.
    const_reference operator[](size_type index) const {return at(index);}
    /// @}
    
  private:
    pointer data_ = null;
    size_type length_ = size_type {};
  };
  
  template<class type_t, xtd::size extent>
  inline const read_only_span<type_t, extent> read_only_span<type_t, extent>::empty_read_only_span;
  
  /// @cond
  // Deduction guides for xtd::read_only_span
  // {
  template<class iterator_t>
  read_only_span(iterator_t first, iterator_t last) -> read_only_span<typename iterator_t::value_type>;
  
  template<class type_t, xtd::size len>
  read_only_span(const type_t (&array)[len]) -> read_only_span<type_t>;
  
  template< class type_t, xtd::size len>
  read_only_span(const std::array<type_t, len>& array) -> read_only_span<type_t>;
  
  #if defined(__xtd__cpp_lib_ranges)
  template<class range_t>
  read_only_span(range_t&& items) -> read_only_span<typename std::remove_reference_t<std::ranges::range_reference_t<range_t>>>;
  #else
  template<class range_t>
  read_only_span(range_t&& items) -> read_only_span<typename range_t::value_type>;
  #endif
  
  template<class collection_t>
  read_only_span(const collection_t& items) -> read_only_span<typename collection_t::value_type>;
  
  template<class collection_t>
  read_only_span(const collection_t& items, xtd::size) -> read_only_span<typename collection_t::value_type>;
  
  template<class collection_t>
  read_only_span(const collection_t& items, xtd::size, xtd::size) -> read_only_span<typename collection_t::value_type>;
  
  template<class type_t>
  read_only_span(const type_t* data, xtd::size size) -> read_only_span<type_t>;
  // }
  /// @endcond
}
