/// @file
/// @brief Contains xtd::collections::generic::helpers::equator struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "../../../internal/__polymorphic_equator.hpp"
#undef __XTD_CORE_INTERNAL__
#include "../iequality_comparer.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief The xtd::collections::generic::helpers namespace contains helpers for generic collections, sush as comparer, equator an hasher structs.
      namespace helpers {
        /// @brief Implements a function object for performing comparisons. Unless specialised, invokes operator== on type type_t. xtd::equator with the key and the value strongly typed to be xtd::any_object.
        /// ```cpp
        /// template<class key_t>
        /// struct equator;
        /// ```
        /// @par Header
        /// ```cpp
        /// #include <xtd/collections/generic/helpers/equator>
        /// ```
        /// @par Namespace
        /// xtd::collections::generic::helpers
        /// @par Library
        /// xtd.core
        /// @ingroup xtd_core helpers_generic_collections
        /// @par Examples
        /// The following example show how to use xtd::collections::generic::helpers::equator with `std::unordered_map`.
        /// ```cpp
        /// auto key_values = std::unordered_map<xtd::date_time, xtd::string, xtd::collections::generic::helpers::hasher<xtd::date_time>, xtd::collections::generic::helpers::equator<xtd::date_time>, xtd::collections::generic::helpers::allocator<xtd::collections::generic::key_value_pair<const xtd::date_time, xtd::string>>> {};
        /// key_values.insert({{1971, 1, 5}, "Birth date"});
        /// ```
        template<class key_t>
        struct equator {
          /// @name Public Aliases
          
          /// @{
          /// @brief Represents the first argument type.
          using first_argument_type = key_t;
          /// @brief Represents the second argument type.
          using second_argument_type = key_t;
          /// @brief Represents the result type.
          using result_type = bool;
          /// @}

          /// @name Public Constructors
          
          /// @{
          /// @brief Initializes a new instance of the hasher.
          equator() = default;
          /// @brief Initializes a new instance of the hasher with specified comparer.
          /// @param comparer A comparer used to hash the key.
          explicit equator(const xtd::collections::generic::iequality_comparer<key_t>& comparer) : comparer {&comparer} {}
          /// @}

          /// @name Public Operators
          
          /// @{
          /// @brief checks if the specified a and b keys are equal.
          /// @param a The first key to check.
          /// @param b The second key to check.
          /// @return `true` if keys are equals; otherwise `false`.
          /// @remarks If key_t inherits from xtd::object, the xtd::object::equals method will be used; otherwise, the [std::equal_to](https://en.cppreference.com/w/cpp/utility/functional/equal_to) object function will be used.
          result_type operator()(const first_argument_type& a, const second_argument_type& b) const {
            if (&a == &b) return true;
            if (comparer) return comparer->equals(a, b);
            return __polymorphic_equator__<first_argument_type, typename std::is_polymorphic<first_argument_type>::type> {}(a, b);
          }
          /// @}

        private:
          const xtd::collections::generic::iequality_comparer<key_t>* comparer = nullptr;
        };
      }
    }
  }
}
