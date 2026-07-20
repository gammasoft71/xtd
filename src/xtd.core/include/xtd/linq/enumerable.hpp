/// @file
/// @brief Contains xtd::linq::enumerable <type_t> class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "enumerable_.hpp" // contains xtd::linq::enumerable <type_t> class definition
#include "../collections/generic/extensions/enumerable.hpp"
#include "../collections/generic/enumerable_generator.hpp"
#include "../nullopt.hpp"
#include "from.hpp"

/// @cond
template<xtd::iterable source_t, xtd::func_callable<xtd::iterable_value_type<source_t>, xtd::iterable_value_type<source_t>, xtd::iterable_value_type<source_t>> func_t>
auto xtd::linq::enumerable::aggregate(const source_t& source, func_t&& func) -> xtd::iterable_value_type<source_t> {
  auto nb = 0;
  auto aggregated = xtd::iterable_value_type<source_t> {};
  for (const auto& item : source)
    aggregated = nb++ == 0 ? item : func(aggregated, item);
  return aggregated;
}

template<typename accumulate_t, xtd::iterable source_t, xtd::func_callable<accumulate_t, accumulate_t, xtd::iterable_value_type<source_t>> func_t>
auto xtd::linq::enumerable::aggregate(const source_t& source, accumulate_t&& seed, func_t&& func) -> accumulate_t {
  auto aggregated = std::move(seed);
  for (const auto& item : source)
    aggregated = func(aggregated, item);
  return aggregated;
}

template<typename result_t, typename accumulate_t, xtd::iterable source_t, xtd::func_callable<accumulate_t, accumulate_t, xtd::iterable_value_type<source_t>> func_t, xtd::func_callable<result_t, accumulate_t> result_selector_t>
auto xtd::linq::enumerable::aggregate(const source_t& source, accumulate_t&& seed, func_t&& func, result_selector_t&& result_selector) -> result_t {
  auto aggregated = std::move(seed);
  for (const auto& item : source)
    aggregated = func(aggregated, item);
  return result_selector(aggregated);
}

