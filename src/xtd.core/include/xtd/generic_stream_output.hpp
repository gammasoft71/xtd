/// @file
/// @brief Contains generic stream output methods.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "stream_insertable.hpp"
#include "any.hpp"
#include "optional.hpp"
#include <array>
#include <deque>
#include <stdexcept>
#include <functional>
#include <forward_list>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <set>
#include <system_error>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <variant>
#include <vector>

/// @cond
extern std::unordered_map<std::type_index, std::function<std::string(xtd::any const&)>> __any_stringer__;

inline std::ostream& operator <<(std::ostream& os, const std::exception& value) {
  return os << "exception: " << value.what();
}

template<class value_t>
requires xtd::stream_insertable<value_t>
inline std::ostream& operator <<(std::ostream& os, const std::optional<value_t>& value) {
  if (!value.has_value()) return os << "(null)";
  return os << "(" << value.value() << ")";
}

template<class value_t>
requires (!xtd::stream_insertable<value_t>)
inline std::ostream& operator <<(std::ostream& os, const std::optional<value_t>&) {
  return os << "(unregistered)";
}

template<class type1_t, class type2_t>
requires xtd::stream_insertable<type1_t> && xtd::stream_insertable<type2_t>
inline std::ostream& operator <<(std::ostream& os, const std::pair<type1_t, type2_t>& value) {
  return os << "(" << value.first << ", " << value.second << ")";
}

template<class type1_t, class type2_t>
requires (!xtd::stream_insertable<type1_t> || !xtd::stream_insertable<type2_t>)
inline std::ostream& operator <<(std::ostream& os, const std::pair<type1_t, type2_t>& value) {
  return os << "( ,  )";
}

template<class type_t, unsigned n_t, unsigned last_t>
requires xtd::stream_insertable<decltype(std::get<n_t>(std::declval<type_t>()))>
struct __xtd_console_tuple_printer {
  static void print(std::ostream& os, const type_t& value) {
    os << std::get<n_t>(value);
    if constexpr (n_t < last_t) os << ", ";
    if constexpr (n_t < last_t)
      __xtd_console_tuple_printer<type_t, n_t + 1, last_t>::print(os, value);
  }
};

template<class ...types_t>
inline std::ostream& operator <<(std::ostream& os, const std::tuple<types_t ... >& value) {
  os << "(";
  __xtd_console_tuple_printer<std::tuple<types_t...>, 0, sizeof...(types_t) - 1>::print(os, value);
  return os << ")";
}

/*
template<class ...args_t>
inline std::ostream& operator <<(std::ostream& os, const std::variant<args_t ...>& value) {
  std::visit([&](auto && t){
    os << t;
  }, value);
  return os;
}*/

template<class iterator_t>
requires xtd::stream_insertable<std::iter_value_t<iterator_t>>
inline void __xtd_console_print_container(std::ostream& os, const iterator_t& begin, const iterator_t& end) {
  for (auto it = begin; it != end; ++it) {
    os << (it != begin ? ", " : "") << *it;
  }
}

template<class iterator_t>
requires (!xtd::stream_insertable<std::iter_value_t<iterator_t>>)
inline void __xtd_console_print_container(std::ostream& os, const iterator_t& begin, const iterator_t& end) {
  for (auto it = begin; it != end; ++it) {
    os << (it != begin ? ", " : "") << " ";
  }
}

template<class iterator_t>
inline std::ostream& __xtd_console_print_sequence_container(std::ostream& os, const iterator_t& begin, const iterator_t& end) {
  os << "[";
  __xtd_console_print_container(os, begin, end);
  return os << "]";
}

template<class type_t, size_t size_t>
inline std::ostream& operator <<(std::ostream& os, const std::array<type_t, size_t>& values) {
  return __xtd_console_print_sequence_container(os, values.begin(), values.end());
}

template<class type_t, class allocator_t = std::allocator < type_t>>
inline std::ostream& operator <<(std::ostream& os, const std::deque<type_t, allocator_t>& values) {
  return __xtd_console_print_sequence_container(os, values.begin(), values.end());
}

