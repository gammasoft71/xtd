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
template<typename type_t>
xtd::linq::enumerable::enumerable_holder<type_t>::enumerable_holder(const type_t& value) : ptr_(std::addressof(value)) {
}

//template<typename type_t>
//xtd::linq::enumerable::enumerable_holder<type_t>::enumerable_holder(type_t& value) : ptr_(std::addressof(value)) {
//}

template<typename type_t>
xtd::linq::enumerable::enumerable_holder<type_t>::enumerable_holder(type_t&& value) requires std::movable<type_t> : value_(std::move(value)), ptr_(std::addressof(*value_)) {
}

template<typename type_t>
auto xtd::linq::enumerable::enumerable_holder<type_t>::get() const -> const xtd::raw_type<type_t>& {return *ptr_;}

template<xtd::iterable source_t, xtd::func_callable<xtd::iterable_value_type<source_t>, xtd::iterable_value_type<source_t>, xtd::iterable_value_type<source_t>> func_t>
auto xtd::linq::enumerable::aggregate(source_t&& source, func_t&& func) -> xtd::iterable_value_type<source_t> {
  auto nb = 0;
  auto aggregated = xtd::iterable_value_type<source_t> {};
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source)
    aggregated = nb++ == 0 ? item : func(aggregated, item);
  return aggregated;
}

template<typename accumulate_t, xtd::iterable source_t, xtd::func_callable<accumulate_t, accumulate_t, xtd::iterable_value_type<source_t>> func_t>
auto xtd::linq::enumerable::aggregate(source_t&& source, accumulate_t&& seed, func_t&& func) -> accumulate_t {
  auto aggregated = std::move(seed);
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source)
    aggregated = func(aggregated, item);
  return aggregated;
}

template<typename result_t, typename accumulate_t, xtd::iterable source_t, xtd::func_callable<accumulate_t, accumulate_t, xtd::iterable_value_type<source_t>> func_t, xtd::func_callable<result_t, accumulate_t> result_selector_t>
auto xtd::linq::enumerable::aggregate(source_t&& source, accumulate_t&& seed, func_t&& func, result_selector_t&& result_selector) -> result_t {
  auto aggregated = std::move(seed);
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source)
    aggregated = func(aggregated, item);
  return result_selector(aggregated);
}

template<xtd::iterable source_t, xtd::predicate_callable<xtd::iterable_value_type<source_t>> predicate_t>
auto xtd::linq::enumerable::all(source_t&& source, predicate_t&& predicate) -> bool {
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source)
    if (!predicate(item)) return false;
  return true;
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::any(source_t&& source) noexcept -> bool {
  return source.begin() != source.end();
}

template<xtd::iterable source_t, xtd::predicate_callable<xtd::iterable_value_type<source_t>> predicate_t>
auto xtd::linq::enumerable::any(source_t&& source, predicate_t&& predicate) -> bool {
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source)
    if (predicate(item)) return true;
  return false;
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::append(source_t&& source, xtd::iterable_value_type<source_t>&& element) noexcept -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>> {
  //auto source_holder = enumerable_holder<source_t> {std::forward<xtd::raw_type<source_t>>(source)};
  //for (const auto& item : source_holder.get())
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
auto xtd::linq::enumerable::average(source_t&& source) -> xtd::decimal {
  auto average = .0l;
  auto count = 0;
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source) {
    average += item;
    ++count;
  }
  if (count == 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
  return average / count;
}

template<xtd::iterable source_t>
requires xtd::real_double<xtd::iterable_value_type<source_t>>
auto xtd::linq::enumerable::average(source_t&& source) -> double {
  auto average = .0;
  auto count = 0;
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source) {
    average += item;
    ++count;
  }
  if (count == 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
  return average / count;
}

template<xtd::iterable source_t>
requires xtd::real_single<xtd::iterable_value_type<source_t>>
auto xtd::linq::enumerable::average(source_t&& source) -> xtd::single {
  auto average = .0f;
  auto count = 0;
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source) {
    average += item;
    ++count;
  }
  if (count == 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
  return average / count;
}

template<xtd::iterable source_t>
requires xtd::signed_integer_32<xtd::iterable_value_type<source_t>>
auto xtd::linq::enumerable::average(source_t&& source) -> double {
  auto average = .0;
  auto count = 0;
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source) {
    average += item;
    ++count;
  }
  if (count == 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
  return average / count;
}

template<xtd::iterable source_t>
requires xtd::signed_integer_64<xtd::iterable_value_type<source_t>>
auto xtd::linq::enumerable::average(source_t&& source) -> double {
  auto average = .0;
  auto count = 0;
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source) {
    average += item;
    ++count;
  }
  if (count == 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
  return average / count;
}

template<xtd::iterable source_t>
requires std::same_as<xtd::iterable_value_type<source_t>, xtd::optional<xtd::decimal>>
auto xtd::linq::enumerable::average(source_t&& source) -> xtd::optional<xtd::decimal> {
  auto average = .0l;
  auto count = 0;
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source) {
    if (!item) continue;
    average += *item;
    ++count;
  }
  return count == 0 ? xtd::nullopt : std::make_optional(average / count);
}

