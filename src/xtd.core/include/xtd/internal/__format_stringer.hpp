/// @file
/// @brief Contains __format_stringer methods.
#pragma once

#define __XTD_STD_INTERNAL__
#include "__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__
#include "__string_definitions.hpp"
#include "../collections/generic/ienumerable.hpp"
#include "../any.hpp"
#include "../chrono.hpp"
#include "../optional.hpp"
#include "../types.hpp"
#include <algorithm>
#include <array>
#include <cctype>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <forward_list>
#include <functional>
#include <iomanip>
#include <iostream>
#include <locale>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <system_error>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

/// @cond
namespace xtd {
  class iformatable;
  class object;
  using string = basic_string<char>;
  namespace globalization {
    class culture_info;
  }
}

template<class char_t>
inline std::basic_string<char_t> __codepoint_to_string(xtd::char32 codepoint) {
  std::basic_string<char_t> result;
  if (codepoint < 0x80)
    result.push_back(static_cast<char_t>(codepoint));
  else  if (codepoint < 0x800) {
    result.push_back(static_cast<char_t>((codepoint >> 6) | 0xc0));
    result.push_back(static_cast<char_t>((codepoint & 0x3f) | 0x80));
  } else if (codepoint < 0x10000) {
    result.push_back(static_cast<char_t>((codepoint >> 12) | 0xe0));
    result.push_back(static_cast<char_t>(((codepoint >> 6) & 0x3f) | 0x80));
    result.push_back(static_cast<char_t>((codepoint & 0x3f) | 0x80));
  } else {
    result.push_back(static_cast<char_t>((codepoint >> 18) | 0xf0));
    result.push_back(static_cast<char_t>(((codepoint >> 12) & 0x3f) | 0x80));
    result.push_back(static_cast<char_t>(((codepoint >> 6) & 0x3f) | 0x80));
    result.push_back(static_cast<char_t>((codepoint & 0x3f) | 0x80));
  }
  return result;
}

template<class char_t>
inline std::basic_string<char_t> __to_string(char codepoint) {
  return __codepoint_to_string<char_t>(codepoint);
}

template<class char_t>
inline std::basic_string<char_t> __to_string(xtd::char32 codepoint) {
  return __codepoint_to_string<char_t>(codepoint);
}

template<class char_t>
inline std::basic_string<char_t> __to_string(xtd::char16 codepoint) {
  return __codepoint_to_string<char_t>(codepoint);
}

template<class char_t>
inline std::basic_string<char_t> __to_string(xtd::char8 codepoint) {
  return __codepoint_to_string<char_t>(codepoint);
}

template<class char_t>
inline std::basic_string<char_t> __to_string(xtd::wchar codepoint) {
  return __codepoint_to_string<char_t>(codepoint);
}

template<class char_t>
inline std::basic_string<char_t> __to_string(const std::basic_string<char_t>& str) {
  std::basic_string<char_t> result;
  std::for_each(str.begin(), str.end(), [&](auto codepoint) {result += __to_string<char_t>(codepoint);});
  return result;
}

template<class char_t, class arg_t>
inline std::basic_string<char_t> __to_string(const std::basic_string<arg_t>& str) {
  std::basic_string<char_t> result;
  for (auto codepoint : str)
    result += __to_string<char_t>(codepoint);
  return result;
}

template<class char_t, class arg_t>
inline std::basic_string<char_t> __to_string(const arg_t* str) {
  std::basic_string<char_t> result;
  for (auto codepoint : std::basic_string<arg_t>(str))
    result += __to_string<char_t>(codepoint);
  return result;
}

std::ostream & operator <<(std::ostream& os, const xtd::char8* str);
std::ostream & operator <<(std::ostream& os, const xtd::char16* str);
std::ostream & operator <<(std::ostream& os, const xtd::char32* str);
std::ostream & operator <<(std::ostream& os, const xtd::wchar* str);

template<class enum_t>
std::string __enum_to_string__(enum_t value) noexcept;
std::string __iformatable_to_string(const xtd::iformatable& value) noexcept;
std::string __object_to_string__(const xtd::object& value) noexcept;

template<class char_t, class type_t, class bool_t>
struct __enum_ostream__ {};

