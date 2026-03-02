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
  /// @return A new bool object converted from value.
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
  /// xtd::any value = 42;
  /// int result = as<int>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(xtd::any value) -> new_type {
    try {
      return xtd::any_cast<new_type>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// int result = as<int>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(bool value) -> new_type {
    return static_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  template<class new_type>
  [[nodiscard]] auto as(xtd::byte value) -> new_type {
    return static_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// int result = as<int>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(char value) -> new_type {
    return static_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// int result = as<int>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(xtd::char8 value) -> new_type {
    return static_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// char8 value = u'a';
  /// int result = as<int>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(xtd::char16 value) -> new_type {
    return static_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// char8 value = U'a';
  /// int result = as<int>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(xtd::char32 value) -> new_type {
    return static_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// char8 value = L'a';
  /// int result = as<int>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(xtd::wchar value) -> new_type {
    return static_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// decimal value = 42.0l;
  /// int result = as<int>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(xtd::decimal value) -> new_type {
    return static_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// double value = 42.0;
  /// int result = as<int>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(double value) -> new_type {
    return static_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// float value = 42.0f;
  /// int result = as<int>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(float value) -> new_type {
    return static_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  template<class new_type>
  [[nodiscard]] auto as(xtd::int16 value) -> new_type {
    return static_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  template<class new_type>
  [[nodiscard]] auto as(xtd::int32 value) -> new_type {
    return static_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// int64 value = 42;
  /// float result = as<float>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(xtd::int64 value) -> new_type {
    return static_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// slong value = 42;
  /// float result = as<float>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(xtd::slong value) -> new_type {
    return static_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// sbyte value = 42;
  /// float result = as<float>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(xtd::sbyte value) -> new_type {
    return static_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// uint16 value = 42;
  /// float result = as<float>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(xtd::uint16 value) -> new_type {
    return static_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// uint32 value = 42;
  /// float result = as<float>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(xtd::uint32 value) -> new_type {
    return static_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// uint64 value = 42;
  /// float result = as<float>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(xtd::uint64 value) -> new_type {
    return static_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// xtd::ulong value = 42;
  /// float result = as<float>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(xtd::ulong value) -> new_type {
    return static_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
  /// @exception xtd::invalid_cast_exception value bad type
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
  /// string value = "Gammasoft";
  /// object result = as<object>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(const xtd::string& value) -> new_type {
    try {
      return dynamic_cast<const new_type&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
  /// @exception xtd::invalid_cast_exception value bad type
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
  /// string value = "Gammasoft";
  /// object result = as<object>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(xtd::string& value) -> new_type {
    try {
      return dynamic_cast<new_type&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @cond
  template<class new_type>
  [[nodiscard]] auto as(const xtd::string& value, xtd::byte from_base) -> new_type {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  template<class new_type>
  [[nodiscard]] auto as(xtd::byte value, xtd::byte from_base) -> new_type {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  template<class new_type>
  [[nodiscard]] auto as(int16 value, xtd::byte from_base) -> new_type {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  template<class new_type>
  [[nodiscard]] auto as(xtd::int32 value, xtd::byte from_base) -> new_type {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  template<class new_type>
  [[nodiscard]] auto as(xtd::int64 value, xtd::byte from_base) -> new_type {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  template<class new_type>
  [[nodiscard]] auto as(xtd::slong value, xtd::byte from_base) -> new_type {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  template<class new_type>
  [[nodiscard]] auto as(xtd::sbyte value, xtd::byte from_base) -> new_type {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  template<class new_type>
  [[nodiscard]] auto as(uint16 value, xtd::byte from_base) -> new_type {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  template<class new_type>
  [[nodiscard]] auto as(xtd::uint32 value, xtd::byte from_base) -> new_type {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  template<class new_type>
  [[nodiscard]] auto as(xtd::uint64 value, xtd::byte from_base) -> new_type {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  template<class new_type>
  [[nodiscard]] auto as(xtd::ulong value, xtd::byte from_base) -> new_type {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  /// @endcond
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
  /// @exception xtd::invalid_cast_exception value bad type
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class new_type>
  [[nodiscard]] auto as(const std::string& value) -> new_type {
    try {
      return dynamic_cast<const new_type&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
  /// @exception xtd::invalid_cast_exception value bad type
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class new_type>
  [[nodiscard]] auto as(std::string& value) -> new_type {
    try {
      return dynamic_cast<new_type&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
  /// @exception xtd::invalid_cast_exception value bad type
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class new_type>
  [[nodiscard]] auto as(const std::u8string& value) -> new_type {
    try {
      return dynamic_cast<const new_type&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
  /// @exception xtd::invalid_cast_exception value bad type
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class new_type>
  [[nodiscard]] auto as(std::u8string& value) -> new_type {
    try {
      return dynamic_cast<new_type&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
  /// @exception xtd::invalid_cast_exception value bad type
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class new_type>
  [[nodiscard]] auto as(const std::u16string& value) -> new_type {
    try {
      return dynamic_cast<const new_type&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
  /// @exception xtd::invalid_cast_exception value bad type
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class new_type>
  [[nodiscard]] auto as(std::u16string& value) -> new_type {
    try {
      return dynamic_cast<new_type&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
  /// @exception xtd::invalid_cast_exception value bad type
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class new_type>
  [[nodiscard]] auto as(const std::u32string& value) -> new_type {
    try {
      return dynamic_cast<const new_type&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
  /// @exception xtd::invalid_cast_exception value bad type
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class new_type>
  [[nodiscard]] auto as(std::u32string& value) -> new_type {
    try {
      return dynamic_cast<new_type&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
  /// @exception xtd::invalid_cast_exception value bad type
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class new_type>
  [[nodiscard]] auto as(const std::wstring& value) -> new_type {
    try {
      return dynamic_cast<const new_type&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
  /// @exception xtd::invalid_cast_exception value bad type
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<class new_type>
  [[nodiscard]] auto as(std::wstring& value) -> new_type {
    try {
      return dynamic_cast<new_type&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// const char* value = "Gammasoft";
  /// intptr result = as<intptr>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(const char* value) -> new_type {
    return reinterpret_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// char* value = "Gammasoft";
  /// intptr result = as<intptr>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(char* value) -> new_type {
    return reinterpret_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// const char8* value = u8"Gammasoft";
  /// intptr result = as<intptr>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(const xtd::char8* value) -> new_type {
    return reinterpret_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// char8* value = u8"Gammasoft";
  /// intptr result = as<intptr>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(xtd::char8* value) -> new_type {
    return reinterpret_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// const char16* value = u"Gammasoft";
  /// intptr result = as<intptr>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(const xtd::char16* value) -> new_type {
    return reinterpret_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// char16* value = u"Gammasoft";
  /// intptr result = as<intptr>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(xtd::char16* value) -> new_type {
    return reinterpret_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// const char32* value = U"Gammasoft";
  /// intptr result = as<intptr>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(const xtd::char32* value) -> new_type {
    return reinterpret_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// char32* value = U"Gammasoft";
  /// intptr result = as<intptr>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(xtd::char32* value) -> new_type {
    return reinterpret_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// const wchar* value = L"Gammasoft";
  /// intptr result = as<intptr>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(const xtd::wchar* value) -> new_type {
    return reinterpret_cast<new_type>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type object converted from value.
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
  /// wchar* value = L"Gammasoft";
  /// intptr result = as<intptr>(value);
  /// ```
  template<class new_type>
  [[nodiscard]] auto as(xtd::wchar* value) -> new_type {
    return reinterpret_cast<new_type>(value);
  }
}
