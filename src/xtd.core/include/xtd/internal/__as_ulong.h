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
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(std::any value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(bool value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(xtd::byte value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(char value) {
    return xtd::convert::to_ullong(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(char8 value) {
    return xtd::convert::to_ullong(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(char16 value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(char32 value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(wchar value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(decimal value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(double value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(float value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(int16 value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(int32 value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(int64 value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(slong value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(sbyte value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(uint16 value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(uint32 value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(uint64 value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(xtd::ulong value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(const xtd::ustring& value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(xtd::ustring& value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new xtd::ulong object converted from value.
  /// @exception xtd::argument_exception value does not represent a xtd::ulong.
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
  /// xtd::ulong result = as<xtd::ulong>(value, 16);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(const xtd::ustring& value, xtd::byte from_base) {
    return xtd::convert::to_ullong(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(const std::string& value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(std::string& value) {
    return xtd::convert::to_ullong(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(const std::u8string& value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(std::u8string& value) {
    return xtd::convert::to_ullong(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(const std::u16string& value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(std::u16string& value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(const std::u32string& value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(std::u32string& value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(const std::wstring& value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(std::wstring& value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(const char* value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(char* value) {
    return xtd::convert::to_ullong(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(const char8* value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(char8* value) {
    return xtd::convert::to_ullong(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(const char16* value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(char16* value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(const char32* value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(char32* value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(const wchar* value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline xtd::ulong as<xtd::ulong>(wchar* value) {
    return xtd::convert::to_ullong(value);
  }
}