template < class char_t, class type_t >
struct __enum_ostream__ < char_t, type_t, std::true_type > {
  std::basic_ostream < char_t > & to_stream(std::basic_ostream < char_t > & os, const type_t& value) noexcept {
    return os << __enum_to_string__(value);
  }
};

template < class char_t, class type_t, class bool_t >
struct __enum_or_polymorphic_ostream__ {};

template < class char_t, class type_t >
struct __enum_or_polymorphic_ostream__ < char_t, type_t, std::true_type > {
  std::basic_ostream < char_t > & to_stream(std::basic_ostream < char_t > & os, const type_t& value) noexcept {
    if (dynamic_cast < const xtd::iformatable* > (&value)) return os << __iformatable_to_string(dynamic_cast < const xtd::iformatable& > (value));
    if (dynamic_cast < const xtd::object* > (&value)) return os << __object_to_string__(dynamic_cast < const xtd::object& > (value));
    return os << value;
  }
};

template < class char_t, class type_t >
struct __enum_or_polymorphic_ostream__ < char_t, type_t, std::false_type > {
  std::basic_ostream < char_t > & to_stream(std::basic_ostream < char_t > & os, const type_t& value) noexcept {
    __enum_ostream__ < char, type_t, typename std::is_enum < type_t>::type > ().to_stream(os, value);
    return os;
  }
};

template < class value_t >
std::string __format_stringer_to_std_string(const value_t& value) {
  std::basic_stringstream < char > ss;
  //ss << value;
  __enum_or_polymorphic_ostream__ < char, value_t, typename std::is_polymorphic < value_t>::type > ().to_stream(ss, value);
  return ss.str();
}

std::string __format_stringer_to_std_string(const char& c);
std::string __format_stringer_to_std_string(const xtd::char8& c);
std::string __format_stringer_to_std_string(const xtd::char16& c);
std::string __format_stringer_to_std_string(const xtd::char32& c);
std::string __format_stringer_to_std_string(const xtd::wchar& c);
std::string __format_stringer_to_std_string(const char* str);
std::string __format_stringer_to_std_string(const xtd::char8* str);
std::string __format_stringer_to_std_string(const xtd::char16* str);
std::string __format_stringer_to_std_string(const xtd::char32* str);
std::string __format_stringer_to_std_string(const xtd::wchar* str);
std::string __format_stringer_to_std_string(const std::string& str);
std::string __format_stringer_to_std_string(const xtd::string& str);
std::string __format_stringer_to_std_string(const std::u8string& str);
std::string __format_stringer_to_std_string(const std::u16string& str);
std::string __format_stringer_to_std_string(const std::u32string& str);
std::string __format_stringer_to_std_string(const std::wstring& str);

template < class char_t, class value_t >
inline std::basic_string < char_t > __format_stringer(value_t value) {
  std::basic_stringstream < char_t > ss;
  ss << __format_stringer_to_std_string(value).c_str(); // Using "c_str()" is not the best method, but it is the only possibility if "char_t" is of another type than "char".
  return ss.str();
}

template < class char_t, class value_t >
inline std::basic_string < char_t > __format_stringer(const bool& value) {
  std::basic_stringstream < char_t > ss;
  ss << std::boolalpha << value;
  return ss.str();
}

template < class char_t, class value_t, xtd::int32 len >
inline std::basic_string < char_t > __format_stringer(const char*& value) {
  std::basic_stringstream < char_t > ss;
  ss << __to_string < char_t > (value);
  return ss.str();
}

template < class char_t, class value_t, xtd::int32 len >
inline std::basic_string < char_t > __format_stringer(const char* const& value) {
  std::basic_stringstream < char_t > ss;
  ss << __to_string < char_t > (value);
  return ss.str();
}

template < class char_t, class value_t >
inline std::basic_string < char_t > __format_stringer(const xtd::char8*& value) {
  auto s = std::u8string(value);
  std::basic_stringstream < char_t > ss;
  ss << std::basic_string < char_t > (s.begin(), s.end());
  return ss.str();
}

