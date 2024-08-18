/// @file
/// @brief Contains xtd::basic_string class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#define __XTD_CORE_INTERNAL__
#include "internal/__format_information.h"
#include "internal/__sprintf.h"
#undef __XTD_CORE_INTERNAL__
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.h"
#undef __XTD_STD_INTERNAL__
/// @endcond
#include "icomparable.h"
#include "iequatable.h"
#include "collections/generic/ienumerable.h"
#include "string_comparison.h"
#include "string_split_options.h"
#include "types.h"
#include "object.h"
#include "parse.h"
#include "to_string.h"
#include "types.h"
#include "unused.h"
#if defined(__xtd__cpp_lib_format)
#include <format>
#endif
#include <ostream>
#include <string>

/// @cond
namespace xtd {
  template<typename char_t, typename traits_t = std::char_traits<char_t>, typename allocator_t = std::allocator<char_t>>
  class basic_string;
}
template<typename char_t, typename ...args_t>
void __ustring_extract_format_arg(xtd::basic_string<char_t>& fmt, std::vector<__format_information<char>>& format, args_t&& ... args);
template<typename target_t, typename source_t>
std::basic_string<target_t> __xtd_convert_to_string(const std::basic_string<source_t>& str) noexcept;
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
  template<typename char_t, typename traits_t, typename allocator_t>
  class basic_string : /*public object,*/ public xtd::icomparable<basic_string<char_t, traits_t, allocator_t>>, public xtd::iequatable<basic_string<char_t, traits_t, allocator_t>> /*, public xtd::ienumerable<basic_string<char_t, traits_t, allocator_t>>*/ {
  public:
    /// @name Public Aliases
    
    /// @{
    /// @brief Represents the basic string base type.
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
    
    //----------------------------------------------------------------------------------------------------------------------------------------------

    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy.
    /// @param str The string to copy.
    basic_string(const basic_string& str) noexcept : chars_(str.chars_) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified string to copy and allocator.
    /// @param str The string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const basic_string& str, const allocator_type& allocator) noexcept : chars_(str.chars_, allocator) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    basic_string(const basic_string& str, xtd::size index) : chars_(str.chars_, index) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index and allocator.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const basic_string& str, xtd::size index, const allocator_type& allocator) : chars_(str.chars_, index, allocator) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index and count characters.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    basic_string(const basic_string& str, xtd::size index, xtd::size count) : chars_(str.chars_, index, count) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index, count characters and allocator.
    /// @param str The string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const basic_string& str, xtd::size index, xtd::size count, const allocator_type& allocator) : chars_(str.chars_, index, count, allocator) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified string to move.
    /// @param str The basic_string to move.
    basic_string(basic_string&& str) noexcept : chars_(std::move(str.chars_)) {str.chars_.clear();}
    /// @brief Initializes a new instance of xtd::basic_string with specified string to move and allocator.
    /// @param str The basic_string to move.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(basic_string&& str, const allocator_type& allocator) noexcept : chars_(std::move(str.chars_), allocator) {str.chars_.clear();}

    //----------------------------------------------------------------------------------------------------------------------------------------------
    
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

    //----------------------------------------------------------------------------------------------------------------------------------------------
    
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

    //----------------------------------------------------------------------------------------------------------------------------------------------
    
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

    //----------------------------------------------------------------------------------------------------------------------------------------------
    
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

    //----------------------------------------------------------------------------------------------------------------------------------------------
    
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

    //----------------------------------------------------------------------------------------------------------------------------------------------
    
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
    /// @brief Gets the number of characters in the current String object.
    /// @return The number of characters in the current string.
    /// @remarks The xtd::basic_string::length property returns the number of xtd::basic_string::value_type objects in this instance, not the number of Unicode characters. The reason is that a Unicode character might be represented by more than one xtd::basic_string::value_type.
    xtd::size length() const noexcept {return chars_.size();}
    
    /// @brief Returns a reference to the underlying base type.
    /// @return Reference to the underlying base type.
    const base_type& chars() const noexcept {return chars_;}
    /// @}

    /// @todo To be removed when inheriting xtd::collections::generic::ienumerable.
    /// @{
    const_iterator begin() const {return chars_.begin();}
    iterator begin() {return chars_.begin();}

    const_iterator cbegin() const {return chars_.cbegin();}

    const_iterator cend() const {return chars_.cend();}
    
    const_iterator end() const {return chars_.end();}
    iterator end() {return chars_.end();}
    /// @}

    /// @name Public Methods
    
    /// @{
    int32 compare_to(const object& value) const noexcept {return dynamic_cast<const basic_string*>(&value) && compare_to(static_cast<const basic_string&>(value));}
    int32 compare_to(const basic_string& value) const noexcept override {return chars_.compare(value.chars_);}

    /// @brief Determines whether this instance and a specified object, which must also be a xtd::basic_string object, have the same value.
    /// @param obj The basic_string to compare to this instance.
    /// @return `true` if `obj` is a xtd::basic_string and its value is the same as this instance; otherwise, `false`.
    bool equals(const object& obj) const noexcept /*override*/ {return dynamic_cast<const basic_string*>(&obj) && equals(static_cast<const basic_string&>(obj));}
    /// @brief Determines whether this instance and another specified String object have the same value.
    /// @param value The basic_string to compare to this instance.
    /// @return `true` if the `value` of the value parameter is the same as the value of this instance; otherwise, `false`.
    /// @remarks This method performs an ordinal (case-sensitive) comparison.
    bool equals(const basic_string& value) const noexcept override {return equals(value, false);}
    /// @brief Determines whether this instance and another specified String object have the same value, ignoring or honoring their case.
    /// @param value The basic_string to compare to this instance.
    /// @param ignore_case true to ignore case when comparing this instance and value; otherwise, false
    /// @return `true` if the `value` of the value parameter is the same as the value of this instance; otherwise, `false`.
    /// @remarks This method performs an ordinal comparison.
    bool equals(const basic_string& value, bool ignore_case) const noexcept {
      //if (ignore_case) return to_upper().chars_ == value.to_upper().chars_;
      return chars_ == value.chars_;
    }
   
    /// @brief Returns the hash code for this basic_string.
    /// @return A hash code.
    xtd::size get_hash_code() const noexcept /*override*/;
        
    /// @brief Indicates whether this basic_string is an empty basic_string ("").
    /// @return true if the value parameter is null or an empty basic_string (""); otherwise, false.
    /// @deprecated Replaced by xtd::basic_string::is_empty(const xtd::basic_string&) - Will be removed in version 0.4.0
    [[deprecated("Replaced by xtd::basic_string::is_empty(const xtd::basic_string&) - Will be removed in version 0.4.0")]]
    bool is_empty() const noexcept {return is_empty(*this);}
    
    /// @todo Uncomment override when inheriting xtd::object.
    basic_string<char> to_string() const noexcept /*override*/ {return __xtd_convert_to_string<char>(chars_);}
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Indicates whether the specifeid basic_string is an empty basic_string ("").
    /// @param string The xtd::basic_string to check if empty.
    /// @return true if the value parameter is null or an empty basic_string (""); otherwise, false.
    static bool is_empty(const xtd::basic_string<value_type, traits_type, allocator_type>& string) noexcept {return !string.length();}
    /// @}
    
    /// @name Public Operators
    
    /// @{
    /// @brief Returns a reference to the character at specified location index.
    /// @param index The position of the character to return.
    /// @return Reference to the requested character.
    /// @exception std::out_of_range If `index` is not within the range of the string.
    const value_type& operator [](xtd::size index) const {
      if (index >= length()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      return chars_[index];
    }
    
    /// @brief Returns a reference to the underlying base type.
    /// @return Reference to the underlying base type.
    virtual operator const base_type&() const noexcept {return chars_;}

    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of str.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const basic_string& str) noexcept {
      chars_.assign(str.chars_);
      return *this;
    }

    /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in `str` is moved from `str` into this string). `str` is in a valid but unspecified state afterwards.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const basic_string&& str) noexcept {
      chars_ = std::move(str.chars_);
      return *this;
    }

    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::basic_string<char, traits_type, allocator_type>& str) noexcept {
      chars_.assign(__xtd_convert_to_string<value_type>(str));
      return *this;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(std::basic_string<char, traits_type, allocator_type>&& str) noexcept {
      chars_.assign(__xtd_convert_to_string<value_type>(str));
      str.clear();
      return *this;
    }

    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::basic_string<xtd::char16, traits_type, allocator_type>& str) noexcept {
      chars_.assign(__xtd_convert_to_string<value_type>(str));
      return *this;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(std::basic_string<xtd::char16, traits_type, allocator_type>&& str) noexcept {
      chars_.assign(__xtd_convert_to_string<value_type>(str));
      str.clear();
      return *this;
    }

    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::basic_string<xtd::char32, traits_type, allocator_type>& str) noexcept {
      chars_.assign(__xtd_convert_to_string<value_type>(str));
      return *this;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(std::basic_string<xtd::char32, traits_type, allocator_type>&& str) noexcept {
      chars_.assign(__xtd_convert_to_string<value_type>(str));
      str.clear();
      return *this;
    }

#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::basic_string<xtd::char8, traits_type, allocator_type>& str) noexcept {
      chars_.assign(__xtd_convert_to_string<value_type>(str));
      return *this;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(std::basic_string<xtd::char8, traits_type, allocator_type>&& str) noexcept {
      chars_.assign(__xtd_convert_to_string<value_type>(str));
      str.clear();
      return *this;
    }
#endif

    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String to use as data source.
    /// @return This current instance.
    basic_string& operator =(const std::basic_string<xtd::wchar, traits_type, allocator_type>& str) noexcept {
      chars_.assign(__xtd_convert_to_string<value_type>(str));
      return *this;
    }

    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    basic_string& operator =(const char* str) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_.assign(__xtd_convert_to_string<value_type>(str));
      return *this;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    basic_string& operator =(const xtd::char16* str) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_.assign(__xtd_convert_to_string<value_type>(str));
      return *this;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    basic_string& operator =(const xtd::char32* str) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_.assign(__xtd_convert_to_string<value_type>(str));
      return *this;
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    basic_string& operator =(const xtd::char8* str) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_.assign(__xtd_convert_to_string<value_type>(str));
      return *this;
    }
