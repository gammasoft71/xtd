/// @file
/// @brief Contains xtd::collections::generic::helpers::lesser struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../icomparer.hpp"
#include "../../../icomparable.hpp"
#include "../../../int32.hpp"
#include "../../../less_than_comparable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief The xtd::collections::generic::helpers namespace contains helpers for generic collections, sush as lesser, equator an hasher structs.
      namespace helpers {
        /// @brief Implements a function object for compare data.
        /// ```cpp
        /// struct lesser;
        /// ```
        /// @par Header
        /// ```cpp
        /// #include <xtd/collections/generic/helpers/lesser>
        /// ```
        /// @par Namespace
        /// xtd::collections::generic::helpers
        /// @par Library
        /// xtd.core
        /// @ingroup xtd_core helpers_generic_collections
        /// @remarks The associative containers xtd::collections::generic::sorted_set, xtd::collections::generic::sorted_multi_set, xtd::collections::generic::sorted_dictionary, xtd::collections::generic::sorted_multi_dictionary use specializations of the template xtd::collections::generic::helpers::lesser as the defaultcompare function.
        /// @par Examples
        /// The following example show how to use xtd::collections::generic::helpers::lesser with `std::map`.
        /// ```cpp
        /// auto key_values = std::map<xtd::date_time, xtd::string, xtd::collections::generic::helpers::lesser<xtd::date_time>, xtd::collections::generic::helpers::allocator<xtd::collections::generic::key_value_pair<const xtd::date_time, xtd::string>>> {};
        /// key_values.insert({{1971, 1, 5}, "Birth date"});
        /// ```
        template<class value_t = void>
        struct lesser {
          /// @name Public Aliases
          
          /// @{
          /// @brief Represents the first argument type.
          using first_argument_type = value_t;
          /// @brief Represents the second argument type.
          using second_argument_type = value_t;
          /// @brief Represents the result type.
          using result_type = bool;
          /// @}
          
          /// @name Public Constructors
          
          /// @{
          /// @brief Initializes a new instance of the comparer.
          lesser() = default;
          /// @brief Initializes a new instance of the comparer with specified comparer.
          /// @param comparer A comparer used to hash the key.
          explicit lesser(const xtd::collections::generic::icomparer<value_t>& comparer) : comparer_ {&comparer} {}
          /// @}
          
          /// @name Public Operators
          
          /// @{
          /// @brief Compares two entities and returns a value indicating whether one is less than the other.
          /// @param x The first entity to compare.
          /// @param y The second entity to compare.
          /// @return true is x less than y; otherwise false.
          constexpr auto operator()(const first_argument_type& x, const second_argument_type& y) const -> result_type {
            if (&x == &y) return false;
            if (comparer_) return comparer_->compare(x, y) < 0;
            if constexpr(std::is_polymorphic_v<first_argument_type> && std::is_base_of_v<xtd::icomparable<first_argument_type>, first_argument_type>) return static_cast<const xtd::icomparable<first_argument_type>&>(x).compare_to(y) < 0;
            else if constexpr(xtd::less_than_comparable<first_argument_type>) return std::less<first_argument_type> {}(x, y);
            else return std::less<const void*> {}(static_cast<const void*>(&x), static_cast<const void*>(&y));
          }
          /// @}
          
        private:
          const xtd::collections::generic::icomparer<value_t>* comparer_ = nullptr;
        };
      }
    }
  }
}
