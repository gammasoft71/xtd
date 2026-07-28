/// @file
/// @brief Contains xtd::to_string methods.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_TO_STRING_INTERNAL__)
#error "Do not include this file: Internal use only. Include <xtd/to_string> or <xtd/to_string.hpp> instead."
#endif
/// @endcond

//#include "globalization/culture_info.hpp"
#include "stream_insertable.hpp"
#include "to_string.hpp"

/// @cond
template<xtd::iterable range_t>
[[nodiscard]] auto __xtd_iterable_to_string(const range_t& values, const xtd::string& fmt, const std::locale& loc) -> std::string;

template<typename value_t>
[[nodiscard]] inline auto xtd::to_string(const value_t& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  if constexpr(std::is_polymorphic_v<value_t>) return __to_string_polymorphic(value, fmt, loc);
  else if constexpr(std::is_enum_v<value_t>) return __enum_formatter<char>(fmt, value, loc);
  else if constexpr(xtd::iterable<value_t> && !std::is_same_v<value_t, xtd::string>) return __xtd_iterable_to_string(value, fmt, loc);
  else if constexpr(xtd::stream_insertable<value_t>) {
    auto ss = std::stringstream {};
    ss << value;
    return ss.str();
  } else xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format);
}

template<class value_t>
requires (requires (const xtd::raw_type<value_t>& value, const xtd::string& fmt) {{value.to_string(fmt)} -> xtd::textual;})
[[nodiscard]] inline auto xtd::to_string(const value_t& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return value.to_string(fmt);
}

template<class value_t>
requires (!requires (const xtd::raw_type<value_t>& value, const xtd::string& fmt) {{value.to_string(fmt)} -> xtd::textual;} && requires (const xtd::raw_type<value_t>& value) {{value.to_string()} -> xtd::textual;})
[[nodiscard]] inline auto xtd::to_string(const value_t& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return value.to_string();
}

template<>
[[nodiscard]] inline auto xtd::to_string(const bool& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __boolean_formatter(fmt.chars(), value, loc);
}

template<>
[[nodiscard]] inline auto xtd::to_string(const sbyte& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __numeric_formatter(fmt.chars(), value, loc);
}

template<>
[[nodiscard]] inline auto xtd::to_string(const char& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __character_formatter(fmt.chars(), value, loc);
}

template<>
[[nodiscard]] inline auto xtd::to_string(const unsigned char& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __numeric_formatter(fmt.chars(), value, loc);
}

template<>
[[nodiscard]] inline auto xtd::to_string(const short& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __numeric_formatter(fmt.chars(), value, loc);
}

template<>
[[nodiscard]] inline auto xtd::to_string(const unsigned short& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __numeric_formatter(fmt.chars(), value, loc);
}

template<>
[[nodiscard]] inline auto xtd::to_string(const int& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __numeric_formatter(fmt.chars(), value, loc);
}

template<>
[[nodiscard]] inline auto xtd::to_string(const unsigned int& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __numeric_formatter(fmt.chars(), value, loc);
}

template<>
[[nodiscard]] inline auto xtd::to_string(const long& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __numeric_formatter(fmt.chars(), value, loc);
}

template<>
[[nodiscard]] inline auto xtd::to_string(const unsigned long& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __numeric_formatter(fmt.chars(), value, loc);
}

template<>
[[nodiscard]] inline auto xtd::to_string(const long long& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __numeric_formatter(fmt.chars(), value, loc);
}

template<>
[[nodiscard]] inline auto xtd::to_string(const unsigned long long& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __numeric_formatter(fmt.chars(), value, loc);
}

template<>
[[nodiscard]] inline auto xtd::to_string(const float& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __floating_point_formatter(fmt.chars(), value, loc);
}

template<>
[[nodiscard]] inline auto xtd::to_string(const double& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __floating_point_formatter(fmt.chars(), value, loc);
}

template<>
[[nodiscard]] inline auto xtd::to_string(const long double& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __floating_point_formatter(fmt.chars(), value, loc);
}

template<>
[[nodiscard]] inline auto xtd::to_string(const std::chrono::system_clock::time_point& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __date_time_formatter(fmt.chars(), std::chrono::system_clock::to_time_t(value), std::chrono::duration_cast<std::chrono::nanoseconds>(value.time_since_epoch()).count() % 1000000000, loc);
}