#endif
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    basic_string& operator =(const xtd::wchar* str) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_.assign(__xtd_convert_to_string<value_type>(str));
      return *this;
    }

    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    basic_string& operator =(char* str) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_.assign(__xtd_convert_to_string<value_type>(str));
      return *this;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    basic_string& operator =(xtd::char16* str) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_.assign(__xtd_convert_to_string<value_type>(str));
      return *this;
    }
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    basic_string& operator =(xtd::char32* str) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_.assign(__xtd_convert_to_string<value_type>(str));
      return *this;
    }
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    basic_string& operator =(xtd::char8* str) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_.assign(__xtd_convert_to_string<value_type>(str));
      return *this;
    }
#endif
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `str`.
    /// @param str String litteral pointer to use as data source.
    /// @exception xtd::tring_null_pointer_exception The `str` is null.
    /// @return This current instance.
    basic_string& operator =(xtd::wchar* str) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_.assign(__xtd_convert_to_string<value_type>(str));
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

    /// @brief Copy assignment operator. Replaces the contents with the specified object.
    /// @param object The object to use as data source.
    /// @return This current instance.
    template<typename type_t>
    basic_string& operator =(const type_t& object) {
      *this = basic_string(object);
      return *this;
    }
    
    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const basic_string& rhs) {
      basic_string result = lhs;
      result.chars_.append(rhs.chars_);
      return result;
    }
    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, basic_string&& rhs) {
      basic_string result = std::move(lhs);
      result.chars_.append(std::move(rhs.chars_));
      return result;
    }
    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const basic_string& rhs) {
      basic_string result = std::move(lhs);
      result.chars_.append(rhs.chars_);
      return result;
    }
    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, basic_string&& rhs) {
      basic_string result = lhs;
      result.chars_.append(std::move(rhs.chars_));
      return result;
    }

    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const char* rhs) {
      basic_string result = lhs;
      result.chars_.append(basic_string(rhs).chars_);
      return result;
    }
    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const char* rhs) {
      basic_string result = lhs;
      result.chars_.append(basic_string(rhs).chars_);
      return result;
    }

    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const xtd::char16* rhs) {
      basic_string result = lhs;
      result.chars_.append(basic_string(rhs).chars_);
      return result;
    }
    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const xtd::char16* rhs) {
      basic_string result = lhs;
      result.chars_.append(basic_string(rhs).chars_);
      return result;
    }

    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const xtd::char32* rhs) {
      basic_string result = lhs;
      result.chars_.append(basic_string(rhs).chars_);
      return result;
    }
    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const xtd::char32* rhs) {
      basic_string result = lhs;
      result.chars_.append(basic_string(rhs).chars_);
      return result;
    }

