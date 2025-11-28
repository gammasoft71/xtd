/// @file
/// @brief Contains xtd::basic_string class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
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
#include "unused.hpp"
#include <cctype>
#include <iomanip>
#include <ostream>
#include <sstream>
#include <string>

/// @cond
template<class ...args_t>
void __basic_string_extract_format_arg(const std::locale& loc, xtd::basic_string<char>& fmt, xtd::array<__format_information<char >>& formats, args_t&&... args);
template<class target_t, class source_t>
std::basic_string<target_t> __xtd_convert_to_string(std::basic_string<source_t>&& str) noexcept;
template<class target_t, class source_t>
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
  template<class char_t, class traits_t, class allocator_t>
  class basic_string : public object, public xtd::icomparable<basic_string<char_t, traits_t, allocator_t>>, public xtd::iequatable<basic_string<char_t, traits_t, allocator_t >>, public xtd::collections::generic::ienumerable<char_t> {
  public:
    /// @name Public Aliases
    
    /// @{
    /// @brief Represents the basic string base type.
    /// @remarks Is equal to `std::basic_string<char_t, traits_t, allocator_t>`.`
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
    /// @remarks This constant is typically used to indicate the absence of an index or a failed search operation. It is equivalent to the maximum value of xtd::size.
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
    static inline constexpr xtd::size bpos = 0;
    
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
    static inline constexpr xtd::size epos = npos - 1;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes a new instance of xtd::basic_string.
    basic_string() = default;
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
    
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @exception xtd::argument_out_of_range_exception `index` is greater or equal than `str` size.
    basic_string(const basic_string<char>& str, xtd::size index) {
      if (index > str.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      if constexpr(std::is_same_v<char, char_t>) chars_ = base_type(str.chars_, index);
      else chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<char>(str.chars_, index)));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @exception xtd::argument_out_of_range_exception `index` is greater or equal than `str` size.
    basic_string(const basic_string<xtd::char16>& str, xtd::size index) {
      if (index > str.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      if constexpr(std::is_same_v<xtd::char16, char_t>) chars_ = base_type(str.chars_, index);
      else chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::char16>(str.chars_, index)));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @exception xtd::argument_out_of_range_exception `index` is greater or equal than `str` size.
    basic_string(const basic_string<xtd::char32>& str, xtd::size index) {
      if (index > str.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      if constexpr(std::is_same_v<xtd::char32, char_t>) chars_ = base_type(str.chars_, index);
      else chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::char32>(str.chars_, index)));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @exception xtd::argument_out_of_range_exception `index` is greater or equal than `str` size.
    basic_string(const basic_string<xtd::char8>& str, xtd::size index) {
      if (index > str.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      if constexpr(std::is_same_v<xtd::char8, char_t>) chars_ = base_type(str.chars_, index);
      else chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::char8>(str.chars_, index)));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @exception xtd::argument_out_of_range_exception `index` is greater or equal than `str` size.
    basic_string(const basic_string<xtd::wchar>& str, xtd::size index) {
      if (index > str.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      if constexpr(std::is_same_v<xtd::wchar, char_t>) chars_ = base_type(str.chars_, index);
      else chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::wchar>(str.chars_, index)));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index and count characters.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    /// @exception xtd::argument_out_of_range_exception `index` + `count`is greater or equal than `str` size.
    basic_string(const basic_string<char>& str, xtd::size index, xtd::size count) {
      if (index + count > str.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      if constexpr(std::is_same_v<char, char_t>) chars_ = base_type(str.chars_, index, count);
      else chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<char>(str.chars_, index, count)));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index and count characters.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    /// @exception xtd::argument_out_of_range_exception `index` + `count`is greater or equal than `str` size.
    basic_string(const basic_string<xtd::char16>& str, xtd::size index, xtd::size count) {
      if (index + count > str.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      if constexpr(std::is_same_v<xtd::char16, char_t>) chars_ = base_type(str.chars_, index, count);
      else chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::char16>(str.chars_, index, count)));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index and count characters.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    /// @exception xtd::argument_out_of_range_exception `index` + `count`is greater or equal than `str` size.
    basic_string(const basic_string<xtd::char32>& str, xtd::size index, xtd::size count) {
      if (index + count > str.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      if constexpr(std::is_same_v<xtd::char32, char_t>) chars_ = base_type(str.chars_, index, count);
      else chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::char32>(str.chars_, index, count)));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index and count characters.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    /// @exception xtd::argument_out_of_range_exception `index` + `count`is greater or equal than `str` size.
    basic_string(const basic_string<xtd::char8>& str, xtd::size index, xtd::size count) {
      if (index + count > str.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      if constexpr(std::is_same_v<xtd::char8, char_t>) chars_ = base_type(str.chars_, index, count);
      else chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::char8>(str.chars_, index, count)));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index and count characters.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    /// @exception xtd::argument_out_of_range_exception `index` + `count`is greater or equal than `str` size.
    basic_string(const basic_string<xtd::wchar>& str, xtd::size index, xtd::size count) {
      if (index + count > str.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      if constexpr(std::is_same_v<xtd::wchar, char_t>) chars_ = base_type(str.chars_, index, count);
      else chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::wchar>(str.chars_, index, count)));
    }
    
    /// @brief Initializes a new instance of xtd::basic_string with specified string to move.
    /// @param str The basic_string to move.
    basic_string(basic_string&&) = default;
    
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character.
    /// @param character The character copied.
    /// @param count The number of copies of character.
    basic_string(char character, xtd::size count) : basic_string(std::basic_string<char>(count, character)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character.
    /// @param character The character copied.
    /// @param count The number of copies of character.
    basic_string(xtd::char16 character, xtd::size count) : basic_string(std::basic_string<xtd::char16>(count, character)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character.
    /// @param character The character copied.
    /// @param count The number of copies of character.
    basic_string(xtd::char32 character, xtd::size count) : basic_string(std::basic_string<xtd::char32>(count, character)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character.
    /// @param character The character copied.
    /// @param count The number of copies of character.
    basic_string(xtd::char8 character, xtd::size count) : basic_string(std::basic_string<xtd::char8>(count, character)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character.
    /// @param character The character copied.
    /// @param count The number of copies of character.
    basic_string(xtd::wchar character, xtd::size count) : basic_string(std::basic_string<xtd::wchar>(count, character)) {}
    
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const char* str) {  // Can't be explicit by design.
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<char, char_t>) chars_ = std::basic_string<char>(str);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<char>(str));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const xtd::char16 * str) { // Can't be explicit by design.
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::char16, char_t>) chars_ = std::basic_string<xtd::char16>(str);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char16>(str));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const xtd::char32 * str) { // Can't be explicit by design.
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::char32, char_t>) chars_ = std::basic_string<xtd::char32>(str);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char32>(str));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const xtd::char8 * str) { // Can't be explicit by design.
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::char8, char_t>) chars_ = std::basic_string<xtd::char8>(str);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char8>(str));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const xtd::wchar * str) { // Can't be explicit by design.
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::wchar, char_t>) chars_ = std::basic_string<xtd::wchar>(str);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::wchar>(str));
    }
    
    /// @brief Initializes a new instance of xtd::basic_string with specified substring and count characters.
    /// @param count The number of substring characters to copy.
    basic_string(const char* str, xtd::size count) {
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<char, char_t>) chars_ = std::basic_string<char>(str, count);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<char>(str, count));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring and count characters.
    /// @param count The number of substring characters to copy.
    basic_string(const xtd::char16 * str, xtd::size count) {
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::char16, char_t>) chars_ = std::basic_string<xtd::char16>(str, count);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char16>(str, count));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring and count characters.
    /// @param count The number of substring characters to copy.
    basic_string(const xtd::char32 * str, xtd::size count) {
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::char32, char_t>) chars_ = std::basic_string<xtd::char32>(str, count);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char32>(str, count));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring and count characters.
    /// @param count The number of substring characters to copy.
    basic_string(const xtd::char8 * str, xtd::size count) {
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::char8, char_t>) chars_ = std::basic_string<xtd::char8>(str, count);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char8>(str, count));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring and count characters.
    /// @param count The number of substring characters to copy.
    basic_string(const xtd::wchar * str, xtd::size count) {
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::wchar, char_t>) chars_ = std::basic_string<xtd::wchar>(str, count);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::wchar>(str, count));
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
    
    /// @brief Initializes a new instance of xtd::basic_string with specified first and last iterators of substring.
    /// @param first The first iterator of substring.
    /// @param last The first iterator of substring.
    template<class input_iterator_t>
    basic_string(input_iterator_t first, input_iterator_t last) : chars_(first, last) {}
    
    /// @brief Initializes a new instance of xtd::basic_string with specified string view of substring and allocator.
    /// @param string_view The basic_string view.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    template<class string_view_like_t>
    explicit constexpr basic_string(const string_view_like_t& string_view) : chars_(string_view) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified string view of substring and allocator.
    /// @param string_view The basic_string view.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    template<class string_view_like_t>
    constexpr basic_string(const string_view_like_t& string_view, size_type index, size_type count) : chars_(string_view, index, count) {}
    
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
    const_pointer c_str() const noexcept {return chars_.c_str();}
    /// @brief Returns a reference to the underlying base type.
    /// @return Reference to the underlying base type.
    const base_type& chars() const noexcept {return chars_;}
    
    /// @brief Returns a reference to the underlying base type.
    /// @return Reference to the underlying base type.
    base_type& chars() noexcept {return chars_;}
    
    /// @brief Gets the number of characters in the current xtd::basic_string object.
    /// @return The number of characters in the current string.
    /// @remarks The xtd::basic_string::length property returns the number of xtd::basic_string::value_type objects in this instance, not the number of Unicode characters. The reason is that a Unicode character might be represented by more than one xtd::basic_string::value_type.
    virtual size_type count() const noexcept {return chars_.size();}
    
    /// @brief Returns a pointer to the underlying array serving as character storage. The pointer is such that the range [`data()`, `data() + size()`] is valid and the values in it correspond to the values stored in the string.
    /// @return A pointer to the underlying character storage.
    /// @remarks The pointer obtained from `data()` may be invalidated by:
    /// * Passing a non-const reference to the string to any standard library function, or
    /// * Calling non-const member functions on the string, excluding operator[](), at(), front(), back(), begin(), end(), rbegin(), rend().
    ///   1. Modifying the character array accessed through the const overload of data has undefined behavior.
    ///   2. Modifying the past-the-end null terminator stored at data() + size() to any value other than char_t() has undefined behavior.
    const_pointer data() const noexcept {return chars_.data();}
    
    /// @brief Checks whether the container is empty.
    /// @return `true` if container is empty; otherwise `false`.
    virtual bool empty() const noexcept {return length() == 0;}
    
    /// @brief Gets the number of characters in the current xtd::basic_string object.
    /// @return The number of characters in the current string.
    /// @remarks The xtd::basic_string::length property returns the number of xtd::basic_string::value_type objects in this instance, not the number of Unicode characters. The reason is that a Unicode character might be represented by more than one xtd::basic_string::value_type.
    virtual size_type length() const noexcept {return chars_.size();}
    
    /// @brief Gets the number of characters in the current xtd::basic_string object.
    /// @return The number of characters in the current string.
    /// @remarks The xtd::basic_string::length property returns the number of xtd::basic_string::value_type objects in this instance, not the number of Unicode characters. The reason is that a Unicode character might be represented by more than one xtd::basic_string::value_type.
    virtual size_type size() const noexcept {return chars_.size();}
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Compares two character sequences.
    /// @param str The other string to compare to.
    /// @return A 32-bit signed integer that indicates whether this instance precedes, follows, or appears in the same position in the sort order as the value parameter:
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
    /// | traits_t::compare(data1, data2, rlen) == 0 and size1 < size2  | data1 is **less than** data2    | < 0          |
    /// | traits_t::compare(data1, data2, rlen) == 0 and size1 == size2 | data1 is **equal to** data2     | 0            |
    /// | traits_t::compare(data1, data2, rlen) == 0 and size1 > size2  | data1 is **greater than** data2 | > 0          |
    /// | traits_t::compare(data1, data2, rlen) > 0                     | data1 is **greater than** data2 | > 0          |
    int32 compare(const basic_string & str) const {return chars_.compare(str);}
    /// @brief Compares two character sequences.
    /// @param pos1 The position of the first character in this string to compare.
    /// @param count1 The number of characters of this string to compare.
    /// @param str The other string to compare to.
    /// @return A 32-bit signed integer that indicates whether this instance precedes, follows, or appears in the same position in the sort order as the value parameter:
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
    /// | traits_t::compare(data1, data2, rlen) == 0 and size1 < size2  | data1 is **less than** data2    | < 0          |
    /// | traits_t::compare(data1, data2, rlen) == 0 and size1 == size2 | data1 is **equal to** data2     | 0            |
    /// | traits_t::compare(data1, data2, rlen) == 0 and size1 > size2  | data1 is **greater than** data2 | > 0          |
    /// | traits_t::compare(data1, data2, rlen) > 0                     | data1 is **greater than** data2 | > 0          |
    int32 compare(size_type pos1, size_type count1, const basic_string & str) const {return chars_.compare(pos1, count1, str);}
    /// @brief Compares two character sequences.
    /// @param pos1 The position of the first character in this string to compare.
    /// @param count1 The number of characters of this string to compare.
    /// @param str The other string to compare to.
    /// @param pos2 The position of the first character of the given string to compare.
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
    /// | traits_t::compare(data1, data2, rlen) == 0 and size1 < size2  | data1 is **less than** data2    | < 0          |
    /// | traits_t::compare(data1, data2, rlen) == 0 and size1 == size2 | data1 is **equal to** data2     | 0            |
    /// | traits_t::compare(data1, data2, rlen) == 0 and size1 > size2  | data1 is **greater than** data2 | > 0          |
    /// | traits_t::compare(data1, data2, rlen) > 0                     | data1 is **greater than** data2 | > 0          |
    int32 compare(size_type pos1, size_type count1, const basic_string & str, size_type pos2) const {return chars_.compare(pos1, count1, str, pos2);}
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
    /// | traits_t::compare(data1, data2, rlen) == 0 and size1 < size2  | data1 is **less than** data2    | < 0          |
    /// | traits_t::compare(data1, data2, rlen) == 0 and size1 == size2 | data1 is **equal to** data2     | 0            |
    /// | traits_t::compare(data1, data2, rlen) == 0 and size1 > size2  | data1 is **greater than** data2 | > 0          |
    /// | traits_t::compare(data1, data2, rlen) > 0                     | data1 is **greater than** data2 | > 0          |
    int32 compare(size_type pos1, size_type count1, const basic_string & str, size_type pos2, size_type count2) const {return chars_.compare(pos1, count1, str, pos2, count2);}
    /// @brief Compares two character sequences.
    /// @param s pointer to the character string to compare to.
    /// @return A 32-bit signed integer that indicates whether this instance precedes, follows, or appears in the same position in the sort order as the value parameter:
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
    /// | traits_t::compare(data1, data2, rlen) == 0 and size1 < size2  | data1 is **less than** data2    | < 0          |
    /// | traits_t::compare(data1, data2, rlen) == 0 and size1 == size2 | data1 is **equal to** data2     | 0            |
    /// | traits_t::compare(data1, data2, rlen) == 0 and size1 > size2  | data1 is **greater than** data2 | > 0          |
    /// | traits_t::compare(data1, data2, rlen) > 0                     | data1 is **greater than** data2 | > 0          |
    int32 compare(const_pointer s) const {return chars_.compare(s);}
    /// @brief Compares two character sequences.
    /// @param pos1 The position of the first character in this string to compare.
    /// @param count1 The number of characters of this string to compare.
    /// @param s pointer to the character string to compare to.
    /// @return A 32-bit signed integer that indicates whether this instance precedes, follows, or appears in the same position in the sort order as the value parameter:
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
    /// | traits_t::compare(data1, data2, rlen) == 0 and size1 < size2  | data1 is **less than** data2    | < 0          |
    /// | traits_t::compare(data1, data2, rlen) == 0 and size1 == size2 | data1 is **equal to** data2     | 0            |
    /// | traits_t::compare(data1, data2, rlen) == 0 and size1 > size2  | data1 is **greater than** data2 | > 0          |
    /// | traits_t::compare(data1, data2, rlen) > 0                     | data1 is **greater than** data2 | > 0          |
    int32 compare(size_type pos1, size_type count1, const_pointer s) const {return chars_.compare(pos1, count1, s);}
    /// @brief Compares two character sequences.
    /// @param pos1 The position of the first character in this string to compare.
    /// @param count1 The number of characters of this string to compare.
    /// @param s pointer to the character string to compare to.
    /// @param count2 The number of characters of the given string to compare.
    /// @return A 32-bit signed integer that indicates whether this instance precedes, follows, or appears in the same position in the sort order as the value parameter:
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
    /// | traits_t::compare(data1, data2, rlen) == 0 and size1 < size2  | data1 is **less than** data2    | < 0          |
    /// | traits_t::compare(data1, data2, rlen) == 0 and size1 == size2 | data1 is **equal to** data2     | 0            |
    /// | traits_t::compare(data1, data2, rlen) == 0 and size1 > size2  | data1 is **greater than** data2 | > 0          |
    /// | traits_t::compare(data1, data2, rlen) > 0                     | data1 is **greater than** data2 | > 0          |
    int32 compare(size_type pos1, size_type count1, const_pointer s, size_type count2) const {return chars_.compare(pos1, count1, s, count2);}
    
    /// @brief Compares this instance with a specified xtd::object and indicates whether this instance precedes, follows, or appears in the same position in the sort order as the specified xtd::object.
    /// @param value An object that evaluates to a xtd::basic_string.
    /// @return A 32-bit signed integer that indicates whether this instance precedes, follows, or appears in the same position in the sort order as the value parameter.
    /// | Value             | Condition                                                         |
    /// | ----------------- | ----------------------------------------------------------------- |
    /// | Less than zero    | This instance precedes `value`.                                   |
    /// | Zero              | This instance has the same position in the sort order as `value`. |
    /// | Greater than zero | This instance follows `value`.                                    |
    /// @exception xtd::argument_exception `value` is not a xtd::basic_string.
    int32 compare_to(const object & value) const {
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
    int32 compare_to(const basic_string & value) const noexcept override {return chars_.compare(value.chars_);}
    
    /// @brief Returns a value indicating whether a specified char occurs within this basic_string.
    /// @param value The char to seek.
    /// @return `true` if the value parameter occurs within this basic_string; otherwise, `false`.
    virtual bool contains(value_type value) const noexcept {return find(value) != npos;}
    /// @brief Returns a value indicating whether a specified substring occurs within this basic_string.
    /// @param value The basic_string to seek.
    /// @return `true` if the value parameter occurs within this basic_string, or if value is the empty basic_string (""); otherwise, `false`.
    virtual bool contains(const basic_string & value) const noexcept {return find(value) != npos;}
    
    /// @brief Determines whether this instance and a specified object, which must also be a xtd::basic_string object, have the same value.
    /// @param obj The basic_string to compare to this instance.
    /// @return `true` if `obj` is a xtd::basic_string and its value is the same as this instance; otherwise, `false`.
    bool equals(const object & obj) const noexcept override {return dynamic_cast<const basic_string*>(&obj) && equals(static_cast<const basic_string&>(obj));}
    /// @brief Determines whether this instance and another specified xtd::basic_string object have the same value.
    /// @param value The basic_string to compare to this instance.
    /// @return `true` if the `value` of the value parameter is the same as the value of this instance; otherwise, `false`.
    /// @remarks This method performs an ordinal (case-sensitive) comparison.
    bool equals(const basic_string & value) const noexcept override {return equals(value, false);}
    /// @brief Determines whether this instance and another specified xtd::basic_string object have the same value, ignoring or honoring their case.
    /// @param value The basic_string to compare to this instance.
    /// @param ignore_case `true` to ignore case when comparing this instance and value; otherwise, `false`
    /// @return `true` if the `value` of the value parameter is the same as the value of this instance; otherwise, `false`.
    /// @remarks This method performs an ordinal comparison.
    bool equals(const basic_string & value, bool ignore_case) const noexcept {
      if (ignore_case) return to_upper().chars_ == value.to_upper().chars_;
      return chars_ == value.chars_;
    }
    
    /// @brief Determines whether the end of this basic_string matches the specified character.
    /// @param value The char_t to compare to the substring at the end of this instance.
    /// @return `true` if value matches the end of this instance; otherwise, `false`.
    bool ends_with(value_type value) const noexcept {return ends_with(value, false);}
    /// @brief Determines whether the end of this basic_string matches the specified character, ignoring or honoring their case.
    /// @param value The char_t to compare to the substring at the end of this instance.
    /// @param ignore_case `true` to ignore case during the comparison; otherwise, `false`.
    /// @return `true` if value matches the end of this instance; otherwise, `false`.
    bool ends_with(value_type value, bool ignore_case) const noexcept {
      if (ignore_case) return to_lower().rfind(static_cast<value_type>(tolower(value))) == length() - 1;
      return chars_.rfind(value) == length() - 1;
    }
    /// @brief Determines whether the end of this basic_string matches the specified basic_string.
    /// @param value The basic_string to compare to the substring at the end of this instance.
    /// @return `true` if value matches the end of this instance; otherwise, `false`.
    bool ends_with(const basic_string & value) const noexcept {return ends_with(value, xtd::string_comparison::ordinal);}
    /// @brief Determines whether the end of this basic_string instance matches the specified basic_string, ignoring or honoring their case.
    /// @param value The string to compare to the substring at the end of this instance.
    /// @param ignore_case `true` to ignore case during the comparison; otherwise, `false`.
    /// @return bool `true` if value matches the end of the specified basic_string; otherwise, `false`.
    bool ends_with(const basic_string & value, bool ignore_case) const noexcept {return ends_with(value, ignore_case ? xtd::string_comparison::ordinal_ignore_case : xtd::string_comparison::ordinal);}
    /// @brief Determines whether the end of this basic_string matches the specified basic_string when compared using the specified comparison option.
    /// @param value The string to compare to the substring at the end of this instance.
    /// @param comparison_type One of the enumeration values that determines how this basic_string and value are compared.
    /// @return bool `true` if value matches the end of the specified basic_string; otherwise, `false`.
    bool ends_with(const basic_string & value, xtd::string_comparison comparison_type) const noexcept {
      if (comparison_type == xtd::string_comparison::ordinal_ignore_case) return to_lower().chars_.rfind(value.to_lower()) + value.to_lower().length() == length();
      return chars_.rfind(value) + value.length() == length();
    }
    
    /// @brief Finds the first substring equal to the given character sequence. Search begins at `0`, i.e. the found substring must not begin in a position preceding `0`.
    /// @return Position of the first character of the found substring or xtd::basic_string::npos if no such substring is found.
    /// @remarks Finds the first substring equal to `str`.
    size_type find(const basic_string & str) const {return chars_.find(str);}
    /// @brief Finds the first substring equal to the given character sequence. Search begins at `pos`, i.e. the found substring must not begin in a position preceding `pos`.
    /// @param str The string to search for.
    /// @param pos The position at which to start the search
    /// @return Position of the first character of the found substring or xtd::basic_string::npos if no such substring is found.
    /// @remarks Finds the first substring equal to `str`.
    size_type find(const basic_string & str, size_type pos) const {return chars_.find(str, pos);}
    /// @brief Finds the first substring equal to the given character sequence. Search begins at `pos`, i.e. the found substring must not begin in a position preceding `pos`.
    /// @param str The string to search for.
    /// @param pos The position at which to start the search
    /// @param count The length of substring to search for.
    /// @return Position of the first character of the found substring or xtd::basic_string::npos if no such substring is found.
    /// @remarks Finds the first substring equal to the range [s, s + count).
    /// @remarks This range may contain null characters. If [`s`, `s + count`) is not a valid range, the behavior is undefined.
    size_type find(const_pointer s, size_type pos, size_type count) const {return chars_.find(s, pos, count);}
    /// @brief Finds the first substring equal to the given character sequence. Search begins at `0`, i.e. the found substring must not begin in a position preceding `0`.
    /// @param s The pointer to a character string to search for.
    /// @return Position of the first character of the found substring or xtd::basic_string::npos if no such substring is found.
    /// @remarks Finds the first substring equal to the character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
    /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
    size_type find(const_pointer s) const {return chars_.find(s);}
    /// @brief Finds the first substring equal to the given character sequence. Search begins at `pos`, i.e. the found substring must not begin in a position preceding `pos`.
    /// @param s The pointer to a character string to search for.
    /// @param pos The position at which to start the search
    /// @return Position of the first character of the found substring or xtd::basic_string::npos if no such substring is found.
    /// @remarks Finds the first substring equal to the character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
    /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
    size_type find(const_pointer s, size_type pos) const {return chars_.find(s, pos);}
    /// @brief Finds the first substring equal to the given character sequence. Search begins at `0`, i.e. the found substring must not begin in a position preceding `0`.
    /// @param ch The character to search for.
    /// @return Position of the first character of the found substring or xtd::basic_string::npos if no such substring is found.
    /// @remarks Finds the first character `ch` (treated as a single-character substring by the formal rules below).
    size_type find(value_type ch) const {return chars_.find(ch);}
    /// @brief Finds the first substring equal to the given character sequence. Search begins at `pos`, i.e. the found substring must not begin in a position preceding `pos`.
    /// @param ch The character to search for.
    /// @param pos The position at which to start the search
    /// @return Position of the first character of the found substring or xtd::basic_string::npos if no such substring is found.
    /// @remarks Finds the first character `ch` (treated as a single-character substring by the formal rules below).
    size_type find(value_type ch, size_type pos) const {return chars_.find(ch, pos);}
    
    /// @brief Finds the first character equal to one of the characters in the given character sequence. The search considers only the range [`pos`, size()). If none of the characters in the given character sequence is present in the range, xtd::basic_string::npos will be returned.
    /// @parzm str The string identifying characters to search for.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in `str`.
    size_type find_first_of(const basic_string & str) const {return chars_.find_first_of(str);}
    /// @brief Finds the first character equal to one of the characters in the given character sequence. The search considers only the range [`pos`, size()). If none of the characters in the given character sequence is present in the range, xtd::basic_string::npos will be returned.
    /// @param str The string identifying characters to search for.
    /// @param pos The position at which to begin searching.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in `str`.
    size_type find_first_of(const basic_string & str, size_type pos) const {return chars_.find_first_of(str, pos);}
    /// @brief Finds the first character equal to one of the characters in the given character sequence. The search considers only the range [`pos`, size()). If none of the characters in the given character sequence is present in the range, xtd::basic_string::npos will be returned.
    /// @param s The pointer to a character string identifying characters to search for.
    /// @param pos The position at which to begin searching.
    /// @param count The length of character string identifying characters to search for.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in the range [`s`, `s + count`). This range can include null characters.
    /// @remarks If [`s`, `s + count`) is not a valid range, the behavior is undefined.
    size_type find_first_of(const_pointer s, size_type pos, size_type count) const {return chars_.find_first_of(s, pos, count);}
    /// @brief Finds the first character equal to one of the characters in the given character sequence. The search considers only the range [`pos`, size()). If none of the characters in the given character sequence is present in the range, xtd::basic_string::npos will be returned.
    /// @param s The pointer to a character string identifying characters to search for.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
    /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
    size_type find_first_of(const_pointer s) const {return chars_.find_first_of(s);}
    /// @brief Finds the first character equal to one of the characters in the given character sequence. The search considers only the range [`pos`, size()). If none of the characters in the given character sequence is present in the range, xtd::basic_string::npos will be returned.
    /// @param s The pointer to a character string identifying characters to search for.
    /// @param pos The position at which to begin searching.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
    /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
    size_type find_first_of(const_pointer s, size_type pos) const {return chars_.find_first_of(s, pos);}
    /// @brief Finds the first character equal to one of the characters in the given character sequence. The search considers only the range [`pos`, size()). If none of the characters in the given character sequence is present in the range, xtd::basic_string::npos will be returned.
    /// @param ch The character to search for.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to `ch`.
    size_type find_first_of(char_t ch) const {return chars_.find_first_of(ch);}
    /// @brief Finds the first character equal to one of the characters in the given character sequence. The search considers only the range [`pos`, size()). If none of the characters in the given character sequence is present in the range, xtd::basic_string::npos will be returned.
    /// @param ch The character to search for.
    /// @param pos The position at which to begin searching.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to `ch`.
    size_type find_first_of(char_t ch, size_type pos) const {return chars_.find_first_of(ch, pos);}
    
    /// @brief Finds the first character equal to none of the characters in the given character sequence. The search considers only the range [`pos`, size()). If all characters in the range can be found in the given character sequence, xtd::basic_string::npos will be returned.
    /// @parzm str The string identifying characters to search for.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in `str`.
    size_type find_first_not_of(const basic_string & str) const {return chars_.find_first_not_of(str);}
    /// @brief Finds the first character equal to none of the characters in the given character sequence. The search considers only the range [`pos`, size()). If all characters in the range can be found in the given character sequence, xtd::basic_string::npos will be returned.
    /// @param str The string identifying characters to search for.
    /// @param pos The position at which to begin searching.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in `str`.
    size_type find_first_not_of(const basic_string & str, size_type pos) const {return chars_.find_first_not_of(str, pos);}
    /// @brief Finds the first character equal to none of the characters in the given character sequence. The search considers only the range [`pos`, size()). If all characters in the range can be found in the given character sequence, xtd::basic_string::npos will be returned.
    /// @param s The pointer to a character string identifying characters to search for.
    /// @param pos The position at which to begin searching.
    /// @param count The length of character string identifying characters to search for.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in the range [`s`, `s + count`). This range can include null characters.
    /// @remarks If [`s`, `s + count`) is not a valid range, the behavior is undefined.
    size_type find_first_not_of(const_pointer s, size_type pos, size_type count) const {return chars_.find_first_not_of(s, pos, count);}
    /// @brief Finds the first character equal to none of the characters in the given character sequence. The search considers only the range [`pos`, size()). If all characters in the range can be found in the given character sequence, xtd::basic_string::npos will be returned.
    /// @param s The pointer to a character string identifying characters to search for.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
    /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
    size_type find_first_not_of(const_pointer s) const {return chars_.find_first_not_of(s);}
    /// @brief Finds the first character equal to none of the characters in the given character sequence. The search considers only the range [`pos`, size()). If all characters in the range can be found in the given character sequence, xtd::basic_string::npos will be returned.
    /// @param s The pointer to a character string identifying characters to search for.
    /// @param pos The position at which to begin searching.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
    /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
    size_type find_first_not_of(const_pointer s, size_type pos) const {return chars_.find_first_not_of(s, pos);}
    /// @brief Finds the first character equal to none of the characters in the given character sequence. The search considers only the range [`pos`, size()). If all characters in the range can be found in the given character sequence, xtd::basic_string::npos will be returned.
    /// @param ch The character to search for.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to `ch`.
    size_type find_first_not_of(char_t ch) const {return chars_.find_first_not_of(ch);}
    /// @brief Finds the first character equal to none of the characters in the given character sequence. The search considers only the range [`pos`, size()). If all characters in the range can be found in the given character sequence, xtd::basic_string::npos will be returned.
    /// @param ch The character to search for.
    /// @param pos The position at which to begin searching.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to `ch`.
    size_type find_first_not_of(char_t ch, size_type pos) const {return chars_.find_first_not_of(ch, pos);}
    
    /// @brief Finds the last character equal to one of characters in the given character sequence. The exact search algorithm is not specified. The search considers only the range [​`0`​, `pos`]. If none of the characters in the given character sequence is present in the range, xtd::basic_string::npos will be returned.
    /// @parzm str The string identifying characters to search for.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in `str`.
    size_type find_last_of(const basic_string & str) const {return chars_.find_last_of(str);}
    /// @brief Finds the last character equal to one of characters in the given character sequence. The exact search algorithm is not specified. The search considers only the range [​`0`​, `pos`]. If none of the characters in the given character sequence is present in the range, xtd::basic_string::npos will be returned.
    /// @param str The string identifying characters to search for.
    /// @param pos The position at which to begin searching.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in `str`.
    size_type find_last_of(const basic_string & str, size_type pos) const {return chars_.find_last_of(str, pos);}
    /// @brief Finds the last character equal to one of characters in the given character sequence. The exact search algorithm is not specified. The search considers only the range [​`0`​, `pos`]. If none of the characters in the given character sequence is present in the range, xtd::basic_string::npos will be returned.
    /// @param s The pointer to a character string identifying characters to search for.
    /// @param pos The position at which to begin searching.
    /// @param count The length of character string identifying characters to search for.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in the range [`s`, `s + count`). This range can include null characters.
    /// @remarks If [`s`, `s + count`) is not a valid range, the behavior is undefined.
    size_type find_last_of(const_pointer s, size_type pos, size_type count) const {return chars_.find_last_of(s, pos, count);}
    /// @brief Finds the last character equal to one of characters in the given character sequence. The exact search algorithm is not specified. The search considers only the range [​`0`​, `pos`]. If none of the characters in the given character sequence is present in the range, xtd::basic_string::npos will be returned.
    /// @param s The pointer to a character string identifying characters to search for.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
    /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
    size_type find_last_of(const_pointer s) const {return chars_.find_last_of(s);}
    /// @brief Finds the last character equal to one of characters in the given character sequence. The exact search algorithm is not specified. The search considers only the range [​`0`​, `pos`]. If none of the characters in the given character sequence is present in the range, xtd::basic_string::npos will be returned.
    /// @param s The pointer to a character string identifying characters to search for.
    /// @param pos The position at which to begin searching.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
    /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
    size_type find_last_of(const_pointer s, size_type pos) const {return chars_.find_last_of(s, pos);}
    /// @brief Finds the last character equal to one of characters in the given character sequence. The exact search algorithm is not specified. The search considers only the range [​`0`​, `pos`]. If none of the characters in the given character sequence is present in the range, xtd::basic_string::npos will be returned.
    /// @param ch The character to search for.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to `ch`.
    size_type find_last_of(char_t ch) const {return chars_.find_last_of(ch);}
    /// @brief Finds the last character equal to one of characters in the given character sequence. The exact search algorithm is not specified. The search considers only the range [​`0`​, `pos`]. If none of the characters in the given character sequence is present in the range, xtd::basic_string::npos will be returned.
    /// @param ch The character to search for.
    /// @param pos The position at which to begin searching.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to `ch`.
    size_type find_last_of(char_t ch, size_type pos) const {return chars_.find_last_of(ch, pos);}
    
    /// @brief Finds the last character equal to none of the characters in the given character sequence. The search considers only the range [​`0`​, `pos`]. If all characters in the range can be found in the given character sequence,xtd::basic_string::npos will be returned.
    /// @parzm str The string identifying characters to search for.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in `str`.
    size_type find_last_not_of(const basic_string & str) const {return chars_.find_last_not_of(str);}
    /// @brief Finds the last character equal to none of the characters in the given character sequence. The search considers only the range [​`0`​, `pos`]. If all characters in the range can be found in the given character sequence,xtd::basic_string::npos will be returned.
    /// @param str The string identifying characters to search for.
    /// @param pos The position at which to begin searching.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in `str`.
    size_type find_last_not_of(const basic_string & str, size_type pos) const {return chars_.find_last_not_of(str, pos);}
    /// @brief Finds the last character equal to none of the characters in the given character sequence. The search considers only the range [​`0`​, `pos`]. If all characters in the range can be found in the given character sequence,xtd::basic_string::npos will be returned.
    /// @param s The pointer to a character string identifying characters to search for.
    /// @param pos The position at which to begin searching.
    /// @param count The length of character string identifying characters to search for.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in the range [`s`, `s + count`). This range can include null characters.
    /// @remarks If [`s`, `s + count`) is not a valid range, the behavior is undefined.
    size_type find_last_not_of(const_pointer s, size_type pos, size_type count) const {return chars_.find_last_not_of(s, pos, count);}
    /// @brief Finds the last character equal to none of the characters in the given character sequence. The search considers only the range [​`0`​, `pos`]. If all characters in the range can be found in the given character sequence,xtd::basic_string::npos will be returned.
    /// @param s The pointer to a character string identifying characters to search for.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
    /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
    size_type find_last_not_of(const_pointer s) const {return chars_.find_last_not_of(s);}
    /// @brief Finds the last character equal to none of the characters in the given character sequence. The search considers only the range [​`0`​, `pos`]. If all characters in the range can be found in the given character sequence,xtd::basic_string::npos will be returned.
    /// @param s The pointer to a character string identifying characters to search for.
    /// @param pos The position at which to begin searching.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
    /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
    size_type find_last_not_of(const_pointer s, size_type pos) const {return chars_.find_last_not_of(s, pos);}
    /// @brief Finds the last character equal to none of the characters in the given character sequence. The search considers only the range [​`0`​, `pos`]. If all characters in the range can be found in the given character sequence,xtd::basic_string::npos will be returned.
    /// @param ch The character to search for.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to `ch`.
    size_type find_last_not_of(char_t ch) const {return chars_.find_last_not_of(ch);}
    /// @brief Finds the last character equal to none of the characters in the given character sequence. The search considers only the range [​`0`​, `pos`]. If all characters in the range can be found in the given character sequence,xtd::basic_string::npos will be returned.
    /// @param ch The character to search for.
    /// @param pos The position at which to begin searching.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to `ch`.
    size_type find_last_not_of(char_t ch, size_type pos) const {return chars_.find_last_not_of(ch, pos);}
    
    /// @brief Returns the allocator associated with the string.
    /// @return The associated allocator.
    allocator_type get_allocator() const {return chars_.get_allocator();}
    
    /// @brief Returns the underlying base type.
    /// @return The underlying base type.
    virtual const base_type& get_base_type() const noexcept {return chars_;}
    
    /// @brief Returns the hash code for this basic_string.
    /// @return A hash code.
    xtd::size get_hash_code() const noexcept override {return xtd::hash_code::combine(chars_);}
    
    enumerator_type get_enumerator() const noexcept override {
      struct basic_string_enumerator : public xtd::collections::generic::ienumerator<value_type> {
        explicit basic_string_enumerator(const basic_string & chars) : chars_(chars) {}
        const value_type& current() const override {
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
    xtd::size index_of(const basic_string & value) const noexcept {return index_of(value, 0, length());}
    /// @brief Reports the index of the first occurrence of the specified character in this basic_string. The search starts at a specified character position.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    xtd::size index_of(const basic_string & value, xtd::size start_index) const {return index_of(value, start_index, length() - start_index);}
    /// @brief Reports the index of the first occurrence of the specified character in this basic_string. The search starts at a specified character position and examines a specified number of character positions.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    /// @exception xtd::index_out_of_range_exception start_index + count are greater than the length of this instance.
    xtd::size index_of(const basic_string & value, xtd::size start_index, xtd::size count) const {
      if (start_index > length() || start_index + count > length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      auto result = find(value, start_index);
      return result > start_index + count ? npos : result;
    }
    /// @brief Reports the index of the first occurrence of the specified character in this basic_string.
    /// @param value An unicode character to seek
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    xtd::size index_of(value_type value) const noexcept {return index_of(value, 0, length());}
    /// @brief Reports the index of the first occurrence of the specified character in this basic_string. The search starts at a specified character position.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    xtd::size index_of(value_type value, xtd::size start_index) const {return index_of(value, start_index, length() - start_index);}
    /// @brief Reports the index of the first occurrence of the specified character in this basic_string. The search starts at a specified character position and examines a specified number of character positions.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    /// @exception xtd::index_out_of_range_exception start_index + count are greater than the length of this instance.
    xtd::size index_of(value_type value, xtd::size start_index, xtd::size count) const {
      if (start_index > length() || start_index + count > length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      auto result = find(value, start_index);
      return result > start_index + count ? npos : result;
    }
    
    /// @brief Reports the index of the first occurrence in this instance of any character in a specified array of characters.
    /// @param values An unicode character array containing one or more characters to seek
    /// @return The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<char_t>::npos if no character in values was found.
    xtd::size index_of_any(const xtd::array<value_type>& values) const noexcept;
    /// @brief Reports the index of the first occurrence in this instance of any character in a specified array of characters. The search starts at a specified character position.
    /// @param values An unicode character array containing one or more characters to seek
    /// @param start_index The search starting position
    /// @return The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<char_t>::npos if no character in values was found.
    /// @exception xtd::index_out_of_range_exception start_index + count are greater than the length of this instance.
    xtd::size index_of_any(const xtd::array<value_type>& values, xtd::size start_index) const;
    /// @brief Reports the index of the first occurrence in this instance of any character in a specified array of characters. The search starts at a specified character position.
    /// @param values An unicode character array containing one or more characters to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine.
    /// @return The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<char_t>::npos if no character in values was found.
    /// @exception xtd::index_out_of_range_exception start_index + count are greater than the length of this instance.
    xtd::size index_of_any(const xtd::array<value_type>& values, xtd::size start_index, xtd::size count) const;
    /// @cond
    xtd::size index_of_any(const std::initializer_list<value_type>& values) const noexcept;
    xtd::size index_of_any(const std::initializer_list<value_type>& values, xtd::size start_index) const;
    xtd::size index_of_any(const std::initializer_list<value_type>& values, xtd::size start_index, xtd::size count) const;
    /// @endcond
    
    /// @brief Inserts a specified instance of basic_string at a specified index position in this instance.
    /// @param start_index The index position of the insertion.
    /// @param value The basic_string to insert.
    /// @return A new basic_string equivalent to this instance but with value inserted at position start_index.
    /// @remarks If start_index is equal to the length of this instance, value is appended to the end of this instance.
    /// @remarks For example, the return value of "abc".Insert(2, "XYZ") is "abXYZc".
    basic_string insert(xtd::size start_index, const basic_string & value) const {
      if (start_index > length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      auto result = self_;
      result.chars_.insert(start_index, value);
      return result;
    }
    
    /// @brief Reports the index of the last occurrence of the specified basic_string in this basic_string.
    /// @param value An unicode character to seek
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    xtd::size last_index_of(const basic_string & value) const noexcept {return last_index_of(value, 0, length());}
    /// @brief Reports the index of the last occurrence of the specified character in this basic_string. The search starts at a specified character position.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    /// @exception xtd::index_out_of_range_exception start_index + count are greater than the length of this instance.
    xtd::size last_index_of(const basic_string & value, xtd::size start_index) const {return last_index_of(value, start_index, length() - start_index);}
    /// @brief Reports the index of the last occurrence of the specified character in this basic_string. The search starts at a specified character position and examines a specified number of character positions.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    /// @exception xtd::index_out_of_range_exception start_index + count are greater than the length of this instance.
    xtd::size last_index_of(const basic_string & value, xtd::size start_index, xtd::size count) const {
      if (start_index > length() || start_index + count > length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      auto result = chars_.rfind(value, start_index + count - value.length());
      return result < start_index ? npos : result;
    }
    /// @brief Reports the index of the last occurrence of the specified character in this tring.
    /// @param value An unicode character to seek
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    xtd::size last_index_of(value_type value) const noexcept {return last_index_of(value, 0, length());}
    /// @brief Reports the index of the last occurrence of the specified character in this basic_string. The search starts at a specified character position.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    /// @exception xtd::index_out_of_range_exception start_index + count are greater than the length of this instance.
    xtd::size last_index_of(value_type value, xtd::size start_index) const {return last_index_of(value, start_index, length() - start_index);}
    /// @brief Reports the index of the last occurrence of the specified character in this basic_string. The search starts at a specified character position and examines a specified number of character positions.
    /// @param str A basic_string to find last index of.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    /// @exception xtd::index_out_of_range_exception start_index + count are greater than the length of this instance.
    xtd::size last_index_of(value_type value, xtd::size start_index, xtd::size count) const {
      if (start_index > length() || start_index + count > length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      auto result = chars_.rfind(value, start_index + count - 1);
      return result < start_index ? npos : result;
    }
    
    /// @brief Reports the index of the last occurrence in this instance of any character in a specified array of characters.
    /// @param values An unicode character array containing one or more characters to seek
    /// @return The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<char_t>::npos if no character in values was found.
    xtd::size last_index_of_any(const xtd::array<value_type>& values) const noexcept;
    /// @brief Reports the index of the last occurrence in this instance of any character in a specified array of characters. The search starts at a specified character position.
    /// @param values An unicode character array containing one or more characters to seek
    /// @param start_index The search starting position
    /// @return The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<char_t>::npos if no character in values was found.
    xtd::size last_index_of_any(const xtd::array<value_type>& values, xtd::size start_index) const;
    /// @brief Reports the index of the last occurrence in this instance of any character in a specified array of characters. The search starts at a specified character position.
    /// @param values An unicode character array containing one or more characters to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine.
    /// @return The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<char_t>::npos if no character in values was found.
    xtd::size last_index_of_any(const xtd::array<value_type>& values, xtd::size start_index, xtd::size count) const;
    /// @cond
    xtd::size last_index_of_any(const std::initializer_list<value_type>& values) const noexcept;
    xtd::size last_index_of_any(const std::initializer_list<value_type>& values, xtd::size start_index) const;
    xtd::size last_index_of_any(const std::initializer_list<value_type>& values, xtd::size start_index, xtd::size count) const;
    /// @endcond
    
    /// @brief Right-aligns the characters in this basic_string, padding with spaces on the left for a specified total length.
    /// @param total_width The number of characters in the resulting basic_string, equal to the number of original characters plus any additional padding characters.
    /// @return A new basic_string that is equivalent to the specified basic_string, but right-aligned and padded on the left with as many spaces as needed to create a length of total_width. Or, if total_width is less than the length of the specified basic_string, a new basic_string object that is identical to the specified basic_string.
    /// @remarks An unicode space is defined as hexadecimal 0x20.
    /// @remarks The pad_left(const std::basic_string<char_t>&, int) method pads the beginning of the returned basic_string. This means that, when used with right-to-left languages, it pads the right portion of the basic_string..
    basic_string pad_left(xtd::size total_width) const noexcept {return pad_left(total_width, ' ');}
    /// @brief Right-aligns the characters in this basic_string, padding with spaces on the left for a specified total length.
    /// @param total_width The number of characters in the resulting basic_string, equal to the number of original characters plus any additional padding characters.
    /// @param paddingChar An unicode padding character.
    /// @return A new basic_string that is equivalent to the specified basic_string, but right-aligned and padded on the left with as many spaces as needed to create a length of total_width. Or, if total_width is less than the length of the specified basic_string, a new basic_string object that is identical the specified basic_string.
    /// @remarks An unicode space is defined as hexadecimal 0x20.
    /// @remarks The pad_left(const std::basic_string<char_t>&, int) method pads the beginning of the returned basic_string. This means that, when used with right-to-left languages, it pads the right portion of the basic_string..
    basic_string pad_left(xtd::size total_width, char32 padding_char) const noexcept {return total_width < length() ? self_ : basic_string(padding_char, total_width - length()) + self_;}
    
    /// @brief Left-aligns the characters in this basic_string, padding with spaces on the right for a specified total length.
    /// @param totalWidth The number of characters in the resulting basic_string, equal to the number of original characters plus any additional padding characters.
    /// @return A new basic_string that is equivalent to the specified basic_string, but left-aligned and padded on the right with as many spaces as needed to create a length of totalWidth. Or, if totalWidth is less than the length of the specified basic_string, a new basic_string object that is identical to the specified basic_string.
    /// @remarks An unicode space is defined as hexadecimal 0x20.
    /// @remarks The PadRight(const std::basic_string<char_t>&, int) method pads the end of the returned basic_string. This means that, when used with right-to-left languages, it pads the left portion of the basic_string..
    basic_string pad_right(xtd::size total_width) const noexcept {return pad_right(total_width, ' ');}
    /// @brief Left-aligns the characters in this basic_string, padding with spaces on the right for a specified total length.
    /// @param totalWidth The number of characters in the resulting basic_string, equal to the number of original characters plus any additional padding characters.
    /// @param paddingChar An unicode padding character.
    /// @return A new basic_string that is equivalent to the specified basic_string, but left-aligned and padded on the tight with as many spaces as needed to create a length of totalWidth. Or, if totalWidth is less than the length of the specified basic_string, a new basic_string object that is identical to the specified basic_string.
    /// @remarks An unicode space is defined as hexadecimal 0x20.
    /// @remarks The xtd::basic_string::pad_right method pads the end of the returned basic_string. This means that, when used with right-to-left languages, it pads the left portion of the basic_string..
    basic_string pad_right(xtd::size total_width, char32 padding_char) const noexcept {return total_width < length() ? self_ : self_ + basic_string(padding_char, total_width - length());}
    
    /// @brief Allows insertion and extraction of quoted strings, such as the ones found in [CSV](https://en.wikipedia.org/wiki/Comma-separated_values) or [XML](https://en.wikipedia.org/wiki/XML).
    /// @return A new quoted basic_string.
    /// @remarks the delimiter is set to @verbatim " @endverbatim by default and the escape is set to `\` by  default.
    /// @remarks for more information see [std::quoted](https://en.cppreference.com/w/cpp/io/manip/quoted).
    basic_string quoted() const {return quoted('"', '\\');}
    /// @brief Allows insertion and extraction of quoted strings, such as the ones found in [CSV](https://en.wikipedia.org/wiki/Comma-separated_values) or [XML](https://en.wikipedia.org/wiki/XML) ith specified delimiter.
    /// @param delimiter The character to use as the delimiter, defaults to `"`.
    /// @return A new quoted basic_string.
    /// @remarks for more information see [std::quoted](https://en.cppreference.com/w/cpp/io/manip/quoted).
    basic_string quoted(value_type delimiter) const {return quoted(delimiter, '\\');}
    /// @brief Allows insertion and extraction of quoted strings, such as the ones found in [CSV](https://en.wikipedia.org/wiki/Comma-separated_values) or [XML](https://en.wikipedia.org/wiki/XML) ith specified delimiter and escape.
    /// @param delimiter The character to use as the delimiter, defaults to `"`.
    /// @param escape The character to use as the escape character, defaults to `\`.
    /// @return A new quoted basic_string.
    /// @remarks for more information see [std::quoted](https://en.cppreference.com/w/cpp/io/manip/quoted).
    basic_string quoted(value_type delimiter, value_type escape) const {
      std::wstringstream ss;
      if constexpr(std::is_same_v<xtd::wchar, value_type>) ss << std::quoted(chars_, delimiter, escape);
      else ss << std::quoted(__xtd_convert_to_string<xtd::wchar>(chars_), static_cast<xtd::wchar>(delimiter), static_cast<xtd::wchar>(escape));
      return ss.str();
    }
    
    /// @brief Deletes all the characters from this basic_string beginning at a specified position and continuing through the last position.
    /// @param start_index The position to begin deleting characters.
    /// @return A new basic_string object that is equivalent to this basic_string less the removed characters.
    basic_string remove(xtd::size start_index) const {return remove(start_index, length() - start_index);}
    /// @brief Deletes all the characters from this basic_string beginning at a specified position and continuing through the last position.
    /// @param start_index The position to begin deleting characters.
    /// @param count The number of characters to delete.
    /// @return A new basic_string object that is equivalent to this basic_string less the removed characters.
    basic_string remove(xtd::size start_index, xtd::size count) const {
      if (start_index > length() || start_index + count > length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      auto result = self_;
      result.chars_.erase(start_index, count);
      return result;
    }
    
    /// @brief Replaces all occurrences of a specified char_t in this basic_string with another specified char_t.
    /// @param old_char A char_t to be replaced.
    /// @param new_char A char_t to replace all occurrences of old_char.
    /// @return A new basic_string equivalent to the specified basic_string but with all instances of old_char replaced with new_char.
    basic_string replace(value_type old_char, value_type new_char) const noexcept {return replace(string(old_char, 1), string(new_char, 1));}
    /// @brief Replaces all occurrences of a specified basic_string in this basic_string with another specified basic_string.
    /// @param old_string A basic_string to be replaced.
    /// @param new_string A basic_string to replace all occurrences of old_string.
    /// @return A new basic_string equivalent to the specified basic_string but with all instances of old_string replaced with new_string.
    /// @remarks If new_string is empty, all occurrences of old_string are removed
    basic_string replace(const basic_string & old_string, const basic_string & new_string) const noexcept {
      auto result = self_;
      auto old_size = old_string.length();
      auto new_size = new_string.length();
      auto index = xtd::size {0};
      while (true) {
        index = result.find(old_string, index);
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
    
    /// @brief Finds the last substring that is equal to the given character sequence. The search begins at `xtd::basic_string::npos` and proceeds from right to left (thus, the found substring, if any, cannot begin in a position following xtd::basic_string::npos). If xtd::basic_string::npos or any value not smaller than xtd::basic_string::size() - 1 is passed as xtd::basic_string::npos, the whole string will be searched.
    /// @return Position of the first character of the found substring or xtd::basic_string::npos if no such substring is found.
    /// @remarks Finds the first substring equal to `str`.
    size_type rfind(const basic_string & str) const {return chars_.rfind(str);}
    /// @brief Finds the last substring that is equal to the given character sequence. The search begins at `pos` and proceeds from right to left (thus, the found substring, if any, cannot begin in a position following `pos`). If xtd::basic_string::npos or any value not smaller than xtd::basic_string::size() - 1 is passed as `pos`, the whole string will be searched.
    /// @param str The string to search for.
    /// @param pos The position at which to start the search
    /// @return Position of the first character of the found substring or xtd::basic_string::npos if no such substring is found.
    /// @remarks Finds the first substring equal to `str`.
    size_type rfind(const basic_string & str, size_type pos) const {return chars_.rfind(str, pos);}
    /// @brief Finds the last substring that is equal to the given character sequence. The search begins at `pos` and proceeds from right to left (thus, the found substring, if any, cannot begin in a position following `pos`). If xtd::basic_string::npos or any value not smaller than xtd::basic_string::size() - 1 is passed as `pos`, the whole string will be searched.
    /// @param str The string to search for.
    /// @param pos The position at which to start the search
    /// @param count The length of substring to search for.
    /// @return Position of the first character of the found substring or xtd::basic_string::npos if no such substring is found.
    /// @remarks Finds the first substring equal to the range [s, s + count).
    /// @remarks This range may contain null characters. If [`s`, `s + count`) is not a valid range, the behavior is undefined.
    size_type rfind(const_pointer s, size_type pos, size_type count) const {return chars_.rfind(s, pos, count);}
    /// @brief Finds the last substring that is equal to the given character sequence. The search begins at `xtd::basic_string::npos` and proceeds from right to left (thus, the found substring, if any, cannot begin in a position following xtd::basic_string::npos). If xtd::basic_string::npos or any value not smaller than xtd::basic_string::size() - 1 is passed as xtd::basic_string::npos, the whole string will be searched.
    /// @param s The pointer to a character string to search for.
    /// @return Position of the first character of the found substring or xtd::basic_string::npos if no such substring is found.
    /// @remarks Finds the first substring equal to the character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
    /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
    size_type rfind(const_pointer s) const {return chars_.rfind(s);}
    /// @brief Finds the last substring that is equal to the given character sequence. The search begins at `pos` and proceeds from right to left (thus, the found substring, if any, cannot begin in a position following `pos`). If xtd::basic_string::npos or any value not smaller than xtd::basic_string::size() - 1 is passed as `pos`, the whole string will be searched.
    /// @param s The pointer to a character string to search for.
    /// @param pos The position at which to start the search
    /// @return Position of the first character of the found substring or xtd::basic_string::npos if no such substring is found.
    /// @remarks Finds the first substring equal to the character string pointed to by `s`. The length of the string is determined by the first null character using `traits_t::length(s)`.
    /// @remarks If [`s`, `s + traits_t::length(s)`) is not a valid range, the behavior is undefined.
    size_type rfind(const_pointer s, size_type pos) const {return chars_.rfind(s, pos);}
    /// @brief Finds the last substring that is equal to the given character sequence. The search begins at `xtd::basic_string::npos` and proceeds from right to left (thus, the found substring, if any, cannot begin in a position following xtd::basic_string::npos). If xtd::basic_string::npos or any value not smaller than xtd::basic_string::size() - 1 is passed as xtd::basic_string::npos, the whole string will be searched.
    /// @param ch The character to search for.
    /// @return Position of the first character of the found substring or xtd::basic_string::npos if no such substring is found.
    /// @remarks Finds the first character `ch` (treated as a single-character substring by the formal rules below).
    size_type rfind(value_type ch) const {return chars_.rfind(ch);}
    /// @brief Finds the last substring that is equal to the given character sequence. The search begins at `pos` and proceeds from right to left (thus, the found substring, if any, cannot begin in a position following `pos`). If xtd::basic_string::npos or any value not smaller than xtd::basic_string::size() - 1 is passed as `pos`, the whole string will be searched.
    /// @param ch The character to search for.
    /// @param pos The position at which to start the search
    /// @return Position of the first character of the found substring or xtd::basic_string::npos if no such substring is found.
    /// @remarks Finds the first character `ch` (treated as a single-character substring by the formal rules below).
    size_type rfind(value_type ch, size_type pos) const {return chars_.rfind(ch, pos);}
    
    /// @brief Splits this basic_string into substrings that are based on the default white-space characters. White-space characters are defined by the c++ standard and return `true` if they are passed to the xtd::char_object::isspace() or std::iswspace() method.
    /// @return An array whose elements contain the substrings in this basic_string that are delimited by one or more characters in white-space separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    xtd::array<basic_string> split() const noexcept;
    /// @brief Splits this basic_string into substrings that are based on the characters in an array.
    /// @param separator A character that delimits the substrings in this basic_string.
    /// @return An array whose elements contain the substrings in this basic_string that are delimited by one or more characters in separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    xtd::array<basic_string> split(value_type separator) const noexcept;
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
    xtd::array<basic_string> split(value_type separator, xtd::string_split_options options) const noexcept;
    /// @brief Splits this basic_string into a maximum number of substrings based on the characters in an array. You also specify the maximum number of substrings to return.
    /// @param separator A character array that delimits the substrings in this basic_string, an empty array that contains no delimiters.
    /// @param count The maximum number of substrings to return.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    /// @remarks If the separator parameter contains no characters, white-space characters are assumed to be the delimiters. White-space characters are defined by the Unicode standard and return `true` if they are passed to the char_t.IsWhiteSpace method.
    /// @remarks Each element of separator defines a separate delimiter character. If two delimiters are adjacent, or a delimiter is found at the beginning or end of the specified basic_string, the corresponding array element contains empty basic_string.
    /// @remarks If there are more than count substrings in the specified basic_string, the first count minus 1 substrings are returned in the first count minus 1 elements of the return value, and the remaining characters in the specified basic_string are returned in the last element of the return value.
    xtd::array<basic_string> split(value_type separator, xtd::size count) const noexcept;
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
    xtd::array<basic_string> split(value_type separator, xtd::size count, xtd::string_split_options options) const noexcept;
    /// @brief Splits this basic_string into substrings that are based on the characters in an array.
    /// @param separators A character array that delimits the substrings in this basic_string, an empty array that contains no delimiters.
    /// @return An array whose elements contain the substrings in this basic_string that are delimited by one or more characters in separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    xtd::array<basic_string> split(const xtd::array<value_type>& separators) const noexcept;
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
    xtd::array<basic_string> split(const xtd::array<value_type>& separators, xtd::string_split_options options) const noexcept;
    /// @brief Splits this basic_string into a maximum number of substrings based on the characters in an array. You also specify the maximum number of substrings to return.
    /// @param separators A character array that delimits the substrings in this basic_string, an empty array that contains no delimiters.
    /// @param count The maximum number of substrings to return.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    /// @remarks If the separator parameter contains no characters, white-space characters are assumed to be the delimiters. White-space characters are defined by the Unicode standard and return `true` if they are passed to the char_t.IsWhiteSpace method.
    /// @remarks Each element of separator defines a separate delimiter character. If two delimiters are adjacent, or a delimiter is found at the beginning or end of the specified basic_string, the corresponding array element contains empty basic_string.
    /// @remarks If there are more than count substrings in the specified basic_string, the first count minus 1 substrings are returned in the first count minus 1 elements of the return value, and the remaining characters in the specified basic_string are returned in the last element of the return value.
    xtd::array<basic_string> split(const xtd::array<value_type>& separators, xtd::size count) const noexcept;
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
    xtd::array<basic_string> split(const xtd::array<value_type>& separators, xtd::size count, xtd::string_split_options options) const noexcept;
    
    /// @brief Determines whether the beginning of this instance of xtd::basic_string matches a specified xtd::basic_string.
    /// @param value A xtd::basic_string to compare to.
    /// @return bool `true` if value matches the beginning of the specified basic_string; otherwise, `false`.
    /// @remarks This method compares value to the substring at the beginning of the specified basic_string that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the beginning of the specified basic_string.
    bool starts_with(value_type value) const noexcept {return starts_with(value, false);}
    /// @brief Determines whether the beginning of this instance of xtd::basic_string matches a specified xtd::basic_string, ignoring or honoring their case.
    /// @param value A xtd::basic_string to compare to.
    /// @param ignore_case `true` to ignore case when comparing the specified basic_string and value; otherwise, `false`
    /// @return bool `true` if value matches the beginning of the specified basic_string; otherwise, `false`.
    /// @remarks This method compares value to the substring at the beginning of the specified basic_string that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the beginning of the specified basic_string.
    bool starts_with(value_type value, bool ignore_case) const noexcept {
      if (ignore_case) return to_lower().find(static_cast<value_type>(tolower(value))) == 0;
      return find(value) == 0;
    }
    /// @brief Determines whether the beginning of this instance of xtd::basic_string matches a specified xtd::basic_string.
    /// @param value A xtd::basic_string to compare to.
    /// @return bool `true` if value matches the beginning of the specified basic_string; otherwise, `false`.
    /// @remarks This method compares value to the substring at the beginning of the specified basic_string that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the beginning of the specified basic_string.
    bool starts_with(const basic_string & value) const noexcept {return starts_with(value, string_comparison::ordinal);}
    /// @brief Determines whether the beginning of this instance of xtd::basic_string matches a specified xtd::basic_string, ignoring or honoring their case.
    /// @param value A xtd::basic_string to compare to.
    /// @param ignore_case `true` to ignore case when comparing the specified basic_string and value; otherwise, `false`
    /// @return bool `true` if value matches the beginning of the specified basic_string; otherwise, `false`.
    /// @remarks This method compares value to the substring at the beginning of the specified basic_string that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the beginning of the specified basic_string.
    bool starts_with(const basic_string & value, bool ignore_case) const noexcept {return starts_with(value, ignore_case ? string_comparison::ordinal_ignore_case : string_comparison::ordinal);}
    /// @brief Determines whether the end of this basic_string matches the specified basic_string when compared using the specified comparison option.
    /// @param value The string to compare to the substring at the end of this instance.
    /// @param comparison_type One of the enumeration values that determines how this basic_string and value are compared.
    /// @return bool `true` if value matches the end of the specified basic_string; otherwise, `false`.
    bool starts_with(const basic_string & value, xtd::string_comparison comparison_type) const noexcept {
      if (comparison_type == xtd::string_comparison::ordinal_ignore_case) return to_lower().find(value.to_lower()) == 0;
      return find(value) == 0;
    }
    
    /// @brief Returns a substring [`pos`, `pos + count`). If the requested substring extends past the end of the string, i.e. the `count` is greater than size() - pos (e.g. if `count` == xtd::basic_string::npos), the returned substring is [`pos`, size()).
    /// @return String containing the substring [`pos`, `pos + count`) or [pos, size()).
    /// @exception `std::out_of_range` if `pos > size()`.
    /// @remarks Equivalent to return `basic_string(*this, pos, count);`.
    basic_string substr() const {return chars_.substr();}
    /// @brief Returns a substring [`pos`, `pos + count`). If the requested substring extends past the end of the string, i.e. the `count` is greater than size() - pos (e.g. if `count` == xtd::basic_string::npos), the returned substring is [`pos`, size()).
    /// @param pos The position of the first character to include.
    /// @return String containing the substring [`pos`, `pos + count`) or [pos, size()).
    /// @exception `std::out_of_range` if `pos > size()`.
    /// @remarks Equivalent to return `basic_string(*this, pos, count);`.
    basic_string substr(size_type pos) const {
      if (pos > length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      return chars_.substr(pos);
    }
    /// @brief Returns a substring [`pos`, `pos + count`). If the requested substring extends past the end of the string, i.e. the `count` is greater than size() - pos (e.g. if `count` == xtd::basic_string::npos), the returned substring is [`pos`, size()).
    /// @param pos The position of the first character to include.
    /// @param count The length of the substring.
    /// @return String containing the substring [`pos`, `pos + count`) or [pos, size()).
    /// @exception `std::out_of_range` if `pos > size()`.
    /// @remarks Equivalent to return `basic_string(*this, pos, count);`.
    basic_string substr(size_type pos, size_type count) const {
      if (pos > length() || pos + count > length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      return chars_.substr(pos, count);
    }
    
    /// @brief Retrieves a substring from this instance. The substring starts at a specified character position and has a specified length.
    /// @param str basic_string to substring.
    /// @param start_index The zero-based starting character position of a substring in this instance.
    /// @return A basic_string equivalent to the substring of length length that begins at start_index in this instance, or Empty if start_index is equal to the length of this instance and length is zero.
    /// @exception xtd::argument_out_of_range_exception `start_index` is greater than the length() of this instance.
    basic_string substring(xtd::size start_index) const {
      if (start_index > length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      return substr(start_index);
    }
    /// @brief Retrieves a substring from this instance. The substring starts at a specified character position and has a specified length.
    /// @param start_index The zero-based starting character position of a substring in this instance.
    /// @param length The number of characters in the substring.
    /// @return A basic_string equivalent to the substring of length length that begins at start_index in this instance, or Empty if start_index is equal to the length of this instance and length is zero.
    /// @exception xtd::argument_out_of_range_exception `start_index` plus `length` is greater than the length() of this instance.
    basic_string substring(xtd::size start_index, xtd::size length) const {
      if (start_index > self_.length() || start_index + length > self_.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      return substr(start_index, length);
    }
    
    /// @brief Copies the characters in this instance to a Unicode character array.
    /// @return A character array whose elements are the individual characters of this instance. If this instance is an empty xtd::basic_string, the returned array is empty and has a zero length.
    xtd::array<value_type> to_array() const noexcept;
    /// @brief Copies the characters in this instance to a Unicode character array starting at specified index.
    /// @param start_index The starting position of basic_string to convert.
    /// @return A character array whose elements are the individual characters of this instance. If this instance is an empty xtd::basic_string, the returned array is empty and has a zero length.
    xtd::array<value_type> to_array(xtd::size start_index) const;
    /// @brief Copies the characters in this instance to a Unicode character array starting at specified index with specified length.
    /// @param start_index The starting position of basic_string to convert.
    /// @param length The length of the basic_string to convert
    /// @return A character array whose elements are the individual characters of this instance. If this instance is an empty xtd::basic_string, the returned array is empty and has a zero length.
    xtd::array<value_type> to_array(xtd::size start_index, xtd::size length) const;
    
    /// @brief Copies the characters in this instance to a Unicode character array.
    /// @return A character array whose elements are the individual characters of this instance. If this instance is an empty xtd::basic_string, the returned array is empty and has a zero length.
    xtd::array<value_type> to_char_array() const noexcept;
    /// @brief Copies the characters in this instance to a Unicode character array starting at specified index with specified length.
    /// @param start_index The starting position of basic_string to convert.
    /// @param length The length of the basic_string to convert
    /// @return A character array whose elements are the individual characters of this instance. If this instance is an empty xtd::basic_string, the returned array is empty and has a zero length.
    xtd::array<value_type> to_char_array(xtd::size start_index, xtd::size length) const;
    
    /// @brief Returns a copy of the current xtd::basic_string converted to lowercase.
    /// @return A string in lowercase.
    basic_string to_lower() const noexcept {
      auto result = basic_string::empty_string;
      std::for_each(chars_.begin(), chars_.end(), [&](auto c) {result += static_cast<value_type>(std::tolower(c));});
      return result;
    }
    
    /// @brief Converts the value of this instance to a xtd::basic_string <char>.
    /// @return The current string.
    /// @todo Uncomment the folllowing line and remove the next..
    basic_string<char> to_string() const noexcept override {
      if constexpr(std::is_same_v<char, char_t>) return chars_;
      else return __xtd_convert_to_string<char>(chars_);
    }
    
    /// @brief Converts the current basic_string to title case (except for words that are entirely in uppercase, which are considered to be acronyms).
    /// @return A new basic_string in title case.
    basic_string to_title_case() const noexcept;
    
    /// @brief Converts the value of this instance to a xtd::basic_string <xtd::char16>.
    /// @return The current string.
    basic_string<xtd::char16> to_u16string() const noexcept {
      if constexpr(std::is_same_v<xtd::char16, char_t>) return chars_;
      else return __xtd_convert_to_string<xtd::char16>(chars_);
    }
    
    /// @brief Converts the value of this instance to a xtd::basic_string <xtd::char32>.
    /// @return The current string.
    basic_string<xtd::char32> to_u32string() const noexcept {
      if constexpr(std::is_same_v<xtd::char32, char_t>) return chars_;
      else return __xtd_convert_to_string<xtd::char32>(chars_);
    }
    
    /// @brief Converts the value of this instance to a xtd::basic_string <xtd::char8>.
    /// @return The current string.
    basic_string<xtd::char8> to_u8string() const noexcept {
      if constexpr(std::is_same_v<xtd::char8, char_t>) return chars_;
      else return __xtd_convert_to_string<xtd::char8>(chars_);
    }
    
    /// @brief Returns a copy of the current xtd::basic_string converted to uppercase.
    /// @return A string in uppercase.
    basic_string to_upper() const noexcept {
      auto result = basic_string::empty_string;
      std::for_each(chars_.begin(), chars_.end(), [&](auto c) {result += static_cast<value_type>(std::toupper(c));});
      return result;
    }
    
    /// @brief Converts the value of this instance to a xtd::basic_string <xtd::wchar>.
    /// @return The current string.
    basic_string<xtd::wchar> to_wstring() const noexcept {
      if constexpr(std::is_same_v<xtd::wchar, char_t>) return chars_;
      else return __xtd_convert_to_string<xtd::wchar>(chars_);
    }
    
    /// @brief Removes all leading and trailing occurrences of white-space characters from the specified xtd::basic_string.
    /// @param str xtd::basic_string to trim end.
    /// @param trim_char A character to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the character in the trim_char parameter are removed from the start and te and of the specified xtd::basic_string.
    basic_string trim() const noexcept {return trim(default_trim_chars);}
    /// @brief Removes all leading and trailing occurrences of a character specified from the specified xtd::basic_string .
    /// @param str xtd::basic_string to trim start.
    /// @param trim_char A character to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the character in the trim_char parameter are removed from the start and the end of the specified xtd::basic_string.
    basic_string trim(value_type trim_char) const noexcept;
    /// @brief Removes all leading and trailing occurrences of a set of characters specified in an array from the specified xtd::basic_string.
    /// @param str xtd::basic_string to trim end.
    /// @param trim_chars An array of characters to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the characters in the trim_chars parameter are removed from the start and the edn of the specified xtd::basic_string.
    basic_string trim(const xtd::array<value_type>& trim_chars) const noexcept;
    
    /// @brief Removes all trailing occurrences of white-space characters from the specified xtd::basic_string.
    /// @param str xtd::basic_string to trim end.
    /// @param trim_char A character to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the character in the trim_char parameter are removed from the end of the specified xtd::basic_string.
    basic_string trim_end() const noexcept {return trim_end(default_trim_chars);}
    /// @brief Removes all trailing occurrences of a character specified from the specified xtd::basic_string .
    /// @param str xtd::basic_string to trim start.
    /// @param trim_char A character to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the character in the trim_char parameter are removed from the end of the specified xtd::basic_string.
    basic_string trim_end(value_type trim_char) const noexcept;
    /// @brief Removes all trailing occurrences of a set of characters specified in an array from the specified xtd::basic_string.
    /// @param str xtd::basic_string to trim end.
    /// @param trim_chars An array of characters to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the characters in the trim_chars parameter are removed from the end of the specified xtd::basic_string.
    basic_string trim_end(const xtd::array<value_type>& trim_chars) const noexcept;
    
    /// @brief Removes all leading occurrences of white-space characters from the specified xtd::basic_string.
    /// @param str xtd::basic_string to trim start.
    /// @param trim_char A character to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the character in the trim_char parameter are removed from the start of the specified xtd::basic_string.
    basic_string trim_start() const noexcept {return trim_start(default_trim_chars);}
    /// @brief Removes all leading occurrences of a character specified from the specified xtd::basic_string .
    /// @param str xtd::basic_string to trim start.
    /// @param trim_char A character to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the character in the trim_char parameter are removed from the start of the specified xtd::basic_string.
    basic_string trim_start(value_type trim_char) const noexcept;
    /// @brief Removes all leading occurrences of a set of characters specified in an array from the specified xtd::basic_string.
    /// @param str An xtd::basic_string to trim start.
    /// @param trim_chars An array of characters to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the characters in the trim_chars parameter are removed from the start of the specified xtd::basic_string.
    basic_string trim_start(const xtd::array<value_type>& trim_chars) const noexcept;
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
    static int32 compare(const basic_string & str_a, const basic_string & str_b) noexcept {return compare(str_a, str_b, false);}
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
    static int32 compare(const basic_string & str_a, const basic_string & str_b, bool ignore_case) noexcept {return compare(str_a, str_b, ignore_case ? xtd::string_comparison::ordinal_ignore_case : xtd::string_comparison::ordinal);}
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
    static int32 compare(const basic_string & str_a, const basic_string & str_b, xtd::string_comparison comparison_type) noexcept {return comparison_type == xtd::string_comparison::ordinal_ignore_case ? str_a.to_lower().compare(str_b.to_lower()) : str_a.compare(str_b);}
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
    static int32 compare(const basic_string & str_a, xtd::size index_a, const basic_string & str_b, xtd::size index_b, xtd::size length) {return compare(str_a, index_a, str_b, index_b, length, false);}
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
    static int32 compare(const basic_string & str_a, xtd::size index_a, const basic_string & str_b, xtd::size index_b, xtd::size length, bool ignore_case) {return compare(str_a, index_a, str_b, index_b, length, ignore_case ? xtd::string_comparison::ordinal_ignore_case : xtd::string_comparison::ordinal);}
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
    static int32 compare(const basic_string & str_a, xtd::size index_a, const basic_string & str_b, xtd::size index_b, xtd::size length, xtd::string_comparison comparison_type) {return comparison_type == xtd::string_comparison::ordinal_ignore_case ? str_a.substr(index_a, length).to_lower().compare(str_b.substr(index_b, length).to_lower()) : str_a.substr(index_a, length).compare(str_b.substr(index_b, length));}
    
    /// @brief Concatenates four specified instances of basic_string.
    /// @param str_a The first basic_string to concatenate.
    /// @param str_b The second basic_string to concatenate.
    /// @param str_c The third basic_string to concatenate.
    /// @param str_d The fourth basic_string to concatenate.
    /// @return The concatenation of str_a, str_b, str_c and str_d.
    static basic_string concat(const basic_string & str_a, const basic_string & str_b, const basic_string & str_c, const basic_string & str_d) noexcept {return str_a + str_b + str_c + str_d;}
    /// @brief Concatenates four specified instances of object.
    /// @param obj_a The first object to concatenate.
    /// @param obj_b The second object to concatenate.
    /// @param obj_c The third object to concatenate.
    /// @param obj_d The fourth object to concatenate.
    /// @return The concatenation of obj_a, obj_b, obj_c and obj_d.
    template<class object_a_t, class object_b_t, class object_c_t, class object_d_t>
    inline static basic_string concat(object_a_t obj_a, object_b_t obj_b, object_c_t obj_c, object_d_t obj_d) noexcept {return format("{}{}{}{}", obj_a, obj_b, obj_c, obj_d);}
    /// @brief Concatenates three specified instances of basic_string.
    /// @param str_a The first basic_string to concatenate.
    /// @param str_b The second basic_string to concatenate.
    /// @param str_c The third basic_string to concatenate.
    /// @return basic_string The concatenation of str_a, str_b and str_c.
    static basic_string concat(const basic_string & str_a, const basic_string & str_b, const basic_string & str_c) noexcept {return str_a + str_b + str_c;}
    /// @brief Concatenates three specified instances of object.
    /// @param obj_a The first object to concatenate.
    /// @param obj_b The second object to concatenate.
    /// @param obj_c The third object to concatenate.
    /// @return The concatenation of obj_a, obj_b and obj_c.
    template<class object_a_t, class object_b_t, class object_c_t>
    inline static basic_string concat(object_a_t obj_a, object_b_t obj_b, object_c_t obj_c) noexcept {return format("{}{}{}", obj_a, obj_b, obj_c);}
    /// @brief Concatenates two specified instances of basic_string.
    /// @param str_a The first basic_string to concatenate.
    /// @param str_b The second basic_string to concatenate.
    /// @return basic_string The concatenation of str_a and str_b.
    static basic_string concat(const basic_string & str_a, const basic_string & str_b) noexcept {return str_a + str_b;}
    /// @brief Concatenates two specified instances of object.
    /// @param obj_a The first object to concatenate.
    /// @param obj_b The second object to concatenate.
    /// @return The concatenation of obj_a and obj_b.
    template<class object_a_t, class object_b_t>
    inline static basic_string concat(object_a_t obj_a, object_b_t obj_b) noexcept {return format("{}{}", obj_a, obj_b);}
    /// @brief Concatenates the elements of a specified basic_string array.
    /// @param values An array of basic_string instances.
    /// @return The concatenated elements of values.
    static basic_string concat(const xtd::array<basic_string>& values) noexcept;
    /// @cond
    static basic_string concat(const xtd::array<const_pointer>& values) noexcept;
    template<class other_char_t>
    inline static basic_string concat(const xtd::array<const other_char_t*>& values) noexcept;
    static basic_string concat(const std::initializer_list<basic_string>& values) noexcept {
      auto result = basic_string::empty_string;
      std::for_each(values.begin(), values.end(), [&](const auto & item) {result += item;});
      return result;
    }
    static basic_string concat(const std::initializer_list<const_pointer>& values) noexcept {
      auto result = basic_string::empty_string;
      std::for_each(values.begin(), values.end(), [&](const auto & item) {result += item;});
      return result;
    }
    template<class other_char_t>
    inline static basic_string concat(const std::initializer_list<const other_char_t*>& values) noexcept {
      auto result = basic_string::empty_string;
      std::for_each(values.begin(), values.end(), [&](const auto & item) {result += item;});
      return result;
    }
    /// @endcond
    /// @brief Concatenates the basic_string representations of the elements in a specified object array.
    /// @param args An object array that contains the elements to concatenate.
    /// @return The concatenated basic_string representations of the values of the elements in args.
    template<class object_t>
    inline static basic_string concat(const xtd::array<object_t>& args) noexcept;
    /// @cond
    template<class object_t>
    inline static basic_string concat(const std::initializer_list<object_t>& args) noexcept {
      basic_string result;
      for (const auto& arg : args)
        result += format("{}", arg);
      return result;
    }
    /// @endcond
    /// @brief Creates the basic_string representation of a specified object.
    /// @param value The object to represent.
    /// @return The basic_string representation of the value of arg.
    template<class value_t>
    inline static basic_string concat(value_t value) noexcept {
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
    static basic_string demangle(const basic_string & name) {
      if constexpr(std::is_same_v<char, char_t>) return __xtd_demangle(name.chars());
      else return __xtd_demangle(__xtd_convert_to_string<char>(name.chars()));
    }
    
    /// @brief Determines whether two specified xtd::basic_string objects have the same value.
    /// @param a The first basic_string to compare.
    /// @param b The second basic_string to compare.
    /// @return `true` if the value of `a` is the same as the value of `b`; otherwise, `false`.
    /// @remarks This method performs an ordinal (case-sensitive) comparison.
    static bool equals(const basic_string & a, const basic_string & b) noexcept {return a.equals(b);}
    /// @brief Determines whether two specified xtd::basic_string objects have the same value.
    /// @param a The first basic_string to compare.
    /// @param b The second basic_string to compare.
    /// @return `true` if the value of `a` is the same as the value of `b`; otherwise, `false`.
    /// @remarks This method performs an ordinal (case-sensitive) comparison.
    template<class char_a_t, class char_b_t>
    inline static bool equals(const char_a_t* a, const char_b_t* b) noexcept {return basic_string {a}.equals(basic_string {b});}
    
    /// @brief Determines whether two specified xtd::basic_string objects have the same value, ignoring or honoring their case.
    /// @param a The first basic_string to compare.
    /// @param b The second basic_string to compare.
    /// @param ignore_case `true` to ignore case when comparing this instance and value; otherwise, `false`
    /// @return `true` if the value of `a` is the same as the value of `b`; otherwise, `false`.
    /// @remarks This method performs an ordinal comparison.
    static bool equals(const basic_string & a, const basic_string & b, bool ignore_case) noexcept {return a.equals(b, ignore_case);}
    /// @brief Determines whether two specified xtd::basic_string objects have the same value, ignoring or honoring their case.
    /// @param a The first basic_string to compare.
    /// @param b The second basic_string to compare.
    /// @param ignore_case `true` to ignore case when comparing this instance and value; otherwise, `false`
    /// @return `true` if the value of `a` is the same as the value of `b`; otherwise, `false`.
    /// @remarks This method performs an ordinal comparison.
    template<class char_a_t, class char_b_t>
    inline static bool equals(const char_a_t* a, const char_b_t* b, bool ignore_case) noexcept {return basic_string {a}.equals(basic_string {b}, ignore_case);}
    
    /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
    /// @param fmt A composite format string.
    /// @param args arguments list to write using format.
    /// @return string formatted.
    /// @ingroup format_parse
    /// @remarks for more information about format see @ref FormatPage "Format".
    template<class ...args_t>
    inline static basic_string format(const basic_string<char>& fmt, args_t&& ... args);
    
    /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
    /// @param loc An std::locale object that contains locale information (see [std::locale](https://en.cppreference.com/w/cpp/locale/locale)).
    /// @param fmt A composite format string.
    /// @param args arguments list to write using format.
    /// @return string formatted.
    /// @ingroup format_parse
    /// @remarks for more information about format see @ref FormatPage "Format".
    template<class ...args_t>
    inline static basic_string format(const std::locale & loc, const basic_string<char>& fmt, args_t&& ... args);
    
    /// @brief Indicates whether the specifeid basic_string is an empty basic_string ("").
    /// @param string The xtd::basic_string to check if empty.
    /// @return `true` if the value parameter is null or an empty basic_string (""); otherwise, `false`.
    static bool is_empty(const xtd::basic_string<value_type, traits_type, allocator_type>& string) noexcept {return !string.length();}
    
    /// @brief Concatenates a specified separator basic_string between each element of a specified object array, yielding a single concatenated basic_string.
    /// @param separator A basic_string separator.
    /// @param values An array of Object.
    /// @return A basic_string consisting of the elements of value interspersed with the separator basic_string.
    /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value) returns "red, blue, green, yellow".
    /// @remarks stream << operator is called on each object to generate the content.
    template<class collection_t>
    inline static basic_string join(const basic_string & separator, const collection_t& values) noexcept {
      xtd::size i = 0;
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
    template<class collection_t>
    inline static basic_string join(const basic_string & separator, const collection_t& values, xtd::size index) {return join(separator, values, index, values.size() - index);}
    /// @brief Concatenates a specified separator basic_string between each element of a specified Object array, yielding a single concatenated basic_string.
    /// @param separator A basic_string separator.
    /// @param values An array of Object.
    /// @param start_index The first array element in value to use.
    /// @param count The number of elements of value to use.
    /// @return A basic_string consisting of the elements of value interspersed with the separator basic_string.
    /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value) returns "red, blue, green, yellow".
    /// @remarks stream << operator is called on each object to generate the content.
    template<class collection_t>
    inline static basic_string join(const basic_string & separator, const collection_t& values, xtd::size index, xtd::size count) {
      if (index > values.size() || index + count > values.size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      xtd::size i = 0;
      basic_string result;
      for (const auto& item : values) {
        if (i >= index) result += format("{}{}", (i != index ? separator : basic_string {}), item);
        if (++i >= index + count) break;
      }
      return result;
    }
    
    /// @cond
    template<class value_t>
    inline static basic_string join(const basic_string & separator, const std::initializer_list<value_t>& values) noexcept;
    template<class value_t>
    inline static basic_string join(const basic_string & separator, const std::initializer_list<value_t>& values, xtd::size index);
    template<class value_t>
    inline static basic_string join(const basic_string & separator, const std::initializer_list<value_t>& values, xtd::size index, xtd::size count);
    /// @endcond
    
    /// @brief Converts a basic_string into a value_t type.
    /// @param str Ax xtd::basic_string to convert to value_t
    /// @return The value_t object parsed.
    template<class value_t>
    inline static value_t parse(const basic_string & str) {
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
    template<class ...args_t>
    inline static basic_string sprintf(const basic_string & fmt, args_t&& ... args) noexcept {return __sprintf(fmt.chars().c_str(), convert_param(std::forward<args_t>(args)) ...);}
    
    /// @brief Try to convert a basic_string into a value_t type.
    /// @param str An xtd::basic_string to convert to value_t
    /// @param value The value that will contain the parsed xtd::basic_string.
    /// @return `true` if xtd::basic_string:=:try_parse succed; otherwise, `false`.
    template<class value_t>
    inline static bool try_parse(const basic_string & str, value_t& value) noexcept {
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
    const_reference operator [](xtd::size index) const {
      if (index >= length() && index != epos) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      return chars_[index == epos ? length() - 1 : index];
    }
    
    /// @brief Returns a reference to the underlying base type.
    /// @return Reference to the underlying base type.
    operator const base_type& () const noexcept {return chars_;}
    
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of str.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const basic_string<char>& str) noexcept {
      if constexpr(std::is_same<char_t, char>::value) chars_ = str.chars_;
      else chars_ = __xtd_convert_to_string<value_type>(str.chars());
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of str.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const basic_string<xtd::char16>& str) noexcept {
      if constexpr(std::is_same<char_t, xtd::char16>::value) chars_ = str.chars_;
      else chars_ = __xtd_convert_to_string<value_type>(str.chars());
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of str.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const basic_string<xtd::char32>& str) noexcept {
      if constexpr(std::is_same<char_t, xtd::char32>::value) chars_ = str.chars_;
      else chars_ = __xtd_convert_to_string<value_type>(str.chars());
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of str.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const basic_string<xtd::char8>& str) noexcept {
      if constexpr(std::is_same<char_t, xtd::char8>::value) chars_ = str.chars_;
      else chars_ = __xtd_convert_to_string<value_type>(str.chars());
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of str.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const basic_string<xtd::wchar>& str) noexcept {
      if constexpr(std::is_same<char_t, xtd::wchar>::value) chars_ = str.chars_;
      else chars_ = __xtd_convert_to_string<value_type>(str.chars());
      return self_;
    }
    
    /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in `str` is moved from `str` into this string). `str` is in a valid but unspecified state afterwards.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(basic_string<char>&& str) noexcept {
      if constexpr(std::is_same<char_t, char>::value) chars_ = std::move(str.chars_);
      else chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_)));
      return self_;
    }
    /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in `str` is moved from `str` into this string). `str` is in a valid but unspecified state afterwards.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(basic_string<xtd::char16>&& str) noexcept {
      if constexpr(std::is_same<char_t, xtd::char16>::value) chars_ = std::move(str.chars_);
      else chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_)));
      return self_;
    }
    /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in `str` is moved from `str` into this string). `str` is in a valid but unspecified state afterwards.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(basic_string<xtd::char32>&& str) noexcept {
      if constexpr(std::is_same<char_t, xtd::char32>::value) chars_ = std::move(str.chars_);
      else chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_)));
      return self_;
    }
    /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in `str` is moved from `str` into this string). `str` is in a valid but unspecified state afterwards.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(basic_string<xtd::char8>&& str) noexcept {
      if constexpr(std::is_same<char_t, xtd::char8>::value) chars_ = std::move(str.chars_);
      else chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_)));
      return self_;
    }
    /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in `str` is moved from `str` into this string). `str` is in a valid but unspecified state afterwards.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(basic_string<xtd::wchar>&& str) noexcept {
      if constexpr(std::is_same<char_t, xtd::wchar>::value) chars_ = std::move(str.chars_);
      else chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_)));
      return self_;
    }
    
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::basic_string<char>& str) noexcept {
      if constexpr(std::is_same<char_t, char>::value) chars_ = str;
      else chars_ = __xtd_convert_to_string<value_type>(str);
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::basic_string<xtd::char16>& str) noexcept {
      if constexpr(std::is_same<char_t, xtd::char16>::value) chars_ = str;
      else chars_ = __xtd_convert_to_string<value_type>(str);
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::basic_string<xtd::char32>& str) noexcept {
      if constexpr(std::is_same<char_t, xtd::char32>::value) chars_ = str;
      else chars_ = __xtd_convert_to_string<value_type>(str);
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::basic_string<xtd::char8>& str) noexcept {
      if constexpr(std::is_same<char_t, xtd::char8>::value) chars_ = str;
      else chars_ = __xtd_convert_to_string<value_type>(str);
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::basic_string<xtd::wchar>& str) noexcept {
      if constexpr(std::is_same<char_t, xtd::wchar>::value) chars_ = str;
      else chars_ = __xtd_convert_to_string<value_type>(str);
      return self_;
    }
    
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(std::basic_string<char>&& str) noexcept {
      if constexpr(std::is_same<char_t, char>::value) chars_ = std::move(str);
      else chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str)));
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(std::basic_string<xtd::char16>&& str) noexcept {
      if constexpr(std::is_same<char_t, xtd::char16>::value) chars_ = std::move(str);
      else chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str)));
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(std::basic_string<xtd::char32>&& str) noexcept {
      if constexpr(std::is_same<char_t, xtd::char32>::value) chars_ = std::move(str);
      else chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str)));
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(std::basic_string<xtd::char8>&& str) noexcept {
      if constexpr(std::is_same<char_t, xtd::char8>::value) chars_ = std::move(str);
      else chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str)));
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(std::basic_string<xtd::wchar>&& str) noexcept {
      if constexpr(std::is_same<char_t, xtd::wchar>::value) chars_ = std::move(str);
      else chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str)));
      return self_;
    }
    
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    basic_string& operator =(const char* str) {
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<char, char_t>) chars_ = std::basic_string<char>(str);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<char>(str));
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    basic_string& operator =(const xtd::char16 * str) {
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::char16, char_t>) chars_ = std::basic_string<xtd::char16>(str);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char16>(str));
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    basic_string& operator =(const xtd::char32 * str) {
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::char32, char_t>) chars_ = std::basic_string<xtd::char32>(str);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char32>(str));
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    basic_string& operator =(const xtd::char8 * str) {
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::char8, char_t>) chars_ = std::basic_string<xtd::char8>(str);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char8>(str));
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    basic_string& operator =(const xtd::wchar * str) {
      if (str == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::null_pointer);
      if constexpr(std::is_same_v<xtd::wchar, char_t>) chars_ = std::basic_string<xtd::wchar>(str);
      else chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::wchar>(str));
      return self_;
    }
    
    /// @brief Copy assignment operator. Replaces the contents with the specified character.
    /// @param character The character to use as data source.
    /// @return This current instance.
    basic_string& operator =(char character) {
      self_ = basic_string(character, 1);
      return  self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with the specified character.
    /// @param character The character to use as data source.
    /// @return This current instance.
    basic_string& operator =(xtd::char16 character) {
      self_ = basic_string(character, 1);
      return  self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with the specified character.
    /// @param character The character to use as data source.
    /// @return This current instance.
    basic_string& operator =(xtd::char32 character) {
      self_ = basic_string(character, 1);
      return  self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with the specified character.
    /// @param character The character to use as data source.
    /// @return This current instance.
    basic_string& operator =(xtd::char8 character) {
      self_ = basic_string(character, 1);
      return  self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with the specified character.
    /// @param character The character to use as data source.
    /// @return This current instance.
    basic_string& operator =(xtd::wchar character) {
      self_ = basic_string(character, 1);
      return  self_;
    }
    
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of the specified initializer list.
    /// @param il The initialiazer list to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::initializer_list<char>& il) {
      self_ = basic_string(il);
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of the specified initializer list.
    /// @param il The initialiazer list to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::initializer_list<xtd::char16>& il) {
      self_ = basic_string(il);
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of the specified initializer list.
    /// @param il The initialiazer list to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::initializer_list<xtd::char32>& il) {
      self_ = basic_string(il);
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of the specified initializer list.
    /// @param il The initialiazer list to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::initializer_list<xtd::char8>& il) {
      self_ = basic_string(il);
      return self_;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of the specified initializer list.
    /// @param il The initialiazer list to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::initializer_list<xtd::wchar>& il) {
      self_ = basic_string(il);
      return self_;
    }
    
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const basic_string<char>& str) {
      if constexpr(std::is_same_v<char, char_t>) chars_ += str.chars_;
      else chars_ += __xtd_convert_to_string<value_type>(str.chars_);
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const basic_string<xtd::char16>& str) {
      if constexpr(std::is_same_v<xtd::char16, char_t>) chars_ += str.chars_;
      else chars_ += __xtd_convert_to_string<value_type>(str.chars_);
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const basic_string<xtd::char32>& str) {
      if constexpr(std::is_same_v<xtd::char32, char_t>) chars_ += str.chars_;
      else chars_ += __xtd_convert_to_string<value_type>(str.chars_);
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const basic_string<xtd::char8>& str) {
      if constexpr(std::is_same_v<xtd::char8, char_t>) chars_ += str.chars_;
      else chars_ += __xtd_convert_to_string<value_type>(str.chars_);
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const basic_string<xtd::wchar>& str) {
      if constexpr(std::is_same_v<xtd::wchar, char_t>) chars_ += str.chars_;
      else chars_ += __xtd_convert_to_string<value_type>(str.chars_);
      return self_;
    }
    
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(basic_string<char>&& str) {
      if constexpr(std::is_same_v<char, char_t>) chars_ += std::move(str.chars_);
      else chars_ += __xtd_convert_to_string<value_type>(std::move(str.chars_));
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(basic_string<xtd::char16>&& str) {
      if constexpr(std::is_same_v<xtd::char16, char_t>) chars_ += std::move(str.chars_);
      else chars_ += __xtd_convert_to_string<value_type>(std::move(str.chars_));
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(basic_string<xtd::char32>&& str) {
      if constexpr(std::is_same_v<xtd::char32, char_t>) chars_ += std::move(str.chars_);
      else chars_ += __xtd_convert_to_string<value_type>(std::move(str.chars_));
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(basic_string<xtd::char8>&& str) {
      if constexpr(std::is_same_v<xtd::char8, char_t>) chars_ += std::move(str.chars_);
      else chars_ += __xtd_convert_to_string<value_type>(std::move(str.chars_));
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(basic_string<xtd::wchar>&& str) {
      if constexpr(std::is_same_v<xtd::wchar, char_t>) chars_ += std::move(str.chars_);
      else chars_ += __xtd_convert_to_string<value_type>(std::move(str.chars_));
      return self_;
    }
    
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const std::basic_string<char>& str) {
      if constexpr(std::is_same_v<char, char_t>) chars_ += str;
      else chars_ += __xtd_convert_to_string<value_type>(str);
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const std::basic_string<xtd::char16>& str) {
      if constexpr(std::is_same_v<xtd::char16, char_t>) chars_ += str;
      else chars_ += __xtd_convert_to_string<value_type>(str);
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const std::basic_string<xtd::char32>& str) {
      if constexpr(std::is_same_v<xtd::char32, char_t>) chars_ += str;
      else chars_ += __xtd_convert_to_string<value_type>(str);
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const std::basic_string<xtd::char8>& str) {
      if constexpr(std::is_same_v<xtd::char8, char_t>) chars_ += str;
      else chars_ += __xtd_convert_to_string<value_type>(str);
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const std::basic_string<xtd::wchar>& str) {
      if constexpr(std::is_same_v<xtd::wchar, char_t>) chars_ += str;
      else chars_ += __xtd_convert_to_string<value_type>(str);
      return self_;
    }
    
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const char* str) {
      chars_ += basic_string(str).chars_;
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const xtd::char16 * str) {
      chars_.append(basic_string(str).chars_); return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const xtd::char32 * str) {
      chars_ += basic_string(str).chars_;
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const xtd::char8 * str) {
      chars_ += basic_string(str).chars_;
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const xtd::wchar * str) {
      chars_ += basic_string(str).chars_;
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param ch Character value to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(char ch) {
      chars_ += basic_string(ch, 1).chars_;
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param ch Character value to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(xtd::char16 ch) {
      chars_ += basic_string(ch, 1).chars_;
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param ch Character value to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(xtd::char32 ch) {
      chars_ += basic_string(ch, 1).chars_;
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param ch Character value to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(xtd::char8 ch) {
      chars_ += basic_string(ch, 1).chars_;
      return self_;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param ch Character value to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(xtd::wchar ch) {
      chars_ += basic_string(ch, 1).chars_;
      return self_;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, const basic_string<char>& rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, const basic_string<xtd::char16>& rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, const basic_string<xtd::char32>& rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, const basic_string<xtd::char8>& rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, const basic_string<xtd::wchar>& rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, basic_string<char>&& rhs) {
      auto result = std::move(lhs);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, basic_string<xtd::char16>&& rhs) {
      auto result = std::move(lhs);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, basic_string<xtd::char32>&& rhs) {
      auto result = std::move(lhs);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, basic_string<xtd::char8>&& rhs) {
      auto result = std::move(lhs);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, basic_string<xtd::wchar>&& rhs) {
      auto result = std::move(lhs);
      result += std::move(rhs);
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const basic_string<char>& rhs) {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const basic_string<xtd::char16>& rhs) {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const basic_string<xtd::char32>& rhs) {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const basic_string<xtd::char8>& rhs) {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const basic_string<xtd::wchar>& rhs) {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, basic_string<char>&& rhs) {
      auto result = lhs;
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, basic_string<xtd::char16>&& rhs) {
      auto result = lhs;
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, basic_string<xtd::char32>&& rhs) {
      auto result = lhs;
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, basic_string<xtd::char8>&& rhs) {
      auto result = lhs;
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, basic_string<xtd::wchar>&& rhs) {
      auto result = lhs;
      result += std::move(rhs);
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, const std::basic_string<char>& rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, const std::basic_string<xtd::char16>& rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, const std::basic_string<xtd::char32>& rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, const std::basic_string<xtd::char8>& rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, const std::basic_string<xtd::wchar>& rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const std::basic_string<char>& lhs, const basic_string & rhs) {
      auto result = lhs;
      if constexpr(std::is_same_v<char, char_t>) result += rhs.chars();
      else result += __xtd_convert_to_string<char>(rhs.chars());
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const std::basic_string<xtd::char16>& lhs, const basic_string & rhs) {
      auto result = lhs;
      if constexpr(std::is_same_v<xtd::char16, char_t>) result += rhs.chars();
      else result += __xtd_convert_to_string<xtd::char16>(rhs.chars());
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const std::basic_string<xtd::char32>& lhs, const basic_string & rhs) {
      auto result = lhs;
      if constexpr(std::is_same_v<xtd::char32, char_t>) result += rhs.chars();
      else result += __xtd_convert_to_string<xtd::char32>(rhs.chars());
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const std::basic_string<xtd::char8>& lhs, const basic_string & rhs) {
      auto result = lhs;
      if constexpr(std::is_same_v<xtd::char8, char_t>) result += rhs.chars();
      else result += __xtd_convert_to_string<xtd::char8>(rhs.chars());
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const std::basic_string<xtd::wchar>& lhs, const basic_string & rhs) {
      auto result = lhs;
      if constexpr(std::is_same_v<xtd::wchar, char_t>) result += rhs.chars();
      else result += __xtd_convert_to_string<xtd::wchar>(rhs.chars());
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, const char* rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, const xtd::char16 * rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, const xtd::char32 * rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, const xtd::char8 * rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, const xtd::wchar * rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const char* rhs) {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const xtd::char16 * rhs) {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const xtd::char32 * rhs) {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const xtd::char8 * rhs) {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const xtd::wchar * rhs) {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const char* lhs, const basic_string & rhs) {
      auto result = basic_string(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char16 * lhs, const basic_string & rhs) {
      auto result = basic_string(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char32 * lhs, const basic_string & rhs) {
      auto result = basic_string(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char8 * lhs, const basic_string & rhs) {
      auto result = basic_string(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::wchar * lhs, const basic_string & rhs) {
      auto result = basic_string(lhs);
      result += rhs;
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const char* lhs, basic_string&& rhs) {
      auto result = basic_string(lhs);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char16 * lhs, basic_string&& rhs) {
      auto result = basic_string(lhs);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char32 * lhs, basic_string&& rhs) {
      auto result = basic_string(lhs);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char8 * lhs, basic_string&& rhs) {
      auto result = basic_string(lhs);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::wchar * lhs, basic_string&& rhs) {
      auto result = basic_string(lhs);
      result += std::move(rhs);
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, const char rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, const xtd::char16 rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, const xtd::char32 rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, const xtd::char8 rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string & lhs, const xtd::wchar rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const char rhs) {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const xtd::char16 rhs) {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const xtd::char32 rhs) {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const xtd::char8 rhs) {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const xtd::wchar rhs) {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(char lhs, const basic_string & rhs) {
      auto result = basic_string(lhs, 1);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(xtd::char16 lhs, const basic_string & rhs) {
      auto result = basic_string(lhs, 1);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(xtd::char32 lhs, const basic_string & rhs) {
      auto result = basic_string(lhs, 1);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(xtd::char8 lhs, const basic_string & rhs) {
      auto result = basic_string(lhs, 1);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(xtd::wchar lhs, const basic_string & rhs) {
      auto result = basic_string(lhs, 1);
      result += rhs;
      return result;
    }
    
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(char lhs, basic_string&& rhs) {
      auto result = basic_string(lhs, 1);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(xtd::char16 lhs, basic_string&& rhs) {
      auto result = basic_string(lhs, 1);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(xtd::char32 lhs, basic_string&& rhs) {
      auto result = basic_string(lhs, 1);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(xtd::char8 lhs, basic_string&& rhs) {
      auto result = basic_string(lhs, 1);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(xtd::wchar lhs, basic_string&& rhs) {
      auto result = basic_string(lhs, 1);
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
    //friend std::basic_ostream<char>& operator <<(std::basic_ostream<char>& stream, const basic_string& str) {return stream << str.to_string().chars_;}
    friend std::basic_ostream<char>& operator <<(std::basic_ostream<char>& stream, const basic_string & str) {
      if constexpr(std::is_same_v<char, char_t>) return stream << str.chars();
      else return stream << __xtd_convert_to_string<char>(str.chars());
    }
    /// @brief Output stream operator. Behaves as a [FormattedOutputFunction](https://en.cppreference.com/w/cpp/named_req/FormattedOutputFunction). After constructing and checking the sentry object, [determines the output format padding](https://en.cppreference.com/w/cpp/named_req/FormattedOutputFunction#Padding).
    /// @param os The character output stream.
    /// @param str The string to be inserted.
    /// @remarks Then inserts each character from the resulting sequence `seq` (the contents of `str` plus padding) to the output stream `os` as if by calling `os.rdbuf()->sputn(seq, n)`, where n is `std::max(os.width(), str.size())`.
    /// @remarks Finally, calls `os.width(0)` to cancel the effects of std::setw, if any.
    /// @remarks Equivalent to `return os << std::basic_string_view<char_t, traits_t>(str);`.
    friend std::basic_ostream<xtd::wchar>& operator <<(std::basic_ostream<xtd::wchar>& stream, const basic_string & str) {return stream << str.to_wstring().chars();}
    
    /// @brief Input stream operator. Behaves as a [FormattedInputFunction](https://en.cppreference.com/w/cpp/named_req/FormattedInputFunction). After constructing and checking the sentry object, which may skip leading whitespace, first clears `str` with `str.erase()`, then reads characters from `is` and appends them to `str` as if by `str.append(1, c)`, until one of the following conditions becomes `true`:
    /// * N characters are read, where N is `is.width()` if `is.width() > 0`, otherwise N is `str.max_size()`,
    /// * the end-of-file condition occurs in the stream is, or
    /// * `std::isspace(c, is.getloc())` is `true` for the next character `c` in `is` (this whitespace character remains in the input stream).
    /// @param is The character input stream.
    /// @param str The string to be extracted.
    /// @remarks If no characters are extracted then std::ios::failbit is set on `is`, which may throw [std::ios_base::failure](https://en.cppreference.com/w/cpp/io/ios_base/failure).
    /// @remarks Finally, calls `is.width(0)` to cancel the effects of [std::setw](https://en.cppreference.com/w/cpp/io/manip/setw), if any.
    friend std::basic_istream<char>& operator >>(std::basic_istream<char>& stream, basic_string & str) {
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
    friend std::basic_istream<xtd::wchar>& operator >>(std::basic_istream<xtd::wchar>& stream, basic_string & str) {
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
    bool is_empty() const noexcept {return is_empty(self_);}
    /// @brief Gets the class name of the object_t.
    /// @return The class name of the object_t.
    /// @remarks For example, the name of the basic_string type is basic_string.
    /// @deprecated Replaced by typeof_<object_t>().name() - Will be removed in version 0.4.0.
    /// @}
    
    /// Name Public Deprecated Static Methods
    
    template<class object_t>
    [[deprecated("Replaced by typeof_<object_t>().name() - Will be removed in version 0.4.0.")]]
    static basic_string class_name() {return get_class_name(full_class_name<object_t>());}
    /// @brief Gets the class name of the specified object.
    /// @return The class name of the specified object.
    /// @remarks For example, the name of the basic_string type is basic_string.
    /// @deprecated Replaced by typeof_(object).name() - Will be removed in version 0.4.0.
    template<class object_t>
    [[deprecated("Replaced by typeof_(object).name() - Will be removed in version 0.4.0.")]]
    static basic_string class_name(const object_t& object) {return get_class_name(full_class_name(object));}
    /// @brief Gets the class name of the specified object.
    /// @return The class name of the specified object.
    /// @remarks For example, the name of the basic_string type is basic_string.
    /// @deprecated Replaced by typeof_(info).name() - Will be removed in version 0.4.0.
    [[deprecated("Replaced by typeof_(info).name() - Will be removed in version 0.4.0.")]]
    static basic_string class_name(const std::type_info & info) {return __xtd_get_class_name(info);}
    /// @brief Gets the fully qualified class name of the objec_t, including the namespace of the objec_t.
    /// @return The fully qualified class name of the objec_t, including the namespace of the objec_t.
    /// @remarks For example, the fully qualified name of the basic_string type is xtd::basic_string.
    /// @deprecated Replaced by typeof_<object_t>().full_name() - Will be removed in version 0.4.0.
    template<class object_t>
    [[deprecated("Replaced by typeof_<object_t>().full_name() - Will be removed in version 0.4.0.")]]
    static basic_string full_class_name() {return demangle(typeid(object_t).name());}
    /// @brief Gets the fully qualified class name of the specified object, including the namespace of the specified object.
    /// @return The fully qualified class name of the objec_t, including the namespace of the specified object.
    /// @remarks For example, the fully qualified name of the basic_string type is xtd::basic_string.
    /// @deprecated Replaced by typeof_(object).full_name() - Will be removed in version 0.4.0.
    template<class object_t>
    [[deprecated("Replaced by typeof_(object).full_name() - Will be removed in version 0.4.0.")]]
    static basic_string full_class_name(const object_t& object) {return demangle(typeid(object).name());}
    /// @brief Gets the fully qualified class name of the specified object, including the namespace of the specified object.
    /// @return The fully qualified class name of the objec_t, including the namespace of the specified object.
    /// @remarks For example, the fully qualified name of the basic_string type is xtd::basic_string.
    /// @deprecated Replaced by typeof_(info).full_name() - Will be removed in version 0.4.0.
    [[deprecated("Replaced by typeof_(info).full_name() - Will be removed in version 0.4.0.")]]
    static basic_string full_class_name(const std::type_info & info) {return __xtd_get_full_class_name(info);}
    /// @}
    
  private:
    friend class basic_string<char>;
    friend class basic_string<xtd::char16>;
    friend class basic_string<xtd::char32>;
    friend class basic_string<xtd::char8>;
    friend class basic_string<xtd::wchar>;
    
    static const xtd::array<value_type> default_split_separators;
    static const xtd::array<value_type> default_trim_chars;
    
    template<class arg_t>
    inline static auto convert_param(arg_t&& arg) noexcept {
      if constexpr(std::is_same<std::remove_cv_t<std::remove_reference_t<arg_t>>, std::string>::value) return std::forward<arg_t>(arg).c_str();
      else if constexpr(std::is_same<std::remove_cv_t<std::remove_reference_t<arg_t>>, std::u16string>::value) return std::forward<arg_t>(arg).c_str();
      else if constexpr(std::is_same<std::remove_cv_t<std::remove_reference_t<arg_t>>, std::u32string>::value) return std::forward<arg_t>(arg).c_str();
      else if constexpr(std::is_same<std::remove_cv_t<std::remove_reference_t<arg_t>>, std::u8string>::value) return std::forward<arg_t>(arg).c_str();
      else if constexpr(std::is_same<std::remove_cv_t<std::remove_reference_t<arg_t>>, std::wstring>::value) return std::forward<arg_t>(arg).c_str();
      else if constexpr(std::is_same<std::remove_cv_t<std::remove_reference_t<arg_t>>, basic_string>::value) return std::forward<arg_t>(arg).c_str();
      else return std::forward<arg_t>(arg);
    }
    
    static basic_string get_class_name(const basic_string & full_name) {
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
