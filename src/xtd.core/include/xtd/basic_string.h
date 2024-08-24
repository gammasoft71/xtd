/// @file
/// @brief Contains xtd::basic_string class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#define __XTD_CORE_INTERNAL__
#include "internal/__format_information.h"
#include "internal/__sprintf.h"
#include "internal/__string_definitions.h"
#undef __XTD_CORE_INTERNAL__
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.h"
#undef __XTD_STD_INTERNAL__
/// @endcond
#include "collections/generic/ienumerable.h"
#include "hash_code.h"
#include "icomparable.h"
#include "iequatable.h"
#include "null.h"
#include "string_comparison.h"
#include "string_split_options.h"
#include "types.h"
#include "object.h"
#include "parse.h"
#include "to_string.h"
#include "types.h"
#include "unused.h"
#include <cctype>
#if defined(__xtd__cpp_lib_format)
#include <format>
#endif
#include <ostream>
#include <string>

/// @cond
template<typename ...args_t>
void __basic_string_extract_format_arg(xtd::basic_string<char>& fmt, std::vector<__format_information<char>>& formats, args_t&&... args);
template<typename target_t, typename source_t>
std::basic_string<target_t> __xtd_convert_to_string(std::basic_string<source_t>&& str) noexcept;
template<typename target_t, typename source_t>
std::basic_string<target_t> __xtd_convert_to_string(const std::basic_string<source_t>& str) noexcept;
void __throw_basic_string_argument_exception(const char* file, xtd::uint32 line, const char* func);
void __throw_basic_string_format_exception(const char* file, xtd::uint32 line, const char* func);
void __throw_basic_string_format_exception_close_bracket(const char* file, xtd::uint32 line, const char* func);
void __throw_basic_string_format_exception_open_bracket(const char* file, xtd::uint32 line, const char* func);
void __throw_basic_string_format_exception_start_colon(const char* file, xtd::uint32 line, const char* func);
void __throw_basic_string_index_out_of_range_exception(const char* file, xtd::uint32 line, const char* func);
void __throw_basic_string_null_pointer_exception(const char* file, xtd::uint32 line, const char* func);
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
  class basic_string : public object, public xtd::icomparable<basic_string<char_t, traits_t, allocator_t>>, public xtd::iequatable<basic_string<char_t, traits_t, allocator_t>>, public xtd::collections::generic::ienumerable<char_t> {
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
    using iterator = xtd::collections::generic::ienumerable<char_t>::iterator;
    /// @brief Represents the basic string const iterator type.
    /// @todo replace xtd::ienumerable::const_iterator
    using const_iterator = xtd::collections::generic::ienumerable<char_t>::const_iterator;
    /// @brief Represents the basic string reverse iterator type.
    using reverse_iterator = base_type::reverse_iterator;
    /// @brief Represents the basic string const reverse iterator type.
    using const_reverse_iterator = base_type::const_reverse_iterator;
    /// @brief Represents the basic string enumerator type.
    using enumerator_type = xtd::collections::generic::enumerator<value_type>;
    /// @}

    /// @name Public Fields
    
    /// @{
    /// @brief Represents the empty basic_string.
    /// @remarks The value of this method is the zero-length basic_string, "".
    static const basic_string empty_string;
    
    /// @brief This is a special value equal to the maximum value representable by the type xtd::size.
    inline static constexpr size_type npos = base_type::npos;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes a new instance of xtd::basic_string.
    basic_string() = default;
    /// @brief Initializes a new instance of xtd::basic_string with specified allocator.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    explicit basic_string(const allocator_type& allocator) noexcept : chars_(allocator) {}

    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const basic_string<char>& str) noexcept : chars_(__xtd_convert_to_string<value_type>(str.chars_)) {}

    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const basic_string<xtd::char16>& str) noexcept : chars_(__xtd_convert_to_string<value_type>(str.chars_)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const basic_string<xtd::char32>& str) noexcept : chars_(__xtd_convert_to_string<value_type>(str.chars_)) {}
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const basic_string<xtd::char8>& str) noexcept : chars_(__xtd_convert_to_string<value_type>(str.chars_)) {}
#endif
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const basic_string<xtd::wchar>& str) noexcept : chars_(__xtd_convert_to_string<value_type>(str.chars_)) {}

    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy and allocator.
    /// @param str The string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const basic_string<char>& str, const allocator_type& allocator) noexcept : chars_(__xtd_convert_to_string<value_type>(str.chars_), allocator) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy and allocator.
    /// @param str The string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const basic_string<xtd::char16>& str, const allocator_type& allocator) noexcept : chars_(__xtd_convert_to_string<value_type>(str.chars_), allocator) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy and allocator.
    /// @param str The string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const basic_string<xtd::char32>& str, const allocator_type& allocator) noexcept : chars_(__xtd_convert_to_string<value_type>(str.chars_), allocator) {}
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy and allocator.
    /// @param str The string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const basic_string<xtd::char8>& str, const allocator_type& allocator) noexcept : chars_(__xtd_convert_to_string<value_type>(str.chars_), allocator) {}
#endif
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy and allocator.
    /// @param str The string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const basic_string<xtd::wchar>& str, const allocator_type& allocator) noexcept : chars_(__xtd_convert_to_string<value_type>(str.chars_), allocator) {}

    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @exception xtd::index_out_of_range_exception `index` is greater or equal than `str` size.
    basic_string(const basic_string<char>& str, xtd::size index) {
      if (index > str.size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<char>(str.chars_, index)));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @exception xtd::index_out_of_range_exception `index` is greater or equal than `str` size.
    basic_string(const basic_string<xtd::char16>& str, xtd::size index) {
      if (index > str.size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::char16>(str.chars_, index)));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @exception xtd::index_out_of_range_exception `index` is greater or equal than `str` size.
    basic_string(const basic_string<xtd::char32>& str, xtd::size index) {
      if (index > str.size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::char32>(str.chars_, index)));
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @exception xtd::index_out_of_range_exception `index` is greater or equal than `str` size.
    basic_string(const basic_string<xtd::char8>& str, xtd::size index) {
      if (index > str.size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::char8>(str.chars_, index)));
    }
#endif
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @exception xtd::index_out_of_range_exception `index` is greater or equal than `str` size.
    basic_string(const basic_string<xtd::wchar>& str, xtd::size index) {
      if (index > str.size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::wchar>(str.chars_, index)));
    }

    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index and allocator.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    /// @exception xtd::index_out_of_range_exception `index` is greater or equal than `str` size.
    basic_string(const basic_string<char>& str, xtd::size index, const allocator_type& allocator) {
      if (index > str.size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<char>(str.chars_, index)), allocator);
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index and allocator.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    /// @exception xtd::index_out_of_range_exception `index` is greater or equal than `str` size.
    basic_string(const basic_string<xtd::char16>& str, xtd::size index, const allocator_type& allocator) {
      if (index > str.size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::char16>(str.chars_, index)), allocator);
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index and allocator.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    /// @exception xtd::index_out_of_range_exception `index` is greater or equal than `str` size.
    basic_string(const basic_string<xtd::char32>& str, xtd::size index, const allocator_type& allocator) {
      if (index > str.size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::char32>(str.chars_, index)), allocator);
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index and allocator.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    /// @exception xtd::index_out_of_range_exception `index` is greater or equal than `str` size.
    basic_string(const basic_string<xtd::char8>& str, xtd::size index, const allocator_type& allocator) {
      if (index > str.size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::char8>(str.chars_, index)), allocator);
    }
#endif
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index and allocator.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    /// @exception xtd::index_out_of_range_exception `index` is greater or equal than `str` size.
    basic_string(const basic_string<xtd::wchar>& str, xtd::size index, const allocator_type& allocator) {
      if (index > str.size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::wchar>(str.chars_, index)), allocator);
    }

    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index and count characters.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    /// @exception xtd::index_out_of_range_exception `index` + `count`is greater or equal than `str` size.
    basic_string(const basic_string<char>& str, xtd::size index, xtd::size count) {
      if (index + count > str.size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<char>(str.chars_, index, count)));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index and count characters.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    /// @exception xtd::index_out_of_range_exception `index` + `count`is greater or equal than `str` size.
    basic_string(const basic_string<xtd::char16>& str, xtd::size index, xtd::size count) {
      if (index + count > str.size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::char16>(str.chars_, index, count)));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index and count characters.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    /// @exception xtd::index_out_of_range_exception `index` + `count`is greater or equal than `str` size.
    basic_string(const basic_string<xtd::char32>& str, xtd::size index, xtd::size count) {
      if (index + count > str.size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::char32>(str.chars_, index, count)));
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index and count characters.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    /// @exception xtd::index_out_of_range_exception `index` + `count`is greater or equal than `str` size.
    basic_string(const basic_string<xtd::char8>& str, xtd::size index, xtd::size count) {
      if (index + count > str.size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::char8>(str.chars_, index, count)));
    }
#endif
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index and count characters.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    /// @exception xtd::index_out_of_range_exception `index` + `count`is greater or equal than `str` size.
    basic_string(const basic_string<xtd::wchar>& str, xtd::size index, xtd::size count) {
      if (index + count > str.size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::wchar>(str.chars_, index, count)));
    }

    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index, count characters and allocator.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    /// @exception xtd::index_out_of_range_exception `index` + `count`is greater or equal than `str` size.
    basic_string(const basic_string<char>& str, xtd::size index, xtd::size count, const allocator_type& allocator) {
      if (index + count > str.size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<char>(str.chars_, index, count)), allocator);
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index, count characters and allocator.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    /// @exception xtd::index_out_of_range_exception `index` + `count`is greater or equal than `str` size.
    basic_string(const basic_string<xtd::char16>& str, xtd::size index, xtd::size count, const allocator_type& allocator) {
      if (index + count > str.size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::char16>(str.chars_, index, count)), allocator);
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index, count characters and allocator.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    /// @exception xtd::index_out_of_range_exception `index` + `count`is greater or equal than `str` size.
    basic_string(const basic_string<xtd::char32>& str, xtd::size index, xtd::size count, const allocator_type& allocator) {
      if (index + count > str.size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::char32>(str.chars_, index, count)), allocator);
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index, count characters and allocator.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    /// @exception xtd::index_out_of_range_exception `index` + `count`is greater or equal than `str` size.
    basic_string(const basic_string<xtd::char8>& str, xtd::size index, xtd::size count, const allocator_type& allocator) {
      if (index + count > str.size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::char8>(str.chars_, index, count)), allocator);
    }