template<class type_t, class allocator_t = std::allocator<type_t>>
inline std::ostream& operator <<(std::ostream& os, const std::forward_list<type_t, allocator_t>& values) {
  return __xtd_console_print_sequence_container(os, values.begin(), values.end());
}

template<class type_t>
inline std::ostream& operator <<(std::ostream& os, const std::initializer_list<type_t>& values) {
  return __xtd_console_print_sequence_container(os, values.begin(), values.end());
}

template<class type_t, class allocator_t = std::allocator<type_t>>
inline std::ostream& operator <<(std::ostream& os, const std::list<type_t, allocator_t>& values) {
  return __xtd_console_print_sequence_container(os, values.begin(), values.end());
}

template<class type_t>
inline std::ostream& operator <<(std::ostream& os, const std::valarray<type_t>& values) {
  return __xtd_console_print_sequence_container(os, std::begin(values), std::end(values));
}

template<class type_t, class allocator_t = std::allocator<type_t>>
inline std::ostream& operator <<(std::ostream& os, const std::vector<type_t, allocator_t>& values) {
  return __xtd_console_print_sequence_container(os, values.begin(), values.end());
}

template<class iterator_t>
inline std::ostream& __xtd_console_print_associative_container(std::ostream& os, const iterator_t& begin, const iterator_t& end) {
  os << "{";
  __xtd_console_print_container(os, begin, end);
  return os << "}";
}

template<class key_t, class value_t, class compare_t = std::less <key_t>, class allocator_t = std::allocator<std::pair<const key_t, value_t>>>
inline std::ostream& operator <<(std::ostream& os, const std::map < key_t, value_t, compare_t, allocator_t >& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

template<class key_t, class value_t, class compare_t = std::less <key_t>, class allocator_t = std::allocator<std::pair<const key_t, value_t>>>
inline std::ostream& operator <<(std::ostream& os, const std::multimap < key_t, value_t, compare_t, allocator_t >& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

template<class key_t, class compare_t = std::less <key_t>, class allocator_t = std::allocator<key_t>>
inline std::ostream& operator <<(std::ostream& os, const std::multiset < key_t, compare_t, allocator_t >& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

template < class key_t, class compare_t = std::less < key_t>, class allocator_t = std::allocator<key_t >>
inline std::ostream& operator <<(std::ostream& os, const std::set < key_t, compare_t, allocator_t >& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

template < class key_t, class value_t, class pred_t = std::equal_to < key_t>, class allocator_t = std::allocator<std::pair<const key_t, value_t >>>
inline std::ostream& operator <<(std::ostream& os, const std::unordered_map < key_t, value_t, pred_t, allocator_t >& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

template < class key_t, class value_t, class pred_t = std::equal_to < key_t>, class allocator_t = std::allocator<std::pair<const key_t, value_t >>>
inline std::ostream& operator <<(std::ostream& os, const std::unordered_multimap < key_t, value_t, pred_t, allocator_t >& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

template < class key_t, class pred_t = std::equal_to < key_t>, class allocator_t = std::allocator<key_t >>
std::ostream& operator <<(std::ostream& os, const std::unordered_multiset < key_t, pred_t, allocator_t >& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

template < class key_t, class pred_t = std::equal_to < key_t>, class allocator_t = std::allocator<key_t >>
inline std::ostream& operator <<(std::ostream& os, const std::unordered_set < key_t, pred_t, allocator_t >& values) {
  return __xtd_console_print_associative_container(os, values.begin(), values.end());
}

inline std::ostream& operator <<(std::ostream& os, const std::error_category& value) {
  return os << "(" << value.name() << ")";
}

inline std::ostream& operator <<(std::ostream& os, const std::error_code& value) {
  return os << "(value = " << value.value() << "category= " << value.category().name() << ")";
}

namespace xtd {
  class iformatable;
  template <class type_t>
  class istringable;
}
auto operator << (std::ostream& os, const xtd::iformatable& value) -> std::ostream&;
template<class type_t>
auto operator << (std::ostream& os, const xtd::istringable<type_t>& value) noexcept -> std::ostream& {
  return os << value.to_string();
}
/// @endcond
