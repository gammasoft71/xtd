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
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(std::any value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(bool value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(xtd::byte value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(char value) {
    return xtd::convert::to_uint64(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(char8 value) {
    return xtd::convert::to_uint64(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(char16 value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(char32 value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(wchar value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(decimal value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(double value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(float value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(int16 value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(int32 value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(int64 value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(slong value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(sbyte value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(uint16 value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(uint32 value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(uint64 value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(xtd::ulong value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(const xtd::ustring& value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(xtd::ustring& value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new uint64 object converted from value.
  /// @exception xtd::argument_exception value does not represent a uint64.
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
  /// uint64 result = as<uint64>(value, 16);
  /// @endcode
  template<>
  inline uint64 as<uint64>(const xtd::ustring& value, xtd::byte from_base) {
    return xtd::convert::to_uint64(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(const std::string& value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(std::string& value) {
    return xtd::convert::to_uint64(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(const std::u8string& value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(std::u8string& value) {
    return xtd::convert::to_uint64(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(const std::u16string& value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(std::u16string& value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(const std::u32string& value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(std::u32string& value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(const std::wstring& value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(std::wstring& value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(const char* value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(char* value) {
    return xtd::convert::to_uint64(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(const char8* value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(char8* value) {
    return xtd::convert::to_uint64(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(const char16* value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(char16* value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(const char32* value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(char32* value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(const wchar* value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64 object converted from value.
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
  /// uint64 result = as<uint64>(value);
  /// @endcode
  template<>
  inline uint64 as<uint64>(wchar* value) {
    return xtd::convert::to_uint64(value);
  }
}