template < class char_t, class value_t >
inline std::basic_string < char_t > __format_stringer(const xtd::char8* const& value) {
  auto s = std::u8string(value);
  std::basic_stringstream < char_t > ss;
  ss << std::basic_string < char_t > (s.begin(), s.end());
  return ss.str();
}

template < class char_t, class value_t >
inline std::basic_string < char_t > __format_stringer(const xtd::char16*& value) {
  std::basic_stringstream < char_t > ss;
  ss << __to_string < char_t > (value);
  return ss.str();
}

template < class char_t, class value_t >
inline std::basic_string < char_t > __format_stringer(const xtd::char16* const& value) {
  std::basic_stringstream < char_t > ss;
  ss << __to_string < char_t > (value);
  return ss.str();
}

template < class char_t, class value_t >
inline std::basic_string < char_t > __format_stringer(const xtd::char32*& value) {
  std::basic_stringstream < char_t > ss;
  ss << __to_string < char_t > (value);
  return ss.str();
}

template < class char_t, class value_t >
inline std::basic_string < char_t > __format_stringer(const xtd::char32* const& value) {
  std::basic_stringstream < char_t > ss;
  ss << __to_string < char_t > (value);
  return ss.str();
}

template < class char_t, class value_t >
inline std::basic_string < char_t > __format_stringer(const xtd::wchar*& value) {
  std::basic_stringstream < char_t > ss;
  ss << __to_string < char_t > (value);
  return ss.str();
}

template < class char_t, class value_t >
inline std::basic_string < char_t > __format_stringer(const xtd::wchar* const& value) {
  std::basic_stringstream < char_t > ss;
  ss << __to_string < char_t > (value);
  return ss.str();
}

template < >
inline std::string __format_stringer < char, std::u8string& > (std::u8string& value) {
  std::basic_stringstream < char > ss;
  ss << std::string(value.begin(), value.end());
  return ss.str();
}

template < >
inline std::string __format_stringer < char, const std::u16string& > (const std::u16string& value) {
  std::basic_stringstream < char > ss;
  ss << __to_string < char > (value);
  return ss.str();
}

template < >
inline std::string __format_stringer < char, const std::u32string& > (const std::u32string& value) {
  std::basic_stringstream < char > ss;
  ss << __to_string < char > (value);
  return ss.str();
}

template < >
inline std::string __format_stringer < char, const std::wstring& > (const std::wstring& value) {
  std::basic_stringstream < char > ss;
  ss << __to_string < char > (value);
  return ss.str();
}

template < >
inline std::string __format_stringer < char, bool& > (bool& value);

template < >
inline std::string __format_stringer < char, xtd::sbyte& > (xtd::sbyte& value);

template < >
inline std::string __format_stringer < char, const unsigned char& > (const unsigned char& value);

template < >
inline std::string __format_stringer < char, unsigned char& > (unsigned char& value);

template < >
inline std::string __format_stringer < char, short& > (short& value);

template < >
inline std::string __format_stringer < char, unsigned short& > (unsigned short& value);

template < >
inline std::string __format_stringer < char, int& > (int& value);

template < >
inline std::string __format_stringer < char, unsigned int& > (unsigned int& value);

template < >
inline std::string __format_stringer < char, long& > (long& value);

template < >
inline std::string __format_stringer < char, unsigned long& > (unsigned long& value);

template < >
inline std::string __format_stringer < char, long long& > (long long& value);

template < >
inline std::string __format_stringer < char, unsigned long long& > (unsigned long long& value);

template < >
inline std::string __format_stringer < char, float& > (float& value);

template < >
inline std::string __format_stringer < char, double& > (double& value);

template < >
inline std::string __format_stringer < char, long double& > (long double& value);

template < >
inline std::string __format_stringer < char, std::chrono::system_clock::time_point& > (std::chrono::system_clock::time_point& value);

template < >
inline std::string __format_stringer < char, std::tm& > (tm& value);

template < >
inline std::string __format_stringer < char, xtd::wchar& > (xtd::wchar& value);

template < >
inline std::string __format_stringer < char, xtd::char8& > (xtd::char8& value);

template < >
inline std::string __format_stringer < char, xtd::char16& > (xtd::char16& value);

template < >
inline std::string __format_stringer < char, xtd::char32& > (xtd::char32& value);
/// @endcond
