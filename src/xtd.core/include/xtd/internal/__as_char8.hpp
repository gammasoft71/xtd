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
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(xtd::any value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(bool value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(xtd::byte value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(char value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(char8 value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(char16 value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(char32 value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(wchar value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(decimal value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(double value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(float value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(int16 value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(int32 value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(int64 value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(slong value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(sbyte value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(uint16 value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(uint32 value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(uint64 value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(xtd::ulong value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(const xtd::string& value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(xtd::string& value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(const std::string& value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(std::string& value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(const std::u8string& value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(std::u8string& value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(const std::u16string& value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(std::u16string& value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(const std::u32string& value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(std::u32string& value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(const std::wstring& value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(std::wstring& value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(const char* value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(char* value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(const char8* value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(char8* value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(const char16* value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(char16* value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(const char32* value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(char32* value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(const wchar* value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8 object converted from value.
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
  /// char8 result = as<char8>(value);
  /// ```
  template<>
  inline char8 as<char8>(wchar* value) {
    return xtd::convert::to_char8(value);
  }
}
