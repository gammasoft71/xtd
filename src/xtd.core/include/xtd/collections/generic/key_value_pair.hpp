/// @file
/// @brief Contains xtd::collections::key_value_pair <key_t, value_t> struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <utility>
#include "../../is.hpp"
#include "../../object.hpp"
#include "../../iequatable.hpp"
#include "../../static.hpp"
#define __XTD_CORE_INTERNAL__
#include "../../internal/__key_value_pair_definition.hpp"
#undef  __XTD_CORE_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Defines a key/value pair that can be set or retrieved.
      /// ```cpp
      /// template<class key_t, class value_t>
      /// struct key_value_pair : xtd::object, xtd::iequatable<key_value_pair<key_t, value_t>>;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/key_value_pair>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @remarks xtd::collections::generic::key_value_pair is same as [std::pair](https://en.cppreference.com/w/cpp/utility/pair).
      template <class key_t, class value_t>
      struct key_value_pair : xtd::object, xtd::iequatable<key_value_pair<key_t, value_t>> {
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the type of the base.
        using base_type = std::pair<key_t, value_t>;
        /// @brief Represents the type of the key.
        using key_type = key_t;
        /// @brief Representd the type of the value.
        using value_type = value_t;
        /// @brief Represents the type of the first.
        using first_type  = key_type;
        /// @brief Represents the type of the second.
        using second_type = value_type;
        /// @}
        
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the key_value_pair<key_t, value_t> class with the default key and value.
        key_value_pair() = default;
        /// @brief Initializes a new instance of the key_value_pair<key_t, value_t> class with the specified key and value.
        /// @param Key The object defined in each key/value pair
        /// @param value The definition associated with key
        key_value_pair(const key_t& key, const value_t& value) : first {key}, second {value} {}
        /// @brief Initializes a new instance of the key_value_pair<key_t, value_t> class with the specified key and value.
        /// @param value The key and value of the key_value_pair<key_t, value_t>.
        key_value_pair(const std::pair<key_t, value_t>& value) : first {value.first}, second {value.second} {} // Can't be explicit by design.
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets or sets the key in the key/value pair.
        key_t first = key_t {};
        /// @brief Gets or sets the value in the key/value pair.
        value_t second = value_t {};
        
        /// @brief Gets the key in the key/value pair.
        /// @return key_t A key_t that is the key of the key_value_pair<key_t, value_t>.
        const key_t& key() const noexcept {
          return first;
        };
        
        /// @brief Gets the value in the key/value pair.
        /// @return value_t A value_t that is the value of the key_value_pair<key_t, value_t>.
        const value_t& value() const noexcept {
          return second;
        };
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Returns a String representation of the key_value_pair<key_t, value_t>, using the String representations of the key and value.
        /// @return const String A String representation of the key_value_pair<key_t, value_t>, which includes the String representations of the key and value.
        /// @return String
        xtd::string to_string() const noexcept override;
        
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param value The key_value_pair to compare with the current object.
        /// @return true if the specified object is equal to the current object; otherwise, false.
        bool equals(const key_value_pair& value) const noexcept override {return first == value.first && second == value.second;}
        
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param obj The object to compare with the current object.
        /// @return true if the specified object is equal to the current object; otherwise, false
        bool equals(const object& obj) const noexcept override {return is<key_value_pair>(obj) && equals(static_cast<const key_value_pair&>(obj));}
        /// @}
        
        /// @name Public Operators
        
        /// @{
        /// @brief Converts the current key_value_pair to a std::pair.
        /// @return A std::pair that is the current key_value_pair<key_t, value_t>.
        operator std::pair<key_t, value_t>() const noexcept {return {first, second};}
        /// @}
      };
      
      /// @brief Defines a key/value pair that can be set or retrieved.
      /// ```cpp
      /// template<>
      /// class key_value_pair<> static_;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/key_value_pair>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @remarks xtd::collections::generic::key_value_pair is same as [std::pair](https://en.cppreference.com/w/cpp/utility/pair).
      template <>
      struct key_value_pair<> static_ {
        /// @name Public Static Methods
        
        /// @{
        /// @brief Creates a key_value_pair from specified key and value.
        /// @tparam key_t The type of the key.
        /// @tparam value_t The type of the value.
        /// @param key The key of the key_value_pair.
        /// @param value The value of the key_value_pair.
        /// @return The key_value_pair value type.
        template<class key_t, class value_t>
        static key_value_pair<key_t, value_t> create(key_t key, value_t value) {return key_value_pair<key_t, value_t>(key, value);}
        /// @}
      };
    }
  }
}
