/// @file
/// @brief Contains xtd::collections::generic::enumerable <type_t> class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "enumerable_collection.hpp"
#include "../predicate.hpp"
#include "../static.hpp"
#include <algorithm>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides classes and interfaces that support queries that use Language-Integrated Query (LINQ).
  namespace linq {
    /// @brief Provides a set of static methods for querying objects that implement ienumerable <type_t>.
    /// @par Definition
    /// ```cpp
    /// template<typename type_t>
    /// class enumerable : public xtd::static_object;
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/linq/enumerable
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
      static source_t aggregate(const xtd::collections::generic::ienumerable<source_t>& source, const xtd::func<source_t, const source_t&, const source_t&>& func)  {
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
      /// The following code example demonstrates how to reverse the order of words in a string by using xtd::linq::enumerable::aggregate.
      /// @include enumerable_aggregate.cpp
      template<typename source_t, typename func_t>
      static source_t aggregate(const xtd::collections::generic::ienumerable<source_t>& source, const func_t& func)  {
        return aggregate(source, xtd::func<source_t, const source_t&, const source_t&> {func});
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
      static accumulate_t aggregate(const xtd::collections::generic::ienumerable<source_t>& source, const accumulate_t& seed, const xtd::func<accumulate_t, const source_t&, const accumulate_t&>& func)  {
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
      template<typename source_t, typename accumulate_t, typename func_t>
      static accumulate_t aggregate(const xtd::collections::generic::ienumerable<source_t>& source, const accumulate_t& seed, const func_t& func)  {
        return aggregate(source, seed, xtd::func<accumulate_t, const source_t&, const accumulate_t&> {func});
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
      static result_t aggregate(const xtd::collections::generic::ienumerable<source_t>& source, const accumulate_t& seed, const xtd::func<accumulate_t, const source_t&, const accumulate_t&>& func, const xtd::func<result_t, const accumulate_t&>& result_selector) {
        auto aggregated = seed;
        for (const auto& item : source)
          aggregated = func(aggregated, item);
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
        return aggregate(source, seed, xtd::func<accumulate_t, const source_t&, const accumulate_t&> {func}, xtd::func<result_t, const accumulate_t&> {result_selector});
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
        return aggregate(source, seed, xtd::func<accumulate_t, const source_t&, const accumulate_t&> {func}, xtd::func<accumulate_t, const accumulate_t&> {result_selector});
      }
      /// @brief Applies an accumulator function over a sequence.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to reverse the order of words in a string by using enumerable::aggregate.
      /// @include enumerable_aggregate4.cpp
      template<typename accumulate_t, typename input_iterator_t>
      static accumulate_t aggregate(input_iterator_t first, input_iterator_t last, const xtd::func<accumulate_t, const accumulate_t&, const accumulate_t&>& func)  {
        auto nb = 0;
        auto aggregated = accumulate_t {};
        for (auto iterator = first; iterator != last; ++iterator)
          if (nb++ == 0) aggregated = *iterator;
          else aggregated = func(aggregated, *iterator);
        return aggregated;
      }
      /// @brief Applies an accumulator function over a sequence.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to reverse the order of words in a string by using xtd::linq::enumerable::aggregate.
      /// @include enumerable_aggregate4.cpp
      template<typename accumulate_t, typename input_iterator_t, typename func_t>
      static accumulate_t aggregate(input_iterator_t first, input_iterator_t last, const func_t& func)  {
        return aggregate(first, last, xtd::func<accumulate_t, const accumulate_t&, const accumulate_t&> {func});
      }
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value.
      /// @param source An xtd::collections::generic::ienumerable <type_t> to aggregate over.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate5.cpp
      template<typename accumulate_t, typename input_iterator_t>
      static accumulate_t aggregate(input_iterator_t first, input_iterator_t last, const accumulate_t& seed, const xtd::func<accumulate_t, const accumulate_t&, const accumulate_t&>& func)  {
        auto aggregated = seed;
        for (auto iterator = first; iterator != last; ++iterator)
          aggregated = func(aggregated, *iterator);
        return aggregated;
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
      static accumulate_t aggregate(input_iterator_t first, input_iterator_t last, const accumulate_t& seed, const func_t& func)  {
        return aggregate(first, last, seed, xtd::func<accumulate_t, const accumulate_t&, const accumulate_t&> {func});
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
      template<typename accumulate_t, typename result_t, typename input_iterator_t>
      static result_t aggregate(input_iterator_t first, input_iterator_t last, const accumulate_t& seed, const xtd::func<accumulate_t, const accumulate_t&, const accumulate_t&>& func, const xtd::func<result_t, const accumulate_t&>& result_selector) {
        auto aggregated = seed;
        for (auto iterator = first; iterator != last; ++iterator)
          aggregated = func(aggregated, *iterator);
        return result_selector(aggregated);
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
        return aggregate(first, last, seed, xtd::func<accumulate_t, const accumulate_t&, const accumulate_t&> {func}, xtd::func<result_t, const accumulate_t&> {result_selector});
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
        return aggregate(first, last, seed, xtd::func<accumulate_t, const accumulate_t&, const accumulate_t&> {func}, xtd::func<accumulate_t, const accumulate_t&> {result_selector});
      }
      
      /// @brief Determines whether all elements of a sequence satisfy a condition.
      /// @param source An xtd::collections::generic::ienumerable <type_t> that contains the elements to apply the predicate to.
      /// @param predicate A function to test each element for a condition.
      /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all.cpp
      template<typename source_t>
      static bool all(const xtd::collections::generic::ienumerable<source_t>& source, const xtd::predicate<const source_t&>& predicate) {
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
      template<typename source_t, typename predicate_t>
      static bool all(const xtd::collections::generic::ienumerable<source_t>& source, const predicate_t& predicate) {
        return all(source, xtd::predicate<const source_t&> {predicate});
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
      static bool all(input_iterator_t first, input_iterator_t last, const xtd::predicate<const source_t&>& predicate) {
        for (auto iterator = first; iterator != last; ++iterator)
          if (!predicate(*iterator)) return false;
        return true;
      }
      /// @brief Determines whether all elements of a sequence satisfy a condition.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @param predicate A function to test each element for a condition.
      /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all2.cpp
      template<typename source_t, typename input_iterator_t, typename predicate_t>
      static bool all(input_iterator_t first, input_iterator_t last, const predicate_t& predicate) {
        return all(first, last, xtd::predicate<const source_t&> {predicate});
      }
      
      /// @brief Determines whether a sequence contains any elements.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @return true if the source sequence contains any elements; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use Any to determine whether a sequence contains any elements.
      /// @include EnumerableAny.cpp
      template<typename source_t>
      static bool any(const xtd::collections::generic::ienumerable<source_t>& source) {
        return source.get_enumerator().move_next();
      }
      /// @brief Determines whether any element of a sequence satisfies a condition.
      /// @param source An xtd::collections::generic::ienumerable <type_t> that contains the elements to apply the predicate to.
      /// @param predicate A function to test each element for a condition.
      /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all.cpp
      template<typename source_t>
      static bool any(const xtd::collections::generic::ienumerable<source_t>& source, const xtd::predicate<const source_t&>& predicate) {
        for (const auto& item : source)
          if (predicate(item)) return true;
        return false;
      }
      /// @brief Determines whether any elements of a sequence satisfy a condition.
      /// @param source An xtd::collections::generic::ienumerable <type_t> that contains the elements to apply the predicate to.
      /// @param predicate A function to test each element for a condition.
      /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all.cpp
      template<typename source_t, typename predicate_t>
      static bool any(const xtd::collections::generic::ienumerable<source_t>& source, const predicate_t& predicate) {
        return any(source, xtd::predicate<const source_t&> {predicate});
      }
      /// @brief Determines whether a sequence contains any elements.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @return true if the source sequence contains any elements; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use Any to determine whether a sequence contains any elements.
      /// @include EnumerableAny.cpp
      template<typename source_t, typename input_iterator_t>
      static bool any(input_iterator_t first, input_iterator_t last) {
        return first != last;
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
      static bool any(input_iterator_t first, input_iterator_t last, const xtd::predicate<const source_t&>& predicate) {
        for (auto iterator = first; iterator != last; ++iterator)
          if (predicate(*iterator)) return true;
        return false;
      }
      /// @brief Determines whether any elements of a sequence satisfy a condition.
      /// @param source An xtd::collections::generic::ienumerable <type_t> that contains the elements to apply the predicate to.
      /// @param predicate A function to test each element for a condition.
      /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all2.cpp
      template<typename source_t, typename input_iterator_t, typename predicate_t>
      static bool any(input_iterator_t first, input_iterator_t last, const predicate_t& predicate) {
        return any(first, last, xtd::predicate<const source_t&> {predicate});
      }
      /// @}
    };
  }
}
