/// @file
/// @brief Contains __format_stringer methods.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <chrono>
#include <cctype>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <locale>
#include <map>
#include <sstream>
#include <string>
#include <vector>

/// @cond
namespace xtd {
  class ustring;

  template<typename value_t>
  inline std::string to_string(const value_t& value, const std::string& fmt, const std::locale& loc);
  template<>
  inline std::string to_string(const bool& value, const std::string& fmt, const std::locale& loc);
  template<>
  inline std::string to_string(const int8_t& value, const std::string& fmt, const std::locale& loc);
  template<>
  inline std::string to_string(const char& value, const std::string& fmt, const std::locale& loc);
  template<>
  inline std::string to_string(const unsigned char& value, const std::string& fmt, const std::locale& loc);
  template<>
  inline std::string to_string(const short& value, const std::string& fmt, const std::locale& loc);
  template<>
  inline std::string to_string(const unsigned short& value, const std::string& fmt, const std::locale& loc);
  template<>
  inline std::string to_string(const int& value, const std::string& fmt, const std::locale& loc);
  template<>
  inline std::string to_string(const unsigned int& value, const std::string& fmt, const std::locale& loc);
  template<>
  inline std::string to_string(const long& value, const std::string& fmt, const std::locale& loc);
  template<>
  inline std::string to_string(const unsigned long& value, const std::string& fmt, const std::locale& loc);
  template<>
  inline std::string to_string(const long long& value, const std::string& fmt, const std::locale& loc);
  template<>
  inline std::string to_string(const unsigned long long& value, const std::string& fmt, const std::locale& loc);
  template<>
  inline std::string to_string(const float& value, const std::string& fmt, const std::locale& loc);
  template<>
  inline std::string to_string(const double& value, const std::string& fmt, const std::locale& loc);
  template<>
  inline std::string to_string(const long double& value, const std::string& fmt, const std::locale& loc);
  template<>
  inline std::string to_string(const std::chrono::system_clock::time_point& value, const std::string& fmt, const std::locale& loc);
  template<>
  inline std::string to_string(const std::tm& value, const std::string& fmt, const std::locale& loc);
  template<typename type_t, typename period_t = std::ratio<1>>
  inline std::string to_string(const std::chrono::duration<type_t, period_t>& value, const std::string& fmt, const std::locale& loc);
  template<>
  inline std::string to_string(const char8_t& value, const std::string& fmt, const std::locale& loc);
  template<>
  inline std::string to_string(const char16_t& value, const std::string& fmt, const std::locale& loc);
  template<>
  inline std::string to_string(const char32_t& value, const std::string& fmt, const std::locale& loc);
  template<>
  inline std::string to_string(const wchar_t& value, const std::string& fmt, const std::locale& loc);

  template<typename value_t>
  inline std::wstring to_string(const value_t& value, const std::wstring& fmt, const std::locale& loc);
  template<>
  inline std::wstring to_string(const bool& value, const std::wstring& fmt, const std::locale& loc);
  template<>
  inline std::wstring to_string(const int8_t& value, const std::wstring& fmt, const std::locale& loc);
  template<>
  inline std::wstring to_string(const char& value, const std::wstring& fmt, const std::locale& loc);
  template<>
  inline std::wstring to_string(const unsigned char& value, const std::wstring& fmt, const std::locale& loc);
  template<>
  inline std::wstring to_string(const short& value, const std::wstring& fmt, const std::locale& loc);
  template<>
  inline std::wstring to_string(const unsigned short& value, const std::wstring& fmt, const std::locale& loc);
  template<>
  inline std::wstring to_string(const int& value, const std::wstring& fmt, const std::locale& loc);
  template<>
  inline std::wstring to_string(const unsigned int& value, const std::wstring& fmt, const std::locale& loc);
  template<>
  inline std::wstring to_string(const long& value, const std::wstring& fmt, const std::locale& loc);
  template<>
  inline std::wstring to_string(const unsigned long& value, const std::wstring& fmt, const std::locale& loc);
  template<>
  inline std::wstring to_string(const long long& value, const std::wstring& fmt, const std::locale& loc);
  template<>
  inline std::wstring to_string(const unsigned long long& value, const std::wstring& fmt, const std::locale& loc);
  template<>
  inline std::wstring to_string(const float& value, const std::wstring& fmt, const std::locale& loc);
  template<>
  inline std::wstring to_string(const double& value, const std::wstring& fmt, const std::locale& loc);
  template<>
  inline std::wstring to_string(const long double& value, const std::wstring& fmt, const std::locale& loc);
  template<>
  inline std::wstring to_string(const std::chrono::system_clock::time_point& value, const std::wstring& fmt, const std::locale& loc);
  template<>
  inline std::wstring to_string(const std::tm& value, const std::wstring& fmt, const std::locale& loc);
  
