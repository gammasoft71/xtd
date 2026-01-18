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
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(xtd::any value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(bool value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(xtd::byte value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(char value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(xtd::char8 value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(xtd::char16 value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(xtd::char32 value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(xtd::wchar value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(xtd::decimal value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(double value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(float value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(xtd::int16 value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(xtd::int32 value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(xtd::int64 value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(xtd::slong value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(xtd::sbyte value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(xtd::uint16 value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(xtd::uint32 value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(xtd::uint64 value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(xtd::ulong value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(const xtd::string& value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(xtd::string& value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new int64 object converted from value.
  /// @exception xtd::argument_exception value does not represent a int64.
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
  /// int64 result = as<int64>(value, 16);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(const xtd::string& value, xtd::byte from_base) -> xtd::int64 {
    return xtd::convert::to_int64(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(const std::string& value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(std::string& value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(const std::u8string& value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(std::u8string& value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(const std::u16string& value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(std::u16string& value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(const std::u32string& value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(std::u32string& value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(const std::wstring& value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(std::wstring& value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(const char* value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(char* value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(const xtd::char8* value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(xtd::char8* value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(const xtd::char16* value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(xtd::char16* value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(const xtd::char32* value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(xtd::char32* value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(const xtd::wchar* value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64 object converted from value.
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
  /// int64 result = as<int64>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::int64>(xtd::wchar* value) -> xtd::int64 {
    return xtd::convert::to_int64(value);
  }
}
