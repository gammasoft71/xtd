/// @file
/// @brief Contains generic stream output methods.
#pragma once

#include <array>
#if !__APPLE__ || __MAC_OS_X_VERSION_MAX_ALLOWED >= 101401
#include <optional>
#endif
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
template <typename Char, typename CharTraits, typename Type>
std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const Type& value) {
  size_t size = sizeof(value) > 32 ? 32 : sizeof(value);
  os << sizeof(value) << std::basic_string<Char> {'-', 'b', 'y', 't', 'e', ' ', 'o', 'b', 'j', 'e', 'c', 't', '<'};
  for (size_t index = 0; index != size; index++)
    os <<  (index != 0 ? (index % 2 == 0 ? ' ' : '-') : '\0') << std::hex << std::setiosflags(std::ios_base::uppercase) << std::setw(2) << std::setfill('0') << static_cast<int>(reinterpret_cast<const unsigned char*>(&value)[index]) << std::resetiosflags(std::ios_base::dec) << std::dec;
  os << (size < sizeof(value) ? std::basic_string<Char> {'-', '.', '.', '.'} : std::basic_string<Char> {}) << '>';
  return os;
}*/

template <typename Char, typename CharTraits>
inline std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const std::exception& value) {
  return os << "exception: " << value.what();
}

#if !__APPLE__ || __MAC_OS_X_VERSION_MAX_ALLOWED >= 101401
template <typename Char, typename CharTraits, typename Value>
inline std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const std::optional<Value>& value) {
  if (!value.has_value()) return os << "(null)";
  return os << '(' << value.value() << ')';
}
#endif

template <typename Char, typename CharTraits, typename Type1, typename Type2>
inline std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const std::pair<Type1, Type2>& value) {
  return os << '(' << value.first << ',' << ' ' << value.second << ')';
}

template<typename Char, typename CharTraits, typename Type, unsigned N, unsigned Last>
struct __xtd_console_tuple_printer {
  static void print(std::basic_ostream<Char, CharTraits>& os, const Type& value) {
    os << std::get<N>(value) << ',' << ' ';
    __xtd_console_tuple_printer<Char, CharTraits, Type, N + 1, Last>::print(os, value);
  }
};

template<typename Char, typename CharTraits, typename Type, unsigned N>
struct __xtd_console_tuple_printer<Char, CharTraits, Type, N, N> {
  static void print(std::basic_ostream<Char, CharTraits>& os, const Type& value) {
    os << std::get<N>(value);
  }
};

template <typename Char, typename CharTraits, typename ... Types>
inline std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const std::tuple<Types ...>& value) {
  os << '(';
  __xtd_console_tuple_printer<Char, CharTraits, std::tuple<Types ...>, 0, sizeof...(Types) - 1>::print(os, value);
  return os << ')';
}

/*
template <typename Char, typename CharTraits, typename ... Args>
inline std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const std::variant<Args ...>& value) {
  std::visit([&](auto && t){
    os << t;
  }, value);
  return os;
}*/

template <typename Char, typename CharTraits, typename Iterator>
inline std::basic_ostream<Char, CharTraits>& __xtd_console_print_sequence_container(std::basic_ostream<Char, CharTraits>& os, const Iterator& begin, const Iterator& end) {
  os << '[';
  bool first = true;
  for (Iterator it = begin; it != end; ++it) {
    if (!first) os << ',' << ' ';
    os << *it;
    first = false;
  }
  return os << ']';
}

template <typename Char, typename CharTraits, typename Type, size_t Size>
inline std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const std::array<Type, Size>& values) {
  return __xtd_console_print_sequence_container(os, values.begin(), values.end());
}

template <typename Char, typename CharTraits, typename Type, class Allocator = std::allocator<Type>>
inline std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const std::deque<Type, Allocator>& values) {
  return __xtd_console_print_sequence_container(os, values.begin(), values.end());
}

template <typename Char, typename CharTraits, typename Type, class Allocator = std::allocator<Type>>
inline std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const std::forward_list<Type, Allocator>& values) {
  return __xtd_console_print_sequence_container(os, values.begin(), values.end());
}

template <typename Char, typename CharTraits, typename Type>
inline std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const std::initializer_list<Type>& values) {
  return __xtd_console_print_sequence_container(os, values.begin(), values.end());
}

template <typename Char, typename CharTraits, typename Type, class Allocator = std::allocator<Type>>
inline std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const std::list<Type, Allocator>& values) {
  return __xtd_console_print_sequence_container(os, values.begin(), values.end());
}

template <typename Char, typename CharTraits, typename Type>
inline std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const std::valarray<Type>& values) {
  return __xtd_console_print_sequence_container(os, std::begin(values), std::end(values));
}

template <typename Char, typename CharTraits, typename Type, class Allocator = std::allocator<Type>>
inline std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const std::vector<Type, Allocator>& values) {
  return __xtd_console_print_sequence_container(os, values.begin(), values.end());
}

template <typename Char, typename CharTraits, typename Iterator>
inline std::basic_ostream<Char, CharTraits>& __xtd_console_print_associative_container(std::basic_ostream<Char, CharTraits>& os, const Iterator& begin, const Iterator& end) {
  os << "{";
  bool first = true;
  for (Iterator it = begin; it != end; ++it) {
    if (!first) os << ", ";
      os << *it;
    first = false;
  }
  return os << "}";
}

template <typename Char, typename CharTraits, typename Key, typename Value, typename Compare = std::less<Key>, typename Allocator = std::allocator<std::pair<const Key, Value> >>
inline std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const std::map<Key, Value, Compare, Allocator>& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

template <typename Char, typename CharTraits, typename Key, typename Value, typename Compare = std::less<Key>, typename Allocator = std::allocator<std::pair<const Key, Value> >>
inline std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const std::multimap<Key, Value, Compare, Allocator>& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

template <typename Char, typename CharTraits, typename Key, typename Compare = std::less<Key>, typename Allocator = std::allocator<Key>>
inline std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const std::multiset<Key, Compare, Allocator>& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

template <typename Char, typename CharTraits, typename Key, typename Compare = std::less<Key>, typename Allocator = std::allocator<Key>>
inline std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const std::set<Key, Compare, Allocator>& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

template <typename Char, typename CharTraits, typename Key, typename Value, typename Pred = std::equal_to<Key>, typename Allocator = std::allocator<std::pair<const Key, Value> >>
inline std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const std::unordered_map<Key, Value, Pred, Allocator>& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

template <typename Char, typename CharTraits, typename Key, typename Value, typename Pred = std::equal_to<Key>, typename Allocator = std::allocator<std::pair<const Key, Value> >>
inline std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const std::unordered_multimap<Key, Value, Pred, Allocator>& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

template <typename Char, typename CharTraits, typename Key, typename Pred = std::equal_to<Key>, typename Allocator = std::allocator<Key>>
std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const std::unordered_multiset<Key, Pred, Allocator>& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

template <typename Char, typename CharTraits, typename Key, typename Pred = std::equal_to<Key>, typename Allocator = std::allocator<Key>>
inline std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const std::unordered_set<Key, Pred, Allocator>& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}
/// @endcond