#endif
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index, count characters and allocator.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    /// @exception xtd::index_out_of_range_exception `index` + `count`is greater or equal than `str` size.
    basic_string(const basic_string<xtd::wchar>& str, xtd::size index, xtd::size count, const allocator_type& allocator) {
      if (index + count > str.size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      chars_ = base_type(__xtd_convert_to_string<value_type>(std::basic_string<xtd::wchar>(str.chars_, index, count)), allocator);
    }

    /// @brief Initializes a new instance of xtd::basic_string with specified string to move.
    /// @param str The basic_string to move.
    basic_string(basic_string<char>&& str) noexcept : chars_(std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_)))) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified string to move.
    /// @param str The basic_string to move.
    basic_string(basic_string<xtd::char16>&& str) noexcept : chars_(std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_)))) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified string to move.
    /// @param str The basic_string to move.
    basic_string(basic_string<xtd::char32>&& str) noexcept : chars_(std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_)))) {}
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Initializes a new instance of xtd::basic_string with specified string to move.
    /// @param str The basic_string to move.
    basic_string(basic_string<xtd::char8>&& str) noexcept : chars_(std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_)))) {}
#endif
    /// @brief Initializes a new instance of xtd::basic_string with specified string to move.
    /// @param str The basic_string to move.
    basic_string(basic_string<xtd::wchar>&& str) noexcept : chars_(std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_)))) {}

    /// @brief Initializes a new instance of xtd::basic_string with specified string to move and allocator.
    /// @param str The basic_string to move.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(basic_string<char>&& str, const allocator_type& allocator) noexcept : chars_(std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_))), allocator) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified string to move and allocator.
    /// @param str The basic_string to move.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(basic_string<xtd::char16>&& str, const allocator_type& allocator) noexcept : chars_(std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_))), allocator) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified string to move and allocator.
    /// @param str The basic_string to move.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(basic_string<xtd::char32>&& str, const allocator_type& allocator) noexcept : chars_(std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_))), allocator) {}
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Initializes a new instance of xtd::basic_string with specified string to move and allocator.
    /// @param str The basic_string to move.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(basic_string<xtd::char8>&& str, const allocator_type& allocator) noexcept : chars_(std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_))), allocator) {}
#endif
    /// @brief Initializes a new instance of xtd::basic_string with specified string to move and allocator.
    /// @param str The basic_string to move.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(basic_string<xtd::wchar>&& str, const allocator_type& allocator) noexcept : chars_(std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_))), allocator) {}

    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character.
    /// @param str The string to copy.
    /// @param count The number of copies of character.
    /// @param character The character copied.
    basic_string(xtd::size count, char character) : basic_string(std::basic_string<char>(count, character)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character and specified allocator.
    /// @param str The string to copy.
    /// @param count The number of copies of character.
    /// @param character The character copied.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(xtd::size count, char character, const allocator_type& allocator) : basic_string(std::basic_string<char>(count, character), allocator) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character.
    /// @param str The string to copy.
    /// @param count The number of copies of character.
    /// @param character The character copied.
    basic_string(xtd::size count, xtd::char16 character) : basic_string(std::basic_string<xtd::char16>(count, character)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character and specified allocator.
    /// @param str The string to copy.
    /// @param count The number of copies of character.
    /// @param character The character copied.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(xtd::size count, xtd::char16 character, const allocator_type& allocator) : basic_string(std::basic_string<xtd::char16>(count, character), allocator) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character.
    /// @param str The string to copy.
    /// @param count The number of copies of character.
    /// @param character The character copied.
    basic_string(xtd::size count, xtd::char32 character) : basic_string(std::basic_string<xtd::char32>(count, character)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character and specified allocator.
    /// @param str The string to copy.
    /// @param count The number of copies of character.
    /// @param character The character copied.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(xtd::size count, xtd::char32 character, const allocator_type& allocator) : basic_string(std::basic_string<xtd::char32>(count, character), allocator) {}
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character.
    /// @param str The string to copy.
    /// @param count The number of copies of character.
    /// @param character The character copied.
    basic_string(xtd::size count, xtd::char8 character) : basic_string(std::basic_string<xtd::char8>(count, character)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character and specified allocator.
    /// @param str The string to copy.
    /// @param count The number of copies of character.
    /// @param character The character copied.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(xtd::size count, xtd::char8 character, const allocator_type& allocator) : basic_string(std::basic_string<xtd::char8>(count, character), allocator) {}
#endif
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character.
    /// @param str The string to copy.
    /// @param count The number of copies of character.
    /// @param character The character copied.
    basic_string(xtd::size count, xtd::wchar character) : basic_string(std::basic_string<xtd::wchar>(count, character)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character and specified allocator.
    /// @param str The string to copy.
    /// @param count The number of copies of character.
    /// @param character The character copied.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(xtd::size count, xtd::wchar character, const allocator_type& allocator) : basic_string(std::basic_string<xtd::wchar>(count, character), allocator) {}

    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const char* str) {  // Can't be explicit by design.
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<char>(str));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const xtd::char16* str) {  // Can't be explicit by design.
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char16>(str));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const xtd::char32* str) {  // Can't be explicit by design.
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char32>(str));
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const xtd::char8* str) {  // Can't be explicit by design.
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char8>(str));
    }
#endif
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const xtd::wchar* str) {  // Can't be explicit by design.
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::wchar>(str));
    }

    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy, and allocator.
    /// @param str The string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const char* str, const allocator_type& allocator) : chars_(allocator) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<char>(str));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy, and allocator.
    /// @param str The string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const xtd::char16* str, const allocator_type& allocator) : chars_(allocator) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char16>(str));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy, and allocator.
    /// @param str The string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const xtd::char32* str, const allocator_type& allocator) : chars_(allocator) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char32>(str));
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy, and allocator.
    /// @param str The string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const xtd::char8* str, const allocator_type& allocator) : chars_(allocator) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char8>(str));
    }
#endif
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy, and allocator.
    /// @param str The string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const xtd::wchar* str, const allocator_type& allocator) : chars_(allocator) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::wchar>(str));
    }

    /// @brief Initializes a new instance of xtd::basic_string with specified substring and count characters.
    /// @param count The number of substring characters to copy.
    basic_string(const char* str, xtd::size count) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<char>(str, count));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring and count characters.
    /// @param count The number of substring characters to copy.
    basic_string(const xtd::char16* str, xtd::size count) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char16>(str, count));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring and count characters.
    /// @param count The number of substring characters to copy.
    basic_string(const xtd::char32* str, xtd::size count) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char32>(str, count));
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Initializes a new instance of xtd::basic_string with specified substring and count characters.
    /// @param count The number of substring characters to copy.
    basic_string(const xtd::char8* str, xtd::size count) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char8>(str, count));
    }
#endif
    /// @brief Initializes a new instance of xtd::basic_string with specified substring and count characters.
    /// @param count The number of substring characters to copy.
    basic_string(const xtd::wchar* str, xtd::size count) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::wchar>(str, count));
    }

    /// @brief Initializes a new instance of xtd::basic_string with specified substring, count characters and allocator.
    /// @param str The string to copy.
    /// @param count The number of substring characters to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const char* str, xtd::size count, const allocator_type& allocator) : chars_(allocator) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<char>(str, count));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring, count characters and allocator.
    /// @param str The string to copy.
    /// @param count The number of substring characters to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const xtd::char16* str, xtd::size count, const allocator_type& allocator) : chars_(allocator) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char16>(str, count));
    }
    /// @brief Initializes a new instance of xtd::basic_string with specified substring, count characters and allocator.
    /// @param str The string to copy.
    /// @param count The number of substring characters to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const xtd::char32* str, xtd::size count, const allocator_type& allocator) : chars_(allocator) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char32>(str, count));
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Initializes a new instance of xtd::basic_string with specified substring, count characters and allocator.
    /// @param str The string to copy.
    /// @param count The number of substring characters to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const xtd::char8* str, xtd::size count, const allocator_type& allocator) : chars_(allocator) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char8>(str, count));
    }
#endif
    /// @brief Initializes a new instance of xtd::basic_string with specified substring, count characters and allocator.
    /// @param str The string to copy.
    /// @param count The number of substring characters to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const xtd::wchar* str, xtd::size count, const allocator_type& allocator) : chars_(allocator) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::wchar>(str, count));
    }

    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const std::basic_string<char>& str) noexcept : chars_(__xtd_convert_to_string<value_type>(str)) {}; // Can't be explicit by design.
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const std::basic_string<xtd::char16>& str) noexcept : chars_(__xtd_convert_to_string<value_type>(str)) {}; // Can't be explicit by design.
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const std::basic_string<xtd::char32>& str) noexcept : chars_(__xtd_convert_to_string<value_type>(str)) {}; // Can't be explicit by design.
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const std::basic_string<xtd::char8>& str) noexcept : chars_(__xtd_convert_to_string<value_type>(str)) {}; // Can't be explicit by design.
#endif
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const std::basic_string<xtd::wchar>& str) noexcept : chars_(__xtd_convert_to_string<value_type>(str)) {}; // Can't be explicit by design.

    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy and allocator.
    /// @param str The string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const std::basic_string<char>& str, const allocator_type& allocator) noexcept : chars_(__xtd_convert_to_string<value_type>(str), allocator) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy and allocator.
    /// @param str The string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const std::basic_string<xtd::char16>& str, const allocator_type& allocator) noexcept : chars_(__xtd_convert_to_string<value_type>(str), allocator) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy and allocator.
    /// @param str The string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const std::basic_string<xtd::char32>& str, const allocator_type& allocator) noexcept : chars_(__xtd_convert_to_string<value_type>(str), allocator) {}
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy and allocator.
    /// @param str The string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const std::basic_string<xtd::char8>& str, const allocator_type& allocator) noexcept : chars_(__xtd_convert_to_string<value_type>(str), allocator) {}
