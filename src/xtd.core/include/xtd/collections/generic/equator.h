/// @file
/// @brief Contains xtd::collections::generic::equator struct.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "../../internal/__equator.h"
#undef __XTD_CORE_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Implements a function object for performing comparisons. Unless specialised, invokes operator== on type type_t. xtd::equator with the key and the value strongly typed to be std::any.
      /// ```cpp
      /// class equator
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/equator>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @par Examples
      /// The following example show how to use xtd::collections::generic::equator with `std::unordered_map`.
      /// ```cpp
      /// auto key_values = std::unordered_map<xtd::date_time, xtd::ustring, xtd::collections::generic::hasher<xtd::date_time>, xtd::collections::generic::equator<xtd::date_time>, xtd::collections::generic::allocator<xtd::collections::generic::key_value_pair<const xtd::date_time, xtd::ustring>>> {};
      /// key_values.insert({{1971, 1, 5}, "Birth date"});
      /// ```
      template<typename key_t = void>
      struct equator {
        /// @brief checks if the specified a and b keys are equal.
        /// @param a The first key to check.
        /// @param b The second key to check.
        /// @return true if keys are equals; otherwise false.
        /// @remarks If key_t inherits from xtd::object, the xtd::object::equals method will be used; otherwise, the [std::equal_to](https://en.cppreference.com/w/cpp/utility/functional/equal_to) object function will be used.
        bool operator()(const key_t& a, const key_t& b) const {return __polymorphic_equator__<key_t, typename std::is_polymorphic<key_t>::type> {}(a, b);}
      };
    }
  }
}
