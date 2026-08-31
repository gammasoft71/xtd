/// @file
/// @brief Contains xtd::span class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "internal/__span_definitions.hpp"
#undef __XTD_CORE_INTERNAL__
#include "collections/generic/helpers/raw_array.hpp"
#include "collections/generic/helpers/wrap_pointer_iterator.hpp"
#include "collections/generic/enumerable.hpp"
#include "array.hpp"
#include "dynamic_extent.hpp"
#include "iequatable.hpp"
#include "index.hpp"
#include "is.hpp"
#include "iterable.hpp"
#include "iterable_value_type.hpp"
#include "null.hpp"
#include "object.hpp"
#include "ptrdiff.hpp"
#include "range.hpp"
#include "views/views.hpp"
#include "typeof.hpp"
#include <span>
#include <type_traits>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a non-owning view over a contiguous sequence of objects.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t, xtd::usize extent = dynamic_extent>
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
  /// @remarks The referenced data can be modified through a xtd::span object. To prevent this, construct a xtd::span over a `const type_t`:
  /// ```cpp
  /// int numbers[] = {0, 1, 2};
  /// span<int> span_numbers = numbers;
  /// span_numbers[0] = 42; // numbers == {42, 1, 2};
  /// span<const int> cspan_numbers = numbers;
  /// cspan_numbers[0] = 0; // ERROR: cspan_numbers[0] is read-only
  /// ```
  ///
  /// @par Examples
  /// Create a span from memory.
  /// @include span_from_memory.cpp
  ///
  /// Create a span over an array.
  /// @include span_over_array.cpp
  template<typename type_t, xtd::usize extent>
  class span : public xtd::object, public xtd::iequatable<xtd::span<type_t, extent>>, public xtd::collections::generic::ienumerable<type_t> {
  public:
    /// @name Public Aliases
    
    /// @{
    /// @brief Represents the span elemeent type.
    using element_type = type_t;
    /// @brief Represents the span value type.
    using value_type = std::remove_cv_t<type_t>;
    /// @brief Represents the span size type (usually xtd::usize).
    using size_type = xtd::usize;
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
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Creates an empty xtd::span whose xtd::span::data is null and xtd::span::size is 0.
    template <xtd::usize count = 0>
    constexpr span() : data_ {xtd::null}, length_ {0} {}
    
    /// @brief
    /// @brief Creates an xtd::span with specified iterators.
    /// @param first The iterator to the first element of the sequence.
    /// @param last The iterator to the last element of the sequence.
    template<typename iterator_t>
    constexpr span(iterator_t first, iterator_t last) : data_ {const_cast<pointer>(&(*first))}, length_ {extent != dynamic_extent ? extent : static_cast<size_type>(std::distance(first, last))} {}
    /* Conflict with span(collection_t& items, xtd::usize count)
    /// @brief Creates an xtd::span with specified iterator and count.
    /// @param first The iterator to the first element of the sequence.
    /// @param count The number of elements in the iteration.
    template<typename iterator_t>
    span(iterator_t first, xtd::usize count) : data_ {&(*first)}, length_ {extent != dynamic_extent ? extent : count} {}
     */
    #if defined(__xtd__cpp_lib_type_identity)
    /// @brief Creates an xtd::span with specified native array.
    /// @param array The native array to construct a view for.
    template<xtd::usize len>
    constexpr span(std::type_identity_t<element_type> (&array)[len]) noexcept : data_ {array}, length_ {extent != dynamic_extent ? extent : len} {}
    #else
    /// @brief Creates an xtd::span with specified native array.
    /// @param array The native array to construct a view for.
    template<xtd::usize len>
    constexpr span(element_type(&array)[len]) noexcept : data_ {const_cast<element_type*>(array)}, length_ {extent != dynamic_extent ? extent : len} {}
    #endif
    /// @brief Creates an xtd::span with specified std::array.
    /// @param array The std::array to construct a view for.
    template<typename array_type_t, xtd::usize len>
    constexpr span(const std::array<array_type_t, len>& array) noexcept : data_ {array.data()}, length_ {extent != dynamic_extent ? extent : len} {}
    /// @brief Creates an xtd::span with specified std::array.
    /// @param array The std::array to construct a view for.
    template<typename array_type_t, xtd::usize len>
    constexpr span(std::array<array_type_t, len>& array) noexcept : data_ {array.data()}, length_ {extent != dynamic_extent ? extent : len} {}
    /// @brief Creates an xtd::span with specified collection and count.
    /// @param items The collection to construct a view for.
    /// @param length The number of elements in the collection.
    /// @exception xtd::argument_out_of_range_exception if length is greater than items size.
    template<typename array_type_t>
    constexpr span(const xtd::array<array_type_t>& items) : span {items, size_type {0}, items.length()} {}
    /// @brief Creates an xtd::span with specified collection and count.
    /// @param items The collection to construct a view for.
    /// @param length The number of elements in the collection.
    /// @exception xtd::argument_out_of_range_exception if length is greater than items size.
    template<typename array_type_t>
    constexpr span(xtd::array<array_type_t>& items) : span {items, size_type {0}, items.length()} {}
    #if defined(__xtd__cpp_lib_ranges)
    /// @brief Creates an xtd::span with specified range.
    /// @param range The range to construct a view for.
    template<typename range_t>
    constexpr span(range_t&& range) noexcept : data_ {std::ranges::data(range)}, length_ {extent != dynamic_extent ? extent : std::ranges::size(range)} {}
    #else
    /// @brief Creates an xtd::span with specified range.
    /// @param range The range to construct a view for.
    template<typename range_t>
    constexpr span(range_t&& range) noexcept : data_ {range.data()}, length_ {extent != dynamic_extent ? extent : range.size()} {}
    #endif
    #if __cplusplus >= 202002l
    /// @brief Creates an xtd::span with specified initializer list.
    /// @param items The initializer list to construct a view for.
    constexpr span(std::initializer_list<type_t> items) noexcept requires std::is_const_v<element_type> : data_ {items.begin()}, length_ {extent != dynamic_extent ? extent : items.size()} {}
    #else
    /// @brief Creates an xtd::span with specified initializer list.
    /// @param items The initializer list to construct a view for.
    constexpr span(std::initializer_list<type_t> items) noexcept : data_ {const_cast<type_t*>(items.begin())}, length_ {extent != dynamic_extent ? extent : items.size()} {
      static_assert(std::is_const_v<element_type>, "type_t must be const");
    }
    #endif
    /* Conflict with span(range_t&& range) noexcept
    /// @brief Creates an xtd::span with specified collection.
    /// @param items The collection to construct a view for.
    /// @exception xtd::argument_out_of_range_exception if length is greater than items size.
    template<typename collection_t>
    constexpr span(collection_t& items) noexcept : span {items, size_type {0}, items.size()} {}
     */
    /// @brief Creates an xtd::span with specified collection and count.
    /// @param items The collection to construct a view for.
    /// @param length The number of elements in the collection.
    /// @exception xtd::argument_out_of_range_exception if length is greater than items size.
    template<typename collection_t>
    constexpr span(collection_t& items, size_type length) : span {items, size_type {0}, length} {}
    /// @brief Creates an xtd::span with specified collection, offest and count.
    /// @param items The collection to construct a view for.
    /// @param start The offset in the collection.
    /// @param length The number of elements in the collection.
    /// @exception xtd::argument_out_of_range_exception if start or start + length are greater than items size.
    template<typename collection_t>
    constexpr span(collection_t& items, size_type start, size_type length) : data_ {const_cast<pointer>(items.data()) + start}, length_ {extent != dynamic_extent ? extent : length} {
      if (start + length > items.size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
    }
    /// @brief Creates an xtd::span with specified data pointer and count.
    /// @param data The data pointer to construct a view for.
    /// @param length The number of elements to constuct.
    constexpr span(type_t* const data, size_type length) : data_ {const_cast<pointer>(data)}, length_ {extent != dynamic_extent ? extent : length} {
      if (!data) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_null);
    }
    /// @brief Creates an xtd::span with specified collection, and range.
    /// @param items The collection to construct a view for.
    /// @param range The range of elements in the collection.
    /// @exception xtd::argument_out_of_range_exception if range.start or range.start + range.end - range.start are greater than items size.
    template<typename collection_t>
    constexpr span(collection_t& items, const xtd::range& range) {
      auto [start, length] = range.get_offset_and_length(items.size());
      data_ = items.data() + start;
      length_ = extent != dynamic_extent ? extent : length;
    }
    /// @}
    
    /// @cond
    template<xtd::usize extent_>
    constexpr span(const std::span<type_t, extent_>& s) : data_ {s.data()}, length_ {s.size()} {}

    constexpr span(span&& items) = default;
    constexpr span(const span& items) = default;
    
    auto operator =(span&& items) -> span& = default;
    auto operator =(const span& items) -> span& = default;
    /// @endcond
    
    /// @name Public Fields
    
    /// @{
    /// @brief Returns an empty xtd::span <type_t> object.
    /// @return An empty xtd::span <type_t> object.
    static const span empty_span;
    /// @}
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets direct access to the underlying contiguous storage
    /// @return A pointer to the beginning of the sequence.
    [[nodiscard]] constexpr auto data() const noexcept -> const_pointer {return data_;}
    /// @brief Gets direct access to the underlying contiguous storage
    /// @return A pointer to the beginning of the sequence.
    [[nodiscard]] constexpr auto data() noexcept -> pointer {return data_;}

    /// @brief Returns a value that indicates whether the current xtd::span <type_t> is empty.
    /// @return `true` if the current span is empty; otherwise, `false`.
    [[nodiscard]] constexpr auto empty() const noexcept -> bool {return is_empty();}
    
    /// @brief Returns a value that indicates whether the current xtd::span <type_t> is empty.
    /// @return `true` if the current span is empty; otherwise, `false`.
    [[nodiscard]] constexpr auto is_empty() const noexcept -> bool {return !length_;}
    
    /// @brief Returns the length of the current span.
    /// @return The length of the current span.
    [[nodiscard]] constexpr auto length() const noexcept -> size_type {return length_;}
    
    /// @brief Returns the number of elements
    /// @return The number of elements in the span.
    [[nodiscard]] constexpr auto size() const noexcept -> size_type {return length();}
    
    /// @brief Returns the size of the sequence in bytes
    /// @return The size of the sequence in bytes, i.e., `size() * sizeof(element_type)`.
    [[nodiscard]] constexpr auto size_bytes() const noexcept -> size_type {return length_ * sizeof(value_type);}
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Clears the contents of this xtd::span <type> object.
    /// @remarks The xtd::span::clear method sets the items in the xtd::span <type_t> object to their default values. It does not remove items from the xtd::span <type_t>.
    auto clear() noexcept -> void {
      for (auto& item : *this)
        item = value_type {};
    }
    
    /// @brief Copies the contents of this xtd::span <type_t> into a destination xtd:span <type_t>.
    /// @param destinaton The destination xtd::span <type_t> object.
    /// @exception xtd::argument_exception `destination` is shorter than the source xtd::span <type_t>.
    template<xtd::usize length>
    auto copy_to(span<type_t, length>& destination) const -> void {
      if (!try_copy_to(destination))
        xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
    }
    
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    [[nodiscard]] auto equals(const object& obj) const noexcept -> bool override {return is<span<value_type>>(obj) && equals(static_cast<const span<value_type>& > (obj));}
    /// @brief Indicates whether the current object is equal to another object of the same type.
    /// @param obj An object to compare with this object.
    /// @return `true` if the current object is equal to the other parameter; otherwise, `false`.
    [[nodiscard]] auto equals(const span& rhs) const noexcept -> bool override {return length() == rhs.length() && data() == rhs.data();}
    
    /// @brief Fills the elements of this span with a specified value.
    /// @param value The value to assign to each element of the span.
    auto fill(const type_t& value) -> void {
      for (auto& item : *this)
        item = value;
    }
    
    /// @brief Obtains a subspan consisting of the first `count` elements of the sequence.
    /// @param count The count elements.
    /// @return A span `r` that is a view over the first `count` elements of `*this`, such that `r.data() == this->data() && r.size() == count`.
    template<xtd::usize count>
    [[nodiscard]] auto first() const -> span<type_t, count> {
      if (count > length_) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      return span<type_t, count> {data_, count};
    }
    /// @brief Obtains a subspan consisting of the first `count` elements of the sequence.
    /// @param count The count elements.
    /// @return A span `r` that is a view over the first `count` elements of `*this`, such that `r.data() == this->data() && r.size() == count`.
    [[nodiscard]] auto first(xtd::usize count) const -> span<type_t> {
      if (count > length_) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      return span<type_t> {data_, count};
    }
    
    auto get_enumerator() const -> xtd::collections::generic::enumerator<type_t> override {
      class span_enumerator : public xtd::collections::generic::ienumerator<type_t> {
      public:
        explicit span_enumerator(const_pointer data, xtd::usize length) : data_(data), length_(length) {}
        const type_t& current() const override {return *(data_ + index_);}
        bool move_next() override {return ++index_ < length_;}
        void reset() override {index_ = xtd::npos;}
        
      protected:
        const_pointer data_;
        xtd::usize length_;
        xtd::usize index_ = xtd::npos;
      };
      return {new_ptr<span_enumerator>(data_, length_)};
    }

    /// @brief Serves as a hash function for a particular type.
    /// @return A hash code for the current object.
    [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override {
      auto result = hash_code {};
      for (const auto& item : *this)
        result.add(item);
      return result.to_hash_code();
    }
    
    /// @brief Obtains a subspan consisting of the last N elements of the sequence
    /// @param count The count elements.
    /// @return A span `r` that is a view over the last `count` elements of `*this`, such that `r.data() == this->data() + (this->size() - count) && r.size() == count`.
    template<xtd::usize count>
    [[nodiscard]] auto last() const -> span<type_t, count> {
      if (count > length_) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      return span<type_t, count> {data_ + length_ - count, count};
    }
    /// @brief Obtains a subspan consisting of the last N elements of the sequence
    /// @param count The count elements.
    /// @return A span `r` that is a view over the last `count` elements of `*this`, such that `r.data() == this->data() + (this->size() - count) && r.size() == count`.
    [[nodiscard]] auto last(xtd::usize count) const -> span<type_t> {
      if (count > length_) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      return span<type_t> {data_ + length_ - count, count};
    }
    
    /// @brief Forms a slice out of the current span starting at a specified index for a specified length.
    /// @param start The zero-based index at which to begin this slice.
    /// @param length The desired length for the slice.
    /// @return A span that consists of length elements from the current span starting at start.
    /// @exception xtd::argument_out_of_range_exception `start` or `start + length` is less than zero or greater than xtd::span::length.
    template<xtd::usize start, size_type lenght = xtd::dynamic_extent>
    [[nodiscard]] auto slice() const -> span<type_t> {
      return lenght == xtd::dynamic_extent ? slice(start) : slice(start, lenght);
    }
    
    /// @brief Forms a slice out of the current span that begins at a specified index.
    /// @param start The zero-based index at which to begin the slice.
    /// @return A span that consists of all elements of the current span from `start` to the end of the span.
    /// @exception xtd::argument_out_of_range_exception `start` is less than zero or greater than xtd::span::length.
    [[nodiscard]] auto slice(size_type start) const -> span<type_t> {
      return slice(start, length_ - start);
    }
    
    /// @brief Forms a slice out of the current span starting at a specified index for a specified length.
    /// @param start The zero-based index at which to begin this slice.
    /// @param length The desired length for the slice.
    /// @return A span that consists of length elements from the current span starting at start.
    /// @exception xtd::argument_out_of_range_exception `start` or `start + length` is less than zero or greater than xtd::span::length.
    [[nodiscard]] auto slice(size_type start, size_type length) const -> span<type_t> {
      if (start > length_ || start + length > length_) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      return span<type_t> {data_ + start, length};
    }
    
    /// @brief Forms a subspan of the current span starting at a specified index for a specified length.
    /// @param offset The zero-based index at which to begin this slice.
    /// @param count The desired length for the slice.
    /// @return A span that consists of length elements from the current span starting at start.
    /// @exception xtd::argument_out_of_range_exception `offset` or `offset + count` is less than zero or greater than xtd::span::length.
    template<xtd::usize offset, size_type count = xtd::dynamic_extent>
    [[nodiscard]] auto subspan() const -> span<type_t> {
      return count == xtd::dynamic_extent ? slice(offset) : slice(offset, count);
    }
    
    /// @brief Forms a subspan of the current span starting at a specified index for a specified length.
    /// @param offset The zero-based index at which to begin this slice.
    /// @param count The desired length for the slice.
    /// @return A span that consists of length elements from the current span starting at start.
    /// @exception xtd::argument_out_of_range_exception `offset` or `offset + count` is less than zero or greater than xtd::span::length.
    [[nodiscard]] auto subspan(size_type offset, size_type count = xtd::dynamic_extent) const -> span<type_t> {
      return count == xtd::dynamic_extent ? slice(offset) : slice(offset, count);
    }
    
    /// @brief Copies the contents of this span into a new array.
    /// @return An array containing the data in the current span.
    [[nodiscard]] auto to_array() const noexcept -> xtd::array<value_type> {
      return data_ && length_ ? xtd::array<value_type>(data_, data_ + length_) : xtd::array<value_type> {};
    }
    
    /// @brief Returns the string representation of this xtd::span <type_t> object.
    /// @return The string representation of this xtd::span <type_t> object.
    /// @remarks For a xtd::span <type_t>, the xtd::span::to_string method returns a xtd::string that contains the characters pointed to by the xtd::span <type_t>. Otherwise, it returns a xtd::string with collection sequance string of the elements that the xtd::span <type_t> contains separated by `, `.
    [[nodiscard]] auto to_string() const noexcept -> xtd::string override {
      if (typeof_<type_t>() == typeof_<char>()) return xtd::string::join("", *this);
      return xtd::string::format("[{}]", xtd::string::join(", ", *this));
    }
    
    /// @brief Attempts to copy the current xtd::span <type_t> to a destination xtd::span <type_t> and returns a value that indicates whether the copy operation succeeded.
    /// @param destination The target of the copy operation.
    /// @return `true` if the copy operation succeeded; otherwise, `false`.
    /// @remarks This method copies all of `source` to `destination` even if `source` and `destination` overlap.
    template<xtd::usize length>
    auto try_copy_to(span<type_t, length>& destination) const noexcept -> bool {
      if (destination.length() < this->length()) return false;
      for (auto index = xtd::usize {}; index < length_; ++index)
        destination[index] = operator [](index);
      return true;
    }
    /// @}
    
    /// @name Public Operators
    
    /// @{
    /// @brief Gets the element at the specified zero-based index.
    /// @param index The zero-based index of the element.
    /// @return The element at the specified index.
    /// @exception xtd::index_out_of_range_exception `index` is less than zero or greater than or equal to xtd::span::length.
    auto operator [](size_type index) const -> const_reference {
      if (index >= length_) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      return *(data_ + index);
    }
    /// @brief Gets the element at the specified zero-based index.
    /// @param index The zero-based index of the element.
    /// @return The element at the specified index.
    /// @exception xtd::index_out_of_range_exception `index` is less than zero or greater than or equal to xtd::span::length.
    auto operator [](size_type index) -> reference {
      if (index >= length_) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      return *(data_ + index);
    }
    /// @brief Gets the element at the specified zero-based index.
    /// @param index The zero-based index of the element.
    /// @return The element at the specified index.
    /// @exception xtd::index_out_of_range_exception `index` is less than zero or greater than or equal to xtd::span::length.
    auto operator [](const xtd::index& index) const -> const_reference {
      return operator[](index.get_offset(size()));
    }
    /// @brief Gets the element at the specified zero-based index.
    /// @param index The zero-based index of the element.
    /// @return The element at the specified index.
    /// @exception xtd::index_out_of_range_exception `index` is less than zero or greater than or equal to xtd::span::length.
    auto operator [](const xtd::index& index) -> reference {
      return operator[](index.get_offset(size()));
    }
    /// @brief Gets the elements at the specified range.
    /// @param range The range of the elements to set.
    /// @remarks This operator provides the ability to access a specific element in the collection by using the following syntax: `my_collection[index]`.
    auto operator [](const xtd::range& range) const -> xtd::read_only_span<type_t>;
    /// @brief Gets the elements at the specified range.
    /// @param range The range of the elements to set.
    /// @remarks This operator provides the ability to access a specific element in the collection by using the following syntax: `my_collection[index]`.
    auto operator [](const xtd::range& range) -> span {
      return span {*this, range};
    }

    /// @brief Gets the element at the specified zero-based index.
    /// @param index The zero-based index of the element.
    /// @return The element at the specified index.
    /// @exception xtd::index_out_of_range_exception `index` is less than zero or greater than or equal to xtd::span::length.
    auto operator ()(size_type index) const -> const_reference {
      return operator[](index);
    }
    /// @brief Gets the element at the specified zero-based index.
    /// @param index The zero-based index of the element.
    /// @return The element at the specified index.
    /// @exception xtd::index_out_of_range_exception `index` is less than zero or greater than or equal to xtd::span::length.
    auto operator ()(size_type index) -> reference {
      return operator[](index);
    }
    /// @brief Gets the element at the specified zero-based index.
    /// @param index The zero-based index of the element.
    /// @return The element at the specified index.
    /// @exception xtd::index_out_of_range_exception `index` is less than zero or greater than or equal to xtd::span::length.
    auto operator ()(const xtd::index& index) const -> const_reference {
      return operator[](index);
    }
    /// @brief Gets the element at the specified zero-based index.
    /// @param index The zero-based index of the element.
    /// @return The element at the specified index.
    /// @exception xtd::index_out_of_range_exception `index` is less than zero or greater than or equal to xtd::span::length.
    auto operator ()(const xtd::index& index) -> reference {
      return operator[](index);
    }
    /// @brief Gets the elements at the specified range.
    /// @param range The range of the elements to set.
    /// @remarks This operator provides the ability to access a specific element in the collection by using the following syntax: `my_collection[index]`.
    auto operator ()(const xtd::range& range) const -> xtd::read_only_span<type_t>;
    /// @brief Gets the elements at the specified range.
    /// @param range The range of the elements to set.
    /// @remarks This operator provides the ability to access a specific element in the collection by using the following syntax: `my_collection[index]`.
    auto operator ()(const xtd::range& range) -> span {
      return operator[](range);
    }
    /// @}

    /// @cond
    operator std::span<type_t, extent>() const {return std::span<type_t, extent>(data_, length_);}
    /// @endcond

  private:
    pointer data_ = null;
    size_type length_ = size_type {};
  };
  
  template<typename type_t, xtd::usize extent>
  inline const span<type_t, extent> span<type_t, extent>::empty_span;
  
  /// @cond
  // Deduction guides for xtd::span
  // {
  template<typename iterator_t>
  span(iterator_t, iterator_t) -> span<typename iterator_t::value_type>;
  
  template<typename type_t, xtd::usize len>
  span(type_t (&)[len]) noexcept -> span<type_t>;
  
  template< class type_t, xtd::usize len>
  span(const std::array<type_t, len>&) noexcept -> span<const type_t>;
  
  template< class type_t, xtd::usize len>
  span(std::array<type_t, len>&) noexcept -> span<type_t>;
  
  template<xtd::iterable iterable_t>
  span(iterable_t&& items) -> span<xtd::iterable_value_type<iterable_t>>;

  template<typename type_t>
  span(std::initializer_list<type_t>) noexcept -> span<const type_t>;
  
  template<typename collection_t>
  span(const collection_t& items) noexcept -> span<const typename collection_t::value_type>;
  
  template<typename collection_t>
  span(const collection_t&, xtd::usize) -> span<const typename collection_t::value_type>;
  
  template<typename collection_t>
  span(collection_t&, xtd::usize) -> span<typename collection_t::value_type>;
  
  template<typename collection_t>
  span(const collection_t&, xtd::usize, xtd::usize) -> span<const typename collection_t::value_type>;
  
  template<typename collection_t>
  span(collection_t&, xtd::usize, xtd::usize) -> span<typename collection_t::value_type>;
  
  template<typename collection_t>
  span(const collection_t&, const xtd::range&) -> span<const typename collection_t::value_type>;

  template<typename type_t>
  span(type_t* const, xtd::usize) -> span<type_t>;
  // }
  /// @endcond
}

/// @cond
template<typename type_t, typename list_t>
auto xtd::collections::generic::extensions::list_common<type_t, list_t>::operator [](const xtd::range& range) -> xtd::span<type_t> {
  return xtd::span<type_t>(self(), range);
}

template<typename type_t, typename list_t>
auto xtd::collections::generic::extensions::list_common<type_t, list_t>::operator ()(const xtd::range& range) -> xtd::span<type_t> {
  return xtd::span<type_t>(self(), range);
}

template<typename type_t, typename allocator_t>
auto xtd::collections::generic::helpers::raw_array<type_t, allocator_t>::operator [](const xtd::range& range) -> xtd::span<type_t> {
  return xtd::span<type_t>(*this, range);
}

template<typename type_t, typename allocator_t>
auto xtd::collections::generic::helpers::raw_array<type_t, allocator_t>::operator ()(const xtd::range& range) -> xtd::span<type_t> {
  return xtd::span<type_t>(*this, range);
}
/// @endcond
