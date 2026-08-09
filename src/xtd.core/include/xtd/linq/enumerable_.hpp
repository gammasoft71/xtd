/// @file
/// @brief Contains xtd::linq::enumerable <type_t> class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../collections/generic/helpers/lesser.hpp"
#include "../collections/generic/helpers/raw_array.hpp"
#include "../collections/generic/comparer.hpp"
#include "../collections/generic/equality_comparer.hpp"
#include "../collections/generic/enumerator.hpp"
#define __XTD_STD_INTERNAL__
#include "../internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__
#define __XTD_CORE_INTERNAL__
#include "../internal/__array_definition.hpp"
#include "../internal/__key_value_pair_definition.hpp"
#include "../internal/__list_definition.hpp"
#undef  __XTD_CORE_INTERNAL__
#include "../callable.hpp"
#include "../decimal.hpp"
#include "../integer.hpp"
#include "../iterable.hpp"
#include "../iterable_value_type.hpp"
#include "../func_callable.hpp"
#include "../iequatable.hpp"
#include "../int32.hpp"
#include "../int64.hpp"
#include "../numeric.hpp"
#include "../optional.hpp"
#include "../predicate_callable.hpp"
#include "../static.hpp"
#include "../usize.hpp"
#include <algorithm>
#include <bitset>
#include <functional>
#include <queue>
#include <stack>

