/// @file
/// @brief Contains xtd::to_string methods.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_TO_STRING_INTERNAL__)
#error "Do not include this file: Internal use only. Include <xtd/to_string> or <xtd/to_string.hpp> instead."
#endif
/// @endcond

//#include "globalization/culture_info.hpp"
#include "to_string.hpp"

/// @cond
template<class value_t>
inline xtd::string xtd::to_string(const value_t& value, const xtd::string& fmt, const std::locale& loc) {
  return __to_string_polymorphic(value, fmt, loc, std::is_polymorphic<value_t>());
}

template<>
inline xtd::string xtd::to_string(const bool& value, const xtd::string& fmt, const std::locale& loc) {
  return __boolean_formatter(fmt.chars(), value, loc);
}

template<>
inline xtd::string xtd::to_string(const sbyte& value, const xtd::string& fmt, const std::locale& loc) {
  return __numeric_formatter(fmt.chars(), value, loc);
}

template<>
inline xtd::string xtd::to_string(const char& value, const xtd::string& fmt, const std::locale& loc) {
  return __character_formatter(fmt.chars(), value, loc);
}

template<>
inline xtd::string xtd::to_string(const unsigned char& value, const xtd::string& fmt, const std::locale& loc) {
  return __numeric_formatter(fmt.chars(), value, loc);
}

template<>
inline xtd::string xtd::to_string(const short& value, const xtd::string& fmt, const std::locale& loc) {
  return __numeric_formatter(fmt.chars(), value, loc);
}

template<>
inline xtd::string xtd::to_string(const unsigned short& value, const xtd::string& fmt, const std::locale& loc) {
  return __numeric_formatter(fmt.chars(), value, loc);
}

template<>
inline xtd::string xtd::to_string(const int& value, const xtd::string& fmt, const std::locale& loc) {
  return __numeric_formatter(fmt.chars(), value, loc);
}

template<>
inline xtd::string xtd::to_string(const unsigned int& value, const xtd::string& fmt, const std::locale& loc) {
  return __numeric_formatter(fmt.chars(), value, loc);
}

template<>
inline xtd::string xtd::to_string(const long& value, const xtd::string& fmt, const std::locale& loc) {
  return __numeric_formatter(fmt.chars(), value, loc);
}

template<>
inline xtd::string xtd::to_string(const unsigned long& value, const xtd::string& fmt, const std::locale& loc) {
  return __numeric_formatter(fmt.chars(), value, loc);
}

template<>
inline xtd::string xtd::to_string(const long long& value, const xtd::string& fmt, const std::locale& loc) {
  return __numeric_formatter(fmt.chars(), value, loc);
}

template<>
inline xtd::string xtd::to_string(const unsigned long long& value, const xtd::string& fmt, const std::locale& loc) {
  return __numeric_formatter(fmt.chars(), value, loc);
}

template<>
inline xtd::string xtd::to_string(const float& value, const xtd::string& fmt, const std::locale& loc) {
  return __floating_point_formatter(fmt.chars(), value, loc);
}

template<>
inline xtd::string xtd::to_string(const double& value, const xtd::string& fmt, const std::locale& loc) {
  return __floating_point_formatter(fmt.chars(), value, loc);
}

template<>
inline xtd::string xtd::to_string(const long double& value, const xtd::string& fmt, const std::locale& loc) {
  return __floating_point_formatter(fmt.chars(), value, loc);
}

template<>
inline xtd::string xtd::to_string(const std::chrono::system_clock::time_point& value, const xtd::string& fmt, const std::locale& loc) {
  return __date_time_formatter(fmt.chars(), std::chrono::system_clock::to_time_t(value), std::chrono::duration_cast<std::chrono::nanoseconds>(value.time_since_epoch()).count() % 1000000000, loc);
}

template<>
inline xtd::string xtd::to_string(const std::tm& value, const xtd::string& fmt, const std::locale& loc) {
  return __date_time_formatter(fmt.chars(), value, 0, loc);
}

