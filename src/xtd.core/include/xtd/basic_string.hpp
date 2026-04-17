/// @file
/// @brief Contains xtd::basic_string class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
/// @cond
#define __XTD_CORE_INTERNAL__
#include "internal/__array_definition.hpp"
#include "internal/__format_information.hpp"
#include "internal/__sprintf.hpp"
#include "internal/__string_definitions.hpp"
#undef __XTD_CORE_INTERNAL__
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__
/// @endcond
#include "collections/generic/ienumerable.hpp"
#include "hash_code.hpp"
#include "icomparable.hpp"
#include "iequatable.hpp"
#include "null.hpp"
#include "string_comparison.hpp"
#include "string_split_options.hpp"
#include "types.hpp"
#include "object.hpp"
#include "parse.hpp"
#include "types.hpp"
#include <cctype>
#include <iomanip>
#include <ostream>
#include <sstream>
#include <string>

/// @cond
template<typename ...args_t>
void __basic_string_extract_format_arg(const std::locale& loc, xtd::basic_string<char>& fmt, xtd::array<__format_information<char >>& formats, args_t&&... args);
template<typename target_t, typename source_t>
std::basic_string<target_t> __xtd_convert_to_string(std::basic_string<source_t>&& str) noexcept;
template<typename target_t, typename source_t>
std::basic_string<target_t> __xtd_convert_to_string(const std::basic_string<source_t>& str) noexcept;
std::basic_string<char> __xtd_demangle(const std::basic_string<char>& value) noexcept;
std::basic_string<char> __xtd_get_class_name(const std::type_info& value) noexcept;
std::basic_string<char> __xtd_get_full_class_name(const std::type_info& value) noexcept;
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents text as a sequence of character units.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system strings
  /// @remarks A basic_string is a sequential collection of characters that's used to represent text. A xtd::basic_string object is a sequential collection of char that represent a basic_string. The value of the xtd::basic_string object is the content of the sequential collection of `char_t`, and unlike [std::basic_string<char_t>](https://en.cppreference.com/w/cpp/basic_string/basic_string) that value is immutable (that is, it is read-only).
  /// @remarks If you want the same mutable basic_string class, you can use xtd::text::basic_string_builder <char_t> class.
  /// @remarks xtd::basic_string implements [std::basic_string<char>](https://en.cppreference.com/w/cpp/basic_string/basic_string) and therefore offers the full (immutable) API of std::basic_string.
  /// @remarks Several aliases for common character types are provided:
  /// @remarks
  /// | Type           | Definition                      |
  /// | -------------- | ------------------------------- |
  /// | xtd::string    | xtd::basic_string <char>        |
  /// | xtd::u16string | xtd::basic_string <xtd::char16> |
  /// | xtd::u32string | xtd::basic_string <xtd::char32> |
  /// | xtd::u8string  | xtd::basic_string <xtd::char8>  |
  /// | xtd::wstring   | xtd::basic_string <xtd::wchar>  |
  template<typename char_t, typename traits_t, typename allocator_t>
  class basic_string : public object, public xtd::icomparable<basic_string<char_t, traits_t, allocator_t>>, public xtd::iequatable<basic_string<char_t, traits_t, allocator_t >>, public xtd::collections::generic::ienumerable<char_t> {
  public:
    /// @name Public Aliases
    
    /// @{
    /// @brief Represents the basic string base type.
    /// @remarks Is equal to `std::basic_string<char_t, traits_t, allocator_t>`.
    using base_type = std::basic_string<char_t, traits_t, allocator_t>;
    /// @brief Represents the basic string traits type.
    using traits_type = typename base_type::traits_type;
    /// @brief Represents the basic string value type.
    using value_type = typename base_type::value_type;
    /// @brief Represents the basic string allocator type.
    using allocator_type = typename base_type::allocator_type;
    /// @brief Represents the basic string size type.
    using size_type = typename base_type::size_type;
    /// @brief Represents the basic string difference type.
    using difference_type = typename base_type::difference_type;
    /// @brief Represents the basic string referecne type.
    using reference = typename base_type::reference;
    /// @brief Represents the basic string const referecne type.
    using const_reference = typename base_type::const_reference;
    /// @brief Represents the basic string pointer type.
    using pointer = typename base_type::pointer;
    /// @brief Represents the basic string const pointer type.
    using const_pointer = typename base_type::const_pointer;
    /// @brief Represents the basic string iterator type.
    /// @todo replace xtd::ienumerable::iterator
    using iterator = typename xtd::collections::generic::ienumerable<char_t>::iterator;
    /// @brief Represents the basic string const iterator type.
    /// @todo replace xtd::ienumerable::const_iterator
    using const_iterator = typename xtd::collections::generic::ienumerable<char_t>::const_iterator;
    /// @brief Represents the basic string reverse iterator type.
    using reverse_iterator = typename base_type::reverse_iterator;
    /// @brief Represents the basic string const reverse iterator type.
    using const_reverse_iterator = typename base_type::const_reverse_iterator;
    /// @brief Represents the basic string enumerator type.
    using enumerator_type = typename xtd::collections::generic::enumerator<value_type>;
    /// @}
    
    /// @name Public Fields
    
    /// @{
    /// @brief Represents the empty basic_string.
    /// @remarks The value of this method is the zero-length basic_string, "".
    static const basic_string empty_string;
    
    /// @brief Represents a value that is not a valid position in a collection.
    /// @remarks This constant is typically used to indicate the absence of an index or a failed search operation. It is equivalent to the maximum value of xtd::usize.
    /// @par Examples
    /// ```cpp
    /// auto str = string {"hello"};
    /// if (str.index_of('g') == str.npos)
    ///   console::write_line("Value not found");
    /// ```
    inline static constexpr size_type npos = base_type::npos;
    
    /// @brief Represents the index of the first valid element in a collection.
    /// @remarks Unlike xtd::npos (which means "no position"), xtd::bpos points to the first accessible element of a collection. It is equivalent to `0`.
    /// @par Examples
    /// ```cpp
    /// auto str = string {"hello"};
    /// console::write_line(str[bpos]); // Prints 'h'
    /// console::write_line(str[bpos + 1]); // Prints 'e'
    /// ```
    static inline constexpr xtd::usize bpos = 0;
    
    /// @brief Represents the index of the last valid element in a collection.
    /// @remarks Unlike xtd::npos (which means "no position"), xtd::epos points to the last accessible element of a collection. It is equivalent to `items.count() - 1`.
    /// @note This constant is provided for readability and convenience. For example, `items[xtd::epos]` directly accesses the last element without manually subtracting one from the collection count.
    /// @remarks The epos is equivalent to `~1_z`. With bitwise operator the code is more concise.
    /// @par Examples
    /// ```cpp
    /// auto str = string {"hello"};
    /// console::write_line(str[epos]); // Prints 'o'
    /// console::write_line(str[epos - 1]); // Prints 'l'
    /// ```
    /// The wollowing exemple shows the same example with bitwise operator as index.
    /// ```cpp
    /// auto str = string {"hello"};
    /// console::write_line(str[~1_z]); // Prints 'o'
    /// console::write_line(str[~2_z]); // Prints 'l'
    /// ```
    static inline constexpr xtd::usize epos = npos - 1;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes a new instance of xtd::basic_string.
    basic_string() = default;
    /// @brief Initializes a new instance of xtd::basic_string with specified string to move.
    /// @param str The basic_string to move.
    basic_string(basic_string&&) = default;
    /// @brief Initializes a new instance of xtd::basic_string with specified string to move.
    /// @param str The basic_string to move.
    basic_string(std::basic_string<char_t>&& str) : chars_ {std::move(str)} {}
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const basic_string<char>& str) noexcept {
      if constexpr(std::is_same_v<char, char_t>) chars_ = str.chars_;
      else chars_ = __xtd_convert_to_string<value_type>(str.chars_);
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const basic_string<xtd::char16>& str) noexcept {
      if constexpr(std::is_same_v<xtd::char16, char_t>) chars_ = str.chars_;
      else chars_ = __xtd_convert_to_string<value_type>(str.chars_);
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const basic_string<xtd::char32>& str) noexcept {
      if constexpr(std::is_same_v<xtd::char32, char_t>) chars_ = str.chars_;
      else chars_ = __xtd_convert_to_string<value_type>(str.chars_);
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const basic_string<xtd::char8>& str) noexcept {
      if constexpr(std::is_same_v<xtd::char8, char_t>) chars_ = str.chars_;
      else chars_ = __xtd_convert_to_string<value_type>(str.chars_);
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const basic_string<xtd::wchar>& str) noexcept {
      if constexpr(std::is_same_v<xtd::wchar, char_t>) chars_ = str.chars_;
      else chars_ = __xtd_convert_to_string<value_type>(str.chars_);
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const std::basic_string<char>& str) noexcept { // Can't be explicit by design.
      if constexpr(std::is_same_v<char, char_t>) chars_ = str;
      else chars_ = __xtd_convert_to_string<value_type>(str);
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const std::basic_string<xtd::char16>& str) noexcept { // Can't be explicit by design.
      if constexpr(std::is_same_v<xtd::char16, char_t>) chars_ = str;
      else chars_ = __xtd_convert_to_string<value_type>(str);
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const std::basic_string<xtd::char32>& str) noexcept { // Can't be explicit by design.
      if constexpr(std::is_same_v<xtd::char32, char_t>) chars_ = str;
      else chars_ = __xtd_convert_to_string<value_type>(str);
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const std::basic_string<xtd::char8>& str) noexcept { // Can't be explicit by design.
      if constexpr(std::is_same_v<xtd::char8, char_t>) chars_ = str;
      else chars_ = __xtd_convert_to_string<value_type>(str);
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const std::basic_string<xtd::wchar>& str) noexcept { // Can't be explicit by design.
      if constexpr(std::is_same_v<xtd::wchar, char_t>) chars_ = str;
      else chars_ = __xtd_convert_to_string<value_type>(str);
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character.
    /// @param character The character copied.
    /// @param count The number of copies of character.
    basic_string(char character, xtd::usize count) : basic_string(std::basic_string<char>(count, character)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character.
    /// @param character The character copied.
    /// @param count The number of copies of character.
    basic_string(xtd::char16 character, xtd::usize count) : basic_string(std::basic_string<xtd::char16>(count, character)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character.
    /// @param character The character copied.
    /// @param count The number of copies of character.
    basic_string(xtd::char32 character, xtd::usize count) : basic_string(std::basic_string<xtd::char32>(count, character)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character.
    /// @param character The character copied.
    /// @param count The number of copies of character.
    basic_string(xtd::char8 character, xtd::usize count) : basic_string(std::basic_string<xtd::char8>(count, character)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character.
    /// @param character The character copied.
    /// @param count The number of copies of character.
    basic_string(xtd::wchar character, xtd::usize count) : basic_string(std::basic_string<xtd::wchar>(count, character)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const char* str) {  // Can't be explicit by design.
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<char, char_t>) chars_ = std::basic_string<char>(str);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<char>(str));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const xtd::char16* str) { // Can't be explicit by design.
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::char16, char_t>) chars_ = std::basic_string<xtd::char16>(str);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char16>(str));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const xtd::char32* str) { // Can't be explicit by design.
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::char32, char_t>) chars_ = std::basic_string<xtd::char32>(str);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char32>(str));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const xtd::char8* str) { // Can't be explicit by design.
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::char8, char_t>) chars_ = std::basic_string<xtd::char8>(str);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char8>(str));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const xtd::wchar* str) { // Can't be explicit by design.
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::wchar, char_t>) chars_ = std::basic_string<xtd::wchar>(str);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::wchar>(str));
    }
    
    /// @brief Initializes a new instance of xtd::basic_string with specified substring and count characters.
    /// @param count The number of substring characters to copy.
    basic_string(const char* str, xtd::usize count) {
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<char, char_t>) chars_ = std::basic_string<char>(str, count);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<char>(str, count));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring and count characters.
    /// @param count The number of substring characters to copy.
    basic_string(const xtd::char16* str, xtd::usize count) {
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::char16, char_t>) chars_ = std::basic_string<xtd::char16>(str, count);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char16>(str, count));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring and count characters.
    /// @param count The number of substring characters to copy.
    basic_string(const xtd::char32* str, xtd::usize count) {
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::char32, char_t>) chars_ = std::basic_string<xtd::char32>(str, count);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char32>(str, count));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring and count characters.
    /// @param count The number of substring characters to copy.
    basic_string(const xtd::char8* str, xtd::usize count) {
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::char8, char_t>) chars_ = std::basic_string<xtd::char8>(str, count);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char8>(str, count));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring and count characters.
    /// @param count The number of substring characters to copy.
    basic_string(const xtd::wchar* str, xtd::usize count) {
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::wchar, char_t>) chars_ = std::basic_string<xtd::wchar>(str, count);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::wchar>(str, count));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified first and last iterators of substring.
    /// @param first The first iterator of substring.
    /// @param last The first iterator of substring.
    template<typename input_iterator_t>
    basic_string(input_iterator_t first, input_iterator_t last) : chars_(first, last) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified std::basic_string_view.
    /// @param str The std::basic_string_view string.
    basic_string(const std::basic_string_view<char_t>& str) : chars_(str) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified initializer list.
    /// @param il The initializer list to fill.
    basic_string(std::initializer_list<char> il) : basic_string(std::basic_string<char>(il)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified initializer list.
    /// @param il The initializer list to fill.
    basic_string(std::initializer_list<xtd::char16> il) : basic_string(std::basic_string<xtd::char16>(il)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified initializer list.
    /// @param il The initializer list to fill.
    basic_string(std::initializer_list<xtd::char32> il) : basic_string(std::basic_string<xtd::char32>(il)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified initializer list.
    /// @param il The initializer list to fill.
    basic_string(std::initializer_list<xtd::char8> il) : basic_string(std::basic_string<xtd::char8>(il)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified initializer list.
    /// @param il The initializer list to fill.
    basic_string(std::initializer_list<xtd::wchar> il) : basic_string(std::basic_string<xtd::wchar>(il)) {}
    /// @}
    
    /// @name Public Properties
    
    /// @{
    /// @brief Returns a pointer to a null-terminated character array with data equivalent to those stored in the string.
    /// @return Pointer to the underlying character storage.
    /// @remarks The pointer is such that the range [`c_str()`, `c_str() + size()`] is valid and the values in it correspond to the values stored in the string with an additional null character after the last position.
    /// @remarks The pointer obtained from c_str() may be invalidated by:
    /// * Passing a non-const reference to the string to any standard library function, or
    /// * Calling non-const member functions on the string, excluding operator[], at(), front(), back(), begin(), rbegin(), end() and rend().
    /// @remarks Writing to the character array accessed through c_str() is undefined behavior.
    /// @remarks c_str() and data() perform the same function.
    [[nodiscard]] auto c_str() const noexcept -> const_pointer {return chars_.c_str();}
    
    /// @brief Returns a reference to the underlying base type.
    /// @return Reference to the underlying base type.
    [[nodiscard]] auto chars() const noexcept -> const base_type& {return chars_;}
    /// @brief Returns a reference to the underlying base type.
    /// @return Reference to the underlying base type.
    [[nodiscard]] auto chars() noexcept -> base_type& {return chars_;}
    
    /// @brief Gets the number of characters in the current xtd::basic_string object.
    /// @return The number of characters in the current string.
    /// @remarks The xtd::basic_string::length property returns the number of xtd::basic_string::value_type objects in this instance, not the number of Unicode characters. The reason is that a Unicode character might be represented by more than one xtd::basic_string::value_type.
    [[nodiscard]] virtual auto count() const noexcept -> size_type {return chars_.size();}
    
    /// @brief Returns a pointer to the underlying array serving as character storage. The pointer is such that the range [`data()`, `data() + size()`] is valid and the values in it correspond to the values stored in the string.
    /// @return A pointer to the underlying character storage.
    /// @remarks The pointer obtained from `data()` may be invalidated by:
    /// * Passing a non-const reference to the string to any standard library function, or
    /// * Calling non-const member functions on the string, excluding operator[](), at(), front(), back(), begin(), end(), rbegin(), rend().
    ///   1. Modifying the character array accessed through the const overload of data has undefined behavior.
    ///   2. Modifying the past-the-end null terminator stored at data() + size() to any value other than char_t() has undefined behavior.
    [[nodiscard]] auto data() const noexcept -> const_pointer {return chars_.data();}
    
    /// @brief Checks whether the container is empty.
    /// @return `true` if container is empty; otherwise `false`.
    [[nodiscard]] virtual auto empty() const noexcept -> bool {return length() == 0;}
    
    /// @brief Gets the number of characters in the current xtd::basic_string object.
    /// @return The number of characters in the current string.
    /// @remarks The xtd::basic_string::length property returns the number of xtd::basic_string::value_type objects in this instance, not the number of Unicode characters. The reason is that a Unicode character might be represented by more than one xtd::basic_string::value_type.
    [[nodiscard]] virtual auto length() const noexcept -> size_type {return chars_.size();}
    
    /// @brief Gets the number of characters in the current xtd::basic_string object.
    /// @return The number of characters in the current string.
    /// @remarks The xtd::basic_string::length property returns the number of xtd::basic_string::value_type objects in this instance, not the number of Unicode characters. The reason is that a Unicode character might be represented by more than one xtd::basic_string::value_type.
    [[nodiscard]] virtual auto size() const noexcept -> size_type {return chars_.size();}
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Compares this instance with a specified xtd::object and indicates whether this instance precedes, follows, or appears in the same position in the sort order as the specified xtd::object.
    /// @param value An object that evaluates to a xtd::basic_string.
    /// @return A 32-bit signed integer that indicates whether this instance precedes, follows, or appears in the same position in the sort order as the value parameter.
    /// | Value             | Condition                                                         |
    /// | ----------------- | ----------------------------------------------------------------- |
    /// | Less than zero    | This instance precedes `value`.                                   |
    /// | Zero              | This instance has the same position in the sort order as `value`. |
    /// | Greater than zero | This instance follows `value`.                                    |
    /// @exception xtd::argument_exception `value` is not a xtd::basic_string.
    [[nodiscard]] auto compare_to(const object& value) const -> xtd::int32 {
      if (!dynamic_cast<const basic_string*>(&value)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
      return compare_to(static_cast<const basic_string&>(value));
    }
    /// @brief Compares this instance with a specified xtd::basic_string object and indicates whether this instance precedes, follows, or appears in the same position in the sort order as the specified string.
    /// @param value The string to compare with this instance.
    /// @return A 32-bit signed integer that indicates whether this instance precedes, follows, or appears in the same position in the sort order as the `value` parameter.
    /// | Value             | Condition                                                         |
    /// | ----------------- | ----------------------------------------------------------------- |
    /// | Less than zero    | This instance precedes `value`.                                   |
    /// | Zero              | This instance has the same position in the sort order as `value`. |
    /// | Greater than zero | This instance follows `value`.                                    |
    [[nodiscard]] auto compare_to(const basic_string& value) const noexcept -> xtd::int32 override {return chars_.compare(value.chars_);}
    
    /// @brief Returns a value indicating whether a specified char occurs within this basic_string.
    /// @param value The char to seek.
    /// @return `true` if the value parameter occurs within this basic_string; otherwise, `false`.
    [[nodiscard]] virtual auto contains(value_type value) const noexcept -> bool {return chars_.find(value) != npos;}
    /// @brief Returns a value indicating whether a specified substring occurs within this basic_string.
    /// @param value The basic_string to seek.
    /// @return `true` if the value parameter occurs within this basic_string, or if value is the empty basic_string (""); otherwise, `false`.
    [[nodiscard]] virtual auto contains(const basic_string& value) const noexcept -> bool {return chars_.find(value) != npos;}
    
    /// @brief Determines whether this instance and a specified object, which must also be a xtd::basic_string object, have the same value.
    /// @param obj The basic_string to compare to this instance.
    /// @return `true` if `obj` is a xtd::basic_string and its value is the same as this instance; otherwise, `false`.
    [[nodiscard]] auto equals(const object& obj) const noexcept -> bool override {return dynamic_cast<const basic_string*>(&obj) && equals(static_cast<const basic_string&>(obj));}
    /// @brief Determines whether this instance and another specified xtd::basic_string object have the same value.
    /// @param value The basic_string to compare to this instance.
    /// @return `true` if the `value` of the value parameter is the same as the value of this instance; otherwise, `false`.
    /// @remarks This method performs an ordinal (case-sensitive) comparison.
    [[nodiscard]] auto equals(const basic_string& value) const noexcept -> bool override {return equals(value, false);}
    /// @brief Determines whether this instance and another specified xtd::basic_string object have the same value, ignoring or honoring their case.
    /// @param value The basic_string to compare to this instance.
    /// @param ignore_case `true` to ignore case when comparing this instance and value; otherwise, `false`
    /// @return `true` if the `value` of the value parameter is the same as the value of this instance; otherwise, `false`.
    /// @remarks This method performs an ordinal comparison.
    [[nodiscard]] auto equals(const basic_string& value, bool ignore_case) const noexcept -> bool {
      if (ignore_case) return to_upper().chars_ == value.to_upper().chars_;
      return chars_ == value.chars_;
    }
    
    /// @brief Determines whether the end of this basic_string matches the specified character.
    /// @param value The char_t to compare to the substring at the end of this instance.
    /// @return `true` if value matches the end of this instance; otherwise, `false`.
    [[nodiscard]] auto ends_with(value_type value) const noexcept -> bool {return ends_with(value, false);}
    /// @brief Determines whether the end of this basic_string matches the specified character, ignoring or honoring their case.
    /// @param value The char_t to compare to the substring at the end of this instance.
    /// @param ignore_case `true` to ignore case during the comparison; otherwise, `false`.
    /// @return `true` if value matches the end of this instance; otherwise, `false`.
    [[nodiscard]] auto ends_with(value_type value, bool ignore_case) const noexcept -> bool {
      if (ignore_case) return to_lower().chars_.rfind(static_cast<value_type>(tolower(value))) == length() - 1;
      return chars_.rfind(value) == length() - 1;
    }
    /// @brief Determines whether the end of this basic_string matches the specified basic_string.
    /// @param value The basic_string to compare to the substring at the end of this instance.
    /// @return `true` if value matches the end of this instance; otherwise, `false`.
    [[nodiscard]] auto ends_with(const basic_string& value) const noexcept -> bool {return ends_with(value, xtd::string_comparison::ordinal);}
    /// @brief Determines whether the end of this basic_string instance matches the specified basic_string, ignoring or honoring their case.
    /// @param value The string to compare to the substring at the end of this instance.
    /// @param ignore_case `true` to ignore case during the comparison; otherwise, `false`.
    /// @return bool `true` if value matches the end of the specified basic_string; otherwise, `false`.
    [[nodiscard]] auto ends_with(const basic_string& value, bool ignore_case) const noexcept -> bool {return ends_with(value, ignore_case ? xtd::string_comparison::ordinal_ignore_case : xtd::string_comparison::ordinal);}
    /// @brief Determines whether the end of this basic_string matches the specified basic_string when compared using the specified comparison option.
    /// @param value The string to compare to the substring at the end of this instance.
    /// @param comparison_type One of the enumeration values that determines how this basic_string and value are compared.
    /// @return bool `true` if value matches the end of the specified basic_string; otherwise, `false`.
    [[nodiscard]] auto ends_with(const basic_string& value, xtd::string_comparison comparison_type) const noexcept -> bool {
      if (comparison_type == xtd::string_comparison::ordinal_ignore_case) return to_lower().chars_.rfind(value.to_lower()) + value.to_lower().length() == length();
      return chars_.rfind(value) + value.length() == length();
    }
       
    /// @brief Returns the underlying base type.
    /// @return The underlying base type.
    [[nodiscard]] virtual auto get_base_type() const noexcept -> const base_type& {return chars_;}
    
    /// @brief Returns the hash code for this basic_string.
    /// @return A hash code.
    [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override {return xtd::hash_code::combine(chars_);}
    
    [[nodiscard]] auto get_enumerator() const noexcept -> enumerator_type override {
      struct basic_string_enumerator : public xtd::collections::generic::ienumerator<value_type> {
        explicit basic_string_enumerator(const basic_string& chars) : chars_(chars) {}
        [[nodiscard]] const value_type& current() const override {
          if (index_ >= chars_.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          return chars_[index_];
        }
        bool move_next() override {return ++index_ < chars_.length();}
        void reset() override {index_ = basic_string::npos;}
        
      private:
        const basic_string& chars_;
        size_type index_ = basic_string::npos;
      };
      return {new_ptr<basic_string_enumerator>(self_)};
    }
    
    /// @brief Reports the index of the first occurrence of the specified basic_string in this basic_string.
    /// @param value An unicode character to seek
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    [[nodiscard]] auto index_of(const basic_string& value) const noexcept -> xtd::usize {return index_of(value, 0, length());}
    /// @brief Reports the index of the first occurrence of the specified character in this basic_string. The search starts at a specified character position.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    [[nodiscard]] auto index_of(const basic_string& value, xtd::usize start_index) const -> xtd::usize {return index_of(value, start_index, length() - start_index);}
    /// @brief Reports the index of the first occurrence of the specified character in this basic_string. The search starts at a specified character position and examines a specified number of character positions.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    /// @exception xtd::index_out_of_range_exception start_index + count are greater than the length of this instance.
    [[nodiscard]] auto index_of(const basic_string& value, xtd::usize start_index, xtd::usize count) const -> xtd::usize {
      if (start_index > length() || start_index + count > length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      auto result = chars_.find(value, start_index);
      return result > start_index + count ? npos : result;
    }
    /// @brief Reports the index of the first occurrence of the specified character in this basic_string.
    /// @param value An unicode character to seek
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    [[nodiscard]] auto index_of(value_type value) const noexcept -> xtd::usize {return index_of(value, 0, length());}
    /// @brief Reports the index of the first occurrence of the specified character in this basic_string. The search starts at a specified character position.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    [[nodiscard]] auto index_of(value_type value, xtd::usize start_index) const -> xtd::usize {return index_of(value, start_index, length() - start_index);}
    /// @brief Reports the index of the first occurrence of the specified character in this basic_string. The search starts at a specified character position and examines a specified number of character positions.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    /// @exception xtd::index_out_of_range_exception start_index + count are greater than the length of this instance.
    [[nodiscard]] auto index_of(value_type value, xtd::usize start_index, xtd::usize count) const -> xtd::usize {
      if (start_index > length() || start_index + count > length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      auto result = chars_.find(value, start_index);
      return result > start_index + count ? npos : result;
    }
    
    /// @brief Reports the index of the first occurrence in this instance of any character in a specified array of characters.
    /// @param values An unicode character array containing one or more characters to seek
    /// @return The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<char_t>::npos if no character in values was found.
    [[nodiscard]] auto index_of_any(const xtd::array<value_type>& values) const noexcept -> xtd::usize;
    /// @brief Reports the index of the first occurrence in this instance of any character in a specified array of characters. The search starts at a specified character position.
    /// @param values An unicode character array containing one or more characters to seek
    /// @param start_index The search starting position
    /// @return The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<char_t>::npos if no character in values was found.
    /// @exception xtd::index_out_of_range_exception start_index + count are greater than the length of this instance.
    [[nodiscard]] auto index_of_any(const xtd::array<value_type>& values, xtd::usize start_index) const -> xtd::usize;
    /// @brief Reports the index of the first occurrence in this instance of any character in a specified array of characters. The search starts at a specified character position.
    /// @param values An unicode character array containing one or more characters to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine.
    /// @return The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<char_t>::npos if no character in values was found.
    /// @exception xtd::index_out_of_range_exception start_index + count are greater than the length of this instance.
    [[nodiscard]] auto index_of_any(const xtd::array<value_type>& values, xtd::usize start_index, xtd::usize count) const -> xtd::usize;
    /// @cond
    [[nodiscard]] auto index_of_any(const std::initializer_list<value_type>& values) const noexcept -> xtd::usize;
    [[nodiscard]] auto index_of_any(const std::initializer_list<value_type>& values, xtd::usize start_index) const -> xtd::usize;
    [[nodiscard]] auto index_of_any(const std::initializer_list<value_type>& values, xtd::usize start_index, xtd::usize count) const -> xtd::usize;
    /// @endcond
    
    /// @brief Inserts a specified instance of basic_string at a specified index position in this instance.
    /// @param start_index The index position of the insertion.
    /// @param value The basic_string to insert.
    /// @return A new basic_string equivalent to this instance but with value inserted at position start_index.
    /// @remarks If start_index is equal to the length of this instance, value is appended to the end of this instance.
    /// @remarks For example, the return value of "abc".Insert(2, "XYZ") is "abXYZc".
    auto insert(xtd::usize start_index, const basic_string& value) const -> basic_string {
      if (start_index > length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      auto result = self_;
      result.chars_.insert(start_index, value);
      return result;
    }
    
    /// @brief Reports the index of the last occurrence of the specified basic_string in this basic_string.
    /// @param value An unicode character to seek
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    [[nodiscard]] auto last_index_of(const basic_string& value) const noexcept -> xtd::usize {return last_index_of(value, 0, length());}
    /// @brief Reports the index of the last occurrence of the specified character in this basic_string. The search starts at a specified character position.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    /// @exception xtd::index_out_of_range_exception start_index + count are greater than the length of this instance.
    [[nodiscard]] auto last_index_of(const basic_string& value, xtd::usize start_index) const -> xtd::usize {return last_index_of(value, start_index, length() - start_index);}
    /// @brief Reports the index of the last occurrence of the specified character in this basic_string. The search starts at a specified character position and examines a specified number of character positions.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    /// @exception xtd::index_out_of_range_exception start_index + count are greater than the length of this instance.
    [[nodiscard]] auto last_index_of(const basic_string& value, xtd::usize start_index, xtd::usize count) const -> xtd::usize {
      if (start_index > length() || start_index + count > length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      auto result = chars_.rfind(value, start_index + count - value.length());
      return result < start_index ? npos : result;
    }
    /// @brief Reports the index of the last occurrence of the specified character in this tring.
    /// @param value An unicode character to seek
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    [[nodiscard]] auto last_index_of(value_type value) const noexcept -> xtd::usize {return last_index_of(value, 0, length());}
    /// @brief Reports the index of the last occurrence of the specified character in this basic_string. The search starts at a specified character position.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    /// @exception xtd::index_out_of_range_exception start_index + count are greater than the length of this instance.
    [[nodiscard]] auto last_index_of(value_type value, xtd::usize start_index) const -> xtd::usize {return last_index_of(value, start_index, length() - start_index);}
    /// @brief Reports the index of the last occurrence of the specified character in this basic_string. The search starts at a specified character position and examines a specified number of character positions.
    /// @param str A basic_string to find last index of.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    /// @exception xtd::index_out_of_range_exception start_index + count are greater than the length of this instance.
    [[nodiscard]] auto last_index_of(value_type value, xtd::usize start_index, xtd::usize count) const -> xtd::usize {
      if (start_index > length() || start_index + count > length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      auto result = chars_.rfind(value, start_index + count - 1);
      return result < start_index ? npos : result;
    }
    
    /// @brief Reports the index of the last occurrence in this instance of any character in a specified array of characters.
    /// @param values An unicode character array containing one or more characters to seek
    /// @return The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<char_t>::npos if no character in values was found.
    [[nodiscard]] auto last_index_of_any(const xtd::array<value_type>& values) const noexcept -> xtd::usize;
    /// @brief Reports the index of the last occurrence in this instance of any character in a specified array of characters. The search starts at a specified character position.
    /// @param values An unicode character array containing one or more characters to seek
    /// @param start_index The search starting position
    /// @return The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<char_t>::npos if no character in values was found.
    [[nodiscard]] auto last_index_of_any(const xtd::array<value_type>& values, xtd::usize start_index) const -> xtd::usize;
    /// @brief Reports the index of the last occurrence in this instance of any character in a specified array of characters. The search starts at a specified character position.
    /// @param values An unicode character array containing one or more characters to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine.
    /// @return The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<char_t>::npos if no character in values was found.
    [[nodiscard]] auto last_index_of_any(const xtd::array<value_type>& values, xtd::usize start_index, xtd::usize count) const -> xtd::usize;
    /// @cond
    [[nodiscard]] auto last_index_of_any(const std::initializer_list<value_type>& values) const noexcept -> xtd::usize;
    [[nodiscard]] auto last_index_of_any(const std::initializer_list<value_type>& values, xtd::usize start_index) const -> xtd::usize;
    [[nodiscard]] auto last_index_of_any(const std::initializer_list<value_type>& values, xtd::usize start_index, xtd::usize count) const -> xtd::usize;
    /// @endcond
    
    /// @brief Right-aligns the characters in this basic_string, padding with spaces on the left for a specified total length.
    /// @param total_width The number of characters in the resulting basic_string, equal to the number of original characters plus any additional padding characters.
    /// @return A new basic_string that is equivalent to the specified basic_string, but right-aligned and padded on the left with as many spaces as needed to create a length of total_width. Or, if total_width is less than the length of the specified basic_string, a new basic_string object that is identical to the specified basic_string.
    /// @remarks An unicode space is defined as hexadecimal 0x20.
    /// @remarks The pad_left(const std::basic_string<char_t>&, int) method pads the beginning of the returned basic_string. This means that, when used with right-to-left languages, it pads the right portion of the basic_string..
    [[nodiscard]] auto pad_left(xtd::usize total_width) const noexcept -> basic_string {return pad_left(total_width, ' ');}
    /// @brief Right-aligns the characters in this basic_string, padding with spaces on the left for a specified total length.
    /// @param total_width The number of characters in the resulting basic_string, equal to the number of original characters plus any additional padding characters.
    /// @param paddingChar An unicode padding character.
    /// @return A new basic_string that is equivalent to the specified basic_string, but right-aligned and padded on the left with as many spaces as needed to create a length of total_width. Or, if total_width is less than the length of the specified basic_string, a new basic_string object that is identical the specified basic_string.
    /// @remarks An unicode space is defined as hexadecimal 0x20.
    /// @remarks The pad_left(const std::basic_string<char_t>&, int) method pads the beginning of the returned basic_string. This means that, when used with right-to-left languages, it pads the right portion of the basic_string..
    [[nodiscard]] auto pad_left(xtd::usize total_width, char32 padding_char) const noexcept -> basic_string {return total_width < length() ? self_ : basic_string(padding_char, total_width - length()) + self_;}
    
    /// @brief Left-aligns the characters in this basic_string, padding with spaces on the right for a specified total length.
    /// @param totalWidth The number of characters in the resulting basic_string, equal to the number of original characters plus any additional padding characters.
    /// @return A new basic_string that is equivalent to the specified basic_string, but left-aligned and padded on the right with as many spaces as needed to create a length of totalWidth. Or, if totalWidth is less than the length of the specified basic_string, a new basic_string object that is identical to the specified basic_string.
    /// @remarks An unicode space is defined as hexadecimal 0x20.
    /// @remarks The PadRight(const std::basic_string<char_t>&, int) method pads the end of the returned basic_string. This means that, when used with right-to-left languages, it pads the left portion of the basic_string..
    [[nodiscard]] auto pad_right(xtd::usize total_width) const noexcept -> basic_string {return pad_right(total_width, ' ');}
    /// @brief Left-aligns the characters in this basic_string, padding with spaces on the right for a specified total length.
    /// @param totalWidth The number of characters in the resulting basic_string, equal to the number of original characters plus any additional padding characters.
    /// @param paddingChar An unicode padding character.
    /// @return A new basic_string that is equivalent to the specified basic_string, but left-aligned and padded on the tight with as many spaces as needed to create a length of totalWidth. Or, if totalWidth is less than the length of the specified basic_string, a new basic_string object that is identical to the specified basic_string.
    /// @remarks An unicode space is defined as hexadecimal 0x20.
    /// @remarks The xtd::basic_string::pad_right method pads the end of the returned basic_string. This means that, when used with right-to-left languages, it pads the left portion of the basic_string..
    [[nodiscard]] auto pad_right(xtd::usize total_width, char32 padding_char) const noexcept -> basic_string {return total_width < length() ? self_ : self_ + basic_string(padding_char, total_width - length());}
    
    /// @brief Allows insertion and extraction of quoted strings, such as the ones found in [CSV](https://en.wikipedia.org/wiki/Comma-separated_values) or [XML](https://en.wikipedia.org/wiki/XML).
    /// @return A new quoted basic_string.
    /// @remarks the delimiter is set to @verbatim " @endverbatim by default and the escape is set to `\` by  default.
    /// @remarks for more information see [std::quoted](https://en.cppreference.com/w/cpp/io/manip/quoted).
    [[nodiscard]] auto quoted() const -> basic_string {return quoted('"', '\\');}
    /// @brief Allows insertion and extraction of quoted strings, such as the ones found in [CSV](https://en.wikipedia.org/wiki/Comma-separated_values) or [XML](https://en.wikipedia.org/wiki/XML) ith specified delimiter.
    /// @param delimiter The character to use as the delimiter, defaults to `"`.
    /// @return A new quoted basic_string.
    /// @remarks for more information see [std::quoted](https://en.cppreference.com/w/cpp/io/manip/quoted).
    [[nodiscard]] auto quoted(value_type delimiter) const -> basic_string {return quoted(delimiter, '\\');}
    /// @brief Allows insertion and extraction of quoted strings, such as the ones found in [CSV](https://en.wikipedia.org/wiki/Comma-separated_values) or [XML](https://en.wikipedia.org/wiki/XML) ith specified delimiter and escape.
    /// @param delimiter The character to use as the delimiter, defaults to `"`.
    /// @param escape The character to use as the escape character, defaults to `\`.
    /// @return A new quoted basic_string.
    /// @remarks for more information see [std::quoted](https://en.cppreference.com/w/cpp/io/manip/quoted).
    [[nodiscard]] auto quoted(value_type delimiter, value_type escape) const -> basic_string {
      std::wstringstream ss;
      if constexpr(std::is_same_v<xtd::wchar, value_type>) ss << std::quoted(chars_, delimiter, escape);
      else ss << std::quoted(__xtd_convert_to_string<xtd::wchar>(chars_), static_cast<xtd::wchar>(delimiter), static_cast<xtd::wchar>(escape));
      return ss.str();
    }
    
    /// @brief Deletes all the characters from this basic_string beginning at a specified position and continuing through the last position.
    /// @param start_index The position to begin deleting characters.
    /// @return A new basic_string object that is equivalent to this basic_string less the removed characters.
    [[nodiscard]] auto remove(xtd::usize start_index) const -> basic_string {return remove(start_index, length() - start_index);}
    /// @brief Deletes all the characters from this basic_string beginning at a specified position and continuing through the last position.
    /// @param start_index The position to begin deleting characters.
    /// @param count The number of characters to delete.
    /// @return A new basic_string object that is equivalent to this basic_string less the removed characters.
    [[nodiscard]] auto remove(xtd::usize start_index, xtd::usize count) const -> basic_string {
      if (start_index > length() || start_index + count > length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      auto result = self_;
      result.chars_.erase(start_index, count);
      return result;
    }
    
    /// @brief Replaces all occurrences of a specified char_t in this basic_string with another specified char_t.
    /// @param old_char A char_t to be replaced.
    /// @param new_char A char_t to replace all occurrences of old_char.
    /// @return A new basic_string equivalent to the specified basic_string but with all instances of old_char replaced with new_char.
    [[nodiscard]] auto replace(value_type old_char, value_type new_char) const noexcept -> basic_string {return replace(string(old_char, 1), string(new_char, 1));}
    /// @brief Replaces all occurrences of a specified basic_string in this basic_string with another specified basic_string.
    /// @param old_string A basic_string to be replaced.
    /// @param new_string A basic_string to replace all occurrences of old_string.
    /// @return A new basic_string equivalent to the specified basic_string but with all instances of old_string replaced with new_string.
    /// @remarks If new_string is empty, all occurrences of old_string are removed
    [[nodiscard]] auto replace(const basic_string& old_string, const basic_string& new_string) const noexcept -> basic_string {
      auto result = self_;
      auto old_size = old_string.length();
      auto new_size = new_string.length();
      auto index = xtd::usize {0};
      while (true) {
        index = result.chars_.find(old_string, index);
        if (index == npos) break;
        if (old_size == new_size) result.chars_.replace(index, old_size, new_string);
        else {
          result.chars_.erase(index, old_string.length());
          result.chars_.insert(index, new_string);
        }
        index += new_string.length();
      }
      return result;
    }
    
    /// @brief Splits this basic_string into substrings that are based on the default white-space characters. White-space characters are defined by the c++ standard and return `true` if they are passed to the xtd::char_object::isspace() or std::iswspace() method.
    /// @return An array whose elements contain the substrings in this basic_string that are delimited by one or more characters in white-space separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    [[nodiscard]] auto split() const noexcept -> xtd::array<basic_string>;
    /// @brief Splits this basic_string into substrings that are based on the characters in an array.
    /// @param separator A character that delimits the substrings in this basic_string.
    /// @return An array whose elements contain the substrings in this basic_string that are delimited by one or more characters in separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    [[nodiscard]] auto split(value_type separator) const noexcept -> xtd::array<basic_string>;
    /// @brief Splits this basic_string into substrings based on the characters in an array. You can specify whether the substrings include empty array elements.
    /// @param separator A character that delimits the substrings in this basic_string
    /// @param options xtd::string_split_options::remove_empty_entries to omit empty array elements from the array returned; or None to include empty array elements in the array returned.
    /// @return An array whose elements contain the substrings in this basic_string that are delimited by one or more characters in separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, the returned array consists of a single element that contains the specified basic_string.
    /// @remarks If the options parameter is remove_empty_entries and the length of the specified basic_string is zero, the method returns an empty array.
    /// @remarks Each element of separator defines a separate delimiter that consists of a single character. If the options argument is none, and two delimiters are adjacent or a delimiter is found at the beginning or end of the specified basic_string, the corresponding array element contains empty basic_string. For example, if separator includes two elements, "-" and "_", the value of the basic_string instance is "-_aa-_", and the value of the options argument is None, the method returns a basic_string array with the following five elements:
    ///   1. empty basic_string, which represents the empty basic_string that precedes the "-" character at index 0.
    ///   2. empty basic_string, which represents the empty basic_string between the "-" character at index 0 and the "_" character at index 1.
    ///   3. "aa",
    ///   4. empty basic_string, which represents the empty basic_string that follows the "_" character at index 4.
    ///   5. empty basic_string, which represents the empty basic_string that follows the "-" character at index 5.
    /// @remarks If the separator parameter contains no characters, white-space characters are assumed to be the delimiters. White-space characters are defined by the c++ standard and return `true` if they are passed to the xtd::char_object::isspace() or std::iswspace() method.
    /// @remarks If count is greater than the number of substrings, the available substrings are returned.
    [[nodiscard]] auto split(value_type separator, xtd::string_split_options options) const noexcept -> xtd::array<basic_string>;
    /// @brief Splits this basic_string into a maximum number of substrings based on the characters in an array. You also specify the maximum number of substrings to return.
    /// @param separator A character array that delimits the substrings in this basic_string, an empty array that contains no delimiters.
    /// @param count The maximum number of substrings to return.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    /// @remarks If the separator parameter contains no characters, white-space characters are assumed to be the delimiters. White-space characters are defined by the Unicode standard and return `true` if they are passed to the char_t.IsWhiteSpace method.
    /// @remarks Each element of separator defines a separate delimiter character. If two delimiters are adjacent, or a delimiter is found at the beginning or end of the specified basic_string, the corresponding array element contains empty basic_string.
    /// @remarks If there are more than count substrings in the specified basic_string, the first count minus 1 substrings are returned in the first count minus 1 elements of the return value, and the remaining characters in the specified basic_string are returned in the last element of the return value.
    [[nodiscard]] auto split(value_type separator, xtd::usize count) const noexcept -> xtd::array<basic_string>;
    /// @brief Splits this basic_string into a maximum number of substrings based on the characters in an array.
    /// @param separators A character array that delimits the substrings in this basic_string, an empty array that contains no delimiters.
    /// @param count The maximum number of substrings to return.
    /// @param options xtd::string_split_options::remove_empty_entries to omit empty array elements from the array returned; or None to include empty array elements in the array returned.
    /// @return An array whose elements contain the substrings in this basic_string that are delimited by one or more characters in separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    /// @remarks If the count parameter is zero, or the options parameter is remove_empty_entries and the length of the specified basic_string is zero, an empty array is returned.
    /// @remarks Each element of separator defines a separate delimiter character. If the options parameter is None, and two delimiters are adjacent or a delimiter is found at the beginning or end of the specified basic_string, the corresponding array element contains an empty basic_string.
    /// @remarks If there are more than count substrings in the specified basic_string, the first count minus 1 substrings are returned in the first count minus 1 elements of the return value, and the remaining characters in the specified basic_string are returned in the last element of the return value.
    /// @remarks If count is greater than the number of substrings, the available substrings are returned.
    [[nodiscard]] auto split(value_type separator, xtd::usize count, xtd::string_split_options options) const noexcept -> xtd::array<basic_string>;
    /// @brief Splits this basic_string into substrings that are based on the characters in an array.
    /// @param separators A character array that delimits the substrings in this basic_string, an empty array that contains no delimiters.
    /// @return An array whose elements contain the substrings in this basic_string that are delimited by one or more characters in separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    [[nodiscard]] auto split(const xtd::array<value_type>& separators) const noexcept -> xtd::array<basic_string>;
    /// @brief Splits this basic_string into substrings based on the characters in an array. You can specify whether the substrings include empty array elements.
    /// @param separators A character array that delimits the substrings in this basic_string, an empty array that contains no delimiters.
    /// @param options xtd::string_split_options::remove_empty_entries to omit empty array elements from the array returned; or None to include empty array elements in the array returned.
    /// @return An array whose elements contain the substrings in this basic_string that are delimited by one or more characters in separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, the returned array consists of a single element that contains the specified basic_string.
    /// @remarks If the options parameter is remove_empty_entries and the length of the specified basic_string is zero, the method returns an empty array.
    /// @remarks Each element of separator defines a separate delimiter that consists of a single character. If the options argument is none, and two delimiters are adjacent or a delimiter is found at the beginning or end of the specified basic_string, the corresponding array element contains empty basic_string. For example, if separator includes two elements, "-" and "_", the value of the basic_string instance is "-_aa-_", and the value of the options argument is None, the method returns a basic_string array with the following five elements:
    ///   1. empty basic_string, which represents the empty basic_string that precedes the "-" character at index 0.
    ///   2. empty basic_string, which represents the empty basic_string between the "-" character at index 0 and the "_" character at index 1.
    ///   3. "aa",
    ///   4. empty basic_string, which represents the empty basic_string that follows the "_" character at index 4.
    ///   5. empty basic_string, which represents the empty basic_string that follows the "-" character at index 5.
    /// @remarks If the separator parameter contains no characters, white-space characters are assumed to be the delimiters. White-space characters are defined by the c++ standard and return `true` if they are passed to the xtd::char_object::isspace() or std::iswspace() method.
    /// @remarks If count is greater than the number of substrings, the available substrings are returned.
    [[nodiscard]] auto split(const xtd::array<value_type>& separators, xtd::string_split_options options) const noexcept -> xtd::array<basic_string>;
    /// @brief Splits this basic_string into a maximum number of substrings based on the characters in an array. You also specify the maximum number of substrings to return.
    /// @param separators A character array that delimits the substrings in this basic_string, an empty array that contains no delimiters.
    /// @param count The maximum number of substrings to return.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    /// @remarks If the separator parameter contains no characters, white-space characters are assumed to be the delimiters. White-space characters are defined by the Unicode standard and return `true` if they are passed to the char_t.IsWhiteSpace method.
    /// @remarks Each element of separator defines a separate delimiter character. If two delimiters are adjacent, or a delimiter is found at the beginning or end of the specified basic_string, the corresponding array element contains empty basic_string.
    /// @remarks If there are more than count substrings in the specified basic_string, the first count minus 1 substrings are returned in the first count minus 1 elements of the return value, and the remaining characters in the specified basic_string are returned in the last element of the return value.
    [[nodiscard]] auto split(const xtd::array<value_type>& separators, xtd::usize count) const noexcept -> xtd::array<basic_string>;
    /// @brief Splits this basic_string into a maximum number of substrings based on the characters in an array.
    /// @param separators A character array that delimits the substrings in this basic_string, an empty array that contains no delimiters.
    /// @param count The maximum number of substrings to return.
    /// @param options xtd::string_split_options::remove_empty_entries to omit empty array elements from the array returned; or None to include empty array elements in the array returned.
    /// @return An array whose elements contain the substrings in this basic_string that are delimited by one or more characters in separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    /// @remarks If the count parameter is zero, or the options parameter is remove_empty_entries and the length of the specified basic_string is zero, an empty array is returned.
    /// @remarks Each element of separator defines a separate delimiter character. If the options parameter is None, and two delimiters are adjacent or a delimiter is found at the beginning or end of the specified basic_string, the corresponding array element contains an empty basic_string.
    /// @remarks If there are more than count substrings in the specified basic_string, the first count minus 1 substrings are returned in the first count minus 1 elements of the return value, and the remaining characters in the specified basic_string are returned in the last element of the return value.
    /// @remarks If count is greater than the number of substrings, the available substrings are returned.
    [[nodiscard]] auto split(const xtd::array<value_type>& separators, xtd::usize count, xtd::string_split_options options) const noexcept -> xtd::array<basic_string>;
    
    /// @brief Determines whether the beginning of this instance of xtd::basic_string matches a specified xtd::basic_string.
    /// @param value A xtd::basic_string to compare to.
    /// @return bool `true` if value matches the beginning of the specified basic_string; otherwise, `false`.
    /// @remarks This method compares value to the substring at the beginning of the specified basic_string that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the beginning of the specified basic_string.
    [[nodiscard]] bool starts_with(value_type value) const noexcept {return starts_with(value, false);}
    /// @brief Determines whether the beginning of this instance of xtd::basic_string matches a specified xtd::basic_string, ignoring or honoring their case.
    /// @param value A xtd::basic_string to compare to.
    /// @param ignore_case `true` to ignore case when comparing the specified basic_string and value; otherwise, `false`
    /// @return bool `true` if value matches the beginning of the specified basic_string; otherwise, `false`.
    /// @remarks This method compares value to the substring at the beginning of the specified basic_string that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the beginning of the specified basic_string.
    [[nodiscard]] bool starts_with(value_type value, bool ignore_case) const noexcept {
      if (ignore_case) return to_lower().chars_.find(static_cast<value_type>(tolower(value))) == 0;
      return chars_.find(value) == 0;
    }
    /// @brief Determines whether the beginning of this instance of xtd::basic_string matches a specified xtd::basic_string.
    /// @param value A xtd::basic_string to compare to.
    /// @return bool `true` if value matches the beginning of the specified basic_string; otherwise, `false`.
    /// @remarks This method compares value to the substring at the beginning of the specified basic_string that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the beginning of the specified basic_string.
    [[nodiscard]] auto starts_with(const basic_string& value) const noexcept -> bool {return starts_with(value, string_comparison::ordinal);}
    /// @brief Determines whether the beginning of this instance of xtd::basic_string matches a specified xtd::basic_string, ignoring or honoring their case.
    /// @param value A xtd::basic_string to compare to.
    /// @param ignore_case `true` to ignore case when comparing the specified basic_string and value; otherwise, `false`
    /// @return bool `true` if value matches the beginning of the specified basic_string; otherwise, `false`.
    /// @remarks This method compares value to the substring at the beginning of the specified basic_string that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the beginning of the specified basic_string.
    [[nodiscard]] auto starts_with(const basic_string& value, bool ignore_case) const noexcept -> bool {return starts_with(value, ignore_case ? string_comparison::ordinal_ignore_case : string_comparison::ordinal);}
    /// @brief Determines whether the end of this basic_string matches the specified basic_string when compared using the specified comparison option.
    /// @param value The string to compare to the substring at the end of this instance.
    /// @param comparison_type One of the enumeration values that determines how this basic_string and value are compared.
    /// @return bool `true` if value matches the end of the specified basic_string; otherwise, `false`.
    [[nodiscard]] auto starts_with(const basic_string& value, xtd::string_comparison comparison_type) const noexcept -> bool {
      if (comparison_type == xtd::string_comparison::ordinal_ignore_case) return to_lower().chars_.find(value.to_lower()) == 0;
      return chars_.find(value) == 0;
    }
    
    /// @brief Retrieves a substring from this instance. The substring starts at a specified character position and has a specified length.
    /// @param str basic_string to substring.
    /// @param start_index The zero-based starting character position of a substring in this instance.
    /// @return A basic_string equivalent to the substring of length length that begins at start_index in this instance, or Empty if start_index is equal to the length of this instance and length is zero.
    /// @exception xtd::argument_out_of_range_exception `start_index` is greater than the length() of this instance.
    [[nodiscard]] auto substring(xtd::usize start_index) const -> basic_string {
      if (start_index > length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      return chars_.substr(start_index);
    }
    /// @brief Retrieves a substring from this instance. The substring starts at a specified character position and has a specified length.
    /// @param start_index The zero-based starting character position of a substring in this instance.
    /// @param length The number of characters in the substring.
    /// @return A basic_string equivalent to the substring of length length that begins at start_index in this instance, or Empty if start_index is equal to the length of this instance and length is zero.
    /// @exception xtd::argument_out_of_range_exception `start_index` plus `length` is greater than the length() of this instance.
    [[nodiscard]] auto substring(xtd::usize start_index, xtd::usize length) const -> basic_string {
      if (start_index > self_.length() || start_index + length > self_.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      return chars_.substr(start_index, length);
    }
    
    /// @brief Copies the characters in this instance to a Unicode character array.
    /// @return A character array whose elements are the individual characters of this instance. If this instance is an empty xtd::basic_string, the returned array is empty and has a zero length.
    [[nodiscard]] auto to_array() const noexcept -> xtd::array<value_type>;
    /// @brief Copies the characters in this instance to a Unicode character array starting at specified index.
    /// @param start_index The starting position of basic_string to convert.
    /// @return A character array whose elements are the individual characters of this instance. If this instance is an empty xtd::basic_string, the returned array is empty and has a zero length.
    [[nodiscard]] auto to_array(xtd::usize start_index) const -> xtd::array<value_type>;
    /// @brief Copies the characters in this instance to a Unicode character array starting at specified index with specified length.
    /// @param start_index The starting position of basic_string to convert.
    /// @param length The length of the basic_string to convert
    /// @return A character array whose elements are the individual characters of this instance. If this instance is an empty xtd::basic_string, the returned array is empty and has a zero length.
    [[nodiscard]] auto to_array(xtd::usize start_index, xtd::usize length) const -> xtd::array<value_type>;
    
    /// @brief Copies the characters in this instance to a Unicode character array.
    /// @return A character array whose elements are the individual characters of this instance. If this instance is an empty xtd::basic_string, the returned array is empty and has a zero length.
    [[nodiscard]] auto to_char_array() const noexcept -> xtd::array<value_type>;
    /// @brief Copies the characters in this instance to a Unicode character array starting at specified index with specified length.
    /// @param start_index The starting position of basic_string to convert.
    /// @param length The length of the basic_string to convert
    /// @return A character array whose elements are the individual characters of this instance. If this instance is an empty xtd::basic_string, the returned array is empty and has a zero length.
    [[nodiscard]] auto to_char_array(xtd::usize start_index, xtd::usize length) const -> xtd::array<value_type>;
    
    /// @brief Returns a copy of the current xtd::basic_string converted to lowercase.
    /// @return A string in lowercase.
    [[nodiscard]] auto to_lower() const noexcept -> basic_string {
      auto result = basic_string::empty_string;
      std::for_each(chars_.begin(), chars_.end(), [&](auto c) {result += static_cast<value_type>(std::tolower(c));});
      return result;
    }
    
    /// @brief Converts the value of this instance to a xtd::basic_string <char>.
    /// @return The current string.
    /// @todo Uncomment the folllowing line and remove the next..
    [[nodiscard]] auto to_string() const noexcept -> basic_string<char> override {
      if constexpr(std::is_same_v<char, char_t>) return chars_;
      else return __xtd_convert_to_string<char>(chars_);
    }
    
    /// @brief Converts the current basic_string to title case (except for words that are entirely in uppercase, which are considered to be acronyms).
    /// @return A new basic_string in title case.
    [[nodiscard]] auto to_title_case() const noexcept -> basic_string;
    
    /// @brief Converts the value of this instance to a xtd::basic_string <xtd::char16>.
    /// @return The current string.
    [[nodiscard]] auto to_u16string() const noexcept -> basic_string<xtd::char16> {
      if constexpr(std::is_same_v<xtd::char16, char_t>) return chars_;
      else return __xtd_convert_to_string<xtd::char16>(chars_);
    }
    
    /// @brief Converts the value of this instance to a xtd::basic_string <xtd::char32>.
    /// @return The current string.
    [[nodiscard]] auto to_u32string() const noexcept -> basic_string<xtd::char32> {
      if constexpr(std::is_same_v<xtd::char32, char_t>) return chars_;
      else return __xtd_convert_to_string<xtd::char32>(chars_);
    }
    
    /// @brief Converts the value of this instance to a xtd::basic_string <xtd::char8>.
    /// @return The current string.
    [[nodiscard]] auto to_u8string() const noexcept -> basic_string<xtd::char8> {
      if constexpr(std::is_same_v<xtd::char8, char_t>) return chars_;
      else return __xtd_convert_to_string<xtd::char8>(chars_);
    }
    
    /// @brief Returns a copy of the current xtd::basic_string converted to uppercase.
    /// @return A string in uppercase.
    [[nodiscard]] auto to_upper() const noexcept -> basic_string {
      auto result = basic_string::empty_string;
      std::for_each(chars_.begin(), chars_.end(), [&](auto c) {result += static_cast<value_type>(std::toupper(c));});
      return result;
    }
    
    /// @brief Converts the value of this instance to a xtd::basic_string <xtd::wchar>.
    /// @return The current string.
    [[nodiscard]] auto to_wstring() const noexcept -> basic_string<xtd::wchar> {
      if constexpr(std::is_same_v<xtd::wchar, char_t>) return chars_;
      else return __xtd_convert_to_string<xtd::wchar>(chars_);
    }
    
    /// @brief Removes all leading and trailing occurrences of white-space characters from the specified xtd::basic_string.
    /// @param str xtd::basic_string to trim end.
    /// @param trim_char A character to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the character in the trim_char parameter are removed from the start and te and of the specified xtd::basic_string.
    [[nodiscard]] auto trim() const noexcept -> basic_string {return trim(default_trim_chars);}
    /// @brief Removes all leading and trailing occurrences of a character specified from the specified xtd::basic_string .
    /// @param str xtd::basic_string to trim start.
    /// @param trim_char A character to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the character in the trim_char parameter are removed from the start and the end of the specified xtd::basic_string.
    [[nodiscard]] auto trim(value_type trim_char) const noexcept -> basic_string;
    /// @brief Removes all leading and trailing occurrences of a set of characters specified in an array from the specified xtd::basic_string.
    /// @param str xtd::basic_string to trim end.
    /// @param trim_chars An array of characters to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the characters in the trim_chars parameter are removed from the start and the edn of the specified xtd::basic_string.
    [[nodiscard]] auto trim(const xtd::array<value_type>& trim_chars) const noexcept -> basic_string;
    
    /// @brief Removes all trailing occurrences of white-space characters from the specified xtd::basic_string.
    /// @param str xtd::basic_string to trim end.
    /// @param trim_char A character to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the character in the trim_char parameter are removed from the end of the specified xtd::basic_string.
    [[nodiscard]] auto trim_end() const noexcept -> basic_string {return trim_end(default_trim_chars);}
    /// @brief Removes all trailing occurrences of a character specified from the specified xtd::basic_string .
    /// @param str xtd::basic_string to trim start.
    /// @param trim_char A character to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the character in the trim_char parameter are removed from the end of the specified xtd::basic_string.
    [[nodiscard]] auto trim_end(value_type trim_char) const noexcept -> basic_string;
    /// @brief Removes all trailing occurrences of a set of characters specified in an array from the specified xtd::basic_string.
    /// @param str xtd::basic_string to trim end.
    /// @param trim_chars An array of characters to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the characters in the trim_chars parameter are removed from the end of the specified xtd::basic_string.
    [[nodiscard]] auto trim_end(const xtd::array<value_type>& trim_chars) const noexcept -> basic_string;
    
    /// @brief Removes all leading occurrences of white-space characters from the specified xtd::basic_string.
    /// @param str xtd::basic_string to trim start.
    /// @param trim_char A character to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the character in the trim_char parameter are removed from the start of the specified xtd::basic_string.
    [[nodiscard]] auto trim_start() const noexcept -> basic_string {return trim_start(default_trim_chars);}
    /// @brief Removes all leading occurrences of a character specified from the specified xtd::basic_string .
    /// @param str xtd::basic_string to trim start.
    /// @param trim_char A character to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the character in the trim_char parameter are removed from the start of the specified xtd::basic_string.
    [[nodiscard]] auto trim_start(value_type trim_char) const noexcept -> basic_string;
    /// @brief Removes all leading occurrences of a set of characters specified in an array from the specified xtd::basic_string.
    /// @param str An xtd::basic_string to trim start.
    /// @param trim_chars An array of characters to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the characters in the trim_chars parameter are removed from the start of the specified xtd::basic_string.
    [[nodiscard]] auto trim_start(const xtd::array<value_type>& trim_chars) const noexcept -> basic_string;
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Compares two specified basic_string objects and returns an integer that indicates their relative position in the sort order.
    /// @param str_a The first basic_string to compare.
    /// @param str_b The second basic_string to compare.
    /// @return A 32-bit signed integer that indicates the lexical relationship between the two compares.
    /// | Value             | Condition                                                     |
    /// | ----------------- | ------------------------------------------------------------- |
    /// | Less than zero    | str_a precedes str_b in the sort order.                       |
    /// | Zero              | str_a occurs in the same position as str_b in the sort order. |
    /// | Greater than zero | str_a follows str_b in the sort order.                        |
    [[nodiscard]] static auto compare(const basic_string& str_a, const basic_string& str_b) noexcept -> xtd::int32 {return compare(str_a, str_b, false);}
    /// @brief Compares two specified basic_string objects, ignoring or honoring their case, and returns an integer that indicates their relative position in the sort order.
    /// @param str_a The first basic_string to compare.
    /// @param str_b The second basic_string to compare.
    /// @param ignore_case `true` to ignore case during the comparison; otherwise, `false`.
    /// @return A 32-bit signed integer that indicates the lexical relationship between the two compares.
    /// | Value             | Condition                                                     |
    /// | ----------------- | ------------------------------------------------------------- |
    /// | Less than zero    | str_a precedes str_b in the sort order.                       |
    /// | Zero              | str_a occurs in the same position as str_b in the sort order. |
    /// | Greater than zero | str_a follows str_b in the sort order.                        |
    [[nodiscard]] static auto compare(const basic_string& str_a, const basic_string& str_b, bool ignore_case) noexcept -> xtd::int32 {return compare(str_a, str_b, ignore_case ? xtd::string_comparison::ordinal_ignore_case : xtd::string_comparison::ordinal);}
    /// @brief Compares two specified basic_string objects using the specified rules, and returns an integer that indicates their relative position in the sort order.
    /// @param str_a The first basic_string to compare.
    /// @param str_b The second basic_string to compare.
    /// @param comparison_type One of the enumeration values that specifies the rules to use in the comparison.
    /// @return A 32-bit signed integer that indicates the lexical relationship between the two compares.
    /// | Value             | Condition                                                     |
    /// | ----------------- | ------------------------------------------------------------- |
    /// | Less than zero    | str_a precedes str_b in the sort order.                       |
    /// | Zero              | str_a occurs in the same position as str_b in the sort order. |
    /// | Greater than zero | str_a follows str_b in the sort order.                        |
    [[nodiscard]] static auto compare(const basic_string& str_a, const basic_string& str_b, xtd::string_comparison comparison_type) noexcept -> xtd::int32 {return comparison_type == xtd::string_comparison::ordinal_ignore_case ? str_a.to_lower().chars_.compare(str_b.to_lower()) : str_a.chars_.compare(str_b);}
    /// @brief Compares substrings of two specified basic_string objects and returns an integer that indicates their relative position in the sort order.
    /// @param str_a The first basic_string to use in the comparison.
    /// @param index_a The position of the substring within str_a.
    /// @param str_b The second basic_string to use in the comparison.
    /// @param index_b The position of the substring within str_b.
    /// @param length The maximum number of characters in the substrings to compare
    /// @return A 32-bit signed integer that indicates the lexical relationship between the two compares.
    /// | Value             | Condition                                                     |
    /// | ----------------- | ------------------------------------------------------------- |
    /// | Less than zero    | str_a precedes str_b in the sort order.                       |
    /// | Zero              | str_a occurs in the same position as str_b in the sort order. |
    /// | Greater than zero | str_a follows str_b in the sort order.                        |
    [[nodiscard]] static auto compare(const basic_string& str_a, xtd::usize index_a, const basic_string& str_b, xtd::usize index_b, xtd::usize length) -> xtd::int32 {return compare(str_a, index_a, str_b, index_b, length, false);}
    /// @brief Compares substrings of two specified basic_string objects, ignoring or honoring their case, and returns an integer that indicates their relative position in the sort order.
    /// @param str_a The first basic_string to use in the comparison.
    /// @param index_a The position of the substring within str_a.
    /// @param str_b The second basic_string to use in the comparison.
    /// @param index_b The position of the substring within str_b.
    /// @param length The maximum number of characters in the substrings to compare
    /// @param ignore_case `true` to ignore case during the comparison; otherwise, `false`.
    /// @return A 32-bit signed integer that indicates the lexical relationship between the two compares.
    /// | Value             | Condition                                                     |
    /// | ----------------- | ------------------------------------------------------------- |
    /// | Less than zero    | str_a precedes str_b in the sort order.                       |
    /// | Zero              | str_a occurs in the same position as str_b in the sort order. |
    /// | Greater than zero | str_a follows str_b in the sort order.                        |
    [[nodiscard]] static auto compare(const basic_string& str_a, xtd::usize index_a, const basic_string& str_b, xtd::usize index_b, xtd::usize length, bool ignore_case) -> xtd::int32 {return compare(str_a, index_a, str_b, index_b, length, ignore_case ? xtd::string_comparison::ordinal_ignore_case : xtd::string_comparison::ordinal);}
    /// @brief Compares substrings of two specified basic_string objects using the specified rules, and returns an integer that indicates their relative position in the sort order.
    /// @param str_a The first basic_string to use in the comparison.
    /// @param index_a The position of the substring within str_a.
    /// @param str_b The second basic_string to use in the comparison.
    /// @param index_b The position of the substring within str_b.
    /// @param length The maximum number of characters in the substrings to compare
    /// @param comparison_type One of the enumeration values that specifies the rules to use in the comparison.
    /// @return A 32-bit signed integer that indicates the lexical relationship between the two compares.
    /// | Value             | Condition                                                     |
    /// | ----------------- | ------------------------------------------------------------- |
    /// | Less than zero    | str_a precedes str_b in the sort order.                       |
    /// | Zero              | str_a occurs in the same position as str_b in the sort order. |
    /// | Greater than zero | str_a follows str_b in the sort order.                        |
    [[nodiscard]] static auto compare(const basic_string& str_a, xtd::usize index_a, const basic_string& str_b, xtd::usize index_b, xtd::usize length, xtd::string_comparison comparison_type) -> xtd::int32 {return comparison_type == xtd::string_comparison::ordinal_ignore_case ? str_a.substring(index_a, length).to_lower().chars_.compare(str_b.substring(index_b, length).to_lower()) : str_a.substring(index_a, length).chars_.compare(str_b.substring(index_b, length));}
    
    /// @brief Concatenates four specified instances of basic_string.
    /// @param str_a The first basic_string to concatenate.
    /// @param str_b The second basic_string to concatenate.
    /// @param str_c The third basic_string to concatenate.
    /// @param str_d The fourth basic_string to concatenate.
    /// @return The concatenation of str_a, str_b, str_c and str_d.
    [[nodiscard]] static auto concat(const basic_string& str_a, const basic_string& str_b, const basic_string& str_c, const basic_string& str_d) noexcept -> basic_string {return str_a + str_b + str_c + str_d;}
    /// @brief Concatenates four specified instances of object.
    /// @param obj_a The first object to concatenate.
    /// @param obj_b The second object to concatenate.
    /// @param obj_c The third object to concatenate.
    /// @param obj_d The fourth object to concatenate.
    /// @return The concatenation of obj_a, obj_b, obj_c and obj_d.
    template<typename object_a_t, typename object_b_t, typename object_c_t, typename object_d_t>
    [[nodiscard]] static auto concat(object_a_t obj_a, object_b_t obj_b, object_c_t obj_c, object_d_t obj_d) noexcept -> basic_string {return format("{}{}{}{}", obj_a, obj_b, obj_c, obj_d);}
    /// @brief Concatenates three specified instances of basic_string.
    /// @param str_a The first basic_string to concatenate.
    /// @param str_b The second basic_string to concatenate.
    /// @param str_c The third basic_string to concatenate.
    /// @return basic_string The concatenation of str_a, str_b and str_c.
    [[nodiscard]] static auto concat(const basic_string& str_a, const basic_string& str_b, const basic_string& str_c) noexcept -> basic_string {return str_a + str_b + str_c;}
    /// @brief Concatenates three specified instances of object.
    /// @param obj_a The first object to concatenate.
    /// @param obj_b The second object to concatenate.
    /// @param obj_c The third object to concatenate.
    /// @return The concatenation of obj_a, obj_b and obj_c.
    template<typename object_a_t, typename object_b_t, typename object_c_t>
    [[nodiscard]] static auto concat(object_a_t obj_a, object_b_t obj_b, object_c_t obj_c) noexcept -> basic_string {return format("{}{}{}", obj_a, obj_b, obj_c);}
    /// @brief Concatenates two specified instances of basic_string.
    /// @param str_a The first basic_string to concatenate.
    /// @param str_b The second basic_string to concatenate.
    /// @return basic_string The concatenation of str_a and str_b.
    [[nodiscard]] static auto concat(const basic_string& str_a, const basic_string& str_b) noexcept -> basic_string {return str_a + str_b;}
    /// @brief Concatenates two specified instances of object.
    /// @param obj_a The first object to concatenate.
    /// @param obj_b The second object to concatenate.
    /// @return The concatenation of obj_a and obj_b.
    template<typename object_a_t, typename object_b_t>
    [[nodiscard]] static auto concat(object_a_t obj_a, object_b_t obj_b) noexcept -> basic_string {return format("{}{}", obj_a, obj_b);}
    /// @brief Concatenates the elements of a specified basic_string array.
    /// @param values An array of basic_string instances.
    /// @return The concatenated elements of values.
    [[nodiscard]] static auto concat(const xtd::array<basic_string>& values) noexcept -> basic_string;
    /// @cond
    [[nodiscard]] static auto concat(const xtd::array<const_pointer>& values) noexcept -> basic_string;
    template<typename other_char_t>
    [[nodiscard]] static auto concat(const xtd::array<const other_char_t*>& values) noexcept -> basic_string;
    [[nodiscard]] static auto concat(const std::initializer_list<basic_string>& values) noexcept -> basic_string {
      auto result = basic_string::empty_string;
      std::for_each(values.begin(), values.end(), [&](const auto& item) {result += item;});
      return result;
    }
    [[nodiscard]] static auto concat(const std::initializer_list<const_pointer>& values) noexcept -> basic_string {
      auto result = basic_string::empty_string;
      std::for_each(values.begin(), values.end(), [&](const auto& item) {result += item;});
      return result;
    }
    template<typename other_char_t>
    [[nodiscard]] static auto concat(const std::initializer_list<const other_char_t*>& values) noexcept -> basic_string {
      auto result = basic_string::empty_string;
      std::for_each(values.begin(), values.end(), [&](const auto& item) {result += item;});
      return result;
    }
    /// @endcond
    /// @brief Concatenates the basic_string representations of the elements in a specified object array.
    /// @param args An object array that contains the elements to concatenate.
    /// @return The concatenated basic_string representations of the values of the elements in args.
    template<typename object_t>
    [[nodiscard]] static auto concat(const xtd::array<object_t>& args) noexcept -> basic_string;
    /// @cond
    template<typename object_t>
    [[nodiscard]] static auto concat(const std::initializer_list<object_t>& args) noexcept -> basic_string {
      basic_string result;
      for (const auto& arg : args)
        result += format("{}", arg);
      return result;
    }
    /// @endcond
    /// @brief Creates the basic_string representation of a specified object.
    /// @param value The object to represent.
    /// @return The basic_string representation of the value of arg.
    template<typename value_t>
    [[nodiscard]] static auto concat(value_t value) noexcept -> basic_string {
      return format("{}", value);
    }
    
    /// @brief Gets demangled basic_string of name,.
    /// @param name The name to demangle.
    /// @return The demangled basic_string of name.
    /// @par Examples
    /// The following example shows how to use xtd::basic_string::demangle.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// using namespace xtd;
    ///
    /// auto main() -> int {
    ///   console::write_line("name = {}", typeid(xtd::date_time).name());
    ///   console::write_line("demangled name = {}", basic_string::demangle(typeid(xtd::date_time).name()));
    /// }
    ///
    /// // This code produces the following output on macOS :
    /// //
    /// // name = N3xtd9date_timeE
    /// // demangled name = xtd::date_time
    /// ```
    [[nodiscard]] static auto demangle(const basic_string& name) -> basic_string {
      if constexpr(std::is_same_v<char, char_t>) return __xtd_demangle(name.chars());
      else return __xtd_demangle(__xtd_convert_to_string<char>(name.chars()));
    }
    
    /// @brief Determines whether two specified xtd::basic_string objects have the same value.
    /// @param a The first basic_string to compare.
    /// @param b The second basic_string to compare.
    /// @return `true` if the value of `a` is the same as the value of `b`; otherwise, `false`.
    /// @remarks This method performs an ordinal (case-sensitive) comparison.
    [[nodiscard]] static auto equals(const basic_string& a, const basic_string& b) noexcept -> bool {return a.equals(b);}
    /// @brief Determines whether two specified xtd::basic_string objects have the same value.
    /// @param a The first basic_string to compare.
    /// @param b The second basic_string to compare.
    /// @return `true` if the value of `a` is the same as the value of `b`; otherwise, `false`.
    /// @remarks This method performs an ordinal (case-sensitive) comparison.
    template<typename char_a_t, typename char_b_t>
    [[nodiscard]] static auto equals(const char_a_t* a, const char_b_t* b) noexcept -> bool {return basic_string {a}.equals(basic_string {b});}
    
    /// @brief Determines whether two specified xtd::basic_string objects have the same value, ignoring or honoring their case.
    /// @param a The first basic_string to compare.
    /// @param b The second basic_string to compare.
    /// @param ignore_case `true` to ignore case when comparing this instance and value; otherwise, `false`
    /// @return `true` if the value of `a` is the same as the value of `b`; otherwise, `false`.
    /// @remarks This method performs an ordinal comparison.
    [[nodiscard]] static auto equals(const basic_string& a, const basic_string& b, bool ignore_case) noexcept -> bool {return a.equals(b, ignore_case);}
    /// @brief Determines whether two specified xtd::basic_string objects have the same value, ignoring or honoring their case.
    /// @param a The first basic_string to compare.
    /// @param b The second basic_string to compare.
    /// @param ignore_case `true` to ignore case when comparing this instance and value; otherwise, `false`
    /// @return `true` if the value of `a` is the same as the value of `b`; otherwise, `false`.
    /// @remarks This method performs an ordinal comparison.
    template<typename char_a_t, typename char_b_t>
    [[nodiscard]] static auto equals(const char_a_t* a, const char_b_t* b, bool ignore_case) noexcept -> bool {return basic_string {a}.equals(basic_string {b}, ignore_case);}
    
    /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
    /// @param fmt A composite format string.
    /// @param args arguments list to write using format.
    /// @return string formatted.
    /// @ingroup format_parse
    /// @remarks for more information about format see @ref FormatPage "Format".
    template<typename ...args_t>
    [[nodiscard]] static auto format(const basic_string<char>& fmt, args_t&& ... args) -> basic_string;
    
    /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
    /// @param loc An std::locale object that contains locale information (see [std::locale](https://en.cppreference.com/w/cpp/locale/locale)).
    /// @param fmt A composite format string.
    /// @param args arguments list to write using format.
    /// @return string formatted.
    /// @ingroup format_parse
    /// @remarks for more information about format see @ref FormatPage "Format".
    template<typename ...args_t>
    [[nodiscard]] static auto format(const std::locale& loc, const basic_string<char>& fmt, args_t&& ... args) -> basic_string;
    
    /// @brief Indicates whether the specifeid basic_string is an empty basic_string ("").
    /// @param string The xtd::basic_string to check if empty.
    /// @return `true` if the value parameter is null or an empty basic_string (""); otherwise, `false`.
    [[nodiscard]] static auto is_empty(const xtd::basic_string<value_type, traits_type, allocator_type>& string) noexcept -> bool {return !string.length();}
    
    /// @brief Concatenates a specified separator basic_string between each element of a specified object array, yielding a single concatenated basic_string.
    /// @param separator A basic_string separator.
    /// @param values An array of Object.
    /// @return A basic_string consisting of the elements of value interspersed with the separator basic_string.
    /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value) returns "red, blue, green, yellow".
    /// @remarks stream << operator is called on each object to generate the content.
    template<typename collection_t>
    [[nodiscard]] static auto join(const basic_string& separator, const collection_t& values) noexcept -> basic_string {
      xtd::usize i = 0;
      basic_string result;
      for (const auto& item : values)
        result += format("{}{}", (i++ != 0 ? separator : basic_string {}), item);
      return result;
    }
    /// @brief Concatenates a specified separator basic_string between each element of a specified object array, yielding a single concatenated basic_string.
    /// @param separator A basic_string separator.
    /// @param values An array of Object.
    /// @param start_index The first array element in value to use.
    /// @return A basic_string consisting of the elements of value interspersed with the separator basic_string.
    /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value) returns "red, blue, green, yellow".
    /// @remarks stream << operator is called on each object to generate the content.
    template<typename collection_t>
    [[nodiscard]] static auto join(const basic_string& separator, const collection_t& values, xtd::usize index) -> basic_string {return join(separator, values, index, values.size() - index);}
    /// @brief Concatenates a specified separator basic_string between each element of a specified Object array, yielding a single concatenated basic_string.
    /// @param separator A basic_string separator.
    /// @param values An array of Object.
    /// @param start_index The first array element in value to use.
    /// @param count The number of elements of value to use.
    /// @return A basic_string consisting of the elements of value interspersed with the separator basic_string.
    /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value) returns "red, blue, green, yellow".
    /// @remarks stream << operator is called on each object to generate the content.
    template<typename collection_t>
    [[nodiscard]] static auto join(const basic_string& separator, const collection_t& values, xtd::usize index, xtd::usize count) -> basic_string {
      if (index > values.size() || index + count > values.size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      xtd::usize i = 0;
      basic_string result;
      for (const auto& item : values) {
        if (i >= index) result += format("{}{}", (i != index ? separator : basic_string {}), item);
        if (++i >= index + count) break;
      }
      return result;
    }
    
    /// @cond
    template<typename value_t>
    [[nodiscard]] static auto join(const basic_string& separator, const std::initializer_list<value_t>& values) noexcept -> basic_string;
    template<typename value_t>
    [[nodiscard]] static auto join(const basic_string& separator, const std::initializer_list<value_t>& values, xtd::usize index) -> basic_string;
    template<typename value_t>
    [[nodiscard]] static auto join(const basic_string& separator, const std::initializer_list<value_t>& values, xtd::usize index, xtd::usize count) -> basic_string;
    /// @endcond
    
    /// @brief Converts a basic_string into a value_t type.
    /// @param str Ax xtd::basic_string to convert to value_t
    /// @return The value_t object parsed.
    template<typename value_t>
    [[nodiscard]] static auto parse(const basic_string& str) -> value_t {
      if constexpr(std::is_same_v<char, char_t>) return xtd::parse<value_t>(str.chars());
      else return xtd::parse<value_t>(__xtd_convert_to_string<char>(str.chars()));
    }
    
    /// @brief Writes the text representation of the specified arguments list, to basic_string using the specified format information.
    /// @param fmt A composite format basic_string.
    /// @param args arguments list to write using format.
    /// @return basic_string formatted.
    /// @ingroup format_parse
    /// @remarks A format specifier follows this prototype:
    /// @remarks %[flags][width][.precision][length]specifier
    /// | specifier | Output                                                                                                                                                   | Example      |
    /// | --------- | -------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ |
    /// | d or i    | Signed decimal integer                                                                                                                                   | 392          |
    /// | u         | Unsigned decimal integer                                                                                                                                 | 7235         |
    /// | o         | Unsigned octal                                                                                                                                           | 610          |
    /// | x         | Unsigned hexadecimal integer                                                                                                                             | 7fa          |
    /// | X         | Unsigned hexadecimal integer (uppercase)                                                                                                                 | 7FA          |
    /// | f         | Decimal floating point, lowercase                                                                                                                        | 392.65       |
    /// | F         | Decimal floating point, lowercase (uppercase)                                                                                                            | 392.65       |
    /// | e         | Scientific notation (mantissa/exponent), lowercase                                                                                                       | 3.9265e+2    |
    /// | E         | Scientific notation (mantissa/exponent), uppercase                                                                                                       | 3.9265E+2    |
    /// | g         | Use the shortest representation: %e or %f                                                                                                                | 392.65       |
    /// | G         | Use the shortest representation: %E or %F                                                                                                                | 392.65       |
    /// | a         | Hexadecimal floating point, lowercase                                                                                                                    | -0xc.90fep-2 |
    /// | A         | Hexadecimal floating point, uppercase                                                                                                                    | -0XC.90FEP-2 |
    /// | c         | Character                                                                                                                                                | a            |
    /// | s         | basic_string of characters                                                                                                                               | sample       |
    /// | p         | Pointer address                                                                                                                                          | b8000000     |
    /// | n         | Nothing printed. The corresponding argument must be a pointer to a signed int. The number of characters written so far is stored in the pointed location |              |
    /// | %         | A % followed by another % character will write a single % to the stream.                                                                                 | %            |
    /// @remarks The format specifier can also contain sub-specifiers: flags, width, .precision and modifiers (in that order), which are optional and follow these specifications:
    /// | flags   | description                                                                                                                                                                                                                                                                                                 |
    /// | ------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
    /// | -       | Left-justify within the given field width; Right justification is the default (see width sub-specifier).                                                                                                                                                                                                    |
    /// | +       | Forces to prefix the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.                                                                                                                                                     |
    /// | (space) | If no sign is going to be written, a blank space is inserted before the value.                                                                                                                                                                                                                              |
    /// | #       | Used with o, x or X specifiers the value is prefixed with 0, 0x or 0X respectively for values different than zero. Used with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written.  |
    /// | 0       | Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).                                                                                                                                                                                                 |
    ///
    /// | width    | description                                                                                                                                                                                          |
    /// | -------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
    /// | (number) | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger. |
    /// | *        | The width is not specified in the format basic_string, but as an additional integer value argument preceding the argument that has to be formatted.                                                  |
    ///
    /// | .precision | description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
    /// | ---------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
    /// | .number    | For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6). For g and G specifiers: This is the maximum number of significant digits to be printed. For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. If the period is specified without an explicit value for precision, 0 is assumed. |
    /// | .*         | The precision is not specified in the format basic_string, but as an additional integer value argument preceding the argument that has to be formatted.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
    /// @remarks The length sub-specifier modifies the length of the data type. This is a chart showing the types used to interpret the corresponding arguments with and without length specifier (if a different type is used, the proper type promotion or conversion is performed, if allowed):
    /// | length | d i           | u o x X                | f F e E g G a A | c     | s        | p     | n               |
    /// | ------ | ------------- | ---------------------- | --------------- | ----- | -------- | ----- | --------------- |
    /// | (none) | int           | unsigned int           | double          | int   | char8*   | void* | int*            |
    /// | hh     | signed char8  | unsigned char8         |                 |       |          |       | unsigned char8* |
    /// | h      | short int     | unsigned short int     |                 |       |          |       | short int*      |
    /// | l      | long int      | unsigned long int      |                 | win_t | wchar*   |       | long int*       |
    /// | ll     | long long int | unsigned long long int |                 |       |          |       | long long int*  |
    /// | j      | intmax_t      | uintmax_t              |                 |       |          |       | intmax_t*       |
    /// | z      | size_t        | size_t                 |                 |       |          |       | size_t*         |
    /// | t      | ptrdiff_t     | ptrdiff_t              |                 |       |          |       | ptrdiff_t*      |
    /// | L      |               |                        | long double     |       |          |       |                 |
    /// @remarks Note regarding the c specifier: it takes an int (or wint_t) as argument, but performs the proper conversion to a char8 value (or a wchar) before formatting it for output.
    /// @remarks you can use std::basic_string or std::wstring with format param %%s.
    template<typename ...args_t>
    [[nodiscard]] static auto sprintf(const basic_string& fmt, args_t&& ... args) noexcept -> basic_string {return __sprintf(fmt.chars().c_str(), convert_param(std::forward<args_t>(args)) ...);}
    
    /// @brief Try to convert a basic_string into a value_t type.
    /// @param str An xtd::basic_string to convert to value_t
    /// @param value The value that will contain the parsed xtd::basic_string.
    /// @return `true` if xtd::basic_string:=:try_parse succed; otherwise, `false`.
    template<typename value_t>
    [[nodiscard]] static auto try_parse(const basic_string& str, value_t& value) noexcept -> bool {
      try {
        value = parse<value_t>(str);
        return true;
      } catch (...) {
        return false;
      }
    }
    /// @}
    
    /// @name Public Operators
    
    /// @{
    /// @brief Returns a reference to the character at specified location index.
    /// @param index The position of the character to return.
    /// @return Reference to the requested character.
    /// @exception xtd::index_out_of_range_exception If `index` is not within the range of the string.
    auto operator [](xtd::usize index) const -> const_reference {
      if (index >= length() && index != epos) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      return chars_[index == epos ? length() - 1 : index];
    }
    
    /// @brief Returns a reference to the underlying base type.
    /// @return Reference to the underlying base type.
    operator const base_type& () const noexcept {return chars_;}
    
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of str.
    /// @param str String to use as data source.
    /// @return This current instance.
    auto operator =(const basic_string<char>& str) noexcept -> basic_string& {
      if constexpr(std::is_same<char_t, char>::value) chars_ = str.chars_;
      else chars_ = __xtd_convert_to_string<value_type>(str.chars());
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of str.
    /// @param str String to use as data source.
    /// @return This current instance.
    auto operator =(const basic_string<xtd::char16>& str) noexcept -> basic_string& {
      if constexpr(std::is_same<char_t, xtd::char16>::value) chars_ = str.chars_;
      else chars_ = __xtd_convert_to_string<value_type>(str.chars());
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of str.
    /// @param str String to use as data source.
    /// @return This current instance.
    auto operator =(const basic_string<xtd::char32>& str) noexcept -> basic_string& {
      if constexpr(std::is_same<char_t, xtd::char32>::value) chars_ = str.chars_;
      else chars_ = __xtd_convert_to_string<value_type>(str.chars());
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of str.
    /// @param str String to use as data source.
    /// @return This current instance.
    auto operator =(const basic_string<xtd::char8>& str) noexcept -> basic_string& {
      if constexpr(std::is_same<char_t, xtd::char8>::value) chars_ = str.chars_;
      else chars_ = __xtd_convert_to_string<value_type>(str.chars());
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of str.
    /// @param str String to use as data source.
    /// @return This current instance.
    auto operator =(const basic_string<xtd::wchar>& str) noexcept -> basic_string& {
      if constexpr(std::is_same<char_t, xtd::wchar>::value) chars_ = str.chars_;
      else chars_ = __xtd_convert_to_string<value_type>(str.chars());
      return self_;
    }
    
    /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in `str` is moved from `str` into this string). `str` is in a valid but unspecified state afterwards.
    /// @param str String to use as data source.
    /// @return This current instance.
    auto operator =(basic_string<char>&& str) noexcept -> basic_string& {
      if constexpr(std::is_same<char_t, char>::value) chars_ = std::move(str.chars_);
      else chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_)));
      return self_;
    }
    /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in `str` is moved from `str` into this string). `str` is in a valid but unspecified state afterwards.
    /// @param str String to use as data source.
    /// @return This current instance.
    auto operator =(basic_string<xtd::char16>&& str) noexcept -> basic_string& {
      if constexpr(std::is_same<char_t, xtd::char16>::value) chars_ = std::move(str.chars_);
      else chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_)));
      return self_;
    }
    /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in `str` is moved from `str` into this string). `str` is in a valid but unspecified state afterwards.
    /// @param str String to use as data source.
    /// @return This current instance.
    auto operator =(basic_string<xtd::char32>&& str) noexcept -> basic_string& {
      if constexpr(std::is_same<char_t, xtd::char32>::value) chars_ = std::move(str.chars_);
      else chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_)));
      return self_;
    }
    /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in `str` is moved from `str` into this string). `str` is in a valid but unspecified state afterwards.
    /// @param str String to use as data source.
    /// @return This current instance.
    auto operator =(basic_string<xtd::char8>&& str) noexcept -> basic_string& {
      if constexpr(std::is_same<char_t, xtd::char8>::value) chars_ = std::move(str.chars_);
      else chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_)));
      return self_;
    }
    /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in `str` is moved from `str` into this string). `str` is in a valid but unspecified state afterwards.
    /// @param str String to use as data source.
    /// @return This current instance.
    auto operator =(basic_string<xtd::wchar>&& str) noexcept -> basic_string& {
      if constexpr(std::is_same<char_t, xtd::wchar>::value) chars_ = std::move(str.chars_);
      else chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_)));
      return self_;
    }
    
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    auto operator =(const std::basic_string<char>& str) noexcept -> basic_string& {
      if constexpr(std::is_same<char_t, char>::value) chars_ = str;
      else chars_ = __xtd_convert_to_string<value_type>(str);
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    auto operator =(const std::basic_string<xtd::char16>& str) noexcept -> basic_string& {
      if constexpr(std::is_same<char_t, xtd::char16>::value) chars_ = str;
      else chars_ = __xtd_convert_to_string<value_type>(str);
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    auto operator =(const std::basic_string<xtd::char32>& str) noexcept -> basic_string& {
      if constexpr(std::is_same<char_t, xtd::char32>::value) chars_ = str;
      else chars_ = __xtd_convert_to_string<value_type>(str);
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    auto operator =(const std::basic_string<xtd::char8>& str) noexcept -> basic_string& {
      if constexpr(std::is_same<char_t, xtd::char8>::value) chars_ = str;
      else chars_ = __xtd_convert_to_string<value_type>(str);
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    auto operator =(const std::basic_string<xtd::wchar>& str) noexcept -> basic_string& {
      if constexpr(std::is_same<char_t, xtd::wchar>::value) chars_ = str;
      else chars_ = __xtd_convert_to_string<value_type>(str);
      return self_;
    }
    
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    auto operator =(std::basic_string<char>&& str) noexcept -> basic_string& {
      if constexpr(std::is_same<char_t, char>::value) chars_ = std::move(str);
      else chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str)));
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    auto operator =(std::basic_string<xtd::char16>&& str) noexcept -> basic_string& {
      if constexpr(std::is_same<char_t, xtd::char16>::value) chars_ = std::move(str);
      else chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str)));
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    auto operator =(std::basic_string<xtd::char32>&& str) noexcept -> basic_string& {
      if constexpr(std::is_same<char_t, xtd::char32>::value) chars_ = std::move(str);
      else chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str)));
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    auto operator =(std::basic_string<xtd::char8>&& str) noexcept -> basic_string& {
      if constexpr(std::is_same<char_t, xtd::char8>::value) chars_ = std::move(str);
      else chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str)));
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    auto operator =(std::basic_string<xtd::wchar>&& str) noexcept -> basic_string& {
      if constexpr(std::is_same<char_t, xtd::wchar>::value) chars_ = std::move(str);
      else chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str)));
      return self_;
    }
    
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    auto operator =(const char* str) -> basic_string& {
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<char, char_t>) chars_ = std::basic_string<char>(str);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<char>(str));
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    auto operator =(const xtd::char16* str) -> basic_string& {
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::char16, char_t>) chars_ = std::basic_string<xtd::char16>(str);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char16>(str));
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    auto operator =(const xtd::char32* str) -> basic_string& {
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::char32, char_t>) chars_ = std::basic_string<xtd::char32>(str);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char32>(str));
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    auto operator =(const xtd::char8* str) -> basic_string& {
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::char8, char_t>) chars_ = std::basic_string<xtd::char8>(str);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char8>(str));
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    auto operator =(const xtd::wchar* str) -> basic_string& {
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::wchar, char_t>) chars_ = std::basic_string<xtd::wchar>(str);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::wchar>(str));
      return self_;
    }
    
    /// @brief Copy assignment operator. Replaces the contents with the specified character.
    /// @param character The character to use as data source.
    /// @return This current instance.
    auto operator =(char character) -> basic_string& {
      self_ = basic_string(character, 1);
      return  self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with the specified character.
    /// @param character The character to use as data source.
    /// @return This current instance.
    auto operator =(xtd::char16 character) -> basic_string& {
      self_ = basic_string(character, 1);
      return  self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with the specified character.
    /// @param character The character to use as data source.
    /// @return This current instance.
    auto operator =(xtd::char32 character) -> basic_string& {
      self_ = basic_string(character, 1);
      return  self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with the specified character.
    /// @param character The character to use as data source.
    /// @return This current instance.
    auto operator =(xtd::char8 character) -> basic_string& {
      self_ = basic_string(character, 1);
      return  self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with the specified character.
    /// @param character The character to use as data source.
    /// @return This current instance.
    auto operator =(xtd::wchar character) -> basic_string& {
      self_ = basic_string(character, 1);
      return  self_;
    }
    
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of the specified initializer list.
    /// @param il The initialiazer list to use as data source.
    /// @return This current instance.
    auto operator =(const std::initializer_list<char>& il) -> basic_string& {
      self_ = basic_string(il);
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of the specified initializer list.
    /// @param il The initialiazer list to use as data source.
    /// @return This current instance.
    auto operator =(const std::initializer_list<xtd::char16>& il) -> basic_string& {
      self_ = basic_string(il);
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of the specified initializer list.
    /// @param il The initialiazer list to use as data source.
    /// @return This current instance.
    auto operator =(const std::initializer_list<xtd::char32>& il) -> basic_string& {
      self_ = basic_string(il);
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of the specified initializer list.
    /// @param il The initialiazer list to use as data source.
    /// @return This current instance.
    auto operator =(const std::initializer_list<xtd::char8>& il) -> basic_string& {
      self_ = basic_string(il);
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of the specified initializer list.
    /// @param il The initialiazer list to use as data source.
    /// @return This current instance.
    auto operator =(const std::initializer_list<xtd::wchar>& il) -> basic_string& {
      self_ = basic_string(il);
      return self_;
    }
    
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    auto operator +=(const basic_string<char>& str) -> basic_string& {
      if constexpr(std::is_same_v<char, char_t>) chars_ += str.chars_;
      else chars_ += __xtd_convert_to_string<value_type>(str.chars_);
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    auto operator +=(const basic_string<xtd::char16>& str) -> basic_string& {
      if constexpr(std::is_same_v<xtd::char16, char_t>) chars_ += str.chars_;
      else chars_ += __xtd_convert_to_string<value_type>(str.chars_);
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    auto operator +=(const basic_string<xtd::char32>& str) -> basic_string& {
      if constexpr(std::is_same_v<xtd::char32, char_t>) chars_ += str.chars_;
      else chars_ += __xtd_convert_to_string<value_type>(str.chars_);
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    auto operator +=(const basic_string<xtd::char8>& str) -> basic_string& {
      if constexpr(std::is_same_v<xtd::char8, char_t>) chars_ += str.chars_;
      else chars_ += __xtd_convert_to_string<value_type>(str.chars_);
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    auto operator +=(const basic_string<xtd::wchar>& str) -> basic_string& {
      if constexpr(std::is_same_v<xtd::wchar, char_t>) chars_ += str.chars_;
      else chars_ += __xtd_convert_to_string<value_type>(str.chars_);
      return self_;
    }
    
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    auto operator +=(basic_string<char>&& str) -> basic_string& {
      if constexpr(std::is_same_v<char, char_t>) chars_ += std::move(str.chars_);
      else chars_ += __xtd_convert_to_string<value_type>(std::move(str.chars_));
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    auto operator +=(basic_string<xtd::char16>&& str) -> basic_string& {
      if constexpr(std::is_same_v<xtd::char16, char_t>) chars_ += std::move(str.chars_);
      else chars_ += __xtd_convert_to_string<value_type>(std::move(str.chars_));
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    auto operator +=(basic_string<xtd::char32>&& str) -> basic_string& {
      if constexpr(std::is_same_v<xtd::char32, char_t>) chars_ += std::move(str.chars_);
      else chars_ += __xtd_convert_to_string<value_type>(std::move(str.chars_));
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    auto operator +=(basic_string<xtd::char8>&& str) -> basic_string& {
      if constexpr(std::is_same_v<xtd::char8, char_t>) chars_ += std::move(str.chars_);
      else chars_ += __xtd_convert_to_string<value_type>(std::move(str.chars_));
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    auto operator +=(basic_string<xtd::wchar>&& str) -> basic_string& {
      if constexpr(std::is_same_v<xtd::wchar, char_t>) chars_ += std::move(str.chars_);
      else chars_ += __xtd_convert_to_string<value_type>(std::move(str.chars_));
      return self_;
    }
    
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    auto operator +=(const std::basic_string<char>& str) -> basic_string& {
      if constexpr(std::is_same_v<char, char_t>) chars_ += str;
      else chars_ += __xtd_convert_to_string<value_type>(str);
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    auto operator +=(const std::basic_string<xtd::char16>& str) -> basic_string& {
      if constexpr(std::is_same_v<xtd::char16, char_t>) chars_ += str;
      else chars_ += __xtd_convert_to_string<value_type>(str);
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    auto operator +=(const std::basic_string<xtd::char32>& str) -> basic_string& {
      if constexpr(std::is_same_v<xtd::char32, char_t>) chars_ += str;
      else chars_ += __xtd_convert_to_string<value_type>(str);
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    auto operator +=(const std::basic_string<xtd::char8>& str) -> basic_string& {
      if constexpr(std::is_same_v<xtd::char8, char_t>) chars_ += str;
      else chars_ += __xtd_convert_to_string<value_type>(str);
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    auto operator +=(const std::basic_string<xtd::wchar>& str) -> basic_string& {
      if constexpr(std::is_same_v<xtd::wchar, char_t>) chars_ += str;
      else chars_ += __xtd_convert_to_string<value_type>(str);
      return self_;
    }
    
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    auto operator +=(const char* str) -> basic_string& {
      chars_ += basic_string(str).chars_;
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    auto operator +=(const xtd::char16* str) -> basic_string& {
      chars_.append(basic_string(str).chars_); return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    auto operator +=(const xtd::char32* str) -> basic_string& {
      chars_ += basic_string(str).chars_;
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    auto operator +=(const xtd::char8* str) -> basic_string& {
      chars_ += basic_string(str).chars_;
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    auto operator +=(const xtd::wchar* str) -> basic_string& {
      chars_ += basic_string(str).chars_;
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param ch Character value to append.
    /// @return This current instance with characters added.
    auto operator +=(char ch) -> basic_string& {
      chars_ += basic_string(ch, 1).chars_;
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param ch Character value to append.
    /// @return This current instance with characters added.
    auto operator +=(xtd::char16 ch) -> basic_string& {
      chars_ += basic_string(ch, 1).chars_;
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param ch Character value to append.
    /// @return This current instance with characters added.
    auto operator +=(xtd::char32 ch) -> basic_string& {
      chars_ += basic_string(ch, 1).chars_;
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param ch Character value to append.
    /// @return This current instance with characters added.
    auto operator +=(xtd::char8 ch) -> basic_string& {
      chars_ += basic_string(ch, 1).chars_;
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param ch Character value to append.
    /// @return This current instance with characters added.
    auto operator +=(xtd::wchar ch) -> basic_string& {
      chars_ += basic_string(ch, 1).chars_;
      return self_;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, const basic_string<char>& rhs) -> basic_string {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, const basic_string<xtd::char16>& rhs) -> basic_string {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, const basic_string<xtd::char32>& rhs) -> basic_string {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, const basic_string<xtd::char8>& rhs) -> basic_string {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, const basic_string<xtd::wchar>& rhs) -> basic_string {
      auto result = lhs;
      result += rhs;
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(basic_string&& lhs, basic_string<char>&& rhs) -> basic_string {
      auto result = std::move(lhs);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(basic_string&& lhs, basic_string<xtd::char16>&& rhs) -> basic_string {
      auto result = std::move(lhs);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(basic_string&& lhs, basic_string<xtd::char32>&& rhs) -> basic_string {
      auto result = std::move(lhs);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(basic_string&& lhs, basic_string<xtd::char8>&& rhs) -> basic_string {
      auto result = std::move(lhs);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(basic_string&& lhs, basic_string<xtd::wchar>&& rhs) -> basic_string {
      auto result = std::move(lhs);
      result += std::move(rhs);
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(basic_string&& lhs, const basic_string<char>& rhs) -> basic_string {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(basic_string&& lhs, const basic_string<xtd::char16>& rhs) -> basic_string {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(basic_string&& lhs, const basic_string<xtd::char32>& rhs) -> basic_string {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(basic_string&& lhs, const basic_string<xtd::char8>& rhs) -> basic_string {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(basic_string&& lhs, const basic_string<xtd::wchar>& rhs) -> basic_string {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, basic_string<char>&& rhs) -> basic_string {
      auto result = lhs;
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, basic_string<xtd::char16>&& rhs) -> basic_string {
      auto result = lhs;
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, basic_string<xtd::char32>&& rhs) -> basic_string {
      auto result = lhs;
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, basic_string<xtd::char8>&& rhs) -> basic_string {
      auto result = lhs;
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, basic_string<xtd::wchar>&& rhs) -> basic_string {
      auto result = lhs;
      result += std::move(rhs);
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, const std::basic_string<char>& rhs) -> basic_string {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, const std::basic_string<xtd::char16>& rhs) -> basic_string {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, const std::basic_string<xtd::char32>& rhs) -> basic_string {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, const std::basic_string<xtd::char8>& rhs) -> basic_string {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, const std::basic_string<xtd::wchar>& rhs) -> basic_string {
      auto result = lhs;
      result += rhs;
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const std::basic_string<char>& lhs, const basic_string& rhs) -> basic_string {
      auto result = lhs;
      if constexpr(std::is_same_v<char, char_t>) result += rhs.chars();
      else result += __xtd_convert_to_string<char>(rhs.chars());
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const std::basic_string<xtd::char16>& lhs, const basic_string& rhs) -> basic_string {
      auto result = lhs;
      if constexpr(std::is_same_v<xtd::char16, char_t>) result += rhs.chars();
      else result += __xtd_convert_to_string<xtd::char16>(rhs.chars());
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const std::basic_string<xtd::char32>& lhs, const basic_string& rhs) -> basic_string {
      auto result = lhs;
      if constexpr(std::is_same_v<xtd::char32, char_t>) result += rhs.chars();
      else result += __xtd_convert_to_string<xtd::char32>(rhs.chars());
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const std::basic_string<xtd::char8>& lhs, const basic_string& rhs) -> basic_string {
      auto result = lhs;
      if constexpr(std::is_same_v<xtd::char8, char_t>) result += rhs.chars();
      else result += __xtd_convert_to_string<xtd::char8>(rhs.chars());
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const std::basic_string<xtd::wchar>& lhs, const basic_string& rhs) -> basic_string {
      auto result = lhs;
      if constexpr(std::is_same_v<xtd::wchar, char_t>) result += rhs.chars();
      else result += __xtd_convert_to_string<xtd::wchar>(rhs.chars());
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, const char* rhs) -> basic_string {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, const xtd::char16* rhs) -> basic_string {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, const xtd::char32* rhs) -> basic_string {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, const xtd::char8* rhs) -> basic_string {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, const xtd::wchar* rhs) -> basic_string {
      auto result = lhs;
      result += rhs;
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(basic_string&& lhs, const char* rhs) -> basic_string {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(basic_string&& lhs, const xtd::char16* rhs) -> basic_string {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(basic_string&& lhs, const xtd::char32* rhs) -> basic_string {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(basic_string&& lhs, const xtd::char8* rhs) -> basic_string {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(basic_string&& lhs, const xtd::wchar* rhs) -> basic_string {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const char* lhs, const basic_string& rhs) -> basic_string {
      auto result = basic_string(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const xtd::char16* lhs, const basic_string& rhs) -> basic_string {
      auto result = basic_string(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const xtd::char32* lhs, const basic_string& rhs) -> basic_string {
      auto result = basic_string(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const xtd::char8* lhs, const basic_string& rhs) -> basic_string {
      auto result = basic_string(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const xtd::wchar* lhs, const basic_string& rhs) -> basic_string {
      auto result = basic_string(lhs);
      result += rhs;
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const char* lhs, basic_string&& rhs) -> basic_string {
      auto result = basic_string(lhs);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const xtd::char16* lhs, basic_string&& rhs) -> basic_string {
      auto result = basic_string(lhs);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const xtd::char32* lhs, basic_string&& rhs) -> basic_string {
      auto result = basic_string(lhs);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const xtd::char8* lhs, basic_string&& rhs) -> basic_string {
      auto result = basic_string(lhs);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const xtd::wchar* lhs, basic_string&& rhs) -> basic_string {
      auto result = basic_string(lhs);
      result += std::move(rhs);
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, const char rhs) -> basic_string {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, const xtd::char16 rhs) -> basic_string {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, const xtd::char32 rhs) -> basic_string {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, const xtd::char8 rhs) -> basic_string {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(const basic_string& lhs, const xtd::wchar rhs) -> basic_string {
      auto result = lhs;
      result += rhs;
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(basic_string&& lhs, const char rhs) -> basic_string {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(basic_string&& lhs, const xtd::char16 rhs) -> basic_string {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(basic_string&& lhs, const xtd::char32 rhs) -> basic_string {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(basic_string&& lhs, const xtd::char8 rhs) -> basic_string {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(basic_string&& lhs, const xtd::wchar rhs) -> basic_string {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(char lhs, const basic_string& rhs) -> basic_string {
      auto result = basic_string(lhs, 1);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(xtd::char16 lhs, const basic_string& rhs) -> basic_string {
      auto result = basic_string(lhs, 1);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(xtd::char32 lhs, const basic_string& rhs) -> basic_string {
      auto result = basic_string(lhs, 1);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(xtd::char8 lhs, const basic_string& rhs) -> basic_string {
      auto result = basic_string(lhs, 1);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(xtd::wchar lhs, const basic_string& rhs) -> basic_string {
      auto result = basic_string(lhs, 1);
      result += rhs;
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(char lhs, basic_string&& rhs) -> basic_string {
      auto result = basic_string(lhs, 1);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(xtd::char16 lhs, basic_string&& rhs) -> basic_string {
      auto result = basic_string(lhs, 1);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(xtd::char32 lhs, basic_string&& rhs) -> basic_string {
      auto result = basic_string(lhs, 1);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(xtd::char8 lhs, basic_string&& rhs) -> basic_string {
      auto result = basic_string(lhs, 1);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend auto operator +(xtd::wchar lhs, basic_string&& rhs) -> basic_string {
      auto result = basic_string(lhs, 1);
      result += std::move(rhs);
      return result;
    }
    
    /// @todo uncomment following operators
    /// @brief Output stream operator. Behaves as a [FormattedOutputFunction](https://en.cppreference.com/w/cpp/named_req/FormattedOutputFunction). After constructing and checking the sentry object, [determines the output format padding](https://en.cppreference.com/w/cpp/named_req/FormattedOutputFunction#Padding).
    /// @param os The character output stream.
    /// @param str The string to be inserted.
    /// @remarks Then inserts each character from the resulting sequence `seq` (the contents of `str` plus padding) to the output stream `os` as if by calling `os.rdbuf()->sputn(seq, n)`, where n is `std::max(os.width(), str.length())`.
    /// @remarks Finally, calls `os.width(0)` to cancel the effects of std::setw, if any.
    /// @remarks Equivalent to `return os << std::basic_string_view<char_t, traits_t>(str);`.
    /// @todo uncomment following line and remove the next.
    //friend std::basic_ostream<char>& operator <<(std::basic_ostream<char>& stream, const basic_string& str) {return stream << str.to_string().chars_;}
    friend auto operator <<(std::basic_ostream<char>& stream, const basic_string& str) -> std::basic_ostream<char>& {
      if constexpr(std::is_same_v<char, char_t>) return stream << str.chars();
      else return stream << __xtd_convert_to_string<char>(str.chars());
    }
    /// @brief Output stream operator. Behaves as a [FormattedOutputFunction](https://en.cppreference.com/w/cpp/named_req/FormattedOutputFunction). After constructing and checking the sentry object, [determines the output format padding](https://en.cppreference.com/w/cpp/named_req/FormattedOutputFunction#Padding).
    /// @param os The character output stream.
    /// @param str The string to be inserted.
    /// @remarks Then inserts each character from the resulting sequence `seq` (the contents of `str` plus padding) to the output stream `os` as if by calling `os.rdbuf()->sputn(seq, n)`, where n is `std::max(os.width(), str.length())`.
    /// @remarks Finally, calls `os.width(0)` to cancel the effects of std::setw, if any.
    /// @remarks Equivalent to `return os << std::basic_string_view<char_t, traits_t>(str);`.
    friend auto operator <<(std::basic_ostream<xtd::wchar>& stream, const basic_string& str) -> std::basic_ostream<xtd::wchar>& {return stream << str.to_wstring().chars();}
    
    /// @brief Input stream operator. Behaves as a [FormattedInputFunction](https://en.cppreference.com/w/cpp/named_req/FormattedInputFunction). After constructing and checking the sentry object, which may skip leading whitespace, first clears `str` with `str.erase()`, then reads characters from `is` and appends them to `str` as if by `str.append(1, c)`, until one of the following conditions becomes `true`:
    /// * N characters are read, where N is `is.width()` if `is.width() > 0`, otherwise N is `str.max_size()`,
    /// * the end-of-file condition occurs in the stream is, or
    /// * `std::isspace(c, is.getloc())` is `true` for the next character `c` in `is` (this whitespace character remains in the input stream).
    /// @param is The character input stream.
    /// @param str The string to be extracted.
    /// @remarks If no characters are extracted then std::ios::failbit is set on `is`, which may throw [std::ios_base::failure](https://en.cppreference.com/w/cpp/io/ios_base/failure).
    /// @remarks Finally, calls `is.width(0)` to cancel the effects of [std::setw](https://en.cppreference.com/w/cpp/io/manip/setw), if any.
    friend auto operator >>(std::basic_istream<char>& stream, basic_string& str) -> std::basic_istream<char>& {
      auto s = std::basic_string<char> {};
      stream >> s;
      str = s;
      return stream;
    }
    /// @brief Input stream operator. Behaves as a [FormattedInputFunction](https://en.cppreference.com/w/cpp/named_req/FormattedInputFunction). After constructing and checking the sentry object, which may skip leading whitespace, first clears `str` with `str.erase()`, then reads characters from `is` and appends them to `str` as if by `str.append(1, c)`, until one of the following conditions becomes `true`:
    /// * N characters are read, where N is `is.width()` if `is.width() > 0`, otherwise N is `str.max_size()`,
    /// * the end-of-file condition occurs in the stream is, or
    /// * `std::isspace(c, is.getloc())` is `true` for the next character `c` in `is` (this whitespace character remains in the input stream).
    /// @param is The character input stream.
    /// @param str The string to be extracted.
    /// @remarks If no characters are extracted then std::ios::failbit is set on `is`, which may throw [std::ios_base::failure](https://en.cppreference.com/w/cpp/io/ios_base/failure).
    /// @remarks Finally, calls `is.width(0)` to cancel the effects of [std::setw](https://en.cppreference.com/w/cpp/io/manip/setw), if any.
    friend auto operator >>(std::basic_istream<xtd::wchar>& stream, basic_string& str) -> std::basic_istream<xtd::wchar>& {
      auto s = std::basic_string<xtd::wchar> {};
      stream >> s;
      str = s;
      return stream;
    }
    /// @}
    
    /// Name Public Deprecated Methods
    
    /// @brief Indicates whether this basic_string is an empty basic_string ("").
    /// @return `true` if the value parameter is null or an empty basic_string (""); otherwise, `false`.
    /// @deprecated Replaced by xtd::basic_string::is_empty(const xtd::basic_string&) - Will be removed in version 0.4.0.
    [[deprecated("Replaced by xtd::basic_string::is_empty(const xtd::basic_string&) - Will be removed in version 0.4.0.")]]
    [[nodiscard]] auto is_empty() const noexcept -> bool {return is_empty(self_);}
    /// @brief Gets the class name of the object_t.
    /// @return The class name of the object_t.
    /// @remarks For example, the name of the basic_string type is basic_string.
    /// @deprecated Replaced by typeof_<object_t>().name() - Will be removed in version 0.4.0.
    /// @}
    
    /// Name Public Deprecated Static Methods
    
    template<typename object_t>
    [[deprecated("Replaced by typeof_<object_t>().name() - Will be removed in version 0.4.0.")]]
    [[nodiscard]] static auto class_name() -> basic_string {return get_class_name(full_class_name<object_t>());}
    /// @brief Gets the class name of the specified object.
    /// @return The class name of the specified object.
    /// @remarks For example, the name of the basic_string type is basic_string.
    /// @deprecated Replaced by typeof_(object).name() - Will be removed in version 0.4.0.
    template<typename object_t>
    [[deprecated("Replaced by typeof_(object).name() - Will be removed in version 0.4.0.")]]
    [[nodiscard]] static auto class_name(const object_t& object) -> basic_string {return get_class_name(full_class_name(object));}
    /// @brief Gets the class name of the specified object.
    /// @return The class name of the specified object.
    /// @remarks For example, the name of the basic_string type is basic_string.
    /// @deprecated Replaced by typeof_(info).name() - Will be removed in version 0.4.0.
    [[deprecated("Replaced by typeof_(info).name() - Will be removed in version 0.4.0.")]]
    [[nodiscard]] static auto class_name(const std::type_info& info) -> basic_string {return __xtd_get_class_name(info);}
    /// @brief Gets the fully qualified class name of the objec_t, including the namespace of the objec_t.
    /// @return The fully qualified class name of the objec_t, including the namespace of the objec_t.
    /// @remarks For example, the fully qualified name of the basic_string type is xtd::basic_string.
    /// @deprecated Replaced by typeof_<object_t>().full_name() - Will be removed in version 0.4.0.
    template<typename object_t>
    [[deprecated("Replaced by typeof_<object_t>().full_name() - Will be removed in version 0.4.0.")]]
    [[nodiscard]] static auto full_class_name() -> basic_string {return demangle(typeid(object_t).name());}
    /// @brief Gets the fully qualified class name of the specified object, including the namespace of the specified object.
    /// @return The fully qualified class name of the objec_t, including the namespace of the specified object.
    /// @remarks For example, the fully qualified name of the basic_string type is xtd::basic_string.
    /// @deprecated Replaced by typeof_(object).full_name() - Will be removed in version 0.4.0.
    template<typename object_t>
    [[deprecated("Replaced by typeof_(object).full_name() - Will be removed in version 0.4.0.")]]
    [[nodiscard]] static auto full_class_name(const object_t& object) -> basic_string {return demangle(typeid(object).name());}
    /// @brief Gets the fully qualified class name of the specified object, including the namespace of the specified object.
    /// @return The fully qualified class name of the objec_t, including the namespace of the specified object.
    /// @remarks For example, the fully qualified name of the basic_string type is xtd::basic_string.
    /// @deprecated Replaced by typeof_(info).full_name() - Will be removed in version 0.4.0.
    [[deprecated("Replaced by typeof_(info).full_name() - Will be removed in version 0.4.0.")]]
    [[nodiscard]] static auto full_class_name(const std::type_info& info) -> basic_string {return __xtd_get_full_class_name(info);}
    /// @}
    
  private:
    friend class basic_string<char>;
    friend class basic_string<xtd::char16>;
    friend class basic_string<xtd::char32>;
    friend class basic_string<xtd::char8>;
    friend class basic_string<xtd::wchar>;
    
    static const xtd::array<value_type> default_split_separators;
    static const xtd::array<value_type> default_trim_chars;
    
    template<typename arg_t>
    [[nodiscard]] static auto convert_param(arg_t&& arg) noexcept {
      if constexpr(std::is_same<std::remove_cv_t<std::remove_reference_t<arg_t>>, std::string>::value) return std::forward<arg_t>(arg).c_str();
      else if constexpr(std::is_same<std::remove_cv_t<std::remove_reference_t<arg_t>>, std::u16string>::value) return std::forward<arg_t>(arg).c_str();
      else if constexpr(std::is_same<std::remove_cv_t<std::remove_reference_t<arg_t>>, std::u32string>::value) return std::forward<arg_t>(arg).c_str();
      else if constexpr(std::is_same<std::remove_cv_t<std::remove_reference_t<arg_t>>, std::u8string>::value) return std::forward<arg_t>(arg).c_str();
      else if constexpr(std::is_same<std::remove_cv_t<std::remove_reference_t<arg_t>>, std::wstring>::value) return std::forward<arg_t>(arg).c_str();
      else if constexpr(std::is_same<std::remove_cv_t<std::remove_reference_t<arg_t>>, basic_string>::value) return std::forward<arg_t>(arg).c_str();
      else return std::forward<arg_t>(arg);
    }
    
    [[nodiscard]] static auto get_class_name(const basic_string& full_name) -> basic_string {
      auto length = full_name.last_index_of("<");
      if (length == npos) length = full_name.length();
      if (full_name.last_index_of("::", 0, length) == npos) return full_name;
      return full_name.substring(full_name.last_index_of("::", 0, length) + 2);
    }
    
    base_type chars_;
  };
}

#define __XTD_BASIC_STRING_INTERNAL__
#include "basic_string_.hpp"
#undef __XTD_BASIC_STRING_INTERNAL__

/// @cond
namespace std {
  template<typename char_t>
  struct hash<xtd::basic_string<char_t>> {
    auto operator()(const xtd::basic_string<char_t>& s) const noexcept -> xtd::usize {return s.get_hash_code();}
  };
}
/// @endcond
