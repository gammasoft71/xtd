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
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(xtd::any value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(bool value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(xtd::byte value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(char value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(xtd::char8 value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(xtd::char16 value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(xtd::char32 value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(xtd::wchar value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(xtd::decimal value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(double value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(float value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(xtd::int16 value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(xtd::int32 value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(xtd::int64 value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(xtd::slong value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(xtd::sbyte value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(xtd::uint16 value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(xtd::uint32 value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(xtd::uint64 value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(xtd::ulong value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a byte.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(const xtd::string& value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a byte.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(xtd::string& value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a byte.
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
  /// xtd::byte result = as<xtd::byte>(value, 16);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(const xtd::string& value, xtd::byte from_base) -> xtd::byte {
    return xtd::convert::to_byte(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(const std::string& value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(std::string& value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(const std::u8string& value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(std::u8string& value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(const std::u16string& value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(std::u16string& value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(const std::u32string& value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(std::u32string& value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(const std::wstring& value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(std::wstring& value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(const char* value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(char* value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(const xtd::char8* value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(xtd::char8* value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(const xtd::char16* value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(xtd::char16* value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(const xtd::char32* value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(xtd::char32* value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(const xtd::wchar* value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
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
  /// xtd::byte result = as<xtd::byte>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::byte>(xtd::wchar* value) -> xtd::byte {
    return xtd::convert::to_byte(value);
  }
}