template<>
[[nodiscard]] inline auto xtd::to_string(const std::tm& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __date_time_formatter(fmt.chars(), value, 0, loc);
}

template<typename type_t, typename period_t>
[[nodiscard]] inline auto xtd::to_string(const std::chrono::duration<type_t, period_t>& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __duration_formatter(fmt.chars(), value, loc);
}

template<>
[[nodiscard]] inline auto xtd::to_string(const char8& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __character_formatter(fmt.chars(), value, loc);
}

template<>
[[nodiscard]] inline auto xtd::to_string(const char16& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __character_formatter(fmt.chars(), value, loc);
}

template<>
[[nodiscard]] inline auto xtd::to_string(const char32& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __character_formatter(fmt.chars(), value, loc);
}

template<>
[[nodiscard]] inline auto xtd::to_string(const wchar& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __character_formatter(fmt.chars(), value, loc);
}

template<typename value_t>
[[nodiscard]] inline auto xtd::to_string(const value_t& value, const xtd::string& fmt) -> xtd::string {
  return to_string(value, fmt, std::locale());
}

[[nodiscard]] inline auto xtd::to_string(const char*  value, const xtd::string& fmt) -> xtd::string {
  return to_string(value, fmt, std::locale());
}

template<>
[[nodiscard]] inline auto xtd::to_string(const std::partial_ordering& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  if (value == std::partial_ordering::less) return "less";
  if (value == std::partial_ordering::greater) return "greater";
  return "equivalent";
}

template<>
[[nodiscard]] inline auto xtd::to_string(const std::strong_ordering& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  if (value == std::strong_ordering::less) return "less";
  if (value == std::strong_ordering::greater) return "greater";
  return "equivalent";
}

template<>
[[nodiscard]] inline auto xtd::to_string(const std::weak_ordering& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  if (value == std::weak_ordering::less) return "less";
  if (value == std::weak_ordering::greater) return "greater";
  return "equivalent";
}

template<typename value_t>
[[nodiscard]] inline auto xtd::to_string(const value_t* value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  if (!value) return "(null)";
  return __numeric_formatter(fmt.chars(), reinterpret_cast<intptr>(value), loc);
}

template<typename value_t>
[[nodiscard]] inline auto xtd::to_string(value_t* const value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  if (!value) return "(null)";
  return __numeric_formatter(fmt.chars(), reinterpret_cast<intptr>(value), loc);
}

template<typename type_t>
[[nodiscard]] inline auto xtd::to_string(const std::shared_ptr<type_t>& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  if (!value) return "(null)";
  return __numeric_formatter(fmt.chars(), reinterpret_cast<intptr>(value.get()), loc);
}

template<typename type_t>
[[nodiscard]] inline auto xtd::to_string(const std::unique_ptr<type_t>& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  if (!value) return "(null)";
  return __numeric_formatter(fmt.chars(), reinterpret_cast<intptr>(value.get()), loc);
}

template<>
[[nodiscard]] inline auto xtd::to_string(const xtd::any& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  auto iterator = __any_stringer__.find(std::type_index(value.type()));
  return iterator != __any_stringer__.cend() ? xtd::to_string(iterator->second(value), fmt, loc) : "(unregistered)";
}

template<typename type_t>
[[nodiscard]] inline auto xtd::to_string(const std::optional<type_t>& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return !value.has_value() ? "(null)" : std::string {"("} + to_string(value.value(), fmt, loc).chars() + std::string {")"};
}

template<>
[[nodiscard]] inline auto xtd::to_string(const std::nullopt_t& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return "(null)";
}

template<>
[[nodiscard]] inline auto xtd::to_string(const std::nullptr_t&, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return "null";
}

template<typename type1_t, typename type2_t>
[[nodiscard]] inline auto xtd::to_string(const std::pair<type1_t, type2_t>& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return std::string {"("} + to_string(value.first, fmt, loc).chars() + std::string {", "} + to_string(value.second, fmt, loc).chars() + std::string {")"};
}

template<typename type_t, unsigned n_t, unsigned last_t>
[[nodiscard]] inline auto xtd::__xtd_tuple_stringer<type_t, n_t, last_t>::to_string(const std::string& str, const type_t& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __xtd_tuple_stringer < type_t, n_t + 1, last_t >::to_string(str + xtd::to_string(std::get<n_t>(value), fmt, loc).chars() + ", ", value, fmt, loc);
}