#endif
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy and allocator.
    /// @param str The string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const std::basic_string<xtd::wchar>& str, const allocator_type& allocator) noexcept : chars_(__xtd_convert_to_string<value_type>(str), allocator) {}

    /// @brief Initializes a new instance of xtd::basic_string with specified first and last iterators of substring.
    /// @param first The first iterator of substring.
    /// @param last The first iterator of substring.
    template<typename input_iterator_t>
    basic_string(input_iterator_t first, input_iterator_t last) : chars_(first, last) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified first and last iterators of substring and allocator.
    /// @param first The first iterator of substring.
    /// @param last The first iterator of substring.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    template<typename input_iterator_t>
    basic_string(input_iterator_t first, input_iterator_t last, const allocator_type& allocator) : chars_(first, last, allocator) {}

    /// @brief Initializes a new instance of xtd::basic_string with specified string view of substring and allocator.
    /// @param string_view The basic_string view.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    template<typename string_view_like_t>
    explicit constexpr basic_string(const string_view_like_t& string_view) : chars_(string_view) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified string view of substring and allocator.
    /// @param string_view The basic_string view.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    template<typename string_view_like_t>
    explicit constexpr basic_string(const string_view_like_t& string_view, const allocator_type& allocator) : chars_(string_view, allocator) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified string view of substring and allocator.
    /// @param string_view The basic_string view.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    template<typename string_view_like_t>
    constexpr basic_string(const string_view_like_t& string_view, size_type index, size_type count) : chars_(string_view, index, count) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified string view of substring and allocator.
    /// @param string_view The basic_string view.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    template<typename string_view_like_t>
    constexpr basic_string(const string_view_like_t& string_view, size_type index, size_type count, const allocator_type& allocator) : chars_(string_view, index, count, allocator) {}

    /// @brief Initializes a new instance of xtd::basic_string with specified initializer list.
    /// @param il The initializer list to fill.
    basic_string(std::initializer_list<char> il) : basic_string(std::basic_string<char>(il)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified initializer list.
    /// @param il The initializer list to fill.
    basic_string(std::initializer_list<xtd::char16> il) : basic_string(std::basic_string<xtd::char16>(il)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified initializer list.
    /// @param il The initializer list to fill.
    basic_string(std::initializer_list<xtd::char32> il) : basic_string(std::basic_string<xtd::char32>(il)) {}
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Initializes a new instance of xtd::basic_string with specified initializer list.
    /// @param il The initializer list to fill.
    basic_string(std::initializer_list<xtd::char8> il) : basic_string(std::basic_string<xtd::char8>(il)) {}
#endif
    /// @brief Initializes a new instance of xtd::basic_string with specified initializer list.
    /// @param il The initializer list to fill.
    basic_string(std::initializer_list<xtd::wchar> il) : basic_string(std::basic_string<xtd::wchar>(il)) {}

    /// @brief Initializes a new instance of xtd::basic_string with specified initializer list and allocator.
    /// @param il The initializer list to fill.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(std::initializer_list<char> il, const allocator_type& allocator) : basic_string(std::basic_string<char>(il), allocator) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified initializer list and allocator.
    /// @param il The initializer list to fill.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(std::initializer_list<xtd::char16> il, const allocator_type& allocator) : basic_string(std::basic_string<xtd::char16>(il), allocator) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified initializer list and allocator.
    /// @param il The initializer list to fill.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(std::initializer_list<xtd::char32> il, const allocator_type& allocator) : basic_string(std::basic_string<xtd::char32>(il), allocator) {}
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Initializes a new instance of xtd::basic_string with specified initializer list and allocator.
    /// @param il The initializer list to fill.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(std::initializer_list<xtd::char8> il, const allocator_type& allocator) : basic_string(std::basic_string<xtd::char8>(il), allocator) {}
#endif
    /// @brief Initializes a new instance of xtd::basic_string with specified initializer list and allocator.
    /// @param il The initializer list to fill.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(std::initializer_list<xtd::wchar> il, const allocator_type& allocator) : basic_string(std::basic_string<xtd::wchar>(il), allocator) {}
    /// @}
    
    /// @name Public Properties
    
    /// @{
    /// @brief Returns reference to the last character in the string.
    /// @return Reference to the last character, equivalent to `operator[](size() - 1)`.
    /// @exception xtd::index_out_of_range_exception If is empty.
    const_reference back() const {return operator[](size() - 1);}
    
    /// @brief Returns an iterator to the first character of the string.
    /// @return Iterator to the first character.
    const_iterator begin() const override {return xtd::collections::generic::ienumerable<value_type>::begin();}
    
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
    
    /// @brief Returns an iterator to the first character of the string.
    /// @return Iterator to the first character.
    const_iterator cbegin() const override {return xtd::collections::generic::ienumerable<value_type>::cbegin();}
    
    /// @brief Returns a reference to the underlying base type.
    /// @return Reference to the underlying base type.
    const base_type& chars() const noexcept {return chars_;}

    /// @brief Returns an iterator to the character following the last character of the string. This character acts as a placeholder, attempting to access it results in undefined behavior.
    /// @return Iterator to the character following the last character.
    const_iterator cend() const override {return xtd::collections::generic::ienumerable<value_type>::cend();}

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
    const_iterator end() const override {return xtd::collections::generic::ienumerable<value_type>::end();}
    
    /// @brief Returns reference to the first character in the string. The behavior is undefined if empty() is true.
    /// @return Reference to the first character, equivalent to `operator[](0)`.
    /// @exception xtd::index_out_of_range_exception If is empty.
    const_reference front() const {return operator[](0);}

    /// @brief Gets the number of characters in the current xtd::basic_string object.
    /// @return The number of characters in the current string.
    /// @remarks The xtd::basic_string::length property returns the number of xtd::basic_string::value_type objects in this instance, not the number of Unicode characters. The reason is that a Unicode character might be represented by more than one xtd::basic_string::value_type.
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
    int32 compare(const basic_string& str) const {return chars_.compare(str);}
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
    int32 compare(size_type pos1, size_type count1, const basic_string& str) const {return chars_.compare(pos1, count1, str);}
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
    int32 compare(size_type pos1, size_type count1, const basic_string& str, size_type pos2) const {return chars_.compare(pos1, count1, str, pos2);}
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
    int32 compare(size_type pos1, size_type count1, const basic_string& str, size_type pos2, size_type count2) const {return chars_.compare(pos1, count1, str, pos2, count2);}
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

    /// @brief Compares this instance with a specified xtd::object and indicates whether this instance precedes, follows, or appears in the same position in the sort order as the specified xtd::object.
    /// @param value An object that evaluates to a xtd::basic_string.
    /// @return A 32-bit signed integer that indicates whether this instance precedes, follows, or appears in the same position in the sort order as the value parameter.
    /// | Value             | Condition                                                         |
    /// | ----------------- | ----------------------------------------------------------------- |
    /// | Less than zero    | This instance precedes `value`.                                   |
    /// | Zero              | This instance has the same position in the sort order as `value`. |
    /// | Greater than zero | This instance follows `value`.                                    |
    /// @exception xtd::argument_exception `value` is not a xtd::basic_string.
    int32 compare_to(const object& value) const {
      if (!dynamic_cast<const basic_string*>(&value)) __throw_basic_string_argument_exception(__FILE__, __LINE__, __func__);
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
    int32 compare_to(const basic_string& value) const noexcept override {return chars_.compare(value.chars_);}

    /// @brief Determines whether this instance and a specified object, which must also be a xtd::basic_string object, have the same value.
    /// @param obj The basic_string to compare to this instance.
    /// @return `true` if `obj` is a xtd::basic_string and its value is the same as this instance; otherwise, `false`.
    bool equals(const object& obj) const noexcept override {return dynamic_cast<const basic_string*>(&obj) && equals(static_cast<const basic_string&>(obj));}
    /// @brief Determines whether this instance and another specified xtd::basic_string object have the same value.
    /// @param value The basic_string to compare to this instance.
    /// @return `true` if the `value` of the value parameter is the same as the value of this instance; otherwise, `false`.
    /// @remarks This method performs an ordinal (case-sensitive) comparison.
    bool equals(const basic_string& value) const noexcept override {return equals(value, false);}
    /// @brief Determines whether this instance and another specified xtd::basic_string object have the same value, ignoring or honoring their case.
    /// @param value The basic_string to compare to this instance.
    /// @param ignore_case true to ignore case when comparing this instance and value; otherwise, false
    /// @return `true` if the `value` of the value parameter is the same as the value of this instance; otherwise, `false`.
    /// @remarks This method performs an ordinal comparison.
    bool equals(const basic_string& value, bool ignore_case) const noexcept {
      if (ignore_case) return to_upper().chars_ == value.to_upper().chars_;
      return chars_ == value.chars_;
    }
    
    /// @brief Finds the first substring equal to the given character sequence. Search begins at `0`, i.e. the found substring must not begin in a position preceding `0`.
    /// @return Position of the first character of the found substring or xtd::basic_string::npos if no such substring is found.
    /// @remarks Finds the first substring equal to `str`.
    size_type find(const basic_string& str) const {return chars_.find(str);}
    /// @brief Finds the first substring equal to the given character sequence. Search begins at `pos`, i.e. the found substring must not begin in a position preceding `pos`.
    /// @param str The string to search for.
    /// @param pos The position at which to start the search
    /// @return Position of the first character of the found substring or xtd::basic_string::npos if no such substring is found.
    /// @remarks Finds the first substring equal to `str`.
    size_type find(const basic_string& str, size_type pos) const {return chars_.find(str, pos);}
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
    size_type find_first_of(const basic_string& str) const {return chars_.find_first_of(str);}
    /// @brief Finds the first character equal to one of the characters in the given character sequence. The search considers only the range [`pos`, size()). If none of the characters in the given character sequence is present in the range, xtd::basic_string::npos will be returned.
    /// @param str The string identifying characters to search for.
    /// @param pos The position at which to begin searching.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in `str`.
    size_type find_first_of(const basic_string& str, size_type pos) const {return chars_.find_first_of(str, pos);}
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
    size_type find_first_not_of(const basic_string& str) const {return chars_.find_first_not_of(str);}
    /// @brief Finds the first character equal to none of the characters in the given character sequence. The search considers only the range [`pos`, size()). If all characters in the range can be found in the given character sequence, xtd::basic_string::npos will be returned.
    /// @param str The string identifying characters to search for.
    /// @param pos The position at which to begin searching.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in `str`.
    size_type find_first_not_of(const basic_string& str, size_type pos) const {return chars_.find_first_not_of(str, pos);}
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
    size_type find_last_of(const basic_string& str) const {return chars_.find_last_of(str);}
    /// @brief Finds the last character equal to one of characters in the given character sequence. The exact search algorithm is not specified. The search considers only the range [​`0`​, `pos`]. If none of the characters in the given character sequence is present in the range, xtd::basic_string::npos will be returned.
    /// @param str The string identifying characters to search for.
    /// @param pos The position at which to begin searching.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in `str`.
    size_type find_last_of(const basic_string& str, size_type pos) const {return chars_.find_last_of(str, pos);}
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
    size_type find_last_not_of(const basic_string& str) const {return chars_.find_last_not_of(str);}
    /// @brief Finds the last character equal to none of the characters in the given character sequence. The search considers only the range [​`0`​, `pos`]. If all characters in the range can be found in the given character sequence,xtd::basic_string::npos will be returned.
    /// @param str The string identifying characters to search for.
    /// @param pos The position at which to begin searching.
    /// @return Position of the found character or xtd::basic_string::npos if no such character is found.
    /// @remarks Finds the first character equal to one of the characters in `str`.
    size_type find_last_not_of(const basic_string& str, size_type pos) const {return chars_.find_last_not_of(str, pos);}
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

    /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
    /// @param fmt A composite format string.
    /// @param args arguments list to write using format.
    /// @return string formatted.
    /// @ingroup format_parse
    /// @remarks for more information about format see @ref FormatPage "Format".
    template<typename ...args_t>
    static basic_string format(const basic_string<char>& fmt, args_t&& ... args) {
      auto result = basic_string<char> {};
      auto index = xtd::size {0};
      auto formats = std::vector<__format_information<char>> {};
      auto begin_format_iterator = fmt.end();
      auto end_format_iterator = fmt.end();
      for (auto iterator = fmt.begin(); iterator != fmt.end(); ++iterator) {
        if (*iterator == '{') {
          if (++iterator == fmt.end())
            __throw_basic_string_format_exception_open_bracket(__FILE__, __LINE__, __func__);
          if (*iterator == '{')
            result += *iterator;
          else {
            begin_format_iterator = iterator;
            while (iterator != fmt.end() && *iterator != '}') ++iterator;
            if (iterator == fmt.end())
              __throw_basic_string_format_exception_open_bracket(__FILE__, __LINE__, __func__);
            end_format_iterator = iterator;
            __format_information<char> fi;
            fi.location = result.size();
            auto format_str = std::basic_string<char> {begin_format_iterator, end_format_iterator};
            if (format_str.size() == 0)
              fi.index = index++;
            else {
              xtd::size index_alignment_separator = basic_string(format_str).index_of(',');
              xtd::size index_format_separator = basic_string(format_str).index_of(u':');
              
              if (index_alignment_separator != std::basic_string<char>::npos && index_format_separator != std::basic_string<char>::npos && index_alignment_separator > index_format_separator)
                index_alignment_separator = std::basic_string<char>::npos;
              
              if (index_alignment_separator != basic_string<char_t>::npos)
                fi.alignment = format_str.substr(index_alignment_separator + 1, index_format_separator != std::basic_string<char>::npos ? index_format_separator - index_alignment_separator - 1 : std::basic_string<char>::npos);
              
              if (index_format_separator != basic_string<char>::npos)
                fi.format = format_str.substr(index_format_separator + 1);
              
              if (index_alignment_separator == 0 || index_format_separator == 0)
                fi.index = index++;
              else {
                auto index_str = std::basic_string<char> {};
                if (index_alignment_separator != basic_string<char>::npos)
                  index_str = format_str.substr(0, index_alignment_separator);
                else if (index_format_separator != basic_string<char>::npos)
                  index_str = format_str.substr(0, index_format_separator);
                else
                  index_str = std::move(format_str);
                try {
                  for (auto c : index_str)
                    if (!std::isdigit(c)) __throw_basic_string_format_exception_start_colon(__FILE__, __LINE__, __func__);
                  fi.index = std::stoi(index_str);
                } catch (...) {
                  __throw_basic_string_format_exception_start_colon(__FILE__, __LINE__, __func__);
                }
              }
            }
            formats.push_back(fi);
          }
        } else if (*iterator == '}') {
          if (++iterator == fmt.end()) {
            __throw_basic_string_format_exception_close_bracket(__FILE__, __LINE__, __func__);
            break;
          }
          if (*iterator != '}') {
            __throw_basic_string_format_exception_close_bracket(__FILE__, __LINE__, __func__);
            break;
          }
          result += *iterator;
        } else
          result += *iterator;
      }
      
      __basic_string_extract_format_arg(result, formats, std::forward<args_t>(args)...);
      return result.c_str();
    }

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
      class basic_string_enumerator : public xtd::collections::generic::ienumerator<value_type> {
      public:
        explicit basic_string_enumerator(const basic_string& chars) : chars_(chars) {}
        
        const value_type& current() const override {return chars_[index_];}
        
        bool move_next() override {return ++index_ < chars_.size();}
        
        void reset() override {index_ = basic_string::npos;}
        
      protected:
        const basic_string& chars_;
        xtd::size index_ = basic_string::npos;
      };
      return {new_ptr<basic_string_enumerator>(*this)};
    }

    /// @brief Reports the index of the first occurrence of the specified basic_string in this basic_string.
    /// @param value An unicode character to seek
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    xtd::size index_of(const basic_string& value) const noexcept {return index_of(value, 0, size());}
    /// @brief Reports the index of the first occurrence of the specified character in this basic_string. The search starts at a specified character position.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    xtd::size index_of(const basic_string& value, xtd::size start_index) const {return index_of(value, start_index, size() - start_index);}
    /// @brief Reports the index of the first occurrence of the specified character in this basic_string. The search starts at a specified character position and examines a specified number of character positions.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    /// @exception xtd::index_out_of_range_exception start_index + count are greater than the length of this instance.
    xtd::size index_of(const basic_string& value, xtd::size start_index, xtd::size count) const {
      if (start_index > size() || start_index + count > size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      auto result = find(value, start_index);
      return result > start_index + count ? npos : result;
    }
    /// @brief Reports the index of the first occurrence of the specified character in this basic_string.
    /// @param value An unicode character to seek
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    xtd::size index_of(value_type value) const noexcept {return index_of(value, 0, size());}
    /// @brief Reports the index of the first occurrence of the specified character in this basic_string. The search starts at a specified character position.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    xtd::size index_of(value_type value, xtd::size start_index) const {return index_of(value, start_index, size() - start_index);}
    /// @brief Reports the index of the first occurrence of the specified character in this basic_string. The search starts at a specified character position and examines a specified number of character positions.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    /// @exception xtd::index_out_of_range_exception start_index + count are greater than the length of this instance.
    xtd::size index_of(value_type value, xtd::size start_index, xtd::size count) const {
      if (start_index > size() || start_index + count > size()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      auto result = find(value, start_index);
      return result > start_index + count ? npos : result;
    }

    /// @brief Indicates whether this basic_string is an empty basic_string ("").
    /// @return true if the value parameter is null or an empty basic_string (""); otherwise, false.
    /// @deprecated Replaced by xtd::basic_string::is_empty(const xtd::basic_string&) - Will be removed in version 0.4.0
    [[deprecated("Replaced by xtd::basic_string::is_empty(const xtd::basic_string&) - Will be removed in version 0.4.0")]]
    bool is_empty() const noexcept {return is_empty(*this);}
    
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
    basic_string pad_left(xtd::size total_width, char32 padding_char) const noexcept {return total_width < size() ? *this : basic_string(total_width - size(), padding_char) + *this;}
    
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
    basic_string pad_right(xtd::size total_width, char32 padding_char) const noexcept {return total_width < size() ? *this : *this + basic_string(total_width - size(), padding_char);}

    /// @brief Finds the last substring that is equal to the given character sequence. The search begins at xtd::basic_string::npos` and proceeds from right to left (thus, the found substring, if any, cannot begin in a position following xtd::basic_string::npos). If xtd::basic_string::npos or any value not smaller than xtd::basic_string::size() - 1 is passed as xtd::basic_string::npos, the whole string will be searched.
    /// @return Position of the first character of the found substring or xtd::basic_string::npos if no such substring is found.
    /// @remarks Finds the first substring equal to `str`.
    size_type rfind(const basic_string& str) const {return chars_.rfind(str);}
    /// @brief Finds the last substring that is equal to the given character sequence. The search begins at `pos` and proceeds from right to left (thus, the found substring, if any, cannot begin in a position following `pos`). If xtd::basic_string::npos or any value not smaller than xtd::basic_string::size() - 1 is passed as `pos`, the whole string will be searched.
    /// @param str The string to search for.
    /// @param pos The position at which to start the search
    /// @return Position of the first character of the found substring or xtd::basic_string::npos if no such substring is found.
    /// @remarks Finds the first substring equal to `str`.
    size_type rfind(const basic_string& str, size_type pos) const {return chars_.rfind(str, pos);}
    /// @brief Finds the last substring that is equal to the given character sequence. The search begins at `pos` and proceeds from right to left (thus, the found substring, if any, cannot begin in a position following `pos`). If xtd::basic_string::npos or any value not smaller than xtd::basic_string::size() - 1 is passed as `pos`, the whole string will be searched.
    /// @param str The string to search for.
    /// @param pos The position at which to start the search
    /// @param count The length of substring to search for.
    /// @return Position of the first character of the found substring or xtd::basic_string::npos if no such substring is found.
    /// @remarks Finds the first substring equal to the range [s, s + count).
    /// @remarks This range may contain null characters. If [`s`, `s + count`) is not a valid range, the behavior is undefined.
    size_type rfind(const_pointer s, size_type pos, size_type count) const {return chars_.rfind(s, pos, count);}
    /// @brief Finds the last substring that is equal to the given character sequence. The search begins at xtd::basic_string::npos` and proceeds from right to left (thus, the found substring, if any, cannot begin in a position following xtd::basic_string::npos). If xtd::basic_string::npos or any value not smaller than xtd::basic_string::size() - 1 is passed as xtd::basic_string::npos, the whole string will be searched.
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
    /// @brief Finds the last substring that is equal to the given character sequence. The search begins at xtd::basic_string::npos` and proceeds from right to left (thus, the found substring, if any, cannot begin in a position following xtd::basic_string::npos). If xtd::basic_string::npos or any value not smaller than xtd::basic_string::size() - 1 is passed as xtd::basic_string::npos, the whole string will be searched.
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
    
    /// @brief Splits this basic_string into substrings that are based on the default white-space characters. White-space characters are defined by the c++ standard and return true if they are passed to the xtd::char_object::isspace() or std::iswspace() method.
    /// @return An array whose elements contain the substrings in this basic_string that are delimited by one or more characters in white-space separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    std::vector<basic_string> split() const noexcept {return split(default_split_separators, std::numeric_limits<xtd::size>::max(), xtd::string_split_options::none);}
    /// @brief Splits this basic_string into substrings that are based on the characters in an array.
    /// @param separator A character that delimits the substrings in this basic_string.
    /// @return An array whose elements contain the substrings in this basic_string that are delimited by one or more characters in separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    std::vector<basic_string> split(value_type separator) const noexcept {return split(std::vector<value_type> {separator}, std::numeric_limits<xtd::size>::max(), xtd::string_split_options::none);}
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
    /// @remarks If the separator parameter contains no characters, white-space characters are assumed to be the delimiters. White-space characters are defined by the c++ standard and return true if they are passed to the xtd::char_object::isspace() or std::iswspace() method.
    /// @remarks If count is greater than the number of substrings, the available substrings are returned.
    std::vector<basic_string> split(value_type separator, xtd::string_split_options options) const noexcept {return split(std::vector<value_type> {separator}, std::numeric_limits<xtd::size>::max(), options);}
    /// @brief Splits this basic_string into a maximum number of substrings based on the characters in an array. You also specify the maximum number of substrings to return.
    /// @param separator A character array that delimits the substrings in this basic_string, an empty array that contains no delimiters.
    /// @param count The maximum number of substrings to return.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    /// @remarks If the separator parameter contains no characters, white-space characters are assumed to be the delimiters. White-space characters are defined by the Unicode standard and return true if they are passed to the char_t.IsWhiteSpace method.
    /// @remarks Each element of separator defines a separate delimiter character. If two delimiters are adjacent, or a delimiter is found at the beginning or end of the specified basic_string, the corresponding array element contains empty basic_string.
    /// @remarks If there are more than count substrings in the specified basic_string, the first count minus 1 substrings are returned in the first count minus 1 elements of the return value, and the remaining characters in the specified basic_string are returned in the last element of the return value.
    std::vector<basic_string> split(value_type separator, xtd::size count) const noexcept {return split(std::vector<value_type> {separator}, count, xtd::string_split_options::none);}
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
    std::vector<basic_string> split(value_type separator, xtd::size count, xtd::string_split_options options) const noexcept {return split(std::vector<value_type> {separator}, count, options);}

    /// @brief Splits this basic_string into substrings that are based on the characters in an array.
    /// @param separators A character array that delimits the substrings in this basic_string, an empty array that contains no delimiters.
    /// @return An array whose elements contain the substrings in this basic_string that are delimited by one or more characters in separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    std::vector<basic_string> split(const std::vector<value_type>& separators) const noexcept {return split(separators, std::numeric_limits<xtd::size>::max(), xtd::string_split_options::none);}
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
    /// @remarks If the separator parameter contains no characters, white-space characters are assumed to be the delimiters. White-space characters are defined by the c++ standard and return true if they are passed to the xtd::char_object::isspace() or std::iswspace() method.
    /// @remarks If count is greater than the number of substrings, the available substrings are returned.
    std::vector<basic_string> split(const std::vector<value_type>& separators, xtd::string_split_options options) const noexcept {return split(separators, std::numeric_limits<xtd::size>::max(), options);}
    /// @brief Splits this basic_string into a maximum number of substrings based on the characters in an array. You also specify the maximum number of substrings to return.
    /// @param separators A character array that delimits the substrings in this basic_string, an empty array that contains no delimiters.
    /// @param count The maximum number of substrings to return.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    /// @remarks If the separator parameter contains no characters, white-space characters are assumed to be the delimiters. White-space characters are defined by the Unicode standard and return true if they are passed to the char_t.IsWhiteSpace method.
    /// @remarks Each element of separator defines a separate delimiter character. If two delimiters are adjacent, or a delimiter is found at the beginning or end of the specified basic_string, the corresponding array element contains empty basic_string.
    /// @remarks If there are more than count substrings in the specified basic_string, the first count minus 1 substrings are returned in the first count minus 1 elements of the return value, and the remaining characters in the specified basic_string are returned in the last element of the return value.
    std::vector<basic_string> split(const std::vector<value_type>& separators, xtd::size count) const noexcept {return split(separators, count, xtd::string_split_options::none);}
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
    std::vector<basic_string> split(const std::vector<value_type>& separators, xtd::size count, xtd::string_split_options options) const noexcept {
      if (count == 0) return {};
      if (count == 1) return {*this};
      
      auto list = std::vector<basic_string> {};
      auto sub_string = basic_string::empty_string;
      auto split_char_separators = separators.size() == 0 ? default_split_separators : separators;
      for (auto it = begin(); it != end(); ++it) {
        auto is_separator = std::find(split_char_separators.begin(), split_char_separators.end(), *it) != split_char_separators.end();
        if (!is_separator) sub_string.chars_.append(basic_string(1, *it));
        if ((static_cast<xtd::size>(it - begin()) == length() - 1 || is_separator) && (sub_string.length() > 0 || (sub_string.length() == 0 && options != xtd::string_split_options::remove_empty_entries))) {
          if (list.size() == count - 1) {
            list.push_back(sub_string + basic_string(c_str(), it - begin() + (is_separator ? 0 : 1), length() - (it - begin()) + (is_separator ? 0 : 1)));
            return list;
          }
          list.push_back(sub_string);
          sub_string.chars_.clear();
        }
      }
      
      return list;
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
    basic_string substr(size_type pos) const {return chars_.substr(pos);}
    /// @brief Returns a substring [`pos`, `pos + count`). If the requested substring extends past the end of the string, i.e. the `count` is greater than size() - pos (e.g. if `count` == xtd::basic_string::npos), the returned substring is [`pos`, size()).
    /// @param pos The position of the first character to include.
    /// @param count The length of the substring.
    /// @return String containing the substring [`pos`, `pos + count`) or [pos, size()).
    /// @exception `std::out_of_range` if `pos > size()`.
    /// @remarks Equivalent to return `basic_string(*this, pos, count);`.
    basic_string substr(size_type pos, size_type count) const {return chars_.substr(pos, count);}
  
    /// @brief Retrieves a substring from this instance. The substring starts at a specified character position and has a specified length.
    /// @param str basic_string to substring.
    /// @param start_index The zero-based starting character position of a substring in this instance.
    /// @return A basic_string equivalent to the substring of length length that begins at start_index in this instance, or Empty if start_index is equal to the length of this instance and length is zero.
    basic_string substring(xtd::size start_index) const noexcept {
      if (start_index >= size()) return "";
      return substr(start_index);
    }
    /// @brief Retrieves a substring from this instance. The substring starts at a specified character position and has a specified length.
    /// @param start_index The zero-based starting character position of a substring in this instance.
    /// @param length The number of characters in the substring.
    /// @return A basic_string equivalent to the substring of length length that begins at start_index in this instance, or Empty if start_index is equal to the length of this instance and length is zero.
    basic_string substring(xtd::size start_index, xtd::size length) const noexcept {
      if (start_index >= size()) return "";
      return substr(start_index, length);
    }

    /// @brief Returns a copy of the current xtd::basic_string converted to lowercase.
    /// @return A string in lowercase.
    basic_string to_lower() const noexcept {
      auto result = basic_string::empty_string;
      std::for_each(begin(), end(), [&](auto c) {result += static_cast<value_type>(std::tolower(c));});
      return result;
    }

    /// @brief Converts the value of this instance to a xtd::basic_string <char>.
    /// @return The current string.
    /// @todo Uncomment the folllowing line and remove the next..
    //xtd::string to_string() const noexcept override {return __xtd_convert_to_string<char>(chars_);}
    xtd::string to_string() const noexcept override;
    
    /// @brief Converts the current basic_string to title case (except for words that are entirely in uppercase, which are considered to be acronyms).
    /// @return A new basic_string in title case.
    basic_string to_title_case() const noexcept {
      auto words = split({' '});
      for (auto& word : words)
        if (word.size() && word != word.to_upper()) word = static_cast<value_type>(toupper(word[0])) + word.substring(1).to_lower();
      return basic_string::join(" ", words);
    }

    /// @brief Converts the value of this instance to a xtd::basic_string <xtd::char16>.
    /// @return The current string.
    basic_string<xtd::char16> to_u16string() const noexcept {return __xtd_convert_to_string<xtd::char16>(chars_);}
    
    /// @brief Converts the value of this instance to a xtd::basic_string <xtd::char32>.
    /// @return The current string.
    basic_string<xtd::char32> to_u32string() const noexcept {return __xtd_convert_to_string<xtd::char32>(chars_);}
    
    /// @brief Converts the value of this instance to a xtd::basic_string <xtd::char8>.
    /// @return The current string.
    basic_string<xtd::char8> to_u8string() const noexcept {return __xtd_convert_to_string<xtd::char8>(chars_);}
    
    /// @brief Returns a copy of the current xtd::basic_string converted to uppercase.
    /// @return A string in uppercase.
    basic_string to_upper() const noexcept {
      auto result = basic_string::empty_string;
      std::for_each(begin(), end(), [&](auto c) {result += static_cast<value_type>(std::toupper(c));});
      return result;
    }

    /// @brief Converts the value of this instance to a xtd::basic_string <xtd::wchar>.
    /// @return The current string.
    basic_string<xtd::wchar> to_wstring() const noexcept {return __xtd_convert_to_string<xtd::wchar>(chars_);}
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Indicates whether the specifeid basic_string is an empty basic_string ("").
    /// @param string The xtd::basic_string to check if empty.
    /// @return true if the value parameter is null or an empty basic_string (""); otherwise, false.
    static bool is_empty(const xtd::basic_string<value_type, traits_type, allocator_type>& string) noexcept {return !string.length();}
    
    /// @brief Concatenates a specified separator basic_string between each element of a specified object array, yielding a single concatenated basic_string.
    /// @param separator A basic_string separator.
    /// @param values An array of Object.
    /// @return A basic_string consisting of the elements of value interspersed with the separator basic_string.
    /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value) returns "red, blue, green, yellow".
    /// @remarks stream << operator is called on each object to generate the content.
    template<typename collection_t>
    static basic_string join(const basic_string separator, const collection_t& values) noexcept {return join(separator, values, 0, values.size());}
    /// @brief Concatenates a specified separator basic_string between each element of a specified object array, yielding a single concatenated basic_string.
    /// @param separator A basic_string separator.
    /// @param values An array of Object.
    /// @param start_index The first array element in value to use.
    /// @return A basic_string consisting of the elements of value interspersed with the separator basic_string.
    /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value) returns "red, blue, green, yellow".
    /// @remarks stream << operator is called on each object to generate the content.
    template<typename collection_t>
    static basic_string join(const basic_string& separator, const collection_t& values, xtd::size index) noexcept {return join(separator, values, index, values.size() - index);}
    /// @brief Concatenates a specified separator basic_string between each element of a specified Object array, yielding a single concatenated basic_string.
    /// @param separator A basic_string separator.
    /// @param values An array of Object.
    /// @param start_index The first array element in value to use.
    /// @param count The number of elements of value to use.
    /// @return A basic_string consisting of the elements of value interspersed with the separator basic_string.
    /// @remarks For example if separator is ", " and the elements of value are "red", "blue", "green", and "yellow", Join(separator, value) returns "red, blue, green, yellow".
    /// @remarks stream << operator is called on each object to generate the content.
    template<typename collection_t>
    static basic_string join(const basic_string& separator, const collection_t& values, xtd::size index, xtd::size count) noexcept {
      xtd::size i = 0;
      basic_string result;
      for (const auto& item : values) {
        if (i >= index) {
          if (i != index) result += separator;
          result += format("{}", item);
        }
        if (++i >= index + count) break;
      }
      return result;
    }
    /// @cond
    template<typename value_t>
    static basic_string join(const basic_string& separator, const std::initializer_list<value_t>& values) noexcept {return join(separator, std::vector<value_t>(values));}
    template<typename value_t>
    static basic_string join(const basic_string& separator, const std::initializer_list<value_t>& values, xtd::size index) noexcept {return join(separator, std::vector<value_t>(values), index);}
    template<typename value_t>
    static basic_string join(const basic_string& separator, const std::initializer_list<value_t>& values, xtd::size index, xtd::size count) noexcept {return join(separator, std::vector<value_t>(values), index, count);}
    /// @endcond
    /// @}
    
    /// @name Public Operators
    
    /// @{
    /// @brief Returns a reference to the character at specified location index.
    /// @param index The position of the character to return.
    /// @return Reference to the requested character.
    /// @exception xtd::index_out_of_range_exception If `index` is not within the range of the string.
    const_reference operator [](xtd::size index) const {
      if (index >= length()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      return chars_[index];
    }
    
    /// @brief Returns a reference to the underlying base type.
    /// @return Reference to the underlying base type.
    virtual operator const base_type&() const noexcept {return chars_;}

    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of str.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const basic_string<char>& str) noexcept {
      chars_ = __xtd_convert_to_string<value_type>(str.chars_);
      return *this;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of str.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const basic_string<xtd::char16>& str) noexcept {
      chars_ = __xtd_convert_to_string<value_type>(str.chars_);
      return *this;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of str.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const basic_string<xtd::char32>& str) noexcept {
      chars_ = __xtd_convert_to_string<value_type>(str.chars_);
      return *this;
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of str.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const basic_string<xtd::char8>& str) noexcept {
      chars_ = __xtd_convert_to_string<value_type>(str.chars_);
      return *this;
    }
#endif
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of str.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const basic_string<xtd::wchar>& str) noexcept {
      chars_ = __xtd_convert_to_string<value_type>(str.chars_);
      return *this;
    }
 
    /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in `str` is moved from `str` into this string). `str` is in a valid but unspecified state afterwards.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(basic_string<char>&& str) noexcept {
      chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_)));
      return *this;
    }
    /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in `str` is moved from `str` into this string). `str` is in a valid but unspecified state afterwards.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(basic_string<xtd::char16>&& str) noexcept {
      chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_)));
      return *this;
    }
    /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in `str` is moved from `str` into this string). `str` is in a valid but unspecified state afterwards.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(basic_string<xtd::char32>&& str) noexcept {
      chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_)));
      return *this;
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in `str` is moved from `str` into this string). `str` is in a valid but unspecified state afterwards.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(basic_string<xtd::char8>&& str) noexcept {
      chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_)));
      return *this;
    }
