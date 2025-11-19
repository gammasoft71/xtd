/// @file
/// @brief Contains xtd::collections::generic::helpers::comparer struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "../../../internal/__polymorphic_comparer.hpp"
#undef __XTD_CORE_INTERNAL__
#include "../icomparer.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief The xtd::collections::generic::helpers namespace contains helpers for generic collections, sush as comparer, equator an hasher structs.
      namespace helpers {
        /// @brief Implements a function object for compare data.
        /// ```cpp
        /// struct comparer;
        /// ```
        /// @par Header
        /// ```cpp
        /// #include <xtd/collections/generic/helpers/comparer>
        /// ```
        /// @par Namespace
        /// xtd::collections::generic::helpers
        /// @par Library
        /// xtd.core
        /// @ingroup xtd_core helpers_generic_collections
        template<class type_t = void>
        struct comparer {
          /// @name Public Aliases
          
          /// @{
          /// @brief Represents the first argument type.
          using first_argument_type = type_t;
          /// @brief Represents the second argument type.
          using second_argument_type = type_t;
          /// @brief Represents the result type.
          using result_type = int32;
          /// @}
          
          /// @name Public Constructors
          
          /// @{
          /// @brief Initializes a new instance of the comparer.
          comparer() = default;
          /// @brief Initializes a new instance of the comparer with specified comparer.
          /// @param comparer A comparer used to hash the key.
          explicit comparer(const xtd::collections::generic::icomparer<type_t>& comparer) : comparer_ {&comparer} {}
          /// @}
          
          /// @name Public Operators
          
          /// @{
          /// @brief Compares two entities and returns a value indicating whether one is less than, equal to, or greater than the other.
          /// @param x The first entity to compare.
          /// @param y The second entity to compare.
          /// @return A 32-bit signed integer that indicates the relative order of the entities being compared. The return value has these meanings:
          ///
          /// | Value             | Condition            |
          /// |-------------------|----------------------|
          /// | Less than zero    | x is less than y.    |
          /// | Zero              | x equals y.          |
          /// | Greater than zero | x is greater than y. |
          constexpr result_type operator()(const first_argument_type& x, const second_argument_type& y) const {
            if (comparer_) return comparer_->compare(x, y);
            return __polymorphic_comparer__<first_argument_type, typename std::is_polymorphic<first_argument_type>::type> {}(x, y);
          }
          /// @}
          
        private:
          const xtd::collections::generic::icomparer<type_t>* comparer_ = nullptr;
        };
      }
    }
  }
}