template<class type_t, class period_t>
inline xtd::string xtd::to_string(const std::chrono::duration<type_t, period_t>& value, const xtd::string& fmt, const std::locale& loc) {
  return __duration_formatter(fmt.chars(), value, loc);
}

template<>
inline xtd::string xtd::to_string(const char8& value, const xtd::string& fmt, const std::locale& loc) {
  return __character_formatter(fmt.chars(), value, loc);
}

template<>
inline xtd::string xtd::to_string(const char16& value, const xtd::string& fmt, const std::locale& loc) {
  return __character_formatter(fmt.chars(), value, loc);
}

template<>
inline xtd::string xtd::to_string(const char32& value, const xtd::string& fmt, const std::locale& loc) {
  return __character_formatter(fmt.chars(), value, loc);
}

template<>
inline xtd::string xtd::to_string(const wchar& value, const xtd::string& fmt, const std::locale& loc) {
  return __character_formatter(fmt.chars(), value, loc);
}

template<class value_t>
inline xtd::string xtd::to_string(const value_t& value, const xtd::string& fmt) {
  return to_string(value, fmt, std::locale());
}

inline xtd::string xtd::to_string(const char*  value, const xtd::string& fmt) {
  return to_string(value, fmt, std::locale());
}

template<>
inline xtd::string xtd::to_string(const std::partial_ordering& value, const xtd::string& fmt, const std::locale& loc) {
  if (value == std::partial_ordering::less) return "less";
  if (value == std::partial_ordering::greater) return "greater";
  return "equivalent";
}

template<>
inline xtd::string xtd::to_string(const std::strong_ordering& value, const xtd::string& fmt, const std::locale& loc) {
  if (value == std::strong_ordering::less) return "less";
  if (value == std::strong_ordering::greater) return "greater";
  return "equivalent";
}

template<>
inline xtd::string xtd::to_string(const std::weak_ordering& value, const xtd::string& fmt, const std::locale& loc) {
  if (value == std::weak_ordering::less) return "less";
  if (value == std::weak_ordering::greater) return "greater";
  return "equivalent";
}

template<class value_t>
inline xtd::string xtd::to_string(const value_t* value, const xtd::string& fmt, const std::locale& loc) {
  if (!value) return "(null)";
  return __numeric_formatter(fmt.chars(), reinterpret_cast<intptr>(value), loc);
}

template<class value_t>
inline xtd::string xtd::to_string(value_t* const value, const xtd::string& fmt, const std::locale& loc) {
  if (!value) return "(null)";
  return __numeric_formatter(fmt.chars(), reinterpret_cast<intptr>(value), loc);
}

template<class type_t>
inline xtd::string xtd::to_string(const std::shared_ptr<type_t>& value, const xtd::string& fmt, const std::locale& loc) {
  if (!value) return "(null)";
  return __numeric_formatter(fmt.chars(), reinterpret_cast<intptr>(value.get()), loc);
}

template<class type_t>
inline xtd::string xtd::to_string(const std::unique_ptr<type_t>& value, const xtd::string& fmt, const std::locale& loc) {
  if (!value) return "(null)";
  return __numeric_formatter(fmt.chars(), reinterpret_cast<intptr>(value.get()), loc);
}

template<>
inline xtd::string xtd::to_string(const xtd::any& value, const xtd::string& fmt, const std::locale& loc) {
  auto iterator = __any_stringer__.find(std::type_index(value.type()));
  return iterator != __any_stringer__.cend() ? xtd::to_string(iterator->second(value), fmt, loc) : "(unregistered)";
}

template<class type_t>
inline xtd::string xtd::to_string(const std::optional<type_t>& value, const xtd::string& fmt, const std::locale& loc) {
  return !value.has_value() ? "(null)" : std::string {"("} + to_string(value.value(), fmt, loc).chars() + std::string {")"};
}

template<>
inline xtd::string xtd::to_string(const std::nullopt_t& value, const xtd::string& fmt, const std::locale& loc) {
  return "(null)";
}

