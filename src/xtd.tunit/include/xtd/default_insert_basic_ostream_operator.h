/// @file
/// @brief Contains std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const type_t& value) function.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
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
#include <optional>
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

/// @cond
template<class type_t> struct __tunit_is_printable : std::false_type {};
template<> struct __tunit_is_printable<bool> : std::true_type {};
template<> struct __tunit_is_printable<char> : std::true_type {};
template<> struct __tunit_is_printable<signed char> : std::true_type {};
template<> struct __tunit_is_printable<unsigned char> : std::true_type {};
template<> struct __tunit_is_printable<wchar_t> : std::true_type {};
template<> struct __tunit_is_printable<char8_t> : std::true_type {};
template<> struct __tunit_is_printable<char16_t> : std::true_type {};
template<> struct __tunit_is_printable<char32_t> : std::true_type {};
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
template<> struct __tunit_is_printable<std::wstring> : std::true_type {};

template<typename char_t, typename char_traits_t, typename value_t>
static void __tunit_print_value(std::basic_ostream<char_t, char_traits_t>& os, const value_t& value, std::true_type) {
  os.operator<<(value);
}

template<typename char_t, typename char_traits_t, typename value_t>
static void __tunit_print_value(std::basic_ostream<char_t, char_traits_t>& os, value_t* value, std::true_type) {
  os.operator<<(value);
}

template<typename char_t, typename char_traits_t, typename value_t>
static void __tunit_print_value(std::basic_ostream<char_t, char_traits_t>& os, const value_t* value, std::true_type) {
  os.operator<<(value);
}

template<typename char_t, typename char_traits_t, typename value_t>
static void __tunit_print_value(std::basic_ostream<char_t, char_traits_t>& os, const value_t& value, std::false_type) {
  size_t size = sizeof(value) > 32 ? 32 : sizeof(value);
  os << size << "-byte object <";
  for (size_t index = 0; index != size; index++)
    os <<  (index != 0 ? (index % 2 == 0 ? " " : "-") : "") << std::hex << std::setiosflags(std::ios_base::uppercase) << std::setw(2) << std::setfill('0') << static_cast<int>(reinterpret_cast<const unsigned char*>(&value)[index]) << std::resetiosflags(std::ios_base::dec) << std::dec;
  os << (size < sizeof(value) ? "-..." : "") << ">";
}

template<typename char_t, typename char_traits_t, typename value_t>
static void __print(std::basic_ostream<char_t, char_traits_t>& os, const value_t& value) {
  __tunit_print_value(os, value, __tunit_is_printable<value_t>());
}

template<typename char_t, typename char_traits_t, typename value_t>
static void __print(std::basic_ostream<char_t, char_traits_t>& os, value_t* value) {
  __tunit_print_value(os, value, __tunit_is_printable<value_t>());
}

template<typename char_t, typename char_traits_t, typename value_t>
static void __print(std::basic_ostream<char_t, char_traits_t>& os, const value_t* value) {
  __tunit_print_value(os, value, __tunit_is_printable<value_t>());
}

template <typename char_t, typename char_traits_t, typename value_t>
struct __tunit_value_printer {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const value_t* & value) {
    __print(os, value);
  }
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const value_t* const & value) {
    __print(os, value);
  }
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const value_t& value) {
    __print(os, value);
  }
};

template <typename char_t, typename char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, std::exception> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::exception& value) {
    os << "exception: " << value.what();
  }
};

template <typename char_t, typename char_traits_t, typename value_t>
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

template <typename char_t, typename char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, std::string> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::string& value) {
    os << "\"" << value << "\"";
  }
};

template <typename char_t, typename char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, std::u8string> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::u8string& value) {
    __tunit_value_printer<char_t, char_traits_t, char8_t>::print(os, value.c_str());
  }
};

template <typename char_t, typename char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, std::u16string> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::u16string& value) {
    __tunit_value_printer<char_t, char_traits_t, char16_t>::print(os, value.c_str());
  }
};

template <typename char_t, typename char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, std::u32string> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::u32string& value) {
    __tunit_value_printer<char_t, char_traits_t, char32_t>::print(os, value.c_str());
  }
};

template <typename char_t, typename char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, std::wstring> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::wstring& value) {
    __tunit_value_printer<char_t, char_traits_t, wchar_t>::print(os, value.c_str());
  }
};

