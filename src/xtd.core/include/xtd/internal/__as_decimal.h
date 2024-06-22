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
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(std::any value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(bool value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(xtd::byte value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(char value) {
    return xtd::convert::to_decimal(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(char16 value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(char32 value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(wchar value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(decimal value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(double value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(float value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(int16 value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(int32 value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(int64 value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(slong value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(sbyte value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(uint16 value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(uint32 value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(uint64 value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(xtd::ulong value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(const xtd::ustring& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(xtd::ustring& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(const std::string& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(std::string& value) {
    return xtd::convert::to_decimal(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(const std::u8string& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(const std::u16string& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(std::u16string& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(const std::u32string& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(std::u32string& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(const std::wstring& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(std::wstring& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(const char* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(char* value) {
    return xtd::convert::to_decimal(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(const char8* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(const char16* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(char16* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(const char32* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(char32* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(const wchar* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal object converted from value.
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
  /// decimal result = as<decimal>(value);
  /// @endcode
  template<>
  inline decimal as<decimal>(wchar* value) {
    return xtd::convert::to_decimal(value);
  }
}
