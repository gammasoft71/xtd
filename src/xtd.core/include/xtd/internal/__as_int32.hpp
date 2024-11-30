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
  /// @return A new int32 object converted from value.
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
  /// std::any value = true;
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(std::any value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
  /// @par Header
  /// ```cpp
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(bool value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
  /// @par Header
  /// ```cpp
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(xtd::byte value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(char value) {
    return xtd::convert::to_int32(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(char8 value) {
    return xtd::convert::to_int32(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(char16 value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(char32 value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(wchar value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
  /// @par Header
  /// ```cpp
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(decimal value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
  /// @par Header
  /// ```cpp
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(double value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
  /// @par Header
  /// ```cpp
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(float value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
  /// @par Header
  /// ```cpp
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(int16 value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
  /// @par Header
  /// ```cpp
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(int32 value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
  /// @par Header
  /// ```cpp
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(int64 value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
  /// @par Header
  /// ```cpp
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(slong value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
  /// @par Header
  /// ```cpp
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(sbyte value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
  /// @par Header
  /// ```cpp
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(uint16 value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
  /// @par Header
  /// ```cpp
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(uint32 value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
  /// @par Header
  /// ```cpp
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(uint64 value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
  /// @par Header
  /// ```cpp
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(xtd::ulong value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(const xtd::string& value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(xtd::string& value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new int32 object converted from value.
  /// @exception xtd::argument_exception value does not represent a int32.
  /// @par Header
  /// ```cpp
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
  /// int32 result = as<int32>(value, 16);
  /// ```
  template<>
  inline int32 as<int32>(const xtd::string& value, xtd::byte from_base) {
    return xtd::convert::to_int32(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(const std::string& value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(std::string& value) {
    return xtd::convert::to_int32(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(const std::u8string& value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(std::u8string& value) {
    return xtd::convert::to_int32(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(const std::u16string& value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(std::u16string& value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(const std::u32string& value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(std::u32string& value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(const std::wstring& value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(std::wstring& value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(const char* value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(char* value) {
    return xtd::convert::to_int32(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(const char8* value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(char8* value) {
    return xtd::convert::to_int32(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(const char16* value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(char16* value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(const char32* value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(char32* value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(const wchar* value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32 object converted from value.
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
  /// int32 result = as<int32>(value);
  /// ```
  template<>
  inline int32 as<int32>(wchar* value) {
    return xtd::convert::to_int32(value);
  }
}
