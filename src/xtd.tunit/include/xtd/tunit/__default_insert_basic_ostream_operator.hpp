/// @file
/// @brief Contains std::basic_ostream<char_t, char_traits_t>& operator <<(std::basic_ostream<char_t, char_traits_t>& os, const type_t& value) function.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_TUNIT_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <array>
#include <cstdint>
#include <deque>
#include <exception>
#include <forward_list>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <sstream>
#include <type_traits>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <xtd/optional>
#include <xtd/target_id>
#include <xtd/string>

/// @cond
template<class type_t> struct __tunit_is_printable : std::false_type {};
template<> struct __tunit_is_printable<bool> : std::true_type {};
template<> struct __tunit_is_printable<char> : std::true_type {};
template<> struct __tunit_is_printable<signed char> : std::true_type {};
template<> struct __tunit_is_printable<unsigned char> : std::true_type {};
template<> struct __tunit_is_printable<wchar_t> : std::true_type {};
template<> struct __tunit_is_printable<xtd::char8> : std::true_type {};
template<> struct __tunit_is_printable<xtd::char16> : std::true_type {};
template<> struct __tunit_is_printable<xtd::char32> : std::true_type {};
template<> struct __tunit_is_printable<short> : std::true_type {};
template<> struct __tunit_is_printable<unsigned short> : std::true_type {};
template<> struct __tunit_is_printable<int> : std::true_type {};
template<> struct __tunit_is_printable<unsigned int> : std::true_type {};
template<> struct __tunit_is_printable<long> : std::true_type {};
template<> struct __tunit_is_printable<unsigned long> : std::true_type {};
template<> struct __tunit_is_printable<long long> : std::true_type {};
template<> struct __tunit_is_printable<unsigned long long> : std::true_type {};
template<> struct __tunit_is_printable<const char*> : std::true_type {};
template<> struct __tunit_is_printable<const wchar_t*> : std::true_type {};
template<> struct __tunit_is_printable<float> : std::true_type {};
template<> struct __tunit_is_printable<double> : std::true_type {};
template<> struct __tunit_is_printable<long double> : std::true_type {};
template<> struct __tunit_is_printable<std::string> : std::true_type {};
template<> struct __tunit_is_printable<xtd::string> : std::true_type {};
template<> struct __tunit_is_printable<std::u8string> : std::true_type {};
template<> struct __tunit_is_printable<std::u16string> : std::true_type {};
template<> struct __tunit_is_printable<std::u32string> : std::true_type {};
template<> struct __tunit_is_printable<std::wstring> : std::true_type {};

template<class char_t, class char_traits_t, class value_t>
inline static void __tunit_print_value(std::basic_ostream<char_t, char_traits_t>& os, const value_t& value, std::true_type) {
  os.operator << (value);
}

template<class char_t, class char_traits_t, class value_t>
inline static void __tunit_print_value(std::basic_ostream<char_t, char_traits_t>& os, value_t* value, std::true_type) {
  os.operator << (value);
}

template<class char_t, class char_traits_t, class value_t>
inline static void __tunit_print_value(std::basic_ostream<char_t, char_traits_t>& os, const value_t* value, std::true_type) {
  os.operator << (value);
}

template<class char_t, class char_traits_t, class value_t>
inline static void __tunit_print_value(std::basic_ostream<char_t, char_traits_t>& os, const value_t& value, std::false_type) {
  size_t size = sizeof(value) > 32 ? 32 : sizeof(value);
  os << size << "-byte object <";
  for (size_t index = 0; index != size; index++)
    os << (index != 0 ? (index % 2 == 0 ? " " : "-") : "") << std::hex << std::setiosflags(std::ios_base::uppercase) << std::setw(2) << std::setfill('0') << static_cast<int>(reinterpret_cast<const unsigned char*>(&value)[index]) << std::resetiosflags(std::ios_base::dec) << std::dec;
  os << (size < sizeof(value) ? "-..." : "") << ">";
}

template<class char_t, class char_traits_t, class value_t>
inline static void __print(std::basic_ostream<char_t, char_traits_t>& os, const value_t& value) {
  __tunit_print_value(os, value, __tunit_is_printable<value_t>());
}

template<class char_t, class char_traits_t, class value_t>
inline static void __print(std::basic_ostream<char_t, char_traits_t>& os, value_t* value) {
  __tunit_print_value(os, value, __tunit_is_printable<value_t>());
}