#endif
    /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in `str` is moved from `str` into this string). `str` is in a valid but unspecified state afterwards.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(basic_string<xtd::wchar>&& str) noexcept {
      chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str.chars_)));
      return *this;
    }

    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::basic_string<char>& str) noexcept {
      chars_ = __xtd_convert_to_string<value_type>(str);
      return *this;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::basic_string<xtd::char16>& str) noexcept {
      chars_ = __xtd_convert_to_string<value_type>(str);
      return *this;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::basic_string<xtd::char32>& str) noexcept {
      chars_ = __xtd_convert_to_string<value_type>(str);
      return *this;
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::basic_string<xtd::char8>& str) noexcept {
      chars_ = __xtd_convert_to_string<value_type>(str);
      return *this;
    }
#endif
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::basic_string<xtd::wchar>& str) noexcept {
      chars_ = __xtd_convert_to_string<value_type>(str);
      return *this;
    }

    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(std::basic_string<char>&& str) noexcept {
      chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str)));
      return *this;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(std::basic_string<xtd::char16>&& str) noexcept {
      chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str)));
      return *this;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(std::basic_string<xtd::char32>&& str) noexcept {
      chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str)));
      return *this;
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(std::basic_string<xtd::char8>&& str) noexcept {
      chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str)));
      return *this;
    }
