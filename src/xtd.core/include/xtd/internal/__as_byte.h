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
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(std::any value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(bool value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// xtd::byte value = 42;
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(xtd::byte value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(char value) {
    return xtd::convert::to_byte(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8 value = u8'a';
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(char8 value) {
    return xtd::convert::to_byte(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16 value = u'a';
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(char16 value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32 value = u'a';
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(char32 value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar value = u'a';
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(wchar value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal value = 42.50l;
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(decimal value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(double value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(float value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16 value = 42;
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(int16 value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32 value = 42;
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(int32 value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64 value = 42l;
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(int64 value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// slong value = 42ll;
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(slong value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte value = 42ll;
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(sbyte value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16 value = 42u;
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(uint16 value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32 value = 42u;
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(uint32 value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64 value = 42ul;
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(uint64 value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// xtd::ulong value = 42ull;
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(xtd::ulong value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a byte.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(const xtd::ustring& value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a byte.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(xtd::ustring& value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a byte.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "0x2A";
  /// xtd::byte result = as<xtd::byte>(value, 16);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(const xtd::ustring& value, xtd::byte from_base) {
    return xtd::convert::to_byte(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(const std::string& value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(std::string& value) {
    return xtd::convert::to_byte(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(const std::u8string& value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(std::u8string& value) {
    return xtd::convert::to_byte(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(const std::u16string& value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(std::u16string& value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(const std::u32string& value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(std::u32string& value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(const std::wstring& value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(std::wstring& value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(const char* value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(char* value) {
    return xtd::convert::to_byte(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8* value = u8"42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(const char8* value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8* value = u8"42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(char8* value) {
    return xtd::convert::to_byte(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16* value = u"42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(const char16* value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16* value = u"42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(char16* value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32* value = U"42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(const char32* value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32* value = U"42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(char32* value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar* value = L"42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(const wchar* value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::byte object converted from value.
  /// @exception xtd::argument_exception value does not represent a bool.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar* value = L"42";
  /// xtd::byte result = as<xtd::byte>(value);
  /// @endcode
  template<>
  inline xtd::byte as<xtd::byte>(wchar* value) {
    return xtd::convert::to_byte(value);
  }
}