template <typename char_t, typename char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, const char*> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const char* const & value) {
    os << "\"" << value << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const char* & value) {
    os << "\"" << value << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, char value) {
    os << value;
  }
};

template <typename char_t, typename char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, char> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const char* const & value) {
    os << "\"" << value << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const char* & value) {
    os << "\"" << value << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, char value) {
    os << value;
  }
};

template <typename char_t, typename char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, const char8_t*> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const char8_t* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
    __tunit_value_printer<char_t, char_traits_t, char8_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const char8_t* & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
    __tunit_value_printer<char_t, char_traits_t, char8_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, char8_t value) {
    if (value <= 0xFF)
      os << static_cast<char>(value);
    else
      os << "\\x" << std::hex << static_cast<int>(value);
  }
};

template <typename char_t, typename char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, char8_t> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const char8_t* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
    __tunit_value_printer<char_t, char_traits_t, char8_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const char8_t* & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
    __tunit_value_printer<char_t, char_traits_t, char8_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, char8_t value) {
    os << static_cast<char>(value);
  }
};

template <typename char_t, typename char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, const char16_t*> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const char16_t* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, char16_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const char16_t* & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, char16_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, char16_t value) {
    if (value <= 0xFF)
      os << static_cast<char>(value);
    else
      os << "\\x" << std::hex << static_cast<int>(value);
  }
};

template <typename char_t, typename char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, char16_t> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const char16_t* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, char16_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const char16_t* & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, char16_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, char16_t value) {
    if (value <= 0xFF)
      os << static_cast<char>(value);
    else
      os << "\\x" << std::hex << static_cast<int>(value);
  }
};

template <typename char_t, typename char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, const char32_t*> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const char32_t* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, char32_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const char32_t* & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, char32_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, char32_t value) {
    if (value <= 0xFF)
      os << static_cast<char>(value);
    else
      os << "\\x" << std::hex << static_cast<int>(value);
  }
};

template <typename char_t, typename char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, char32_t> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const char32_t* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, char32_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const char32_t* & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, char32_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, char32_t value) {
    if (value <= 0xFF)
      os << static_cast<char>(value);
    else
      os << "\\x" << std::hex << static_cast<int>(value);
  }
};

template <typename char_t, typename char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, const wchar_t*> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const wchar_t* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, wchar_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const wchar_t* & value) {
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

template <typename char_t, typename char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, wchar_t> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const wchar_t* const & value) {
    os << "\"";
    for (size_t index = 0; value[index] != L'\0'; index++)
      __tunit_value_printer<char_t, char_traits_t, wchar_t>::print(os, value[index]);
    os << "\"";
  }
  
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const wchar_t* & value) {
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

template <typename char_t, typename char_traits_t, typename type1_t, typename type2_t>
struct __tunit_value_printer<char_t, char_traits_t, std::pair<type1_t, type2_t>> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::pair<type1_t, type2_t>& value) {
    os << "(";
    __tunit_value_printer<char_t, char_traits_t, type1_t>::print(os, value.first);
    os << ", ";
    __tunit_value_printer<char_t, char_traits_t, type2_t>::print(os, value.second);
    os << ")";
  }
};

template<typename char_t, typename char_traits_t, typename type_t, unsigned N, unsigned Last>
struct __tuple_printer {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const type_t& value) {
    __tunit_value_printer<char_t, char_traits_t, typename std::tuple_element<N, type_t>::type>::print(os, std::get<N>(value));
    os << ", ";
    __tuple_printer<char_t, char_traits_t, type_t, N + 1, Last>::print(os, value);
  }
};

template<typename char_t, typename char_traits_t, typename type_t, unsigned N>
struct __tuple_printer<char_t, char_traits_t, type_t, N, N> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const type_t& value) {
    __tunit_value_printer<char_t, char_traits_t, typename std::tuple_element<N, type_t>::type>::print(os, std::get<N>(value));
  }
};

template <typename char_t, typename char_traits_t, typename ... Types>
struct __tunit_value_printer<char_t, char_traits_t, std::tuple<Types ...>> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::tuple<Types ...>& value) {
    os << "(";
    __tuple_printer<char_t, char_traits_t, std::tuple<Types ...>, 0, sizeof...(Types) - 1>::print(os, value);
    os << ")";
  }
};

template <typename char_t, typename char_traits_t>
struct __tunit_value_printer<char_t, char_traits_t, std::tuple<>> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::tuple<>&) {
    os << "()";
  }
};

