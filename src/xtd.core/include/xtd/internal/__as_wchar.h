/// @file
/// @brief Contains xtd::as method.
#pragma once

/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(std::any value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(bool value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// xtd::byte value = 42;
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(xtd::byte value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(char value) {
    return xtd::convert::to_wchar(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8 value = u8'a';
  /// wchar result = as<wchar>(value);
  /// @endcode
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
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16 value = u'a';
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(char16 value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32 value = u'a';
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(char32 value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar value = u'a';
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(wchar value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal value = 42.50l;
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(decimal value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(double value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(float value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16 value = 42;
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(int16 value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32 value = 42;
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(int32 value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64 value = 42l;
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(int64 value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// slong value = 42ll;
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(slong value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte value = 42ll;
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(sbyte value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16 value = 42u;
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(uint16 value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32 value = 42u;
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(uint32 value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64 value = 42ul;
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(uint64 value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// xtd::ulong value = 42ull;
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(xtd::ulong value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(const xtd::ustring& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(xtd::ustring& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(const std::string& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(std::string& value) {
    return xtd::convert::to_wchar(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(const std::u8string& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// wchar result = as<wchar>(value);
  /// @endcode
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
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(const std::u16string& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(std::u16string& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(const std::u32string& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(std::u32string& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(const std::wstring& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(std::wstring& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(const char* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(char* value) {
    return xtd::convert::to_wchar(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8* value = u8"42";
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(const char8* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8* value = u8"42";
  /// wchar result = as<wchar>(value);
  /// @endcode
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
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16* value = u"42";
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(const char16* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16* value = u"42";
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(char16* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32* value = U"42";
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(const char32* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32* value = U"42";
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(char32* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar* value = L"42";
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(const wchar* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code
  /// #include <xtd/as>
  /// @endcode
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar* value = L"42";
  /// wchar result = as<wchar>(value);
  /// @endcode
  template<>
  inline wchar as<wchar>(wchar* value) {
    return xtd::convert::to_wchar(value);
  }
}