  template<typename type_t, typename period_t = std::ratio<1>>
  inline std::wstring to_string(const std::chrono::duration<type_t, period_t>& value, const std::wstring& fmt, const std::locale& loc);
  template<>
  inline std::wstring to_string(const char8_t& value, const std::wstring& fmt, const std::locale& loc);
  template<>
  inline std::wstring to_string(const char16_t& value, const std::wstring& fmt, const std::locale& loc);
  template<>
  inline std::wstring to_string(const char32_t& value, const std::wstring& fmt, const std::locale& loc);
  template<>
  inline std::wstring to_string(const wchar_t& value, const std::wstring& fmt, const std::locale& loc);

  template<typename type_t, typename string_t>
  inline string_t to_string(type_t value, const std::map<type_t, string_t, std::greater<type_t>>& values) {
    auto it = values.find(value);
    if (it != values.end()) return it->second;
    string_t result;
    long long rest = static_cast<long long>(value);
    for (auto item : values) {
      if (static_cast<long long>(item.first) != 0 && (rest & static_cast<long long>(item.first)) == static_cast<long long>(item.first)) {
        if (!result.empty()) result = string_t {',', ' '} + result;
        result = item.second + result;
        rest -= static_cast<long long>(item.first);
      }
    }
    if (!result.empty()) return result;
    return to_string(static_cast<long long>(value), string_t {'G'}, std::locale());
  }
  
  template<typename type_t, typename string_t>
  inline string_t to_string(type_t value, const std::map<type_t, string_t>& values) {
    std::map<type_t, string_t, std::greater<type_t>> descending_values;
    for(auto item : values) descending_values[item.first] = item.second;
    return to_string(value, descending_values);
  }
  
  template<typename type_t>
  inline std::string to_string(type_t value, const std::initializer_list<std::pair<type_t, std::string>>& il) {
    std::map<type_t, std::string, std::greater<type_t>> values;
    for(auto item : il) values[item.first] = item.second;
    return to_string(value, values);
  }
  
  template<typename type_t>
  inline std::wstring to_string(type_t value, const std::initializer_list<std::pair<type_t, std::wstring>>& il) {
    std::map<type_t, std::wstring, std::greater<type_t>> values;
    for(auto item : il) values[item.first] = item.second;
    return to_string(value, values);
  }
}

template<typename char_t>
inline std::basic_string<char_t> __codepoint_to_string(char32_t codepoint) {
  std::basic_string<char_t> result;
  if (codepoint < 0x80) {
    result.push_back(static_cast<char_t>(codepoint));
  }
  else  if (codepoint < 0x800) {
    result.push_back(static_cast<char_t>((codepoint >> 6) | 0xc0));
    result.push_back(static_cast<char_t>((codepoint & 0x3f) | 0x80));
  }
  else if (codepoint < 0x10000) {
    result.push_back(static_cast<char_t>((codepoint >> 12) | 0xe0));
    result.push_back(static_cast<char_t>(((codepoint >> 6) & 0x3f) | 0x80));
    result.push_back(static_cast<char_t>((codepoint & 0x3f) | 0x80));
  }
  else {
    result.push_back(static_cast<char_t>((codepoint >> 18) | 0xf0));
    result.push_back(static_cast<char_t>(((codepoint >> 12) & 0x3f) | 0x80));
    result.push_back(static_cast<char_t>(((codepoint >> 6) & 0x3f) | 0x80));
    result.push_back(static_cast<char_t>((codepoint & 0x3f) | 0x80));
  }
  return result;
}

template<typename char_t>
inline std::basic_string<char_t> __to_string(char codepoint) {
  return __codepoint_to_string<char_t>(codepoint);
}

