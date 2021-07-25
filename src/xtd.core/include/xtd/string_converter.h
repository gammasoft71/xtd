/// @file
/// @brief Contains xtd::string_converter class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "static.h"
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the string container converter class.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks This class cannot be inherited.
  /// @remarks The class is used to convert string container to another.
  /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
  /// @remarks To change the encoded format use xtd::text::encoding with xtd::ustring class.
  class string_converter static_ {
  public:
    /// @brief Converts std::string to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    static const std::string& to_string(const std::string& str) noexcept;
    /// @brief Converts const char* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::string to_string(const char* str) noexcept;
    /// @brief Converts char* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::string to_string(char* str) noexcept;
    /// @brief Converts xtd::ustring to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::string to_string(const xtd::ustring& str) noexcept;
    /// @brief Converts std::u8string to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::string to_string(const std::u8string& str) noexcept;
    /// @brief Converts const char8_t* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::string to_string(const char8_t* str) noexcept;
    /// @brief Converts char8_t* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::string to_string(char8_t* str) noexcept;
    /// @brief Converts std::u16string to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::string to_string(const std::u16string& str) noexcept;
    /// @brief Converts const char16_t* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::string to_string(const char16_t* str) noexcept;
    /// @brief Converts char16_t* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::string to_string(char16_t* str) noexcept;
    /// @brief Converts std::u32string to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::string to_string(const std::u32string& str) noexcept;
    /// @brief Converts const char32_t* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::string to_string(const char32_t* str) noexcept;
    /// @brief Converts char32_t* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::string to_string(char32_t* str) noexcept;
    /// @brief Converts std::wstring to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::string to_string(const std::wstring& str) noexcept;
    /// @brief Converts const wchar_t* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::string to_string(const wchar_t* str) noexcept;
    /// @brief Converts wchar_t* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::string to_string(wchar_t* str) noexcept;

    /// @brief Converts std::string to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    static xtd::ustring to_ustring(const std::string& str) noexcept;
    /// @brief Converts const char* to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    static xtd::ustring to_ustring(const char* str) noexcept;
    /// @brief Converts char* to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    static xtd::ustring to_ustring(char* str) noexcept;
    /// @brief Converts xtd::ustring to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    static const xtd::ustring& to_ustring(const xtd::ustring& str) noexcept;
    /// @brief Converts std::u8string to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    static xtd::ustring to_ustring(const std::u8string& str) noexcept;
    /// @brief Converts const char8_t* to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    static xtd::ustring to_ustring(const char8_t* str) noexcept;
    /// @brief Converts char8_t* to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    static xtd::ustring to_ustring(char8_t* str) noexcept;
    /// @brief Converts std::u16string to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    static xtd::ustring to_ustring(const std::u16string& str) noexcept;
    /// @brief Converts const char16_t* to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    static xtd::ustring to_ustring(const char16_t* str) noexcept;
    /// @brief Converts char16_t* to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    static xtd::ustring to_ustring(char16_t* str) noexcept;
    /// @brief Converts std::u32string to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    static xtd::ustring to_ustring(const std::u32string& str) noexcept;
    /// @brief Converts const char32_t* to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    static xtd::ustring to_ustring(const char32_t* str) noexcept;
    /// @brief Converts char32_t* to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    static xtd::ustring to_ustring(char32_t* str) noexcept;
    /// @brief Converts std::wstring to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    static xtd::ustring to_ustring(const std::wstring& str) noexcept;
    /// @brief Converts const wchar_t* to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    static xtd::ustring to_ustring(const wchar_t* str) noexcept;
    /// @brief Converts wchar_t* to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    static xtd::ustring to_ustring(wchar_t* str) noexcept;

    /// @brief Converts std::string to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u8string to_u8string(const std::string& str) noexcept;
    /// @brief Converts const char* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u8string to_u8string(const char* str) noexcept;
    /// @brief Converts char* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u8string to_u8string(char* str) noexcept;
    /// @brief Converts xtd::ustring to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u8string to_u8string(const xtd::ustring& str) noexcept;
    /// @brief Converts std::u8string to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    static const std::u8string& to_u8string(const std::u8string& str) noexcept;
    /// @brief Converts const char8_t* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u8string to_u8string(const char8_t* str) noexcept;
    /// @brief Converts char8_t* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u8string to_u8string(char8_t* str) noexcept;
    /// @brief Converts std::u16string to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u8string to_u8string(const std::u16string& str) noexcept;
    /// @brief Converts const char16_t* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u8string to_u8string(const char16_t* str) noexcept;
    /// @brief Converts char16_t* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u8string to_u8string(char16_t* str) noexcept;
    /// @brief Converts std::u32string to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u8string to_u8string(const std::u32string& str) noexcept;
    /// @brief Converts const char32_t* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u8string to_u8string(const char32_t* str) noexcept;
    /// @brief Converts char32_t* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u8string to_u8string(char32_t* str) noexcept;
    /// @brief Converts std::wstring to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u8string to_u8string(const std::wstring& str) noexcept;
    /// @brief Converts const wchar_t* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u8string to_u8string(const wchar_t* str) noexcept;
    /// @brief Converts wchar_t* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u8string to_u8string(wchar_t* str) noexcept;

    /// @brief Converts std::string to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u16string to_u16string(const std::string& str) noexcept;
    /// @brief Converts const char* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u16string to_u16string(const char* str) noexcept;
    /// @brief Converts char* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u16string to_u16string(char* str) noexcept;
    /// @brief Converts xtd::ustring to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u16string to_u16string(const xtd::ustring& str) noexcept;
    /// @brief Converts std::u8string to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u16string to_u16string(const std::u8string& str) noexcept;
    /// @brief Converts const char8_t* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u16string to_u16string(const char8_t* str) noexcept;
    /// @brief Converts char8_t* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u16string to_u16string(char8_t* str) noexcept;
    /// @brief Converts std::u16string to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    static const std::u16string& to_u16string(const std::u16string& str) noexcept;
    /// @brief Converts const char16_t* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u16string to_u16string(const char16_t* str) noexcept;
    /// @brief Converts char16_t* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u16string to_u16string(char16_t* str) noexcept;
    /// @brief Converts std::u32string to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u16string to_u16string(const std::u32string& str) noexcept;
    /// @brief Converts const char32_t* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u16string to_u16string(const char32_t* str) noexcept;
    /// @brief Converts char32_t* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u16string to_u16string(char32_t* str) noexcept;
    /// @brief Converts std::wstring to std::to_u16string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u16string to_u16string(const std::wstring& str) noexcept;
    /// @brief Converts const wchar_t* to std::to_u16string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u16string to_u16string(const wchar_t* str) noexcept;
    /// @brief Converts wchar_t* to std::to_u16string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u16string to_u16string(wchar_t* str) noexcept;

    /// @brief Converts std::string to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u32string to_u32string(const std::string& str) noexcept;
    /// @brief Converts const char* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u32string to_u32string(const char* str) noexcept;
    /// @brief Converts char* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u32string to_u32string(char* str) noexcept;
    /// @brief Converts xtd::ustring to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u32string to_u32string(const xtd::ustring& str) noexcept;
    /// @brief Converts std::u8string to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u32string to_u32string(const std::u8string& str) noexcept;
    /// @brief Converts const char8_t* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u32string to_u32string(const char8_t* str) noexcept;
    /// @brief Converts char8_t* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u32string to_u32string(char8_t* str) noexcept;
    /// @brief Converts std::u16string to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u32string to_u32string(const std::u16string& str) noexcept;
    /// @brief Converts const char16_t* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u32string to_u32string(const char16_t* str) noexcept;
    /// @brief Converts char16_t* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u32string to_u32string(char16_t* str) noexcept;
    /// @brief Converts std::u32string to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u32string to_u32string(const std::u32string& str) noexcept;
    /// @brief Converts const char32_t* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u32string to_u32string(const char32_t* str) noexcept;
    /// @brief Converts char32_t* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u32string to_u32string(char32_t* str) noexcept;
    /// @brief Converts std::wstring to std::to_u16string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u32string to_u32string(const std::wstring& str) noexcept;
    /// @brief Converts const wchar_t* to std::to_u16string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u32string to_u32string(const wchar_t* str) noexcept;
    /// @brief Converts wchar_t* to std::to_u16string.
    /// @param str string to convert.
    /// @return The converted string.
    static std::u32string to_u32string(wchar_t* str) noexcept;
  };
}
