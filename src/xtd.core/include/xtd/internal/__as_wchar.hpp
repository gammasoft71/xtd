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
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(std::any value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// ```cpp
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(bool value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// ```cpp
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(xtd::byte value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(char value) {
    return xtd::convert::to_wchar(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(char8 value) {
    return xtd::convert::to_wchar(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(char16 value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(char32 value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(wchar value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// ```cpp
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(decimal value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// ```cpp
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(double value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// ```cpp
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(float value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// ```cpp
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(int16 value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// ```cpp
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(int32 value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// ```cpp
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(int64 value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// ```cpp
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(slong value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// ```cpp
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(sbyte value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// ```cpp
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(uint16 value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// ```cpp
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(uint32 value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// ```cpp
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(uint64 value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// ```cpp
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(xtd::ulong value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(const xtd::string& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(xtd::string& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(const std::string& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(std::string& value) {
    return xtd::convert::to_wchar(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(const std::u8string& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(std::u8string& value) {
    return xtd::convert::to_wchar(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(const std::u16string& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(std::u16string& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(const std::u32string& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(std::u32string& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(const std::wstring& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(std::wstring& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(const char* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(char* value) {
    return xtd::convert::to_wchar(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(const char8* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(char8* value) {
    return xtd::convert::to_wchar(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(const char16* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(char16* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(const char32* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(char32* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(const wchar* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
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
  /// wchar result = as<wchar>(value);
  /// ```
  template<>
  inline wchar as<wchar>(wchar* value) {
    return xtd::convert::to_wchar(value);
  }
}
