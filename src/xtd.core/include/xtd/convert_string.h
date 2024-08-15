/// @file
/// @brief Contains xtd::convert_string class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "static.h"
#include "string.h"
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.h"
#undef __XTD_STD_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents API to convert string containers.
  /// @par Header
  /// ```cpp
  /// #include <xtd/convert_string>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks This class cannot be inherited.
  /// @remarks This class is used to convert string container to another.
  /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
  /// @remarks To change the encoded format use xtd::text::encoding with xtd::string class.
  class convert_string static_ {
  public:
    /// @name Public Static Methods
    
    /// @{
    /// @brief Converts std::string to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// string s1 = "Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// ```
    static const std::string& to_string(const std::string& str) noexcept;
    /// @brief Converts const char* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// const char* c1 = "Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// ```
    static std::string to_string(const char* str) noexcept;
    /// @brief Converts char* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// char* c1 = "Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// ```
    static std::string to_string(char* str) noexcept;
    /// @brief Converts xtd::string to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// string s1 = "Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// ```
    static std::string to_string(const xtd::string& str) noexcept;
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Converts std::u8string to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u8string s1 = u8"Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// ```
    static std::string to_string(const std::u8string& str) noexcept;
    /// @brief Converts const char8* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// const char8* c1 = u8"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// ```
    static std::string to_string(const char8* str) noexcept;
    /// @brief Converts char8* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// char8* c1 = u8"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// ```
    static std::string to_string(char8* str) noexcept;
#endif
    /// @brief Converts std::u16string to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u16string s1 = u"Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// ```
    static std::string to_string(const std::u16string& str) noexcept;
    /// @brief Converts const char16* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// const char16* c1 = u"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// ```
    static std::string to_string(const char16* str) noexcept;
    /// @brief Converts char16* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// char16* c1 = u"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// ```
    static std::string to_string(char16* str) noexcept;
    /// @brief Converts std::u32string to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u32string s1 = U"Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// ```
    static std::string to_string(const std::u32string& str) noexcept;
    /// @brief Converts const char32* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// const char32* c1 = U"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// ```
    static std::string to_string(const char32* str) noexcept;
    /// @brief Converts char32* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// char32* c1 = U"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// ```
    static std::string to_string(char32* str) noexcept;
    /// @brief Converts std::wstring to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// wstring s1 = L"Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// ```
    static std::string to_string(const std::wstring& str) noexcept;
    /// @brief Converts const wchar* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// const wchar* c1 = L"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// ```
    static std::string to_string(const wchar* str) noexcept;
    /// @brief Converts wchar* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// wchar* c1 = L"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// ```
    static std::string to_string(wchar* str) noexcept;
    
    /// @brief Converts std::string to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// string s1 = "Gammasoft";
    /// string s2 = string_converter::to_ustring(s1);
    /// ```
    static xtd::string to_ustring(const std::string& str) noexcept;
    /// @brief Converts const char* to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// const char* c1 = "Gammasoft";
    /// string s1 = string_converter::to_ustring(c1);
    /// ```
    static xtd::string to_ustring(const char* str) noexcept;
    /// @brief Converts char* to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// char* c1 = "Gammasoft";
    /// string s1 = string_converter::to_ustring(c1);
    /// ```
    static xtd::string to_ustring(char* str) noexcept;
    /// @brief Converts xtd::string to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// string s1 = "Gammasoft";
    /// string s2 = string_converter::to_ustring(s1);
    /// ```
    static const xtd::string& to_ustring(const xtd::string& str) noexcept;
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Converts std::u8string to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u8string s1 = u8"Gammasoft";
    /// string s2 = string_converter::to_ustring(s1);
    /// ```
    static xtd::string to_ustring(const std::u8string& str) noexcept;
    /// @brief Converts const char8* to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// const char8* c1 = u8"Gammasoft";
    /// string s1 = string_converter::to_ustring(c1);
    /// ```
    static xtd::string to_ustring(const char8* str) noexcept;
    /// @brief Converts char8* to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// char8* c1 = u8"Gammasoft";
    /// string s1 = string_converter::to_ustring(c1);
    /// ```
    static xtd::string to_ustring(char8* str) noexcept;
#endif
    /// @brief Converts std::u16string to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u16string s1 = u"Gammasoft";
    /// string s2 = string_converter::to_ustring(s1);
    /// ```
    static xtd::string to_ustring(const std::u16string& str) noexcept;
    /// @brief Converts const char16* to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// const char16* c1 = u"Gammasoft";
    /// string s1 = string_converter::to_ustring(c1);
    /// ```
    static xtd::string to_ustring(const char16* str) noexcept;
    /// @brief Converts char16* to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char16* c1 = u"Gammasoft";
    /// string s1 = string_converter::to_ustring(c1);
    /// ```
    static xtd::string to_ustring(char16* str) noexcept;
    /// @brief Converts std::u32string to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u32string s1 = U"Gammasoft";
    /// string s2 = string_converter::to_ustring(s1);
    /// ```
    static xtd::string to_ustring(const std::u32string& str) noexcept;
    /// @brief Converts const char32* to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char32* c1 = U"Gammasoft";
    /// string s1 = string_converter::to_ustring(c1);
    /// ```
    static xtd::string to_ustring(const char32* str) noexcept;
    /// @brief Converts char32* to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char32* c1 = U"Gammasoft";
    /// string s1 = string_converter::to_ustring(c1);
    /// ```
    static xtd::string to_ustring(char32* str) noexcept;
    /// @brief Converts std::wstring to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// wstring s1 = L"Gammasoft";
    /// string s2 = string_converter::to_ustring(s1);
    /// ```
    static xtd::string to_ustring(const std::wstring& str) noexcept;
    /// @brief Converts const wchar* to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const wchar* c1 = L"Gammasoft";
    /// string s1 = string_converter::to_ustring(c1);
    /// ```
    static xtd::string to_ustring(const wchar* str) noexcept;
    /// @brief Converts wchar* to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// wchar* c1 = L"Gammasoft";
    /// string s1 = string_converter::to_ustring(c1);
    /// ```
    static xtd::string to_ustring(wchar* str) noexcept;
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Converts std::string to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// string s1 = "Gammasoft";
    /// u8string s2 = string_converter::to_u8string(s1);
    /// ```
    static std::u8string to_u8string(const std::string& str) noexcept;
    /// @brief Converts const char* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char* c1 = "Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// ```
    static std::u8string to_u8string(const char* str) noexcept;
    /// @brief Converts char* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char* c1 = "Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// ```
    static std::u8string to_u8string(char* str) noexcept;
    /// @brief Converts xtd::string to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// string s1 = "Gammasoft";
    /// u8string s2 = string_converter::to_u8string(s1);
    /// ```
    static std::u8string to_u8string(const xtd::string& str) noexcept;
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Converts std::u8string to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u8string s1 = u8"Gammasoft";
    /// u8string s2 = string_converter::to_u8string(s1);
    /// ```
    static const std::u8string& to_u8string(const std::u8string& str) noexcept;
    /// @brief Converts const char8* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char8* c1 = u8"Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// ```
    static std::u8string to_u8string(const char8* str) noexcept;
    /// @brief Converts char8* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    static std::u8string to_u8string(char8* str) noexcept;
#endif
    /// @brief Converts std::u16string to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u16string s1 = u"Gammasoft";
    /// u8string s2 = string_converter::to_u8string(s1);
    /// ```
    static std::u8string to_u8string(const std::u16string& str) noexcept;
    /// @brief Converts const char16* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char16* c1 = u"Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// ```
    static std::u8string to_u8string(const char16* str) noexcept;
    /// @brief Converts char16* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char16* c1 = u"Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// ```
    static std::u8string to_u8string(char16* str) noexcept;
    /// @brief Converts std::u32string to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u32string s1 = U"Gammasoft";
    /// u8string s2 = string_converter::to_8ustring(s1);
    /// ```
    static std::u8string to_u8string(const std::u32string& str) noexcept;
    /// @brief Converts const char32* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char32* c1 = U"Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// ```
    static std::u8string to_u8string(const char32* str) noexcept;
    /// @brief Converts char32* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char32* c1 = U"Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// ```
    static std::u8string to_u8string(char32* str) noexcept;
    /// @brief Converts std::wstring to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// wstring s1 = L"Gammasoft";
    /// u8string s2 = string_converter::to_u8string(s1);
    /// ```
    static std::u8string to_u8string(const std::wstring& str) noexcept;
    /// @brief Converts const wchar* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const wchar* c1 = L"Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// ```
    static std::u8string to_u8string(const wchar* str) noexcept;
    /// @brief Converts wchar* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// wchar* c1 = L"Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// ```
    static std::u8string to_u8string(wchar* str) noexcept;
#endif
    
    /// @brief Converts std::string to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// string s1 = "Gammasoft";
    /// u16string s2 = string_converter::to_u16string(s1);
    /// ```
    static std::u16string to_u16string(const std::string& str) noexcept;
    /// @brief Converts const char* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char* c1 = "Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// ```
    static std::u16string to_u16string(const char* str) noexcept;
    /// @brief Converts char* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char* c1 = "Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// ```
    static std::u16string to_u16string(char* str) noexcept;
    /// @brief Converts xtd::string to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// string s1 = "Gammasoft";
    /// u16string s2 = string_converter::to_u16string(s1);
    /// ```
    static std::u16string to_u16string(const xtd::string& str) noexcept;
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Converts std::u8string to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u8string s1 = u8"Gammasoft";
    /// u16string s2 = string_converter::to_u16string(s1);
    /// ```
    static std::u16string to_u16string(const std::u8string& str) noexcept;
    /// @brief Converts const char8* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char8* c1 = u8"Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// ```
    static std::u16string to_u16string(const char8* str) noexcept;
    /// @brief Converts char8* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char8* c1 = u8"Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// ```
    static std::u16string to_u16string(char8* str) noexcept;
#endif
    /// @brief Converts std::u16string to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u16string s1 = u"Gammasoft";
    /// u16string s2 = string_converter::to_u16string(s1);
    /// ```
    static const std::u16string& to_u16string(const std::u16string& str) noexcept;
    /// @brief Converts const char16* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char16* c1 = u"Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// ```
    static std::u16string to_u16string(const char16* str) noexcept;
    /// @brief Converts char16* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char16* c1 = u"Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// ```
    static std::u16string to_u16string(char16* str) noexcept;
    /// @brief Converts std::u32string to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u32string s1 = U"Gammasoft";
    /// u16string s2 = string_converter::to_u16string(s1);
    /// ```
    static std::u16string to_u16string(const std::u32string& str) noexcept;
    /// @brief Converts const char32* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char32* c1 = U"Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// ```
    static std::u16string to_u16string(const char32* str) noexcept;
    /// @brief Converts char32* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char32* c1 = "Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// ```
    static std::u16string to_u16string(char32* str) noexcept;
    /// @brief Converts std::wstring to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// wstring s1 = L"Gammasoft";
    /// u16string s2 = string_converter::to_u16string(s1);
    /// ```
    static std::u16string to_u16string(const std::wstring& str) noexcept;
    /// @brief Converts const wchar* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const wchar* c1 = L"Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// ```
    static std::u16string to_u16string(const wchar* str) noexcept;
    /// @brief Converts wchar* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// wchar* c1 = L"Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// ```
    static std::u16string to_u16string(wchar* str) noexcept;
    
    /// @brief Converts std::string to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// string s1 = "Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// ```
    static std::u32string to_u32string(const std::string& str) noexcept;
    /// @brief Converts const char* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char* c1 = "Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// ```
    static std::u32string to_u32string(const char* str) noexcept;
    /// @brief Converts char* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char* c1 = "Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// ```
    static std::u32string to_u32string(char* str) noexcept;
    /// @brief Converts xtd::string to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// string s1 = "Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// ```
    static std::u32string to_u32string(const xtd::string& str) noexcept;
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Converts std::u8string to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u8string s1 = u8"Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// ```
    static std::u32string to_u32string(const std::u8string& str) noexcept;
    /// @brief Converts const char8* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char8* c1 = u8"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// ```
    static std::u32string to_u32string(const char8* str) noexcept;
    /// @brief Converts char8* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char8* c1 = u8"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// ```
    static std::u32string to_u32string(char8* str) noexcept;
#endif
    /// @brief Converts std::u16string to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u16string s1 = u"Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// ```
    static std::u32string to_u32string(const std::u16string& str) noexcept;
    /// @brief Converts const char16* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char16* c1 = u"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// ```
    static std::u32string to_u32string(const char16* str) noexcept;
    /// @brief Converts char16* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char16* c1 = u"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// ```
    static std::u32string to_u32string(char16* str) noexcept;
    /// @brief Converts std::u32string to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u32string s1 = U"Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// ```
    static const std::u32string& to_u32string(const std::u32string& str) noexcept;
    /// @brief Converts const char32* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char32* c1 = U"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// ```
    static std::u32string to_u32string(const char32* str) noexcept;
    /// @brief Converts char32* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char32* c1 = U"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// ```
    static std::u32string to_u32string(char32* str) noexcept;
    /// @brief Converts std::wstring to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// wstring s1 = L"Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// ```
    static std::u32string to_u32string(const std::wstring& str) noexcept;
    /// @brief Converts const wchar* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const wchar* c1 = L"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// ```
    static std::u32string to_u32string(const wchar* str) noexcept;
    /// @brief Converts wchar* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// wchar* c1 = L"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// ```
    static std::u32string to_u32string(wchar* str) noexcept;
    
    /// @brief Converts std::string to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// string s1 = "Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// ```
    static std::wstring to_wstring(const std::string& str) noexcept;
    /// @brief Converts const char* to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char* c1 = "Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// ```
    static std::wstring to_wstring(const char* str) noexcept;
    /// @brief Converts char* to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char* c1 = "Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// ```
    static std::wstring to_wstring(char* str) noexcept;
    /// @brief Converts xtd::string to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// string s1 = "Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// ```
    static std::wstring to_wstring(const xtd::string& str) noexcept;
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Converts std::u8string to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u8string s1 = u8"Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// ```
    static std::wstring to_wstring(const std::u8string& str) noexcept;
    /// @brief Converts const char8* to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char8* c1 = u8"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// ```
    static std::wstring to_wstring(const char8* str) noexcept;
    /// @brief Converts char8* to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char8* c1 = u8"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// ```
    static std::wstring to_wstring(char8* str) noexcept;
#endif
    /// @brief Converts std::u16string to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u16string s1 = u"Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// ```
    static std::wstring to_wstring(const std::u16string& str) noexcept;
    /// @brief Converts const char16* to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char16* c1 = u"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// ```
    static std::wstring to_wstring(const char16* str) noexcept;
    /// @brief Converts char16* to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char16* c1 = u"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// ```
    static std::wstring to_wstring(char16* str) noexcept;
    /// @brief Converts std::u32string to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u32string s1 = U"Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// ```
    static std::wstring to_wstring(const std::u32string& str) noexcept;
    /// @brief Converts const char32* to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char32* c1 = U"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// ```
    static std::wstring to_wstring(const char32* str) noexcept;
    /// @brief Converts char32* to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char32* c1 = U"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// ```
    static std::wstring to_wstring(char32* str) noexcept;
    /// @brief Converts std::wstring to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// wstring s1 = L"Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// ```
    static const std::wstring& to_wstring(const std::wstring& str) noexcept;
    /// @brief Converts const wchar* to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const wchar* c1 = L"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// ```
    static std::wstring to_wstring(const wchar* str) noexcept;
    /// @brief Converts wchar* to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// wchar* c1 = L"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// ```
    static std::wstring to_wstring(wchar* str) noexcept;
    /// @}
  };
}