template <typename char_t, typename char_traits_t, typename Iterator>
std::basic_ostream<char_t, char_traits_t>& __print_sequence_container(std::basic_ostream<char_t, char_traits_t>& os, const Iterator& begin, const Iterator& end) {
  os << "[";
  bool first = true;
  for (Iterator it = begin; it != end; ++it) {
    if (!first) os << ", ";
    __tunit_value_printer<char_t, char_traits_t, typename std::iterator_traits<Iterator>::value_type>::print(os, *it);
    first = false;
  }
  return os << "]";
}

template <typename char_t, typename char_traits_t, typename value_t, size_t Size>
struct __tunit_value_printer<char_t, char_traits_t, std::array<value_t, Size>> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::array<value_t, Size>& values) {
    __print_sequence_container(os, values.begin(), values.end());
  }
};

template <typename char_t, typename char_traits_t, typename value_t>
struct __tunit_value_printer<char_t, char_traits_t, std::deque<value_t>> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::deque<value_t>& values) {
    __print_sequence_container(os, values.begin(), values.end());
  }
};

template <typename char_t, typename char_traits_t, typename value_t>
struct __tunit_value_printer<char_t, char_traits_t, std::forward_list<value_t>> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::forward_list<value_t>& values) {
    __print_sequence_container(os, values.begin(), values.end());
  }
};

template <typename char_t, typename char_traits_t, typename value_t>
struct __tunit_value_printer<char_t, char_traits_t, std::list<value_t>> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::list<value_t>& values) {
    __print_sequence_container(os, values.begin(), values.end());
  }
};

template <typename char_t, typename char_traits_t, typename value_t>
struct __tunit_value_printer<char_t, char_traits_t, std::initializer_list<value_t>> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::initializer_list<value_t>& values) {
    __print_sequence_container(os, values.begin(), values.end());
  }
};

template <typename char_t, typename char_traits_t, typename value_t>
struct __tunit_value_printer<char_t, char_traits_t, std::vector<value_t>> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::vector<value_t>& values) {
    __print_sequence_container(os, values.begin(), values.end());
  }
};

template <typename char_t, typename char_traits_t, typename Iterator>
std::basic_ostream<char_t, char_traits_t>& __print_associative_container(std::basic_ostream<char_t, char_traits_t>& os, const Iterator& begin, const Iterator& end) {
  os << "{";
  bool first = true;
  for (Iterator it = begin; it != end; ++it) {
    if (!first) os << ", ";
    __tunit_value_printer<char_t, char_traits_t, typename std::iterator_traits<Iterator>::value_type>::print(os, *it);
    first = false;
  }
  return os << "}";
}

template <typename char_t, typename char_traits_t, typename Key, typename value_t>
struct __tunit_value_printer<char_t, char_traits_t, std::map<Key, value_t>> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::map<Key, value_t>& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template <typename char_t, typename char_traits_t, typename Key, typename value_t>
struct __tunit_value_printer<char_t, char_traits_t, std::multimap<Key, value_t>> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::multimap<Key, value_t>& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template <typename char_t, typename char_traits_t, typename value_t>
struct __tunit_value_printer<char_t, char_traits_t, std::multiset<value_t>> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::multiset<value_t>& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template <typename char_t, typename char_traits_t, typename value_t>
struct __tunit_value_printer<char_t, char_traits_t, std::set<value_t>> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::set<value_t>& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template <typename char_t, typename char_traits_t, typename Key, typename value_t>
struct __tunit_value_printer<char_t, char_traits_t, std::unordered_map<Key, value_t>> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::unordered_map<Key, value_t>& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template <typename char_t, typename char_traits_t, typename Key, typename value_t>
struct __tunit_value_printer<char_t, char_traits_t, std::unordered_multimap<Key, value_t>> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::unordered_multimap<Key, value_t>& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template <typename char_t, typename char_traits_t, typename value_t>
struct __tunit_value_printer<char_t, char_traits_t, std::unordered_multiset<value_t>> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::unordered_multiset<value_t>& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template <typename char_t, typename char_traits_t, typename value_t>
struct __tunit_value_printer<char_t, char_traits_t, std::unordered_set<value_t>> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const std::unordered_set<value_t>& values) {
    __print_associative_container(os, values.begin(), values.end());
  }
};

