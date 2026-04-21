/// @file
/// @brief Contains xtd::as method.
#pragma once

/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#define __XTD_STD_INTERNAL__
#include "__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::any value = true;
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::any value) -> xtd::string {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// bool value = true;
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(bool value) -> xtd::string {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::byte value = 42;
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::byte value) -> xtd::string {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new string object converted from value.
  /// @exception xtd::argument_exception vfrom_base is not 2, 8, 10, or 16.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::byte value = 42;
  /// string result = as<string>(value, 16);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::byte value, xtd::byte from_base) -> xtd::string {
    return xtd::convert::to_string(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// char value = 'a';
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(char value) -> xtd::string {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// char8 value = u8'a';
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::char8 value) -> xtd::string {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// char16 value = u'a';
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::char16 value) -> xtd::string {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// char32 value = u'a';
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::char32 value) -> xtd::string {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// wchar value = u'a';
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::wchar value) -> xtd::string {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// decimal value = 42.50l;
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::decimal value) -> xtd::string {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// double value = 42.50;
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(double value) -> xtd::string {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// float value = 42.50f;
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(float value) -> xtd::string {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// int16 value = 42;
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::int16 value) -> xtd::string {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new string object converted from value.
  /// @exception xtd::argument_exception vfrom_base is not 2, 8, 10, or 16.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// int16 value = 42;
  /// string result = as<string>(value, 16);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::int16 value, xtd::byte from_base) -> xtd::string {
    return xtd::convert::to_string(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// int32 value = 42;
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::int32 value) -> xtd::string {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new string object converted from value.
  /// @exception xtd::argument_exception vfrom_base is not 2, 8, 10, or 16.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// int32 value = 42;
  /// string result = as<string>(value, 16);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::int32 value, xtd::byte from_base) -> xtd::string {
    return xtd::convert::to_string(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// int64 value = 42l;
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::int64 value) -> xtd::string {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new string object converted from value.
  /// @exception xtd::argument_exception vfrom_base is not 2, 8, 10, or 16.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// int64 value = 42;
  /// string result = as<string>(value, 16);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::int64 value, xtd::byte from_base) -> xtd::string {
    return xtd::convert::to_string(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// slong value = 42ll;
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::slong value) -> xtd::string {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new string object converted from value.
  /// @exception xtd::argument_exception vfrom_base is not 2, 8, 10, or 16.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// slong value = 42;
  /// string result = as<string>(value, 16);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::slong value, xtd::byte from_base) -> xtd::string {
    return xtd::convert::to_string(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// sbyte value = 42ll;
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::sbyte value) -> xtd::string {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new string object converted from value.
  /// @exception xtd::argument_exception vfrom_base is not 2, 8, 10, or 16.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// sbyte value = 42;
  /// string result = as<string>(value, 16);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::sbyte value, xtd::byte from_base) -> xtd::string {
    return xtd::convert::to_string(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// uint16 value = 42u;
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::uint16 value) -> xtd::string {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new string object converted from value.
  /// @exception xtd::argument_exception vfrom_base is not 2, 8, 10, or 16.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// uint16 value = 42;
  /// string result = as<string>(value, 16);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::uint16 value, xtd::byte from_base) -> xtd::string {
    return xtd::convert::to_string(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// uint32 value = 42u;
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::uint32 value) -> xtd::string {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new string object converted from value.
  /// @exception xtd::argument_exception vfrom_base is not 2, 8, 10, or 16.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// uint32 value = 42;
  /// string result = as<string>(value, 16);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::uint32 value, xtd::byte from_base) -> xtd::string {
    return xtd::convert::to_string(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// uint64 value = 42ul;
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::uint64 value) -> xtd::string {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new string object converted from value.
  /// @exception xtd::argument_exception vfrom_base is not 2, 8, 10, or 16.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// uint64 value = 42;
  /// string result = as<string>(value, 16);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::uint64 value, xtd::byte from_base) -> xtd::string {
    return xtd::convert::to_string(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::ulong value = 42ull;
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::ulong value) -> xtd::string {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new string object converted from value.
  /// @exception xtd::argument_exception vfrom_base is not 2, 8, 10, or 16.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::ulong value = 42;
  /// string result = as<string>(value, 16);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::ulong value, xtd::byte from_base) -> xtd::string {
    return xtd::convert::to_string(value, from_base);
  }
  /// @brief Casts a type into another type.
  /// @param value xtd::string to convert.
  /// @return A new xtd::u16string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::string value = "Hello";
  /// xtd::u16string result = as<xtd::u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u16string>(const xtd::string& value) -> xtd::u16string {
    return value;
  }
  /// @brief Casts a type into another type.
  /// @param value xtd::string to convert.
  /// @return A new xtd::u16string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::string value = "Hello";
  /// xtd::u16string result = as<xtd::u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u16string>(xtd::string& value) -> xtd::u16string {
    return value;
  }
  
  /// @brief Casts a type into another type.
  /// @param value xtd::string to convert.
  /// @return A new xtd::u32string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::string value = "Hello";
  /// xtd::u32string result = as<xtd::u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u32string>(const xtd::string& value) -> xtd::u32string {
    return value;
  }
  /// @brief Casts a type into another type.
  /// @param value xtd::string to convert.
  /// @return A new xtd::u32string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::string value = "Hello";
  /// xtd::u32string result = as<xtd::u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u32string>(xtd::string& value) -> xtd::u32string {
    return value;
  }
  
  /// @brief Casts a type into another type.
  /// @param value xtd::string to convert.
  /// @return A new xtd::u8string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::string value = "Hello";
  /// xtd::u8string result = as<xtd::u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u8string>(const xtd::string& value) -> xtd::u8string {
    return value;
  }
  /// @brief Casts a type into another type.
  /// @param value xtd::string to convert.
  /// @return A new xtd::u16string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::string value = "Hello";
  /// xtd::u8string result = as<xtd::u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u8string>(xtd::string& value) -> xtd::u8string {
    return value;
  }
  
  /// @brief Casts a type into another type.
  /// @param value xtd::string to convert.
  /// @return A new xtd::wstring object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::string value = "Hello";
  /// xtd::wstring result = as<xtd::wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::wstring>(const xtd::string& value) -> xtd::wstring {
    return value;
  }
  /// @brief Casts a type into another type.
  /// @param value xtd::string to convert.
  /// @return A new xtd::u16string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::string value = "Hello";
  /// xtd::wstring result = as<xtd::wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::wstring>(xtd::string& value) -> xtd::wstring {
    return value;
  }
  
  /// @cond
  template<>
  [[nodiscard]] inline auto as<xtd::u16string>(const char* value) -> xtd::u16string {
    return xtd::string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u16string>(char* value) -> xtd::u16string {
    return xtd::string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u32string>(const char* value) -> xtd::u32string {
    return xtd::string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u32string>(char* value) -> xtd::u32string {
    return xtd::string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u8string>(const char* value) -> xtd::u8string {
    return xtd::string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u8string>(char* value) -> xtd::u8string {
    return xtd::string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::wstring>(const char* value) -> xtd::wstring {
    return xtd::string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::wstring>(char* value) -> xtd::wstring {
    return xtd::string {value};
  }
  /// @endcond
  
  
  /// @cond
  template<typename type_t>
  [[nodiscard]] inline auto as(const xtd::u16string& value) -> type_t {
    return value;
  }
  template<typename type_t>
  [[nodiscard]] inline auto as(xtd::u16string& value) -> type_t {
    return value;
  }
  /// @endcond
  
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::string result = as<xtd::string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(const xtd::u16string& value) -> xtd::string {
    return value;
  }
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::string result = as<xtd::string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::u16string& value) -> xtd::string {
    return value;
  }
  
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u16string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u16string result = as<xtd::u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u16string>(const xtd::u16string& value) -> xtd::u16string {
    return value;
  }
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u16string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u16string result = as<xtd::u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u16string>(xtd::u16string& value) -> xtd::u16string {
    return value;
  }
  
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u32string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u32string result = as<xtd::u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u32string>(const xtd::u16string& value) -> xtd::u32string {
    return value;
  }
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u32string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u32string result = as<xtd::u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u32string>(xtd::u16string& value) -> xtd::u32string {
    return value;
  }
  
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u8string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u8string result = as<xtd::u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u8string>(const xtd::u16string& value) -> xtd::u8string {
    return value;
  }
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u8string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u8string result = as<xtd::u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u8string>(xtd::u16string& value) -> xtd::u8string {
    return value;
  }
  
  /// @cond
  template<>
  [[nodiscard]] inline auto as<xtd::u16string>(const xtd::char16* value) -> xtd::u16string {
    return xtd::u16string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u16string>(xtd::char16* value) -> xtd::u16string {
    return xtd::u16string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u32string>(const xtd::char16* value) -> xtd::u32string {
    return xtd::u16string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u32string>(xtd::char16* value) -> xtd::u32string {
    return xtd::u16string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u8string>(const xtd::char16* value) -> xtd::u8string {
    return xtd::u16string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u8string>(xtd::char16* value) -> xtd::u8string {
    return xtd::u16string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::wstring>(const xtd::char16* value) -> xtd::wstring {
    return xtd::u16string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::wstring>(xtd::char16* value) -> xtd::wstring {
    return xtd::u16string {value};
  }
  /// @endcond
  
  /// @cond
  template<typename type_t>
  [[nodiscard]] inline auto as(const xtd::u32string& value) -> type_t {
    return value;
  }
  template<typename type_t>
  [[nodiscard]] inline auto as(xtd::u32string& value) -> type_t {
    return value;
  }
  /// @endcond
  
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::string result = as<xtd::string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(const xtd::u32string& value) -> xtd::string {
    return value;
  }
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::string result = as<xtd::string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::u32string& value) -> xtd::string {
    return value;
  }
  
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u16string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u16string result = as<xtd::u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u16string>(const xtd::u32string& value) -> xtd::u16string {
    return value;
  }
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u16string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u16string result = as<xtd::u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u16string>(xtd::u32string& value) -> xtd::u16string {
    return value;
  }
  
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u32string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u32string result = as<xtd::u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u32string>(const xtd::u32string& value) -> xtd::u32string {
    return value;
  }
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u32string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u32string result = as<xtd::u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u32string>(xtd::u32string& value) -> xtd::u32string {
    return value;
  }
  
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u8string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u8string result = as<xtd::u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u8string>(const xtd::u32string& value) -> xtd::u8string {
    return value;
  }
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u8string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u8string result = as<xtd::u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u8string>(xtd::u32string& value) -> xtd::u8string {
    return value;
  }
  
  /// @cond
  template<>
  [[nodiscard]] inline auto as<xtd::u16string>(const xtd::char32* value) -> xtd::u16string {
    return xtd::u32string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u16string>(xtd::char32* value) -> xtd::u16string {
    return xtd::u32string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u32string>(const xtd::char32* value) -> xtd::u32string {
    return xtd::u32string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u32string>(xtd::char32* value) -> xtd::u32string {
    return xtd::u32string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u8string>(const xtd::char32* value) -> xtd::u8string {
    return xtd::u32string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u8string>(xtd::char32* value) -> xtd::u8string {
    return xtd::u32string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::wstring>(const xtd::char32* value) -> xtd::wstring {
    return xtd::u32string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::wstring>(xtd::char32* value) -> xtd::wstring {
    return xtd::u32string {value};
  }
  /// @endcond
  
  /// @cond
  template<typename type_t>
  [[nodiscard]] inline auto as(const xtd::u8string& value) -> type_t {
    return value;
  }
  template<typename type_t>
  [[nodiscard]] inline auto as(xtd::u8string& value) -> type_t {
    return value;
  }
  /// @endcond
  
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::string result = as<xtd::string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(const xtd::u8string& value) -> xtd::string {
    return value;
  }
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::string result = as<xtd::string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::u8string& value) -> xtd::string {
    return value;
  }
  
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u16string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u16string result = as<xtd::u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u16string>(const xtd::u8string& value) -> xtd::u16string {
    return value;
  }
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u16string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u16string result = as<xtd::u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u16string>(xtd::u8string& value) -> xtd::u16string {
    return value;
  }
  
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u32string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u32string result = as<xtd::u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u32string>(const xtd::u8string& value) -> xtd::u32string {
    return value;
  }
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u32string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u32string result = as<xtd::u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u32string>(xtd::u8string& value) -> xtd::u32string {
    return value;
  }
  
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u8string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u8string result = as<xtd::u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u8string>(const xtd::u8string& value) -> xtd::u8string {
    return value;
  }
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u8string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u8string result = as<xtd::u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u8string>(xtd::u8string& value) -> xtd::u8string {
    return value;
  }
  
  /// @cond
  template<>
  [[nodiscard]] inline auto as<xtd::u16string>(const xtd::char8* value) -> xtd::u16string {
    return xtd::u8string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u16string>(xtd::char8* value) -> xtd::u16string {
    return xtd::u8string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u32string>(const xtd::char8* value) -> xtd::u32string {
    return xtd::u8string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u32string>(xtd::char8* value) -> xtd::u32string {
    return xtd::u8string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u8string>(const xtd::char8* value) -> xtd::u8string {
    return xtd::u8string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u8string>(xtd::char8* value) -> xtd::u8string {
    return xtd::u8string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::wstring>(const xtd::char8* value) -> xtd::wstring {
    return xtd::u8string {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::wstring>(xtd::char8* value) -> xtd::wstring {
    return xtd::u8string {value};
  }
  /// @endcond
  
  /// @cond
  template<typename type_t>
  [[nodiscard]] inline auto as(const xtd::wstring& value) -> type_t {
    return value;
  }
  template<typename type_t>
  [[nodiscard]] inline auto as(xtd::wstring& value) -> type_t {
    return value;
  }
  /// @endcond
  
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::string result = as<xtd::string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(const xtd::wstring& value) -> xtd::string {
    return value;
  }
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::string result = as<xtd::string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::wstring& value) -> xtd::string {
    return value;
  }
  
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u16string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u16string result = as<xtd::u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u16string>(const xtd::wstring& value) -> xtd::u16string {
    return value;
  }
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u16string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u16string result = as<xtd::u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u16string>(xtd::wstring& value) -> xtd::u16string {
    return value;
  }
  
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u32string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u32string result = as<xtd::u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u32string>(const xtd::wstring& value) -> xtd::u32string {
    return value;
  }
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u32string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u32string result = as<xtd::u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u32string>(xtd::wstring& value) -> xtd::u32string {
    return value;
  }
  
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u8string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u8string result = as<xtd::u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u8string>(const xtd::wstring& value) -> xtd::u8string {
    return value;
  }
  /// @brief Casts a type into another type.
  /// @param value xtd::u16string to convert.
  /// @return A new xtd::u8string object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::u16string value = u"Hello";
  /// xtd::u8string result = as<xtd::u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::u8string>(xtd::wstring& value) -> xtd::u8string {
    return value;
  }
  
  /// @cond
  template<>
  [[nodiscard]] inline auto as<xtd::u16string>(const xtd::wchar* value) -> xtd::u16string {
    return xtd::wstring {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u16string>(xtd::wchar* value) -> xtd::u16string {
    return xtd::wstring {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u32string>(const xtd::wchar* value) -> xtd::u32string {
    return xtd::wstring {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u32string>(xtd::wchar* value) -> xtd::u32string {
    return xtd::wstring {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u8string>(const xtd::wchar* value) -> xtd::u8string {
    return xtd::wstring {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::u8string>(xtd::wchar* value) -> xtd::u8string {
    return xtd::wstring {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::wstring>(const xtd::wchar* value) -> xtd::wstring {
    return xtd::wstring {value};
  }
  template<>
  [[nodiscard]] inline auto as<xtd::wstring>(xtd::wchar* value) -> xtd::wstring {
    return xtd::wstring {value};
  }
  /// @endcond
}
