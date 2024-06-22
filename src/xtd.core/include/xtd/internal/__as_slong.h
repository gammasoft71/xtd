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
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(std::any value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(bool value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(xtd::byte value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(char value) {
    return xtd::convert::to_llong(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(char8 value) {
    return xtd::convert::to_llong(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(char16 value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(char32 value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(wchar value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(decimal value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(double value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(float value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(int16 value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(int32 value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(int64 value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(slong value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(sbyte value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(uint16 value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(uint32 value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(uint64 value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(xtd::ulong value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(const xtd::ustring& value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(xtd::ustring& value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new slong object converted from value.
  /// @exception xtd::argument_exception value does not represent a slong.
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
  /// ustring value = "0x2A";
  /// slong result = as<slong>(value, 16);
  /// @endcode
  template<>
  inline slong as<slong>(const xtd::ustring& value, xtd::byte from_base) {
    return xtd::convert::to_llong(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(const std::string& value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(std::string& value) {
    return xtd::convert::to_llong(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(const std::u8string& value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(std::u8string& value) {
    return xtd::convert::to_llong(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(const std::u16string& value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(std::u16string& value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(const std::u32string& value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(std::u32string& value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(const std::wstring& value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(std::wstring& value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(const char* value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(char* value) {
    return xtd::convert::to_llong(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(const char8* value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(char8* value) {
    return xtd::convert::to_llong(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(const char16* value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(char16* value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(const char32* value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(char32* value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(const wchar* value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new slong object converted from value.
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
  /// slong result = as<slong>(value);
  /// @endcode
  template<>
  inline slong as<slong>(wchar* value) {
    return xtd::convert::to_llong(value);
  }
}