template<typename char_t>
inline std::basic_string<char_t> __to_string(char32_t codepoint) {
  return __codepoint_to_string<char_t>(codepoint);
}

template<typename char_t>
inline std::basic_string<char_t> __to_string(char16_t codepoint) {
  return __codepoint_to_string<char_t>(codepoint);
}

template<typename char_t>
inline std::basic_string<char_t> __to_string(char8_t codepoint) {
  return __codepoint_to_string<char_t>(codepoint);
}

template<typename char_t>
inline std::basic_string<char_t> __to_string(wchar_t codepoint) {
  return __codepoint_to_string<char_t>(codepoint);
}

template<typename char_t>
inline std::basic_string<char_t> __to_string(const std::basic_string<char_t>& str) {
  std::basic_string<char_t> result;
  for (auto codepoint : str)
    result += __to_string<char_t>(codepoint);
  return result;
}

template<typename char_t, typename arg_t>
inline std::basic_string<char_t> __to_string(const std::basic_string<arg_t>& str) {
  std::basic_string<char_t> result;
  for (auto codepoint : str)
    result += __to_string<char_t>(codepoint);
  return result;
}

template<typename char_t, typename arg_t>
inline std::basic_string<char_t> __to_string(const arg_t* str) {
  std::basic_string<char_t> result;
  for (auto codepoint : std::basic_string<arg_t>(str))
    result += __to_string<char_t>(codepoint);
  return result;
}

template<typename char_t, typename type_t, typename period_t = std::ratio<1>>
std::basic_ostream<char_t>& operator<<(std::basic_ostream<char_t>& os, const std::chrono::duration<type_t, period_t>& value) {
  return os << xtd::to_string(value, std::basic_string<char_t> {'G'}, std::locale());
}

template<typename value_t>
std::string __format_stringer_to_std_string(value_t value) {
  std::basic_stringstream<char> ss;
  ss << value;
  return ss.str();
}

std::string __format_stringer_to_std_string(const char* str);
std::string __format_stringer_to_std_string(const char8_t* str);
std::string __format_stringer_to_std_string(const char16_t* str);
std::string __format_stringer_to_std_string(const char32_t* str);
std::string __format_stringer_to_std_string(const wchar_t* str);
std::string __format_stringer_to_std_string(const std::string& str);
std::string __format_stringer_to_std_string(const xtd::ustring& str);
std::string __format_stringer_to_std_string(const std::u8string& str);
std::string __format_stringer_to_std_string(const std::u16string& str);
std::string __format_stringer_to_std_string(const std::u32string& str);
std::string __format_stringer_to_std_string(const std::wstring& str);

template<typename char_t, typename value_t>
inline std::basic_string<char_t> __format_stringer(value_t value) {
  std::basic_stringstream<char_t> ss;
  ss << __format_stringer_to_std_string(value).c_str();
  return ss.str();
}

template<typename char_t, typename value_t, int32_t len>
inline std::basic_string<char_t> __format_stringer(const char*& value) {
  std::basic_stringstream<char_t> ss;
  ss << __to_string<char_t>(value);
  return ss.str();
}

template<typename char_t, typename value_t, int32_t len>
inline std::basic_string<char_t> __format_stringer(const char* const& value) {
  std::basic_stringstream<char_t> ss;
  ss << __to_string<char_t>(value);
  return ss.str();
}

template<typename char_t, typename value_t>
inline std::basic_string<char_t> __format_stringer(const char8_t*& value) {
  auto s = std::u8string(value);
  std::basic_stringstream<char_t> ss;
  ss << std::basic_string<char_t>(s.begin(), s.end());
  return ss.str();
}

template<typename char_t, typename value_t>
inline std::basic_string<char_t> __format_stringer(const char8_t* const& value) {
  auto s = std::u8string(value);
  std::basic_stringstream<char_t> ss;
  ss << std::basic_string<char_t>(s.begin(), s.end());
  return ss.str();
}

template<typename char_t, typename value_t>
inline std::basic_string<char_t> __format_stringer(const char16_t*& value) {
  std::basic_stringstream<char_t> ss;
  ss << __to_string<char_t>(value);
  return ss.str();
}

