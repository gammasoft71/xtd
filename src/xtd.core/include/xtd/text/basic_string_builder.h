/// @file
/// @brief Contains xtd::basic_string_builder class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#include "../basic_string.h"
#include "../argument_exception.h"
#include "../index_out_of_range_exception.h"
#include "../null_pointer_exception.h"

/// @cond
/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Contains classes that represent ASCII and Unicode character encodings; abstract base classes for converting blocks of characters to and from blocks of bytes; and a helper class that manipulates and formats xtd::string objects without creating intermediate instances of xtd::string.
  namespace text {
    /// @brief Represents a mutable string of characters. This class cannot be inherited.
    /// @par Namespace
    /// xtd::text
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core system text strings
    /// @remarks xtd::text::basic_string_builder class represents a string-like object whose value is a mutable sequence of characters.
    /// @remarks xtd::text::basic_string_builder implements [std::basic_string<char>](https://en.cppreference.com/w/cpp/basic_string_builder/basic_string_builder) and therefore offers the full API of std::basic_string.
    /// @remarks Several aliases for common character types are provided:
    /// @remarks
    /// | Type                         | Definition                              |
    /// | ---------------------------- | --------------------------------------- |
    /// | xtd::text::string_builder    | xtd::basic_string_builder <char>        |
    /// | xtd::text::u16string_builder | xtd::basic_string_builder <xtd::char16> |
    /// | xtd::text::u32string_builder | xtd::basic_string_builder <xtd::char32> |
    /// | xtd::text::u8string_builder  | xtd::basic_string_builder <xtd::char8>  |
    /// | xtd::text::wstring_builder   | xtd::basic_string_builder <xtd::wchar>  |
    template<typename char_t, typename traits_t = std::char_traits<char_t>, typename allocator_t = xtd::collections::generic::helpers::allocator<char_t>>
    class basic_string_builder final : public object, public xtd::iequatable<basic_string_builder<char_t, traits_t, allocator_t>> {
    public:
      /// @name Public Aliases
      
      /// @{
      /// @brief Represents the basic string base type.
      /// @remarks Is equal to `std::basic_string<char_t, traits_t, allocator_t>`.`
      using base_type = std::basic_string<char_t, traits_t, allocator_t>;
      /// @brief Represents the basic string traits type.
      using traits_type = base_type::traits_type;
      /// @brief Represents the basic string value type.
      using value_type = base_type::value_type;
      /// @brief Represents the basic string allocator type.
      using allocator_type = base_type::allocator_type;
      /// @brief Represents the basic string size type.
      using size_type = base_type::size_type;
      /// @brief Represents the basic string difference type.
      using difference_type = base_type::difference_type;
      /// @brief Represents the basic string referecne type.
      using reference = base_type::reference;
      /// @brief Represents the basic string const referecne type.
      using const_reference = base_type::const_reference;
      /// @brief Represents the basic string pointer type.
      using pointer = base_type::pointer;
      /// @brief Represents the basic string const pointer type.
      using const_pointer = base_type::const_pointer;
      /// @brief Represents the basic string iterator type.
      /// @todo replace xtd::ienumerable::iterator
      using iterator = base_type::iterator;
      /// @brief Represents the basic string const iterator type.
      /// @todo replace xtd::ienumerable::const_iterator
      using const_iterator = base_type::const_iterator;
      /// @brief Represents the basic string reverse iterator type.
      using reverse_iterator = base_type::reverse_iterator;
      /// @brief Represents the basic string const reverse iterator type.
      using const_reverse_iterator = base_type::const_reverse_iterator;
      /// @}
      
      /// @name Public Fields
      
      /// @{
      /// @brief This is a special value equal to the maximum value representable by the type xtd::size.
      inline static constexpr size_type npos = base_type::npos;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of xtd::basic_string_builder.
      basic_string_builder() = default;
      /// @brief Initializes a new instance of xtd::basic_string_builder with specified allocator.
      /// @param allocator The allocator to use for all memory allocations of this basic_string_builder.
      explicit basic_string_builder(const allocator_type& allocator) noexcept : chars_(allocator) {}
      
      /// @brief Initializes a new instance of xtd::basic_string_builder with specified string to copy.
      /// @param str The string to copy.
      basic_string_builder(const basic_string_builder& str) noexcept : chars_(str.chars_) {}
      /// @brief Initializes a new instance of xtd::basic_string_builder with specified string to copy and allocator.
      /// @param str The string to copy.
      /// @param allocator The allocator to use for all memory allocations of this basic_string_builder.
      basic_string_builder(const basic_string_builder& str, const allocator_type& allocator) noexcept : chars_(str.chars_, allocator) {}
      
      /// @brief Initializes a new instance of xtd::basic_string_builder with specified substring at index.
      /// @param str The string to copy.
      /// @param index The index of the first substring character where start copy.
      /// @exception xtd::index_out_of_range_exception `index` is greater or equal than `str` size.
      basic_string_builder(const basic_string_builder& str, xtd::size index) {
        if (index > str.size()) throw xtd::index_out_of_range_exception(csf_);
        chars_ = base_type(str.chars_, index);
      }
      /// @brief Initializes a new instance of xtd::basic_string_builder with specified substring at index and allocator.
      /// @param str The string to copy.
      /// @param index The index of the first substring character where start copy.
      /// @param allocator The allocator to use for all memory allocations of this basic_string_builder.
      /// @exception xtd::index_out_of_range_exception `index` is greater or equal than `str` size.
      basic_string_builder(const basic_string_builder& str, xtd::size index, const allocator_type& allocator) {
        if (index > str.size()) throw xtd::index_out_of_range_exception(csf_);
        chars_ = base_type(str.chars_, index, allocator);
      }
      
      /// @brief Initializes a new instance of xtd::basic_string_builder with specified substring at index and count characters.
      /// @param str The string to copy.
      /// @param index The index of the first substring character where start copy.
      /// @param count The number of substring characters to copy.
      /// @exception xtd::index_out_of_range_exception `index` + `count`is greater or equal than `str` size.
      basic_string_builder(const basic_string_builder& str, xtd::size index, xtd::size count) {
        if (index + count > str.size()) throw xtd::index_out_of_range_exception(csf_);
        chars_ = base_type(str.chars_, index, count);
      }
      /// @brief Initializes a new instance of xtd::basic_string_builder with specified substring at index, count characters and allocator.
      /// @param str The string to copy.
      /// @param index The index of the first substring character where start copy.
      /// @param count The number of substring characters to copy.
      /// @param allocator The allocator to use for all memory allocations of this basic_string_builder.
      /// @exception xtd::index_out_of_range_exception `index` + `count`is greater or equal than `str` size.
      basic_string_builder(const basic_string_builder& str, xtd::size index, xtd::size count, const allocator_type& allocator) {
        if (index + count > str.size()) throw xtd::index_out_of_range_exception(csf_);
        chars_ = base_type(str.chars_, index, count, allocator);
      }
      
      /// @brief Initializes a new instance of xtd::basic_string_builder with specified string to move.
      /// @param str The basic_string_builder to move.
      basic_string_builder(basic_string_builder&& str) noexcept : chars_(std::move(str.chars_)) {}
      /// @brief Initializes a new instance of xtd::basic_string_builder with specified string to move and allocator.
      /// @param str The basic_string_builder to move.
      /// @param allocator The allocator to use for all memory allocations of this basic_string_builder.
      basic_string_builder(basic_string_builder&& str, const allocator_type& allocator) noexcept : chars_(std::move(str.chars_), allocator) {}
      
      /// @brief Initializes a new instance of xtd::basic_string_builder with specified count copies of character.
      /// @param str The string to copy.
      /// @param count The number of copies of character.
      /// @param character The character copied.
      basic_string_builder(xtd::size count, value_type character) : chars_(count, character) {}
      /// @brief Initializes a new instance of xtd::basic_string_builder with specified count copies of character and specified allocator.
      /// @param str The string to copy.
      /// @param count The number of copies of character.
      /// @param character The character copied.
      /// @param allocator The allocator to use for all memory allocations of this basic_string_builder.
      basic_string_builder(xtd::size count, value_type character, const allocator_type& allocator) : chars_(count, character, allocator) {}
      
      /// @brief Initializes a new instance of xtd::basic_string_builder with specified string to copy.
      /// @param str The string to copy.
      basic_string_builder(const_pointer str) {  // Can't be explicit by design.
        if (str == null) throw xtd::null_pointer_exception(csf_);
        chars_ = base_type(str);
      }
      /// @brief Initializes a new instance of xtd::basic_string_builder with specified string to copy, and allocator.
      /// @param str The string to copy.
      /// @param allocator The allocator to use for all memory allocations of this basic_string_builder.
      basic_string_builder(const_pointer str, const allocator_type& allocator) {
        if (str == null) throw xtd::null_pointer_exception(csf_);
        chars_ = base_type(str, allocator);
      }
      
      /// @brief Initializes a new instance of xtd::basic_string_builder with specified substring and count characters.
      /// @param count The number of substring characters to copy.
      basic_string_builder(const_pointer str, xtd::size count) {
        if (str == null) throw xtd::null_pointer_exception(csf_);
        chars_ = base_type(str, count);
      }
      /// @brief Initializes a new instance of xtd::basic_string_builder with specified substring, count characters and allocator.
      /// @param str The string to copy.
      /// @param count The number of substring characters to copy.
      /// @param allocator The allocator to use for all memory allocations of this basic_string_builder.
      basic_string_builder(const_pointer str, xtd::size count, const allocator_type& allocator) : chars_(allocator) {
        if (str == null) throw xtd::null_pointer_exception(csf_);
        chars_ = base_type(str, count);
      }
      
      /// @brief Initializes a new instance of xtd::basic_string_builder with specified string to copy.
      /// @param str The string to copy.
      basic_string_builder(const std::basic_string<value_type>& str) noexcept : chars_(str) {}; // Can't be explicit by design.
      /// @brief Initializes a new instance of xtd::basic_string_builder with specified string to copy and allocator.
      /// @param str The string to copy.
      /// @param allocator The allocator to use for all memory allocations of this basic_string_builder.
      basic_string_builder(const std::basic_string<value_type>& str, const allocator_type& allocator) noexcept : chars_(str, allocator) {}
      
      /// @brief Initializes a new instance of xtd::basic_string_builder with specified first and last iterators of substring.
      /// @param first The first iterator of substring.
      /// @param last The first iterator of substring.
      template<typename input_iterator_t>
      basic_string_builder(input_iterator_t first, input_iterator_t last) : chars_(first, last) {}
      /// @brief Initializes a new instance of xtd::basic_string_builder with specified first and last iterators of substring and allocator.
      /// @param first The first iterator of substring.
      /// @param last The first iterator of substring.
      /// @param allocator The allocator to use for all memory allocations of this basic_string_builder.
      template<typename input_iterator_t>
      basic_string_builder(input_iterator_t first, input_iterator_t last, const allocator_type& allocator) : chars_(first, last, allocator) {}
            
      /// @brief Initializes a new instance of xtd::basic_string_builder with specified initializer list.
      /// @param il The initializer list to fill.
      basic_string_builder(std::initializer_list<value_type> il) : chars_(il) {}
      
      /// @brief Initializes a new instance of xtd::basic_string_builder with specified initializer list and allocator.
      /// @param il The initializer list to fill.
      /// @param allocator The allocator to use for all memory allocations of this basic_string_builder.
      basic_string_builder(std::initializer_list<value_type> il, const allocator_type& allocator) : chars_(il, allocator) {}
      
      basic_string_builder(xtd::size capacity) {this->capacity(capacity);}
      basic_string_builder(xtd::size capacity, xtd::size max_capacity) : max_capacity_{max_capacity} {this->capacity(capacity);}
      basic_string_builder(const xtd::basic_string<value_type>& value) : chars_(value.chars()) {}
      basic_string_builder(const xtd::basic_string<value_type>& value, xtd::size capacity) : chars_(value.chars()) {this->capacity(capacity);}
      basic_string_builder(const xtd::basic_string<value_type>& value, xtd::size start_index, xtd::size length, xtd::size capacity) : chars_(value.substr(start_index, length).chars()) {this->capacity(capacity);}
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Returns reference to the last character in the string.
      /// @return Reference to the last character, equivalent to `operator[](size() - 1)`.
      /// @exception xtd::index_out_of_range_exception If is empty.
      const_reference back() const {return operator[](size() - 1);}
      
      /// @brief Returns an iterator to the first character of the string.
      /// @return Iterator to the first character.
      const_iterator begin() const {return chars_.begin();}
      /// @brief Returns an iterator to the first character of the string.
      /// @return Iterator to the first character.
      iterator begin() {return chars_.begin();}

      /// @brief Returns a pointer to a null-terminated character array with data equivalent to those stored in the string.
      /// @return Pointer to the underlying character storage.
      /// @remarks The pointer is such that the range [`c_str()`, `c_str() + size()`] is valid and the values in it correspond to the values stored in the string with an additional null character after the last position.
      /// @remarks The pointer obtained from c_str() may be invalidated by:
      /// * Passing a non-const reference to the string to any standard library function, or
      /// * Calling non-const member functions on the string, excluding operator[], at(), front(), back(), begin(), rbegin(), end() and rend().
      /// @remarks Writing to the character array accessed through c_str() is undefined behavior.
      /// @remarks c_str() and data() perform the same function.
      const value_type* c_str() const noexcept {return chars_.c_str();}
      
      /// @brief Returns the number of characters that the string has currently allocated space for.
      /// @return Capacity of the currently allocated storage, i.e. the storage available for storing elements.
      size_type capacity() const noexcept {return chars_.capacity();}
      /// @brief Sets the number of characters that the string has currently allocated space for.
      /// @param value Capacity of the currently allocated storage, i.e. the storage available for storing elements.
      basic_string_builder& capacity(size_type value) {
        if (value > max_capacity_) throw xtd::argument_exception {csf_};
        chars_.reserve(value);
        return *this;
      }

      /// @brief Returns an iterator to the first character of the string.
      /// @return Iterator to the first character.
      const_iterator cbegin() const {return chars_.cbegin();}
      
      /// @brief Returns a reference to the underlying base type.
      /// @return Reference to the underlying base type.
      const base_type& chars() const noexcept {return chars_;}
      
      /// @brief Returns an iterator to the character following the last character of the string. This character acts as a placeholder, attempting to access it results in undefined behavior.
      /// @return Iterator to the character following the last character.
      const_iterator cend() const {return chars_.cend();}
      
      /// @brief Returns a pointer to the underlying array serving as character storage. The pointer is such that the range [`data()`, `data() + size()`] is valid and the values in it correspond to the values stored in the string.
      /// @return A pointer to the underlying character storage.
      /// @remarks The pointer obtained from `data()` may be invalidated by:
      /// * Passing a non-const reference to the string to any standard library function, or
      /// * Calling non-const member functions on the string, excluding operator[](), at(), front(), back(), begin(), end(), rbegin(), rend().
      ///   1. Modifying the character array accessed through the const overload of data has undefined behavior.
      ///   2. Modifying the past-the-end null terminator stored at data() + size() to any value other than char_t() has undefined behavior.
      const value_type* data() const noexcept {return chars_.data();}
      
      /// @brief Checks if the string has no characters, i.e. whether `begin() == end()`.
      /// @return `true` if the string is empty; otherwise `false`.
      bool empty() const noexcept {return chars_.empty();}
      
      /// @brief Returns an iterator to the character following the last character of the string. This character acts as a placeholder, attempting to access it results in undefined behavior.
      /// @return Iterator to the character following the last character.
      const_iterator end() const {return chars_.end();}
      /// @brief Returns an iterator to the character following the last character of the string. This character acts as a placeholder, attempting to access it results in undefined behavior.
      /// @return Iterator to the character following the last character.
      iterator end() {return chars_.end();}

      /// @brief Returns reference to the first character in the string. The behavior is undefined if empty() is true.
      /// @return Reference to the first character, equivalent to `operator[](0)`.
      /// @exception xtd::index_out_of_range_exception If is empty.
      const_reference front() const {return operator[](0);}
      
      /// @brief Gets the number of characters in the current xtd::basic_string_builder object.
      /// @return The number of characters in the current string.
      /// @remarks The xtd::basic_string_builder::length property returns the number of xtd::basic_string_builder::value_type objects in this instance, not the number of Unicode characters. The reason is that a Unicode character might be represented by more than one xtd::basic_string_builder::value_type.
      size_type length() const noexcept {return chars_.size();}
      
      /// @brief Returns the maximum number of elements the string is able to hold due to system or library implementation limitations, i.e. `std::distance(begin(), end())` for the largest string.
      /// @return Maximum number of characters.
      size_type max_size() const noexcept {return chars_.max_size();}
      
      /// @brief Returns the number of `char_t` elements in the string, i.e. `std::distance(begin(), end())`.
      /// @return The number of `char_t` elements in the string.
      size_type size() const noexcept {return chars_.size();}
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Returns a reference to the character at specified location `pos`.
      /// @return Reference to the requested character.
      /// @exception xtd::index_out_of_range_exception If `index` is not within the range of the string.
      const_reference at(size_type pos) const {return operator [](pos);}
      
      /// @brief Compares two character sequences.
      /// @param str The other string to compare to.
      /// @return
      /// * Negative value if `*this` appears before the character sequence specified by the arguments, in lexicographical order.
      /// * Zero if both character sequences compare equivalent.
      /// * Positive value if `*this` appears after the character sequence specified by the arguments, in lexicographical order.
      /// @remarks Compares this string to str.
      /// @remarks A character sequence consisting of `count1` characters starting at `data1` is compared to a character sequence consisting of `count2` characters starting at `data2` as follows:
      /// * First, calculate the number of characters to compare, as if by `size_type rlen = std::min(count1, count2)`.
      /// * Then compare the sequences by calling `traits_t::compare(data1, data2, rlen)`. For standard strings this function performs character-by-character lexicographical comparison. If the result is zero (the character sequences are equal so far), then their sizes are compared as follows:
      /// @remarks
      /// | Condition                                                     | Result                          | Return value |
      /// | ------------------------------------------------------------- | ------------------------------- | ------------ |
      /// | traits_t::compare(data1, data2, rlen) < 0                     | data1 is **less than** data2    | < 0          |
      /// | traits_t::compare(data1, data2, rlen) == 0 and size1 < size2  | data1 is **less than** data2    | < 0          |
      /// | traits_t::compare(data1, data2, rlen) == 0 and size1 == size2 | data1 is **equal to** data2     | 0            |
      /// | traits_t::compare(data1, data2, rlen) == 0 and size1 > size2  | data1 is **greater than** data2 | > 0          |
      /// | traits_t::compare(data1, data2, rlen) > 0                     | data1 is **greater than** data2 | > 0          |
      int32 compare(const basic_string_builder& str) const {return chars_.compare(str);}
      /// @brief Compares two character sequences.
      /// @param pos1 The position of the first character in this string to compare.
      /// @param count1 The number of characters of this string to compare.
      /// @param str The other string to compare to.
      /// @return
      /// * Negative value if `*this` appears before the character sequence specified by the arguments, in lexicographical order.
      /// * Zero if both character sequences compare equivalent.
      /// * Positive value if `*this` appears after the character sequence specified by the arguments, in lexicographical order.
      /// @remarks Compares a [`pos1`, `pos1 + count1`) substring of this string to `str`.
      /// * If `count1 > size() - pos1`, the substring is [`pos1`, size()).
      /// @remarks A character sequence consisting of `count1` characters starting at `data1` is compared to a character sequence consisting of `count2` characters starting at `data2` as follows:
      /// * First, calculate the number of characters to compare, as if by `size_type rlen = std::min(count1, count2)`.
      /// * Then compare the sequences by calling `traits_t::compare(data1, data2, rlen)`. For standard strings this function performs character-by-character lexicographical comparison. If the result is zero (the character sequences are equal so far), then their sizes are compared as follows:
      /// @remarks
      /// | Condition                                                     | Result                          | Return value |
      /// | ------------------------------------------------------------- | ------------------------------- | ------------ |
      /// | traits_t::compare(data1, data2, rlen) < 0                     | data1 is **less than** data2    | < 0          |
      /// | traits_t::compare(data1, data2, rlen) == 0 and size1 < size2  | data1 is **less than** data2    | < 0          |
      /// | traits_t::compare(data1, data2, rlen) == 0 and size1 == size2 | data1 is **equal to** data2     | 0            |
      /// | traits_t::compare(data1, data2, rlen) == 0 and size1 > size2  | data1 is **greater than** data2 | > 0          |
      /// | traits_t::compare(data1, data2, rlen) > 0                     | data1 is **greater than** data2 | > 0          |
      int32 compare(size_type pos1, size_type count1, const basic_string_builder& str) const {return chars_.compare(pos1, count1, str);}
      /// @brief Compares two character sequences.
      /// @param pos1 The position of the first character in this string to compare.
      /// @param count1 The number of characters of this string to compare.
      /// @param str The other string to compare to.
      /// @param pos2 The position of the first character of the given string to compare.
      /// @return
      /// * Negative value if `*this` appears before the character sequence specified by the arguments, in lexicographical order.
      /// * Zero if both character sequences compare equivalent.
      /// * Positive value if `*this` appears after the character sequence specified by the arguments, in lexicographical order.
      /// @remarks Compares a [`pos1`, `pos1 + count1`) substring of this string to a substring [`pos2`, `pos2 + count2`) of `str`.
      /// * If `count1 > size() - pos1`, the first substring is [`pos1`, size()).
      /// * If `count2 > str.size() - pos2`, the second substring is [`pos2`, `str.size()`).
      /// @remarks A character sequence consisting of `count1` characters starting at `data1` is compared to a character sequence consisting of `count2` characters starting at `data2` as follows:
      /// * First, calculate the number of characters to compare, as if by `size_type rlen = std::min(count1, count2)`.
      /// * Then compare the sequences by calling `traits_t::compare(data1, data2, rlen)`. For standard strings this function performs character-by-character lexicographical comparison. If the result is zero (the character sequences are equal so far), then their sizes are compared as follows:
      /// @remarks
      /// | Condition                                                     | Result                          | Return value |
      /// | ------------------------------------------------------------- | ------------------------------- | ------------ |
      /// | traits_t::compare(data1, data2, rlen) < 0                     | data1 is **less than** data2    | < 0          |
      /// | traits_t::compare(data1, data2, rlen) == 0 and size1 < size2  | data1 is **less than** data2    | < 0          |
      /// | traits_t::compare(data1, data2, rlen) == 0 and size1 == size2 | data1 is **equal to** data2     | 0            |
      /// | traits_t::compare(data1, data2, rlen) == 0 and size1 > size2  | data1 is **greater than** data2 | > 0          |
      /// | traits_t::compare(data1, data2, rlen) > 0                     | data1 is **greater than** data2 | > 0          |
      int32 compare(size_type pos1, size_type count1, const basic_string_builder& str, size_type pos2) const {return chars_.compare(pos1, count1, str, pos2);}
      /// @brief Compares two character sequences.
      /// @param pos1 The position of the first character in this string to compare.
      /// @param count1 The number of characters of this string to compare.
      /// @param str The other string to compare to.
      /// @param pos2 The position of the first character of the given string to compare.
      /// @param count2 The number of characters of the given string to compare.
      /// @return A 32-bit signed integer that indicates whether this instance precedes, follows, or appears in the same position in the sort order as the value parameter:
      /// * Negative value if `*this` appears before the character sequence specified by the arguments, in lexicographical order.
      /// * Zero if both character sequences compare equivalent.
      /// * Positive value if `*this` appears after the character sequence specified by the arguments, in lexicographical order.
      /// @remarks Compares a [`pos1`, `pos1 + count1`) substring of this string to a substring [`pos2`, `pos2 + count2`) of `str`.
      /// * If `count1 > size() - pos1`, the first substring is [`pos1`, size()).
      /// * If `count2 > str.size() - pos2`, the second substring is [`pos2`, `str.size()`).
      /// @remarks A character sequence consisting of `count1` characters starting at `data1` is compared to a character sequence consisting of `count2` characters starting at `data2` as follows:
      /// * First, calculate the number of characters to compare, as if by `size_type rlen = std::min(count1, count2)`.
      /// * Then compare the sequences by calling `traits_t::compare(data1, data2, rlen)`. For standard strings this function performs character-by-character lexicographical comparison. If the result is zero (the character sequences are equal so far), then their sizes are compared as follows:
      /// @remarks
      /// | Condition                                                     | Result                          | Return value |
      /// | ------------------------------------------------------------- | ------------------------------- | ------------ |
      /// | traits_t::compare(data1, data2, rlen) < 0                     | data1 is **less than** data2    | < 0          |
      /// | traits_t::compare(data1, data2, rlen) == 0 and size1 < size2  | data1 is **less than** data2    | < 0          |
      /// | traits_t::compare(data1, data2, rlen) == 0 and size1 == size2 | data1 is **equal to** data2     | 0            |
      /// | traits_t::compare(data1, data2, rlen) == 0 and size1 > size2  | data1 is **greater than** data2 | > 0          |
      /// | traits_t::compare(data1, data2, rlen) > 0                     | data1 is **greater than** data2 | > 0          |
      int32 compare(size_type pos1, size_type count1, const basic_string_builder& str, size_type pos2, size_type count2) const {return chars_.compare(pos1, count1, str, pos2, count2);}
      /// @brief Compares two character sequences.
      /// @param s pointer to the character string to compare to.
      /// @return
      /// * Negative value if `*this` appears before the character sequence specified by the arguments, in lexicographical order.
      /// * Zero if both character sequences compare equivalent.
      /// * Positive value if `*this` appears after the character sequence specified by the arguments, in lexicographical order.
      /// @remarks Compares this string to the null-terminated character sequence beginning at the character pointed to by `s` with length `traits_t::length(s)`.
      /// @remarks A character sequence consisting of `count1` characters starting at `data1` is compared to a character sequence consisting of `count2` characters starting at `data2` as follows:
      /// * First, calculate the number of characters to compare, as if by `size_type rlen = std::min(count1, count2)`.
      /// * Then compare the sequences by calling `traits_t::compare(data1, data2, rlen)`. For standard strings this function performs character-by-character lexicographical comparison. If the result is zero (the character sequences are equal so far), then their sizes are compared as follows:
      /// @remarks
      /// | Condition                                                     | Result                          | Return value |
      /// | ------------------------------------------------------------- | ------------------------------- | ------------ |
      /// | traits_t::compare(data1, data2, rlen) < 0                     | data1 is **less than** data2    | < 0          |
      /// | traits_t::compare(data1, data2, rlen) == 0 and size1 < size2  | data1 is **less than** data2    | < 0          |
      /// | traits_t::compare(data1, data2, rlen) == 0 and size1 == size2 | data1 is **equal to** data2     | 0            |
      /// | traits_t::compare(data1, data2, rlen) == 0 and size1 > size2  | data1 is **greater than** data2 | > 0          |
      /// | traits_t::compare(data1, data2, rlen) > 0                     | data1 is **greater than** data2 | > 0          |
      int32 compare(const_pointer s) const {return chars_.compare(s);}
      /// @brief Compares two character sequences.
      /// @param pos1 The position of the first character in this string to compare.
      /// @param count1 The number of characters of this string to compare.
      /// @param s pointer to the character string to compare to.
      /// @return
      /// * Negative value if `*this` appears before the character sequence specified by the arguments, in lexicographical order.
      /// * Zero if both character sequences compare equivalent.
      /// * Positive value if `*this` appears after the character sequence specified by the arguments, in lexicographical order.
      /// @remarks Compares a [`pos1`, `pos1 + count1`) substring of this string to the null-terminated character sequence beginning at the character pointed to by `s` with length `traits_t::length(s)`.
      /// * If `count1 > size() - pos1`, the substring is [`pos1$ , size()).
      /// @remarks A character sequence consisting of `count1` characters starting at `data1` is compared to a character sequence consisting of `count2` characters starting at `data2` as follows:
      /// * First, calculate the number of characters to compare, as if by `size_type rlen = std::min(count1, count2)`.
      /// * Then compare the sequences by calling `traits_t::compare(data1, data2, rlen)`. For standard strings this function performs character-by-character lexicographical comparison. If the result is zero (the character sequences are equal so far), then their sizes are compared as follows:
      /// @remarks
      /// | Condition                                                     | Result                          | Return value |
      /// | ------------------------------------------------------------- | ------------------------------- | ------------ |
      /// | traits_t::compare(data1, data2, rlen) < 0                     | data1 is **less than** data2    | < 0          |
      /// | traits_t::compare(data1, data2, rlen) == 0 and size1 < size2  | data1 is **less than** data2    | < 0          |
      /// | traits_t::compare(data1, data2, rlen) == 0 and size1 == size2 | data1 is **equal to** data2     | 0            |
      /// | traits_t::compare(data1, data2, rlen) == 0 and size1 > size2  | data1 is **greater than** data2 | > 0          |
      /// | traits_t::compare(data1, data2, rlen) > 0                     | data1 is **greater than** data2 | > 0          |
      int32 compare(size_type pos1, size_type count1, const_pointer s) const {return chars_.compare(pos1, count1, s);}
      /// @brief Compares two character sequences.
      /// @param pos1 The position of the first character in this string to compare.
      /// @param count1 The number of characters of this string to compare.
      /// @param s pointer to the character string to compare to.
      /// @param count2 The number of characters of the given string to compare.
      /// @return
      /// * Negative value if `*this` appears before the character sequence specified by the arguments, in lexicographical order.
      /// * Zero if both character sequences compare equivalent.
      /// * Positive value if `*this` appears after the character sequence specified by the arguments, in lexicographical order.
      /// @remarks Compares a [`pos1`, `pos1 + count1`) substring of this string to the characters in the range [`s`, `s + count2`). The characters in [`s`, `s + count2`) may include null characters.
      /// * If `count1 > size() - pos1`, the substring is [`pos1`, size()).
      /// @remarks A character sequence consisting of `count1` characters starting at `data1` is compared to a character sequence consisting of `count2` characters starting at `data2` as follows:
      /// * First, calculate the number of characters to compare, as if by `size_type rlen = std::min(count1, count2)`.
      /// * Then compare the sequences by calling `traits_t::compare(data1, data2, rlen)`. For standard strings this function performs character-by-character lexicographical comparison. If the result is zero (the character sequences are equal so far), then their sizes are compared as follows:
      /// @remarks
      /// | Condition                                                     | Result                          | Return value |
      /// | ------------------------------------------------------------- | ------------------------------- | ------------ |
      /// | traits_t::compare(data1, data2, rlen) < 0                     | data1 is **less than** data2    | < 0          |
      /// | traits_t::compare(data1, data2, rlen) == 0 and size1 < size2  | data1 is **less than** data2    | < 0          |
      /// | traits_t::compare(data1, data2, rlen) == 0 and size1 == size2 | data1 is **equal to** data2     | 0            |
      /// | traits_t::compare(data1, data2, rlen) == 0 and size1 > size2  | data1 is **greater than** data2 | > 0          |
      /// | traits_t::compare(data1, data2, rlen) > 0                     | data1 is **greater than** data2 | > 0          |
      int32 compare(size_type pos1, size_type count1, const_pointer s, size_type count2) const {return chars_.compare(pos1, count1, s, count2);}
      
      /// @brief Determines whether this instance and a specified object, which must also be a xtd::basic_string_builder object, have the same value.
      /// @param obj The basic_string_builder to compare to this instance.
      /// @return `true` if `obj` is a xtd::basic_string_builder and its value is the same as this instance; otherwise, `false`.
      bool equals(const object& obj) const noexcept override {return dynamic_cast<const basic_string_builder*>(&obj) && equals(static_cast<const basic_string_builder&>(obj));}
      /// @brief Determines whether this instance and another specified xtd::basic_string_builder object have the same value.
      /// @param value The basic_string_builder to compare to this instance.
      /// @return `true` if the `value` of the value parameter is the same as the value of this instance; otherwise, `false`.
      /// @remarks This method performs an ordinal (case-sensitive) comparison.
      bool equals(const basic_string_builder& value) const noexcept override {return chars_ == value.chars_;}
      
      /// @brief Finds the first substring equal to the given character sequence. Search begins at `0`, i.e. the found substring must not begin in a position preceding `0`.
      /// @return Position of the first character of the found substring or xtd::basic_string_builder::npos if no such substring is found.
      /// @remarks Finds the first substring equal to `str`.
      size_type find(const basic_string_builder& str) const {return chars_.find(str);}
      /// @brief Finds the first substring equal to the given character sequence. Search begins at `pos`, i.e. the found substring must not begin in a position preceding `pos`.
      /// @param str The string to search for.
      /// @param pos The position at which to start the search
      /// @return Position of the first character of the found substring or xtd::basic_string_builder::npos if no such substring is found.
      /// @remarks Finds the first substring equal to `str`.
      size_type find(const basic_string_builder& str, size_type pos) const {return chars_.find(str, pos);}
      /// @brief Finds the first substring equal to the given character sequence. Search begins at `pos`, i.e. the found substring must not begin in a position preceding `pos`.
      /// @param str The string to search for.
      /// @param pos The position at which to start the search
      /// @param count The length of substring to search for.
      /// @return Position of the first character of the found substring or xtd::basic_string_builder::npos if no such substring is found.
      /// @remarks Finds the first substring equal to the range [s, s + count).
      /// @remarks This range may contain null characters. If [`s`, `s + count`) is not a valid range, the behavior is undefined.
      size_type find(const_pointer s, size_type pos, size_type count) const {return chars_.find(s, pos, count);}
      /// @brief Finds the first substring equal to the given character sequence. Search begins at `0`, i.e. the found substring must not begin in a position preceding `0`.
      /// @param s The pointer to a character string to search for.
      /// @return Position of the first character of the found substring or xtd::basic_string_builder::npos if no such substring is found.
      /// @remarks Finds the first substring equal to the character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
      /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
      size_type find(const_pointer s) const {return chars_.find(s);}
      /// @brief Finds the first substring equal to the given character sequence. Search begins at `pos`, i.e. the found substring must not begin in a position preceding `pos`.
      /// @param s The pointer to a character string to search for.
      /// @param pos The position at which to start the search
      /// @return Position of the first character of the found substring or xtd::basic_string_builder::npos if no such substring is found.
      /// @remarks Finds the first substring equal to the character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
      /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
      size_type find(const_pointer s, size_type pos) const {return chars_.find(s, pos);}
      /// @brief Finds the first substring equal to the given character sequence. Search begins at `0`, i.e. the found substring must not begin in a position preceding `0`.
      /// @param ch The character to search for.
      /// @return Position of the first character of the found substring or xtd::basic_string_builder::npos if no such substring is found.
      /// @remarks Finds the first character `ch` (treated as a single-character substring by the formal rules below).
      size_type find(value_type ch) const {return chars_.find(ch);}
      /// @brief Finds the first substring equal to the given character sequence. Search begins at `pos`, i.e. the found substring must not begin in a position preceding `pos`.
      /// @param ch The character to search for.
      /// @param pos The position at which to start the search
      /// @return Position of the first character of the found substring or xtd::basic_string_builder::npos if no such substring is found.
      /// @remarks Finds the first character `ch` (treated as a single-character substring by the formal rules below).
      size_type find(value_type ch, size_type pos) const {return chars_.find(ch, pos);}
      
      /// @brief Finds the first character equal to one of the characters in the given character sequence. The search considers only the range [`pos`, size()). If none of the characters in the given character sequence is present in the range, xtd::basic_string_builder::npos will be returned.
      /// @parzm str The string identifying characters to search for.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to one of the characters in `str`.
      size_type find_first_of(const basic_string_builder& str) const {return chars_.find_first_of(str);}
      /// @brief Finds the first character equal to one of the characters in the given character sequence. The search considers only the range [`pos`, size()). If none of the characters in the given character sequence is present in the range, xtd::basic_string_builder::npos will be returned.
      /// @param str The string identifying characters to search for.
      /// @param pos The position at which to begin searching.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to one of the characters in `str`.
      size_type find_first_of(const basic_string_builder& str, size_type pos) const {return chars_.find_first_of(str, pos);}
      /// @brief Finds the first character equal to one of the characters in the given character sequence. The search considers only the range [`pos`, size()). If none of the characters in the given character sequence is present in the range, xtd::basic_string_builder::npos will be returned.
      /// @param s The pointer to a character string identifying characters to search for.
      /// @param pos The position at which to begin searching.
      /// @param count The length of character string identifying characters to search for.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to one of the characters in the range [`s`, `s + count`). This range can include null characters.
      /// @remarks If [`s`, `s + count`) is not a valid range, the behavior is undefined.
      size_type find_first_of(const_pointer s, size_type pos, size_type count) const {return chars_.find_first_of(s, pos, count);}
      /// @brief Finds the first character equal to one of the characters in the given character sequence. The search considers only the range [`pos`, size()). If none of the characters in the given character sequence is present in the range, xtd::basic_string_builder::npos will be returned.
      /// @param s The pointer to a character string identifying characters to search for.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to one of the characters in character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
      /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
      size_type find_first_of(const_pointer s) const {return chars_.find_first_of(s);}
      /// @brief Finds the first character equal to one of the characters in the given character sequence. The search considers only the range [`pos`, size()). If none of the characters in the given character sequence is present in the range, xtd::basic_string_builder::npos will be returned.
      /// @param s The pointer to a character string identifying characters to search for.
      /// @param pos The position at which to begin searching.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to one of the characters in character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
      /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
      size_type find_first_of(const_pointer s, size_type pos) const {return chars_.find_first_of(s, pos);}
      /// @brief Finds the first character equal to one of the characters in the given character sequence. The search considers only the range [`pos`, size()). If none of the characters in the given character sequence is present in the range, xtd::basic_string_builder::npos will be returned.
      /// @param ch The character to search for.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to `ch`.
      size_type find_first_of(char_t ch) const {return chars_.find_first_of(ch);}
      /// @brief Finds the first character equal to one of the characters in the given character sequence. The search considers only the range [`pos`, size()). If none of the characters in the given character sequence is present in the range, xtd::basic_string_builder::npos will be returned.
      /// @param ch The character to search for.
      /// @param pos The position at which to begin searching.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to `ch`.
      size_type find_first_of(char_t ch, size_type pos) const {return chars_.find_first_of(ch, pos);}
      
      /// @brief Finds the first character equal to none of the characters in the given character sequence. The search considers only the range [`pos`, size()). If all characters in the range can be found in the given character sequence, xtd::basic_string_builder::npos will be returned.
      /// @parzm str The string identifying characters to search for.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to one of the characters in `str`.
      size_type find_first_not_of(const basic_string_builder& str) const {return chars_.find_first_not_of(str);}
      /// @brief Finds the first character equal to none of the characters in the given character sequence. The search considers only the range [`pos`, size()). If all characters in the range can be found in the given character sequence, xtd::basic_string_builder::npos will be returned.
      /// @param str The string identifying characters to search for.
      /// @param pos The position at which to begin searching.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to one of the characters in `str`.
      size_type find_first_not_of(const basic_string_builder& str, size_type pos) const {return chars_.find_first_not_of(str, pos);}
      /// @brief Finds the first character equal to none of the characters in the given character sequence. The search considers only the range [`pos`, size()). If all characters in the range can be found in the given character sequence, xtd::basic_string_builder::npos will be returned.
      /// @param s The pointer to a character string identifying characters to search for.
      /// @param pos The position at which to begin searching.
      /// @param count The length of character string identifying characters to search for.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to one of the characters in the range [`s`, `s + count`). This range can include null characters.
      /// @remarks If [`s`, `s + count`) is not a valid range, the behavior is undefined.
      size_type find_first_not_of(const_pointer s, size_type pos, size_type count) const {return chars_.find_first_not_of(s, pos, count);}
      /// @brief Finds the first character equal to none of the characters in the given character sequence. The search considers only the range [`pos`, size()). If all characters in the range can be found in the given character sequence, xtd::basic_string_builder::npos will be returned.
      /// @param s The pointer to a character string identifying characters to search for.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to one of the characters in character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
      /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
      size_type find_first_not_of(const_pointer s) const {return chars_.find_first_not_of(s);}
      /// @brief Finds the first character equal to none of the characters in the given character sequence. The search considers only the range [`pos`, size()). If all characters in the range can be found in the given character sequence, xtd::basic_string_builder::npos will be returned.
      /// @param s The pointer to a character string identifying characters to search for.
      /// @param pos The position at which to begin searching.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to one of the characters in character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
      /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
      size_type find_first_not_of(const_pointer s, size_type pos) const {return chars_.find_first_not_of(s, pos);}
      /// @brief Finds the first character equal to none of the characters in the given character sequence. The search considers only the range [`pos`, size()). If all characters in the range can be found in the given character sequence, xtd::basic_string_builder::npos will be returned.
      /// @param ch The character to search for.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to `ch`.
      size_type find_first_not_of(char_t ch) const {return chars_.find_first_not_of(ch);}
      /// @brief Finds the first character equal to none of the characters in the given character sequence. The search considers only the range [`pos`, size()). If all characters in the range can be found in the given character sequence, xtd::basic_string_builder::npos will be returned.
      /// @param ch The character to search for.
      /// @param pos The position at which to begin searching.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to `ch`.
      size_type find_first_not_of(char_t ch, size_type pos) const {return chars_.find_first_not_of(ch, pos);}
      
      /// @brief Finds the last character equal to one of characters in the given character sequence. The exact search algorithm is not specified. The search considers only the range [​`0`​, `pos`]. If none of the characters in the given character sequence is present in the range, xtd::basic_string_builder::npos will be returned.
      /// @parzm str The string identifying characters to search for.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to one of the characters in `str`.
      size_type find_last_of(const basic_string_builder& str) const {return chars_.find_last_of(str);}
      /// @brief Finds the last character equal to one of characters in the given character sequence. The exact search algorithm is not specified. The search considers only the range [​`0`​, `pos`]. If none of the characters in the given character sequence is present in the range, xtd::basic_string_builder::npos will be returned.
      /// @param str The string identifying characters to search for.
      /// @param pos The position at which to begin searching.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to one of the characters in `str`.
      size_type find_last_of(const basic_string_builder& str, size_type pos) const {return chars_.find_last_of(str, pos);}
      /// @brief Finds the last character equal to one of characters in the given character sequence. The exact search algorithm is not specified. The search considers only the range [​`0`​, `pos`]. If none of the characters in the given character sequence is present in the range, xtd::basic_string_builder::npos will be returned.
      /// @param s The pointer to a character string identifying characters to search for.
      /// @param pos The position at which to begin searching.
      /// @param count The length of character string identifying characters to search for.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to one of the characters in the range [`s`, `s + count`). This range can include null characters.
      /// @remarks If [`s`, `s + count`) is not a valid range, the behavior is undefined.
      size_type find_last_of(const_pointer s, size_type pos, size_type count) const {return chars_.find_last_of(s, pos, count);}
      /// @brief Finds the last character equal to one of characters in the given character sequence. The exact search algorithm is not specified. The search considers only the range [​`0`​, `pos`]. If none of the characters in the given character sequence is present in the range, xtd::basic_string_builder::npos will be returned.
      /// @param s The pointer to a character string identifying characters to search for.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to one of the characters in character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
      /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
      size_type find_last_of(const_pointer s) const {return chars_.find_last_of(s);}
      /// @brief Finds the last character equal to one of characters in the given character sequence. The exact search algorithm is not specified. The search considers only the range [​`0`​, `pos`]. If none of the characters in the given character sequence is present in the range, xtd::basic_string_builder::npos will be returned.
      /// @param s The pointer to a character string identifying characters to search for.
      /// @param pos The position at which to begin searching.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to one of the characters in character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
      /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
      size_type find_last_of(const_pointer s, size_type pos) const {return chars_.find_last_of(s, pos);}
      /// @brief Finds the last character equal to one of characters in the given character sequence. The exact search algorithm is not specified. The search considers only the range [​`0`​, `pos`]. If none of the characters in the given character sequence is present in the range, xtd::basic_string_builder::npos will be returned.
      /// @param ch The character to search for.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to `ch`.
      size_type find_last_of(char_t ch) const {return chars_.find_last_of(ch);}
      /// @brief Finds the last character equal to one of characters in the given character sequence. The exact search algorithm is not specified. The search considers only the range [​`0`​, `pos`]. If none of the characters in the given character sequence is present in the range, xtd::basic_string_builder::npos will be returned.
      /// @param ch The character to search for.
      /// @param pos The position at which to begin searching.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to `ch`.
      size_type find_last_of(char_t ch, size_type pos) const {return chars_.find_last_of(ch, pos);}
      
      /// @brief Finds the last character equal to none of the characters in the given character sequence. The search considers only the range [​`0`​, `pos`]. If all characters in the range can be found in the given character sequence,xtd::basic_string_builder::npos will be returned.
      /// @parzm str The string identifying characters to search for.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to one of the characters in `str`.
      size_type find_last_not_of(const basic_string_builder& str) const {return chars_.find_last_not_of(str);}
      /// @brief Finds the last character equal to none of the characters in the given character sequence. The search considers only the range [​`0`​, `pos`]. If all characters in the range can be found in the given character sequence,xtd::basic_string_builder::npos will be returned.
      /// @param str The string identifying characters to search for.
      /// @param pos The position at which to begin searching.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to one of the characters in `str`.
      size_type find_last_not_of(const basic_string_builder& str, size_type pos) const {return chars_.find_last_not_of(str, pos);}
      /// @brief Finds the last character equal to none of the characters in the given character sequence. The search considers only the range [​`0`​, `pos`]. If all characters in the range can be found in the given character sequence,xtd::basic_string_builder::npos will be returned.
      /// @param s The pointer to a character string identifying characters to search for.
      /// @param pos The position at which to begin searching.
      /// @param count The length of character string identifying characters to search for.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to one of the characters in the range [`s`, `s + count`). This range can include null characters.
      /// @remarks If [`s`, `s + count`) is not a valid range, the behavior is undefined.
      size_type find_last_not_of(const_pointer s, size_type pos, size_type count) const {return chars_.find_last_not_of(s, pos, count);}
      /// @brief Finds the last character equal to none of the characters in the given character sequence. The search considers only the range [​`0`​, `pos`]. If all characters in the range can be found in the given character sequence,xtd::basic_string_builder::npos will be returned.
      /// @param s The pointer to a character string identifying characters to search for.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to one of the characters in character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
      /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
      size_type find_last_not_of(const_pointer s) const {return chars_.find_last_not_of(s);}
      /// @brief Finds the last character equal to none of the characters in the given character sequence. The search considers only the range [​`0`​, `pos`]. If all characters in the range can be found in the given character sequence,xtd::basic_string_builder::npos will be returned.
      /// @param s The pointer to a character string identifying characters to search for.
      /// @param pos The position at which to begin searching.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to one of the characters in character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
      /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
      size_type find_last_not_of(const_pointer s, size_type pos) const {return chars_.find_last_not_of(s, pos);}
      /// @brief Finds the last character equal to none of the characters in the given character sequence. The search considers only the range [​`0`​, `pos`]. If all characters in the range can be found in the given character sequence,xtd::basic_string_builder::npos will be returned.
      /// @param ch The character to search for.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to `ch`.
      size_type find_last_not_of(char_t ch) const {return chars_.find_last_not_of(ch);}
      /// @brief Finds the last character equal to none of the characters in the given character sequence. The search considers only the range [​`0`​, `pos`]. If all characters in the range can be found in the given character sequence,xtd::basic_string_builder::npos will be returned.
      /// @param ch The character to search for.
      /// @param pos The position at which to begin searching.
      /// @return Position of the found character or xtd::basic_string_builder::npos if no such character is found.
      /// @remarks Finds the first character equal to `ch`.
      size_type find_last_not_of(char_t ch, size_type pos) const {return chars_.find_last_not_of(ch, pos);}
      
      /// @brief Returns the allocator associated with the string.
      /// @return The associated allocator.
      allocator_type get_allocator() const {return chars_.get_allocator();}
      
      /// @brief Returns the underlying base type.
      /// @return The underlying base type.
      virtual const base_type& get_base_type() const noexcept {return chars_;}
      
      /// @brief Returns the hash code for this basic_string_builder.
      /// @return A hash code.
      xtd::size get_hash_code() const noexcept override {return xtd::hash_code::combine(chars_);}
      
      /// @brief Finds the last substring that is equal to the given character sequence. The search begins at xtd::basic_string_builder::npos` and proceeds from right to left (thus, the found substring, if any, cannot begin in a position following xtd::basic_string_builder::npos). If xtd::basic_string_builder::npos or any value not smaller than xtd::basic_string_builder::size() - 1 is passed as xtd::basic_string_builder::npos, the whole string will be searched.
      /// @return Position of the first character of the found substring or xtd::basic_string_builder::npos if no such substring is found.
      /// @remarks Finds the first substring equal to `str`.
      size_type rfind(const basic_string_builder& str) const {return chars_.rfind(str);}
      /// @brief Finds the last substring that is equal to the given character sequence. The search begins at `pos` and proceeds from right to left (thus, the found substring, if any, cannot begin in a position following `pos`). If xtd::basic_string_builder::npos or any value not smaller than xtd::basic_string_builder::size() - 1 is passed as `pos`, the whole string will be searched.
      /// @param str The string to search for.
      /// @param pos The position at which to start the search
      /// @return Position of the first character of the found substring or xtd::basic_string_builder::npos if no such substring is found.
      /// @remarks Finds the first substring equal to `str`.
      size_type rfind(const basic_string_builder& str, size_type pos) const {return chars_.rfind(str, pos);}
      /// @brief Finds the last substring that is equal to the given character sequence. The search begins at `pos` and proceeds from right to left (thus, the found substring, if any, cannot begin in a position following `pos`). If xtd::basic_string_builder::npos or any value not smaller than xtd::basic_string_builder::size() - 1 is passed as `pos`, the whole string will be searched.
      /// @param str The string to search for.
      /// @param pos The position at which to start the search
      /// @param count The length of substring to search for.
      /// @return Position of the first character of the found substring or xtd::basic_string_builder::npos if no such substring is found.
      /// @remarks Finds the first substring equal to the range [s, s + count).
      /// @remarks This range may contain null characters. If [`s`, `s + count`) is not a valid range, the behavior is undefined.
      size_type rfind(const_pointer s, size_type pos, size_type count) const {return chars_.rfind(s, pos, count);}
      /// @brief Finds the last substring that is equal to the given character sequence. The search begins at xtd::basic_string_builder::npos` and proceeds from right to left (thus, the found substring, if any, cannot begin in a position following xtd::basic_string_builder::npos). If xtd::basic_string_builder::npos or any value not smaller than xtd::basic_string_builder::size() - 1 is passed as xtd::basic_string_builder::npos, the whole string will be searched.
      /// @param s The pointer to a character string to search for.
      /// @return Position of the first character of the found substring or xtd::basic_string_builder::npos if no such substring is found.
      /// @remarks Finds the first substring equal to the character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
      /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
      size_type rfind(const_pointer s) const {return chars_.rfind(s);}
      /// @brief Finds the last substring that is equal to the given character sequence. The search begins at `pos` and proceeds from right to left (thus, the found substring, if any, cannot begin in a position following `pos`). If xtd::basic_string_builder::npos or any value not smaller than xtd::basic_string_builder::size() - 1 is passed as `pos`, the whole string will be searched.
      /// @param s The pointer to a character string to search for.
      /// @param pos The position at which to start the search
      /// @return Position of the first character of the found substring or xtd::basic_string_builder::npos if no such substring is found.
      /// @remarks Finds the first substring equal to the character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
      /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
      size_type rfind(const_pointer s, size_type pos) const {return chars_.rfind(s, pos);}
      /// @brief Finds the last substring that is equal to the given character sequence. The search begins at xtd::basic_string_builder::npos` and proceeds from right to left (thus, the found substring, if any, cannot begin in a position following xtd::basic_string_builder::npos). If xtd::basic_string_builder::npos or any value not smaller than xtd::basic_string_builder::size() - 1 is passed as xtd::basic_string_builder::npos, the whole string will be searched.
      /// @param ch The character to search for.
      /// @return Position of the first character of the found substring or xtd::basic_string_builder::npos if no such substring is found.
      /// @remarks Finds the first character `ch` (treated as a single-character substring by the formal rules below).
      size_type rfind(value_type ch) const {return chars_.rfind(ch);}
      /// @brief Finds the last substring that is equal to the given character sequence. The search begins at `pos` and proceeds from right to left (thus, the found substring, if any, cannot begin in a position following `pos`). If xtd::basic_string_builder::npos or any value not smaller than xtd::basic_string_builder::size() - 1 is passed as `pos`, the whole string will be searched.
      /// @param ch The character to search for.
      /// @param pos The position at which to start the search
      /// @return Position of the first character of the found substring or xtd::basic_string_builder::npos if no such substring is found.
      /// @remarks Finds the first character `ch` (treated as a single-character substring by the formal rules below).
      size_type rfind(value_type ch, size_type pos) const {return chars_.rfind(ch, pos);}
      
      /// @brief Returns a substring [`pos`, `pos + count`). If the requested substring extends past the end of the string, i.e. the `count` is greater than size() - pos (e.g. if `count` == xtd::basic_string_builder::npos), the returned substring is [`pos`, size()).
      /// @return String containing the substring [`pos`, `pos + count`) or [pos, size()).
      /// @exception `std::out_of_range` if `pos > size()`.
      /// @remarks Equivalent to return `basic_string_builder(*this, pos, count);`.
      basic_string_builder substr() const {return chars_.substr();}
      /// @brief Returns a substring [`pos`, `pos + count`). If the requested substring extends past the end of the string, i.e. the `count` is greater than size() - pos (e.g. if `count` == xtd::basic_string_builder::npos), the returned substring is [`pos`, size()).
      /// @param pos The position of the first character to include.
      /// @return String containing the substring [`pos`, `pos + count`) or [pos, size()).
      /// @exception `std::out_of_range` if `pos > size()`.
      /// @remarks Equivalent to return `basic_string_builder(*this, pos, count);`.
      basic_string_builder substr(size_type pos) const {return chars_.substr(pos);}
      /// @brief Returns a substring [`pos`, `pos + count`). If the requested substring extends past the end of the string, i.e. the `count` is greater than size() - pos (e.g. if `count` == xtd::basic_string_builder::npos), the returned substring is [`pos`, size()).
      /// @param pos The position of the first character to include.
      /// @param count The length of the substring.
      /// @return String containing the substring [`pos`, `pos + count`) or [pos, size()).
      /// @exception `std::out_of_range` if `pos > size()`.
      /// @remarks Equivalent to return `basic_string_builder(*this, pos, count);`.
      basic_string_builder substr(size_type pos, size_type count) const {return chars_.substr(pos, count);}
      
      /// @brief Converts the value of this instance to a xtd::basic_string_builder <char>.
      /// @return The current string.
      /// @todo Uncomment the folllowing line and remove the next..
      //xtd::string to_string() const noexcept override {return __xtd_convert_to_string<char>(chars_);}
      xtd::string to_string() const noexcept override {return xtd::string {chars_};}
      /// @}
      
      /// @name Public Static Methods
      
      /// @{

      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Returns a reference to the character at specified location index.
      /// @param index The position of the character to return.
      /// @return Reference to the requested character.
      /// @exception xtd::index_out_of_range_exception If `index` is not within the range of the string.
      const_reference operator [](xtd::size index) const {
        if (index >= length()) throw xtd::index_out_of_range_exception(csf_);
        return chars_[index];
      }
      
      /// @brief Returns a reference to the underlying base type.
      /// @return Reference to the underlying base type.
      virtual operator const base_type&() const noexcept {return chars_;}
      
      /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of str.
      /// @param str String to use as data source.
      /// @return This current instance.
      basic_string_builder& operator =(const basic_string_builder& str) noexcept {
        chars_ = str.chars_;
        return *this;
      }
      
      /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in `str` is moved from `str` into this string). `str` is in a valid but unspecified state afterwards.
      /// @param str String to use as data source.
      /// @return This current instance.
      basic_string_builder& operator =(basic_string_builder&& str) noexcept {
        chars_ = std::move(str.chars_);
        return *this;
      }
      
      /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
      /// @param str String to use as data source.
      /// @return This current instance.
      basic_string_builder& operator =(const std::basic_string<value_type>& str) noexcept {
        chars_ = str;
        return *this;
      }
      
      /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
      /// @param str String to use as data source.
      /// @return This current instance.
      basic_string_builder& operator =(std::basic_string<value_type>&& str) noexcept {
        chars_ = std::move(str);
        return *this;
      }
      
      /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
      /// @param str String litteral pointer to use as data source.
      /// @exception xtd::tring_null_pointer_exception The `str` is null.
      /// @return This current instance.
      basic_string_builder& operator =(const_pointer str) {
        if (str == null) throw xtd::null_pointer_exception(csf_);
        chars_ = str;
        return *this;
      }
      
      /// @brief Copy assignment operator. Replaces the contents with the specified character.
      /// @param character The character to use as data source.
      /// @return This current instance.
      basic_string_builder& operator =(value_type character) {
        chars_ = character;
        return  *this;
      }
      
      /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of the specified initializer list.
      /// @param il The initialiazer list to use as data source.
      /// @return This current instance.
      basic_string_builder& operator =(const std::initializer_list<value_type>& il) {
        chars_ = il;
        return *this;
      }
      
      /// @brief Addition assignment operator. Appends additional characters to the string.
      /// @param str string to append.
      /// @return This current instance with characters added.
      basic_string_builder& operator +=(const basic_string_builder& str) {
        chars_ += str.chars_;
        return *this;
      }
      
      /// @brief Addition assignment operator. Appends additional characters to the string.
      /// @param str string to append.
      /// @return This current instance with characters added.
      basic_string_builder& operator +=(basic_string_builder&& str) {
        chars_ += std::move(str.chars_);
        str.chars_.clear();
        return *this;
      }
      
      /// @brief Addition assignment operator. Appends additional characters to the string.
      /// @param str string to append.
      /// @return This current instance with characters added.
      basic_string_builder& operator +=(const_pointer str) {
        if (str == null) throw xtd::null_pointer_exception(csf_);
        chars_ += str;
        return *this;
      }

      /// @brief Addition assignment operator. Appends additional characters to the string.
      /// @param ch Character value to append.
      /// @return This current instance with characters added.
      basic_string_builder& operator +=(value_type ch) {
        chars_ += ch;
        return *this;
      }
      
      /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
      /// @param lhs The string characters who will precede the `rhs`.
      /// @param rhs The string characters who will follow the `lhs`.
      /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
      friend basic_string_builder operator +(const basic_string_builder& lhs, const basic_string_builder& rhs) {
        auto result = lhs;
        result += rhs;
        return result;
      }
      
      /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
      /// @param lhs The string characters who will precede the `rhs`.
      /// @param rhs The string characters who will follow the `lhs`.
      /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
      friend basic_string_builder operator +(basic_string_builder&& lhs, basic_string_builder&& rhs) {
        auto result = std::move(lhs);
        result += std::move(rhs);
        return result;
      }
      
      /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
      /// @param lhs The string characters who will precede the `rhs`.
      /// @param rhs The string characters who will follow the `lhs`.
      /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
      friend basic_string_builder operator +(basic_string_builder&& lhs, const basic_string_builder& rhs) {
        auto result = std::move(lhs);
        result += rhs;
        return result;
      }
      
      /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
      /// @param lhs The string characters who will precede the `rhs`.
      /// @param rhs The string characters who will follow the `lhs`.
      /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
      friend basic_string_builder operator +(const basic_string_builder& lhs, basic_string_builder&& rhs) {
        auto result = lhs;
        result += std::move(rhs);
        return result;
      }
      
      /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
      /// @param lhs The string characters who will precede the `rhs`.
      /// @param rhs The string characters who will follow the `lhs`.
      /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
      friend basic_string_builder operator +(const basic_string_builder& lhs, const_pointer rhs) {
        auto result = lhs;
        result += rhs;
        return result;
      }
      
      /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
      /// @param lhs The string characters who will precede the `rhs`.
      /// @param rhs The string characters who will follow the `lhs`.
      /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
      friend basic_string_builder operator +(basic_string_builder&& lhs, const_pointer rhs) {
        auto result = std::move(lhs);
        result += rhs;
        return result;
      }
      
      /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
      /// @param lhs The string characters who will precede the `rhs`.
      /// @param rhs The string characters who will follow the `lhs`.
      /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
      friend basic_string_builder operator +(const_pointer lhs, const basic_string_builder& rhs) {
        return lhs + rhs.chars_;
      }
      
      /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
      /// @param lhs The string characters who will precede the `rhs`.
      /// @param rhs The string characters who will follow the `lhs`.
      /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
      friend basic_string_builder operator +(const_pointer lhs, basic_string_builder&& rhs) {
        return lhs + std::move(rhs).chars_;
      }
      
      /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
      /// @param lhs The string characters who will precede the `rhs`.
      /// @param rhs The character who will follow the `lhs`.
      /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
      friend basic_string_builder operator +(basic_string_builder& lhs, value_type rhs) {
        auto result = lhs;
        result += rhs;
        return result;
      }
      
      /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
      /// @param lhs The string characters who will precede the `rhs`.
      /// @param rhs The character who will follow the `lhs`.
      /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
      friend basic_string_builder operator +(basic_string_builder&& lhs, value_type rhs) {
        auto result = std::move(lhs);
        result += rhs;
        return result;
      }

      /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
      /// @param lhs The character who will precede the `rhs`.
      /// @param rhs The string characters who will follow the `lhs`.
      /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
      friend basic_string_builder operator +(value_type lhs, const basic_string_builder& rhs) {
        auto result = basic_string_builder(1, lhs);
        result += rhs;
        return result;
      }
      
      /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
      /// @param lhs The character who will precede the `rhs`.
      /// @param rhs The string characters who will follow the `lhs`.
      /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
      friend basic_string_builder operator +(value_type lhs, basic_string_builder&& rhs) {
        auto result = basic_string_builder(1, lhs);
        result += std::move(rhs);
        return result;
      }
      
      /// @todo uncomment following operators
      /// @brief Output stream operator. Behaves as a [FormattedOutputFunction](https://en.cppreference.com/w/cpp/named_req/FormattedOutputFunction). After constructing and checking the sentry object, [determines the output format padding](https://en.cppreference.com/w/cpp/named_req/FormattedOutputFunction#Padding).
      /// @param os The character output stream.
      /// @param str The string to be inserted.
      /// @remarks Then inserts each character from the resulting sequence `seq` (the contents of `str` plus padding) to the output stream `os` as if by calling `os.rdbuf()->sputn(seq, n)`, where n is `std::max(os.width(), str.size())`.
      /// @remarks Finally, calls `os.width(0)` to cancel the effects of std::setw, if any.
      /// @remarks Equivalent to `return os << std::basic_string_view<char_t, traits_t>(str);`.
      /// @todo uncomment following line and remove the next.
      //friend std::basic_ostream<char>& operator <<(std::basic_ostream<char>& stream, const basic_string_builder& str) {return stream << str.to_string().chars_;}
      friend std::basic_ostream<char>& operator <<(std::basic_ostream<char>& stream, const basic_string_builder& str) {return stream << xtd::basic_string<char>(str.chars()).chars();}
      /// @brief Output stream operator. Behaves as a [FormattedOutputFunction](https://en.cppreference.com/w/cpp/named_req/FormattedOutputFunction). After constructing and checking the sentry object, [determines the output format padding](https://en.cppreference.com/w/cpp/named_req/FormattedOutputFunction#Padding).
      /// @param os The character output stream.
      /// @param str The string to be inserted.
      /// @remarks Then inserts each character from the resulting sequence `seq` (the contents of `str` plus padding) to the output stream `os` as if by calling `os.rdbuf()->sputn(seq, n)`, where n is `std::max(os.width(), str.size())`.
      /// @remarks Finally, calls `os.width(0)` to cancel the effects of std::setw, if any.
      /// @remarks Equivalent to `return os << std::basic_string_view<char_t, traits_t>(str);`.
      friend std::basic_ostream<xtd::wchar>& operator <<(std::basic_ostream<xtd::wchar>& stream, const basic_string_builder& str) {return stream << xtd::basic_string<xtd::wchar>(str.chars()).chars();}
      
      /// @brief Input stream operator. Behaves as a [FormattedInputFunction](https://en.cppreference.com/w/cpp/named_req/FormattedInputFunction). After constructing and checking the sentry object, which may skip leading whitespace, first clears `str` with `str.erase()`, then reads characters from `is` and appends them to `str` as if by `str.append(1, c)`, until one of the following conditions becomes true:
      /// * N characters are read, where N is `is.width()` if `is.width() > 0`, otherwise N is `str.max_size()`,
      /// * the end-of-file condition occurs in the stream is, or
      /// * `std::isspace(c, is.getloc())` is `true` for the next character `c` in `is` (this whitespace character remains in the input stream).
      /// @param is The character input stream.
      /// @param str The string to be extracted.
      /// @remarks If no characters are extracted then std::ios::failbit is set on `is`, which may throw [std::ios_base::failure](https://en.cppreference.com/w/cpp/io/ios_base/failure).
      /// @remarks Finally, calls `is.width(0)` to cancel the effects of [std::setw](https://en.cppreference.com/w/cpp/io/manip/setw), if any.
      friend std::basic_istream<char>& operator >>(std::basic_istream<char>& stream, basic_string_builder& str) {
        auto s = std::basic_string<char> {};
        stream >> s;
        str = xtd::basic_string<value_type>(s).chars();
        return stream;
      }
      /// @brief Input stream operator. Behaves as a [FormattedInputFunction](https://en.cppreference.com/w/cpp/named_req/FormattedInputFunction). After constructing and checking the sentry object, which may skip leading whitespace, first clears `str` with `str.erase()`, then reads characters from `is` and appends them to `str` as if by `str.append(1, c)`, until one of the following conditions becomes true:
      /// * N characters are read, where N is `is.width()` if `is.width() > 0`, otherwise N is `str.max_size()`,
      /// * the end-of-file condition occurs in the stream is, or
      /// * `std::isspace(c, is.getloc())` is `true` for the next character `c` in `is` (this whitespace character remains in the input stream).
      /// @param is The character input stream.
      /// @param str The string to be extracted.
      /// @remarks If no characters are extracted then std::ios::failbit is set on `is`, which may throw [std::ios_base::failure](https://en.cppreference.com/w/cpp/io/ios_base/failure).
      /// @remarks Finally, calls `is.width(0)` to cancel the effects of [std::setw](https://en.cppreference.com/w/cpp/io/manip/setw), if any.
      friend std::basic_istream<xtd::wchar>& operator >>(std::basic_istream<xtd::wchar>& stream, basic_string_builder& str) {
        auto s = std::basic_string<xtd::wchar> {};
        stream >> s;
        str = xtd::basic_string<value_type>(s).chars();
        return stream;
      }
      /// @}
      
    private:
      base_type chars_;
      size_type max_capacity_ = npos;
    };
  }
}