#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const xtd::char8* rhs) {
      basic_string result = lhs;
      result.chars_.append(basic_string(rhs).chars_);
      return result;
    }
    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const xtd::char8* rhs) {
      basic_string result = lhs;
      result.chars_.append(basic_string(rhs).chars_);
      return result;
    }
#endif

    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const xtd::wchar* rhs) {
      basic_string result = lhs;
      result.chars_.append(basic_string(rhs).chars_);
      return result;
    }
    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const xtd::wchar* rhs) {
      basic_string result = lhs;
      result.chars_.append(basic_string(rhs).chars_);
      return result;
    }

    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const char* lhs, const basic_string& rhs) {
      basic_string result = basic_string(lhs).chars_;
      result.chars_.append(rhs);
      return result;
    }
    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const char* lhs, basic_string&& rhs) {
      basic_string result = basic_string(lhs).chars_;
      result.chars_.append(rhs);
      return result;
    }

    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char16* lhs, const basic_string& rhs) {
      basic_string result = basic_string(lhs).chars_;
      result.chars_.append(rhs);
      return result;
    }
    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char16* lhs, basic_string&& rhs) {
      basic_string result = basic_string(lhs).chars_;
      result.chars_.append(rhs);
      return result;
    }

    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char32* lhs, const basic_string& rhs) {
      basic_string result = basic_string(lhs).chars_;
      result.chars_.append(rhs);
      return result;
    }
    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char32* lhs, basic_string&& rhs) {
      basic_string result = basic_string(lhs).chars_;
      result.chars_.append(rhs);
      return result;
    }