template<>
inline xtd::string xtd::to_string(const std::nullptr_t&, const xtd::string& fmt, const std::locale& loc) {
  return "null";
}

template<class type1_t, class type2_t>
inline xtd::string xtd::to_string(const std::pair<type1_t, type2_t>& value, const xtd::string& fmt, const std::locale& loc) {
  return std::string {"("} + to_string(value.first, fmt, loc).chars() + std::string {", "} + to_string(value.second, fmt, loc).chars() + std::string {")"};
}

template<class type_t, unsigned n_t, unsigned last_t>
inline xtd::string xtd::__xtd_tuple_stringer<type_t, n_t, last_t>::to_string(const std::string& str, const type_t& value, const xtd::string& fmt, const std::locale& loc) {
  return __xtd_tuple_stringer < type_t, n_t + 1, last_t >::to_string(str + xtd::to_string(std::get<n_t>(value), fmt, loc).chars() + ", ", value, fmt, loc);
}

template<class type_t, unsigned n_t>
inline xtd::string xtd::__xtd_tuple_stringer<type_t, n_t, n_t>::to_string(const std::string& str, const type_t& value, const xtd::string& fmt, const std::locale& loc) {
  return str + xtd::to_string(std::get<n_t>(value), fmt, loc).chars();
}

template<class ...types_t>
inline xtd::string xtd::to_string(const std::tuple<types_t ...>& value, const xtd::string& fmt, const std::locale& loc) {
  return __xtd_tuple_stringer < std::tuple<types_t ...>, 0, sizeof...(types_t) - 1 >::to_string(std::string {"("}, value, fmt, loc) + ")";
}

template<class iterator_t>
inline std::string __xtd_iterator_to_string(const std::string& str, iterator_t iterator, const iterator_t& begin, const iterator_t& end, const xtd::string& fmt, const std::locale& loc) {
  if (iterator == end) return str;
  auto new_str = str + (iterator == begin ? std::string {} : std::string {", "}) + xtd::to_string(*iterator, fmt, loc).chars();
  return __xtd_iterator_to_string(new_str, ++iterator, begin, end, fmt, loc);
}

template<class iterator_t>
inline std::string __xtd_sequence_container_to_string(const iterator_t& begin, const iterator_t& end, const xtd::string& fmt, const std::locale& loc) {
  return __xtd_iterator_to_string("[", begin, begin, end, fmt, loc) + "]";
}

