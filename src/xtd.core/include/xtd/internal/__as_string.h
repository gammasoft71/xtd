/// @file
/// @brief Contains xtd::as method.
#pragma once

/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#define __XTD_STD_INTERNAL__
#include "__xtd_std_version.h"
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
  inline std::string as<std::string>(const std::string& value) {
    return xtd::convert_string::to_string(value);
  }
  /// ```cpp
  /// string value = "Gammasoft";
  /// string result = as<string>(value);
  /// ```
  template<>
  inline std::string as<std::string>(std::string& value) {
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
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(const std::string& value) {
    return xtd::convert_string::to_ustring(value);
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
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(std::string& value) {
    return xtd::convert_string::to_ustring(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
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
  inline std::u8string as<std::u8string>(const std::string& value) {
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
  inline std::u8string as<std::u8string>(std::string& value) {
    return xtd::convert_string::to_u8string(value);
  }
#endif
  
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
  inline std::u16string as<std::u16string>(const std::string& value) {
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
  inline std::u16string as<std::u16string>(std::string& value) {
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
  inline std::u32string as<std::u32string>(const std::string& value) {
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
  inline std::u32string as<std::u32string>(std::string& value) {
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
  inline std::wstring as<std::wstring>(const std::string& value) {
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
  inline std::wstring as<std::wstring>(std::string& value) {
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
  inline std::string as<std::string>(const char* value) {
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
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(const char* value) {
    return xtd::convert_string::to_ustring(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
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
  inline std::u8string as<std::u8string>(const char* value) {
    return xtd::convert_string::to_u8string(value);
  }
#endif
  
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
  inline std::u16string as<std::u16string>(const char* value) {
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
  inline std::u32string as<std::u32string>(const char* value) {
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
  inline std::wstring as<std::wstring>(const char* value) {
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
  inline std::string as<std::string>(char* value) {
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
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(char* value) {
    return xtd::convert_string::to_ustring(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
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
  inline std::u8string as<std::u8string>(char* value) {
    return xtd::convert_string::to_u8string(value);
  }
#endif
  
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
  inline std::u16string as<std::u16string>(char* value) {
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
  inline std::u32string as<std::u32string>(char* value) {
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
  inline std::wstring as<std::wstring>(char* value) {
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
  /// ustring value = "Gammasoft";
  /// string result = as<string>(value);
  /// ```
  template<>
  inline std::string as<std::string>(const xtd::ustring& value) {
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
  /// ustring value = "Gammasoft";
  /// string result = as<string>(value);
  /// ```
  template<>
  inline std::string as<std::string>(xtd::ustring& value) {
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
  /// ustring value = "Gammasoft";
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(const xtd::ustring& value) {
    return xtd::convert_string::to_ustring(value);
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
  /// ustring value = "Gammasoft";
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(xtd::ustring& value) {
    return xtd::convert_string::to_ustring(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
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
  /// ustring value = "Gammasoft";
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  inline std::u8string as<std::u8string>(const xtd::ustring& value) {
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
  /// ustring value = "Gammasoft";
  /// u8string result = as<u8string>(value);
  /// ```
  template<>
  inline std::u8string as<std::u8string>(xtd::ustring& value) {
    return xtd::convert_string::to_u8string(value);
  }
#endif
  
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
  /// ustring value = "Gammasoft";
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  inline std::u16string as<std::u16string>(const xtd::ustring& value) {
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
  /// ustring value = "Gammasoft";
  /// u16string result = as<u16string>(value);
  /// ```
  template<>
  inline std::u16string as<std::u16string>(xtd::ustring& value) {
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
  /// ustring value = "Gammasoft";
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  inline std::u32string as<std::u32string>(const xtd::ustring& value) {
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
  /// ustring value = "Gammasoft";
  /// u32string result = as<u32string>(value);
  /// ```
  template<>
  inline std::u32string as<std::u32string>(xtd::ustring& value) {
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
  /// ustring value = "Gammasoft";
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  inline std::wstring as<std::wstring>(const xtd::ustring& value) {
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
  /// ustring value = "Gammasoft";
  /// wstring result = as<wstring>(value);
  /// ```
  template<>
  inline std::wstring as<std::wstring>(xtd::ustring& value) {
    return xtd::convert_string::to_wstring(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
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
  inline std::string as<std::string>(const std::u8string& value) {
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
  inline std::string as<std::string>(std::u8string& value) {
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
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(const std::u8string& value) {
    return xtd::convert_string::to_ustring(value);
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
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(std::u8string& value) {
    return xtd::convert_string::to_ustring(value);
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
  inline std::u8string as<std::u8string>(const std::u8string& value) {
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
  inline std::u8string as<std::u8string>(std::u8string& value) {
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
  inline std::u16string as<std::u16string>(const std::u8string& value) {
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
  inline std::u16string as<std::u16string>(std::u8string& value) {
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
  inline std::u32string as<std::u32string>(const std::u8string& value) {
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
  inline std::u32string as<std::u32string>(std::u8string& value) {
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
  inline std::wstring as<std::wstring>(const std::u8string& value) {
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
  inline std::wstring as<std::wstring>(std::u8string& value) {
    return xtd::convert_string::to_wstring(value);
  }
#endif
  
#if defined(__xtd__cpp_lib_char8_t)
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
  inline std::string as<std::string>(const char8* value) {
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
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(const char8* value) {
    return xtd::convert_string::to_ustring(value);
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
  inline std::u8string as<std::u8string>(const char8* value) {
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
  inline std::u16string as<std::u16string>(const char8* value) {
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
  inline std::u32string as<std::u32string>(const char8* value) {
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
  inline std::wstring as<std::wstring>(const char8* value) {
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
  inline std::string as<std::string>(char8* value) {
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
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(char8* value) {
    return xtd::convert_string::to_ustring(value);
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
  inline std::u8string as<std::u8string>(char8* value) {
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
  inline std::u16string as<std::u16string>(char8* value) {
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
  inline std::u32string as<std::u32string>(char8* value) {
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
  inline std::wstring as<std::wstring>(char8* value) {
    return xtd::convert_string::to_wstring(value);
  }
#endif
  
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
  inline std::string as<std::string>(const std::u16string& value) {
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
  inline std::string as<std::string>(std::u16string& value) {
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
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(const std::u16string& value) {
    return xtd::convert_string::to_ustring(value);
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
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(std::u16string& value) {
    return xtd::convert_string::to_ustring(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
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
  inline std::u8string as<std::u8string>(const std::u16string& value) {
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
  inline std::u8string as<std::u8string>(std::u16string& value) {
    return xtd::convert_string::to_u8string(value);
  }
#endif
  
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
  inline std::u16string as<std::u16string>(const std::u16string& value) {
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
  inline std::u16string as<std::u16string>(std::u16string& value) {
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
  inline std::u32string as<std::u32string>(const std::u16string& value) {
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
  inline std::u32string as<std::u32string>(std::u16string& value) {
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
  inline std::wstring as<std::wstring>(const std::u16string& value) {
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
  inline std::wstring as<std::wstring>(std::u16string& value) {
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
  inline std::string as<std::string>(const char16* value) {
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
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(const char16* value) {
    return xtd::convert_string::to_ustring(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
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
  inline std::u8string as<std::u8string>(const char16* value) {
    return xtd::convert_string::to_u8string(value);
  }
#endif
  
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
  inline std::u16string as<std::u16string>(const char16* value) {
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
  inline std::u32string as<std::u32string>(const char16* value) {
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
  inline std::wstring as<std::wstring>(const char16* value) {
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
  inline std::string as<std::string>(char16* value) {
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
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(char16* value) {
    return xtd::convert_string::to_ustring(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
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
  inline std::u8string as<std::u8string>(char16* value) {
    return xtd::convert_string::to_u8string(value);
  }
#endif
  
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
  inline std::u16string as<std::u16string>(char16* value) {
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
  inline std::u32string as<std::u32string>(char16* value) {
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
  inline std::wstring as<std::wstring>(char16* value) {
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
  inline std::string as<std::string>(const std::u32string& value) {
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
  inline std::string as<std::string>(std::u32string& value) {
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
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(const std::u32string& value) {
    return xtd::convert_string::to_ustring(value);
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
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(std::u32string& value) {
    return xtd::convert_string::to_ustring(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
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
  inline std::u8string as<std::u8string>(const std::u32string& value) {
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
  inline std::u8string as<std::u8string>(std::u32string& value) {
    return xtd::convert_string::to_u8string(value);
  }
#endif
  
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
  inline std::u16string as<std::u16string>(const std::u32string& value) {
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
  inline std::u16string as<std::u16string>(std::u32string& value) {
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
  inline std::u32string as<std::u32string>(const std::u32string& value) {
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
  inline std::u32string as<std::u32string>(std::u32string& value) {
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
  inline std::wstring as<std::wstring>(const std::u32string& value) {
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
  inline std::wstring as<std::wstring>(std::u32string& value) {
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
  inline std::string as<std::string>(const char32* value) {
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
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(const char32* value) {
    return xtd::convert_string::to_ustring(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
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
  inline std::u8string as<std::u8string>(const char32* value) {
    return xtd::convert_string::to_u8string(value);
  }
#endif
  
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
  inline std::u16string as<std::u16string>(const char32* value) {
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
  inline std::u32string as<std::u32string>(const char32* value) {
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
  inline std::wstring as<std::wstring>(const char32* value) {
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
  inline std::string as<std::string>(char32* value) {
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
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(char32* value) {
    return xtd::convert_string::to_ustring(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
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
  inline std::u8string as<std::u8string>(char32* value) {
    return xtd::convert_string::to_u8string(value);
  }
#endif
  
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
  inline std::u16string as<std::u16string>(char32* value) {
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
  inline std::u32string as<std::u32string>(char32* value) {
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
  inline std::wstring as<std::wstring>(char32* value) {
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
  inline std::string as<std::string>(const std::wstring& value) {
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
  inline std::string as<std::string>(std::wstring& value) {
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
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(const std::wstring& value) {
    return xtd::convert_string::to_ustring(value);
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
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(std::wstring& value) {
    return xtd::convert_string::to_ustring(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
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
  inline std::u8string as<std::u8string>(const std::wstring& value) {
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
  inline std::u8string as<std::u8string>(std::wstring& value) {
    return xtd::convert_string::to_u8string(value);
  }
#endif
  
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
  inline std::u16string as<std::u16string>(const std::wstring& value) {
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
  inline std::u16string as<std::u16string>(std::wstring& value) {
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
  inline std::u32string as<std::u32string>(const std::wstring& value) {
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
  inline std::u32string as<std::u32string>(std::wstring& value) {
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
  inline std::wstring as<std::wstring>(const std::wstring& value) {
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
  inline std::wstring as<std::wstring>(std::wstring& value) {
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
  inline std::string as<std::string>(const wchar* value) {
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
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(const wchar* value) {
    return xtd::convert_string::to_ustring(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
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
  inline std::u8string as<std::u8string>(const wchar* value) {
    return xtd::convert_string::to_u8string(value);
  }
#endif
  
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
  inline std::u16string as<std::u16string>(const wchar* value) {
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
  inline std::u32string as<std::u32string>(const wchar* value) {
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
  inline std::wstring as<std::wstring>(const wchar* value) {
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
  inline std::string as<std::string>(wchar* value) {
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
  /// ustring result = as<ustring>(value);
  /// ```
  template<>
  inline xtd::ustring as<xtd::ustring>(wchar* value) {
    return xtd::convert_string::to_ustring(value);
  }
  
#if defined(__xtd__cpp_lib_char8_t)
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
  inline std::u8string as<std::u8string>(wchar* value) {
    return xtd::convert_string::to_u8string(value);
  }
#endif
  
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
  inline std::u16string as<std::u16string>(wchar* value) {
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
  inline std::u32string as<std::u32string>(wchar* value) {
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
  inline std::wstring as<std::wstring>(wchar* value) {
    return xtd::convert_string::to_wstring(value);
  }
}