template<typename char_t, typename value_t>
inline std::basic_string<char_t> __format_stringer(const char16_t* const& value) {
  std::basic_stringstream<char_t> ss;
  ss << __to_string<char_t>(value);
  return ss.str();
}

template<typename char_t, typename value_t>
inline std::basic_string<char_t> __format_stringer(const char32_t*& value) {
  std::basic_stringstream<char_t> ss;
  ss << __to_string<char_t>(value);
  return ss.str();
}

template<typename char_t, typename value_t>
inline std::basic_string<char_t> __format_stringer(const char32_t* const& value) {
  std::basic_stringstream<char_t> ss;
  ss << __to_string<char_t>(value);
  return ss.str();
}

template<typename char_t, typename value_t>
inline std::basic_string<char_t> __format_stringer(const wchar_t*& value) {
  std::basic_stringstream<char_t> ss;
  ss << __to_string<char_t>(value);
  return ss.str();
}

template<typename char_t, typename value_t>
inline std::basic_string<char_t> __format_stringer(const wchar_t* const& value) {
  std::basic_stringstream<char_t> ss;
  ss << __to_string<char_t>(value);
  return ss.str();
}

template<>
inline std::string __format_stringer<char, std::u8string&>(std::u8string& value) {
  std::basic_stringstream<char> ss;
  ss << std::string(value.begin(), value.end());
  return ss.str();
}

template<>
inline std::string __format_stringer<char, std::u16string&>(std::u16string& value) {
  std::basic_stringstream<char> ss;
  ss << __to_string<char>(value);
  return ss.str();
}

template<>
inline std::string __format_stringer<char, std::u32string&>(std::u32string& value) {
  std::basic_stringstream<char> ss;
  ss << __to_string<char>(value);
  return ss.str();
}

template<>
inline std::string __format_stringer<char, std::wstring&>(std::wstring& value) {
  std::basic_stringstream<char> ss;
  ss << __to_string<char>(value);
  return ss.str();
}

template<>
inline std::string __format_stringer<char, bool&>(bool& value) {
  return xtd::to_string(value, "G", std::locale());
}

template<>
inline std::string __format_stringer<char, int8_t&>(int8_t& value) {
  return xtd::to_string(value, "G", std::locale());
}

template<>
inline std::string __format_stringer<char, unsigned char&>(unsigned char& value) {
  return xtd::to_string(value, "G", std::locale());
}

template<>
inline std::string __format_stringer<char, short&>(short& value) {
  return xtd::to_string(value, "G", std::locale());
}

template<>
inline std::string __format_stringer<char, unsigned short&>(unsigned short& value) {
  return xtd::to_string(value, "G", std::locale());
}

template<>
inline std::string __format_stringer<char, int&>(int& value) {
  return xtd::to_string(value, "G", std::locale());
}

template<>
inline std::string __format_stringer<char, unsigned int&>(unsigned int& value) {
  return xtd::to_string(value, "G", std::locale());
}

template<>
inline std::string __format_stringer<char, long&>(long& value) {
  return xtd::to_string(value, "G", std::locale());
}

template<>
inline std::string __format_stringer<char, unsigned long&>(unsigned long& value) {
  return xtd::to_string(value, "G", std::locale());
}

template<>
inline std::string __format_stringer<char, long long&>(long long& value) {
  return xtd::to_string(value, "G", std::locale());
}

template<>
inline std::string __format_stringer<char, unsigned long long&>(unsigned long long& value) {
  return xtd::to_string(value, "G", std::locale());
}

template<>
inline std::string __format_stringer<char, float&>(float& value) {
  return xtd::to_string(value, "G", std::locale());
}

template<>
inline std::string __format_stringer<char, double&>(double& value) {
  return xtd::to_string(value, "G", std::locale());
}

template<>
inline std::string __format_stringer<char, long double&>(long double& value) {
  return xtd::to_string(value, "G", std::locale());
}

template<>
inline std::string __format_stringer<char, std::chrono::system_clock::time_point&> (std::chrono::system_clock::time_point& value) {
  return xtd::to_string(value, "G", std::locale());
}

template<>
inline std::string __format_stringer<char, std::tm&> (tm& value) {
  return xtd::to_string(value, "G", std::locale());
}