template<class char_t, class char_traits_t, class value_t>
inline static void __print(std::basic_ostream<char_t, char_traits_t>& os, const value_t* value) {
  __tunit_print_value(os, value, __tunit_is_printable<value_t>());
}

template<class char_t, class char_traits_t, class value_t>
struct __tunit_value_printer {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const value_t*& value) {
    __print(os, value);
  }
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const value_t* const& value) {
    __print(os, value);
  }
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const value_t& value) {
    __print(os, value);
  }
};

template<class char_t, class char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, std::exception> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::exception& value) {
    os << "exception: " << value.what();
  }
};

template<class char_t, class char_traits_t, class value_t>
struct __tunit_value_printer<char_t, char_traits_t, std::optional<value_t>> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::optional<value_t>& value) {
    if (!value.has_value())
      os << "(null)";
    else {
      os << "(";
      __tunit_value_printer<char_t, char_traits_t, value_t>::print(os, value.value());
      os << ")";
    }
  }
};

template<class char_t, class char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, std::string> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::string & value) {
    os << xtd::string(value).quoted().chars();
  }
};

template<class char_t, class char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, xtd::string> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::string & value) {
    os << xtd::string(value).quoted().chars();
  }
};

template<class char_t, class char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, std::u8string> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::u8string & value) {
    __tunit_value_printer<char_t, char_traits_t, xtd::char8>::print(os, value.c_str());
  }
};

template<class char_t, class char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, std::u16string> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::u16string & value) {
    __tunit_value_printer<char_t, char_traits_t, xtd::char16>::print(os, value.c_str());
  }
};

template<class char_t, class char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, std::u32string> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::u32string & value) {
    __tunit_value_printer<char_t, char_traits_t, xtd::char32>::print(os, value.c_str());
  }
};

template<class char_t, class char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, std::wstring> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::wstring & value) {
    __tunit_value_printer<char_t, char_traits_t, wchar_t>::print(os, value.c_str());
  }
};

template<class char_t, class char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, const char*> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const char* const & value) {
    os << xtd::string(value).quoted().chars();
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const char*& value) {
    os << xtd::string(value).quoted().chars();
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, char value) {
    os << value;
  }
};

template<class char_t, class char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, char> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const char* const & value) {
    os << xtd::string(value).quoted().chars();
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const char*& value) {
    os << xtd::string(value).quoted().chars();
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, char value) {
    os << value;
  }
};

template<class char_t, class char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, const xtd::char8*> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const xtd::char8* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != '\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, xtd::char8>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const xtd::char8*& value) {
    os << "\"";
    for (size_t index = 0; value[index] != '\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, xtd::char8>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, xtd::char8 value) {
    if (static_cast<int>(value) <= 0xFF)
      os << static_cast<char>(value);
    else
      os << "\\x" << std::hex << static_cast<int>(value);
  }
};

template<class char_t, class char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, xtd::char8> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const xtd::char8* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != '\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, xtd::char8>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const xtd::char8*& value) {
    os << "\"";
    for (size_t index = 0; value[index] != '\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, xtd::char8>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, xtd::char8 value) {
    os << static_cast<char>(value);
  }
};

template<class char_t, class char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, const xtd::char16*> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const xtd::char16* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != '\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, xtd::char16>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const xtd::char16*& value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, xtd::char16>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, xtd::char16 value) {
    if (value <= 0xFF)
      os << static_cast<char>(value);
    else
      os << "\\x" << std::hex << static_cast<int>(value);
  }
};

template<class char_t, class char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, xtd::char16> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const xtd::char16* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, xtd::char16>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const xtd::char16*& value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, xtd::char16>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, xtd::char16 value) {
    if (value <= 0xFF)
      os << static_cast<char>(value);
    else
      os << "\\x" << std::hex << static_cast<int>(value);
  }
};

template<class char_t, class char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, const xtd::char32*> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const xtd::char32* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, xtd::char32>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const xtd::char32*& value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, xtd::char32>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, xtd::char32 value) {
    if (value <= 0xFF)
      os << static_cast<char>(value);
    else
      os << "\\x" << std::hex << static_cast<int>(value);
  }
};

template<class char_t, class char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, xtd::char32> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const xtd::char32* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, xtd::char32>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const xtd::char32*& value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, xtd::char32>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, xtd::char32 value) {
    if (value <= 0xFF)
      os << static_cast<char>(value);
    else
      os << "\\x" << std::hex << static_cast<int>(value);
  }
};

