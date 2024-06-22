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
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(std::any value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(bool value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(xtd::byte value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(char value) {
    return xtd::convert::to_single(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(char8 value) {
    return xtd::convert::to_single(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(char16 value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(char32 value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(wchar value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(decimal value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(double value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(float value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(int16 value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(int32 value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(int64 value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(slong value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(sbyte value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(uint16 value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(uint32 value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(uint64 value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(xtd::ulong value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const xtd::ustring& value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(xtd::ustring& value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const std::string& value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(std::string& value) {
    return xtd::convert::to_single(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const std::u8string& value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(std::u8string& value) {
    return xtd::convert::to_single(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const std::u16string& value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(std::u16string& value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const std::u32string& value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(std::u32string& value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const std::wstring& value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(std::wstring& value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const char* value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(char* value) {
    return xtd::convert::to_single(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const char8* value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(char8* value) {
    return xtd::convert::to_single(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const char16* value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(char16* value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const char32* value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(char32* value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const wchar* value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(wchar* value) {
    return xtd::convert::to_single(value);
  }
}
