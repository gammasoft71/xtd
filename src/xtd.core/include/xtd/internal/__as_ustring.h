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
  /// @code #include <xtd/as> @endcode
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
  inline ustring as<ustring>(std::any value) {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline ustring as<ustring>(bool value) {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline ustring as<ustring>(xtd::byte value) {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new ustring object converted from value.
  /// @exception xtd::argument_exception vfrom_base is not 2, 8, 10, or 16.
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
  /// ustring result = as<ustring>(value, 16);
  /// @endcode
  template<>
  inline ustring as<ustring>(xtd::byte value, xtd::byte from_base) {
    return xtd::convert::to_string(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline ustring as<ustring>(char value) {
    return xtd::convert::to_string(value);
  }
  
#if defined(__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline ustring as<ustring>(char8 value) {
    return xtd::convert::to_string(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline ustring as<ustring>(char16 value) {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline ustring as<ustring>(char32 value) {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline ustring as<ustring>(wchar value) {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline ustring as<ustring>(decimal value) {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline ustring as<ustring>(double value) {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline ustring as<ustring>(float value) {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline ustring as<ustring>(int16 value) {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new ustring object converted from value.
  /// @exception xtd::argument_exception vfrom_base is not 2, 8, 10, or 16.
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
  /// ustring result = as<ustring>(value, 16);
  /// @endcode
  template<>
  inline ustring as<ustring>(int16 value, xtd::byte from_base) {
    return xtd::convert::to_string(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline ustring as<ustring>(int32 value) {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new ustring object converted from value.
  /// @exception xtd::argument_exception vfrom_base is not 2, 8, 10, or 16.
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
  /// ustring result = as<ustring>(value, 16);
  /// @endcode
  template<>
  inline ustring as<ustring>(int32 value, xtd::byte from_base) {
    return xtd::convert::to_string(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline ustring as<ustring>(int64 value) {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new ustring object converted from value.
  /// @exception xtd::argument_exception vfrom_base is not 2, 8, 10, or 16.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64 value = 42;
  /// ustring result = as<ustring>(value, 16);
  /// @endcode
  template<>
  inline ustring as<ustring>(int64 value, xtd::byte from_base) {
    return xtd::convert::to_string(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline ustring as<ustring>(slong value) {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new ustring object converted from value.
  /// @exception xtd::argument_exception vfrom_base is not 2, 8, 10, or 16.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// slong value = 42;
  /// ustring result = as<ustring>(value, 16);
  /// @endcode
  template<>
  inline ustring as<ustring>(slong value, xtd::byte from_base) {
    return xtd::convert::to_string(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline ustring as<ustring>(sbyte value) {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new ustring object converted from value.
  /// @exception xtd::argument_exception vfrom_base is not 2, 8, 10, or 16.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte value = 42;
  /// ustring result = as<ustring>(value, 16);
  /// @endcode
  template<>
  inline ustring as<ustring>(sbyte value, xtd::byte from_base) {
    return xtd::convert::to_string(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline ustring as<ustring>(uint16 value) {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new ustring object converted from value.
  /// @exception xtd::argument_exception vfrom_base is not 2, 8, 10, or 16.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16 value = 42;
  /// ustring result = as<ustring>(value, 16);
  /// @endcode
  template<>
  inline ustring as<ustring>(uint16 value, xtd::byte from_base) {
    return xtd::convert::to_string(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline ustring as<ustring>(uint32 value) {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new ustring object converted from value.
  /// @exception xtd::argument_exception vfrom_base is not 2, 8, 10, or 16.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32 value = 42;
  /// ustring result = as<ustring>(value, 16);
  /// @endcode
  template<>
  inline ustring as<ustring>(uint32 value, xtd::byte from_base) {
    return xtd::convert::to_string(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline ustring as<ustring>(uint64 value) {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new ustring object converted from value.
  /// @exception xtd::argument_exception vfrom_base is not 2, 8, 10, or 16.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64 value = 42;
  /// ustring result = as<ustring>(value, 16);
  /// @endcode
  template<>
  inline ustring as<ustring>(uint64 value, xtd::byte from_base) {
    return xtd::convert::to_string(value, from_base);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
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
  /// xtd::ulong result = as<xtd::ulong>(value);
  /// @endcode
  template<>
  inline ustring as<ustring>(xtd::ulong value) {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @param from_base The base of the number in value, which must be 2, 8, 10, or 16.
  /// @return A new ustring object converted from value.
  /// @exception xtd::argument_exception vfrom_base is not 2, 8, 10, or 16.
  /// @par Header
  /// @code #include <xtd/as> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// xtd::ulong value = 42;
  /// ustring result = as<ustring>(value, 16);
  /// @endcode
  template<>
  inline ustring as<ustring>(xtd::ulong value, xtd::byte from_base) {
    return xtd::convert::to_string(value, from_base);
  }
}