template<typename type_t, unsigned n_t>
[[nodiscard]] inline auto xtd::__xtd_tuple_stringer<type_t, n_t, n_t>::to_string(const std::string& str, const type_t& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return str + xtd::to_string(std::get<n_t>(value), fmt, loc).chars();
}

template<typename ...types_t>
[[nodiscard]] inline auto xtd::to_string(const std::tuple<types_t ...>& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __xtd_tuple_stringer < std::tuple<types_t ...>, 0, sizeof...(types_t) - 1 >::to_string(std::string {"("}, value, fmt, loc) + ")";
}

template<typename iterator_t>
[[nodiscard]] inline auto __xtd_iterator_to_string(const std::string& str, iterator_t iterator, const iterator_t& begin, const iterator_t& end, const xtd::string& fmt, const std::locale& loc) -> std::string {
  if (iterator == end) return str;
  auto new_str = str + (iterator == begin ? std::string {} : std::string {", "}) + xtd::to_string(*iterator, fmt, loc).chars();
  return __xtd_iterator_to_string(new_str, ++iterator, begin, end, fmt, loc);
}

template<typename iterator_t>
[[nodiscard]] inline auto __xtd_sequence_container_to_string(const iterator_t& begin, const iterator_t& end, const xtd::string& fmt, const std::locale& loc) -> std::string {
  return __xtd_iterator_to_string("[", begin, begin, end, fmt, loc) + "]";
}

template<xtd::iterable iterable_t>
[[nodiscard]] inline auto __xtd_iterable_to_string(const iterable_t& values, const xtd::string& fmt, const std::locale& loc) -> std::string {
  std::ostringstream oss;
  oss.imbue(loc);
  oss << "[";
  auto first = true;
  auto& mutable_values = const_cast<iterable_t&>(values);
  for (const auto value : mutable_values) {
    if (!first) oss << ", ";
    first = false;
    oss << xtd::to_string(value, fmt, loc);
  }
  oss << "]";
  return oss.str();
}

