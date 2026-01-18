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
  /// @return A new double object converted from value.
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
  /// xtd::any value = true;
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(xtd::any value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(bool value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(xtd::byte value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(char value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(xtd::char8 value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(xtd::char16 value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(xtd::char32 value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(xtd::wchar value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(xtd::decimal value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(double value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(float value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(xtd::int16 value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(xtd::int32 value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(xtd::int64 value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(xtd::slong value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(xtd::sbyte value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(xtd::uint16 value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(xtd::uint32 value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(xtd::uint64 value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(xtd::ulong value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(const xtd::string& value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(xtd::string& value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(const std::string& value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(std::string& value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(const std::u8string& value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(std::u8string& value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(const std::u16string& value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(std::u16string& value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(const std::u32string& value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(std::u32string& value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(const std::wstring& value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(std::wstring& value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(const char* value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(char* value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(const xtd::char8* value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(xtd::char8* value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(const xtd::char16* value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(xtd::char16* value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(const xtd::char32* value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(xtd::char32* value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(const xtd::wchar* value) -> double {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
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
  /// double result = as<double>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<double>(xtd::wchar* value) -> double {
    return xtd::convert::to_double(value);
  }
}