template<>
inline std::string __format_stringer<char, wchar_t&>(wchar_t& value) {
  return xtd::to_string(value, "G", std::locale());
}

template<>
inline std::string __format_stringer<char, char8_t&>(char8_t& value) {
  return xtd::to_string(value, "G", std::locale());
}

template<>
inline std::string __format_stringer<char, char16_t&>(char16_t& value) {
  return xtd::to_string(value, "G", std::locale());
}

template<>
inline std::string __format_stringer<char, char32_t&>(char32_t& value) {
  return xtd::to_string(value, "G", std::locale());
}

template<>
inline std::wstring __format_stringer<wchar_t, std::u8string&>(std::u8string& value) {
  std::basic_stringstream<wchar_t> ss;
  ss << std::wstring(value.begin(), value.end());
  return ss.str();
}

template<>
inline std::wstring __format_stringer<wchar_t, std::u16string&>(std::u16string& value) {
  std::basic_stringstream<wchar_t> ss;
  ss << __to_string<wchar_t>(value);
  return ss.str();
}

template<>
inline std::wstring __format_stringer<wchar_t, std::u32string&>(std::u32string& value) {
  std::basic_stringstream<wchar_t> ss;
  ss << __to_string<wchar_t>(value);
  return ss.str();
}

template<>
inline std::wstring __format_stringer<wchar_t, std::string&>(std::string& value) {
  std::basic_stringstream<wchar_t> ss;
  ss << __to_string<wchar_t>(value);
  return ss.str();
}

template<>
inline std::wstring __format_stringer<wchar_t, bool&>(bool& value) {
  return xtd::to_string(value, L"G", std::locale());
}

template<>
inline std::wstring __format_stringer<wchar_t, int8_t&>(int8_t& value) {
  return xtd::to_string(value, L"G", std::locale());
}

template<>
inline std::wstring __format_stringer<wchar_t, char&>(char& value) {
  return xtd::to_string(value, L"G", std::locale());
}

template<>
inline std::wstring __format_stringer<wchar_t, unsigned char&>(unsigned char& value) {
  return xtd::to_string(value, L"G", std::locale());
}

template<>
inline std::wstring __format_stringer<wchar_t, short&>(short& value) {
  return xtd::to_string(value, L"G", std::locale());
}

template<>
inline std::wstring __format_stringer<wchar_t, unsigned short&>(unsigned short& value) {
  return xtd::to_string(value, L"G", std::locale());
}

template<>
inline std::wstring __format_stringer<wchar_t, int&>(int& value) {
  return xtd::to_string(value, L"G", std::locale());
}

template<>
inline std::wstring __format_stringer<wchar_t, unsigned int&>(unsigned int& value) {
  return xtd::to_string(value, L"G", std::locale());
}

template<>
inline std::wstring __format_stringer<wchar_t, long&>(long& value) {
  return xtd::to_string(value, L"G", std::locale());
}

template<>
inline std::wstring __format_stringer<wchar_t, unsigned long&>(unsigned long& value) {
  return xtd::to_string(value, L"G", std::locale());
}

template<>
inline std::wstring __format_stringer<wchar_t, long long&>(long long& value) {
  return xtd::to_string(value, L"G", std::locale());
}

template<>
inline std::wstring __format_stringer<wchar_t, unsigned long long&>(unsigned long long& value) {
  return xtd::to_string(value, L"G", std::locale());
}

template<>
inline std::wstring __format_stringer<wchar_t, float&>(float& value) {
  return xtd::to_string(value, L"G", std::locale());
}

template<>
inline std::wstring __format_stringer<wchar_t, double&>(double& value) {
  return xtd::to_string(value, L"G", std::locale());
}

template<>
inline std::wstring __format_stringer<wchar_t, long double&>(long double& value) {
  return xtd::to_string(value, L"G", std::locale());
}

template<>
inline std::wstring __format_stringer<wchar_t, std::chrono::system_clock::time_point&> (std::chrono::system_clock::time_point& value) {
  return xtd::to_string(value, L"G", std::locale());
}

template<>
inline std::wstring __format_stringer<wchar_t, std::tm&> (tm& value) {
  return xtd::to_string(value, L"G", std::locale());
}
/// @endcond
