/// @file
/// @brief Contains generic stream output methods.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <array>
#include <optional>
#include <deque>
#include <stdexcept>
#include <forward_list>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

/// @cond
/*
template <typename char_t, typename char_traits_t, typename type_t>
std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const type_t& value) {
  size_t size = sizeof(value) > 32 ? 32 : sizeof(value);
  os << sizeof(value) << std::basic_string<char_t> {'-', 'b', 'y', 't', 'e', ' ', 'o', 'b', 'j', 'e', 'c', 't', '<'};
  for (size_t index = 0; index != size; index++)
    os <<  (index != 0 ? (index % 2 == 0 ? ' ' : '-') : '\0') << std::hex << std::setiosflags(std::ios_base::uppercase) << std::setw(2) << std::setfill('0') << static_cast<int>(reinterpret_cast<const unsigned char*>(&value)[index]) << std::resetiosflags(std::ios_base::dec) << std::dec;
  os << (size < sizeof(value) ? std::basic_string<char_t> {'-', '.', '.', '.'} : std::basic_string<char_t> {}) << '>';
  return os;
}*/

template <typename char_t, typename char_traits_t>
inline std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const std::exception& value) {
  return os << "exception: " << value.what();
}

template <typename char_t, typename char_traits_t, typename value_t>
inline std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const std::optional<value_t>& value) {
  if (!value.has_value()) return os << "(null)";
  return os << '(' << value.value() << ')';
}

template <typename char_t, typename char_traits_t, typename type1_t, typename type2_t>
inline std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const std::pair<type1_t, type2_t>& value) {
  return os << '(' << value.first << ',' << ' ' << value.second << ')';
}

template<typename char_t, typename char_traits_t, typename type_t, unsigned n_t, unsigned last_t>
struct __xtd_console_tuple_printer {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const type_t& value) {
    os << std::get<n_t>(value) << ',' << ' ';
    __xtd_console_tuple_printer<char_t, char_traits_t, type_t, n_t + 1, last_t>::print(os, value);
  }
};

template<typename char_t, typename char_traits_t, typename type_t, unsigned n_t>
struct __xtd_console_tuple_printer<char_t, char_traits_t, type_t, n_t, n_t> {
  static void print(std::basic_ostream<char_t, char_traits_t>& os, const type_t& value) {
    os << std::get<n_t>(value);
  }
};

template <typename char_t, typename char_traits_t, typename ... types_t>
inline std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const std::tuple<types_t ...>& value) {
  os << '(';
  __xtd_console_tuple_printer<char_t, char_traits_t, std::tuple<types_t ...>, 0, sizeof...(types_t) - 1>::print(os, value);
  return os << ')';
}

/*
template <typename char_t, typename char_traits_t, typename ... Args>
inline std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const std::variant<Args ...>& value) {
  std::visit([&](auto && t){
    os << t;
  }, value);
  return os;
}*/

template <typename char_t, typename char_traits_t, typename iterator_t>
inline std::basic_ostream<char_t, char_traits_t>& __xtd_console_print_sequence_container(std::basic_ostream<char_t, char_traits_t>& os, const iterator_t& begin, const iterator_t& end) {
  os << '[';
  bool first = true;
  for (iterator_t it = begin; it != end; ++it) {
    if (!first) os << ',' << ' ';
    os << *it;
    first = false;
  }
  return os << ']';
}

template <typename char_t, typename char_traits_t, typename type_t, size_t size_t>
inline std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const std::array<type_t, size_t>& values) {
  return __xtd_console_print_sequence_container(os, values.begin(), values.end());
}

template <typename char_t, typename char_traits_t, typename type_t, class allocator_t = std::allocator<type_t>>
inline std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const std::deque<type_t, allocator_t>& values) {
  return __xtd_console_print_sequence_container(os, values.begin(), values.end());
}

template <typename char_t, typename char_traits_t, typename type_t, class allocator_t = std::allocator<type_t>>
inline std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const std::forward_list<type_t, allocator_t>& values) {
  return __xtd_console_print_sequence_container(os, values.begin(), values.end());
}

template <typename char_t, typename char_traits_t, typename type_t>
inline std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const std::initializer_list<type_t>& values) {
  return __xtd_console_print_sequence_container(os, values.begin(), values.end());
}

template <typename char_t, typename char_traits_t, typename type_t, class allocator_t = std::allocator<type_t>>
inline std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const std::list<type_t, allocator_t>& values) {
  return __xtd_console_print_sequence_container(os, values.begin(), values.end());
}

template <typename char_t, typename char_traits_t, typename type_t>
inline std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const std::valarray<type_t>& values) {
  return __xtd_console_print_sequence_container(os, std::begin(values), std::end(values));
}

template <typename char_t, typename char_traits_t, typename type_t, class allocator_t = std::allocator<type_t>>
inline std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const std::vector<type_t, allocator_t>& values) {
  return __xtd_console_print_sequence_container(os, values.begin(), values.end());
}

template <typename char_t, typename char_traits_t, typename iterator_t>
inline std::basic_ostream<char_t, char_traits_t>& __xtd_console_print_associative_container(std::basic_ostream<char_t, char_traits_t>& os, const iterator_t& begin, const iterator_t& end) {
  os << "{";
  bool first = true;
  for (iterator_t it = begin; it != end; ++it) {
    if (!first) os << ", ";
      os << *it;
    first = false;
  }
  return os << "}";
}

template <typename char_t, typename char_traits_t, typename key_t, typename value_t, typename Compare = std::less<key_t>, typename allocator_t = std::allocator<std::pair<const key_t, value_t> >>
inline std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const std::map<key_t, value_t, Compare, allocator_t>& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

template <typename char_t, typename char_traits_t, typename key_t, typename value_t, typename Compare = std::less<key_t>, typename allocator_t = std::allocator<std::pair<const key_t, value_t> >>
inline std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const std::multimap<key_t, value_t, Compare, allocator_t>& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

template <typename char_t, typename char_traits_t, typename key_t, typename Compare = std::less<key_t>, typename allocator_t = std::allocator<key_t>>
inline std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const std::multiset<key_t, Compare, allocator_t>& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

template <typename char_t, typename char_traits_t, typename key_t, typename Compare = std::less<key_t>, typename allocator_t = std::allocator<key_t>>
inline std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const std::set<key_t, Compare, allocator_t>& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

template <typename char_t, typename char_traits_t, typename key_t, typename value_t, typename pred_t = std::equal_to<key_t>, typename allocator_t = std::allocator<std::pair<const key_t, value_t> >>
inline std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const std::unordered_map<key_t, value_t, pred_t, allocator_t>& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

template <typename char_t, typename char_traits_t, typename key_t, typename value_t, typename pred_t = std::equal_to<key_t>, typename allocator_t = std::allocator<std::pair<const key_t, value_t> >>
inline std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const std::unordered_multimap<key_t, value_t, pred_t, allocator_t>& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

template <typename char_t, typename char_traits_t, typename key_t, typename pred_t = std::equal_to<key_t>, typename allocator_t = std::allocator<key_t>>
std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const std::unordered_multiset<key_t, pred_t, allocator_t>& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

template <typename char_t, typename char_traits_t, typename key_t, typename pred_t = std::equal_to<key_t>, typename allocator_t = std::allocator<key_t>>
inline std::basic_ostream<char_t, char_traits_t>& operator<<(std::basic_ostream<char_t, char_traits_t>& os, const std::unordered_set<key_t, pred_t, allocator_t>& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}
/// @endcond