template<class type_t, size_t size>
inline xtd::string xtd::to_string(const std::array<type_t, size>& values, const xtd::string& fmt, const std::locale& loc) {
  return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<class type_t, class allocator_t>
inline xtd::string xtd::to_string(const std::deque<type_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) {
  return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<class type_t, class allocator_t>
inline xtd::string xtd::to_string(const std::forward_list<type_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) {
  return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<class type_t>
inline xtd::string xtd::to_string(const std::initializer_list<type_t>& values, const xtd::string& fmt, const std::locale& loc) {
  return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<class type_t, class allocator_t>
inline xtd::string xtd::to_string(const std::list<type_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) {
  return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<class type_t, class container_t>
inline xtd::string xtd::to_string(const std::queue<type_t, container_t>& values, const xtd::string& fmt, const std::locale& loc) {
  struct std_queue : public std::queue<type_t> {
    std_queue(const std::queue<type_t>& queue) : ptr {reinterpret_cast<const std_queue*>(&queue)} {}
    auto begin() const {return ptr->c.begin();}
    auto end() const {return ptr->c.end();}
    const std_queue* ptr;
  };
  auto items = std_queue {values};
  return __xtd_sequence_container_to_string(items.begin(), items.end(), fmt, loc);
}

template<class type_t, class container_t>
inline xtd::string xtd::to_string(const std::stack<type_t, container_t>& values, const xtd::string& fmt, const std::locale& loc) {
  struct std_stack : public std::stack<type_t> {
    std_stack(const std::stack<type_t>& queue) : ptr {reinterpret_cast<const std_stack*>(&queue)} {}
    auto begin() const {return ptr->c.begin();}
    auto end() const {return ptr->c.end();}
    const std_stack* ptr;
  };
  auto items = std_stack {values};
  return __xtd_sequence_container_to_string(items.begin(), items.end(), fmt, loc);
}

template<class type_t>
inline xtd::string xtd::to_string(const std::valarray<type_t>& values, const xtd::string& fmt, const std::locale& loc) {
  return __xtd_sequence_container_to_string(std::begin(values), std::end(values), fmt, loc);
}

template<class type_t, class allocator_t>
inline xtd::string xtd::to_string(const std::vector<type_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) {
  return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<class iterator_t>
inline std::string __xtd_associative_container_to_string(const iterator_t& begin, const iterator_t& end, const xtd::string& fmt, const std::locale& loc) {
  return __xtd_iterator_to_string("{", begin, begin, end, fmt, loc) + "}";
}

template<class key_t, class value_t, class compare_t, class allocator_t>
inline xtd::string xtd::to_string(const std::map<key_t, value_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) {
  return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<class key_t, class value_t, class compare_t, class allocator_t>
inline xtd::string xtd::to_string(const std::multimap<key_t, value_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) {
  return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<class key_t, class compare_t, class allocator_t>
inline xtd::string xtd::to_string(const std::multiset<key_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) {
  return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<class key_t, class compare_t, class allocator_t>
inline xtd::string xtd::to_string(const std::set<key_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) {
  return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<class key_t, class value_t, class compare_t, class allocator_t>
inline xtd::string xtd::to_string(const std::unordered_map<key_t, value_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) {
  return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<class key_t, class value_t, class compare_t, class allocator_t>
inline xtd::string xtd::to_string(const std::unordered_multimap<key_t, value_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) {
  return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<class key_t, class compare_t, class allocator_t>
inline xtd::string xtd::to_string(const std::unordered_multiset<key_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) {
  return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<class key_t, class compare_t, class allocator_t>
inline xtd::string xtd::to_string(const std::unordered_set<key_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) {
  return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<class type_t>
inline xtd::string xtd::to_string(type_t value, const std::initializer_list<std::pair<type_t, xtd::string>>& il) {
  std::map<type_t, xtd::string, std::greater<type_t>> values;
  for (auto item : il) values[item.first] = item.second;
  return to_string(value, values);
}

#if defined(__xtd__cpp_lib_ranges)
//template <std::ranges::range range_t>
//inline xtd::string xtd::to_string(const range_t& values, const xtd::string& fmt, const std::locale& loc) {
//  return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);
//}
/*
template <std::ranges::range range_t>
inline xtd::string to_string(const range_t& values, const xtd::string& fmt, const std::locale& loc) {
  std::ostringstream oss;
  oss.imbue(loc);

  oss << "[";
  bool first = true;
  for (auto&& v : values) {
    if (!first) oss << ", ";
    first = false;
    oss << xtd::to_string(v, fmt, loc);
  }
  oss << "]";
  return oss.str();
}
*/
#endif

template<class type_t>
inline xtd::string xtd::to_string(const xtd::collections::generic::ienumerable<type_t>& values, const xtd::string& fmt, const std::locale& loc) {
  return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<class type_t>
inline xtd::string xtd::to_string(const __xtd_raw_array_data__<type_t>& values, const xtd::string& fmt, const std::locale& loc) {
  return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<class type_t, class string_t>
inline string_t xtd::to_string(type_t value, const std::map<type_t, string_t, std::greater<type_t>>& values) {
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

template<class type_t, class string_t>
inline string_t xtd::to_string(type_t value, const std::map<type_t, string_t>& values) {
  std::map<type_t, string_t, std::greater<type_t>> descending_values;
  for (auto item : values) descending_values[item.first] = item.second;
  return to_string(value, descending_values);
}

template<class char_t, class value_t>
inline std::basic_string<char_t> __string_formatter(const std::basic_string<char_t>& fmt, value_t value, const std::locale& loc) {
  return __format_stringer<char_t>(value);
}

template < >
inline std::string __format_stringer < char, bool& > (bool& value) {
  return xtd::to_string(value, "G", std::locale());
}

template < >
inline std::string __format_stringer < char, xtd::sbyte& > (xtd::sbyte& value) {
  return xtd::to_string(value, "G", std::locale());
}

template < >
inline std::string __format_stringer < char, const unsigned char& > (const unsigned char& value) {
  return xtd::to_string(value, "G", std::locale());
}

template < >
inline std::string __format_stringer < char, unsigned char& > (unsigned char& value) {
  return xtd::to_string(value, "G", std::locale());
}

template < >
inline std::string __format_stringer < char, short& > (short& value) {
  return xtd::to_string(value, "G", std::locale());
}

template < >
inline std::string __format_stringer < char, unsigned short& > (unsigned short& value) {
  return xtd::to_string(value, "G", std::locale());
}

template < >
inline std::string __format_stringer < char, int& > (int& value) {
  return xtd::to_string(value, "G", std::locale());
}

template < >
inline std::string __format_stringer < char, unsigned int& > (unsigned int& value) {
  return xtd::to_string(value, "G", std::locale());
}

template < >
inline std::string __format_stringer < char, long& > (long& value) {
  return xtd::to_string(value, "G", std::locale());
}

template < >
inline std::string __format_stringer < char, unsigned long& > (unsigned long& value) {
  return xtd::to_string(value, "G", std::locale());
}

template < >
inline std::string __format_stringer < char, long long& > (long long& value) {
  return xtd::to_string(value, "G", std::locale());
}

template < >
inline std::string __format_stringer < char, unsigned long long& > (unsigned long long& value) {
  return xtd::to_string(value, "G", std::locale());
}

template < >
inline std::string __format_stringer < char, float& > (float& value) {
  return xtd::to_string(value, "G", std::locale());
}

template < >
inline std::string __format_stringer < char, double& > (double& value) {
  return xtd::to_string(value, "G", std::locale());
}

template < >
inline std::string __format_stringer < char, long double& > (long double& value) {
  return xtd::to_string(value, "G", std::locale());
}

template < >
inline std::string __format_stringer < char, std::chrono::system_clock::time_point& > (std::chrono::system_clock::time_point& value) {
  return xtd::to_string(value, "G", std::locale());
}

template < >
inline std::string __format_stringer < char, std::tm& > (tm& value) {
  return xtd::to_string(value, "G", std::locale());
}

template < >
inline std::string __format_stringer < char, xtd::wchar& > (xtd::wchar& value) {
  return xtd::to_string(value, "G", std::locale());
}

template < >
inline std::string __format_stringer < char, xtd::char8& > (xtd::char8& value) {
  return xtd::to_string(value, "G", std::locale());
}

template < >
inline std::string __format_stringer < char, xtd::char16& > (xtd::char16& value) {
  return xtd::to_string(value, "G", std::locale());
}

template < >
inline std::string __format_stringer < char, xtd::char32& > (xtd::char32& value) {
  return xtd::to_string(value, "G", std::locale());
}

template<class char_t, class type_t, class period_t = std::ratio<1>>
std::basic_ostream<char_t>& operator <<(std::basic_ostream<char_t>& os, const std::chrono::duration<type_t, period_t>& value) {
  return os << xtd::to_string(value, std::basic_string<char_t> {'G'}, std::locale());
}

template < class char_t, class type_t >
struct __enum_ostream__ < char_t, type_t, std::false_type > {
  std::basic_ostream < char_t >& to_stream(std::basic_ostream < char_t >& os, const type_t& value) noexcept {
    //return os << value;
    return os << xtd::to_string(value, std::basic_string < char_t > {}, std::locale {});
  }
};
/// @endcond
