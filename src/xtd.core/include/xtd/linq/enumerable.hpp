/// @file
/// @brief Contains xtd::linq::enumerable <type_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../collections/generic/helpers/allocator.hpp"
//#include "../collections/generic/iequality_comparer.hpp"
#include "../collections/generic/equality_comparer.hpp"
#define __XTD_CORE_INTERNAL__
#include "../internal/__array_definition.hpp"
#include "../internal/__key_value_pair_definition.hpp"
#include "../internal/__list_definition.hpp"
#undef  __XTD_CORE_INTERNAL__
#include "../decimal.hpp"
#include "../iequatable.hpp"
#include "../int32.hpp"
#include "../int64.hpp"
#include "../optional.hpp"
#include "../size.hpp"
#include "../static.hpp"
#include <algorithm>
#include <functional>

/// @cond
template<class type_t>
struct __opaque_xtd_linq_enumerable_collection__;
template<class type_t, class param_t>
struct __opaque_xtd_linq_lazy_enumerable__;
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace collections::generic {
    template<class type_t>
    class ienumerable;
  }
  /// @endcond
  
  /// @brief Provides classes and interfaces that support queries that use Language-Integrated Query (LINQ).
  namespace linq {

    /// @brief Provides a set of static methods for querying objects that implement ienumerable <type_t>.
    /// @par Definition
    /// ```cpp
    /// template<class type_t>
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
      /// @name Public Aliases
      
      /// @{
      /// @brief Represents the ienumerable value type.
      template<class type_t>
      using iequality_comparer = typename xtd::collections::generic::iequality_comparer<type_t>;
      
      /// @brief Represents the ienumerable value type.
      template<class type_t>
      using ienumerable = typename xtd::collections::generic::ienumerable<type_t>;
      
      /// @brief Represents the list value type.
      template<class type_t>
      using list = typename xtd::collections::generic::list<type_t>;
      
      /// @brief Represents the key value pair value type.
      template<class key_t, class value_t>
      using key_value_pair = xtd::collections::generic::key_value_pair<key_t, value_t>;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Applies an accumulator function over a sequence.
      /// @tparam source_t The type of the elements of source.
      /// @param source An xtd::collections::generic::ienumerable <type_t> to aggregate over.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to reverse the order of words in a string by using enumerable::aggregate.
      /// @include enumerable_aggregate.cpp
      template<class source_t>
      static source_t aggregate(const ienumerable<source_t>& source, const std::function<source_t(const source_t&, const source_t&)>& func) {
        auto nb = 0;
        auto aggregated = source_t {};
        for (const auto& item : source)
          if (nb++ == 0) aggregated = item;
          else aggregated = func(aggregated, item);
        return aggregated;
      }
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value.
      /// @tparam source_t The type of the elements of source.
      /// @param source An xtd::collections::generic::ienumerable <type_t> to aggregate over.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate2.cpp
      template<class source_t>
      static source_t aggregate(const ienumerable<source_t>& source, const source_t& seed, const std::function<source_t(const source_t&, const source_t&)>& func) {
        auto aggregated = seed;
        for (const auto& item : source)
          aggregated = func(aggregated, item);
        return aggregated;
      }
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value.
      /// @tparam accumulate_t The type of the accumulator value.
      /// @tparam source_t The type of the elements of source.
      /// @param source An xtd::collections::generic::ienumerable <type_t> to aggregate over.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @return The final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate2.cpp
      template<class accumulate_t, class source_t>
      static accumulate_t aggregate(const ienumerable<source_t>& source, const accumulate_t& seed, const std::function<accumulate_t(const source_t&, const accumulate_t&)>& func) {
        auto aggregated = seed;
        for (const auto& item : source)
          aggregated = func(aggregated, item);
        return aggregated;
      }
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
      /// @tparam source_t The type of the elements of source.
      /// @param source An xtd::collections::generic::ienumerable <type_t> to aggregate over.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @param result_Selector A function to transform the final accumulator value into the result value.
      /// @return The transformed final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate3.cpp
      template<class source_t>
      static source_t aggregate(const ienumerable<source_t>& source, const source_t& seed, const std::function<source_t(const source_t&, const source_t&)>& func, const std::function<source_t(const source_t&)>& result_selector) {
        auto aggregated = seed;
        for (const auto& item : source)
          aggregated = func(aggregated, item);
        return result_selector(aggregated);
      }
      /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
      /// @tparam result_t The type of the resulting value.
      /// @tparam accumulate_t The type of the accumulator value.
      /// @tparam source_t The type of the elements of source.
      /// @param source An xtd::collections::generic::ienumerable <type_t> to aggregate over.
      /// @param seed The initial accumulator value.
      /// @param func An accumulator function to be invoked on each element.
      /// @param result_Selector A function to transform the final accumulator value into the result value.
      /// @return The transformed final accumulator value.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
      /// @include enumerable_aggregate3.cpp
      template<class result_t, class accumulate_t, class source_t>
      static result_t aggregate(const ienumerable<source_t>& source, const accumulate_t& seed, const std::function<accumulate_t(const source_t&, const accumulate_t&)>& func, const std::function<result_t(const accumulate_t&)>& result_selector) {
        auto aggregated = seed;
        for (const auto& item : source)
          aggregated = func(aggregated, item);
        return result_selector(aggregated);
      }

      /// @brief Determines whether all elements of a sequence satisfy a condition.
      /// @tparam source_t The type of the elements of source.
      /// @param source An xtd::collections::generic::ienumerable <type_t> that contains the elements to apply the predicate to.
      /// @param predicate A function to test each element for a condition.
      /// @return `true` if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, `false`.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is `true` if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all.cpp
      template<class source_t>
      static bool all(const ienumerable<source_t>& source, const std::function<bool(const source_t&)>& predicate) {
        for (const auto& item : source)
          if (!predicate(item)) return false;
        return true;
      }
            
      /// @brief Determines whether a sequence contains any elements.
      /// @tparam source_t The type of the elements of source.
      /// @param source The xtd::collections::generic::ienumerable <type_t> to check for emptiness.
      /// @param last The last iterator.
      /// @return `true` if the source sequence contains any elements; otherwise, `false`.
      /// @par Examples
      /// The following code example demonstrates how to use Any to determine whether a sequence contains any elements.
      /// @include enumerable_any.cpp
      template<class source_t>
      static bool any(const ienumerable<source_t>& source) noexcept {
        return source.begin() != source.end();
      }
      /// @brief Determines whether any element of a sequence satisfies a condition.
      /// @tparam source_t The type of the elements of source.
      /// @param source An xtd::collections::generic::ienumerable <type_t> that contains the elements to apply the predicate to.
      /// @param predicate A function to test each element for a condition.
      /// @return `true` if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, `false`.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is `true` if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all.cpp
      template<class source_t>
      static bool any(const ienumerable<source_t>& source, const std::function<bool(const source_t&)>& predicate) {
        for (const auto& item : source)
          if (predicate(item)) return true;
        return false;
      }
      
      /// @brief Appends a value to the end of the sequence.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values.
      /// @param element The value to append to source.
      /// @return A new sequence that ends with element.
      /// @par Examples
      /// The following code example demonstrates how to use Append to append a value to the end of the sequence.
      /// @include enumerable_append.cpp
      template<class source_t>
      static const ienumerable<source_t>& append(const ienumerable<source_t>& source, const source_t& element) noexcept {
        static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<source_t> {};
        result = __opaque_xtd_linq_enumerable_collection__<source_t> {};
        for (const auto& item : source)
          result.items.push_back(item);
        result.items.push_back(element);
        return result;
      }

      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @par Example
      /// The following code example demonstrates how to use as_enumerable <source_t>(ienumerable <source_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
      /// @include enumerable_as_enumerable.cpp
      template<class source_t>
      static const ienumerable<source_t>& as_enumerable(const ienumerable<source_t>& source) noexcept {
        return source;
      }
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @par Example
      /// The following code example demonstrates how to use as_enumerable <source_t>(ienumerable <source_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
      /// @include enumerable_as_enumerable.cpp
      template<class source_t>
      static const ienumerable<source_t>& as_enumerable(std::initializer_list<source_t> source) noexcept {
        static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<source_t> {};
        result = __opaque_xtd_linq_enumerable_collection__<source_t> {};
        for (const auto& item : source)
          result.items.push_back(item);
        return result;
      }
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam collection_t The type of the source.
      /// @param source A sequence of values.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @par Example
      /// The following code example demonstrates how to use as_enumerable <source_t>(ienumerable <source_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
      /// @include enumerable_as_enumerable.cpp
      template<class collection_t>
      static const auto& as_enumerable(const collection_t& source) noexcept {
        using source_t = typename collection_t::value_type;
        static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<source_t> {};
        result = __opaque_xtd_linq_enumerable_collection__<source_t> {};
        for (const auto& item : source)
          result.items.push_back(item);
        return static_cast<const ienumerable<source_t>&>(result);
      }
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam input_iterator_t The type of the source iterators.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @par Example
      /// The following code example demonstrates how to use as_enumerable <source_t>(ienumerable <source_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
      /// @include enumerable_as_enumerable2.cpp
      template<class input_iterator_t>
      static const auto& as_enumerable(input_iterator_t first, input_iterator_t last) noexcept {
        using source_t = typename std::decay<decltype(*first)>::type;
        static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<source_t> {};
        result = __opaque_xtd_linq_enumerable_collection__<source_t> {};
        for (auto iterator = first; iterator != last; ++iterator)
          result.items.push_back(*iterator);
        return static_cast<const ienumerable<source_t>&>(result);
      }
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam input_iterator_t The type of the source iterators.
      /// @param iterator The iterator.
      /// @param legnth The le,gth to iterate.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @par Example
      /// The following code example demonstrates how to use as_enumerable <source_t>(ienumerable <source_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
      /// @include enumerable_as_enumerable2.cpp
      template<class input_iterator_t>
      static const auto& as_enumerable(input_iterator_t iterator, size_t length) noexcept {
        return as_enumerable(iterator, iterator + length);
      }
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam source_t The type of the source array.
      /// @param array The native array.
      /// @param legnth The length of the array.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @par Example
      /// The following code example demonstrates how to use as_enumerable <source_t>(ienumerable <source_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
      /// @include enumerable_as_enumerable.cpp
      template<class source_t, size_t length>
      static const auto& as_enumerable(const source_t (&array)[length]) noexcept {
        return as_enumerable(array, array + length);
      }

      /// @brief Computes the average of a sequence of xtd::decimal values.
      /// @param source A sequence of xtd::decimal values to calculate the average of.
      /// @return The average of the sequence of values.
      /// @exception xtd::invalid_operation_exception `source` contains no elements.
      static xtd::decimal average(const ienumerable<xtd::decimal>& source);
      /// @brief Computes the average of a sequence of double values.
      /// @param source A sequence of double values to calculate the average of.
      /// @return The average of the sequence of values.
      /// @exception xtd::invalid_operation_exception `source` contains no elements.
      static double average(const ienumerable<double>& source);
      /// @brief Computes the average of a sequence of float values.
      /// @param source A sequence of float values to calculate the average of.
      /// @return The average of the sequence of values.
      /// @exception xtd::invalid_operation_exception `source` contains no elements.
      static float average(const ienumerable<float>& source);
      /// @brief Computes the average of a sequence of xtd::int32 values.
      /// @param source A sequence of xtd::int32 values to calculate the average of.
      /// @return The average of the sequence of values.
      /// @exception xtd::invalid_operation_exception `source` contains no elements.
      static double average(const ienumerable<xtd::int32>& source);
      /// @brief Computes the average of a sequence of xtd::int64 values.
      /// @param source A sequence of xtd::int64 values to calculate the average of.
      /// @return The average of the sequence of values.
      /// @exception xtd::invalid_operation_exception `source` contains no elements.
      static double average(const ienumerable<xtd::int64>& source);

      /// @brief Computes the average of a sequence of optional xtd::decimal values.
      /// @param source A sequence of optional xtd::decimal values to calculate the average of.
      /// @return The average of the sequence of values, or xtd::nullopt if the source sequence is empty or contains only values that are xtd::nullopt.
      static xtd::optional<xtd::decimal> average(const ienumerable<xtd::optional<xtd::decimal>>& source) noexcept;
      /// @brief Computes the average of a sequence of optional double values.
      /// @param source A sequence of optional double values to calculate the average of.
      /// @return The average of the sequence of values, or xtd::nullopt if the source sequence is empty or contains only values that are xtd::nullopt.
      static xtd::optional<double> average(const ienumerable<xtd::optional<double>>& source) noexcept;
      /// @brief Computes the average of a sequence of optional float values.
      /// @param source A sequence of optional float values to calculate the average of.
      /// @return The average of the sequence of values, or xtd::nullopt if the source sequence is empty or contains only values that are xtd::nullopt.
      static xtd::optional<float> average(const ienumerable<xtd::optional<float>>& source) noexcept;
      /// @brief Computes the average of a sequence of optional xtd::int32 values.
      /// @param source A sequence of optional xtd::int32 values to calculate the average of.
      /// @return The average of the sequence of values, or xtd::nullopt if the source sequence is empty or contains only values that are xtd::nullopt.
      static xtd::optional<double> average(const ienumerable<xtd::optional<xtd::int32>>& source) noexcept;
      /// @brief Computes the average of a sequence of optional xtd::int64 values.
      /// @param source A sequence of optional xtd::int64 values to calculate the average of.
      /// @return The average of the sequence of values, or xtd::nullopt if the source sequence is empty or contains only values that are xtd::nullopt.
      static xtd::optional<double> average(const ienumerable<xtd::optional<xtd::int64>>& source) noexcept;

      /// @brief Casts the elements of an xtd::collections::generic::ienumerable to the specified type.
      /// @tparam result_t The type of the resulting value.
      /// @tparam source_t The type of the elements of source.
      /// @param source The xtd::collections::generic::ienumerable that contains the elements to be cast to type `result_t`.
      /// @return An xtd::collections::generic::ienumerable <type_t> that contains each element of the source sequence cast to the specified type.
      /// @exception xtd::invalid_cast_exception An element in the sequence cannot be cast to type `result_t`.
      /// @remarks The xtd::as include file `#include <xtd/as>` is needeed to use this method.
      template<class result_t, class source_t>
      static const ienumerable<result_t>& cast(const ienumerable<source_t>& source) noexcept;
      
      /// @brief Splits the elements of a sequence into chunks of size at most size.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values to chunk.
      /// @param size The maximum size of each chunk.
      /// @return A sequence of chunks of size at most size.
      /// @zxception xtd::argument_out_of_range_exception `size` is equal to 0.
      template<class source_t>
      static const ienumerable<xtd::array<source_t>>& chunk(const ienumerable<source_t>& source, xtd::size size);

      /// @brief Concatenates two sequences.
      /// @tparam source_t The type of the elements of source.
      /// @param first The first sequence to concatenate.
      /// @param second The sequence to concatenate to the first sequence.
      /// @return An xtd::collections::generic::ienumerable <type_t> that contains the concatenated elements of the two input sequences.
      template<class source_t>
      static const ienumerable<source_t>& concat(const ienumerable<source_t>& first, const ienumerable<source_t>& second) noexcept {
        static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<source_t> {};
        result = __opaque_xtd_linq_enumerable_collection__<source_t> {};
        for (const auto& item : first)
          result.items.push_back(item);
        for (const auto& item : second)
          result.items.push_back(item);
        return static_cast<const ienumerable<source_t>&>(result);
      }
      
      /// @brief Determines whether a sequence contains a specified element by using the default equality comparer.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence in which to locate a value.
      /// @param value The value to locate in the sequence.
      /// @return `true` if the source sequence contains an element that has the specified value; otherwise, `false`.
      template<class source_t>
      static bool contains(const ienumerable<source_t>& source, const source_t& value) noexcept {
        for (const auto& item : source)
          if (item == value) return true;
        return false;
      }
      
      /// @brief Determines whether a sequence contains a specified element by using a specified equality comparer.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence in which to locate a value.
      /// @param value The value to locate in the sequence.
      /// @param comparer An equality comparer to compare values.
      /// @return `true` if the source sequence contains an element that has the specified value; otherwise, `false`.
      template<class source_t>
      static bool contains(const ienumerable<source_t>& source, const source_t& value, const xtd::collections::generic::iequality_comparer<source_t>& comparer) noexcept {
        for (const auto& item : source)
          if (comparer.equals(item, value)) return true;
        return false;
      }
      
      /// @brief Returns the number of elements in a sequence.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence that contains elements to be counted.
      /// @return The number of elements in the input sequence.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::count <source_t>(const ienumerable <source_t>&) to count the elements in a sequence.
      /// @include enumerable_count.cpp
      template<class source_t>
      static xtd::size count(const ienumerable<source_t>& source) noexcept {
        auto count = xtd::size {0};
        auto enumerator = source.get_enumerator();
        while (enumerator.move_next()) ++count;
        return count;
      }

      /// @brief Returns a number that represents how many elements in the specified sequence satisfy a condition.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence that contains elements to be tested and counted.
      /// @param predicate A function to test each element for a condition.
      /// @return A number that represents how many elements in the sequence satisfy the condition in the predicate function.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::count <source_t>(const ienumerable <source_t>&, const std::function <bool(const source_t&)>&) to count the elements in a sequence that satisfy a condition.
      /// @include enumerable_count2.cpp
      template<class source_t>
      static xtd::size count(const ienumerable<source_t>& source, const std::function<bool(const source_t&)>& predicate) noexcept {
        return where<source_t>(source,predicate).count();
      }

      /// @brief Returns the number of elements with the specified value.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence that contains elements to be tested and counted.
      /// @param value The value to search for.
      /// @return A number representing the number of elements in the sequence that are equal to the `value`.
      template<class source_t>
      static xtd::size count(const ienumerable<source_t>& source, const source_t& value) noexcept {
        return count<source_t>(source, [value](const source_t& item) -> bool {return item == value;});
      }

      /// @brief Returns the count of elements in the source sequence grouped by key.
      /// @tparam source_t The type of the elements of source.
      /// @tparam key_t The type of the key returned by `key_selector`.
      /// @param source A sequence that contains elements to be counted.
      /// @param key_selector A function to extract the key for each element.
      /// @return An enumerable containing the frequencies of each key occurrence in `source`.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::count_by <source_t>(const ienumerable <source_t>&, const std::function <key_t(const source_t&)>&) to count the number of elements in a sequence grouped by key.
      /// @include enumerable_count_by.cpp
      template<class key_t, class source_t>
      static const ienumerable<key_value_pair<key_t, xtd::size>>& count_by(const ienumerable<source_t>& source, const std::function<key_t(const source_t&)>& key_selector) noexcept {
        return count_by(source, key_selector, xtd::collections::generic::equality_comparer<key_t>::default_equality_comparer());
      }
      
      /// @brief Returns the count of elements in the source sequence grouped by key.
      /// @tparam source_t The type of the elements of source.
      /// @tparam key_t The type of the key returned by `key_selector`.
      /// @param source A sequence that contains elements to be counted.
      /// @param key_selector A function to extract the key for each element.
      /// @param key_comparer An equality comparer to compare keys.
      /// @return An enumerable containing the frequencies of each key occurrence in `source`.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::count_by <source_t>(const ienumerable <source_t>&, const std::function <key_t(const source_t&)>&) to count the number of elements in a sequence grouped by key.
      /// @include enumerable_count_by.cpp
      template<class key_t, class source_t>
      static const ienumerable<key_value_pair<key_t, xtd::size>>& count_by(const ienumerable<source_t>& source, const std::function<key_t(const source_t&)>& key_selector, const iequality_comparer<key_t>& key_comparer) noexcept {
        static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<key_value_pair<key_t, xtd::size>> {};
        result = __opaque_xtd_linq_enumerable_collection__<key_value_pair<key_t, xtd::size>> {};
        auto keys = list<key_t> {};
        auto enumerator = source.get_enumerator();
        while (enumerator.move_next()) {
          auto key = key_selector(enumerator.current());
          auto index = size_t {0};
          for (; index < keys.size(); ++index)
            if (key_comparer.equals(keys[index], key)) break;
          if (index < keys.size()) result.items[index] = {key, result.items[index].value() + 1};
          else {
            keys.push_back(key);
            result.items.push_back({key, 1});
          }
        }
        return static_cast<const ienumerable<key_value_pair<key_t, xtd::size>>&>(result);
      }
      
      /// @brief Returns the elements of the specified sequence or the type parameter's default value in a singleton collection if the sequence is empty.
      /// @tparam source_t The type of the elements of source.
      /// @param source The sequence to return a default value for if it is empty.
      /// @return An xtd::collections::generic::ienumerable <type_t> that contains default_value if source is empty; otherwise, source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::default_if_empty <source_t>(const ienumerable <source_t>&) to return a default value if a sequence is empty.
      /// @include enumerable_default_if_empty.cpp
      template<class source_t>
      static const ienumerable<source_t>& default_if_empty(const ienumerable<source_t>& source) noexcept {
        return default_if_empty(source, source_t {});
      }

      /// @brief Returns the elements of the specified sequence or the specified value in a singleton collection if the sequence is empty.
      /// @tparam source_t The type of the elements of source.
      /// @param source The sequence to return a default value for if it is empty.
      /// @param default_value The value to return if the sequence is empty.
      /// @return An xtd::collections::generic::ienumerable <type_t> that contains default_value if source is empty; otherwise, source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::default_if_empty <source_t>(const ienumerable <source_t>&, const source_t&) to return a default value if a sequence is empty.
      /// @include enumerable_default_if_empty2.cpp
      template<class source_t>
      static const ienumerable<source_t>& default_if_empty(const ienumerable<source_t>& source, const source_t& default_value) noexcept {
        static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<source_t> {};
        result = __opaque_xtd_linq_enumerable_collection__<source_t> {};
        if (!any(source)) result.items.push_back(default_value);
        else for (const auto& item : source)
          result.items.push_back(item);
        return result;
      }

      /// @brief Returns the first element of the sequence that satisfies a condition, or a specified default value if no such element is found.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values to return an element from.
      /// @param predicate A function to test each element for a condition.
      /// @param default_value The default value to return if the sequence is empty.
      /// @return `default_value` if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
      template<class source_t>
      static source_t first_or_default(const ienumerable<source_t>& source, const std::function<bool(const source_t&)>& predicate, const source_t& default_value) noexcept {
        const auto& result = where(source, predicate);
        return any(result) ? *result.begin() : default_value;
      }
      /// @brief Returns the first element of the sequence that satisfies a condition or a default value if no such element is found.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values to return an element from.
      /// @param predicate A function to test each element for a condition.
      /// @return default `source_t {}` if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
      template<class source_t>
      static source_t first_or_default(const ienumerable<source_t>& source, const std::function<bool(const source_t&)>& predicate) noexcept {
        return first_or_default(source, predicate, source_t {});
      }
      /// @brief Returns the first element of the sequence that satisfies a condition or a default value if no such element is found.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values to return an element from.
      /// @param default_value The default value to return if the sequence is empty.
      /// @return `default_value` if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
      template<class source_t>
      static source_t first_or_default(const ienumerable<source_t>& source, const source_t& default_value) noexcept {
        return any(source) ? *source.begin() : default_value;
      }
      /// @brief Returns the first element of the sequence that satisfies a condition or a default value if no such element is found.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values to return an element from.
      /// @return default `source_t {}` if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
      template<class source_t>
      static source_t first_or_default(const ienumerable<source_t>& source) noexcept {
        return first_or_default(source, source_t {});
      }

      /// @brief Generates a sequence of integral numbers within a specified range.
      /// @param count The number of sequential integers to generate.
      /// @return An xtd::collections::generic::ienumerable <xtd::int32> that contains a range of sequential integral numbers.
      /// @exception xtd::argument_out_of_range_exception `count` is less than 0.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::range to generate a sequence of values.
      /// @include enumerable_range.cpp
      template<class type_t>
      static const ienumerable<type_t>& range(type_t count) {
        auto step = type_t {};
        return range(type_t {}, count, ++step);
      }
      /// @brief Generates a sequence of integral numbers within a specified range.
      /// @param start The value of the first integer in the sequence.
      /// @param count The number of sequential integers to generate.
      /// @return An xtd::collections::generic::ienumerable <xtd::int32> that contains a range of sequential integral numbers.
      /// @exception xtd::argument_out_of_range_exception `count` is less than 0.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::range to generate a sequence of values.
      /// @include enumerable_range.cpp
      template<class type_t>
      static const ienumerable<type_t>& range(type_t start, type_t count) {
        auto step = type_t {};
        return range(start, count, ++step);
      }
      /// @brief Generates a sequence of integral numbers within a specified range and step.
      /// @param start The value of the first integer in the sequence.
      /// @param count The number of sequential integers to generate.
      /// @param step The integer number specifying the incrementation.
      /// @return An xtd::collections::generic::ienumerable that contains a range of sequential integral numbers.
      /// @exception xtd::argument_out_of_range_exception `count` is less than 0.
      template<class type_t>
      static const ienumerable<type_t>& range(type_t start, type_t count, type_t step) {
        if (step == type_t {}) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
        if (count < type_t {}) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
        static thread_local auto result = __opaque_xtd_linq_lazy_enumerable__<type_t, std::tuple<type_t, type_t, type_t, type_t>> {};
        result = __opaque_xtd_linq_lazy_enumerable__<type_t, std::tuple<type_t, type_t, type_t, type_t>> {
          std::make_tuple(start, count, step, type_t {}),
          [](std::tuple<type_t, type_t, type_t, type_t>& params) {
            auto& result = std::get<0>(params);
            auto& count = std::get<1>(params);
            auto& step = std::get<2>(params);
            auto& index = std::get<3>(params);
            if (index++ >= count) return false;
            if (index != 1) result += step;
            return true;
          }};
        return result;
      }

      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @remarks Same as as_enemerable(const ienumerable<source_t>& source).
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::from to create a sequence of values.
      /// @include linq_from.cpp
      template<class source_t>
      static const ienumerable<source_t>& from(const ienumerable<source_t>& source) noexcept {
        return as_enumerable(source);
      }
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @remarks Same as as_enemerable(std::initializer_list<source_t> source).
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::from to create a sequence of values.
      /// @include linq_from2.cpp
      template<class source_t>
      static const ienumerable<source_t>& from(std::initializer_list<source_t> source) noexcept {
        return as_enumerable(source);
      }
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam collection_t The type of the source.
      /// @param source A sequence of values.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @remarks Same as as_enemerable(const collection_t& source).
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::from to create a sequence of values.
      /// @include linq_from3.cpp
      template<class collection_t>
      static const auto& from(const collection_t& source) noexcept {
        return as_enumerable(source);
      }
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam input_iterator_t The type of the source iterators.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @par Example
      /// The following code example demonstrates how to use as_enumerable <source_t>(ienumerable <source_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
      /// @remarks Same as as_enemerable(input_iterator_t first, input_iterator_t last).
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::from to create a sequence of values.
      /// @include linq_from4.cpp
      template<class input_iterator_t>
      static const auto& from(input_iterator_t first, input_iterator_t last) noexcept {
        return as_enumerable(first, last);
      }
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam input_iterator_t The type of the source iterators.
      /// @param iterator The iterator.
      /// @param legnth The le,gth to iterate.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @remarks Same as as_enemerable(input_iterator_t iterator, size_t length).
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::from to create a sequence of values.
      /// @include linq_from5.cpp
      template<class input_iterator_t>
      static const auto& from(input_iterator_t iterator, size_t length) noexcept {
        return as_enumerable(iterator, iterator + length);
      }
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam source_t The type of the source array.
      /// @param array The native array.
      /// @param legnth The length of the array.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @remarks Same as as_enemerable(const source_t (&array)[length]).
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::from to create a sequence of values.
      /// @include linq_from6.cpp
      template<class source_t, size_t length>
      static const auto& from(const source_t (&array)[length]) noexcept {
        return as_enumerable(array, array + length);
      }

      /// @brief Projects each element of a sequence into a new form.
      /// @tparam result_t The type of the resulting value.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const ienumerable <source_t>&, const std::function <result_t(const source_t&)>&) to project over a sequence of values.
      /// @include enumerable_range.cpp
      template<class result_t, class source_t>
      static const ienumerable<result_t>& select(const ienumerable<source_t>& source, const std::function<result_t(const source_t&)>& selector) {
        static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<result_t> {};
        result = __opaque_xtd_linq_enumerable_collection__<result_t> {};
        for (const auto& item : source)
          result.items.push_back(selector(item));
        return result;
      }
      /// @brief Projects each element of a sequence into a new form.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const ienumerable <source_t>&, const std::function <result_t(const source_t&)>&) to project over a sequence of values.
      /// @include enumerable_range.cpp
      template<class source_t>
      static const ienumerable<source_t>& select(const ienumerable<source_t>& source, const std::function<source_t(const source_t&)>& selector) {
        static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<source_t> {};
        result = __opaque_xtd_linq_enumerable_collection__<source_t> {};
        for (const auto& item : source)
          result.items.push_back(selector(item));
        return result;
      }
      /// @brief Projects each element of a sequence into a new form by incorporating the element's index.
      /// @tparam result_t The type of the resulting value.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each source element; the second parameter of the function represents the index of the source element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const ienumerable <source_t>&, const std::function <result_t(const source_t&, xtd::size)>&) to project over a sequence of values and use the index of each element.
      /// @include enumerable_select.cpp
      template<class result_t, class source_t>
      static const ienumerable<result_t>& select(const ienumerable<source_t>& source, const std::function<result_t(const source_t&, xtd::size)>& selector) {
        static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<result_t> {};
        result = __opaque_xtd_linq_enumerable_collection__<result_t> {};
        auto index = xtd::size {0};
        for (const auto& item : source)
          result.items.push_back(selector(item, index++));
        return result;
      }
      /// @brief Projects each element of a sequence into a new form by incorporating the element's index.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each source element; the second parameter of the function represents the index of the source element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const ienumerable <source_t>&, const std::function <result_t(const source_t&, xtd::size)>&) to project over a sequence of values and use the index of each element.
      /// @include enumerable_select.cpp
      template<class source_t>
      static const ienumerable<source_t>& select(const ienumerable<source_t>& source, const std::function<source_t(const source_t&, xtd::size)>& selector) {
        static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<source_t> {};
        result = __opaque_xtd_linq_enumerable_collection__<source_t> {};
        auto index = xtd::size {0};
        for (const auto& item : source)
          result.items.push_back(selector(item, index++));
        return result;
      }

      /// @brief Creates a xtd::collections::generic::list <type_t> from an xtd::collections::generic::ienumerable <type_t>.
      /// @tparam source_t The type of the elements of source.
      /// @param source The xtd::collections::generic::ienumerable <type_t> to create a xtd::collections::generic::list <type_t> from.
      /// @return A xtd::collections::generic::list <type_t> that contains elements from the input sequence.
      /// @remarks The xtd::collections::generic::list include file `#include <xtd/collections/generic/lists>` is needeed to use this method.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::to_list to force immediate query evaluation and return a xtd::collections::generic::list <type_t> that contains the query results.
      /// @include enumerable_to_list.cpp
      template<class source_t>
      static const list<source_t>& to_list(const ienumerable<source_t>& source) noexcept;
      
      /// @brief Filters a sequence of values based on a predicate.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values to filter.
      /// @param predicate A function to test each element for a condition.
      /// @return An xtd::collections::generic::ienumerable <type_t> that contains elements from the input sequence that satisfy the condition.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::where <source_t>(const ienumerable <source_t>&, const std::function<bool (const source_t&)>&) to filter a sequence.
      /// @include enumerable_where.cpp
      template<class source_t>
      static const ienumerable<source_t>& where(const ienumerable<source_t>& source, const std::function<bool(const source_t&)>& predicate) {
        static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<source_t> {};
        result = __opaque_xtd_linq_enumerable_collection__<source_t> {};
        for (const auto& item : source)
          if (predicate(item)) result.items.push_back(item);
        return result;
      }
      /// @brief Filters a sequence of values based on a predicate. Each element's index is used in the logic of the predicate function.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values to filter.
      /// @param predicate A function to test each source element for a condition; the second parameter of the function represents the index of the source element.
      /// @return An xtd::collections::generic::ienumerable <type_t> that contains elements from the input sequence that satisfy the condition.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::where <source_t>(const ienumerable <source_t>&, const std::function<bool (const source_t&, xtd::size)>&) to filter a sequence based on a predicate that involves the index of each element.
      /// @include enumerable_where2.cpp
      template<class source_t>
      static const ienumerable<source_t>& where(const ienumerable<source_t>& source, const std::function<bool(const source_t&, xtd::size)>& predicate) {
        static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<source_t> {};
        result = __opaque_xtd_linq_enumerable_collection__<source_t> {};
        auto index = xtd::size {0};
        for (const auto& item : source)
          if (predicate(item, index++)) result.items.push_back(item);
        return result;
      }
      /// @}
      
    private:
      template<class source_t, class collection_t>
      static const list<source_t>& collection_to_list(const collection_t& source) noexcept;
      template<class source_t, class input_iterator_t>
      static const list<source_t>& input_iterator_to_list(input_iterator_t first, input_iterator_t last) noexcept;
    };
  }
}

#include "../collections/generic/extensions/enumerable.hpp"
#include "from.hpp"
