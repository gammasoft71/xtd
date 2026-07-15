/// @file
/// @brief Contains xtd::linq::enumerable <type_t> class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "enumerable_.hpp" // contains xtd::linq::enumerable <type_t> class definition
#include "../collections/generic/extensions/enumerable.hpp"
#include "../collections/generic/enumerable_generator.hpp"
#include "from.hpp"

/// @cond
template<xtd::forward_iterable source_t, xtd::func_callable<typename xtd::raw_type<source_t>::value_type, typename xtd::raw_type<source_t>::value_type, typename xtd::raw_type<source_t>::value_type> func_t>
auto xtd::linq::enumerable::aggregate(source_t&& source, func_t&& func) -> typename xtd::raw_type<source_t>::value_type {
  auto nb = 0;
  auto aggregated = typename xtd::raw_type<source_t>::value_type {};
  for (const auto& item : source)
    aggregated = nb++ == 0 ? item : func(aggregated, item);
  return aggregated;
}

template<typename accumulate_t, xtd::forward_iterable source_t, xtd::func_callable<accumulate_t, accumulate_t, typename xtd::raw_type<source_t>::value_type> func_t>
auto xtd::linq::enumerable::aggregate(source_t&& source, accumulate_t&& seed, func_t&& func) -> accumulate_t {
  auto aggregated = std::move(seed);
  for (const auto& item : source)
    aggregated = func(aggregated, item);
  return aggregated;
}

template<typename result_t, typename accumulate_t, xtd::forward_iterable source_t, xtd::func_callable<accumulate_t, accumulate_t, typename xtd::raw_type<source_t>::value_type> func_t, xtd::func_callable<result_t, accumulate_t> result_selector_t>
auto xtd::linq::enumerable::aggregate(source_t&& source, accumulate_t&& seed, func_t&& func, result_selector_t&& result_selector) -> result_t {
  auto aggregated = std::move(seed);
  for (const auto& item : source)
    aggregated = func(aggregated, item);
  return result_selector(aggregated);
}

template<xtd::forward_iterable source_t, xtd::predicate_callable<typename xtd::raw_type<source_t>::value_type> predicate_t>
auto xtd::linq::enumerable::all(source_t&& source, predicate_t&& predicate) -> bool {
  for (const auto& item : source)
    if (!predicate(item)) return false;
  return true;
}

template<xtd::forward_iterable source_t>
auto xtd::linq::enumerable::any(source_t&& source) noexcept -> bool {
  return source.begin() != source.end();
}

template<xtd::forward_iterable source_t, xtd::predicate_callable<typename xtd::raw_type<source_t>::value_type> predicate_t>
auto xtd::linq::enumerable::any(source_t&& source, predicate_t&& predicate) -> bool {
  for (const auto& item : source)
    if (predicate(item)) return true;
  return false;
}

template<xtd::forward_iterable source_t>
auto xtd::linq::enumerable::append(source_t&& source, typename xtd::raw_type<source_t>::value_type&& element) noexcept -> xtd::collections::generic::enumerable_generator<typename xtd::raw_type<source_t>::value_type> {
  for (const auto& item : source)
    co_yield item;
  co_yield std::forward<typename xtd::raw_type<source_t>::value_type>(element);
}
