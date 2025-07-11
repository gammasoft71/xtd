/// @file
/// @brief Contains xtd::convert_string class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "static.hpp"
#include "string.hpp"
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.hpp"
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
    /// @brief Converts xtd::string to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// string s1 = "Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// ```
    static const xtd::string& to_string(const xtd::string& str) noexcept;
    /// @brief Converts std::string to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// string s1 = "Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// ```
    static xtd::string to_string(const std::string& str) noexcept;
    /// @brief Converts const char* to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// const char* c1 = "Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// ```
    static xtd::string to_string(const char* str) noexcept;
    /// @brief Converts char* to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// char* c1 = "Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// ```
    static xtd::string to_string(char* str) noexcept;
    /// @brief Converts xtd::u8string to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u8string s1 = u8"Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// ```
    static xtd::string to_string(const xtd::u8string& str) noexcept;
    /// @brief Converts std::u8string to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// std::u8string s1 = u8"Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// ```
    static xtd::string to_string(const std::u8string& str) noexcept;
    /// @brief Converts const char8* to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// const char8* c1 = u8"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// ```
    static xtd::string to_string(const char8* str) noexcept;
    /// @brief Converts char8* to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// char8* c1 = u8"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// ```
    static xtd::string to_string(char8* str) noexcept;
    /// @brief Converts xtd::u16string to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u16string s1 = u"Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// ```
    static xtd::string to_string(const xtd::u16string& str) noexcept;
    /// @brief Converts std::u16string to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// std::u16string s1 = u"Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// ```
    static xtd::string to_string(const std::u16string& str) noexcept;
    /// @brief Converts const char16* to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// const char16* c1 = u"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// ```
    static xtd::string to_string(const char16* str) noexcept;
    /// @brief Converts char16* to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// char16* c1 = u"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// ```
    static xtd::string to_string(char16* str) noexcept;
    /// @brief Converts xtd::u32string to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u32string s1 = U"Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// ```
    static xtd::string to_string(const xtd::u32string& str) noexcept;
    /// @brief Converts std::u32string to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// std::u32string s1 = U"Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// ```
    static xtd::string to_string(const std::u32string& str) noexcept;
    /// @brief Converts const char32* to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// const char32* c1 = U"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// ```
    static xtd::string to_string(const char32* str) noexcept;
    /// @brief Converts char32* to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// char32* c1 = U"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// ```
    static xtd::string to_string(char32* str) noexcept;
    /// @brief Converts xtd::wstring to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// wstring s1 = L"Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// ```
    static xtd::string to_string(const xtd::wstring& str) noexcept;
    /// @brief Converts std::wstring to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// std::wstring s1 = L"Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// ```
    static xtd::string to_string(const std::wstring& str) noexcept;
    /// @brief Converts const wchar* to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// const wchar* c1 = L"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// ```
    static xtd::string to_string(const wchar* str) noexcept;
    /// @brief Converts wchar* to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// wchar* c1 = L"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// ```
    static xtd::string to_string(wchar* str) noexcept;
    
    /// @brief Converts xtd::string to xtd::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// string s1 = "Gammasoft";
    /// u8string s2 = string_converter::to_u8string(s1);
    /// ```
    static xtd::u8string to_u8string(const xtd::string& str) noexcept;
    /// @brief Converts std::string to xtd::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// string s1 = "Gammasoft";
    /// u8string s2 = string_converter::to_u8string(s1);
    /// ```
    static xtd::u8string to_u8string(const std::string& str) noexcept;
    /// @brief Converts const char* to xtd::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char* c1 = "Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// ```
    static xtd::u8string to_u8string(const char* str) noexcept;
    /// @brief Converts char* to xtd::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char* c1 = "Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// ```
    static xtd::u8string to_u8string(char* str) noexcept;
    /// @brief Converts std::u8string to xtd::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u8string s1 = u8"Gammasoft";
    /// u8string s2 = string_converter::to_u8string(s1);
    /// ```
    static const xtd::u8string& to_u8string(const xtd::u8string& str) noexcept;
    /// @brief Converts std::u8string to xtd::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// std::u8string s1 = u8"Gammasoft";
    /// u8string s2 = string_converter::to_u8string(s1);
    /// ```
    static xtd::u8string to_u8string(const std::u8string& str) noexcept;
    /// @brief Converts const char8* to xtd::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char8* c1 = u8"Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// ```
    static xtd::u8string to_u8string(const char8* str) noexcept;
    /// @brief Converts char8* to xtd::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    static xtd::u8string to_u8string(char8* str) noexcept;
    /// @brief Converts std::u16string to xtd::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u16string s1 = u"Gammasoft";
    /// u8string s2 = string_converter::to_u8string(s1);
    /// ```
    static xtd::u8string to_u8string(const xtd::u16string& str) noexcept;
    /// @brief Converts std::u16string to xtd::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// std::u16string s1 = u"Gammasoft";
    /// u8string s2 = string_converter::to_u8string(s1);
    /// ```
    static xtd::u8string to_u8string(const std::u16string& str) noexcept;
    /// @brief Converts const char16* to xtd::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char16* c1 = u"Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// ```
    static xtd::u8string to_u8string(const char16* str) noexcept;
    /// @brief Converts char16* to xtd::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char16* c1 = u"Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// ```
    static xtd::u8string to_u8string(char16* str) noexcept;
    /// @brief Converts std::u32string to xtd::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u32string s1 = U"Gammasoft";
    /// u8string s2 = string_converter::to_u8string(s1);
    /// ```
    static xtd::u8string to_u8string(const xtd::u32string& str) noexcept;
    /// @brief Converts std::u32string to xtd::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// std::u32string s1 = U"Gammasoft";
    /// u8string s2 = string_converter::to_u8string(s1);
    /// ```
    static xtd::u8string to_u8string(const std::u32string& str) noexcept;
    /// @brief Converts const char32* to xtd::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char32* c1 = U"Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// ```
    static xtd::u8string to_u8string(const char32* str) noexcept;
    /// @brief Converts char32* to xtd::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char32* c1 = U"Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// ```
    static xtd::u8string to_u8string(char32* str) noexcept;
    /// @brief Converts std::wstring to xtd::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// wstring s1 = L"Gammasoft";
    /// u8string s2 = string_converter::to_u8string(s1);
    /// ```
    static xtd::u8string to_u8string(const xtd::wstring& str) noexcept;
    /// @brief Converts std::wstring to xtd::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// std::wstring s1 = L"Gammasoft";
    /// u8string s2 = string_converter::to_u8string(s1);
    /// ```
    static xtd::u8string to_u8string(const std::wstring& str) noexcept;
    /// @brief Converts const wchar* to xtd::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const wchar* c1 = L"Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// ```
    static xtd::u8string to_u8string(const wchar* str) noexcept;
    /// @brief Converts wchar* to xtd::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// wchar* c1 = L"Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// ```
    static xtd::u8string to_u8string(wchar* str) noexcept;
    
    /// @brief Converts xtd::string to xtd::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// string s1 = "Gammasoft";
    /// u16string s2 = string_converter::to_u16string(s1);
    /// ```
    static xtd::u16string to_u16string(const xtd::string& str) noexcept;
    /// @brief Converts std::string to xtd::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// string s1 = "Gammasoft";
    /// u16string s2 = string_converter::to_u16string(s1);
    /// ```
    static xtd::u16string to_u16string(const std::string& str) noexcept;
    /// @brief Converts const char* to xtd::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char* c1 = "Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// ```
    static xtd::u16string to_u16string(const char* str) noexcept;
    /// @brief Converts char* to xtd::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char* c1 = "Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// ```
    static xtd::u16string to_u16string(char* str) noexcept;
    /// @brief Converts std::u8string to xtd::u16string.
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
    static xtd::u16string to_u16string(const xtd::u8string& str) noexcept;
    /// @brief Converts std::u8string to xtd::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// std::u8string s1 = u8"Gammasoft";
    /// u16string s2 = string_converter::to_u16string(s1);
    /// ```
    static xtd::u16string to_u16string(const std::u8string& str) noexcept;
    /// @brief Converts const char8* to xtd::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char8* c1 = u8"Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// ```
    static xtd::u16string to_u16string(const char8* str) noexcept;
    /// @brief Converts char8* to xtd::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char8* c1 = u8"Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// ```
    static xtd::u16string to_u16string(char8* str) noexcept;
    /// @brief Converts std::u16string to xtd::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u16string s1 = u"Gammasoft";
    /// u16string s2 = string_converter::to_u16string(s1);
    /// ```
    static const xtd::u16string& to_u16string(const xtd::u16string& str) noexcept;
    /// @brief Converts std::u16string to xtd::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// std::u16string s1 = u"Gammasoft";
    /// u16string s2 = string_converter::to_u16string(s1);
    /// ```
    static xtd::u16string to_u16string(const std::u16string& str) noexcept;
    /// @brief Converts const char16* to xtd::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char16* c1 = u"Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// ```
    static xtd::u16string to_u16string(const char16* str) noexcept;
    /// @brief Converts char16* to xtd::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char16* c1 = u"Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// ```
    static xtd::u16string to_u16string(char16* str) noexcept;
    /// @brief Converts std::u32string to xtd::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u32string s1 = U"Gammasoft";
    /// u16string s2 = string_converter::to_u16string(s1);
    /// ```
    static xtd::u16string to_u16string(const xtd::u32string& str) noexcept;
    /// @brief Converts std::u32string to xtd::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// std::u32string s1 = U"Gammasoft";
    /// u16string s2 = string_converter::to_u16string(s1);
    /// ```
    static xtd::u16string to_u16string(const std::u32string& str) noexcept;
    /// @brief Converts const char32* to xtd::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char32* c1 = U"Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// ```
    static xtd::u16string to_u16string(const char32* str) noexcept;
    /// @brief Converts char32* to xtd::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char32* c1 = "Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// ```
    static xtd::u16string to_u16string(char32* str) noexcept;
    /// @brief Converts std::wstring to xtd::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// wstring s1 = L"Gammasoft";
    /// u16string s2 = string_converter::to_u16string(s1);
    /// ```
    static xtd::u16string to_u16string(const xtd::wstring& str) noexcept;
    /// @brief Converts std::wstring to xtd::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// std::wstring s1 = L"Gammasoft";
    /// u16string s2 = string_converter::to_u16string(s1);
    /// ```
    static xtd::u16string to_u16string(const std::wstring& str) noexcept;
    /// @brief Converts const wchar* to xtd::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const wchar* c1 = L"Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// ```
    static xtd::u16string to_u16string(const wchar* str) noexcept;
    /// @brief Converts wchar* to xtd::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// wchar* c1 = L"Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// ```
    static xtd::u16string to_u16string(wchar* str) noexcept;
    
    /// @brief Converts xtd::string to xtd::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// string s1 = "Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// ```
    static xtd::u32string to_u32string(const xtd::string& str) noexcept;
    /// @brief Converts std::string to xtd::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// string s1 = "Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// ```
    static xtd::u32string to_u32string(const std::string& str) noexcept;
    /// @brief Converts const char* to xtd::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char* c1 = "Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// ```
    static xtd::u32string to_u32string(const char* str) noexcept;
    /// @brief Converts char* to xtd::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char* c1 = "Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// ```
    static xtd::u32string to_u32string(char* str) noexcept;
    /// @brief Converts std::u8string to xtd::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u8string s1 = u8"Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// ```
    static xtd::u32string to_u32string(const xtd::u8string& str) noexcept;
    /// @brief Converts std::u8string to xtd::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// std::u8string s1 = u8"Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// ```
    static xtd::u32string to_u32string(const std::u8string& str) noexcept;
    /// @brief Converts const char8* to xtd::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char8* c1 = u8"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// ```
    static xtd::u32string to_u32string(const char8* str) noexcept;
    /// @brief Converts char8* to xtd::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char8* c1 = u8"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// ```
    static xtd::u32string to_u32string(char8* str) noexcept;
    /// @brief Converts std::u16string to xtd::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u16string s1 = u"Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// ```
    static xtd::u32string to_u32string(const xtd::u16string& str) noexcept;
    /// @brief Converts std::u16string to xtd::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// std::u16string s1 = u"Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// ```
    static xtd::u32string to_u32string(const std::u16string& str) noexcept;
    /// @brief Converts const char16* to xtd::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char16* c1 = u"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// ```
    static xtd::u32string to_u32string(const char16* str) noexcept;
    /// @brief Converts char16* to xtd::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char16* c1 = u"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// ```
    static xtd::u32string to_u32string(char16* str) noexcept;
    /// @brief Converts std::u32string to xtd::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u32string s1 = U"Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// ```
    static const xtd::u32string& to_u32string(const xtd::u32string& str) noexcept;
    /// @brief Converts std::u32string to xtd::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u32string s1 = U"Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// ```
    static xtd::u32string to_u32string(const std::u32string& str) noexcept;
    /// @brief Converts const char32* to xtd::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char32* c1 = U"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// ```
    static xtd::u32string to_u32string(const char32* str) noexcept;
    /// @brief Converts char32* to xtd::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char32* c1 = U"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// ```
    static xtd::u32string to_u32string(char32* str) noexcept;
    /// @brief Converts std::wstring to xtd::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// wstring s1 = L"Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// ```
    static xtd::u32string to_u32string(const xtd::wstring& str) noexcept;
    /// @brief Converts std::wstring to xtd::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// std::wstring s1 = L"Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// ```
    static xtd::u32string to_u32string(const std::wstring& str) noexcept;
    /// @brief Converts const wchar* to xtd::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const wchar* c1 = L"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// ```
    static xtd::u32string to_u32string(const wchar* str) noexcept;
    /// @brief Converts wchar* to xtd::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// wchar* c1 = L"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// ```
    static xtd::u32string to_u32string(wchar* str) noexcept;
    
    /// @brief Converts xtd::string to xtd::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// string s1 = "Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// ```
    static xtd::wstring to_wstring(const xtd::string& str) noexcept;
    /// @brief Converts std::string to xtd::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// std::string s1 = "Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// ```
    static xtd::wstring to_wstring(const std::string& str) noexcept;
    /// @brief Converts const char* to xtd::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char* c1 = "Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// ```
    static xtd::wstring to_wstring(const char* str) noexcept;
    /// @brief Converts char* to xtd::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char* c1 = "Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// ```
    static xtd::wstring to_wstring(char* str) noexcept;
    /// @brief Converts std::u8string to xtd::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u8string s1 = u8"Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// ```
    static xtd::wstring to_wstring(const xtd::u8string& str) noexcept;
    /// @brief Converts std::u8string to xtd::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// std::u8string s1 = u8"Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// ```
    static xtd::wstring to_wstring(const std::u8string& str) noexcept;
    /// @brief Converts const char8* to xtd::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char8* c1 = u8"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// ```
    static xtd::wstring to_wstring(const char8* str) noexcept;
    /// @brief Converts char8* to xtd::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char8* c1 = u8"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// ```
    static xtd::wstring to_wstring(char8* str) noexcept;
    /// @brief Converts std::u16string to xtd::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u16string s1 = u"Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// ```
    static xtd::wstring to_wstring(const xtd::u16string& str) noexcept;
    /// @brief Converts std::u16string to xtd::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// std::u16string s1 = u"Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// ```
    static xtd::wstring to_wstring(const std::u16string& str) noexcept;
    /// @brief Converts const char16* to xtd::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char16* c1 = u"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// ```
    static xtd::wstring to_wstring(const char16* str) noexcept;
    /// @brief Converts char16* to xtd::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char16* c1 = u"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// ```
    static xtd::wstring to_wstring(char16* str) noexcept;
    /// @brief Converts std::u32string to xtd::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// u32string s1 = U"Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// ```
    static xtd::wstring to_wstring(const xtd::u32string& str) noexcept;
    /// @brief Converts std::u32string to xtd::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// std::u32string s1 = U"Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// ```
    static xtd::wstring to_wstring(const std::u32string& str) noexcept;
    /// @brief Converts const char32* to xtd::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const char32* c1 = U"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// ```
    static xtd::wstring to_wstring(const char32* str) noexcept;
    /// @brief Converts char32* to xtd::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// char32* c1 = U"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// ```
    static xtd::wstring to_wstring(char32* str) noexcept;
    /// @brief Converts std::wstring to xtd::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// wstring s1 = L"Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// ```
    static const xtd::wstring& to_wstring(const xtd::wstring& str) noexcept;
    /// @brief Converts std::wstring to xtd::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// ```cpp
    /// std::wstring s1 = L"Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// ```
    static xtd::wstring to_wstring(const std::wstring& str) noexcept;
    /// @brief Converts const wchar* to xtd::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// const wchar* c1 = L"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// ```
    static xtd::wstring to_wstring(const wchar* str) noexcept;
    /// @brief Converts wchar* to xtd::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// ```cpp
    /// wchar* c1 = L"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// ```
    static xtd::wstring to_wstring(wchar* str) noexcept;
    
    /// @brief Converts string_t to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @deprecated Replaced by xtd::convert_string::to_string - Will be removed in version 0.4.0.
    template<class string_t>
    [[deprecated("Replaced by xtd::convert_string::to_string - Will be removed in version 0.4.0.")]] static const xtd::string& to_ustring(const string_t& str) noexcept {return to_string(str);}
    /// @brief Converts string_t to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @deprecated Replaced by xtd::convert_string::to_string - Will be removed in version 0.4.0.
    template<class char_t>
    [[deprecated("Replaced by xtd::convert_string::to_string - Will be removed in version 0.4.0.")]] static const xtd::string& to_ustring(const char_t* str) noexcept {return to_string(str);}
    /// @brief Converts string_t to xtd::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @deprecated Replaced by xtd::convert_string::to_string - Will be removed in version 0.4.0.
    template<class char_t>
    [[deprecated("Replaced by xtd::convert_string::to_string - Will be removed in version 0.4.0.")]] static const xtd::string& to_ustring(char_t* str) noexcept {return to_string(str);}
    /// @}
  };
}
