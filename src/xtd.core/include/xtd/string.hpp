/// @file
/// @brief Contains xtd::string alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "internal/__string_definitions.hpp"
#undef __XTD_CORE_INTERNAL__
#include "basic_string.hpp"

/// @cond
/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents text as a sequence of UTF-8 code units.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system strings
  /// @remarks A string is a sequential collection of characters that's used to represent text. A xtd::string object is a sequential collection of char that represent a string; a char corresponds to a UTF-8 code unit. The value of the xtd::string object is the content of the sequential collection of char, and unlike [std::basic_string<char>](https://en.cppreference.com/w/cpp/string/basic_string) that value is immutable (that is, it is read-only).
  /// @remarks If you want the same mutable string class, you can use xtd::text::string_builder class.
  /// @remarks xtd::string implements xtd::basic_string and therefore offers the full (immutable) API of [std::string](https://en.cppreference.com/w/cpp/string/basic_string).
  using string = xtd::basic_string<char>;
    
  /// @brief Converts a signed integer to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  string to_string(int val);
  /// @brief Converts an unsigned integer to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  string to_string(unsigned val);
  /// @brief Converts a signed integer to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  string to_string(long val);
  /// @brief Converts an unsigned integer to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  string to_string(unsigned long val);
  /// @brief Converts a signed integer to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  string to_string(long long val);
  /// @brief Converts an unsigned integer to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  string to_string(unsigned long long val);
  /// @brief Converts a floating point to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  string to_string(float val);
  /// @brief Converts a floating point integer to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  string to_string(double val);
  /// @brief Converts a floating point to xtd::string.
  /// @param val A numeric value to convert.
  /// @return A string holding the converted value.
  string to_string(long double val);
  /// @brief Converts a type_t to xtd::string.
  /// @param val A type_t value to convert.
  /// @return A string holding the converted value.
  template<class type_t>
  string to_string(type_t val) {
    return string::format("{}", val);
  }
  
  /// @brief Converts a type_t to xtd::string.
  /// @param val A type_t value to convert.
  /// @return A string holding the converted value.
  /// @deprecated Replaced by xtd::to_string - Will be removed in version 0.4.0.
  template<class type_t>
  [[deprecated("Replaced by xtd::to_string - Will be removed in version 0.4.0.")]] string to_ustring(type_t val) {
    return to_string(val);
  }
}

/*
/// @cond
/// Needed for std::format
#if defined(__xtd__cpp_lib_format)
template <>
struct std::formatter<xtd::string> : std::formatter<std::string> {
  template<class object_t, class format_context_t>
  auto format(const object_t& obj, format_context_t& ctx) const {return std::format_to(ctx.out(), "{}", std::string {obj.to_string()});}
};
#endif
/// @endcond
*/

/// @todo Remove `string` class.
template<>
inline std::string xtd::to_string(const xtd::string& value, const std::string& fmt, const std::locale& loc) {return value.to_string();}

/// @cond
template<class key_t, class value_t>
xtd::string xtd::collections::generic::key_value_pair<key_t, value_t>::to_string() const noexcept {return xtd::string::format("({0}, {1})", first, second);}

template<class type_t>
xtd::string __opaque_xtd_linq_enumerable_collection__<type_t>::to_string() const {return xtd::string::format("[{}]", xtd::string::join(", ", *this));}

template<class type_t, class param_t>
xtd::string __opaque_xtd_linq_lazy_enumerable__<type_t, param_t>::to_string() const {return xtd::string::format("[{}]", xtd::string::join(", ", *this));}

template<class type_t>
xtd::string xtd::reference_wrapper_object<type_t>::to_string() const noexcept {return xtd::string::format("{} [value={}]", xtd::object::to_string(), !ref_.has_value() ? "(null)" : string::format("{}", get()));}

template<class type_t>
xtd::string xtd::shared_ptr_object<type_t>::to_string() const noexcept {return xtd::string::format("{} [pointer={}]", xtd::object::to_string(), ptr_ == xtd::null ? "null"  : string::format("0x{:X16}, use_count={}", get(), use_count()));}

template<class type_t, class deleter_t>
xtd::string xtd::unique_ptr_object<type_t, deleter_t>::to_string() const noexcept {return xtd::string::format("{} [pointer={}]", xtd::object::to_string(), ptr_ == xtd::null ? "null"  : string::format("0x{:X16}", get()));}
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name String suffixes
    
    /// @{
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = "This is a "_s + "simple test"_s;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_s(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = u8"This is a "_s + u8"simple test"_s;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_s(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = U"This is a "_s + U"simple test"_s;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_s(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = u"This is a "_s + u"simple test"_s;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_s(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = L"This is a "_s + L"simple test"_s;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_s(const wchar* s, xtd::size n);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42.0_sb;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sb(long double s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sb;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sb(unsigned long long s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with two digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42.0_sb2;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sb2( long double s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with two digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sb2;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sb2(unsigned long long s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with four digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42.0_sb4;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sb4(long double s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with four digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sb4;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sb4(unsigned long long s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with eight digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42.0_sb8;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sb8(long double s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with eight digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sb8;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sb8(unsigned long long s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with sixteen digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42.0_sb16;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sb16(long double s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with sixteen digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sb16;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sb16(unsigned long long s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with thirty two digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42.0_sb32;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sb32(long double s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with thirty two digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sb32;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sb32(unsigned long long s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with sixty four digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42.0_sb64;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sb64(long double s);
    
    /// @brief Used to convert the specified value to xtd::string with a binary format with sixty four digits.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sb64;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sb64(unsigned long long s);
    
    /// @brief Used to convert the specified value to xtd::string with a decimal format.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 4.9_sd;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sd(long double s);
    
    /// @brief Used to convert the specified value to xtd::string with a decimal format.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sd;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sd(unsigned long long s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sx;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sx(long double s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sx;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sx(unsigned long long s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sx2;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sx2(unsigned long long s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sx4;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sx4(unsigned long long s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sx8;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sx8(unsigned long long s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sx16;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sx16(unsigned long long s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42.0_sX;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sX(long double s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sX;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sX(unsigned long long s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sX2;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sX2(unsigned long long s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sX4;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sX4(unsigned long long s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sX8;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sX8(unsigned long long s);
    
    /// @brief Used to convert specified value into xtd::string.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::string s = 42_sX16;
    /// xtd::console::out << s << xtd::environment::new_line;
    /// ```
    xtd::string operator""_sX16(unsigned long long s);
    /// @}
  }
}
