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
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(std::any value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(bool value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(xtd::byte value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(char value) {
    return xtd::convert::to_sbyte(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(char8 value) {
    return xtd::convert::to_sbyte(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(char16 value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(char32 value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(wchar value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(decimal value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(double value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(float value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(int16 value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(int32 value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(int64 value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(slong value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(sbyte value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(uint16 value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(uint32 value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(uint64 value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(xtd::ulong value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(const xtd::ustring& value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(xtd::ustring& value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new sbyte object converted from value.
  /// @exception xtd::argument_exception value does not represent a sbyte.
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
  /// sbyte result = as<sbyte>(value, 16);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(const xtd::ustring& value, xtd::byte from_base) {
    return xtd::convert::to_sbyte(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(const std::string& value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(std::string& value) {
    return xtd::convert::to_sbyte(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(const std::u8string& value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(std::u8string& value) {
    return xtd::convert::to_sbyte(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(const std::u16string& value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(std::u16string& value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(const std::u32string& value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(std::u32string& value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(const std::wstring& value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(std::wstring& value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(const char* value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(char* value) {
    return xtd::convert::to_sbyte(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(const char8* value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(char8* value) {
    return xtd::convert::to_sbyte(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(const char16* value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(char16* value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(const char32* value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(char32* value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(const wchar* value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte object converted from value.
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
  /// sbyte result = as<sbyte>(value);
  /// @endcode
  template<>
  inline sbyte as<sbyte>(wchar* value) {
    return xtd::convert::to_sbyte(value);
  }
}
