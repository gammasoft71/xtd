/// @file
/// @brief Contains xtd::collections::generic::helpers::comparer struct.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <functional>

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
        /// class comparer
        /// ```
        /// @par Header
        /// ```cpp
        /// #include <xtd/collections/comparer
        /// ```
        /// @par Namespace
        /// xtd::collections::generic
        /// @par Library
        /// xtd.core
        /// @ingroup xtd_core helpers_generic_collections
        /// @remarks The associative containers xtd::collections::generic::sorted_set, xtd::collections::generic::sorted_multi_set, xtd::collections::generic::sorted_dictionary, xtd::collections::generic::sorted_multi_dictionary use specializations of the template xtd::collections::generic::helpers::comparer as the defaultcompare function.
        /// @par Examples
        /// The following example show how to use xtd::collections::generic::helpers::comparer with `std::unordered_map`.
        /// ```cpp
        /// auto key_values = std::map<xtd::date_time, xtd::string, xtd::collections::generic::helpers::comparer<xtd::date_time>, xtd::collections::generic::helpers::allocator<xtd::collections::generic::key_value_pair<const xtd::date_time, xtd::string>>> {};
        /// key_values.insert({{1971, 1, 5}, "Birth date"});
        /// ```
        template<typename type_t = void>
        struct comparer {
          /// @name Public Operators
          
          /// @{
          /// @brief Serves as a hash function for a specified key with a particular type (type_t).
          /// @param key The key to hash.
          /// @return A hash code for the spesified key.
          /// @remarks If key_t inherits from xtd::object, the xtd::object::get_hash_code method will be used; otherwise, the [std::hash](https://en.cppreference.com/w/cpp/utility/hash) object function will be used.
          constexpr bool operator()(const type_t& lhs, const type_t& rhs) const {return std::less {}(lhs, rhs);}
          /// @}
        };
      }
    }
  }
}