template<xtd::iterable source_t, xtd::predicate_callable<xtd::iterable_value_type<source_t>> predicate_t>
auto xtd::linq::enumerable::all(const source_t& source, predicate_t&& predicate) -> bool {
  for (const auto& item : source)
    if (!predicate(item)) return false;
  return true;
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::any(const source_t& source) noexcept -> bool {
  return source.begin() != source.end();
}

template<xtd::iterable source_t, xtd::predicate_callable<xtd::iterable_value_type<source_t>> predicate_t>
auto xtd::linq::enumerable::any(const source_t& source, predicate_t&& predicate) -> bool {
  for (const auto& item : source)
    if (predicate(item)) return true;
  return false;
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::append(const source_t& source, xtd::iterable_value_type<source_t>&& element) noexcept -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>> {
  for (const auto& item : source)
    co_yield item;
  co_yield std::move(element);
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::as_enumerable(const source_t& source) noexcept -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>> {
  for (const auto& item : source)
    co_yield item;
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::as_enumerable(source_t& source) noexcept -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>> {
  for (const auto& item : source)
    co_yield item;
}

template<typename value_t>
auto xtd::linq::enumerable::as_enumerable(std::initializer_list<value_t> source) noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
  for (const auto& item : source)
    co_yield item;
}

template<std::forward_iterator iterator_t>
auto xtd::linq::enumerable::as_enumerable(iterator_t first, iterator_t last) noexcept -> xtd::collections::generic::enumerable_generator<typename std::decay<decltype(*first)>::type> {
  for (auto iterator = first; iterator != last; ++iterator)
    co_yield *iterator;
}

template<std::forward_iterator iterator_t>
auto xtd::linq::enumerable::as_enumerable(iterator_t iterator, xtd::usize length) noexcept -> xtd::collections::generic::enumerable_generator<typename std::decay<decltype(*iterator)>::type> {
  return as_enumerable(iterator, iterator + length);
}

template<typename value_t, xtd::usize length>
auto xtd::linq::enumerable::as_enumerable(const value_t (&array)[length]) noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
  return as_enumerable(array, array + length);
}

template<typename value_t, xtd::usize length>
auto xtd::linq::enumerable::as_enumerable(value_t (&array)[length]) noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
  return as_enumerable(array, array + length);
}

template<typename value_t, typename container_t>
auto xtd::linq::enumerable::as_enumerable(const std::queue<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
  struct accessor : public std::queue<value_t> {static auto get() {return &accessor::c;}};
  const auto& underlying_items = source.*accessor::get();
  return as_enumerable(underlying_items.begin(), underlying_items.end());
}
template<typename value_t, typename container_t>
auto xtd::linq::enumerable::as_enumerable(std::queue<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
  struct accessor : public std::queue<value_t> {static auto get() {return &accessor::c;}};
  const auto& underlying_items = source.*accessor::get();
  return as_enumerable(underlying_items.begin(), underlying_items.end());
}
template<typename value_t, typename container_t>
auto xtd::linq::enumerable::as_enumerable(const std::priority_queue<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
  struct accessor : public std::priority_queue<value_t> {static auto get() {return &accessor::c;}};
  const auto& underlying_items = source.*accessor::get();
  return as_enumerable(underlying_items.begin(), underlying_items.end());
}
template<typename value_t, typename container_t>
auto xtd::linq::enumerable::as_enumerable(std::priority_queue<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
  struct accessor : public std::priority_queue<value_t> {static auto get() {return &accessor::c;}};
  const auto& underlying_items = source.*accessor::get();
  return as_enumerable(underlying_items.begin(), underlying_items.end());
}
template<typename value_t, typename container_t>
auto xtd::linq::enumerable::as_enumerable(const std::stack<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
  struct accessor : public std::stack<value_t> {static auto get() {return &accessor::c;}};
  const auto& underlying_items = source.*accessor::get();
  return as_enumerable(underlying_items.begin(), underlying_items.end());
}
template<typename value_t, typename container_t>
auto xtd::linq::enumerable::as_enumerable(std::stack<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
  struct accessor : public std::stack<value_t> {static auto get() {return &accessor::c;}};
  const auto& underlying_items = source.*accessor::get();
  return as_enumerable(underlying_items.begin(), underlying_items.end());
}

template<xtd::iterable source_t>
requires xtd::real_decimal<xtd::iterable_value_type<source_t>>
auto xtd::linq::enumerable::average(const source_t& source) -> xtd::decimal {
  auto average = .0l;
  auto count = 0;
  for (const auto& item : source) {
    average += item;
    ++count;
  }
  if (count == 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
  return average / count;
}

template<xtd::iterable source_t>
requires xtd::real_double<xtd::iterable_value_type<source_t>>
auto xtd::linq::enumerable::average(const source_t& source) -> double {
  auto average = .0;
  auto count = 0;
  for (const auto& item : source) {
    average += item;
    ++count;
  }
  if (count == 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
  return average / count;
}

template<xtd::iterable source_t>
requires xtd::real_single<xtd::iterable_value_type<source_t>>
auto xtd::linq::enumerable::average(const source_t& source) -> xtd::single {
  auto average = .0f;
  auto count = 0;
  for (const auto& item : source) {
    average += item;
    ++count;
  }
  if (count == 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
  return average / count;
}

template<xtd::iterable source_t>
requires xtd::signed_integer_32<xtd::iterable_value_type<source_t>>
auto xtd::linq::enumerable::average(const source_t& source) -> double {
  auto average = .0;
  auto count = 0;
  for (const auto& item : source) {
    average += item;
    ++count;
  }
  if (count == 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
  return average / count;
}

template<xtd::iterable source_t>
requires xtd::signed_integer_64<xtd::iterable_value_type<source_t>>
auto xtd::linq::enumerable::average(const source_t& source) -> double {
  auto average = .0;
  auto count = 0;
  for (const auto& item : source) {
    average += item;
    ++count;
  }
  if (count == 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
  return average / count;
}

template<xtd::iterable source_t>
requires std::same_as<xtd::iterable_value_type<source_t>, xtd::optional<xtd::decimal>>
auto xtd::linq::enumerable::average(const source_t& source) -> xtd::optional<xtd::decimal> {
  auto average = .0l;
  auto count = 0;
  for (auto item : source) {
    if (!item) continue;
    average += *item;
    ++count;
  }
  return count == 0 ? xtd::nullopt : std::make_optional(average / count);
}

template<xtd::iterable source_t>
requires std::same_as<xtd::iterable_value_type<source_t>, xtd::optional<double>>
auto xtd::linq::enumerable::average(const source_t& source) -> xtd::optional<double> {
  auto average = .0;
  auto count = 0;
  for (auto item : source) {
    if (!item) continue;
    average += *item;
    ++count;
  }
  return count == 0 ? xtd::nullopt : std::make_optional(average / count);
}

template<xtd::iterable source_t>
requires std::same_as<xtd::iterable_value_type<source_t>, xtd::optional<xtd::single>>
auto xtd::linq::enumerable::average(const source_t& source) -> xtd::optional<xtd::single> {
  auto average = .0f;
  auto count = 0;
  for (auto item : source) {
    if (!item) continue;
    average += *item;
    ++count;
  }
  return count == 0 ? xtd::nullopt : std::make_optional(average / count);
}

template<xtd::iterable source_t>
requires std::same_as<xtd::iterable_value_type<source_t>, xtd::optional<xtd::int32>>
auto xtd::linq::enumerable::average(const source_t& source) -> xtd::optional<double> {
  auto average = .0;
  auto count = 0;
  for (auto item : source) {
    if (!item) continue;
    average += *item;
    ++count;
  }
  return count == 0 ? xtd::nullopt : std::make_optional(average / count);
}

template<xtd::iterable source_t>
requires std::same_as<xtd::iterable_value_type<source_t>, xtd::optional<xtd::int64>>
auto xtd::linq::enumerable::average(const source_t& source) -> xtd::optional<double> {
  auto average = .0;
  auto count = 0;
  for (auto item : source) {
    if (!item) continue;
    average += *item;
    ++count;
  }
  return count == 0 ? xtd::nullopt : std::make_optional(average / count);
}

template<xtd::iterable first_t,xtd::iterable second_t>
auto xtd::linq::enumerable::concat(const first_t& first, const second_t& second) noexcept  -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<first_t>> {
  for (const auto& item : first)
    co_yield item;
  for (const auto& item : second)
    co_yield item;
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::contains(const source_t& source, const xtd::iterable_value_type<source_t>& value) noexcept -> bool {
  for (const auto& item : source)
    if (item == value) return true;
  return false;
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::contains(const source_t& source, const xtd::iterable_value_type<source_t>& value, const xtd::collections::generic::iequality_comparer<xtd::iterable_value_type<source_t>>& comparer) noexcept -> bool {
  for (const auto& item : source)
    if (comparer.equals(item, value)) return true;
  return false;
}

template<xtd::iterable source_t, xtd::func_callable<bool, xtd::iterable_value_type<source_t>, xtd::iterable_value_type<source_t>> equater_t>
auto xtd::linq::enumerable::contains(const source_t& source, const xtd::iterable_value_type<source_t>& value, equater_t&& equater) noexcept -> bool {
  for (const auto& item : source)
    if (equater(item, value)) return true;
  return false;
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::count(const source_t& source) noexcept -> xtd::usize {
  auto count = xtd::usize {0};
  auto enumerator = source.get_enumerator();
  while (enumerator.move_next()) ++count;
  return count;
}

template<xtd::iterable source_t, xtd::predicate_callable<xtd::iterable_value_type<source_t>> predicate_t>
auto xtd::linq::enumerable::count(const source_t& source, predicate_t&& predicate) noexcept -> xtd::usize {
  return where(source, predicate).count();
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::count(const source_t& source, const xtd::iterable_value_type<source_t>& value) noexcept -> xtd::usize {
  return count(source, [value](const xtd::iterable_value_type<source_t>& item) -> bool {return item == value;});
}

template<class result_t, xtd::iterable source_t>
auto xtd::linq::enumerable::select(const source_t& source, auto&& selector) -> xtd::collections::generic::enumerable_generator<result_t> {
  auto index = xtd::usize {0};
  for (const auto& item : source)
    co_yield invoke_selector_with_optional_index<result_t>(selector, item, index++);
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::select(const source_t& source, auto&& selector) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>> {
  auto index = xtd::usize {0};
  for (const auto& item : source)
    co_yield invoke_selector_with_optional_index<xtd::iterable_value_type<source_t>>(selector, item, index++);
}

template <typename predicate_t, typename value_t>
constexpr auto xtd::linq::enumerable::invoke_predicate_with_optional_index(predicate_t&& predicate, value_t&& value, xtd::usize index) -> bool {
  if constexpr (xtd::func_callable<predicate_t, bool, xtd::raw_type<value_t>, xtd::usize>) return predicate(value, index);
  else if constexpr (xtd::predicate_callable<predicate_t, xtd::raw_type<value_t>>) return predicate(value);
  else static_assert(false);
}

template <typename result_t, typename selector_t, typename value_t>
auto xtd::linq::enumerable::invoke_selector_with_optional_index(selector_t&& selector, value_t&& value, xtd::usize index) -> result_t {
  if constexpr (xtd::callable<selector_t, xtd::raw_type<result_t>, xtd::raw_type<value_t>, xtd::usize>) return selector(value, index);
  if constexpr (xtd::callable<selector_t, xtd::raw_type<result_t>, xtd::raw_type<value_t>>) return selector(value);
  else static_assert(false);
}
