/// @file
/// @brief Contains xtd::collections::generic::extensions::enumerable <type_t> class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../../../linq/enumerable_.hpp"
#include "../../../foreach.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief The xtd::collections::generic::extensions namespace contains collection and interface extensions.
      namespace extensions {
        /// @brief Provides a set of static methods for querying objects that implement ienumerable <type_t>.
        /// @par Definition
        /// ```cpp
        /// template<typename type_t>
        /// class enumerable : public xtd::static_object;
        /// ```
        /// @par Header
        /// ```cpp
        /// #include <xtd/linq/generic/extensions/enumerable>
        /// ```
        /// @par Namespace
        /// xtd::linq
        /// @par Library
        /// xtd.core
        /// @ingroup xtd_core extensions_generic_collections
        template<typename value_t, typename enumerable_t>
        class enumerable {
        public:
          /// @name Public Aliases
          
          /// @{
          /// @brief Represents the ienumerable enumerable type.
          using enumerable_type = enumerable_t;
          /// @brief Represents the ienumerable value type.
          using value_type = value_t;
          /// @brief Represents the ienumerable value type.
          template<typename type_t>
          using ienumerable = typename xtd::linq::enumerable::ienumerable<type_t>;
          
          /// @brief Represents the list value type.
          template<typename type_t>
          using list = typename xtd::linq::enumerable::list<type_t>;
          /// @}
          
          /// @name Public Static Methods
          
          /// @{
          /// @brief Applies an accumulator function over a sequence.
          /// @param func An accumulator function to be invoked on each element.
          /// @return The final accumulator value.
          /// @par Examples
          /// The following code example demonstrates how to reverse the order of words in a string by using enumerable::aggregate.
          /// @include enumerable_aggregate.cpp
          template<xtd::func_callable<value_t, value_t, value_t> func_t>
          [[nodiscard]] auto aggregate(func_t&& func) const -> value_t {
            return xtd::linq::enumerable::aggregate(self(), std::forward<func_t>(func));
          }
          /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value.
          /// @tparam accumulate_t The type of the accumulator value.
          /// @param seed The initial accumulator value.
          /// @param func An accumulator function to be invoked on each element.
          /// @return The final accumulator value.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
          /// @include enumerable_aggregate2.cpp
          template<typename accumulate_t, xtd::func_callable<accumulate_t, accumulate_t, value_t> func_t>
          [[nodiscard]] auto aggregate(accumulate_t&& seed, func_t&& func) const -> accumulate_t {
            return xtd::linq::enumerable::aggregate(self(), std::forward<accumulate_t>(seed), std::forward<func_t>(func));
          }
          /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
          /// @tparam result_t The type of the resulting value.
          /// @tparam accumulate_t The type of the accumulator value.
          /// @param seed The initial accumulator value.
          /// @param func An accumulator function to be invoked on each element.
          /// @param result_Selector A function to transform the final accumulator value into the result value.
          /// @return The transformed final accumulator value.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
          /// @include enumerable_aggregate3.cpp
          template<typename result_t, typename accumulate_t, xtd::func_callable<accumulate_t, accumulate_t, value_t> func_t, xtd::func_callable<result_t, value_t> result_selector_t>
          [[nodiscard]] auto aggregate(accumulate_t&& seed, func_t&& func, result_selector_t&& result_selector) const -> result_t {
            return xtd::linq::enumerable::aggregate(self(), std::forward<accumulate_t>(seed), std::forward<func_t>(func), std::forward<result_selector_t>(result_selector));
          }
          
          /// @brief Determines whether all elements of a sequence satisfy a condition.
          /// @param predicate A function to test each element for a condition.
          /// @return `true` if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, `false`.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::all <value_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is `true` if all the pet names start with "B" or if the pets array is empty.
          /// @include enumerable_all.cpp
          template<xtd::predicate_callable<value_t> predicate_t>
          [[nodiscard]] auto all(predicate_t&& predicate) const -> bool {
            return xtd::linq::enumerable::all(self(), std::forward<predicate_t>(predicate));
          }
          
          /// @brief Determines whether a sequence contains any elements.
          /// @return `true` if the source sequence contains any elements; otherwise, `false`.
          /// @par Examples
          /// The following code example demonstrates how to use Any to determine whether a sequence contains any elements.
          /// @include enumerable_any.cpp
          [[nodiscard]] auto any() const noexcept -> bool {
            return xtd::linq::enumerable::any(self());
          }
          /// @brief Determines whether any element of a sequence satisfies a condition.
          /// @param predicate A function to test each element for a condition.
          /// @return `true` if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, `false`.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::all <value_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is `true` if all the pet names start with "B" or if the pets array is empty.
          /// @include enumerable_any.cpp
          template<xtd::predicate_callable<value_t> predicate_t>
          [[nodiscard]] auto any(predicate_t&& predicate) const -> bool {
            return xtd::linq::enumerable::any(self(), std::forward<predicate_t>(predicate));
          }
          
          /// @brief Appends a value to the end of the sequence.
          /// @param element The value to append to source.
          /// @return A new sequence that ends with element.
          /// @par Examples
          /// The following code example demonstrates how to use Append to append a value to the end of the sequence.
          /// @include enumerable_append.cpp
          template<typename element_t>
          [[nodiscard]] auto append(element_t&& element) const noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
            return xtd::linq::enumerable::append(self(), std::forward<element_t>(element));
          }
          
          /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
          /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
          /// @par Example
          /// The following code example demonstrates how to use as_enumerable <value_t>(ienumerable <value_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
          /// @include enumerable_as_enumerable.cpp
          [[nodiscard]] auto as_enumerable() const noexcept {
            return xtd::linq::enumerable::as_enumerable(self());
          }
          
          /// @brief Computes the average of a sequence of value_t values.
          /// @return The average of this sequence of values.
          /// @exception xtd::invalid_operation_exception this sequence contains no elements.
          [[nodiscard]] auto average() const noexcept {
            return xtd::linq::enumerable::average(self());
          }
          
          /// @brief Casts the elements of an xtd::collections::generic::ienumerable to the specified type.
          /// @tparam result_t The type of the resulting value.
          /// @return An xtd::collections::generic::ienumerable <type_t> that contains each element of the source sequence cast to the specified type.
          /// @exception xtd::invalid_cast_exception An element in the sequence cannot be cast to type `result_t`.
          template<typename result_t>
          [[nodiscard]] auto cast() const noexcept -> xtd::collections::generic::enumerable_generator<result_t> {
            return xtd::linq::enumerable::cast<result_t>(self());
          }
          
          /// @brief Splits the elements of a sequence into chunks of size at most size.
          /// @param size The maximum size of each chunk.
          /// @return A sequence of chunks of size at most size.
          [[nodiscard]] auto chunk(xtd::usize size) const -> xtd::collections::generic::enumerable_generator<xtd::array<value_t>> {
            return xtd::linq::enumerable::chunk(self(), size);
          }
          
          /// @brief Concatenates two sequences.
          /// @param second The sequence to concatenate to the current sequence.
          /// @return An xtd::collections::generic::ienumerable <type_t> that contains the concatenated elements of the two input sequences.
          template<xtd::iterable second_t>
          [[nodiscard]] auto concat(second_t&& second) const noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
            return xtd::linq::enumerable::concat(self(), std::forward<second_t>(second));
          }
          
          /// @brief Determines whether a sequence contains a specified element by using the default equality comparer.
          /// @param value The value to locate in the sequence.
          /// @return `true` if the source sequence contains an element that has the specified value; otherwise, `false`.
          [[nodiscard]] auto contains(value_t&& value) const noexcept -> bool {
            return xtd::linq::enumerable::contains(self(), std::forward<value_t>(value));
          }
          /// @brief Determines whether a sequence contains a specified element by using a specified equality comparer.
          /// @param value The value to locate in the sequence.
          /// @param comparer An equality comparer to compare values.
          /// @return `true` if the source sequence contains an element that has the specified value; otherwise, `false`.
          [[nodiscard]] auto contains(value_t&& value, xtd::collections::generic::iequality_comparer<value_t>&& comparer) const noexcept -> bool {
            return xtd::linq::enumerable::contains(self(), std::forward<value_t>(value), std::forward<xtd::collections::generic::iequality_comparer<value_t>>(comparer));
          }
          /// @brief Determines whether a sequence contains a specified element by using a specified equality comparer.
          /// @param value The value to locate in the sequence.
          /// @param comparer An equality comparer to compare values.
          /// @return `true` if the source sequence contains an element that has the specified value; otherwise, `false`.
          template<xtd::func_callable<bool, value_t, value_t> equater_t>
          [[nodiscard]] auto contains(value_t&& value, equater_t&& equater) const noexcept -> bool {
            return xtd::linq::enumerable::contains(self(), std::forward<value_t>(value), std::forward<equater_t>(equater));
          }

          /// @brief Returns the number of elements in current sequence.
          /// @return The number of elements in the input sequence.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::count <value_t>(const ienumerable <value_t>&) to count the elements in a sequence.
          /// @include enumerable_count.cpp
          [[nodiscard]] auto count() const noexcept -> xtd::usize {
            return xtd::linq::enumerable::count(self());
          }
          /// @brief Returns a number that represents how many elements in the specified sequence satisfy a condition.
          /// @param predicate A function to test each element for a condition.
          /// @return A number that represents how many elements in the sequence satisfy the condition in the predicate function.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::count <value_t>(const ienumerable <value_t>&, const std::function <bool(const value_t&)>&) to count the elements in a sequence that satisfy a condition.
          /// @include enumerable_count2.cpp
          template<xtd::predicate_callable<value_t> predicate_t>
          [[nodiscard]] auto count(predicate_t&& predicate) const noexcept -> xtd::usize {
            return xtd::linq::enumerable::count(self(), std::forward<predicate_t>(predicate));
          }
          /// @brief Returns the number of elements with the specified value.
          /// @param value The value to search for.
          /// @return A number representing the number of elements in the sequence that are equal to the `value`.
          [[nodiscard]] auto count(value_t&& value) const noexcept -> xtd::usize {
            return xtd::linq::enumerable::count(self(), std::forward<value_t>(value));
          }
          
          /// @brief Returns the count of elements in the current sequence grouped by key.
          /// @tparam key_t The type of the key returned by `key_selector`.
          /// @param key_selector A function to extract the key for each element.
          /// @return An enumerable containing the frequencies of each key occurrence in current sequence.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::count_by <value_t>(const ienumerable <value_t>&, const std::function <key_t(const value_t&)>&) to count the number of elements in a sequence grouped by key.
          /// @include enumerable_count_by.cpp
          template<typename key_t, xtd::callable<key_t, value_t> key_selector_t>
          [[nodiscard]] auto count_by(key_selector_t&& key_selector) const noexcept {
            return xtd::linq::enumerable::count_by<key_t>(self(), std::forward<key_selector_t>(key_selector));
          }
          /// @brief Returns the count of elements in the current sequence grouped by key.
          /// @tparam key_t The type of the key returned by `key_selector`.
          /// @param key_selector A function to extract the key for each element.
          /// @param key_comparer An equality comparer to compare keys.
          /// @return An enumerable containing the frequencies of each key occurrence in current sequence.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::count_by <value_t>(const ienumerable <value_t>&, const std::function <key_t(const value_t&)>&) to count the number of elements in a sequence grouped by key.
          /// @include enumerable_count_by.cpp
          template<typename key_t, xtd::callable<key_t, value_t> key_selector_t>
          [[nodiscard]] auto count_by(key_selector_t&& key_selector, xtd::collections::generic::iequality_comparer<key_t>&& key_comparer) const noexcept -> xtd::collections::generic::enumerable_generator<xtd::collections::generic::key_value_pair<key_t, xtd::usize>> {
            return xtd::linq::enumerable::count_by<key_t>(self(), std::forward<key_selector_t>(key_selector), std::forward<xtd::collections::generic::iequality_comparer<key_t>>(key_comparer));
          }
          /// @brief Returns the count of elements in the current sequence grouped by key.
          /// @tparam key_t The type of the key returned by `key_selector`.
          /// @param key_selector A function to extract the key for each element.
          /// @param key_comparer An equality comparer to compare keys.
          /// @return An enumerable containing the frequencies of each key occurrence in current sequence.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::count_by <value_t>(const ienumerable <value_t>&, const std::function <key_t(const value_t&)>&) to count the number of elements in a sequence grouped by key.
          /// @include enumerable_count_by.cpp
          template<typename key_t, xtd::callable<key_t, value_t> key_selector_t, xtd::callable<bool, key_t, key_t> key_equater_t>
          [[nodiscard]] auto count_by(key_selector_t&& key_selector, key_equater_t&& key_equater) const noexcept -> xtd::collections::generic::enumerable_generator<xtd::collections::generic::key_value_pair<key_t, xtd::usize>> {
            return xtd::linq::enumerable::count_by<key_t, value_t>(self(), std::forward<key_selector_t>(key_selector), std::forward<key_equater_t>(key_equater));
          }
          
          /// @brief Returns the elements of the specified sequence or the type parameter's default value in a singleton collection if the current sequence is empty.
          /// @return An xtd::collections::generic::ienumerable <type_t> that contains default_value if source is empty; otherwise, source.
          [[nodiscard]] auto default_if_empty() const noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
            return xtd::linq::enumerable::default_if_empty(self());
          }
          /// @brief Returns the elements of the specified sequence or the specified value in a singleton collection if the current sequence is empty.
          /// @param default_value The value to return if the sequence is empty.
          /// @return An xtd::collections::generic::ienumerable <type_t> that contains default_value if source is empty; otherwise, source.
          [[nodiscard]] auto default_if_empty(const value_t& default_value) const noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
            return xtd::linq::enumerable::default_if_empty(self(), default_value);
          }
          
          /// @brief Returns distinct elements from a sequence by using the default equality comparer to compare values.
          /// @return An enumerable distinct elements from the source sequence.
          [[nodiscard]] auto distinct() const noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
            return xtd::linq::enumerable::distinct(self());
          }
          /// @brief Returns distinct elements from a sequence by using a specified xtd::collections::generic::iequality_comparer <type_t> to compare values.
          /// @param comparer An xtd::collections::generic::iequality_comparer <type_t> to compare values.
          /// @return An enumerable distinct elements from the source sequence.
          [[nodiscard]] auto distinct(xtd::collections::generic::iequality_comparer<value_t>&& comparer) const noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
            return xtd::linq::enumerable::distinct(self(), std::forward<xtd::collections::generic::iequality_comparer<value_t>>(comparer));
          }
          /// @brief Returns distinct elements from a sequence by using a specified xtd::collections::generic::iequality_comparer <type_t> to compare values.
          /// @param equater An equality comparer to compare values.
          /// @return An enumerable distinct elements from the source sequence.
          template<xtd::func_callable<bool, value_t, value_t> equater_t>
          [[nodiscard]] auto distinct(equater_t&& equater) const noexcept -> xtd::collections::generic::enumerable_generator<value_t> {
            return xtd::linq::enumerable::distinct(self(), std::forward<equater_t>(equater));
          }

          /// @brief Returns the first element of the sequence that satisfies a condition, or a specified default value if no such element is found.
          /// @param predicate A function to test each element for a condition.
          /// @param default_value The default value to return if the sequence is empty.
          /// @return `default_value` if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
          template<xtd::predicate_callable<value_t> predicate_t>
          [[nodiscard]] auto first_or_default(predicate_t&& predicate, value_t&& default_value) const noexcept -> value_t {
            return xtd::linq::enumerable::first_or_default(self(), std::forward<predicate_t>(predicate), std::forward<value_t>(default_value));
          }
          /// @brief Returns the first element of the sequence that satisfies a condition or a default value if no such element is found.
          /// @param predicate A function to test each element for a condition.
          /// @return default `value_t {}` if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
          template<xtd::predicate_callable<value_t> predicate_t>
          [[nodiscard]] auto first_or_default(predicate_t&& predicate) const noexcept -> value_t {
            return xtd::linq::enumerable::first_or_default(self(), std::forward<predicate_t>(predicate));
          }
          /// @brief Returns the first element of the sequence that satisfies a condition or a default value if no such element is found.
          /// @param default_value The default value to return if the sequence is empty.
          /// @return `default_value`  if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
          [[nodiscard]] auto first_or_default(value_t&& default_value) const noexcept -> value_t {
            return xtd::linq::enumerable::first_or_default(self(), std::forward<value_t>(default_value));
          }
          /// @brief Returns the first element of the sequence that satisfies a condition or a default value if no such element is found.
          /// @return default `value_t {}` if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
          [[nodiscard]] auto first_or_default() const noexcept -> value_t {
            return xtd::linq::enumerable::first_or_default(self());
          }
          
          /// @brief Returns the maximum value in a sequence of xtd::numeric values.
          /// @return A value of xtd::numeric that corresponds to the maximum value in the sequence.
          [[nodiscard]] auto max() const -> value_t requires xtd::numeric<value_t> {
            return xtd::linq::enumerable::max(self());
          }
          /// @brief Returns the maximum value in a sequence of xtd::numeric values.
          /// @param selector A transform function to apply to each element.
          /// @return A value of xtd::numeric that corresponds to the maximum value in the sequence.
          template<xtd::callable<value_t, value_t> selector_t>
          [[nodiscard]] auto max(selector_t&& selector) const -> value_t requires xtd::numeric<value_t> {
            return xtd::linq::enumerable::max(self(), std::forward<selector_t>(selector));
          }
          /// @brief Returns the maximum value in a sequence of xtd::numeric values.
          /// @param selector A transform function to apply to each element.
          /// @return A value of xtd::numeric that corresponds to the maximum value in the sequence.
          template<typename result_t, xtd::callable<result_t, value_t> selector_t>
          requires xtd::numeric<result_t>
          [[nodiscard]] auto max(selector_t&& selector) const -> result_t {
            return xtd::linq::enumerable::max<result_t>(self(), std::forward<selector_t>(selector));
          }

          /// @brief Returns the minimum value in a sequence of xtd::numeric values.
          /// @return A value of xtd::numeric that corresponds to the minimum value in the sequence.
          [[nodiscard]] auto min() const -> value_t requires xtd::numeric<value_t> {
            return xtd::linq::enumerable::min(self());
          }
          /// @brief Returns the minimum value in a sequence of xtd::numeric values.
          /// @param selector A transform function to apply to each element.
          /// @return A value of xtd::numeric that corresponds to the minimum value in the sequence.
          template<xtd::callable<value_t, value_t> selector_t>
          [[nodiscard]] auto min(selector_t&& selector) const -> value_t requires xtd::numeric<value_t> {
            return xtd::linq::enumerable::min(self(), selector);
          }
          /// @brief Returns the minimum value in a sequence of xtd::numeric values.
          /// @param selector A transform function to apply to each element.
          /// @return A value of xtd::numeric that corresponds to the minimum value in the sequence.
          template<typename result_t, xtd::callable<result_t, value_t> selector_t>
          requires xtd::numeric<result_t>
          [[nodiscard]] auto min(selector_t&& selector) const -> result_t {
            return xtd::linq::enumerable::min<result_t, value_t>(self(), selector);
          }

          /// @brief Sorts the elements of a sequence in ascending order.
          /// @return An xtd::collections::generic::ienumerable <value_t> whose elements are sorted.
          [[nodiscard]] auto order() const -> xtd::collections::generic::enumerable_generator<value_t> {
            return xtd::linq::enumerable::order(self());
          }
          /// @brief Sorts the elements of a sequence in ascending order.
          /// @param comparer An xtd::collections::generic::icomparer <value_t> to compare keys.
          /// @return An xtd::collections::generic::ienumerable <value_t> whose elements are sorted.
          [[nodiscard]] auto order(const xtd::collections::generic::icomparer<value_t>& comparer) const -> xtd::collections::generic::enumerable_generator<value_t> {
            return xtd::linq::enumerable::order(self(), comparer);
          }
          /// @brief Sorts the elements of a sequence in ascending order.
          /// @param lesser An xtd::collections::generic::icomparer <value_t> to compare keys.
          /// @return An xtd::collections::generic::ienumerable <value_t> whose elements are sorted.
          template<xtd::func_callable<bool, value_t, value_t> lesser_t>
          [[nodiscard]] auto order(lesser_t&& lesser) const -> xtd::collections::generic::enumerable_generator<value_t> {
            return xtd::linq::enumerable::order(self(), lesser);
          }

          /// @brief Sorts the elements of a sequence in ascending order according to a key.
          /// @param key_selector A function to extract a key from an element.
          /// @par Examples
          /// The following code example demonstrates how to use order_by<key_t, value_t>(ienumerable <value_t>, std::function<key_t(const value_t&)>) to sort the elements of a sequence.
          /// @include linq_order_by.cpp
          [[nodiscard]] auto order_by(const std::function<value_t(const value_t&)>& key_selector) const {
            return xtd::linq::enumerable::order_by(self(), key_selector);
          }
          
          /// @brief Sorts the elements of a sequence in descending order according to a key.
          /// @param key_selector A function to extract a key from an element.
          /// @par Examples
          /// The following code example demonstrates how to use order_by<key_t, value_t>(ienumerable <value_t>, std::function<key_t(const value_t&)>) to sort the elements of a sequence.
          /// @include linq_order_by.cpp
          template<typename key_t>
          [[nodiscard]] auto order_by_descending(const std::function<key_t(const value_t&)>& key_selector) const {
            return xtd::linq::enumerable::order_by_descending<key_t, value_t>(self(), key_selector);
          }
          
          /// @brief Sorts the elements of a sequence in descending order according to a key.
          /// @param key_selector A function to extract a key from an element.
          /// @par Examples
          /// The following code example demonstrates how to use order_by<key_t, value_t>(ienumerable <value_t>, std::function<key_t(const value_t&)>) to sort the elements of a sequence.
          /// @include linq_order_by.cpp
          [[nodiscard]] auto order_by_descending(const std::function<value_t(const value_t&)>& key_selector) const {
            return xtd::linq::enumerable::order_by_descending(self(), key_selector);
          }
          
          /// @brief Sorts the elements of a sequence in ascending order according to a key.
          /// @param key_selector A function to extract a key from an element.
          /// @par Examples
          /// The following code example demonstrates how to use order_by<key_t, value_t>(ienumerable <value_t>, std::function<key_t(const value_t&)>) to sort the elements of a sequence.
          /// @include linq_order_by.cpp
          template<typename key_t>
          [[nodiscard]] auto order_by(const std::function<key_t(const value_t&)>& key_selector) const {
            return xtd::linq::enumerable::order_by<key_t, value_t>(self(), key_selector);
          }
          
          /// @brief Projects each element of a sequence into a new form.
          /// @param selector A transform function to apply to each element.
          /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::select <value_t, result_t>(const ienumerable <value_t>&, const std::function <result_t(const value_t&)>&) to project over a sequence of values.
          /// @include enumerable_select.cpp
          [[nodiscard]] auto select(auto&& selector) const {
            return xtd::linq::enumerable::select(self(), selector);
          }
          /// @brief Projects each element of a sequence into a new form by incorporating the element's index.
          /// @tparam result_t The type of the resulting value.
          /// @param selector A transform function to apply to each source element; the second parameter of the function represents the index of the source element.
          /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::select <value_t, result_t>(const ienumerable <value_t>&, const std::function <result_t(const value_t&, xtd::usize)>&) to project over a sequence of values and use the index of each element.
          /// @include enumerable_select.cpp
          template<typename result_t>
          [[nodiscard]] auto select(auto&& selector) const {
            return xtd::linq::enumerable::select<result_t>(self(), selector);
          }

          /// @brief Shuffles the order of the elements of a sequence.
          /// @return A sequence whose elements correspond to those of the input sequence in randomized order.
          /// @warning Need to include random file `#include <xtd/random>`.
          [[nodiscard]] auto shuffle() const -> xtd::collections::generic::enumerable_generator<value_t> {
            return xtd::linq::enumerable::shuffle(self());
          }

          /// @brief Bypasses a specified number of elements in a sequence and then returns the remaining elements.
          /// @param count The number of elements to skip before returning the remaining elements.
          /// @return A sequence that contains the elements that occur after the specified index in the input sequence.
          [[nodiscard]] auto skip(xtd::usize count) -> xtd::collections::generic::enumerable_generator<value_t> {
            return xtd::linq::enumerable::skip(self(), count);
          }
          
          /// @brief Bypasses elements in a sequence as long as a specified condition is true and then returns the remaining elements.
          /// @param predicate A function to test each element for a condition.
          /// @return A sequence that contains the elements from the input sequence starting at the first element in the linear series that does not pass the test specified by predicate.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::skip_while to skip elements of an array as long as a condition is true.
          /// @include enumerable_skip_while.cpp
          [[nodiscard]] auto skip_while(auto&& predicate) -> xtd::collections::generic::enumerable_generator<value_t> {
            return xtd::linq::enumerable::skip_while(self(), predicate);
          }
          
          /// @brief Returns a specified number of contiguous elements from the start of a sequence.
          /// @param source A sequence of values to return elements from.
          /// @param count The number of elements to return.
          /// @return A sequence that contains the specified number of elements from the start of the input sequence.
          [[nodiscard]] auto take(xtd::usize count) -> xtd::collections::generic::enumerable_generator<value_t> {
            return xtd::linq::enumerable::take(self(), count);
          }
          /// @brief Returns a specified number of contiguous elements from the start of a sequence.
          /// @param source A sequence of values to return elements from.
          /// @param range The range of elements to return.
          /// @return A sequence that contains the specified number of elements from the start of the input sequence.
          [[nodiscard]] auto take(const xtd::range& range) -> xtd::collections::generic::enumerable_generator<value_t> {
            return xtd::linq::enumerable::take(self(), range);
          }
          
          /// @brief Returns elements from a sequence as long as a specified condition is true, and then skips the remaining elements.
          /// @param predicate A function to test each element for a condition.
          /// @return A sequence that contains the elements from the input sequence that occur before the element at which the test no longer passes.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::take_while to return elements from the start of a sequence as long as a condition is true.
          /// @include enumerable_take_while.cpp
          [[nodiscard]] auto take_while(auto&& predicate) -> xtd::collections::generic::enumerable_generator<value_t> {
            return xtd::linq::enumerable::take_while(self(), predicate);
          }
          
          /// @brief Creates a xtd::array <type_t> from an xtd::collections::generic::ienumerable <type_t>.
          /// @return A xtd::array <type_t> that contains elements from the input sequence.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::to_array to force immediate query evaluation and return a xtd::array <type_t> that contains the query results.
          /// @include enumerable_to_array.cpp
          [[nodiscard]] auto to_array() const -> xtd::array<value_t>;
          
          /// @brief Creates a xtd::collections::generic::list <type_t> from an xtd::collections::generic::ienumerable <type_t>.
          /// @return A xtd::collections::generic::list <type_t> that contains elements from the input sequence.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::to_list to force immediate query evaluation and return a xtd::collections::generic::list <type_t> that contains the query results.
          /// @include enumerable_to_list.cpp
          [[nodiscard]] auto to_list() const -> xtd::collections::generic::list<value_t>;
          
          /// @brief Filters a sequence of values based on a predicate.
          /// @param predicate A function to test each element for a condition.
          /// @return An xtd::collections::generic::ienumerable <type_t> that contains elements from the input sequence that satisfy the condition.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::where <value_t>(const ienumerable <value_t>&, const std::function<bool (const value_t&)>&) to filter a sequence.
          /// @include enumerable_where.cpp
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::where <value_t>(const ienumerable <value_t>&, const std::function<bool (const value_t&, xtd::usize)>&) to filter a sequence based on a predicate that involves the index of each element.
          /// @include enumerable_where2.cpp
          auto where(auto&& predicate) const {
            return xtd::linq::enumerable::where(self(), predicate);
          }
          /// @}
          
        private:
          auto self() const noexcept -> const enumerable_t& {return static_cast<const enumerable_t&>(*this);}
        };
      }
    }
  }
}

#define __XTD_CORE_INTERNAL__
#include "../../../internal/__enumerable_collection.hpp"
#undef __XTD_CORE_INTERNAL__
#include "../ienumerable.hpp"
