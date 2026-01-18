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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(const std::string& value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  /// ```cpp
  /// string value = "Gammasoft";
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(std::string& value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(const std::string& value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(std::string& value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(const std::string& value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(std::string& value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(const std::string& value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(std::string& value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(const std::string& value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(std::string& value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(const std::string& value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(std::string& value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(const char* value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(const char* value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// const char* cvalue1 = "Gammasoft";
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(const char* value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(const char* value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(const char* value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(const char* value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(char* value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(char* value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(char* value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(char* value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(char* value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(char* value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(const xtd::string& value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(xtd::string& value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(const xtd::string& value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(xtd::string& value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(const xtd::string& value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(xtd::string& value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(const xtd::string& value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(xtd::string& value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(const xtd::string& value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(xtd::string& value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(const xtd::string& value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(xtd::string& value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string value = u8"Gammasoft";
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(const std::u8string& value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string value = u8"Gammasoft";
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(std::u8string& value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string value = u8"Gammasoft";
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(const std::u8string& value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string value = u8"Gammasoft";
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(std::u8string& value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string value = u8"Gammasoft";
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(const std::u8string& value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string value = u8"Gammasoft";
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(std::u8string& value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string value = u8"Gammasoft";
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(const std::u8string& value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string value = u8"Gammasoft";
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(std::u8string& value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string value = u8"Gammasoft";
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(const std::u8string& value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string value = u8"Gammasoft";
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(std::u8string& value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string value = u8"Gammasoft";
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(const std::u8string& value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string value = u8"Gammasoft";
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(std::u8string& value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(const char8* value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(const char8* value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(const char8* value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(const char8* value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(const char8* value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(const char8* value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(char8* value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(char8* value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(char8* value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(char8* value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(char8* value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(char8* value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string value = u"Gammasoft";
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(const std::u16string& value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string value = u"Gammasoft";
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(std::u16string& value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string value = u"Gammasoft";
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(const std::u16string& value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string value = u"Gammasoft";
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(std::u16string& value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string value = "Gammasoft";
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(const std::u16string& value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string value = "Gammasoft";
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(std::u16string& value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string value = u"Gammasoft";
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(const std::u16string& value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string value = u"Gammasoft";
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(std::u16string& value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string value = u"Gammasoft";
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(const std::u16string& value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string value = u"Gammasoft";
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(std::u16string& value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string value = u"Gammasoft";
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(const std::u16string& value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string value = u"Gammasoft";
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(std::u16string& value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(const char16* value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(const char16* value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(const char16* value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(const char16* value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(const char16* value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(const char16* value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(char16* value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(char16* value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(char16* value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(char16* value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(char16* value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(char16* value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string value = U"Gammasoft";
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(const std::u32string& value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string value = U"Gammasoft";
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(std::u32string& value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string value = U"Gammasoft";
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(const std::u32string& value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string value = U"Gammasoft";
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(std::u32string& value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string value = U"Gammasoft";
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(const std::u32string& value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string value = U"Gammasoft";
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(std::u32string& value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string value = U"Gammasoft";
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(const std::u32string& value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string value = U"Gammasoft";
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(std::u32string& value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string value = U"Gammasoft";
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(const std::u32string& value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string value = U"Gammasoft";
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(std::u32string& value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string value = U"Gammasoft";
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(const std::u32string& value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string value = U"Gammasoft";
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(std::u32string& value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(const char32* value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(const char32* value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(const char32* value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(const char32* value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(const char32* value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(const char32* value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(char32* value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(char32* value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(char32* value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(char32* value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(char32* value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(char32* value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring value = L"Gammasoft";
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(const std::wstring& value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring value = L"Gammasoft";
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(std::wstring& value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring value = L"Gammasoft";
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(const std::wstring& value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring value = L"Gammasoft";
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(std::wstring& value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring value = L"Gammasoft";
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(const std::wstring& value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring value = L"Gammasoft";
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(std::wstring& value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring value = L"Gammasoft";
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(const std::wstring& value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring value = L"Gammasoft";
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(std::wstring& value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring value = L"Gammasoft";
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(const std::wstring& value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring value = L"Gammasoft";
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(std::wstring& value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring value = L"Gammasoft";
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(const std::wstring& value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring value = L"Gammasoft";
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(std::wstring& value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(const wchar* value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(const wchar* value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(const wchar* value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(const wchar* value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(const wchar* value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(const wchar* value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::string>(wchar* value) -> std::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// string result = as<string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<xtd::string>(wchar* value) -> xtd::string {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u8string>(wchar* value) -> std::u8string {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u16string>(wchar* value) -> std::u16string {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::u32string>(wchar* value) -> std::u32string {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
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
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  [[nodiscard]] inline auto as<std::wstring>(wchar* value) -> std::wstring {
    return xtd::convert_string::to_wstring(value);
  }
}