#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char8* lhs, const basic_string& rhs) {
      basic_string result = basic_string(lhs).chars_;
      result.chars_.append(rhs);
      return result;
    }
    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char8* lhs, basic_string&& rhs) {
      basic_string result = basic_string(lhs).chars_;
      result.chars_.append(rhs);
      return result;
    }
#endif
    
    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::wchar* lhs, const basic_string& rhs) {
      basic_string result = basic_string(lhs).chars_;
      result.chars_.append(rhs);
      return result;
    }
    /// @brief Returns a string containing characters from `lhs` followed by the characters from `rhs`.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::wchar* lhs, basic_string&& rhs) {
      basic_string result = basic_string(lhs).chars_;
      result.chars_.append(rhs);
      return result;
    }

    /// @brief Returns a string containing characters from this current instance followed by the specified character.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const char rhs) {
      basic_string result = lhs;
      result.chars_.append(basic_string(rhs).chars_);
      return result;
    }
    /// @brief Returns a string containing characters from this current instance followed by the specified character.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const char rhs) {
      basic_string result = lhs;
      result.chars_.append(basic_string(rhs).chars_);
      return result;
    }

    /// @brief Returns a string containing characters from this current instance followed by the specified character.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const xtd::char16 rhs) {
      basic_string result = lhs;
      result.chars_.append(basic_string(rhs).chars_);
      return result;
    }
    /// @brief Returns a string containing characters from this current instance followed by the specified character.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const xtd::char16 rhs) {
      basic_string result = lhs;
      result.chars_.append(basic_string(rhs).chars_);
      return result;
    }

    /// @brief Returns a string containing characters from this current instance followed by the specified character.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const xtd::char32 rhs) {
      basic_string result = lhs;
      result.chars_.append(basic_string(rhs).chars_);
      return result;
    }
    /// @brief Returns a string containing characters from this current instance followed by the specified character.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const xtd::char32 rhs) {
      basic_string result = lhs;
      result.chars_.append(basic_string(rhs).chars_);
      return result;
    }

#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Returns a string containing characters from this current instance followed by the specified character.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const xtd::char8 rhs) {
      basic_string result = lhs;
      result.chars_.append(basic_string(rhs).chars_);
      return result;
    }
    /// @brief Returns a string containing characters from this current instance followed by the specified character.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const xtd::char8 rhs) {
      basic_string result = lhs;
      result.chars_.append(basic_string(rhs).chars_);
      return result;
    }