template<xtd::iterable source_t>
requires std::same_as<xtd::iterable_value_type<source_t>, xtd::optional<double>>
auto xtd::linq::enumerable::average(source_t&& source) -> xtd::optional<double> {
  auto average = .0;
  auto count = 0;
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source) {
    if (!item) continue;
    average += *item;
    ++count;
  }
  return count == 0 ? xtd::nullopt : std::make_optional(average / count);
}

template<xtd::iterable source_t>
requires std::same_as<xtd::iterable_value_type<source_t>, xtd::optional<xtd::single>>
auto xtd::linq::enumerable::average(source_t&& source) -> xtd::optional<xtd::single> {
  auto average = .0f;
  auto count = 0;
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source) {
    if (!item) continue;
    average += *item;
    ++count;
  }
  return count == 0 ? xtd::nullopt : std::make_optional(average / count);
}

template<xtd::iterable source_t>
requires std::same_as<xtd::iterable_value_type<source_t>, xtd::optional<xtd::int32>>
auto xtd::linq::enumerable::average(source_t&& source) -> xtd::optional<double> {
  auto average = .0;
  auto count = 0;
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source) {
    if (!item) continue;
    average += *item;
    ++count;
  }
  return count == 0 ? xtd::nullopt : std::make_optional(average / count);
}

template<xtd::iterable source_t>
requires std::same_as<xtd::iterable_value_type<source_t>, xtd::optional<xtd::int64>>
auto xtd::linq::enumerable::average(source_t&& source) -> xtd::optional<double> {
  auto average = .0;
  auto count = 0;
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source) {
    if (!item) continue;
    average += *item;
    ++count;
  }
  return count == 0 ? xtd::nullopt : std::make_optional(average / count);
}

template<xtd::iterable first_t,xtd::iterable second_t>
auto xtd::linq::enumerable::concat(first_t&& first, second_t&& second) noexcept  -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<first_t>> {
  //auto first_holder = enumerable_holder<xtd::raw_type<first_t>> {std::forward<first_t>(first)};
  //auto second_holder = enumerable_holder<xtd::raw_type<second_t>> {std::forward<second_t>(second)};
  //for (const auto& item : first_holder.get())
  //  co_yield item;
  //for (const auto& item : second_holder.get())
  //  co_yield item;
  for (const auto& item : first)
    co_yield item;
  for (const auto& item : second)
    co_yield item;
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::contains(source_t&& source, const xtd::iterable_value_type<source_t>& value) noexcept -> bool {
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source)
    if (item == value) return true;
  return false;
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::contains(source_t&& source, const xtd::iterable_value_type<source_t>& value, const iequality_comparer<xtd::iterable_value_type<source_t>>& comparer) noexcept -> bool {
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source)
    if (comparer.equals(item, value)) return true;
  return false;
}

template<xtd::iterable source_t, xtd::func_callable<bool, xtd::iterable_value_type<source_t>, xtd::iterable_value_type<source_t>> equater_t>
auto xtd::linq::enumerable::contains(source_t&& source, const xtd::iterable_value_type<source_t>& value, equater_t&& equater) noexcept -> bool {
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source)
    if (equater(item, value)) return true;
  return false;
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::count(source_t&& source) noexcept -> xtd::usize {
  auto count = xtd::usize {0};
  auto enumerator = source.get_enumerator();
  while (enumerator.move_next()) ++count;
  return count;
}

