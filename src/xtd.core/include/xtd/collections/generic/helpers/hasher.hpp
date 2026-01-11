/// @file
/// @brief Contains xtd::collections::generic::helpers::hasher struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../iequality_comparer.hpp"
#include "../../../object.hpp"
#include "../../../ihashable.hpp"
#include <type_traits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief The xtd::collections::generic::helpers namespace contains helpers for generic collections, sush as comparer, equator an hasher structs.
      namespace helpers {
        /// @brief Implements a function object for hashing data.
        /// ```cpp
        /// template<class key_t>
        /// struct hasher;
        /// ```
        /// @par Header
        /// ```cpp
        /// #include <xtd/collections/generic/helpers/hasher>
        /// ```
        /// @par Namespace
        /// xtd::collections::generic::helpers
        /// @par Library
        /// xtd.core
        /// @ingroup xtd_core helpers_generic_collections
        /// @remarks The unordered associative containers xtd::collections::generic::has_set, xtd::collections::generic::hash_multi_set, xtd::collections::generic::dictionary, xtd::collections::generic::multi_dictionary use specializations of the template xtd::collections::generic::helpers::hasher as the default hash function.
        /// @par Examples
        /// The following example show how to use xtd::collections::generic::helpers::hasher with `std::unordered_map`.
        /// ```cpp
        /// auto key_values = std::unordered_map<xtd::date_time, xtd::string, xtd::collections::generic::helpers::hasher<xtd::date_time>, xtd::collections::generic::helpers::equator<xtd::date_time>, xtd::collections::generic::helpers::allocator<xtd::collections::generic::key_value_pair<const xtd::date_time, xtd::string>>> {};
        /// key_values.insert({{1971, 1, 5}, "Birth date"});
        /// ```
        template<class key_t>
        struct hasher {
          /// @name Public Aliases
          
          /// @{
          /// @brief Represents the argument type.
          using argument_type = key_t;
          /// @brief Represents the result type.
          using result_type = xtd::size;
          /// @}
          
          /// @name Public Constructors
          
          /// @{
          /// @brief Initializes a new instance of the hasher.
          hasher() noexcept = default;
          /// @brief Initializes a new instance of the hasher with specified comparer.
          /// @param comparer A comparer used to hash the key.
          explicit hasher(const xtd::collections::generic::iequality_comparer<key_t>& comparer) noexcept : comparer {const_cast<xtd::collections::generic::iequality_comparer<key_t>*>(&comparer)} {}
          /// @}
          
          /// @cond
          hasher(const hasher&) noexcept = default;
          hasher(hasher&&) noexcept = default;
          hasher& operator=(const hasher&) noexcept = default;
          hasher& operator=(hasher&&) noexcept = default;
          /// @endcond
          
          /// @name Public Operators
          
          /// @{
          /// @brief Serves as a hash function for a specified key with a particular type (type_t).
          /// @param key The key to hash.
          /// @return A hash code for the spesified key.
          /// @remarks If key_t inherits from xtd::object, the xtd::object::get_hash_code method will be used; otherwise, the [std::hash](https://en.cppreference.com/w/cpp/utility/hash) object function will be used.
          auto operator()(const argument_type& key) const noexcept -> result_type {
            if (comparer) return comparer->get_hash_code(key);
            if constexpr(std::is_polymorphic_v<argument_type> && std::is_base_of_v<xtd::ihashable, argument_type>) return static_cast<const xtd::ihashable&>(key).get_hash_code();
            else if constexpr(std::is_polymorphic_v<argument_type> && std::is_base_of_v<xtd::object, argument_type>) return static_cast<const xtd::object&>(key).get_hash_code();
            else if constexpr(std::is_invocable_v<std::hash<argument_type>, const argument_type&>) return std::hash<argument_type> {}(key);
            else return std::hash<std::intptr_t> {}(reinterpret_cast<std::intptr_t>(&key));
          }
          /// @}
          
        private:
          xtd::collections::generic::iequality_comparer<key_t>* comparer = nullptr;
        };
      }
    }
  }
}