#endif
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(std::basic_string<xtd::wchar>&& str) noexcept {
      chars_ = std::move(__xtd_convert_to_string<value_type>(std::move(str)));
      return *this;
    }

    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    basic_string& operator =(const char* str) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<char>(str));
      return *this;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    basic_string& operator =(const xtd::char16* str) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char16>(str));
      return *this;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    basic_string& operator =(const xtd::char32* str) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char32>(str));
      return *this;
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    basic_string& operator =(const xtd::char8* str) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::char8>(str));
      return *this;
    }
#endif
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    basic_string& operator =(const xtd::wchar* str) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_ = __xtd_convert_to_string<value_type>(std::basic_string<xtd::wchar>(str));
      return *this;
    }

    /// @brief Copy assignment operator. Replaces the contents with the specified character.
    /// @param character The character to use as data source.
    /// @return This current instance.
    basic_string& operator =(char character) {
      *this = basic_string(1, character);
      return  *this;
    }
    /// @brief Copy assignment operator. Replaces the contents with the specified character.
    /// @param character The character to use as data source.
    /// @return This current instance.
    basic_string& operator =(xtd::char16 character) {
      *this = basic_string(1, character);
      return  *this;
    }
    /// @brief Copy assignment operator. Replaces the contents with the specified character.
    /// @param character The character to use as data source.
    /// @return This current instance.
    basic_string& operator =(xtd::char32 character) {
      *this = basic_string(1, character);
      return  *this;
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Copy assignment operator. Replaces the contents with the specified character.
    /// @param character The character to use as data source.
    /// @return This current instance.
    basic_string& operator =(xtd::char8 character) {
      *this = basic_string(1, character);
      return  *this;
    }
#endif
    /// @brief Copy assignment operator. Replaces the contents with the specified character.
    /// @param character The character to use as data source.
    /// @return This current instance.
    basic_string& operator =(xtd::wchar character) {
      *this = basic_string(1, character);
      return  *this;
    }

    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of the specified initializer list.
    /// @param il The initialiazer list to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::initializer_list<char>& il) {
      *this = basic_string(il);
      return *this;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of the specified initializer list.
    /// @param il The initialiazer list to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::initializer_list<xtd::char16>& il) {
      *this = basic_string(il);
      return *this;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of the specified initializer list.
    /// @param il The initialiazer list to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::initializer_list<xtd::char32>& il) {
      *this = basic_string(il);
      return *this;
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of the specified initializer list.
    /// @param il The initialiazer list to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::initializer_list<xtd::char8>& il) {
      *this = basic_string(il);
      return *this;
    }
