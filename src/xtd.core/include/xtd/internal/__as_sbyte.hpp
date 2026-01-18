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
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(xtd::any value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(bool value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(xtd::byte value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(char value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(xtd::char8 value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(xtd::char16 value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(xtd::char32 value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(xtd::wchar value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(xtd::decimal value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(double value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(float value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(xtd::int16 value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(xtd::int32 value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(xtd::int64 value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(xtd::slong value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(xtd::sbyte value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(xtd::uint16 value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(xtd::uint32 value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(xtd::uint64 value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(xtd::ulong value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(const xtd::string& value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(xtd::string& value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new sbyte object converted from value.
  /// @exception xtd::argument_exception value does not represent a sbyte.
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
  /// sbyte result = as<sbyte>(value, 16);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(const xtd::string& value, xtd::byte from_base) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(const std::string& value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(std::string& value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(const std::u8string& value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(std::u8string& value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(const std::u16string& value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(std::u16string& value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(const std::u32string& value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(std::u32string& value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(const std::wstring& value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(std::wstring& value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(const char* value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(char* value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(const xtd::char8* value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(xtd::char8* value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(const xtd::char16* value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(xtd::char16* value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(const xtd::char32* value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(xtd::char32* value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(const xtd::wchar* value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// ```
  template<>
  inline auto as<xtd::sbyte>(xtd::wchar* value) -> xtd::sbyte {
    return xtd::convert::to_sbyte(value);
  }
}