template<class char_t, class char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, const wchar_t*> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const wchar_t* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, wchar_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const wchar_t*& value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, wchar_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, wchar_t value) {
    if (value <= 0xFF)
      os << static_cast<char>(value);
    else
      os << "\\x" << std::hex << static_cast<int>(value);
  }
};

template<class char_t, class char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, wchar_t> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const wchar_t* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, wchar_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const wchar_t*& value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, wchar_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, wchar_t value) {
    if (value <= 0xFF)
      os << static_cast<char>(value);
    else
      os << "\\x" << std::hex << static_cast<int>(value);
  }
};

template<class char_t, class char_traits_t, class type1_t, class type2_t>
struct __tunit_value_printer<char_t, char_traits_t, std::pair<type1_t, type2_t>> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::pair<type1_t, type2_t>& value) {
    os << "(";
    __tunit_value_printer<char_t, char_traits_t, type1_t>::print(os, value.first);
    os << ", ";
    __tunit_value_printer<char_t, char_traits_t, type2_t>::print(os, value.second);
    os << ")";
  }
};

template<class char_t, class char_traits_t, class type_t, unsigned N, unsigned Last>
struct __tuple_printer {
  static void print(std::basic_ostream < char_t, char_traits_t >& os, const type_t& value) {
    __tunit_value_printer < char_t, char_traits_t, typename std::tuple_element < N, type_t>::type>::print(os, std::get < N > (value));
    os << ", ";
    __tuple_printer < char_t, char_traits_t, type_t, N + 1, Last >::print(os, value);
  }
};

template < class char_t, class char_traits_t, class type_t, unsigned N >
struct __tuple_printer < char_t, char_traits_t, type_t, N, N > {
  static void print(std::basic_ostream < char_t, char_traits_t >& os, const type_t& value) {
    __tunit_value_printer < char_t, char_traits_t, typename std::tuple_element < N, type_t>::type>::print(os, std::get < N > (value));
  }
};

template < class char_t, class char_traits_t, class ...types_t >
struct __tunit_value_printer < char_t, char_traits_t, std::tuple < types_t ...>> {
  static void print(std::basic_ostream < char_t, char_traits_t >& os, const std::tuple < types_t ... >& value) {
    os << "(";
    __tuple_printer < char_t, char_traits_t, std::tuple < types_t ...>, 0, sizeof...(types_t) - 1 >::print(os, value);
    os << ")";
  }
};

template < class char_t, class char_traits_t >
struct __tunit_value_printer < char_t, char_traits_t, std::tuple < >> {
  static void print(std::basic_ostream < char_t, char_traits_t >& os, const std::tuple < >&) {
    os << "()";
  }
};

template < class char_t, class char_traits_t, class iterator_t >
std::basic_ostream < char_t, char_traits_t >& __print_sequence_container(std::basic_ostream < char_t, char_traits_t >& os, const iterator_t& begin, const iterator_t& end) {
  os << "[";
  bool first = true;
  for (iterator_t it = begin; it != end; ++it) {
    if (!first) os << ", ";
    __tunit_value_printer < char_t, char_traits_t, typename std::iterator_traits < iterator_t>::value_type >::print(os, *it);
    first = false;
  }
  return os << "]";
}

template < class char_t, class char_traits_t, class value_t, size_t Size >
struct __tunit_value_printer < char_t, char_traits_t, std::array < value_t, Size>> {
  static void print(std::basic_ostream < char_t, char_traits_t >& os, const std::array < value_t, Size >& values) {
    __print_sequence_container(os, values.begin(), values.end());
  }
};

template < class char_t, class char_traits_t, class value_t >
struct __tunit_value_printer < char_t, char_traits_t, std::deque < value_t>> {
  static void print(std::basic_ostream < char_t, char_traits_t >& os, const std::deque < value_t >& values) {
    __print_sequence_container(os, values.begin(), values.end());
  }
};

template < class char_t, class char_traits_t, class value_t >
struct __tunit_value_printer < char_t, char_traits_t, std::forward_list < value_t>> {
  static void print(std::basic_ostream < char_t, char_traits_t >& os, const std::forward_list < value_t >& values) {
    __print_sequence_container(os, values.begin(), values.end());
  }
};

template < class char_t, class char_traits_t, class value_t >
struct __tunit_value_printer < char_t, char_traits_t, std::list < value_t>> {
  static void print(std::basic_ostream < char_t, char_traits_t >& os, const std::list < value_t >& values) {
    __print_sequence_container(os, values.begin(), values.end());
  }
};