#endif
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of the specified initializer list.
    /// @param il The initialiazer list to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::initializer_list<xtd::wchar>& il) {
      *this = basic_string(il);
      return *this;
    }
 
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const basic_string<char>& str) {
      chars_ += __xtd_convert_to_string<value_type>(str.chars_);
      return *this;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const basic_string<xtd::char16>& str) {
      chars_ += __xtd_convert_to_string<value_type>(str.chars_);
      return *this;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const basic_string<xtd::char32>& str) {
      chars_ += __xtd_convert_to_string<value_type>(str.chars_);
      return *this;
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const basic_string<xtd::char8>& str) {
      chars_ += __xtd_convert_to_string<value_type>(str.chars_);
      return *this;
    }
#endif
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const basic_string<xtd::wchar>& str) {
      chars_ += __xtd_convert_to_string<value_type>(str.chars_);
      return *this;
    }

    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(basic_string<char>&& str) {
      chars_ += __xtd_convert_to_string<value_type>(std::move(str.chars_));
      return *this;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(basic_string<xtd::char16>&& str) {
      chars_ += __xtd_convert_to_string<value_type>(std::move(str.chars_));
      return *this;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(basic_string<xtd::char32>&& str) {
      chars_ += __xtd_convert_to_string<value_type>(std::move(str.chars_));
      return *this;
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(basic_string<xtd::char8>&& str) {
      chars_ += __xtd_convert_to_string<value_type>(std::move(str.chars_));
      return *this;
    }
#endif
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(basic_string<xtd::wchar>&& str) {
      chars_ += __xtd_convert_to_string<value_type>(std::move(str.chars_));
      return *this;
    }

    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const char* str) {
      chars_ += basic_string(str).chars_;
      return *this;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const xtd::char16* str) {
      chars_.append(basic_string(str).chars_); return *this;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const xtd::char32* str) {
      chars_ += basic_string(str).chars_;
      return *this;
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const xtd::char8* str) {
      chars_ += basic_string(str).chars_;
      return *this;
    }
#endif
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param str string to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(const xtd::wchar* str) {
      chars_ += basic_string(str).chars_;
      return *this;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param ch Character value to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(char ch) {
      chars_ += basic_string(1, ch).chars_;
      return *this;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param ch Character value to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(xtd::char16 ch) {
      chars_ += basic_string(1, ch).chars_;
      return *this;
    }
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param ch Character value to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(xtd::char32 ch) {
      chars_ += basic_string(1, ch).chars_;
      return *this;
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param ch Character value to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(xtd::char8 ch) {
      chars_ += basic_string(1, ch).chars_;
      return *this;
    }
#endif
    /// @brief Addition assignment operator. Appends additional characters to the string.
    /// @param ch Character value to append.
    /// @return This current instance with characters added.
    basic_string& operator +=(xtd::wchar ch) {
      chars_ += basic_string(1, ch).chars_;
      return *this;
    }

    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const basic_string<char>& rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const basic_string<xtd::char16>& rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const basic_string<xtd::char32>& rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const basic_string<xtd::char8>& rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
#endif
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const basic_string<xtd::wchar>& rhs) {
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
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, basic_string<xtd::char8>&& rhs) {
      auto result = std::move(lhs);
      result += std::move(rhs);
      return result;
    }
#endif
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
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const basic_string<xtd::char8>& rhs) {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
#endif
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
    friend basic_string operator +(const basic_string& lhs, basic_string<char>&& rhs) {
      auto result = lhs;
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, basic_string<xtd::char16>&& rhs) {
      auto result = lhs;
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, basic_string<xtd::char32>&& rhs) {
      auto result = lhs;
      result += std::move(rhs);
      return result;
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, basic_string<xtd::char8>&& rhs) {
      auto result = lhs;
      result += std::move(rhs);
      return result;
    }
#endif
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, basic_string<xtd::wchar>&& rhs) {
      auto result = lhs;
      result += std::move(rhs);
      return result;
    }

    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const char* rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const xtd::char16* rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const xtd::char32* rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const xtd::char8* rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
#endif
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const xtd::wchar* rhs) {
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
    friend basic_string operator +(basic_string&& lhs, const xtd::char16* rhs) {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const xtd::char32* rhs) {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const xtd::char8* rhs) {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
#endif
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const xtd::wchar* rhs) {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }

    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const char* lhs, const basic_string& rhs) {
      auto result = basic_string(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char16* lhs, const basic_string& rhs) {
      auto result = basic_string(lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char32* lhs, const basic_string& rhs) {
      auto result = basic_string(lhs);
      result += rhs;
      return result;
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char8* lhs, const basic_string& rhs) {
      auto result = basic_string(lhs);
      result += rhs;
      return result;
    }
#endif
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::wchar* lhs, const basic_string& rhs) {
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
    friend basic_string operator +(const xtd::char16* lhs, basic_string&& rhs) {
      auto result = basic_string(lhs);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char32* lhs, basic_string&& rhs) {
      auto result = basic_string(lhs);
      result += std::move(rhs);
      return result;
    }

#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char8* lhs, basic_string&& rhs) {
      auto result = basic_string(lhs);
      result += std::move(rhs);
      return result;
    }
#endif
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::wchar* lhs, basic_string&& rhs) {
      auto result = basic_string(lhs);
      result += std::move(rhs);
      return result;
    }

    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const char rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const xtd::char16 rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const xtd::char32 rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const xtd::char8 rhs) {
      auto result = lhs;
      result += rhs;
      return result;
    }
#endif
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const xtd::wchar rhs) {
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
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const xtd::char8 rhs) {
      auto result = std::move(lhs);
      result += rhs;
      return result;
    }
