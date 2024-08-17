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
  class basic_string : /*public object,*/ public xtd::icomparable<basic_string<char_t, traits_t, allocator_t>>/*, public xtd::iequatable<basic_string<char_t, traits_t, allocator_t>>*/ /*, public xtd::ienumerable<basic_string<char_t, traits_t, allocator_t>>*/ {
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
    inline static const basic_string empty_string;
    
    /// @brief This is a special value equal to the maximum value representable by the type xtd::size.
    inline static size_type npos = base_type::npos;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes a new instance of xtd::basic_string.
    basic_string() noexcept = default;
    /// @brief Initializes a new instance of xtd::basic_string with specified allocator.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    explicit basic_string(const allocator_type& allocator) noexcept : chars_(allocator) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character.
    /// @param str The basic_string to copy.
    /// @param count The number of copies of character.
    /// @param character The character copied.
    basic_string(xtd::size count, value_type character) : chars_(count, character) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character and specified allocator.
    /// @param str The basic_string to copy.
    /// @param count The number of copies of character.
    /// @param character The character copied.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(xtd::size count, value_type character, const allocator_type& allocator) : chars_(count, character, allocator) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character.
    /// @param str The basic_string to copy.
    /// @param count The number of copies of character.
    /// @param character The character copied.
    template<typename other_char_t>
    basic_string(xtd::size count, other_char_t character) : basic_string(std::basic_string<other_char_t>(count, character)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified count copies of character and specified allocator.
    /// @param str The basic_string to copy.
    /// @param count The number of copies of character.
    /// @param character The character copied.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    template<typename other_char_t>
    basic_string(xtd::size count, other_char_t character, const allocator_type& allocator) : basic_string(std::basic_string<other_char_t>(count, character), allocator) {}
    
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index.
    /// @param str The basic_string to copy.
    /// @param index The index of the first substring character where start copy.
    basic_string(const basic_string& str, xtd::size index) : chars_(str.chars_, index) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index and allocator.
    /// @param str The basic_string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const basic_string& str, xtd::size index, const allocator_type& allocator) : chars_(str.chars_, index, allocator) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index and count characters.
    /// @param str The basic_string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    basic_string(const basic_string& str, xtd::size index, xtd::size count) : chars_(str.chars_, index, count) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified substring at index, count characters and allocator.
    /// @param str The basic_string to copy.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const basic_string& str, xtd::size index, xtd::size count, const allocator_type& allocator) : chars_(str.chars_, index, count, allocator) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified substring and count characters.
    /// @param count The number of substring characters to copy.
    basic_string(const value_type* str, xtd::size count) : chars_(str, count) {if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);}
    /// @brief Initializes a new instance of xtd::basic_string with specified substring, count characters and allocator.
    /// @param str The basic_string to copy.
    /// @param count The number of substring characters to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const value_type* str, xtd::size count, const allocator_type& allocator) : chars_(str, count, allocator) {if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);}
    /// @brief Initializes a new instance of xtd::basic_string with specified basic_string to copy.
    basic_string(const value_type* str) : chars_(str) {if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);} // Can't be explicit by design.
    /// @brief Initializes a new instance of xtd::basic_string with specified basic_string to copy, and allocator.
    /// @param str The basic_string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const value_type* str, const allocator_type& allocator) : chars_(str, allocator) {if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);}
    /// @brief Initializes a new instance of xtd::basic_string with specified basic_string to copy.
    basic_string(value_type* str) : chars_(str) {if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);} // Can't be explicit by design.
    /// @brief Initializes a new instance of xtd::basic_string with specified basic_string to copy, and allocator.
    /// @param str The basic_string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(value_type* str, const allocator_type& allocator) : chars_(str, allocator) {if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);}
    /// @brief Initializes a new instance of xtd::basic_string with specified basic_string to copy.
    /// @param str The basic_string to copy.
    basic_string(const basic_string& str) noexcept : chars_(str.chars_) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified basic_string to copy and allocator.
    /// @param str The basic_string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const basic_string& str, const allocator_type& allocator) noexcept : chars_(str.chars_, allocator) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified basic_string to copy.
    /// @param str The basic_string to copy.
    basic_string(const std::basic_string<value_type>& str) noexcept : chars_(str) {}; // Can't be explicit by design.
    /// @brief Initializes a new instance of xtd::basic_string with specified basic_string to copy and allocator.
    /// @param str The basic_string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(const std::basic_string<value_type>& str, const allocator_type& allocator) noexcept : chars_(str, allocator) {}

    /// @brief Initializes a new instance of xtd::basic_string with specified basic_string to copy.
    /// @param str The basic_string to copy.
    template<typename other_char_t>
    basic_string(const other_char_t* str) : basic_string(std::basic_string<other_char_t>(str)) {if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);}// Can't be explicit by design.
    /// @brief Initializes a new instance of xtd::basic_string with specified basic_string to copy, and allocator.
    /// @param str The basic_string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    template<typename other_char_t>
    basic_string(const other_char_t* str, const allocator_type& allocator) : basic_string(std::basic_string<other_char_t>(str), allocator) {if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);}
    /// @brief Initializes a new instance of xtd::basic_string with specified basic_string to copy.
    /// @param str The basic_string to copy.
    template<typename other_char_t>
    basic_string(other_char_t* str) {if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);} // Can't be explicit by design.
    /// @brief Initializes a new instance of xtd::basic_string with specified basic_string to copy, and allocator.
    /// @param str The basic_string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    template<typename other_char_t>
    basic_string(other_char_t* str, const allocator_type& allocator) : basic_string(std::basic_string<other_char_t>(str), allocator) {if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);}
    /// @brief Initializes a new instance of xtd::basic_string with specified basic_string to copy.
    /// @param str The basic_string to copy.
    template<typename other_char_t>
    basic_string(const std::basic_string<other_char_t>& str) noexcept : chars_(__xtd_convert_to_string<value_type>(str)) {} // Can't be explicit by design.
    /// @brief Initializes a new instance of xtd::basic_string with specified basic_string to copy and allocator.
    /// @param str The basic_string to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    template<typename other_char_t>
    basic_string(const std::basic_string<other_char_t>& str, const allocator_type& allocator) noexcept : chars_(__xtd_convert_to_string<value_type>(str), allocator) {}

    /// @brief Initializes a new instance of xtd::basic_string with specified basic_string to move.
    /// @param str The basic_string to move.
    basic_string(basic_string&& str) noexcept : chars_(std::move(str.chars_)) {str.chars_.clear();}
    /// @brief Initializes a new instance of xtd::basic_string with specified basic_string to move and allocator.
    /// @param str The basic_string to move.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(basic_string&& str, const allocator_type& allocator) noexcept : chars_(std::move(str.chars_), allocator) {str.chars_.clear();}
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
    /// @brief Initializes a new instance of xtd::basic_string with specified basic_string view of substring and allocator.
    /// @param string_view The basic_string view.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    template<typename string_view_like_t>
    explicit constexpr basic_string(const string_view_like_t& string_view, const allocator_type& allocator = allocator_type()) : chars_(string_view, allocator) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified basic_string view of substring and allocator.
    /// @param string_view The basic_string view.
    /// @param index The index of the first substring character where start copy.
    /// @param count The number of substring characters to copy.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    template<typename string_view_like_t>
    constexpr basic_string(const string_view_like_t& string_view, size_type index, size_type count, const allocator_type& allocator = allocator_type()) : chars_(string_view, index, count, allocator) {}

    /// @brief Initializes a new instance of xtd::basic_string with specified initializer list.
    /// @param il The initializer list to fill.
    basic_string(std::initializer_list<value_type> il) : chars_(il) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified initializer list and allocator.
    /// @param il The initializer list to fill.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    basic_string(std::initializer_list<value_type> il, const allocator_type& allocator) : chars_(il, allocator) {}

    /// @brief Initializes a new instance of xtd::basic_string with specified initializer list.
    /// @param il The initializer list to fill.
    template<typename other_char_t>
    basic_string(std::initializer_list<other_char_t> il) : basic_string(std::basic_string<other_char_t>(il)) {}
    /// @brief Initializes a new instance of xtd::basic_string with specified initializer list and allocator.
    /// @param il The initializer list to fill.
    /// @param allocator The allocator to use for all memory allocations of this basic_string.
    template<typename other_char_t>
    basic_string(std::initializer_list<other_char_t> il, const allocator_type& allocator) : basic_string(std::basic_string<other_char_t>(il), allocator) {}
    /// @}
    
    /// @cond
    /*
    template<typename type_t>
    basic_string(const type_t& object) : chars_(object) {}
    template<typename type_t>
    basic_string(const type_t& object, const allocator_type& allocator) : chars_(object, allocator) {}
    template<typename type_t>
    basic_string(const type_t& object, xtd::size index, xtd::size count) : chars_(object, index, count) {}
    template<typename type_t>
    basic_string(const type_t& object, xtd::size index, xtd::size count, const allocator_type& allocator) : chars_(object, index, count, allocator) {}
    template<typename type_t>
    basic_string(const type_t& object, xtd::size count) : chars_(object, 0, count) {}
    template<typename type_t>
    basic_string(const type_t& object, xtd::size count, const allocator_type& allocator) :chars_(object, 0, count, allocator) {}
     */
    
    basic_string& operator =(const basic_string& str) noexcept {
      chars_.assign(str.chars_);
      return *this;
    }
    basic_string& operator =(const std::basic_string<value_type, traits_type, allocator_type>& str) noexcept {
      chars_.assign(str);
      return *this;
    }
    basic_string& operator =(const value_type* str) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_.assign(str);
      return *this;
    }

    template<typename other_char_t>
    basic_string& operator =(const std::basic_string<other_char_t>& str) noexcept {
      chars_.assign(__xtd_convert_to_string<value_type>(str));
      return *this;
    }
    template<typename other_char_t>
    basic_string& operator =(const other_char_t* str) {
      if (str == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      chars_.assign(__xtd_convert_to_string<value_type>(*str));
      return *this;
    }

    
    basic_string& operator =(value_type character) {
      *this = basic_string(1, character);
      return  *this;
    }

    template<typename other_char_t>
    basic_string& operator =(other_char_t character) {
      *this = basic_string(1, character);
      return  *this;
    }

    basic_string& operator =(const std::initializer_list<value_type>& il) {
      assign(il);
      return *this;
    }

    template<typename other_char_t>
    basic_string& operator =(const std::initializer_list<other_char_t>& il) {
      *this = basic_string(il);
      return *this;
    }

    //template<typename type_t>
    //basic_string& operator =(const type_t& object) {return std::basic_string<value_type>::assign(object);}
    
    template<typename type_t>
    basic_string operator +(const type_t& object) const {
      basic_string result(*this);
      result.append(object);
      return result;
    }
    
    template<typename type_t>
    basic_string operator +(const type_t* object) const {
      if (object == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      basic_string result(*this);
      result.append(basic_string(object));
      return result;
    }
    
    template<typename type_t>
    basic_string operator +(type_t* object) const {
      if (object == null) __throw_basic_string_null_pointer_exception(__FILE__, __LINE__, __func__);
      basic_string result(*this);
      result.append(basic_string(object));
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
    
    bool operator ==(const basic_string& other) const;
    bool operator !=(const basic_string& other) const;
    bool operator ==(const std::basic_string<value_type, traits_type, allocator_type>& other) const;
    bool operator !=(const std::basic_string<value_type, traits_type, allocator_type>& other) const;
    bool operator ==(const value_type* other) const;
    bool operator !=(const value_type* other) const;

    template<typename other_char_t>
    bool operator ==(const std::basic_string<other_char_t>& other) const;
    template<typename other_char_t>
    bool operator !=(const std::basic_string<other_char_t>& other) const;
    template<typename other_char_t>
    bool operator ==(const other_char_t* other) const;
    template<typename other_char_t>
    bool operator !=(const other_char_t* other) const;

    const value_type& operator [](xtd::size index) const {
      if (index >= length()) __throw_basic_string_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      return chars_[index];
    }
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    xtd::size length() const noexcept {return chars_.size();}
    
    const_iterator begin() const {return chars_.begin();}
    iterator begin() {return chars_.begin();}

    const_iterator cbegin() const {return chars_.cbegin();}
    
    const base_type& chars() const noexcept {return chars_;}
    base_type& chars() noexcept {return chars_;}

    const_iterator cend() const {return chars_.cend();}
    
    const_iterator end() const {return chars_.end();}
    iterator end() {return chars_.end();}
    /// @}
    
    /// @name Public Methods
    
    /// @{
    int32 compare_to(const basic_string& value) const noexcept override {return chars_.compare(value.chars_);}
    
    /// @brief Returns a value indicating whether a specified char occurs within this basic_string.
    /// @param value The char to seek.
    /// @return true if the value parameter occurs within this basic_string; otherwise, false.
    bool contains(value_type value) const noexcept;
    /// @brief Returns a value indicating whether a specified char occurs within this basic_string.
    /// @param value The char to seek.
    /// @return true if the value parameter occurs within this basic_string; otherwise, false.
    template<typename other_char_t>
    bool contains(other_char_t value) const noexcept;
    /// @brief Returns a value indicating whether a specified substring occurs within this basic_string.
    /// @param value The basic_string to seek.
    /// @return true if the value parameter occurs within this basic_string, or if value is the empty basic_string (""); otherwise, false.
    bool contains(const basic_string& value) const noexcept;

    /// @brief Determines whether this instance and a specified object, which must also be a xtd::basic_string object, have the same value.
    /// @param obj The basic_string to compare to this instance.
    /// @return `true` if `obj` is a xtd::basic_string and its value is the same as this instance; otherwise, `false`.
    bool equals(const object& obj) const noexcept /*override*/;
    /// @brief Determines whether this instance and another specified String object have the same value.
    /// @param value The basic_string to compare to this instance.
    /// @return `true` if the `value` of the value parameter is the same as the value of this instance; otherwise, `false`.
    /// @remarks This method performs an ordinal (case-sensitive) comparison.
    bool equals(const basic_string& value) const noexcept;
    /// @brief Determines whether this instance and another specified String object have the same value, ignoring or honoring their case.
    /// @param value The basic_string to compare to this instance.
    /// @param ignore_case true to ignore case when comparing this instance and value; otherwise, false
    /// @return `true` if the `value` of the value parameter is the same as the value of this instance; otherwise, `false`.
    /// @remarks This method performs an ordinal comparison.
    bool equals(const basic_string& value, bool ignore_case) const noexcept;

    /// @brief Determines whether the end of this basic_string matches the specified character.
    /// @param value The char_t to compare to the substring at the end of this instance.
    /// @return true if value matches the end of this instance; otherwise, false.
    bool ends_with(value_type value) const noexcept;
    /// @brief Determines whether the end of this basic_string matches the specified character.
    /// @param value The char_t to compare to the substring at the end of this instance.
    /// @return true if value matches the end of this instance; otherwise, false.
    template<typename other_char_t>
    bool ends_with(other_char_t value) const noexcept;
    /// @brief Determines whether the end of this basic_string matches the specified basic_string.
    /// @param value The basic_string to compare to the substring at the end of this instance.
    /// @return true if value matches the end of this instance; otherwise, false.
    bool ends_with(const basic_string& value) const noexcept;
    /// @brief Determines whether the end of this basic_string instance matches the specified basic_string when compared using the specified culture.
    /// @param ignore_case true to ignore case during the comparison; otherwise, false.
    /// @return bool true if value matches the end of the specified basic_string; otherwise, false.
    bool ends_with(const basic_string& value, bool ignore_case) const noexcept;
    /// @brief Determines whether the end of this basic_string matches the specified basic_string when compared using the specified comparison option.
    /// @param comparison_type One of the enumeration values that determines how this basic_string and value are compared.
    /// @return bool true if value matches the end of the specified basic_string; otherwise, false.
    bool ends_with(const basic_string& value, xtd::string_comparison comparison_type) const noexcept;
    
    /// @brief Returns the hash code for this basic_string.
    /// @return A hash code.
    xtd::size get_hash_code() const noexcept /*override*/;
    
    /// @brief Reports the index of the first occurrence of the specified character in this basic_string.
    /// @param value An unicode character to seek
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    xtd::size index_of(value_type value) const noexcept;
    /// @brief Reports the index of the first occurrence of the specified basic_string in this basic_string.
    /// @param value An unicode character to seek
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    xtd::size index_of(const basic_string& value) const noexcept;
    /// @brief Reports the index of the first occurrence of the specified character in this basic_string. The search starts at a specified character position.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    xtd::size index_of(value_type value, xtd::size start_index) const noexcept;
    /// @brief Reports the index of the first occurrence of the specified character in this basic_string. The search starts at a specified character position.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    xtd::size index_of(const basic_string& value, xtd::size start_index) const noexcept;
    /// @brief Reports the index of the first occurrence of the specified character in this basic_string. The search starts at a specified character position and examines a specified number of character positions.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    xtd::size index_of(value_type value, xtd::size start_index, xtd::size count) const noexcept;
    /// @brief Reports the index of the first occurrence of the specified character in this basic_string. The search starts at a specified character position and examines a specified number of character positions.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    xtd::size index_of(const basic_string& value, xtd::size start_index, xtd::size count) const noexcept;
    
    /// @brief Reports the index of the first occurrence in this instance of any character in a specified array of characters.
    /// @param values An unicode character array containing one or more characters to seek
    /// @return The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<char_t>::npos if no character in values was found.
    xtd::size index_of_any(const std::vector<value_type>& values) const noexcept;
    /// @brief Reports the index of the first occurrence in this instance of any character in a specified array of characters. The search starts at a specified character position.
    /// @param values An unicode character array containing one or more characters to seek
    /// @param start_index The search starting position
    /// @return The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<char_t>::npos if no character in values was found.
    xtd::size index_of_any(const std::vector<value_type>& values, xtd::size start_index) const noexcept;
    /// @brief Reports the index of the first occurrence in this instance of any character in a specified array of characters. The search starts at a specified character position.
    /// @param values An unicode character array containing one or more characters to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine.
    /// @return The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<char_t>::npos if no character in values was found.
    xtd::size index_of_any(const std::vector<value_type>& values, xtd::size start_index, xtd::size count) const noexcept;
    /// @cond
    xtd::size index_of_any(const std::initializer_list<value_type>& values) const noexcept;
    xtd::size index_of_any(const std::initializer_list<value_type>& values, xtd::size start_index) const noexcept;
    xtd::size index_of_any(const std::initializer_list<value_type>& values, xtd::size start_index, xtd::size count) const noexcept;
    /// @endcond
    
    /// @brief Inserts a specified instance of basic_string at a specified index position in this instance.
    /// @param start_index The index position of the insertion.
    /// @param value The basic_string to insert.
    /// @return A new basic_string equivalent to this instance but with value inserted at position start_index.
    /// @remarks If start_index is equal to the length of this instance, value is appended to the end of this instance.
    /// @remarks For example, the return value of "abc".Insert(2, "XYZ") is "abXYZc".
    basic_string insert(xtd::size start_index, const basic_string& value) const noexcept;
    
    /// @brief Indicates whether this basic_string is an empty basic_string ("").
    /// @return true if the value parameter is null or an empty basic_string (""); otherwise, false.
    /// @deprecated Replaced by xtd::basic_string::is_empty(const xtd::basic_string&) - Will be removed in version 0.4.0
    [[deprecated("Replaced by xtd::basic_string::is_empty(const xtd::basic_string&) - Will be removed in version 0.4.0")]]
    bool is_empty() const noexcept {return is_empty(*this);}
    
    /// @brief Reports the index of the last occurrence of the specified character in this tring.
    /// @param value An unicode character to seek
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    xtd::size last_index_of(value_type value) const noexcept;
    /// @brief Reports the index of the last occurrence of the specified basic_string in this basic_string.
    /// @param value An unicode character to seek
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    xtd::size last_index_of(const basic_string& value) const noexcept;
    /// @brief Reports the index of the last occurrence of the specified character in this basic_string. The search starts at a specified character position.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    xtd::size last_index_of(value_type value, xtd::size start_index) const noexcept;
    /// @brief Reports the index of the last occurrence of the specified character in this basic_string. The search starts at a specified character position.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    xtd::size last_index_of(const basic_string& value, xtd::size start_index) const noexcept;
    /// @brief Reports the index of the last occurrence of the specified character in this basic_string. The search starts at a specified character position and examines a specified number of character positions.
    /// @param str A basic_string to find last index of.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    xtd::size last_index_of(value_type value, xtd::size start_index, xtd::size count) const noexcept;
    /// @brief Reports the index of the last occurrence of the specified character in this basic_string. The search starts at a specified character position and examines a specified number of character positions.
    /// @param value An unicode character to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine
    /// @return The index position of value if that character is found, or std::basic_string<char_t>::npos if it is not.
    xtd::size last_index_of(const basic_string& value, xtd::size start_index, xtd::size count) const noexcept;

    /// @brief Reports the index of the last occurrence in this instance of any character in a specified array of characters.
    /// @param values An unicode character array containing one or more characters to seek
    /// @return The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<char_t>::npos if no character in values was found.
    xtd::size last_index_of_any(const std::vector<value_type>& values) const noexcept;
    /// @brief Reports the index of the last occurrence in this instance of any character in a specified array of characters. The search starts at a specified character position.
    /// @param values An unicode character array containing one or more characters to seek
    /// @param start_index The search starting position
    /// @return The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<char_t>::npos if no character in values was found.
    xtd::size last_index_of_any(const std::vector<value_type>& values, xtd::size start_index) const noexcept;
    /// @brief Reports the index of the last occurrence in this instance of any character in a specified array of characters. The search starts at a specified character position.
    /// @param values An unicode character array containing one or more characters to seek
    /// @param start_index The search starting position
    /// @param count The number of character positions to examine.
    /// @return The index position of the first occurrence in this instance where any character in values was found; otherwise, std::basic_string<char_t>::npos if no character in values was found.
    xtd::size last_index_of_any(const std::vector<value_type>& values, xtd::size start_index, xtd::size count) const noexcept;
    /// @cond
    xtd::size last_index_of_any(const std::initializer_list<value_type>& values) const noexcept;
    xtd::size last_index_of_any(const std::initializer_list<value_type>& values, xtd::size start_index) const noexcept;
    xtd::size last_index_of_any(const std::initializer_list<value_type>& values, xtd::size start_index, xtd::size count) const noexcept;
    /// @endcond
    
    /// @brief Right-aligns the characters in this basic_string, padding with spaces on the left for a specified total length.
    /// @param total_width The number of characters in the resulting basic_string, equal to the number of original characters plus any additional padding characters.
    /// @return A new basic_string that is equivalent to the specified basic_string, but right-aligned and padded on the left with as many spaces as needed to create a length of total_width. Or, if total_width is less than the length of the specified basic_string, a new basic_string object that is identical to the specified basic_string.
    /// @remarks An unicode space is defined as hexadecimal 0x20.
    /// @remarks The pad_left(const std::basic_string<char_t>&, int) method pads the beginning of the returned basic_string. This means that, when used with right-to-left languages, it pads the right portion of the basic_string..
    basic_string pad_left(xtd::size total_width) const noexcept;
    /// @brief Right-aligns the characters in this basic_string, padding with spaces on the left for a specified total length.
    /// @param total_width The number of characters in the resulting basic_string, equal to the number of original characters plus any additional padding characters.
    /// @param paddingChar An unicode padding character.
    /// @return A new basic_string that is equivalent to the specified basic_string, but right-aligned and padded on the left with as many spaces as needed to create a length of total_width. Or, if total_width is less than the length of the specified basic_string, a new basic_string object that is identical the specified basic_string.
    /// @remarks An unicode space is defined as hexadecimal 0x20.
    /// @remarks The pad_left(const std::basic_string<char_t>&, int) method pads the beginning of the returned basic_string. This means that, when used with right-to-left languages, it pads the right portion of the basic_string..
    basic_string pad_left(xtd::size total_width, char32 padding_char) const noexcept;

    /// @brief Left-aligns the characters in this basic_string, padding with spaces on the right for a specified total length.
    /// @param totalWidth The number of characters in the resulting basic_string, equal to the number of original characters plus any additional padding characters.
    /// @return A new basic_string that is equivalent to the specified basic_string, but left-aligned and padded on the right with as many spaces as needed to create a length of totalWidth. Or, if totalWidth is less than the length of the specified basic_string, a new basic_string object that is identical to the specified basic_string.
    /// @remarks An unicode space is defined as hexadecimal 0x20.
    /// @remarks The PadRight(const std::basic_string<char_t>&, int) method pads the end of the returned basic_string. This means that, when used with right-to-left languages, it pads the left portion of the basic_string..
    basic_string pad_right(xtd::size total_width) const noexcept;
    /// @brief Left-aligns the characters in this basic_string, padding with spaces on the right for a specified total length.
    /// @param totalWidth The number of characters in the resulting basic_string, equal to the number of original characters plus any additional padding characters.
    /// @param paddingChar An unicode padding character.
    /// @return A new basic_string that is equivalent to the specified basic_string, but left-aligned and padded on the tight with as many spaces as needed to create a length of totalWidth. Or, if totalWidth is less than the length of the specified basic_string, a new basic_string object that is identical to the specified basic_string.
    /// @remarks An unicode space is defined as hexadecimal 0x20.
    /// @remarks The xtd::basic_string::pad_right method pads the end of the returned basic_string. This means that, when used with right-to-left languages, it pads the left portion of the basic_string..
    basic_string pad_right(xtd::size total_width, char32 padding_char) const noexcept;

    /// @brief Allows insertion and extraction of quoted strings, such as the ones found in [CSV](https://en.wikipedia.org/wiki/Comma-separated_values) or [XML](https://en.wikipedia.org/wiki/XML).
    /// @return A new quoted basic_string.
    /// @remarks the delimiter is set to @verbatim " @endverbatim by default and the escape is set to `\` by  default.
    /// @remarks for more information see [std::quoted](https://en.cppreference.com/w/cpp/io/manip/quoted).
    basic_string quoted() const;
    /// @brief Allows insertion and extraction of quoted strings, such as the ones found in [CSV](https://en.wikipedia.org/wiki/Comma-separated_values) or [XML](https://en.wikipedia.org/wiki/XML) ith specified delimiter and escape.
    /// @param delimiter The character to use as the delimiter, defaults to `"`.
    /// @param escape The character to use as the escape character, defaults to `\`.
    /// @return A new quoted basic_string.
    /// @remarks for more information see [std::quoted](https://en.cppreference.com/w/cpp/io/manip/quoted).
    basic_string quoted(value_type delimiter, value_type escape) const;
    
    /// @brief Deletes all the characters from this basic_string beginning at a specified position and continuing through the last position.
    /// @param start_index The position to begin deleting characters.
    /// @return A new basic_string object that is equivalent to this basic_string less the removed characters.
    basic_string remove(xtd::size start_index) const noexcept;
    /// @brief Deletes all the characters from this basic_string beginning at a specified position and continuing through the last position.
    /// @param start_index The position to begin deleting characters.
    /// @param count The number of characters to delete.
    /// @return A new basic_string object that is equivalent to this basic_string less the removed characters.
    basic_string remove(xtd::size start_index, xtd::size count) const noexcept;
    
    /// @brief Replaces all occurrences of a specified char_t in this basic_string with another specified char_t.
    /// @param old_char A char_t to be replaced.
    /// @param new_char A char_t to replace all occurrences of old_char.
    /// @return A new basic_string equivalent to the specified basic_string but with all instances of old_char replaced with new_char.
    basic_string replace(value_type old_char, value_type new_char) const noexcept;
    /// @brief Replaces all occurrences of a specified basic_string in this basic_string with another specified basic_string.
    /// @param old_string A basic_string to be replaced.
    /// @param new_string A basic_string to replace all occurrences of old_string.
    /// @return A new basic_string equivalent to the specified basic_string but with all instances of old_string replaced with new_string.
    /// @remarks If new_string is empty, all occurrences of old_string are removed
    basic_string replace(const basic_string& old_string, const basic_string& new_string) const noexcept;
    
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
    std::vector<basic_string> split(const std::vector<value_type>& separators, xtd::size count, string_split_options options) const noexcept;
    /// @brief Splits this basic_string into substrings that are based on the default white-space characters. White-space characters are defined by the c++ standard and return true if they are passed to the xtd::char_object::isspace() or std::iswspace() method.
    /// @return An array whose elements contain the substrings in this basic_string that are delimited by one or more characters in white-space separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    std::vector<basic_string> split() const noexcept;
    /// @brief Splits this basic_string into substrings that are based on the characters in an array.
    /// @param separators A character array that delimits the substrings in this basic_string, an empty array that contains no delimiters.
    /// @return An array whose elements contain the substrings in this basic_string that are delimited by one or more characters in separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    std::vector<basic_string> split(const std::vector<value_type>& separators) const noexcept;
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
    std::vector<basic_string> split(const std::vector<value_type>& separators, string_split_options options) const noexcept;
    /// @brief Splits this basic_string into a maximum number of substrings based on the characters in an array. You also specify the maximum number of substrings to return.
    /// @param separators A character array that delimits the substrings in this basic_string, an empty array that contains no delimiters.
    /// @param count The maximum number of substrings to return.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If the specified basic_string does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains the specified basic_string.
    /// @remarks If the separator parameter contains no characters, white-space characters are assumed to be the delimiters. White-space characters are defined by the Unicode standard and return true if they are passed to the char_t.IsWhiteSpace method.
    /// @remarks Each element of separator defines a separate delimiter character. If two delimiters are adjacent, or a delimiter is found at the beginning or end of the specified basic_string, the corresponding array element contains empty basic_string.
    /// @remarks If there are more than count substrings in the specified basic_string, the first count minus 1 substrings are returned in the first count minus 1 elements of the return value, and the remaining characters in the specified basic_string are returned in the last element of the return value.
    std::vector<basic_string> split(const std::vector<value_type>& separators, xtd::size count) const noexcept;
    
    /// @brief Determines whether the beginning of this instance of xtd::basic_string matches a specified xtd::basic_string.
    /// @param value A xtd::basic_string to compare to.
    /// @return bool true if value matches the beginning of the specified basic_string; otherwise, false.
    /// @remarks This method compares value to the substring at the beginning of the specified basic_string that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the beginning of the specified basic_string.
    bool starts_with(value_type value) const noexcept;
    /// @brief Determines whether the beginning of this instance of xtd::basic_string matches a specified xtd::basic_string, ignoring or honoring their case.
    /// @param value A xtd::basic_string to compare to.
    /// @param ignore_case true to ignore case when comparing the specified basic_string and value; otherwise, false
    /// @return bool true if value matches the beginning of the specified basic_string; otherwise, false.
    /// @remarks This method compares value to the substring at the beginning of the specified basic_string that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the beginning of the specified basic_string.
    bool starts_with(value_type value, bool ignore_case) const noexcept;
    /// @brief Determines whether the beginning of this instance of xtd::basic_string matches a specified xtd::basic_string.
    /// @param value A xtd::basic_string to compare to.
    /// @return bool true if value matches the beginning of the specified basic_string; otherwise, false.
    /// @remarks This method compares value to the substring at the beginning of the specified basic_string that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the beginning of the specified basic_string.
    bool starts_with(const basic_string& value) const noexcept;
    /// @brief Determines whether the beginning of this instance of xtd::basic_string matches a specified xtd::basic_string, ignoring or honoring their case.
    /// @param value A xtd::basic_string to compare to.
    /// @param ignore_case true to ignore case when comparing the specified basic_string and value; otherwise, false
    /// @return bool true if value matches the beginning of the specified basic_string; otherwise, false.
    /// @remarks This method compares value to the substring at the beginning of the specified basic_string that is the same length as value, and returns an indication whether they are equal. To be equal, value must be a reference to this same instance, or match the beginning of the specified basic_string.
    bool starts_with(const basic_string& value, bool ignore_case) const noexcept;
    
    /// @brief Returns a substring [`pos`, `pos + count`). If the requested substring extends past the end of the basic_string, i.e. the `count` is greater than `size()` - `pos` (e.g. if `count` == `npos`), the returned substring is [`pos`, xtd::basic_string::size()).
    /// @param pos The position of the first character to include.
    /// @param count The length of the substring.
    /// @return xtd::basic_string containing the substring [`pos`, `pos` + `count`) or [`pos`, xtd::basic_string::size()).
    basic_string substr(size_type pos = 0, size_type count = npos) const;

    /// @brief Retrieves a substring from this instance. The substring starts at a specified character position and has a specified length.
    /// @param str basic_string to substring.
    /// @param start_index The zero-based starting character position of a substring in this instance.
    /// @return A basic_string equivalent to the substring of length length that begins at start_index in this instance, or Empty if start_index is equal to the length of this instance and length is zero.
    basic_string substring(xtd::size start_index) const noexcept;
    /// @brief Retrieves a substring from this instance. The substring starts at a specified character position and has a specified length.
    /// @param start_index The zero-based starting character position of a substring in this instance.
    /// @param length The number of characters in the substring.
    /// @return A basic_string equivalent to the substring of length length that begins at start_index in this instance, or Empty if start_index is equal to the length of this instance and length is zero.
    basic_string substring(xtd::size start_index, xtd::size length) const noexcept;
    
    /// @brief Copies the characters in this instance to a Unicode character array.
    /// @return A character array whose elements are the individual characters of this instance. If this instance is an empty xtd::basic_string, the returned array is empty and has a zero length.
    std::vector<value_type> to_array() const noexcept;
    /// @brief Copies the characters in this instance to a Unicode character array starting at specified index.
    /// @param start_index The starting position of basic_string to convert.
    /// @return A character array whose elements are the individual characters of this instance. If this instance is an empty xtd::basic_string, the returned array is empty and has a zero length.
    std::vector<value_type> to_array(xtd::size start_index) const noexcept;
    /// @brief Copies the characters in this instance to a Unicode character array starting at specified index with specified length.
    /// @param start_index The starting position of basic_string to convert.
    /// @param length The length of the basic_string to convert
    /// @return A character array whose elements are the individual characters of this instance. If this instance is an empty xtd::basic_string, the returned array is empty and has a zero length.
    std::vector<value_type> to_array(xtd::size start_index, xtd::size length) const noexcept;
    
    /// @brief Returns a copy of the current basic_string converted to lowercase.
    /// @return A new basic_string in lowercase.
    basic_string to_lower() const noexcept;
    
    basic_string<char> to_string() const noexcept /*override*/ {return __xtd_convert_to_string<char>(*this);}
    
    /// @brief Converts the current basic_string to title case (except for words that are entirely in uppercase, which are considered to be acronyms).
    /// @return A new basic_string in title case.
    basic_string to_title_case() const noexcept;
    
    /// @brief Returns a copy of the current basic_string converted to uppercase.
    /// @return A new basic_string in uppercase.
    basic_string to_upper() const noexcept;
    
    /// @brief Removes all leading and trailing occurrences of white-space characters from the specified xtd::basic_string.
    /// @param str xtd::basic_string to trim end.
    /// @param trim_char A character to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the character in the trim_char parameter are removed from the start and te and of the specified xtd::basic_string.
    basic_string trim() const noexcept;
    /// @brief Removes all leading and trailing occurrences of a character specified from the specified xtd::basic_string .
    /// @param str xtd::basic_string to trim start.
    /// @param trim_char A character to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the character in the trim_char parameter are removed from the start and the end of the specified xtd::basic_string.
    basic_string trim(value_type trim_char) const noexcept;
    /// @brief Removes all leading and trailing occurrences of a set of characters specified in an array from the specified xtd::basic_string.
    /// @param str xtd::basic_string to trim end.
    /// @param trim_chars An array of characters to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the characters in the trim_chars parameter are removed from the start and the edn of the specified xtd::basic_string.
    basic_string trim(const std::vector<value_type>& trim_chars) const noexcept;
    
    /// @brief Removes all trailing occurrences of white-space characters from the specified xtd::basic_string.
    /// @param str xtd::basic_string to trim end.
    /// @param trim_char A character to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the character in the trim_char parameter are removed from the end of the specified xtd::basic_string.
    basic_string trim_end() const noexcept;
    /// @brief Removes all trailing occurrences of a character specified from the specified xtd::basic_string .
    /// @param str xtd::basic_string to trim start.
    /// @param trim_char A character to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the character in the trim_char parameter are removed from the end of the specified xtd::basic_string.
    basic_string trim_end(value_type trim_char) const noexcept;
    /// @brief Removes all trailing occurrences of a set of characters specified in an array from the specified xtd::basic_string.
    /// @param str xtd::basic_string to trim end.
    /// @param trim_chars An array of characters to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the characters in the trim_chars parameter are removed from the end of the specified xtd::basic_string.
    basic_string trim_end(const std::vector<value_type>& trim_chars) const noexcept;
    
    /// @brief Removes all leading occurrences of white-space characters from the specified xtd::basic_string.
    /// @param str xtd::basic_string to trim start.
    /// @param trim_char A character to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the character in the trim_char parameter are removed from the start of the specified xtd::basic_string.
    basic_string trim_start() const noexcept;
    /// @brief Removes all leading occurrences of a character specified from the specified xtd::basic_string .
    /// @param str xtd::basic_string to trim start.
    /// @param trim_char A character to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the character in the trim_char parameter are removed from the start of the specified xtd::basic_string.
    basic_string trim_start(value_type trim_char) const noexcept;
    /// @brief Removes all leading occurrences of a set of characters specified in an array from the specified xtd::basic_string.
    /// @param str An xtd::basic_string to trim start.
    /// @param trim_chars An array of characters to remove.
    /// @return The xtd::basic_string that remains after all occurrences of the characters in the trim_chars parameter are removed from the start of the specified xtd::basic_string.
    basic_string trim_start(const std::vector<value_type>& trim_chars) const noexcept;
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Gets the class name of the object_t.
    /// @return The class name of the object_t.
    /// @remarks For example, the name of the basic_string type is basic_string.
    /// @deprecated Replaced by typeof_<object_t>().name() - Will be removed in version 0.4.0
    template<typename object_t>
    [[deprecated("Replaced by typeof_<object_t>().name() - Will be removed in version 0.4.0")]]
    static basic_string class_name() {return get_class_name(full_class_name<object_t>());}
    /// @brief Gets the class name of the specified object.
    /// @return The class name of the specified object.
    /// @remarks For example, the name of the basic_string type is basic_string.
    /// @deprecated Replaced by typeof_(object).name() - Will be removed in version 0.4.0
    template<typename object_t>
    [[deprecated("Replaced by typeof_(object).name() - Will be removed in version 0.4.0")]]
    static basic_string class_name(const object_t& object) {return get_class_name(full_class_name(object));}
    /// @brief Gets the class name of the specified object.
    /// @return The class name of the specified object.
    /// @remarks For example, the name of the basic_string type is basic_string.
    /// @deprecated Replaced by typeof_(info).name() - Will be removed in version 0.4.0
    [[deprecated("Replaced by typeof_(info).name() - Will be removed in version 0.4.0")]]
    static basic_string class_name(const std::type_info& info);
    
    /// @brief Compares two specified basic_string objects and returns an integer that indicates their relative position in the sort order.
    /// @param str_a The first basic_string to compare.
    /// @param str_b The second basic_string to compare.
    /// @return A 32-bit signed integer that indicates the lexical relationship between the two compares.
    /// | Value             | Condition                                                     |
    /// | ----------------- | ------------------------------------------------------------- |
    /// | Less than zero    | str_a precedes str_b in the sort order.                       |
    /// | Zero              | str_a occurs in the same position as str_b in the sort order. |
    /// | Greater than zero | str_a follows str_b in the sort order.                        |
    static int32 compare(const basic_string& str_a, const basic_string& str_b) noexcept;
    /// @brief Compares two specified basic_string objects, ignoring or honoring their case, and returns an integer that indicates their relative position in the sort order.
    /// @param str_a The first basic_string to compare.
    /// @param str_b The second basic_string to compare.
    /// @param ignore_case true to ignore case during the comparison; otherwise, false.
    /// @return A 32-bit signed integer that indicates the lexical relationship between the two compares.
    /// | Value             | Condition                                                     |
    /// | ----------------- | ------------------------------------------------------------- |
    /// | Less than zero    | str_a precedes str_b in the sort order.                       |
    /// | Zero              | str_a occurs in the same position as str_b in the sort order. |
    /// | Greater than zero | str_a follows str_b in the sort order.                        |
    static int32 compare(const basic_string& str_a, const basic_string& str_b, bool ignore_case) noexcept;
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
    static int32 compare(const basic_string& str_a, const basic_string& str_b, xtd::string_comparison comparison_type) noexcept;
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
    static int32 compare(const basic_string& str_a, xtd::size index_a, const basic_string& str_b, xtd::size index_b, xtd::size length) noexcept;
    /// @brief Compares substrings of two specified basic_string objects, ignoring or honoring their case, and returns an integer that indicates their relative position in the sort order.
    /// @param str_a The first basic_string to use in the comparison.
    /// @param index_a The position of the substring within str_a.
    /// @param str_b The second basic_string to use in the comparison.
    /// @param index_b The position of the substring within str_b.
    /// @param length The maximum number of characters in the substrings to compare
    /// @param ignore_case true to ignore case during the comparison; otherwise, false.
    /// @return A 32-bit signed integer that indicates the lexical relationship between the two compares.
    /// | Value             | Condition                                                     |
    /// | ----------------- | ------------------------------------------------------------- |
    /// | Less than zero    | str_a precedes str_b in the sort order.                       |
    /// | Zero              | str_a occurs in the same position as str_b in the sort order. |
    /// | Greater than zero | str_a follows str_b in the sort order.                        |
    static int32 compare(const basic_string& str_a, xtd::size index_a, const basic_string& str_b, xtd::size index_b, xtd::size length, bool ignore_case) noexcept;
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
    static int32 compare(const basic_string& str_a, xtd::size index_a, const basic_string& str_b, xtd::size index_b, xtd::size length, xtd::string_comparison comparison_type) noexcept;
    
    /// @brief Concatenates four specified instances of basic_string.
    /// @param str_a The first basic_string to concatenate.
    /// @param str_b The second basic_string to concatenate.
    /// @param str_c The third basic_string to concatenate.
    /// @param str_d The fourth basic_string to concatenate.
    /// @return The concatenation of str_a, str_b, str_c and str_d.
    static basic_string concat(const basic_string& str_a, const basic_string& str_b, const basic_string& str_c, const basic_string& str_d) noexcept;
    /// @brief Concatenates four specified instances of object.
    /// @param obj_a The first object to concatenate.
    /// @param obj_b The second object to concatenate.
    /// @param obj_c The third object to concatenate.
    /// @param obj_d The fourth object to concatenate.
    /// @return The concatenation of obj_a, obj_b, obj_c and obj_d.
    template<typename object_a_t, typename object_b_t, typename object_c_t, typename object_d_t>
    static basic_string concat(object_a_t obj_a, object_b_t obj_b, object_c_t obj_c, object_d_t obj_d) noexcept {
      return format("{}{}{}{}", obj_a, obj_b, obj_c, obj_d);
    }
    /// @brief Concatenates three specified instances of basic_string.
    /// @param str_a The first basic_string to concatenate.
    /// @param str_b The second basic_string to concatenate.
    /// @param str_c The third basic_string to concatenate.
    /// @return basic_string The concatenation of str_a, str_b and str_c.
    static basic_string concat(const basic_string& str_a, const basic_string& str_b, const basic_string& str_c) noexcept;
    /// @brief Concatenates three specified instances of object.
    /// @param obj_a The first object to concatenate.
    /// @param obj_b The second object to concatenate.
    /// @param obj_c The third object to concatenate.
    /// @return The concatenation of obj_a, obj_b and obj_c.
    template<typename object_a_t, typename object_b_t, typename object_c_t>
    static basic_string concat(object_a_t obj_a, object_b_t obj_b, object_c_t obj_c) noexcept {
      return format("{}{}{}", obj_a, obj_b, obj_c);
    }
    /// @brief Concatenates two specified instances of basic_string.
    /// @param str_a The first basic_string to concatenate.
    /// @param str_b The second basic_string to concatenate.
    /// @return basic_string The concatenation of str_a and str_b.
    static basic_string concat(const basic_string& str_a, const basic_string& str_b) noexcept;
    /// @brief Concatenates two specified instances of object.
    /// @param obj_a The first object to concatenate.
    /// @param obj_b The second object to concatenate.
    /// @return The concatenation of obj_a and obj_b.
    template<typename object_a_t, typename object_b_t>
    static basic_string concat(object_a_t obj_a, object_b_t obj_b) noexcept {
      return format("{}{}", obj_a, obj_b);
    }
    /// @brief Concatenates the elements of a specified basic_string array.
    /// @param values An array of basic_string instances.
    /// @return The concatenated elements of values.
    static basic_string concat(const std::vector<basic_string>& values) noexcept;
    /// @cond
    static basic_string concat(const std::vector<const value_type*>& values) noexcept;
    template<typename other_char_t>
    static basic_string concat(const std::vector<const other_char_t*>& values) noexcept;
    static basic_string concat(const std::initializer_list<basic_string>& values) noexcept;
    static basic_string concat(const std::initializer_list<const value_type*>& values) noexcept;
    template<typename other_char_t>
    static basic_string concat(const std::initializer_list<const other_char_t*>& values) noexcept;
    /// @endcond
    /// @brief Concatenates the basic_string representations of the elements in a specified object array.
    /// @param args An object array that contains the elements to concatenate.
    /// @return The concatenated basic_string representations of the values of the elements in args.
    template<typename object_t>
    static basic_string concat(const std::vector<object_t>& args) noexcept {
      basic_string result;
      for (const auto& arg : args)
        result += format("{}", arg);
      return result;
    }
    /// @cond
    template<typename object_t>
    static basic_string concat(const std::initializer_list<object_t>& args) noexcept {
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
    static basic_string concat(value_t value) noexcept {
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
    static basic_string demangle(const basic_string& name);

    /// @brief Determines whether two specified xtd::basic_string objects have the same value.
    /// @param a The first basic_string to compare.
    /// @param b The second basic_string to compare.
    /// @return `true` if the value of `a` is the same as the value of `b`; otherwise, `false`.
    /// @remarks This method performs an ordinal (case-sensitive) comparison.
    static bool equals(const basic_string& a, const basic_string& b) noexcept;
    /// @brief Determines whether two specified xtd::basic_string objects have the same value, ignoring or honoring their case.
    /// @param a The first basic_string to compare.
    /// @param b The second basic_string to compare.
    /// @param ignore_case true to ignore case when comparing this instance and value; otherwise, false
    /// @return `true` if the value of `a` is the same as the value of `b`; otherwise, `false`.
    /// @remarks This method performs an ordinal comparison.
    static bool equals(const basic_string& a, const basic_string& b, bool ignore_case) noexcept;

    /// @brief Writes the text representation of the specified arguments list, to basic_string using the specified format information.
    /// @param fmt A composite format basic_string.
    /// @param args arguments list to write using format.
    /// @return basic_string formatted.
    /// @ingroup format_parse
    /// @remarks for more information about format see @ref FormatPage "Format".
    template<typename ...args_t>
    static basic_string format(const basic_string& fmt, args_t&& ... args) {
      basic_string result;
      xtd::size index = 0;
      std::vector<__format_information<char>> formats;
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
            std::basic_string format_str {begin_format_iterator, end_format_iterator};
            if (format_str.size() == 0)
              fi.index = index++;
            else {
              xtd::size index_alignment_separator = basic_string(format_str).index_of(',');
              xtd::size index_format_separator = basic_string(format_str).index_of(u':');
              
              if (index_alignment_separator != npos && index_format_separator != npos && index_alignment_separator > index_format_separator)
                index_alignment_separator = npos;
                
              if (index_alignment_separator != npos)
                fi.alignment = format_str.substr(index_alignment_separator + 1, index_format_separator != npos ? index_format_separator - index_alignment_separator - 1 : npos);
                
              if (index_format_separator != npos)
                fi.format = format_str.substr(index_format_separator + 1);
                
              if (index_alignment_separator == 0 || index_format_separator == 0)
                fi.index = index++;
              else {
                basic_string index_str;
                if (index_alignment_separator != npos)
                  index_str = format_str.substr(0, index_alignment_separator);
                else if (index_format_separator != npos)
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
      
      __ustring_extract_format_arg(result, formats, std::forward<args_t>(args)...);
      return result.c_str();
    }
    
    /// @brief Gets the fully qualified class name of the objec_t, including the namespace of the objec_t.
    /// @return The fully qualified class name of the objec_t, including the namespace of the objec_t.
    /// @remarks For example, the fully qualified name of the basic_string type is xtd::basic_string.
    /// @deprecated Replaced by typeof_<object_t>().full_name() - Will be removed in version 0.4.0
    template<typename object_t>
    [[deprecated("Replaced by typeof_<object_t>().full_name() - Will be removed in version 0.4.0")]]
    static basic_string full_class_name() {return demangle(typeid(object_t).name());}
    /// @brief Gets the fully qualified class name of the specified object, including the namespace of the specified object.
    /// @return The fully qualified class name of the objec_t, including the namespace of the specified object.
    /// @remarks For example, the fully qualified name of the basic_string type is xtd::basic_string.
    /// @deprecated Replaced by typeof_(object).full_name() - Will be removed in version 0.4.0
    template<typename object_t>
    [[deprecated("Replaced by typeof_(object).full_name() - Will be removed in version 0.4.0")]]
    static basic_string full_class_name(const object_t& object) {return demangle(typeid(object).name());}
    /// @brief Gets the fully qualified class name of the specified object, including the namespace of the specified object.
    /// @return The fully qualified class name of the objec_t, including the namespace of the specified object.
    /// @remarks For example, the fully qualified name of the basic_string type is xtd::basic_string.
    /// @deprecated Replaced by typeof_(info).full_name() - Will be removed in version 0.4.0
    [[deprecated("Replaced by typeof_(info).full_name() - Will be removed in version 0.4.0")]]
    static basic_string full_class_name(const std::type_info& info);
    
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
    
    /// @brief Converts a basic_string into a value_t type.
    /// @param str Ax xtd::basic_string to convert to value_t
    /// @return The value_t object parsed.
    template<typename value_t>
    static value_t parse(const basic_string& str) {
      return xtd::parse<value_t>(str);
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
    /// | s         | basic_string of characters                                                                                                                                     | sample       |
    /// | p         | Pointer address                                                                                                                                          | b8000000     |
    /// | n         | Nothing printed. The corresponding argument must be a pointer to a signed int. The number of characters written so far is stored in the pointed location |              |
    /// | %         | A % followed by another % character will write a single % to the stream.                                                                                 | %            |
    /// @remarks The format specifier can also contain sub-specifiers: flags, width, .precision and modifiers (in that order), which are optional and follow these specifications:
    /// | flags   | description                                                                                                                                                                                                                                                                                                 |
    /// | ------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
    /// | -       | Left-justify within the given field width; Right justification is the default (see width sub-specifier).                                                                                                                                                                                                    |
    /// | +       | Forces to prefix the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.                                                                                                                                                    |
    /// | (space) | If no sign is going to be written, a blank space is inserted before the value.                                                                                                                                                                                                                              |
    /// | #       | Used with o, x or X specifiers the value is prefixed with 0, 0x or 0X respectively for values different than zero. Used with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written. |
    /// | 0       | Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).                                                                                                                                                                                                 |
    ///
    /// | width    | description                                                                                                                                                                                          |
    /// | -------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
    /// | (number) | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger. |
    /// | *        | The width is not specified in the format basic_string, but as an additional integer value argument preceding the argument that has to be formatted.                                                        |
    ///
    /// | .precision | description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
    /// | ---------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
    /// | .number    | For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6). For g and G specifiers: This is the maximum number of significant digits to be printed. For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. If the period is specified without an explicit value for precision, 0 is assumed. |
    /// | .*         | The precision is not specified in the format basic_string, but as an additional integer value argument preceding the argument that has to be formatted.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
    /// @remarks The length sub-specifier modifies the length of the data type. This is a chart showing the types used to interpret the corresponding arguments with and without length specifier (if a different type is used, the proper type promotion or conversion is performed, if allowed):
    /// | length | d i           | u o x X                | f F e E g G a A | c     | s        | p     | n               |
    /// | ------ | ------------- | ---------------------- | --------------- | ----- | -------- | ----- | --------------- |
    /// | (none) | int           | unsigned int           | double          | int   | char8*   | void* | int*            |
    /// | hh     | signed char8  | unsigned char8         |                 |       |          |       | unsigned char8* |
    /// | h      | short int     | unsigned short int     |                 |       |          |       | short int*      |
    /// | l      | long int      | unsigned long int      |                 | win_t | wchar*   |       | long int*       |
    /// | ll     | long long int | unsigned long long int |                 |       |          |       | long long int*  |
    /// | j      | intmax_t      | uintmax_t              |                 |       |          |       | intmax_t*       |
    /// | z      | xtd::size        | xtd::size                 |                 |       |          |       | xtd::size*         |
    /// | t      | ptrdiff_t     | ptrdiff_t              |                 |       |          |       | ptrdiff_t*      |
    /// | L      |               |                        | long double     |       |          |       |                 |
    /// @remarks Note regarding the c specifier: it takes an int (or wint_t) as argument, but performs the proper conversion to a char8 value (or a wchar) before formatting it for output.
    /// @remarks you can use std::basic_string or std::wstring with format param %%s.
    template<typename ... args_t>
    static basic_string sprintf(const basic_string& fmt, args_t&& ... args) noexcept {return __sprintf(fmt.c_str(), convert_param(std::forward<args_t>(args)) ...);}
    
    /// @brief Try to convert a basic_string into a value_t type.
    /// @param str An xtd::basic_string to convert to value_t
    /// @param value The value that will contain the parsed xtd::basic_string.
    /// @return true if xtd::basic_string:=:try_parse succed; otherwise, false.
    template<typename value_t>
    static bool try_parse(const basic_string& str, value_t& value) noexcept {
      try {
        value = parse<value_t>(str);
        return true;
      } catch (...) {
        return false;
      }
    }
    /// @}
    
    /// @cond
    friend std::ostream& operator <<(std::ostream& stream, const basic_string& str) {return stream << str.c_str();}
    friend std::istream& operator >>(std::istream& stream, basic_string& str) {
      decltype(str.chars_) s;
      stream >> s;
      str = s;
      return stream;
    }
    
    friend basic_string operator +(const basic_string& str_a, const basic_string& str_b) {
      basic_string result = str_a;
      result.append(str_b);
      return result;
    }
    
    friend basic_string operator +(const basic_string& str_a, const std::basic_string<value_type, traits_type, allocator_type>& str_b) {
      basic_string result = str_a;
      result.append(basic_string(str_b));
      return result;
    }
    
    friend basic_string operator +(const basic_string& str_a, const value_type* str_b) {
      basic_string result = str_a;
      result.append(basic_string(str_b));
      return result;
    }
    
    template<typename other_char_t>
    friend basic_string operator +(const basic_string& str_a, const std::basic_string<other_char_t>& str_b) {
      basic_string result = str_a;
      result.append(basic_string(str_b));
      return result;
    }
    
    template<typename other_char_t>
    friend basic_string operator +(const basic_string& str_a, const other_char_t* str_b) {
      basic_string result = str_a;
      result.append(basic_string(str_b));
      return result;
    }
    
    friend basic_string operator +(const basic_string& str_a, value_type character) {
      basic_string result = str_a;
      result.append(basic_string(1, character));
      return result;
    }
    
    template<typename other_char_t>
    friend basic_string operator +(const basic_string& str_a, other_char_t character) {
      basic_string result = str_a;
      result.append(basic_string(1, character));
      return result;
    }
    
    friend basic_string operator +(const basic_string& str_a, const std::initializer_list<value_type>& il) {
      basic_string result = str_a;
      result.append(basic_string(il));
      return result;
    }
    
    template<typename other_char_t>
    friend basic_string operator +(const basic_string& str_a, const std::initializer_list<other_char_t>& il) {
      basic_string result = str_a;
      result.append(basic_string(il));
      return result;
    }
    
    friend basic_string operator +(const std::basic_string<value_type, traits_type, allocator_type>& str_a, const basic_string& str_b) {
      basic_string result(str_a);
      result.append(str_b);
      return result;
    }
    
    friend basic_string operator +(const value_type* str_a, const basic_string& str_b) {
      basic_string result(str_a);
      result.append(str_b);
      return result;
    }
    
    template<typename other_char_t>
    friend basic_string operator +(const std::basic_string<other_char_t>& str_a, const basic_string& str_b) {
      basic_string result(str_a);
      result.append(str_b);
      return result;
    }
    
    template<typename other_char_t>
    friend basic_string operator +(const other_char_t* str_a, const basic_string& str_b) {
      basic_string result(str_a);
      result.append(str_b);
      return result;
    }
    
    friend basic_string operator +(value_type character, const basic_string& str_b) {
      basic_string result(1, character);
      result.append(str_b);
      return result;
    }
    
    template<typename other_char_t>
    friend basic_string operator +(other_char_t character, const basic_string& str_b) {
      basic_string result(1, character);
      result.append(str_b);
      return result;
    }
    
    friend basic_string operator +(const std::initializer_list<value_type>& il, const basic_string& str_b) {
      basic_string result(il);
      result.append(str_b);
      return result;
    }
    
    template<typename other_char_t>
    friend basic_string operator +(const std::initializer_list<other_char_t>& il, const basic_string& str_b) {
      basic_string result(il);
      result.append(str_b);
      return result;
    }
    /// @endcond
    
  private:
    template<typename arg_t>
    static auto convert_param(arg_t&& arg) noexcept {
      if constexpr(std::is_same<std::remove_cv_t<std::remove_reference_t<arg_t>>, std::string>::value) return std::forward<arg_t>(arg).c_str();
#if defined(__xtd__cpp_lib_char8_t)
      else if constexpr(std::is_same<std::remove_cv_t<std::remove_reference_t<arg_t>>, std::u8string>::value) return std::forward<arg_t>(arg).c_str();
#endif
      else if constexpr(std::is_same<std::remove_cv_t<std::remove_reference_t<arg_t>>, std::u16string>::value) return std::forward<arg_t>(arg).c_str();
      else if constexpr(std::is_same<std::remove_cv_t<std::remove_reference_t<arg_t>>, std::u32string>::value) return std::forward<arg_t>(arg).c_str();
      else if constexpr(std::is_same<std::remove_cv_t<std::remove_reference_t<arg_t>>, std::wstring>::value) return std::forward<arg_t>(arg).c_str();
      else if constexpr(std::is_same<std::remove_cv_t<std::remove_reference_t<arg_t>>, xtd::string>::value) return std::forward<arg_t>(arg).c_str();
      else return std::forward<arg_t>(arg);
    }
    
    static basic_string get_class_name(const basic_string& full_name);
    
    static const std::vector<value_type> default_split_separators;
    static const std::vector<value_type> default_trim_chars;
    
    base_type chars_;
  };
}

/// @cond
template<typename char_t, typename arg_t>
inline void __ustring_extract_format_arg(std::basic_string<char_t>& fmt, xtd::size& index, std::vector<__format_information<char_t>>& formats, arg_t&& arg) {
  xtd::size offset = 0;
  for (auto& format : formats) {
    format.location += offset;
    if (format.index == index) {
      xtd::basic_string arg_str = xtd::to_string(arg, format.format);
      
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

template<typename char_t, typename ...args_t>
inline void __ustring_extract_format_arg(xtd::basic_string<char_t>& fmt, std::vector<__format_information<char_t>>& formats, args_t&& ... args) {
  xtd::size index = 0;
  (__ustring_extract_format_arg(fmt, index, formats, args), ...);
  unused_(index); // workaround to mute gcc warning: unused-but-set-variable
}

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
/// @endcond
