/// @file
/// @brief Contains xtd::collections::generic::extensions::enumerable <type_t> class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../../../linq/enumerable.hpp"

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
        /// #include <xtd/linq/enumerable
        /// ```
        /// @par Namespace
        /// xtd::linq
        /// @par Library
        /// xtd.core
        /// @ingroup xtd_core extensions_generic_collections
        template <typename enumerable_t, typename source_t>
        class enumerable {
        public:
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
          /// @brief Applies an accumulator function over a sequence.
          /// @param func An accumulator function to be invoked on each element.
          /// @return The final accumulator value.
          /// @par Examples
          /// The following code example demonstrates how to reverse the order of words in a string by using xtd::linq::enumerable::aggregate.
          /// @include enumerable_aggregate.cpp
          template<typename func_t>
          source_t aggregate(const func_t& func) const {
            return xtd::linq::enumerable::aggregate(base(), func);
          }
          /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value.
          /// @param seed The initial accumulator value.
          /// @param func An accumulator function to be invoked on each element.
          /// @return The final accumulator value.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
          /// @include enumerable_aggregate2.cpp
          template<typename accumulate_t>
          accumulate_t aggregate(const accumulate_t& seed, const std::function<accumulate_t(const source_t&, const accumulate_t&)>& func) const {
            return xtd::linq::enumerable::aggregate(base(), seed, func);
          }
          /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value.
          /// @param seed The initial accumulator value.
          /// @param func An accumulator function to be invoked on each element.
          /// @return The final accumulator value.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
          /// @include enumerable_aggregate2.cpp
          template<typename accumulate_t, typename func_t>
          accumulate_t aggregate(const accumulate_t& seed, const func_t& func) const {
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
          template<typename accumulate_t, typename result_t>
          result_t aggregate(const accumulate_t& seed, const std::function<accumulate_t(const source_t&, const accumulate_t&)>& func, const std::function<result_t(const accumulate_t&)>& result_selector) const {
            return xtd::linq::enumerable::aggregate(base(), seed, func, result_selector);
          }
          /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
          /// @param seed The initial accumulator value.
          /// @param func An accumulator function to be invoked on each element.
          /// @param result_selector A function to transform the final accumulator value into the result value.
          /// @return The transformed final accumulator value.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
          /// @include enumerable_aggregate3.cpp
          template<typename accumulate_t, typename result_t, typename func_t, typename result_selector_t>
          result_t aggregate(const accumulate_t& seed, const func_t& func, const result_selector_t& result_selector) const {
            return xtd::linq::enumerable::aggregate(base(), seed, func, result_selector);
          }
          /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
          /// @param seed The initial accumulator value.
          /// @param func An accumulator function to be invoked on each element.
          /// @param result_Selector A function to transform the final accumulator value into the result value.
          /// @return The transformed final accumulator value.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::aggregate to apply an accumulator function and use a seed value.
          /// @include enumerable_aggregate3.cpp
          template<typename accumulate_t, typename func_t, typename result_selector_t>
          accumulate_t aggregate(const accumulate_t& seed, const func_t& func, const result_selector_t& result_selector) const {
            return xtd::linq::enumerable::aggregate(base(), seed, func, result_selector);
          }
          
          /// @brief Determines whether all elements of a sequence satisfy a condition.
          /// @param predicate A function to test each element for a condition.
          /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
          /// @include enumerable_all.cpp
          bool all(const std::function<bool(const source_t&)>& predicate) const {
            return xtd::linq::enumerable::all(base(), predicate);
          }
          /// @brief Determines whether all elements of a sequence satisfy a condition.
          /// @param predicate A function to test each element for a condition.
          /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
          /// @include enumerable_all.cpp
          template<typename predicate_t>
          bool all(const predicate_t& predicate) const {
            return xtd::linq::enumerable::all(base(), predicate);
          }
          
          /// @brief Determines whether a sequence contains any elements.
          /// @return true if the source sequence contains any elements; otherwise, false.
          /// @par Examples
          /// The following code example demonstrates how to use Any to determine whether a sequence contains any elements.
          /// @include enumerable_any.cpp
          bool any() const noexcept {
            return xtd::linq::enumerable::any(base());
          }
          /// @brief Determines whether any element of a sequence satisfies a condition.
          /// @param predicate A function to test each element for a condition.
          /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
          /// @include enumerable_any.cpp
          bool any(const std::function<bool(const source_t&)>& predicate) const {
            return xtd::linq::enumerable::any(base(), predicate);
          }
          /// @brief Determines whether any elements of a sequence satisfy a condition.
          /// @param predicate A function to test each element for a condition.
          /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
          /// @par Examples
          /// The following code example demonstrates how to use xtd::linq::enumerable::all <source_t> to determine whether all the elements in a sequence satisfy a condition. Variable all_start_with_B is true if all the pet names start with "B" or if the pets array is empty.
          /// @include enumerable_any.cpp
          template<typename predicate_t>
          bool any(const predicate_t& predicate) const {
            return xtd::linq::enumerable::any(base(), predicate);
          }
          
          /// @brief Appends a value to the end of the sequence.
          /// @param element The value to append to source.
          /// @return A new sequence that ends with element.
          /// @par Examples
          /// The following code example demonstrates how to use Append to append a value to the end of the sequence.
          /// @include enumerable_append.cpp
          const xtd::collections::generic::ienumerable<source_t>& append(const source_t& element) const noexcept {
            return xtd::linq::enumerable::append(base(), element);
          }

          /// @brief Returns the input typed as xtd::collection::generic::ienumerable <type_t>.
          /// @return The input sequence typed as xtd::collection::generic::ienumerable <type_t>.
          /// @par Example
          /// The following code example demonstrates how to use as_enumerable <source_t>(ienumerable <source_t>) to hide a type's custom Where method when the standard query operator implementation is desired.
          /// @include enumerable_as_enumerable.cpp
          const xtd::collections::generic::ienumerable<source_t>& as_enumerable() const noexcept {
            return xtd::linq::enumerable::as_enumerable(base());
          }

          /// @brief Computes the average of a sequence of source_t values.
          /// @return The average of this sequence of values.
          /// @exception xtd::invalid_operation_exception this sequence contains no elements.
          auto average() const noexcept {
            return xtd::linq::enumerable::average(base());
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
          /// @param source A sequence of values to invoke a transform function on.
          /// @param selector A transform function to apply to each element.
          /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
          template<typename result_t>
          const xtd::collections::generic::ienumerable<result_t>& select(const std::function<result_t(const source_t&)>& selector) const {
            return xtd::linq::enumerable::select<source_t, result_t>(base(), selector);
          }
          /// @brief Projects each element of a sequence into a new form.
          /// @param source A sequence of values to invoke a transform function on.
          /// @param selector A transform function to apply to each element.
          /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
          template<typename result_t, typename selector_t>
          const xtd::collections::generic::ienumerable<result_t>& select(const selector_t& selector) const {
            return xtd::linq::enumerable::select<source_t, result_t>(base(), selector);
          }
          /// @brief Projects each element of a sequence into a new form.
          /// @param source A sequence of values to invoke a transform function on.
          /// @param selector A transform function to apply to each element.
          /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
          const xtd::collections::generic::ienumerable<source_t>& select(const std::function<source_t(const source_t&)>& selector) const {
            return xtd::linq::enumerable::select(base(), selector);
          }
          /// @brief Projects each element of a sequence into a new form.
          /// @param source A sequence of values to invoke a transform function on.
          /// @param selector A transform function to apply to each element.
          /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
          template<typename selector_t>
          const xtd::collections::generic::ienumerable<source_t>& select(const selector_t& selector) const {
            return xtd::linq::enumerable::select(base(), selector);
          }
          /// @brief Projects each element of a sequence into a new form by incorporating the element's index.
          /// @param source A sequence of values to invoke a transform function on.
          /// @param selector A transform function to apply to each source element; the second parameter of the function represents the index of the source element.
          /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
          template<typename result_t>
          const xtd::collections::generic::ienumerable<result_t>& select(const std::function<result_t(const source_t&, size_t index)>& selector) const {
            return xtd::linq::enumerable::select<source_t, result_t>(base(), selector);
          }
          /// @brief Projects each element of a sequence into a new form by incorporating the element's index.
          /// @param source A sequence of values to invoke a transform function on.
          /// @param selector A transform function to apply to each source element; the second parameter of the function represents the index of the source element.
          /// @return An xtd::collections::generic::ienumerable <type_t> whose elements are the result of invoking the transform function on each element of source.
          const xtd::collections::generic::ienumerable<source_t>& select(const std::function<source_t(const source_t&, size_t index)>& selector) const {
            return xtd::linq::enumerable::select(base(), selector);
          }

          /// @brief Creates a xtd::collections::generic::list <type_t> from an xtd::collections::generic::ienumerable <type_t>.
          /// @return A xtd::collections::generic::list <type_t> that contains elements from the input sequence.
          const xtd::collections::generic::list<source_t>& to_list() const noexcept;
          
          /// @brief Filters a sequence of values based on a predicate.
          /// @param predicate A function to test each element for a condition.
          /// @return An xtd::collections::generic::ienumerable <type_t> that contains elements from the input sequence that satisfy the condition.
          const xtd::collections::generic::ienumerable<source_t>& where(const std::function<bool(const source_t&)>& predicate) const {
            return xtd::linq::enumerable::where(base(), predicate);
          }
          /// @brief Filters a sequence of values based on a predicate.
          /// @param predicate A function to test each element for a condition.
          /// @return An xtd::collections::generic::ienumerable <type_t> that contains elements from the input sequence that satisfy the condition.
          template<typename predicate_t>
          const xtd::collections::generic::ienumerable<source_t>& where(const predicate_t& predicate) const {
            return xtd::linq::enumerable::where(base(), predicate);
          }
          /// @brief Filters a sequence of values based on a predicate. Each element's index is used in the logic of the predicate function.
          /// @param predicate A function to test each source element for a condition; the second parameter of the function represents the index of the source element.
          /// @return An xtd::collections::generic::ienumerable <type_t> that contains elements from the input sequence that satisfy the condition.
          const xtd::collections::generic::ienumerable<source_t>& where(const std::function<bool(const source_t&)>& predicate, size_t) const {
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

#include "../../../linq/enumerable_collection.hpp"
#include "../ienumerable.hpp"