template<xtd::iterable source_t, xtd::predicate_callable<xtd::iterable_value_type<source_t>> predicate_t>
auto xtd::linq::enumerable::count(source_t&& source, predicate_t&& predicate) noexcept -> xtd::usize {
  return where(std::forward<source_t>(source), predicate).count();
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::count(source_t&& source, xtd::iterable_value_type<source_t>&& value) noexcept -> xtd::usize {
  return count(std::forward<source_t>(source), [value](const xtd::iterable_value_type<source_t>& item) -> bool {return item == value;});
}

template<typename key_t, xtd::iterable source_t, xtd::callable<key_t, xtd::iterable_value_type<source_t>> key_selector_t>
auto xtd::linq::enumerable::count_by(source_t&& source, key_selector_t&& key_selector) noexcept -> xtd::collections::generic::enumerable_generator<xtd::collections::generic::key_value_pair<key_t, xtd::usize>> {
  return count_by<key_t>(std::forward<source_t>(source), key_selector, [](auto&& a, auto&& b) {return xtd::collections::generic::equality_comparer<key_t>::default_equality_comparer().equals(a, b);});
  //return count_by<key_t>(std::forward<source_t>(source), key_selector, xtd::collections::generic::equality_comparer<key_t>::default_equality_comparer());
}

template<typename key_t, xtd::iterable source_t, xtd::callable<key_t, xtd::iterable_value_type<source_t>> key_selector_t>
auto xtd::linq::enumerable::count_by(source_t&& source, key_selector_t&& key_selector, const iequality_comparer<key_t>& key_comparer) noexcept -> xtd::collections::generic::enumerable_generator<xtd::collections::generic::key_value_pair<key_t, xtd::usize>> {
  return count_by<key_t>(std::forward<source_t>(source), key_selector, [&key_comparer](auto&& a, auto&& b) {return key_comparer.equals(a, b);});
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::default_if_empty(source_t&& source) noexcept -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>> {
  auto default_value = xtd::iterable_value_type<source_t> {};
  //return default_if_empty(std::forward<source_t>(source), std::forward<xtd::iterable_value_type<source_t>>(default_value));
  if (!any(source)) co_yield default_value;
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //else for (const auto& item : source_holder.get())
  else for (const auto& item : source)
    co_yield item;
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::default_if_empty(source_t&& source, const xtd::iterable_value_type<source_t>& default_value) noexcept -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>> {
  if (!any(source)) co_yield default_value;
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //else for (const auto& item : source_holder.get())
  else for (const auto& item : source)
    co_yield item;
}

template<xtd::iterable source_t, xtd::predicate_callable<xtd::iterable_value_type<source_t>> prediacte_t>
auto xtd::linq::enumerable::first_or_default(source_t&& source, prediacte_t&& predicate, xtd::iterable_value_type<source_t>&& default_value) noexcept -> xtd::iterable_value_type<source_t> {
  auto result = where(std::forward<source_t>(source), std::forward<prediacte_t>(predicate));
  return any(result) ? *result.begin() : std::move(default_value);
}

template<xtd::iterable source_t, xtd::predicate_callable<xtd::iterable_value_type<source_t>> prediacte_t>
auto xtd::linq::enumerable::first_or_default(source_t&& source, prediacte_t&& predicate) noexcept -> xtd::iterable_value_type<source_t> {
  return first_or_default(std::forward<source_t>(source), std::forward<prediacte_t>(predicate), xtd::iterable_value_type<source_t> {});
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::first_or_default(source_t&& source, xtd::iterable_value_type<source_t>&& default_value) noexcept -> xtd::iterable_value_type<source_t> {
  return any(std::forward<source_t>(source)) ? *source.begin() : std::move(default_value);
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::first_or_default(source_t&& source) noexcept -> xtd::iterable_value_type<source_t> {
  return first_or_default(std::forward<source_t>(source), xtd::iterable_value_type<source_t> {});
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::from(const source_t& source) noexcept -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>> {
  return as_enumerable(source);
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::from(source_t& source) noexcept -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>> {
  return as_enumerable(source);
}

template<typename value_t>
auto xtd::linq::enumerable::from(std::initializer_list<value_t> source) noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
  return as_enumerable(source);
}

template<std::forward_iterator iterator_t>
auto xtd::linq::enumerable::from(iterator_t first, iterator_t last) noexcept -> xtd::collections::generic::enumerable_generator<typename std::decay<decltype(*first)>::type> {
  return as_enumerable(first, last);
}

template<std::forward_iterator iterator_t>
auto xtd::linq::enumerable::from(iterator_t iterator, xtd::usize length) noexcept -> xtd::collections::generic::enumerable_generator<typename std::decay<decltype(*iterator)>::type> {
  return as_enumerable(iterator, length);
}

template<typename value_t, xtd::usize length>
auto xtd::linq::enumerable::from(const value_t (&array)[length]) noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
  return as_enumerable(array);
}

template<typename value_t, xtd::usize length>
auto xtd::linq::enumerable::from(value_t (&array)[length]) noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
  return as_enumerable(array);
}

template<typename value_t, typename container_t>
auto xtd::linq::enumerable::from(const std::queue<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
  return as_enumerable(source);
}

template<typename value_t, typename container_t>
auto xtd::linq::enumerable::from(std::queue<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
  return as_enumerable(source);
}

template<typename value_t, typename container_t>
auto xtd::linq::enumerable::from(const std::priority_queue<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
  return as_enumerable(source);
}

template<typename value_t, typename container_t>
auto xtd::linq::enumerable::from(std::priority_queue<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
  return as_enumerable(source);
}

template<typename value_t, typename container_t>
auto xtd::linq::enumerable::from(const std::stack<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
  return as_enumerable(source);
}

template<typename value_t, typename container_t>
auto xtd::linq::enumerable::from(std::stack<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
  return as_enumerable(source);
}

template<xtd::iterable source_t>
requires xtd::numeric<xtd::iterable_value_type<source_t>>
auto xtd::linq::enumerable::max(source_t&& source) -> xtd::iterable_value_type<source_t> {
  auto result = xtd::optional<xtd::iterable_value_type<source_t>> {};
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source)
    if (!result || item > result) result = item;
  return result.value_or(xtd::iterable_value_type<source_t> {});
}

template<xtd::iterable source_t, xtd::callable<xtd::iterable_value_type<source_t>, xtd::iterable_value_type<source_t>> selector_t>
requires xtd::numeric<xtd::iterable_value_type<source_t>>
auto xtd::linq::enumerable::max(source_t&& source, selector_t&& selector) -> xtd::iterable_value_type<source_t> {
  auto result = xtd::optional<xtd::iterable_value_type<source_t>> {};
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source) {
    auto val = selector(item);
    if (!result || val > result) result = val;
  }
  return result.value_or(xtd::iterable_value_type<source_t> {});
}

template<typename result_t, xtd::iterable source_t, xtd::callable<result_t, xtd::iterable_value_type<source_t>> selector_t>
requires xtd::numeric<xtd::iterable_value_type<source_t>>
auto xtd::linq::enumerable::max(source_t&& source, selector_t&& selector) -> result_t {
  auto result = xtd::optional<result_t> {};
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source) {
    auto val = selector(item);
    if (!result || val > result) result = val;
  }
  return result.value_or(result_t {});
}

template<xtd::iterable source_t>
requires xtd::numeric<xtd::iterable_value_type<source_t>>
auto xtd::linq::enumerable::min(source_t&& source) -> xtd::iterable_value_type<source_t> {
  auto result = xtd::optional<source_t> {};
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source)
    if (!result || item < result) result = item;
  return result.value_or(source_t {});
}

