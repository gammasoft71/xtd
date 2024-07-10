/// @file
/// @brief Contains xtd::collections::generic::equal_to struct.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/object>
#include <functional>
#include <type_traits>

/// @cond
template<typename key_t, typename bool_t>
struct __object_equal_to__ {};

template<typename key_t>
struct __object_equal_to__<key_t, std::true_type> {
  bool operator()(const key_t& a, const key_t& b) const {return xtd::object::equals(a, b);}
};

template<typename key_t>
struct __object_equal_to__<key_t, std::false_type> {
  bool operator()(const key_t& a, const key_t& b) const {return std::equal_to<key_t> {}(a, b);}
};

template<typename key_t, typename bool_t>
struct __polymorphic_equal_to__ {};

template<typename key_t>
struct __polymorphic_equal_to__<key_t, std::true_type> {
  bool operator()(const key_t& a, const key_t& b) const {return __object_equal_to__<key_t, typename std::is_base_of<xtd::object, key_t>::type> {}(a, b);}
};

template<typename key_t>
struct __polymorphic_equal_to__<key_t, std::false_type> {
  bool operator()(const key_t& a, const key_t& b) const {return std::equal_to<key_t> {}(a, b);}
};
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Implements a function object for performing comparisons. Unless specialised, invokes operator== on type type_t. xtd::equal_to with the key and the value strongly typed to be std::any.
      /// ```cpp
      /// class equal_to
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/equal_to>
      /// ```
      /// @par Namespace
      /// xtd::collections
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core collections
      template<typename key_t = void>
      struct equal_to {
        /// @brief checks if the specified a and b keys are equal.
        /// @param a The first key to check.
        /// @param b The second key to check.
        /// @return true if keys are equals; otherwise false.
        /// @remarks If key_t inherits from xtd::object, the xtd::object::equals method will be used; otherwise, the [std::equal_to](https://en.cppreference.com/w/cpp/utility/functional/equal_to) object function will be used.
        bool operator()(const key_t& a, const key_t& b) const {return __polymorphic_equal_to__<key_t, typename std::is_polymorphic<key_t>::type> {}(a, b);}
      };
    }
  }
}
