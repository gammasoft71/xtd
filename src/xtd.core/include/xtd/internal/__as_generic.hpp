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
  /// std::any value = 42;
  /// int result = as<int>(value);
  /// ```
  template<class new_type_t>
  new_type_t as(std::any value) {
    try {
      return std::any_cast<new_type_t>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(bool value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(xtd::byte value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(char value) {
    return static_cast<new_type_t>(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(char8 value) {
    return static_cast<new_type_t>(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(char16 value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(char32 value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(wchar value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(decimal value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(double value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(float value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(int16 value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(int32 value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(int64 value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(slong value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(sbyte value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(uint16 value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(uint32 value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(uint64 value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(xtd::ulong value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(const xtd::string& value) {
    try {
      return dynamic_cast<const new_type_t&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(xtd::string& value) {
    try {
      return dynamic_cast<new_type_t&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @cond
  template<class new_type_t>
  new_type_t as(const xtd::string& value, xtd::byte from_base) {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  template<class new_type_t>
  new_type_t as(xtd::byte value, xtd::byte from_base) {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  template<class new_type_t>
  new_type_t as(int16 value, xtd::byte from_base) {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  template<class new_type_t>
  new_type_t as(int32 value, xtd::byte from_base) {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  template<class new_type_t>
  new_type_t as(int64 value, xtd::byte from_base) {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  template<class new_type_t>
  new_type_t as(slong value, xtd::byte from_base) {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  template<class new_type_t>
  new_type_t as(sbyte value, xtd::byte from_base) {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  template<class new_type_t>
  new_type_t as(uint16 value, xtd::byte from_base) {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  template<class new_type_t>
  new_type_t as(uint32 value, xtd::byte from_base) {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  template<class new_type_t>
  new_type_t as(uint64 value, xtd::byte from_base) {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  template<class new_type_t>
  new_type_t as(xtd::ulong value, xtd::byte from_base) {
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  /// @endcond
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(const std::string& value) {
    try {
      return dynamic_cast<const new_type_t&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(std::string& value) {
    try {
      return dynamic_cast<new_type_t&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(const std::u8string& value) {
    try {
      return dynamic_cast<const new_type_t&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(std::u8string& value) {
    try {
      return dynamic_cast<new_type_t&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(const std::u16string& value) {
    try {
      return dynamic_cast<const new_type_t&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(std::u16string& value) {
    try {
      return dynamic_cast<new_type_t&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(const std::u32string& value) {
    try {
      return dynamic_cast<const new_type_t&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(std::u32string& value) {
    try {
      return dynamic_cast<new_type_t&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(const std::wstring& value) {
    try {
      return dynamic_cast<const new_type_t&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(std::wstring& value) {
    try {
      return dynamic_cast<new_type_t&>(value);
    } catch (const std::exception& e) {
      xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, e.what());
    }
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(const char* value) {
    return reinterpret_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(char* value) {
    return reinterpret_cast<new_type_t>(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(const char8* value) {
    return reinterpret_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(char8* value) {
    return reinterpret_cast<new_type_t>(value);
  }
#endif
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(const char16* value) {
    return reinterpret_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(char16* value) {
    return reinterpret_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(const char32* value) {
    return reinterpret_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(char32* value) {
    return reinterpret_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(const wchar* value) {
    return reinterpret_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
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
  template<class new_type_t>
  new_type_t as(wchar* value) {
    return reinterpret_cast<new_type_t>(value);
  }
}