template<xtd::iterable source_t, xtd::callable<xtd::iterable_value_type<source_t>, xtd::iterable_value_type<source_t>> selector_t>
requires xtd::numeric<xtd::iterable_value_type<source_t>>
auto xtd::linq::enumerable::min(source_t&& source, selector_t&& selector) -> xtd::iterable_value_type<source_t> {
  auto result = xtd::optional<source_t> {};
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source) {
    auto val = selector(item);
    if (!result || val < result) result = val;
  }
  return result.value_or(source_t {});
}

template<typename result_t, xtd::iterable source_t, xtd::callable<result_t, xtd::iterable_value_type<source_t>> selector_t>
requires xtd::numeric<xtd::iterable_value_type<source_t>>
auto xtd::linq::enumerable::min(source_t&& source, selector_t&& selector) -> result_t {
  auto result = xtd::optional<result_t> {};
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source) {
    auto val = selector(item);
    if (!result || val < result) result = val;
  }
  return result.value_or(result_t {});
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::order(source_t&& source) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>> {
  //return order(source, xtd::collections::generic::comparer<xtd::iterable_value_type<source_t>>::default_comparer);
  return order(source, xtd::collections::generic::helpers::lesser<xtd::iterable_value_type<source_t>>(xtd::collections::generic::comparer<xtd::iterable_value_type<source_t>>::default_comparer));
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::order(source_t&& source, const xtd::collections::generic::icomparer<xtd::iterable_value_type<source_t>>& comparer) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>> {
  return order(source, xtd::collections::generic::helpers::lesser<xtd::iterable_value_type<source_t>>(comparer));
}

template<xtd::integer integer_t>
auto xtd::linq::enumerable::range(integer_t count) -> xtd::collections::generic::enumerable_generator<integer_t> {
  auto step = integer_t {};
  return range(integer_t {}, count, ++step);
}

template<xtd::integer integer_t>
auto xtd::linq::enumerable::range(integer_t start, integer_t count) -> xtd::collections::generic::enumerable_generator<integer_t> {
  auto step = integer_t {};
  return range(start, count, ++step);
}

template<xtd::integer integer_t>
auto xtd::linq::enumerable::range(integer_t start, integer_t count, integer_t step) -> xtd::collections::generic::enumerable_generator<integer_t> {
  if (step == integer_t {}) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  if (count < integer_t {}) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
  
  for (auto index = integer_t {}; index < count; ++index)
    co_yield start + (index * step);
}

template<typename result_t, xtd::iterable source_t>
auto xtd::linq::enumerable::select(source_t&& source, auto&& selector) -> xtd::collections::generic::enumerable_generator<result_t> {
  auto index = xtd::usize {0};
  //auto source_holder = enumerable_holder<source_t> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source)
    co_yield invoke_selector_with_optional_index<result_t>(selector, item, index++);
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::select(source_t&& source, auto&& selector) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>> {
  auto index = xtd::usize {0};
  //auto source_holder = enumerable_holder<xtd::raw_type<source_t>> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source)
    co_yield invoke_selector_with_optional_index<xtd::iterable_value_type<source_t>>(selector, item, index++);
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::skip_while(source_t&& source, auto&& predicate) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>> {
  bool skip = true;
  auto index = xtd::usize {0};
  //auto source_holder = enumerable_holder<xtd::raw_type<source_t>> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source) {
    if (skip && !invoke_predicate_with_optional_index(predicate, item, index++)) skip = false;
    if (!skip) co_yield item;
  }
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::take_while(source_t&& source, auto&& predicate) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>> {
  auto index = xtd::usize {0};
  //auto source_holder = enumerable_holder<xtd::raw_type<source_t>> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source) {
    if (!invoke_predicate_with_optional_index(predicate, item, index++)) break;
    co_yield item;
  }
}

template<xtd::iterable source_t>
auto xtd::linq::enumerable::where(source_t&& source, auto&& predicate) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>> {
  auto index = xtd::usize {0};
  //auto source_holder = enumerable_holder<xtd::raw_type<source_t>> {std::forward<source_t>(source)};
  //for (const auto& item : source_holder.get())
  for (const auto& item : source)
    if (invoke_predicate_with_optional_index(predicate, item, index++)) co_yield item;
}


template<typename predicate_t, typename value_t>
constexpr auto xtd::linq::enumerable::invoke_predicate_with_optional_index(predicate_t&& predicate, value_t&& value, xtd::usize index) -> bool {
  if constexpr (xtd::func_callable<predicate_t, bool, xtd::raw_type<value_t>, xtd::usize>) return predicate(std::forward<value_t>(value), index);
  else if constexpr (xtd::predicate_callable<predicate_t, xtd::raw_type<value_t>>) return predicate(std::forward<value_t>(value));
  else static_assert(always_false_v<predicate_t>, "Predicate must accept either (value) or (value, index).");
}

template<typename result_t, typename selector_t, typename value_t>
auto xtd::linq::enumerable::invoke_selector_with_optional_index(selector_t&& selector, value_t&& value, xtd::usize index) -> result_t {
  if constexpr (xtd::callable<selector_t, xtd::raw_type<result_t>, xtd::raw_type<value_t>, xtd::usize>) return selector(std::forward<value_t>(value), index);
  if constexpr (xtd::callable<selector_t, xtd::raw_type<result_t>, xtd::raw_type<value_t>>) return selector(std::forward<value_t>(value));
  else static_assert(always_false_v<selector_t>, "Selector must accept either (value) or (value, index).");
}
/// @endcond