/// @cond
template<typename type_t>
struct __opaque_xtd_linq_enumerable_collection__;
template<typename type_t, typename param_t>
struct __opaque_xtd_linq_lazy_enumerable__;
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace collections::generic {
    template<typename type_t>
    class enumerable_generator;
    template<typename type_t>
    class ienumerable;
  }
  /// @endcond
  
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
      /// @brief Represents the enumerator value type.
      template<typename type_t>
      using enumerator = typename xtd::collections::generic::enumerator<type_t>;
      
      /// @brief Represents the ienumerable value type.
      template<typename type_t>
      using iequality_comparer = typename xtd::collections::generic::iequality_comparer<type_t>;
      
      /// @brief Represents the ienumerable value type.
      template<typename type_t>
      using ienumerable = typename xtd::collections::generic::ienumerable<type_t>;
      
      /// @brief Represents the list value type.
      template<typename type_t>
      using list = typename xtd::collections::generic::list<type_t>;
      
      /// @brief Represents the key value pair value type.
      template<typename key_t, typename value_t>
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
      template<xtd::iterable source_t, xtd::func_callable<xtd::iterable_value_type<source_t>, xtd::iterable_value_type<source_t>, xtd::iterable_value_type<source_t>> func_t>
      [[nodiscard]] static auto aggregate(source_t&& source, func_t&& func) -> xtd::iterable_value_type<source_t>;
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
      template<typename accumulate_t, xtd::iterable source_t, xtd::func_callable<accumulate_t, accumulate_t, xtd::iterable_value_type<source_t>> func_t>
      [[nodiscard]] static auto aggregate(source_t&& source, accumulate_t&& seed, func_t&& func) -> accumulate_t;
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
      template<typename result_t, typename accumulate_t, xtd::iterable source_t, xtd::func_callable<accumulate_t, accumulate_t, xtd::iterable_value_type<source_t>> func_t, xtd::func_callable<result_t, accumulate_t> result_selector_t>
      [[nodiscard]] static auto aggregate(source_t&& source, accumulate_t&& seed, func_t&& func, result_selector_t&& result_selector) -> result_t;
      
      /// @brief Determines whether all elements of a sequence satisfy a condition.
      /// @tparam source_t The type of the elements of source.
      /// @param source An xtd::collections::generic::ienumerable <type_t> that contains the elements to apply the predicate to.
      /// @param predicate A function to test each element for a condition.
      /// @return `true` if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, `false`.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is `true` if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all.cpp
      template<xtd::iterable source_t, xtd::predicate_callable<xtd::iterable_value_type<source_t>> predicate_t>
      [[nodiscard]] static auto all(source_t&& source, predicate_t&& predicate) -> bool;
      
      /// @brief Determines whether a sequence contains any elements.
      /// @tparam source_t The type of the elements of source.
      /// @param source The xtd::collections::generic::ienumerable <type_t> to check for emptiness.
      /// @param last The last iterator.
      /// @return `true` if the source sequence contains any elements; otherwise, `false`.
      /// @par Examples
      /// The following code example demonstrates how to use Any to determine whether a sequence contains any elements.
      /// @include enumerable_any.cpp
      template<xtd::iterable source_t>
      [[nodiscard]] static auto any(source_t&& source) noexcept -> bool;
      /// @brief Determines whether any element of a sequence satisfies a condition.
      /// @tparam source_t The type of the elements of source.
      /// @param source An xtd::collections::generic::ienumerable <type_t> that contains the elements to apply the predicate to.
      /// @param predicate A function to test each element for a condition.
      /// @return `true` if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, `false`.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is `true` if all the pet names start with "B" or if the pets array is empty.
      /// @include enumerable_all.cpp
      template<xtd::iterable source_t, xtd::predicate_callable<xtd::iterable_value_type<source_t>> predicate_t>
      [[nodiscard]] static auto any(source_t&& source, predicate_t&& predicate) -> bool;

      /// @brief Appends a value to the end of the sequence.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values.
      /// @param element The value to append to source.
      /// @return A new sequence that ends with element.
      /// @par Examples
      /// The following code example demonstrates how to use Append to append a value to the end of the sequence.
      /// @include enumerable_append.cpp
      template<xtd::iterable source_t>
      [[nodiscard]] static auto append(source_t&& source, xtd::iterable_value_type<source_t>&& element) noexcept -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>;
      
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @par Examples
      /// The following code example demonstrates how to use as_enumerable <source_t>(ienumerable <source_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
      /// @include enumerable_as_enumerable.cpp
      /// @note Need to include list file `#include <xtd/collections/generic/list>`.
      template<xtd::iterable source_t>
      [[nodiscard]] static auto as_enumerable(source_t&& source) noexcept;  // Defined in include/xtd/collections/generic/list.hpp
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @par Examples
      /// The following code example demonstrates how to use as_enumerable <source_t>(ienumerable <source_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
      /// @include enumerable_as_enumerable.cpp
      template<xtd::iterable source_t>
      [[nodiscard]] static auto as_enumerable(const source_t& source) noexcept -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>;
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @par Examples
      /// The following code example demonstrates how to use as_enumerable <source_t>(ienumerable <source_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
      /// @include enumerable_as_enumerable.cpp
      template<xtd::iterable source_t>
      [[nodiscard]] static auto as_enumerable(source_t& source) noexcept -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>;
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @par Examples
      /// The following code example demonstrates how to use as_enumerable <source_t>(ienumerable <source_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
      /// @include enumerable_as_enumerable.cpp
      template<typename value_t>
      [[nodiscard]] static auto as_enumerable(std::initializer_list<value_t> source) noexcept -> xtd::collections::generic::enumerable_generator<value_t>;
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam input_iterator_t The type of the source iterators.
      /// @param first The first iterator.
      /// @param last The last iterator.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @par Examples
      /// The following code example demonstrates how to use as_enumerable <source_t>(ienumerable <source_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
      /// @include enumerable_as_enumerable2.cpp
      template<std::forward_iterator iterator_t>
      [[nodiscard]] static auto as_enumerable(iterator_t first, iterator_t last) noexcept -> xtd::collections::generic::enumerable_generator<typename std::decay<decltype(*first)>::type>;
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam input_iterator_t The type of the source iterators.
      /// @param iterator The iterator.
      /// @param legnth The le,gth to iterate.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @par Examples
      /// The following code example demonstrates how to use as_enumerable <source_t>(ienumerable <source_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
      /// @include enumerable_as_enumerable2.cpp
      template<std::forward_iterator iterator_t>
      [[nodiscard]] static auto as_enumerable(iterator_t iterator, xtd::usize length) noexcept -> xtd::collections::generic::enumerable_generator<typename std::decay<decltype(*iterator)>::type>;
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam source_t The type of the source array.
      /// @param array The native array.
      /// @param legnth The length of the array.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @par Examples
      /// The following code example demonstrates how to use as_enumerable <source_t>(ienumerable <source_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
      /// @include enumerable_as_enumerable.cpp
      template<typename value_t, xtd::usize length>
      [[nodiscard]] static auto as_enumerable(const value_t (&array)[length]) noexcept -> xtd::collections::generic::enumerable_generator<value_t>;
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam source_t The type of the source array.
      /// @param array The native array.
      /// @param legnth The length of the array.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @par Examples
      /// The following code example demonstrates how to use as_enumerable <source_t>(ienumerable <source_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
      /// @include enumerable_as_enumerable.cpp
      template<typename value_t, xtd::usize length>
      [[nodiscard]] static auto as_enumerable(value_t (&array)[length]) noexcept -> xtd::collections::generic::enumerable_generator<value_t>;

      /// @cond
      template<xtd::usize size_>
      [[nodiscard]] static auto as_enumerable(const std::bitset<size_>& source) noexcept -> xtd::collections::generic::enumerable_generator<bool>; // defined in xtd/collections/bit_array.hpp
      template<xtd::usize size_>
      [[nodiscard]] static auto as_enumerable(std::bitset<size_>& source) noexcept -> xtd::collections::generic::enumerable_generator<bool>; // defined in xtd/collections/bit_array.hpp
      template<typename value_t, typename container_t>
      [[nodiscard]] static auto as_enumerable(const std::queue<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t>;
      template<typename value_t, typename container_t>
      [[nodiscard]] static auto as_enumerable(std::queue<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t>;
      template<typename value_t, typename container_t>
      [[nodiscard]] static auto as_enumerable(const std::priority_queue<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t>;
      template<typename value_t, typename container_t>
      [[nodiscard]] static auto as_enumerable(std::priority_queue<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t>;
      template<typename value_t, typename container_t>
      [[nodiscard]] static auto as_enumerable(const std::stack<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t>;
      template<typename value_t, typename container_t>
      [[nodiscard]] static auto as_enumerable(std::stack<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t>;
      /// @endcond
      
      /// @brief Computes the average of a sequence of xtd::decimal values.
      /// @param source A sequence of xtd::decimal values to calculate the average of.
      /// @return The average of the sequence of values.
      /// @exception xtd::invalid_operation_exception `source` contains no elements.
      template<xtd::iterable source_t>
      requires xtd::real_decimal<xtd::iterable_value_type<source_t>>
      [[nodiscard]] static auto average(source_t&& source) -> xtd::decimal;
      /// @brief Computes the average of a sequence of double values.
      /// @param source A sequence of double values to calculate the average of.
      /// @return The average of the sequence of values.
      /// @exception xtd::invalid_operation_exception `source` contains no elements.
      template<xtd::iterable source_t>
      requires xtd::real_double<xtd::iterable_value_type<source_t>>
      [[nodiscard]] static auto average(source_t&& source) -> double;
      /// @brief Computes the average of a sequence of float values.
      /// @param source A sequence of float values to calculate the average of.
      /// @return The average of the sequence of values.
      /// @exception xtd::invalid_operation_exception `source` contains no elements.
      template<xtd::iterable source_t>
      requires xtd::real_single<xtd::iterable_value_type<source_t>>
      [[nodiscard]] static auto average(source_t&& source) -> xtd::single;
      /// @brief Computes the average of a sequence of xtd::int32 values.
      /// @param source A sequence of xtd::int32 values to calculate the average of.
      /// @return The average of the sequence of values.
      /// @exception xtd::invalid_operation_exception `source` contains no elements.
      template<xtd::iterable source_t>
      requires xtd::signed_integer_32<xtd::iterable_value_type<source_t>>
      [[nodiscard]] static auto average(source_t&& source) -> double;
      /// @brief Computes the average of a sequence of xtd::int64 values.
      /// @param source A sequence of xtd::int64 values to calculate the average of.
      /// @return The average of the sequence of values.
      /// @exception xtd::invalid_operation_exception `source` contains no elements.
      template<xtd::iterable source_t>
      requires xtd::signed_integer_64<xtd::iterable_value_type<source_t>>
      [[nodiscard]] static auto average(source_t&& source) -> double;

      /// @brief Computes the average of a sequence of optional xtd::decimal values.
      /// @param source A sequence of optional xtd::decimal values to calculate the average of.
      /// @return The average of the sequence of values, or xtd::nullopt if the source sequence is empty or contains only values that are xtd::nullopt.
      template<xtd::iterable source_t>
      requires std::same_as<xtd::iterable_value_type<source_t>, xtd::optional<xtd::decimal>>
      [[nodiscard]] static auto average(source_t&& source) -> xtd::optional<xtd::decimal>;
      /// @brief Computes the average of a sequence of optional double values.
      /// @param source A sequence of optional double values to calculate the average of.
      /// @return The average of the sequence of values, or xtd::nullopt if the source sequence is empty or contains only values that are xtd::nullopt.
      template<xtd::iterable source_t>
      requires std::same_as<xtd::iterable_value_type<source_t>, xtd::optional<double>>
      [[nodiscard]] static auto average(source_t&& source) -> xtd::optional<double>;
      /// @brief Computes the average of a sequence of optional float values.
      /// @param source A sequence of optional float values to calculate the average of.
      /// @return The average of the sequence of values, or xtd::nullopt if the source sequence is empty or contains only values that are xtd::nullopt.
      template<xtd::iterable source_t>
      requires std::same_as<xtd::iterable_value_type<source_t>, xtd::optional<xtd::single>>
      [[nodiscard]] static auto average(source_t&& source) -> xtd::optional<xtd::single>;
      /// @brief Computes the average of a sequence of optional xtd::int32 values.
      /// @param source A sequence of optional xtd::int32 values to calculate the average of.
      /// @return The average of the sequence of values, or xtd::nullopt if the source sequence is empty or contains only values that are xtd::nullopt.
      template<xtd::iterable source_t>
      requires std::same_as<xtd::iterable_value_type<source_t>, xtd::optional<xtd::int32>>
      [[nodiscard]] static auto average(source_t&& source) -> xtd::optional<double>;
      /// @brief Computes the average of a sequence of optional xtd::int64 values.
      /// @param source A sequence of optional xtd::int64 values to calculate the average of.
      /// @return The average of the sequence of values, or xtd::nullopt if the source sequence is empty or contains only values that are xtd::nullopt.
      template<xtd::iterable source_t>
      requires std::same_as<xtd::iterable_value_type<source_t>, xtd::optional<xtd::int64>>
      [[nodiscard]] static auto average(source_t&& source) -> xtd::optional<double>;

      /// @brief Casts the elements of an xtd::collections::generic::ienumerable to the specified type.
      /// @tparam result_t The type of the resulting value.
      /// @tparam source_t The type of the elements of source.
      /// @param source The xtd::collections::generic::ienumerable that contains the elements to be cast to type `result_t`.
      /// @return An xtd::collections::generic::ienumerable <type_t> that contains each element of the source sequence cast to the specified type.
      /// @exception xtd::invalid_cast_exception An element in the sequence cannot be cast to type `result_t`.
      /// @remarks The xtd::as include file `#include <xtd/as>` is needeed to use this method.
      template<typename result_t, xtd::iterable source_t>
      [[nodiscard]] static auto cast(source_t&& source) -> xtd::collections::generic::enumerable_generator<result_t>; // Defined include/xtd/as.hpp
      
      /// @brief Splits the elements of a sequence into chunks of size at most size.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values to chunk.
      /// @param size The maximum size of each chunk.
      /// @return A sequence of chunks of size at most size.
      /// @zxception xtd::argument_out_of_range_exception `size` is equal to 0.
      /// @note Need to include array file `#include <xtd/array>`.
      template<xtd::iterable source_t>
      [[nodiscard]] static auto chunk(source_t&& source, xtd::usize size) -> xtd::collections::generic::enumerable_generator<xtd::array<xtd::iterable_value_type<source_t>>>; // Defined in include/xtd/array.hpp
      
      /// @brief Concatenates two sequences.
      /// @tparam source_t The type of the elements of source.
      /// @param first The first sequence to concatenate.
      /// @param second The sequence to concatenate to the first sequence.
      /// @return An xtd::collections::generic::ienumerable <type_t> that contains the concatenated elements of the two input sequences.
      template<xtd::iterable first_t,xtd::iterable second_t>
      [[nodiscard]] static auto concat(first_t&& first, second_t&& second) noexcept -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<first_t>>;
      
      /// @brief Determines whether a sequence contains a specified element by using the default equality comparer.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence in which to locate a value.
      /// @param value The value to locate in the sequence.
      /// @return `true` if the source sequence contains an element that has the specified value; otherwise, `false`.
      template<xtd::iterable source_t>
      [[nodiscard]] static auto contains(source_t&& source, const xtd::iterable_value_type<source_t>& value) noexcept -> bool;
      /// @brief Determines whether a sequence contains a specified element by using a specified equality comparer.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence in which to locate a value.
      /// @param value The value to locate in the sequence.
      /// @param comparer An equality comparer to compare values.
      /// @return `true` if the source sequence contains an element that has the specified value; otherwise, `false`.
      template<xtd::iterable source_t>
      [[nodiscard]] static auto contains(source_t&& source, const xtd::iterable_value_type<source_t>& value, const iequality_comparer<xtd::iterable_value_type<source_t>>& comparer) noexcept -> bool;
      /// @brief Determines whether a sequence contains a specified element by using a specified equality comparer.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence in which to locate a value.
      /// @param value The value to locate in the sequence.
      /// @param equater An equality comparer to compare values.
      /// @return `true` if the source sequence contains an element that has the specified value; otherwise, `false`.
      template<xtd::iterable source_t, xtd::func_callable<bool, xtd::iterable_value_type<source_t>, xtd::iterable_value_type<source_t>> equater_t>
      [[nodiscard]] static auto contains(source_t&& source, const xtd::iterable_value_type<source_t>& value, equater_t&& equater) noexcept -> bool;

      /// @brief Returns the number of elements in a sequence.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence that contains elements to be counted.
      /// @return The number of elements in the input sequence.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::count <source_t>(const ienumerable <source_t>&) to count the elements in a sequence.
      /// @include enumerable_count.cpp
      template<xtd::iterable source_t>
      [[nodiscard]] static auto count(source_t&& source) noexcept -> xtd::usize;
      /// @brief Returns a number that represents how many elements in the specified sequence satisfy a condition.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence that contains elements to be tested and counted.
      /// @param predicate A function to test each element for a condition.
      /// @return A number that represents how many elements in the sequence satisfy the condition in the predicate function.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::count <source_t>(const ienumerable <source_t>&, const std::function <bool(const source_t&)>&) to count the elements in a sequence that satisfy a condition.
      /// @include enumerable_count2.cpp
      template<xtd::iterable source_t, xtd::predicate_callable<xtd::iterable_value_type<source_t>> predicate_t>
      [[nodiscard]] static auto count(source_t&& source, predicate_t&& predicate) noexcept -> xtd::usize;
      /// @brief Returns the number of elements with the specified value.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence that contains elements to be tested and counted.
      /// @param value The value to search for.
      /// @return A number representing the number of elements in the sequence that are equal to the `value`.
      template<xtd::iterable source_t>
      [[nodiscard]] static auto count(source_t&& source, xtd::iterable_value_type<source_t>&& value) noexcept -> xtd::usize;
      
      /// @brief Returns the count of elements in the source sequence grouped by key.
      /// @tparam source_t The type of the elements of source.
      /// @tparam key_t The type of the key returned by `key_selector`.
      /// @param source A sequence that contains elements to be counted.
      /// @param key_selector A function to extract the key for each element.
      /// @return An enumerable containing the frequencies of each key occurrence in `source`.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::count_by <source_t>(const ienumerable <source_t>&, const std::function <key_t(const source_t&)>&) to count the number of elements in a sequence grouped by key.
      /// @include enumerable_count_by.cpp
      template<typename key_t, xtd::iterable source_t, xtd::callable<key_t, xtd::iterable_value_type<source_t>> key_selector_t>
      [[nodiscard]] static auto count_by(source_t&& source, key_selector_t&& key_selector) noexcept -> xtd::collections::generic::enumerable_generator<xtd::collections::generic::key_value_pair<key_t, xtd::usize>>;
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
      template<typename key_t, xtd::iterable source_t, xtd::callable<key_t, xtd::iterable_value_type<source_t>> key_selector_t>
      [[nodiscard]] static auto count_by(source_t&& source, key_selector_t&& key_selector, const iequality_comparer<key_t>& key_comparer) noexcept -> xtd::collections::generic::enumerable_generator<xtd::collections::generic::key_value_pair<key_t, xtd::usize>>;
      /// @brief Returns the count of elements in the source sequence grouped by key.
      /// @tparam source_t The type of the elements of source.
      /// @tparam key_t The type of the key returned by `key_selector`.
      /// @param source A sequence that contains elements to be counted.
      /// @param key_selector A function to extract the key for each element.
      /// @param key_equater An equality comparer to compare keys.
      /// @return An enumerable containing the frequencies of each key occurrence in `source`.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::count_by <source_t>(const ienumerable <source_t>&, const std::function <key_t(const source_t&)>&) to count the number of elements in a sequence grouped by key.
      /// @include enumerable_count_by.cpp
      /// @note Need to include list file `#include <xtd/collections/generic/list>`.
      template<typename key_t, xtd::iterable source_t, xtd::callable<key_t, xtd::iterable_value_type<source_t>> key_selector_t, xtd::callable<bool, key_t, key_t> key_equater_t>
      [[nodiscard]] static auto count_by(source_t&& source, key_selector_t&& key_selector, key_equater_t&& key_equater) noexcept -> xtd::collections::generic::enumerable_generator<xtd::collections::generic::key_value_pair<key_t, xtd::usize>>; // Defined in include/xtd/collections/generic/list.hpp

      /// @brief Returns the elements of the specified sequence or the type parameter's default value in a singleton collection if the sequence is empty.
      /// @tparam source_t The type of the elements of source.
      /// @param source The sequence to return a default value for if it is empty.
      /// @return An xtd::collections::generic::ienumerable <type_t> that contains default_value if source is empty; otherwise, source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::default_if_empty <source_t>(const ienumerable <source_t>&) to return a default value if a sequence is empty.
      /// @include enumerable_default_if_empty.cpp
      template<xtd::iterable source_t>
      [[nodiscard]] static auto default_if_empty(source_t&& source) noexcept -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>;
      /// @brief Returns the elements of the specified sequence or the specified value in a singleton collection if the sequence is empty.
      /// @tparam source_t The type of the elements of source.
      /// @param source The sequence to return a default value for if it is empty.
      /// @param default_value The value to return if the sequence is empty.
      /// @return An xtd::collections::generic::ienumerable <type_t> that contains default_value if source is empty; otherwise, source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::default_if_empty <source_t>(const ienumerable <source_t>&, const source_t&) to return a default value if a sequence is empty.
      /// @include enumerable_default_if_empty2.cpp
      template<xtd::iterable source_t>
      [[nodiscard]] static auto default_if_empty(source_t&& source, const xtd::iterable_value_type<source_t>& default_value) noexcept -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>;
      
      /// @brief Returns distinct elements from a sequence by using the default equality comparer to compare values.
      /// @param source The sequence to remove duplicate elements from.
      /// @return An enumerable distinct elements from the source sequence.
      /// @note Need to include list file `#include <xtd/collections/generic/list>`.
      template<xtd::iterable source_t>
      [[nodiscard]] static auto distinct(source_t&& source) noexcept -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>; // Defined in include/xtd/collections/generic/list.hpp
      /// @brief Returns distinct elements from a sequence by using a specified xtd::collections::generic::iequality_comparer <type_t> to compare values.
      /// @param source The sequence to remove duplicate elements from.
      /// @param comparer An xtd::collections::generic::iequality_comparer <type_t> to compare values.
      /// @return An enumerable distinct elements from the source sequence.
      template<xtd::iterable source_t>
      [[nodiscard]] static auto distinct(source_t&& source, const iequality_comparer<source_t>& comparer) noexcept  -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>;
      /// @brief Returns distinct elements from a sequence by using a specified xtd::collections::generic::iequality_comparer <type_t> to compare values.
      /// @param source The sequence to remove duplicate elements from.
      /// @param equater An equality comparer to compare values.
      /// @return An enumerable distinct elements from the source sequence.
      /// @note Need to include list file `#include <xtd/collections/generic/list>`.
      template<xtd::iterable source_t, xtd::func_callable<bool, xtd::iterable_value_type<source_t>, xtd::iterable_value_type<source_t>> equater_t>
      [[nodiscard]] static auto distinct(source_t&& source, equater_t&& equater) noexcept  -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>; // Defined in include/xtd/collections/generic/list.hpp

      /// @brief Returns the first element of the sequence that satisfies a condition, or a specified default value if no such element is found.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values to return an element from.
      /// @param predicate A function to test each element for a condition.
      /// @param default_value The default value to return if the sequence is empty.
      /// @return `default_value` if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
      template<xtd::iterable source_t, xtd::predicate_callable<xtd::iterable_value_type<source_t>> prediacte_t>
      [[nodiscard]] static auto first_or_default(source_t&& source, prediacte_t&& predicate, xtd::iterable_value_type<source_t>&& default_value) noexcept -> xtd::iterable_value_type<source_t>;
      /// @brief Returns the first element of the sequence that satisfies a condition or a default value if no such element is found.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values to return an element from.
      /// @param predicate A function to test each element for a condition.
      /// @return default `source_t {}` if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
      template<xtd::iterable source_t, xtd::predicate_callable<xtd::iterable_value_type<source_t>> prediacte_t>
      [[nodiscard]] static auto first_or_default(source_t&& source, prediacte_t&& predicate) noexcept -> xtd::iterable_value_type<source_t>;
      /// @brief Returns the first element of the sequence that satisfies a condition or a default value if no such element is found.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values to return an element from.
      /// @param default_value The default value to return if the sequence is empty.
      /// @return `default_value` if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
      template<xtd::iterable source_t>
      [[nodiscard]] static auto first_or_default(source_t&& source, xtd::iterable_value_type<source_t>&& default_value) noexcept -> xtd::iterable_value_type<source_t>;
      /// @brief Returns the first element of the sequence that satisfies a condition or a default value if no such element is found.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values to return an element from.
      /// @return default `source_t {}` if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
      template<xtd::iterable source_t>
      [[nodiscard]] static auto first_or_default(source_t&& source) noexcept -> xtd::iterable_value_type<source_t>;
      
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @remarks Same as as_enemerable(const ienumerable<source_t>& source).
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::from to create a sequence of values.
      /// @include linq_from.cpp
      /// @note Need to include list file `#include <xtd/collections/generic/list>`.
      template<xtd::iterable source_t>
      [[nodiscard]] static auto from(source_t&& source) noexcept;  // Defined in include/xtd/collections/generic/list.hpp
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @remarks Same as as_enemerable(const ienumerable<source_t>& source).
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::from to create a sequence of values.
      /// @include linq_from.cpp
      template<xtd::iterable source_t>
      [[nodiscard]] static auto from(const source_t& source) noexcept -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>;
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @remarks Same as as_enemerable(const ienumerable<source_t>& source).
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::from to create a sequence of values.
      /// @include linq_from3.cpp
      template<xtd::iterable source_t>
      [[nodiscard]] static auto from(source_t& source) noexcept -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>;
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @remarks Same as as_enemerable(std::initializer_list<source_t> source).
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::from to create a sequence of values.
      /// @include linq_from2.cpp
      template<typename value_t>
      [[nodiscard]] static auto from(std::initializer_list<value_t> source) noexcept -> xtd::collections::generic::enumerable_generator<value_t>;
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
      template<std::forward_iterator iterator_t>
      [[nodiscard]] static auto from(iterator_t first, iterator_t last) noexcept -> xtd::collections::generic::enumerable_generator<typename std::decay<decltype(*first)>::type>;
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam input_iterator_t The type of the source iterators.
      /// @param iterator The iterator.
      /// @param legnth The le,gth to iterate.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @remarks Same as as_enemerable(input_iterator_t iterator, xtd::usize length).
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::from to create a sequence of values.
      /// @include linq_from5.cpp
      template<std::forward_iterator iterator_t>
      [[nodiscard]] static auto from(iterator_t iterator, xtd::usize length) noexcept -> xtd::collections::generic::enumerable_generator<typename std::decay<decltype(*iterator)>::type>;
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam source_t The type of the source array.
      /// @param array The native array.
      /// @param legnth The length of the array.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @remarks Same as as_enemerable(const source_t (&array)[length]).
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::from to create a sequence of values.
      /// @include linq_from6.cpp
      template<typename value_t, xtd::usize length>
      [[nodiscard]] static auto from(const value_t (&array)[length]) noexcept -> xtd::collections::generic::enumerable_generator<value_t>;
      /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
      /// @tparam source_t The type of the source array.
      /// @param array The native array.
      /// @param legnth The length of the array.
      /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
      /// @remarks Same as as_enemerable(const source_t (&array)[length]).
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::from to create a sequence of values.
      /// @include linq_from6.cpp
      template<typename value_t, xtd::usize length>
      [[nodiscard]] static auto from(value_t (&array)[length]) noexcept -> xtd::collections::generic::enumerable_generator<value_t>;
      
      /// @cond
      template<xtd::usize size_>
      [[nodiscard]] static auto from(const std::bitset<size_>& source) noexcept -> xtd::collections::generic::enumerable_generator<bool>; // defined in xtd/collections/bit_array.hpp
      template<xtd::usize size_>
      [[nodiscard]] static auto from(std::bitset<size_>& source) noexcept -> xtd::collections::generic::enumerable_generator<bool>; // defined in xtd/collections/bit_array.hpp
      template<typename value_t, typename container_t>
      [[nodiscard]] static auto from(const std::queue<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t>;
      template<typename value_t, typename container_t>
      [[nodiscard]] static auto from(std::queue<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t>;
      template<typename value_t, typename container_t>
      [[nodiscard]] static auto from(const std::priority_queue<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t>;
      template<typename value_t, typename container_t>
      [[nodiscard]] static auto from(std::priority_queue<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t>;
      template<typename value_t, typename container_t>
      [[nodiscard]] static auto from(const std::stack<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t>;
      template<typename value_t, typename container_t>
      [[nodiscard]] static auto from(std::stack<value_t, container_t>& source) noexcept -> xtd::collections::generic::enumerable_generator<value_t>;
      /// @endcond

      /// @brief Returns the maximum value in a sequence of xtd::numeric values.
      /// @param sources A sequence of xtd::numeric values to determine the maximum value of.
      /// @return A value of xtd::numeric that corresponds to the maximum value in the sequence.
      template<xtd::iterable source_t>
      requires xtd::numeric<xtd::iterable_value_type<source_t>>
      [[nodiscard]] static auto max(source_t&& source) -> xtd::iterable_value_type<source_t>;
      /// @brief Returns the maximum value in a sequence of xtd::numeric values.
      /// @param sources A sequence of xtd::numeric values to determine the maximum value of.
      /// @param selector A transform function to apply to each element.
      /// @return A value of xtd::numeric that corresponds to the maximum value in the sequence.
      template<xtd::iterable source_t, xtd::callable<xtd::iterable_value_type<source_t>, xtd::iterable_value_type<source_t>> selector_t>
      requires xtd::numeric<xtd::iterable_value_type<source_t>>
      [[nodiscard]] static auto max(source_t&& source, selector_t&& selector) -> xtd::iterable_value_type<source_t>;
      /// @brief Returns the maximum value in a sequence of xtd::numeric values.
      /// @param sources A sequence of xtd::numeric values to determine the maximum value of.
      /// @param selector A transform function to apply to each element.
      /// @return A value of xtd::numeric that corresponds to the maximum value in the sequence.
      template<typename result_t, xtd::iterable source_t, xtd::callable<result_t, xtd::iterable_value_type<source_t>> selector_t>
      requires xtd::numeric<xtd::iterable_value_type<source_t>>
      [[nodiscard]] static auto max(source_t&& source, selector_t&& selector) -> result_t;
      
      /// @brief Returns the minimum value in a sequence of xtd::numeric values.
      /// @param sources A sequence of xtd::numeric values to determine the minimum value of.
      /// @return A value of xtd::numeric that corresponds to the minimum value in the sequence.
      template<xtd::iterable source_t>
      requires xtd::numeric<xtd::iterable_value_type<source_t>>
      [[nodiscard]] static auto min(source_t&& source) -> xtd::iterable_value_type<source_t>;
      /// @brief Returns the minimum value in a sequence of xtd::numeric values.
      /// @param sources A sequence of xtd::numeric values to determine the minimum value of.
      /// @param selector A transform function to apply to each element.
      /// @return A value of xtd::numeric that corresponds to the minimum value in the sequence.
      template<xtd::iterable source_t, xtd::callable<xtd::iterable_value_type<source_t>, xtd::iterable_value_type<source_t>> selector_t>
      requires xtd::numeric<xtd::iterable_value_type<source_t>>
      [[nodiscard]] static auto min(source_t&& source, selector_t&& selector) -> xtd::iterable_value_type<source_t>;
      /// @brief Returns the minimum value in a sequence of xtd::numeric values.
      /// @param sources A sequence of xtd::numeric values to determine the minimum value of.
      /// @param selector A transform function to apply to each element.
      /// @return A value of xtd::numeric that corresponds to the minimum value in the sequence.
      template<typename result_t, xtd::iterable source_t, xtd::callable<result_t, xtd::iterable_value_type<source_t>> selector_t>
      requires xtd::numeric<xtd::iterable_value_type<source_t>>
      [[nodiscard]] static auto min(source_t&& source, selector_t&& selector) -> result_t;

      /// @brief Sorts the elements of a sequence in ascending order.
      /// @param source A sequence of values to order.
      /// @return An xtd::collections::generic::ienumerable <source_t> whose elements are sorted.
      template<xtd::iterable source_t>
      [[nodiscard]] static auto order(source_t&& source) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>;
      /// @brief Sorts the elements of a sequence in ascending order.
      /// @param source A sequence of values to order.
      /// @param comparer An xtd::collections::generic::icomparer <source_t> to compare keys.
      /// @return An xtd::collections::generic::ienumerable <source_t> whose elements are sorted.
      template<xtd::iterable source_t>
      [[nodiscard]] static auto order(source_t&& source, const xtd::collections::generic::icomparer<xtd::iterable_value_type<source_t>>& comparer) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>;
      /// @brief Sorts the elements of a sequence in ascending order.
      /// @param source A sequence of values to order.
      /// @param lesser An xtd::collections::generic::icomparer <source_t> to compare keys.
      /// @return An xtd::collections::generic::ienumerable <source_t> whose elements are sorted.
      /// @note Need to include list file `#include <xtd/collections/generic/list>`.
      template<xtd::iterable source_t, xtd::func_callable<bool, xtd::iterable_value_type<source_t>, xtd::iterable_value_type<source_t>> lesser_t>
      [[nodiscard]] static auto order(source_t&& source, lesser_t&& lesser) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>; // Defined in include/xtd/collections/generic/list.hpp

      /// @brief Sorts the elements of a sequence in ascending order according to a key.
      /// @param source A sequence of values to order.
      /// @param key_selector A function to extract a key from an element.
      /// @par Examples
      /// The following code example demonstrates how to use order_by<key_t, source_t>(ienumerable <source_t>, std::function<key_t(const source_t&)>) to sort the elements of a sequence.
      /// @include linq_order_by.cpp
      /// @note Need to include list file `#include <xtd/collections/generic/list>`.
      template<typename key_t, xtd::iterable source_t, xtd::callable<key_t, xtd::iterable_value_type<source_t>> key_selector_t>
      [[nodiscard]] static auto order_by(source_t&& source, key_selector_t&& key_selector) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>; // Defined in include/xtd/collections/generic/list.hpp
      
      /// @brief Sorts the elements of a sequence in ascending order according to a key.
      /// @param source A sequence of values to order.
      /// @param key_selector A function to extract a key from an element.
      /// @par Examples
      /// The following code example demonstrates how to use order_by<source_t, source_t>(ienumerable <source_t>, std::function<source_t(const source_t&)>) to sort the elements of a sequence.
      /// @include linq_order_by.cpp
      /// @note Need to include list file `#include <xtd/collections/generic/list>`.
      template<xtd::iterable source_t, xtd::callable<xtd::iterable_value_type<source_t>, xtd::iterable_value_type<source_t>> key_selector_t>
      [[nodiscard]] static auto order_by(source_t&& source, key_selector_t&& key_selector) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>; // Defined in include/xtd/collections/generic/list.hpp
      
      /// @brief Sorts the elements of a sequence in descending order according to a key.
      /// @param source A sequence of values to order.
      /// @param key_selector A function to extract a key from an element.
      /// @par Examples
      /// The following code example demonstrates how to use order_by<key_t, source_t>(ienumerable <source_t>, std::function<key_t(const source_t&)>) to sort the elements of a sequence.
      /// @include linq_order_by_descending.cpp
      /// @note Need to include list file `#include <xtd/collections/generic/list>`.
      template<typename key_t, xtd::iterable source_t, xtd::callable<key_t, xtd::iterable_value_type<source_t>> key_selector_t>
      [[nodiscard]] static auto order_by_descending(source_t&& source, key_selector_t&& key_selector) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>; // Defined in include/xtd/collections/generic/list.hpp
      
      /// @brief Sorts the elements of a sequence in descending order according to a key.
      /// @param source A sequence of values to order.
      /// @param key_selector A function to extract a key from an element.
      /// @par Examples
      /// The following code example demonstrates how to use order_by<source_t, source_t>(ienumerable <source_t>, std::function<source_t(const source_t&)>) to sort the elements of a sequence.
      /// @include linq_order_by_descending.cpp
      /// @note Need to include list file `#include <xtd/collections/generic/list>`.
      template<xtd::iterable source_t, xtd::callable<xtd::iterable_value_type<source_t>, xtd::iterable_value_type<source_t>> key_selector_t>
      [[nodiscard]] static auto order_by_descending(source_t&& source, key_selector_t&& key_selector) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>; // Defined in include/xtd/collections/generic/list.hpp
      
      /// @brief Generates a sequence of integral numbers within a specified range.
      /// @param count The number of sequential integers to generate.
      /// @return An xtd::collections::generic::ienumerable <xtd::int32> that contains a range of sequential integral numbers.
      /// @exception xtd::argument_out_of_range_exception `count` is less than 0.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::range to generate a sequence of values.
      /// @include enumerable_range.cpp
      template<xtd::integer integer_t>
      [[nodiscard]] static auto range(integer_t count) -> xtd::collections::generic::enumerable_generator<integer_t>;
      /// @brief Generates a sequence of integral numbers within a specified range.
      /// @param start The value of the first integer in the sequence.
      /// @param count The number of sequential integers to generate.
      /// @return An xtd::collections::generic::ienumerable <xtd::int32> that contains a range of sequential integral numbers.
      /// @exception xtd::argument_out_of_range_exception `count` is less than 0.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::range to generate a sequence of values.
      /// @include enumerable_range.cpp
      template<xtd::integer integer_t>
      [[nodiscard]] static auto range(integer_t start, integer_t count) -> xtd::collections::generic::enumerable_generator<integer_t>;
      /// @brief Generates a sequence of integral numbers within a specified range and step.
      /// @param start The value of the first integer in the sequence.
      /// @param count The number of sequential integers to generate.
      /// @param step The integer number specifying the incrementation.
      /// @return An xtd::collections::generic::ienumerable that contains a range of sequential integral numbers.
      /// @exception xtd::argument_out_of_range_exception `count` is less than 0.
      template<xtd::integer integer_t>
      [[nodiscard]] static auto range(integer_t start, integer_t count, integer_t step) -> xtd::collections::generic::enumerable_generator<integer_t>;
      
      /// @brief Projects each element of a sequence into a new form.
      /// @tparam result_t The type of the resulting value.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const ienumerable <source_t>&, const std::function <result_t(const source_t&)>&) to project over a sequence of values.
      /// @include enumerable_select.cpp
      template<typename result_t, xtd::iterable source_t>
      [[nodiscard]] static auto select(source_t&& source, auto&& selector) -> xtd::collections::generic::enumerable_generator<result_t>;
      /// @brief Projects each element of a sequence into a new form by incorporating the element's index.
      /// @tparam result_t The type of the resulting value.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values to invoke a transform function on.
      /// @param selector A transform function to apply to each source element; the second parameter of the function represents the index of the source element.
      /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const ienumerable <source_t>&, const std::function <result_t(const source_t&, xtd::usize)>&) to project over a sequence of values and use the index of each element.
      /// @include enumerable_select.cpp
      template<xtd::iterable source_t>
      [[nodiscard]] static auto select(source_t&& source, auto&& selector) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>;
      
      /// @brief Shuffles the order of the elements of a sequence.
      /// @param source A sequence of values to shuffle.
      /// @return A sequence whose elements correspond to those of the input sequence in randomized order.
      /// @note Need to include random file `#include <xtd/random>`.
      template<xtd::forward_iterable source_t>
      [[nodiscard]] static auto shuffle(source_t&& source) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>; // Defined in include/xtd/random.hpp

      /// @brief Bypasses a specified number of elements in a sequence and then returns the remaining elements.
      /// @param source A sequznce of values to return elements from.
      /// @param count The number of elements to skip before returning the remaining elements.
      /// @return A sequence that contains the elements that occur after the specified index in the input sequence.
      template<xtd::iterable source_t>
      [[nodiscard]] static auto skip(source_t&& source, xtd::usize count) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>;
      
      /// @brief Bypasses elements in a sequence as long as a specified condition is true and then returns the remaining elements.
      /// @param source A sequence of values to return elements from.
      /// @param predicate A function to test each element for a condition.
      /// @return A sequence that contains the elements from the input sequence starting at the first element in the linear series that does not pass the test specified by predicate.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::skip_while to skip elements of an array as long as a condition is true.
      /// @include enumerable_skip_while.cpp
      template<xtd::iterable source_t>
      [[nodiscard]] static auto skip_while(source_t&& source, auto&& predicate) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>;

      /// @brief Returns a specified number of contiguous elements from the start of a sequence.
      /// @param source A sequence of values to return elements from.
      /// @param count The number of elements to return.
      /// @return A sequence that contains the specified number of elements from the start of the input sequence.
      template<xtd::iterable source_t>
      [[nodiscard]] static auto take(source_t&& source, xtd::usize count) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>;
      
      /// @brief Returns elements from a sequence as long as a specified condition is true, and then skips the remaining elements.
      /// @param source A sequence to return elements from.
      /// @param predicate A function to test each element for a condition.
      /// @return A sequence that contains the elements from the input sequence that occur before the element at which the test no longer passes.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::take_while to return elements from the start of a sequence as long as a condition is true.
      /// @include enumerable_take_while.cpp
      template<xtd::iterable source_t>
      [[nodiscard]] static auto take_while(source_t&& source, auto&& predicate) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>;

      /// @brief Creates a xtd::array <type_t> from an xtd::collections::generic::ienumerable <type_t>.
      /// @tparam source_t The type of the elements of source.
      /// @param source The xtd::collections::generic::ienumerable <type_t> to create a xtd::collections::generic::list <type_t> from.
      /// @return A xtd::array <type_t> that contains elements from the input sequence.
      /// @remarks The xtd::collections::generic::list include file `#include <xtd/array>` is needeed to use this method.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::to_array to force immediate query evaluation and return a xtd::array <type_t> that contains the query results.
      /// @include enumerable_to_array.cpp
      /// @note Need to include array file `#include <xtd/array>`.
      template<typename source_t>
      [[nodiscard]] static auto to_array(const ienumerable<source_t>& source); // Defined in include/xtd/array.hpp
      
      /// @brief Creates a xtd::collections::generic::list <type_t> from an xtd::collections::generic::ienumerable <type_t>.
      /// @tparam source_t The type of the elements of source.
      /// @param source The xtd::collections::generic::ienumerable <type_t> to create a xtd::collections::generic::list <type_t> from.
      /// @return A xtd::collections::generic::list <type_t> that contains elements from the input sequence.
      /// @remarks The xtd::collections::generic::list include file `#include <xtd/collections/generic/lists>` is needeed to use this method.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::to_list to force immediate query evaluation and return a xtd::collections::generic::list <type_t> that contains the query results.
      /// @include enumerable_to_list.cpp
      /// @note Need to include list file `#include <xtd/collections/generic/list>`.
      template<typename source_t>
      [[nodiscard]] static auto to_list(const ienumerable<source_t>& source); // Defined in include/xtd/collections/generic/list.hpp
      
      /// @brief Filters a sequence of values based on a predicate.
      /// @tparam source_t The type of the elements of source.
      /// @param source A sequence of values to filter.
      /// @param predicate A function to test each element for a condition.
      /// @return An xtd::collections::generic::ienumerable <type_t> that contains elements from the input sequence that satisfy the condition.
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::where <source_t>(const ienumerable <source_t>&, const std::function<bool (const source_t&)>&) to filter a sequence.
      /// @include enumerable_where.cpp
      /// @par Examples
      /// The following code example demonstrates how to use xtd::linq::enumerable::where <source_t>(const ienumerable <source_t>&, const std::function<bool (const source_t&, xtd::usize)>&) to filter a sequence based on a predicate that involves the index of each element.
      /// @include enumerable_where2.cpp
      template<xtd::iterable source_t>
      [[nodiscard]] static auto where(source_t&& source, auto&& predicate) -> xtd::collections::generic::enumerable_generator<xtd::iterable_value_type<source_t>>;
      /// @}
      
    private:      
      template<typename type_t>
      struct enumerable_holder {
        enumerable_holder(const type_t& value);
        //enumerable_holder(type_t& value);
        enumerable_holder(type_t&& value) requires std::movable<type_t>;
        
        auto get() const -> const xtd::raw_type<type_t>&;
        
      private:
        std::optional<type_t> value_;
        const xtd::raw_type<type_t>* ptr_;
      };

      template<typename...>
      static inline constexpr bool always_false_v = false;
      
      template<typename predicate_t, typename value_t>
      [[nodiscard]] static constexpr auto invoke_predicate_with_optional_index(predicate_t&& predicate, value_t&& value, xtd::usize index) -> bool;

      template<typename result_t, typename selector_t, typename value_t>
      [[nodiscard]] static auto invoke_selector_with_optional_index(selector_t&& selector, value_t&& value, xtd::usize index) -> result_t;
    };
  }
}