#endif
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
    friend basic_string operator +(char lhs, const basic_string& rhs) {
      auto result = basic_string(1, lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(xtd::char16 lhs, const basic_string& rhs) {
      auto result = basic_string(1, lhs);
      result += rhs;
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(xtd::char32 lhs, const basic_string& rhs) {
      auto result = basic_string(1, lhs);
      result += rhs;
      return result;
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(xtd::char8 lhs, const basic_string& rhs) {
      auto result = basic_string(1, lhs);
      result += rhs;
      return result;
    }
#endif
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(xtd::wchar lhs, const basic_string& rhs) {
      auto result = basic_string(1, lhs);
      result += rhs;
      return result;
    }

    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(char lhs, basic_string&& rhs) {
      auto result = basic_string(1, lhs);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(xtd::char16 lhs, basic_string&& rhs) {
      auto result = basic_string(1, lhs);
      result += std::move(rhs);
      return result;
    }
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(xtd::char32 lhs, basic_string&& rhs) {
      auto result = basic_string(1, lhs);
      result += std::move(rhs);
      return result;
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(xtd::char8 lhs, basic_string&& rhs) {
      auto result = basic_string(1, lhs);
      result += std::move(rhs);
      return result;
    }
#endif
    /// @brief Addition operator. Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(xtd::wchar lhs, basic_string&& rhs) {
      auto result = basic_string(1, lhs);
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
    friend std::basic_ostream<char>& operator <<(std::basic_ostream<char>& stream, const basic_string& str) {return stream << __xtd_convert_to_string<char>(str.chars_);}
    /// @brief Output stream operator. Behaves as a [FormattedOutputFunction](https://en.cppreference.com/w/cpp/named_req/FormattedOutputFunction). After constructing and checking the sentry object, [determines the output format padding](https://en.cppreference.com/w/cpp/named_req/FormattedOutputFunction#Padding).
    /// @param os The character output stream.
    /// @param str The string to be inserted.
    /// @remarks Then inserts each character from the resulting sequence `seq` (the contents of `str` plus padding) to the output stream `os` as if by calling `os.rdbuf()->sputn(seq, n)`, where n is `std::max(os.width(), str.size())`.
    /// @remarks Finally, calls `os.width(0)` to cancel the effects of std::setw, if any.
    /// @remarks Equivalent to `return os << std::basic_string_view<char_t, traits_t>(str);`.
    friend std::basic_ostream<xtd::wchar>& operator <<(std::basic_ostream<xtd::wchar>& stream, const basic_string& str) {return stream << str.to_wstring().chars_;}

    /// @brief Input stream operator. Behaves as a [FormattedInputFunction](https://en.cppreference.com/w/cpp/named_req/FormattedInputFunction). After constructing and checking the sentry object, which may skip leading whitespace, first clears `str` with `str.erase()`, then reads characters from `is` and appends them to `str` as if by `str.append(1, c)`, until one of the following conditions becomes true:
    /// * N characters are read, where N is `is.width()` if `is.width() > 0`, otherwise N is `str.max_size()`,
    /// * the end-of-file condition occurs in the stream is, or
    /// * `std::isspace(c, is.getloc())` is `true` for the next character `c` in `is` (this whitespace character remains in the input stream).
    /// @param is The character input stream.
    /// @param str The string to be extracted.
    /// @remarks If no characters are extracted then std::ios::failbit is set on `is`, which may throw [std::ios_base::failure](https://en.cppreference.com/w/cpp/io/ios_base/failure).
    /// @remarks Finally, calls `is.width(0)` to cancel the effects of [std::setw](https://en.cppreference.com/w/cpp/io/manip/setw), if any.
    friend std::basic_istream<char>& operator >>(std::basic_istream<char>& stream, basic_string& str) {
      auto s = std::basic_string<char> {};
      stream >> s;
      str = s;
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
    friend std::basic_istream<xtd::wchar>& operator >>(std::basic_istream<xtd::wchar>& stream, basic_string& str) {
      auto s = std::basic_string<xtd::wchar> {};
      stream >> s;
      str = s;
      return stream;
    }
    /// @}

  private:
    friend class basic_string<char>;
    friend class basic_string<xtd::char16>;
    friend class basic_string<xtd::char32>;
#if defined(__xtd__cpp_lib_char8_t)
    friend class basic_string<xtd::char8>;
#endif
    friend class basic_string<xtd::wchar>;

    static const std::vector<char_t> default_split_separators;
    static const std::vector<char_t> default_trim_chars;

    base_type::iterator to_base_type_iterator(iterator value) const noexcept {
      if (value == begin()) return chars_.begin();
      if (value == end()) return chars_.end();
      return chars_.begin() + (value - begin());
    }
    
    iterator to_iterator(base_type::iterator value) const noexcept {
      if (value == chars_.begin()) return begin();
      if (value == chars_.end()) return end();
      return begin() + (value - chars_.begin());
    }

    base_type chars_;
  };

  /// @cond
  template<typename char_t, typename traits_t, typename allocator_t>
  inline const basic_string<char_t, traits_t, allocator_t> basic_string<char_t, traits_t, allocator_t>::empty_string;
  
  template<typename char_t, typename traits_t, typename allocator_t>
  inline const std::vector<char_t> basic_string<char_t, traits_t, allocator_t>::default_split_separators = {9, 10, 11, 12, 13, 32};

  template<typename char_t, typename traits_t, typename allocator_t>
  inline const std::vector<char_t> basic_string<char_t, traits_t, allocator_t>::default_trim_chars = default_split_separators;

  /// @endcond
}

/// @cond
template<typename arg_t>
void __basic_string_extract_format_arg(std::basic_string<char>& fmt, xtd::size& index, std::vector<__format_information<char>>& formats, arg_t&& arg) {
  auto offset = xtd::size {0};
  for (auto& format : formats) {
    format.location += offset;
    if (format.index == index) {
      xtd::basic_string<char> arg_str = xtd::to_string(arg, format.format);
      
      if (!format.alignment.empty()) {
        xtd::int32 alignment = 0;
        try {
          alignment = std::stoi(format.alignment);
        } catch (...) {
          __throw_basic_string_format_exception(__FILE__, __LINE__, __func__);
        }
        if (alignment > 0) arg_str = arg_str.pad_left(alignment);
        else if (alignment < 0) arg_str = arg_str.pad_right(-alignment);
      }
      fmt.insert(format.location, arg_str);
      offset += arg_str.size();
    }
  }
  ++index;
}

template<typename ...args_t>
void __basic_string_extract_format_arg(xtd::basic_string<char>& fmt, std::vector<__format_information<char>>& formats, args_t&&... args) {
  auto index = xtd::size {0};
  (__basic_string_extract_format_arg(const_cast<std::basic_string<char>&>(fmt.chars()), index, formats, args), ...);
  unused_(index); // workaround to mute gcc warning: unused-but-set-variable
}

template<typename target_t, typename source_t>
inline std::basic_string<target_t> __xtd_convert_to_string(std::basic_string<source_t>&& str) noexcept {
  auto out = std::basic_string<target_t> {};
  auto codepoint = 0u;
  for (const auto& character : str) {
    if (character >= 0xd800 && character <= 0xdbff)
      codepoint = ((character - 0xd800) << 10) + 0x10000;
    else  {
      if (character >= 0xdc00 && character <= 0xdfff) codepoint |= character - 0xdc00;
      else codepoint = character;
      
      if (codepoint <= 0x7f)
        out.append(1, static_cast<target_t>(codepoint));
      else if (codepoint <= 0x7ff) {
        out.append(1, static_cast<target_t>(0xc0 | ((codepoint >> 6) & 0x1f)));
        out.append(1, static_cast<target_t>(0x80 | (codepoint & 0x3f)));
      } else if (codepoint <= 0xffff) {
        out.append(1, static_cast<target_t>(0xe0 | ((codepoint >> 12) & 0x0f)));
        out.append(1, static_cast<target_t>(0x80 | ((codepoint >> 6) & 0x3f)));
        out.append(1, static_cast<target_t>(0x80 | (codepoint & 0x3f)));
      } else {
        out.append(1, static_cast<target_t>(0xf0 | ((codepoint >> 18) & 0x07)));
        out.append(1, static_cast<target_t>(0x80 | ((codepoint >> 12) & 0x3f)));
        out.append(1, static_cast<target_t>(0x80 | ((codepoint >> 6) & 0x3f)));
        out.append(1, static_cast<target_t>(0x80 | (codepoint & 0x3f)));
      }
      codepoint = 0;
    }
  }
  str.clear();
  return std::move(out);
}

template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, char>(std::basic_string<char>&& str) noexcept {
  auto out = std::basic_string<xtd::char16> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::char16>(0xd800 + (static_cast<xtd::char16>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::char16>(0xdc00 + (static_cast<xtd::char16>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::char16>(codepoint));
    }
  }
  str.clear();
  return out;
}

#if defined(__xtd__cpp_lib_char8_t)
template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::char8>(std::basic_string<xtd::char8>&& str) noexcept {
  auto out = std::basic_string<xtd::char16> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::char16>(0xd800 + (static_cast<xtd::char16>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::char16>(0xdc00 + (static_cast<xtd::char16>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::char16>(codepoint));
    }
  }
  str.clear();
  return out;
}
#endif

template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, char>(std::basic_string<char>&& str) noexcept {
  auto out = std::basic_string<xtd::wchar> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (sizeof(xtd::wchar) > 2)
        out.append(1, static_cast<xtd::wchar>(codepoint));
      else if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::wchar>(0xd800 + (static_cast<xtd::wchar>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::wchar>(0xdc00 + (static_cast<xtd::wchar>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::wchar>(codepoint));
    }
  }
  str.clear();
  return out;
}

#if defined(__xtd__cpp_lib_char8_t)
template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::char8>(std::basic_string<xtd::char8>&& str) noexcept {
  auto out = std::basic_string<xtd::wchar> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (sizeof(xtd::wchar) > 2)
        out.append(1, static_cast<xtd::wchar>(codepoint));
      else if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::wchar>(0xd800 + (static_cast<xtd::wchar>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::wchar>(0xdc00 + (static_cast<xtd::wchar>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::wchar>(codepoint));
    }
  }
  str.clear();
  return out;
}
#endif

template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, char>(std::basic_string<char>&& str) noexcept {
  auto out = std::basic_string<xtd::char32> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff))
      out.append(1, static_cast<xtd::char32>(codepoint));
  }
  str.clear();
  return out;
}

#if defined(__xtd__cpp_lib_char8_t)
template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::char8>(std::basic_string<xtd::char8>&& str) noexcept {
  auto out = std::basic_string<xtd::char32> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff))
      out.append(1, static_cast<xtd::char32>(codepoint));
  }
  str.clear();
  return out;
}
#endif

template<>
inline std::basic_string<char> __xtd_convert_to_string<char, char>(std::basic_string<char>&& str) noexcept {return std::move(str);}
template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::char16>(std::basic_string<xtd::char16>&& str) noexcept {return std::move(str);}
template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::char32>(std::basic_string<xtd::char32>&& str) noexcept {return std::move(str);}
#if defined(__xtd__cpp_lib_char8_t)
template<>
inline std::basic_string<xtd::char8> __xtd_convert_to_string<xtd::char8, xtd::char8>(std::basic_string<xtd::char8>&& str) noexcept {return std::move(str);}
#endif
template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::wchar>(std::basic_string<xtd::wchar>&& str) noexcept {return std::move(str);}
#if defined(__xtd__cpp_lib_char8_t)
template<>
inline std::basic_string<xtd::char8> __xtd_convert_to_string<xtd::char8, char>(std::basic_string<char>&& str) noexcept {
  auto result = std::basic_string<xtd::char8> {reinterpret_cast<const xtd::char8*>(str.c_str())};
  str.clear();
  return result;
}
template<>
inline std::basic_string<char> __xtd_convert_to_string<char, xtd::char8>(std::basic_string<xtd::char8>&& str) noexcept {
  auto result = std::basic_string<char> {reinterpret_cast<const char*>(str.c_str())};
  str.clear();
  return result;
}
#endif
template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::char32>(std::basic_string<xtd::char32>&& str) noexcept {return __xtd_convert_to_string<xtd::char16>(__xtd_convert_to_string<char>(std::move(str)));}
template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::wchar>(std::basic_string<xtd::wchar>&& str) noexcept {return __xtd_convert_to_string<xtd::char16>(__xtd_convert_to_string<char>(std::move(str)));}
template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::char16>(std::basic_string<xtd::char16>&& str) noexcept {return __xtd_convert_to_string<xtd::char32>(__xtd_convert_to_string<char>(std::move(str)));}
template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::wchar>(std::basic_string<xtd::wchar>&& str) noexcept {return __xtd_convert_to_string<xtd::char32>(__xtd_convert_to_string<char>(std::move(str)));}
template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::char16>(std::basic_string<xtd::char16>&& str) noexcept {return __xtd_convert_to_string<xtd::wchar>(__xtd_convert_to_string<char>(std::move(str)));}
template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::char32>(std::basic_string<xtd::char32>&& str) noexcept {return __xtd_convert_to_string<xtd::wchar>(__xtd_convert_to_string<char>(std::move(str)));}

template<typename target_t, typename source_t>
inline std::basic_string<target_t> __xtd_convert_to_string(const std::basic_string<source_t>& str) noexcept {
  auto out = std::basic_string<target_t> {};
  auto codepoint = 0u;
  for (const auto& character : str) {
    if (character >= 0xd800 && character <= 0xdbff)
      codepoint = ((character - 0xd800) << 10) + 0x10000;
    else  {
      if (character >= 0xdc00 && character <= 0xdfff) codepoint |= character - 0xdc00;
      else codepoint = character;
      
      if (codepoint <= 0x7f)
        out.append(1, static_cast<target_t>(codepoint));
      else if (codepoint <= 0x7ff) {
        out.append(1, static_cast<target_t>(0xc0 | ((codepoint >> 6) & 0x1f)));
        out.append(1, static_cast<target_t>(0x80 | (codepoint & 0x3f)));
      } else if (codepoint <= 0xffff) {
        out.append(1, static_cast<target_t>(0xe0 | ((codepoint >> 12) & 0x0f)));
        out.append(1, static_cast<target_t>(0x80 | ((codepoint >> 6) & 0x3f)));
        out.append(1, static_cast<target_t>(0x80 | (codepoint & 0x3f)));
      } else {
        out.append(1, static_cast<target_t>(0xf0 | ((codepoint >> 18) & 0x07)));
        out.append(1, static_cast<target_t>(0x80 | ((codepoint >> 12) & 0x3f)));
        out.append(1, static_cast<target_t>(0x80 | ((codepoint >> 6) & 0x3f)));
        out.append(1, static_cast<target_t>(0x80 | (codepoint & 0x3f)));
      }
      codepoint = 0;
    }
  }
  return out;
}

template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, char>(const std::basic_string<char>& str) noexcept {
  auto out = std::basic_string<xtd::char16> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::char16>(0xd800 + (static_cast<xtd::char16>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::char16>(0xdc00 + (static_cast<xtd::char16>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::char16>(codepoint));
    }
  }
  return out;
}

#if defined(__xtd__cpp_lib_char8_t)
template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::char8>(const std::basic_string<xtd::char8>& str) noexcept {
  auto out = std::basic_string<xtd::char16> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::char16>(0xd800 + (static_cast<xtd::char16>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::char16>(0xdc00 + (static_cast<xtd::char16>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::char16>(codepoint));
    }
  }
  return out;
}
#endif

template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, char>(const std::basic_string<char>& str) noexcept {
  auto out = std::basic_string<xtd::wchar> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (sizeof(xtd::wchar) > 2)
        out.append(1, static_cast<xtd::wchar>(codepoint));
      else if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::wchar>(0xd800 + (static_cast<xtd::wchar>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::wchar>(0xdc00 + (static_cast<xtd::wchar>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::wchar>(codepoint));
    }
  }
  return out;
}

#if defined(__xtd__cpp_lib_char8_t)
template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::char8>(const std::basic_string<xtd::char8>& str) noexcept {
  auto out = std::basic_string<xtd::wchar> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff)) {
      if (sizeof(xtd::wchar) > 2)
        out.append(1, static_cast<xtd::wchar>(codepoint));
      else if (codepoint > 0xffff) {
        out.append(1, static_cast<xtd::wchar>(0xd800 + (static_cast<xtd::wchar>(codepoint) >> 10)));
        out.append(1, static_cast<xtd::wchar>(0xdc00 + (static_cast<xtd::wchar>(codepoint) & 0x03ff)));
      } else if (codepoint < 0xd800 || codepoint >= 0xe000)
        out.append(1, static_cast<xtd::wchar>(codepoint));
    }
  }
  return out;
}
#endif

template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, char>(const std::basic_string<char>& str) noexcept {
  auto out = std::basic_string<xtd::char32> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff))
      out.append(1, static_cast<xtd::char32>(codepoint));
  }
  return out;
}

