/// @file
/// @brief Contains xtd::convert_string class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "invalid_cast_exception.h"
#include "static.h"
#include "ustring.h"
#include "diagnostics/stack_frame.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the string container converter class.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks This class cannot be inherited.
  /// @remarks This class is used to convert string container to another.
  /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
  /// @remarks To change the encoded format use xtd::text::encoding with xtd::ustring class.
  class convert_string static_ {
  public:
    /// @brief Converts std::string to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// string s1 = "Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// @endcode
    static const std::string& to_string(const std::string& str) noexcept;
    /// @brief Converts const char* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// const char* c1 = "Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// @endcode
    static std::string to_string(const char* str) noexcept;
    /// @brief Converts char* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// char* c1 = "Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// @endcode
    static std::string to_string(char* str) noexcept;
    /// @brief Converts xtd::ustring to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// ustring s1 = "Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// @endcode
    static std::string to_string(const xtd::ustring& str) noexcept;
    /// @brief Converts std::u8string to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// u8string s1 = u8"Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// @endcode
    static std::string to_string(const std::u8string& str) noexcept;
    /// @brief Converts const char8_t* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// const char8_t* c1 = u8"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// @endcode
    static std::string to_string(const char8_t* str) noexcept;
    /// @brief Converts char8_t* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// char8_t* c1 = u8"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// @endcode
    static std::string to_string(char8_t* str) noexcept;
    /// @brief Converts std::u16string to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// u16string s1 = u"Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// @endcode
    static std::string to_string(const std::u16string& str) noexcept;
    /// @brief Converts const char16_t* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// const char16_t* c1 = u"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// @endcode
    static std::string to_string(const char16_t* str) noexcept;
    /// @brief Converts char16_t* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// char16_t* c1 = u"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// @endcode
    static std::string to_string(char16_t* str) noexcept;
    /// @brief Converts std::u32string to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// u32string s1 = U"Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// @endcode
    static std::string to_string(const std::u32string& str) noexcept;
    /// @brief Converts const char32_t* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// const char32_t* c1 = U"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// @endcode
    static std::string to_string(const char32_t* str) noexcept;
    /// @brief Converts char32_t* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// char32_t* c1 = U"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// @endcode
    static std::string to_string(char32_t* str) noexcept;
    /// @brief Converts std::wstring to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// wstring s1 = L"Gammasoft";
    /// string s2 = string_converter::to_string(s1);
    /// @endcode
    static std::string to_string(const std::wstring& str) noexcept;
    /// @brief Converts const wchar_t* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// const wchar_t* c1 = L"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// @endcode
    static std::string to_string(const wchar_t* str) noexcept;
    /// @brief Converts wchar_t* to std::string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// wchar_t* c1 = L"Gammasoft";
    /// string s1 = string_converter::to_string(c1);
    /// @endcode
    static std::string to_string(wchar_t* str) noexcept;

    /// @brief Converts std::string to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// string s1 = "Gammasoft";
    /// ustring s2 = string_converter::to_ustring(s1);
    /// @endcode
    static xtd::ustring to_ustring(const std::string& str) noexcept;
    /// @brief Converts const char* to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// const char* c1 = "Gammasoft";
    /// ustring s1 = string_converter::to_ustring(c1);
    /// @endcode
    static xtd::ustring to_ustring(const char* str) noexcept;
    /// @brief Converts char* to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// char* c1 = "Gammasoft";
    /// ustring s1 = string_converter::to_ustring(c1);
    /// @endcode
    static xtd::ustring to_ustring(char* str) noexcept;
    /// @brief Converts xtd::ustring to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// ustring s1 = "Gammasoft";
    /// ustring s2 = string_converter::to_ustring(s1);
    /// @endcode
    static const xtd::ustring& to_ustring(const xtd::ustring& str) noexcept;
    /// @brief Converts std::u8string to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// u8string s1 = u8"Gammasoft";
    /// ustring s2 = string_converter::to_ustring(s1);
    /// @endcode
    static xtd::ustring to_ustring(const std::u8string& str) noexcept;
    /// @brief Converts const char8_t* to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// const char8_t* c1 = u8"Gammasoft";
    /// ustring s1 = string_converter::to_ustring(c1);
    /// @endcode
    static xtd::ustring to_ustring(const char8_t* str) noexcept;
    /// @brief Converts char8_t* to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// char8_t* c1 = u8"Gammasoft";
    /// ustring s1 = string_converter::to_ustring(c1);
    /// @endcode
    static xtd::ustring to_ustring(char8_t* str) noexcept;
    /// @brief Converts std::u16string to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// u16string s1 = u"Gammasoft";
    /// ustring s2 = string_converter::to_ustring(s1);
    /// @endcode
    static xtd::ustring to_ustring(const std::u16string& str) noexcept;
    /// @brief Converts const char16_t* to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// const char16_t* c1 = u"Gammasoft";
    /// ustring s1 = string_converter::to_ustring(c1);
    /// @endcode
    static xtd::ustring to_ustring(const char16_t* str) noexcept;
    /// @brief Converts char16_t* to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// char16_t* c1 = u"Gammasoft";
    /// ustring s1 = string_converter::to_ustring(c1);
    /// @endcode
    static xtd::ustring to_ustring(char16_t* str) noexcept;
    /// @brief Converts std::u32string to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// u32string s1 = U"Gammasoft";
    /// ustring s2 = string_converter::to_ustring(s1);
    /// @endcode
    static xtd::ustring to_ustring(const std::u32string& str) noexcept;
    /// @brief Converts const char32_t* to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const char32_t* c1 = U"Gammasoft";
    /// ustring s1 = string_converter::to_ustring(c1);
    /// @endcode
    static xtd::ustring to_ustring(const char32_t* str) noexcept;
    /// @brief Converts char32_t* to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// char32_t* c1 = U"Gammasoft";
    /// ustring s1 = string_converter::to_ustring(c1);
    /// @endcode
    static xtd::ustring to_ustring(char32_t* str) noexcept;
    /// @brief Converts std::wstring to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// wstring s1 = L"Gammasoft";
    /// ustring s2 = string_converter::to_ustring(s1);
    /// @endcode
    static xtd::ustring to_ustring(const std::wstring& str) noexcept;
    /// @brief Converts const wchar_t* to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const wchar_t* c1 = L"Gammasoft";
    /// ustring s1 = string_converter::to_ustring(c1);
    /// @endcode
    static xtd::ustring to_ustring(const wchar_t* str) noexcept;
    /// @brief Converts wchar_t* to xtd::ustring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// wchar_t* c1 = L"Gammasoft";
    /// ustring s1 = string_converter::to_ustring(c1);
    /// @endcode
    static xtd::ustring to_ustring(wchar_t* str) noexcept;

    /// @brief Converts std::string to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// string s1 = "Gammasoft";
    /// u8string s2 = string_converter::to_u8string(s1);
    /// @endcode
    static std::u8string to_u8string(const std::string& str) noexcept;
    /// @brief Converts const char* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const char* c1 = "Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// @endcode
    static std::u8string to_u8string(const char* str) noexcept;
    /// @brief Converts char* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// char* c1 = "Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// @endcode
    static std::u8string to_u8string(char* str) noexcept;
    /// @brief Converts xtd::ustring to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// ustring s1 = "Gammasoft";
    /// u8string s2 = string_converter::to_u8string(s1);
    /// @endcode
    static std::u8string to_u8string(const xtd::ustring& str) noexcept;
    /// @brief Converts std::u8string to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// u8string s1 = u8"Gammasoft";
    /// u8string s2 = string_converter::to_u8string(s1);
    /// @endcode
    static const std::u8string& to_u8string(const std::u8string& str) noexcept;
    /// @brief Converts const char8_t* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const char8_t* c1 = u8"Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// @endcode
    static std::u8string to_u8string(const char8_t* str) noexcept;
    /// @brief Converts char8_t* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    static std::u8string to_u8string(char8_t* str) noexcept;
    /// @brief Converts std::u16string to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// u16string s1 = u"Gammasoft";
    /// u8string s2 = string_converter::to_u8string(s1);
    /// @endcode
    static std::u8string to_u8string(const std::u16string& str) noexcept;
    /// @brief Converts const char16_t* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const char16_t* c1 = u"Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// @endcode
    static std::u8string to_u8string(const char16_t* str) noexcept;
    /// @brief Converts char16_t* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// char16_t* c1 = u"Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// @endcode
    static std::u8string to_u8string(char16_t* str) noexcept;
    /// @brief Converts std::u32string to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// u32string s1 = U"Gammasoft";
    /// u8string s2 = string_converter::to_8ustring(s1);
    /// @endcode
    static std::u8string to_u8string(const std::u32string& str) noexcept;
    /// @brief Converts const char32_t* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const char32_t* c1 = U"Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// @endcode
    static std::u8string to_u8string(const char32_t* str) noexcept;
    /// @brief Converts char32_t* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// char32_t* c1 = U"Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// @endcode
    static std::u8string to_u8string(char32_t* str) noexcept;
    /// @brief Converts std::wstring to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// wstring s1 = L"Gammasoft";
    /// u8string s2 = string_converter::to_u8string(s1);
    /// @endcode
    static std::u8string to_u8string(const std::wstring& str) noexcept;
    /// @brief Converts const wchar_t* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const wchar_t* c1 = L"Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// @endcode
    static std::u8string to_u8string(const wchar_t* str) noexcept;
    /// @brief Converts wchar_t* to std::u8string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// wchar_t* c1 = L"Gammasoft";
    /// u8string s1 = string_converter::to_u8string(c1);
    /// @endcode
    static std::u8string to_u8string(wchar_t* str) noexcept;

    /// @brief Converts std::string to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// string s1 = "Gammasoft";
    /// u16string s2 = string_converter::to_u16string(s1);
    /// @endcode
    static std::u16string to_u16string(const std::string& str) noexcept;
    /// @brief Converts const char* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const char* c1 = "Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// @endcode
    static std::u16string to_u16string(const char* str) noexcept;
    /// @brief Converts char* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// char* c1 = "Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// @endcode
    static std::u16string to_u16string(char* str) noexcept;
    /// @brief Converts xtd::ustring to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// ustring s1 = "Gammasoft";
    /// u16string s2 = string_converter::to_u16string(s1);
    /// @endcode
    static std::u16string to_u16string(const xtd::ustring& str) noexcept;
    /// @brief Converts std::u8string to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// u8string s1 = u8"Gammasoft";
    /// u16string s2 = string_converter::to_u16string(s1);
    /// @endcode
    static std::u16string to_u16string(const std::u8string& str) noexcept;
    /// @brief Converts const char8_t* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const char8_t* c1 = u8"Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// @endcode
    static std::u16string to_u16string(const char8_t* str) noexcept;
    /// @brief Converts char8_t* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// char8_t* c1 = u8"Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// @endcode
    static std::u16string to_u16string(char8_t* str) noexcept;
    /// @brief Converts std::u16string to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// u16string s1 = u"Gammasoft";
    /// u16string s2 = string_converter::to_u16string(s1);
    /// @endcode
    static const std::u16string& to_u16string(const std::u16string& str) noexcept;
    /// @brief Converts const char16_t* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const char16_t* c1 = u"Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// @endcode
    static std::u16string to_u16string(const char16_t* str) noexcept;
    /// @brief Converts char16_t* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// char16_t* c1 = u"Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// @endcode
    static std::u16string to_u16string(char16_t* str) noexcept;
    /// @brief Converts std::u32string to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// u32string s1 = U"Gammasoft";
    /// u16string s2 = string_converter::to_u16string(s1);
    /// @endcode
    static std::u16string to_u16string(const std::u32string& str) noexcept;
    /// @brief Converts const char32_t* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const char32_t* c1 = U"Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// @endcode
    static std::u16string to_u16string(const char32_t* str) noexcept;
    /// @brief Converts char32_t* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// char32_t* c1 = "Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// @endcode
    static std::u16string to_u16string(char32_t* str) noexcept;
    /// @brief Converts std::wstring to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// wstring s1 = L"Gammasoft";
    /// u16string s2 = string_converter::to_u16string(s1);
    /// @endcode
    static std::u16string to_u16string(const std::wstring& str) noexcept;
    /// @brief Converts const wchar_t* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const wchar_t* c1 = L"Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// @endcode
    static std::u16string to_u16string(const wchar_t* str) noexcept;
    /// @brief Converts wchar_t* to std::u16string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// wchar_t* c1 = L"Gammasoft";
    /// u16string s1 = string_converter::to_u16string(c1);
    /// @endcode
    static std::u16string to_u16string(wchar_t* str) noexcept;

    /// @brief Converts std::string to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// string s1 = "Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// @endcode
    static std::u32string to_u32string(const std::string& str) noexcept;
    /// @brief Converts const char* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const char* c1 = "Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// @endcode
    static std::u32string to_u32string(const char* str) noexcept;
    /// @brief Converts char* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// char* c1 = "Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// @endcode
    static std::u32string to_u32string(char* str) noexcept;
    /// @brief Converts xtd::ustring to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// ustring s1 = "Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// @endcode
    static std::u32string to_u32string(const xtd::ustring& str) noexcept;
    /// @brief Converts std::u8string to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// u8string s1 = u8"Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// @endcode
    static std::u32string to_u32string(const std::u8string& str) noexcept;
    /// @brief Converts const char8_t* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const char8_t* c1 = u8"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// @endcode
    static std::u32string to_u32string(const char8_t* str) noexcept;
    /// @brief Converts char8_t* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// char8_t* c1 = u8"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// @endcode
    static std::u32string to_u32string(char8_t* str) noexcept;
    /// @brief Converts std::u16string to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// u16string s1 = u"Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// @endcode
    static std::u32string to_u32string(const std::u16string& str) noexcept;
    /// @brief Converts const char16_t* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const char16_t* c1 = u"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// @endcode
    static std::u32string to_u32string(const char16_t* str) noexcept;
    /// @brief Converts char16_t* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// char16_t* c1 = u"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// @endcode
    static std::u32string to_u32string(char16_t* str) noexcept;
    /// @brief Converts std::u32string to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// u32string s1 = U"Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// @endcode
    static const std::u32string& to_u32string(const std::u32string& str) noexcept;
    /// @brief Converts const char32_t* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const char32_t* c1 = U"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// @endcode
    static std::u32string to_u32string(const char32_t* str) noexcept;
    /// @brief Converts char32_t* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// char32_t* c1 = U"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// @endcode
    static std::u32string to_u32string(char32_t* str) noexcept;
    /// @brief Converts std::wstring to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// wstring s1 = L"Gammasoft";
    /// u32string s2 = string_converter::to_u32string(s1);
    /// @endcode
    static std::u32string to_u32string(const std::wstring& str) noexcept;
    /// @brief Converts const wchar_t* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const wchar_t* c1 = L"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// @endcode
    static std::u32string to_u32string(const wchar_t* str) noexcept;
    /// @brief Converts wchar_t* to std::u32string.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// wchar_t* c1 = L"Gammasoft";
    /// u32string s1 = string_converter::to_u32string(c1);
    /// @endcode
    static std::u32string to_u32string(wchar_t* str) noexcept;

    /// @brief Converts std::string to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// string s1 = "Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// @endcode
    static std::wstring to_wstring(const std::string& str) noexcept;
    /// @brief Converts const char* to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const char* c1 = "Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// @endcode
    static std::wstring to_wstring(const char* str) noexcept;
    /// @brief Converts char* to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// char* c1 = "Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// @endcode
    static std::wstring to_wstring(char* str) noexcept;
    /// @brief Converts xtd::ustring to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// ustring s1 = "Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// @endcode
    static std::wstring to_wstring(const xtd::ustring& str) noexcept;
    /// @brief Converts std::u8string to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// u8string s1 = u8"Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// @endcode
    static std::wstring to_wstring(const std::u8string& str) noexcept;
    /// @brief Converts const char8_t* to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const char8_t* c1 = u8"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// @endcode
    static std::wstring to_wstring(const char8_t* str) noexcept;
    /// @brief Converts char8_t* to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// char8_t* c1 = u8"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// @endcode
    static std::wstring to_wstring(char8_t* str) noexcept;
    /// @brief Converts std::u16string to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// u16string s1 = u"Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// @endcode
    static std::wstring to_wstring(const std::u16string& str) noexcept;
    /// @brief Converts const char16_t* to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const char16_t* c1 = u"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// @endcode
    static std::wstring to_wstring(const char16_t* str) noexcept;
    /// @brief Converts char16_t* to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// char16_t* c1 = u"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// @endcode
    static std::wstring to_wstring(char16_t* str) noexcept;
    /// @brief Converts std::u32string to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// u32string s1 = U"Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// @endcode
    static std::wstring to_wstring(const std::u32string& str) noexcept;
    /// @brief Converts const char32_t* to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const char32_t* c1 = U"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// @endcode
    static std::wstring to_wstring(const char32_t* str) noexcept;
    /// @brief Converts char32_t* to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// char32_t* c1 = U"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// @endcode
    static std::wstring to_wstring(char32_t* str) noexcept;
    /// @brief Converts std::wstring to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @par Examples
    /// @code
    /// wstring s1 = L"Gammasoft";
    /// wstring s2 = string_converter::to_wstring(s1);
    /// @endcode
    static const std::wstring& to_wstring(const std::wstring& str) noexcept;
    /// @brief Converts const wchar_t* to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// const wchar_t* c1 = L"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// @endcode
    static std::wstring to_wstring(const wchar_t* str) noexcept;
    /// @brief Converts wchar_t* to std::wstring.
    /// @param str string to convert.
    /// @return The converted string.
    /// @remarks This method is used to convert string container to another.
    /// @warning The content of the string must be encoded in UTF-8 (65001) format. Make sure it is, otherwise the result will be uncertain.
    /// @code
    /// wchar_t* c1 = L"Gammasoft";
    /// wstring s1 = string_converter::to_wstring(c1);
    /// @endcode
    static std::wstring to_wstring(wchar_t* str) noexcept;
  };
 
  /// @brief Casts a type into another type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string s1 = "Gammasoft";
  /// object o1 = as<object>(s1);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(const std::string& value) {
    try {
      return dynamic_cast<const new_type_t&>(value);
    } catch (const std::exception& e) {
      throw invalid_cast_exception(e.what(), csf_);
    }
    throw std::bad_cast();
  }

  /// @brief Casts a type into another type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string s1 = "Gammasoft";
  /// string s2 = as<string>(s1);
  /// @endcode
  template<>
  inline std::string as<std::string>(const std::string& value) {
    return convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string s1 = "Gammasoft";
  /// ustring s2 = as<ustring>(s1);
  /// @endcode
  template<>
  inline xtd::ustring as<xtd::ustring>(const std::string& value) {
    return convert_string::to_ustring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string s1 = "Gammasoft";
  /// u8string s2 = as<u8string>(s1);
  /// @endcode
  template<>
  inline std::u8string as<std::u8string>(const std::string& value) {
    return convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string s1 = "Gammasoft";
  /// u16string s2 = as<u16string>(s1);
  /// @endcode
  template<>
  inline std::u16string as<std::u16string>(const std::string& value) {
    return convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string s1 = "Gammasoft";
  /// u32string s2 = as<u32string>(s1);
  /// @endcode
  template<>
  inline std::u32string as<std::u32string>(const std::string& value) {
    return convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string s1 = "Gammasoft";
  /// wstring s2 = as<wstring>(s1);
  /// @endcode
  template<>
  inline std::wstring as<std::wstring>(const std::string& value) {
    return convert_string::to_wstring(value);
  }

  /// @brief Casts a type into another type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* c1 = "Gammasoft";
  /// intptr_t handle = as<intptr_t>(c1);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(const char* value) {
    return reinterpret_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* c1 = "Gammasoft";
  /// string s1 = as<string>(c1);
  /// @endcode
  template<>
  inline std::string as<std::string>(const char* value) {
    return convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* c1 = "Gammasoft";
  /// ustring s1 = as<ustring>(c1);
  /// @endcode
  template<>
  inline xtd::ustring as<xtd::ustring>(const char* value) {
    return convert_string::to_ustring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* c1 = "Gammasoft";
  /// u8string s1 = as<u8string>(c1);
  /// @endcode
  template<>
  inline std::u8string as<std::u8string>(const char* value) {
    return convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* c1 = "Gammasoft";
  /// u16string s1 = as<u16string>(c1);
  /// @endcode
  template<>
  inline std::u16string as<std::u16string>(const char* value) {
    return convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* c1 = "Gammasoft";
  /// u32string s1 = as<u32string>(c1);
  /// @endcode
  template<>
  inline std::u32string as<std::u32string>(const char* value) {
    return convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* c1 = "Gammasoft";
  /// wstring s1 = as<wstring>(c1);
  /// @endcode
  template<>
  inline std::wstring as<std::wstring>(const char* value) {
    return convert_string::to_wstring(value);
  }

  /// @brief Casts a type into another type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* c1 = "Gammasoft";
  /// intptr_t handle = as<intptr_t>(c1);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(char* value) {
    return reinterpret_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* c1 = "Gammasoft";
  /// string s1 = as<string>(c1);
  /// @endcode
  template<>
  inline std::string as<std::string>(char* value) {
    return convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* c1 = "Gammasoft";
  /// ustring s1 = as<ustring>(c1);
  /// @endcode
  template<>
  inline xtd::ustring as<xtd::ustring>(char* value) {
    return convert_string::to_ustring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* c1 = "Gammasoft";
  /// u8string s1 = as<u8string>(c1);
  /// @endcode
  template<>
  inline std::u8string as<std::u8string>(char* value) {
    return convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* c1 = "Gammasoft";
  /// u16string s1 = as<u16string>(c1);
  /// @endcode
  template<>
  inline std::u16string as<std::u16string>(char* value) {
    return convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* c1 = "Gammasoft";
  /// u32string s1 = as<u32string>(c1);
  /// @endcode
  template<>
  inline std::u32string as<std::u32string>(char* value) {
    return convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* c1 = "Gammasoft";
  /// wstring s1 = as<wstring>(c1);
  /// @endcode
  template<>
  inline std::wstring as<std::wstring>(char* value) {
    return convert_string::to_wstring(value);
  }

}