#endif

    /// @brief Returns a string containing characters from this current instance followed by the specified character.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const basic_string& lhs, const xtd::wchar rhs) {
      basic_string result = lhs;
      result.chars_.append(basic_string(rhs).chars_);
      return result;
    }
    /// @brief Returns a string containing characters from this current instance followed by the specified character.
    /// @param lhs The string characters who will precede the `rhs`.
    /// @param rhs The character who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(basic_string&& lhs, const xtd::wchar rhs) {
      basic_string result = lhs;
      result.chars_.append(basic_string(rhs).chars_);
      return result;
    }

    /// @brief Returns a string containing characters from this current instance followed by the specified character.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const char lhs, const basic_string& rhs) {
      basic_string result = basic_string(lhs).chars_;
      result.chars_.append(rhs);
      return result;
    }
    /// @brief Returns a string containing characters from this current instance followed by the specified character.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const char lhs, basic_string&& rhs) {
      basic_string result = basic_string(lhs).chars_;
      result.chars_.append(rhs);
      return result;
    }

    /// @brief Returns a string containing characters from this current instance followed by the specified character.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char16 lhs, const basic_string& rhs) {
      basic_string result = basic_string(lhs).chars_;
      result.chars_.append(rhs);
      return result;
    }
    /// @brief Returns a string containing characters from this current instance followed by the specified character.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char16 lhs, basic_string&& rhs) {
      basic_string result = basic_string(lhs).chars_;
      result.chars_.append(rhs);
      return result;
    }

    /// @brief Returns a string containing characters from this current instance followed by the specified character.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char32 lhs, const basic_string& rhs) {
      basic_string result = basic_string(lhs).chars_;
      result.chars_.append(rhs);
      return result;
    }
    /// @brief Returns a string containing characters from this current instance followed by the specified character.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char32 lhs, basic_string&& rhs) {
      basic_string result = basic_string(lhs).chars_;
      result.chars_.append(rhs);
      return result;
    }

#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Returns a string containing characters from this current instance followed by the specified character.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char8 lhs, const basic_string& rhs) {
      basic_string result = basic_string(lhs).chars_;
      result.chars_.append(rhs);
      return result;
    }
    /// @brief Returns a string containing characters from this current instance followed by the specified character.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::char8 lhs, basic_string&& rhs) {
      basic_string result = basic_string(lhs).chars_;
      result.chars_.append(rhs);
      return result;
    }
#endif

    /// @brief Returns a string containing characters from this current instance followed by the specified character.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::wchar lhs, const basic_string& rhs) {
      basic_string result = basic_string(lhs).chars_;
      result.chars_.append(rhs);
      return result;
    }
    /// @brief Returns a string containing characters from this current instance followed by the specified character.
    /// @param lhs The character who will precede the `rhs`.
    /// @param rhs The string characters who will follow the `lhs`.
    /// @return A string containing characters from `lhs` followed by the characters from `rhs`.
    friend basic_string operator +(const xtd::wchar lhs, basic_string&& rhs) {
      basic_string result = basic_string(lhs).chars_;
      result.chars_.append(rhs);
      return result;
    }


    basic_string& operator +=(const basic_string& str);
    basic_string& operator +=(const std::basic_string<value_type, traits_type, allocator_type>& str);
    basic_string& operator +=(const value_type* str);
    template<typename other_char_t>
    basic_string& operator +=(const std::basic_string<other_char_t>& str);
    template<typename other_char_t>
    basic_string& operator +=(const other_char_t* str);
    
    basic_string& operator +=(value_type character);
    template<typename other_char_t>
    basic_string& operator +=(other_char_t character);
    basic_string& operator +=(const std::initializer_list<value_type>& il);
    template<typename other_char_t>
    basic_string& operator +=(const std::initializer_list<other_char_t>& il);
    
    template<typename type_t>
    basic_string& operator +=(const type_t& object) {
      *this = *this + basic_string(object);
      return *this;
    }
    
    bool operator ==(const std::basic_string<value_type, traits_type, allocator_type>& other) const;
    bool operator !=(const std::basic_string<value_type, traits_type, allocator_type>& other) const;
    bool operator ==(const value_type* other) const;
    bool operator !=(const value_type* other) const;
        
    friend std::ostream& operator <<(std::ostream& stream, const basic_string& str) {return stream << str.chars_;}
    friend std::istream& operator >>(std::istream& stream, basic_string& str) {
      decltype(str.chars_) s;
      stream >> s;
      str = s;
      return stream;
    }
    /// @}

  private:
    base_type chars_;
  };

  /// @cond
  template<typename char_t, typename traits_t, typename allocator_t>
  inline const basic_string<char_t, traits_t, allocator_t> basic_string<char_t, traits_t, allocator_t>::empty_string;
  /// @endcond
}

/// @cond
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