#if defined(__xtd__cpp_lib_char8_t)
template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::char8>(const std::basic_string<xtd::char8>& str) noexcept {
  auto out = std::basic_string<xtd::char32> {};
  auto codepoint = 0u;
  auto str_ptr = str.data();
  while (*str_ptr != 0) {
    auto ch = static_cast<unsigned char>(*str_ptr);
    if (ch <= 0x7f) codepoint = ch;
    else if (ch <= 0xbf) codepoint = (codepoint << 6) | (ch & 0x3f);
    else if (ch <= 0xdf) codepoint = ch & 0x1f;
    else if (ch <= 0xef) codepoint = ch & 0x0f;
    else codepoint = ch & 0x07;
    ++str_ptr;
    if (((*str_ptr & 0xc0) != 0x80) && (codepoint <= 0x10ffff))
      out.append(1, static_cast<xtd::char32>(codepoint));
  }
  return out;
}
#endif

template<>
inline std::basic_string<char> __xtd_convert_to_string<char, char>(const std::basic_string<char>& str) noexcept {return str;}
template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::char16>(const std::basic_string<xtd::char16>& str) noexcept {return str;}
template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::char32>(const std::basic_string<xtd::char32>& str) noexcept {return str;}
#if defined(__xtd__cpp_lib_char8_t)
template<>
inline std::basic_string<xtd::char8> __xtd_convert_to_string<xtd::char8, xtd::char8>(const std::basic_string<xtd::char8>& str) noexcept {return str;}
#endif
template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::wchar>(const std::basic_string<xtd::wchar>& str) noexcept {return str;}
#if defined(__xtd__cpp_lib_char8_t)
template<>
inline std::basic_string<xtd::char8> __xtd_convert_to_string<xtd::char8, char>(const std::basic_string<char>& str) noexcept {return reinterpret_cast<const xtd::char8*>(str.c_str());}
template<>
inline std::basic_string<char> __xtd_convert_to_string<char, xtd::char8>(const std::basic_string<xtd::char8>& str) noexcept {return reinterpret_cast<const char*>(str.c_str());}
#endif
template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::char32>(const std::basic_string<xtd::char32>& str) noexcept {return __xtd_convert_to_string<xtd::char16>(__xtd_convert_to_string<char>(str));}
template<>
inline std::basic_string<xtd::char16> __xtd_convert_to_string<xtd::char16, xtd::wchar>(const std::basic_string<xtd::wchar>& str) noexcept {return __xtd_convert_to_string<xtd::char16>(__xtd_convert_to_string<char>(str));}
template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::char16>(const std::basic_string<xtd::char16>& str) noexcept {return __xtd_convert_to_string<xtd::char32>(__xtd_convert_to_string<char>(str));}
template<>
inline std::basic_string<xtd::char32> __xtd_convert_to_string<xtd::char32, xtd::wchar>(const std::basic_string<xtd::wchar>& str) noexcept {return __xtd_convert_to_string<xtd::char32>(__xtd_convert_to_string<char>(str));}
template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::char16>(const std::basic_string<xtd::char16>& str) noexcept {return __xtd_convert_to_string<xtd::wchar>(__xtd_convert_to_string<char>(str));}
template<>
inline std::basic_string<xtd::wchar> __xtd_convert_to_string<xtd::wchar, xtd::char32>(const std::basic_string<xtd::char32>& str) noexcept {return __xtd_convert_to_string<xtd::wchar>(__xtd_convert_to_string<char>(str));}
/// @endcond