template <typename char_t, typename char_traits_t, typename type_t>
std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const type_t& value) {
  __tunit_value_printer<char_t, char_traits_t, type_t>::print(os, value);
  return os;
}

template <typename char_t, typename char_traits_t, typename type_t>
std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const type_t* value) {
  __tunit_value_printer<char_t, char_traits_t, type_t>::print(os, value);
  return os;
}

template <typename char_t, typename char_traits_t, typename type_t>
std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, type_t* value) {
  __tunit_value_printer<char_t, char_traits_t, type_t>::print(os, value);
  return os;
}

inline std::string __tunit_codepoint_to_string(char32_t codepoint) {
  std::string result;
  if (codepoint < 0x80) {
    result.push_back(static_cast<char>(codepoint));
  } else  if (codepoint < 0x800) {
    result.push_back(static_cast<char>((codepoint >> 6) | 0xc0));
    result.push_back(static_cast<char>((codepoint & 0x3f) | 0x80));
  } else if (codepoint < 0x10000) {
    result.push_back(static_cast<char>((codepoint >> 12) | 0xe0));
    result.push_back(static_cast<char>(((codepoint >> 6) & 0x3f) | 0x80));
    result.push_back(static_cast<char>((codepoint & 0x3f) | 0x80));
  } else {
    result.push_back(static_cast<char>((codepoint >> 18) | 0xf0));
    result.push_back(static_cast<char>(((codepoint >> 12) & 0x3f) | 0x80));
    result.push_back(static_cast<char>(((codepoint >> 6) & 0x3f) | 0x80));
    result.push_back(static_cast<char>((codepoint & 0x3f) | 0x80));
  }
  return result;
}

inline std::string __tunit_to_string(const char8_t& value) {
  std::stringstream ss;
  ss << "\"" << __tunit_codepoint_to_string(value) << "\"";
  return ss.str();
}

inline std::string __tunit_to_string(const char16_t& value) {
  std::stringstream ss;
  ss << "\"" << __tunit_codepoint_to_string(value) << "\"";
  return ss.str();
}

inline std::string __tunit_to_string(const char32_t& value) {
  std::stringstream ss;
  ss << "\"" << __tunit_codepoint_to_string(value) << "\"";
  return ss.str();
}

inline std::string __tunit_to_string(const wchar_t& value) {
  std::stringstream ss;
  ss << "\"" << __tunit_codepoint_to_string(value) << "\"";
  return ss.str();
}

inline std::string __tunit_to_string(const std::string& value) {
  std::stringstream ss;
  ss << "\"" << value << "\"";
  return ss.str();
}

inline std::string __tunit_to_string(const std::u8string& value) {
  std::stringstream ss;
  ss << "\"" << value << "\"";
  return ss.str();
}

inline std::string __tunit_to_string(const std::u16string& value) {
  std::string result;
  result += "\"";
  for (auto codepoint : value)
    result += __tunit_codepoint_to_string(codepoint);
  result += "\"";
  return result;
}

inline std::string __tunit_to_string(const std::u32string& value) {
  std::string result;
  result += "\"";
  for (auto codepoint : value)
    result += __tunit_codepoint_to_string(codepoint);
  result += "\"";
  return result;
}

inline std::string __tunit_to_string(const std::wstring& value) {
  std::string result;
  result += "\"";
  for (auto codepoint : value)
    result += __tunit_codepoint_to_string(codepoint);
  result += "\"";
  return result;
}

inline std::string __tunit_to_string(const char* value) {
  std::stringstream ss;
  ss << "\"" << value << "\"";
  return ss.str();
}

inline std::string __tunit_to_string(const char8_t* value) {
  return __tunit_to_string(std::u8string(value));
}

inline std::string __tunit_to_string(const char16_t* value) {
  return __tunit_to_string(std::u16string(value));
}

inline std::string __tunit_to_string(const char32_t* value) {
  return __tunit_to_string(std::u32string(value));
}

inline std::string __tunit_to_string(const wchar_t* value) {
  return __tunit_to_string(std::wstring(value));
}

template <typename value_t>
inline std::string __tunit_to_string(const value_t& value) {
  std::stringstream ss;
  ss << value;
  return ss.str();
}

template <typename value_t>
inline std::string __tunit_to_string(const value_t* value) {
  std::stringstream ss;
  ss << value;
  return ss.str();
}
/// @endcond