template < class char_t, class char_traits_t, class value_t >
struct __tunit_value_printer < char_t, char_traits_t, std::initializer_list < value_t>> {
  static void print(std::basic_ostream < char_t, char_traits_t >& os, const std::initializer_list < value_t >& values) {
    __print_sequence_container(os, values.begin(), values.end());
  }
};

template < class char_t, class char_traits_t, class value_t >
struct __tunit_value_printer < char_t, char_traits_t, std::vector < value_t>> {
  static void print(std::basic_ostream < char_t, char_traits_t >& os, const std::vector < value_t >& values) {
    __print_sequence_container(os, values.begin(), values.end());
  }
};

template < class char_t, class char_traits_t, class iterator_t >
std::basic_ostream < char_t, char_traits_t >& __print_associative_container(std::basic_ostream < char_t, char_traits_t >& os, const iterator_t& begin, const iterator_t& end) {
  os << "{";
  bool first = true;
  for (iterator_t it = begin; it != end; ++it) {
    if (!first) os << ", ";
    __tunit_value_printer < char_t, char_traits_t, typename std::iterator_traits < iterator_t>::value_type >::print(os, *it);
    first = false;
  }
  return os << "}";
}

template < class char_t, class char_traits_t, class key_t, class value_t >
struct __tunit_value_printer < char_t, char_traits_t, std::map < key_t, value_t>> {
  static void print(std::basic_ostream < char_t, char_traits_t >& os, const std::map < key_t, value_t >& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template < class char_t, class char_traits_t, class key_t, class value_t >
struct __tunit_value_printer < char_t, char_traits_t, std::multimap < key_t, value_t>> {
  static void print(std::basic_ostream < char_t, char_traits_t >& os, const std::multimap < key_t, value_t >& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template < class char_t, class char_traits_t, class value_t >
struct __tunit_value_printer < char_t, char_traits_t, std::multiset < value_t>> {
  static void print(std::basic_ostream < char_t, char_traits_t >& os, const std::multiset < value_t >& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template < class char_t, class char_traits_t, class value_t >
struct __tunit_value_printer < char_t, char_traits_t, std::set < value_t>> {
  static void print(std::basic_ostream < char_t, char_traits_t >& os, const std::set < value_t >& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template < class char_t, class char_traits_t, class key_t, class value_t >
struct __tunit_value_printer < char_t, char_traits_t, std::unordered_map < key_t, value_t>> {
  static void print(std::basic_ostream < char_t, char_traits_t >& os, const std::unordered_map < key_t, value_t >& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template < class char_t, class char_traits_t, class key_t, class value_t >
struct __tunit_value_printer < char_t, char_traits_t, std::unordered_multimap < key_t, value_t>> {
  static void print(std::basic_ostream < char_t, char_traits_t >& os, const std::unordered_multimap < key_t, value_t >& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template < class char_t, class char_traits_t, class value_t >
struct __tunit_value_printer < char_t, char_traits_t, std::unordered_multiset < value_t>> {
  static void print(std::basic_ostream < char_t, char_traits_t >& os, const std::unordered_multiset < value_t >& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template < class char_t, class char_traits_t, class value_t >
struct __tunit_value_printer < char_t, char_traits_t, std::unordered_set < value_t>> {
  static void print(std::basic_ostream < char_t, char_traits_t >& os, const std::unordered_set < value_t >& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

#if __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_TEST_APPLICATION__
template < class char_t, class char_traits_t, class type_t >
std::basic_ostream < char_t, char_traits_t >& operator <<(std::basic_ostream < char_t, char_traits_t >& os, const type_t& value) {
  __tunit_value_printer < char_t, char_traits_t, type_t >::print(os, value);
  return os;
}

template < class char_t, class char_traits_t, class type_t >
std::basic_ostream < char_t, char_traits_t >& operator <<(std::basic_ostream < char_t, char_traits_t >& os, const type_t* value) {
  __tunit_value_printer < char_t, char_traits_t, type_t >::print(os, value);
  return os;
}

template < class char_t, class char_traits_t, class type_t >
std::basic_ostream < char_t, char_traits_t >& operator <<(std::basic_ostream < char_t, char_traits_t >& os, type_t* value) {
  __tunit_value_printer < char_t, char_traits_t, type_t >::print(os, value);
  return os;
}
#endif

inline std::string __tunit_codepoint_to_string(xtd::char32 codepoint) {
  std::string result;
  if (codepoint < 0x80)
    result.push_back(static_cast < char > (codepoint));
  else  if (codepoint < 0x800) {
    result.push_back(static_cast < char > ((codepoint >> 6) | 0xc0));
    result.push_back(static_cast < char > ((codepoint & 0x3f) | 0x80));
  } else if (codepoint < 0x10000) {
    result.push_back(static_cast < char > ((codepoint >> 12) | 0xe0));
    result.push_back(static_cast < char > (((codepoint >> 6) & 0x3f) | 0x80));
    result.push_back(static_cast < char > ((codepoint & 0x3f) | 0x80));
  } else {
    result.push_back(static_cast < char > ((codepoint >> 18) | 0xf0));
    result.push_back(static_cast < char > (((codepoint >> 12) & 0x3f) | 0x80));
    result.push_back(static_cast < char > (((codepoint >> 6) & 0x3f) | 0x80));
    result.push_back(static_cast < char > ((codepoint & 0x3f) | 0x80));
  }
  return result;
}

inline xtd::string __tunit_to_string(const xtd::char8& value) {
  std::stringstream ss;
  ss << xtd::string(__tunit_codepoint_to_string(value)).quoted().chars();
  return ss.str();
}

inline xtd::string __tunit_to_string(const xtd::char16& value) {
  std::stringstream ss;
  ss << xtd::string(__tunit_codepoint_to_string(value)).quoted().chars();
  return ss.str();
}

inline xtd::string __tunit_to_string(const xtd::char32& value) {
  std::stringstream ss;
  ss << xtd::string(__tunit_codepoint_to_string(value)).quoted().chars();
  return ss.str();
}

inline xtd::string __tunit_to_string(const wchar_t& value) {
  std::stringstream ss;
  ss << xtd::string(__tunit_codepoint_to_string(value)).quoted().chars();
  return ss.str();
}

inline xtd::string __tunit_to_string(const std::string& value) {
  std::stringstream ss;
  ss << xtd::string(value).quoted().chars();
  return ss.str();
}

inline xtd::string __tunit_to_string(const xtd::string& value) {
  std::stringstream ss;
  ss << value.quoted().chars();
  return ss.str();
}

inline xtd::string __tunit_to_string(const std::u8string& value) {
  std::stringstream ss;
  ss << xtd::string(value).quoted().chars();
  return ss.str();
}

inline xtd::string __tunit_to_string(const std::u16string& value) {
  std::string result;
  result += "\"";
  for (auto codepoint : value)
    result += __tunit_codepoint_to_string(codepoint);
  result += "\"";
  return result;
}

inline xtd::string __tunit_to_string(const std::u32string& value) {
  std::string result;
  result += "\"";
  for (auto codepoint : value)
    result += __tunit_codepoint_to_string(codepoint);
  result += "\"";
  return result;
}

inline xtd::string __tunit_to_string(const std::wstring& value) {
  std::string result;
  result += "\"";
  for (auto codepoint : value)
    result += __tunit_codepoint_to_string(codepoint);
  result += "\"";
  return result;
}

inline xtd::string __tunit_to_string(const void* value) {
  std::stringstream ss;
  ss << "\"" << reinterpret_cast < xtd::intptr > (value) << "\"";
  return ss.str();
}

inline xtd::string __tunit_to_string(void* value) {
  std::stringstream ss;
  ss << "\"" << reinterpret_cast < xtd::intptr > (value) << "\"";
  return ss.str();
}

inline xtd::string __tunit_to_string(const char* value) {
  std::stringstream ss;
  ss << xtd::string(value).quoted().chars();
  return ss.str();
}

inline xtd::string __tunit_to_string(const xtd::char8* value) {
  return __tunit_to_string(std::u8string(value));
}

inline xtd::string __tunit_to_string(const xtd::char16* value) {
  return __tunit_to_string(std::u16string(value));
}

inline xtd::string __tunit_to_string(const xtd::char32* value) {
  return __tunit_to_string(std::u32string(value));
}

inline xtd::string __tunit_to_string(const wchar_t* value) {
  return __tunit_to_string(std::wstring(value));
}

template < class value_t >
inline xtd::string __tunit_to_string(const value_t& value) {
  std::stringstream ss;
  ss << value;
  return ss.str();
}

template < class value_t >
inline xtd::string __tunit_to_string(const value_t* value) {
  std::stringstream ss;
  ss << reinterpret_cast < xtd::intptr > (value);
  return ss.str();
}

template < class value_t >
inline xtd::string __tunit_to_string(value_t* value) {
  std::stringstream ss;
  ss << reinterpret_cast < xtd::intptr > (value);
  return ss.str();
}
/// @endcond
