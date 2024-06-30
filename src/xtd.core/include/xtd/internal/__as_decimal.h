/// @file
/// @brief Contains xtd::as method.
#pragma once

/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#define __XTD_STD_INTERNAL__
#include "__xtd_std_version.h"
#undef __XTD_STD_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(std::any value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
  /// @par Header
  /// ```cpp
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(bool value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
  /// @par Header
  /// ```cpp
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(xtd::byte value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(char value) {
    return xtd::convert::to_decimal(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(char8 value) {
    return xtd::convert::to_decimal(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(char16 value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(char32 value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(wchar value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
  /// @par Header
  /// ```cpp
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(decimal value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
  /// @par Header
  /// ```cpp
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(double value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
  /// @par Header
  /// ```cpp
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(float value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
  /// @par Header
  /// ```cpp
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(int16 value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
  /// @par Header
  /// ```cpp
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(int32 value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
  /// @par Header
  /// ```cpp
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(int64 value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
  /// @par Header
  /// ```cpp
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(slong value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
  /// @par Header
  /// ```cpp
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(sbyte value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
  /// @par Header
  /// ```cpp
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(uint16 value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
  /// @par Header
  /// ```cpp
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(uint32 value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
  /// @par Header
  /// ```cpp
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(uint64 value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
  /// @par Header
  /// ```cpp
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(xtd::ulong value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// ustring value = "42";
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(const xtd::ustring& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// ustring value = "42";
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(xtd::ustring& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(const std::string& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(std::string& value) {
    return xtd::convert::to_decimal(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(const std::u8string& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(std::u8string& value) {
    return xtd::convert::to_decimal(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(const std::u16string& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(std::u16string& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(const std::u32string& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(std::u32string& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(const std::wstring& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(std::wstring& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(const char* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(char* value) {
    return xtd::convert::to_decimal(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(const char8* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(char8* value) {
    return xtd::convert::to_decimal(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(const char16* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(char16* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(const char32* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(char32* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(const wchar* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// ```
  template<>
  inline decimal as<decimal>(wchar* value) {
    return xtd::convert::to_decimal(value);
  }
}