template<typename type_t, xtd::usize size>
[[nodiscard]] inline auto xtd::to_string(const std::array<type_t, size>& values, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<xtd::usize size>
[[nodiscard]] inline auto xtd::to_string(const std::bitset<size>& values, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  auto result = xtd::string {"["};
  for (auto index = xtd::usize {0}; index < values.length(); ++index)
    result += (index ? ", " : "") + to_string(static_cast<bool>(values[index]), fmt, loc);
  return result + "]";
}

template<typename type_t, typename allocator_t>
[[nodiscard]] inline auto xtd::to_string(const std::deque<type_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<typename type_t, typename allocator_t>
[[nodiscard]] inline auto xtd::to_string(const std::forward_list<type_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<typename type_t>
[[nodiscard]] inline auto xtd::to_string(const std::initializer_list<type_t>& values, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<typename type_t, typename allocator_t>
[[nodiscard]] inline auto xtd::to_string(const std::list<type_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<typename type_t, typename container_t>
[[nodiscard]] inline auto xtd::to_string(const std::queue<type_t, container_t>& values, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  struct accessor : public std::queue<type_t> {static auto get() {return &accessor::c;}};
  const auto& underlying_items = values.*accessor::get();
  return __xtd_sequence_container_to_string(underlying_items.begin(), underlying_items.end(), fmt, loc);
}

template<typename type_t, typename container_t>
[[nodiscard]] inline auto xtd::to_string(const std::priority_queue<type_t, container_t>& values, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  struct std_priority_queue : public std::queue<type_t> {
    std_priority_queue(const std::priority_queue<type_t>& queue) : ptr {reinterpret_cast<const std_priority_queue*>(&queue)} {}
    auto begin() const {return ptr->c.begin();}
    auto end() const {return ptr->c.end();}
    const std_priority_queue* ptr;
  };
  auto items = std_priority_queue {values};
  return __xtd_sequence_container_to_string(items.begin(), items.end(), fmt, loc);
}

template<typename type_t, typename container_t>
[[nodiscard]] inline auto xtd::to_string(const std::stack<type_t, container_t>& values, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  struct accessor : public std::stack<type_t> {static auto get() {return &accessor::c;}};
  const auto& underlying_items = values.*accessor::get();
  return __xtd_sequence_container_to_string(underlying_items.rbegin(), underlying_items.rend(), fmt, loc);
}

template<typename type_t>
[[nodiscard]] inline auto xtd::to_string(const std::valarray<type_t>& values, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __xtd_sequence_container_to_string(std::begin(values), std::end(values), fmt, loc);
}

template<typename type_t, typename allocator_t>
[[nodiscard]] inline auto xtd::to_string(const std::vector<type_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<typename iterator_t>
[[nodiscard]] inline auto __xtd_associative_container_to_string(const iterator_t& begin, const iterator_t& end, const xtd::string& fmt, const std::locale& loc) -> std::string {
  return __xtd_iterator_to_string("{", begin, begin, end, fmt, loc) + "}";
}

template<typename key_t, typename value_t, typename compare_t, typename allocator_t>
[[nodiscard]] inline auto xtd::to_string(const std::map<key_t, value_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<typename key_t, typename value_t, typename compare_t, typename allocator_t>
[[nodiscard]] inline auto xtd::to_string(const std::multimap<key_t, value_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<typename key_t, typename compare_t, typename allocator_t>
[[nodiscard]] inline auto xtd::to_string(const std::multiset<key_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<typename key_t, typename compare_t, typename allocator_t>
[[nodiscard]] inline auto xtd::to_string(const std::set<key_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<typename key_t, typename value_t, typename compare_t, typename allocator_t>
[[nodiscard]] inline auto xtd::to_string(const std::unordered_map<key_t, value_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<typename key_t, typename value_t, typename compare_t, typename allocator_t>
[[nodiscard]] inline auto xtd::to_string(const std::unordered_multimap<key_t, value_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<typename key_t, typename compare_t, typename allocator_t>
[[nodiscard]] inline auto xtd::to_string(const std::unordered_multiset<key_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<typename key_t, typename compare_t, typename allocator_t>
[[nodiscard]] inline auto xtd::to_string(const std::unordered_set<key_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<typename ...args_t>
[[nodiscard]] inline auto xtd::to_string(const std::variant<args_t...>& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  if (value.valueless_by_exception()) return "(valueless_by_exception)";
  return std::visit([&](auto && t){return xtd::to_string(t, fmt, loc);}, value);
}

template<typename type_t>
[[nodiscard]] inline auto xtd::to_string(type_t value, const std::initializer_list<std::pair<type_t, xtd::string>>& il) -> xtd::string {
  std::map<type_t, xtd::string, std::greater<type_t>> values;
  for (const auto& item : il) values[item.first] = item.second;
  return to_string(value, values);
}

template<>
inline auto xtd::to_string(const std::filesystem::path& value, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return to_string(value.string(), fmt, loc);
}

template<typename type_t>
[[nodiscard]] inline auto xtd::to_string(const xtd::collections::generic::ienumerable<type_t>& values, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<typename type_t>
[[nodiscard]] inline auto xtd::to_string(const xtd::collections::generic::helpers::raw_array<type_t>& values, const xtd::string& fmt, const std::locale& loc) -> xtd::string {
  return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);
}

template<typename type_t, typename string_t>
[[nodiscard]] inline auto xtd::to_string(type_t value, const std::map<type_t, string_t, std::greater<type_t>>& values) -> string_t {
  auto it = values.find(value);
  if (it != values.end()) return it->second;
  string_t result;
  long long rest = static_cast<long long>(value);
  for (const auto& item : values) {
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
[[nodiscard]] inline auto xtd::to_string(type_t value, const std::map<type_t, string_t>& values) -> string_t {
  std::map<type_t, string_t, std::greater<type_t>> descending_values;
  for (const auto& item : values) descending_values[item.first] = item.second;
  return to_string(value, descending_values);
}

template<typename char_t, typename value_t>
[[nodiscard]] inline auto __string_formatter(const std::basic_string<char_t>& fmt, value_t value, const std::locale& loc) -> std::basic_string<char_t> {
  return __format_stringer<char_t>(value);
}

template<>
[[nodiscard]] inline auto __format_stringer<char, bool&>(bool& value) -> std::string {
  return xtd::to_string(value, "G", std::locale());
}

template<>
[[nodiscard]] inline auto __format_stringer<char, xtd::sbyte&>(xtd::sbyte& value) -> std::string {
  return xtd::to_string(value, "G", std::locale());
}

template<>
[[nodiscard]] inline auto __format_stringer<char, const unsigned char&>(const unsigned char& value) -> std::string {
  return xtd::to_string(value, "G", std::locale());
}

template<>
[[nodiscard]] inline auto __format_stringer<char, unsigned char&>(unsigned char& value) -> std::string {
  return xtd::to_string(value, "G", std::locale());
}

template<>
[[nodiscard]] inline auto __format_stringer<char, short&>(short& value) -> std::string {
  return xtd::to_string(value, "G", std::locale());
}

template<>
[[nodiscard]] inline auto __format_stringer<char, unsigned short&>(unsigned short& value) -> std::string {
  return xtd::to_string(value, "G", std::locale());
}

template<>
[[nodiscard]] inline auto __format_stringer<char, int&>(int& value) -> std::string {
  return xtd::to_string(value, "G", std::locale());
}

template<>
[[nodiscard]] inline auto __format_stringer<char, unsigned int&>(unsigned int& value) -> std::string {
  return xtd::to_string(value, "G", std::locale());
}

template<>
[[nodiscard]] inline auto __format_stringer<char, long&>(long& value) -> std::string {
  return xtd::to_string(value, "G", std::locale());
}

template<>
[[nodiscard]] inline auto __format_stringer<char, unsigned long&>(unsigned long& value) -> std::string {
  return xtd::to_string(value, "G", std::locale());
}

template<>
[[nodiscard]] inline auto __format_stringer<char, long long&>(long long& value) -> std::string {
  return xtd::to_string(value, "G", std::locale());
}

template<>
[[nodiscard]] inline auto __format_stringer<char, unsigned long long&>(unsigned long long& value) -> std::string {
  return xtd::to_string(value, "G", std::locale());
}

template<>
[[nodiscard]] inline auto __format_stringer<char, float&>(float& value) -> std::string {
  return xtd::to_string(value, "G", std::locale());
}

template<>
[[nodiscard]] inline auto __format_stringer<char, double&>(double& value) -> std::string {
  return xtd::to_string(value, "G", std::locale());
}

template<>
[[nodiscard]] inline auto __format_stringer<char, long double&>(long double& value) -> std::string {
  return xtd::to_string(value, "G", std::locale());
}

template<>
[[nodiscard]] inline auto __format_stringer<char, std::chrono::system_clock::time_point&>(std::chrono::system_clock::time_point& value) -> std::string {
  return xtd::to_string(value, "G", std::locale());
}

template<>
[[nodiscard]] inline auto __format_stringer<char, std::tm&>(tm& value) -> std::string {
  return xtd::to_string(value, "G", std::locale());
}

template<>
[[nodiscard]] inline auto __format_stringer<char, xtd::wchar&>(xtd::wchar& value) -> std::string {
  return xtd::to_string(value, "G", std::locale());
}

template<>
[[nodiscard]] inline auto __format_stringer<char, xtd::char8&>(xtd::char8& value) -> std::string {
  return xtd::to_string(value, "G", std::locale());
}

template<>
[[nodiscard]] inline auto __format_stringer<char, xtd::char16&>(xtd::char16& value) -> std::string {
  return xtd::to_string(value, "G", std::locale());
}

template<>
[[nodiscard]] inline auto __format_stringer<char, xtd::char32&>(xtd::char32& value) -> std::string {
  return xtd::to_string(value, "G", std::locale());
}

template<typename char_t, typename type_t, typename period_t = std::ratio<1>>
auto operator <<(std::basic_ostream<char_t>& os, const std::chrono::duration<type_t, period_t>& value) -> std::basic_ostream<char_t>& {
  return os << xtd::to_string(value, std::basic_string<char_t> {'G'}, std::locale());
}

template < class char_t, typename type_t >
struct __enum_ostream__<char_t, type_t, std::false_type> {
  auto to_stream(std::basic_ostream < char_t >& os, const type_t& value) noexcept -> std::basic_ostream<char_t>& {
    //return os << value;
    return os << xtd::to_string(value, std::basic_string < char_t > {}, std::locale {});
  }
};
/// @endcond
