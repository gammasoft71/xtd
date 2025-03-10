/// @file
/// @brief Contains xtd::collections::generic::extensions::enumerable <type_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../../../linq/enumerable.hpp"
#include "../../../linq/foreach.hpp"

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
        /// template<class type_t>
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
        template <class enumerable_t, class source_t>
        class enumerable {
        public:
          /// @name Public Aliases
          
          /// @{
          /// @brief Represents the ienumerable enumerable type.
          using enumerable_type = enumerable_t;
          /// @brief Represents the ienumerable source type.
          using source_type = source_t;
          /// @brief Represents the ienumerable value type.
          template <class type_t>
          using ienumerable = typename xtd::linq::enumerable::ienumerable<type_t>;

          /// @brief Represents the list value type.
          template <class type_t>
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
          source_t aggregate(const std::function<source_t(const source_t&, const source_t&)>& func) const {
            return xtd::linq::enumerable::aggregate(base(), func);
          }
          /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value.
          /// @param seed The initial accumulator value.
          /// @param func An accumulator function to be invoked on each element.
          /// @return The final accumulator value.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
          /// @include enumerable_aggregate2.cpp
          source_t aggregate(const source_t& seed, const std::function<source_t(const source_t&, const source_t&)>& func) const {
            return xtd::linq::enumerable::aggregate(base(), seed, func);
          }
          /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value.
          /// @tparam accumulate_t The type of the accumulator value.
          /// @param seed The initial accumulator value.
          /// @param func An accumulator function to be invoked on each element.
          /// @return The final accumulator value.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
          /// @include enumerable_aggregate2.cpp
          template<class accumulate_t>
          accumulate_t aggregate(const accumulate_t& seed, const std::function<accumulate_t(const source_t&, const accumulate_t&)>& func) const {
            return xtd::linq::enumerable::aggregate(base(), seed, func);
          }
          /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
          /// @param seed The initial accumulator value.
          /// @param func An accumulator function to be invoked on each element.
          /// @param result_Selector A function to transform the final accumulator value into the result value.
          /// @return The transformed final accumulator value.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
          /// @include enumerable_aggregate3.cpp
          source_t aggregate(const source_t& seed, const std::function<source_t(const source_t&, const source_t&)>& func, const std::function<source_t(const source_t&)>& result_selector) const {
            return xtd::linq::enumerable::aggregate(base(), seed, func, result_selector);
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
          template<class result_t, class accumulate_t>
          result_t aggregate(const accumulate_t& seed, const std::function<accumulate_t(const source_t&, const accumulate_t&)>& func, const std::function<result_t(const accumulate_t&)>& result_selector) const {
            return xtd::linq::enumerable::aggregate(base(), seed, func, result_selector);
          }

          /// @brief Determines whether all elements of a sequence satisfy a condition.
          /// @param predicate A function to test each element for a condition.
          /// @return `true` if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, `false`.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is `true` if all the pet names start with "B" or if the pets array is empty.
          /// @include enumerable_all.cpp
          bool all(const std::function<bool(const source_t&)>& predicate) const {
            return xtd::linq::enumerable::all(base(), predicate);
          }
          
          /// @brief Determines whether a sequence contains any elements.
          /// @return `true` if the source sequence contains any elements; otherwise, `false`.
          /// @par Examples
          /// The following code example demonstrates how to use Any to determine whether a sequence contains any elements.
          /// @include enumerable_any.cpp
          bool any() const noexcept {
            return xtd::linq::enumerable::any(base());
          }
          /// @brief Determines whether any element of a sequence satisfies a condition.
          /// @param predicate A function to test each element for a condition.
          /// @return `true` if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, `false`.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is `true` if all the pet names start with "B" or if the pets array is empty.
          /// @include enumerable_any.cpp
          bool any(const std::function<bool(const source_t&)>& predicate) const {
            return xtd::linq::enumerable::any(base(), predicate);
          }
          
          /// @brief Appends a value to the end of the sequence.
          /// @param element The value to append to source.
          /// @return A new sequence that ends with element.
          /// @par Examples
          /// The following code example demonstrates how to use Append to append a value to the end of the sequence.
          /// @include enumerable_append.cpp
          const ienumerable<source_t>& append(const source_t& element) const noexcept {
            return xtd::linq::enumerable::append(base(), element);
          }

          /// @brief Returns the input typed as xtd::collections::generic::ienumerable <type_t>.
          /// @return The input sequence typed as xtd::collections::generic::ienumerable <type_t>.
          /// @par Example
          /// The following code example demonstrates how to use as_enumerable <source_t>(ienumerable <source_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
          /// @include enumerable_as_enumerable.cpp
          const ienumerable<source_t>& as_enumerable() const noexcept {
            return xtd::linq::enumerable::as_enumerable(base());
          }

          /// @brief Computes the average of a sequence of source_t values.
          /// @return The average of this sequence of values.
          /// @exception xtd::invalid_operation_exception this sequence contains no elements.
          auto average() const noexcept {
            return xtd::linq::enumerable::average(base());
          }
          
          /// @brief Casts the elements of an xtd::collections::generic::ienumerable to the specified type.
          /// @tparam result_t The type of the resulting value.
          /// @return An xtd::collections::generic::ienumerable <type_t> that contains each element of the source sequence cast to the specified type.
          /// @exception xtd::invalid_cast_exception An element in the sequence cannot be cast to type `result_t`.
          template <class result_t>
          const ienumerable<result_t>& cast() const noexcept {
            return xtd::linq::enumerable::cast<result_t>(base());
          }

          /// @brief Splits the elements of a sequence into chunks of size at most size.
          /// @tparam source_t The type of the elements of source.
          /// @param source A sequence of values to chunk.
          /// @param size The maximum size of each chunk.
          /// @return A sequence of chunks of size at most size.
          const ienumerable<xtd::array<source_t>>& chunk(size_t size) const {
            return xtd::linq::enumerable::chunk(base(), size);
          }

          /// @brief Concatenates two sequences.
          /// @param second The sequence to concatenate to the current sequence.
          /// @return An xtd::collections::generic::ienumerable <type_t> that contains the concatenated elements of the two input sequences.
          const ienumerable<source_t>& concat(const ienumerable<source_t>& second) const noexcept {
            return xtd::linq::enumerable::concat(base(), second);
          }

          /// @brief Determines whether a sequence contains a specified element by using the default equality comparer.
          /// @param value The value to locate in the sequence.
          /// @return `true` if the source sequence contains an element that has the specified value; otherwise, `false`.
          bool contains(const source_t& value) const noexcept {
            return xtd::linq::enumerable::contains(base(), value);
          }
          
          /// @brief Determines whether a sequence contains a specified element by using a specified equality comparer.
          /// @param value The value to locate in the sequence.
          /// @param comparer An equality comparer to compare values.
          /// @return `true` if the source sequence contains an element that has the specified value; otherwise, `false`.
          bool contains(const source_t& value, const xtd::collections::generic::iequality_comparer<source_t>& comparer) const noexcept {
            return xtd::linq::enumerable::contains(base(), value, comparer);
          }

          /// @brief Returns the number of elements in current sequence.
          /// @return The number of elements in the input sequence.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::count <source_t>(const ienumerable <source_t>&) to count the elements in a sequence.
          /// @include enumerable_count.cpp
          size_t count() const noexcept {
            return xtd::linq::enumerable::count(base());
          }
          
          /// @brief Returns a number that represents how many elements in the specified sequence satisfy a condition.
          /// @param predicate A function to test each element for a condition.
          /// @return A number that represents how many elements in the sequence satisfy the condition in the predicate function.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::count <source_t>(const ienumerable <source_t>&, const std::function <bool(const source_t&)>&) to count the elements in a sequence that satisfy a condition.
          /// @include enumerable_count2.cpp
          size_t count(const std::function<bool(const source_t&)>& predicate) const noexcept {
            return xtd::linq::enumerable::count(base(), predicate);
          }
          
          /// @brief Returns the number of elements with the specified value.
          /// @param value The value to search for.
          /// @return A number representing the number of elements in the sequence that are equal to the `value`.
          xtd::size count(const source_t& value) const noexcept {
            return xtd::linq::enumerable::count(base(), value);
          }

          /// @brief Returns the count of elements in the current sequence grouped by key.
          /// @tparam key_t The type of the key returned by `key_selector`.
          /// @param key_selector A function to extract the key for each element.
          /// @return An enumerable containing the frequencies of each key occurrence in current sequence.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::count_by <source_t>(const ienumerable <source_t>&, const std::function <key_t(const source_t&)>&) to count the number of elements in a sequence grouped by key.
          /// @include enumerable_count_by.cpp
          template <class key_t>
          const ienumerable<key_value_pair<key_t, xtd::size>>& count_by(const std::function<key_t(const source_t&)>& key_selector) const noexcept {
            return xtd::linq::enumerable::count_by<key_t, source_t>(base(), key_selector);
          }
          
          /// @brief Returns the count of elements in the current sequence grouped by key.
          /// @tparam key_t The type of the key returned by `key_selector`.
          /// @param key_selector A function to extract the key for each element.
          /// @param key_comparer An equality comparer to compare keys.
          /// @return An enumerable containing the frequencies of each key occurrence in current sequence.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::count_by <source_t>(const ienumerable <source_t>&, const std::function <key_t(const source_t&)>&) to count the number of elements in a sequence grouped by key.
          /// @include enumerable_count_by.cpp
          template <class key_t>
          const ienumerable<key_value_pair<key_t, xtd::size>>& count_by(const std::function<key_t(const source_t&)>& key_selector, const iequality_comparer<key_t>& key_comparer) const noexcept {
            return xtd::linq::enumerable::count_by<key_t, source_t>(base(), key_selector, key_comparer);
          }
          
          /// @brief Returns the elements of the specified sequence or the type parameter's default value in a singleton collection if the current sequence is empty.
          /// @return An xtd::collections::generic::ienumerable <type_t> that contains default_value if source is empty; otherwise, source.
          const ienumerable<source_t>& default_if_empty() const noexcept {
            return xtd::linq::enumerable::default_if_empty(base());
          }
          
          /// @brief Returns the elements of the specified sequence or the specified value in a singleton collection if the current sequence is empty.
          /// @param default_value The value to return if the sequence is empty.
          /// @return An xtd::collections::generic::ienumerable <type_t> that contains default_value if source is empty; otherwise, source.
          const ienumerable<source_t>& default_if_empty(const source_t& default_value) const noexcept {
            return xtd::linq::enumerable::default_if_empty(base(), default_value);
          }

          /// @brief Returns the first element of the sequence that satisfies a condition, or a specified default value if no such element is found.
          /// @param predicate A function to test each element for a condition.
          /// @param default_value The default value to return if the sequence is empty.
          /// @return `default_value` if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
          source_t first_or_default(const std::function<bool(const source_t&)>& predicate, const source_t& default_value) const noexcept {
            return xtd::linq::enumerable::first_or_default(base(), predicate, default_value);
          }
          /// @brief Returns the first element of the sequence that satisfies a condition or a default value if no such element is found.
          /// @param predicate A function to test each element for a condition.
          /// @return default `source_t {}` if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
          source_t first_or_default(const std::function<bool(const source_t&)>& predicate) const noexcept {
            return xtd::linq::enumerable::first_or_default(base(), predicate);
          }

          /// @brief Returns the first element of the sequence that satisfies a condition or a default value if no such element is found.
          /// @param default_value The default value to return if the sequence is empty.
          /// @return `default_value`  if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
          source_t first_or_default(const source_t default_value) const noexcept {
            return xtd::linq::enumerable::first_or_default(base(), default_value);
          }
          
          /// @brief Returns the first element of the sequence that satisfies a condition or a default value if no such element is found.
          /// @return default `source_t {}`  if source is empty or if no element passes the test specified by predicate; otherwise, the first element in source that passes the test specified by predicate.
          source_t first_or_default() const noexcept {
            return xtd::linq::enumerable::first_or_default(base());
          }

          /// @brief Projects each element of a sequence into a new form.
          /// @tparam result_t The type of the resulting value.
          /// @param source A sequence of values to invoke a transform function on.
          /// @param selector A transform function to apply to each element.
          /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const ienumerable <source_t>&, const std::function <result_t(const source_t&)>&) to project over a sequence of values.
          /// @include enumerable_range.cpp.cpp
          template<class result_t>
          const ienumerable<result_t>& select(const std::function<result_t(const source_t&)>& selector) const {
            return xtd::linq::enumerable::select<result_t, source_t>(base(), selector);
          }
          /// @brief Projects each element of a sequence into a new form.
          /// @param source A sequence of values to invoke a transform function on.
          /// @param selector A transform function to apply to each element.
          /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const ienumerable <source_t>&, const std::function <result_t(const source_t&)>&) to project over a sequence of values.
          /// @include enumerable_range.cpp.cpp
          const ienumerable<source_t>& select(const std::function<source_t(const source_t&)>& selector) const {
            return xtd::linq::enumerable::select(base(), selector);
          }
          /// @brief Projects each element of a sequence into a new form by incorporating the element's index.
          /// @tparam result_t The type of the resulting value.
          /// @param source A sequence of values to invoke a transform function on.
          /// @param selector A transform function to apply to each source element; the second parameter of the function represents the index of the source element.
          /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const ienumerable <source_t>&, const std::function <result_t(const source_t&, size_t)>&) to project over a sequence of values and use the index of each element.
          /// @include enumerable_select.cpp
          template<class result_t>
          const ienumerable<result_t>& select(const std::function<result_t(const source_t&, size_t index)>& selector) const {
            return xtd::linq::enumerable::select<result_t, source_t>(base(), selector);
          }
          /// @brief Projects each element of a sequence into a new form by incorporating the element's index.
          /// @param source A sequence of values to invoke a transform function on.
          /// @param selector A transform function to apply to each source element; the second parameter of the function represents the index of the source element.
          /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::select <source_t, result_t>(const ienumerable <source_t>&, const std::function <result_t(const source_t&, size_t)>&) to project over a sequence of values and use the index of each element.
          /// @include enumerable_select.cpp
          const ienumerable<source_t>& select(const std::function<source_t(const source_t&, size_t index)>& selector) const {
            return xtd::linq::enumerable::select(base(), selector);
          }

          /// @brief Creates a xtd::collections::generic::list <type_t> from an xtd::collections::generic::ienumerable <type_t>.
          /// @return A xtd::collections::generic::list <type_t> that contains elements from the input sequence.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::to_list to force immediate query evaluation and return a xtd::collections::generic::list <type_t> that contains the query results.
          /// @include enumerable_to_list.cpp
          const list<source_t>& to_list() const noexcept;
          
          /// @brief Filters a sequence of values based on a predicate.
          /// @param predicate A function to test each element for a condition.
          /// @return An xtd::collections::generic::ienumerable <type_t> that contains elements from the input sequence that satisfy the condition.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::where <source_t>(const ienumerable <source_t>&, const std::function<bool (const source_t&)>&) to filter a sequence.
          /// @include enumerable_where.cpp
          const ienumerable<source_t>& where(const std::function<bool(const source_t&)>& predicate) const {
            return xtd::linq::enumerable::where(base(), predicate);
          }
          /// @brief Filters a sequence of values based on a predicate. Each element's index is used in the logic of the predicate function.
          /// @param predicate A function to test each source element for a condition; the second parameter of the function represents the index of the source element.
          /// @return An xtd::collections::generic::ienumerable <type_t> that contains elements from the input sequence that satisfy the condition.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::where <source_t>(const ienumerable <source_t>&, const std::function<bool (const source_t&, size_t)>&) to filter a sequence based on a predicate that involves the index of each element.
          /// @include enumerable_where2.cpp
          const ienumerable<source_t>& where(const std::function<bool(const source_t&, size_t)>& predicate) const {
            return xtd::linq::enumerable::where(base(), predicate);
          }
          /// @}
          
        private:
          const enumerable_t& base() const noexcept {return static_cast<const enumerable_t&>(*this);}
        };
      }
    }
  }
}

#define __XTD_CORE_INTERNAL__
#include "../../../internal/__enumerable_collection.hpp"
#undef __XTD_CORE_INTERNAL__
#include "../ienumerable.hpp"
