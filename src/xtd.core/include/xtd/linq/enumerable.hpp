/// @file
/// @brief Contains xtd::linq::enumerable <type_t> class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../collections/generic/helpers/allocator.hpp"
#include "../decimal.hpp"
#include "../iequatable.hpp"
#include "../int32.hpp"
#include "../int64.hpp"
#include "../optional.hpp"
#include "../static.hpp"
#include <algorithm>
#include <functional>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace collections::generic {
    template<typename type_t, typename allocator_t = xtd::collections::generic::helpers::allocator<typename std::conditional<std::is_same<bool, type_t>::value, char, type_t>::type>>
    class list;
    template<typename type_t>
    class ienumerable;
  }
  /// @endcond
  
  /// @brief Provides classes and interfaces that support queries that use Language-Integrated Query (LINQ).
  namespace linq {
    /// @cond
    template<typename type_t, typename allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
    class enumerable_collection;
    /// @endcond

    /// @brief Provides a set of static methods for querying objects that implement ienumerable <type_t>.
    /// @par Definition
    /// ```cpp
    /// template<typename type_t>
    /// class enumerable : public xtd::static_object;
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/linq/enumerable>
    /// ```
    /// @par Namespace
    /// xtd::linq
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core linq
    class enumerable static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Applies an accumulator function over a sequence.
      /// @param source An xtd::collections::generic::ienumerable <type_t> to aggregate over.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to reverse the order of words in a string by using enumerable::aggregate.
      /// @include enumerable_aggregate.cpp
      template<typename source_t>
      static source_t aggregate(const xtd::collections::generic::ienumerable<source_t>& source, const std::function<source_t(const source_t&, const source_t&)>& func) {
        auto nb = 0;
        auto aggregated = source_t {};
        for (const auto& item : source)
          if (nb++ == 0) aggregated = item;
          else aggregated = func(aggregated, item);
        return aggregated;
      }
      /// @brief Applies an accumulator function over a sequence.
      /// @param source An xtd::collections::generic::ienumerable <type_t> to aggregate over.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to reverse the order of words in a string by using enumerable::aggregate.
      /// @include enumerable_aggregate.cpp
      template<typename source_t>
      static source_t aggregate(std::initializer_list<source_t> source, const std::function<source_t(const source_t&, const source_t&)>& func) {
        auto nb = 0;
        auto aggregated = source_t {};
        for (const auto& item : source)
          if (nb++ == 0) aggregated = item;
          else aggregated = func(aggregated, item);
        return aggregated;
      }
      /// @brief Applies an accumulator function over a sequence.
      /// @param source A collection_t collection to aggregate over.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to reverse the order of words in a string by using enumerable::aggregate.
      /// @include enumerable_aggregate.cpp
      template<typename source_t, typename collection_t>
      static source_t aggregate(const collection_t& source, const std::function<source_t(const source_t&, const source_t&)>& func) {
        auto nb = 0;
        auto aggregated = source_t {};
        for (const auto& item : source)
          if (nb++ == 0) aggregated = item;
          else aggregated = func(aggregated, item);
        return aggregated;
      }
      /// @brief Applies an accumulator function over a sequence.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to reverse the order of words in a string by using enumerable::aggregate.
      /// @include enumerable_aggregate4.cpp
      template<typename source_t, typename input_iterator_t>
      static source_t aggregate(input_iterator_t first, input_iterator_t last, const std::function<source_t(const source_t&, const source_t&)>& func) {
        auto nb = 0;
        auto aggregated = source_t {};
        for (auto iterator = first; iterator != last; ++iterator)
          if (nb++ == 0) aggregated = *iterator;
          else aggregated = func(aggregated, *iterator);
        return aggregated;
      }
      
      /// @brief Applies an accumulator function over a sequence.
      /// @param source An xtd::collections::generic::ienumerable <type_t> to aggregate over.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to reverse the order of words in a string by using xtd::linq::enumerable::aggregate.
      /// @include enumerable_aggregate.cpp
      template<typename source_t, typename func_t>
      static source_t aggregate(const xtd::collections::generic::ienumerable<source_t>& source, const func_t& func) {
        return aggregate(source, std::function<source_t(const source_t&, const source_t&)> {func});
      }
      /// @brief Applies an accumulator function over a sequence.
      /// @param source An xtd::collections::generic::ienumerable <type_t> to aggregate over.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to reverse the order of words in a string by using xtd::linq::enumerable::aggregate.
      /// @include enumerable_aggregate.cpp
      template<typename source_t, typename func_t>
      static source_t aggregate(std::initializer_list<source_t> source, const func_t& func) {
        return aggregate(source, std::function<source_t(const source_t&, const source_t&)> {func});
      }
      /// @brief Applies an accumulator function over a sequence.
      /// @param source A collection_t collection to aggregate over.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to reverse the order of words in a string by using xtd::linq::enumerable::aggregate.
      /// @include enumerable_aggregate.cpp
      template<typename collection_t, typename func_t>
      static auto aggregate(const collection_t& source, const func_t& func) {
        using source_t = typename collection_t::value_type;
        return aggregate(source, std::function<source_t(const source_t&, const source_t&)> {func});
      }
      /// @brief Applies an accumulator function over a sequence.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to reverse the order of words in a string by using xtd::linq::enumerable::aggregate.
      /// @include enumerable_aggregate4.cpp
      template<typename input_iterator_t, typename func_t>
      static auto aggregate(input_iterator_t first, input_iterator_t last, const func_t& func) {
        using source_t = typename std::decay<decltype(*first)>::type;
        return aggregate(first, last, std::function<source_t(const source_t&, const source_t&)> {func});
      }
      
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value.
      /// @param source An xtd::collections::generic::ienumerable <type_t> to aggregate over.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate2.cpp
      template<typename source_t, typename accumulate_t>
      static accumulate_t aggregate(const xtd::collections::generic::ienumerable<source_t>& source, const accumulate_t& seed, const std::function<accumulate_t(const source_t&, const accumulate_t&)>& func) {
        auto aggregated = seed;
        for (const auto& item : source)
          aggregated = func(aggregated, item);
        return aggregated;
      }
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value.
      /// @param source An xtd::collections::generic::ienumerable <type_t> to aggregate over.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate2.cpp
      template<typename source_t, typename accumulate_t>
      static accumulate_t aggregate(std::initializer_list<source_t> source, const accumulate_t& seed, const std::function<accumulate_t(const source_t&, const accumulate_t&)>& func) {
        auto aggregated = seed;
        for (const auto& item : source)
          aggregated = func(aggregated, item);
        return aggregated;
      }
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value.
      /// @param source A collection_t collection to aggregate over.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate2.cpp
      template<typename source_t, typename accumulate_t, typename collection_t>
      static accumulate_t aggregate(const collection_t& source, const accumulate_t& seed, const std::function<accumulate_t(const source_t&, const accumulate_t&)>& func) {
        auto aggregated = seed;
        for (const auto& item : source)
          aggregated = func(aggregated, item);
        return aggregated;
      }
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value.
      /// @param source An xtd::collections::generic::ienumerable <type_t> to aggregate over.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate5.cpp
      template<typename source_t, typename accumulate_t, typename input_iterator_t>
      static accumulate_t aggregate(input_iterator_t first, input_iterator_t last, const accumulate_t& seed, const std::function<accumulate_t(const source_t&, const accumulate_t&)>& func) {
        auto aggregated = seed;
        for (auto iterator = first; iterator != last; ++iterator)
          aggregated = func(aggregated, *iterator);
        return aggregated;
      }
      
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value.
      /// @param source An xtd::collections::generic::ienumerable <type_t> to aggregate over.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate2.cpp
      template<typename source_t, typename accumulate_t, typename func_t>
      static accumulate_t aggregate(const xtd::collections::generic::ienumerable<source_t>& source, const accumulate_t& seed, const func_t& func) {
        return aggregate(source, seed, std::function<accumulate_t(const source_t&, const accumulate_t&)> {func});
      }
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value.
      /// @param source An xtd::collections::generic::ienumerable <type_t> to aggregate over.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate2.cpp
      template<typename source_t, typename accumulate_t, typename func_t>
      static accumulate_t aggregate(std::initializer_list<source_t> source, const accumulate_t& seed, const func_t& func) {
        return aggregate(source, seed, std::function<accumulate_t(const source_t&, const accumulate_t&)> {func});
      }
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value.
      /// @param source A collection_t collection to aggregate over.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate5.cpp
      template<typename accumulate_t, typename collection_t, typename func_t>
      static accumulate_t aggregate(const collection_t& source, const accumulate_t& seed, const func_t& func) {
        using source_t = typename collection_t::value_type;
        return aggregate(source, seed, std::function<accumulate_t(const source_t&, const accumulate_t&)> {func});
      }
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate5.cpp
      template<typename accumulate_t, typename input_iterator_t, typename func_t>
      static accumulate_t aggregate(input_iterator_t first, input_iterator_t last, const accumulate_t& seed, const func_t& func) {
        using source_t = typename std::decay<decltype(*first)>::type;
        return aggregate(first, last, seed, std::function<accumulate_t(const source_t&, const accumulate_t&)> {func});
      }
      
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
      /// @param source An xtd::collections::generic::ienumerable <type_t> to aggregate over.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @param result_Selector A function to transform the final accumulator value into the result value.
      /// @return The transformed final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate3.cpp
      template<typename source_t, typename accumulate_t, typename result_t>
      static result_t aggregate(const xtd::collections::generic::ienumerable<source_t>& source, const accumulate_t& seed, const std::function<accumulate_t(const source_t&, const accumulate_t&)>& func, const std::function<result_t(const accumulate_t&)>& result_selector) {
        auto aggregated = seed;
        for (const auto& item : source)
          aggregated = func(aggregated, item);
        return result_selector(aggregated);
      }
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
      /// @param source An xtd::collections::generic::ienumerable <type_t> to aggregate over.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @param result_Selector A function to transform the final accumulator value into the result value.
      /// @return The transformed final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate3.cpp
      template<typename source_t, typename accumulate_t, typename result_t>
      static result_t aggregate(std::initializer_list<source_t> source, const accumulate_t& seed, const std::function<accumulate_t(const source_t&, const accumulate_t&)>& func, const std::function<result_t(const accumulate_t&)>& result_selector) {
        auto aggregated = seed;
        for (const auto& item : source)
          aggregated = func(aggregated, item);
        return result_selector(aggregated);
      }
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
      /// @param source A collection_t collection to aggregate over.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @param result_Selector A function to transform the final accumulator value into the result value.
      /// @return The transformed final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate3.cpp
      template<typename source_t, typename accumulate_t, typename result_t, typename collection_t>
      static result_t aggregate(const collection_t& source, const accumulate_t& seed, const std::function<accumulate_t(const source_t&, const accumulate_t&)>& func, const std::function<result_t(const accumulate_t&)>& result_selector) {
        auto aggregated = seed;
        for (const auto& item : source)
          aggregated = func(aggregated, item);
        return result_selector(aggregated);
      }
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @param result_Selector A function to transform the final accumulator value into the result value.
      /// @return The transformed final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate5.cpp
      template<typename source_t, typename accumulate_t, typename result_t, typename input_iterator_t>
      static result_t aggregate(input_iterator_t first, input_iterator_t last, const accumulate_t& seed, const std::function<accumulate_t(const source_t&, const accumulate_t&)>& func, const std::function<result_t(const accumulate_t&)>& result_selector) {
        auto aggregated = seed;
        for (auto iterator = first; iterator != last; ++iterator)
          aggregated = func(aggregated, *iterator);
        return result_selector(aggregated);
      }
            
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
      /// @param source An xtd::collections::generic::ienumerable <type_t> to aggregate over.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @param result_selector A function to transform the final accumulator value into the result value.
      /// @return The transformed final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate3.cpp
      template<typename source_t, typename accumulate_t, typename result_t, typename func_t, typename result_selector_t>
      static result_t aggregate(const xtd::collections::generic::ienumerable<source_t>& source, const accumulate_t& seed, const func_t& func, const result_selector_t& result_selector) {
        return aggregate(source, seed, std::function<accumulate_t(const source_t&, const accumulate_t&)> {func}, std::function<result_t(const accumulate_t&)> {result_selector});
      }
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
      /// @param source An xtd::collections::generic::ienumerable <type_t> to aggregate over.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @param result_selector A function to transform the final accumulator value into the result value.
      /// @return The transformed final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate3.cpp
      template<typename source_t, typename accumulate_t, typename result_t, typename func_t, typename result_selector_t>
      static result_t aggregate(std::initializer_list<source_t> source, const accumulate_t& seed, const func_t& func, const result_selector_t& result_selector) {
        return aggregate(source, seed, std::function<accumulate_t(const source_t&, const accumulate_t&)> {func}, std::function<result_t(const accumulate_t&)> {result_selector});
      }
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
      /// @param source A collection_t collection to aggregate over.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @param result_selector A function to transform the final accumulator value into the result value.
      /// @return The transformed final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate6.cpp
      template<typename accumulate_t, typename result_t, typename collection_t, typename func_t, typename result_selector_t>
      static result_t aggregate(const collection_t& collection, const accumulate_t& seed, const func_t& func, const result_selector_t& result_selector) {
        using source_t = typename collection_t::value_type;
        return aggregate(collection, seed, std::function<accumulate_t(const source_t&, const accumulate_t&)> {func}, std::function<result_t(const accumulate_t&)> {result_selector});
      }
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @param result_selector A function to transform the final accumulator value into the result value.
      /// @return The transformed final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate6.cpp
      template<typename accumulate_t, typename result_t, typename input_iterator_t, typename func_t, typename result_selector_t>
      static result_t aggregate(input_iterator_t first, input_iterator_t last, const accumulate_t& seed, const func_t& func, const result_selector_t& result_selector) {
        using source_t = typename std::decay<decltype(*first)>::type;
        return aggregate(first, last, seed, std::function<accumulate_t(const source_t&, const accumulate_t&)> {func}, std::function<result_t(const accumulate_t&)> {result_selector});
      }
      
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
      /// @param source An xtd::collections::generic::ienumerable <type_t> to aggregate over.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @param result_Selector A function to transform the final accumulator value into the result value.
      /// @return The transformed final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate3.cpp
      template<typename source_t, typename accumulate_t, typename func_t, typename result_selector_t>
      static accumulate_t aggregate(const xtd::collections::generic::ienumerable<source_t>& source, const accumulate_t& seed, const func_t& func, const result_selector_t& result_selector) {
        return aggregate(source, seed, std::function<accumulate_t(const source_t&, const accumulate_t&)> {func}, std::function<accumulate_t(const accumulate_t&)> {result_selector});
      }
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
      /// @param source An xtd::collections::generic::ienumerable <type_t> to aggregate over.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @param result_Selector A function to transform the final accumulator value into the result value.
      /// @return The transformed final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate3.cpp
      template<typename source_t, typename accumulate_t, typename func_t, typename result_selector_t>
      static accumulate_t aggregate(std::initializer_list<source_t> source, const accumulate_t& seed, const func_t& func, const result_selector_t& result_selector) {
        return aggregate(source, seed, std::function<accumulate_t(const source_t&, const accumulate_t&)> {func}, std::function<accumulate_t(const accumulate_t&)> {result_selector});
      }
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
      /// @param source A collection_t collection to aggregate over.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @param result_selector A function to transform the final accumulator value into the result value.
      /// @return The transformed final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate6.cpp
      template<typename accumulate_t, typename collection_t, typename func_t, typename result_selector_t>
      static accumulate_t aggregate(const collection_t& collection, const accumulate_t& seed, const func_t& func, const result_selector_t& result_selector) {
        using source_t = typename collection_t::value_type;
        return aggregate(collection, seed, std::function<accumulate_t(const source_t&, const accumulate_t&)> {func}, std::function<accumulate_t(const accumulate_t&)> {result_selector});
      }
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @param result_selector A function to transform the final accumulator value into the result value.
      /// @return The transformed final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate6.cpp
      template<typename accumulate_t, typename input_iterator_t, typename func_t, typename result_selector_t>
      static accumulate_t aggregate(input_iterator_t first, input_iterator_t last, const accumulate_t& seed, const func_t& func, const result_selector_t& result_selector) {
        using source_t = typename std::decay<decltype(*first)>::type;
        return aggregate(first, last, seed, std::function<accumulate_t(const source_t&, const accumulate_t&)> {func}, std::function<accumulate_t(const accumulate_t&)> {result_selector});
      }

      /// @brief Determines whether all elements of a sequence satisfy a condition.
      /// @param source An xtd::collections::generic::ienumerable <type_t> that contains the elements to apply the predicate to.
      /// @param predicate A function to test each element for a condition.
      /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all.cpp
      template<typename source_t>
      static bool all(const xtd::collections::generic::ienumerable<source_t>& source, const std::function<bool(const source_t&)>& predicate) {
        for (const auto& item : source)
          if (!predicate(item)) return false;
        return true;
      }
      /// @brief Determines whether all elements of a sequence satisfy a condition.
      /// @param source An xtd::collections::generic::ienumerable <type_t> that contains the elements to apply the predicate to.
      /// @param predicate A function to test each element for a condition.
      /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all.cpp
      template<typename source_t>
      static bool all(std::initializer_list<source_t> source, const std::function<bool(const source_t&)>& predicate) {
        for (const auto& item : source)
          if (!predicate(item)) return false;
        return true;
      }
      /// @brief Determines whether all elements of a sequence satisfy a condition.
      /// @param source An xtd::collections::generic::ienumerable <type_t> that contains the elements to apply the predicate to.
      /// @param predicate A function to test each element for a condition.
      /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all.cpp
      template<typename source_t, typename collection_t>
      static bool all(const collection_t& source, const std::function<bool(const source_t&)>& predicate) {
        for (const auto& item : source)
          if (!predicate(item)) return false;
        return true;
      }
      /// @brief Determines whether all elements of a sequence satisfy a condition.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @param predicate A function to test each element for a condition.
      /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all.cpp
      template<typename source_t, typename input_iterator_t>
      static bool all(input_iterator_t first, input_iterator_t last, const std::function<bool(const source_t&)>& predicate) {
        for (auto iterator = first; iterator != last; ++iterator)
          if (!predicate(*iterator)) return false;
        return true;
      }
      
      /// @brief Determines whether all elements of a sequence satisfy a condition.
      /// @param source An xtd::collections::generic::ienumerable <type_t> that contains the elements to apply the predicate to.
      /// @param predicate A function to test each element for a condition.
      /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all.cpp
      template<typename source_t, typename predicate_t>
      static bool all(std::initializer_list<source_t> source, const predicate_t& predicate) {
        return all(source, std::function<bool(const source_t&)> {predicate});
      }
      /// @brief Determines whether all elements of a sequence satisfy a condition.
      /// @param source An xtd::collections::generic::ienumerable <type_t> that contains the elements to apply the predicate to.
      /// @param predicate A function to test each element for a condition.
      /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all.cpp
      template<typename collection_t, typename predicate_t>
      static bool all(const collection_t& source, const predicate_t& predicate) {
        using source_t = typename collection_t::value_type;
        return all(source, std::function<bool(const source_t&)> {predicate});
      }
      /// @brief Determines whether all elements of a sequence satisfy a condition.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @param predicate A function to test each element for a condition.
      /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all2.cpp
      template<typename input_iterator_t, typename predicate_t>
      static bool all(input_iterator_t first, input_iterator_t last, const predicate_t& predicate) {
        using source_t = typename std::decay<decltype(*first)>::type;
        return all(first, last, std::function<bool(const source_t&)> {predicate});
      }
      
      /// @brief Determines whether a sequence contains any elements.
      /// @param source The xtd::collections::generic::ienumerable <type_t> to check for emptiness.
      /// @param last The last iterator.
      /// @return true if the source sequence contains any elements; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use Any to determine whether a sequence contains any elements.
      /// @include enumerable_any.cpp
      template<typename source_t>
      static bool any(const xtd::collections::generic::ienumerable<source_t>& source) noexcept {
        return source.begin() != source.end();
      }
      /// @brief Determines whether a sequence contains any elements.
      /// @param source The xtd::collections::generic::ienumerable <type_t> to check for emptiness.
      /// @param last The last iterator.
      /// @return true if the source sequence contains any elements; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use Any to determine whether a sequence contains any elements.
      /// @include enumerable_any.cpp
      template<typename source_t>
      static bool any(std::initializer_list<source_t> source) noexcept {
        return source.begin() != source.end();
      }
      /// @brief Determines whether a sequence contains any elements.
      /// @param source The collection_t to check for emptiness.
      /// @return true if the source sequence contains any elements; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use Any to determine whether a sequence contains any elements.
      /// @include enumerable_any.cpp
      template<typename collection_t>
      static bool any(const collection_t& source) noexcept {
        return source.begin() != source.end();
      }
      /// @brief Determines whether a sequence contains any elements.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @return true if the source sequence contains any elements; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use Any to determine whether a sequence contains any elements.
      /// @include enumerable_any.cpp
      template<typename input_iterator_t>
      static bool any(input_iterator_t first, input_iterator_t last) noexcept {
        return first != last;
      }

      /// @brief Determines whether any element of a sequence satisfies a condition.
      /// @param source An xtd::collections::generic::ienumerable <type_t> that contains the elements to apply the predicate to.
      /// @param predicate A function to test each element for a condition.
      /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all.cpp
      template<typename source_t>
      static bool any(const xtd::collections::generic::ienumerable<source_t>& source, const std::function<bool(const source_t&)>& predicate) {
        for (const auto& item : source)
          if (predicate(item)) return true;
        return false;
      }
      /// @brief Determines whether any element of a sequence satisfies a condition.
      /// @param source An xtd::collections::generic::ienumerable <type_t> that contains the elements to apply the predicate to.
      /// @param predicate A function to test each element for a condition.
      /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all.cpp
      template<typename source_t>
      static bool any(std::initializer_list<source_t> source, const std::function<bool(const source_t&)>& predicate) {
        for (const auto& item : source)
          if (predicate(item)) return true;
        return false;
      }
      /// @brief Determines whether any element of a sequence satisfies a condition.
      /// @param source A collection_t that contains the elements to apply the predicate to.
      /// @param predicate A function to test each element for a condition.
      /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all.cpp
      template<typename source_t, typename collection_t>
      static bool any(const collection_t& source, const std::function<bool(const source_t&)>& predicate) {
        for (const auto& item : source)
          if (predicate(item)) return true;
        return false;
      }
      /// @brief Determines whether any elements of a sequence satisfy a condition.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @param predicate A function to test each element for a condition.
      /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all.cpp
      template<typename source_t, typename input_iterator_t>
      static bool any(input_iterator_t first, input_iterator_t last, const std::function<bool(const source_t&)>& predicate) {
        for (auto iterator = first; iterator != last; ++iterator)
          if (predicate(*iterator)) return true;
        return false;
      }

      /// @brief Determines whether any elements of a sequence satisfy a condition.
      /// @param source A collection_t that contains the elements to apply the predicate to.
      /// @param predicate A function to test each element for a condition.
      /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all.cpp
      template<typename source_t, typename predicate_t>
      static bool any(std::initializer_list<source_t> source, const predicate_t& predicate) {
        return any(source, std::function<bool(const source_t&)> {predicate});
      }
      /// @brief Determines whether any elements of a sequence satisfy a condition.
      /// @param source A collection_t that contains the elements to apply the predicate to.
      /// @param predicate A function to test each element for a condition.
      /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all.cpp
      template<typename collection_t, typename predicate_t>
      static bool any(const collection_t& source, const predicate_t& predicate) {
        using source_t = typename collection_t::value_type;
        return any(source, std::function<bool(const source_t&)> {predicate});
      }
      /// @brief Determines whether any elements of a sequence satisfy a condition.
      /// @param source An xtd::collections::generic::ienumerable <type_t> that contains the elements to apply the predicate to.
      /// @param predicate A function to test each element for a condition.
      /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all2.cpp
      template<typename input_iterator_t, typename predicate_t>
      static bool any(input_iterator_t first, input_iterator_t last, const predicate_t& predicate) {
        using source_t = typename std::decay<decltype(*first)>::type;
        return any(first, last, std::function<bool(const source_t&)> {predicate});
      }
      
      /// @brief Appends a value to the end of the sequence.
      /// @param source A sequence of values.
      /// @param element The value to append to source.
      /// @return A new sequence that ends with element.
      /// @par Examples
      /// The following code example demonstrates how to use Append to append a value to the end of the sequence.
      /// @include enumerable_append.cpp
      template<typename source_t>
      static const xtd::collections::generic::ienumerable<source_t>& append(const xtd::collections::generic::ienumerable<source_t>& source, const source_t& element) noexcept {
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        for (const auto& item : source)
          result.items.push_back(item);
        result.items.push_back(element);
        return result;
      }
      /// @brief Appends a value to the end of the sequence.
      /// @param source A sequence of values.
      /// @param element The value to append to source.
      /// @return A new sequence that ends with element.
      /// @par Examples
      /// The following code example demonstrates how to use Append to append a value to the end of the sequence.
      /// @include enumerable_append.cpp
      template<typename source_t>
      static const xtd::collections::generic::ienumerable<source_t>& append(std::initializer_list<source_t> source, const source_t& element) noexcept {
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        for (const auto& item : source)
          result.items.push_back(item);
        result.items.push_back(element);
        return result;
      }
      /// @brief Appends a value to the end of the sequence.
      /// @param source A sequence of values.
      /// @param element The value to append to source.
      /// @return A new sequence that ends with element.
      /// @par Examples
      /// The following code example demonstrates how to use Append to append a value to the end of the sequence.
      /// @include enumerable_append.cpp
      template<typename source_t, typename collection_t>
      static const xtd::collections::generic::ienumerable<source_t>& append(const collection_t& source, const source_t& element) noexcept {
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        for (const auto& item : source)
          result.items.push_back(item);
        result.items.push_back(element);
        return result;
      }
      /// @brief Appends a value to the end of the sequence.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @param element The value to append to source.
      /// @return A new sequence that ends with element.
      /// @par Examples
      /// The following code example demonstrates how to use Append to append a value to the end of the sequence.
      /// @include enumerable_append2.cpp
      template<typename source_t, typename input_iterator_t>
      static const xtd::collections::generic::ienumerable<source_t>& append(input_iterator_t first, input_iterator_t last, const source_t& element) noexcept {
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        for (auto iterator = first; iterator != last; ++iterator)
          result.items.push_back(*iterator);
        result.items.push_back(element);
        return result;
      }

      /// @brief Returns the input typed as xtd::collection::generic::ienumerable <type_t>.
      /// @param source A sequence of values.
      /// @return The input sequence typed as xtd::collection::generic::ienumerable <type_t>.
      /// @par Example
      /// The following code example demonstrates how to use as_enumerable <source_t>(ienumerable <source_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
      /// @include enumerable_as_enumerable.cpp
      template<typename source_t>
      static const xtd::collections::generic::ienumerable<source_t>& as_enumerable(const xtd::collections::generic::ienumerable<source_t>& source) noexcept {
        return source;
      }
      /// @brief Returns the input typed as xtd::collection::generic::ienumerable <type_t>.
      /// @param source A sequence of values.
      /// @return The input sequence typed as xtd::collection::generic::ienumerable <type_t>.
      /// @par Example
      /// The following code example demonstrates how to use as_enumerable <source_t>(ienumerable <source_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
      /// @include enumerable_as_enumerable.cpp
      template<typename source_t>
      static const xtd::collections::generic::ienumerable<source_t>& as_enumerable(std::initializer_list<source_t> source) noexcept {
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        for (const auto& item : source)
          result.items.push_back(item);
        return result;
      }
      /// @brief Returns the input typed as xtd::collection::generic::ienumerable <type_t>.
      /// @param source A sequence of values.
      /// @return The input sequence typed as xtd::collection::generic::ienumerable <type_t>.
      /// @par Example
      /// The following code example demonstrates how to use as_enumerable <source_t>(ienumerable <source_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
      /// @include enumerable_as_enumerable.cpp
      template <typename collection_t>
      static const auto& as_enumerable(const collection_t& source) noexcept {
        using source_t = typename collection_t::value_type;
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        for (const auto& item : source)
          result.items.push_back(item);
        return static_cast<const xtd::collections::generic::ienumerable<source_t>&>(result);
      }
      /// @brief Returns the input typed as xtd::collection::generic::ienumerable <type_t>.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @return The input sequence typed as xtd::collection::generic::ienumerable <type_t>.
      /// @par Example
      /// The following code example demonstrates how to use as_enumerable <source_t>(ienumerable <source_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
      /// @include enumerable_as_enumerable2.cpp
      template<typename input_iterator_t>
      static const auto& as_enumerable(input_iterator_t first, input_iterator_t last) noexcept {
        using source_t = typename std::decay<decltype(*first)>::type;
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        for (auto iterator = first; iterator != last; ++iterator)
          result.items.push_back(*iterator);
        return static_cast<const xtd::collections::generic::ienumerable<source_t>&>(result);
      }

      /// @brief Computes the average of a sequence of xtd::decimal values.
      /// @param source A sequence of xtd::decimal values to calculate the average of.
      /// @return The average of the sequence of values.
      /// @exception xtd::invalid_operation_exception `source` contains no elements.
      static xtd::decimal average(const xtd::collections::generic::ienumerable<xtd::decimal>& source);
      /// @brief Computes the average of a sequence of double values.
      /// @param source A sequence of double values to calculate the average of.
      /// @return The average of the sequence of values.
      /// @exception xtd::invalid_operation_exception `source` contains no elements.
      static double average(const xtd::collections::generic::ienumerable<double>& source);
      /// @brief Computes the average of a sequence of float values.
      /// @param source A sequence of float values to calculate the average of.
      /// @return The average of the sequence of values.
      /// @exception xtd::invalid_operation_exception `source` contains no elements.
      static float average(const xtd::collections::generic::ienumerable<float>& source);
      /// @brief Computes the average of a sequence of xtd::int32 values.
      /// @param source A sequence of xtd::int32 values to calculate the average of.
      /// @return The average of the sequence of values.
      /// @exception xtd::invalid_operation_exception `source` contains no elements.
      static double average(const xtd::collections::generic::ienumerable<xtd::int32>& source);
      /// @brief Computes the average of a sequence of xtd::int64 values.
      /// @param source A sequence of xtd::int64 values to calculate the average of.
      /// @return The average of the sequence of values.
      /// @exception xtd::invalid_operation_exception `source` contains no elements.
      static double average(const xtd::collections::generic::ienumerable<xtd::int64>& source);

      /// @brief Computes the average of a sequence of optional xtd::decimal values.
      /// @param source A sequence of optional xtd::decimal values to calculate the average of.
      /// @return The average of the sequence of values, or xtd::nullopt if the source sequence is empty or contains only values that are xtd::nullopt.
      static xtd::optional<xtd::decimal> average(const xtd::collections::generic::ienumerable<xtd::optional<xtd::decimal>>& source) noexcept;
      /// @brief Computes the average of a sequence of optional double values.
      /// @param source A sequence of optional double values to calculate the average of.
      /// @return The average of the sequence of values, or xtd::nullopt if the source sequence is empty or contains only values that are xtd::nullopt.
      static xtd::optional<double> average(const xtd::collections::generic::ienumerable<xtd::optional<double>>& source) noexcept;
      /// @brief Computes the average of a sequence of optional float values.
      /// @param source A sequence of optional float values to calculate the average of.
      /// @return The average of the sequence of values, or xtd::nullopt if the source sequence is empty or contains only values that are xtd::nullopt.
      static xtd::optional<float> average(const xtd::collections::generic::ienumerable<xtd::optional<float>>& source) noexcept;
      /// @brief Computes the average of a sequence of optional xtd::int32 values.
      /// @param source A sequence of optional xtd::int32 values to calculate the average of.
      /// @return The average of the sequence of values, or xtd::nullopt if the source sequence is empty or contains only values that are xtd::nullopt.
      static xtd::optional<double> average(const xtd::collections::generic::ienumerable<xtd::optional<xtd::int32>>& source) noexcept;
      /// @brief Computes the average of a sequence of optional xtd::int64 values.
      /// @param source A sequence of optional xtd::int64 values to calculate the average of.
      /// @return The average of the sequence of values, or xtd::nullopt if the source sequence is empty or contains only values that are xtd::nullopt.
      static xtd::optional<double> average(const xtd::collections::generic::ienumerable<xtd::optional<xtd::int64>>& source) noexcept;
      
      /// @brief Returns the first element of the sequence that satisfies a condition or a default value if no such element is found.
      /// @param source A sequence of values to return an element from.
      /// @param default_value The default value to return if the sequence is empty.
      /// @return `default_value`  if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
      template <typename source_t>
      static source_t first_or_default(const xtd::collections::generic::ienumerable<source_t>& source, const source_t& default_value) noexcept {
        return any(source) ? *source.begin() : default_value;
      }
      /// @brief Returns the first element of the sequence that satisfies a condition or a default value if no such element is found.
      /// @param source A sequence of values to return an element from.
      /// @param default_value The default value to return if the sequence is empty.
      /// @return `default_value`  if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
      template <typename source_t>
      static source_t first_or_default(std::initializer_list<source_t> source, const source_t& default_value) noexcept {
        return any(source) ? *source.begin() : default_value;
      }
      /// @brief Returns the first element of the sequence that satisfies a condition or a default value if no such element is found.
      /// @param source A sequence of values to return an element from.
      /// @param default_value The default value to return if the sequence is empty.
      /// @return `default_value`  if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
      template <typename source_t, typename collection_t>
      static auto first_or_default(const collection_t& source, const source_t& default_value) noexcept {
        return any(source) ? *source.begin() : default_value;
      }
      /// @brief Returns the first element of the sequence that satisfies a condition or a default value if no such element is found.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @param default_value The default value to return if the sequence is empty.
      /// @return `default_value`  if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
      template <typename source_t, typename input_iterator_t>
      static auto first_or_default(input_iterator_t first, input_iterator_t last, const source_t& default_value) noexcept {
        return any(first, last) ? *first : default_value;
      }

      /// @brief Returns the first element of the sequence that satisfies a condition or a default value if no such element is found.
      /// @param source A sequence of values to return an element from.
      /// @return default `source_t {}`  if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
      template <typename source_t>
      static source_t first_or_default(const xtd::collections::generic::ienumerable<source_t>& source) noexcept {
        return first_or_default(source, source_t {});
      }
      /// @brief Returns the first element of the sequence that satisfies a condition or a default value if no such element is found.
      /// @param source A sequence of values to return an element from.
      /// @return default `source_t {}`  if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
      template <typename source_t>
      static source_t first_or_default(std::initializer_list<source_t> source) noexcept {
        return first_or_default(source, source_t {});
      }
      /// @brief Returns the first element of the sequence that satisfies a condition or a default value if no such element is found.
      /// @param source A sequence of values to return an element from.
      /// @return default `source_t {}`  if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
      template <typename collection_t>
      static auto first_or_default(const collection_t& source) noexcept {
        using source_t = typename collection_t::value_type;
        return first_or_default(source, source_t {});
      }
      /// @brief Returns the first element of the sequence that satisfies a condition or a default value if no such element is found.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @return default `source_t {}`  if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
      template <typename input_iterator_t>
      static auto first_or_default(input_iterator_t first, input_iterator_t last) noexcept {
        using source_t = typename std::decay<decltype(*first)>::type;
        return first_or_default(first, last, source_t {});
      }

      /// @brief Generates a sequence of integral numbers within a specified range.
      /// @param start The value of the first integer in the sequence.
      /// @param count The number of sequential integers to generate.
      /// @return An xtd::collection::generic::ienumerable <xtd::int32> that contains a range of sequential integral numbers.
      /// @exception xtd::argument_out_of_range_exception `count` is less than 0.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::range to generate a sequence of values.
      /// @include enumerable_range.cpp.cpp
      static const xtd::collections::generic::ienumerable<xtd::int32>& range(xtd::int32 start, xtd::int32 count);
      
      /// @brief Projects each element of a sequence into a new form.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function <result_t(const source_t&)>&) to project over a sequence of values.
      /// @include enumerable_range.cpp.cpp
      template<typename source_t, typename result_t>
      static const xtd::collections::generic::ienumerable<result_t>& select(const xtd::collections::generic::ienumerable<source_t>& source, const std::function<result_t(const source_t&)>& selector) {
        static thread_local auto result = enumerable_collection<result_t> {};
        result = enumerable_collection<result_t> {};
        for (const auto& item : source)
          result.items.push_back(selector(item));
        return result;
      }
      /// @brief Projects each element of a sequence into a new form.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function <result_t(const source_t&)>&) to project over a sequence of values.
      /// @include enumerable_range.cpp.cpp
      template<typename source_t, typename result_t>
      static const xtd::collections::generic::ienumerable<result_t>& select(std::initializer_list<source_t> source, const std::function<result_t(const source_t&)>& selector) {
        static thread_local auto result = enumerable_collection<result_t> {};
        result = enumerable_collection<result_t> {};
        for (const auto& item : source)
          result.items.push_back(selector(item));
        return result;
      }
      /// @brief Projects each element of a sequence into a new form.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function <result_t(const source_t&)>&) to project over a sequence of values.
      /// @include enumerable_range.cpp.cpp
      template<typename source_t, typename result_t, typename collection_t>
      static const xtd::collections::generic::ienumerable<result_t>& select(const collection_t& source, const std::function<result_t(const source_t&)>& selector) {
        static thread_local auto result = enumerable_collection<result_t> {};
        result = enumerable_collection<result_t> {};
        for (const auto& item : source)
          result.items.push_back(selector(item));
        return result;
      }
      /// @brief Projects each element of a sequence into a new form.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function <result_t(const source_t&)>&) to project over a sequence of values.
      /// @include enumerable_range.cpp.cpp
      template<typename source_t, typename result_t, typename input_iterator_t>
      static const xtd::collections::generic::ienumerable<result_t>& select(input_iterator_t first, input_iterator_t last, const std::function<result_t(const source_t&)>& selector) {
        static thread_local auto result = enumerable_collection<result_t> {};
        result = enumerable_collection<result_t> {};
        for (auto iterator = first; iterator != last; ++iterator)
          result.items.push_back(selector(*iterator));
        return result;
      }
      
      /// @brief Projects each element of a sequence into a new form.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function <result_t(const source_t&)>&) to project over a sequence of values.
      /// @include enumerable_range.cpp.cpp
      template<typename source_t>
      static const xtd::collections::generic::ienumerable<source_t>& select(const xtd::collections::generic::ienumerable<source_t>& source, const std::function<source_t(const source_t&)>& selector) {
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        for (const auto& item : source)
          result.items.push_back(selector(item));
        return result;
      }
      /// @brief Projects each element of a sequence into a new form.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function <result_t(const source_t&)>&) to project over a sequence of values.
      /// @include enumerable_range.cpp.cpp
      template<typename source_t>
      static const xtd::collections::generic::ienumerable<source_t>& select(std::initializer_list<source_t> source, const std::function<source_t(const source_t&)>& selector) {
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        for (const auto& item : source)
          result.items.push_back(selector(item));
        return result;
      }
      /// @brief Projects each element of a sequence into a new form.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function <result_t(const source_t&)>&) to project over a sequence of values.
      /// @include enumerable_range.cpp.cpp
      template<typename source_t, typename collection_t>
      static const xtd::collections::generic::ienumerable<source_t>& select(const collection_t& source, const std::function<source_t(const source_t&)>& selector) {
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        for (const auto& item : source)
          result.items.push_back(selector(item));
        return result;
      }
      /// @brief Projects each element of a sequence into a new form.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function <result_t(const source_t&)>&) to project over a sequence of values.
      /// @include enumerable_range.cpp.cpp
      template<typename source_t, typename input_iterator_t>
      static const xtd::collections::generic::ienumerable<source_t>& select(input_iterator_t first, input_iterator_t last, const std::function<source_t(const source_t&)>& selector) {
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        for (auto iterator = first; iterator != last; ++iterator)
          result.items.push_back(selector(*iterator));
        return result;
      }
      
      /// @brief Projects each element of a sequence into a new form by incorporating the element's index.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each source element; the second parameter of the function represents the index of the source element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function <result_t(const source_t&, size_t)>&) to project over a sequence of values and use the index of each element.
      /// @include enumerable_select.cpp
      template<typename source_t, typename result_t>
      static const xtd::collections::generic::ienumerable<result_t>& select(const xtd::collections::generic::ienumerable<source_t>& source, const std::function<result_t(const source_t&, size_t)>& selector) {
        static thread_local auto result = enumerable_collection<result_t> {};
        result = enumerable_collection<result_t> {};
        auto index = size_t {0};
        for (const auto& item : source)
          result.items.push_back(selector(item, index++));
        return result;
      }
      /// @brief Projects each element of a sequence into a new form by incorporating the element's index.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each source element; the second parameter of the function represents the index of the source element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function <result_t(const source_t&, size_t)>&) to project over a sequence of values and use the index of each element.
      /// @include enumerable_select.cpp
      template<typename source_t, typename result_t>
      static const xtd::collections::generic::ienumerable<result_t>& select(std::initializer_list<source_t> source, const std::function<result_t(const source_t&, size_t)>& selector) {
        static thread_local auto result = enumerable_collection<result_t> {};
        result = enumerable_collection<result_t> {};
        auto index = size_t {0};
        for (const auto& item : source)
          result.items.push_back(selector(item, index++));
        return result;
      }
      /// @brief Projects each element of a sequence into a new form by incorporating the element's index.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each source element; the second parameter of the function represents the index of the source element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function <result_t(const source_t&, size_t)>&) to project over a sequence of values and use the index of each element.
      /// @include enumerable_select.cpp
      template<typename source_t, typename result_t, typename collection_t>
      static const xtd::collections::generic::ienumerable<result_t>& select(const collection_t& source, const std::function<result_t(const source_t&, size_t)>& selector) {
        static thread_local auto result = enumerable_collection<result_t> {};
        result = enumerable_collection<result_t> {};
        auto index = size_t {0};
        for (const auto& item : source)
          result.items.push_back(selector(item, index++));
        return result;
      }
      /// @brief Projects each element of a sequence into a new form by incorporating the element's index.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each source element; the second parameter of the function represents the index of the source element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function <result_t(const source_t&, size_t)>&) to project over a sequence of values and use the index of each element.
      /// @include enumerable_select.cpp
      template<typename source_t, typename result_t, typename input_iterator_t>
      static const xtd::collections::generic::ienumerable<result_t>& select(input_iterator_t first, input_iterator_t last, const std::function<result_t(const source_t&, size_t)>& selector) {
        static thread_local auto result = enumerable_collection<result_t> {};
        result = enumerable_collection<result_t> {};
        auto index = size_t {0};
        for (auto iterator = first; iterator != last; ++iterator)
          result.items.push_back(selector(*iterator, index++));
        return result;
      }
      
      /// @brief Projects each element of a sequence into a new form by incorporating the element's index.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each source element; the second parameter of the function represents the index of the source element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function <result_t(const source_t&, size_t)>&) to project over a sequence of values and use the index of each element.
      /// @include enumerable_select.cpp
      template<typename source_t>
      static const xtd::collections::generic::ienumerable<source_t>& select(const xtd::collections::generic::ienumerable<source_t>& source, const std::function<source_t(const source_t&, size_t)>& selector) {
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        auto index = size_t {0};
        for (const auto& item : source)
          result.items.push_back(selector(item, index++));
        return result;
      }
      /// @brief Projects each element of a sequence into a new form by incorporating the element's index.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each source element; the second parameter of the function represents the index of the source element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function <result_t(const source_t&, size_t)>&) to project over a sequence of values and use the index of each element.
      /// @include enumerable_select.cpp
      template<typename source_t>
      static const xtd::collections::generic::ienumerable<source_t>& select(std::initializer_list<source_t> source, const std::function<source_t(const source_t&, size_t)>& selector) {
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        auto index = size_t {0};
        for (const auto& item : source)
          result.items.push_back(selector(item, index++));
        return result;
      }
      /// @brief Projects each element of a sequence into a new form by incorporating the element's index.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each source element; the second parameter of the function represents the index of the source element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function <result_t(const source_t&, size_t)>&) to project over a sequence of values and use the index of each element.
      /// @include enumerable_select.cpp
      template<typename source_t, typename collection_t>
      static const xtd::collections::generic::ienumerable<source_t>& select(const collection_t& source, const std::function<source_t(const source_t&, size_t)>& selector) {
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        auto index = size_t {0};
        for (const auto& item : source)
          result.items.push_back(selector(item, index++));
        return result;
      }
      /// @brief Projects each element of a sequence into a new form by incorporating the element's index.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each source element; the second parameter of the function represents the index of the source element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function <result_t(const source_t&, size_t)>&) to project over a sequence of values and use the index of each element.
      /// @include enumerable_select.cpp
      template<typename source_t, typename input_iterator_t>
      static const xtd::collections::generic::ienumerable<source_t>& select(input_iterator_t first, input_iterator_t last, const std::function<source_t(const source_t&, size_t)>& selector) {
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        auto index = size_t {0};
        for (auto iterator = first; iterator != last; ++iterator)
          result.items.push_back(selector(*iterator, index++));
        return result;
      }

      /// @brief Creates a xtd::collections::generic::list <type_t> from an xtd::collections::generic::ienumerable <type_t>.
      /// @param source The xtd::collections::generic::ienumerable <type_t> to create a xtd::collections::generic::list <type_t> from.
      /// @return A xtd::collections::generic::list <type_t> that contains elements from the input sequence.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::to_list to force immediate query evaluation and return a xtd::collection::generic::list <type_t> that contains the query results.
      /// @include enumerable_to_list.cpp
      template<typename source_t>
      static const xtd::collections::generic::list<source_t>& to_list(const xtd::collections::generic::ienumerable<source_t>& source) noexcept;
      /// @brief Creates a xtd::collections::generic::list <type_t> from an std::initializer_list <type_t>.
      /// @param source The std::initializer_list <type_t> to create a xtd::collections::generic::list <type_t> from.
      /// @return A xtd::collections::generic::list <type_t> that contains elements from the input sequence.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::to_list to force immediate query evaluation and return a xtd::collection::generic::list <type_t> that contains the query results.
      /// @include enumerable_to_list.cpp
      template<typename source_t>
      static const xtd::collections::generic::list<source_t>& to_list(std::initializer_list<source_t> source) noexcept;
      /// @brief Creates a xtd::collections::generic::list <type_t> from an collection_t.
      /// @param source The collection_t to create a xtd::collections::generic::list <type_t> from.
      /// @return A xtd::collections::generic::list <type_t> that contains elements from the input sequence.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::to_list to force immediate query evaluation and return a xtd::collection::generic::list <type_t> that contains the query results.
      /// @include enumerable_to_list.cpp
      template<typename collection_t>
      static const auto& to_list(const collection_t& source) noexcept {
        using source_t = typename collection_t::value_type;
        return collection_to_list<source_t, collection_t>(source);
      }
      /// @brief Creates a xtd::collections::generic::list <type_t> from iterators.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @return A xtd::collections::generic::list <type_t> that contains elements from the input sequence.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::to_list to force immediate query evaluation and return a xtd::collection::generic::list <type_t> that contains the query results.
      /// @include enumerable_to_list.cpp
      template<typename input_iterator_t>
      static const auto& to_list(input_iterator_t first, input_iterator_t last) noexcept {
        using source_t = typename std::decay<decltype(*first)>::type;
        return input_iterator_to_list<source_t, input_iterator_t>(first, last);
      }
      
      /// @brief Filters a sequence of values based on a predicate.
      /// @param source A sequence of values to filter.
      /// @param predicate A function to test each element for a condition.
      /// @return An xtd::collections::generic::ienumerable <type_t> that contains elements from the input sequence that satisfy the condition.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::where <source_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function<bool (const source_t&)>&) to filter a sequence.
      /// @include enumerable_where.cpp
      template<typename source_t>
      static const xtd::collections::generic::ienumerable<source_t>& where(const xtd::collections::generic::ienumerable<source_t>& source, const std::function<bool(const source_t&)>& predicate) {
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        for (const auto& item : source)
          if (predicate(item)) result.items.push_back(item);
        return result;
      }
      /// @brief Filters a sequence of values based on a predicate.
      /// @param source A sequence of values to filter.
      /// @param predicate A function to test each element for a condition.
      /// @return An xtd::collections::generic::ienumerable <type_t> that contains elements from the input sequence that satisfy the condition.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::where <source_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function<bool (const source_t&)>&) to filter a sequence.
      /// @include enumerable_where.cpp
      template<typename source_t>
      static const xtd::collections::generic::ienumerable<source_t>& where(std::initializer_list<source_t> source, const std::function<bool(const source_t&)>& predicate) {
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        for (const auto& item : source)
          if (predicate(item)) result.items.push_back(item);
        return result;
      }
      /// @brief Filters a sequence of values based on a predicate.
      /// @param source A sequence of values to filter.
      /// @param predicate A function to test each element for a condition.
      /// @return An xtd::collections::generic::ienumerable <type_t> that contains elements from the input sequence that satisfy the condition.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::where <source_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function<bool (const source_t&)>&) to filter a sequence.
      /// @include enumerable_where.cpp
      template<typename source_t, typename collection_t>
      static const xtd::collections::generic::ienumerable<source_t>& where(const collection_t& source, const std::function<bool(const source_t&)>& selector) {
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        for (const auto& item : source)
          if (predicate(item)) result.items.push_back(item);
        return result;
      }
      /// @brief Filters a sequence of values based on a predicate.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @param predicate A function to test each element for a condition.
      /// @return An xtd::collections::generic::ienumerable <type_t> that contains elements from the input sequence that satisfy the condition.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::where <source_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function<bool (const source_t&)>&) to filter a sequence.
      /// @include enumerable_where.cpp
      template<typename source_t, typename input_iterator_t>
      static const xtd::collections::generic::ienumerable<source_t>& where(input_iterator_t first, input_iterator_t last, const std::function<bool(const source_t&)>& predicate) {
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        for (auto iterator = first; iterator != last; ++iterator)
          if (predicate(*iterator)) result.items.push_back(*iterator);
        return result;
      }

      /// @brief Filters a sequence of values based on a predicate. Each element's index is used in the logic of the predicate function.
      /// @param source A sequence of values to filter.
      /// @param predicate A function to test each source element for a condition; the second parameter of the function represents the index of the source element.
      /// @return An xtd::collections::generic::ienumerable <type_t> that contains elements from the input sequence that satisfy the condition.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::where <source_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function<bool (const source_t&, size_t)>&) to filter a sequence based on a predicate that involves the index of each element.
      /// @include enumerable_where2.cpp
      template<typename source_t>
      static const xtd::collections::generic::ienumerable<source_t>& where(const xtd::collections::generic::ienumerable<source_t>& source, const std::function<bool(const source_t&, size_t)>& predicate) {
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        auto index = size_t {0};
        for (const auto& item : source)
          if (predicate(item, index++)) result.items.push_back(item);
        return result;
      }
      /// @brief Filters a sequence of values based on a predicate. Each element's index is used in the logic of the predicate function.
      /// @param source A sequence of values to filter.
      /// @param predicate A function to test each source element for a condition; the second parameter of the function represents the index of the source element.
      /// @return An xtd::collections::generic::ienumerable <type_t> that contains elements from the input sequence that satisfy the condition.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::where <source_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function<bool (const source_t&, size_t)>&) to filter a sequence based on a predicate that involves the index of each element.
      /// @include enumerable_where2.cpp
      template<typename source_t>
      static const xtd::collections::generic::ienumerable<source_t>& where(std::initializer_list<source_t> source, const std::function<bool(const source_t&, size_t)>& predicate) {
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        auto index = size_t {0};
        for (const auto& item : source)
          if (predicate(item, index++)) result.items.push_back(item);
        return result;
      }
      /// @brief Filters a sequence of values based on a predicate. Each element's index is used in the logic of the predicate function.
      /// @param source A sequence of values to filter.
      /// @param predicate A function to test each source element for a condition; the second parameter of the function represents the index of the source element.
      /// @return An xtd::collections::generic::ienumerable <type_t> that contains elements from the input sequence that satisfy the condition.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::where <source_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function<bool (const source_t&, size_t)>&) to filter a sequence based on a predicate that involves the index of each element.
      /// @include enumerable_where2.cpp
      template<typename source_t, typename collection_t>
      static const xtd::collections::generic::ienumerable<source_t>& where(const collection_t& source, const std::function<bool(const source_t&, size_t)>& selector) {
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        auto index = size_t {0};
        for (const auto& item : source)
          if (predicate(item, index++)) result.items.push_back(item);
        return result;
      }
      /// @brief Filters a sequence of values based on a predicate. Each element's index is used in the logic of the predicate function.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @param predicate A function to test each source element for a condition; the second parameter of the function represents the index of the source element.
      /// @return An xtd::collections::generic::ienumerable <type_t> that contains elements from the input sequence that satisfy the condition.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::where <source_t>(const xtd::collections::generic::ienumerable <source_t>&, const std::function<bool (const source_t&, size_t)>&) to filter a sequence based on a predicate that involves the index of each element.
      /// @include enumerable_where2.cpp
      template<typename source_t, typename input_iterator_t>
      static const xtd::collections::generic::ienumerable<source_t>& where(input_iterator_t first, input_iterator_t last, const std::function<bool(const source_t&, size_t)>& predicate) {
        static thread_local auto result = enumerable_collection<source_t> {};
        result = enumerable_collection<source_t> {};
        auto index = size_t {0};
        for (auto iterator = first; iterator != last; ++iterator)
          if (predicate(*iterator, index++)) result.items.push_back(*iterator);
        return result;
      }
      /// @}
      
    private:
      template<typename source_t, typename collection_t>
      static const xtd::collections::generic::list<source_t>& collection_to_list(const collection_t& source) noexcept;
      template<typename source_t, typename input_iterator_t>
      static const xtd::collections::generic::list<source_t>& input_iterator_to_list(input_iterator_t first, input_iterator_t last) noexcept;
      static void throw_argument_out_of_range_exception();
      static void throw_invalid_operation_exception();
    };
  }
}

#include "../collections/generic/extensions/enumerable.hpp"
#include "from.hpp"
