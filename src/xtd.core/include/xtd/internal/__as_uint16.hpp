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
  /// @return A new uint16 object converted from value.
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
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(xtd::any value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
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
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(bool value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
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
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(xtd::byte value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
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
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(char value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
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
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(xtd::char8 value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
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
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(xtd::char16 value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
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
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(xtd::char32 value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
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
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(xtd::wchar value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
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
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(xtd::decimal value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
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
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(double value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
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
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(float value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
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
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(xtd::int16 value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
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
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(xtd::int32 value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
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
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(xtd::int64 value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
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
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(xtd::slong value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
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
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(xtd::sbyte value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
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
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(xtd::uint16 value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
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
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(xtd::uint32 value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
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
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(xtd::uint64 value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
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
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(xtd::ulong value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// string value = "42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(const xtd::string& value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// string value = "42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(xtd::string& value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a uint16.
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
  /// string value = "0x2A";
  /// uint16 result = as<uint16>(value, 16);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(const xtd::string& value, xtd::byte from_base) -> xtd::uint16 {
    return xtd::convert::to_uint16(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// string value = "42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(const std::string& value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// string value = "42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(std::string& value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// u8string value = u8"42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(const std::u8string& value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// u8string value = u8"42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(std::u8string& value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// u16string value = u"42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(const std::u16string& value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// u16string value = u"42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(std::u16string& value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// u32string value = U"42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(const std::u32string& value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// u32string value = U"42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(std::u32string& value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// wstring value = L"42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(const std::wstring& value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// wstring value = L"42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(std::wstring& value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// const char* value = "42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(const char* value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// char* value = "42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(char* value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// const char8* value = u8"42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(const xtd::char8* value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// char8* value = u8"42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(xtd::char8* value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// const char16* value = u"42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(const xtd::char16* value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// char16* value = u"42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(xtd::char16* value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// const char32* value = U"42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(const xtd::char32* value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// char32* value = U"42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(xtd::char32* value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// const wchar* value = L"42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(const xtd::wchar* value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16 object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
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
  /// wchar* value = L"42";
  /// uint16 result = as<uint16>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::uint16>(xtd::wchar* value) -> xtd::uint16 {
    return xtd::convert::to_uint16(value);
  }
}
