/// @file
/// @brief Contains xtd::collections::generic::params class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../../object.h"
#include "../../string.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief An object of type xtd::collections::generic::params <type_t> is a lightweight proxy object that provides access to an array of objects of type const `type_t` (that may be allocated in read-only memory).
      /// ```cpp
      /// template<typename type_t>
      /// class params : public xtd::object
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/params
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @remarks This class cannot be inherited.
      /// @remarks A xtd::collections::generic::params object is automatically constructed when:
      /// * A brace-enclosed params is used to initialize an object, where the corresponding constructor accepts an xtd::collections::generic::params or [std::initializer_list](https://en.cppreference.com/w/cpp/utility/initializer_list) parameter,
      /// * A brace-enclosed params is used as the right operand of assignment or as a function call argument, and the corresponding assignment operator/function accepts an xtd::collections::generic::params or [std::initializer_list](https://en.cppreference.com/w/cpp/utility/initializer_list) parameter.
      /// * A brace-enclosed params is bound to auto, including in a [ranged for loop](https://en.cppreference.com/w/cpp/language/range-for).
      /// @remarks xtd::collections::generic::params may be implemented as a pair of pointers or pointer and length. Copying a xtd::collections::generic::params does not copy the backing array of the corresponding params.
      /// @remarks xtd::collections::generic::params is exactly The same as [std::initializer_list](https://en.cppreference.com/w/cpp/utility/initializer_list) object.
      /// @par Examples
      /// The following example demonstrates how to usea xtd::collections::generic::params <type_t> class.
      /// @include generic_params.cpp
      template<typename type_t>
      class params final : public xtd::object {
      public:
        /// @name Public Alias
        
        /// @{
        /// @brief Represents the params base type.
        using base_type = std::initializer_list<type_t>;
        /// @brief Represents the params value type.
        using value_type = base_type::value_type;
        /// @brief Represents the reference of params value type.
        using reference = base_type::reference;
        /// @brief Represents the const reference of params value type.
        using const_reference = base_type::const_reference;
        /// @brief Represents the params size type (usually xtd::size).
        using size_type = base_type::size_type;
        /// @brief Represents the iterator of params value type.
        using iterator = base_type::iterator;
        /// @brief Represents the const iterator of params value type.
        using const_iterator = base_type::const_iterator;
        /// @}
        
        /// @name Public Constructors
        
        /// @{
        /// @brief Create a new instance of the class xtd::collections::generic::params.
        params() noexcept = default;
        /// @}
        
        /// @cond
        params(const params&) noexcept = default;
        params(params&&) noexcept = default;
        params(const base_type& il) noexcept : items_(il) {}
        params(base_type&& il) noexcept : items_(il) {}
        params(const value_type* p, size_type s) : items_(p, s) {}
        /// @endcond
        
        /// @name Public Methods
        
        /// @{
        /// @brief Returns the number of elements in the params, i.e. `std::distance(begin(), end())`.
        /// @return The number of elements in the params.
        size_type size() const noexcept {return items_.size();}
        
        /// @brief Returns a pointer to the first element in the params.
        /// @return A pointer to the first element in the params.
        /// @remarks If the params is empty, the values of begin() and end() are unspecified, but will be identical.
        iterator begin() const noexcept {return items_.begin();}
        /// @brief Returns a pointer to one past the last element in the params, i.e. begin() + size().
        /// @return A pointer to one past the last element in the params.
        /// @remarks If the params is empty, the values of begin() and end() are unspecified, but will be identical.
        iterator end() const noexcept {return items_.end();}
        
        xtd::string to_string() const noexcept override {return xtd::string::format("{}", items_);}
        /// @}
        
        /// @name Public Operators
        
        /// @{
        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlying base type.
        operator const base_type&() const noexcept {return items_;}
        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlying base type.
        operator base_type&() noexcept {return items_;}
        /// @}
        
      private:
        base_type items_;
      };
    }
  }
}

/// @cond
namespace std {
  template<typename type_t>
  inline const type_t* begin(xtd::collections::generic::params<type_t> items) noexcept {
    return items.begin();
  }
  
  template<typename type_t>
  inline const type_t* end(xtd::collections::generic::params<type_t> items) noexcept {
    return items.end();
  }
}
/// @endcond
