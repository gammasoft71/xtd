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
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(xtd::any value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(bool value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(xtd::byte value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(char value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(xtd::char8 value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(xtd::char16 value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(xtd::char32 value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(xtd::wchar value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(xtd::decimal value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(double value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(float value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(xtd::int16 value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(xtd::int32 value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(xtd::int64 value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(xtd::slong value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(xtd::sbyte value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(xtd::uint16 value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(xtd::uint32 value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(xtd::uint64 value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(xtd::ulong value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(const xtd::string& value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(xtd::string& value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(const std::string& value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(std::string& value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(const std::u8string& value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(std::u8string& value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(const std::u16string& value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(std::u16string& value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(const std::u32string& value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(std::u32string& value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(const std::wstring& value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(std::wstring& value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(const char* value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(char* value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(const xtd::char8* value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(xtd::char8* value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(const xtd::char16* value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(xtd::char16* value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(const xtd::char32* value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(xtd::char32* value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(const xtd::wchar* value) -> float {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  /// float result = as<float>(value);
  /// ```
  template<>
  inline auto as<float>(xtd::wchar* value) -> float {
    return xtd::convert::to_single(value);
  }
}
